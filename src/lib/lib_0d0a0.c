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
u32 var8005d9a4 = 0x00000000;
u32 var8005d9a8 = 0x00000000;
u32 var8005d9ac = 0x00000000;

GLOBAL_ASM(
glabel func0000d0a0
/*     d0a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     d0a4:	3c028009 */ 	lui	$v0,%hi(var80094de8)
/*     d0a8:	3c038009 */ 	lui	$v1,%hi(var80094e08)
/*     d0ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     d0b0:	24634e08 */ 	addiu	$v1,$v1,%lo(var80094e08)
/*     d0b4:	24424de8 */ 	addiu	$v0,$v0,%lo(var80094de8)
.L0000d0b8:
/*     d0b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*     d0bc:	1443fffe */ 	bne	$v0,$v1,.L0000d0b8
/*     d0c0:	a040ffff */ 	sb	$zero,-0x1($v0)
/*     d0c4:	3c0e8009 */ 	lui	$t6,%hi(var80094ae0)
/*     d0c8:	25ce4ae0 */ 	addiu	$t6,$t6,%lo(var80094ae0)
/*     d0cc:	3c048009 */ 	lui	$a0,%hi(var80094e88)
/*     d0d0:	3c058009 */ 	lui	$a1,%hi(var80094e08)
/*     d0d4:	adc00000 */ 	sw	$zero,0x0($t6)
/*     d0d8:	24a54e08 */ 	addiu	$a1,$a1,%lo(var80094e08)
/*     d0dc:	24844e88 */ 	addiu	$a0,$a0,%lo(var80094e88)
/*     d0e0:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     d0e4:	24060020 */ 	addiu	$a2,$zero,0x20
/*     d0e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     d0ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     d0f0:	03e00008 */ 	jr	$ra
/*     d0f4:	00000000 */ 	nop
);

// Mismatch: The store to var80094ae0 is done differently.
//void func0000d0a0(void)
//{
//	s32 i;
//
//	for (i = 0; i < ARRAYCOUNT(var80094de8); i++) {
//		var80094de8[i] = 0;
//	}
//
//	var80094ae0 = 0;
//
//	osCreateMesgQueue(&var80094e88, &var80094e08, 0x20);
//}

GLOBAL_ASM(
glabel func0000d0f8
/*     d0f8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*     d0fc:	afb70044 */ 	sw	$s7,0x44($sp)
/*     d100:	3c178009 */ 	lui	$s7,%hi(var80094ae0)
/*     d104:	26f74ae0 */ 	addiu	$s7,$s7,%lo(var80094ae0)
/*     d108:	8eee0000 */ 	lw	$t6,0x0($s7)
/*     d10c:	afb40038 */ 	sw	$s4,0x38($sp)
/*     d110:	afb30034 */ 	sw	$s3,0x34($sp)
/*     d114:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d118:	00c08025 */ 	or	$s0,$a2,$zero
/*     d11c:	00809825 */ 	or	$s3,$a0,$zero
/*     d120:	00a0a025 */ 	or	$s4,$a1,$zero
/*     d124:	afbf004c */ 	sw	$ra,0x4c($sp)
/*     d128:	afbe0048 */ 	sw	$s8,0x48($sp)
/*     d12c:	afb60040 */ 	sw	$s6,0x40($sp)
/*     d130:	afb5003c */ 	sw	$s5,0x3c($sp)
/*     d134:	afb20030 */ 	sw	$s2,0x30($sp)
/*     d138:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     d13c:	11c00003 */ 	beqz	$t6,.L0000d14c
/*     d140:	afa70064 */ 	sw	$a3,0x64($sp)
/*     d144:	0c0034d4 */ 	jal	func0000d350
/*     d148:	00000000 */ 	nop
.L0000d14c:
/*     d14c:	3c010008 */ 	lui	$at,0x8
/*     d150:	0201082b */ 	sltu	$at,$s0,$at
/*     d154:	10200005 */ 	beqz	$at,.L0000d16c
/*     d158:	02602025 */ 	or	$a0,$s3,$zero
/*     d15c:	320f3fff */ 	andi	$t7,$s0,0x3fff
/*     d160:	0010f382 */ 	srl	$s8,$s0,0xe
/*     d164:	10000003 */ 	b	.L0000d174
/*     d168:	afaf0050 */ 	sw	$t7,0x50($sp)
.L0000d16c:
/*     d16c:	0000f025 */ 	or	$s8,$zero,$zero
/*     d170:	afb00050 */ 	sw	$s0,0x50($sp)
.L0000d174:
/*     d174:	0c013920 */ 	jal	osInvalDCache
/*     d178:	02002825 */ 	or	$a1,$s0,$zero
/*     d17c:	13c0001b */ 	beqz	$s8,.L0000d1ec
/*     d180:	00009025 */ 	or	$s2,$zero,$zero
/*     d184:	3c108009 */ 	lui	$s0,%hi(var80094de8)
/*     d188:	3c118009 */ 	lui	$s1,%hi(var80094ae8)
/*     d18c:	3c168009 */ 	lui	$s6,%hi(var80094e88)
/*     d190:	26d64e88 */ 	addiu	$s6,$s6,%lo(var80094e88)
/*     d194:	26314ae8 */ 	addiu	$s1,$s1,%lo(var80094ae8)
/*     d198:	26104de8 */ 	addiu	$s0,$s0,%lo(var80094de8)
/*     d19c:	24150001 */ 	addiu	$s5,$zero,0x1
.L0000d1a0:
/*     d1a0:	a2150000 */ 	sb	$s5,0x0($s0)
/*     d1a4:	8ee20000 */ 	lw	$v0,0x0($s7)
/*     d1a8:	24194000 */ 	addiu	$t9,$zero,0x4000
/*     d1ac:	afb90014 */ 	sw	$t9,0x14($sp)
/*     d1b0:	24580001 */ 	addiu	$t8,$v0,0x1
/*     d1b4:	aef80000 */ 	sw	$t8,0x0($s7)
/*     d1b8:	02202025 */ 	or	$a0,$s1,$zero
/*     d1bc:	8fa50064 */ 	lw	$a1,0x64($sp)
/*     d1c0:	00003025 */ 	or	$a2,$zero,$zero
/*     d1c4:	02803825 */ 	or	$a3,$s4,$zero
/*     d1c8:	afb30010 */ 	sw	$s3,0x10($sp)
/*     d1cc:	0c01394c */ 	jal	osPiStartDma
/*     d1d0:	afb60018 */ 	sw	$s6,0x18($sp)
/*     d1d4:	26520001 */ 	addiu	$s2,$s2,0x1
/*     d1d8:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d1dc:	26310018 */ 	addiu	$s1,$s1,0x18
/*     d1e0:	26944000 */ 	addiu	$s4,$s4,0x4000
/*     d1e4:	165effee */ 	bne	$s2,$s8,.L0000d1a0
/*     d1e8:	26734000 */ 	addiu	$s3,$s3,0x4000
.L0000d1ec:
/*     d1ec:	8fa30050 */ 	lw	$v1,0x50($sp)
/*     d1f0:	3c168009 */ 	lui	$s6,%hi(var80094e88)
/*     d1f4:	26d64e88 */ 	addiu	$s6,$s6,%lo(var80094e88)
/*     d1f8:	10600014 */ 	beqz	$v1,.L0000d24c
/*     d1fc:	24150001 */ 	addiu	$s5,$zero,0x1
/*     d200:	3c018009 */ 	lui	$at,%hi(var80094de8)
/*     d204:	00320821 */ 	addu	$at,$at,$s2
/*     d208:	a0354de8 */ 	sb	$s5,%lo(var80094de8)($at)
/*     d20c:	8ee20000 */ 	lw	$v0,0x0($s7)
/*     d210:	00124880 */ 	sll	$t1,$s2,0x2
/*     d214:	01324823 */ 	subu	$t1,$t1,$s2
/*     d218:	3c0a8009 */ 	lui	$t2,%hi(var80094ae8)
/*     d21c:	254a4ae8 */ 	addiu	$t2,$t2,%lo(var80094ae8)
/*     d220:	000948c0 */ 	sll	$t1,$t1,0x3
/*     d224:	24480001 */ 	addiu	$t0,$v0,0x1
/*     d228:	aee80000 */ 	sw	$t0,0x0($s7)
/*     d22c:	012a2021 */ 	addu	$a0,$t1,$t2
/*     d230:	8fa50064 */ 	lw	$a1,0x64($sp)
/*     d234:	00003025 */ 	or	$a2,$zero,$zero
/*     d238:	02803825 */ 	or	$a3,$s4,$zero
/*     d23c:	afb30010 */ 	sw	$s3,0x10($sp)
/*     d240:	afa30014 */ 	sw	$v1,0x14($sp)
/*     d244:	0c01394c */ 	jal	osPiStartDma
/*     d248:	afb60018 */ 	sw	$s6,0x18($sp)
.L0000d24c:
/*     d24c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*     d250:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     d254:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     d258:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     d25c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*     d260:	8fb40038 */ 	lw	$s4,0x38($sp)
/*     d264:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*     d268:	8fb60040 */ 	lw	$s6,0x40($sp)
/*     d26c:	8fb70044 */ 	lw	$s7,0x44($sp)
/*     d270:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*     d274:	03e00008 */ 	jr	$ra
/*     d278:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

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

void func0000d350(void)
{
	u32 stack;
	struct var80094ae8 *msg;
	s32 i;

	while (var80094ae0) {
		osRecvMesg(&var80094e88, (OSMesg) &msg, OS_MESG_BLOCK);

		for (i = 0; i < ARRAYCOUNT(var80094ae8); i++) {
			if (&var80094ae8[i] == msg) {
				break;
			}
		}

		var80094de8[i] = 0;
		var80094ae0--;
	}
}

void func0000d410(void *memaddr, void *romaddr, u32 len)
{
	func0000d0f8(memaddr, romaddr, len, false);
	func0000d350();
	dmaCheckPiracy(memaddr, len);
}

void func0000d44c(void *memaddr, void *romaddr, u32 len)
{
	func0000d0f8(memaddr, romaddr, len, true);
	func0000d350();
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
/*     d4f8:	0c003504 */ 	jal	func0000d410
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
