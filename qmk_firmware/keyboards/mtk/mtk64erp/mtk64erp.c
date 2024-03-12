/*
Copylight 2024 mentako_ya
SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

//////////////////////////////////////////////////////////////////////////////

// clang-format off
const matrix_row_t matrix_mask[MATRIX_ROWS] = {

    0b00111110,
    0b00111101,
    0b00111011,
    0b00110111,
    0b00101111,
    0b00011111,

    0b00111110,    
    0b00111101,
    0b00111011,
    0b00110111,
    0b00101111,
    0b00011111

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
	if (!encoder_update_user(index, clockwise)) {
		return false;
	}
    return true;
}
#endif

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {
    uprintf("hear is pointing_dev_init_kb to set pmw33xx_set_cpi(%u, %u) \n", 0, 1000);
    pmw33xx_init(0);         // index 1 is the second device.
    pmw33xx_set_cpi(0, 1000); // applies to first sensor
    pointing_device_init_user();
}

// Contains report from sensor #0 already, need to merge in from sensor #1
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    printf("heare is pointing_device_task_kb. ");
    //pmw33xx_report_t report = pmw33xx_read_burst(0);
    //uprintf("report.delta_x:%u, report.delta_y:%u) \n", report.delta_x, report.delta_x);
    //uprintf("report.is_lifted:%u, report.is_motion:%u) \n", report.motion.b.is_lifted, report.motion.b.is_motion);
    if (mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.v !=0 || mouse_report.h != 0){
        uprintf("mouse_report.x:%u, y:%u, v%u, h%u) \n", mouse_report.x, mouse_report.y, mouse_report.v, mouse_report.h);
    }
    return pointing_device_task_user(mouse_report);
}
#endif
