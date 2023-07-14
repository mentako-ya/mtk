/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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
#include "quantum.h"
#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif

#define PMW3389_SPI_MODE 3
#define PMW3389_SPI_DIVISOR (F_CPU / PMW3389_CLOCKS)
#define PMW3389_CLOCKS 2000000

bool pmw3389_spi_start(void) {
    return spi_start(PMW3389_NCS_PIN, false, PMW3389_SPI_MODE, PMW3389_SPI_DIVISOR);
}

uint16_t pmw3389_reg_read(uint8_t addr) {
    pmw3389_spi_start();
    spi_write(addr & 0x7f);
    wait_us(160);
    uint8_t data = spi_read();
    spi_stop();
    wait_us(20);
    return data;
}

void pmw3389_reg_write(uint8_t addr, uint8_t data) {
    pmw3389_spi_start();
    spi_write(addr | 0x80);
    spi_write(data);
    wait_us(35);
    spi_stop();
    wait_us(145);
}

uint16_t pmw3389_cpi_get(void) {
    uint16_t cpival = (pmw3389_reg_read(pmw3389_Resolution_H) << 8) | pmw3389_reg_read(pmw3389_Resolution_L);
    return (uint16_t)((cpival) & 0xFFFF) * pmw3389_CPI_STEP;
}

void pmw3389_cpi_set(uint16_t cpi) {
	uint16_t cpival = cpi / pmw3389_CPI_STEP;
    pmw3389_reg_write(pmw3389_Resolution_L, cpival & 0xFF);
    pmw3389_reg_write(pmw3389_Resolution_H, (cpival >> 8) & 0xFF);
    pmw3389_reg_write(pmw3389_Motion_Burst, 0);
#if defined(CONSOLE_ENABLE)
    dprintf("pmw3389_Resolution_L: %02X\n", cpival & 0xFF);
    dprintf("pmw3389_Resolution_H: %02X\n", (cpival >> 8) & 0xFF);
#endif
}

static uint32_t pmw3389_timer      = 0;
static uint32_t pmw3389_scan_count = 0;
static uint32_t pmw3389_last_count = 0;

void pmw3389_scan_perf_task(void) {
    pmw3389_scan_count++;
    uint32_t now = timer_read32();
    if (TIMER_DIFF_32(now, pmw3389_timer) > 1000) {
#if defined(CONSOLE_ENABLE)
        dprintf("pmw3389 scan frequency: %lu\n", pmw3389_scan_count);
#endif
        pmw3389_last_count = pmw3389_scan_count;
        pmw3389_scan_count = 0;
        pmw3389_timer      = now;
    }
}

uint32_t pmw3389_scan_rate_get(void) {
    return pmw3389_last_count;
}

bool pmw3389_motion_read(pmw3389_motion_t *d) {
#ifdef DEBUG_PMW3389_SCAN_RATE
    pmw3389_scan_perf_task();
#endif
    uint8_t mot = pmw3389_reg_read(pmw3389_Motion);
    if ((mot & 0x88) != 0x80) {
        return false;
    }
    d->x = pmw3389_reg_read(pmw3389_Delta_X_L);
    d->x |= pmw3389_reg_read(pmw3389_Delta_X_H) << 8;
    d->y = pmw3389_reg_read(pmw3389_Delta_Y_L);
    d->y |= pmw3389_reg_read(pmw3389_Delta_Y_H) << 8;
    return true;
}

bool pmw3389_motion_burst(pmw3389_motion_t *d) {
#ifdef DEBUG_PMW3389_SCAN_RATE
    pmw3389_scan_perf_task();
#endif
    pmw3389_spi_start();
    spi_write(pmw3389_Motion_Burst);
    wait_us(35);
    uint8_t mot = spi_read();
    if ((mot & 0x88) != 0x80) {
        spi_stop();
        return false;
    }
    spi_read(); // skip Observation
    d->x = spi_read();
    d->x |= spi_read() << 8;
    d->y = spi_read();
    d->y |= spi_read() << 8;
    spi_stop();
    return true;
}

bool pmw3389_init(void) {
    spi_init();
    setPinOutput(PMW3389_NCS_PIN);
    // reboot
    pmw3389_spi_start();
    pmw3389_reg_write(pmw3389_Power_Up_Reset, 0x5a);
    wait_ms(50);
    // read five registers of motion and discard those values
    pmw3389_reg_read(pmw3389_Motion);
    pmw3389_reg_read(pmw3389_Delta_X_L);
    pmw3389_reg_read(pmw3389_Delta_X_H);
    pmw3389_reg_read(pmw3389_Delta_Y_L);
    pmw3389_reg_read(pmw3389_Delta_Y_H);
    // configuration
    pmw3389_reg_write(pmw3389_Config2, 0x00);
    // check product ID and revision ID
    uint8_t pid = pmw3389_reg_read(pmw3389_Product_ID);
    uint8_t rev = pmw3389_reg_read(pmw3389_Revision_ID);
    spi_stop();
    return pid == 0x47 && rev == 0x01;
}
