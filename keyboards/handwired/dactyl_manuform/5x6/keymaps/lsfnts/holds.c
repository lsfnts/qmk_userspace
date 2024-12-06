#pragma once

#include QMK_KEYBOARD_H

#define LINGER_KEYS 2


typedef struct {
    uint16_t timer;
    uint8_t keycode;
    bool     held;
} linger;

linger lingers[LINGER_KEYS] =
{
    {.keycode = KC_U},
};

bool linger_tap_key(uint16_t keycode, keyrecord_t *record, uint16_t i) {
    tap_code(keycode);
    lingers[i].timer = timer_read();
    lingers[i].held = true;
    return false;
}

bool release_linger( uint16_t i){
    lingers[i].held = false;
    return false;
}

bool linger_keys(void) {
    uint8_t saved_mods = get_mods();
    bool flag = false;
    for (uint8_t i = 0; i < LINGER_KEYS; i++) {
        if (lingers[i].held) {
            if (timer_elapsed(lingers[i].timer) > TAPPING_TERM) {
                if (saved_mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    press(lingers[i]);
                    set_mods(saved_mods);
                } else {
                    press(lingers[i]);
                }
       			lingers[i].timer = 0;
                lingers[i].held = false;
            }
        }
        if (lingers[i].held){
            flag = true;
        }
    }
    return flag;
}