// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _COLEMAK_DH 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _NAV 4
#define _NUM 5
#define _CONTROL 6

#define CTT_ESC CTL_T(KC_ESC) // escape when tapped, control when held
#define CTT_ENT CTL_T(KC_ENT) // space on tap, control when held
#define CTL_TAB LCTL(KC_TAB) // control + tab
#define CS_TAB C(S(KC_TAB)) //Control + Shift + Tab, for reopening tabs
#define CS_ESC C(S(KC_ESC)) //Control + Shift + Esc
#define CA_DEL C(A(KC_DEL)) //Control + Alt + Delete

#define LGT_ESC LGUI_T(KC_ESC) // escape when tapped, escape when held

#define ALT_TAB LALT(KC_TAB) // alt + tab

// Layer keypress definitions
#define LYR_NAV TG(_NAV)
#define LYR_LWR OSL(_LOWER)  // one-shot modifier
#define LYR_UPR OSL(_RAISE)  // one-shot modifier
#define LYR_NUM TG(_NUM)
#define LYR_CTL TG(_CONTROL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  NUM,
  NAVTG,
  CONTROL,
  RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTT_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LSFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_MEH,           KC_HYPR,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LGT_ESC, CTT_ENT, LYR_LWR,                   LYR_UPR, KC_SPC,  KC_TAB
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MEH,           KC_HYPR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LGT_ESC, CTT_ENT, LYR_LWR,                   LYR_UPR, KC_SPC,  KC_TAB
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ALT_TAB, KC_GRV,  KC_MINS, KC_BSLS, KC_EQL,  _______,                            KC_LPRN, KC_LCBR, KC_LBRC, KC_QUOT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   NUM,     OS_RSFT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ALT_TAB, KC_TILD, KC_UNDS, KC_PIPE, KC_PLUS, _______,                            KC_RPRN, KC_RCBR, KC_RBRC, KC_DQT,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, OS_LSFT, NAVTG,                     _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN2, KC_MS_UP,KC_BTN1, LYR_CTL,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  CTL_TAB,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CS_TAB, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,          _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, RESET,                     RESET,   _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_PDOT,                            KC_PMNS, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PPLS,                            KC_PEQL, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_PAST, KC_PSLS, _______, _______, _______,          _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, RESET,                     RESET,   _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_CONTROL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, QK_RBT,                             QK_BOOT, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QWERTY,  KC_WAKE, _______, KC_PWR,  _______,                            _______, _______, _______, _______, CS_ESC,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_SLEP, _______, _______,                            _______, _______, _______, _______, CA_DEL,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, COLEMAK, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, RESET,                     RESET,   _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

enum combos {
    WF_ESC,
    FP_BSP,
    PB_CTLBSP,
    TG_LMB,
    CD_TAB,
    DV_RMB,
    JL_CTLDEL,
    LU_DEL,
    UY_ESC,
    YSCLN_BSLSH,
    MN_LT,
    NE_CLN,
    EI_GT,
    KH_QUOTE,
    HCM_UNSCR,
    CMDOT_ALT
};

const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM yscln_combo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END}; //ne = colon
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END}; //ei = >
const uint16_t PROGMEM kh_combo[] = {KC_K, KC_H, COMBO_END}; //kh = '
const uint16_t PROGMEM hcm_combo[] = {KC_H, KC_COMM, COMBO_END}; //h, = _
const uint16_t PROGMEM cmdot_combo[] = {KC_COMM, KC_DOT, COMBO_END}; //h, = _
combo_t key_combos[] = {
    [WF_ESC] = COMBO(wf_combo, KC_ESC),
    [FP_BSP] = COMBO(fp_combo, KC_BSPC),
    [PB_CTLBSP] = COMBO(pb_combo, C(KC_BSPC)),
    [TG_LMB] = COMBO(tg_combo, KC_BTN1),
    [CD_TAB] = COMBO(cd_combo, KC_TAB),
    [DV_RMB] = COMBO(dv_combo, KC_BTN2),
    [JL_CTLDEL] = COMBO(jl_combo, C(KC_DEL)),
    [LU_DEL] = COMBO(lu_combo, KC_DEL),
    [UY_ESC] = COMBO(uy_combo, KC_ESC),
    [YSCLN_BSLSH] = COMBO(yscln_combo, KC_BSLS),
    [MN_LT] = COMBO(mn_combo, KC_LT),
    [NE_CLN] = COMBO(ne_combo, KC_COLON),
    [EI_GT] = COMBO(ei_combo, KC_GT),
    [KH_QUOTE] = COMBO(kh_combo, KC_QUOT),
    [HCM_UNSCR] = COMBO(hcm_combo, KC_UNDS),
    [CMDOT_ALT] = COMBO(cmdot_combo, KC_LALT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      }
      return false;
      break;
    case NAVTG:
      if (record->event.pressed) {
        layer_on(_NAV);
      }
      return false;
      break;
    case RESET:
      if (record->event.pressed) {
        layer_clear();
      }
      return false;
      break;
  }
  return true;
}
