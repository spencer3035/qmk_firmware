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
    UP_DIR,
    PAREN_END,
    Q_PAREN_END,
    CLOPEN_SQ,
    CLOPEN_PAREN,
    CLOPEN_CURLY,
};

enum layers {
    BASE_LAYER,
    GAMING_LAYER,
    SYMBOLS_LAYER,
    NAVIGATION_LAYER,
    FUNCTION_LAYER,
    MACROS_LAYER,
    STENOGRAPHY_LAYER,
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
  [BASE_LAYER] = LAYOUT_ergodox(
____,      KC_1,               KC_2,     KC_3,      KC_4,      KC_5,                   ____,
____,      KC_Q,               KC_W,     KC_E,      KC_R,      KC_T,                   KC_ESCAPE,
KC_LGUI,   MT(MOD_LALT,KC_A),  KC_S,     KC_D,      KC_F,      KC_G,                   /*_*/
____,      MT(MOD_LCTL,KC_Z),  KC_X,     KC_C,      KC_V,      KC_B,                   CW_TOGG,
____,      ____,               ____,     ____,      TO(2),     /*_*/                   /*_*/
/*_*/      /*_*/               /*_*/     /*_*/      /*_*/      OSM(MOD_LGUI),          DM_PLY1,
/*_*/      /*_*/               /*_*/     /*_*/      /*_*/      /*_*/                   DM_RSTP,
/*_*/      /*_*/               /*_*/     /*_*/      KC_SPACE,  OSM(MOD_LSFT),          QK_REP,
TO(1),     KC_6,               KC_7,     KC_8,      KC_9,      KC_0,                   ____,
TO(6),     KC_Y,               KC_U,     KC_I,      KC_O,      KC_P,                   KC_BSLS,
/*_*/      KC_H,               KC_J,     KC_K,      KC_L,      MT(MOD_RALT,KC_SCLN),   KC_QUOTE,
KC_MINUS,  KC_N,               KC_M,     KC_COMMA,  KC_DOT,    MT(MOD_RCTL,KC_SLASH),  KC_COLN,
/*_*/      /*_*/               OSL(2),   KC_LEFT,   KC_DOWN,   KC_UP,                  KC_RIGHT,
DM_PLY2,   KC_TAB,             /*_*/     /*_*/      /*_*/      /*_*/                   /*_*/
OSL(5),    /*_*/               /*_*/     /*_*/      /*_*/      /*_*/                   /*_*/
QK_AREP,   KC_BSPC,            KC_ENTER  /*_*/      /*_*/      /*_*/                   /*_*/
  ),
  [GAMING_LAYER] = LAYOUT_ergodox(
KC_GRAVE,  ____,  ____,     ____,  ____,       ____,      ____,
KC_TAB,    ____,  ____,     ____,  ____,       ____,      ____,
KC_LCTL,   KC_A,  ____,     ____,  KC_F,       ____,      /*_*/
KC_LSFT,   KC_Z,  ____,     ____,  ____,       ____,      ____,
KC_LALT,   ____,  QK_LOCK,  ____,  KC_ESCAPE,  /*_*/      /*_*/
/*_*/      /*_*/  /*_*/     /*_*/  /*_*/       ____,      ____,
/*_*/      /*_*/  /*_*/     /*_*/  /*_*/       /*_*/      ____,
/*_*/      /*_*/  /*_*/     /*_*/  ____,       ____,      ____,
TO(0),     ____,  ____,     ____,  ____,       ____,      KC_EQUAL,
XXXX,      ____,  ____,     ____,  ____,       ____,      ____,
/*_*/      ____,  ____,     ____,  ____,       KC_SCLN,   ____,
____,      ____,  ____,     ____,  ____,       KC_SLASH,  KC_RSFT,
/*_*/      /*_*/  XXXX,     ____,  ____,       ____,      ____,
____,      ____,  /*_*/     /*_*/  /*_*/       /*_*/      /*_*/
____,      /*_*/  /*_*/     /*_*/  /*_*/       /*_*/      /*_*/
____,      ____,  ____      /*_*/  /*_*/       /*_*/      /*_*/
  ),
  [SYMBOLS_LAYER] = LAYOUT_ergodox(
____,  ____,     ____,      ____,      ____,      ____,      ____,
____,  KC_CIRC,  KC_MINUS,  KC_AMPR,   KC_LCBR,   ____,      ____,
____,  KC_PIPE,  KC_PLUS,   KC_EXLM,   KC_LPRN,   KC_ASTR,   /*_*/
____,  ____,     ____,      KC_HASH,   KC_LBRC,   ____,      ____,
____,  ____,     ____,      ____,      TO(0),     /*_*/      /*_*/
/*_*/  /*_*/     /*_*/      /*_*/      /*_*/      ____,      ____,
/*_*/  /*_*/     /*_*/      /*_*/      /*_*/      /*_*/      ____,
/*_*/  /*_*/     /*_*/      /*_*/      ____,      ____,      ____,
____,  ____,     ____,      ____,      ____,      ____,      KC_DOT,
____,  ____,     KC_RCBR,   KC_GRAVE,  ____,      ____,      ____,
/*_*/  KC_TILD,  KC_RPRN,   KC_DQUO,   KC_EQUAL,  KC_SCLN,   ____,
____,  ____,     KC_RBRC,   ____,      ____,      KC_SLASH,  ____,
/*_*/  /*_*/     TO(0),     ____,      ____,      ____,      ____,
____,  ____,     /*_*/      /*_*/      /*_*/      /*_*/      /*_*/
____,  /*_*/     /*_*/      /*_*/      /*_*/      /*_*/      /*_*/
____,  ____,     ____       /*_*/      /*_*/      /*_*/      /*_*/
  ),
  [NAVIGATION_LAYER] = LAYOUT_ergodox(
____,  ____,           ____,          ____,        ____,      ____,     ____,
____,  LCTL(KC_LALT),  ____,          ____,        ____,      ____,     ____,
____,  KC_LALT,        ____,          KC_DELETE,   ____,      ____,     /*_*/
____,  KC_LCTL,        ____,          ____,        ____,      ____,     ____,
____,  ____,           ____,          ____,        ____,      /*_*/     /*_*/
/*_*/  /*_*/           /*_*/          /*_*/        /*_*/      ____,     ____,
/*_*/  /*_*/           /*_*/          /*_*/        /*_*/      /*_*/     ____,
/*_*/  /*_*/           /*_*/          /*_*/        ____,      ____,     ____,
____,  ____,           ____,          ____,        ____,      ____,     ____,
____,  ____,           ____,          KC_INSERT,   ____,      ____,     ____,
/*_*/  KC_LEFT,        KC_DOWN,       KC_UP,       KC_RIGHT,  KC_RALT,  ____,
____,  KC_HOME,        KC_PGDN,       KC_PAGE_UP,  KC_END,    KC_RCTL,  ____,
/*_*/  /*_*/           LALT(KC_TAB),  ____,        ____,      ____,     ____,
____,  ____,           /*_*/          /*_*/        /*_*/      /*_*/     /*_*/
____,  /*_*/           /*_*/          /*_*/        /*_*/      /*_*/     /*_*/
____,  ____,           ____           /*_*/        /*_*/      /*_*/     /*_*/
  ),
  [FUNCTION_LAYER] = LAYOUT_ergodox(
____,  ____,           ____,   ____,   ____,   ____,  ____,
____,  LCTL(KC_LALT),  ____,   ____,   ____,   ____,  ____,
____,  KC_LALT,        ____,   ____,   KC_F,   ____,  /*_*/
____,  KC_LCTL,        ____,   ____,   ____,   ____,  ____,
____,  ____,           ____,   ____,   ____,   /*_*/  /*_*/
/*_*/  /*_*/           /*_*/   /*_*/   /*_*/   ____,  ____,
/*_*/  /*_*/           /*_*/   /*_*/   /*_*/   /*_*/  ____,
/*_*/  /*_*/           /*_*/   /*_*/   ____,   ____,  ____,
____,  ____,           ____,   ____,   ____,   ____,  ____,
____,  KC_F12,         KC_F7,  KC_F8,  KC_F9,  ____,  ____,
/*_*/  KC_F11,         KC_F4,  KC_F5,  KC_F6,  ____,  ____,
____,  KC_F10,         KC_F1,  KC_F2,  KC_F3,  ____,  ____,
/*_*/  /*_*/           ____,   ____,   ____,   ____,  ____,
____,  ____,           /*_*/   /*_*/   /*_*/   /*_*/  /*_*/
____,  /*_*/           /*_*/   /*_*/   /*_*/   /*_*/  /*_*/
____,  ____,           ____    /*_*/   /*_*/   /*_*/  /*_*/
  ),
  [MACROS_LAYER] = LAYOUT_ergodox(
____,   DM_REC1,       DM_REC2,  XXXX,       XXXX,          XXXX,         ____,
____,   XXXX,          XXXX,     FAT_ARROW,  XXXX,          XXXX,         ____,
____,   THIN_ARROW,    XXXX,     UP_DIR,     PAREN_END,     Q_PAREN_END,  /*_*/
____,   XXXX,          XXXX,     XXXX,       XXXX,          CLOPEN_SQ,    ____,
____,   ____,          ____,     ____,       ____,          /*_*/         /*_*/
/*_*/   /*_*/          /*_*/     /*_*/       /*_*/          ____,         ____,
/*_*/   /*_*/          /*_*/     /*_*/       /*_*/          /*_*/         ____,
/*_*/   /*_*/          /*_*/     /*_*/       ____,          ____,         ____,
____,   XXXX,          XXXX,     XXXX,       XXXX,          XXXX,         ____,
____,   XXXX,          XXXX,     XXXX,       CLOPEN_PAREN,  XXXX,         ____,
/*_*/   CLOPEN_CURLY,  XXXX,     XXXX,       XXXX,          XXXX,         ____,
____,   XXXX,          XXXX,     XXXX,       XXXX,          XXXX,         ____,
/*_*/   /*_*/          ____,     ____,       ____,          ____,         ____,
____,   ____,          /*_*/     /*_*/       /*_*/          /*_*/         /*_*/
TO(0),  /*_*/          /*_*/     /*_*/       /*_*/          /*_*/         /*_*/
____,   ____,          ____      /*_*/       /*_*/          /*_*/         /*_*/
  ),
  [STENOGRAPHY_LAYER] = LAYOUT_ergodox(
____,     XXXX,     STN_N2,  STN_N3,  STN_N4,  STN_N5,   BOLT,
____,     STN_N1,   STN_TL,  STN_PL,  STN_HL,  STN_ST1,  ____,
____,     STN_S1,   STN_KL,  STN_WL,  STN_RL,  STN_ST2,  /*_*/
____,     STN_S2,   XXXX,    XXXX,    XXXX,    XXXX,     XXXX,
____,     ____,     ____,    ____,    STN_NC,  /*_*/     /*_*/
/*_*/     /*_*/     /*_*/    /*_*/    /*_*/    STN_NC,   STN_RES1,
/*_*/     /*_*/     /*_*/    /*_*/    /*_*/    /*_*/     STN_RES2,
/*_*/     /*_*/     /*_*/    /*_*/    STN_A,   STN_O,    ____,
GEMIN,    STN_N6,   STN_N7,  STN_N8,  STN_N9,  XXXX,     XXXX,
TO(0),    STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_NA,   STN_NB,
/*_*/     STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_TR,   STN_DR,
____,     XXXX,     XXXX,    XXXX,    XXXX,    STN_SR,   STN_ZR,
/*_*/     /*_*/     STN_NC,  ____,    ____,    ____,     ____,
STN_FN,   STN_NC,   /*_*/    /*_*/    /*_*/    /*_*/     /*_*/
STN_PWR,  /*_*/     /*_*/    /*_*/    /*_*/    /*_*/     /*_*/
____,     STN_E,    STN_U    /*_*/    /*_*/    /*_*/     /*_*/
  ),
};

enum combo_events {
    TO_NAV,
    TO_FN,
    CHANGE_DIR,
};

const uint16_t PROGMEM to_nav[] = { KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM to_fn[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM change_dir[] = { KC_D, KC_C, COMBO_END};

combo_t key_combos[] = {
    [TO_NAV] = COMBO_ACTION(to_nav),
    [TO_FN] = COMBO_ACTION(to_fn),
    [CHANGE_DIR] = COMBO_ACTION(change_dir),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case TO_NAV:
            if (pressed) {
                set_oneshot_layer(NAVIGATION_LAYER, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case TO_FN:
            if (pressed) {
                set_oneshot_layer(FUNCTION_LAYER, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case CHANGE_DIR:
            if (pressed) {
                SEND_STRING("cd ");
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case UP_DIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;
        case PAREN_END:
            if (record->event.pressed) {
                SEND_STRING(");\n");
            }
            break;
        case Q_PAREN_END:
            if (record->event.pressed) {
                SEND_STRING("\");\n");
            }
            break;
        case CLOPEN_SQ:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case CLOPEN_PAREN:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case CLOPEN_CURLY:
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
    }
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
