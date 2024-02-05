// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

//////////////////////////////////////////////////////////////////////////////

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_mtk64erp(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
	  KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
	  KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOTE ,
    MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1    ,
	  KC_LALT  , KC_LGUI  ,                  LT(1,KC_LNG2) ,LT(2,KC_SPC),                                KC_BSPC  , KC_ENT   ,                       KC_EQL   , KC_INT3  ,
                          TG(2)    ,            KC_ENT   ,       LT(3,KC_LNG1) ,             KC_LGUI ,            KC_ESC   ,            KC_ENT   ,
					 KC_LEFT , KC_RGHT ,      KC_UP,KC_DOWN,           G(KC_C) ,             G(KC_V) ,     SGUI(KC_Z),LGUI(KC_Z),  S(KC_TAB),KC_TAB
  ),

  LAYOUT_mtk64erp(
    S(KC_ESC), S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  ,S(KC_MINS),
    S(KC_TAB), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_LBRC),
    S(KC_LCTL),S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  ,S(KC_SCLN),S(KC_QUOTE),
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_INT1)  ,
    S(KC_LALT),S(KC_LGUI),                      _______  , _______  ,                                  _______  , _______  ,                      S(KC_EQL) ,S(KC_INT3),
                          _______  ,            _______  ,             _______,              _______ ,            _______  ,             _______ ,
                      _______,_______,      _______,_______,           _______,              _______ ,        _______,_______,       _______,_______
  ),

  LAYOUT_mtk64erp(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_PGUP  , KC_UP    , KC_PGDN  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_END   , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8) ,              KC_BTN4 , KC_BTN5  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  , _______  ,
    _______  , _______  ,                       _______  , _______  ,                                  _______  , _______  ,                       _______  , _______  ,
	                        _______  ,            _______  ,             _______,              _______ ,            _______  ,             _______ ,
				            S(KC_TAB),KC_TAB ,      _______,_______,           _______,              _______ ,        _______,_______,       _______,_______
  ),

  LAYOUT_mtk64erp(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_MO  , SCRL_TO  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
	  AM_TO_CL_INC        , AM_TO_CL_DEC        ,
	  AM_TO_RST_INC       , AM_TG_CL            , SCRL_DVD , SCRL_DVI , EE_CLR  ,              EE_CLR  , _______  , _______  , _______  , _______  , _______  , _______  ,
	  QK_BOOT  , AM_TG_CL ,                       _______  , _______  ,                                  _______  , _______  ,                       _______  , QK_BOOT  ,
                          _______  ,            _______  ,             _______,              _______ ,            _______  ,             _______ ,
                      _______,_______,      _______,_______,           _______,              _______ ,        _______,_______,       _______,_______
  ),

};
// clang-format on

// encoder logic
#ifdef ENCODER_ENABLE

enum encoder_number {
    _1ST_ENC = 0,
    _2ND_ENC,
    _3RD_ENC,
    _4TH_ENC,
};

bool encoder_initialized = false;

bool encoder_update_user(uint8_t index, bool clockwise) {

	if(encoder_initialized != true) {
        // encoder誤作動防止     
		return true;
	}

	keypos_t key;

	switch (index) {
	case _1ST_ENC:
		if (clockwise) {
			key.row = 5;
			key.col = 2;
		} else {
			key.row = 5;
			key.col = 3;
		}
		break;
	case _2ND_ENC:
		if (clockwise) {
			key.row = 5;
			key.col = 0;
		} else {
			key.row = 5;
			key.col = 1;
		}
		break;
	case _3RD_ENC:
		if (clockwise) {
			key.row = 11;
			key.col = 2;
		} else {
			key.row = 11;
			key.col = 3;
		}
		break;
	case _4TH_ENC:
		if (clockwise) {
			key.row = 11;
			key.col = 0;
		} else {
			key.row = 11;
			key.col = 1;
		}
		break;
	}
	uint8_t layer = layer_switch_get_layer(key);
	uint16_t keycode = keymap_key_to_keycode(layer, key);

	tap_code16(keycode);

#ifdef CONSOLE_ENABLE
    uprintf("encoder_update_user: index: %u, clockwise: %u \n", index, clockwise);
#endif

	return true;
}
#endif

void keyboard_post_init_user(void) {
#if defined(CONSOLE_ENABLE)
    debug_enable = true;
#endif
#ifdef AUTO_MOUSE_LAYER_ENABLE
    user_config.raw = eeconfig_read_user();
#endif
#ifdef ENCODER_ENABLE
    encoder_initialized = true;
#endif
}
