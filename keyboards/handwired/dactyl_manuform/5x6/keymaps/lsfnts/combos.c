#pragma once
#include "tapdance.c"

enum combos {
    H_Z,
    H_Q,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM H_Z_combo[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM H_Q_combo[] = {KC_B, KC_G, COMBO_END};


combo_t key_combos[] = {
    [H_Z] = COMBO(H_Z_combo, KC_Z),
    [H_Q] = COMBO(H_Q_combo, TD(Q_U)),
};