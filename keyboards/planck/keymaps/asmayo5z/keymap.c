/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
  _NAV,
  _CONTROL
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  NUM,
  NAVTG,
  CONTROL,
  RESETLYR
};

#define _COLEMAK_DH 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _NAV 4
#define _NUM 5
#define _CONTROL 6

#define CTT_ESC CTL_T(KC_ESC) // escape when tapped, control when held
#define CTT_TAB CTL_T(KC_TAB) // tab when tapped, control when held
#define CTT_ENT CTL_T(KC_ENT) // space on tap, control when held
#define CTL_TAB LCTL(KC_TAB) // control + tab
#define CS_TAB C(S(KC_TAB)) //Control + Shift + Tab, for reopening tabs
#define CS_ESC C(S(KC_ESC)) //Control + Shift + Esc
#define CA_DEL C(A(KC_DEL)) //Control + Alt + Delete

#define LGT_ESC LGUI_T(KC_ESC) // escape when tapped, escape when held

#define ALT_TAB LALT(KC_TAB) // alt + tab

#define SHFT_T LSFT_T(KC_T) // T when tapped, left shift when held
#define SHFT_N RSFT_T(KC_N) // T when tapped, left shift when held

// Layer keypress definitions
#define LYR_NAV TG(_NAV)
#define LYR_LWR OSL(_LOWER)  // one-shot modifier
#define LYR_UPR OSL(_RAISE)  // one-shot modifier
#define LYR_NUM TG(_NUM)
#define LYR_CTL TG(_CONTROL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    XXXXXXX, XXXXXXX, LGT_ESC, CTT_ENT, LYR_LWR, KC_MEH,  KC_HYPR,  LYR_UPR, KC_SPC,  CTT_TAB, XXXXXXX, XXXXXXX
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |    Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   ;  |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |    A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |    Z  |   X  |   C  |   V  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      | GUI  |Enter |Lower | Meh  |Hyper |Raise |Space | Tab  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, XXXXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    SHFT_T,  KC_G,    XXXXXXX, XXXXXXX,  KC_M,    SHFT_N,  KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, XXXXXXX,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    XXXXXXX, XXXXXXX, LGT_ESC, CTT_ENT, LYR_LWR, KC_MEH,  KC_HYPR,  LYR_UPR, KC_SPC,  CTT_TAB, XXXXXXX, XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_LOWER] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_MINS, KC_BSLS, KC_EQL,  _______, _______, _______, _______, KC_LPRN, KC_LCBR, KC_LBRC, KC_QUOT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______, _______, _______, NUM,     _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,
    KC_TILD, KC_UNDS, KC_PIPE, KC_PLUS, _______, _______, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC, KC_DQT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, OS_LSFT, NAVTG,   _______, _______, _______, OS_LSFT, _______, _______, _______
),

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_PDOT, _______, _______, KC_PMNS, KC_7,    KC_8,    KC_9,    _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PPLS, _______, _______, KC_PEQL, KC_4,    KC_5,    KC_6,    _______,
    _______, KC_PAST, KC_PSLS, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______,
    _______, _______, RESETLYR,_______, RESETLYR,_______, _______, RESETLYR,_______, _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_NAV] = LAYOUT_planck_grid(
    _______, KC_BTN2, KC_MS_UP,KC_BTN1, LYR_CTL, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  CTL_TAB,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CS_TAB,
    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,
    _______, _______, RESETLYR,_______, RESETLYR,_______, _______, RESETLYR,_______, _______, _______, _______
),

/* Control
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CONTROL] = LAYOUT_planck_grid(
    _______, QWERTY,  KC_WAKE, _______, KC_PWR,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_SLEP, _______, _______, _______, _______, _______, _______, _______, CS_ESC,
    _______, _______, _______, COLEMAK, _______, _______, _______, _______, _______, _______, _______, CA_DEL,
    _______, _______, RESETLYR, _______,RESETLYR,_______, _______, RESETLYR,_______, _______, _______, _______
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
    EI_GT,
    KH_QUOTE,
    HCM_UNSCR,
    CMDOT_ALT,
    UE_CLN
};

const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM yscln_combo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
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
    [EI_GT] = COMBO(ei_combo, KC_GT),
    [KH_QUOTE] = COMBO(kh_combo, KC_QUOT),
    [HCM_UNSCR] = COMBO(hcm_combo, KC_UNDS),
    [CMDOT_ALT] = COMBO(cmdot_combo, KC_LALT),
    [UE_CLN] = COMBO(ue_combo, KC_COLON)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
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
    case RESETLYR:
      if (record->event.pressed) {
        layer_clear();
      }
      return false;
      break;
  }
  return true;
}
