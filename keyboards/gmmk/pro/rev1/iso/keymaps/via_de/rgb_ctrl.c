#include "rgb_ctrl.h"
#include "rgb_keys.h"

void update_caps_lock_indication(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_WHITE);
    } else {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
            rgb_matrix_set_color(LED_CAPS, RGB_OFF);
        }
    }
}

// set all to white and BOOTLOADER key to magenta
void indicate_configured_keys(uint8_t layer) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if(index != NO_LED){
                uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){col,row});
                if (kc > KC_TRNS) {
                    if(kc == QK_BOOT) {
                        rgb_matrix_set_color(index, RGB_MAGENTA);
                    } else if(kc == KC_MPLY){
                        rgb_matrix_set_color(index, RGB_SPRINGGREEN);
                    } else if (kc == KC_MSTP){
                        rgb_matrix_set_color(index, RGB_RED);
                    } else {
                        rgb_matrix_set_color(index, RGB_WHITE);
                    }
                }
            }
        }
    }
}
