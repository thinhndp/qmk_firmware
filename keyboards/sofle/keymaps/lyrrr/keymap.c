#include <stdio.h>

#include QMK_KEYBOARD_H

#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RALT OSM(MOD_RALT)
#define CTL_F LCTL(KC_F)
#define CTL_A LCTL(KC_A)
#define CTL_E LCTL(KC_E)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define OS_CS OSM(MOD_LCTL|MOD_LSFT)
#define CTL_SPC LCTL(KC_SPC)
#define RCS_Z RCS(KC_Z)
#define RCS_C RCS(KC_C)
#define RCS_V RCS(KC_V)

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _SYMBOLS,
    _NUMBERS,
    _EXTEND,
    _FUNCTION,
    _EMOJI,
};

enum custom_keycodes {
    OS_TOGGLE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,    OS_TOGGLE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  KC_LGUI, MO(3), MO(4), KC_LSFT, KC_DEL,       KC_ENT, KC_SPC, MO(2), MO(6), KC_RGUI
),
[_COLEMAK] = LAYOUT(
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
  KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G,        KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
  KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D,        KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,    KC_NO, KC_K, KC_M, KC_COMM, KC_DOT, KC_TRNS, KC_RSFT,
  KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT, KC_SPC, TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
[_SYMBOLS] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  KC_MINS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_EQL, KC_GRV, KC_COLN, KC_SCLN, KC_PLUS, KC_F12,
  KC_UNDS, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_CIRC,    KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_GRV,
  KC_ASTR, KC_DQUO, KC_QUOT, KC_BSLS, KC_PIPE, KC_AMPR, KC_TRNS, KC_TRNS, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_EQL, KC_TRNS,
  KC_TRNS, KC_TRNS, MO(5), MO(3), KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_NUMBERS] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NUM,             KC_EQL, KC_7, KC_8, KC_9, KC_PLUS, KC_TRNS,
  KC_TRNS, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,    KC_ASTR, KC_4, KC_5, KC_6, KC_MINS, KC_TRNS,
  KC_TRNS, KC_NO, KC_APP, KC_TAB, KC_BSPC, KC_ENT, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_DOT, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_EXTEND] = LAYOUT(
  QK_BOOT, KC_LGUI, KC_NO, KC_NO, RGB_VAD, RGB_VAI,        RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_NO, QK_BOOT,
  RGB_TOG, KC_ESC, CTL_A, CTL_F, CTL_E, KC_INS,            KC_CAPS, KC_DEL, KC_HOME, KC_END, KC_PGUP, KC_NO,
  RGB_MOD, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, RGB_SPI,
  RGB_RMOD, CTL_Z, CTL_X, CTL_C, CTL_V, OS_CS, KC_NO,      KC_NO, KC_ENT, KC_BSPC, KC_TAB, KC_APP, KC_PSCR, RGB_SPD,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, CTL_SPC, MO(5), KC_TRNS, KC_TRNS
),
[_FUNCTION] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,    KC_F12, KC_F7, KC_F8, KC_F9, KC_SCRL, KC_TRNS,
  KC_TRNS, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_BRID,    KC_F11, KC_F4, KC_F5, KC_F6, DF(0), KC_TRNS,
  KC_TRNS, RCS(KC_Z), KC_NO, RCS(KC_C), RCS(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, DF(1), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_EMOJI] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,    KC_F12, KC_F7, KC_F8, KC_F9, KC_SCRL, KC_TRNS,
  KC_TRNS, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_BRID,    KC_F11, KC_F4, KC_F5, KC_F6, DF(0), KC_TRNS,
  KC_TRNS, RCS(KC_Z), KC_NO, RCS(KC_C), RCS(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, DF(1), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

bool is_mac = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_TOGGLE:
            if (record->event.pressed) {
                is_mac = !is_mac;
            }
            return false;
        default:
            return true;
    }
}

#ifdef OLED_ENABLE
static void print_status_narrow(void) {
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("lyrrr"), false);
    oled_write_ln_P(PSTR(""), false);

    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case _EXTEND:
            oled_write_ln_P(PSTR("Ext"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("Func"), false);
            break;
        case _EMOJI:
            oled_write_ln_P(PSTR("Emo"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("OS"), false);
    const char* os_status = is_mac ? PSTR("Mac") : PSTR("Win");
    oled_write_ln_P(os_status, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();

    }
    else {
        oled_write_ln_P(PSTR("lyrrr"), false);
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
// #define RGB_VAD QK_UNDERGLOW_VALUE_DOWN
// #define RGB_VAI QK_UNDERGLOW_VALUE_UP
// #define RGB_HUD QK_UNDERGLOW_HUE_DOWN
// #define RGB_HUI QK_UNDERGLOW_HUE_UP
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            // case _EXTEND:
            //     if (clockwise) {
            //         tap_code(UG_VALU);
            //     } else {
            //         tap_code(UG_VALD);
            //     }
            //     break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            // case _EXTEND:
            //     if (clockwise) {
            //         tap_code(RGB_HUD);
            //     } else {
            //         tap_code(RGB_HUI);
            //     }
            //     break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return true;
}

#endif
