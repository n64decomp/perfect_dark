#include <ultra64.h>
#include "lib/boot.h"
#include "lib/sched.h"
#include "constants.h"
#include "game/menugfx.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/audiomgr.h"
#include "lib/reset.h"
#include "lib/rzip.h"
#include "lib/crash.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/pimgr.h"
#include "lib/profile.h"
#include "lib/rmon.h"
#include "lib/lib_48150.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

/*
 * private typedefs and defines
 */
#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

/*
 * OSScTask state
 */
#define OS_SC_DP                0x0001  /* set if still needs dp        */
#define OS_SC_SP                0x0002  /* set if still needs sp        */
#define OS_SC_YIELD             0x0010  /* set if yield requested       */
#define OS_SC_YIELDED           0x0020  /* set if yield completed       */

/*
 * OSScTask->flags type identifier
 */
#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)

/*
 * private functions
 */
void __scMain(void *arg);
void __scHandleTasks(OSSched *s);
void __scHandleRSP(OSSched *s);
void __scHandleRDP(OSSched *s);
void __scAppendList(OSSched *s, OSScTask *t);
OSScTask *__scTaskReady(OSScTask *t);
s32 __scTaskComplete(OSSched *s,OSScTask *t);
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp, s32 resuming);
void __scYield(OSSched *s);
s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP);

OSViMode var8008dcc0[2];
OSViMode *var8008dd60[2];
OSViMode var8008dd68[2];
u32 var8008de08;
s32 var8008de0c;
s32 var8008de10;
u32 var8008de14;
OSTimer g_SchedRspTimer;
u32 g_SchedDpCounters[4];
struct artifact g_ArtifactLists[3][120];
u8 g_SchedSpecialArtifactIndexes[3];
s32 g_SchedWriteArtifactsIndex;
s32 g_SchedFrontArtifactsIndex;
s32 g_SchedPendingArtifactsIndex;

bool g_SchedCrashedUnexpectedly = false;
bool g_SchedCrashEnable1 = false;
bool g_SchedCrashEnable2 = false;
u32 g_SchedCrashRenderInterval = 45000000;
u32 g_SchedCrashLastRendered = 0;

s32 var8005ce74 = 0;
f32 g_ViXScalesBySlot[2] = {1, 1};
f32 g_ViYScalesBySlot[2] = {1, 1};
u32 g_SchedViModesPending[2] = {false, false};
s32 g_ViUnblackTimer = 3;
s32 g_ViShakeDirection = 1;
s32 g_ViShakeIntensity = 0;
s32 g_ViShakeTimer = 0;
u32 var8005cea0 = 0;
u32 var8005cea4 = 0;
OSScMsg g_SchedRspMsg = {OS_SC_RSP_MSG};
bool g_SchedIsFirstTask = true;

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

void schedRenderCrashPeriodically(u32 framecount)
{
	if ((framecount & 0xf) == 0 && ((g_SchedCrashEnable2 && g_SchedCrashEnable1) || g_SchedCrashedUnexpectedly)) {
		if (osGetCount() - g_SchedCrashLastRendered > g_SchedCrashRenderInterval) {
			crashRenderFrame(g_FrameBuffers[0]);
			crashRenderFrame(g_FrameBuffers[1]);
		}
	}
}

void schedInitCrashLastRendered(void)
{
	g_SchedCrashLastRendered = osGetCount();
}

void osCreateScheduler(OSSched *sc, OSThread *thread, u8 mode, u32 numFields)
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
	sc->prenmiMsg.type = OS_SC_PRE_NMI_MSG;
	sc->thread = thread;

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
	schedInitCrashLastRendered();
	osCreateThread(sc->thread, THREAD_SCHED, &__scMain, sc, bootAllocateStack(THREAD_SCHED, STACKSIZE_SCHED), THREADPRI_SCHED);
	osStartThread(sc->thread);
}

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, int is8mb)
{
	OSIntMask mask;

	mask = osSetIntMask(1);

	c->msgQ = msgQ;
	c->is8mb = is8mb;
	c->next = sc->clientList;
	sc->clientList = c;

	osSetIntMask(mask);
}

#if VERSION < VERSION_NTSC_1_0
void osScRemoveClient(OSSched *sc, OSScClient *c)
{
	OSScClient *client = sc->clientList;
	OSScClient *prev   = 0;
	OSIntMask  mask;

	mask = osSetIntMask(OS_IM_NONE);

	while (client) {
		if (client == c) {
			if (prev) {
				prev->next = c->next;
			} else {
				sc->clientList = c->next;
			}

			break;
		}

		prev = client;
		client = client->next;
	}

	osSetIntMask(mask);
}
#endif

OSMesgQueue *osScGetCmdQ(OSSched *sc)
{
	return &sc->cmdQ;
}

/**
 * The scheduler's main loop.
 *
 * Most N64 games do the task scheduling on retrace (VIDEO_MSG), but PD does
 * task scheduling both at retrace and when the RDP completes a task.
 */
void __scMain(void *arg)
{
	OSMesg msg = 0;
	OSSched *sc = (OSSched *)arg;
	int done = 0;

	schedInitArtifacts();

	while (!done) {
		osRecvMesg(&sc->interruptQ, (OSMesg *)&msg, OS_MESG_BLOCK);

		switch ((int) msg) {
		case VIDEO_MSG:
			if (osViGetCurrentFramebuffer() == osViGetNextFramebuffer()) {
				osDpSetStatus(DPC_STATUS_FLUSH);
			}

			__scHandleRetrace(sc);
			__scHandleTasks(sc);
			break;
		case RSP_DONE_MSG:
			__scHandleRSP(sc);
			break;
		case RDP_DONE_MSG:
			osDpSetStatus(DPC_STATUS_START_GCLK);
			__scHandleRDP(sc);
			__scHandleTasks(sc);
			break;
		}
	}
}

void schedAppendTasks(OSSched *sc, OSScTask *t)
{
	s32 state;
	OSScTask *sp = 0;
	OSScTask *dp = 0;

	OSPri prevpri = osGetThreadPri(0);
	osSetThreadPri(0, THREADPRI_SCHED + 1);

	__scAppendList(sc, t);

	if (sc->doAudio && sc->curRSPTask) {
		__scYield(sc);
	} else {
		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp, false);
		}
	}

	osSetThreadPri(0, prevpri);
}

/**
 * Handle a retrace (vsync) event.
 *
 * Audio tasks are scheduled based on retrace + a timer (approximately 6ms).
 * On NTSC, this is done on every second frame if 8MB, or every second frame
 * if 4MB. I guess less memory means the audio queue has to be kept smaller
 * and processed more frequently. On PAL, it's every second frame regardless.
 *
 * Controller input is polled here.
 *
 * Lastly, if there's crash information available then it will be checked and
 * rendered periodically (once every 16 retraces). I guess this makes it render
 * if the RDP has hung.
 */
void __scHandleRetrace(OSSched *sc)
{
	sc->frameCount++;

#if PAL
	if (!g_Resetting && (sc->frameCount & 1)) {
		osStopTimer(&g_SchedRspTimer);
		osSetTimer(&g_SchedRspTimer, 280000, 0, amgrGetFrameMesgQueue(), &g_SchedRspMsg);
	}
#else
	if (!g_Resetting && ((sc->frameCount & 1) || IS4MB())) {
		osStopTimer(&g_SchedRspTimer);
		osSetTimer(&g_SchedRspTimer, 280000, 0, amgrGetFrameMesgQueue(), &g_SchedRspMsg);
	}
#endif

	if (!g_Resetting) {
		vi00009ed4();
	}

	joysTick();
	snd0000fe18();
	schedRenderCrashPeriodically(sc->frameCount);
}

extern struct sndcache g_SndCache;

/**
 * __scHandleTasks is called both on retrace and when the RDP completes a task.
 */
void __scHandleTasks(OSSched *sc)
{
	s32         state;
	OSScTask    *rspTask = 0;
	OSScClient  *client;
	OSScTask    *sp = 0;
	OSScTask    *dp = 0;

	profileTick();

	/**
	 * Read the task command queue and schedule tasks
	 */
	while (osRecvMesg(&sc->cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) != -1) {
		__scAppendList(sc, rspTask);
	}

	if (sc->doAudio && sc->curRSPTask) {
		/**
		 * Preempt the running gfx task.  Note: if the RSP
		 * component of the graphics task has finished, but the
		 * RDP component is still running, we can start an audio
		 * task which will freeze the RDP (and save the RDP cmd
		 * FIFO) while the audio RSP code is running.
		 */
		__scYield(sc);
	} else {
		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp, false);
		}
	}

	/**
	 * Notify audio and graphics threads to start building the command
	 * lists for the next frame (client threads may choose not to
	 * build the list in overrun case)
	 */
	for (client = sc->clientList; client != 0; client = client->next) {
		if ((*((s32*)client + 2) == 0) || ((sc->frameCount & 1) == 0)) {
			osSendMesg(client->msgQ, (OSMesg) &sc->retraceMsg, OS_MESG_NOBLOCK);
		}
	}

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *end = (s32 *)&bootAllocateStack;
		s32 *ptr = (s32 *)&bootPhase1;
		s32 i;

		while (ptr < end) {
			checksum ^= *ptr;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			u8 *addr = (u8 *) &g_SndCache;

			for (i = 0; i < 40; i++) {
				addr[4 + i] = 0xff;
			}
		}
	}
#endif
}

/**
 * __scHandleRSP is called when an RSP task signals that it has
 * finished or yielded (at the hosts request).
 */
void __scHandleRSP(OSSched *sc)
{
	OSScTask *t, *sp = 0, *dp = 0;
	s32 state;

	if (!g_Resetting) {
		t = sc->curRSPTask;
		sc->curRSPTask = 0;

		if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
			t->state |= OS_SC_YIELDED;

			if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
				profileHandleRspEvent(RSPEVENT_GFX_PAUSE);

				// Push the task back on the list
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
			__scExec(sc, sp, dp, true);
		}
	}
}

u32 *schedGetDpCounters(void)
{
	return g_SchedDpCounters;
}

void schedInitArtifacts(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < MAX_ARTIFACTS; j++) {
			g_ArtifactLists[i][j].type = ARTIFACTTYPE_FREE;
		}

		g_SchedSpecialArtifactIndexes[i] = 0;
	}
}

/**
 * The write list is an artifact list that is not currently being displayed on
 * the screen. Update logic can write here to put artifacts on the next frame.
 */
struct artifact *schedGetWriteArtifacts(void)
{
	return g_ArtifactLists[g_SchedWriteArtifactsIndex];
}

/**
 * The front list is the artifact list that is currently being displayed on the
 * screen. Rendering logic reads this list. The list may be re-used for multiple
 * frames in a row during lag.
 */
struct artifact *schedGetFrontArtifacts(void)
{
	return g_ArtifactLists[g_SchedFrontArtifactsIndex];
}

/**
 * The pending list is possibly misnamed. I'm not sure how this list works.
 *
 * @TODO: Investigate.
 */
struct artifact *schedGetPendingArtifacts(void)
{
	return g_ArtifactLists[g_SchedPendingArtifactsIndex];
}

void schedIncrementWriteArtifacts(void)
{
	g_SchedWriteArtifactsIndex = (g_SchedWriteArtifactsIndex + 1) % 3;
}

void schedIncrementFrontArtifacts(void)
{
	g_SchedFrontArtifactsIndex = (g_SchedFrontArtifactsIndex + 1) % 3;
}

void schedIncrementPendingArtifacts(void)
{
	g_SchedPendingArtifactsIndex = (g_SchedPendingArtifactsIndex + 1) % 3;
}

void schedResetArtifacts(void)
{
	g_SchedWriteArtifactsIndex = 0;
	g_SchedFrontArtifactsIndex = 1;
	g_SchedPendingArtifactsIndex = 0;
}

void schedUpdatePendingArtifacts(void)
{
	struct artifact *artifacts = schedGetPendingArtifacts();
	s32 i;

	for (i = 0; i < MAX_ARTIFACTS; i++) {
		struct artifact *artifact = &artifacts[i];

		if (artifact->type != ARTIFACTTYPE_FREE) {
			u16 *unk08 = artifact->unk08;
			u16 value08 = unk08[0];

			if (g_SchedSpecialArtifactIndexes[g_SchedPendingArtifactsIndex] == 1) {
				u16 *unk0c = artifact->unk0c.u16p;
				u16 value0c = unk0c[0];

				if (value0c > value08) {
					artifact->unk02 = value08;
				} else {
					artifact->unk02 = value0c;
				}
			} else {
				artifact->unk02 = value08;
			}
		}
	}

	g_SchedSpecialArtifactIndexes[g_SchedPendingArtifactsIndex] = 0;

	schedIncrementPendingArtifacts();
}

/**
 * __scHandleRDP is called when an RDP task signals that it has finished.
 */
void __scHandleRDP(OSSched *sc)
{
	OSScTask *t, *sp = NULL, *dp = NULL;
	s32 state;

	if (sc->curRDPTask != NULL) {
		schedUpdatePendingArtifacts();

		if (var8005dd18 == 0) {
			schedConsiderScreenshot();
		}

		osDpGetCounters(g_SchedDpCounters);

		t = sc->curRDPTask;
		sc->curRDPTask = NULL;
		t->state &= ~OS_SC_NEEDS_RDP;

		__scTaskComplete(sc, t);

		state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);

		if (__scSchedule(sc, &sp, &dp, state) != state) {
			__scExec(sc, sp, dp, false);
		}
	}
}

/**
 * __scTaskReady checks to see if the graphics task is able to run
 * based on the current state of the RCP.
 */
OSScTask *__scTaskReady(OSScTask *t)
{
	void *a;
	void *b;

	if (t) {
		if ((osDpGetStatus() & DPC_STATUS_FREEZE) == 0) {
			if (osViGetCurrentFramebuffer() != osViGetNextFramebuffer()) {
				return 0;
			}
		}

		return t;
	}

	return 0;
}

/*
 * __scTaskComplete checks to see if the task is complete (all RCP
 * operations have been performed) and sends the done message to the
 * client if it is.
 */
s32 __scTaskComplete(OSSched *sc, OSScTask *t)
{
	if (t->list.t.type == M_AUDTASK) {
		profileHandleRspEvent(RSPEVENT_AUD_FINISH);
	} else {
		profileHandleRspEvent(RSPEVENT_GFX_FINISH);
	}

	if ((t->state & OS_SC_RCP_MASK) == 0) {
		if (t->list.t.type == 1
				&& (t->flags & OS_SC_SWAPBUFFER)
				&& (t->flags & OS_SC_LAST_TASK)) {
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

			if (g_ViUnblackTimer != 0 && g_ViUnblackTimer < 3) {
				g_ViUnblackTimer--;
			}

			schedRenderCrashOnBuffer(t->framebuffer);
			osViSwapBuffer(t->framebuffer);
		}

		osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);

		return 1;
	}

	return 0;
}

/**
 * Place task on either the audio or graphics queue.
 */
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

void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp, s32 resuming)
{
	if (sp) {
		if (sp->list.t.type == M_AUDTASK) {
			osWritebackDCacheAll();
		}

		if (sp->list.t.type != M_AUDTASK && (sp->state & OS_SC_YIELD) == 0) {
			osDpSetStatus(DPC_STATUS_CMD_BUSY | DPC_STATUS_CBUF_READY | DPC_STATUS_DMA_BUSY | DPC_STATUS_END_VALID);
		}

		if (resuming) {
			if (sp->list.t.type != M_AUDTASK) {
				profileHandleRspEvent(RSPEVENT_GFX_RESUME);
			}
		} else {
			if (sp->list.t.type == M_AUDTASK) {
				profileHandleRspEvent(RSPEVENT_AUD_START);
			} else {
				profileHandleRspEvent(RSPEVENT_GFX_START);
			}
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

#if VERSION < VERSION_NTSC_1_0
bool schedIsCurTaskAudio(OSSched *sc)
{
	if (sc->curRSPTask) {
		return sc->curRSPTask->list.t.type == M_AUDTASK;
	}

	return false;
}
#endif

void __scYield(OSSched *sc)
{
	if (sc->curRSPTask->list.t.type == M_GFXTASK) {
		sc->curRSPTask->state |= OS_SC_YIELD;
		osSpTaskYield();
	} else {
		// empty
	}
}

/*
 * Schedules the tasks to be run on the RCP.
 */
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
	} else if (__scTaskReady(gfx)) {
		switch (gfx->flags & OS_SC_TYPE_MASK) {
		case OS_SC_XBUS:
			if (gfx->state & OS_SC_YIELDED) {
				if (avail & OS_SC_SP) {
					*sp = gfx;
					avail &= ~OS_SC_SP;

					if (gfx->state & OS_SC_DP) {
						*dp = gfx;
						avail &= ~OS_SC_DP;
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

	if (avail != availRCP) {
		avail = __scSchedule(sc, sp, dp, avail);
	}

	return avail;
}

void schedConsiderScreenshot(void)
{
	if (g_MenuData.screenshottimer == 1) {
		if (IS8MB()) {
			menugfxCreateBlur();
		}

		g_MenuData.screenshottimer = 0;
	}

	if (g_MenuData.screenshottimer >= 2) {
		g_MenuData.screenshottimer--;
	}
}
