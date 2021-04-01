#include <ultra64.h>
#include "constants.h"
#include "types.h"
#include "data.h"
#include "bss.h"
#include "lib/memory.h"

u8 g_RdpDramStack[SP_DRAM_STACK_SIZE8];

u8 g_RdpYieldData[0xb00];

u16 *g_RdpOutBufferEnd = NULL;
u16 *g_RdpOutBufferStart = NULL;

struct rdptask g_RdpTaskA = {
	{
		// OSScTask
		NULL,
		0,
		0,
		0,
		{
			// OSTask
			M_GFXTASK,               // type
			OS_TASK_DP_WAIT,         // flags
			NULL,
			0,
			NULL,
			SP_UCODE_SIZE,           // ucode_size
			NULL,
			SP_UCODE_DATA_SIZE,      // ucode_data_size
			(u64 *) &g_RdpDramStack, // dram_stack
			SP_DRAM_STACK_SIZE8,     // dram_stack_size
		}
	}
};

struct rdptask g_RdpTaskB = {
	{
		// OSScTask
		NULL,
		0,
		0,
		0,
		{
			// OSTask
			M_GFXTASK,               // type
			OS_TASK_DP_WAIT,         // flags
			NULL,
			0,
			NULL,
			SP_UCODE_SIZE,           // ucode_size
			NULL,
			SP_UCODE_DATA_SIZE,      // ucode_data_size
			(u64 *) &g_RdpDramStack, // dram_stack
			SP_DRAM_STACK_SIZE8,     // dram_stack_size
		}
	}
};

struct rdptask *g_RdpCurTask = &g_RdpTaskA;

extern u8 rspbootTextStart;
extern u8 rspbootTextEnd;
extern u8 gspTextStart;
extern u8 gspDataStart;

void rdpInit(void)
{
	s32 size = 0x10000;

	if (IS4MB()) {
		size = 0x8000;
	}

	g_RdpOutBufferStart = malloc(size, MEMPOOL_PERMANENT);
	g_RdpOutBufferEnd = (u16 *)((u32)g_RdpOutBufferStart + size);
}

void rdpCreateTask(Gfx *gdlstart, Gfx *gdlend, u32 arg2, void *msg)
{
	OSScTask *sctask;
	OSTask *task;

	sctask = &g_RdpCurTask->sctask;
	task = &sctask->list;

	task->t.ucode_boot = (u64 *) &rspbootTextStart;
	task->t.ucode_boot_size = (u32) (&rspbootTextEnd - &rspbootTextStart);

	if (rspbootTextStart);

	task->t.ucode = (u64 *) &gspTextStart;
	task->t.ucode_data = (u64 *) &gspDataStart;
	task->t.output_buff = (u64 *)g_RdpOutBufferStart;
	task->t.output_buff_size = (u64 *)g_RdpOutBufferEnd;
	task->t.data_ptr = (u64 *) gdlstart;
	task->t.data_size = (gdlend - gdlstart) * sizeof(Gfx);
	task->t.yield_data_ptr = (u64 *)&g_RdpYieldData;
	task->t.yield_data_size = sizeof(g_RdpYieldData);

	sctask->next = NULL;
	sctask->flags = OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER;
	sctask->msgQ = &var8008db30;
	sctask->msg = msg;
	sctask->framebuffer = g_RdpCurTask->framebuffer;

	osWritebackDCacheAll();
	__scHandleRetraceViaPri(&g_SchedThread, sctask);

	// Swap g_RdpCurTask
	g_RdpCurTask = (struct rdptask *)((u32)g_RdpCurTask ^ (u32) &g_RdpTaskA ^ (u32) &g_RdpTaskB);
}
