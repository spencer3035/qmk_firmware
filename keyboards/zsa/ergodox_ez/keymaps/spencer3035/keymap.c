#include QMK_KEYBOARD_H
#include "version.h"
#define ____ KC_TRANSPARENT
#define GEMIN QK_STENO_GEMINI
#define BOLT QK_STENO_BOLT

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
};

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
  [0] = LAYOUT_ergodox(
____,     ____,               ____,      ____,      ____,        ____,                   ____,
____,     KC_Q,               KC_W,      KC_E,      KC_R,        KC_T,                   KC_ESCAPE,
KC_LGUI,  MT(MOD_LALT,KC_A),  KC_S,      KC_D,      LT(4,KC_F),  LT(5,KC_G),             /*_*/
____,     MT(MOD_LCTL,KC_Z),  KC_X,      KC_C,      KC_V,        KC_B,                   CW_TOGG,
____,     ____,               ____,      OSL(3),    OSL(2),      /*_*/                   /*_*/
/*_*/     /*_*/               /*_*/      /*_*/      /*_*/        OSM(MOD_LGUI),          DM_PLY1,
/*_*/     /*_*/               /*_*/      /*_*/      /*_*/        /*_*/                   DM_RSTP,
/*_*/     /*_*/               /*_*/      /*_*/      KC_SPACE,    OSM(MOD_LSFT),          QK_REP,
TO(1),    ____,               ____,      ____,      ____,        ____,                   ____,
TO(7),    KC_Y,               KC_U,      KC_I,      KC_O,        KC_P,                   KC_BSLS,
/*_*/     KC_H,               KC_J,      KC_K,      KC_L,        MT(MOD_RALT,KC_SCLN),   KC_QUOTE,
____,     KC_N,               KC_M,      KC_COMMA,  KC_DOT,      MT(MOD_RCTL,KC_SLASH),  KC_COLN,
/*_*/     /*_*/               KC_MINUS,  KC_LEFT,   KC_DOWN,     KC_UP,                  KC_RIGHT,
DM_PLY2,  OSL(6),             /*_*/      /*_*/      /*_*/        /*_*/                   /*_*/
KC_TAB,   /*_*/               /*_*/      /*_*/      /*_*/        /*_*/                   /*_*/
QK_AREP,  KC_BSPC,            KC_ENTER   /*_*/      /*_*/        /*_*/                   /*_*/
  ),
  [1] = LAYOUT_ergodox(
KC_GRAVE,  KC_1,  KC_2,     KC_3,  KC_4,       KC_5,      ____,
KC_TAB,    ____,  ____,     ____,  ____,       ____,      ____,
KC_LCTL,   KC_A,  ____,     ____,  KC_F,       KC_G,      /*_*/
KC_LSFT,   KC_Z,  ____,     ____,  ____,       ____,      ____,
KC_LALT,   ____,  QK_LOCK,  ____,  KC_ESCAPE,  /*_*/      /*_*/
/*_*/      /*_*/  /*_*/     /*_*/  /*_*/       ____,      ____,
/*_*/      /*_*/  /*_*/     /*_*/  /*_*/       /*_*/      ____,
/*_*/      /*_*/  /*_*/     /*_*/  ____,       ____,      ____,
TO(0),     KC_6,  KC_7,     KC_8,  KC_9,       KC_0,      KC_MINUS,
____,      ____,  ____,     ____,  ____,       ____,      ____,
/*_*/      ____,  ____,     ____,  ____,       KC_SCLN,   ____,
____,      ____,  ____,     ____,  ____,       KC_SLASH,  KC_RSFT,
/*_*/      /*_*/  ____,     ____,  ____,       ____,      ____,
____,      ____,  /*_*/     /*_*/  /*_*/       /*_*/      /*_*/
____,      /*_*/  /*_*/     /*_*/  /*_*/       /*_*/      /*_*/
____,      ____,  KC_ENTER  /*_*/  /*_*/       /*_*/      /*_*/
  ),
  [2] = LAYOUT_ergodox(
____,  ____,      ____,    ____,      ____,           ____,      ____,
____,  ____,      ____,    ____,      ____,           ____,      ____,
____,  KC_LALT,   ____,    KC_SPACE,  OSM(MOD_LGUI),  ____,      /*_*/
____,  KC_LCTL,   ____,    ____,      ____,           ____,      ____,
____,  ____,      ____,    ____,      TO(0),          /*_*/      /*_*/
/*_*/  /*_*/      /*_*/    /*_*/      /*_*/           ____,      ____,
/*_*/  /*_*/      /*_*/    /*_*/      /*_*/           /*_*/      ____,
/*_*/  /*_*/      /*_*/    /*_*/      ____,           ____,      ____,
____,  ____,      ____,    ____,      ____,           ____,      ____,
____,  KC_MINUS,  KC_7,    KC_8,      KC_9,           KC_GRAVE,  ____,
/*_*/  KC_LBRC,   KC_4,    KC_5,      KC_6,           KC_RBRC,   KC_DQUO,
____,  KC_EQUAL,  KC_1,    KC_2,      KC_3,           ____,      ____,
/*_*/  /*_*/      KC_DOT,  ____,      ____,           ____,      ____,
____,  ____,      /*_*/    /*_*/      /*_*/           /*_*/      /*_*/
____,  /*_*/      /*_*/    /*_*/      /*_*/           /*_*/      /*_*/
____,  ____,      KC_0     /*_*/      /*_*/           /*_*/      /*_*/
  ),
  [3] = LAYOUT_ergodox(
____,  ____,     ____,     ____,      ____,           ____,     ____,
____,  ____,     ____,     ____,      ____,           ____,     ____,
____,  KC_LALT,  ____,     KC_SPACE,  OSM(MOD_RGUI),  ____,     /*_*/
____,  KC_LCTL,  ____,     ____,      ____,           ____,     ____,
____,  ____,     ____,     TO(0),     ____,           /*_*/     /*_*/
/*_*/  /*_*/     /*_*/     /*_*/      /*_*/           ____,     ____,
/*_*/  /*_*/     /*_*/     /*_*/      /*_*/           /*_*/     ____,
/*_*/  /*_*/     /*_*/     /*_*/      ____,           ____,     ____,
____,  ____,     ____,     ____,      ____,           ____,     ____,
____,  KC_UNDS,  KC_AMPR,  KC_ASTR,   KC_LPRN,        KC_TILD,  KC_PIPE,
/*_*/  KC_LCBR,  KC_DLR,   KC_PERC,   KC_CIRC,        KC_RCBR,  KC_DQUO,
____,  KC_PLUS,  KC_EXLM,  KC_AT,     KC_HASH,        ____,     ____,
/*_*/  /*_*/     ____,     ____,      ____,           ____,     ____,
____,  ____,     /*_*/     /*_*/      /*_*/           /*_*/     /*_*/
____,  /*_*/     /*_*/     /*_*/      /*_*/           /*_*/     /*_*/
____,  ____,     KC_RPRN   /*_*/      /*_*/           /*_*/     /*_*/
  ),
  [4] = LAYOUT_ergodox(
____,  ____,     ____,          ____,        ____,      ____,     ____,
____,  ____,     ____,          ____,        ____,      ____,     ____,
____,  KC_LALT,  ____,          KC_DELETE,   ____,      ____,     /*_*/
____,  KC_LCTL,  ____,          ____,        ____,      ____,     ____,
____,  ____,     ____,          ____,        ____,      /*_*/     /*_*/
/*_*/  /*_*/     /*_*/          /*_*/        /*_*/      ____,     ____,
/*_*/  /*_*/     /*_*/          /*_*/        /*_*/      /*_*/     ____,
/*_*/  /*_*/     /*_*/          /*_*/        ____,      ____,     ____,
____,  ____,     ____,          ____,        ____,      ____,     ____,
____,  ____,     ____,          KC_INSERT,   ____,      ____,     ____,
/*_*/  KC_LEFT,  KC_DOWN,       KC_UP,       KC_RIGHT,  KC_RALT,  ____,
____,  KC_HOME,  KC_PGDN,       KC_PAGE_UP,  KC_END,    KC_RCTL,  ____,
/*_*/  /*_*/     LALT(KC_TAB),  ____,        ____,      ____,     ____,
____,  ____,     /*_*/          /*_*/        /*_*/      /*_*/     /*_*/
____,  /*_*/     /*_*/          /*_*/        /*_*/      /*_*/     /*_*/
____,  ____,     OSM(MOD_RGUI)  /*_*/        /*_*/      /*_*/     /*_*/
  ),
  [5] = LAYOUT_ergodox(
____,  ____,     ____,   ____,   ____,   ____,     ____,
____,  ____,     ____,   ____,   ____,   ____,     ____,
____,  KC_LALT,  ____,   KC_D,   KC_F,   ____,     /*_*/
____,  KC_LCTL,  ____,   ____,   ____,   ____,     ____,
____,  ____,     ____,   ____,   ____,   /*_*/     /*_*/
/*_*/  /*_*/     /*_*/   /*_*/   /*_*/   ____,     ____,
/*_*/  /*_*/     /*_*/   /*_*/   /*_*/   /*_*/     ____,
/*_*/  /*_*/     /*_*/   /*_*/   ____,   ____,     ____,
____,  ____,     ____,   ____,   ____,   ____,     ____,
____,  KC_F12,   KC_F7,  KC_F8,  KC_F9,  ____,     ____,
/*_*/  KC_F11,   KC_F4,  KC_F5,  KC_F6,  KC_RALT,  ____,
____,  KC_F10,   KC_F1,  KC_F2,  KC_F3,  KC_RCTL,  ____,
/*_*/  /*_*/     ____,   ____,   ____,   ____,     ____,
____,  ____,     /*_*/   /*_*/   /*_*/   /*_*/     /*_*/
____,  /*_*/     /*_*/   /*_*/   /*_*/   /*_*/     /*_*/
____,  ____,     ____    /*_*/   /*_*/   /*_*/     /*_*/
  ),
  [6] = LAYOUT_ergodox(
____,  DM_REC1,      DM_REC2,  ____,        ____,        ____,         ____,
____,  ST_MACRO_0,   KC_NO,    ST_MACRO_1,  KC_NO,       KC_NO,        ____,
____,  ST_MACRO_2,   KC_NO,    ST_MACRO_3,  KC_NO,       KC_NO,        /*_*/
____,  KC_NO,        KC_NO,    ST_MACRO_4,  KC_NO,       ST_MACRO_5,   ____,
____,  ____,         ____,     ____,        ____,        /*_*/         /*_*/
/*_*/  /*_*/         /*_*/     /*_*/        /*_*/        ____,         ____,
/*_*/  /*_*/         /*_*/     /*_*/        /*_*/        /*_*/         ____,
/*_*/  /*_*/         /*_*/     /*_*/        ____,        ____,         ____,
____,  ____,         ____,     ____,        ____,        ____,         ____,
____,  ST_MACRO_6,   KC_NO,    ST_MACRO_7,  ST_MACRO_8,  KC_NO,        ____,
/*_*/  ST_MACRO_9,   KC_NO,    KC_NO,       KC_NO,       ST_MACRO_10,  ____,
____,  ST_MACRO_11,  KC_NO,    KC_NO,       KC_NO,       ST_MACRO_12,  ____,
/*_*/  /*_*/         ____,     ____,        ____,        ____,         ____,
____,  ____,         /*_*/     /*_*/        /*_*/        /*_*/         /*_*/
____,  /*_*/         /*_*/     /*_*/        /*_*/        /*_*/         /*_*/
____,  ____,         ____      /*_*/        /*_*/        /*_*/         /*_*/
  ),
  [7] = LAYOUT_ergodox(
____,     KC_NO,    STN_N2,  STN_N3,  STN_N4,  STN_N5,   BOLT,
____,     STN_N1,   STN_TL,  STN_PL,  STN_HL,  STN_ST1,  ____,
____,     STN_S1,   STN_KL,  STN_WL,  STN_RL,  STN_ST2,  /*_*/
____,     STN_S2,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
____,     ____,     ____,    ____,    STN_NC,  /*_*/     /*_*/
/*_*/     /*_*/     /*_*/    /*_*/    /*_*/    STN_NC,   STN_RES1,
/*_*/     /*_*/     /*_*/    /*_*/    /*_*/    /*_*/     STN_RES2,
/*_*/     /*_*/     /*_*/    /*_*/    STN_A,   STN_O,    ____,
GEMIN,    STN_N6,   STN_N7,  STN_N8,  STN_N9,  KC_NO,    KC_NO,
TO(0),    STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_NA,   STN_NB,
/*_*/     STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_TR,   STN_DR,
____,     KC_NO,    KC_NO,   KC_NO,   KC_NO,   STN_SR,   STN_ZR,
/*_*/     /*_*/     STN_NC,  ____,    ____,    ____,     ____,
STN_FN,   STN_NC,   /*_*/    /*_*/    /*_*/    /*_*/     /*_*/
STN_PWR,  /*_*/     /*_*/    /*_*/    /*_*/    /*_*/     /*_*/
____,     STN_E,    STN_U    /*_*/    /*_*/    /*_*/     /*_*/
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(10) SS_TAP(X_Q) SS_DELAY(10) SS_LSFT(SS_TAP(X_1))  SS_DELAY(10) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT) SS_DELAY(10) SS_TAP(X_DOT) SS_DELAY(10) SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C) SS_DELAY(10) SS_TAP(X_D) SS_DELAY(10) SS_TAP(X_SPACE) SS_DELAY(10) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(10) SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(10) SS_TAP(X_RBRC) SS_DELAY(10) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(10) SS_TAP(X_EQUAL) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8)) SS_DELAY(10) SS_TAP(X_EQUAL) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(10) SS_LSFT(SS_TAP(X_0)) SS_DELAY(10) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)) SS_DELAY(10) SS_LSFT(SS_TAP(X_RBRC)) SS_DELAY(10) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_0)) SS_DELAY(10) SS_TAP(X_SCLN)  SS_DELAY(10) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(10) SS_TAP(X_EQUAL) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH) SS_DELAY(10) SS_TAP(X_EQUAL) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;

  }
  return true;
}

uint16_t layer_state_set_user(uint16_t state) {
    uint8_t layer = biton16(state);
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
    switch (keycode) {
        case KC_C:
            return KC_D;
        case KC_Q:
            return KC_A;
        case KC_E:
            return KC_D;
        default:
            return ____;
    }
}
