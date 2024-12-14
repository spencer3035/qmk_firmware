#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_27_255_255,
};

/* Keymap: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0
  [0] = LAYOUT_ergodox_pretty(
 KC_EQUAL,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_TRANSPARENT,         KC_TRANSPARENT, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,
 KC_DELETE,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_TRANSPARENT,         KC_TRANSPARENT, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
 MT(MOD_LGUI, KC_TAB), KC_A,KC_S,   KC_D,   KC_F,   KC_G,                   KC_H,   KC_J,   KC_K,   KC_L,   MT(MOD_RALT, KC_SCLN),MT(MOD_RGUI, KC_QUOTE),
 KC_LEFT_SHIFT, MT(MOD_LCTL, KC_Z),KC_X,   KC_C,   KC_V,   KC_B,   KC_TRANSPARENT,         KC_TRANSPARENT, KC_N,   KC_M,   KC_COMMA,  KC_DOT,   MT(MOD_RCTL, KC_SLASH),KC_RIGHT_SHIFT,
 TG(1),   KC_GRAVE,  CW_TOGG,  KC_LEFT,  KC_RIGHT,                          KC_UP,   KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_MINUS,
 KC_TRANSPARENT, KC_INSERT,         KC_DELETE,  KC_LEFT_GUI,
 KC_HOME,                           KC_PAGE_UP,
 KC_SPACE,  KC_BSPC,  KC_END,       KC_PGDN,  KC_ESCAPE,  KC_ENTER
  ),
    // Layer 1
  [1] = LAYOUT_ergodox_pretty(
 KC_ESCAPE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRANSPARENT,         KC_TRANSPARENT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
 KC_TRANSPARENT, KC_EXLM,  KC_AT,   KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRANSPARENT,         KC_TRANSPARENT, KC_UP,   KC_7,   KC_8,   KC_9,   KC_ASTR,  KC_F12,
 KC_TRANSPARENT, KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRAVE,                  KC_DOWN,  KC_4,   KC_5,   KC_6,   KC_PLUS,  KC_TRANSPARENT,
 KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRANSPARENT,         RALT(KC_RIGHT_CTRL),KC_AMPR,  KC_1,   KC_2,   KC_3,   KC_BSLS,  KC_TRANSPARENT,
 KC_TRANSPARENT, KC_EQUAL,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                         KC_TRANSPARENT, KC_DOT,   KC_0,   KC_EQUAL,  KC_TRANSPARENT,
                         RGB_MODE_FORWARD,RGB_VAI,  RGB_TOG,  RGB_SLD,
                             KC_TRANSPARENT, TOGGLE_LAYER_COLOR,
                     RGB_VAD,  HSV_172_255_255,HSV_27_255_255, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUI
  ),
    // Layer 2
  [2] = LAYOUT_ergodox_pretty(
 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,  KC_MS_BTN2,                          KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT,
                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT,
                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};



