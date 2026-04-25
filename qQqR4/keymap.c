#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  MAC_SPOTLIGHT,
};



#define DUAL_FUNC_0 LT(8, KC_H)
#define DUAL_FUNC_1 LT(8, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           RALT(KC_W),     
    KC_LEFT_SHIFT,  MT(MOD_LSFT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F),KC_G,                                           KC_H,           MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RCTL, KC_L),DUAL_FUNC_0,    DUAL_FUNC_1,    
    KC_LEFT_CTRL,   MT(MOD_LALT, KC_Z),MT(MOD_LGUI, KC_X),KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_QUES,        KC_RIGHT_ALT,   
                                                    LT(2, KC_TAB),  LT(1, KC_SPACE),                                LT(1, KC_ENTER),LT(2, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_NO,          
    KC_NO,          KC_GRAVE,       KC_LABK,        KC_RABK,        KC_MINUS,       KC_PIPE,                                        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_COLN,        KC_CIRC,        RALT(KC_5),     
    KC_NO,          KC_EXLM,        KC_ASTR,        KC_SLASH,       KC_EQUAL,       KC_AMPR,                                        KC_HASH,        KC_LPRN,        KC_RPRN,        KC_SCLN,        KC_DQUO,        KC_NO,          
    KC_NO,          KC_TILD,        KC_PLUS,        KC_BSLS,        KC_UNDS,        KC_PERC,                                        KC_AT,          KC_LBRC,        KC_RBRC,        RALT(KC_GRAVE), KC_QUOTE,       KC_NO,          
                                                    KC_TRANSPARENT, MAC_SPOTLIGHT,                                  MAC_SPOTLIGHT,  KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_F12,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          KC_NO,          
    MT(MOD_LSFT, KC_AUDIO_VOL_DOWN),MT(MOD_LSFT, KC_AUDIO_MUTE),MT(MOD_LCTL, KC_AUDIO_VOL_UP),MT(MOD_LALT, KC_MEDIA_PREV_TRACK),MT(MOD_LGUI, KC_MEDIA_PLAY_PAUSE),KC_MEDIA_NEXT_TRACK,                                KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_RIGHT_SHIFT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_LBRC),  KC_NO,          LGUI(KC_RBRC),  KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DELETE
  ),
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
    case MAC_SPOTLIGHT:
      HCS(0x221);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(RALT(KC_O));
        } else {
          unregister_code16(RALT(KC_O));
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
