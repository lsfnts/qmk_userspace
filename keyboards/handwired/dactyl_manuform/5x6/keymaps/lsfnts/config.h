/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef MANUFACTURER 
#define MANUFACTURER lsfnts

#undef RGB_DI_PIN
#undef RGBLED_NUM
#undef SOFT_SERIAL_PIN
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY

#define MK_COMBINED

#define USE_I2C
#define F_SCL 800000L

#define EE_HANDS
#define MATRIX_IO_DELAY 14

#undef DEBOUNCE
#define DEBOUNCE 4

#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_COL_PINS { D2, D3, D4, D5, E6, D7 }
#define MATRIX_ROW_PINS { B0, B1, B2, B3, B4, B5 }

#define ENCODERS_PAD_A {B6}
#define ENCODERS_PAD_B {B7}

//#define DEBUG_MATRIX_SCAN_RATE

#define TAPPING_TERM 280
#define TAPPING_TERM_PER_KEY

#define QMK_KEYS_PER_SCAN 2

#define EXTRA_SHORT_COMBOS

#define USB_POLLING_INTERVAL_MS 2

#define NO_MUSIC_MODE

#define LAYER_STATE_8BIT

#define MOUSEKEY_DELAY  28
#define MOUSEKEY_INTERVAL   14
#define MOUSEKEY_MOVE_DELTA 	1
#define MOUSEKEY_MAX_SPEED 	28
#define MOUSEKEY_TIME_TO_MAX 	32
#define MOUSEKEY_WHEEL_DELAY 	14
#define MOUSEKEY_WHEEL_INTERVAL 	28
#define MOUSEKEY_WHEEL_MAX_SPEED 	10
#define MOUSEKEY_WHEEL_TIME_TO_MAX  196

#define QUICK_TAP_TERM 0
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
#define MODS_TO_NEUTRALIZE { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI), MOD_BIT(KC_RIGHT_GUI), MOD_BIT(KC_LEFT_CTRL)|MOD_BIT(KC_LEFT_SHIFT) }
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_F18
#define ONESHOT_TIMEOUT 3000

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
