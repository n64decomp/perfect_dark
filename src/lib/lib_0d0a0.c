#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_0d0a0.h"
#include "types.h"

u8 g_LoadState = 0;

void dmaInit(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_DmaSlotsBusy); i++) {
		g_DmaSlotsBusy[i] = 0;
	}

	g_DmaNumSlotsBusy = 0;

	osCreateMesgQueue(&g_DmaMesgQueue, &var80094e08, 0x20);
}

void dmaStart(void *memaddr, u32 romaddr, u32 len, bool priority)
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

u32 xorDeadbeef(u32 value)
{
	return value ^ 0xdeadbeef;
}

u32 xorDeadbabe(u32 value)
{
	return value ^ 0xdeadbabe;
}

/**
 * This is executed after a DMA transfer. It xors the first 8 words with
 * 0x0330c820, then reads a value from the boot loader (0x340 in ROM) which
 * should be the same value, and xors the memory again with that value.
 */
void dmaCheckPiracy(void *memaddr, u32 len)
{
	if (g_LoadState != LOADSTATE_NONE && len > 128) {
#if PIRACYCHECKS
		u32 value = xorDeadbeef(0x0330c820 ^ 0xdeadbeef);
		u32 *ptr = (u32 *)memaddr;
		u32 data;
		u32 devaddr;
		s32 i;

		for (i = 0; i < 8; i++) {
			ptr[i] ^= value;
		}

		devaddr = xorDeadbabe(0xb0000340 ^ 0xdeadbabe);

		osPiReadIo(devaddr, &data);

		for (i = 0; i < 8; i++) {
			ptr[i] ^= data;
		}
#endif

		g_LoadState = LOADSTATE_NONE;
	}
}

void dmaWait(void)
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

void dmaExec(void *memaddr, void *romaddr, u32 len)
{
	dmaStart(memaddr, (u32) romaddr, len, false);
	dmaWait();
	dmaCheckPiracy(memaddr, len);
}

void dmaExecHighPriority(void *memaddr, void *romaddr, u32 len)
{
	dmaStart(memaddr, (u32) romaddr, len, true);
	dmaWait();
	dmaCheckPiracy(memaddr, len);
}

GLOBAL_ASM(
glabel func0000d488
/*     d488:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     d48c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     d490:	afa40030 */ 	sw	$a0,0x30($sp)
/*     d494:	afa60038 */ 	sw	$a2,0x38($sp)
/*     d498:	14c00009 */ 	bnez	$a2,.L0000d4c0
/*     d49c:	00a03825 */ 	or	$a3,$a1,$zero
/*     d4a0:	2498000f */ 	addiu	$t8,$a0,0xf
/*     d4a4:	34a90001 */ 	ori	$t1,$a1,0x1
/*     d4a8:	392a0001 */ 	xori	$t2,$t1,0x1
/*     d4ac:	3719000f */ 	ori	$t9,$t8,0xf
/*     d4b0:	3b28000f */ 	xori	$t0,$t9,0xf
/*     d4b4:	00aa5823 */ 	subu	$t3,$a1,$t2
/*     d4b8:	10000014 */ 	b	.L0000d50c
/*     d4bc:	010b1021 */ 	addu	$v0,$t0,$t3
.L0000d4c0:
/*     d4c0:	8fa40030 */ 	lw	$a0,0x30($sp)
/*     d4c4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*     d4c8:	34e50001 */ 	ori	$a1,$a3,0x1
/*     d4cc:	38ae0001 */ 	xori	$t6,$a1,0x1
/*     d4d0:	00ee1823 */ 	subu	$v1,$a3,$t6
/*     d4d4:	2484000f */ 	addiu	$a0,$a0,0xf
/*     d4d8:	006f3021 */ 	addu	$a2,$v1,$t7
/*     d4dc:	24c6000f */ 	addiu	$a2,$a2,0xf
/*     d4e0:	348c000f */ 	ori	$t4,$a0,0xf
/*     d4e4:	3984000f */ 	xori	$a0,$t4,0xf
/*     d4e8:	34d8000f */ 	ori	$t8,$a2,0xf
/*     d4ec:	3b06000f */ 	xori	$a2,$t8,0xf
/*     d4f0:	afa4001c */ 	sw	$a0,0x1c($sp)
/*     d4f4:	afa30018 */ 	sw	$v1,0x18($sp)
/*     d4f8:	0c003504 */ 	jal	dmaExec
/*     d4fc:	01c02825 */ 	or	$a1,$t6,$zero
/*     d500:	8fa30018 */ 	lw	$v1,0x18($sp)
/*     d504:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*     d508:	00831021 */ 	addu	$v0,$a0,$v1
.L0000d50c:
/*     d50c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     d510:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*     d514:	03e00008 */ 	jr	$ra
/*     d518:	00000000 */ 	nop
/*     d51c:	00000000 */ 	nop
);
