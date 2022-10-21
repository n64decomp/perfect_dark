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

struct joydata g_JoyData[2];
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
#if VERSION >= VERSION_NTSC_1_0
u8 g_JoyPfsStates[100];
u32 var80099fac;
u32 var80099fb0;
#endif

const char var70054080[] = "joyReset\n";
const char var7005408c[] = "joyReset: doing nothing\n";

struct joydata *g_JoyDataPtr = &g_JoyData[0];
bool g_JoyBusy = false;
u32 var8005ee68 = 0;

// Number of times per pad that different inputs were attempted to be read
// when controller was disconnected or not ready.
u32 g_JoyBadReadsStickX[4] = {0};
u32 g_JoyBadReadsStickY[4] = {0};
u32 g_JoyBadReadsButtons[4] = {0};
u32 g_JoyBadReadsButtonsPressed[4] = {0};

u8 g_JoyConnectedControllers = 0;
bool g_JoyQueuesCreated = false;
bool g_JoyInitDone = false;
bool g_JoyNeedsInit = true;
u32 g_JoyCyclicPollDisableCount = 0;
u32 var8005eec0 = 1;
s32 (*var8005eec4)(struct contsample *samples, s32 samplenum) = NULL;
void (*var8005eec8)(struct contsample *samples, s32 samplenum, s32 samplenum2) = NULL;
s32 g_JoyNextPfsStateIndex = (VERSION >= VERSION_NTSC_1_0 ? 0 : 30);
s32 var8005eed0 = 0;

#if VERSION >= VERSION_NTSC_1_0
u32 var8005eed4 = 0;
#endif

u8 var8005eed8 = 0;

#if VERSION >= VERSION_NTSC_1_0
bool var8005eedc = true;
s32 var8005eee0 = 0;
s32 var8005eee4 = -1;
u32 var8005eee8 = 0;
u32 var8005eeec = 0;
u32 var8005eef0 = 1;
#else
u32 var800612c8nb = 3;
u8 var800612ccnb = 0;
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

#if VERSION >= VERSION_NTSC_1_0
u32 joy00013980(void)
{
	return var8005eeec;
}
#endif

/**
 * Note: Some of the variables in this file are misnamed in NTSC beta.
 * @TODO: Untangle these.
 */
void joy0001398c(s32 value)
{
#if VERSION >= VERSION_NTSC_1_0
	var8005eee4 = var8005eee0 = value * 11000;
#else
	g_JoyNextPfsStateIndex = value;
#endif
}

void joy000139c8(void)
{
	joy0001398c(VERSION >= VERSION_NTSC_1_0 ? 10 : 30);
}

#if VERSION < VERSION_NTSC_1_0
// Same function as the one a couple above, just relocated
u32 joy00013980(void)
{
#if VERSION >= VERSION_NTSC_1_0
	return var8005eeec;
#else
	return var8005eed8;
#endif
}
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

#if VERSION >= VERSION_NTSC_1_0
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

			var8005eee8++;

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

#if VERSION < VERSION_PAL_BETA
	if (arg0) {
		// empty
	}
#endif
}
#endif

/**
 * "Temporarily" because the next time joyCheckPfs runs, the true state will be
 * recorded.
 *
 * Note that var8005eed8 is always zero, so this record will suggest that this
 * pak is the only one connected.
 */
void joySetPfsTemporarilyPlugged(s8 index)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 bitpattern = var8005eed8 & ~(1 << index);

	joyRecordPfsState(bitpattern);
#else
	var8005eed8 &= ~(1 << index);
#endif
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

	var8005eec4 = NULL;
	var8005eec8 = NULL;

	for (i = 0; i < 2; i++) {
		g_JoyData[i].curlast = 0;
		g_JoyData[i].curstart = 0;
		g_JoyData[i].nextlast = 0;
		g_JoyData[i].nextsecondlast = 0;
		g_JoyData[i].unk200 = -1;

		for (j = 0; j < 4; j++) {
			g_JoyData[i].samples[0].pads[j].button = 0;
			g_JoyData[i].samples[0].pads[j].stick_x = 0;
			g_JoyData[i].samples[0].pads[j].stick_y = 0;
			g_JoyData[i].samples[0].pads[j].errno = 0;
		}
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

		var8005eec0 = 1;
	}
}

void joy00013e84(void)
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

s8 contGetFreeSlot(void)
{
	s32 i;

	if (g_JoyDataPtr->unk200 >= 0) {
		return g_JoyDataPtr->unk200;
	}

	for (i = 0; i < 4; i++) {
		if ((g_JoyConnectedControllers & (1 << i)) == 0) {
			return i;
		}
	}

	return 4;
}

u32 joyGetConnectedControllers(void)
{
	return g_JoyConnectedControllers;
}

#if VERSION < VERSION_NTSC_1_0
void func00014e9cnb(void *callback, s32 value2)
{
	var8005eec4 = callback;
	g_JoyData[1].unk200 =  value2;
}
#endif

#if VERSION < VERSION_NTSC_1_0
void func00014eb0nb(void *value)
{
	var8005eec8 = value;
}
#endif

void joyConsumeSamples(struct joydata *joydata)
{
	s8 i;
	s32 samplenum;
	u16 buttons1;
	u16 buttons2;

	joydata->curstart = joydata->curlast;
	joydata->curlast = joydata->nextlast;

	for (i = 0; i < 4; i++) {
		joydata->buttonspressed[i] = 0;
		joydata->buttonsreleased[i] = 0;

		if (joydata->curlast != joydata->curstart) {
			samplenum = (joydata->curstart + 1) % 20; while (true) {
				buttons1 = joydata->samples[samplenum].pads[i].button;
				buttons2 = joydata->samples[(samplenum + 19) % 20].pads[i].button;

				joydata->buttonspressed[i] |= buttons1 & ~buttons2;
				joydata->buttonsreleased[i] |= ~buttons1 & buttons2;

				if (g_JoyDisableCooldown[i] > 0) {
					if (joydata->samples[samplenum].pads[i].button == 0
							&& joydata->samples[samplenum].pads[i].stick_x < 15
							&& joydata->samples[samplenum].pads[i].stick_x > -15
							&& joydata->samples[samplenum].pads[i].stick_y < 15
							&& joydata->samples[samplenum].pads[i].stick_y > -15) {
						g_JoyDisableCooldown[i] = 0;
					} else {
						g_JoyDisableCooldown[i]--;
					}
				}

				if (samplenum == joydata->curlast) {
					break;
				}

				samplenum = (samplenum + 1) % 20;
			}
		}
	}
}

#if VERSION < VERSION_NTSC_1_0
void joy0001509cnb(void)
{
	static bool doingit = false;

	if (!doingit) {
		doingit = true;

		if (g_JoyNextPfsStateIndex < var8005eed0) {
			var8005eed0 = 0;
			joy00013e84();
			osPfsIsPlug(&g_PiMesgQueue, &var8005eed8);
			var8005eed8 |= 0x10;
		}

		doingit = false;
	}
}
#endif

/**
 * The use of the static variable suggests that the function is able to be
 * called recursively, but its behaviour should not be run when recursing.
 */
void joy00014238(void)
{
	static bool doingit = false;
	s32 i;

	if (!doingit) {
		doingit = true;

		for (i = 0; i < 4; i++) {
			if (joy000155f4(i) == PAK010_13) {
				pakSetUnk010(i, PAK010_11);
			}
		}

		if (var8005eec4 == NULL) {
			joysTickRumble();
		}

		doingit = false;
	}
}

void joyDebugJoy(void)
{
#if VERSION >= VERSION_NTSC_1_0
	static u32 var8005ef08 = 0;

	mainOverrideVariable("debugjoy", &var8005ef08);
#else
	mainOverrideVariable("joyforce", &var800612c8nb);
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.paksconnected) {
		joyCheckPfs(1);
	}
#endif

	if (var8005eec4) {
		g_JoyData[1].nextlast = var8005eec4(g_JoyData[1].samples, g_JoyData[1].curlast);
		joyConsumeSamples(&g_JoyData[1]);
	}

	joyConsumeSamples(&g_JoyData[0]);

	if (var8005eec8) {
		var8005eec8(g_JoyData[0].samples, g_JoyData[0].curstart, g_JoyData[0].curlast);
	}

	if (joyIsCyclicPollingEnabled() && var8005eec0 && joyGetNumSamples() <= 0) {
#if VERSION >= VERSION_NTSC_FINAL
		joyDisableCyclicPolling();
		joy00014238();
		joyEnableCyclicPolling();
		joyConsumeSamples(&g_JoyData[0]);
#elif VERSION >= VERSION_NTSC_1_0
		joyDisableCyclicPolling();
		joyEnableCyclicPolling();
		joyConsumeSamples(&g_JoyData[0]);
		joy00014238();
#else
		joyDisableCyclicPolling(500, "joy.c");
		joy00014238();
		joy0001509cnb();
		joyEnableCyclicPolling(507, "joy.c");
		joyConsumeSamples(&g_JoyData[0]);
#endif
	}
}

#if VERSION >= VERSION_NTSC_1_0
const char var700540b4[] = "JOY : g_EnableCyclicPolling=%d";
const char var700540d4[] = "JOY : g_JoyReCheckInterval=%d";
const char var700540f4[] = "JOY : g_JoyReCheckEventIn=%d";
const char var70054114[] = "JOY : g_JoyRecheckDone=%d";
#endif

const char var70054130[] = "osContStartReadData -> Failed - CONT_NO_RESPONSE_ERROR\n";
const char var70054168[] = "osContStartReadData -> Failed - CONT_OVERRUN_ERROR\n";
const char var7005419c[] = "joyTickRetrace:joy%derrno%d->%d\n";
const char var700541c0[] = "joyTickRetrace:joy%derrno%d->%d\n";

s32 joyStartReadData(OSMesgQueue *mq)
{
	return osContStartReadData(mq);
}

void joyReadData(void)
{
	s32 index = (g_JoyData[0].nextlast + 1) % 20;

	if (index == g_JoyData[0].curstart) {
		// If the sample queue is full, don't overwrite the oldest sample.
		// Instead, overwrite the most recent.
		index = g_JoyData[0].nextlast;
	}

	osContGetReadData(g_JoyData[0].samples[index].pads);

	g_JoyData[0].nextlast = index;
	g_JoyData[0].nextsecondlast = (g_JoyData[0].nextlast + 19) % 20;
}

void joysTick(void)
{
	OSMesg msg;
	s8 i;

#if VERSION < VERSION_NTSC_1_0
	var8005eed0++;
#endif

	if (osRecvMesg(&g_JoyStopCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
		if (g_JoyBusy) {
			osRecvMesg(&g_PiMesgQueue, &msg, OS_MESG_BLOCK);

			g_JoyBusy = false;
			joyReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno == 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno != 0)
						|| (g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno != 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno == 0)) {
					joy00013e84();
					break;
				}
			}
		}

		osSendMesg(&g_JoyStopCyclicPollingDoneMesgQueue, &msg, OS_MESG_NOBLOCK);

		var8005ee68++;

#if VERSION >= VERSION_NTSC_1_0
		joyCheckPfs(0);
#endif
		return;
	}

	if (osRecvMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			joyStartReadData(&g_PiMesgQueue);
			g_JoyBusy = true;
		}

		osSendMesg(&g_JoyStartCyclicPollingDoneMesgQueue, &msg, OS_MESG_NOBLOCK);
		return;
	}

#if VERSION < VERSION_NTSC_1_0
	if (var8005ee68) {
		return;
	}
#endif

	if (g_JoyInitDone) {
#if VERSION >= VERSION_NTSC_1_0
		if (var8005ee68) {
			joyCheckPfs(0);
			return;
		}
#endif

		if (osRecvMesg(&g_PiMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
			static s32 count = 0;

			g_JoyBusy = false;
			joyReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno == 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno != 0)
						|| (g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno != 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno == 0)) {
					joy00013e84();
					break;
				}
			}

			joy00014238();

#if VERSION >= VERSION_NTSC_1_0
			joyCheckPfs(0);
#else
			joy0001509cnb();
#endif

			joyStartReadData(&g_PiMesgQueue);
			g_JoyBusy = true;

			count++;

			if (count >= 60) {
				s32 i;

				for (i = 0; i < 4; i++) {
					if (g_JoyBadReadsStickX[i] || g_JoyBadReadsStickY[i] || g_JoyBadReadsButtons[i] || g_JoyBadReadsButtonsPressed[i]) {
						g_JoyBadReadsStickX[i] = 0;
						g_JoyBadReadsStickY[i] = 0;
						g_JoyBadReadsButtons[i] = 0;
						g_JoyBadReadsButtonsPressed[i] = 0;
					}
				}

				count = 0;
			}
		}
	}
}

void joy00014810(bool value)
{
	var8005eec0 = value;
}

s32 joyGetNumSamples(void)
{
	return (g_JoyDataPtr->curlast - g_JoyDataPtr->curstart + 20) % 20;
}

s32 joyGetStickXOnSample(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickX[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % 20].pads[contpadnum].stick_x;
}

s32 joyGetStickYOnSample(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickY[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % 20].pads[contpadnum].stick_y;
}

s32 joyGetStickYOnSampleIndex(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickY[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum) % 20].pads[contpadnum].stick_y;
}

u16 joyGetButtonsOnSample(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button;

	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtons[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	button = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % 20].pads[contpadnum].button;

	return button & mask;
}

u16 joyGetButtonsPressedOnSample(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button1;
	u16 button2;

	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtonsPressed[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	button1 = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % 20].pads[contpadnum].button;
	button2 = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum) % 20].pads[contpadnum].button;

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

	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtons[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	i = (g_JoyDataPtr->curstart + 1) % 20;

	while (true) {
		if (checksamples == NULL || checksamples[index]) {
			button = g_JoyDataPtr->samples[i].pads[contpadnum].button;

			if (button & mask) {
				count++;
			}
		}

		if (i == g_JoyDataPtr->curlast) {
			break;
		}

		i = (i + 1) % 20;
		index++;
	}

	return count;
}

s8 joyGetStickX(s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickX[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[g_JoyDataPtr->curlast].pads[contpadnum].stick_x;
}

s8 joyGetStickY(s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickY[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[g_JoyDataPtr->curlast].pads[contpadnum].stick_y;
}

u16 joyGetButtons(s8 contpadnum, u16 mask)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtons[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[g_JoyDataPtr->curlast].pads[contpadnum].button & mask;
}

u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtonsPressed[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->buttonspressed[contpadnum] & mask;
}

#if VERSION < VERSION_NTSC_1_0
u16 joyGetButtonsReleasedThisFrame(s8 contpadnum, u16 mask)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtonsPressed[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->buttonsreleased[contpadnum] & mask;
}
#endif

bool joyIsCyclicPollingEnabled(void)
{
	return g_JoyCyclicPollDisableCount ? false : true;
}

/**
 * If cyclic polling is enabled, send a message to the scheduler thread telling
 * it to update the joy state (connected controllers, PFS etc). Then block while
 * waiting for its done message to come back, and increment the disable count.
 *
 * If cyclic polling was already disabled, simply increase the disable count.
 */
void joyDisableCyclicPolling(
#if VERSION >= VERSION_NTSC_1_0
		void
#else
		s32 line, char *file
#endif
		)
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
void joyEnableCyclicPolling(
#if VERSION >= VERSION_NTSC_1_0
		void
#else
		s32 line, char *file
#endif
		)
{
	OSMesg msg;

	g_JoyCyclicPollDisableCount--;

	if (g_JoyCyclicPollDisableCount == 0) {
		osSendMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&g_JoyStartCyclicPollingDoneMesgQueue, &msg, OS_MESG_BLOCK);
	}
}

#if VERSION < VERSION_NTSC_1_0
void joySetDataIndex(s32 arg0)
{
	g_JoyDataPtr = &g_JoyData[arg0];
}

s32 joyGetDataIndex(void)
{
	return g_JoyDataPtr - g_JoyData;
}
#endif

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

#if VERSION >= VERSION_NTSC_1_0
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
#endif

void joyStopRumble(s8 arg0, bool disablepolling)
{
	if (arg0 != SAVEDEVICE_GAMEPAK) {
#if VERSION >= VERSION_NTSC_1_0
		s32 device = arg0;
#else
		s32 device = g_Vars.playertojoymap[arg0];
#endif

		if (g_Paks[device].type != PAKTYPE_MEMORY && g_Paks[device].type != PAKTYPE_GAMEBOY) {
			if (disablepolling) {
#if VERSION >= VERSION_NTSC_1_0
				joyDisableCyclicPolling();
#else
				joyDisableCyclicPolling(1054, "joy.c");
#endif
			}

			if (osMotorProbe(&g_PiMesgQueue, PFS(device), device) == 0) {
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
			}

			if (disablepolling) {
#if VERSION >= VERSION_NTSC_1_0
				joyEnableCyclicPolling();
#else
				joyEnableCyclicPolling(1066, "joy.c");
#endif
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

s32 joy000155f4(s8 device)
{
	return joy000155b4(device);
}

void joysTickRumble(void)
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
