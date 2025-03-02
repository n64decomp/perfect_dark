#include <ultra64.h>
#include "lib/boot.h"
#include "lib/sched.h"
#include "naudio/n_synthInternals.h"
#include "constants.h"
#include "bss.h"
#include "lib/audiodma.h"
#include "lib/lib_2fc60.h"
#include "lib/profile.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

u32 var80091560;
u32 var80091564;
u64 var80091568;
u64 var80091570;
u64 var80091578;
u64 var80091580;
u64 var80091588;
u64 var80091590;
u32 var80091598;
u32 var8009159c;
u32 var800915a0;
u32 var800915a4;
u32 var800915a8;
u32 var800915ac;
u32 var800915b0;
u32 var800915b4;
u32 var800915b8;
u32 var800915bc;
u32 var800915c0;
u32 var800915c4;
AMAudioMgr g_AudioManager;
OSScClient g_AudioSchedClient;
u32 var800918dc;
u32 g_AmgrFreqPerTick;
u32 var800918e4;
s32 var800918e8;
s32 var800918ec;
void *g_AudioSp;

u32 var8005cf90 = 0x00000000;
u8 var8005cf94 = 1;

void amgr_handle_done_msg(AudioInfo *info);
void amgr_handle_frame_msg(AudioInfo *info, AudioInfo *previnfo);
void amgr_main(void *arg);

void amgr_init(void)
{
	g_AudioSp = boot_allocate_stack(THREAD_AUDIO, STACKSIZE_AUDIO);
}

#if VERSION >= VERSION_PAL_BETA
void amgr_create(ALSynConfig *config, u32 *settings)
#else
void amgr_create(ALSynConfig *config)
#endif
{
	f32 freqpertick;
	s32 i;

	config->outputRate = osAiSetFrequency(22020);
	config->dmaproc = adma_new;

#if VERSION >= VERSION_JPN_FINAL
	freqpertick = settings[1] * (f32)config->outputRate / 30.0f;

	if (IS4MB()) {
		freqpertick *= 0.5f;
	}
#elif VERSION >= VERSION_PAL_BETA
	freqpertick = settings[1] * (f32)config->outputRate / 25.0f;
#else
	freqpertick = config->outputRate / 30.0f;

	if (IS4MB()) {
		freqpertick *= 0.5f;
	}
#endif

	g_AmgrFreqPerTick = (s32)freqpertick;

	if ((f32)g_AmgrFreqPerTick < freqpertick) {
		g_AmgrFreqPerTick++;
	}

	g_AmgrFreqPerTick = g_AmgrFreqPerTick / SAMPLES * SAMPLES + SAMPLES;
	var800918dc = g_AmgrFreqPerTick - SAMPLES;
	var800918e4 = g_AmgrFreqPerTick + 80;
	var8005cf94 = 0;

	adma_init();

	osCreateMesgQueue(&g_AudioManager.audioReplyMsgQ, g_AudioManager.audioReplyMsgBuf, ARRAYCOUNT(g_AudioManager.audioFrameMsgBuf));
	osCreateMesgQueue(&g_AudioManager.audioFrameMsgQ, g_AudioManager.audioFrameMsgBuf, ARRAYCOUNT(g_AudioManager.audioFrameMsgBuf));

	var800918ec = 2000;

#if !PAL
	if (IS4MB()) {
		var800918ec >>= 1;
	}
#endif

	for (i = 0; i < ARRAYCOUNT(g_AudioManager.ACMDList); i++) {
		g_AudioManager.ACMDList[i] = alHeapAlloc(&g_SndHeap, 1, var800918ec * sizeof(Acmd));
	}

	for (i = 0; i < ARRAYCOUNT(g_AudioManager.audioInfo); i++) {
		g_AudioManager.audioInfo[i] = alHeapAlloc(&g_SndHeap, 1, sizeof(AudioInfo));
		g_AudioManager.audioInfo[i]->frameSamples = 0;
		g_AudioManager.audioInfo[i]->data = alHeapAlloc(&g_SndHeap, 1, PAL ? 3688 : 1024 * 3);
	}

#define ms *(((s32) ((f32) 44.1))&~0x7)

	{
		s32 sp590[] = { 1, 132 ms,
			// input output    fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    123.8 ms, 19724, 0,     21503, 0,         0,          0,
		};

		s32 sp568[] = { 1, 11 ms,
			// input output  fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    2.6 ms, 16384, 0,     32767, 7600,      7000,       0
		};

		s32 sp540[] = { 1, 11 ms,
			// input output  fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    2.6 ms, 0,     24575, 32767, 380,       500,        0,
		};

		s32 sp478[] = { 6, 156.2 ms,
			// input output    fbcoef ffcoef  gain   chorusrate chorusdepth filtercoef
			0 ms,    8.8 ms,   9830,  -9830,  0,     0,         0,          0,
			9.8 ms,  40 ms,    9054,  -9830,  29964, 0,         0,          3018,
			19.8 ms, 63.8 ms,  16384, -16384, 28024, 0,         0,          4742,
			79.8 ms, 139.8 ms, 21018, -16384, 29263, 0,         0,          5712,
			84.2 ms, 120 ms,   8515,  -8192,  24036, 0,         0,          8838,
			0 ms,    148 ms,   13000, -13000, 0,     0,         0,          17664,
		};

		s32 sp430[] = { 2, 55.6 ms,
			// input output   fbcoef ffcoef  gain   chorusrate chorusdepth filtercoef
			38.4 ms, 47.2 ms, 28994, 0,      23551, 0,         0,          31689,
			0 ms,    33 ms,   24359, -19832, 32497, 0,         1,          26299,
		};

		s32 sp3c8[] = { 3, 72 ms,
			// input output   fbcoef ffcoef  gain  chorusrate chorusdepth filtercoef
			0 ms,    8.8 ms,  9830,  -9830,  0,    0,         0,          0,
			9.8 ms,  40 ms,   9054,  -9830,  5874, 0,         0,          3018,
			19.8 ms, 63.8 ms, 16384, -16384, 6251, 0,         0,          4742,
		};

		s32 sp360[] = { 3, 72 ms,
			// input output   fbcoef ffcoef  gain  chorusrate chorusdepth filtercoef
			0 ms,    8.8 ms,  9830,  -9830,  0,    0,         0,          0,
			9.8 ms,  40 ms,   9054,  -9830,  5874, 0,         0,          3018,
			19.8 ms, 63.8 ms, 16384, -16384, 6251, 0,         0,          4742,
		};

		s32 sp2f8[] = { 3, 55 ms,
			// input output   fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    29.6 ms, 9830,  -9830, 0,     0,         0,          0,
			10.4 ms, 20.8 ms, 3276,  -3276, 16383, 0,         0,          0,
			0 ms,    33 ms,   5000,  0,     0,     0,         0,          20480,
		};

		s32 sp270[] = { 4, 55 ms,
			// input output   fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    36.2 ms, 9830,  -9830, 0,     0,         0,          0,
			12 ms,   29.6 ms, 3276,  -3276, 16383, 0,         0,          0,
			36.2 ms, 50 ms,   3276,  -3276, 16383, 0,         0,          0,
			0 ms,    51.6 ms, 8000,  0,     0,     0,         0,          20480,
		};

		s32 sp248[] = { 1, 110 ms,
			// input output   fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    98.4 ms, 12000, 0,     32767, 0,         0,          0,
		};

		s32 params_bus0_4mb[] = { 4, 93.4 ms,
			// input output  fbcoef ffcoef  gain   chorusrate chorusdepth filtercoef
			4.8 ms, 9.8 ms,  9830,  -9830,  13444, 0,         0,          0,
			11 ms,  35.2 ms, 16384, -16384, 6635,  0,         0,          0,
			66 ms,  74.2 ms, 8192,  -8192,  0,     0,         0,          0,
			0 ms,   81.4 ms, 18000, -18000, 0,     380,       10,         0,
		};

		s32 params_bus1_4mb[] = { 1, 33 ms,
			// input output   fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    27.4 ms, 13108, 0,     29493, 0,         0,          0,
		};

		s32 params_bus0_8mb[] = { 8, 176 ms,
			// input output    fbcoef ffcoef  gain   chorusrate chorusdepth filtercoef
			0 ms,    4.8 ms,   9830,  -9830,  0,     0,         0,          0,
			4.8 ms,  9.8 ms,   9830,  -9830,  11140, 0,         0,          0,
			22 ms,   70.4 ms,  16384, -16384, 4587,  0,         0,          0,
			26.4 ms, 52.8 ms,  8192,  -8192,  0,     0,         0,          0,
			88 ms,   154 ms,   16384, -16384, 4587,  0,         0,          0,
			92.4 ms, 132 ms,   8192,  -8192,  0,     0,         0,          0,
			132 ms,  148.6 ms, 8192,  -8192,  0,     0,         0,          0,
			0 ms,    162.8 ms, 13000, -13000, 0,     380,       10,         0,
		};

		s32	params_bus1_8mb[] = { 1, 66 ms,
			// input output fbcoef ffcoef gain   chorusrate chorusdepth filtercoef
			0 ms,    55 ms,  13108, 0,     29493, 0,         0,          0,
		};

		s32	sp040[] = { 1, 8.2 ms,
			// input output fbcoef ffcoef gain chorusrate chorusdepth filtercoef
			0 ms,    0 ms,  0,     0,     0,   0,         0,          0,
		};

		config->params[0] = (s32 *) (IS4MB() ? params_bus0_4mb : params_bus0_8mb);

		if (g_SndMaxFxBusses >= 2) {
			for (i = 1; i < g_SndMaxFxBusses; i++) {
				config->params[i] = (s32 *) (IS4MB() ? params_bus1_4mb : params_bus1_8mb);
			}
		}
	}

	n_alInit(&g_AudioManager.g, config);
	osc_build_linkedlist(0, 60);
	osCreateThread(&g_AudioManager.thread, THREAD_AUDIO, &amgr_main, 0, g_AudioSp, THREADPRI_AUDIO);
}

s8 g_AudioIsThreadRunning = false;

void amgr_start_thread(void)
{
	osStartThread(&g_AudioManager.thread);
	g_AudioIsThreadRunning = true;
}

OSMesgQueue *amgr_get_frame_mesg_queue(void)
{
	return &g_AudioManager.audioFrameMsgQ;
}

/**
 * This doesn't set g_AudioIsThreadRunning to false, but that's okay because
 * this is only called when resetting the console, and when that happens the
 * variable is likely reset too.
 */
void amgr_stop_thread(void)
{
	if (g_AudioIsThreadRunning) {
		osStopThread(&g_AudioManager.thread);
	}
}

extern u32 g_AdmaCurFrame;

void amgr_main(void *arg)
{
	s32 count = 0;
	bool done = false;
	s16 *msg = NULL;
	AudioInfo *info = NULL;

	static u32 var8005d514 = 1;

#if PAL
	// Receive retrace events every second retrace
	osScAddClient(&g_Sched, &g_AudioSchedClient, &g_AudioManager.audioFrameMsgQ, true);
#else
	// 8MB - Receive retrace events every second retrace
	// 4MB - Receive retrace events every retrace due to smaller command buffer
	osScAddClient(&g_Sched, &g_AudioSchedClient, &g_AudioManager.audioFrameMsgQ, !IS4MB());
#endif

	while (!done) {
		osRecvMesg(&g_AudioManager.audioFrameMsgQ, (OSMesg *) &msg, OS_MESG_BLOCK);

		switch (*msg) {
		case OS_SC_RSP_MSG:
			var80091588 = osGetTime();
			profile_set_marker(PROFILE_AUDIOFRAME_START);
			amgr_handle_frame_msg(g_AudioManager.audioInfo[g_AdmaCurFrame % 3], info);
			adma_receive_all();

			count++;
			profile_set_marker(PROFILE_AUDIOFRAME_END);

			var80091590 = osGetTime();
			var80091570 = var80091590 - var80091588;

			if (count % 240 == 0) {
				var80091578 = var80091580 / 240;
				var80091580 = 0; var80091568 = 0;
			} else {
				var80091580 = (var80091580 + var80091590) - var80091588;
			}

			if (var80091568 < var80091590 - var80091588) {
				var80091568 = var80091590 - var80091588;
			}

			if (var8005d514 == 0) {
				osRecvMesg(&g_AudioManager.audioReplyMsgQ, (OSMesg *) &info, OS_MESG_BLOCK);
			}

			var8005d514 = 0;
			amgr_handle_done_msg(info);
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

void amgr_handle_frame_msg(AudioInfo *info, AudioInfo *previnfo)
{
	u32 somevalue;
	s16 *outbuffer;
	Acmd *datastart;
	Acmd *cmd;

	static OSScTask *g_AmgrCurrentCmdList;

	extern u8 aspTextStart;
	extern u8 aspDataStart;

	if (g_AmgrCurrentCmdList) {
		sched_submit_task(&g_Sched, g_AmgrCurrentCmdList);
	}

	adma_begin_frame();

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
	g_AmgrCurrentCmdList->list.t.ucode_boot_size = (uintptr_t) &rspbootTextEnd - (uintptr_t) &rspbootTextStart;
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

void amgr_handle_done_msg(AudioInfo *info)
{
	static bool firsttime = true;

	if ((s32)osAiGetLength() >> 2 == 0 && firsttime == false) {
		firsttime = false;
	}
}
