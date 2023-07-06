/*
Copylight 2022 Mentako_ya
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

// USB Device descriptor parameters
#define VENDOR_ID           0x4d59     // "MY" = mentako_ya
#define PRODUCT_ID          0x0100
#define DEVICE_VER          0x0002
#define MANUFACTURER        mentako_ya
#define PRODUCT             mtk64e

// Key matrix parameters (duplex matrix)
#define MATRIX_ROWS         (6 * 2)  // split keyboard
#define MATRIX_COLS         (4 * 2)  // duplex matrix
#define MATRIX_ROW_PINS     { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS     { F4, F5, F6, F7 }
#define MATRIX_MASKED
#define DEBOUNCE            5

/* Rotary encoder */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B6, B3 }
#define ENCODERS_PAD_B { B5, B2 }
#define ENCODER_RESOLUTION 2
#endif

// Split parameters
#define SOFT_SERIAL_PIN         D2
#define SPLIT_HAND_MATRIX_GRID  F7, D7
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT       500
#define NO_SUSPEND_POWER_DOWN
#define USB_SUSPEND_WAKEUP_DELAY 200

#define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO, KEYBALL_GET_MOTION, KEYBALL_SET_CPI

// RGB LED settings
#define RGB_DI_PIN          D3
#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM      74
#    define RGBLED_SPLIT    { 37, 37 }
#    ifndef RGBLIGHT_LIMIT_VAL
#        define RGBLIGHT_LIMIT_VAL  120 // limitated for power consumption
#    endif
#    ifndef RGBLIGHT_VAL_STEP
#        define RGBLIGHT_VAL_STEP   12
#    endif
#    ifndef RGBLIGHT_HUE_STEP
#        define RGBLIGHT_HUE_STEP   17
#    endif
#    ifndef RGBLIGHT_SAT_STEP
#        define RGBLIGHT_SAT_STEP   17
#    endif
#endif
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SPLIT    { 37, 37 }
#endif

#ifndef OLED_FONT_H
#    define OLED_FONT_H "keyboards/mtk/lib/glcdfont.c"
#endif

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif

// To squeeze firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define LAYER_STATE_8BIT
