#include <ultra64.h>
#include "constants.h"
#include "game/pak/pak.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

/**
 * PD uses use a separate thread (than the main game) for controller polling.
 * This thread polls the controllers as frequently as possible and stores its
 * results inside g_JoyData->samples. This allows the main thread to access a
 * history of controller states since the last rendered frame. For example,
 * under laggy conditions the player might press and release a button between
 * two frames and the main thread can tell that this has happened even if the
 * button was unpressed during both the previous and current frame.
 *
 * The samples array contains 20 elements and is written to in a cyclic manner.
 * These samples are split into two partitions: cur and next. cur refers to
 * samples which are currently visible to the main thread on this frame, and
 * samples in next are samples which have been added since the start of the
 * current frame and will be made visible on the next frame.
 *
 * At the start of a frame, the main thread informs the cont system that it's
 * ready to consume more samples. The cont system then moves the partition
 * boundaries so that the old next partition becomes the new cur, and everything
 * else becomes available for next.
 *
 * If all 20 samples are in use, the cont system will overwrite the most recent
 * sample in the next partition.
 */

struct joydata g_JoyData[2];
s32 g_JoyDisableCooldown[4];
OSMesgQueue var80099e78;
OSMesg var80099e90;
u32 var80099e94;
u32 var80099e98;
u32 var80099e9c;
u32 var80099ea0;
u32 var80099ea4;
u32 var80099ea8;
u32 var80099eac;
u32 var80099eb0;
u32 var80099eb4;
OSMesg var80099eb8;
u32 var80099ebc;
OSMesgQueue var80099ec0;
OSMesg var80099ed8;
u32 var80099edc;
OSMesgQueue var80099ee0;
OSMesg var80099ef8;
u32 var80099efc;
OSMesgQueue var80099f00;
OSMesg var80099f18;
u32 var80099f1c;
OSMesgQueue var80099f20;
OSContStatus var80099f38[4];
u8 g_JoyPfsStates[100];
u32 var80099fac;
u32 var80099fb0;

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
u32 var8005eebc = 0;
u32 var8005eec0 = 1;
s32 (*var8005eec4)(struct contsample *samples, s32 samplenum) = NULL;
void (*var8005eec8)(struct contsample *samples, s32 samplenum, s32 samplenum2) = NULL;
s32 g_JoyNextPfsStateIndex = 0;
u32 var8005eed0 = 0;
u32 var8005eed4 = 0;
u8 var8005eed8 = 0;
u32 var8005eedc = 1;
s32 var8005eee0 = 0;
s32 var8005eee4 = -1;
u32 var8005eee8 = 0;
u32 var8005eeec = 0;
u32 var8005eef0 = 1;

#if VERSION >= VERSION_NTSC_1_0
void joy00013900(void)
{
	if (var8005eef0) {
		joy000150e8();
		var8005eef0 = false;
	}
}

void joy00013938(void)
{
	if (!var8005eef0) {
		joy00015144();
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

#if VERSION >= VERSION_NTSC_1_0
void joy0001398c(s32 value)
{
	var8005eee4 = var8005eee0 = value * 11000;
}
#else
GLOBAL_ASM(
glabel joy0001398c
/*    14a70:	3c018006 */ 	lui	$at,0x8006
/*    14a74:	03e00008 */ 	jr	$ra
/*    14a78:	ac2412bc */ 	sw	$a0,0x12bc($at)
);
#endif

void joy000139c8(void)
{
#if VERSION >= VERSION_NTSC_1_0
	joy0001398c(10);
#else
	joy0001398c(30);
#endif
}

#if VERSION < VERSION_NTSC_1_0
// Same function as the one a couple above, just relocated
u32 joy00013980(void)
{
#if VERSION >= VERSION_NTSC_1_0
	return var8005eeec;
#else
	return *(u8 *)&var8005eeec;
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
			&& (arg0 == 2 || (var8005eee0 && (arg0 || ((var8005eebc == 0 || var8005eef0 == 0) && var8005eeec))))
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
				joy000150e8();
			}

			osPfsIsPlug(&var80099e78, &bitpattern);

			if (arg0) {
				joy00015144();
			}

			bitpattern |= 0x10;

			joyRecordPfsState(bitpattern);

			var8005eee4 = var8005eee0;
		}

		doingit = false;
	}

#if !PAL
	if (arg0) {
		// empty
	}
#endif
}
#endif

#if VERSION >= VERSION_NTSC_1_0
/**
 * "Temporarily" because the next time joyCheckPfs runs, the true state will be
 * recorded.
 *
 * Note that var8005eed8 is always zero, so this record will suggest that this
 * pak is the only one connected.
 */
void joySetPfsTemporarilyPlugged(s8 index)
{
	u8 bitpattern = var8005eed8 & ~(1 << index);

	joyRecordPfsState(bitpattern);
}
#else
GLOBAL_ASM(
glabel joySetPfsTemporarilyPlugged
/*    14aa8:	3c028006 */ 	lui	$v0,0x8006
/*    14aac:	244212c4 */ 	addiu	$v0,$v0,0x12c4
/*    14ab0:	00047600 */ 	sll	$t6,$a0,0x18
/*    14ab4:	90580000 */ 	lbu	$t8,0x0($v0)
/*    14ab8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14abc:	24190001 */ 	addiu	$t9,$zero,0x1
/*    14ac0:	01f94004 */ 	sllv	$t0,$t9,$t7
/*    14ac4:	01004827 */ 	nor	$t1,$t0,$zero
/*    14ac8:	03095024 */ 	and	$t2,$t8,$t1
/*    14acc:	afa40000 */ 	sw	$a0,0x0($sp)
/*    14ad0:	03e00008 */ 	jr	$ra
/*    14ad4:	a04a0000 */ 	sb	$t2,0x0($v0)
);
#endif

void joySystemInit(void)
{
	s32 i;
	s32 j;

	osCreateMesgQueue(&var80099ec0, &var80099eb8, 1);
	osCreateMesgQueue(&var80099ee0, &var80099ed8, 1);
	osCreateMesgQueue(&var80099f00, &var80099ef8, 1);
	osCreateMesgQueue(&var80099f20, &var80099f18, 1);
	osCreateMesgQueue(&var80099e78, &var80099e90, 10);

	osSetEventMesg(OS_EVENT_SI, &var80099e78, NULL);

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
		g_JoyDisableCooldown[i] = PALDOWN(60);
	}
}

void joy00013dfc(void)
{
	OSMesg msg;

	if (g_JoyQueuesCreated) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);

		joy00013e84();

		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);

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
		osContInit(&var80099e78, &g_JoyConnectedControllers, var80099f38);
		g_JoyInitDone = true;

		for (i = 0; i < 4; i++) {
			joy000153c4(i, 0);
		}
	} else {
		u32 slots = 0xf;
		s32 i;

		osContStartQuery(&var80099e78);
		osRecvMesg(&var80099e78, NULL, OS_MESG_BLOCK);
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
GLOBAL_ASM(
glabel func00014e9cnb
/*    14e9c:	3c018006 */ 	lui	$at,0x8006
/*    14ea0:	ac2412b4 */ 	sw	$a0,0x12b4($at)
/*    14ea4:	3c01800a */ 	lui	$at,0x800a
/*    14ea8:	03e00008 */ 	jr	$ra
/*    14eac:	ac25e5c4 */ 	sw	$a1,-0x1a3c($at)
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00014eb0nb
/*    14eb0:	3c018006 */ 	lui	$at,0x8006
/*    14eb4:	03e00008 */ 	jr	$ra
/*    14eb8:	ac2412b8 */ 	sw	$a0,0x12b8($at)
);
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
GLOBAL_ASM(
glabel func0001509cnb
/*    1509c:	3c0e8006 */ 	lui	$t6,0x8006
/*    150a0:	8dce12d4 */ 	lw	$t6,0x12d4($t6)
/*    150a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    150a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    150ac:	15c00019 */ 	bnez	$t6,.NB00015114
/*    150b0:	3c028006 */ 	lui	$v0,0x8006
/*    150b4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    150b8:	3c018006 */ 	lui	$at,0x8006
/*    150bc:	244212c0 */ 	addiu	$v0,$v0,0x12c0
/*    150c0:	ac2f12d4 */ 	sw	$t7,0x12d4($at)
/*    150c4:	3c188006 */ 	lui	$t8,0x8006
/*    150c8:	8f1812bc */ 	lw	$t8,0x12bc($t8)
/*    150cc:	8c590000 */ 	lw	$t9,0x0($v0)
/*    150d0:	0319082a */ 	slt	$at,$t8,$t9
/*    150d4:	1020000d */ 	beqz	$at,.NB0001510c
/*    150d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    150dc:	0c005332 */ 	jal	joy00013e84
/*    150e0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    150e4:	3c04800a */ 	lui	$a0,0x800a
/*    150e8:	3c058006 */ 	lui	$a1,0x8006
/*    150ec:	24a512c4 */ 	addiu	$a1,$a1,0x12c4
/*    150f0:	0c014228 */ 	jal	osPfsIsPlug
/*    150f4:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    150f8:	3c028006 */ 	lui	$v0,0x8006
/*    150fc:	244212c4 */ 	addiu	$v0,$v0,0x12c4
/*    15100:	90480000 */ 	lbu	$t0,0x0($v0)
/*    15104:	35090010 */ 	ori	$t1,$t0,0x10
/*    15108:	a0490000 */ 	sb	$t1,0x0($v0)
.NB0001510c:
/*    1510c:	3c018006 */ 	lui	$at,0x8006
/*    15110:	ac2012d4 */ 	sw	$zero,0x12d4($at)
.NB00015114:
/*    15114:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15118:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1511c:	03e00008 */ 	jr	$ra
/*    15120:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

/**
 * The use of the static variable suggests that the function is able to be
 * called recursively, but its behaviour should not be run when recursing.
 */
void joy00014238(void)
{
	static bool doingit = false;
	s32 i;

	if (doingit == false) {
		doingit = true;

		for (i = 0; i < 4; i++) {
			if (joy000155f4(i) == 13) {
				pakSetUnk010(i, 11);
			}
		}

		if (var8005eec4 == NULL) {
			joy0001561c();
		}

		doingit = false;
	}
}

u32 var8005ef08 = 0;

void joyDebugJoy(void)
{
#if VERSION >= VERSION_NTSC_1_0
	func0000db30("debugjoy", &var8005ef08);
#else
	func0000db30("joyforce", &var8005ef08);
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

	if (joy000150c4() && var8005eec0 && joyGetNumSamples() <= 0) {
#if VERSION >= VERSION_NTSC_FINAL
		joy000150e8();
		joy00014238();
		joy00015144();
		joyConsumeSamples(&g_JoyData[0]);
#elif VERSION >= VERSION_NTSC_1_0
		joy000150e8();
		joy00015144();
		joyConsumeSamples(&g_JoyData[0]);
		joy00014238();
#else
		joy000150e8(500, "joy.c");
		joy00014238();
		func0001509cnb();
		joy00015144(507, "joy.c");
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

#if VERSION < VERSION_NTSC_1_0
const char var70055958nb[] = "joy.c";
const char var70055960nb[] = "joy.c";
#endif

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

#if VERSION >= VERSION_NTSC_1_0
void joyPoll(void)
{
	OSMesg msg;
	s8 i;

	if (osRecvMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK) == 0) {
		if (g_JoyBusy) {
			osRecvMesg(&var80099e78, &msg, OS_MESG_BLOCK);

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

		osSendMesg(&var80099ee0, &msg, OS_MESG_NOBLOCK);

		var8005ee68++;

		joyCheckPfs(0);
		return;
	}

	if (osRecvMesg(&var80099f00, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			joyStartReadData(&var80099e78);
			g_JoyBusy = true;
		}

		osSendMesg(&var80099f20, &msg, OS_MESG_NOBLOCK);
		return;
	}

	if (g_JoyInitDone) {
		if (var8005ee68) {
			joyCheckPfs(0);
			return;
		}

		if (osRecvMesg(&var80099e78, &msg, OS_MESG_NOBLOCK) == 0) {
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
			joyCheckPfs(0);

			joyStartReadData(&var80099e78);
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
#else
GLOBAL_ASM(
glabel joyPoll
/*    1536c:	3c028006 */ 	lui	$v0,0x8006
/*    15370:	244212c0 */ 	addiu	$v0,$v0,0x12c0
/*    15374:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    15378:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    1537c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    15380:	3c04800a */ 	lui	$a0,0x800a
/*    15384:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    15388:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    1538c:	2484e620 */ 	addiu	$a0,$a0,-6624
/*    15390:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    15394:	0c0126b0 */ 	jal	osRecvMesg
/*    15398:	00003025 */ 	or	$a2,$zero,$zero
/*    1539c:	14400045 */ 	bnez	$v0,.NB000154b4
/*    153a0:	3c188006 */ 	lui	$t8,0x8006
/*    153a4:	8f181254 */ 	lw	$t8,0x1254($t8)
/*    153a8:	3c04800a */ 	lui	$a0,0x800a
/*    153ac:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    153b0:	13000035 */ 	beqz	$t8,.NB00015488
/*    153b4:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    153b8:	0c0126b0 */ 	jal	osRecvMesg
/*    153bc:	24060001 */ 	addiu	$a2,$zero,0x1
/*    153c0:	3c018006 */ 	lui	$at,0x8006
/*    153c4:	0c0054bc */ 	jal	joyReadData
/*    153c8:	ac201254 */ 	sw	$zero,0x1254($at)
/*    153cc:	3c19800a */ 	lui	$t9,0x800a
/*    153d0:	8f39e3a8 */ 	lw	$t9,-0x1c58($t9)
/*    153d4:	3c09800a */ 	lui	$t1,0x800a
/*    153d8:	2529e1c0 */ 	addiu	$t1,$t1,-7744
/*    153dc:	00194080 */ 	sll	$t0,$t9,0x2
/*    153e0:	01194023 */ 	subu	$t0,$t0,$t9
/*    153e4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    153e8:	3c04800a */ 	lui	$a0,0x800a
/*    153ec:	2484e1c0 */ 	addiu	$a0,$a0,-7744
/*    153f0:	01093821 */ 	addu	$a3,$t0,$t1
/*    153f4:	00002825 */ 	or	$a1,$zero,$zero
/*    153f8:	24060006 */ 	addiu	$a2,$zero,0x6
.NB000153fc:
/*    153fc:	00a60019 */ 	multu	$a1,$a2
/*    15400:	00001012 */ 	mflo	$v0
/*    15404:	00e25021 */ 	addu	$t2,$a3,$v0
/*    15408:	91430004 */ 	lbu	$v1,0x4($t2)
/*    1540c:	1460000a */ 	bnez	$v1,.NB00015438
/*    15410:	00000000 */ 	sll	$zero,$zero,0x0
/*    15414:	8c8b01ec */ 	lw	$t3,0x1ec($a0)
/*    15418:	000b6080 */ 	sll	$t4,$t3,0x2
/*    1541c:	018b6023 */ 	subu	$t4,$t4,$t3
/*    15420:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    15424:	008c6821 */ 	addu	$t5,$a0,$t4
/*    15428:	01a27021 */ 	addu	$t6,$t5,$v0
/*    1542c:	91cf0004 */ 	lbu	$t7,0x4($t6)
/*    15430:	15e0000c */ 	bnez	$t7,.NB00015464
/*    15434:	00000000 */ 	sll	$zero,$zero,0x0
.NB00015438:
/*    15438:	1060000e */ 	beqz	$v1,.NB00015474
/*    1543c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    15440:	8c9801ec */ 	lw	$t8,0x1ec($a0)
/*    15444:	0018c880 */ 	sll	$t9,$t8,0x2
/*    15448:	0338c823 */ 	subu	$t9,$t9,$t8
/*    1544c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    15450:	00994021 */ 	addu	$t0,$a0,$t9
/*    15454:	01024821 */ 	addu	$t1,$t0,$v0
/*    15458:	912a0004 */ 	lbu	$t2,0x4($t1)
/*    1545c:	55400006 */ 	bnezl	$t2,.NB00015478
/*    15460:	00055e00 */ 	sll	$t3,$a1,0x18
.NB00015464:
/*    15464:	0c005332 */ 	jal	joy00013e84
/*    15468:	00000000 */ 	sll	$zero,$zero,0x0
/*    1546c:	10000006 */ 	beqz	$zero,.NB00015488
/*    15470:	00000000 */ 	sll	$zero,$zero,0x0
.NB00015474:
/*    15474:	00055e00 */ 	sll	$t3,$a1,0x18
.NB00015478:
/*    15478:	000b2e03 */ 	sra	$a1,$t3,0x18
/*    1547c:	28a10004 */ 	slti	$at,$a1,0x4
/*    15480:	1420ffde */ 	bnez	$at,.NB000153fc
/*    15484:	00000000 */ 	sll	$zero,$zero,0x0
.NB00015488:
/*    15488:	3c04800a */ 	lui	$a0,0x800a
/*    1548c:	2484e640 */ 	addiu	$a0,$a0,-6592
/*    15490:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    15494:	0c01272c */ 	jal	osSendMesg
/*    15498:	00003025 */ 	or	$a2,$zero,$zero
/*    1549c:	3c038006 */ 	lui	$v1,0x8006
/*    154a0:	24631258 */ 	addiu	$v1,$v1,0x1258
/*    154a4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    154a8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    154ac:	1000008c */ 	beqz	$zero,.NB000156e0
/*    154b0:	ac6e0000 */ 	sw	$t6,0x0($v1)
.NB000154b4:
/*    154b4:	3c04800a */ 	lui	$a0,0x800a
/*    154b8:	2484e660 */ 	addiu	$a0,$a0,-6560
/*    154bc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    154c0:	0c0126b0 */ 	jal	osRecvMesg
/*    154c4:	00003025 */ 	or	$a2,$zero,$zero
/*    154c8:	14400013 */ 	bnez	$v0,.NB00015518
/*    154cc:	3c038006 */ 	lui	$v1,0x8006
/*    154d0:	24631258 */ 	addiu	$v1,$v1,0x1258
/*    154d4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    154d8:	3c04800a */ 	lui	$a0,0x800a
/*    154dc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    154e0:	17000006 */ 	bnez	$t8,.NB000154fc
/*    154e4:	ac780000 */ 	sw	$t8,0x0($v1)
/*    154e8:	0c0054b4 */ 	jal	joyStartReadData
/*    154ec:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    154f0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    154f4:	3c018006 */ 	lui	$at,0x8006
/*    154f8:	ac281254 */ 	sw	$t0,0x1254($at)
.NB000154fc:
/*    154fc:	3c04800a */ 	lui	$a0,0x800a
/*    15500:	2484e680 */ 	addiu	$a0,$a0,-6528
/*    15504:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    15508:	0c01272c */ 	jal	osSendMesg
/*    1550c:	00003025 */ 	or	$a2,$zero,$zero
/*    15510:	10000074 */ 	beqz	$zero,.NB000156e4
/*    15514:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB00015518:
/*    15518:	3c038006 */ 	lui	$v1,0x8006
/*    1551c:	24631258 */ 	addiu	$v1,$v1,0x1258
/*    15520:	8c690000 */ 	lw	$t1,0x0($v1)
/*    15524:	3c0a8006 */ 	lui	$t2,0x8006
/*    15528:	5520006e */ 	bnezl	$t1,.NB000156e4
/*    1552c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15530:	8d4a12a4 */ 	lw	$t2,0x12a4($t2)
/*    15534:	3c04800a */ 	lui	$a0,0x800a
/*    15538:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    1553c:	11400068 */ 	beqz	$t2,.NB000156e0
/*    15540:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    15544:	0c0126b0 */ 	jal	osRecvMesg
/*    15548:	00003025 */ 	or	$a2,$zero,$zero
/*    1554c:	14400064 */ 	bnez	$v0,.NB000156e0
/*    15550:	3c018006 */ 	lui	$at,0x8006
/*    15554:	0c0054bc */ 	jal	joyReadData
/*    15558:	ac201254 */ 	sw	$zero,0x1254($at)
/*    1555c:	3c0b800a */ 	lui	$t3,0x800a
/*    15560:	8d6be3a8 */ 	lw	$t3,-0x1c58($t3)
/*    15564:	3c0d800a */ 	lui	$t5,0x800a
/*    15568:	25ade1c0 */ 	addiu	$t5,$t5,-7744
/*    1556c:	000b6080 */ 	sll	$t4,$t3,0x2
/*    15570:	018b6023 */ 	subu	$t4,$t4,$t3
/*    15574:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    15578:	3c04800a */ 	lui	$a0,0x800a
/*    1557c:	2484e1c0 */ 	addiu	$a0,$a0,-7744
/*    15580:	018d3821 */ 	addu	$a3,$t4,$t5
/*    15584:	00002825 */ 	or	$a1,$zero,$zero
/*    15588:	24060006 */ 	addiu	$a2,$zero,0x6
.NB0001558c:
/*    1558c:	00a60019 */ 	multu	$a1,$a2
/*    15590:	00001012 */ 	mflo	$v0
/*    15594:	00e27021 */ 	addu	$t6,$a3,$v0
/*    15598:	91c30004 */ 	lbu	$v1,0x4($t6)
/*    1559c:	1460000a */ 	bnez	$v1,.NB000155c8
/*    155a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    155a4:	8c8f01ec */ 	lw	$t7,0x1ec($a0)
/*    155a8:	000fc080 */ 	sll	$t8,$t7,0x2
/*    155ac:	030fc023 */ 	subu	$t8,$t8,$t7
/*    155b0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    155b4:	0098c821 */ 	addu	$t9,$a0,$t8
/*    155b8:	03224021 */ 	addu	$t0,$t9,$v0
/*    155bc:	91090004 */ 	lbu	$t1,0x4($t0)
/*    155c0:	1520000c */ 	bnez	$t1,.NB000155f4
/*    155c4:	00000000 */ 	sll	$zero,$zero,0x0
.NB000155c8:
/*    155c8:	1060000e */ 	beqz	$v1,.NB00015604
/*    155cc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    155d0:	8c8a01ec */ 	lw	$t2,0x1ec($a0)
/*    155d4:	000a5880 */ 	sll	$t3,$t2,0x2
/*    155d8:	016a5823 */ 	subu	$t3,$t3,$t2
/*    155dc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    155e0:	008b6021 */ 	addu	$t4,$a0,$t3
/*    155e4:	01826821 */ 	addu	$t5,$t4,$v0
/*    155e8:	91ae0004 */ 	lbu	$t6,0x4($t5)
/*    155ec:	55c00006 */ 	bnezl	$t6,.NB00015608
/*    155f0:	00057e00 */ 	sll	$t7,$a1,0x18
.NB000155f4:
/*    155f4:	0c005332 */ 	jal	joy00013e84
/*    155f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    155fc:	10000006 */ 	beqz	$zero,.NB00015618
/*    15600:	00000000 */ 	sll	$zero,$zero,0x0
.NB00015604:
/*    15604:	00057e00 */ 	sll	$t7,$a1,0x18
.NB00015608:
/*    15608:	000f2e03 */ 	sra	$a1,$t7,0x18
/*    1560c:	28a10004 */ 	slti	$at,$a1,0x4
/*    15610:	1420ffde */ 	bnez	$at,.NB0001558c
/*    15614:	00000000 */ 	sll	$zero,$zero,0x0
.NB00015618:
/*    15618:	0c005449 */ 	jal	joy00014238
/*    1561c:	00000000 */ 	sll	$zero,$zero,0x0
/*    15620:	0c005427 */ 	jal	func0001509cnb
/*    15624:	00000000 */ 	sll	$zero,$zero,0x0
/*    15628:	3c04800a */ 	lui	$a0,0x800a
/*    1562c:	0c0054b4 */ 	jal	joyStartReadData
/*    15630:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    15634:	3c038006 */ 	lui	$v1,0x8006
/*    15638:	8c6312dc */ 	lw	$v1,0x12dc($v1)
/*    1563c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    15640:	3c018006 */ 	lui	$at,0x8006
/*    15644:	ac391254 */ 	sw	$t9,0x1254($at)
/*    15648:	3c018006 */ 	lui	$at,0x8006
/*    1564c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    15650:	ac2312dc */ 	sw	$v1,0x12dc($at)
/*    15654:	2861003c */ 	slti	$at,$v1,0x3c
/*    15658:	14200021 */ 	bnez	$at,.NB000156e0
/*    1565c:	3c038006 */ 	lui	$v1,0x8006
/*    15660:	3c048006 */ 	lui	$a0,0x8006
/*    15664:	3c058006 */ 	lui	$a1,0x8006
/*    15668:	3c028006 */ 	lui	$v0,0x8006
/*    1566c:	3c068006 */ 	lui	$a2,0x8006
/*    15670:	24c6129c */ 	addiu	$a2,$a2,0x129c
/*    15674:	2442128c */ 	addiu	$v0,$v0,0x128c
/*    15678:	24a5127c */ 	addiu	$a1,$a1,0x127c
/*    1567c:	2484126c */ 	addiu	$a0,$a0,0x126c
/*    15680:	2463125c */ 	addiu	$v1,$v1,0x125c
.NB00015684:
/*    15684:	8c680000 */ 	lw	$t0,0x0($v1)
/*    15688:	5500000b */ 	bnezl	$t0,.NB000156b8
/*    1568c:	ac600000 */ 	sw	$zero,0x0($v1)
/*    15690:	8c890000 */ 	lw	$t1,0x0($a0)
/*    15694:	55200008 */ 	bnezl	$t1,.NB000156b8
/*    15698:	ac600000 */ 	sw	$zero,0x0($v1)
/*    1569c:	8caa0000 */ 	lw	$t2,0x0($a1)
/*    156a0:	55400005 */ 	bnezl	$t2,.NB000156b8
/*    156a4:	ac600000 */ 	sw	$zero,0x0($v1)
/*    156a8:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*    156ac:	51600006 */ 	beqzl	$t3,.NB000156c8
/*    156b0:	24420004 */ 	addiu	$v0,$v0,0x4
/*    156b4:	ac600000 */ 	sw	$zero,0x0($v1)
.NB000156b8:
/*    156b8:	ac800000 */ 	sw	$zero,0x0($a0)
/*    156bc:	aca00000 */ 	sw	$zero,0x0($a1)
/*    156c0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    156c4:	24420004 */ 	addiu	$v0,$v0,0x4
.NB000156c8:
/*    156c8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    156cc:	24840004 */ 	addiu	$a0,$a0,0x4
/*    156d0:	1446ffec */ 	bne	$v0,$a2,.NB00015684
/*    156d4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    156d8:	3c018006 */ 	lui	$at,0x8006
/*    156dc:	ac2012dc */ 	sw	$zero,0x12dc($at)
.NB000156e0:
/*    156e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB000156e4:
/*    156e4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    156e8:	03e00008 */ 	jr	$ra
/*    156ec:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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

s32 joyGetStickX(s8 contpadnum)
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

s32 joyGetStickY(s8 contpadnum)
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
GLOBAL_ASM(
glabel func00015fa4nb
/*    15fa4:	3c038006 */ 	lui	$v1,0x8006
/*    15fa8:	8c631250 */ 	lw	$v1,0x1250($v1)
/*    15fac:	afa40000 */ 	sw	$a0,0x0($sp)
/*    15fb0:	afa50004 */ 	sw	$a1,0x4($sp)
/*    15fb4:	8c790200 */ 	lw	$t9,0x200($v1)
/*    15fb8:	00047600 */ 	sll	$t6,$a0,0x18
/*    15fbc:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    15fc0:	30b8ffff */ 	andi	$t8,$a1,0xffff
/*    15fc4:	03002825 */ 	or	$a1,$t8,$zero
/*    15fc8:	0721000f */ 	bgez	$t9,.NB00016008
/*    15fcc:	01e02025 */ 	or	$a0,$t7,$zero
/*    15fd0:	3c088006 */ 	lui	$t0,0x8006
/*    15fd4:	9108129c */ 	lbu	$t0,0x129c($t0)
/*    15fd8:	3c0c8006 */ 	lui	$t4,0x8006
/*    15fdc:	258c128c */ 	addiu	$t4,$t4,0x128c
/*    15fe0:	01e84807 */ 	srav	$t1,$t0,$t7
/*    15fe4:	312a0001 */ 	andi	$t2,$t1,0x1
/*    15fe8:	15400007 */ 	bnez	$t2,.NB00016008
/*    15fec:	000f5880 */ 	sll	$t3,$t7,0x2
/*    15ff0:	016c1821 */ 	addu	$v1,$t3,$t4
/*    15ff4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    15ff8:	00001025 */ 	or	$v0,$zero,$zero
/*    15ffc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    16000:	03e00008 */ 	jr	$ra
/*    16004:	ac6e0000 */ 	sw	$t6,0x0($v1)
.NB00016008:
/*    16008:	00047880 */ 	sll	$t7,$a0,0x2
/*    1600c:	3c18800a */ 	lui	$t8,0x800a
/*    16010:	030fc021 */ 	addu	$t8,$t8,$t7
/*    16014:	8f18e5c8 */ 	lw	$t8,-0x1a38($t8)
/*    16018:	5b000004 */ 	blezl	$t8,.NB0001602c
/*    1601c:	0004c840 */ 	sll	$t9,$a0,0x1
/*    16020:	03e00008 */ 	jr	$ra
/*    16024:	00001025 */ 	or	$v0,$zero,$zero
/*    16028:	0004c840 */ 	sll	$t9,$a0,0x1
.NB0001602c:
/*    1602c:	00794021 */ 	addu	$t0,$v1,$t9
/*    16030:	950901f8 */ 	lhu	$t1,0x1f8($t0)
/*    16034:	01251024 */ 	and	$v0,$t1,$a1
/*    16038:	304affff */ 	andi	$t2,$v0,0xffff
/*    1603c:	01401025 */ 	or	$v0,$t2,$zero
/*    16040:	03e00008 */ 	jr	$ra
/*    16044:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s32 joy000150c4(void)
{
	return var8005eebc ? false : true;
}

void joy000150e8(
#if VERSION >= VERSION_NTSC_1_0
		void
#else
		s32 line, char *file
#endif
		)
{
	OSMesg msg;

	if (var8005eebc == 0) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);
	}

	var8005eebc++;
}

void joy00015144(
#if VERSION >= VERSION_NTSC_1_0
		void
#else
		s32 line, char *file
#endif
		)
{
	OSMesg msg;

	var8005eebc--;

	if (var8005eebc == 0) {
		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);
	}
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00016130nb
/*    16130:	000471c0 */ 	sll	$t6,$a0,0x7
/*    16134:	01c47021 */ 	addu	$t6,$t6,$a0
/*    16138:	3c0f800a */ 	lui	$t7,0x800a
/*    1613c:	25efe1c0 */ 	addiu	$t7,$t7,-7744
/*    16140:	000e7080 */ 	sll	$t6,$t6,0x2
/*    16144:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    16148:	3c018006 */ 	lui	$at,0x8006
/*    1614c:	03e00008 */ 	jr	$ra
/*    16150:	ac381250 */ 	sw	$t8,0x1250($at)
);

GLOBAL_ASM(
glabel func00016154nb
/*    16154:	3c0e8006 */ 	lui	$t6,0x8006
/*    16158:	8dce1250 */ 	lw	$t6,0x1250($t6)
/*    1615c:	3c0f800a */ 	lui	$t7,0x800a
/*    16160:	25efe1c0 */ 	addiu	$t7,$t7,-7744
/*    16164:	24010204 */ 	addiu	$at,$zero,0x204
/*    16168:	01cf1023 */ 	subu	$v0,$t6,$t7
/*    1616c:	0041001a */ 	div	$zero,$v0,$at
/*    16170:	00001012 */ 	mflo	$v0
/*    16174:	03e00008 */ 	jr	$ra
/*    16178:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void joyReset(void)
{
	s32 i;

	osCreateMesgQueue(&var80099e78, &var80099e90, 10);
	osSetEventMesg(OS_EVENT_SI, &var80099e78, 0);

	for (i = 0; i < 4; i++) {
		if (osMotorProbe(&var80099e78, PFS(i), i) == 0) {
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

	if (g_MpPlayers[g_Vars.playerstats[playernum].mpindex].base.controlmode >= CONTROLMODE_21) {
		*pad2 = PLAYERCOUNT() + playernum;
		return;
	}

	*pad2 = -1;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void joy000153c4(s8 device, s32 arg1)
{
	u32 stack;

	if (device != SAVEDEVICE_GAMEPAK) {
		if (g_Paks[device].unk000 != 2 && g_Paks[device].unk000 != 3) {
			if (arg1) {
				joy000150e8();
			}

			if (osMotorProbe(&var80099e78, PFS(device), device) == 0) {
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
				osMotorStop(PFS(device));
			}

			if (arg1) {
				joy00015144();
			}

			if (g_Paks[device].unk004 != 6 && g_Paks[device].unk004 != 7) {
				g_Paks[device].unk004 =  5;
			}

			g_Paks[device].unk2b4 = -1;
		}
	}

	if (device) {
		// empty
	}
}
#else
GLOBAL_ASM(
glabel joy000153c4
/*    162b0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    162b4:	00047600 */ 	sll	$t6,$a0,0x18
/*    162b8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    162bc:	24010004 */ 	addiu	$at,$zero,0x4
/*    162c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    162c4:	afa40028 */ 	sw	$a0,0x28($sp)
/*    162c8:	11e10073 */ 	beq	$t7,$at,.NB00016498
/*    162cc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    162d0:	3c06800a */ 	lui	$a2,0x800a
/*    162d4:	00cf3021 */ 	addu	$a2,$a2,$t7
/*    162d8:	90c6eb9c */ 	lbu	$a2,-0x1464($a2)
/*    162dc:	3c19800a */ 	lui	$t9,0x800a
/*    162e0:	27396870 */ 	addiu	$t9,$t9,0x6870
/*    162e4:	0006c080 */ 	sll	$t8,$a2,0x2
/*    162e8:	0306c023 */ 	subu	$t8,$t8,$a2
/*    162ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*    162f0:	0306c023 */ 	subu	$t8,$t8,$a2
/*    162f4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    162f8:	0306c021 */ 	addu	$t8,$t8,$a2
/*    162fc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    16300:	03194021 */ 	addu	$t0,$t8,$t9
/*    16304:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    16308:	8d020000 */ 	lw	$v0,0x0($t0)
/*    1630c:	24010002 */ 	addiu	$at,$zero,0x2
/*    16310:	10410061 */ 	beq	$v0,$at,.NB00016498
/*    16314:	24010003 */ 	addiu	$at,$zero,0x3
/*    16318:	50410060 */ 	beql	$v0,$at,.NB0001649c
/*    1631c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    16320:	10a00006 */ 	beqz	$a1,.NB0001633c
/*    16324:	2404041e */ 	addiu	$a0,$zero,0x41e
/*    16328:	3c057005 */ 	lui	$a1,0x7005
/*    1632c:	24a55958 */ 	addiu	$a1,$a1,0x5958
/*    16330:	0c00581b */ 	jal	joy000150e8
/*    16334:	afa60024 */ 	sw	$a2,0x24($sp)
/*    16338:	8fa60024 */ 	lw	$a2,0x24($sp)
.NB0001633c:
/*    1633c:	24010004 */ 	addiu	$at,$zero,0x4
/*    16340:	14c10003 */ 	bne	$a2,$at,.NB00016350
/*    16344:	3c04800a */ 	lui	$a0,0x800a
/*    16348:	10000009 */ 	beqz	$zero,.NB00016370
/*    1634c:	00003825 */ 	or	$a3,$zero,$zero
.NB00016350:
/*    16350:	00065080 */ 	sll	$t2,$a2,0x2
/*    16354:	01465023 */ 	subu	$t2,$t2,$a2
/*    16358:	000a5080 */ 	sll	$t2,$t2,0x2
/*    1635c:	01465021 */ 	addu	$t2,$t2,$a2
/*    16360:	3c0b800a */ 	lui	$t3,0x800a
/*    16364:	256b7658 */ 	addiu	$t3,$t3,0x7658
/*    16368:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    1636c:	014b3821 */ 	addu	$a3,$t2,$t3
.NB00016370:
/*    16370:	2484e5d8 */ 	addiu	$a0,$a0,-6696
/*    16374:	00e02825 */ 	or	$a1,$a3,$zero
/*    16378:	0c01440d */ 	jal	osMotorProbe
/*    1637c:	afa60024 */ 	sw	$a2,0x24($sp)
/*    16380:	14400032 */ 	bnez	$v0,.NB0001644c
/*    16384:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    16388:	24010004 */ 	addiu	$at,$zero,0x4
/*    1638c:	14c10003 */ 	bne	$a2,$at,.NB0001639c
/*    16390:	00002825 */ 	or	$a1,$zero,$zero
/*    16394:	10000009 */ 	beqz	$zero,.NB000163bc
/*    16398:	00003825 */ 	or	$a3,$zero,$zero
.NB0001639c:
/*    1639c:	00066080 */ 	sll	$t4,$a2,0x2
/*    163a0:	01866023 */ 	subu	$t4,$t4,$a2
/*    163a4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    163a8:	01866021 */ 	addu	$t4,$t4,$a2
/*    163ac:	3c0d800a */ 	lui	$t5,0x800a
/*    163b0:	25ad7658 */ 	addiu	$t5,$t5,0x7658
/*    163b4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    163b8:	018d3821 */ 	addu	$a3,$t4,$t5
.NB000163bc:
/*    163bc:	00e02025 */ 	or	$a0,$a3,$zero
/*    163c0:	0c014370 */ 	jal	osMotorAccess
/*    163c4:	afa60024 */ 	sw	$a2,0x24($sp)
/*    163c8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    163cc:	24010004 */ 	addiu	$at,$zero,0x4
/*    163d0:	00002825 */ 	or	$a1,$zero,$zero
/*    163d4:	14c10003 */ 	bne	$a2,$at,.NB000163e4
/*    163d8:	00067080 */ 	sll	$t6,$a2,0x2
/*    163dc:	10000008 */ 	beqz	$zero,.NB00016400
/*    163e0:	00003825 */ 	or	$a3,$zero,$zero
.NB000163e4:
/*    163e4:	01c67023 */ 	subu	$t6,$t6,$a2
/*    163e8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    163ec:	01c67021 */ 	addu	$t6,$t6,$a2
/*    163f0:	3c0f800a */ 	lui	$t7,0x800a
/*    163f4:	25ef7658 */ 	addiu	$t7,$t7,0x7658
/*    163f8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    163fc:	01cf3821 */ 	addu	$a3,$t6,$t7
.NB00016400:
/*    16400:	00e02025 */ 	or	$a0,$a3,$zero
/*    16404:	0c014370 */ 	jal	osMotorAccess
/*    16408:	afa60024 */ 	sw	$a2,0x24($sp)
/*    1640c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    16410:	24010004 */ 	addiu	$at,$zero,0x4
/*    16414:	00002825 */ 	or	$a1,$zero,$zero
/*    16418:	14c10003 */ 	bne	$a2,$at,.NB00016428
/*    1641c:	0006c080 */ 	sll	$t8,$a2,0x2
/*    16420:	10000008 */ 	beqz	$zero,.NB00016444
/*    16424:	00003825 */ 	or	$a3,$zero,$zero
.NB00016428:
/*    16428:	0306c023 */ 	subu	$t8,$t8,$a2
/*    1642c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    16430:	0306c021 */ 	addu	$t8,$t8,$a2
/*    16434:	3c19800a */ 	lui	$t9,0x800a
/*    16438:	27397658 */ 	addiu	$t9,$t9,0x7658
/*    1643c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    16440:	03193821 */ 	addu	$a3,$t8,$t9
.NB00016444:
/*    16444:	0c014370 */ 	jal	osMotorAccess
/*    16448:	00e02025 */ 	or	$a0,$a3,$zero
.NB0001644c:
/*    1644c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    16450:	2404042a */ 	addiu	$a0,$zero,0x42a
/*    16454:	3c057005 */ 	lui	$a1,0x7005
/*    16458:	51000004 */ 	beqzl	$t0,.NB0001646c
/*    1645c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    16460:	0c005834 */ 	jal	joy00015144
/*    16464:	24a55960 */ 	addiu	$a1,$a1,0x5960
/*    16468:	8fa3001c */ 	lw	$v1,0x1c($sp)
.NB0001646c:
/*    1646c:	24010006 */ 	addiu	$at,$zero,0x6
/*    16470:	8c620004 */ 	lw	$v0,0x4($v1)
/*    16474:	10410004 */ 	beq	$v0,$at,.NB00016488
/*    16478:	24010007 */ 	addiu	$at,$zero,0x7
/*    1647c:	10410002 */ 	beq	$v0,$at,.NB00016488
/*    16480:	24090005 */ 	addiu	$t1,$zero,0x5
/*    16484:	ac690004 */ 	sw	$t1,0x4($v1)
.NB00016488:
/*    16488:	3c01bf80 */ 	lui	$at,0xbf80
/*    1648c:	44812000 */ 	mtc1	$at,$f4
/*    16490:	00000000 */ 	sll	$zero,$zero,0x0
/*    16494:	e46402b4 */ 	swc1	$f4,0x2b4($v1)
.NB00016498:
/*    16498:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0001649c:
/*    1649c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    164a0:	03e00008 */ 	jr	$ra
/*    164a4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s32 joy000155b4(s8 device)
{
	return g_Paks[device].unk010;
}

s32 joy000155f4(s8 device)
{
	return joy000155b4(device);
}

void joy0001561c(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Paks[i].unk010 == 11 && g_Paks[i].unk000 == 1) {
			switch (g_Paks[i].unk004) {
			case 3:
				g_Paks[i].unk004 = 4;
				osMotorStart(PFS(i));
				break;
			case 4:
				if (g_Paks[i].unk284 != -1) {
					if (g_Paks[i].unk28c == 0) {
						osMotorStart(PFS(i));
					} else if (g_Paks[i].unk284 == g_Paks[i].unk28c) {
						osMotorStop(PFS(i));
					}

					g_Paks[i].unk28c++;

					if (g_Paks[i].unk288 == g_Paks[i].unk28c) {
						g_Paks[i].unk28c = 0;
					}
				}

				g_Paks[i].unk2b4--;

				if (g_Paks[i].unk2b4 < 0) {
					g_Paks[i].unk004 = 5;
				}
				break;
			case 5:
				g_Paks[i].unk004 = 2;
				osMotorStop(PFS(i));
				break;
			case 6:
				osMotorStop(PFS(i));
				g_Paks[i].unk004 = 7;
				break;
			case 8:
				g_Paks[i].unk004 = 2;
				g_Paks[i].unk2b4 = -1;
				break;
			}
		}
	}
}
