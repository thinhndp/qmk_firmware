#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    OS_LINUX,
    OS_WINDOWS,
    OS_MAC
} os_mode_t;

typedef struct {
    uint16_t keys[3];
} os_keycom_t;
