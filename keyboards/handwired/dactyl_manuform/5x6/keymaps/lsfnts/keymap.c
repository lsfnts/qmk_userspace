#include QMK_KEYBOARD_H
//#include "holds.c"
#include "combos.c"
#include "tapdance.c"

//Sabado 12 de marzo

#define _HDRHODIUM 0
#define _QWERTY 1
#define _NAV 2
#define _MOUSE 3
#define _GUI 4
#define _NUM 5

#define NAV MO(_NAV)
#define MOUSE MO(_MOUSE)
#define NUM MO(_NUM)

#define RHOD TO(_HDRHODIUM)
#define QWERTY TO(_QWERTY)

// Left-hand home row mods
#define HOME_C LGUI_T(KC_C)
#define HOME_S LALT_T(KC_S)
#define HOME_N LSFT_T(KC_N)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_A RCTL_T(KC_A)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_M RGUI_T(KC_M)




bool lingering = false;
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*switch (keycode){
        case KC_BSPC:
        mod_state = get_mods();
        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
        }
    }*/
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HDRHODIUM] = LAYOUT_5x6(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5  ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,KC_CAPS,
        KC_TAB , KC_Z   , KC_B   , KC_H   , KC_G   , KC_QUOT  ,                         KC_COMM, KC_DOT , KC_SLSH, KC_J, KC_X ,KC_DEL,
        SH_OS, HOME_C   , HOME_S , HOME_N , HOME_T , KC_K  ,                         KC_SCLN, HOME_A , HOME_E , HOME_I , HOME_M ,SH_OS,
        KC_GRV, KC_P   , KC_F   , KC_L   , KC_D   , KC_V  ,                         KC_MINS, KC_U   , KC_O   , KC_Y   , KC_W   ,KC_BSLS,
                        TD(L_PAR),KC_EQL,                                                       KC_QUOT, TD(R_PAR),
                                            KC_R,KC_BSPC,                       KC_ENT, KC_SPC,
                                            NAV,QWERTY,                         RHOD, OSM(MOD_RALT),//layers?
                                            MOUSE,NUM,                        TG(_GUI), KC_NO
    ),
    [_QWERTY] = LAYOUT_5x6( 
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_P, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_SCLN,KC_A, KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_SLSH,KC_Z, KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                         KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                         KC_LSFT,KC_SPC,                        KC_ENT, KC_RSFT,
                                         KC_LCTL,QWERTY,                         RHOD,  KC_DEL,
                                         KC_LALT, KC_TAB,                        KC_LGUI, KC_LALT
    ),
    [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,C(KC_Q),C(KC_W),_______,C(KC_Y),_______,                        _______,KC_BSPC,KC_DEL ,_______,_______,_______,
        _______,C(KC_A),C(KC_S),_______,C(KC_F),_______,                        _______,KC_LEFT,KC_DOWN,KC_UP ,KC_RIGHT,_______,
        _______,C(KC_Z),C(KC_X),C(KC_C),C(KC_V),_______,                        _______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______,
                        _______,_______,                                                         _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),
    [_MOUSE] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,_______,                        _______,MS_BTN3,MS_UP,MS_BTN4,MS_BTN5,MS_BTN6,
        _______,_______,MS_ACL0,MS_ACL1,MS_ACL2,_______,                        _______,MS_LEFT,MS_DOWN,MS_UP,MS_RIGT,_______,
        _______,_______,_______,_______,_______,_______,                        _______,MS_WHLL,MS_WHLD,MS_WHLU,MS_WHLR,_______,
                        _______,_______,                                                        _______,_______,
                                                  _______,_______,            MS_BTN1,MS_BTN2,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
    [_GUI] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_TAB,
        _______,KC_LEFT,KC_DOWN,KC_UP ,KC_RIGHT,_______,                        _______,KC_LEFT,KC_DOWN,KC_UP ,KC_RIGHT,_______,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,                        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            KC_BSPC ,KC_DEL ,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
    ),
    [_NUM] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______, KC_7  , KC_8  , KC_9  ,KC_PLUS,KC_LT,
        _______,_______,_______,_______,_______,_______,                        _______, KC_4  , KC_5  , KC_6  ,KC_ASTR,KC_MINS,
        _______,_______,_______,_______,_______,_______,                        _______, KC_1  , KC_2  , KC_3  ,KC_EQL,KC_GT,
                        _______,_______,                                                         _______,_______,
                                                _______,_______,            _______, KC_0  ,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods = get_mods();
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (mods & MOD_MASK_SHIFT){
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_RIGHT);
            }
        } else {
            if (mods & MOD_MASK_SHIFT){
                tap_code(KC_UP);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{5,10}, {4,10}, {3,10}, {2,10}, {1,10}, {0,10}},
    {{5,11}, {4,11}, {3,11}, {2,11}, {1,11}, {0,11}},

    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_D:
        case KC_F ... KC_M:
        case KC_O ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_N:
        case HOME_E:
            return true;
        default:
            return false;
    }
}

/*void matrix_scan_user(void) {
    if(lingering) {
        lingering = linger_keys();
    }
}*/