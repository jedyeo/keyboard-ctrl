#include QMK_KEYBOARD_H
 
#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _L4 4
 
 
// util stuff
#define M_RUN LGUI(KC_R) // run menu
#define M_EXP LGUI(KC_E) // file exp
#define M_HIDE LGUI(KC_D) // hide windows
 
// desktop switching
#define GUI_TAB LGUI(KC_TAB)
#define GC_LEFT LGUI(LCTL(KC_LEFT))
#define GC_RIGHT LGUI(LCTL(KC_RIGHT))
 
enum custom_keycodes {
    M_PANIC = SAFE_RANGE,
};
 
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    /*switch(keycode) {
        case M_PANIC:
            if(record->event.pressed) {
                tap_code16(KC_MSTP);
                //tap_code16(M_HIDE);
            }
            break;
    }*/
 
    return true;
};
 
 
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_L0] = LAYOUT_ANSI( // BASE LAYER
        KC_GESC,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,     KC_EQL,     KC_BSPC, \
        KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,    KC_BSLS, \
        KC_CAPS,         KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,     KC_ENT,              \
        KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                          \
        KC_LCTL,         MO(_L1),  KC_LALT,                      KC_SPC,                                 MO(_L1),  MO(_L3),  MO(_L2),                 KC_RCTL  \
        ),
   
    [_L1] = LAYOUT_ANSI( // SUPER
        KC_DEL,         KC_INS,    KC_HOME,  KC_END,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_VOLD,     KC_VOLU,    KC_MUTE, \
        GUI_TAB,        GC_LEFT,   KC_UP,    GC_RIGHT, M_RUN,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_UP,    KC_MPRV,     KC_MNXT,    KC_MPLY, \
        KC_TRNS,        KC_LEFT,   KC_DOWN,  KC_RGHT,  M_EXP,    KC_CALC,  KC_NO,    KC_NO,    KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT,     KC_NO,               \
        KC_TRNS,        M_HIDE,    KC_PSCR,  KC_PAUS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                            \
        KC_TRNS,        KC_TRNS,   KC_TRNS,                      KC_LGUI,                                KC_TRNS,  KC_TRNS,  KC_NO,                   OSL(_L4) \
        ),
   
    [_L2] = LAYOUT_ANSI( // FN
        KC_GRV,         KC_F1,     KC_F2,    KC_F3,   KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12,     KC_DEL, \
        KC_TRNS,        KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    GC_LEFT,     GC_RIGHT,   KC_INS, \
        KC_TRNS,        KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_PGUP,            \
        KC_TRNS,        KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PGDN,                         \
        KC_TRNS,        KC_NO,     KC_TRNS,                      KC_TRNS,                                KC_NO,    KC_TRNS,  KC_TRNS,                 KC_NO   \
        ),
   
    [_L3] = LAYOUT_ANSI( // RGB CONTROL
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_VAD,     RGB_VAI,    RGB_TOG, \
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_HUD,     RGB_HUI,    RGB_M_P, \
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_SAD,  RGB_SAI,     KC_NO,               \
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    RGB_SPD,  RGB_SPI,  KC_NO,    KC_NO,                            \
        KC_NO,          KC_NO,     KC_NO,                        KC_NO,                                  KC_NO,    KC_TRNS,  RGB_RMOD,    RGB_MOD              \
        ),
 
    [_L4] = LAYOUT_ANSI( // AFTER EFFECTS
        KC_PAST,        KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,      KC_NO, \
        KC_P0,          KC_PDOT,   KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,      KC_NO, \
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,             \
        KC_NO,          KC_NO,     KC_NO,    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                          \
        KC_NO,          KC_NO,     KC_NO,                        KC_NO,                                  KC_NO,    KC_NO,    KC_NO,       KC_TRNS            \
        ),
    };
 
void rgb_matrix_L_helper(uint8_t red, uint8_t green, uint8_t blue, bool default_L) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}
 
void rgb_matrix_indicators_user(void) {
    uint8_t this_led = host_keyboard_leds();
    if (!g_suspend_state && rgb_matrix_config.enable) {
        switch (biton32(layer_state)) {
            case _L1:
                rgb_matrix_L_helper(0xFF, 0xCC, 0xFF, false);
                break;
            case _L2:
                rgb_matrix_L_helper(0xD2, 0xFF, 0xCC, false);
                break;
            case _L3:
                //rgb_matrix_L_helper(0xFF, 0xE3, 0xCC, false);
                break;
            case _L4:
                rgb_matrix_L_helper(0xFF, 0x00, 0x00, false);
                break;
        }
    }
    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        // 54 rctrl
        // 59 spacebar
       
        //rgb_matrix_set_color(54, 0xCC, 0xDD, 0xFF);
        rgb_matrix_set_color(54, 0xFF, 0x00, 0x00);
        //rgb_matrix_set_color(59, 0xCC, 0xDD, 0xFF);
    }
}
 
void matrix_init_user(void) {
    // user initialization
}
 
void matrix_scan_user(void) {
    // user matrix
}