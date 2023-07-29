#include <SDL.h>
#include <PR/ultratypes.h>
#include <PR/os_thread.h>
#include <PR/os_cont.h>
#include "input.h"

static SDL_GameController *pads[INPUT_MAX_CONTROLLERS];
static SDL_Haptic *haptics[INPUT_MAX_CONTROLLERS];

static const u16 buttonMap[] = {
	/* SDL_CONTROLLER_BUTTON_A             */ A_BUTTON,
	/* SDL_CONTROLLER_BUTTON_B             */ B_BUTTON,
	/* SDL_CONTROLLER_BUTTON_X             */ Z_TRIG,
	/* SDL_CONTROLLER_BUTTON_Y             */ Z_TRIG,
	/* SDL_CONTROLLER_BUTTON_BACK          */ START_BUTTON,
	/* SDL_CONTROLLER_BUTTON_GUIDE         */ 0,
	/* SDL_CONTROLLER_BUTTON_START         */ START_BUTTON,
	/* SDL_CONTROLLER_BUTTON_LEFTSTICK     */ 0,
	/* SDL_CONTROLLER_BUTTON_RIGHTSTICK    */ 0,
	/* SDL_CONTROLLER_BUTTON_LEFTSHOULDER  */ L_TRIG,
	/* SDL_CONTROLLER_BUTTON_RIGHTSHOULDER */ R_TRIG,
	/* SDL_CONTROLLER_BUTTON_DPAD_UP       */ U_JPAD,
	/* SDL_CONTROLLER_BUTTON_DPAD_DOWN     */ D_JPAD,
	/* SDL_CONTROLLER_BUTTON_DPAD_LEFT     */ L_JPAD,
	/* SDL_CONTROLLER_BUTTON_DPAD_RIGHT    */ R_JPAD,
};

static const u16 buttonTrigLeft = Z_TRIG;
static const u16 buttonTrigRight = Z_TRIG;

static s32 connectedMask = 0;

s32 inputInit(void)
{
	if (!SDL_WasInit(SDL_INIT_GAMECONTROLLER)) {
		if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) != 0) {
			return -1;
		}
	}

	const s32 numJoys = SDL_NumJoysticks();

	s32 ret = 0;
	for (s32 jidx = 0, cidx = 0; jidx < numJoys && cidx < INPUT_MAX_CONTROLLERS; ++jidx) {
		if (SDL_IsGameController(jidx)) {
			pads[cidx] = SDL_GameControllerOpen(jidx);
			if (pads[cidx]) {
				SDL_Haptic *hap = SDL_HapticOpen(jidx);
				if (hap) {
					if (SDL_HapticRumbleSupported(hap) && (SDL_HapticRumbleInit(hap) == 0)) {
						haptics[cidx] = hap;
					} else {
						SDL_HapticClose(hap);
					}
				}
				ret |= 1 << cidx;
				++cidx;
			}
		}
	}

	connectedMask = ret;

	return ret;
}

s32 inputReadController(s32 idx, OSContPad *npad)
{
	if (idx < 0 || idx >= INPUT_MAX_CONTROLLERS || !pads[idx] || !npad) {
		return -1;
	}

	const s16 leftX = SDL_GameControllerGetAxis(pads[idx], SDL_CONTROLLER_AXIS_LEFTX);
	const s16 leftY = SDL_GameControllerGetAxis(pads[idx], SDL_CONTROLLER_AXIS_LEFTY);
	const s16 rightX = SDL_GameControllerGetAxis(pads[idx], SDL_CONTROLLER_AXIS_RIGHTX);
	const s16 rightY = SDL_GameControllerGetAxis(pads[idx], SDL_CONTROLLER_AXIS_RIGHTY);

	npad->button = 0;

	if (rightX < -0x4000) npad->button |= L_CBUTTONS;
	if (rightX > +0x4000) npad->button |= R_CBUTTONS;
	if (rightY < -0x4000) npad->button |= U_CBUTTONS;
	if (rightY > +0x4000) npad->button |= D_CBUTTONS;

	for (size_t i = 0; i < sizeof(buttonMap) / sizeof(*buttonMap); ++i) {
		if (buttonMap[i]) {
			if (SDL_GameControllerGetButton(pads[idx], i)) {
				npad->button |= buttonMap[i];
			}
		}
	}

	const s32 stickY = -leftY / 0x100;
	npad->stick_x = leftX / 0x100;
	npad->stick_y = (stickY == 128) ? 127 : stickY;

	return 0;
}

void inputUpdate(void)
{
	SDL_GameControllerUpdate();
	// TODO: handle controller changes
}

s32 inputControllerConnected(s32 idx)
{
	if (idx < 0 || idx >= INPUT_MAX_CONTROLLERS) {
		return 0;
	}
	return !!pads[idx];
}

s32 inputRumbleSupported(s32 idx)
{
	if (idx < 0 || idx >= INPUT_MAX_CONTROLLERS) {
		return 0;
	}
	return !!haptics[idx];
}

void inputRumble(s32 idx, f32 strength, f32 time)
{
	if (idx < 0 || idx >= INPUT_MAX_CONTROLLERS || !haptics[idx]) {
		return;
	}
	if (strength <= 0.f) {
		SDL_HapticRumbleStop(haptics[idx]);
	} else {
		SDL_HapticRumblePlay(haptics[idx], strength, (u32)(time * 1000.f));
	}
}

s32 inputControllerMask(void)
{
	return connectedMask;
}
