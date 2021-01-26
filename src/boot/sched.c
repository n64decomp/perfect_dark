#include <ultra64.h>
#include "boot/init.h"
#include "boot/sched.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0e0770.h"
#include "gvars/gvars.h"
#include "lib/lib_04a80.h"
#include "lib/lib_05e40.h"
#include "lib/lib_074f0.h"
#include "lib/lib_08a20.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13710.h"
#include "lib/lib_13750.h"
#include "lib/lib_13900.h"
#include "lib/lib_2fa00.h"
#include "lib/lib_48120.h"
#include "lib/lib_48150.h"
#include "lib/lib_481d0.h"
#include "lib/lib_48cd0.h"
#include "lib/lib_48dc0.h"
#include "lib/lib_48ef0.h"
#include "lib/lib_48f50.h"
#include "lib/lib_490b0.h"
#include "types.h"

void func00001b10(u32 value)
{
	var8005ce64 = value;
}

void func00001b1c(u32 value)
{
	var8005ce60 = value;
}

void func00001b28(u32 value)
{
	var8005ce68 = value;
}

void func00001b34(u32 value)
{
	var8005ce6c = value;
}

void func00001b40(u32 arg0)
{
	if ((var8005ce68 && var8005ce64) || var8005ce60) {
		func0000cf54(arg0);
		var8005ce70 = osGetCount();
	}
}

void func00001b98(u32 value)
{
	if ((value & 0xf) == 0 && ((var8005ce68 && var8005ce64) || var8005ce60)) {
		if (osGetCount() - var8005ce70 > var8005ce6c) {
			func0000cf54(var8009cac0);
			func0000cf54(var8009cac4);
		}
	}
}

void osCreateLog(void)
{
	var8005ce70 = osGetCount();
}

void osCreateScheduler(OSSched *sc, void *stack, u8 mode, u32 numFields)
{
	sc->curRSPTask = 0;
	sc->curRDPTask = 0;
	sc->clientList = 0;
	sc->frameCount = 0;
	sc->audioListHead = 0;
	sc->gfxListHead = 0;
	sc->audioListTail = 0;
	sc->gfxListTail = 0;
	sc->retraceMsg.type = OS_SC_RETRACE_MSG;
	sc->prenmiMsg.type = 5; // OS_SC_PRE_NMI_MSG
	sc->thread = stack;

	resetThreadCreate();

	osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);
	osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, OS_SC_MAX_MESGS);

	osCreateViManager(OS_PRIORITY_VIMGR);

	var8008de08 = osViModeTable[mode].comRegs.hStart;
	var8008de0c = osViModeTable[mode].fldRegs[0].vStart;
	var8008de10 = osViModeTable[mode].fldRegs[1].vStart;

	var8008dd60[0] = &var8008dd68;
	var8008dd60[1] = &var8008ddb8;

	var8008dd68 = osViModeTable[mode];
	var8008ddb8 = osViModeTable[mode];

	osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg)RSP_DONE_MSG);
	osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg)RDP_DONE_MSG);

	osViSetEvent(&sc->interruptQ, (OSMesg)VIDEO_MSG, numFields);
	osCreateLog();
	osCreateThread(sc->thread, THREAD_SCHED, &__scMain, sc, allocateStack(THREAD_SCHED, STACKSIZE_SCHED), THREADPRI_SCHED);
	osStartThread(sc->thread);
}

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next)
{
	OSIntMask mask;

	mask = osSetIntMask(1);

	c->msgQ = msgQ;
	c[1].next = next;
	c->next = sc->clientList;
	sc->clientList = c;

	osSetIntMask(mask);
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel osScRemoveClient
/*     205c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     2060:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     2064:	afa40020 */ 	sw	$a0,0x20($sp)
/*     2068:	8c8300b4 */ 	lw	$v1,0xb4($a0)
/*     206c:	afa00018 */ 	sw	$zero,0x18($sp)
/*     2070:	afa50024 */ 	sw	$a1,0x24($sp)
/*     2074:	24040001 */ 	li	$a0,0x1
/*     2078:	0c012688 */ 	jal	osSetIntMask
/*     207c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*     2080:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*     2084:	8fa50024 */ 	lw	$a1,0x24($sp)
/*     2088:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     208c:	1060000f */ 	beqz	$v1,.L000020cc
/*     2090:	00402025 */ 	move	$a0,$v0
.L00002094:
/*     2094:	5465000a */ 	bnel	$v1,$a1,.L000020c0
/*     2098:	00603025 */ 	move	$a2,$v1
/*     209c:	10c00004 */ 	beqz	$a2,.L000020b0
/*     20a0:	8fb90020 */ 	lw	$t9,0x20($sp)
/*     20a4:	8caf0000 */ 	lw	$t7,0x0($a1)
/*     20a8:	10000008 */ 	b	.L000020cc
/*     20ac:	accf0000 */ 	sw	$t7,0x0($a2)
.L000020b0:
/*     20b0:	8cb80000 */ 	lw	$t8,0x0($a1)
/*     20b4:	10000005 */ 	b	.L000020cc
/*     20b8:	af3800b4 */ 	sw	$t8,0xb4($t9)
/*     20bc:	00603025 */ 	move	$a2,$v1
.L000020c0:
/*     20c0:	8c630000 */ 	lw	$v1,0x0($v1)
/*     20c4:	1460fff3 */ 	bnez	$v1,.L00002094
/*     20c8:	00000000 */ 	nop
.L000020cc:
/*     20cc:	0c012688 */ 	jal	osSetIntMask
/*     20d0:	00000000 */ 	nop
/*     20d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     20d8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*     20dc:	03e00008 */ 	jr	$ra
/*     20e0:	00000000 */ 	nop
);
#endif

OSMesgQueue *osScGetCmdQ(OSSched *sc)
{
	return &sc->cmdQ;
}

void __scMain(void *arg)
{
    OSMesg msg = 0;
    OSSched *sc = (OSSched *)arg;
    int done = 0;

	func00002400();

	while (!done) {
		osRecvMesg(&sc->interruptQ, (OSMesg *)&msg, OS_MESG_BLOCK);

		switch ((int) msg) {
		case VIDEO_MSG:
			if (osViGetCurrentFramebuffer() == osViGetNextFramebuffer()) {
				osDpSetStatus(4);
			}

			func00002078(sc);
			__scHandleRetrace(sc);
			break;
		case RSP_DONE_MSG:
			__scHandleRSP(sc);
			break;
		case RDP_DONE_MSG:
			osDpSetStatus(8);
			__scHandleRDP(sc);
			__scHandleRetrace(sc);
			break;
		}
	}
}

void __scHandleRetraceViaPri(OSSched *sc, OSScTask *t)
{
	s32 state;
	OSScTask *sp = 0;
	OSScTask *dp = 0;

	OSPri prevpri = osGetThreadPri(0);
	osSetThreadPri(0, 31);

	__scAppendList(sc, t);

	if (sc->doAudio && sc->curRSPTask) {
		__scYield(sc);
	} else {
		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp);
		}
	}

	osSetThreadPri(0, prevpri);
}

void func00002078(OSSched *sc)
{
	sc->frameCount++;

	if (var8005ced0 == 0 && ((sc->frameCount & 1) != 0 || IS4MB())) {
		osStopTimer(&var8008de18);
		osSetTimer(&var8008de18, 280000, 0, func00009118(), &var8005cea8);
	}

	if (var8005ced0 == 0) {
		func00009ed4();
	}

	contPoll();
	func0000fe18();
	func00001b98(sc->frameCount);
}

#if VERSION >= VERSION_NTSC_1_0
void __scHandleRetrace(OSSched *sc)
{
	s32         state;
	OSScTask    *rspTask = 0;
	OSScClient  *client;
	OSScTask    *sp = 0;
	OSScTask    *dp = 0;

	func00009a88();

	while (osRecvMesg(&sc->cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) != -1) {
		__scAppendList(sc, rspTask);
	}

	if (sc->doAudio && sc->curRSPTask) {
		__scYield(sc);
	} else {
		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp);
		}
	}

	for (client = sc->clientList; client != 0; client = client->next) {
		if ((*((s32*)client + 2) == 0) || ((sc->frameCount & 1) == 0)) {
			osSendMesg(client->msgQ, (OSMesg) &sc->retraceMsg, OS_MESG_NOBLOCK);
		}
	}

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *end = (s32 *)&allocateStack;
		s32 *ptr = (s32 *)&func000016cc;
		s32 i;

		while (ptr < end) {
			checksum ^= *ptr;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			u8 *addr = var80095210;

			for (i = 0; i < 40; i++) {
				addr[4 + i] = 0xff;
			}
		}
	}
#endif
}
#endif

void __scHandleRSP(OSSched *sc)
{
	OSScTask *t, *sp = 0, *dp = 0;
	s32 state;

	if (!var8005ced0) {
		t = sc->curRSPTask;
		sc->curRSPTask = 0;

		func00009aa0(0x10001);

		if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
			t->state |= OS_SC_YIELDED;

			if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
				t->next = sc->gfxListHead;
				sc->gfxListHead = t;

				if (sc->gfxListTail == 0) {
					sc->gfxListTail = t;
				}
			}
		} else {
			t->state &= ~OS_SC_NEEDS_RSP;
			__scTaskComplete(sc, t);
		}

		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp);
		}
	}
}

u32 *func000023f4(void)
{
	return &var8008de38;
}

GLOBAL_ASM(
glabel func00002400
/*     2400:	3c038009 */ 	lui	$v1,%hi(var8008de48)
/*     2404:	3c058009 */ 	lui	$a1,%hi(var8008fa68)
/*     2408:	3c078009 */ 	lui	$a3,%hi(var8008fa68+0x3)
/*     240c:	24e7fa6b */ 	addiu	$a3,$a3,%lo(var8008fa68+0x3)
/*     2410:	24a5fa68 */ 	addiu	$a1,$a1,%lo(var8008fa68)
/*     2414:	2463de48 */ 	addiu	$v1,$v1,%lo(var8008de48)
/*     2418:	24060078 */ 	addiu	$a2,$zero,0x78
.L0000241c:
/*     241c:	00001025 */ 	or	$v0,$zero,$zero
/*     2420:	00602025 */ 	or	$a0,$v1,$zero
.L00002424:
/*     2424:	24420001 */ 	addiu	$v0,$v0,0x1
/*     2428:	24840014 */ 	addiu	$a0,$a0,0x14
/*     242c:	1446fffd */ 	bne	$v0,$a2,.L00002424
/*     2430:	a480ffec */ 	sh	$zero,-0x14($a0)
/*     2434:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     2438:	24630960 */ 	addiu	$v1,$v1,0x960
/*     243c:	14a7fff7 */ 	bne	$a1,$a3,.L0000241c
/*     2440:	a0a0ffff */ 	sb	$zero,-0x1($a1)
/*     2444:	03e00008 */ 	jr	$ra
/*     2448:	00000000 */ 	nop
);

struct bootbufferthing *func0000244c(void)
{
	return &var8008de48[var8008fa6c];
}

struct bootbufferthing *func00002480(void)
{
	return &var8008de48[var8008fa70];
}

struct bootbufferthing *func000024b4(void)
{
	return &var8008de48[var8008fa74];
}

void func000024e8(void)
{
	var8008fa6c = (var8008fa6c + 1) % 3;
}

void func00002510(void)
{
	var8008fa70 = (var8008fa70 + 1) % 3;
}

void func00002538(void)
{
	var8008fa74 = (var8008fa74 + 1) % 3;
}

void func00002560(void)
{
	var8008fa6c = 0;
	var8008fa70 = 1;
	var8008fa74 = 0;
}

GLOBAL_ASM(
glabel func00002580
/*     2580:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     2584:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     2588:	0c00092d */ 	jal	func000024b4
/*     258c:	00000000 */ 	nop
/*     2590:	3c0b8009 */ 	lui	$t3,%hi(var8008fa74)
/*     2594:	3c0a8009 */ 	lui	$t2,%hi(var8008fa68)
/*     2598:	254afa68 */ 	addiu	$t2,$t2,%lo(var8008fa68)
/*     259c:	256bfa74 */ 	addiu	$t3,$t3,%lo(var8008fa74)
/*     25a0:	00003825 */ 	or	$a3,$zero,$zero
/*     25a4:	00401825 */ 	or	$v1,$v0,$zero
/*     25a8:	24090960 */ 	addiu	$t1,$zero,0x960
/*     25ac:	24080001 */ 	addiu	$t0,$zero,0x1
.L000025b0:
/*     25b0:	946e0000 */ 	lhu	$t6,0x0($v1)
/*     25b4:	24e70014 */ 	addiu	$a3,$a3,0x14
/*     25b8:	11c00012 */ 	beqz	$t6,.L00002604
/*     25bc:	00000000 */ 	nop
/*     25c0:	8d6f0000 */ 	lw	$t7,0x0($t3)
/*     25c4:	8c640008 */ 	lw	$a0,0x8($v1)
/*     25c8:	014fc021 */ 	addu	$t8,$t2,$t7
/*     25cc:	93190000 */ 	lbu	$t9,0x0($t8)
/*     25d0:	94850000 */ 	lhu	$a1,0x0($a0)
/*     25d4:	5519000b */ 	bnel	$t0,$t9,.L00002604
/*     25d8:	a4650002 */ 	sh	$a1,0x2($v1)
/*     25dc:	8c64000c */ 	lw	$a0,0xc($v1)
/*     25e0:	94860000 */ 	lhu	$a2,0x0($a0)
/*     25e4:	00a6082a */ 	slt	$at,$a1,$a2
/*     25e8:	10200003 */ 	beqz	$at,.L000025f8
/*     25ec:	00000000 */ 	nop
/*     25f0:	10000004 */ 	b	.L00002604
/*     25f4:	a4650002 */ 	sh	$a1,0x2($v1)
.L000025f8:
/*     25f8:	10000002 */ 	b	.L00002604
/*     25fc:	a4660002 */ 	sh	$a2,0x2($v1)
/*     2600:	a4650002 */ 	sh	$a1,0x2($v1)
.L00002604:
/*     2604:	14e9ffea */ 	bne	$a3,$t1,.L000025b0
/*     2608:	24630014 */ 	addiu	$v1,$v1,0x14
/*     260c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     2610:	014c6821 */ 	addu	$t5,$t2,$t4
/*     2614:	0c00094e */ 	jal	func00002538
/*     2618:	a1a00000 */ 	sb	$zero,0x0($t5)
/*     261c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     2620:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     2624:	03e00008 */ 	jr	$ra
/*     2628:	00000000 */ 	nop
);

void __scHandleRDP(OSSched *sc)
{
	OSScTask *t, *sp = NULL, *dp = NULL;
	s32 state;

	if (sc->curRDPTask != NULL) {
		func00002580();

		if (var8005dd18 == 0) {
			func00002d90();
		}

		func00009aa0(0x10002);
		osDpGetCounters(&var8008de38);

		t = sc->curRDPTask;
		sc->curRDPTask = NULL;
		t->state &= ~OS_SC_NEEDS_RDP;

		__scTaskComplete(sc, t);

		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp);
		}
	}
}

OSScTask *__scTaskReady(OSScTask *t)
{
	void *a;
	void *b;

	if (t) {
		if ((func00048cd0() & 2) == 0) {
			if (osViGetCurrentFramebuffer() != osViGetNextFramebuffer()) {
				return 0;
			}
		}

		return t;
	}

	return 0;
}

GLOBAL_ASM(
glabel __scTaskComplete
/*     2768:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     276c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     2770:	afa40018 */ 	sw	$a0,0x18($sp)
/*     2774:	afa5001c */ 	sw	$a1,0x1c($sp)
/*     2778:	8caf0004 */ 	lw	$t7,0x4($a1)
/*     277c:	00001025 */ 	or	$v0,$zero,$zero
/*     2780:	31f80003 */ 	andi	$t8,$t7,0x3
/*     2784:	170000a1 */ 	bnez	$t8,.L00002a0c
/*     2788:	00000000 */ 	nop
/*     278c:	8cb90010 */ 	lw	$t9,0x10($a1)
/*     2790:	24010001 */ 	addiu	$at,$zero,0x1
/*     2794:	57210097 */ 	bnel	$t9,$at,.L000029f4
/*     2798:	8fab001c */ 	lw	$t3,0x1c($sp)
/*     279c:	8ca20008 */ 	lw	$v0,0x8($a1)
/*     27a0:	30480040 */ 	andi	$t0,$v0,0x40
/*     27a4:	11000092 */ 	beqz	$t0,.L000029f0
/*     27a8:	30490020 */ 	andi	$t1,$v0,0x20
/*     27ac:	11200090 */ 	beqz	$t1,.L000029f0
/*     27b0:	3c0a8006 */ 	lui	$t2,%hi(var8005cec8)
/*     27b4:	8d4acec8 */ 	lw	$t2,%lo(var8005cec8)($t2)
/*     27b8:	11400005 */ 	beqz	$t2,.L000027d0
/*     27bc:	00000000 */ 	nop
/*     27c0:	0c012338 */ 	jal	func00048ce0
/*     27c4:	00002025 */ 	or	$a0,$zero,$zero
/*     27c8:	3c018006 */ 	lui	$at,%hi(var8005cec8)
/*     27cc:	ac20cec8 */ 	sw	$zero,%lo(var8005cec8)($at)
.L000027d0:
/*     27d0:	3c078006 */ 	lui	$a3,%hi(var8005ce74)
/*     27d4:	24e7ce74 */ 	addiu	$a3,$a3,%lo(var8005ce74)
/*     27d8:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*     27dc:	3c198006 */ 	lui	$t9,%hi(var8005ce8c)
/*     27e0:	2739ce8c */ 	addiu	$t9,$t9,%lo(var8005ce8c)
/*     27e4:	256c0001 */ 	addiu	$t4,$t3,0x1
/*     27e8:	05810004 */ 	bgez	$t4,.L000027fc
/*     27ec:	318d0001 */ 	andi	$t5,$t4,0x1
/*     27f0:	11a00002 */ 	beqz	$t5,.L000027fc
/*     27f4:	00000000 */ 	nop
/*     27f8:	25adfffe */ 	addiu	$t5,$t5,-2
.L000027fc:
/*     27fc:	000d7880 */ 	sll	$t7,$t5,0x2
/*     2800:	000fc023 */ 	negu	$t8,$t7
/*     2804:	03193021 */ 	addu	$a2,$t8,$t9
/*     2808:	8cce0000 */ 	lw	$t6,0x0($a2)
/*     280c:	24080001 */ 	addiu	$t0,$zero,0x1
/*     2810:	aced0000 */ 	sw	$t5,0x0($a3)
/*     2814:	11c00068 */ 	beqz	$t6,.L000029b8
/*     2818:	010d1823 */ 	subu	$v1,$t0,$t5
/*     281c:	00034880 */ 	sll	$t1,$v1,0x2
/*     2820:	3c028009 */ 	lui	$v0,%hi(var8008dd60)
/*     2824:	00491021 */ 	addu	$v0,$v0,$t1
/*     2828:	00035080 */ 	sll	$t2,$v1,0x2
/*     282c:	8c42dd60 */ 	lw	$v0,%lo(var8008dd60)($v0)
/*     2830:	01435021 */ 	addu	$t2,$t2,$v1
/*     2834:	3c0b8009 */ 	lui	$t3,%hi(var8008dcc0)
/*     2838:	256bdcc0 */ 	addiu	$t3,$t3,%lo(var8008dcc0)
/*     283c:	000a5100 */ 	sll	$t2,$t2,0x4
/*     2840:	014b2021 */ 	addu	$a0,$t2,$t3
/*     2844:	8c8d0008 */ 	lw	$t5,0x8($a0)
/*     2848:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*     284c:	558d0015 */ 	bnel	$t4,$t5,.L000028a4
/*     2850:	3c040008 */ 	lui	$a0,0x8
/*     2854:	8c4f0020 */ 	lw	$t7,0x20($v0)
/*     2858:	8c980020 */ 	lw	$t8,0x20($a0)
/*     285c:	55f80011 */ 	bnel	$t7,$t8,.L000028a4
/*     2860:	3c040008 */ 	lui	$a0,0x8
/*     2864:	8c59002c */ 	lw	$t9,0x2c($v0)
/*     2868:	8c8e002c */ 	lw	$t6,0x2c($a0)
/*     286c:	572e000d */ 	bnel	$t9,$t6,.L000028a4
/*     2870:	3c040008 */ 	lui	$a0,0x8
/*     2874:	8c480040 */ 	lw	$t0,0x40($v0)
/*     2878:	8c890040 */ 	lw	$t1,0x40($a0)
/*     287c:	55090009 */ 	bnel	$t0,$t1,.L000028a4
/*     2880:	3c040008 */ 	lui	$a0,0x8
/*     2884:	8c4a0028 */ 	lw	$t2,0x28($v0)
/*     2888:	8c8b0028 */ 	lw	$t3,0x28($a0)
/*     288c:	554b0005 */ 	bnel	$t2,$t3,.L000028a4
/*     2890:	3c040008 */ 	lui	$a0,0x8
/*     2894:	8c4c003c */ 	lw	$t4,0x3c($v0)
/*     2898:	8c8d003c */ 	lw	$t5,0x3c($a0)
/*     289c:	118d0045 */ 	beq	$t4,$t5,.L000029b4
/*     28a0:	3c040008 */ 	lui	$a0,0x8
.L000028a4:
/*     28a4:	0c012194 */ 	jal	osSetIntMask
/*     28a8:	34840401 */ 	ori	$a0,$a0,0x401
/*     28ac:	3c0f8006 */ 	lui	$t7,%hi(var8005ce74)
/*     28b0:	8defce74 */ 	lw	$t7,%lo(var8005ce74)($t7)
/*     28b4:	24180001 */ 	addiu	$t8,$zero,0x1
/*     28b8:	3c098009 */ 	lui	$t1,%hi(var8008dcc0)
/*     28bc:	030f1823 */ 	subu	$v1,$t8,$t7
/*     28c0:	00034080 */ 	sll	$t0,$v1,0x2
/*     28c4:	01034021 */ 	addu	$t0,$t0,$v1
/*     28c8:	00084100 */ 	sll	$t0,$t0,0x4
/*     28cc:	0003c880 */ 	sll	$t9,$v1,0x2
/*     28d0:	2529dcc0 */ 	addiu	$t1,$t1,%lo(var8008dcc0)
/*     28d4:	3c0e8009 */ 	lui	$t6,%hi(var8008dd60)
/*     28d8:	01d97021 */ 	addu	$t6,$t6,$t9
/*     28dc:	01095021 */ 	addu	$t2,$t0,$t1
/*     28e0:	254c0048 */ 	addiu	$t4,$t2,0x48
/*     28e4:	8dcedd60 */ 	lw	$t6,%lo(var8008dd60)($t6)
.L000028e8:
/*     28e8:	8d410000 */ 	lw	$at,0x0($t2)
/*     28ec:	254a000c */ 	addiu	$t2,$t2,12
/*     28f0:	25ce000c */ 	addiu	$t6,$t6,12
/*     28f4:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     28f8:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*     28fc:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     2900:	8d41fffc */ 	lw	$at,-0x4($t2)
/*     2904:	154cfff8 */ 	bne	$t2,$t4,.L000028e8
/*     2908:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     290c:	8d410000 */ 	lw	$at,0x0($t2)
/*     2910:	00402025 */ 	or	$a0,$v0,$zero
/*     2914:	adc10000 */ 	sw	$at,0x0($t6)
/*     2918:	8d4c0004 */ 	lw	$t4,0x4($t2)
/*     291c:	0c012194 */ 	jal	osSetIntMask
/*     2920:	adcc0004 */ 	sw	$t4,0x4($t6)
/*     2924:	3c0d8006 */ 	lui	$t5,%hi(var8005ce74)
/*     2928:	8dadce74 */ 	lw	$t5,%lo(var8005ce74)($t5)
/*     292c:	3c048009 */ 	lui	$a0,%hi(var8008dd60+0x4)
/*     2930:	000dc080 */ 	sll	$t8,$t5,0x2
/*     2934:	00187823 */ 	negu	$t7,$t8
/*     2938:	008f2021 */ 	addu	$a0,$a0,$t7
/*     293c:	0c012354 */ 	jal	func00048d50
/*     2940:	8c84dd64 */ 	lw	$a0,%lo(var8008dd60+0x4)($a0)
/*     2944:	3c048006 */ 	lui	$a0,%hi(var8005ce90+0x3)
/*     2948:	0c012338 */ 	jal	func00048ce0
/*     294c:	9084ce93 */ 	lbu	$a0,%lo(var8005ce90+0x3)($a0)
/*     2950:	3c198006 */ 	lui	$t9,%hi(var8005ce74)
/*     2954:	8f39ce74 */ 	lw	$t9,%lo(var8005ce74)($t9)
/*     2958:	3c018006 */ 	lui	$at,%hi(var8005ce7c)
/*     295c:	00194080 */ 	sll	$t0,$t9,0x2
/*     2960:	00084823 */ 	negu	$t1,$t0
/*     2964:	00290821 */ 	addu	$at,$at,$t1
/*     2968:	0c012370 */ 	jal	func00048dc0
/*     296c:	c42cce7c */ 	lwc1	$f12,%lo(var8005ce7c)($at)
/*     2970:	3c0b8006 */ 	lui	$t3,%hi(var8005ce74)
/*     2974:	8d6bce74 */ 	lw	$t3,%lo(var8005ce74)($t3)
/*     2978:	3c018006 */ 	lui	$at,%hi(var8005ce84)
/*     297c:	000b6080 */ 	sll	$t4,$t3,0x2
/*     2980:	000c5023 */ 	negu	$t2,$t4
/*     2984:	002a0821 */ 	addu	$at,$at,$t2
/*     2988:	0c0123bc */ 	jal	func00048ef0
/*     298c:	c42cce84 */ 	lwc1	$f12,%lo(var8005ce84)($at)
/*     2990:	0c0123d4 */ 	jal	func00048f50
/*     2994:	24040042 */ 	addiu	$a0,$zero,0x42
/*     2998:	3c0e8006 */ 	lui	$t6,%hi(var8005ce74)
/*     299c:	8dcece74 */ 	lw	$t6,%lo(var8005ce74)($t6)
/*     29a0:	3c0f8006 */ 	lui	$t7,%hi(var8005ce8c)
/*     29a4:	25efce8c */ 	addiu	$t7,$t7,%lo(var8005ce8c)
/*     29a8:	000e6880 */ 	sll	$t5,$t6,0x2
/*     29ac:	000dc023 */ 	negu	$t8,$t5
/*     29b0:	030f3021 */ 	addu	$a2,$t8,$t7
.L000029b4:
/*     29b4:	acc00000 */ 	sw	$zero,0x0($a2)
.L000029b8:
/*     29b8:	3c028006 */ 	lui	$v0,%hi(var8005ce90)
/*     29bc:	8c42ce90 */ 	lw	$v0,%lo(var8005ce90)($v0)
/*     29c0:	10400005 */ 	beqz	$v0,.L000029d8
/*     29c4:	28410003 */ 	slti	$at,$v0,0x3
/*     29c8:	10200003 */ 	beqz	$at,.L000029d8
/*     29cc:	2459ffff */ 	addiu	$t9,$v0,-1
/*     29d0:	3c018006 */ 	lui	$at,%hi(var8005ce90)
/*     29d4:	ac39ce90 */ 	sw	$t9,%lo(var8005ce90)($at)
.L000029d8:
/*     29d8:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*     29dc:	0c0006d0 */ 	jal	func00001b40
/*     29e0:	8d04000c */ 	lw	$a0,0xc($t0)
/*     29e4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*     29e8:	0c01242c */ 	jal	func000490b0
/*     29ec:	8d24000c */ 	lw	$a0,0xc($t1)
.L000029f0:
/*     29f0:	8fab001c */ 	lw	$t3,0x1c($sp)
.L000029f4:
/*     29f4:	24060001 */ 	addiu	$a2,$zero,0x1
/*     29f8:	8d640050 */ 	lw	$a0,0x50($t3)
/*     29fc:	0c012238 */ 	jal	osSendMesg
/*     2a00:	8d650054 */ 	lw	$a1,0x54($t3)
/*     2a04:	10000001 */ 	b	.L00002a0c
/*     2a08:	24020001 */ 	addiu	$v0,$zero,0x1
.L00002a0c:
/*     2a0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     2a10:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     2a14:	03e00008 */ 	jr	$ra
/*     2a18:	00000000 */ 	nop
);

void __scAppendList(OSSched *sc, OSScTask *t)
{
	long type = t->list.t.type;

	if (type == M_AUDTASK) {
		if (sc->audioListTail) {
			sc->audioListTail->next = t;
		} else {
			sc->audioListHead = t;
		}

		sc->audioListTail = t;
		sc->doAudio = 1;
	} else {
		if (sc->gfxListTail) {
			sc->gfxListTail->next = t;
		} else {
			sc->gfxListHead = t;
		}

		sc->gfxListTail = t;
	}

	t->next = NULL;
	t->state = t->flags & OS_SC_RCP_MASK;
}

void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp)
{
	if (sp) {
		if (sp->list.t.type == M_AUDTASK) {
			osWritebackDCacheAll();
		}

		if (sp->list.t.type != M_AUDTASK && (sp->state & OS_SC_YIELD) == 0) {
			osDpSetStatus(0x3c0);
		}

		if (sp->list.t.type == M_AUDTASK) {
			func00009aa0(0x30001);
		} else {
			func00009aa0(0x40001);
			func00009aa0(0x20002);
		}

		sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);

		osSpTaskLoad(&sp->list);
		osSpTaskStartGo(&sp->list);

		sc->curRSPTask = sp;

		if (sp->list.t.type != M_AUDTASK) {
			sc->curRDPTask = dp;
		}
	}
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00002d68nb
/*     2d68:	8c8300c8 */ 	lw	$v1,0xc8($a0)
/*     2d6c:	00001025 */ 	move	$v0,$zero
/*     2d70:	10600005 */ 	beqz	$v1,.L00002d88
/*     2d74:	00000000 */ 	nop
/*     2d78:	8c620010 */ 	lw	$v0,0x10($v1)
/*     2d7c:	384e0002 */ 	xori	$t6,$v0,0x2
/*     2d80:	03e00008 */ 	jr	$ra
/*     2d84:	2dc20001 */ 	sltiu	$v0,$t6,0x1
.L00002d88:
/*     2d88:	03e00008 */ 	jr	$ra
/*     2d8c:	00000000 */ 	nop
);
#endif

void __scYield(OSSched *sc)
{
	if (sc->curRSPTask->list.t.type == M_GFXTASK) {
		sc->curRSPTask->state |= 0x0010;
		osSpTaskYield();
	} else {
		// empty
	}
}

s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP)
{
	s32 avail = availRCP;
	OSScTask *gfx = sc->gfxListHead;
	OSScTask *audio = sc->audioListHead;

	if (sc->doAudio && (avail & OS_SC_SP)) {
		if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK)) {
			*sp = gfx;
			avail &= ~OS_SC_SP;
		} else {
			*sp = audio;
			avail &= ~OS_SC_SP;
			sc->doAudio = 0;
			sc->audioListHead = sc->audioListHead->next;

			if (sc->audioListHead == NULL) {
				sc->audioListTail = NULL;
			}
		}
	} else {
		if (__scTaskReady(gfx)) {
			switch (gfx->flags & OS_SC_TYPE_MASK) {
			case OS_SC_XBUS:
				if (gfx->state & OS_SC_YIELDED) {
					if (avail & OS_SC_SP) {
						*sp = gfx;
						avail &= ~OS_SC_SP;

						if (gfx->state & OS_SC_DP) {
							*dp = gfx;
							avail &= ~OS_SC_DP;

							if (avail & OS_SC_DP == 0) {
								assert(sc->curRDPTask == gfx);
							}
						}

						sc->gfxListHead = sc->gfxListHead->next;

						if (sc->gfxListHead == NULL) {
							sc->gfxListTail = NULL;
						}
					}
				} else {
					if (avail == (OS_SC_SP | OS_SC_DP)) {
						*sp = *dp = gfx;
						avail &= ~(OS_SC_SP | OS_SC_DP);
						sc->gfxListHead = sc->gfxListHead->next;

						if (sc->gfxListHead == NULL) {
							sc->gfxListTail = NULL;
						}
					}
				}
				break;
			case OS_SC_DRAM:
			case OS_SC_DP_DRAM:
			case OS_SC_DP_XBUS:
				if (gfx->state & OS_SC_SP) {
					if (avail & OS_SC_SP) {
						*sp = gfx;
						avail &= ~OS_SC_SP;
					}
				} else if (gfx->state & OS_SC_DP) {
					if (avail & OS_SC_DP) {
						*dp = gfx;
						avail &= ~OS_SC_DP;
						sc->gfxListHead = sc->gfxListHead->next;

						if (sc->gfxListHead == NULL) {
							sc->gfxListTail = NULL;
						}
					}
				}
				break;
			case OS_SC_SP_DRAM:
			case OS_SC_SP_XBUS:
			default:
				break;
			}
		}
	}

	if (avail != availRCP) {
		avail = __scSchedule(sc, sp, dp, avail);
	}

	return avail;
}

void func00002d90(void)
{
	if (g_MenuData.unk016 == 1) {
		if (IS8MB()) {
			func0f0e0770();
		}

		g_MenuData.unk016 = 0;
	}

	if (g_MenuData.unk016 >= 2) {
		g_MenuData.unk016--;
	}
}
