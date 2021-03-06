/**
 * $Id: $
 *
 * @brief Red Pitaya library housekeeping module interface
 *
 * @Author Red Pitaya
 *
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */



#ifndef __HOUSEKEEPING_H
#define __HOUSEKEEPING_H

#include <stdint.h>
#include <stdbool.h>

// Base Housekeeping address
static const int HOUSEKEEPING_BASE_ADDR = 0x00000000;
static const int HOUSEKEEPING_BASE_SIZE = 0x30;

// Housekeeping structure declaration
typedef struct housekeeping_control_s {
    uint32_t id;
    uint32_t dna_lo;
    uint32_t dna_hi;
    uint32_t digital_loop;
} housekeeping_control_t;

static const uint32_t LED_CONTROL_MASK = 0xFF;
static const uint32_t DIGITAL_LOOP_MASK = 0x1;
int hk_EnableDigitalLoop(bool enable);

static volatile housekeeping_control_t *hk = NULL;

static int hk_Init() {
    cmn_Map(HOUSEKEEPING_BASE_SIZE, HOUSEKEEPING_BASE_ADDR, (void**)&hk);
    return RP_OK;
}

static int hk_Release() {
    cmn_Unmap(HOUSEKEEPING_BASE_SIZE, (void**)&hk);
    return RP_OK;
}

#endif //__HOUSEKEEPING_H
