#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

volatile u32 g_DmaNumSlotsBusy;
u32 var80094ae4;
OSIoMesg g_DmaIoMsgs[32];
volatile u8 g_DmaSlotsBusy[32];
OSMesg var80094e08;
u32 var80094e0c;
u32 var80094e10;
u32 var80094e14;
u32 var80094e18;
u32 var80094e1c;
u32 var80094e20;
u32 var80094e24;
u32 var80094e28;
u32 var80094e2c;
u32 var80094e30;
u32 var80094e34;
u32 var80094e38;
u32 var80094e3c;
u32 var80094e40;
u32 var80094e44;
u32 var80094e48;
u32 var80094e4c;
u32 var80094e50;
u32 var80094e54;
u32 var80094e58;
u32 var80094e5c;
u32 var80094e60;
u32 var80094e64;
u32 var80094e68;
u32 var80094e6c;
u32 var80094e70;
u32 var80094e74;
u32 var80094e78;
u32 var80094e7c;
u32 var80094e80;
u32 var80094e84;
OSMesgQueue g_DmaMesgQueue;

u8 g_LoadType = 0;

void dmaInit(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_DmaSlotsBusy); i++) {
		g_DmaSlotsBusy[i] = 0;
	}

	g_DmaNumSlotsBusy = 0;

	osCreateMesgQueue(&g_DmaMesgQueue, &var80094e08, 0x20);
}

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel dmaStart
/*     d728:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*     d72c:	3c010200 */ 	lui	$at,0x200
/*     d730:	afb40038 */ 	sw	$s4,0x38($sp)
/*     d734:	afb30034 */ 	sw	$s3,0x34($sp)
/*     d738:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d73c:	00a1082b */ 	sltu	$at,$a1,$at
/*     d740:	00c08025 */ 	or	$s0,$a2,$zero
/*     d744:	00a09825 */ 	or	$s3,$a1,$zero
/*     d748:	0080a025 */ 	or	$s4,$a0,$zero
/*     d74c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*     d750:	afbe0048 */ 	sw	$s8,0x48($sp)
/*     d754:	afb70044 */ 	sw	$s7,0x44($sp)
/*     d758:	afb60040 */ 	sw	$s6,0x40($sp)
/*     d75c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*     d760:	afb20030 */ 	sw	$s2,0x30($sp)
/*     d764:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     d768:	14200006 */ 	bnez	$at,.NB0000d784
/*     d76c:	afa70064 */ 	sw	$a3,0x64($sp)
/*     d770:	3c047005 */ 	lui	$a0,0x7005
/*     d774:	0c003074 */ 	jal	func0000c1d0nb
/*     d778:	248442d0 */ 	addiu	$a0,$a0,0x42d0
/*     d77c:	240e0045 */ 	addiu	$t6,$zero,0x45
/*     d780:	a00e0000 */ 	sb	$t6,0x0($zero)
.NB0000d784:
/*     d784:	3c178009 */ 	lui	$s7,0x8009
/*     d788:	26f77a60 */ 	addiu	$s7,$s7,0x7a60
/*     d78c:	8eef0000 */ 	lw	$t7,0x0($s7)
/*     d790:	51e00004 */ 	beqzl	$t7,.NB0000d7a4
/*     d794:	3c010008 */ 	lui	$at,0x8
/*     d798:	0c003634 */ 	jal	dmaWait
/*     d79c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d7a0:	3c010008 */ 	lui	$at,0x8
.NB0000d7a4:
/*     d7a4:	0201082b */ 	sltu	$at,$s0,$at
/*     d7a8:	10200005 */ 	beqz	$at,.NB0000d7c0
/*     d7ac:	02802025 */ 	or	$a0,$s4,$zero
/*     d7b0:	32183fff */ 	andi	$t8,$s0,0x3fff
/*     d7b4:	0010f382 */ 	srl	$s8,$s0,0xe
/*     d7b8:	10000003 */ 	beqz	$zero,.NB0000d7c8
/*     d7bc:	afb80050 */ 	sw	$t8,0x50($sp)
.NB0000d7c0:
/*     d7c0:	0000f025 */ 	or	$s8,$zero,$zero
/*     d7c4:	afb00050 */ 	sw	$s0,0x50($sp)
.NB0000d7c8:
/*     d7c8:	0c013e48 */ 	jal	osInvalDCache
/*     d7cc:	02002825 */ 	or	$a1,$s0,$zero
/*     d7d0:	13c0001b */ 	beqz	$s8,.NB0000d840
/*     d7d4:	00009025 */ 	or	$s2,$zero,$zero
/*     d7d8:	3c108009 */ 	lui	$s0,0x8009
/*     d7dc:	3c118009 */ 	lui	$s1,0x8009
/*     d7e0:	3c168009 */ 	lui	$s6,0x8009
/*     d7e4:	26d67e08 */ 	addiu	$s6,$s6,0x7e08
/*     d7e8:	26317a68 */ 	addiu	$s1,$s1,0x7a68
/*     d7ec:	26107d68 */ 	addiu	$s0,$s0,0x7d68
/*     d7f0:	24150001 */ 	addiu	$s5,$zero,0x1
.NB0000d7f4:
/*     d7f4:	a2150000 */ 	sb	$s5,0x0($s0)
/*     d7f8:	8ee20000 */ 	lw	$v0,0x0($s7)
/*     d7fc:	24084000 */ 	addiu	$t0,$zero,0x4000
/*     d800:	afa80014 */ 	sw	$t0,0x14($sp)
/*     d804:	24590001 */ 	addiu	$t9,$v0,0x1
/*     d808:	aef90000 */ 	sw	$t9,0x0($s7)
/*     d80c:	02202025 */ 	or	$a0,$s1,$zero
/*     d810:	8fa50064 */ 	lw	$a1,0x64($sp)
/*     d814:	00003025 */ 	or	$a2,$zero,$zero
/*     d818:	02603825 */ 	or	$a3,$s3,$zero
/*     d81c:	afb40010 */ 	sw	$s4,0x10($sp)
/*     d820:	0c013e74 */ 	jal	osPiStartDma
/*     d824:	afb60018 */ 	sw	$s6,0x18($sp)
/*     d828:	26520001 */ 	addiu	$s2,$s2,0x1
/*     d82c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d830:	26310018 */ 	addiu	$s1,$s1,0x18
/*     d834:	26734000 */ 	addiu	$s3,$s3,0x4000
/*     d838:	165effee */ 	bne	$s2,$s8,.NB0000d7f4
/*     d83c:	26944000 */ 	addiu	$s4,$s4,0x4000
.NB0000d840:
/*     d840:	8fa30050 */ 	lw	$v1,0x50($sp)
/*     d844:	3c168009 */ 	lui	$s6,0x8009
/*     d848:	26d67e08 */ 	addiu	$s6,$s6,0x7e08
/*     d84c:	10600014 */ 	beqz	$v1,.NB0000d8a0
/*     d850:	24150001 */ 	addiu	$s5,$zero,0x1
/*     d854:	3c018009 */ 	lui	$at,0x8009
/*     d858:	00320821 */ 	addu	$at,$at,$s2
/*     d85c:	a0357d68 */ 	sb	$s5,0x7d68($at)
/*     d860:	8ee20000 */ 	lw	$v0,0x0($s7)
/*     d864:	00125080 */ 	sll	$t2,$s2,0x2
/*     d868:	01525023 */ 	subu	$t2,$t2,$s2
/*     d86c:	3c0b8009 */ 	lui	$t3,0x8009
/*     d870:	256b7a68 */ 	addiu	$t3,$t3,0x7a68
/*     d874:	000a50c0 */ 	sll	$t2,$t2,0x3
/*     d878:	24490001 */ 	addiu	$t1,$v0,0x1
/*     d87c:	aee90000 */ 	sw	$t1,0x0($s7)
/*     d880:	014b2021 */ 	addu	$a0,$t2,$t3
/*     d884:	8fa50064 */ 	lw	$a1,0x64($sp)
/*     d888:	00003025 */ 	or	$a2,$zero,$zero
/*     d88c:	02603825 */ 	or	$a3,$s3,$zero
/*     d890:	afb40010 */ 	sw	$s4,0x10($sp)
/*     d894:	afa30014 */ 	sw	$v1,0x14($sp)
/*     d898:	0c013e74 */ 	jal	osPiStartDma
/*     d89c:	afb60018 */ 	sw	$s6,0x18($sp)
.NB0000d8a0:
/*     d8a0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*     d8a4:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     d8a8:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     d8ac:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     d8b0:	8fb30034 */ 	lw	$s3,0x34($sp)
/*     d8b4:	8fb40038 */ 	lw	$s4,0x38($sp)
/*     d8b8:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*     d8bc:	8fb60040 */ 	lw	$s6,0x40($sp)
/*     d8c0:	8fb70044 */ 	lw	$s7,0x44($sp)
/*     d8c4:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*     d8c8:	03e00008 */ 	jr	$ra
/*     d8cc:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
#endif

#if VERSION >= VERSION_NTSC_1_0
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
	if (g_LoadType != LOADTYPE_NONE && len > 128) {
#if PIRACYCHECKS
		u32 value = xorDeadbeef((PAL ? 0x0109082b : 0x0330c820) ^ 0xdeadbeef);
		u32 *ptr = (u32 *)memaddr;
		u32 data;
		u32 devaddr;
		s32 i;

		for (i = 0; i < 8; i++) {
			ptr[i] ^= value;
		}

		devaddr = xorDeadbabe((PAL ? 0xb0000454 : 0xb0000340) ^ 0xdeadbabe);

		osPiReadIo(devaddr, &data);

		for (i = 0; i < 8; i++) {
			ptr[i] ^= data;
		}
#endif

		g_LoadType = LOADTYPE_NONE;
	}
}
#endif

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
#if VERSION >= VERSION_NTSC_1_0
	dmaCheckPiracy(memaddr, len);
#endif
}

void dmaExecHighPriority(void *memaddr, void *romaddr, u32 len)
{
	dmaStart(memaddr, (u32) romaddr, len, true);
	dmaWait();
#if VERSION >= VERSION_NTSC_1_0
	dmaCheckPiracy(memaddr, len);
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
void *dmaExecWithAutoAlign(void *memaddr, u32 romaddr, u32 len)
{
	u32 alignedrom = ALIGN2(romaddr);
	u32 alignedmem = ALIGN16((u32)memaddr);
	u32 offset = romaddr - alignedrom; // 0 or 1
	u32 alignedlen = ALIGN16(offset + len);

	if (len == 0) {
		return (void *)(alignedmem + offset);
	}

	dmaExec((void *)alignedmem, (void *)alignedrom, alignedlen);

	return (void *)(alignedmem + offset);
}
