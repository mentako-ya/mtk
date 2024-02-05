/*
Copylight 2024 mentako_ya
SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

//////////////////////////////////////////////////////////////////////////////

// clang-format off
matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b01110111,
    0b11111111,
    0b01110111,
    0b11110111,
    0b11111111,
    0b00001111,
    0b01110111,
    0b11111111,
    0b01110111,
    0b11110111,
    0b11111111,
    0b00001111,
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