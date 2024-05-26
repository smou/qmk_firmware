

RGB_MATRIX_EFFECT(CYCLE_SOLID_REACTIVE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
/*
HSV =
-> Hue (color angle)
-> Saturation in percent
-> value / brighness in percent
*/

/*
Keeps main effect by scale saturation to show white reactive animation.
*/
static HSV REACTIVE_math(HSV hsv, uint8_t led_i, uint16_t max_tick) {
    // Reverse search to find most recent key hit
    uint16_t tick = max_tick;
    for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
        if (g_last_hit_tracker.index[j] == led_i && g_last_hit_tracker.tick[j] < tick) {
            tick = g_last_hit_tracker.tick[j];
            break;
        }
    }
    uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
    // scaling current saturation from 0 to origin
    // e.g. tick=16000 / 256 => 62
    // hsv.s = 240 => offset = 62 * 250 / 256 = 60
    hsv.s = scale8(offset, hsv.v);
    return hsv;
}

static HSV RAINBOW_MOVING_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h += abs8(g_led_config.point[i].y - k_rgb_matrix_center.y) + (g_led_config.point[i].x - time);
    return hsv;
}

bool CYCLE_SOLID_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb;
        HSV hsv = rgb_matrix_config.hsv;
        hsv = RAINBOW_MOVING_math(hsv, i, time);
        hsv = REACTIVE_math(hsv, i, max_tick);
        rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
