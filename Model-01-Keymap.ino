
// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"
harry.mills@relayplatform.com
// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
//#include "Kaleidoscope-NumPad.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LED-Wavepool.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Heatmap showing which keys are used most
#include "Kaleidoscope-Heatmap.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for dual use keys - now provided by QuKeys
//#include "Kaleidoscope-DualUse.h"

// Support for topsy turvy keys (! when unshifted, 1 when shifted etc)
//#include "Kaleidoscope-TopsyTurvy.h"
// Kaleidoscope Qukeys
#include <Kaleidoscope-Qukeys.h>

    // Dual Use keys
    /* &DualUse */

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       MACRO_EMAIL,
       MACRO_LT,
       MACRO_LTE,
       MACRO_GTE,
       MACRO_GT,
       MACRO_EPIPE
     };

/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard DVORAK keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *77174 8498 RT0001
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *
  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like DVORAK, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

//enum { DVORAK, NUMPAD, FUNCTION }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

#define DVORAK_KM 0
#define NUMPAD_KM 1
#define FUNCTION_KM 2

#define DVORAK  KEYMAP (\
     Key_PrintScreen,     Key_1,           Key_2,            Key_3,      Key_4, Key_5, Key_LEDEffectNext,         M(MACRO_EMAIL), Key_6, Key_7, Key_8, Key_9, Key_0, Key_KeypadNumLock, \
     MT(RightAlt, Backtick), Key_Quote,Key_Comma,        Key_Period, Key_P, Key_Y, Key_Tab,                   Key_Enter,    Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash, \
     CTL_T(Escape),       Key_A,           Key_O,            Key_E,      Key_U, Key_I,                                          Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus, \
     Key_LeftShift,       Key_Semicolon,   Key_Q,            Key_J,      Key_K, Key_X, LSHIFT(Key_Semicolon),     Key_Delete,   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals, \
     SFT_T(Escape),       GUI_T(Spacebar), CTL_T(Backspace), LGUI(Key_Space),                                     LCTRL(Key_B), LT(FUNCTION_KM, Tab), LT(NUMPAD_KM, Enter), ALT_T(Slash), \
     LT(FUNCTION_KM, Spacebar),                                                                                   LT(NUMPAD_KM, Enter), \
)

#define NUMPAD  KEYMAP ( \
   ___, Key_F1,        Key_F2,        Key_F3,               Key_F4,                Key_F5,               ___,     M(MACRO_VERSION_INFO), Key_F6,        Key_F7, Key_F8, Key_F9, Key_F10,            Key_F11, \
   ___, LSHIFT(Key_1), LSHIFT(Key_2), Key_LeftCurlyBracket, Key_RightCurlyBracket, Key_Pipe,             ___,     ___,                   Key_Equals,    Key_7,  Key_8,  Key_9,  Key_KeypadMultiply, Key_F12, \
   ___, LSHIFT(Key_3), LSHIFT(Key_4), LSHIFT(Key_9),        LSHIFT(Key_0),         Key_Backtick,                  Key_Minus,             Key_4,  Key_5, Key_6,  Key_Backslash,      Key_Quote, \
   ___, LSHIFT(Key_5), LSHIFT(Key_6), Key_LeftBracket,      Key_RightBracket,      LSHIFT(Key_Backtick), ___,     ___,                   Key_KeypadDot, Key_1,  Key_2,  Key_3,  Key_Slash,          Key_Enter, \
   ___, ___, ___, ___,    ___, ___, ___, Key_0, \
   ___,                   ___, \
)

#define FUNCTION  KEYMAP ( \
   ___,      ___,              ___,          ___,          ___,           ___,            ___,    Consumer_ScanPreviousTrack, ___,                      ___,                        ___,                      ___,                    ___,          ___, \
   Key_Tab,  ___,              ___,          ___,          ___,           ___,            ___,    Consumer_PlaySlashPause,    Key_Equals,               Key_Home,                   Key_UpArrow,              Key_End,                Key_PageUp,   ___, \
   Key_Home, M(MACRO_LT),      M(MACRO_LTE), M(MACRO_GTE), M(MACRO_GT),   M(MACRO_EPIPE),                                Consumer_VolumeIncrement, Key_LeftArrow,              Key_DownArrow,            Key_RightArrow,         Key_PageDown, ___, \
   Key_End,  Key_PrintScreen,  Key_Insert,   ___,          ___,           ___,            ___,    Consumer_Mute,              Consumer_VolumeDecrement, Consumer_ScanPreviousTrack, Consumer_PlaySlashPause,  Consumer_ScanNextTrack, Key_Pipe,     ___, \
   ___, ___, ___, ___,    ___, ___, ___, ___, \
   ___,    ___ \
)

KEYMAPS(
  DVORAK,
  NUMPAD,
  FUNCTION
)

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
    case MACRO_VERSION_INFO:
      versionInfoMacro(keyState);
      break;

    case MACRO_EMAIL:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR("harry.porter-mills@relayplatform.com"));
      }
      break;

    case MACRO_LT:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR("<"));
      }
      break;

    case MACRO_LTE:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR("<="));
      }
      break;

    case MACRO_GTE:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR(">="));
      }
      break;

    case MACRO_GT:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR(">"));
      }
      break;

    case MACRO_EPIPE:
      if (keyToggledOn(keyState)) {
        return Macros.type(PSTR("|>"));
      }
      break;
  }

  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    LEDControl.disable();
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** Init plugins */
  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  KALEIDOSCOPE_INIT_PLUGINS(
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    BootGreetingEffect,

    // Quantum keys
    Qukeys,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    TestMode,

    // LEDControl provides support for other LED modes
    LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    LEDOff,

    // The rainbow effect changes the color of all of the keyboard's keys at the same time
    // running through all the colors of the rainbow.
    LEDRainbowEffect,

    // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
    // and slowly moves the rainbow across your keyboard
    LEDRainbowWaveEffect,

    // Show a heatmap of how much the keys are used
    HeatmapEffect,

    // The chase effect follows the adventure of a blue pixel which chases a red pixel across
    // your keyboard. Spoiler: the blue pixel never catches the red pixel
    //LEDChaseEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    /* solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet, */

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    LEDBreatheEffect,

    // The AlphaSquare effect prints each character you type, using your
    // keyboard's LEDs as a display
    //AlphaSquareEffect,

    // The stalker effect lights up the keys you've pressed recently
    StalkerEffect,
    WavepoolEffect,

    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    //oqNumPad,

    // The macros plugin adds support for macros
    Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    MouseKeys,

    // The HostPowerManagement plugin enables waking up the host from suspend,
    // and allows us to turn LEDs off when it goes to sleep.
    HostPowerManagement
  );

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();


  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  //NumPad.numPadLayer = NUMPAD_KM;

  // We configure the AlphaSquare effect to use RED letters
  //AlphaSquare.color = { 255, 0, 0 };

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  //HeatmapEffect.heat_colors = heat_colors;
  HeatmapEffect.heat_colors_length = 4;

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  /* StalkerEffect.variant = STALKER(BlazingTrail); */
  StalkerEffect.variant = STALKER(Haunt);
  WavepoolEffect.idle_timeout = 5000;  // 5 seconds
  WavepoolEffect.activate();

  // We want the keyboard to be able to wake the host up from suspend.
  HostPowerManagement.enableWakeup();

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // Set the time we need to hold a dual use key to switch the toggle version
  // on (in milliseconds)
  Qukeys.setHoldTimeout(150);
  Qukeys.setOverlapThreshold(40);
  Qukeys.setMinimumHoldTime(30);
  Qukeys.setMinimumPriorInterval(40);
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
