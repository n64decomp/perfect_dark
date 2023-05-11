#include <ultra64.h>
#include "lib/boot.h"
#include "lib/sched.h"
#include "constants.h"
#include "bss.h"
#include "lib/audiodma.h"
#include "lib/lib_2fc60.h"
#include "lib/profile.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

AMAudioMgr g_AudioManager;
OSScClient var800918d0;
u32 var800918dc;
u32 g_AmgrFreqPerTick;
s32 var800918e8;
s32 var800918ec;
void *g_AudioSp;

u32 var8005cf90 = 0x00000000;
u8 var8005cf94 = 1;

static void amgrHandleDoneMsg(AudioInfo *info);
static void amgrHandleFrameMsg(AudioInfo *info, AudioInfo *previnfo);
static void amgrMain(void *arg);

void amgrInit(void)
{
	g_AudioSp = bootAllocateStack(THREAD_AUDIO, STACKSIZE_AUDIO);
}

void amgrCreate(ALSynConfig *config)
{
	f32 freqpertick;
	s32 i;

	config->outputRate = osAiSetFrequency(22020);
	config->dmaproc = admaNew;

	freqpertick = config->outputRate / 30.0f;

	g_AmgrFreqPerTick = (s32)freqpertick;

	if ((f32)g_AmgrFreqPerTick < freqpertick) {
		g_AmgrFreqPerTick++;
	}

	g_AmgrFreqPerTick = g_AmgrFreqPerTick / 184 * 184 + 184;
	var800918dc = g_AmgrFreqPerTick - 184;
	var8005cf94 = 0;

	admaInit();

	osCreateMesgQueue(&g_AudioManager.audioReplyMsgQ, g_AudioManager.audioReplyMsgBuf, ARRAYCOUNT(g_AudioManager.audioFrameMsgBuf));
	osCreateMesgQueue(&g_AudioManager.audioFrameMsgQ, g_AudioManager.audioFrameMsgBuf, ARRAYCOUNT(g_AudioManager.audioFrameMsgBuf));

	var800918ec = 2000;

	for (i = 0; i < ARRAYCOUNT(g_AudioManager.ACMDList); i++) {
		g_AudioManager.ACMDList[i] = UNCACHED(alHeapAlloc(&g_SndHeap, 1, var800918ec * sizeof(Acmd)));
	}

	for (i = 0; i < ARRAYCOUNT(g_AudioManager.audioInfo); i++) {
		// @todo: Find out why AudioInfo is only 0x60
		g_AudioManager.audioInfo[i] = alHeapAlloc(&g_SndHeap, 1, 0x60);
		g_AudioManager.audioInfo[i]->frameSamples = 0;
		g_AudioManager.audioInfo[i]->data = alHeapAlloc(&g_SndHeap, 1, PAL ? 3688 : 1024 * 3);
	}

	{
		s32 sp590[] = { 0x00000001, 0x000014a0, 0x00000000, 0x00001358, 0x00004d0c, 0x00000000, 0x000053ff, 0x00000000, 0x00000000, 0x00000000 };
		s32 sp568[] = { 0x00000001, 0x000001b8, 0x00000000, 0x00000068, 0x00004000, 0x00000000, 0x00007fff, 0x00001db0, 0x00001b58, 0x00000000 };
		s32 sp540[] = { 0x00000001, 0x000001b8, 0x00000000, 0x00000068, 0x00000000, 0x00005fff, 0x00007fff, 0x0000017c, 0x000001f4, 0x00000000 };
		s32 sp478[] = { 0x00000006, 0x00001868, 0x00000000, 0x00000160, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000188, 0x00000640, 0x0000235e, 0xffffd99a, 0x0000750c, 0x00000000, 0x00000000, 0x00000bca, 0x00000318, 0x000009f8, 0x00004000, 0xffffc000, 0x00006d78, 0x00000000, 0x00000000, 0x00001286, 0x00000c78, 0x000015d8, 0x0000521a, 0xffffc000, 0x0000724f, 0x00000000, 0x00000000, 0x00001650, 0x00000d28, 0x000012c0, 0x00002143, 0xffffe000, 0x00005de4, 0x00000000, 0x00000000, 0x00002286, 0x00000000, 0x00001720, 0x000032c8, 0xffffcd38, 0x00000000, 0x00000000, 0x00000000, 0x00004500 };
		s32 sp430[] = { 0x00000002, 0x000008b0, 0x00000600, 0x00000760, 0x00007142, 0x00000000, 0x00005bff, 0x00000000, 0x00000000, 0x00007bc9, 0x00000000, 0x00000528, 0x00005f27, 0xffffb288, 0x00007ef1, 0x00000000, 0x00000001, 0x000066bb };
		s32 sp3c8[] = { 0x00000003, 0x00000b40, 0x00000000, 0x00000160, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000188, 0x00000640, 0x0000235e, 0xffffd99a, 0x000016f2, 0x00000000, 0x00000000, 0x00000bca, 0x00000318, 0x000009f8, 0x00004000, 0xffffc000, 0x0000186b, 0x00000000, 0x00000000, 0x00001286 };
		s32 sp360[] = { 0x00000003, 0x00000b40, 0x00000000, 0x00000160, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000188, 0x00000640, 0x0000235e, 0xffffd99a, 0x000016f2, 0x00000000, 0x00000000, 0x00000bca, 0x00000318, 0x000009f8, 0x00004000, 0xffffc000, 0x0000186b, 0x00000000, 0x00000000, 0x00001286 };
		s32 sp2f8[] = { 0x00000003, 0x00000898, 0x00000000, 0x000004a0, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000001a0, 0x00000340, 0x00000ccc, 0xfffff334, 0x00003fff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000528, 0x00001388, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000 };
		s32 sp270[] = { 0x00000004, 0x00000898, 0x00000000, 0x000005a8, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000001e0, 0x000004a0, 0x00000ccc, 0xfffff334, 0x00003fff, 0x00000000, 0x00000000, 0x00000000, 0x000005a8, 0x000007d0, 0x00000ccc, 0xfffff334, 0x00003fff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000810, 0x00001f40, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000 };
		s32 sp248[] = { 0x00000001, 0x00001130, 0x00000000, 0x00000f60, 0x00002ee0, 0x00000000, 0x00007fff, 0x00000000, 0x00000000, 0x00000000 };
		s32 sp1c0[] = { 0x00000004, 0x00000e98, 0x000000c0, 0x00000188, 0x00002666, 0xffffd99a, 0x00003484, 0x00000000, 0x00000000, 0x00000000, 0x000001b8, 0x00000580, 0x00004000, 0xffffc000, 0x000019eb, 0x00000000, 0x00000000, 0x00000000, 0x00000a50, 0x00000b98, 0x00002000, 0xffffe000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000cb8, 0x00004650, 0xffffb9b0, 0x00000000, 0x0000017c, 0x0000000a, 0x00000000 };
		s32 sp198[] = { 0x00000001, 0x00000528, 0x00000000, 0x00000448, 0x00003334, 0x00000000, 0x00007335, 0x00000000, 0x00000000, 0x00000000 };
		s32 sp090[] = { 0x00000008, 0x00001b80, 0x00000000, 0x000000c0, 0x00002666, 0xffffd99a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000c0, 0x00000188, 0x00002666, 0xffffd99a, 0x00002b84, 0x00000000, 0x00000000, 0x00000000, 0x00000370, 0x00000b00, 0x00004000, 0xffffc000, 0x000011eb, 0x00000000, 0x00000000, 0x00000000, 0x00000420, 0x00000840, 0x00002000, 0xffffe000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000dc0, 0x00001810, 0x00004000, 0xffffc000, 0x000011eb, 0x00000000, 0x00000000, 0x00000000, 0x00000e70, 0x000014a0, 0x00002000, 0xffffe000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000014a0, 0x00001738, 0x00002000, 0xffffe000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001970, 0x000032c8, 0xffffcd38, 0x00000000, 0x0000017c, 0x0000000a, 0x00000000 };
		s32 sp068[] = { 0x00000001, 0x00000a50, 0x00000000, 0x00000898, 0x00003334, 0x00000000, 0x00007335, 0x00000000, 0x00000000, 0x00000000 };
		s32 sp040[] = { 0x00000001, 0x00000148, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		config->params[0] = (s32 *) sp090;

		if (g_SndMaxFxBusses >= 2) {
			for (i = 1; i < g_SndMaxFxBusses; i++) {
				config->params[i] = (s32 *) sp068;
			}
		}
	}

	n_alInit(&g_AudioManager.g, config);
	func00030bfc(0, 60);
	osCreateThread(&g_AudioManager.thread, THREAD_AUDIO, &amgrMain, 0, g_AudioSp, THREADPRI_AUDIO);
}

s8 g_AudioIsThreadRunning = false;

void amgrStartThread(void)
{
	osStartThread(&g_AudioManager.thread);
	g_AudioIsThreadRunning = true;
}

/**
 * This doesn't set g_AudioIsThreadRunning to false, but that's okay because
 * this is only called when resetting the console, and when that happens the
 * variable is likely reset too.
 */
void amgrStopThread(void)
{
	if (g_AudioIsThreadRunning) {
		osStopThread(&g_AudioManager.thread);
	}
}

extern u32 g_AdmaCurFrame;

static void amgrMain(void *arg)
{
	s32 count = 0;
	bool done = false;
	s32 msg = 0;
	AudioInfo *info = NULL;

	static bool first = true;

	osScAddClient(&g_Sched, &var800918d0, &g_AudioManager.audioFrameMsgQ, true);

	while (!done) {
		osRecvMesg(&g_AudioManager.audioFrameMsgQ, (OSMesg *) &msg, OS_MESG_BLOCK);

		switch (msg) {
		case OS_SC_RSP_MSG:
			profileStart(PROFILEMARKER_AUDIO);
			amgrHandleFrameMsg(g_AudioManager.audioInfo[g_AdmaCurFrame % 3], info);
			admaReceiveAll();

			count++;
			profileEnd(PROFILEMARKER_AUDIO);

			if (!first) {
				osRecvMesg(&g_AudioManager.audioReplyMsgQ, (OSMesg *) &info, OS_MESG_BLOCK);
			}

			first = false;
			amgrHandleDoneMsg(info);
			break;
		case OS_SC_PRE_NMI_MSG:
			done = true;
			break;
		case OS_SC_QUIT_MSG:
			done = true;
			break;
		}
	}

	n_alClose(&g_AudioManager.g);
}

static void amgrHandleFrameMsg(AudioInfo *info, AudioInfo *previnfo)
{
	u32 somevalue;
	s16 *outbuffer;
	Acmd *datastart;
	Acmd *cmd;

	static OSScTask *g_AmgrCurrentCmdList;

	extern u8 aspTextStart;
	extern u8 aspDataStart;

	if (g_AmgrCurrentCmdList) {
		schedSubmitAudTask(&g_Sched, g_AmgrCurrentCmdList);
	}

	admaBeginFrame();

	somevalue = IO_READ(OS_PHYSICAL_TO_K1(AI_LEN_REG)) / 4;
	datastart = g_AudioManager.ACMDList[var8005cf90];
	outbuffer = (s16 *) osVirtualToPhysical(info->data);

	if (previnfo) {
		osAiSetNextBuffer(previnfo->data, previnfo->frameSamples * 4);
	}

	if (somevalue > 248 && var8005cf94 == 0) {
		info->frameSamples = var800918dc;
		var8005cf94 = 2;
	} else {
		info->frameSamples = g_AmgrFreqPerTick;

		if (var8005cf94 != 0) {
			var8005cf94--;
		}
	}

	cmd = n_alAudioFrame(datastart, &var800918e8, outbuffer, info->frameSamples);

	g_AmgrCurrentCmdList = &info->task;

	g_AmgrCurrentCmdList->next = NULL;
	g_AmgrCurrentCmdList->msgQ = &g_AudioManager.audioReplyMsgQ;
	g_AmgrCurrentCmdList->msg = info;
	g_AmgrCurrentCmdList->flags = OS_SC_NEEDS_RSP;
	g_AmgrCurrentCmdList->list.t.type = M_AUDTASK;
	g_AmgrCurrentCmdList->list.t.flags = 0;
	g_AmgrCurrentCmdList->list.t.ucode_boot = (u64 *) &rspbootTextStart;
	g_AmgrCurrentCmdList->list.t.ucode_boot_size = (u32) &rspbootTextEnd - (u32) &rspbootTextStart;
	g_AmgrCurrentCmdList->list.t.ucode = (u64 *) &aspTextStart;
	g_AmgrCurrentCmdList->list.t.ucode_data = (u64 *) &aspDataStart;
	g_AmgrCurrentCmdList->list.t.ucode_size = SP_UCODE_SIZE;
	g_AmgrCurrentCmdList->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
	g_AmgrCurrentCmdList->list.t.data_ptr = (u64 *) datastart;
	g_AmgrCurrentCmdList->list.t.data_size = (cmd - datastart) * sizeof(Acmd);
	g_AmgrCurrentCmdList->list.t.yield_data_ptr = NULL;
	g_AmgrCurrentCmdList->list.t.yield_data_size = 0;

	var8005cf90 ^= 1;
}

static void amgrHandleDoneMsg(AudioInfo *info)
{
	static bool firsttime = true;

	if ((s32)osAiGetLength() >> 2 == 0 && firsttime == false) {
		firsttime = false;
	}
}
