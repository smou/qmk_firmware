/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "rgb_ctrl.h"

enum KB_LAYERS {
    WIN_DEFAULT,
    MACOS,
    FN
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ^        1(!)     2(")     3(§)     4($)     5(%)     6(&)     7(/)     8(()     9())     0(=)     ß(?)     ´(`)     BackSpc           PgUp
//      Tab      Q(@)     W        E(€)     R        T        Z        U        I        O        P        Ü        +(*)                       PgDn
//      Caps     A        S        D        F        G        H        J        K        L        Ö        Ä        #(')     Enter             End
//      Sh_L     <(>)     Y        X        C        V        B        N        M        ,(;)     .(:)     -(_)              Sh_R     Up       Del
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [WIN_DEFAULT] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,          KC_PGUP,
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,                   KC_PGDN,
        KC_CAPS, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH, KC_ENT,           KC_END,
        KC_LSFT, DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,          KC_RSFT, KC_UP,   KC_DEL,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, MO(FN),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [FN] = LAYOUT(
        _______, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RM_VALU, RM_TOGG,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RM_VALD, RGB_SPI
    ),
    // macOS layer
    [MACOS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,          KC_PGUP,
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,                   KC_PGDN,
        KC_CAPS, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH, KC_ENT,           KC_END,
        KC_LSFT, DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,          KC_RSFT, KC_UP,   KC_DEL,
        KC_LCMD, KC_LCTL, KC_LOPT,                            KC_SPC,                             KC_ROPT, MO(FN),   KC_RCMD, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

// overwrite for macos
// -> @ RALT + Q 
// curly braces, pipe, eckige klammern, backslash
const key_override_t atMail_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_Q, LOPT(KC_L), 1<<MACOS); // @ to alt+q
const key_override_t curlyBraces_open_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_7, LOPT(KC_8), 1<<MACOS); // { to alt+7
const key_override_t curlyBraces_close_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_0, LOPT(KC_9), 1<<MACOS); // } to alt+0
const key_override_t bracket_open_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_8, LOPT(KC_5), 1<<MACOS); // [ to alt+8
const key_override_t bracket_close_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_9, LOPT(KC_6), 1<<MACOS); // ] to alt+9
const key_override_t backslash_key_override = ko_make_with_layers(MOD_MASK_ALT, DE_SS, SAGR(KC_7), 1<<MACOS); // \ to alt+ß
const key_override_t lockscreen_key_override = ko_make_with_layers(MOD_MASK_CTRL, DE_L, LCMD(LCTL(DE_Q)), 1<<MACOS); // lockscreen to win+l
const key_override_t pipe_key_override = ko_make_with_layers(MOD_MASK_ALT, DE_LABK, LOPT(KC_7), 1<<MACOS); // piple to alt+<
const key_override_t alt_tab_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_TAB, LCMD(KC_TAB), 1<<MACOS); // piple to alt+<

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&atMail_key_override,
    &curlyBraces_open_key_override,
    &curlyBraces_close_key_override,
    &bracket_open_key_override,
    &bracket_close_key_override,
    &backslash_key_override,
    &lockscreen_key_override,
    &pipe_key_override,
    &alt_tab_key_override
};

uint32_t get_host_os(uint32_t trigger_time, void* cb_arg) {
    switch (detected_host_os()) {
    case OS_MACOS:   // On Mac, set default layer to BASE_MAC.
    case OS_IOS:
        set_single_persistent_default_layer(MACOS);
        break;
    default:         // On Windows and Linux, set to BASE_WIN.
        set_single_persistent_default_layer(WIN_DEFAULT);
        break;
    }
    return 0;
}

void keyboard_post_init_user(void){
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CYCLE_SOLID_REACTIVE);
    // Set default layer based on the detected OS after a 500 ms delay.   
    defer_exec(500, get_host_os, NULL);
}

// RGB Config
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch(current_layer) {
            case FN:
                indicate_configured_keys(current_layer);
                break;
            default:
                update_caps_lock_indication();
                break;
        }
    return false;
}


