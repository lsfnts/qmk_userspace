#pragma once
#include "print.h"
enum {
    L_PAR,
    R_PAR,
    L_MOD,
    R_MOD,
    Q_U,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_QUAD_TAP,
    TD_QUAD_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    bool is_new_dance = QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX;
    if (state->count == 1) {
        if (state->pressed && !is_new_dance) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed && !is_new_dance) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }else if (state->count == 3) {
        if (state->pressed && !is_new_dance) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    } else if (state->count == 4) {
        if (state->pressed && !is_new_dance) return TD_QUAD_HOLD;
        else return TD_QUAD_TAP;
    } return TD_UNKNOWN;
}

void l_par(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) { tap_code16(KC_LPRN);}
    else if (state->count == 2) { tap_code16(KC_LCBR);}
    else if (state->count == 3) { tap_code(KC_LBRC);}
    else if (state->count == 4) { tap_code16(KC_LABK);}
    else tap_code16(KC_LPRN);
}
void r_par(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) { tap_code16(KC_RPRN);}
    else if (state->count == 2) { tap_code16(KC_RCBR);}
    else if (state->count == 3) { tap_code(KC_RBRC);}
    else if (state->count == 4) { tap_code16(KC_RABK);}
    else tap_code16(KC_RPRN);
}

static td_tap_t l_mod_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void l_mod(tap_dance_state_t *state, void *user_data) {
    l_mod_tap_state.state = cur_dance(state);
    switch(l_mod_tap_state.state){
        case TD_SINGLE_TAP: add_oneshot_mods(MOD_BIT(KC_LSFT)); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: add_oneshot_mods(MOD_BIT(KC_LCTL)); break;
        case TD_DOUBLE_HOLD: register_code(KC_LCTL); break;
        case TD_TRIPLE_TAP: add_oneshot_mods(MOD_BIT(KC_LALT)); break;
        case TD_TRIPLE_HOLD: register_code(KC_LALT); break;
        default: break;
    }
}

void l_mod_reset(tap_dance_state_t *state, void *user_data) {
    switch (l_mod_tap_state.state) {
        case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LALT); break;
        default: break;
    }
    l_mod_tap_state.state = TD_NONE;
}

static td_tap_t r_mod_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void r_mod(tap_dance_state_t *state, void *user_data) {
    r_mod_tap_state.state = cur_dance(state);
    switch(r_mod_tap_state.state){
        case TD_SINGLE_TAP: add_oneshot_mods(MOD_BIT(KC_RSFT)); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: add_oneshot_mods(MOD_BIT(KC_RCTL)); break;
        case TD_DOUBLE_HOLD: register_code(KC_RCTL); break;
        case TD_TRIPLE_TAP: add_oneshot_mods(MOD_BIT(KC_LALT)); break;
        case TD_TRIPLE_HOLD: register_code(KC_LALT); break;
        default: break;
    }
}

void r_mod_reset(tap_dance_state_t *state, void *user_data) {
    switch (r_mod_tap_state.state) {
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RCTL); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LALT); break;
        default: break;
    }
    r_mod_tap_state.state = TD_NONE;
}


void q_u_tap(tap_dance_state_t *state, void *user_data) {
    tap_code(KC_Q);
}

void q_u(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !(QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX)){
        tap_code(KC_U);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [L_PAR] = ACTION_TAP_DANCE_FN(l_par),
    [R_PAR] = ACTION_TAP_DANCE_FN(r_par),
    [L_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL ,l_mod, l_mod_reset),
    [R_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL ,r_mod, r_mod_reset),
    [Q_U] = ACTION_TAP_DANCE_FN_ADVANCED(q_u_tap ,q_u, NULL),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(Q_U):
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}