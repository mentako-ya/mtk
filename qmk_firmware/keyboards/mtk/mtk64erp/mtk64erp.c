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

// #ifdef ENCODER_ENABLE
// bool encoder_update_kb(uint8_t index, bool clockwise) {
//     uprintf("hear is encoder_update_kb index = %u clockwise = %u\n", index, clockwise);
// 	if (!encoder_update_user(index, clockwise)) {
// 		return false;
// 	}
//     return true;
// }
// #endif

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {
//    uprintf("hear is pointing_dev_init_kb to set pmw33xx_set_cpi(%u, %u) \n", 0, 1000);
    pmw33xx_init(0);         // index 1 is the second device.
    pmw33xx_set_cpi(0, 1000); // applies to first sensor
    pointing_device_init_user();
}

// Contains report from sensor #0 already, need to merge in from sensor #1
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

    return pointing_device_task_user(mouse_report);
}
#endif

#ifdef OLED_ENABLE

bool oled_task_kb(void) {

    if (!oled_task_user()) {
        return false;
    }

    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("mtk64erp"), true);
    oled_write_ln_P(PSTR("Copylight 2024 mentako_ya"), false);
    oled_write_ln_P(PSTR("SPDX-License-Identifier: GPL-2.0-or-later"), false);

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