/*
Copyright 2022 mentako-ya

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

#include "pmw3389.h"
#include "pointing_device.h"

bool pmw3389_has = false;

void pointing_device_driver_init(void) {
    pmw3389_has = pmw3389_init();
    pmw3389_reg_write(pmw3389_Motion_Burst, 0);
}

#define constrain_hid(amt) ((amt) < -127 ? -127 : ((amt) > 127 ? 127 : (amt)))

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
    pmw3389_motion_t d = {0};
    if (pmw3389_has && pmw3389_motion_burst(&d)) {
        mouse_report.x = constrain_hid(d.y);
        mouse_report.y = constrain_hid(d.x);
    }
    return mouse_report;
}

uint16_t pointing_device_driver_get_cpi(void) {
    if (!pmw3389_has) {
        return 0;
    }
    return pmw3389_cpi_get();
}

void pointing_device_driver_set_cpi(uint16_t cpi) {
    if (!pmw3389_has) {
        return;
    }
    pmw3389_cpi_set(cpi);
}
