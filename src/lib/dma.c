#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

volatile u32 g_DmaNumSlotsBusy;
u32 var80094ae4;
OSIoMesg g_DmaIoMsgs[32];
volatile u8 g_DmaSlotsBusy[32];
OSMesg g_DmaMesgs[32];
OSMesgQueue g_DmaMesgQueue;

u8 g_LoadType = 0;

void dma_init(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_DmaSlotsBusy); i++) {
		g_DmaSlotsBusy[i] = 0;
	}

	g_DmaNumSlotsBusy = 0;

	osCreateMesgQueue(&g_DmaMesgQueue, g_DmaMesgs, ARRAYCOUNT(g_DmaMesgs));
}

void dma_start(void *memaddr, u32 romaddr, u32 len, bool priority)
{
	u32 numiterations;
	u32 remainder;
	s32 i;

#if VERSION < VERSION_NTSC_1_0
	if (romaddr >= ROM_SIZE * 1024 * 1024) {
		crash_set_message("DMA : Off the end of the rom");
		CRASH();
	}
#endif

	if (g_DmaNumSlotsBusy) {
		dma_wait();
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
		memaddr = (void *)((uintptr_t) memaddr + 0x4000);
	}

	if (remainder) {
		g_DmaSlotsBusy[i] = true;
		g_DmaNumSlotsBusy++;

		osPiStartDma(&g_DmaIoMsgs[i], priority, 0, romaddr, memaddr, remainder, &g_DmaMesgQueue);
	}
}

#if VERSION >= VERSION_NTSC_1_0
u32 xor_deadbeef(u32 value)
{
	return value ^ 0xdeadbeef;
}

u32 xor_deadbabe(u32 value)
{
	return value ^ 0xdeadbabe;
}

/**
 * This is executed after a DMA transfer. It xors the first 8 words with
 * 0x0330c820, then reads a value from the boot loader (0x340 in ROM) which
 * should be the same value, and xors the memory again with that value.
 */
void dma_check_piracy(void *memaddr, u32 len)
{
	if (g_LoadType != LOADTYPE_NONE && len > 128) {
#if PIRACYCHECKS
		u32 value = xor_deadbeef((PAL ? 0x0109082b : 0x0330c820) ^ 0xdeadbeef);
		u32 *ptr = (u32 *)memaddr;
		u32 data;
		u32 devaddr;
		s32 i;

		for (i = 0; i < 8; i++) {
			ptr[i] ^= value;
		}

		devaddr = xor_deadbabe((PAL ? 0xb0000454 : 0xb0000340) ^ 0xdeadbabe);

		osPiReadIo(devaddr, &data);

		for (i = 0; i < 8; i++) {
			ptr[i] ^= data;
		}
#endif

		g_LoadType = LOADTYPE_NONE;
	}
}
#endif

void dma_wait(void)
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

void dma_exec(void *memaddr, u32 romaddr, u32 len)
{
	dma_start(memaddr, romaddr, len, false);
	dma_wait();
#if VERSION >= VERSION_NTSC_1_0
	dma_check_piracy(memaddr, len);
#endif
}

void dma_exec_high_priority(void *memaddr, u32 romaddr, u32 len)
{
	dma_start(memaddr, romaddr, len, true);
	dma_wait();
#if VERSION >= VERSION_NTSC_1_0
	dma_check_piracy(memaddr, len);
#endif
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
void *dma_exec_with_auto_align(void *memaddr, u32 romaddr, u32 len)
{
	u32 alignedrom = ALIGN2(romaddr);
	u32 alignedmem = ALIGN16((uintptr_t) memaddr);
	u32 offset = romaddr - alignedrom; // 0 or 1
	u32 alignedlen = ALIGN16(offset + len);

	if (len == 0) {
		return (void *)(alignedmem + offset);
	}

	dma_exec((void *)alignedmem, alignedrom, alignedlen);

	return (void *)(alignedmem + offset);
}
