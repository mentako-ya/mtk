// Copyright 2024 mentako-ya
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// Key matrix parameters (duplex matrix)
//#define MATRIX_ROWS         (7 * 2)  // split keyboard
//#define MATRIX_COLS         (7)      // squared matrix
//#define MATRIX_ROW_PINS     { GP28, GP27, GP26, GP22, GP20, GP23, GP21}
//#define MATRIX_COL_PINS     { GP28, GP27, GP26, GP22, GP20, GP23, GP21}
#define MATRIX_MASKED
#define DEBOUNCE            5

/* Rotary encoder */
//#ifdef ENCODER_ENABLE
//#define ENCODERS_PAD_A { GP6, GP8 }
//#define ENCODERS_PAD_B { GP7, GP9 }
//#define ENCODER_RESOLUTION 2
//#define ENCODER_MAP_KEY_DELAY 10
//#endif

// Split parameters
//#define SOFT_SERIAL_PIN         D2
//#define SPLIT_HAND_MATRIX_GRID  F7, D7

// #define SOFT_SERIAL_PIN         GP1
// #define SPLIT_HAND_MATRIX_GRID  GP26, GP6
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT       500
// #define NO_SUSPEND_POWER_DOWN
// #define USB_SUSPEND_WAKEUP_DELAY 200
#define SPLIT_MAX_CONNECTION_ERRORS 10
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500

//#define SPLIT_POINTING_ENABLE

// Trackball  parameters
#ifdef POINTING_DEVICE_ENABLE
#    define SPI_DRIVER SPID1
#    define SPI_SCK_PIN GP14
#    define SPI_MISO_PIN GP12
#    define SPI_MOSI_PIN GP15
#    define PMW33XX_CS_PIN GP13
#    define PMW33XX_CPI 500
#    define PMW33XX_CS_DIVISOR 64
#    define PMW33XX_LIFTOFF_DISTANCE 0x04

#    define POINTING_DEVICE_CS_PIN GP13
#    define SPLIT_POINTING_ENABLE

#    define POINTING_DEVICE_LEFT
//#    define POINTING_DEVICE_RIGHT
//#    define POINTING_DEVICE_COMBINED

#ifdef CONSOLE_ENABLE
#    define POINTING_DEVICE_DEBUG
#endif
//#    define ROTATIONAL_TRANSFORM_ANGLE  -25
//#    define POINTING_DEVICE_INVERT_Y
//#    define POINTING_DEVICE_TASK_THROTTLE_MS 1
// // #    undef RP_SPI_USE_SPI0
// // #    define RP_SPI_USE_SPI0 TRUE
// // #    undef RP_SPI_USE_SPI1
// // #    define RP_SPI_USE_SPI1 FALSE
// // #    define SPI_DRIVER SPID0


// #    define PMW33XX_CS_PIN GP13
// // SPI1 SCK
// #    define SPI_SCK_PIN GP14
// // SPI1 RX
// #    define SPI_MISO_PIN GP12
// // SPI1 TX
// #    define SPI_MOSI_PIN GP15

#endif
// /* cocot */

// #    undef RP_SPI_USE_SPI0
// #    define RP_SPI_USE_SPI0 FLASE
// #    undef RP_SPI_USE_SPI1
// #    define RP_SPI_USE_SPI1 TRUE



// #    undef RP_SPI_USE_SPI0
// #    define RP_SPI_USE_SPI0 FALSE
// #    undef RP_SPI_USE_SPI1
// #    define RP_SPI_USE_SPI1 TRUE
// #    define SPI_DRIVER SPID1

// /* keyball */
// // #    define SPI_SCK_PIN B1
// // #    define SPI_MISO_PIN B3
// // #    define SPI_MOSI_PIN B2ß
// /* cocot */
// // #    define SPI_SCK_PIN GP2
// // #    define SPI_MISO_PIN GP4    //RX
// // #    define SPI_MOSI_PIN GP3    //TX
// #    define SPI_SCK_PIN GP14
// #    define SPI_MISO_PIN GP12    //RX
// #    define SPI_MOSI_PIN GP15    //TX

// #endif


// #ifndef PMW33XX_CS_PIN
// /* keyball */
// //#    define PMW33XX_CS_PIN B6
// /* cocot */
// //#    define PMW33XX_CS_PIN GP5
// //#    define PMW33XX_CS_PIN GP13
// #endif


//#define POINTING_DEVICE_ROTATION_270

#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

#ifdef OLED_ENABLE
#   define OLED_DISPLAY_128X64
#   define OLED_TIMEOUT 60000
#   define OLED_BRIGHTNESS 128
#endif