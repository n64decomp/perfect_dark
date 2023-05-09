#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

volatile u32 g_DmaNumSlotsBusy;
OSIoMesg g_DmaIoMsgs[32];
volatile u8 g_DmaSlotsBusy[32];
OSMesg g_DmaMesgs[32];
OSMesgQueue g_DmaMesgQueue;

static void dmaWait(void);

void dmaInit(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_DmaSlotsBusy); i++) {
		g_DmaSlotsBusy[i] = 0;
	}

	g_DmaNumSlotsBusy = 0;

	osCreateMesgQueue(&g_DmaMesgQueue, g_DmaMesgs, ARRAYCOUNT(g_DmaMesgs));
}

static void dmaStart(void *memaddr, u32 romaddr, u32 len, bool priority)
{
	u32 numiterations;
	u32 remainder;
	s32 i;

	if (g_DmaNumSlotsBusy) {
		dmaWait();
	}

	if (len < 0x4000 * ARRAYCOUNT(g_DmaIoMsgs)) {
		numiterations = len / 0x4000;
		remainder = len % 0x4000;
	} else {
		// DMA size is 0x80000 or more. It won't fit in the queue, so do it
		// all in one call to osPiStartDma using the remainder variable.
		numiterations = 0;
		remainder = len;
	}

	osInvalDCache(memaddr, len);

	for (i = 0; i != numiterations; i++) {
		g_DmaSlotsBusy[i] = true;
		g_DmaNumSlotsBusy++;

		osPiStartDma(&g_DmaIoMsgs[i], priority, 0, romaddr, memaddr, 0x4000, &g_DmaMesgQueue);

		romaddr += 0x4000;
		memaddr = (void *)((u32)memaddr + 0x4000);
	}

	if (remainder) {
		g_DmaSlotsBusy[i] = true;
		g_DmaNumSlotsBusy++;

		osPiStartDma(&g_DmaIoMsgs[i], priority, 0, romaddr, memaddr, remainder, &g_DmaMesgQueue);
	}
}

static void dmaWait(void)
{
	u32 stack;
	OSIoMesg *msg;
	s32 i;

	while (g_DmaNumSlotsBusy) {
		osRecvMesg(&g_DmaMesgQueue, (OSMesg) &msg, OS_MESG_BLOCK);

		for (i = 0; i < ARRAYCOUNT(g_DmaIoMsgs); i++) {
			if (&g_DmaIoMsgs[i] == msg) {
				break;
			}
		}

		g_DmaSlotsBusy[i] = false;
		g_DmaNumSlotsBusy--;
	}
}

void dmaExec(void *memaddr, u32 romaddr, u32 len)
{
	dmaStart(memaddr, romaddr, len, false);
	dmaWait();
}

void dmaExecHighPriority(void *memaddr, u32 romaddr, u32 len)
{
	dmaStart(memaddr, romaddr, len, true);
	dmaWait();
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
