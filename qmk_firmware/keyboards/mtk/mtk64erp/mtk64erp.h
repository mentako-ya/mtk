/*
Copylight 2024 mentako_ya
SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "quantum.h"

// clang-format off
#define LAYOUT_mtk64erp( \
    L00, L01, L02, L03, L04, L05,              R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15,              R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25,              R25, R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35, L36,    R36, R35, R34, R33, R32, R31, R30, \
    L40, L41,                L45, L46,    R46, R45,                R41, R40, \
              E4P,      E3P,      L43,    R43,      E2P,      E1P,           \
			E4L,E4R,  E3L,E3R,    L42,    R42,    E2L,E2R,  E1L,E1R          \
	) \
    { \
        {   L00,   L01,   L02, KC_NO,   L03,   L04,   L05, KC_NO }, \
        {   L10,   L11,   L12,   E4P,   L13,   L14,   L15,   E3P }, \
        {   L20,   L21,   L22, KC_NO,   L23,   L24,   L25, KC_NO }, \
        {   L30,   L31,   L32, KC_NO,   L33,   L34,   L35,   L36 }, \
        {   L40,   L41, KC_NO, KC_NO,   L42,   L43,   L45,   L46 }, \
        {   E4R,   E4L,   E3R,   E3L, KC_NO, KC_NO, KC_NO, KC_NO }, \
        {   R00,   R01,   R02, KC_NO,   R03,   R04,   R05, KC_NO }, \
        {   R10,   R11,   R12,   E1P,   R13,   R14,   R15,   E2P }, \
        {   R20,   R21,   R22, KC_NO,   R23,   R24,   R25, KC_NO }, \
        {   R30,   R31,   R32, KC_NO,   R33,   R34,   R35,   R36 }, \
        {   R40,   R41, KC_NO, KC_NO,   R42,   R43,   R45,   R46 }, \
        {   E1L,   E1R,   E2L,   E2R, KC_NO, KC_NO, KC_NO, KC_NO }  \
    }
// clang-format on

// enum cocot_keycodes {

//     COCOT_SAFE_RANGE = SAFE_RANGE,
//     CPI_SW,
//     SCRL_SW,
//     ROT_R15,
//     ROT_L15,
//     SCRL_MO,
//     SCRL_TO,
//     SCRL_IN,
// };

// #define CPI_SW QK_KB_0
// #define SCRL_SW QK_KB_1
// #define ROT_R15 QK_KB_2
// #define ROT_L15 QK_KB_3
// #define SCRL_MO QK_KB_4
// #define SCRL_TO QK_KB_5
// #define SCRL_IN QK_KB_6

enum custom_keycodes {
    KBC_RST = SAFE_RANGE, // configuration: reset to default
    KBC_SAVE,             // configuration: save to EEPROM

    CPI_I100, // CPI +100 CPI
    CPI_D100, // CPI -100 CPI
    CPI_I1K,  // CPI +1000 CPI
    CPI_D1K,  // CPI -1000 CPI

    // In scroll mode, motion from primary trackball is treated as scroll
    // wheel.
    SCRL_TO,  // Toggle scroll mode
    SCRL_MO,  // Momentary scroll mode
    SCRL_DVI, // Increment scroll divider
    SCRL_DVD, // Decrement scroll divider

    AM_TG_CL,       //Toggle auto mouse layer
    AM_TO_CL_INC,   //Increment AUTO_MOUSE_TIME
    AM_TO_CL_DEC,   //Decrement AUTO_MOUSE_TIME
    AM_TO_RST_INC,  //Increment AUTO_MOUSE_TIME
    AM_TO_RST_DEC,  //Decrement AUTO_MOUSE_TIME
};

// // エンコーダー有効時、指定がなければ左エンコーダーを有効化
// #if defined(ENCODER_ENABLE) && !defined(ENCODER_LEFT_ENABLE) && !defined(ENCODER_RIGHT_ENABEL)
// // #warning define ENCODER_LEFT_ENABLE.
// #    define ENCODER_LEFT_ENABLE
// #endif

// // 両側ボール用　Slave側スクロール無効化　デフォルトでは未使用
// #if !defined(ENCODER_ENABLE) && !defined(SLAVE_SCRL_DISABLE)
// #    define SLAVE_SCRL_DISABLE 0
// #endif