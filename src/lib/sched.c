#include <ultra64.h>
#include "lib/boot.h"
#include "lib/sched.h"
#include "constants.h"
#include "game/menugfx.h"
#include "bss.h"
#include "lib/audiomgr.h"
#include "lib/crash.h"
#include "lib/reset.h"
#include "lib/rzip.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/pimgr.h"
#include "lib/profile.h"
#include "lib/lib_48150.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

/*
 * OSScTask state
 */
#define OS_SC_YIELD             0x0010  /* set if yield requested       */
#define OS_SC_YIELDED           0x0020  /* set if yield completed       */

OSSched g_Sched;
OSViMode var8008dcc0[2];
OSViMode *var8008dd60[2];
OSViMode var8008dd68[2];
s32 var8008de0c;
s32 var8008de10;
OSTimer g_SchedRspTimer;
u8 g_ScBottleneck = ' ';

#ifdef DEBUG
bool g_SchedCrashedUnexpectedly = false;
bool g_SchedCrashEnable1 = false;
bool g_SchedCrashEnable2 = false;
u32 g_SchedCrashRenderInterval = 45000000;
u32 g_SchedCrashLastRendered = 0;
#endif

s32 var8005ce74 = 0;
f32 g_ViXScalesBySlot[2] = {1, 1};
f32 g_ViYScalesBySlot[2] = {1, 1};
u32 g_SchedViModesPending[2] = {false, false};
s32 g_ViUnblackTimer = 4;
s32 g_ViShakeDirection = 1;
s32 g_ViShakeIntensity = 0;
s32 g_ViShakeTimer = 0;
bool g_SchedIsFirstTask = true;

#ifdef DEBUG
void schedSetCrashEnable1(bool enable)
{
	g_SchedCrashEnable1 = enable;
}

void schedSetCrashedUnexpectedly(bool enable)
{
	g_SchedCrashedUnexpectedly = enable;
}

void schedSetCrashEnable2(bool enable)
{
	g_SchedCrashEnable2 = enable;
}

void schedSetCrashRenderInterval(u32 cycles)
{
	g_SchedCrashRenderInterval = cycles;
}

void schedRenderCrashOnBuffer(void *framebuffer)
{
	if ((g_SchedCrashEnable2 && g_SchedCrashEnable1) || g_SchedCrashedUnexpectedly) {
		crashRenderFrame(framebuffer);
		g_SchedCrashLastRendered = osGetCount();
	}
}

extern u16 *g_FrameBuffers[3];

void schedRenderCrashPeriodically(u32 framecount)
{
	if ((framecount & 0xf) == 0 && ((g_SchedCrashEnable2 && g_SchedCrashEnable1) || g_SchedCrashedUnexpectedly)) {
		if (osGetCount() - g_SchedCrashLastRendered > g_SchedCrashRenderInterval) {
			crashRenderFrame(g_FrameBuffers[0]);
			crashRenderFrame(g_FrameBuffers[1]);
			crashRenderFrame(g_FrameBuffers[2]);
		}
	}
}

void schedInitCrashLastRendered(void)
{
	g_SchedCrashLastRendered = osGetCount();
}
#endif

static void __scExec(OSSched *sc, OSScTask *t)
{
	if (t->list.t.type == M_GFXTASK) {
		if ((t->state & OS_SC_YIELD) == 0) {
			profileHandleRspEvent(RSPEVENT_GFX_START);
		}
	} else {
		osWritebackDCacheAll();
		profileHandleRspEvent(RSPEVENT_AUD_START);
	}

	t->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);

	osSpTaskLoad(&t->list);
	osSpTaskStartGo(&t->list);

	sc->curRSPTask = t;

	if (t->state & OS_SC_NEEDS_RDP) {
		sc->curRDPTask = t;
	}
}

static void __scTryDispatch(OSSched *sc)
{
	if (sc->curRSPTask == NULL) {
		if (sc->nextAudTask) {
			OSScTask *t = sc->nextAudTask;
			sc->nextAudTask = NULL;
			__scExec(sc, t);
		} else if ((sc->curRDPTask == NULL || sc->curRDPTask == sc->nextGfxTask) && sc->queuedFB == NULL) {
			OSScTask *t = sc->nextGfxTask;

			if (t) {
				sc->nextGfxTask = sc->nextGfxTask2;
				sc->nextGfxTask2 = NULL;
				__scExec(sc, t);
			}
		}
	}
}

static void __scSwap(OSSched *sc, void *framebuffer)
{
	if (g_SchedIsFirstTask) {
		osViBlack(false);
		g_SchedIsFirstTask = false;
	}

	var8005ce74 = (var8005ce74 + 1) % 2;

	if (g_SchedViModesPending[1 - var8005ce74]) {
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
			osViBlack(g_ViUnblackTimer);
			osViSetXScale(g_ViXScalesBySlot[1 - var8005ce74]);
			osViSetYScale(g_ViYScalesBySlot[1 - var8005ce74]);

#ifdef ANTIALIAS
			osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON);
#else
			osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_OFF);
#endif
		}

		g_SchedViModesPending[1 - var8005ce74] = false;
	}

	if (g_ViUnblackTimer != 0 && g_ViUnblackTimer < 4) {
		g_ViUnblackTimer--;
	}

#ifdef DEBUG
	schedRenderCrashOnBuffer(framebuffer);
#endif
	osViSwapBuffer(framebuffer);
}

static void __scTaskComplete(OSSched *sc, OSScTask *t)
{
	if (t->list.t.type == M_AUDTASK) {
		profileHandleRspEvent(RSPEVENT_AUD_FINISH);
		osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);
	} else {
		profileHandleRspEvent(RSPEVENT_GFX_FINISH);

		if (sc->scheduledFB == NULL) {
			sc->scheduledFB = t->framebuffer;
			__scSwap(sc, t->framebuffer);
		} else {
			sc->queuedFB = t->framebuffer;
		}

		osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);
	}
}

//-----------------------------------------------------------------------------\
//-- Event handlers -----------------------------------------------------------/
//----------------------------------------------------------------------------/

static void __scHandleRetrace(OSSched *sc)
{
	if (sc->scheduledFB && osViGetCurrentFramebuffer() == sc->scheduledFB) {
		if (sc->queuedFB) {
			sc->scheduledFB = sc->queuedFB;
			sc->queuedFB = NULL;
			__scSwap(sc, sc->scheduledFB);
			__scTryDispatch(sc);
		} else {
			sc->scheduledFB = NULL;
		}
	}

	sc->alt ^= 1;

	/**
	 * On every second retrace, we set a ~6ms timer to prompt the audio thread
	 * to start making another frame. When the audio task is ready, we try to
	 * give it to the RSP after the next gfx task finishes rather than yield the
	 * gfx task. But if we're at the second retrace and the previous gfx task is
	 * still not done then we must yield it.
	 */
	if (sc->alt && !g_Resetting) {
		osStopTimer(&g_SchedRspTimer);
		osSetTimer(&g_SchedRspTimer, 280000, 0, &g_AudioManager.audioFrameMsgQ, (OSMesg) OS_SC_RSP_MSG);

		if (sc->nextAudTask && sc->curRSPTask->list.t.type == M_GFXTASK) {
			osSpTaskYield();
			sc->curRSPTask->state |= OS_SC_YIELD;
		}
	}

	if (!g_Resetting) {
		vi00009ed4();
	}

	joysTick();

#ifdef DEBUG
	sc->frameCount++;
	schedRenderCrashPeriodically(sc->frameCount);
#endif

	if (sc->gfxmq) {
		osSendMesg(sc->gfxmq, (OSMesg) OS_SC_RETRACE_MSG, OS_MESG_NOBLOCK);
	}
}

static void __scHandleRSP(OSSched *sc)
{
	if (!g_Resetting) {
		OSScTask *t = sc->curRSPTask;
		sc->curRSPTask = NULL;

		if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
			t->state |= OS_SC_YIELDED;

			sc->nextGfxTask2 = sc->nextGfxTask;
			sc->nextGfxTask = t;
		} else {
			t->state &= ~OS_SC_NEEDS_RSP;

			if ((t->state & OS_SC_RCP_MASK) == 0) {
				__scTaskComplete(sc, t);
			}
		}

		__scTryDispatch(sc);
	}
}

static void __scHandleRDP(OSSched *sc)
{
	OSScTask *t;

	schedUpdatePendingArtifacts();

	if (var8005dd18 == 0) {
		if (g_MenuData.screenshottimer == 1) {
			menugfxCreateBlur();

			g_MenuData.screenshottimer = 0;
		}

		if (g_MenuData.screenshottimer >= 2) {
			g_MenuData.screenshottimer--;
		}
	}

	t = sc->curRDPTask;
	sc->curRDPTask = NULL;
	t->state &= ~OS_SC_NEEDS_RDP;

	if ((t->state & OS_SC_RCP_MASK) == 0) {
		__scTaskComplete(sc, t);
	}

	__scTryDispatch(sc);
}

static void __scMain(void *arg)
{
	void (*msg)(OSSched *sc);
	OSSched *sc = (OSSched *)arg;

	schedInitArtifacts();

	while (1) {
		osRecvMesg(&sc->interruptQ, (OSMesg *) &msg, OS_MESG_BLOCK);
		msg(sc);
	}
}

//-----------------------------------------------------------------------------\
//-- Public functions ---------------------------------------------------------/
//----------------------------------------------------------------------------/

void schedSubmitAudTask(OSSched *sc, OSScTask *t)
{
	OSPri prevpri = osGetThreadPri(0);
	osSetThreadPri(0, THREADPRI_SCHED + 1);

	if (sc->curRSPTask == NULL) {
		__scExec(sc, t);
	} else {
		t->state = OS_SC_NEEDS_RSP;
		sc->nextAudTask = t;
	}

	osSetThreadPri(0, prevpri);
}

void schedSubmitGfxTask(OSSched *sc, OSScTask *t)
{
	OSPri prevpri = osGetThreadPri(0);
	osSetThreadPri(0, THREADPRI_SCHED + 1);

	t->state = OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP;

	if (sc->curRSPTask == NULL && sc->curRDPTask == NULL && sc->queuedFB == NULL) {
		g_ScBottleneck = 'C';
		__scExec(sc, t);
	} else {
		g_ScBottleneck = sc->queuedFB ? 'V' : 'R';

		if (sc->nextGfxTask == NULL) {
			sc->nextGfxTask = t;
		} else {
			sc->nextGfxTask2 = t;
		}
	}

	osSetThreadPri(0, prevpri);
}

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, int is8mb)
{
	OSIntMask mask;

	mask = osSetIntMask(1);

	if (is8mb) {
		sc->audmq = msgQ;
	} else {
		sc->gfxmq = msgQ;
	}

	osSetIntMask(mask);
}

void osCreateScheduler(OSSched *sc, OSThread *thread, u8 mode, u32 numFields)
{
	sc->audmq = NULL;
	sc->gfxmq = NULL;
	sc->curRSPTask = NULL;
	sc->curRDPTask = NULL;
	sc->frameCount = 0;
	sc->alt = 0;
	sc->nextAudTask = NULL;
	sc->nextGfxTask = NULL;
	sc->nextGfxTask2 = NULL;
	sc->retraceMsg.type = OS_SC_RETRACE_MSG;
	sc->prenmiMsg.type = OS_SC_PRE_NMI_MSG;
	sc->thread = thread;
	sc->scheduledFB = NULL;
	sc->queuedFB = NULL;

	resetThreadCreate();

	osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);

	osCreateViManager(OS_PRIORITY_VIMGR);

	var8008de0c = osViModeTable[mode].fldRegs[0].vStart;
	var8008de10 = osViModeTable[mode].fldRegs[1].vStart;

	var8008dd60[0] = &var8008dd68[0];
	var8008dd60[1] = &var8008dd68[1];

	var8008dd68[0] = osViModeTable[mode];
	var8008dd68[1] = osViModeTable[mode];

	osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg) &__scHandleRSP);
	osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg) &__scHandleRDP);

	osViSetEvent(&sc->interruptQ, (OSMesg) &__scHandleRetrace, numFields);
#ifdef DEBUG
	schedInitCrashLastRendered();
#endif
	osCreateThread(sc->thread, THREAD_SCHED, &__scMain, sc, bootAllocateStack(THREAD_SCHED, STACKSIZE_SCHED), THREADPRI_SCHED);
	osStartThread(sc->thread);
}
