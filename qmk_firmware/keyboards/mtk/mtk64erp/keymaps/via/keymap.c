// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

//////////////////////////////////////////////////////////////////////////////

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
	  KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
	  KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOTE ,
    MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
	  KC_LALT  , KC_LGUI  ,                  LT(1,KC_LNG2) ,LT(2,KC_SPC),                                KC_BSPC  , KC_ENT   ,                       KC_EQL   , KC_INT3  ,
                          TG(2)    ,            KC_ENT   ,       LT(3,KC_LNG1) ,             KC_LGUI            , KC_ESC   ,            KC_ENT   ,
					                                                             G(KC_C) ,             G(KC_V) ,
    LT(1,KC_LNG2),        LT(2,KC_SPC),         LT(3,KC_LNG1)       ,                                             KC_LGUI  ,            KC_BSPC  ,            KC_ENT
  ),

  [1] = LAYOUT(
    S(KC_ESC), S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  , S(KC_MINS),
    S(KC_TAB), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  , S(KC_LBRC),
    S(KC_LCTL),S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  ,S(KC_SCLN), S(KC_QUOTE),
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH), S(KC_INT1)  ,
    S(KC_LALT),S(KC_LGUI),                      _______  , _______  ,                                  _______  , _______  ,                      S(KC_EQL) , S(KC_INT3),
                          _______  ,            _______  ,             _______ ,             _______ ,            _______  ,             _______ ,
                                                                       _______ ,             _______ ,
    _______  ,            _______  ,            _______  ,                                                        _______  ,             _______ ,            _______
  ),         

  [2] = LAYOUT(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_PGUP  , KC_UP    , KC_PGDN  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_END   , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,             KC_BTN4 , KC_BTN5  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  , _______  ,
    _______  , _______                        , _______  , _______  ,                                  _______  , _______                        , _______  , _______  ,
	                        _______             , _______  ,             _______ ,             _______            , _______             , _______ ,
                                                                       _______ ,             _______ ,
    _______  ,            _______  ,            _______  ,                                                        _______  ,             _______ ,            _______
  ),

  [3] = LAYOUT(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_MO  , SCRL_TO  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
	  AM_TO_CL_INC        , AM_TO_CL_DEC        ,
	  AM_TO_RST_INC       , AM_TG_CL            , SCRL_DVD , SCRL_DVI , EE_CLR   ,             EE_CLR  , _______  , _______  , _______  , _______  , _______  , _______  ,
	  QK_BOOT  , AM_TG_CL ,                       _______  , _______  ,                                  _______  , _______  ,                       _______  , QK_BOOT  ,
                          _______  ,            _______  ,             _______ ,             _______ ,            _______  ,             _______ ,
                                                                       _______ ,             _______ ,
    _______  ,            _______  ,            _______  ,                                                        _______  ,             _______ ,            _______
  ),

};
// clang-format on

// encoder logic
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_LEFT  , KC_RGHT) , ENCODER_CCW_CW(KC_UP   , KC_DOWN  ), ENCODER_CCW_CW(KC_LEFT  , KC_RGHT) , ENCODER_CCW_CW(KC_UP   , KC_DOWN  )},
    [1] = {ENCODER_CCW_CW(S(KC_TAB), KC_TAB)  , ENCODER_CCW_CW(KC_PGUP , KC_PGDN  ), ENCODER_CCW_CW(S(KC_TAB), KC_TAB)  , ENCODER_CCW_CW(KC_PGUP , KC_PGDN  )},
    [2] = {ENCODER_CCW_CW(KC_VOLU  , KC_VOLD) , ENCODER_CCW_CW(CPI_I100, CPI_D100 ), ENCODER_CCW_CW(KC_VOLU  , KC_VOLD) , ENCODER_CCW_CW(CPI_I100, CPI_D100 )},
    [3] = {ENCODER_CCW_CW(RGB_MOD  , RGB_RMOD), ENCODER_CCW_CW(RGB_HUI , RGB_HUD  ), ENCODER_CCW_CW(RGB_MOD  , RGB_RMOD), ENCODER_CCW_CW(RGB_HUI , RGB_HUD  )},
};
#endif

void keyboard_post_init_user(void)
{
#if defined(CONSOLE_ENABLE)
	debug_enable = true;
#endif
#ifdef AUTO_MOUSE_LAYER_ENABLE
	user_config.raw = eeconfig_read_user();
#endif
}

#ifdef CONSOLE_ENABLE
void matrix_init_kb(void)
{
	debug_enable = true;
	debug_matrix = true;
}
#endif

#ifdef POINTING_DEVICE_ENABLE

typedef union {
  uint64_t raw;
  struct {
    int16_t x;
    int16_t y;
    int8_t v;
    int8_t h;
  };
} user_mousereport_t;

user_mousereport_t usr_ms_rep;

void pointing_device_init_user(void) {

    pmw33xx_init(0);         // index 1 is the second device.
    pmw33xx_set_cpi(0, 1000); // applies to first sensor

}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    usr_ms_rep.x = mouse_report.x;
    usr_ms_rep.y = mouse_report.y;
    usr_ms_rep.v = mouse_report.v;
    usr_ms_rep.h = mouse_report.h;

    if (is_keyboard_left()) {
        mouse_report.x = usr_ms_rep.y;
        mouse_report.y = usr_ms_rep.x;
    } else {
        mouse_report.x = usr_ms_rep.y * -1;
        mouse_report.y = usr_ms_rep.x * -1;
    }

    #ifdef CONSOLE_ENABLE
    if (mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.v !=0 || mouse_report.h != 0){
        uprintf("mouse_report.x:%u, y:%u, v%u, h%u) \n", mouse_report.x, mouse_report.y, mouse_report.v, mouse_report.h);
    }
    #endif
    return mouse_report;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer:  "), false);
    oled_write_ln_P(get_u8_str(get_highest_layer(layer_state), ' '), false);
    oled_write_P(PSTR("MouseXY:"), false);
    oled_write_P(get_u16_str(usr_ms_rep.x, ' '), false);
    oled_write_ln_P(get_u16_str(usr_ms_rep.y, ' '), false);

    oled_write_P(PSTR("ScrlVH: "), false);
    oled_write_P(get_u16_str(usr_ms_rep.v, ' '), false);
    oled_write_ln_P(get_u16_str(usr_ms_rep.h, ' '), false);

    return false;
}
#endif