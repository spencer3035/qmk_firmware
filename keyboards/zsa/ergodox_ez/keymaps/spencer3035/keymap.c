#include QMK_KEYBOARD_H
#include "version.h"
#define ____ KC_TRANSPARENT
#define XXXX KC_NO
#define GEMIN QK_STENO_GEMINI
#define BOLT QK_STENO_BOLT

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    FAT_ARROW,
    THIN_ARROW,
};

enum layers {
    BASE_LAYER,
    ALT_LAYOUT_LAYER,
    GAMING_LAYER,
    GAMING_ALT_LAYER,
    SYMBOLS_LAYER,
    NAVIGATION_LAYER,
    STENOGRAPHY_LAYER,
};

#define BAL BASE_LAYER
#define SYL SYMBOLS_LAYER
#define NAL NAVIGATION_LAYER
#define STL STENOGRAPHY_LAYER
#define ALT ALT_LAYOUT_LAYER
#define GML GAMING_LAYER
#define G2L GAMING_ALT_LAYER

/* Setup:
 * 0) Setup registers, put in register q, modifies register q, w, and e. Use q to format one layer
 * 03j2w"wy$3j"ey$3j"qy$:40,$s/KC_LEFT_SHIFT/KC_LSFT/ge:40,$s/KC_RIGHT_SHIFT/KC_RSFT/ge:40,$s/QK_STENO_BOLT/BOLT/ge:40,$s/QK_STENO_GEMINI/GEMIN/ge:40,$s/KC_LEFT_GUI/KC_LGUI/ge:40,$s/KC_LEFT_CTRL/KC_LCTL/ge:40,$s/KC_LEFT_ALT/KC_LALT/ge:40,$s/KC_RIGHT_GUI/KC_RGUI/ge:40,$s/KC_RIGHT_CTRL/KC_RCTL/ge:40,$s/KC_RIGHT_ALT/KC_RALT/ge:40,$s/KC_TRANSPARENT/____/ge:40,$s/100/10/ge/\[[0-9]\]l
 *
 * 1) Reorganize columns appropriately:
 * j0EEEEEEEaj0EEEEEEEaj0EEEEEEajEEEEEEEaj0EEEEEaj0EEaj0Eaj0EEEa14kddpdjpd2jpd3jpd4jpd5jpd6jp9k
 *
 * 2) Add blank entries to appropriate columns
 * o//i*_*ddjjpkJjj2pk3J9j5pk6Jj6pk7Jj4pk5J11k5p6J6p7J4p5J2jpJj2p3J13k
 *
 * 3) Format one layer
 * @w@e:s/_pretty//jV15j:!column -tn
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_ergodox(
KC_GRAVE,  KC_1,     KC_2,               KC_3,               KC_4,               KC_5,           ____,
KC_TAB,    KC_Q,     KC_W,               KC_E,               KC_R,               KC_T,           ____,
KC_LGUI,   KC_A,     MT(MOD_LALT,KC_S),  MT(MOD_LGUI,KC_D),  MT(MOD_LCTL,KC_F),  LT(NAL,KC_G),   /*_*/
KC_LSFT,   KC_Z,     KC_X,               KC_C,               KC_V,               KC_B,           CW_TOGG,
____,      ____,     ____,               ____,               KC_ESC,             /*_*/           /*_*/
/*_*/      /*_*/     /*_*/               /*_*/               /*_*/               ____,           QK_REP,
/*_*/      /*_*/     /*_*/               /*_*/               /*_*/               /*_*/           ____,
/*_*/      /*_*/     /*_*/               /*_*/               KC_SPACE,           OSM(MOD_LSFT),  ____,
____,      KC_6,     KC_7,               KC_8,               KC_9,               KC_0,           KC_DOT,
____,      KC_Y,     KC_U,               KC_I,               KC_O,               KC_P,           KC_BSLS,
/*_*/      KC_H,     MT(MOD_RCTL,KC_J),  MT(MOD_RGUI,KC_K),  MT(MOD_RALT,KC_L),  KC_SCLN,        KC_QUOTE,
KC_MINUS,  KC_N,     KC_M,               KC_COMMA,           KC_DOT,             KC_SLASH,       KC_COLN,
/*_*/      /*_*/     OSL(SYL),           KC_LEFT,            KC_DOWN,            KC_UP,          KC_RIGHT,
QK_REP,    KC_TAB,   /*_*/               /*_*/               /*_*/               /*_*/           /*_*/
____,      /*_*/     /*_*/               /*_*/               /*_*/               /*_*/           /*_*/
TO(NAL),   KC_BSPC,  KC_ENTER            /*_*/               /*_*/               /*_*/           /*_*/
  ),
  [ALT_LAYOUT_LAYER] = LAYOUT_ergodox(
KC_GRAVE,  KC_1,      KC_2,               KC_3,               KC_4,               KC_5,           ____,
KC_TAB,    KC_B,      KC_L,               KC_D,               KC_C,               KC_Z,           ____,
KC_LGUI,   KC_N,      MT(MOD_LALT,KC_R),  MT(MOD_LGUI,KC_T),  MT(MOD_LCTL,KC_S),  LT(NAL,KC_G),   /*_*/
KC_LSFT,   KC_Q,      KC_X,               KC_M,               KC_W,               KC_V,           CW_TOGG,
XXXX,      XXXX,      QK_LOCK,            XXXX,               KC_ESC,             /*_*/           /*_*/
/*_*/      /*_*/      /*_*/               /*_*/               /*_*/               XXXX,           QK_REP,
/*_*/      /*_*/      /*_*/               /*_*/               /*_*/               /*_*/           ____,
/*_*/      /*_*/      /*_*/               /*_*/               KC_SPACE,           OSM(MOD_LSFT),  XXXX,
____,      KC_6,      KC_7,               KC_8,               KC_9,               KC_0,           KC_DOT,
____,      KC_MINUS,  KC_F,               KC_O,               KC_U,               KC_J,           KC_BSLS,
/*_*/      KC_Y,      MT(MOD_RCTL,KC_H),  MT(MOD_RGUI,KC_A),  MT(MOD_RALT,KC_E),  KC_I,           KC_SCLN,
XXXX,      KC_K,      KC_P,               KC_COMMA,           KC_DOT,             KC_SLASH,       KC_QUOTE,
/*_*/      /*_*/      OSL(SYL),           KC_LEFT,            KC_DOWN,            KC_UP,          KC_RIGHT,
QK_REP,    KC_TAB,    /*_*/               /*_*/               /*_*/               /*_*/           /*_*/
XXXX,      /*_*/      /*_*/               /*_*/               /*_*/               /*_*/           /*_*/
TO(NAL),   KC_BSPC,   KC_ENTER            /*_*/               /*_*/               /*_*/           /*_*/
  ),
  [GAMING_LAYER] = LAYOUT_ergodox(
KC_GRAVE,  KC_1,     KC_2,      KC_3,      KC_4,      KC_5,      XXXX,
KC_TAB,    KC_Q,     KC_W,      KC_E,      KC_R,      KC_T,      XXXX,
XXXX,      KC_A,     KC_S,      KC_D,      KC_F,      KC_G,      /*_*/
KC_LSFT,   KC_Z,     KC_X,      KC_C,      KC_V,      KC_B,      XXXX,
KC_LCTL,   KC_LALT,  QK_LOCK,   XXXX,      KC_ESC,    /*_*/      /*_*/
/*_*/      /*_*/     /*_*/      /*_*/      /*_*/      KC_LCTL,   QK_REP,
/*_*/      /*_*/     /*_*/      /*_*/      /*_*/      /*_*/      XXXX,
/*_*/      /*_*/     /*_*/      /*_*/      KC_SPACE,  KC_LSFT,   OSL(G2L),
____,      KC_6,     KC_7,      KC_8,      KC_9,      KC_0,      KC_DOT,
TO(STL),   KC_Y,     KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
/*_*/      KC_H,     KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOTE,
KC_MINUS,  KC_N,     KC_M,      KC_COMMA,  KC_DOT,    KC_SLASH,  KC_COLN,
/*_*/      /*_*/     OSL(SYL),  KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,
QK_REP,    KC_TAB,   /*_*/      /*_*/      /*_*/      /*_*/      /*_*/
XXXX,      /*_*/     /*_*/      /*_*/      /*_*/      /*_*/      /*_*/
TO(NAL),   KC_BSPC,  KC_ENTER   /*_*/      /*_*/      /*_*/      /*_*/
  ),
  [GAMING_ALT_LAYER] = LAYOUT_ergodox(
XXXX,     KC_6,     KC_7,     KC_8,      KC_9,      KC_0,      XXXX,
XXXX,     KC_Y,     KC_U,     KC_I,      KC_O,      KC_P,      XXXX,
XXXX,     KC_H,     KC_J,     KC_K,      KC_L,      KC_SCLN,   /*_*/
XXXX,     KC_N,     KC_M,     KC_COMMA,  KC_DOT,    KC_SLASH,  XXXX,
XXXX,     XXXX,     XXXX,     XXXX,      KC_ESC,    /*_*/      /*_*/
/*_*/     /*_*/     /*_*/     /*_*/      /*_*/      TO(GML),   QK_REP,
/*_*/     /*_*/     /*_*/     /*_*/      /*_*/      /*_*/      XXXX,
/*_*/     /*_*/     /*_*/     /*_*/      KC_SPACE,  KC_LSFT,   KC_LCTL,
____,     ____,     ____,     ____,      ____,      ____,      ____,
____,     ____,     ____,     ____,      ____,      ____,      ____,
/*_*/     ____,     ____,     ____,      ____,      ____,      ____,
____,     ____,     ____,     ____,      ____,      ____,      ____,
/*_*/     /*_*/     XXXX,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,
QK_REP,   KC_TAB,   /*_*/     /*_*/      /*_*/      /*_*/      /*_*/
XXXX,     /*_*/     /*_*/     /*_*/      /*_*/      /*_*/      /*_*/
TO(BAL),  KC_BSPC,  KC_ENTER  /*_*/      /*_*/      /*_*/      /*_*/
  ),
  [SYMBOLS_LAYER] = LAYOUT_ergodox(
XXXX,     KC_KP_1,     KC_KP_2,      KC_KP_3,      KC_KP_4,    KC_KP_5,      KC_NUM_LOCK,
XXXX,     KC_CIRC,     KC_KP_MINUS,  KC_AMPR,      KC_LCBR,    XXXX,         XXXX,
XXXX,     KC_PIPE,     KC_KP_PLUS,   KC_EXLM,      KC_LPRN,    KC_PAST,      /*_*/
XXXX,     THIN_ARROW,  FAT_ARROW,    KC_HASH,      KC_LBRC,    XXXX,         XXXX,
XXXX,     XXXX,        XXXX,         XXXX,         XXXX,       /*_*/         /*_*/
/*_*/     /*_*/        /*_*/         /*_*/         /*_*/       XXXX,         XXXX,
/*_*/     /*_*/        /*_*/         /*_*/         /*_*/       /*_*/         XXXX,
/*_*/     /*_*/        /*_*/         /*_*/         XXXX,       XXXX,         XXXX,
XXXX,     KC_KP_6,     KC_KP_7,      KC_KP_8,      KC_KP_9,    KC_KP_0,      KC_KP_DOT,
XXXX,     XXXX,        KC_RCBR,      KC_GRAVE,     XXXX,       XXXX,         XXXX,
/*_*/     KC_TILD,     KC_RPRN,      KC_DQUO,      KC_EQUAL,   KC_SCLN,      XXXX,
XXXX,     XXXX,        KC_RBRC,      KC_KP_COMMA,  KC_KP_DOT,  KC_KP_SLASH,  XXXX,
/*_*/     /*_*/        TO(BAL),      XXXX,         XXXX,       XXXX,         XXXX,
XXXX,     XXXX,        /*_*/         /*_*/         /*_*/       /*_*/         /*_*/
XXXX,     /*_*/        /*_*/         /*_*/         /*_*/       /*_*/         /*_*/
TO(BAL),  XXXX,        KC_KP_ENTER   /*_*/         /*_*/       /*_*/         /*_*/
  ),
  [NAVIGATION_LAYER] = LAYOUT_ergodox(
____,     KC_F1,    KC_F2,                 KC_F3,               KC_F4,                  KC_F5,   KC_F12,
____,     TO(BAL),  TO(ALT),               TO(STL),             TO(GML),                ____,    ____,
____,     ____,     KC_LALT,               KC_LGUI,             KC_LCTL,                ____,    /*_*/
____,     ____,     ____,                  ____,                ____,                   ____,    ____,
____,     ____,     ____,                  ____,                ____,                   /*_*/    /*_*/
/*_*/     /*_*/     /*_*/                  /*_*/                /*_*/                   ____,    ____,
/*_*/     /*_*/     /*_*/                  /*_*/                /*_*/                   /*_*/    ____,
/*_*/     /*_*/     /*_*/                  /*_*/                ____,                   ____,    ____,
____,     KC_F6,    KC_F7,                 KC_F8,               KC_F9,                  KC_F10,  KC_F11,
____,     ____,     ____,                  KC_INSERT,           ____,                   ____,    ____,
/*_*/     KC_LEFT,  MT(MOD_RCTL,KC_DOWN),  MT(MOD_RGUI,KC_UP),  MT(MOD_RALT,KC_RIGHT),  ____,    ____,
____,     KC_HOME,  KC_PGDN,               KC_PAGE_UP,          KC_END,                 ____,    ____,
/*_*/     /*_*/     ____,                  ____,                ____,                   ____,    ____,
____,     ____,     /*_*/                  /*_*/                /*_*/                   /*_*/    /*_*/
____,     /*_*/     /*_*/                  /*_*/                /*_*/                   /*_*/    /*_*/
TO(BAL),  KC_DEL,   ____                   /*_*/                /*_*/                   /*_*/    /*_*/
  ),
  [STENOGRAPHY_LAYER] = LAYOUT_ergodox(
____,     XXXX,     STN_N2,   STN_N3,  STN_N4,  STN_N5,   BOLT,
____,     STN_N1,   STN_TL,   STN_PL,  STN_HL,  STN_ST1,  ____,
____,     STN_S1,   STN_KL,   STN_WL,  STN_RL,  STN_ST2,  /*_*/
____,     STN_S2,   XXXX,     XXXX,    XXXX,    XXXX,     XXXX,
____,     ____,     ____,     ____,    STN_NC,  /*_*/     /*_*/
/*_*/     /*_*/     /*_*/     /*_*/    /*_*/    STN_NC,   STN_RES1,
/*_*/     /*_*/     /*_*/     /*_*/    /*_*/    /*_*/     STN_RES2,
/*_*/     /*_*/     /*_*/     /*_*/    STN_A,   STN_O,    ____,
GEMIN,    STN_N6,   STN_N7,   STN_N8,  STN_N9,  XXXX,     XXXX,
____,     STN_ST3,  STN_FR,   STN_PR,  STN_LR,  STN_NA,   STN_NB,
/*_*/     STN_ST4,  STN_RR,   STN_BR,  STN_GR,  STN_TR,   STN_DR,
____,     XXXX,     STN_ST4,  XXXX,    XXXX,    STN_SR,   STN_ZR,
/*_*/     /*_*/     STN_NC,   ____,    ____,    ____,     ____,
STN_FN,   STN_NC,   /*_*/     /*_*/    /*_*/    /*_*/     /*_*/
STN_PWR,  /*_*/     /*_*/     /*_*/    /*_*/    /*_*/     /*_*/
TO(BAL),  STN_E,    STN_U     /*_*/    /*_*/    /*_*/     /*_*/
  ),
};

enum combo_events {
    CHANGE_DIR,
};

const uint16_t PROGMEM change_dir[] = { KC_D, KC_C, COMBO_END};

combo_t key_combos[] = {
    [CHANGE_DIR] = COMBO_ACTION(change_dir),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CHANGE_DIR:
            if (pressed) {
                SEND_STRING("cd ");
            }
            break;
    }
}


bool process_macro_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FAT_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=> ");
            }
            break;
        case THIN_ARROW:
            if (record->event.pressed) {
                SEND_STRING("-> ");
            }
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_macro_user(keycode, record);
    return true;
}

uint8_t layer_state_set_user(uint8_t state) {
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

// Alternate keycodes
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    switch (keycode) {
        case KC_D:
            return KC_E;
        case KC_TAB:
            if (shifted) {
                return KC_TAB;
            } else {
                return S(KC_TAB);
            }
        case KC_LPRN:
            return KC_RPRN;
        default:
            return ____;
    }
}
