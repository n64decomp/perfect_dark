#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

OSIoMesg g_DmaIoMsgs[1];
OSMesg g_DmaMesgs[1];
OSMesgQueue g_DmaMesgQueue;

void dmaInit(void)
{
	osCreateMesgQueue(&g_DmaMesgQueue, g_DmaMesgs, ARRAYCOUNT(g_DmaMesgs));
}

static void dmaStart(void *memaddr, u32 romaddr, u32 len, bool priority)
{
	OSIoMesg *msg;
	osInvalDCache(memaddr, len);
	osPiStartDma(&g_DmaIoMsgs[0], priority, 0, romaddr, memaddr, len, &g_DmaMesgQueue);
	osRecvMesg(&g_DmaMesgQueue, (OSMesg) &msg, OS_MESG_BLOCK);
}

void dmaExec(void *memaddr, u32 romaddr, u32 len)
{
	dmaStart(memaddr, romaddr, len, OS_MESG_PRI_NORMAL);
}

void dmaExecHighPriority(void *memaddr, u32 romaddr, u32 len)
{
	dmaStart(memaddr, romaddr, len, OS_MESG_PRI_HIGH);
}

/**
 * DMA data from ROM to RAM with automatic alignment.
 *
 * The destination memory address is aligned to 0x10.
 *
 * The ROM address is aligned to 2 bytes (ie. subtract 1 if ROM address is odd).
 * If this is done then the returned memory pointer is bumped forwards by one
 * to compensate. The length of data to be transferred is also increased by one
 * to make it 2-byte aligned.
 *
 * It is assumed that the passed len is 2-byte aligned (ie. an even number).
 *
 * If a length of zero is passed, no DMA is done. This can be used to retrieve
 * the memory address that would have been returned.
 */
void *dmaExecWithAutoAlign(void *memaddr, u32 romaddr, u32 len)
{
	u32 alignedrom = ALIGN2(romaddr);
	u32 alignedmem = ALIGN16((u32)memaddr);
	u32 offset = romaddr - alignedrom; // 0 or 1
	u32 alignedlen = ALIGN16(offset + len);

	if (len == 0) {
		return (void *)(alignedmem + offset);
	}

	dmaExec((void *)alignedmem, alignedrom, alignedlen);

	return (void *)(alignedmem + offset);
}
