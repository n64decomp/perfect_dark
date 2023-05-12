#include <ultra64.h>
#include "constants.h"
#include "game/pak.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

/**
 * PD polls the controllers from the scheduler's thread. The scheduler polls the
 * controllers on each retrace and stores the results inside g_JoyData->samples.
 * This allows the main thread to access a history of controller states since
 * the last rendered frame. For example, under laggy conditions the player might
 * press and release a button between two frames and the main thread can tell
 * that this has happened even if the button was unpressed during both the
 * previous and current frame.
 *
 * The samples array contains 20 elements and is written to in a cyclic manner.
 * These samples are split into two partitions: cur and next. cur refers to
 * samples which are currently visible to the main thread on this frame, and
 * samples in next are samples which have been added since the start of the
 * current frame and will be made visible on the next frame.
 *
 * At the start of a frame, the main thread informs the joy system that it's
 * ready to consume more samples. The joy system then moves the partition
 * boundaries so that the old next partition becomes the new cur, and everything
 * else becomes available for next.
 *
 * If all 20 samples are in use, the joy system will overwrite the most recent
 * sample in the next partition.
 */

struct joydata g_JoyData;
s32 g_JoyDisableCooldown[4];
OSMesgQueue g_PiMesgQueue;
OSMesg var80099e90[10];
OSMesg var80099eb8[2];
OSMesgQueue g_JoyStopCyclicPollingMesgQueue;
OSMesg var80099ed8[2];
OSMesgQueue g_JoyStopCyclicPollingDoneMesgQueue;
OSMesg var80099ef8[2];
OSMesgQueue g_JoyStartCyclicPollingMesgQueue;
OSMesg var80099f18[2];
OSMesgQueue g_JoyStartCyclicPollingDoneMesgQueue;
OSContStatus var80099f38[4];
u8 g_JoyPfsStates[100];

bool g_JoyBusy = false;
u32 var8005ee68 = 0;

u8 g_JoyConnectedControllers = 0;
bool g_JoyQueuesCreated = false;
bool g_JoyInitDone = false;
bool g_JoyNeedsInit = true;
u32 g_JoyCyclicPollDisableCount = 0;
s32 g_JoyNextPfsStateIndex = 0;

bool var8005eedc = true;
s32 var8005eee0 = 0;
s32 var8005eee4 = -1;
u32 var8005eeec = 0;
u32 var8005eef0 = 1;

static void joy00013e84(void);
static void joysTickRumble(void);

void joy00013900(void)
{
	if (var8005eef0) {
		joyDisableCyclicPolling();
		var8005eef0 = false;
	}
}

void joy00013938(void)
{
	if (!var8005eef0) {
		joyEnableCyclicPolling();
		var8005eef0 = true;
	}
}

void joy00013974(u32 value)
{
	var8005eeec = value;
}

u32 joy00013980(void)
{
	return var8005eeec;
}

/**
 * Note: Some of the variables in this file are misnamed in NTSC beta.
 * @TODO: Untangle these.
 */
void joy0001398c(s32 value)
{
	var8005eee4 = var8005eee0 = value * 11000;
}

void joy000139c8(void)
{
	joy0001398c(10);
}

/**
 * Remove an item from the beginning of the g_JoyPfsStates array,
 * shift the rest of the array back and return the removed item.
 */
s32 joyShiftPfsStates(void)
{
	s32 pfsstate = 0;
	s32 i;

	if (g_JoyNextPfsStateIndex) {
		pfsstate = g_JoyPfsStates[0];

		if (g_JoyNextPfsStateIndex > 1) {
			for (i = 0; i < g_JoyNextPfsStateIndex; i++) {
				g_JoyPfsStates[i] = g_JoyPfsStates[i + 1];
			}

			g_JoyNextPfsStateIndex--;
		}
	}

	return pfsstate;
}

void joyRecordPfsState(u8 pfsstate)
{
	if (g_JoyNextPfsStateIndex + 1 >= 100) {
		joyShiftPfsStates();
	}

	if (g_JoyNextPfsStateIndex == 0 || pfsstate != g_JoyPfsStates[g_JoyNextPfsStateIndex - 1]) {
		g_JoyPfsStates[g_JoyNextPfsStateIndex] = pfsstate;
		g_JoyNextPfsStateIndex++;
	}
}

/**
 * Scan controllers for controller paks, but only under certain conditions.
 * Seems to be timer based, or can be forced by passing 2 as arg0.
 */
void joyCheckPfs(s32 arg0)
{
	static u32 thiscount = 0; // 8005eef4
	static u32 prevcount = 0; // 8005eef8
	static u32 doingit = false; // 8005eefc
	u32 diffcount;
	u32 value;

	if (var8005eedc
			&& (arg0 == 2 || (var8005eee0 && (arg0 || ((g_JoyCyclicPollDisableCount == 0 || var8005eef0 == 0) && var8005eeec))))
			&& !doingit) {
		doingit = true;
		prevcount = thiscount;
		thiscount = osGetCount();
		diffcount = (thiscount - prevcount) / 256;
		value = var8005eee0 * 2;

		if (diffcount > value) {
			diffcount = value;
		}

		var8005eee4 -= diffcount;

		if (var8005eee4 < 0
				|| arg0 == 2
				|| (arg0 == 1 && var8005eee4 < 0 && var8005eee0 < -var8005eee4)) {
			u8 bitpattern = 0;

			if (arg0) {
				joyDisableCyclicPolling();
			}

			osPfsIsPlug(&g_PiMesgQueue, &bitpattern);

			if (arg0) {
				joyEnableCyclicPolling();
			}

			bitpattern |= 0x10;

			joyRecordPfsState(bitpattern);

			var8005eee4 = var8005eee0;
		}

		doingit = false;
	}
}

void joyInit(void)
{
	s32 i;
	s32 j;

	osCreateMesgQueue(&g_JoyStopCyclicPollingMesgQueue, var80099eb8, 1);
	osCreateMesgQueue(&g_JoyStopCyclicPollingDoneMesgQueue, var80099ed8, 1);
	osCreateMesgQueue(&g_JoyStartCyclicPollingMesgQueue, var80099ef8, 1);
	osCreateMesgQueue(&g_JoyStartCyclicPollingDoneMesgQueue, var80099f18, 1);
	osCreateMesgQueue(&g_PiMesgQueue, var80099e90, ARRAYCOUNT(var80099e90));

	osSetEventMesg(OS_EVENT_SI, &g_PiMesgQueue, NULL);

	g_JoyQueuesCreated = true;

	g_JoyData.curlast = 0;
	g_JoyData.curstart = 0;
	g_JoyData.nextlast = 0;
	g_JoyData.nextsecondlast = 0;
	g_JoyData.unk200 = -1;

	for (j = 0; j < 4; j++) {
		g_JoyData.samples[0].pads[j].button = 0;
		g_JoyData.samples[0].pads[j].stick_x = 0;
		g_JoyData.samples[0].pads[j].stick_y = 0;
		g_JoyData.samples[0].pads[j].errno = 0;
	}

	for (i = 0; i < 4; i++) {
		g_JoyDisableCooldown[i] = 0;
	}
}

/**
 * Disable all input on all controllers for 60 frames, or until the player has
 * released all inputs.
 *
 * It's used to prevent the player from accidentally skipping cutscenes and
 * progressing past endscreens if they are holding buttons when they are
 * started.
 */
void joyDisableTemporarily(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_JoyDisableCooldown[i] = TICKS(60);
	}
}

void joyReset(void)
{
	OSMesg msg;

	if (g_JoyQueuesCreated) {
		osSendMesg(&g_JoyStopCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&g_JoyStopCyclicPollingDoneMesgQueue, &msg, OS_MESG_BLOCK);

		joy00013e84();

		osSendMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&g_JoyStartCyclicPollingDoneMesgQueue, &msg, OS_MESG_BLOCK);
	}
}

static void joy00013e84(void)
{
	static u8 var8005ef00 = 0xff;

	// osContInit should be called only once. The first time this function is
	// called it'll take the first branch here, and all subsequent calls will
	// take the second branch.
	if (g_JoyNeedsInit) {
		s32 i;
		g_JoyNeedsInit = false;
		osContInit(&g_PiMesgQueue, &g_JoyConnectedControllers, var80099f38);
		g_JoyInitDone = true;

		for (i = 0; i < 4; i++) {
			joyStopRumble(i, false);
		}
	} else {
		u32 slots = 0xf;
		s32 i;

		osContStartQuery(&g_PiMesgQueue);
		osRecvMesg(&g_PiMesgQueue, NULL, OS_MESG_BLOCK);
		osContGetQuery(var80099f38);

		for (i = 0; i < 4; i++) {
			if (var80099f38[i].errno & CONT_NO_RESPONSE_ERROR) {
				slots -= 1 << i;
			}
		}

		g_JoyConnectedControllers = slots;
	}

	if (var8005ef00 != g_JoyConnectedControllers) {
		s32 i = 0;
		s32 index = 0;

		for (; i < 4; i++) {
			if (g_JoyConnectedControllers & (1 << i)) {
				g_Vars.playertojoymap[index++] = i;
			}
		}

		var8005ef00 = g_JoyConnectedControllers;
	}
}

u32 joyGetConnectedControllers(void)
{
	return g_JoyConnectedControllers;
}

/**
 * The use of the static variable suggests that the function is able to be
 * called recursively, but its behaviour should not be run when recursing.
 */
static void joy00014238(void)
{
	static bool doingit = false;
	s32 i;

	if (!doingit) {
		doingit = true;

		for (i = 0; i < 4; i++) {
			if (joy000155b4(i) == PAK010_13) {
				pakSetUnk010(i, PAK010_11);
			}
		}

		joysTickRumble();

		doingit = false;
	}
}

void joyDebugJoy(void)
{
	s8 i;
	s32 samplenum;
	u16 buttons1;
	u16 buttons2;

	if (g_Vars.paksconnected) {
		joyCheckPfs(1);
	}

	g_JoyData.curstart = g_JoyData.curlast;
	g_JoyData.curlast = g_JoyData.nextlast;

	for (i = 0; i < 4; i++) {
		g_JoyData.buttonspressed[i] = 0;
		g_JoyData.buttonsreleased[i] = 0;

		if (g_JoyData.curlast != g_JoyData.curstart) {
			samplenum = g_JoyData.curstart + 1;

			if (samplenum >= 20) {
				samplenum = 0;
			}

			while (true) {
				s32 prev = samplenum - 1;

				if (prev < 0) {
					prev = 19;
				}

				buttons1 = g_JoyData.samples[samplenum].pads[i].button;
				buttons2 = g_JoyData.samples[prev].pads[i].button;

				g_JoyData.buttonspressed[i] |= buttons1 & ~buttons2;
				g_JoyData.buttonsreleased[i] |= ~buttons1 & buttons2;

				if (g_JoyDisableCooldown[i] > 0) {
					if (g_JoyData.samples[samplenum].pads[i].button == 0
							&& g_JoyData.samples[samplenum].pads[i].stick_x < 15
							&& g_JoyData.samples[samplenum].pads[i].stick_x > -15
							&& g_JoyData.samples[samplenum].pads[i].stick_y < 15
							&& g_JoyData.samples[samplenum].pads[i].stick_y > -15) {
						g_JoyDisableCooldown[i] = 0;
					} else {
						g_JoyDisableCooldown[i]--;
					}
				}

				if (samplenum == g_JoyData.curlast) {
					break;
				}

				samplenum++;

				if (samplenum >= 20) {
					samplenum = 0;
				}
			}
		}
	}
}

static void joyReadData(void)
{
	s32 index = g_JoyData.nextlast + 1;

	if (index >= 20) {
		index = 0;
	}

	if (index == g_JoyData.curstart) {
		// If the sample queue is full, don't overwrite the oldest sample.
		// Instead, overwrite the most recent.
		index = g_JoyData.nextlast;
	}

	osContGetReadData(g_JoyData.samples[index].pads);

	g_JoyData.nextlast = index;
	g_JoyData.nextsecondlast = g_JoyData.nextlast + 19;

	if (g_JoyData.nextsecondlast >= 20) {
		g_JoyData.nextsecondlast -= 20;
	}
}

void joysTick(void)
{
	OSMesg msg;
	s8 i;

	if (osRecvMesg(&g_JoyStopCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
		if (g_JoyBusy) {
			osRecvMesg(&g_PiMesgQueue, &msg, OS_MESG_BLOCK);

			g_JoyBusy = false;
			joyReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((g_JoyData.samples[g_JoyData.nextlast].pads[i].errno == 0 && g_JoyData.samples[g_JoyData.nextsecondlast].pads[i].errno != 0)
						|| (g_JoyData.samples[g_JoyData.nextlast].pads[i].errno != 0 && g_JoyData.samples[g_JoyData.nextsecondlast].pads[i].errno == 0)) {
					joy00013e84();
					break;
				}
			}
		}

		osSendMesg(&g_JoyStopCyclicPollingDoneMesgQueue, &msg, OS_MESG_NOBLOCK);

		var8005ee68++;

		joyCheckPfs(0);
		return;
	}

	if (osRecvMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			osContStartReadData(&g_PiMesgQueue);
			g_JoyBusy = true;
		}

		osSendMesg(&g_JoyStartCyclicPollingDoneMesgQueue, &msg, OS_MESG_NOBLOCK);
		return;
	}

	if (g_JoyInitDone) {
		if (var8005ee68) {
			joyCheckPfs(0);
			return;
		}

		if (osRecvMesg(&g_PiMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
			g_JoyBusy = false;
			joyReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((g_JoyData.samples[g_JoyData.nextlast].pads[i].errno == 0 && g_JoyData.samples[g_JoyData.nextsecondlast].pads[i].errno != 0)
						|| (g_JoyData.samples[g_JoyData.nextlast].pads[i].errno != 0 && g_JoyData.samples[g_JoyData.nextsecondlast].pads[i].errno == 0)) {
					joy00013e84();
					break;
				}
			}

			joy00014238();

			joyCheckPfs(0);

			osContStartReadData(&g_PiMesgQueue);
			g_JoyBusy = true;
		}
	}
}

s32 joyGetNumSamples(void)
{
	s32 tmp = g_JoyData.curlast - g_JoyData.curstart + 20;

	if (tmp >= 20) {
		tmp -= 20;
	}

	return tmp;
}

s32 joyGetStickXOnSample(s32 samplenum, s8 contpadnum)
{
	s32 tmp;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	tmp = g_JoyData.curstart + samplenum + 1;

	if (tmp >= 20) {
		tmp -= 20;
	}

	return g_JoyData.samples[tmp].pads[contpadnum].stick_x;
}

s32 joyGetStickYOnSample(s32 samplenum, s8 contpadnum)
{
	s32 tmp;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	tmp = g_JoyData.curstart + samplenum + 1;

	if (tmp >= 20) {
		tmp -= 20;
	}

	return g_JoyData.samples[tmp].pads[contpadnum].stick_y;
}

s32 joyGetStickYOnSampleIndex(s32 samplenum, s8 contpadnum)
{
	s32 tmp;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	tmp = g_JoyData.curstart + samplenum;

	if (tmp >= 20) {
		tmp -= 20;
	}

	return g_JoyData.samples[tmp].pads[contpadnum].stick_y;
}

u16 joyGetButtonsOnSample(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button;
	s32 tmp;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	tmp = g_JoyData.curstart + samplenum + 1;

	if (tmp >= 20) {
		tmp -= 20;
	}

	button = g_JoyData.samples[tmp].pads[contpadnum].button;

	return button & mask;
}

u16 joyGetButtonsPressedOnSample(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button1;
	u16 button2;
	s32 tmp;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	tmp = g_JoyData.curstart + samplenum + 1;

	if (tmp >= 20) {
		tmp -= 20;
	}

	button1 = g_JoyData.samples[tmp].pads[contpadnum].button;

	tmp = g_JoyData.curstart + samplenum;

	if (tmp >= 20) {
		tmp -= 20;
	}

	button2 = g_JoyData.samples[tmp].pads[contpadnum].button;

	return (button1 & ~button2) & mask;
}

/**
 * Count the number of times the buttons specified by mask were held during the
 * specific samples given in checksamples.
 *
 * For example, if checksamples[5] is nonzero and a button was pressed on
 * samplenum 5 which matches the mask, count is incremented.
 */
s32 joyCountButtonsOnSpecificSamples(u32 *checksamples, s8 contpadnum, u16 mask)
{
	s32 count = 0;
	s32 index = 0;
	s32 i;
	u16 button;

	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	i = g_JoyData.curstart + 1;

	if (i >= 20) {
		i -= 20;
	}

	while (true) {
		if (checksamples == NULL || checksamples[index]) {
			button = g_JoyData.samples[i].pads[contpadnum].button;

			if (button & mask) {
				count++;
			}
		}

		if (i == g_JoyData.curlast) {
			break;
		}

		i++;

		if (i >= 20) {
			i -= 20;
		}

		index++;
	}

	return count;
}

s8 joyGetStickX(s8 contpadnum)
{
	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyData.samples[g_JoyData.curlast].pads[contpadnum].stick_x;
}

s8 joyGetStickY(s8 contpadnum)
{
	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyData.samples[g_JoyData.curlast].pads[contpadnum].stick_y;
}

u16 joyGetButtons(s8 contpadnum, u16 mask)
{
	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyData.samples[g_JoyData.curlast].pads[contpadnum].button & mask;
}

u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask)
{
	if (g_JoyData.unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyData.buttonspressed[contpadnum] & mask;
}

/**
 * If cyclic polling is enabled, send a message to the scheduler thread telling
 * it to update the joy state (connected controllers, PFS etc). Then block while
 * waiting for its done message to come back, and increment the disable count.
 *
 * If cyclic polling was already disabled, simply increase the disable count.
 */
void joyDisableCyclicPolling(void)
{
	OSMesg msg;

	if (g_JoyCyclicPollDisableCount == 0) {
		osSendMesg(&g_JoyStopCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&g_JoyStopCyclicPollingDoneMesgQueue, &msg, OS_MESG_BLOCK);
	}

	g_JoyCyclicPollDisableCount++;
}

/**
 * Indicate that the caller is done with cyclic polling being disabled,
 * and enable cyclic polling if there are no callers left who want it disabled.
 */
void joyEnableCyclicPolling(void)
{
	OSMesg msg;

	g_JoyCyclicPollDisableCount--;

	if (g_JoyCyclicPollDisableCount == 0) {
		osSendMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&g_JoyStartCyclicPollingDoneMesgQueue, &msg, OS_MESG_BLOCK);
	}
}

void joyDestroy(void)
{
	s32 i;

	osCreateMesgQueue(&g_PiMesgQueue, var80099e90, ARRAYCOUNT(var80099e90));
	osSetEventMesg(OS_EVENT_SI, &g_PiMesgQueue, 0);

	for (i = 0; i < 4; i++) {
		if (osMotorProbe(&g_PiMesgQueue, PFS(i), i) == 0) {
			osMotorStop(PFS(i));
			osMotorStop(PFS(i));
			osMotorStop(PFS(i));
		}
	}
}

void joyGetContpadNumsForPlayer(s8 playernum, s32 *pad1, s32 *pad2)
{
	if (g_Vars.normmplayerisrunning) {
		*pad1 = g_Vars.playerstats[playernum].mpindex;
		*pad2 = -1;
		return;
	}

	*pad1 = playernum;

	if (g_PlayerConfigsArray[g_Vars.playerstats[playernum].mpindex].controlmode >= CONTROLMODE_21) {
		*pad2 = PLAYERCOUNT() + playernum;
		return;
	}

	*pad2 = -1;
}

void joyStopRumble(s8 arg0, bool disablepolling)
{
	if (arg0 != SAVEDEVICE_GAMEPAK) {
		s32 device = arg0;

		if (g_Paks[device].type != PAKTYPE_MEMORY && g_Paks[device].type != PAKTYPE_GAMEBOY) {
			if (disablepolling) {
				joyDisableCyclicPolling();
			}

			if (osMotorProbe(&g_PiMesgQueue, PFS(device), device) == 0) {
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
			}

			if (disablepolling) {
				joyEnableCyclicPolling();
			}

			if (g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPING
					&& g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPED) {
				g_Paks[device].rumblestate = RUMBLESTATE_ENABLED_STOPPING;
			}

			g_Paks[device].rumblettl = -1;
		}
	}
}

s32 joy000155b4(s8 device)
{
	return g_Paks[device].unk010;
}

static void joysTickRumble(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Paks[i].unk010 == PAK010_11 && g_Paks[i].type == PAKTYPE_RUMBLE) {
			switch (g_Paks[i].rumblestate) {
			case RUMBLESTATE_ENABLED_STARTING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_RUMBLING;
				osMotorStart(PFS(i));
				break;
			case RUMBLESTATE_ENABLED_RUMBLING:
				if (g_Paks[i].rumblepulsestopat != -1) {
					if (g_Paks[i].rumblepulsetimer == 0) {
						osMotorStart(PFS(i));
					} else if (g_Paks[i].rumblepulsestopat == g_Paks[i].rumblepulsetimer) {
						osMotorStop(PFS(i));
					}

					g_Paks[i].rumblepulsetimer++;

					if (g_Paks[i].rumblepulselen == g_Paks[i].rumblepulsetimer) {
						g_Paks[i].rumblepulsetimer = 0;
					}
				}

				g_Paks[i].rumblettl--;

				if (g_Paks[i].rumblettl < 0) {
					g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPING;
				}
				break;
			case RUMBLESTATE_ENABLED_STOPPING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPED;
				osMotorStop(PFS(i));
				break;
			case RUMBLESTATE_DISABLED_STOPPING:
				osMotorStop(PFS(i));
				g_Paks[i].rumblestate = RUMBLESTATE_DISABLED_STOPPED;
				break;
			case RUMBLESTATE_ENABLING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPED;
				g_Paks[i].rumblettl = -1;
				break;
			}
		}
	}
}
