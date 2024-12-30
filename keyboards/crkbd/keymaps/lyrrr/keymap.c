#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "types.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TABL G(S(KC_LBRC))
#define TABR G(S(KC_RBRC))
#define SPCL A(G(KC_LEFT))
#define SPC_R A(G(KC_RGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define MC_ESC LCTL_T(KC_ESC)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    MOD,
    KEB,
    // OHD,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)

    OS_MOD,
    OS_COPY,
    OS_PASTE,
    OS_APP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_LGUI, LA_NAV,  KC_LSFT, KC_SPC,  LA_SYM,  KC_LALT
    ),

    [SYM] = LAYOUT_split_3x6_3(
        // _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,  _______,
        // _______, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, _______,
        // _______, KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC, XXXXXXX, KC_AMPR, KC_SCLN, KC_COLN, KC_EXLM, _______,
        //                            _______, _______, _______, _______, _______, _______
        //
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_EQL, KC_TILD, KC_GRV, KC_F12,
        KC_TRNS, KC_PLUS, KC_MINS, KC_LBRC, KC_LPRN, KC_LCBR, KC_BSLS, OS_CTRL, OS_SHFT, OS_ALT, OS_CMD, KC_TRNS,
        KC_TRNS, KC_ASTR, KC_UNDS, KC_RBRC, KC_RPRN, KC_RCBR, KC_SLSH, KC_PIPE, KC_LT, KC_GT, KC_QUES, KC_TRNS,
                                   _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_split_3x6_3(
        QK_BOOT, SW_LANG, SW_WIN,  OS_APP,  TABR,    KC_VOLU, KC_CAPS, KC_DEL,  HOME,    END,     KC_PSCR,  _______,
        RGB_TOG, OS_CMD,  OS_ALT,  OS_SHFT, OS_CTRL, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, _______,
        RGB_MOD, SPCL,    SPC_R,   OS_COPY, OS_PASTE,KC_MPLY, KC_ENT,  KC_BSPC, KC_TAB,  KC_PGDN, KC_PGUP, _______,
                                   MO(MOD), _______, _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, OS_CMD,  OS_ALT,  OS_SHFT, OS_CTRL, KC_F11,  KC_F12,  OS_CTRL, OS_SHFT, OS_ALT,  OS_CMD,  _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                                   _______, _______, _______, _______, _______, _______
    ),

    [MOD] = LAYOUT_split_3x6_3(
        TO(KEB), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        TO(DEF), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        OS_MOD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______
    ),

    [KEB] = LAYOUT_split_3x6_3(
        _______, QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        TO(DEF), QK_RBT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, QK_MAKE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______
    ),

    // [OHD] = LAYOUT_split_3x6_3(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                                _______, _______, _______, _______, _______, _______
    // ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

os_mode_t current_os_mode = OS_LINUX;

os_keycom_t get_os_keycom(uint16_t keycode) {
    switch (keycode) {
        case OS_COPY:
            if (current_os_mode == OS_LINUX) {
                return (os_keycom_t){{ KC_LCTL, KC_C, KC_NO }};
            } else if (current_os_mode == OS_WINDOWS) {
                return (os_keycom_t){{ KC_LCTL, KC_C, KC_NO }};
            } else if (current_os_mode == OS_MAC) {
                return (os_keycom_t){{ KC_LGUI, KC_C, KC_NO }};
            }
        case OS_PASTE:
            if (current_os_mode == OS_LINUX) {
                return (os_keycom_t){{ KC_LCTL, KC_V, KC_NO }};
            } else if (current_os_mode == OS_WINDOWS) {
                return (os_keycom_t){{ KC_LCTL, KC_V, KC_NO }};
            } else if (current_os_mode == OS_MAC) {
                return (os_keycom_t){{ KC_LGUI, KC_V, KC_NO }};
            }
        case OS_APP:
            if (current_os_mode == OS_LINUX) {
                return (os_keycom_t){{ KC_LGUI, KC_A, KC_NO }};
            } else if (current_os_mode == OS_WINDOWS) {
                return (os_keycom_t){{ KC_LCTL, KC_V, KC_NO }};
            } else if (current_os_mode == OS_MAC) {
                return (os_keycom_t){{ KC_LALT, KC_SPC, KC_NO }};
            }
        case SW_LANG:
            if (current_os_mode == OS_LINUX) {
                return (os_keycom_t){{ KC_LGUI, KC_NO, KC_SPC }};
            } else if (current_os_mode == OS_WINDOWS) {
                return (os_keycom_t){{ KC_LCTL, KC_NO, KC_LSFT }};
            } else if (current_os_mode == OS_MAC) {
                return (os_keycom_t){{ KC_LCTL, KC_LALT, KC_SPC }};
            }
        case SW_WIN:
            if (current_os_mode == OS_LINUX) {
                return (os_keycom_t){{ KC_LALT, KC_NO, KC_TAB }};
            } else if (current_os_mode == OS_WINDOWS) {
                return (os_keycom_t){{ KC_LALT, KC_NO, KC_TAB }};
            } else if (current_os_mode == OS_MAC) {
                return (os_keycom_t){{ KC_LALT, KC_NO, KC_TAB }};
            }
        default:
            return (os_keycom_t){{ KC_NO, KC_NO, KC_NO }};
    }
    return (os_keycom_t){{ KC_NO, KC_NO, KC_NO }};
}

void handle_swappers(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active,
        get_os_keycom(SW_WIN),
        SW_WIN,
        keycode,
        record
    );
    update_swapper(
        &sw_lang_active,
        get_os_keycom(SW_LANG),
        SW_LANG,
        keycode,
        record
    );
}

void handle_oneshots(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    handle_swappers(keycode, record);
    handle_oneshots(keycode, record);

    switch (keycode) {
        case OS_MOD:
            if (record->event.pressed) {
                current_os_mode = (current_os_mode + 1) % 3;
            }
            return false;
        case OS_COPY:
        case OS_PASTE:
        case OS_APP:
            if (record->event.pressed) {
                os_keycom_t keycom = get_os_keycom(keycode);

                // Press the keys in the key combination (up to 3 keys)
                for (int i = 0; i < 3; i++) {
                    if (keycom.keys[i] != KC_NO) {
                        register_code(keycom.keys[i]);
                    }
                }
            } else {
                os_keycom_t keycom = get_os_keycom(keycode);

                // Release the keys in the key combination
                for (int i = 0; i < 3; i++) {
                    if (keycom.keys[i] != KC_NO) {
                        unregister_code(keycom.keys[i]);
                    }
                }
            }
            return false;
        default:
            return true;
    }
    // return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Def"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("Mod"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("Keb"), false);
            break;
        // case 6:
        //     oled_write_ln_P(PSTR("OHD"), false);
        //     break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("OS"), false);
    switch (current_os_mode) {
        case OS_LINUX:
            oled_write_ln_P(PSTR("Linux"), false);
            break;
        case OS_WINDOWS:
            oled_write_ln_P(PSTR("Win"), false);
            break;
        case OS_MAC:
            oled_write_ln_P(PSTR("Mac"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    // clang-format on
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    }
    else {
        oled_render_logo();
    }
    return false;
}
#endif
