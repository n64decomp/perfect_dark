#include <ultra64.h>
#include "constants.h"
#include "lib/audiomgr.h"
#include "lib/joy.h"
#include "lib/reset.h"
#include "bss.h"
#include "data.h"
#include "types.h"

OSMesg g_ResetMesgs[10];
OSMesgQueue g_ResetMesgQueue;
OSThread g_ResetThread;
u8 g_ResetStack[STACKSIZE_RESET];

s8 g_Resetting = false;

/**
 * When the reset button is pressed, a PRENMI event occurs, followed by the NMI
 * (actual reset) at least 0.5 seconds later. During PRENMI, the system must
 * prepare the system for reset.
 */
static void resetproc(void *data)
{
	OSMesg msg = 0;
	OSViMode *mode;

	static u64 prenmitime;

	// Wait until a PRENMI message is received
	osRecvMesg(&g_ResetMesgQueue, &msg, OS_MESG_BLOCK);

	// Set a global variable so the scheduler knows the system is about to reset
	// and can stop scheduling new RSP tasks
	g_Resetting = true;

	// Stop the audio and main threads and ensure the reset thread's priority is set correctly
	amgrStopThread();
	osStopThread(&g_MainThread);
	osSetThreadPri(0, THREADPRI_RESET);

	// Reset the Y scale for the current VI mode
#if PAL
	mode = &osViModeTable[OS_VI_PAL_LAN1];
#else
	if (osTvType == OS_TV_MPAL) {
		mode = &osViModeTable[OS_VI_MPAL_LAN1];
	} else {
		mode = &osViModeTable[OS_VI_NTSC_LAN1];
	}
#endif

	mode->fldRegs[0].yScale = 1024;
	mode->fldRegs[1].yScale = 1024;

	osViSetMode(mode);

	// Blank the screen
	osViBlack(1);

	// Wait about 0.048 seconds
	prenmitime = osGetTime();

	while (osGetTime() < prenmitime + OS_NSEC_TO_CYCLES(48484848)) {
		// empty
	}

	// Stop controller rumbles if active
	joyDestroy();

	// Wait for the system to reset
	while (1);
}

void resetThreadCreate(void)
{
	osCreateMesgQueue(&g_ResetMesgQueue, g_ResetMesgs, ARRAYCOUNT(g_ResetMesgs));
	osSetEventMesg(OS_EVENT_PRENMI, &g_ResetMesgQueue, (OSMesg) 669);
	osCreateThread(&g_ResetThread, THREAD_RESET, resetproc, 0, &g_ResetStack[STACKSIZE_RESET], THREADPRI_RESET);
	osStartThread(&g_ResetThread);
}
