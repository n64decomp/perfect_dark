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

#define NUM_DATA    2
#define NUM_SAMPLES 20
#define NUM_PADS    MAXCONTROLLERS

struct contsample {
	OSContPad pads[NUM_PADS];
};

struct joydata {
	struct contsample samples[NUM_SAMPLES];
	s32 curlast;
	s32 curstart;
	s32 nextlast;
	s32 nextsecondlast;
	u16 buttonspressed[NUM_PADS];
	u16 buttonsreleased[NUM_PADS];
	s32 unk200;
};

struct joydata g_JoyData[NUM_DATA];
s32 g_JoyDisableCooldown[NUM_PADS];
OSMesgQueue g_PiMesgQueue;
OSMesg g_PiMesgBuf[10];
OSMesg g_JoyStopCyclicPollingMesgBuf[1];
OSMesgQueue g_JoyStopCyclicPollingMesgQueue;
OSMesg g_JoyStopCyclicPollingDoneMesgBuf[1];
OSMesgQueue g_JoyStopCyclicPollingDoneMesgQueue;
OSMesg g_JoyStartCyclicPollingMesgBuf[1];
OSMesgQueue g_JoyStartCyclicPollingMesgQueue;
OSMesg g_JoyStartCyclicPollingDoneMesgBuf[1];
OSMesgQueue g_JoyStartCyclicPollingDoneMesgQueue;
OSContStatus g_JoyContStatuses[NUM_PADS];
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
u32 g_JoyBadReadsStickX[NUM_PADS] = {0};
u32 g_JoyBadReadsStickY[NUM_PADS] = {0};
u32 g_JoyBadReadsButtons[NUM_PADS] = {0};
u32 g_JoyBadReadsButtonsPressed[NUM_PADS] = {0};

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
bool g_JoyPfsPollMasterEnabled = true;
s32 g_JoyPfsPollInterval = 0;
s32 g_JoyPfsPollTimeRemaining = -1;
u32 g_JoyPfsPollCount = 0;
bool g_JoyPfsPollEnabled = false;
bool g_JoyCyclicPollingLocked = true;
#else
u32 var800612c8nb = 3;
u8 var800612ccnb = 0;
#endif

void joy00013e84(void);
s32 joy_get_pak_state2(s8 device);
void joys_tick_rumble(void);

#if VERSION >= VERSION_NTSC_1_0
void joy_lock_cyclic_polling(void)
{
	if (g_JoyCyclicPollingLocked) {
		joy_disable_cyclic_polling();
		g_JoyCyclicPollingLocked = false;
	}
}

void joy_unlock_cyclic_polling(void)
{
	if (!g_JoyCyclicPollingLocked) {
		joy_enable_cyclic_polling();
		g_JoyCyclicPollingLocked = true;
	}
}

void joy_set_pfs_poll_enabled(bool enabled)
{
	g_JoyPfsPollEnabled = enabled;
}

bool joy_is_pfs_poll_enabled(void)
{
	return g_JoyPfsPollEnabled;
}
#endif

void joy_set_pfs_poll_interval(s32 value)
{
#if VERSION >= VERSION_NTSC_1_0
	g_JoyPfsPollTimeRemaining = g_JoyPfsPollInterval = value * 11000;
#else
	g_JoyNextPfsStateIndex = value;
#endif
}

void joy_set_default_pfs_poll_interval(void)
{
	joy_set_pfs_poll_interval(VERSION >= VERSION_NTSC_1_0 ? 10 : 30);
}

/**
 * Remove an item from the beginning of the g_JoyPfsStates array,
 * shift the rest of the array back and return the removed item.
 */
s32 joy_shift_pfs_states(void)
{
#if VERSION >= VERSION_NTSC_1_0
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
#else
	return var8005eed8;
#endif
}

#if VERSION >= VERSION_NTSC_1_0
void joy_record_pfs_state(u8 pfsstate)
{
	if (g_JoyNextPfsStateIndex + 1 >= ARRAYCOUNT(g_JoyPfsStates)) {
		joy_shift_pfs_states();
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
 *
 * force 0 = poll based on the configured poll frequency and if not disabled
 * force 1 = poll based on the configured poll frequency even if disabled
 * force 2 = poll now
 */
void joy_poll_pfs(s32 force)
{
	static u32 thiscount = 0;
	static u32 prevcount = 0;
	static u32 doingit = false;
	u32 diffcount;
	u32 value;

	if (g_JoyPfsPollMasterEnabled
			&& (force == 2 || (g_JoyPfsPollInterval && (force || ((g_JoyCyclicPollDisableCount == 0 || !g_JoyCyclicPollingLocked) && g_JoyPfsPollEnabled))))
			&& !doingit) {
		doingit = true;
		prevcount = thiscount;
		thiscount = osGetCount();
		diffcount = (thiscount - prevcount) / 256;
		value = g_JoyPfsPollInterval * 2;

		if (diffcount > value) {
			diffcount = value;
		}

		g_JoyPfsPollTimeRemaining -= diffcount;

		if (g_JoyPfsPollTimeRemaining < 0
				|| force == 2
				|| (force == 1 && g_JoyPfsPollTimeRemaining < 0 && -g_JoyPfsPollTimeRemaining > g_JoyPfsPollInterval)) {
			u8 bitpattern = 0;

			g_JoyPfsPollCount++;

			if (force) {
				joy_disable_cyclic_polling();
			}

			osPfsIsPlug(&g_PiMesgQueue, &bitpattern);

			if (force) {
				joy_enable_cyclic_polling();
			}

			bitpattern |= 0x10; // eeprom

			joy_record_pfs_state(bitpattern);

			g_JoyPfsPollTimeRemaining = g_JoyPfsPollInterval;
		}

		doingit = false;
	}

#if VERSION < VERSION_PAL_BETA
	if (force);
#endif
}
#endif

/**
 * "Temporarily" because the next time joy_poll_pfs runs, the true state will be
 * recorded.
 *
 * Note that var8005eed8 is always zero, so this record will suggest that this
 * pak is the only one connected.
 */
void joy_set_pfs_temporarily_plugged(s8 index)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 bitpattern = var8005eed8 & ~(1 << index);

	joy_record_pfs_state(bitpattern);
#else
	var8005eed8 &= ~(1 << index);
#endif
}

void joy_init(void)
{
	s32 i;
	s32 j;

	osCreateMesgQueue(&g_JoyStopCyclicPollingMesgQueue, g_JoyStopCyclicPollingMesgBuf, ARRAYCOUNT(g_JoyStopCyclicPollingMesgBuf));
	osCreateMesgQueue(&g_JoyStopCyclicPollingDoneMesgQueue, g_JoyStopCyclicPollingDoneMesgBuf, ARRAYCOUNT(g_JoyStopCyclicPollingDoneMesgBuf));
	osCreateMesgQueue(&g_JoyStartCyclicPollingMesgQueue, g_JoyStartCyclicPollingMesgBuf, ARRAYCOUNT(g_JoyStartCyclicPollingMesgBuf));
	osCreateMesgQueue(&g_JoyStartCyclicPollingDoneMesgQueue, g_JoyStartCyclicPollingDoneMesgBuf, ARRAYCOUNT(g_JoyStartCyclicPollingDoneMesgBuf));
	osCreateMesgQueue(&g_PiMesgQueue, g_PiMesgBuf, ARRAYCOUNT(g_PiMesgBuf));

	osSetEventMesg(OS_EVENT_SI, &g_PiMesgQueue, NULL);

	g_JoyQueuesCreated = true;

	var8005eec4 = NULL;
	var8005eec8 = NULL;

	for (i = 0; i < NUM_DATA; i++) {
		g_JoyData[i].curlast = 0;
		g_JoyData[i].curstart = 0;
		g_JoyData[i].nextlast = 0;
		g_JoyData[i].nextsecondlast = 0;
		g_JoyData[i].unk200 = -1;

		for (j = 0; j < NUM_PADS; j++) {
			g_JoyData[i].samples[0].pads[j].button = 0;
			g_JoyData[i].samples[0].pads[j].stick_x = 0;
			g_JoyData[i].samples[0].pads[j].stick_y = 0;
			g_JoyData[i].samples[0].pads[j].errno = 0;
		}
	}

	for (i = 0; i < NUM_PADS; i++) {
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
void joy_disable_temporarily(void)
{
	s32 i;

	for (i = 0; i < NUM_PADS; i++) {
		g_JoyDisableCooldown[i] = TICKS(60);
	}
}

void joy_reset(void)
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
	static u8 prevconnected = 0xff;

	// osContInit should be called only once. The first time this function is
	// called it'll take the first branch here, and all subsequent calls will
	// take the second branch.
	if (g_JoyNeedsInit) {
		s32 i;
		g_JoyNeedsInit = false;
		osContInit(&g_PiMesgQueue, &g_JoyConnectedControllers, g_JoyContStatuses);
		g_JoyInitDone = true;

		for (i = 0; i < NUM_PADS; i++) {
			joy_stop_rumble(i, false);
		}
	} else {
		u32 slots = 0xf;
		s32 i;

		osContStartQuery(&g_PiMesgQueue);
		osRecvMesg(&g_PiMesgQueue, NULL, OS_MESG_BLOCK);
		osContGetQuery(g_JoyContStatuses);

		for (i = 0; i < ARRAYCOUNT(g_JoyContStatuses); i++) {
			if (g_JoyContStatuses[i].errno & CONT_NO_RESPONSE_ERROR) {
				slots -= 1 << i;
			}
		}

		g_JoyConnectedControllers = slots;
	}

	if (prevconnected != g_JoyConnectedControllers) {
		s32 i = 0;
		s32 index = 0;

		for (; i < NUM_PADS; i++) {
			if (g_JoyConnectedControllers & (1 << i)) {
				g_Vars.playertojoymap[index++] = i;
			}
		}

		prevconnected = g_JoyConnectedControllers;
	}
}

s8 cont_get_free_slot(void)
{
	s32 i;

	if (g_JoyDataPtr->unk200 >= 0) {
		return g_JoyDataPtr->unk200;
	}

	for (i = 0; i < NUM_PADS; i++) {
		if ((g_JoyConnectedControllers & (1 << i)) == 0) {
			return i;
		}
	}

	return NUM_PADS;
}

u32 joy_get_connected_controllers(void)
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

void joy_consume_samples(struct joydata *joydata)
{
	s8 i;
	s32 samplenum;
	u16 buttons1;
	u16 buttons2;

	joydata->curstart = joydata->curlast;
	joydata->curlast = joydata->nextlast;

	for (i = 0; i < NUM_PADS; i++) {
		joydata->buttonspressed[i] = 0;
		joydata->buttonsreleased[i] = 0;

		if (joydata->curlast != joydata->curstart) {
			samplenum = (joydata->curstart + 1) % NUM_SAMPLES; \
			while (true) {
				buttons1 = joydata->samples[samplenum].pads[i].button;
				buttons2 = joydata->samples[(samplenum + NUM_SAMPLES - 1) % NUM_SAMPLES].pads[i].button;

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

				samplenum = (samplenum + 1) % NUM_SAMPLES;
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

		for (i = 0; i < NUM_PADS; i++) {
			if (joy_get_pak_state2(i) == PAKSTATE_13) {
				pak_set_state(i, PAKSTATE_READY);
			}
		}

		if (var8005eec4 == NULL) {
			joys_tick_rumble();
		}

		doingit = false;
	}
}

void joy_debug_joy(void)
{
#if VERSION >= VERSION_NTSC_1_0
	static u32 var8005ef08 = 0;

	main_override_variable("debugjoy", &var8005ef08);
#else
	main_override_variable("joyforce", &var800612c8nb);
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.paksneededformenu) {
		joy_poll_pfs(1);
	}
#endif

	if (var8005eec4) {
		g_JoyData[1].nextlast = var8005eec4(g_JoyData[1].samples, g_JoyData[1].curlast);
		joy_consume_samples(&g_JoyData[1]);
	}

	joy_consume_samples(&g_JoyData[0]);

	if (var8005eec8) {
		var8005eec8(g_JoyData[0].samples, g_JoyData[0].curstart, g_JoyData[0].curlast);
	}

	if (joy_is_cyclic_polling_enabled() && var8005eec0 && joy_get_num_samples() <= 0) {
#if VERSION >= VERSION_NTSC_FINAL
		joy_disable_cyclic_polling();
		joy00014238();
		joy_enable_cyclic_polling();
		joy_consume_samples(&g_JoyData[0]);
#elif VERSION >= VERSION_NTSC_1_0
		joy_disable_cyclic_polling();
		joy_enable_cyclic_polling();
		joy_consume_samples(&g_JoyData[0]);
		joy00014238();
#else
		joy_disable_cyclic_polling(500, "joy.c");
		joy00014238();
		joy0001509cnb();
		joy_enable_cyclic_polling(507, "joy.c");
		joy_consume_samples(&g_JoyData[0]);
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

s32 joy_start_read_data(OSMesgQueue *mq)
{
	return osContStartReadData(mq);
}

void joy_read_data(void)
{
	s32 index = (g_JoyData[0].nextlast + 1) % NUM_SAMPLES;

	if (index == g_JoyData[0].curstart) {
		// If the sample queue is full, don't overwrite the oldest sample.
		// Instead, overwrite the most recent.
		index = g_JoyData[0].nextlast;
	}

	osContGetReadData(g_JoyData[0].samples[index].pads);

	g_JoyData[0].nextlast = index;
	g_JoyData[0].nextsecondlast = (g_JoyData[0].nextlast + NUM_SAMPLES - 1) % NUM_SAMPLES;
}

void joys_handle_retrace(void)
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
			joy_read_data();

			// Check if error state has changed for any controller
			for (i = 0; i < NUM_PADS; i++) {
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
		joy_poll_pfs(0);
#endif
		return;
	}

	if (osRecvMesg(&g_JoyStartCyclicPollingMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			joy_start_read_data(&g_PiMesgQueue);
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
			joy_poll_pfs(0);
			return;
		}
#endif

		if (osRecvMesg(&g_PiMesgQueue, &msg, OS_MESG_NOBLOCK) == 0) {
			static s32 count = 0;

			g_JoyBusy = false;
			joy_read_data();

			// Check if error state has changed for any controller
			for (i = 0; i < NUM_PADS; i++) {
				if ((g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno == 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno != 0)
						|| (g_JoyData[0].samples[g_JoyData[0].nextlast].pads[i].errno != 0 && g_JoyData[0].samples[g_JoyData[0].nextsecondlast].pads[i].errno == 0)) {
					joy00013e84();
					break;
				}
			}

			joy00014238();

#if VERSION >= VERSION_NTSC_1_0
			joy_poll_pfs(0);
#else
			joy0001509cnb();
#endif

			joy_start_read_data(&g_PiMesgQueue);
			g_JoyBusy = true;

			count++;

			if (count >= 60) {
				s32 i;

				for (i = 0; i < NUM_PADS; i++) {
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

s32 joy_get_num_samples(void)
{
	return (g_JoyDataPtr->curlast - g_JoyDataPtr->curstart + NUM_SAMPLES) % NUM_SAMPLES;
}

s32 joy_get_stick_x_on_sample(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickX[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % NUM_SAMPLES].pads[contpadnum].stick_x;
}

s32 joy_get_stick_y_on_sample(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickY[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % NUM_SAMPLES].pads[contpadnum].stick_y;
}

s32 joy_get_stick_y_on_sample_index(s32 samplenum, s8 contpadnum)
{
	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsStickY[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	return g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum) % NUM_SAMPLES].pads[contpadnum].stick_y;
}

u16 joy_get_buttons_on_sample(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button;

	if (g_JoyDataPtr->unk200 < 0 && (g_JoyConnectedControllers >> contpadnum & 1) == 0) {
		g_JoyBadReadsButtons[contpadnum]++;
		return 0;
	}

	if (g_JoyDisableCooldown[contpadnum] > 0) {
		return 0;
	}

	button = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % NUM_SAMPLES].pads[contpadnum].button;

	return button & mask;
}

u16 joy_get_buttons_pressed_on_sample(s32 samplenum, s8 contpadnum, u16 mask)
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

	button1 = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum + 1) % NUM_SAMPLES].pads[contpadnum].button;
	button2 = g_JoyDataPtr->samples[(g_JoyDataPtr->curstart + samplenum) % NUM_SAMPLES].pads[contpadnum].button;

	return (button1 & ~button2) & mask;
}

/**
 * Count the number of times the buttons specified by mask were held during the
 * specific samples given in checksamples.
 *
 * For example, if checksamples[5] is nonzero and a button was pressed on
 * samplenum 5 which matches the mask, count is incremented.
 */
s32 joy_count_buttons_on_specific_samples(u32 *checksamples, s8 contpadnum, u16 mask)
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

	i = (g_JoyDataPtr->curstart + 1) % NUM_SAMPLES;

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

		i = (i + 1) % NUM_SAMPLES;
		index++;
	}

	return count;
}

s8 joy_get_stick_x(s8 contpadnum)
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

s8 joy_get_stick_y(s8 contpadnum)
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

u16 joy_get_buttons(s8 contpadnum, u16 mask)
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

u16 joy_get_buttons_pressed_this_frame(s8 contpadnum, u16 mask)
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
u16 joy_get_buttons_released_this_frame(s8 contpadnum, u16 mask)
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

bool joy_is_cyclic_polling_enabled(void)
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
void joy_disable_cyclic_polling(
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
void joy_enable_cyclic_polling(
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
void joy_set_data_index(s32 arg0)
{
	g_JoyDataPtr = &g_JoyData[arg0];
}

s32 joy_get_data_index(void)
{
	return g_JoyDataPtr - g_JoyData;
}
#endif

void joy_destroy(void)
{
	s32 i;

	osCreateMesgQueue(&g_PiMesgQueue, g_PiMesgBuf, ARRAYCOUNT(g_PiMesgBuf));
	osSetEventMesg(OS_EVENT_SI, &g_PiMesgQueue, 0);

	for (i = 0; i < NUM_PADS; i++) {
		if (osMotorProbe(&g_PiMesgQueue, PFS(i), i) == 0) {
			osMotorStop(PFS(i));
			osMotorStop(PFS(i));
			osMotorStop(PFS(i));
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void joy_get_contpad_nums_for_player(s8 playernum, s32 *pad1, s32 *pad2)
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

void joy_stop_rumble(s8 arg0, bool disablepolling)
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
				joy_disable_cyclic_polling();
#else
				joy_disable_cyclic_polling(1054, "joy.c");
#endif
			}

			if (osMotorProbe(&g_PiMesgQueue, PFS(device), device) == 0) {
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
			}

			if (disablepolling) {
#if VERSION >= VERSION_NTSC_1_0
				joy_enable_cyclic_polling();
#else
				joy_enable_cyclic_polling(1066, "joy.c");
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

s32 joy_get_pak_state(s8 device)
{
	return g_Paks[device].state;
}

s32 joy_get_pak_state2(s8 device)
{
	return joy_get_pak_state(device);
}

void joys_tick_rumble(void)
{
	s32 i;

	for (i = 0; i < NUM_PADS; i++) {
		if (g_Paks[i].state == PAKSTATE_READY && g_Paks[i].type == PAKTYPE_RUMBLE) {
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
