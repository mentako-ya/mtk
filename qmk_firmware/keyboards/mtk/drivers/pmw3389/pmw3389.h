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

#pragma once

#include <stdint.h>
#include "spi_master.h"

//////////////////////////////////////////////////////////////////////////////
// Configurations

#ifndef PMW3389_NCS_PIN
#    define PMW3389_NCS_PIN B6
#endif

/// DEBUG_PMW3389_SCAN_RATE enables scan performance counter.
/// It records scan count in a last second and enables pmw3389_scan_rate_get().
/// Additionally, it will be logged automatically when defined CONSOLE_ENABLE
/// and `debug_enable = true`.
//#define DEBUG_PMW3389_SCAN_RATE

//////////////////////////////////////////////////////////////////////////////
// Top level API

/// pmw3389_init initializes PMW3389DM-T2QU module.
/// It will return true when succeeded, otherwise false.
bool pmw3389_init(void);

typedef struct {
    int16_t x;
    int16_t y;
} pmw3389_motion_t;

/// pmw3389_motion_read gets a motion data by Motion register.
/// This requires to write a dummy data to pmw3389_Motion register
/// just before.
bool pmw3389_motion_read(pmw3389_motion_t *d);

/// pmw3389_motion_burst gets a motion data by Motion_Burst command.
/// This requires to write a dummy data to pmw3389_Motion_Burst register
/// just before.
bool pmw3389_motion_burst(pmw3389_motion_t *d);

/// pmw3389_scan_rate_get gets count of scan in a last second.
/// This works only when DEBUG_PMW3389_SCAN_RATE is defined.
uint32_t pmw3389_scan_rate_get(void);

// TODO: document
uint16_t pmw3389_cpi_get(void);

// TODO: document
void pmw3389_cpi_set(uint16_t cpi);

//////////////////////////////////////////////////////////////////////////////
// Register operations

/// pmw3389_reg_write writes a value to a register.
void pmw3389_reg_write(uint8_t addr, uint8_t data);

/// pmw3389_reg_read reads a value from a register.
uint16_t pmw3389_reg_read(uint8_t addr);

typedef enum {
    pmw3389_Product_ID                 = 0x00,
    pmw3389_Revision_ID                = 0x01,
    pmw3389_Motion                     = 0x02,
    pmw3389_Delta_X_L                  = 0x03,
    pmw3389_Delta_X_H                  = 0x04,
    pmw3389_Delta_Y_L                  = 0x05,
    pmw3389_Delta_Y_H                  = 0x06,
    pmw3389_SQUAL                      = 0x07,
    pmw3389_Raw_Data_Sum               = 0x08,
    pmw3389_Maximum_Raw_data           = 0x09,
    pmw3389_Minimum_Raw_data           = 0x0A,
    pmw3389_Shutter_Lower              = 0x0B,
    pmw3389_Shutter_Upper              = 0x0C,
    pmw3389_Control                    = 0x0D,
    pmw3389_Resolution_L               = 0x0E,
    pmw3389_Resolution_H               = 0x0F,
    pmw3389_Config2                    = 0x10,
    pmw3389_Angle_Tune                 = 0x11,
    pmw3389_Frame_Capture              = 0x12,
    pmw3389_SROM_Enable                = 0x13,
    pmw3389_Run_Downshift              = 0x14,
    pmw3389_Rest1_Rate_Lower           = 0x15,
    pmw3389_Rest1_Rate_Upper           = 0x16,
    pmw3389_Rest1_Downshift            = 0x17,
    pmw3389_Rest2_Rate_Lower           = 0x18,
    pmw3389_Rest2_Rate_Upper           = 0x19,
    pmw3389_Rest2_Downshift            = 0x1A,
    pmw3389_Rest3_Rate_Lower           = 0x1B,
    pmw3389_Rest3_Rate_Upper           = 0x1C,
    pmw3389_Observation                = 0x24,
    pmw3389_Data_Out_Lower             = 0x25,
    pmw3389_Data_Out_Upper             = 0x26,
    pmw3389_Raw_Data_Dump              = 0x29,
    pmw3389_SROM_ID                    = 0x2A,
    pmw3389_Min_SQ_Run                 = 0x2B,
    pmw3389_Raw_Data_Threshold         = 0x2C,
    pmw3389_Config5                    = 0x2F,
    pmw3389_Power_Up_Reset             = 0x3A,
    pmw3389_Shutdown                   = 0x3B,
    pmw3389_Inverse_Product_ID         = 0x3F,
    pmw3389_LiftCutoff_Tune3           = 0x41,
    pmw3389_Angle_Snap                 = 0x42,
    pmw3389_LiftCutoff_Tune1           = 0x4A,
    pmw3389_Motion_Burst               = 0x50,
    pmw3389_LiftCutoff_Tune_Timeout    = 0x58,
    pmw3389_LiftCutoff_Tune_Min_Length = 0x5A,
    pmw3389_SROM_Load_Burst            = 0x62,
    pmw3389_Lift_Config                = 0x63,
    pmw3389_Raw_Data_Burst             = 0x64,
    pmw3389_LiftCutoff_Tune2           = 0x65,
} pmw3389_reg_t;

#define pmw3389_CPI_STEP 50
#define pmw3389_CPI_MIN 50
#define pmw3389_MAXCPI 16000

//////////////////////////////////////////////////////////////////////////////
// SPI operations

bool pmw3389_spi_start(void);

void inline pmw3389_spi_stop(void) {
    spi_stop();
}

spi_status_t inline pmw3389_spi_write(uint8_t data) {
    return spi_write(data);
}

spi_status_t inline pmw3389_spi_read(void) {
    return spi_read();
}
