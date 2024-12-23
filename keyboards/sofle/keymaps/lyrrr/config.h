// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/* Mod tap */
#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS

/* Custom Features */
#define CUSTOM_FONT
#define CUSTOM_LAYER_READ // Guard against removal issues

/* Tapping and Encoder Configuration */
#define ENCODER_DIRECTION_FLIP

/* RGBLIGHT Configuration */
#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_LED_COUNT
    #undef RGBLED_SPLIT
    #define WS2812_DI_PIN D3           // Data pin for WS2812 LEDs
    #define RGBLIGHT_LED_COUNT 14      // Total number of LEDs
    #define RGBLED_SPLIT { 7, 7 }      // Split configuration: 7 LEDs per side
    #define RGBLIGHT_LIMIT_VAL 200     // Brightness limit (max 255)
    #define RGBLIGHT_HUE_STEP 10       // Hue adjustment step
    #define RGBLIGHT_SAT_STEP 17       // Saturation adjustment step
    #define RGBLIGHT_VAL_STEP 17       // Brightness adjustment step
    #define RGBLIGHT_SLEEP             // Turn off RGB lighting on suspend
    #define RGBLIGHT_LAYERS            // Enable layer-specific RGB lighting

    /* RGB Effects - Uncomment desired effects */
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #undef RGBLIGHT_EFFECT_SNAKE
    // #undef RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #undef RGBLIGHT_EFFECT_RGB_TEST
    // #undef RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
#endif

/* RGB_MATRIX Configuration */
#ifdef RGB_MATRIX_ENABLE
    #undef RGB_MATRIX_ENABLE
//     #undef RGBLIGHT_LED_COUNT
//     #undef RGBLED_SPLIT
//     #define RGB_MATRIX_LED_COUNT 14            // Total number of LEDs
//     #define RGB_MATRIX_KEYPRESSES              // React to keypresses
//     #define RGB_MATRIX_SLEEP                   // Turn off effects on suspend
//     #define RGB_MATRIX_FRAMEBUFFER_EFFECTS     // Framebuffer effects
//     #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // Brightness limit (max 255)
//     #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
//
//     /* Adjustment steps for RGB Matrix */
//     #define RGB_MATRIX_HUE_STEP 8
//     #define RGB_MATRIX_SAT_STEP 8
//     #define RGB_MATRIX_VAL_STEP 8
//     #define RGB_MATRIX_SPD_STEP 10
//
//     /* Optional: Disable unnecessary animations to save firmware space */
//     // #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
//     // #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
//     // #undef ENABLE_RGB_MATRIX_RAINDROPS
//     // #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#endif
