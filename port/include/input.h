#ifndef _IN_INPUT_H
#define _IN_INPUT_H

#include <PR/ultratypes.h>
#include <PR/os_cont.h>

#define INPUT_MAX_CONTROLLERS MAXCONTROLLERS
#define INPUT_MAX_CONTROLLER_BUTTONS 32

#define CONT_STICK_XNEG 0x10000
#define CONT_STICK_XPOS 0x20000
#define CONT_STICK_YNEG 0x40000
#define CONT_STICK_YPOS 0x80000

#define CONT_NUM_BUTTONS 16 // not including the stick axes

enum virtkey {
  /* same order as SDL scancodes */
  VK_KEYBOARD_BEGIN = 0,
  VK_RETURN = 40,
  VK_ESCAPE = 41,

  /* same order as SDL mouse buttons */
  VK_MOUSE_BEGIN = 512,
  VK_MOUSE_LEFT = VK_MOUSE_BEGIN,
  VK_MOUSE_MIDDLE,
  VK_MOUSE_RIGHT,
  VK_MOUSE_X1,
  VK_MOUSE_X2,
  VK_MOUSE_WHEEL_UP,
  VK_MOUSE_WHEEL_DN,

  /* same order as SDL gamecontroller buttons plus two buttons for triggers */
  VK_JOY_BEGIN,
  VK_JOY1_BEGIN = VK_JOY_BEGIN,
  VK_JOY1_LTRIG = VK_JOY1_BEGIN + 30,
  VK_JOY1_RTRIG = VK_JOY1_BEGIN + 31,
  VK_JOY2_BEGIN = VK_JOY1_BEGIN + INPUT_MAX_CONTROLLER_BUTTONS,
  VK_JOY3_BEGIN = VK_JOY2_BEGIN + INPUT_MAX_CONTROLLER_BUTTONS,
  VK_JOY4_BEGIN = VK_JOY3_BEGIN + INPUT_MAX_CONTROLLER_BUTTONS,

  VK_TOTAL_COUNT = VK_JOY_BEGIN + INPUT_MAX_CONTROLLERS * INPUT_MAX_CONTROLLER_BUTTONS,
};

enum contkey {
  CK_C_R,
  CK_C_L,
  CK_C_D,
  CK_C_U,
  CK_RTRIG,
  CK_LTRIG,
  CK_X, // gap in CONT_
  CK_Y, // gap in CONT_
  CK_DPAD_R,
  CK_DPAD_L,
  CK_DPAD_D,
  CK_DPAD_U,
  CK_START,
  CK_ZTRIG,
  CK_B,
  CK_A,
  CK_STICK_XNEG,
  CK_STICK_XPOS,
  CK_STICK_YNEG,
  CK_STICK_YPOS,
  CK_TOTAL_COUNT
};

// returns bitmask of connected controllers or -1 if failed
s32 inputInit(void);

// returns 0 if read, non-0 if failed
s32 inputReadController(s32 idx, OSContPad *npad);

// returns 1 if rumble is supported for specified controller
s32 inputRumbleSupported(s32 idx);

// returns 1 if specified controller is connected
s32 inputControllerConnected(s32 idx);

// returns bitmask of connected controllers
s32 inputControllerMask(void);

// vk is a value from the virtkey enum above
s32 inputKeyPressed(u32 vk);

// idx is controller index, contbtn is one of the CONT_ constants
s32 inputButtonPressed(s32 idx, u16 contbtn);

// bind virtkey vk to n64 pad #idx's button/axis ck as represented by its contkey value
// if bind is -1, picks a bind slot automatically
void inputKeyBind(s32 idx, u32 ck, s32 bind, u32 vk);

// strength is 0 .. 1; 0 strength turns it off
void inputRumble(s32 idx, f32 strength, f32 time);

// locks the mouse cursor in the window and makes it invisible if argument is true
void inputLockMouse(s32 lock);

// returns the current state of the above
s32 inputMouseIsLocked(void);

// returns mouse position in native viewport coordinates (ie, 320x240 most of the time)
void inputMouseGetPosition(s32 *x, s32 *y);

// returns changes in mouse position since last frame, in window coordinates
void inputMouseGetRawDelta(s32 *dx, s32 *dy);

// returns changes in mouse position since last frame, scaled by sensitivity
// returns 0, 0 when the mouse is not locked into the window
void inputMouseGetScaledDelta(f32 *dx, f32 *dy);

// call this every frame
void inputUpdate(void);

#endif
