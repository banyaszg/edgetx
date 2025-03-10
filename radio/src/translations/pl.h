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
 *
 */

// PL translations author: Jacek Drewniak <jpdjpd33@gmail.com>

/*
 * Formatting octal codes available in TR_ strings:
 *  \037\x           -sets LCD x-coord (x value in octal)
 *  \036             -newline
 *  \035             -horizontal tab (ARM only)
 *  \001 to \034     -extended spacing (value * FW/2)
 *  \0               -ends current string
 */

#define TR_MIN_PLURAL2  2
#define TR_MAX_PLURAL2  4
// For this number of minute in the last decimal place singular form is used in
// plural
#define TR_USE_SINGULAR_IN_PLURAL 0
#define TR_USE_PLURAL2_SPECIAL_CASE 1
// If the number of minutes is above this value PLURAL2 is used
#define TR_USE_PLURAL2 INT_MAX

#define TR_MINUTE_SINGULAR     "minuta"
#define TR_MINUTE_PLURAL1      "minuty"
#define TR_MINUTE_PLURAL2      "minut"

#define TR_OFFON               "WYŁ","ZAŁ"
#define TR_MMMINV              "---","REV"
#define TR_VBEEPMODE           "Cichy","Alarm","BezPr","Wsz."
#define TR_VBLMODE             TR("Wył","Wyłącz"),TR("Przy","Przycisk"),TR("Drąż","Drązki"),"Oba",TR("Zał","Włącz")
#define TR_TRNMODE             "Wył",TR("+=","Dodaj"),TR(":=","Zastąp")
#define TR_TRNCHN              "KN1","KN2","KN3","KN4"
#define TR_AUX_SERIAL_MODES    "Wyłącz","S-Port Kopia","Telemetria","Trener SBUS","LUA","CLI","GPS","Debug","SpaceMouse","Moduł zewnętrzny"
#define TR_SWTYPES             "Brak","Chwil.","2POZ","3POZ"
#define TR_POTTYPES            "Brak",TR("Pot","Potencjometr"),TR("Pot w. det","Poten z zapadką"),"Suwak",TR("Multipos","Przeł.Wielopoz."),"Axis X","Axis Y","Switch"
#define TR_VPERSISTENT         "Wyłącz","Lot","Ręczny Reset"
#define TR_COUNTRY_CODES       TR("US","Ameryka"),TR("JP","Japonia"),TR("EU", "Europa")
#define TR_USBMODES            "Ask",TR("Joyst","Joystick"),TR("SDCard","Storage"),"Serial"
#define TR_JACK_MODES          "Ask","Audio","Trainer"

#define TR_SBUS_INVERSION_VALUES       "normal","not inverted"
#define TR_MULTI_CUSTOM        "Custom"
#define TR_VTRIMINC            TR("Expo","Expotencja"),TR("B.Dokł","B.Dokładny"),TR("Dokł.","Dokładny"),"Średni",TR("Zgrubn","Zgrubny")
#define TR_VDISPLAYTRIMS       "Nie","Zmień","Tak"
#define TR_VBEEPCOUNTDOWN      "Cichy","Pik","Dźwięk","Wibrac",TR2_2("P & W","Pik & Wibrac"),TR2_2("Dzw & Wbr","Dźwięk & Wibrac")
#define TR_COUNTDOWNVALUES     "5s","10s","20s","30s"
#define TR_VVARIOCENTER        "Ton","Cicho"
#define TR_CURVE_TYPES         "Standard","Własny"
#define TR_ADCFILTERVALUES     "Globalne","WYŁ","ZAŁ"

#define TR_VCURVETYPE                  "Diff","Expo","Func","Cstm"
#define TR_VCURVEFUNC          "---","x>0","x<0","|x|","f>0","f<0","|f|"
#define TR_VMLTPX              "Dodaj","Mnóż","Zastąp"
#define TR_VMLTPX2             "+=","*=",":="

#if LCD_W >= 212
  #define TR_CSWTIMER          "Timer"
  #define TR_CSWSTICKY         "Stały"
  #define TR_CSWSTAY           "Brzeg"
#else
  #define TR_CSWTIMER          "Tim"
  #define TR_CSWSTICKY         "Stały"
  #define TR_CSWSTAY           "Brzeg"
#endif

#define TR_CSWEQUAL  "a=x"
#define TR_VCSWFUNC  "---",TR_CSWEQUAL,"a" STR_CHAR_TILDE "x","a>x","a<x","|a|>x","|a|<x","AND","OR","XOR",TR_CSWSTAY,"a=b","a>b","a<b",STR_CHAR_DELTA "≥x","|" STR_CHAR_DELTA "|≥x",TR_CSWTIMER,TR_CSWSTICKY

#define TR_SF_TRAINER         "Trener"
#define TR_SF_INST_TRIM       "Inst-Trim"
#define TR_SF_RESET           "Resetuj"
#define TR_SF_SET_TIMER       "Ustaw"
#define TR_SF_VOLUME          "Głośność"
#define TR_SF_FAILSAFE        "SetFailsafe"
#define TR_SF_RANGE_CHECK     "RangeCheck"
#define TR_SF_MOD_BIND        "ModuleBind"
#define TR_SF_RGBLEDS         "RGB leds"
 
#define TR_SOUND              "GrajDźwięk"
#define TR_PLAY_TRACK         "GrajŚcieżk"
#define TR_PLAY_VALUE         TR("Graj Wart","GrajWartoś")
#define TR_SF_HAPTIC          "Wibracje"
#define TR_SF_PLAY_SCRIPT     "SkryptyLua"
#define TR_SF_BG_MUSIC        "Muz. tła"
#define TR_SF_BG_MUSIC_PAUSE  "Muz. tła ||"
#define TR_SF_LOGS            "Logi->SD"
#define TR_ADJUST_GVAR        "Ustaw"
#define TR_SF_BACKLIGHT       "Podświetl"
#define TR_SF_VARIO           "Wario"
#define TR_SF_TEST            "Test"
#define TR_SF_SAFETY          TR("Bezp.","Bezpiecz")

#define TR_SF_SCREENSHOT      "Zrzut Ekra"
#define TR_SF_RACING_MODE     "RacingMode"
#define TR_SF_DISABLE_TOUCH   "No Touch"
#define TR_SF_DISABLE_AUDIO_AMP TR("Wycisz wzm.", "Wycisz wzmacniacz audio")
#define TR_SF_SET_SCREEN      "Set Main Screen"

#define TR_FSW_RESET_TELEM     TR("Telm", "Telemetra")
#define TR_FSW_RESET_TIMERS    "Tmr1","Tmr2","Tmr3"


#define TR_VFSWRESET           TR_FSW_RESET_TIMERS,TR("All","Flight"),TR_FSW_RESET_TELEM
#define TR_FUNCSOUNDS          TR("Bp1","Beep1"),TR("Bp2","Beep2"),TR("Bp3","Beep3"),TR("Ost1","Ostrz1"),TR("Ost2","Ostrz2"),TR("Chee","Cheep"),TR("Rata","Ratata"),"Tick",TR("Syre","Syrena"),TR("Dzwo","Dzwone"),TR("Crck","Krytcz"),TR("Alrm","AlmZeg")

#define LENGTH_UNIT_IMP        "ft"
#define SPEED_UNIT_IMP         "mph"
#define LENGTH_UNIT_METR       "m"
#define SPEED_UNIT_METR        "kmh"

#define TR_VUNITSSYSTEM        TR("Metr.","Metryczn"),TR("Imper.","Imperial")
#define TR_VTELEMUNIT          "-","V","A","mA","kts","m/s","f/s","kmh","mph","m","ft","°C","°F","%","mAh","W","mW","dB","rpm","g","°","rad","ml","fOz","mlm","Hz","ms","us","km","dBm"

#define STR_V                  (STR_VTELEMUNIT[1])
#define STR_A                  (STR_VTELEMUNIT[2])

#define TR_VTELEMSCREENTYPE    "Brak","Liczb","Paski","Skrypt"
#define TR_GPSFORMAT           "DMS","NMEA"


#define TR_VSWASHTYPE                  "---","120","120X","140","90"

#define TR_STICK_NAMES0        "SK"
#define TR_STICK_NAMES1        "SW"
#define TR_STICK_NAMES2        "Gaz"
#define TR_STICK_NAMES3        "Lot"
#define TR_SURFACE_NAMES0      "SK"
#define TR_SURFACE_NAMES1      "Gaz"

#if defined(PCBNV14)
#define  TR_RFPOWER_AFHDS2             "Default","High"
#endif

#define TR_ROTARY_ENCODERS
#define TR_ROTENC_SWITCHES

#define TR_ON_ONE_SWITCHES      "ON","One"

#if defined(USE_HATS_AS_KEYS)
#define TR_HATSMODE             "Tryb grzybków"
#define TR_HATSOPT              "Tylko trymy","Tylko przyciski","Przełączane","Globalne"
#define TR_HATSMODE_TRIMS       "Tryb grzybków: trymy"
#define TR_HATSMODE_KEYS        "Tryb grzybków: przyciski"
#endif

#if defined(COLORLCD)
  #define TR_ROTARY_ENC_OPT  "Normal","Inverted"
#else
  #define TR_ROTARY_ENC_OPT  "Normal","Inverted","V-I H-N","V-I H-A"
#endif

#if defined(IMU)
  #define TR_IMU_VSRCRAW       "TltX","TltY",
#else
  #define TR_IMU_VSRCRAW
#endif

#if defined(HELI)
  #define TR_CYC_VSRCRAW      "CYC1","CYC2","CYC3"
#else
  #define TR_CYC_VSRCRAW      "[C1]","[C2]","[C3]"
#endif


#define TR_SRC_BATT                    "Batt"
#define TR_SRC_TIME                    "Time"
#define TR_SRC_GPS                     "GPS"
#define TR_SRC_TIMER                   "Tmr"

#define TR_VTMRMODES                   "WYŁ","ABS","Strt","THs","TH%","THt"
#define TR_VTRAINER_MASTER_OFF         "OFF"
#define TR_VTRAINER_MASTER_JACK        "Trener/Jack"
#define TR_VTRAINER_SLAVE_JACK         "Uczeń/Jack"
#define TR_VTRAINER_MASTER_SBUS_MODULE "Trener/SBUS Moduł"
#define TR_VTRAINER_MASTER_CPPM_MODULE "Trener/CPPM Moduł"
#define TR_VTRAINER_MASTER_BATTERY     "Trener/Serial"
#define TR_VTRAINER_BLUETOOTH          "Master/" TR("BT","Bluetooth"), "Slave/" TR("BT","Bluetooth")
#define TR_VTRAINER_MULTI              "Master/Multi"
#define TR_VFAILSAFE                   "Brak","Utrzymuj","Własne","0 sygnału","Odbiornik"
#define TR_VSENSORTYPES                "Użytkownik","Obliczone"
#define TR_VFORMULAS                   "Dodaj","Średnie","Min","Max","Mnóż","Zliczani","Komórka","Zużycie","Zasięg"
#define TR_VPREC                       "0.--","0.0 ","0.00"
#define TR_VCELLINDEX                  "Niskie","1","2","3","4","5","6","7","8","Wysokie","Delta"
#define TR_TEXT_SIZE                   "Standard","Tiny","Small","Mid","Double"
#define TR_SUBTRIMMODES                STR_CHAR_DELTA" (center only)","= (symetrical)"
#define TR_TIMER_DIR                   TR("Remain", "Show Remain"), TR("Elaps.", "Show Elapsed")
#define TR_PPMUNIT                     "0.--","0.0","us"

#if defined(COLORLCD)
#if defined(BOLD)
#define TR_FONT_SIZES                  "STD"
#else
#define TR_FONT_SIZES                  "STD","BOLD","XXS","XS","L","XL","XXL"
#endif
#endif

#if defined(PCBTARANIS) || defined(PCBHORUS)
  #define TR_ENTER                     "[ENTER]"
#elif defined(PCBNV14)
  #define TR_ENTER                     "[NEXT]"
#else
  #define TR_ENTER                     "[MENU]"
#endif

#if defined(PCBHORUS)
  #define TR_EXIT                      "RTN"
  #define TR_OK                        TR_ENTER
#else
  #define TR_EXIT                      "EXIT"
  #define TR_OK                        TR("\010" "\010" "\010" "[OK]", "\010" "\010" "\010" "\010" "\010" "[OK]")
#endif

#if defined(PCBTARANIS)
  #define TR_POPUPS_ENTER_EXIT         TR(TR_EXIT "\010" TR_ENTER, TR_EXIT "\010" "\010" "\010" "\010" TR_ENTER)

#else
  #define TR_POPUPS_ENTER_EXIT         TR_ENTER "\010" TR_EXIT
#endif

#define TR_MENUWHENDONE        CENTER "\006" TR_ENTER " > DALEJ"
#define TR_FREE                "woln"
#define TR_YES                 "Tak"
#define TR_NO                  "Nie"
#define TR_DELETEMODEL         "SKASUJ MODEL"
#define TR_COPYINGMODEL        "Kopiuj model.."
#define TR_MOVINGMODEL         "Przenieś model."
#define TR_LOADINGMODEL        "Załaduj model.."
#define TR_UNLABELEDMODEL      "Bez etyk."
#define TR_NAME                "Nazwa"
#define TR_MODELNAME           "Nazwa modelu"
#define TR_PHASENAME           "Nazwa Fazy"
#define TR_MIXNAME             "Nazwa Mix"
#define TR_INPUTNAME           "Wpisz Nazw"
#define TR_EXPONAME            "LiniaNazw"
#define TR_BITMAP              "Obrazek"
#define TR_NO_PICTURE          "Bez obrazka"
#define TR_TIMER               TR("Timer", "Timer ")
#define TR_START               "Start"
#define TR_ELIMITS             TR("Limi+25%", "Kanał +/- 125% ")
#define TR_ETRIMS              TR("E.Trym ", "Poszer Trymery")
#define TR_TRIMINC             "Krok Trym"
#define TR_DISPLAY_TRIMS       TR("Pok.Trym.","Pokaż Trymery")
#define TR_TTRACE              TR("Źród gaz", INDENT "Źródło gazu ")
#define TR_TTRIM               TR("TryGaz", INDENT "TrymWolnObrotó")
#define TR_TTRIM_SW            TR("T-Trim-Sw", INDENT "Trim switch")
#define TR_BEEPCTR             TR("ŚrodBeep", "Pikn.Środka")
#define TR_USE_GLOBAL_FUNCS    TR("Funk.Glb.","Użyj Funkcji Glb")
#define TR_PROTOCOL            TR("Proto", "Protokół")
#define TR_PPMFRAME            INDENT "Ramka PPM"
#define TR_REFRESHRATE               TR(INDENT "Refresh", INDENT "Refresh rate")
#define STR_WARN_BATTVOLTAGE           TR(INDENT "Output is VBAT: ", INDENT "Uwaga: output level is VBAT: ")
#define TR_WARN_5VOLTS                 "Uwaga: output level is 5 volts"
#define TR_MS                  "ms"
#define TR_SWITCH              "Przełą"
#define TR_FUNCTION_SWITCHES   "Ustawiane przełączniki"
#define TR_SF_SWITCH           "Trigger"
#define TR_TRIMS               "Trymy"
#define TR_FADEIN              "Pojawia"
#define TR_FADEOUT             "Zanik   "
#define TR_DEFAULT             "(Bazowa) "
#if defined(COLORLCD)
  #define TR_CHECKTRIMS        "Sprawdź trymy"
#else
  #define TR_CHECKTRIMS        CENTER "\006Spr  \012Trymy"
#endif
#define OFS_CHECKTRIMS         CENTER_OFS+(9*FW)
#define TR_SWASHTYPE           "Typ tarczy"
#define TR_COLLECTIVE          TR("Kolektyw", "Źródło Kolektywu")
#define TR_AILERON             TR("Lateral cyc.", "Lateral cyc. source")
#define TR_ELEVATOR            TR("Long. cyc.", "Long. cyc. source")
#define TR_SWASHRING           "Tarcza    "
#define TR_MODE                "Tryb"
#if LCD_W > LCD_H
  #define TR_LEFT_STICK        "Lewy"
#else
  #define TR_LEFT_STICK        "Lewy"
#endif
#define TR_SUBTYPE             INDENT "Podtyp"
#define TR_NOFREEEXPO          "BrakWoln.Expo!"
#define TR_NOFREEMIXER         "BrakWoln.Mixów!"
#define TR_SOURCE               "Źródło"
#define TR_WEIGHT              "Waga "
#define TR_SIDE                "Strona"
#define TR_OFFSET              "Ofset "
#define TR_TRIM                "Trym"
#define TR_DREX                "DRex"
#define DREX_CHBOX_OFFSET      30
#define TR_CURVE               "Krzywa"
#define TR_FLMODE              "Tryb"
#define TR_MIXWARNING          "UWAGA"
#define TR_OFF                 "Wył."
#define TR_ANTENNA                     "Antenna"
#define TR_NO_INFORMATION              TR("No info", "No information")
#define TR_MULTPX              "Złącz."
#define TR_DELAYDOWN           "Opózn.(-)"
#define TR_DELAYUP             "Opózn.(+)"
#define TR_SLOWDOWN            "Spowoln.(-)"
#define TR_SLOWUP              "Spowoln.(+)"
#define TR_MIXES               "MIKSERY"
#define TR_CV                  "Kr"
#if defined(PCBNV14)
#define TR_GV                  "ZG"
#else
#define TR_GV                  TR("G", "ZG")
#endif
#define TR_RANGE               INDENT "Zakres"
#define TR_CENTER              INDENT "Środek"
#define TR_ALARM               "Alarm"
#define TR_BLADES              "Łopaty śmigla"
#define TR_SCREEN              "Ekran "
#define TR_SOUND_LABEL         "Dźwięk"
#define TR_LENGTH              "Długość"
#define TR_BEEP_LENGTH         "Dług. Beepa"
#define TR_BEEP_PITCH          "Dźwięk"
#define TR_HAPTIC_LABEL        "Wibracja"
#define TR_STRENGTH            "Siła"
#define TR_IMU_LABEL           "IMU"
#define TR_IMU_OFFSET          "Offset"
#define TR_IMU_MAX             "Max"
#define TR_CONTRAST            "Kontrast"
#define TR_ALARMS_LABEL        "Alarmy"
#define TR_BATTERY_RANGE       TR("PokażPasBat.", "Pokaż pasek bateri")
#define TR_BATTERYCHARGING     "Ładowanie..."
#define TR_BATTERYFULL         "Bateria naładowana"
#define TR_BATTERYNONE         "Brak!"
#define TR_BATTERYWARNING      "Bateria rozładowana"
#define TR_INACTIVITYALARM     "Alarm bezczynności"
#define TR_MEMORYWARNING       "Pełna pamięć"
#define TR_ALARMWARNING        "Wyłącz dźwięk"
#define TR_RSSI_SHUTDOWN_ALARM   TR("Rssi Shutdown", "Check Rssi on Shutdown")
#define TR_MODEL_STILL_POWERED "Model jest włączony"
#define TR_TRAINER_STILL_CONNECTED     "Uczeń ciągle podłączony"
#define TR_USB_STILL_CONNECTED         "USB jest podłączone"
#define TR_MODEL_SHUTDOWN              "Wyłączyć?"
#define TR_PRESS_ENTER_TO_CONFIRM      "Press enter to confirm"
#define TR_THROTTLE_LABEL      "Gaz"
#define TR_THROTTLE_START      "Gaz Start"
#define TR_THROTTLEREVERSE     TR("OdwrGaz", INDENT "OdwrGaz")
#define TR_MINUTEBEEP          TR("Minuta", "PikCoMinutę")
#define TR_BEEPCOUNTDOWN       INDENT "Odliczanie"
#define TR_PERSISTENT          TR(INDENT "Dokł.", INDENT "Dokładny")
#define TR_BACKLIGHT_LABEL     "Podświetl"
#define TR_GHOST_MENU_LABEL            "GHOST MENU"
#define TR_STATUS                      "Status"
#define TR_BLDELAY             INDENT"Czas trwania"
#define TR_BLONBRIGHTNESS      INDENT"Jasnośc wł."
#define TR_BLOFFBRIGHTNESS     INDENT"Jasność wył."
#define TR_KEYS_BACKLIGHT      "Podśw. przycisków"
#define TR_BLCOLOR             "Kolor"
#define TR_SPLASHSCREEN        "Logo ekranu"
#define TR_PLAY_HELLO                  "Dźwięk uruchomienia"
#define TR_PWR_ON_DELAY                "Pwr On delay"
#define TR_PWR_OFF_DELAY               "Pwr Off delay"
#define TR_THROTTLE_WARNING     TR(INDENT"OstrzGaz", INDENT "OstrzeżenieGaz")
#define TR_CUSTOM_THROTTLE_WARNING     TR(INDENT INDENT INDENT INDENT "InnePoł", INDENT INDENT INDENT INDENT "Inne położenie?")
#define TR_CUSTOM_THROTTLE_WARNING_VAL TR("Poł. %", "Położenie %")
#define TR_SWITCHWARNING       TR(INDENT "OstrzPrzeł", INDENT "PozycjaPrzeł")
#define TR_POTWARNINGSTATE     TR(INDENT "Pot&Slid.", INDENT "Pots & sliders")
#define TR_SLIDERWARNING       TR(INDENT "Slid. pos.", INDENT "Slider positions")
#define TR_POTWARNING          TR(INDENT "Ostrz.Poten.", INDENT "PozycjaPotencj.")
#define TR_TIMEZONE            TR("Strefa czasowa" ,"Strefa czasowa GPS")
#define TR_ADJUST_RTC          TR("RegulujRTC", "RegulujRTC")
#define TR_GPS                 "GPS"
#define TR_DEF_CHAN_ORD        TR("Baz.kolejn.kan.", "Bazowa kolejność kanałów")
#define TR_STICKS              "Drążki"
#define TR_POTS                "Pots"
#define TR_SWITCHES            "Przełącz"
#define TR_SWITCHES_DELAY      "Opóźn.Przeł."
#define TR_SLAVE               "Uczeń"
#define TR_MODESRC             " Tryb\006% Źródło"
#define TR_MULTIPLIER          "Mnożnik"
#define TR_CAL                 "Kal."
#define TR_CALIBRATION                 "Kalibracja"
#define TR_VTRIM               "Trym - +"
#define TR_CALIB_DONE          "Kalibracja zakończona"
#if defined(PCBHORUS)
  #define TR_MENUTOSTART       "Press [Enter] to start"
  #define TR_SETMIDPOINT       "Center sticks/pots/sliders and press [Enter]"
  #define TR_MOVESTICKSPOTS    "Move sticks, pots and sliders and press [Enter]"
#elif defined(COLORLCD)
  #define TR_MENUTOSTART       TR_ENTER " KALIBRUJ"
  #define TR_SETMIDPOINT       "Centruj drażki/potencj"
  #define TR_MOVESTICKSPOTS    "Poruszaj drążkami/pot"
#else
  #define TR_MENUTOSTART       CENTER "\010" TR_ENTER " KALIBRUJ"
  #define TR_SETMIDPOINT       TR(CENTER "\002Cenruj drążki/potencj",CENTER "\010Ustaw drązki/potencj na środku")
  #define TR_MOVESTICKSPOTS    "Poruszaj drążkami/pot"
#endif
#define TR_TXnRX                      "Tx:\0Rx:"
#define OFS_RX                        4
#define TR_NODATA                     CENTER "Brak Danych"
#define TR_US                         "us"
#define TR_HZ                         "Hz"
#define TR_TMIXMAXMS                  "TmixMaks"
#define TR_FREE_STACK                 "Wolny stos"
#define TR_INT_GPS_LABEL              "Wewnęt. GPS"
#define TR_HEARTBEAT_LABEL            "Heartbeat"
#define TR_LUA_SCRIPTS_LABEL          "Skrypty Lua"
#define TR_FREE_MEM_LABEL             "Free mem"
#define TR_DURATION_MS                TR("[C]","Czas trwania(ms): ")
#define TR_INTERVAL_MS                TR("[O]","Okres(ms): ")
#define TR_MEM_USED_SCRIPT            "Skrypt(B): "
#define TR_MEM_USED_WIDGET            "Widget(B): "
#define TR_MEM_USED_EXTRA             "Ekstra(B): "
#define TR_STACK_MIX                  "Mix: "
#define TR_STACK_AUDIO                "Audio: "
#define TR_GPS_FIX_YES                "Fix: Tak"
#define TR_GPS_FIX_NO                 "Fix: Nie"
#define TR_GPS_SATS                   "Sat: "
#define TR_GPS_HDOP                   "Hdop: "
#define TR_STACK_MENU                 "Menu: "
#define TR_TIMER_LABEL                "Timer"
#define TR_THROTTLE_PERCENT_LABEL     "Throttle %"
#define TR_BATT_LABEL                 "Battery"
#define TR_SESSION                    "Sesja"
#define TR_MENUTORESET         TR_ENTER " >> Reset"
#define TR_PPM_TRAINER         "TR"
#define TR_CH                  "KN"
#define TR_MODEL               "MODEL"
#if defined(SURFACE_RADIO)
#define TR_FM                  "DM"
#else
#define TR_FM                  "FL"
#endif
#define TR_EEPROMLOWMEM        "Mało pamięci EEPROM"
#define TR_PRESS_ANY_KEY_TO_SKIP   "Wciśnij guzik->ignoruj"
#define TR_THROTTLE_NOT_IDLE     "Gaz nie na zerze"
#define TR_ALARMSDISABLED      "Alarmy wyłączone"
#define TR_PRESSANYKEY         TR("\010Wciśnij jakiś klawisz","Wciśnij jakiś klawisz")
#define TR_BADEEPROMDATA       "\006Błąd danych EEPROM"
#define TR_BAD_RADIO_DATA      "Brak lub nieprawidłowe dane radia"
#define TR_RADIO_DATA_RECOVERED        TR3("Using backup radio data","Using backup radio settings","Radio settings recovered from backup")
#define TR_RADIO_DATA_UNRECOVERABLE    TR3("Radio settings invalid","Radio settings not valid", "Unable to read valid radio settings")
#define TR_EEPROMFORMATTING    "\004Formatowanie EEPROM"
#define TR_STORAGE_FORMAT      "Storage Preparation"
#define TR_EEPROMOVERFLOW      "Przeładowany EEPROM"
#define TR_RADIO_SETUP      "USTAWIENIA RADIA"
#define TR_MENUTRAINER         "TRENER"
#define TR_MENUSPECIALFUNCS    "FUNKCJE GLOBALNE"
#define TR_MENUVERSION         "WERSJA"
#define TR_MENU_RADIO_SWITCHES            TR("PRZEŁ","TEST PRZEŁ")
#define TR_MENU_RADIO_ANALOGS             TR("WE-ANA","WEJŚCIA ANALOG.")
#define TR_MENU_RADIO_ANALOGS_CALIB       "CALIBRATED ANALOGS"
#define TR_MENU_RADIO_ANALOGS_RAWLOWFPS   "RAW ANALOGS (5 Hz)"
#define TR_MENUCALIBRATION                "KALIBRACJA"
#define TR_MENU_FSWITCH                   "USTAWIANE PRZEŁĄCZNIKI"
#if defined(COLORLCD)
  #define TR_TRIMS2OFFSETS     "Trymery => Subtrimy"
#else
  #define TR_TRIMS2OFFSETS     "\006Trims => Subtrims"
#endif
#define TR_CHANNELS2FAILSAFE  "Channels=>Failsafe"
#define TR_CHANNEL2FAILSAFE   "Channel=>Failsafe"
#define TR_MENUMODELSEL        TR("WYB.MODEL","WYBÓR MODELU")
#define TR_MENU_MODEL_SETUP           TR("USTAW","USTAW MODELU")
#if defined(SURFACE_RADIO)
#define TR_MENUFLIGHTMODES    "DRIVE MODES"
#define TR_MENUFLIGHTMODE     "DRIVE MODE"
#else
#define TR_MENUFLIGHTMODE     "FAZA LOTU"
#define TR_MENUFLIGHTMODES    "FAZY LOTU"
#endif
#define TR_MENUHELISETUP       "USTAW HELI"

  #define TR_MENUINPUTS        "WEJŚCIA"
  #define TR_MENULIMITS        "WYJŚCIA"

#define TR_MENUCURVES          "KRZYWE"
#define TR_MENUCURVE           "KRZYWA"
#define TR_MENULOGICALSWITCH    "PRZEŁ. LOGICZNY"
#define TR_MENULOGICALSWITCHES   TR("PRZEŁ. LOG.", "PRZEŁ. LOGICZNE")
#define TR_MENUCUSTOMFUNC      "FUNKCJE SPECJALNE"
#define TR_MENUCUSTOMSCRIPTS   "WŁASNE SKRYPTY"
#define TR_MENUTELEMETRY       "TELEMETRIA"
#define TR_MENUSTAT            "STAT"
#define TR_MENUDEBUG           "DEBUG"
#define TR_MONITOR_CHANNELS1   "MONITOR KANAŁÓW 1/8"
#define TR_MONITOR_CHANNELS2   "MONITOR KANAŁÓW 9/16"
#define TR_MONITOR_SWITCHES    "MONITOR PRZEŁ. LOGICZNYCH"
#define TR_MONITOR_CHANNELS3   "MONITOR KANAŁÓW 17/24"
#define TR_MONITOR_CHANNELS4   "MONITOR KANAŁÓW 25/32"
#define TR_MONITOR_OUTPUT_DESC "Wyjścia"
#define TR_MONITOR_MIXER_DESC  "Mixers"
  #define TR_RECEIVER_NUM      TR("Nr RX", "Nr odbiornika")
  #define TR_RECEIVER          INDENT "Odbiornik"
#define TR_MULTI_RFTUNE        TR("Freq tune", "RF Freq. fine tune")
#define TR_MULTI_RFPOWER               "Moc RF"
#define TR_MULTI_WBUS                  "Wyjście"
#define TR_MULTI_TELEMETRY             "Telemetria"
#define TR_MULTI_VIDFREQ       TR("Vid. freq.", "Video frequency")
#define TR_RF_POWER       "Moc RF"
#define TR_MULTI_FIXEDID               TR("FixedID", "Fixed ID")
#define TR_MULTI_OPTION        TR("Opcja", "Wartość opcji")
#define TR_MULTI_AUTOBIND      TR(INDENT "Bind Ch.",INDENT "Bind on channel")
#define TR_DISABLE_CH_MAP              TR("No Ch. map", "Disable Ch. map")
#define TR_DISABLE_TELEM               TR("No Telem", "Disable Telemetry")
#define TR_MULTI_DSM_AUTODTECT TR(INDENT "Autodetect", INDENT "Autodetect format")
#define TR_MULTI_LOWPOWER      TR(INDENT "Low power", INDENT "Low power mode")
#define TR_MULTI_LNA_DISABLE            INDENT "LNA disable"
#define TR_MODULE_TELEMETRY            TR(INDENT "S.Port", INDENT "S.Port link")
#define TR_MODULE_TELEM_ON             TR("ON", "Enabled")
#define TR_DISABLE_INTERNAL         TR("Disable int. RF", "Disable internal RF")
#define TR_MODULE_NO_SERIAL_MODE       TR("!serial mode", "Not in serial mode")
#define TR_MODULE_NO_INPUT             TR("No input", "No serial input")
#define TR_MODULE_NO_TELEMETRY         TR3( "No telmetry", "No MULTI_TELEMETRY", "No telemetry (enable MULTI_TELEMETRY)")
#define TR_MODULE_WAITFORBIND          "Bind to load protocol"
#define TR_MODULE_BINDING              "Binding"
#define TR_MODULE_UPGRADE_ALERT        TR3("Upg. needed", "Module upgrade required", "Module\nUpgrade required")
#define TR_MODULE_UPGRADE              TR("Upg. advised", "Module update recommended")
#define TR_REBIND                      "Rebinding required"
#define TR_REG_OK                      "Registration ok"
#define TR_BIND_OK                     "Bind successful"
#define TR_BINDING_CH1_8_TELEM_ON               "Ch1-8 Telem WŁ"
#define TR_BINDING_CH1_8_TELEM_OFF               "Ch1-8 Telem WYŁ"
#define TR_BINDING_CH9_16_TELEM_ON               "Ch9-16 Telem WŁ"
#define TR_BINDING_CH9_16_TELEM_OFF               "Ch9-16 Telem WYŁ"
#define TR_PROTOCOL_INVALID            TR("Prot. invalid", "Protocol invalid")
#define TR_MODULE_STATUS                TR(INDENT "Status", INDENT "Module Status")
#define TR_MODULE_SYNC                 TR(INDENT "Sync", INDENT "Proto Sync Status")
#define TR_MULTI_SERVOFREQ     TR("Servo rate", "Servo update rate")
#define TR_MULTI_MAX_THROW             TR("Max. Throw", "Enable max. throw")
#define TR_MULTI_RFCHAN                TR("RF Channel", "Select RF channel")
#define TR_FLYSKY_TELEMETRY            TR("FlySky RSSI #", "Use FlySky RSSI value without rescalling")
#define TR_GPS_COORDS_FORMAT            TR("Koord.GPS","Typ koordynat GPS")
#define TR_VARIO               TR("Wario","Wariometr")
#define TR_PITCH_AT_ZERO       "Ton przy Zerze"
#define TR_PITCH_AT_MAX        "Ton przy Max"
#define TR_REPEAT_AT_ZERO      "Powtórz przy Zerze"
#define TR_BATT_CALIB          "Kalib:Baterii"
#define TR_CURRENT_CALIB       " +=\006Kalibracja prądu"
#define TR_VOLTAGE             TR (INDENT"Napięcie",INDENT"Źródło Napięcia")
#define TR_SELECT_MODEL        "Wybór modelu"
#define TR_MANAGE_MODELS       "MENADŻER MODELI"
#define TR_MODELS              "Modele"
#define TR_SELECT_MODE         "Wybierz tryb"
#define TR_CREATE_MODEL        "Nowy model"
#define TR_FAVORITE_LABEL      "Ulubione"
#define TR_MODELS_MOVED        "Unused models moved to"
#define TR_NEW_MODEL           "Nowy model"
#define TR_INVALID_MODEL       "Nieprawid. model"
#define TR_EDIT_LABELS         "Edyt. etykiety"
#define TR_LABEL_MODEL         "Etykietuj model"
#define TR_MOVE_UP             "Wyżej"
#define TR_MOVE_DOWN           "Niżej"
#define TR_ENTER_LABEL         "Wpisz etykietę"
#define TR_LABEL               "Etykieta"
#define TR_LABELS              "Etykiety"
#define TR_CURRENT_MODEL       "Wybrany"
#define TR_ACTIVE              "Aktywny"
#define TR_NEW                 "Nowy"
#define TR_NEW_LABEL           "Nowa etyk."
#define TR_RENAME_LABEL        "Zmień etyk."
#define TR_DELETE_LABEL        "Usuń etyk."
#define TR_DUPLICATE_MODEL     "Duplikuj model"
#define TR_COPY_MODEL          "Skopiuj model"
#define TR_MOVE_MODEL          "Przenieś model"
#define TR_BACKUP_MODEL        "Zbackupuj model"
#define TR_DELETE_MODEL        "Skasuj model"
#define TR_RESTORE_MODEL       "Odtwórz model"
#define TR_DELETE_ERROR        "Błąd kasowania"
#define TR_SDCARD_ERROR        "Błąd karty SD"
#define TR_SDCARD              "Karta SD"
#define TR_NO_FILES_ON_SD      "Brak plików na SD!"
#define TR_NO_SDCARD           "Brak karty SD"
#define TR_WAITING_FOR_RX              "Czekam na RX..."
#define TR_WAITING_FOR_TX              "Czekam na TX..."
#define TR_WAITING_FOR_MODULE          TR("Waiting module", "Waiting for module...")
#define TR_NO_TOOLS                    "Brak narzędzi"
#define TR_NORMAL                      "Normal"
#define TR_NOT_INVERTED                "Not inv"
#define TR_NOT_CONNECTED               "!Połączony"
#define TR_CONNECTED                   "Połączony"
#define TR_FLEX_915                    "Flex 915MHz"
#define TR_FLEX_868                    "Flex 868MHz"
#define TR_16CH_WITHOUT_TELEMETRY      TR("16CH without telem.", "16CH without telemetry")
#define TR_16CH_WITH_TELEMETRY         TR("16CH with telem.", "16CH with telemetry")
#define TR_8CH_WITH_TELEMETRY          TR("8CH with telem.", "8CH with telemetry")
#define TR_EXT_ANTENNA                 "Zewn. antena"
#define TR_PIN                         "Pin"
#define TR_UPDATE_RX_OPTIONS           "Update RX options?"
#define TR_UPDATE_TX_OPTIONS           "Update TX options?"
#define TR_MODULES_RX_VERSION          "Modules / RX version"
#define TR_SHOW_MIXER_MONITORS         "Show mixer monitors"
#define TR_MENU_MODULES_RX_VERSION     "MODULES / RX VERSION"
#define TR_MENU_FIRM_OPTIONS           "FIRMWARE OPTIONS"
#define TR_IMU                        "IMU"
#define TR_STICKS_POTS_SLIDERS         "Sticks/Pots/Sliders"
#define TR_PWM_STICKS_POTS_SLIDERS     "PWM Sticks/Pots/Sliders"
#define TR_RF_PROTOCOL                 "Protokół RF"
#define TR_MODULE_OPTIONS              "Module options"
#define TR_POWER                       "Power"
#define TR_NO_TX_OPTIONS               "No TX options"
#define TR_RTC_BATT                    "RTC Batt"
#define TR_POWER_METER_EXT             "Power Meter (EXT)"
#define TR_POWER_METER_INT             "Power Meter (INT)"
#define TR_SPECTRUM_ANALYSER_EXT       "Spectrum (EXT)"
#define TR_SPECTRUM_ANALYSER_INT       "Spectrum (INT)"
#define TR_SDCARD_FULL                 "Pełna karta SD" 
#if defined(COLORLCD)
#define TR_SDCARD_FULL_EXT             TR_SDCARD_FULL "\nLogi i zrzuty ekranu wyłączone"
#else
#define TR_SDCARD_FULL_EXT             TR_SDCARD_FULL "\036Logi i zrzuty ekranu" LCDW_128_480_LINEBREAK "wyłączone"
#endif
#define TR_NEEDS_FILE                  "NEEDS FILE"
#define TR_EXT_MULTI_SPEC              "opentx-inv"
#define TR_INT_MULTI_SPEC              "stm-opentx-noinv"
#define TR_INCOMPATIBLE        "Niekompatybilne"
#define TR_WARNING             "UWAGA"
#define TR_EEPROMWARN          "EEPROM"
#define TR_STORAGE_WARNING     "STORAGE"
#define TR_EEPROM_CONVERTING   "Konwersja EEPROM"
#define TR_SDCARD_CONVERSION_REQUIRE   "SD card conversion required"
#define TR_CONVERTING                  "Konwertuję: "
#define TR_THROTTLE_UPPERCASE        "GAZ"
#define TR_ALARMSWARN          "ALARM"
#define TR_SWITCHWARN          TR("Przełą","Kontrola")
#define TR_FAILSAFEWARN        "FAILSAFE"
#define TR_TEST_WARNING        TR("TESTING", "TEST BUILD")
#define TR_TEST_NOTSAFE        "Tylko do testów"
#define TR_WRONG_SDCARDVERSION TR("Expected ver: ","Expected version: ")
#define TR_WARN_RTC_BATTERY_LOW        "RTC Battery low"
#define TR_WARN_MULTI_LOWPOWER         "Low power mode"
#define TR_BATTERY                     "BATTERY"
#define TR_WRONG_PCBREV        "Wrong PCB detected"
#define TR_EMERGENCY_MODE      "EMERGENCY MODE"
#define TR_NO_FAILSAFE         "Brak Failsafe"
#define TR_KEYSTUCK            "Blokada klucza"
#define TR_VOLUME              "Głośność"
#define TR_LCD                 "LCD"
#define TR_BRIGHTNESS          "Jasność"
#define TR_CPU_TEMP            "Temp. CPU\016>"
#define TR_COPROC              "CoProc."
#define TR_COPROC_TEMP         "Temp. MB"
#define TR_TEMPWARNING         INDENT "Przegrzanie"
#define TR_TTL_WARNING         "Uwaga: use 3.3V logic levels"
#define TR_FUNC                "Funkcja"
#define TR_V1                  "V1"
#define TR_V2                  "V2"
#define TR_DURATION            "Czas trwania"
#define TR_DELAY               "Opóźnienie"
#define TR_SD_CARD             "SD"
#define TR_SDHC_CARD           "SD-HC"
#define TR_NO_SOUNDS_ON_SD     "Brak dźwięków na SD"
#define TR_NO_MODELS_ON_SD     "Brak modelu na SD"
#define TR_NO_BITMAPS_ON_SD    "Brak obrazków na SD"
#define TR_NO_SCRIPTS_ON_SD    "Brak skryptów na SD"
#define TR_SCRIPT_SYNTAX_ERROR TR("Błąd składni", "Skrypt:błąd składni")
#define TR_SCRIPT_PANIC        "Skrypt:panic"
#define TR_SCRIPT_KILLED       "Skrypt:killed"
#define TR_SCRIPT_ERROR        "Nieznany błąd"
#define TR_PLAY_FILE           "Odtwórz"
#define TR_DELETE_FILE         "Skasuj"
#define TR_COPY_FILE           "Kopiuj"
#define TR_RENAME_FILE         "Zmień nazwę"
#define TR_ASSIGN_BITMAP       "Wybierz obrazek"
#define TR_ASSIGN_SPLASH       "Ekran startowy"
#define TR_EXECUTE_FILE        "Wykonaj"
#define TR_REMOVED             " skasowane"
#define TR_SD_INFO             "Informacje"
#define TR_NA                  "[X]"
#define TR_HARDWARE            "HARDWARE"
#define TR_FORMATTING          "Formatowanie.."
#define TR_TEMP_CALIB          "Temp. kalibracji"
#define TR_TIME                "Czas"
#define TR_MAXBAUDRATE         "Max bauds"
#define TR_BAUDRATE            "Baudrate"
#define TR_SAMPLE_MODE         TR("Sampling","Sample Mode")
#define TR_SAMPLE_MODES        "Normal","OneBit"
#define TR_LOADING             "Ładowanie..."
#define TR_DELETE_THEME        "Usunąć motyw?"
#define TR_SAVE_THEME          "Zapisać motyw?"
#define TR_EDIT_COLOR                  "Edytuj kolor"
#define TR_NO_THEME_IMAGE              "Brak obrazu motywu"
#define TR_BACKLIGHT_TIMER             "Czas bezczynności"

#if defined(COLORLCD)
  #define TR_MODEL_QUICK_SELECT "Szybki wybór modelu"
#endif

#define TR_SELECT_TEMPLATE_FOLDER "Wybierz folder szablonu"
#define TR_SELECT_TEMPLATE     "WYBIERZ SZABLON MODELU:"
#define TR_NO_TEMPLATES        "Brak szablonów modeli w tym folderze"
#define TR_SAVE_TEMPLATE       "Save as template"
#define TR_BLANK_MODEL         "Pusty model"
#define TR_BLANK_MODEL_INFO    "Stwórz pusty model"
#define TR_FILE_EXISTS         "PLIK ISTNIEJE"
#define TR_ASK_OVERWRITE       "Czy chcesz nadpisać?"

#define TR_BLUETOOTH            "Bluetooth"
#define TR_BLUETOOTH_DISC       "Szukaj"
#define TR_BLUETOOTH_INIT       "Init"
#define TR_BLUETOOTH_DIST_ADDR  "Dist addr"
#define TR_BLUETOOTH_LOCAL_ADDR "Local addr"
#define TR_BLUETOOTH_PIN_CODE   "PIN code"
#define TR_BLUETOOTH_NODEVICES  "No Devices Found"
#define TR_BLUETOOTH_SCANNING   "Skanuję..."
#define TR_BLUETOOTH_BAUDRATE   "BT Prędkość"
#if defined(PCBX9E)
#define TR_BLUETOOTH_MODES      "---","Włączony"
#else
#define TR_BLUETOOTH_MODES      "---","Telemetry","Trainer"
#endif
#define TR_SD_INFO_TITLE       "SD INFO"
#define TR_SD_TYPE             "Typ:"
#define TR_SD_SPEED            "Prędkość:"
#define TR_SD_SECTORS          "Sektory :"
#define TR_SD_SIZE             "Wielkość:"
#define TR_TYPE                INDENT TR_SD_TYPE
#define TR_GLOBAL_VARS         "Zmienne Globalne"
#define TR_GVARS               "Zmien.Glob."
#define TR_GLOBAL_VAR          "Zmienna Globalna"
#define TR_MENU_GLOBAL_VARS      "ZMIENNE GLOBALNE"
#define TR_OWN                 "Własność"
#define TR_DATE                "Data"
#define TR_MONTHS              { "Sty", "Lut", "Mar", "Kwi", "Maj", "Cze", "Lip", "Sie", "Wrz", "Paź", "Lis", "Gru" }
#define TR_ROTARY_ENCODER      "R.E."
#define TR_ROTARY_ENC_MODE     TR("RotEnc Mode","Rotary Encoder Mode")
#define TR_CHANNELS_MONITOR    "MONITOR KANAŁÓW"
#define TR_MIXERS_MONITOR      "MONITOR MIKSER"
#define TR_PATH_TOO_LONG       "Ścieżka za długa"
#define TR_VIEW_TEXT           "Pokaż tekst"
#define TR_FLASH_BOOTLOADER    "Flash bootloader"
#define TR_FLASH_DEVICE                TR("Flash device","Flash device")
#define TR_FLASH_EXTERNAL_DEVICE "Sflashuj Moduł Zewnętrzny"
#define TR_FLASH_RECEIVER_OTA          "Flash receiver OTA"
#define TR_FLASH_RECEIVER_BY_EXTERNAL_MODULE_OTA "Flash RX by ext. OTA"
#define TR_FLASH_RECEIVER_BY_INTERNAL_MODULE_OTA "Flash RX by int. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_EXTERNAL_MODULE_OTA "Flash FC by ext. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_INTERNAL_MODULE_OTA "Flash FC by int. OTA"
#define TR_FLASH_BLUETOOTH_MODULE      TR("Flash BT module", "Flash Bluetooth module")
#define TR_FLASH_POWER_MANAGEMENT_UNIT          "Flash pwr mngt unit"
#define TR_DEVICE_NO_RESPONSE          TR("Device not responding", "Device not responding")
#define TR_DEVICE_FILE_ERROR           TR("Device file prob.", "Device file prob.")
#define TR_DEVICE_DATA_REFUSED         TR("Device data refused", "Device data refused")
#define TR_DEVICE_WRONG_REQUEST        TR("Device access problem", "Device access problem")
#define TR_DEVICE_FILE_REJECTED        TR("Device file refused", "Device file refused")
#define TR_DEVICE_FILE_WRONG_SIG       TR("Device file sig.", "Device file sig.")
#define TR_CURRENT_VERSION             TR("Current vers. ", "Current version: ")
#define TR_FLASH_INTERNAL_MODULE "Sflashuj Moduł Wewnętrzny"
#define TR_FLASH_INTERNAL_MULTI        TR("Flash Int. Multi", "Flash Internal Multi")
#define TR_FLASH_EXTERNAL_MODULE       "Flash external module"
#define TR_FLASH_EXTERNAL_MULTI        TR("Flash Ext. Multi", "Flash External Multi")
#define TR_FLASH_EXTERNAL_ELRS         TR("Flash Ext. ELRS", "Flash External ELRS")
#define TR_FIRMWARE_UPDATE_ERROR TR("FW update Error","Firmware update error")
#define TR_FIRMWARE_UPDATE_SUCCESS     "Flash successful"
#define TR_WRITING                     "Zapis...  "
#define TR_CONFIRM_FORMAT              "Zatwierdź Format?"
#define TR_INTERNALRF                  "Wewn.Moduł RF"
#define TR_INTERNAL_MODULE             TR("Moduł wewn.", "Moduł wewnętrzny")
#define TR_EXTERNAL_MODULE             TR("Moduł zewn.", "Moduł zewnętrzny")
#define TR_OPENTX_UPGRADE_REQUIRED     "OpenTX upgrade required"
#define TR_TELEMETRY_DISABLED          "Telem. disabled"
#define TR_MORE_OPTIONS_AVAILABLE      "More options available"
#define TR_NO_MODULE_INFORMATION       "No module information"
#define TR_EXTERNALRF          "Zewn.Moduł RF"
#define TR_FAILSAFE            TR(INDENT"Failsafe",INDENT"Tryb Failsafe")
#define TR_FAILSAFESET         "USTAWIENIE FAILSAFE"
#define TR_REG_ID                      "Reg. ID"
#define TR_OWNER_ID                    "Owner ID"
#define TR_HOLD                "Hold"
#define TR_HOLD_UPPERCASE              "HOLD"
#define TR_NONE                "Nic"
#define TR_NONE_UPPERCASE              "NIC"
#define TR_MENUSENSOR          "CZUJNIK"
#define TR_POWERMETER_PEAK             "Peak"
#define TR_POWERMETER_POWER            "Moc"
#define TR_POWERMETER_ATTN             "Attn"
#define TR_POWERMETER_FREQ             "Freq."
#define TR_MENUTOOLS                   "NARZĘDZIA"
#define TR_TURN_OFF_RECEIVER           "Wyłącz odbiornik"
#define TR_STOPPING                    "Stopping..."
#define TR_MENU_SPECTRUM_ANALYSER      "SPECTRUM ANALYSER"
#define TR_MENU_POWER_METER            "POWER METER"
#define TR_SENSOR              "SENSOR"
#define TR_COUNTRY_CODE        "Kod regionu"
#define TR_USBMODE             "Tryb USB"
#define TR_JACK_MODE           "Tryb Jack"
#define TR_VOICE_LANGUAGE      "Język głosu"
#define TR_UNITS_SYSTEM        "Jednostki"
#define TR_UNITS_PPM                   "PPM Units"
#define TR_EDIT                "Edytuj"
#define TR_INSERT_BEFORE       "Wstaw przed"
#define TR_INSERT_AFTER        "Wstaw za"
#define TR_COPY                "Kopiuj"
#define TR_MOVE                "Przenieś"
#define TR_PASTE               "Wklej"
#define TR_PASTE_AFTER         "Wklej za"
#define TR_PASTE_BEFORE        "Wklej przed"
#define TR_DELETE              "Kasuj"
#define TR_INSERT              "Wstaw"
#define TR_RESET_FLIGHT        "Zeruj lot"
#define TR_RESET_TIMER1        "Zeruj Timer1"
#define TR_RESET_TIMER2        "Zeruj Timer2"
#define TR_RESET_TIMER3        "Zeruj Timer3"
#define TR_RESET_TELEMETRY     "Wyczyść telemetrię"
#define TR_STATISTICS          "Statystyki"
#define TR_ABOUT_US            "O nas"
#define TR_USB_JOYSTICK        "USB Joystick (HID)"
#define TR_USB_MASS_STORAGE    "USB Storage (SD)"
#define TR_USB_SERIAL          "USB Serial (VCP)"
#define TR_SETUP_SCREENS       "Ustaw ekrany"
#define TR_MONITOR_SCREENS     "Monitors"
#define TR_AND_SWITCH          "Przełącznik AND"
#define TR_SF                  "FS"
#define TR_GF                  "FG"
#define TR_ANADIAGS_CALIB      "Calibrated analogs"
#define TR_ANADIAGS_FILTRAWDEV "Filtered raw analogs with deviation"
#define TR_ANADIAGS_UNFILTRAW  "Unfiltered raw analogs"
#define TR_ANADIAGS_MINMAX     "Min., max. and range"
#define TR_ANADIAGS_MOVE       "Move analogs to their extremes!"
#define TR_SPEAKER             INDENT"Głośnik"
#define TR_BUZZER              INDENT"Brzęczyk"
#define TR_BYTES               "bajty"
#define TR_MODULE_BIND         TR("[BND]","[Bind]")
#define TR_POWERMETER_ATTN_NEEDED      "Attenuator needed"
#define TR_PXX2_SELECT_RX              "Select RX"
#define TR_PXX2_DEFAULT                "<default>"
#define TR_BT_SELECT_DEVICE            "Wybierz urządzenie"
#define TR_DISCOVER                    "Szukaj"
#define TR_BUTTON_INIT                 BUTTON("Init")
#define TR_WAITING                     "Czekam..."
#define TR_RECEIVER_DELETE             "Delete receiver?"
#define TR_RECEIVER_RESET              "Reset receiver?"
#define TR_SHARE                       "Share"
#define TR_BIND                        "Bind"
#define TR_REGISTER                    TR("Reg", "Register")
#define TR_MODULE_RANGE        TR("[Zas]","Zasięg")
#define TR_RANGE_TEST                  "Test zasięgu"
#define TR_RECEIVER_OPTIONS            TR("REC. OPTIONS", "RECEIVER OPTIONS")
#define TR_RESET_BTN           "[Reset]"
#define TR_DEBUG                       "Debug"
#define TR_KEYS_BTN                BUTTON(TR("SW","Switches"))
#define TR_ANALOGS_BTN                 BUTTON(TR("Analog","Analogi"))
#define TR_FS_BTN                      BUTTON(TR("Ust. łącz.", TR_FUNCTION_SWITCHES ))
#define TR_TOUCH_NOTFOUND              "Touch hardware not found"
#define TR_TOUCH_EXIT                  "Touch screen to exit"
#define TR_SET                 "[Set]"
#define TR_TRAINER             "Port Trenera"
#define TR_CHANS               "Kanały"
#define TR_ANTENNAPROBLEM      CENTER "Problem z anteną TX"
#define TR_MODELIDUSED         TR("ID zajęte","ID modelu zajęte")
#define TR_MODELIDUNIQUE       "ID jest unikalne"
#define TR_MODULE              "Moduł "
#define TR_RX_NAME             "Nazwa Rx"
#define TR_TELEMETRY_TYPE      TR("Typ ", "Typ telemetrii")
#define TR_TELEMETRY_SENSORS   "Czujniki"
#define TR_VALUE               "Wartość"
#define TR_PERIOD              "Okres"
#define TR_INTERVAL            "Interwał"
#define TR_REPEAT              "Powtórz"
#define TR_ENABLE              "Włącz"
#define TR_DISABLE             "Wyłączać"
#define TR_TOPLCDTIMER         "Top LCD Timer"
#define TR_UNIT                "Jednostka"
#define TR_TELEMETRY_NEWSENSOR INDENT "Dodaj nowy czujnik..."
#define TR_CHANNELRANGE        TR(INDENT "ZakrKn",INDENT "Zakres kanału")
#define TR_AFHDS3_RX_FREQ              TR("RX freq.", "RX frequency")
#define TR_AFHDS3_ONE_TO_ONE_TELEMETRY TR("Unicast/Tel.", "Unicast/Telemetry")
#define TR_AFHDS3_ONE_TO_MANY          "Multicast"
#define TR_AFHDS3_ACTUAL_POWER         TR("Act. pow", "Actual power")
#define TR_AFHDS3_POWER_SOURCE         TR("Power src.", "Power source")
#define TR_ANTENNACONFIRM1     "EXT. ANTENNA"
#if defined(PCBX12S)
#define TR_ANTENNA_MODES       "Internal","Ask","Per model","Internal + External"
#else
#define TR_ANTENNA_MODES       "Internal","Ask","Per model","External"
#endif
#define TR_USE_INTERNAL_ANTENNA        TR("Use int. antenna", "Use internal antenna")
#define TR_USE_EXTERNAL_ANTENNA        TR("Use ext. antenna", "Use external antenna")
#define TR_ANTENNACONFIRM2     TR("Check antenna", "Make sure antenna is installed!")
#define TR_MODULE_PROTOCOL_FLEX_WARN_LINE1                "Nie wymaga"
#define TR_MODULE_PROTOCOL_FCC_WARN_LINE1         "Wymaga FCC"
#define TR_MODULE_PROTOCOL_EU_WARN_LINE1          "Wymaga EU"
#define TR_MODULE_PROTOCOL_WARN_LINE2                "certyfikacji firmware"
#define TR_LOWALARM            INDENT "Alarm niski"
#define TR_CRITICALALARM       INDENT "Alarm krytyczny"
#define TR_DISABLE_ALARM               TR(INDENT "Disable alarms", INDENT "Disable telemetry alarms")
#define TR_POPUP               "Popup"
#define TR_MIN                 "Min"
#define TR_MAX                 "Max"
#define TR_CURVE_PRESET        "Predef..."
#define TR_PRESET              "Predef."
#define TR_MIRROR              "Lustro"
#define TR_CLEAR               "Wyczyść"
#define TR_RESET               "Resetuj"
#define TR_RESET_SUBMENU       "Reset..."
#define TR_COUNT               "Punkty"
#define TR_PT                  "pkt"
#define TR_PTS                 "pkty"
#define TR_SMOOTH              "Gładka"
#define TR_COPY_STICKS_TO_OFS  TR("Cpy stick->subtrim", "Skopiuj Drążki Do Offsetu")
#define TR_COPY_MIN_MAX_TO_OUTPUTS     TR("Cpy min/max to all",  "Copy min/max/center to all outputs")
#define TR_COPY_TRIMS_TO_OFS   TR("Cpy trim->subtrim", "Skopiuj Trymery Do subtrymerów")
#define TR_INCDEC              "Zwiększ/Zmnie"
#define TR_GLOBALVAR           "Zm.Global."
#define TR_MIXSOURCE           "Źródło Miks."
#define TR_CONSTANT            "Stała   "
#define TR_PREFLIGHT_POTSLIDER_CHECK "WYŁ","ZAŁ","Auto"
#define TR_PREFLIGHT           "Lista Ostrzeżeń"
#define TR_CHECKLIST           TR(INDENT "Czeklista",INDENT "Pokaż Listę Ostrzeżeń")
#define TR_CHECKLIST_INTERACTIVE       TR(INDENT "C-Interakt", INDENT "Interkatywna lista ostrż.")
#define TR_AUX_SERIAL_MODE     "Port szreg."
#define TR_AUX2_SERIAL_MODE    "Port szreg. 2"
#define TR_AUX_SERIAL_PORT_POWER       "Zasil.portu"
#define TR_SCRIPT              "Skrypt"
#define TR_INPUTS              "Wejścia"
#define TR_OUTPUTS             "Wyjścia"
#define STR_EEBACKUP            "Backup EEPROMu"
#define STR_FACTORYRESET        "Ustaw.Fabrycz"
#define TR_CONFIRMRESET        "Wykasować wszytkie modele?    "
#define TR_TOO_MANY_LUA_SCRIPTS "Za dużo skryptów Lua!"
#define TR_SPORT_UPDATE_POWER_MODE     "SP Power"
#define TR_SPORT_UPDATE_POWER_MODES    "AUTO","ON"
#define TR_NO_TELEMETRY_SCREENS        "No Telemetry Screens"
#define TR_TOUCH_PANEL                 "Touch panel:"
#define TR_FILE_SIZE                   "File size"
#define TR_FILE_OPEN                   "Open anyway?"
#define TR_TIMER_MODES                 {TR_OFFON,TR_START,TR_THROTTLE_LABEL,TR_THROTTLE_PERCENT_LABEL,TR_THROTTLE_START}

// Horus and Taranis column headers
#define TR_PHASES_HEADERS_NAME         "Nazwa"
#define TR_PHASES_HEADERS_SW           "Przełą"
#define TR_PHASES_HEADERS_RUD_TRIM     "Trymer SK"
#define TR_PHASES_HEADERS_ELE_TRIM     "Trymer SW"
#define TR_PHASES_HEADERS_THT_TRIM     "Trymer Gazu"
#define TR_PHASES_HEADERS_AIL_TRIM     "Trymer Lotek"
#define TR_PHASES_HEADERS_CH5_TRIM     "Trymer 5"
#define TR_PHASES_HEADERS_CH6_TRIM     "Trymer 6"
#define TR_PHASES_HEADERS_FAD_IN       "Pojawian"
#define TR_PHASES_HEADERS_FAD_OUT      "Zanik"

#define TR_LIMITS_HEADERS_NAME         "Nazwa"
#define TR_LIMITS_HEADERS_SUBTRIM      "Subtrim"
#define TR_LIMITS_HEADERS_MIN          "Min"
#define TR_LIMITS_HEADERS_MAX          "Max"
#define TR_LIMITS_HEADERS_DIRECTION    "Kierunek"
#define TR_LIMITS_HEADERS_CURVE        "Krzywa"
#define TR_LIMITS_HEADERS_PPMCENTER    "Środek PPM"
#define TR_LIMITS_HEADERS_SUBTRIMMODE  "Tryb subtrim"
#define TR_INVERTED                    "Inverted"


#define TR_LSW_DESCRIPTIONS            { "Comparison type or function", "First variable", "Second variable or constant", "Second variable or constant", "Additional condition for line to be enabled", "Minimum ON duration of the logical switch", "Minimum TRUE duration for the switch to become ON" }

#if defined(COLORLCD)
  // Horus layouts and widgets
  #define TR_FIRST_CHANNEL             "Pierwszy kanał"
  #define TR_FILL_BACKGROUND           "Wypełnić tło?"
  #define TR_BG_COLOR                  "BG Color"
  #define TR_SLIDERS_TRIMS             "Sliders+Trims"
  #define TR_SLIDERS                   "Sliders"
  #define TR_FLIGHT_MODE               "Flight mode"
  #define TR_INVALID_FILE              "Invalid File"
  #define TR_TIMER_SOURCE              "Timer source"
  #define TR_SIZE                      "Rozmiar"
  #define TR_SHADOW                    "Cień"
  #define TR_ALIGNMENT                 "Wyrównaj"
  #define TR_ALIGN_LABEL               "Wyrównaj przywieszka"
  #define TR_ALIGN_VALUE               "Wyrównać wartość"
  #define TR_ALIGN_OPTS                { "Lewy", "Centrum", "Prawe" }
  #define TR_TEXT                      "Tekst"
  #define TR_COLOR                     "Kolor"
  #define TR_MAIN_VIEW_X               "Main view XX"
  #define TR_PANEL1_BACKGROUND         "Panel1 tło"
  #define TR_PANEL2_BACKGROUND         "Panel2 tło"
  #define TR_WIDGET_GAUGE              "Wskaźnik"
  #define TR_WIDGET_MODELBMP           "Modele"
  #define TR_WIDGET_OUTPUTS            "Wyjścia"
  #define TR_WIDGET_TEXT               "Tekst"
  #define TR_WIDGET_TIMER              "Timer"
  #define TR_WIDGET_VALUE              "Wartość"
#endif

// Bootloader common - Ascii only
#define TR_BL_USB_CONNECTED           "USB polaczone"
#define TR_BL_USB_PLUGIN              "lub podlacz kabel USB"
#define TR_BL_USB_MASS_STORE          "dla trybu danych"
#define TR_BL_USB_PLUGIN_MASS_STORE   "lub podlacz kabel USB dla trybu danych"
#define TR_BL_WRITE_FW                "Zapis firmware"
#define TR_BL_FORK                    "Fork:"
#define TR_BL_VERSION                 "Wersja:"
#define TR_BL_RADIO                   "Radio:"
#define TR_BL_EXIT                    "Wyjdz"
#define TR_BL_DIR_MISSING             " Brak katalogu"
#define TR_BL_DIR_EMPTY               " Katalog jest pusty"
#define TR_BL_WRITING_FW              "Zapis firmware ..."
#define TR_BL_WRITING_COMPL           "Zapis ukonczony"

#if LCD_W >= 480
  #define TR_BL_INVALID_FIRMWARE       "Nieprawidlowy plik firmware"
#elif LCD_W >= 212
  #define TR_BL_OR_PLUGIN_USB_CABLE    TR_BL_USB_PLUGIN_MASS_STORE
  #define TR_BL_HOLD_ENTER_TO_START    "\012Przytrzymaj [ENT] by zaczac zapis"
  #define TR_BL_INVALID_FIRMWARE       "\011Nieprawidlowy plik firmware!      "
  #define TR_BL_INVALID_EEPROM         "\011Nieprawidlowy plik EEPROM!        "
#else
  #define TR_BL_OR_PLUGIN_USB_CABLE    TR_BL_USB_PLUGIN
  #define TR_BL_HOLD_ENTER_TO_START    "\006Przytrzymaj [ENT] by zaczac"
  #define TR_BL_INVALID_FIRMWARE       "\004011Nieprawidlowy firmware!   "
  #define TR_BL_INVALID_EEPROM         "\004011Nieprawidlowy EEPROM!     "
#endif

#if defined(PCBTARANIS)
   // Bootloader Taranis specific - Ascii only
  #define TR_BL_RESTORE_EEPROM        "Przywroc EEPROM"
  #if defined(RADIO_COMMANDO8)
    #define TR_BL_POWER_KEY           "Nacisnij przycisk Power"
    #define TR_BL_FLASH_EXIT          "Wyjdz z trybu flashowania"
  #endif
#elif defined(PCBHORUS)
   // Bootloader Horus specific - Ascii only
  #define TR_BL_SELECT_KEY            "[ENT] aby wybrac plik"
  #define TR_BL_FLASH_KEY             "Przytrzymaj [ENT] aby flashowac"
  #define TR_BL_EXIT_KEY              "[RTN] aby wyjsc"
#elif defined(PCBNV14)
   // Bootloader NV14 specific - Ascii only
  #define TR_BL_RF_USB_ACCESS         "Dostep RF USB"
  #define TR_BL_CURRENT_FW            "Obecny firmware:"
  #define TR_BL_SELECT_KEY            "[R TRIM] aby wybrac plik"
  #define TR_BL_FLASH_KEY             "Przytrzymaj [R TRIM] aby flashowac"
  #define TR_BL_EXIT_KEY              " [L TRIM] aby wyjsc"
#endif

// About screen
#define TR_ABOUTUS             TR("   O   ", "  O  ")

#define TR_CHR_HOUR            'h'
#define TR_CHR_INPUT           'I'   // Values between A-I will work

#define TR_BEEP_VOLUME         "Głośn pikan"
#define TR_WAV_VOLUME          "Głośn wav  "
#define TR_BG_VOLUME           "Głośn tła"

#define TR_TOP_BAR             "GórnPas"
#define TR_FLASH_ERASE                 "Flash erase..."
#define TR_FLASH_WRITE                 "Flash write..."
#define TR_OTA_UPDATE                  "OTA update..."
#define TR_MODULE_RESET                "Module reset..."
#define TR_UNKNOWN_RX                  "Nieznany RX"
#define TR_UNSUPPORTED_RX              "Niewspierany RX"
#define TR_OTA_UPDATE_ERROR            "OTA update error"
#define TR_DEVICE_RESET                "Device reset..."
#define TR_ALTITUDE            INDENT "Wysokość"
#define TR_SCALE               "Skala"
#define TR_VIEW_CHANNELS       "Pokaż Kanały"
#define TR_VIEW_NOTES          "Pokaż Notki"
#define TR_MODEL_SELECT        "Model Select"
#define TR_ID                  "ID"
#define TR_PRECISION           "Precyzja "
#define TR_RATIO               "Współcz."
#define TR_FORMULA             "Formuła"
#define TR_CELLINDEX           "Cell index"
#define TR_LOGS                "Logi"
#define TR_OPTIONS             "Opcje  "
#define TR_FIRMWARE_OPTIONS    "Opcje firmware"

#define TR_ALTSENSOR           "Sensor wys."
#define TR_CELLSENSOR          "Sensor Cell"
#define TR_GPSSENSOR           "Sensor GPS"
#define TR_CURRENTSENSOR       "Sensor"
#define TR_AUTOOFFSET          "Auto Ofset"
#define TR_ONLYPOSITIVE        "Dodatni"
#define TR_FILTER              "Filtr"
#define TR_TELEMETRYFULL       "Wszyskie miejsca zajęte!"
//TODO: translation
#define TR_INVERTED_SERIAL     INDENT "Odwróć"
#define TR_IGNORE_INSTANCE     INDENT "Ignoruj przypadek"
#define TR_SHOW_INSTANCE_ID    "Pokaż ID instancji"
#define TR_DISCOVER_SENSORS    "Znajdź nowe czujniki"
#define TR_STOP_DISCOVER_SENSORS "Szukanie STOP "
#define TR_DELETE_ALL_SENSORS  "Usuń czujniki     "
#define TR_CONFIRMDELETE       "Usunąć wszystkie?"
#define TR_SELECT_WIDGET       "Wybierz widżet"
#define TR_WIDGET_FULLSCREEN   "Pełny ekran"
#define TR_REMOVE_WIDGET       "Usuń widżet"
#define TR_WIDGET_SETTINGS     "Ustawienia widżetu"
#define TR_REMOVE_SCREEN       "Usuń ekran"
#define TR_SETUP_WIDGETS       "Ustaw widżety"
#define TR_USER_INTERFACE      "Interfejs użytkownika"
#define TR_THEME               "Szablon"
#define TR_SETUP               "Ustawienia"
#define TR_LAYOUT              "Układ"
#define TR_ADD_MAIN_VIEW       "Dodaj główny widok"
#define TR_BACKGROUND_COLOR    "Kolor tła"
#define TR_MAIN_COLOR          "Główny kolor"
#define TR_BAR2_COLOR          "Drugi kolor pas."
#define TR_BAR1_COLOR          "Główny kolor pas."
#define TR_TEXT_COLOR          "Kolor tekstu"
#define TR_TEXT_VIEWER         "Podgląd tekstu"

#define TR_MENU_INPUTS                  STR_CHAR_INPUT "Wejścia"
#define TR_MENU_LUA                     STR_CHAR_LUA "SkryptyLUA"
#define TR_MENU_STICKS                  STR_CHAR_STICK "Drążki"
#define TR_MENU_POTS                    STR_CHAR_POT "Pots"
#define TR_MENU_MIN                     STR_CHAR_FUNCTION "MIN"
#define TR_MENU_MAX                     STR_CHAR_FUNCTION "MAX"
#define TR_MENU_HELI                    STR_CHAR_CYC "Cyclic"
#define TR_MENU_TRIMS                   STR_CHAR_TRIM "Trymy"
#define TR_MENU_SWITCHES                STR_CHAR_SWITCH "Przełączniki"
#define TR_MENU_LOGICAL_SWITCHES        STR_CHAR_SWITCH "Przełączn.logicz"
#define TR_MENU_TRAINER                 STR_CHAR_TRAINER "Trener "
#define TR_MENU_CHANNELS                STR_CHAR_CHANNEL "Kanały  "
#define TR_MENU_GVARS                   STR_CHAR_SLIDER "Zmienne glob."
#define TR_MENU_TELEMETRY               STR_CHAR_TELEMETRY "Telemetria"
#define TR_MENU_DISPLAY                 "DISPLAY"
#define TR_MENU_OTHER                   "Inny "
#define TR_MENU_INVERT                  "Odwróć"
#define TR_AUDIO_MUTE                  TR("Audio mute","Mute if no sound")
#define TR_JITTER_FILTER                "Filtr ADC"
#define TR_DEAD_ZONE                    "Dead zone"
#define TR_RTC_CHECK                    TR("Check RTC", "Check RTC voltage")
#define TR_AUTH_FAILURE                 "Auth-failure"
#define TR_RACING_MODE                  "Racing mode"

#define TR_USE_THEME_COLOR              "Użyj koloru szablonu"

#define TR_ADD_ALL_TRIMS_TO_SUBTRIMS    "Dodaj trymy do podtrymów"
#if LCD_W > LCD_H
  #define TR_OPEN_CHANNEL_MONITORS      "Otwórz Monitor kanałów"
#else
  #define TR_OPEN_CHANNEL_MONITORS      "Otwórz Mon. kanałów"
#endif
#define TR_DUPLICATE                    "Duplikuj"
#define TR_ACTIVATE                     "Aktywuj"
#define TR_RED                          "Czerwony"
#define TR_BLUE                         "Niebieski"
#define TR_GREEN                        "Zielony"
#define TR_COLOR_PICKER                 "Wybór koloru"
#define TR_EDIT_THEME_DETAILS           "Edytuj szablon"
#define TR_THEME_COLOR_DEFAULT          "DOMYŚLNY"
#define TR_THEME_COLOR_PRIMARY1         "GŁÓWNY1"
#define TR_THEME_COLOR_PRIMARY2         "GŁÓWNY2"
#define TR_THEME_COLOR_PRIMARY3         "GŁÓWNY3"
#define TR_THEME_COLOR_SECONDARY1       "POBOCZNY1"
#define TR_THEME_COLOR_SECONDARY2       "POBOCZNY2"
#define TR_THEME_COLOR_SECONDARY3       "POBOCZNY3"
#define TR_THEME_COLOR_FOCUS            "WYBRANY"
#define TR_THEME_COLOR_EDIT             "ZMIEŃ"
#define TR_THEME_COLOR_ACTIVE           "AKTYWNY"
#define TR_THEME_COLOR_WARNING          "OSTRZEŻENIE"
#define TR_THEME_COLOR_DISABLED         "WYŁĄCZONY"
#define TR_THEME_COLOR_CUSTOM           "WŁASNY"
#define TR_THEME_CHECKBOX               "Pole wyboru"
#define TR_THEME_ACTIVE                 "Aktywny"
#define TR_THEME_REGULAR                "Normalny"
#define TR_THEME_WARNING                "Ostrzeżenie"
#define TR_THEME_DISABLED               "Wyłączony"
#define TR_THEME_EDIT                   "Zmień"
#define TR_THEME_FOCUS                  "Wybrany"
#define TR_AUTHOR                       "Autor"
#define TR_DESCRIPTION                  "Opis"
#define TR_SAVE                         "Zapisz"
#define TR_CANCEL                       "Anuluj"
#define TR_EDIT_THEME                   "Edytuj szablon"
#define TR_DETAILS                      "Detale"
#define TR_THEME_EDITOR                 "Szablony"

// Main menu
#define TR_MAIN_MENU_SELECT_MODEL       "Wybierz\nmodel"
#define TR_MAIN_MENU_MANAGE_MODELS      "Menadżer\nmodeli"
#define TR_MAIN_MENU_MODEL_NOTES        "Notatki\nmodelu"
#define TR_MAIN_MENU_CHANNEL_MONITOR    "Monitor\nkanałów"
#define TR_MAIN_MENU_MODEL_SETTINGS     "Ustawienia\nmodelu"
#define TR_MAIN_MENU_RADIO_SETTINGS     "Ustawienia\nradia"
#define TR_MAIN_MENU_SCREEN_SETTINGS    "Ustawienia\nekranów"
#define TR_MAIN_MENU_RESET_TELEMETRY    "Reset\ntelemetrii"
#define TR_MAIN_MENU_STATISTICS         "Statystyki"
#define TR_MAIN_MENU_ABOUT_EDGETX       "O\nEdgeTX"
// End Main menu

// Voice in native language
#define TR_VOICE_ENGLISH                "Angielski"
#define TR_VOICE_CHINESE                "Chiński"
#define TR_VOICE_CZECH                  "Czeski"
#define TR_VOICE_DANISH                 "Duński"
#define TR_VOICE_DEUTSCH                "Niemiecki"
#define TR_VOICE_DUTCH                  "Holenderski"
#define TR_VOICE_ESPANOL                "Hiszpański"
#define TR_VOICE_FRANCAIS               "Francuski"
#define TR_VOICE_HUNGARIAN              "Węgierski"
#define TR_VOICE_ITALIANO               "Włoski"
#define TR_VOICE_POLISH                 "Polski"
#define TR_VOICE_PORTUGUES              "Portugalski"
#define TR_VOICE_RUSSIAN                "Rosyjski"
#define TR_VOICE_SLOVAK                 "Słowacki"
#define TR_VOICE_SWEDISH                "Szwedzki"
#define TR_VOICE_TAIWANESE              "Tajwański"
#define TR_VOICE_JAPANESE               "Japonês"
#define TR_VOICE_HEBREW                 "Hebrajski"

#define TR_USBJOYSTICK_LABEL           "Dżojstik USB"
#define TR_USBJOYSTICK_EXTMODE         "Tryb"
#define TR_VUSBJOYSTICK_EXTMODE        "Klasyczny","Zaawansowany"
#define TR_USBJOYSTICK_SETTINGS        "Ustawienia kanałów"
#define TR_USBJOYSTICK_IF_MODE         TR("Tryb in.","Tryb interfesju")
#define TR_VUSBJOYSTICK_IF_MODE        "Dżojstik","Pad","Wielo oś."
#define TR_USBJOYSTICK_CH_MODE         "Tryb"
#define TR_VUSBJOYSTICK_CH_MODE        "Brak","Prz","Oś","Sym"
#define TR_VUSBJOYSTICK_CH_MODE_S      "-","P","O","S"
#define TR_USBJOYSTICK_CH_BTNMODE      "Tryb guzików"
#define TR_VUSBJOYSTICK_CH_BTNMODE     "Normalny","Puls","SWEmu","Delta","Companion"
#define TR_VUSBJOYSTICK_CH_BTNMODE_S   TR("Norm","Normal"),TR("Puls","Puls"),TR("SWEm","SWEmul"),TR("Delt","Delta"),TR("CPN","Companion")
#define TR_USBJOYSTICK_CH_SWPOS        "Pozycje"
#define TR_VUSBJOYSTICK_CH_SWPOS       "Guz.","2POS","3POS","4POS","5POS","6POS","7POS","8POS"
#define TR_USBJOYSTICK_CH_AXIS         "Oś"
#define TR_VUSBJOYSTICK_CH_AXIS        "X","Y","Z","rotX","rotY","rotZ","Suwak","Wyb.","Koło"
#define TR_USBJOYSTICK_CH_SIM          "Oś sym."
#define TR_VUSBJOYSTICK_CH_SIM         "Ail","Ele","Rud","Thr"
#define TR_USBJOYSTICK_CH_INVERSION    "Odwróć"
#define TR_USBJOYSTICK_CH_BTNNUM       "Guzik nr."
#define TR_USBJOYSTICK_BTN_COLLISION   "!Kolizja nr. guzika!"
#define TR_USBJOYSTICK_AXIS_COLLISION  "!Kolizja osi!"
#define TR_USBJOYSTICK_CIRC_COUTOUT    TR("Circ. cut", "Circular cutout")
#define TR_VUSBJOYSTICK_CIRC_COUTOUT   "None","X-Y, Z-rX","X-Y, rX-rY"
#define TR_USBJOYSTICK_APPLY_CHANGES   "Zastosuj zmiany"

#define TR_DIGITAL_SERVO          "Serwo 333HZ"
#define TR_ANALOG_SERVO           "Serwo 50HZ"
#define TR_SIGNAL_OUTPUT          "Wyj. sygnału"
#define TR_SERIAL_BUS             "Mag. szereg."
#define TR_SYNC                   "Synch"

#define TR_ENABLED_FEATURES       "Włączone opcje"
#define TR_RADIO_MENU_TABS        "Zakładki menu radia"
#define TR_MODEL_MENU_TABS        "Zakładki menu modelu"

#define TR_SELECT_MENU_ALL        "All"
#define TR_SELECT_MENU_CLR        "Clear"
#define TR_SELECT_MENU_INV        "Invert"
