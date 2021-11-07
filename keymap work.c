#include QMK_KEYBOARD_H

enum custom_keycodes {
    FULCRUM = SAFE_RANGE,
    ONEPUNCH, WELLSKY //list of macros
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case FULCRUM:
                SEND_STRING("TorobatL"SS_TAP(X_ENTER));
                return false;
                break;
            case ONEPUNCH:
                SEND_STRING("qywvof-nimfus-7pefHi"SS_TAP(X_ENTER));
                return false;
                break;
            case WELLSKY:
                SEND_STRING("WellSkyWelcomes50061"SS_TAP(X_ENTER));
                return false;
                break;

        }
    }
    return true;
};

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FULCRUM:
        if (record->event.pressed) {
            SEND_STRING("TorobatL"SS_TAP(X_ENTER));
        } else {
        }
        break;
        }
        return true;
};*/


//Layer 0 (chrome and discord)
  //Mute  Layer    Incognito      CloseTabs
  //Pass  NewTab   NewWindow    Reopen
  //Sleep Cancel   OneDarkMode    AllDarkMode
  //Quit  LFChat   DestinyChat    MuteDiscord
//Layer 1
  //CLOSE TAB       LAYER 0            PASSWORD      REOPEN TABS
  //NEW TAB         NEW WINDOW         TASK VIEW     COPY
  //SNAP L          SNAP R             DARK MODE     PASTE
  //UNDO            REDO               CTL BKSPC     MUTE
//Premiere
  //Mute    Layer       Export      CloseTabs
  //Pass    In          Text        Import
  //Sleep   Out         Razor       Selection
  //Quit    ClearInOut  Alt/Opt     Enter
//numberpad
  //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x4(
        LGUI(KC_W),     TG(1),            ONEPUNCH,        SGUI(KC_T),
        FULCRUM,        LGUI(KC_T),       LGUI(KC_N),      SGUI(KC_N),
        KC_SLEP,        RCS(KC_C),        LSA(KC_A),       LSA(KC_D),
        LGUI(KC_Q),     LCA(KC_C),        LCA(KC_G),       SGUI(KC_M)
  ),
[1] = LAYOUT_ortho_4x4(
        LCTL(KC_W),        TO(0),             WELLSKY,               RCS(KC_T),
        LCTL(KC_T),        LCTL(KC_N),        LWIN(KC_TAB),          LCTL(KC_C),
        LWIN(KC_LEFT),     LWIN(KC_RIGHT),    LSA(KC_A),             LCTL(KC_V),
        LCTL(KC_Z),        LCTL(KC_Y),        LCTL(KC_BSPACE),       RCS(KC_M)
  )
  /*[2] = LAYOUT_ortho_4x4(
        LGUI(KC_W),     TG(3),            LGUI(KC_M),      KC_MUTE,
        FULCRUM,        KC_I,             KC_T,            LGUI(KC_I),
        KC_SLEP,        KC_O,             KC_C,            KC_V,
        LGUI(KC_Q),     LOPT(KC_X),       KC_LOPT,         LOPT(KC_Y)
  ),
  [3] = LAYOUT_ortho_4x4(
        LGUI(KC_W),  TG(4),   TO(0),      KC_MUTE,
        KC_P7,       KC_P8,   KC_P9,      KC_PPLS,
        KC_P4,       KC_P5,   KC_P6,      KC_PMNS,
        KC_P1,       KC_P2,   KC_P3,      KC_P0
  ),
  [4] = LAYOUT_ortho_4x4(
        LGUI(KC_W),  TO(0),   KC_ENT,     LSFT(KC_SCLN),
        KC_P7,       KC_P8,   KC_P9,      KC_A,
        KC_P4,       KC_P5,   KC_P6,      KC_P,
        KC_P1,       KC_P2,   KC_P3,      KC_P0
  )*/
};

// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_GREEN);
}
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      if (clockwise) {
          tap_code16(C(KC_TAB));
      } else {
          tap_code16(C(S(KC_TAB)));
      }
      //second -encoder (E4)
    } else if (index == 3) {
      if (clockwise) {
          tap_code(KC__VOLUP);
      } else {
          tap_code(KC__VOLDOWN);
      }
    }
    return true;
}

/*if (index == 0) {
    if(IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            tap_code16(C(KC_TAB));
        } else {
            tap_code16(C(S(KC_TAB)));
        }
//if (layer_on(_LOWER)) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(C(S(KC_TAB)));
    }//
  //second -encoder (E4)
} else if (index == 3) {
  if (clockwise) {
      tap_code(KC__VOLUP);
  } else {
      tap_code(KC__VOLDOWN);
  }
}
return true;
} */
