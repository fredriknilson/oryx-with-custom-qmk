#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(2, KC_F17)
#define DUAL_FUNC_1 LT(14, KC_1)
#define DUAL_FUNC_2 LT(11, KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           RALT(KC_W),     
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           RALT(KC_O),     DUAL_FUNC_0,    
    KC_LEFT_CTRL,   MT(MOD_LALT, KC_Z),MT(MOD_LGUI, KC_X),KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_QUES,        KC_RIGHT_ALT,   
                                                    LT(3, KC_SPACE),LT(4, KC_TAB),                                  LT(4, KC_BSPC), LT(3, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_4,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           
    KC_G,           KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_ALT,    KC_LEFT_ALT,    KC_A,           KC_S,           KC_D,           KC_F,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_CTRL,                                   LT(4, KC_BSPC), LT(3, KC_ENTER)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_CTRL,                                   LT(3, KC_ENTER),LT(4, KC_BSPC)
  ),
  [3] = LAYOUT_voyager(
    KC_F12,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    CW_TOGG,        KC_GRAVE,       KC_LABK,        KC_RABK,        KC_MINUS,       KC_PIPE,                                        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_COLN,        KC_CIRC,        RALT(KC_5),     
    KC_LEFT_SHIFT,  KC_EXLM,        KC_ASTR,        KC_SLASH,       KC_EQUAL,       KC_AMPR,                                        KC_HASH,        KC_LPRN,        KC_RPRN,        KC_SCLN,        KC_DQUO,        KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   DUAL_FUNC_1,    DUAL_FUNC_2,    KC_BSLS,        KC_UNDS,        KC_PERC,                                        KC_AT,          KC_LBRC,        KC_RBRC,        RALT(KC_QUOTE), KC_QUOTE,       KC_RIGHT_ALT,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          KC_NO,          
    MT(MOD_LSFT, KC_AUDIO_VOL_DOWN),KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,                                KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_LBRC),  KC_NO,          LGUI(KC_RBRC),  KC_NO,          KC_RIGHT_ALT,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_INSERT,      KC_DELETE
  ),
};


const uint16_t PROGMEM combo0[] = { KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_T, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
    COMBO(combo1, TG(2)),
};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(RALT(KC_A));
        } else {
          unregister_code16(RALT(KC_A));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_TILD);
        } else {
          unregister_code16(KC_TILD);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PLUS);
        } else {
          unregister_code16(KC_PLUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


// Overrides

// Shift + , → ;
const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// Shift + . → :
const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
// shift + ? → !
const key_override_t shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
// Shift + / → back slash
const key_override_t shift_slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
// Shift + / → |
const key_override_t alt_slash_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_PIPE);
// Shift + Backspace → Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);


const key_override_t *const key_overrides[] = {
    &shift_comm_override,
    &shift_dot_override,
    &shift_ques_override,
    &shift_slsh_override,
    &alt_slash_override,
    &delete_key_override,
    NULL
};