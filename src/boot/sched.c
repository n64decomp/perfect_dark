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
#include "lib/audiomgr.h"
#include "lib/lib_074f0.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13710.h"
#include "lib/lib_13750.h"
#include "lib/lib_2fa00.h"
#include "lib/lib_48150.h"
#include "lib/lib_48cd0.h"
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

void func00001b40(void *framebuffer)
{
	if ((var8005ce68 && var8005ce64) || var8005ce60) {
		func0000cf54(framebuffer);
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

	var8008dd60[0] = &var8008dd68[0];
	var8008dd60[1] = &var8008dd68[1];

	var8008dd68[0] = osViModeTable[mode];
	var8008dd68[1] = osViModeTable[mode];

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

	bbufResetBuffers();

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
		osSetTimer(&var8008de18, 280000, 0, amgr0009118(), &var8005cea8);
	}

	if (var8005ced0 == 0) {
		func00009ed4();
	}

	contPoll();
	func0000fe18();
	func00001b98(sc->frameCount);
}

//#if VERSION >= VERSION_NTSC_1_0
#if VERSION >= 0
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
		s32 *ptr = (s32 *)&init;
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

void bbufResetBuffers(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 120; j++) {
			g_BootBuffers[i].unk00[j].unk00 = 0;
		}

		g_BootBufferDirtyIndexes[i] = 0;
	}
}

struct bootbufferthing *bbufGetIndex0Buffer(void)
{
	return &g_BootBuffers[g_BootBufferIndex0];
}

struct bootbufferthing *bbufGetIndex1Buffer(void)
{
	return &g_BootBuffers[g_BootBufferIndex1];
}

struct bootbufferthing *bbufGetIndex2Buffer(void)
{
	return &g_BootBuffers[g_BootBufferIndex2];
}

void bbufIncIndex0(void)
{
	g_BootBufferIndex0 = (g_BootBufferIndex0 + 1) % 3;
}

void bbufIncIndex1(void)
{
	g_BootBufferIndex1 = (g_BootBufferIndex1 + 1) % 3;
}

void bbufIncIndex2(void)
{
	g_BootBufferIndex2 = (g_BootBufferIndex2 + 1) % 3;
}

void bbufResetIndexes(void)
{
	g_BootBufferIndex0 = 0;
	g_BootBufferIndex1 = 1;
	g_BootBufferIndex2 = 0;
}

void bbufUpdateIndex2Buffer(void)
{
	struct bootbufferthing *thing = bbufGetIndex2Buffer();
	s32 i;

	for (i = 0; i < 120; i++) {
		struct bootbufferthingdeep *deep = &thing->unk00[i];

		if (deep->unk00) {
			u16 *unk08 = deep->unk08;
			u16 value08 = unk08[0];

			if (g_BootBufferDirtyIndexes[g_BootBufferIndex2] == 1) {
				u16 *unk0c = deep->unk0c;
				u16 value0c = unk0c[0];

				if (value0c > value08) {
					deep->unk02 = value08;
				} else {
					deep->unk02 = value0c;
				}
			} else {
				deep->unk02 = value08;
			}
		}
	}

	g_BootBufferDirtyIndexes[g_BootBufferIndex2] = 0;

	bbufIncIndex2();
}

void __scHandleRDP(OSSched *sc)
{
	OSScTask *t, *sp = NULL, *dp = NULL;
	s32 state;

	if (sc->curRDPTask != NULL) {
		bbufUpdateIndex2Buffer();

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

s32 __scTaskComplete(OSSched *sc, OSScTask *t)
{
	if ((t->state & OS_SC_RCP_MASK) == 0) {
		if (t->list.t.type == 1
				&& (t->flags & OS_SC_SWAPBUFFER)
				&& (t->flags & OS_SC_LAST_TASK)) {
			if (var8005cec8) {
				osViBlack(0);
				var8005cec8 = 0;
			}

			var8005ce74 = (var8005ce74 + 1) % 2;

			if (var8005ce88[1 - var8005ce74] != 0) {
				if (var8008dd60[1 - var8005ce74]->comRegs.width != var8008dcc0[1 - var8005ce74].comRegs.width
						|| var8008dd60[1 - var8005ce74]->comRegs.xScale != var8008dcc0[1 - var8005ce74].comRegs.xScale
						|| var8008dd60[1 - var8005ce74]->fldRegs[0].yScale != var8008dcc0[1 - var8005ce74].fldRegs[0].yScale
						|| var8008dd60[1 - var8005ce74]->fldRegs[1].yScale != var8008dcc0[1 - var8005ce74].fldRegs[1].yScale
						|| var8008dd60[1 - var8005ce74]->fldRegs[0].origin != var8008dcc0[1 - var8005ce74].fldRegs[0].origin
						|| var8008dd60[1 - var8005ce74]->fldRegs[1].origin != var8008dcc0[1 - var8005ce74].fldRegs[1].origin) {
					s32 mask = osSetIntMask(0x80401);

					*var8008dd60[1 - var8005ce74] = var8008dcc0[1 - var8005ce74];

					osSetIntMask(mask);

					osViSetMode(var8008dd60[1 - var8005ce74]);
					osViBlack(var8005ce90);
					osViSetXScale(var8005ce78[1 - var8005ce74]);
					osViSetYScale(var8005ce80[1 - var8005ce74]);
					func00048f50(0x42);
				}

				var8005ce88[1 - var8005ce74] = 0;
			}

			if (var8005ce90 != 0 && var8005ce90 < 3) {
				var8005ce90--;
			}

			func00001b40(t->framebuffer);
			func000490b0(t->framebuffer);
		}

		osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);

		return 1;
	}

	return 0;
}

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
