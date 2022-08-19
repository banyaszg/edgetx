/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"
#include "usb_joystick.h"

#define MAX_HID_REPORTDESC 160
#define MAX_HID_REPORT 80

uint8_t _hidReportDesc[MAX_HID_REPORTDESC] = { };
uint8_t _hidReportDescSize = 0;
uint8_t _hidReport[MAX_HID_REPORT] = { };
uint8_t _hidReportSize = 0;

static uint8_t _usbJoystickChannels[MAX_OUTPUT_CHANNELS] = { };
static uint8_t _usbJoystickPushBtnCount = 0;
static uint8_t _usbJoystickSwitch2sCount = 0;
static uint8_t _usbJoystickSwitch3sCount = 0;
static uint8_t _usbJoystickAxisCount = 0;

static const uint8_t _usbJoystickUniqueTypes[USBJOYS_CH_LAST + 1] = 
  { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1 };

int usbJoystickActive()
{
  return (usbPlugged() && getSelectedUsbMode() == USB_JOYSTICK_MODE);
}

int isUSBJoystickChannelFree(int except_idx, uint8_t id)
{
  if (id > USBJOYS_CH_LAST) return false;

  // Free to multiple usages
  if (_usbJoystickUniqueTypes[id] == 0) return true;
  
  // Unique ids
  for (int i = 0; i < MAX_OUTPUT_CHANNELS; i++) {
    if (i == except_idx) continue; 
    if (id == g_model.usbJoystickCh[i].mode) return false;
  }
  
  return true;
}

int setupUSBJoystick()
{
  static const uint8_t axisTypes[USBJOYS_CH_LAST + 1] = 
    { 0, 0, 0, 0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,    2,    2 };
  static const uint8_t axisTypeCodes[USBJOYS_CH_LAST + 1] = 
    { 0, 0, 0, 0, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0xb0, 0xb8, 0xba, 0xbb };
  
  static uint8_t oldHIDReportDesc[MAX_HID_REPORTDESC] = { };
  static uint8_t oldHIDReportDescSize = 0;

  // copy old to compare
  memcpy(oldHIDReportDesc, _hidReportDesc, MAX_HID_REPORTDESC);
  oldHIDReportDescSize = _hidReportDescSize;

  // Init data
  memset(_hidReportDesc, 0, MAX_HID_REPORTDESC);
  _hidReportDescSize = 0;
  memset(_hidReport, 0, MAX_HID_REPORT);
  _hidReportSize = 0;
  memset(_usbJoystickChannels, 0, MAX_OUTPUT_CHANNELS);
  _usbJoystickPushBtnCount = 0;
  _usbJoystickSwitch2sCount = 0;
  _usbJoystickSwitch3sCount = 0;
  _usbJoystickAxisCount = 0;
  
  uint8_t genAxisCount = 0;
  uint8_t simAxisCount = 0;
  
  // sort channels by type
  uint8_t typeCount[USBJOYS_CH_LAST + 1] = { };
  uint8_t typeIx[USBJOYS_CH_LAST + 1] = { };
  uint8_t mode = 0;
  for (uint8_t i = 0; i < MAX_OUTPUT_CHANNELS; i++) {
    mode = g_model.usbJoystickCh[i].mode;
    if ((mode > USBJOYS_CH_NONE) && (mode <=  USBJOYS_CH_LAST)) {
      if (_usbJoystickUniqueTypes[mode]) {
        // only one for these types
        typeCount[mode] = 1;
      } else {
        typeCount[mode]++;
      }
    }
  }
  uint8_t ixcount = 0;
  for (uint8_t i = 0; i <= USBJOYS_CH_LAST; i++) {
    typeIx[i] = ixcount;
    ixcount += typeCount[i];
  }
  for (uint8_t i = 0; i < MAX_OUTPUT_CHANNELS; i++) {
    mode = g_model.usbJoystickCh[i].mode;
    if ((mode > USBJOYS_CH_NONE) && (mode <=  USBJOYS_CH_LAST)) {
      _usbJoystickChannels[typeIx[mode]] = i;
      
      if (_usbJoystickUniqueTypes[mode]) {
        // only one for these types
      } else {
        typeIx[mode]++;
      }      
    }
  }

  // store counts  
  _usbJoystickPushBtnCount = typeCount[USBJOYS_CH_PUSHBTN];
  _usbJoystickSwitch2sCount = typeCount[USBJOYS_CH_SWITCH_2S];
  _usbJoystickSwitch3sCount = typeCount[USBJOYS_CH_SWITCH_3S];
  for (uint8_t i = 0; i <= USBJOYS_CH_LAST; i++) {
    if (axisTypes[i] > 0) {
      _usbJoystickAxisCount += typeCount[i];
      
      if (axisTypes[i] == 1) genAxisCount += typeCount[i];
      else if (axisTypes[i] == 2) simAxisCount += typeCount[i];
    }
  }

  // generate report desc
  
  // button (bits) calculations
  uint8_t btnBits = _usbJoystickPushBtnCount + (_usbJoystickSwitch2sCount * 2) + (_usbJoystickSwitch3sCount * 3);
  uint8_t btnPaddingBits = 8 - (btnBits % 8);
  if (btnPaddingBits == 8) btnPaddingBits = 0;
  
  // USAGE_PAGE (Generic Desktop)
  _hidReportDesc[_hidReportDescSize++] = 0x05;
  _hidReportDesc[_hidReportDescSize++] = 0x01;
  
  // USAGE (Joystick=0x04, Gamepad=0x05,  Multi-axis Controller=0x08)
  uint8_t joystickType = 0x04;
  if (g_model.usbJoystickMode == USBJOYS_GAMEPAD) joystickType = 0x05;
  else if (g_model.usbJoystickMode == USBJOYS_MULTIAXIS) joystickType = 0x08;
  _hidReportDesc[_hidReportDescSize++] = 0x09;
  _hidReportDesc[_hidReportDescSize++] = joystickType;
  
  // COLLECTION (Application)
  _hidReportDesc[_hidReportDescSize++] = 0xa1;
  _hidReportDesc[_hidReportDescSize++] = 0x01;
  
  // COLLECTION (Physical)
  _hidReportDesc[_hidReportDescSize++] = 0xa1;
  _hidReportDesc[_hidReportDescSize++] = 0x00;
  
  // button types
  if (btnBits > 0) {
    // USAGE_PAGE (Button)
    _hidReportDesc[_hidReportDescSize++] = 0x05;
    _hidReportDesc[_hidReportDescSize++] = 0x09;
    
    // USAGE_MINIMUM (Button 1)
    _hidReportDesc[_hidReportDescSize++] = 0x19;
    _hidReportDesc[_hidReportDescSize++] = 0x01;
    
    // USAGE_MAXIMUM (Button 24)
    _hidReportDesc[_hidReportDescSize++] = 0x29;
    _hidReportDesc[_hidReportDescSize++] = btnBits;
    
    // LOGICAL_MINIMUM (0)
    _hidReportDesc[_hidReportDescSize++] = 0x15;
    _hidReportDesc[_hidReportDescSize++] = 0x00;
    
    // LOGICAL_MAXIMUM (1)
    _hidReportDesc[_hidReportDescSize++] = 0x25;
    _hidReportDesc[_hidReportDescSize++] = 0x01;
    
    // REPORT_COUNT (#)
    _hidReportDesc[_hidReportDescSize++] = 0x95;
    _hidReportDesc[_hidReportDescSize++] = btnBits;
    
    // REPORT_SIZE (1)
    _hidReportDesc[_hidReportDescSize++] = 0x75;
    _hidReportDesc[_hidReportDescSize++] = 0x01;
    
    // INPUT (Data,Var,Abs,Preferred)
    _hidReportDesc[_hidReportDescSize++] = 0x81;
    _hidReportDesc[_hidReportDescSize++] = 0x02;
    
    if (btnPaddingBits > 0) {
      // REPORT_COUNT (#)
      _hidReportDesc[_hidReportDescSize++] = 0x95;
      _hidReportDesc[_hidReportDescSize++] = btnPaddingBits;
      
      // REPORT_SIZE (1)
      _hidReportDesc[_hidReportDescSize++] = 0x75;
      _hidReportDesc[_hidReportDescSize++] = 0x01;
      
      // INPUT (Const,Var,Abs)
      _hidReportDesc[_hidReportDescSize++] = 0x81;
      _hidReportDesc[_hidReportDescSize++] = 0x03;
    }
  }

  // generic axis types
  if (genAxisCount > 0) {
  
    // USAGE_PAGE (Generic Desktop)
    _hidReportDesc[_hidReportDescSize++] = 0x05;
    _hidReportDesc[_hidReportDescSize++] = 0x01;
    
    for (uint8_t i = 0; i <= USBJOYS_CH_LAST; i++) {
      if (axisTypes[i] == 1) {
        for (uint8_t cnt = 0; cnt < typeCount[i]; cnt++) {
          // USAGE (#)
          _hidReportDesc[_hidReportDescSize++] = 0x09;
          _hidReportDesc[_hidReportDescSize++] = axisTypeCodes[i];
        }
      }
    }
    
    // LOGICAL_MINIMUM (0)
    _hidReportDesc[_hidReportDescSize++] = 0x16;
    _hidReportDesc[_hidReportDescSize++] = 0x00;
    _hidReportDesc[_hidReportDescSize++] = 0x00;
        
    // LOGICAL_MAXIMUM (2047)
    _hidReportDesc[_hidReportDescSize++] = 0x26;
    _hidReportDesc[_hidReportDescSize++] = 0xFF;
    _hidReportDesc[_hidReportDescSize++] = 0x07;
        
    // REPORT_SIZE (16)
    _hidReportDesc[_hidReportDescSize++] = 0x75;
    _hidReportDesc[_hidReportDescSize++] = 0x10;
    
    // REPORT_COUNT (#)
    _hidReportDesc[_hidReportDescSize++] = 0x95;
    _hidReportDesc[_hidReportDescSize++] = genAxisCount;
    
    // INPUT (Data,Var,Abs)
    _hidReportDesc[_hidReportDescSize++] = 0x81;
    _hidReportDesc[_hidReportDescSize++] = 0x02;
  }
  
  // sim axis types
  if (simAxisCount > 0) {
  
    // USAGE_PAGE (Simulation Controls)
    _hidReportDesc[_hidReportDescSize++] = 0x05;
    _hidReportDesc[_hidReportDescSize++] = 0x02;
    
    for (uint8_t i = 0; i <= USBJOYS_CH_LAST; i++) {
      if (axisTypes[i] == 2) {
        for (uint8_t cnt = 0; cnt < typeCount[i]; cnt++) {
          // USAGE (#)
          _hidReportDesc[_hidReportDescSize++] = 0x09;
          _hidReportDesc[_hidReportDescSize++] = axisTypeCodes[i];
        }
      }
    }
    
    // LOGICAL_MINIMUM (0)
    _hidReportDesc[_hidReportDescSize++] = 0x16;
    _hidReportDesc[_hidReportDescSize++] = 0x00;
    _hidReportDesc[_hidReportDescSize++] = 0x00;
        
    // LOGICAL_MAXIMUM (2047)
    _hidReportDesc[_hidReportDescSize++] = 0x26;
    _hidReportDesc[_hidReportDescSize++] = 0xFF;
    _hidReportDesc[_hidReportDescSize++] = 0x07;
        
    // REPORT_SIZE (16)
    _hidReportDesc[_hidReportDescSize++] = 0x75;
    _hidReportDesc[_hidReportDescSize++] = 0x10;
    
    // REPORT_COUNT (#)
    _hidReportDesc[_hidReportDescSize++] = 0x95;
    _hidReportDesc[_hidReportDescSize++] = simAxisCount;
    
    // INPUT (Data,Var,Abs)
    _hidReportDesc[_hidReportDescSize++] = 0x81;
    _hidReportDesc[_hidReportDescSize++] = 0x02;
  }

  // END_COLLECTION  
  _hidReportDesc[_hidReportDescSize++] = 0xc0;
  
  // END_COLLECTION  
  _hidReportDesc[_hidReportDescSize++] = 0xc0;
  
  // end of report desc
  
  _hidReportSize = ((btnBits + btnPaddingBits) / 8) + (_usbJoystickAxisCount * 2);
  
  //compare with the old description
  if (_hidReportDescSize != oldHIDReportDescSize) return true;
  if (memcmp(_hidReportDesc, oldHIDReportDesc, _hidReportDescSize) != 0) return true;
  
  return false;
}

extern "C" struct usbReport_t usbReportDesc()
{
  usbReport_t res = { _hidReportDesc, _hidReportDescSize };
  return res;
}

void addBitToReport(uint8_t val, uint8_t &bitcnt, uint8_t &bytecnt)
{
  if(val) _hidReport[bytecnt] |= 1 << bitcnt;
  bitcnt++;
  while (bitcnt >= 8) { bytecnt++; bitcnt -= 8; }
}

void usbStateUpdate()
{
  uint8_t rbitcnt = 0;
  uint8_t rcnt = 0;
  uint8_t chcnt = 0;
  uint8_t val = 0;

  memset(_hidReport, 0, MAX_HID_REPORT);

  for (uint8_t i = 0; i < _usbJoystickPushBtnCount; i++) {
    val = (channelOutputs[_usbJoystickChannels[chcnt]] > 0) ? 1 : 0;
    addBitToReport(val, rbitcnt, rcnt);
    chcnt++;
  }
  for (uint8_t i = 0; i < _usbJoystickSwitch2sCount; i++) {
    val = (channelOutputs[_usbJoystickChannels[chcnt]] > 0) ? 0b10 : 0b01;
    addBitToReport(val & 1, rbitcnt, rcnt);
    addBitToReport(val & 2, rbitcnt, rcnt);
    chcnt++;
  }
  for (uint8_t i = 0; i < _usbJoystickSwitch3sCount; i++) {
    val = 0b010;
    if (channelOutputs[_usbJoystickChannels[chcnt]] < 0) val = 0b001;
    else if (channelOutputs[_usbJoystickChannels[chcnt]] > 0) val = 0b100;
    addBitToReport(val & 1, rbitcnt, rcnt);
    addBitToReport(val & 2, rbitcnt, rcnt);
    addBitToReport(val & 4, rbitcnt, rcnt);
    chcnt++;
  }
  if (rbitcnt > 0) {
    rbitcnt = 0;
    rcnt++;
  }
  
  for (uint8_t i = 0; i < _usbJoystickAxisCount; i++) {
    int16_t value = channelOutputs[_usbJoystickChannels[chcnt]] + 1024;
    if ( value > 2047 ) value = 2047;
    else if ( value < 0 ) value = 0;
    _hidReport[rcnt++] = static_cast<uint8_t>(value & 0xFF);
    _hidReport[rcnt++] = static_cast<uint8_t>((value >> 8) & 0x07);
    chcnt++;
  }  
}

struct usbReport_t usbReport()
{
  usbStateUpdate();
  
  usbReport_t res = { _hidReport, _hidReportSize };
  return res;
}

