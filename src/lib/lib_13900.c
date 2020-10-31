#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/pak/pak.h"
#include "gvars/gvars.h"
#include "lib/lib_04a80.h"
#include "lib/main.h"
#include "lib/lib_13900.h"
#include "lib/lib_4f5e0.h"
#include "types.h"

const char var70054080[] = "joyReset\n";
const char var7005408c[] = "joyReset: doing nothing\n";

struct contdata *var8005ee60 = &var80099a60[0];
bool g_ContBusy = false;
u32 var8005ee68 = 0x00000000;
u32 var8005ee6c[4] = {0};
u32 var8005ee7c[4] = {0};
u32 var8005ee8c[4] = {0};
u32 var8005ee9c[4] = {0};
u8 g_ConnectedControllers = 0;
u32 var8005eeb0 = 0x00000000;
bool g_ContInitDone = false;
bool g_ContNeedsInit = true;
u32 var8005eebc = 0x00000000;
u32 var8005eec0 = 0x00000001;
s32 (*var8005eec4)(struct contsample *samples, s32 samplenum) = NULL;
void (*var8005eec8)(struct contsample *samples, s32 samplenum, s32 samplenum2) = NULL;
s32 var8005eecc = 0;
u32 var8005eed0 = 0x00000000;
u32 var8005eed4 = 0x00000000;
u8 var8005eed8 = 0;
u32 var8005eedc = 0x00000001;
s32 var8005eee0 = 0;
s32 var8005eee4 = -1;
u32 var8005eee8 = 0x00000000;
u32 var8005eeec = 0x00000000;
u32 var8005eef0 = 0x00000001;

void func00013900(void)
{
	if (var8005eef0) {
		func000150e8();
		var8005eef0 = false;
	}
}

void func00013938(void)
{
	if (!var8005eef0) {
		func00015144();
		var8005eef0 = true;
	}
}

void func00013974(u32 value)
{
	var8005eeec = value;
}

u32 func00013980(void)
{
	return var8005eeec;
}

void func0001398c(s32 value)
{
	var8005eee4 = var8005eee0 = value * 11000;
}

void func000139c8(void)
{
	func0001398c(10);
}

/**
 * Remove an item from the beginning of the var80099f48 array,
 * shift the rest of the array back and return the removed item.
 */
s32 func000139e8(void)
{
	s32 result = 0;
	s32 i;

	if (var8005eecc) {
		result = var80099f48[0];

		if (var8005eecc > 1) {
			for (i = 0; i < var8005eecc; i++) {
				var80099f48[i] = var80099f48[i + 1];
			}

			var8005eecc--;
		}
	}

	return result;
}

void func00013a40(u8 arg0)
{
	if (var8005eecc + 1 >= 100) {
		func000139e8();
	}

	if (var8005eecc == 0 || arg0 != var80099f48[var8005eecc - 1]) {
		var80099f48[var8005eecc] = arg0;
		var8005eecc++;
	}
}

/**
 * Scan controllers for controller paks, but only under certain conditions.
 * Seems to be timer based, or can be forced by passing 2 as arg0.
 */
void contCheckPfs(s32 arg0)
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
				func000150e8();
			}

			osPfsIsPlug(&var80099e78, &bitpattern);

			if (arg0) {
				func00015144();
			}

			bitpattern |= 0x10;

			func00013a40(bitpattern);

			var8005eee4 = var8005eee0;
		}

		doingit = false;
	}

	if (arg0) {
		// empty
	}
}

void func00013c4c(s8 index)
{
	u8 value = var8005eed8 & ~(1 << index);

	func00013a40(value);
}

void contSystemInit(void)
{
	s32 i;
	s32 j;

	osCreateMesgQueue(&var80099ec0, &var80099eb8, 1);
	osCreateMesgQueue(&var80099ee0, &var80099ed8, 1);
	osCreateMesgQueue(&var80099f00, &var80099ef8, 1);
	osCreateMesgQueue(&var80099f20, &var80099f18, 1);
	osCreateMesgQueue(&var80099e78, &var80099e90, 10);

	osSetEventMesg(OS_EVENT_SI, &var80099e78, NULL);

	var8005eeb0 = 1;
	var8005eec4 = NULL;
	var8005eec8 = NULL;

	for (i = 0; i < 2; i++) {
		var80099a60[i].unk1e0 = 0;
		var80099a60[i].unk1e4 = 0;
		var80099a60[i].unk1e8 = 0;
		var80099a60[i].unk1ec = 0;
		var80099a60[i].unk200 = -1;

		for (j = 0; j < 4; j++) {
			var80099a60[i].samples[0].pads[j].button = 0;
			var80099a60[i].samples[0].pads[j].stick_x = 0;
			var80099a60[i].samples[0].pads[j].stick_y = 0;
			var80099a60[i].samples[0].pads[j].errno = 0;
		}
	}

	for (i = 0; i < 4; i++) {
		var80099e68[i] = 0;
	}
}

void func00013dd4(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var80099e68[i] = 60;
	}
}

void func00013dfc(void)
{
	OSMesg msg;

	if (var8005eeb0) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);

		func00013e84();

		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);

		var8005eec0 = 1;
	}
}

void func00013e84(void)
{
	static u8 var8005ef00 = 0xff;

	// osContInit should be called only once. The first time this function is
	// called it'll take the first branch here, and all subsequent calls will
	// take the second branch.
	if (g_ContNeedsInit) {
		s32 i;
		g_ContNeedsInit = false;
		osContInit(&var80099e78, &g_ConnectedControllers, var80099f38);
		g_ContInitDone = true;

		for (i = 0; i < 4; i++) {
			func000153c4(i, 0);
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

		g_ConnectedControllers = slots;
	}

	if (var8005ef00 != g_ConnectedControllers) {
		s32 i = 0;
		s32 index = 0;

		for (; i < 4; i++) {
			if (g_ConnectedControllers & (1 << i)) {
				g_Vars.playertojoymap[index++] = i;
			}
		}

		var8005ef00 = g_ConnectedControllers;
	}
}

s8 contGetFreeSlot(void)
{
	s32 i;

	if (var8005ee60->unk200 >= 0) {
		return var8005ee60->unk200;
	}

	for (i = 0; i < 4; i++) {
		if ((g_ConnectedControllers & (1 << i)) == 0) {
			return i;
		}
	}

	return 4;
}

u32 contGetConnectedControllers(void)
{
	return g_ConnectedControllers;
}

GLOBAL_ASM(
glabel func00014058
/*    14058:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    1405c:	afb00004 */ 	sw	$s0,0x4($sp)
/*    14060:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    14064:	8c8f01e8 */ 	lw	$t7,0x1e8($a0)
/*    14068:	24100014 */ 	addiu	$s0,$zero,0x14
/*    1406c:	00001025 */ 	or	$v0,$zero,$zero
/*    14070:	ac8e01e4 */ 	sw	$t6,0x1e4($a0)
/*    14074:	ac8f01e0 */ 	sw	$t7,0x1e0($a0)
/*    14078:	0002c040 */ 	sll	$t8,$v0,0x1
.L0001407c:
/*    1407c:	00981821 */ 	addu	$v1,$a0,$t8
/*    14080:	a46001f0 */ 	sh	$zero,0x1f0($v1)
/*    14084:	a46001f8 */ 	sh	$zero,0x1f8($v1)
/*    14088:	8c9901e0 */ 	lw	$t9,0x1e0($a0)
/*    1408c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14090:	3c18800a */ 	lui	$t8,%hi(var80099e68)
/*    14094:	27189e68 */ 	addiu	$t8,$t8,%lo(var80099e68)
/*    14098:	10b9005e */ 	beq	$a1,$t9,.L00014214
/*    1409c:	24ae0001 */ 	addiu	$t6,$a1,0x1
/*    140a0:	01d0001a */ 	div	$zero,$t6,$s0
/*    140a4:	00023880 */ 	sll	$a3,$v0,0x2
/*    140a8:	00003010 */ 	mfhi	$a2
/*    140ac:	00e23823 */ 	subu	$a3,$a3,$v0
/*    140b0:	00027880 */ 	sll	$t7,$v0,0x2
/*    140b4:	01f86021 */ 	addu	$t4,$t7,$t8
/*    140b8:	00073840 */ 	sll	$a3,$a3,0x1
/*    140bc:	16000002 */ 	bnez	$s0,.L000140c8
/*    140c0:	00000000 */ 	nop
/*    140c4:	0007000d */ 	break	0x7
.L000140c8:
/*    140c8:	2401ffff */ 	addiu	$at,$zero,-1
/*    140cc:	16010004 */ 	bne	$s0,$at,.L000140e0
/*    140d0:	3c018000 */ 	lui	$at,0x8000
/*    140d4:	15c10002 */ 	bne	$t6,$at,.L000140e0
/*    140d8:	00000000 */ 	nop
/*    140dc:	0006000d */ 	break	0x6
.L000140e0:
/*    140e0:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L000140e4:
/*    140e4:	01f0001a */ 	div	$zero,$t7,$s0
/*    140e8:	0006c880 */ 	sll	$t9,$a2,0x2
/*    140ec:	0326c823 */ 	subu	$t9,$t9,$a2
/*    140f0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    140f4:	00997021 */ 	addu	$t6,$a0,$t9
/*    140f8:	0000c010 */ 	mfhi	$t8
/*    140fc:	0018c880 */ 	sll	$t9,$t8,0x2
/*    14100:	0338c823 */ 	subu	$t9,$t9,$t8
/*    14104:	01c74021 */ 	addu	$t0,$t6,$a3
/*    14108:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    1410c:	00997021 */ 	addu	$t6,$a0,$t9
/*    14110:	95050000 */ 	lhu	$a1,0x0($t0)
/*    14114:	16000002 */ 	bnez	$s0,.L00014120
/*    14118:	00000000 */ 	nop
/*    1411c:	0007000d */ 	break	0x7
.L00014120:
/*    14120:	2401ffff */ 	addiu	$at,$zero,-1
/*    14124:	16010004 */ 	bne	$s0,$at,.L00014138
/*    14128:	3c018000 */ 	lui	$at,0x8000
/*    1412c:	15e10002 */ 	bne	$t7,$at,.L00014138
/*    14130:	00000000 */ 	nop
/*    14134:	0006000d */ 	break	0x6
.L00014138:
/*    14138:	01c77821 */ 	addu	$t7,$t6,$a3
/*    1413c:	95e90000 */ 	lhu	$t1,0x0($t7)
/*    14140:	947801f0 */ 	lhu	$t8,0x1f0($v1)
/*    14144:	00a05025 */ 	or	$t2,$a1,$zero
/*    14148:	0120c827 */ 	nor	$t9,$t1,$zero
/*    1414c:	00b97024 */ 	and	$t6,$a1,$t9
/*    14150:	030e7825 */ 	or	$t7,$t8,$t6
/*    14154:	947901f8 */ 	lhu	$t9,0x1f8($v1)
/*    14158:	00a0c027 */ 	nor	$t8,$a1,$zero
/*    1415c:	a46f01f0 */ 	sh	$t7,0x1f0($v1)
/*    14160:	03097024 */ 	and	$t6,$t8,$t1
/*    14164:	032e7825 */ 	or	$t7,$t9,$t6
/*    14168:	a46f01f8 */ 	sh	$t7,0x1f8($v1)
/*    1416c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    14170:	01205825 */ 	or	$t3,$t1,$zero
/*    14174:	59a00017 */ 	blezl	$t5,.L000141d4
/*    14178:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    1417c:	95180000 */ 	lhu	$t8,0x0($t0)
/*    14180:	57000012 */ 	bnezl	$t8,.L000141cc
/*    14184:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14188:	81050002 */ 	lb	$a1,0x2($t0)
/*    1418c:	28a1000f */ 	slti	$at,$a1,0xf
/*    14190:	5020000e */ 	beqzl	$at,.L000141cc
/*    14194:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14198:	28a1fff2 */ 	slti	$at,$a1,-14
/*    1419c:	5420000b */ 	bnezl	$at,.L000141cc
/*    141a0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141a4:	81050003 */ 	lb	$a1,0x3($t0)
/*    141a8:	28a1000f */ 	slti	$at,$a1,0xf
/*    141ac:	50200007 */ 	beqzl	$at,.L000141cc
/*    141b0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141b4:	28a1fff2 */ 	slti	$at,$a1,-14
/*    141b8:	54200004 */ 	bnezl	$at,.L000141cc
/*    141bc:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141c0:	10000003 */ 	b	.L000141d0
/*    141c4:	ad800000 */ 	sw	$zero,0x0($t4)
/*    141c8:	25b9ffff */ 	addiu	$t9,$t5,-1
.L000141cc:
/*    141cc:	ad990000 */ 	sw	$t9,0x0($t4)
.L000141d0:
/*    141d0:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
.L000141d4:
/*    141d4:	50ce0010 */ 	beql	$a2,$t6,.L00014218
/*    141d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*    141dc:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*    141e0:	01f0001a */ 	div	$zero,$t7,$s0
/*    141e4:	00003010 */ 	mfhi	$a2
/*    141e8:	16000002 */ 	bnez	$s0,.L000141f4
/*    141ec:	00000000 */ 	nop
/*    141f0:	0007000d */ 	break	0x7
.L000141f4:
/*    141f4:	2401ffff */ 	addiu	$at,$zero,-1
/*    141f8:	16010004 */ 	bne	$s0,$at,.L0001420c
/*    141fc:	3c018000 */ 	lui	$at,0x8000
/*    14200:	15e10002 */ 	bne	$t7,$at,.L0001420c
/*    14204:	00000000 */ 	nop
/*    14208:	0006000d */ 	break	0x6
.L0001420c:
/*    1420c:	1000ffb5 */ 	b	.L000140e4
/*    14210:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L00014214:
/*    14214:	24420001 */ 	addiu	$v0,$v0,0x1
.L00014218:
/*    14218:	0002c600 */ 	sll	$t8,$v0,0x18
/*    1421c:	00181603 */ 	sra	$v0,$t8,0x18
/*    14220:	28410004 */ 	slti	$at,$v0,0x4
/*    14224:	5420ff95 */ 	bnezl	$at,.L0001407c
/*    14228:	0002c040 */ 	sll	$t8,$v0,0x1
/*    1422c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*    14230:	03e00008 */ 	jr	$ra
/*    14234:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

// Mismatch because goal calculates &var80099e68 before the % 20 on the marked
// line, but the below does it after.
//void func00014058(struct contdata *contdata)
//{
//	s8 i;
//	s32 samplenum;
//	u16 buttons1;
//	u16 buttons2;
//
//	contdata->unk1e4 = contdata->unk1e0;
//	contdata->unk1e0 = contdata->unk1e8;
//
//	for (i = 0; i < 4; i++) {
//		contdata->unk1f0[i] = 0;
//		contdata->unk1f8[i] = 0;
//
//		if (contdata->unk1e0 != contdata->unk1e4) {
//			// Mismatch here
//			samplenum = (contdata->unk1e4 + 1) % 20;
//
//			while (true) {
//				buttons1 = contdata->samples[samplenum].pads[i].button;
//				buttons2 = contdata->samples[(samplenum + 19) % 20].pads[i].button;
//
//				contdata->unk1f0[i] |= buttons1 & ~buttons2;
//				contdata->unk1f8[i] |= ~buttons1 & buttons2;
//
//				if (var80099e68[i] > 0) {
//					if (contdata->samples[samplenum].pads[i].button == 0
//							&& contdata->samples[samplenum].pads[i].stick_x < 15
//							&& contdata->samples[samplenum].pads[i].stick_x > -15
//							&& contdata->samples[samplenum].pads[i].stick_y < 15
//							&& contdata->samples[samplenum].pads[i].stick_y > -15) {
//						var80099e68[i] = 0;
//					} else {
//						var80099e68[i]--;
//					}
//				}
//
//				if (samplenum == contdata->unk1e0) {
//					break;
//				}
//
//				samplenum = (samplenum + 1) % 20;
//			}
//		}
//	}
//}

/**
 * The use of the static variable suggests that the function is able to be
 * called recursively, but its behaviour should not be run when recursing.
 */
void func00014238(void)
{
	static bool doingit = false;
	s32 i;

	if (doingit == false) {
		doingit = true;

		for (i = 0; i < 4; i++) {
			if (func000155f4(i) == 13) {
				func0f116db0(i, 11);
			}
		}

		if (var8005eec4 == NULL) {
			func0001561c();
		}

		doingit = false;
	}
}

u32 var8005ef08 = 0;

void contDebugJoy(void)
{
	func0000db30("debugjoy", &var8005ef08);

	if (g_Vars.unk0004d0) {
		contCheckPfs(1);
	}

	if (var8005eec4) {
		var80099a60[1].unk1e8 = var8005eec4(var80099a60[1].samples, var80099a60[1].unk1e0);
		func00014058(&var80099a60[1]);
	}

	func00014058(&var80099a60[0]);

	if (var8005eec8) {
		var8005eec8(var80099a60[0].samples, var80099a60[0].unk1e4, var80099a60[0].unk1e0);
	}

	if (func000150c4() && var8005eec0 && contGetNumSamples() <= 0) {
		func000150e8();

#if VERSION >= VERSION_NTSC_FINAL
		func00014238();
		func00015144();
		func00014058(&var80099a60[0]);
#else
		func00015144();
		func00014058(&var80099a60[0]);
		func00014238();
#endif
	}
}

const char var700540b4[] = "JOY : g_EnableCyclicPolling=%d";
const char var700540d4[] = "JOY : g_JoyReCheckInterval=%d";
const char var700540f4[] = "JOY : g_JoyReCheckEventIn=%d";
const char var70054114[] = "JOY : g_JoyRecheckDone=%d";
const char var70054130[] = "osContStartReadData -> Failed - CONT_NO_RESPONSE_ERROR\n";
const char var70054168[] = "osContStartReadData -> Failed - CONT_OVERRUN_ERROR\n";
const char var7005419c[] = "joyTickRetrace:joy%derrno%d->%d\n";
const char var700541c0[] = "joyTickRetrace:joy%derrno%d->%d\n";

s32 contStartReadData(OSMesgQueue *mq)
{
	return osContStartReadData(mq);
}

void contReadData(void)
{
	s32 index = (var80099a60[0].unk1e8 + 1) % 20;

	if (index == var80099a60[0].unk1e4) {
		// If the sample queue is full, don't overwrite the oldest sample.
		// Instead, overwrite the most recent.
		index = var80099a60[0].unk1e8;
	}

	osContGetReadData(var80099a60[0].samples[index].pads);

	var80099a60[0].unk1e8 = index;
	var80099a60[0].unk1ec = (var80099a60[0].unk1e8 + 19) % 20;
}

void contPoll(void)
{
	OSMesg msg;
	s8 i;

	if (osRecvMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK) == 0) {
		if (g_ContBusy) {
			osRecvMesg(&var80099e78, &msg, OS_MESG_BLOCK);

			g_ContBusy = false;
			contReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno == 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno != 0)
						|| (var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno != 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno == 0)) {
					func00013e84();
					break;
				}
			}
		}

		osSendMesg(&var80099ee0, &msg, OS_MESG_NOBLOCK);

		var8005ee68++;

		contCheckPfs(0);
		return;
	}

	if (osRecvMesg(&var80099f00, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			contStartReadData(&var80099e78);
			g_ContBusy = true;
		}

		osSendMesg(&var80099f20, &msg, OS_MESG_NOBLOCK);
		return;
	}

	if (g_ContInitDone) {
		if (var8005ee68) {
			contCheckPfs(0);
			return;
		}

		if (osRecvMesg(&var80099e78, &msg, OS_MESG_NOBLOCK) == 0) {
			static s32 count = 0;

			g_ContBusy = false;
			contReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno == 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno != 0)
						|| (var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno != 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno == 0)) {
					func00013e84();
					break;
				}
			}

			func00014238();
			contCheckPfs(0);

			contStartReadData(&var80099e78);
			g_ContBusy = true;

			count++;

			if (count >= 60) {
				s32 i;

				for (i = 0; i < 4; i++) {
					if (var8005ee6c[i] || var8005ee7c[i] || var8005ee8c[i] || var8005ee9c[i]) {
						var8005ee6c[i] = 0;
						var8005ee7c[i] = 0;
						var8005ee8c[i] = 0;
						var8005ee9c[i] = 0;
					}
				}

				count = 0;
			}
		}
	}
}

void func00014810(bool value)
{
	var8005eec0 = value;
}

s32 contGetNumSamples(void)
{
	return (var8005ee60->unk1e0 - var8005ee60->unk1e4 + 20) % 20;
}

s32 func00014848(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee6c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->unk1e4 + samplenum + 1) % 20].pads[contpadnum].stick_x;
}

s32 func00014904(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->unk1e4 + samplenum + 1) % 20].pads[contpadnum].stick_y;
}

s32 func000149c0(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->unk1e4 + samplenum) % 20].pads[contpadnum].stick_y;
}

u16 func00014a78(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	button = var8005ee60->samples[(var8005ee60->unk1e4 + samplenum + 1) % 20].pads[contpadnum].button;

	return button & mask;
}

u16 func00014b50(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button1;
	u16 button2;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee9c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	button1 = var8005ee60->samples[(var8005ee60->unk1e4 + samplenum + 1) % 20].pads[contpadnum].button;
	button2 = var8005ee60->samples[(var8005ee60->unk1e4 + samplenum) % 20].pads[contpadnum].button;

	return (button1 & ~button2) & mask;
}

s32 func00014c98(u32 *arg0, s8 contpadnum, u16 mask)
{
	s32 count = 0;
	s32 index = 0;
	s32 i;
	u16 button;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	i = (var8005ee60->unk1e4 + 1) % 20;

	while (true) {
		if (arg0 == NULL || arg0[index]) {
			button = var8005ee60->samples[i].pads[contpadnum].button;

			if (button & mask) {
				count++;
			}
		}

		if (i == var8005ee60->unk1e0) {
			break;
		}

		i = (i + 1) % 20;
		index++;
	}

	return count;
}

s8 contGetStickX(s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee6c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->unk1e0].pads[contpadnum].stick_x;
}

s8 contGetStickY(s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->unk1e0].pads[contpadnum].stick_y;
}

u16 contGetButtons(s8 contpadnum, u16 mask)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->unk1e0].pads[contpadnum].button & mask;
}

u16 func00015020(s8 contpadnum, u16 mask)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee9c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->unk1f0[contpadnum] & mask;
}

s32 func000150c4(void)
{
	return var8005eebc ? false : true;
}

void func000150e8(void)
{
	OSMesg msg;

	if (var8005eebc == 0) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);
	}

	var8005eebc++;
}

void func00015144(void)
{
	OSMesg msg;

	var8005eebc--;

	if (var8005eebc == 0) {
		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);
	}
}

void func0001519c(void)
{
	s32 i;

	osCreateMesgQueue(&var80099e78, &var80099e90, 10);
	osSetEventMesg(OS_EVENT_SI, &var80099e78, 0);

	for (i = 0; i < 4; i++) {
		if (!func0004f854(&var80099e78, (i == 4 ? NULL : &var800a3180[i]), i)) {
			func0004f5e0((i == 4 ? NULL : &var800a3180[i]), 0);
			func0004f5e0((i == 4 ? NULL : &var800a3180[i]), 0);
			func0004f5e0((i == 4 ? NULL : &var800a3180[i]), 0);
		}
	}
}

void func000152d0(s8 playernum, s32 *arg1, s32 *arg2)
{
	if (g_Vars.normmplayerisrunning) {
		*arg1 = g_Vars.playerstats[playernum].mpindex;
		*arg2 = -1;
		return;
	}

	*arg1 = playernum;

	if (g_MpPlayers[g_Vars.playerstats[playernum].mpindex].base.controlmode >= CONTROLMODE_21) {
		*arg2 = PLAYERCOUNT() + playernum;
		return;
	}

	*arg2 = -1;
}

void func000153c4(s8 arg0, s32 arg1)
{
	u32 stack;

	if (arg0 != 4) {
		if (var800a2380[arg0].unk000 != 2 && var800a2380[arg0].unk000 != 3) {
			if (arg1) {
				func000150e8();
			}

			if (func0004f854(&var80099e78, arg0 == 4 ? NULL : &var800a3180[arg0], arg0) == 0) {
				func0004f5e0(arg0 == 4 ? NULL : &var800a3180[arg0], 0);
				func0004f5e0(arg0 == 4 ? NULL : &var800a3180[arg0], 0);
				func0004f5e0(arg0 == 4 ? NULL : &var800a3180[arg0], 0);
			}

			if (arg1) {
				func00015144();
			}

			if (var800a2380[arg0].unk004 != 6 && var800a2380[arg0].unk004 != 7) {
				var800a2380[arg0].unk004 =  5;
			}

			var800a2380[arg0].unk2b4 = -1;
		}
	}

	if (arg0) {
		// empty
	}
}

s32 func000155b4(s8 index)
{
	return var800a2380[index].unk010;
}

s32 func000155f4(s8 index)
{
	return func000155b4(index);
}

void func0001561c(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (var800a2380[i].unk010 == 11 && var800a2380[i].unk000 == 1) {
			switch (var800a2380[i].unk004) {
			case 3:
				var800a2380[i].unk004 = 4;
				func0004f5e0(i == 4 ? NULL : &var800a3180[i], 1);
				break;
			case 4:
				if (var800a2380[i].unk284 != -1) {
					if (var800a2380[i].unk28c == 0) {
						func0004f5e0(i == 4 ? NULL : &var800a3180[i], 1);
					} else if (var800a2380[i].unk284 == var800a2380[i].unk28c) {
						func0004f5e0(i == 4 ? NULL : &var800a3180[i], 0);
					}

					var800a2380[i].unk28c++;

					if (var800a2380[i].unk288 == var800a2380[i].unk28c) {
						var800a2380[i].unk28c = 0;
					}
				}

				var800a2380[i].unk2b4--;

				if (var800a2380[i].unk2b4 < 0) {
					var800a2380[i].unk004 = 5;
				}
				break;
			case 5:
				var800a2380[i].unk004 = 2;
				func0004f5e0(i == 4 ? NULL : &var800a3180[i], 0);
				break;
			case 6:
				func0004f5e0(i == 4 ? NULL : &var800a3180[i], 0);
				var800a2380[i].unk004 = 7;
				break;
			case 8:
				var800a2380[i].unk004 = 2;
				var800a2380[i].unk2b4 = -1;
				break;
			}
		}
	}
}
