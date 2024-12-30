#include "swapper.h"

void update_swapper(
    bool *active,
    os_keycom_t keycom,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                for (int i = 0; i < 2; i++) {
                    if (keycom.keys[i] != KC_NO) {
                        register_code(keycom.keys[i]);
                    }
                }
            }
            register_code(keycom.keys[2]);
        } else {
            unregister_code(keycom.keys[2]);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        for (int i = 0; i < 2; i++) {
            if (keycom.keys[i] != KC_NO) {
                unregister_code(keycom.keys[i]);
            }
        }
        *active = false;
    }
}
