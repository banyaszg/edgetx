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

void clearInputs()
{
  memset(g_model.expoData, 0, sizeof(g_model.expoData));
}

void setDefaultInputs()
{
  for (int i=0; i<NUM_STICKS; i++) {
    uint8_t stick_index = channelOrder(i+1);
    ExpoData *expo = expoAddress(i);
    expo->srcRaw = MIXSRC_Rud - 1 + stick_index;
    expo->curve.type = CURVE_REF_EXPO;
    expo->chn = i;
    expo->weight = 100;
    expo->mode = 3; // TODO constant
    for (int c = 0; c < 3; c++) {
      g_model.inputNames[i][c] = STR_VSRCRAW[2 + 4 * stick_index + c];
    }
#if LEN_INPUT_NAME > 3
    g_model.inputNames[i][3] = '\0';
#endif
  }
  storageDirty(EE_MODEL);
}

void clearMixes()
{
  memset(g_model.mixData, 0, sizeof(g_model.mixData));
}

void setDefaultMixes()
{
  for (int i=0; i<NUM_STICKS; i++) {
    MixData * mix = mixAddress(i);
    mix->destCh = i;
    mix->weight = 100;
    mix->srcRaw = i+1;
  }
  storageDirty(EE_MODEL);
}

void setDefaultModelRegistrationID()
{
  memcpy(g_model.modelRegistrationID, g_eeGeneral.ownerRegistrationID, PXX2_LEN_REGISTRATION_ID);
}

void setDefaultGVars()
{
#if defined(FLIGHT_MODES) && defined(GVARS)
  for (int fmIdx = 1; fmIdx < MAX_FLIGHT_MODES; fmIdx++) {
    for (int gvarIdx = 0; gvarIdx < MAX_GVARS; gvarIdx++) {
      g_model.flightModeData[fmIdx].gvars[gvarIdx] = GVAR_MAX + 1;
    }
  }
#endif
}

void setUSBJoystickDefaults()
{
  TRACE("setUSBJoystickDefaults");
  g_model.usbJoystickMode = USBJOYS_GAMEPAD;
  if (MAX_OUTPUT_CHANNELS >= 8) {  
    g_model.usbJoystickCh[0].mode = USBJOYS_CH_X_AXIS;
    g_model.usbJoystickCh[1].mode = USBJOYS_CH_Y_AXIS;
    g_model.usbJoystickCh[2].mode = USBJOYS_CH_Z_AXIS;
    g_model.usbJoystickCh[3].mode = USBJOYS_CH_RX_AXIS;
    g_model.usbJoystickCh[4].mode = USBJOYS_CH_RY_AXIS;
    g_model.usbJoystickCh[5].mode = USBJOYS_CH_RZ_AXIS;
    g_model.usbJoystickCh[6].mode = USBJOYS_CH_SLIDER;
    g_model.usbJoystickCh[7].mode = USBJOYS_CH_SLIDER;
  }
  for (int i = 8; i < MAX_OUTPUT_CHANNELS; i++) {
    g_model.usbJoystickCh[i].mode = USBJOYS_CH_PUSHBTN;
  }
}

void setVendorSpecificModelDefaults(uint8_t id)
{
#if defined(FRSKY_RELEASE)
  g_model.moduleData[INTERNAL_MODULE].type = IS_PXX2_INTERNAL_ENABLED() ? MODULE_TYPE_ISRM_PXX2 : MODULE_TYPE_XJT_PXX1;
  g_model.moduleData[INTERNAL_MODULE].channelsCount = defaultModuleChannels_M8(INTERNAL_MODULE);
  #if defined(EEPROM)
    g_model.header.modelId[INTERNAL_MODULE] = findNextUnusedModelId(id, INTERNAL_MODULE);
    modelHeaders[id].modelId[INTERNAL_MODULE] = g_model.header.modelId[INTERNAL_MODULE];
  #endif
#endif

    // TODO: we should probably have some default trainer mode
    //       per radio, depending on what is supported
    //
#if defined(PCBXLITE)
  g_model.trainerData.mode = TRAINER_MODE_MASTER_BLUETOOTH;
#endif

#if defined(RADIOMASTER_RTF_RELEASE)
  // Those settings are for headless radio
  g_model.trainerData.mode = TRAINER_MODE_SLAVE;
  g_model.moduleData[INTERNAL_MODULE].type = MODULE_TYPE_MULTIMODULE;
  g_model.moduleData[INTERNAL_MODULE].setMultiProtocol(MODULE_SUBTYPE_MULTI_FRSKY);
  g_model.moduleData[INTERNAL_MODULE].subType = MM_RF_FRSKY_SUBTYPE_D8;
  g_model.moduleData[INTERNAL_MODULE].failsafeMode = FAILSAFE_NOPULSES;
#endif
}

void applyDefaultTemplate()
{
  setDefaultInputs();
  setDefaultMixes();
  setDefaultGVars();
  setUSBJoystickDefaults();

  setDefaultModelRegistrationID();

#if defined(FUNCTION_SWITCHES)
  g_model.functionSwitchConfig = DEFAULT_FS_CONFIG;
  g_model.functionSwitchGroup = DEFAULT_FS_GROUPS;
  g_model.functionSwitchStartConfig = DEFAULT_FS_STARTUP_CONFIG;
  g_model.functionSwitchLogicalState = 0;
#endif

#if defined(COLORLCD)
  //TODO: not sure yet we need it here
  loadDefaultLayout();

  // enable switch warnings
  for (int i = 0; i < NUM_SWITCHES; i++) {
    g_model.switchWarningState |= (1 << (3*i));
  }
#endif

  // TODO: what about switch warnings in non-color LCD radios?
}


void setModelDefaults(uint8_t id)
{
  memset(&g_model, 0, sizeof(g_model));
  applyDefaultTemplate();
  
  setVendorSpecificModelDefaults(id);

#if !defined(STORAGE_MODELSLIST)
  // EEPROM model indexes starting with 0
  id++;
#endif
  strAppendUnsigned(strAppend(g_model.header.name, STR_MODEL), id, 2);

#if defined(LUA) && defined(PCBTARANIS) // Horus uses menuModelWizard() for wizard
  if (isFileAvailable(WIZARD_PATH "/" WIZARD_NAME)) {
    f_chdir(WIZARD_PATH);
    luaExec(WIZARD_NAME);
  }
#endif
}
