#ifndef _IN_INPUT_H
#define _IN_INPUT_H

#include <PR/ultratypes.h>
#include <PR/os_cont.h>

#define INPUT_MAX_CONTROLLERS MAXCONTROLLERS
#define INPUT_RUMBLE_STRENGTH 0.333f

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

// 0 strength turns it off
void inputRumble(s32 idx, f32 strength, f32 time);

// call this every frame
void inputUpdate(void);

#endif
