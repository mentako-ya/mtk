/*
Copylight 2024 mentako_ya
SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include <print.h>
#endif


//////////////////////////////////////////////////////////////////////////////

// clang-format off
const matrix_row_t matrix_mask[MATRIX_ROWS] = {

    0b01111110,
    0b01111101,
    0b01111011,
    0b01110111,
    0b01101111,
    0b01011111,
    0b00111111,

    0b01111110,    
    0b01111101,
    0b01111011,
    0b01110111,
    0b01101111,
    0b01011111,
    0b00111111,

};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {

    pmw33xx_init(0);         // index 1 is the second device.
    pmw33xx_set_cpi(0, 1000); // applies to first sensor

}

// Contains report from sensor #0 already, need to merge in from sensor #1
// report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

//     return mouse_report;

// }

#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
            keycode = keycode & 0xFF;
    }

    if (keycode < 60) {
        name = code_to_name[keycode];
    }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

bool oled_task_kb(void) {

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer:  "), false);
    oled_write_ln_P(get_u8_str(get_highest_layer(layer_state), ' '), false);

    oled_render_keylog();

#   ifdef RGBLIGHT_ENABLE
        oled_write_P(PSTR("RGB Mode: "), false);
        oled_write_ln(get_u8_str(rgblight_get_mode(), ' '), false);
        oled_write_P(PSTR("h: "), false);
        oled_write(get_u8_str(rgblight_get_hue(), ' '), false);
        oled_write_P(PSTR("s: "), false);
        oled_write(get_u8_str(rgblight_get_sat(), ' '), false);
        oled_write_P(PSTR("v: "), false);
        oled_write_ln(get_u8_str(rgblight_get_val(), ' '), false);
#   endif
    return false;
}
#endif