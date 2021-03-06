#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/room.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_0bfb0.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_126b0.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

u32 *savefileGetFlags(void)
{
	return &g_SoloSaveFile.flags;
}

void savefileSetFlag(u32 value)
{
	bitSetByIndex(value, &g_SoloSaveFile.flags, true);
}

void savefileUnsetFlag(u32 value)
{
	bitSetByIndex(value, &g_SoloSaveFile.flags, false);
}

u32 savefileHasFlag(u32 value)
{
	return bitGetByIndex(value, &g_SoloSaveFile.flags);
}

void savefilePrintFlags(void)
{
	s32 i;

	for (i = 0x23; i != 0x4f; i++) {
		osSyncPrintf("Flag %d = %s", i,
				bitGetByIndex(i, &g_SoloSaveFile.flags) ? "TRUE" : "FALSE");
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel savefileApplyOptions
/*  f10fb94:	3c03800a */ 	lui	$v1,0x800a
/*  f10fb98:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f10fb9c:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10fba0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10fba4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10fba8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10fbac:	04410005 */ 	bgez	$v0,.PF0f10fbc4
/*  f10fbb0:	00803025 */ 	move	$a2,$a0
/*  f10fbb4:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10fbb8:	240f0004 */ 	li	$t7,0x4
/*  f10fbbc:	05c20004 */ 	bltzl	$t6,.PF0f10fbd0
/*  f10fbc0:	afaf0024 */ 	sw	$t7,0x24($sp)
.PF0f10fbc4:
/*  f10fbc4:	10000002 */ 	b	.PF0f10fbd0
/*  f10fbc8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10fbcc:	afaf0024 */ 	sw	$t7,0x24($sp)
.PF0f10fbd0:
/*  f10fbd0:	04410004 */ 	bgez	$v0,.PF0f10fbe4
/*  f10fbd4:	00002025 */ 	move	$a0,$zero
/*  f10fbd8:	8c78029c */ 	lw	$t8,0x29c($v1)
/*  f10fbdc:	24080005 */ 	li	$t0,0x5
/*  f10fbe0:	07000003 */ 	bltz	$t8,.PF0f10fbf0
.PF0f10fbe4:
/*  f10fbe4:	24190001 */ 	li	$t9,0x1
/*  f10fbe8:	10000002 */ 	b	.PF0f10fbf4
/*  f10fbec:	afb90020 */ 	sw	$t9,0x20($sp)
.PF0f10fbf0:
/*  f10fbf0:	afa80020 */ 	sw	$t0,0x20($sp)
.PF0f10fbf4:
/*  f10fbf4:	24d00014 */ 	addiu	$s0,$a2,0x14
/*  f10fbf8:	0fc47c20 */ 	jal	0xf11f080
/*  f10fbfc:	02002825 */ 	move	$a1,$s0
/*  f10fc00:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc04:	0fc54d7e */ 	jal	0xf1535f8
/*  f10fc08:	00402825 */ 	move	$a1,$v0
/*  f10fc0c:	24040001 */ 	li	$a0,0x1
/*  f10fc10:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc14:	02002825 */ 	move	$a1,$s0
/*  f10fc18:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc1c:	0fc54d94 */ 	jal	0xf153650
/*  f10fc20:	00402825 */ 	move	$a1,$v0
/*  f10fc24:	24040002 */ 	li	$a0,0x2
/*  f10fc28:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc2c:	02002825 */ 	move	$a1,$s0
/*  f10fc30:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc34:	0fc54dc0 */ 	jal	0xf153700
/*  f10fc38:	00402825 */ 	move	$a1,$v0
/*  f10fc3c:	24040003 */ 	li	$a0,0x3
/*  f10fc40:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc44:	02002825 */ 	move	$a1,$s0
/*  f10fc48:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc4c:	0fc54dd6 */ 	jal	0xf153758
/*  f10fc50:	00402825 */ 	move	$a1,$v0
/*  f10fc54:	24040004 */ 	li	$a0,0x4
/*  f10fc58:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc5c:	02002825 */ 	move	$a1,$s0
/*  f10fc60:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc64:	0fc54daa */ 	jal	0xf1536a8
/*  f10fc68:	00402825 */ 	move	$a1,$v0
/*  f10fc6c:	24040005 */ 	li	$a0,0x5
/*  f10fc70:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc74:	02002825 */ 	move	$a1,$s0
/*  f10fc78:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc7c:	0fc54dec */ 	jal	0xf1537b0
/*  f10fc80:	00402825 */ 	move	$a1,$v0
/*  f10fc84:	24040009 */ 	li	$a0,0x9
/*  f10fc88:	0fc47c20 */ 	jal	0xf11f080
/*  f10fc8c:	02002825 */ 	move	$a1,$s0
/*  f10fc90:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc94:	0fc54e76 */ 	jal	0xf1539d8
/*  f10fc98:	00402825 */ 	move	$a1,$v0
/*  f10fc9c:	2404000a */ 	li	$a0,0xa
/*  f10fca0:	0fc47c20 */ 	jal	0xf11f080
/*  f10fca4:	02002825 */ 	move	$a1,$s0
/*  f10fca8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcac:	0fc54e02 */ 	jal	0xf153808
/*  f10fcb0:	00402825 */ 	move	$a1,$v0
/*  f10fcb4:	24040015 */ 	li	$a0,0x15
/*  f10fcb8:	0fc47c20 */ 	jal	0xf11f080
/*  f10fcbc:	02002825 */ 	move	$a1,$s0
/*  f10fcc0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcc4:	0fc54e18 */ 	jal	0xf153860
/*  f10fcc8:	00402825 */ 	move	$a1,$v0
/*  f10fccc:	24040017 */ 	li	$a0,0x17
/*  f10fcd0:	0fc47c20 */ 	jal	0xf11f080
/*  f10fcd4:	02002825 */ 	move	$a1,$s0
/*  f10fcd8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcdc:	0fc54e2e */ 	jal	0xf1538b8
/*  f10fce0:	00402825 */ 	move	$a1,$v0
/*  f10fce4:	2404001a */ 	li	$a0,0x1a
/*  f10fce8:	0fc47c20 */ 	jal	0xf11f080
/*  f10fcec:	02002825 */ 	move	$a1,$s0
/*  f10fcf0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcf4:	0fc54e5a */ 	jal	0xf153968
/*  f10fcf8:	00402825 */ 	move	$a1,$v0
/*  f10fcfc:	24040020 */ 	li	$a0,0x20
/*  f10fd00:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd04:	02002825 */ 	move	$a1,$s0
/*  f10fd08:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fd0c:	0fc54e44 */ 	jal	0xf153910
/*  f10fd10:	00402825 */ 	move	$a1,$v0
/*  f10fd14:	2404000c */ 	li	$a0,0xc
/*  f10fd18:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd1c:	02002825 */ 	move	$a1,$s0
/*  f10fd20:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd24:	0fc54d7e */ 	jal	0xf1535f8
/*  f10fd28:	00402825 */ 	move	$a1,$v0
/*  f10fd2c:	2404000d */ 	li	$a0,0xd
/*  f10fd30:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd34:	02002825 */ 	move	$a1,$s0
/*  f10fd38:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd3c:	0fc54d94 */ 	jal	0xf153650
/*  f10fd40:	00402825 */ 	move	$a1,$v0
/*  f10fd44:	2404000e */ 	li	$a0,0xe
/*  f10fd48:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd4c:	02002825 */ 	move	$a1,$s0
/*  f10fd50:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd54:	0fc54dc0 */ 	jal	0xf153700
/*  f10fd58:	00402825 */ 	move	$a1,$v0
/*  f10fd5c:	2404000f */ 	li	$a0,0xf
/*  f10fd60:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd64:	02002825 */ 	move	$a1,$s0
/*  f10fd68:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd6c:	0fc54dd6 */ 	jal	0xf153758
/*  f10fd70:	00402825 */ 	move	$a1,$v0
/*  f10fd74:	24040010 */ 	li	$a0,0x10
/*  f10fd78:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd7c:	02002825 */ 	move	$a1,$s0
/*  f10fd80:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd84:	0fc54daa */ 	jal	0xf1536a8
/*  f10fd88:	00402825 */ 	move	$a1,$v0
/*  f10fd8c:	24040011 */ 	li	$a0,0x11
/*  f10fd90:	0fc47c20 */ 	jal	0xf11f080
/*  f10fd94:	02002825 */ 	move	$a1,$s0
/*  f10fd98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd9c:	0fc54dec */ 	jal	0xf1537b0
/*  f10fda0:	00402825 */ 	move	$a1,$v0
/*  f10fda4:	24040012 */ 	li	$a0,0x12
/*  f10fda8:	0fc47c20 */ 	jal	0xf11f080
/*  f10fdac:	02002825 */ 	move	$a1,$s0
/*  f10fdb0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdb4:	0fc54e76 */ 	jal	0xf1539d8
/*  f10fdb8:	00402825 */ 	move	$a1,$v0
/*  f10fdbc:	24040013 */ 	li	$a0,0x13
/*  f10fdc0:	0fc47c20 */ 	jal	0xf11f080
/*  f10fdc4:	02002825 */ 	move	$a1,$s0
/*  f10fdc8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdcc:	0fc54e02 */ 	jal	0xf153808
/*  f10fdd0:	00402825 */ 	move	$a1,$v0
/*  f10fdd4:	24040016 */ 	li	$a0,0x16
/*  f10fdd8:	0fc47c20 */ 	jal	0xf11f080
/*  f10fddc:	02002825 */ 	move	$a1,$s0
/*  f10fde0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fde4:	0fc54e18 */ 	jal	0xf153860
/*  f10fde8:	00402825 */ 	move	$a1,$v0
/*  f10fdec:	24040018 */ 	li	$a0,0x18
/*  f10fdf0:	0fc47c20 */ 	jal	0xf11f080
/*  f10fdf4:	02002825 */ 	move	$a1,$s0
/*  f10fdf8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdfc:	0fc54e2e */ 	jal	0xf1538b8
/*  f10fe00:	00402825 */ 	move	$a1,$v0
/*  f10fe04:	2404001b */ 	li	$a0,0x1b
/*  f10fe08:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe0c:	02002825 */ 	move	$a1,$s0
/*  f10fe10:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe14:	0fc54e5a */ 	jal	0xf153968
/*  f10fe18:	00402825 */ 	move	$a1,$v0
/*  f10fe1c:	24040021 */ 	li	$a0,0x21
/*  f10fe20:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe24:	02002825 */ 	move	$a1,$s0
/*  f10fe28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe2c:	0fc54e44 */ 	jal	0xf153910
/*  f10fe30:	00402825 */ 	move	$a1,$v0
/*  f10fe34:	2404000b */ 	li	$a0,0xb
/*  f10fe38:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe3c:	02002825 */ 	move	$a1,$s0
/*  f10fe40:	0fc54e70 */ 	jal	0xf1539c0
/*  f10fe44:	00402025 */ 	move	$a0,$v0
/*  f10fe48:	24040014 */ 	li	$a0,0x14
/*  f10fe4c:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe50:	02002825 */ 	move	$a1,$s0
/*  f10fe54:	0fc54e73 */ 	jal	0xf1539cc
/*  f10fe58:	00402025 */ 	move	$a0,$v0
/*  f10fe5c:	24040021 */ 	li	$a0,0x21
/*  f10fe60:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe64:	02002825 */ 	move	$a1,$s0
/*  f10fe68:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe6c:	0fc54e44 */ 	jal	0xf153910
/*  f10fe70:	00402825 */ 	move	$a1,$v0
/*  f10fe74:	24040040 */ 	li	$a0,0x40
/*  f10fe78:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe7c:	02002825 */ 	move	$a1,$s0
/*  f10fe80:	3c01800a */ 	lui	$at,0x800a
/*  f10fe84:	a022a9f3 */ 	sb	$v0,-0x560d($at)
/*  f10fe88:	24040022 */ 	li	$a0,0x22
/*  f10fe8c:	0fc47c20 */ 	jal	0xf11f080
/*  f10fe90:	02002825 */ 	move	$a1,$s0
/*  f10fe94:	1040000d */ 	beqz	$v0,.PF0f10fecc
/*  f10fe98:	3c098009 */ 	lui	$t1,0x8009
/*  f10fe9c:	91291040 */ 	lbu	$t1,0x1040($t1)
/*  f10fea0:	24010001 */ 	li	$at,0x1
/*  f10fea4:	15210005 */ 	bne	$t1,$at,.PF0f10febc
/*  f10fea8:	00000000 */ 	nop
/*  f10feac:	0fc2f26f */ 	jal	0xf0bc9bc
/*  f10feb0:	00002025 */ 	move	$a0,$zero
/*  f10feb4:	10000007 */ 	b	.PF0f10fed4
/*  f10feb8:	00000000 */ 	nop
.PF0f10febc:
/*  f10febc:	0fc2f26f */ 	jal	0xf0bc9bc
/*  f10fec0:	24040001 */ 	li	$a0,0x1
/*  f10fec4:	10000003 */ 	b	.PF0f10fed4
/*  f10fec8:	00000000 */ 	nop
.PF0f10fecc:
/*  f10fecc:	0fc2f26f */ 	jal	0xf0bc9bc
/*  f10fed0:	00002025 */ 	move	$a0,$zero
.PF0f10fed4:
/*  f10fed4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f10fed8:	914a1040 */ 	lbu	$t2,0x1040($t2)
/*  f10fedc:	24010001 */ 	li	$at,0x1
/*  f10fee0:	55410008 */ 	bnel	$t2,$at,.PF0f10ff04
/*  f10fee4:	24040019 */ 	li	$a0,0x19
/*  f10fee8:	0fc54efc */ 	jal	0xf153bf0
/*  f10feec:	00002025 */ 	move	$a0,$zero
/*  f10fef0:	0fc54ef6 */ 	jal	0xf153bd8
/*  f10fef4:	00002025 */ 	move	$a0,$zero
/*  f10fef8:	1000000c */ 	b	.PF0f10ff2c
/*  f10fefc:	24040008 */ 	li	$a0,0x8
/*  f10ff00:	24040019 */ 	li	$a0,0x19
.PF0f10ff04:
/*  f10ff04:	0fc47c20 */ 	jal	0xf11f080
/*  f10ff08:	02002825 */ 	move	$a1,$s0
/*  f10ff0c:	0fc54efc */ 	jal	0xf153bf0
/*  f10ff10:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10ff14:	24040007 */ 	li	$a0,0x7
/*  f10ff18:	0fc47c20 */ 	jal	0xf11f080
/*  f10ff1c:	02002825 */ 	move	$a1,$s0
/*  f10ff20:	0fc54ef6 */ 	jal	0xf153bd8
/*  f10ff24:	00402025 */ 	move	$a0,$v0
/*  f10ff28:	24040008 */ 	li	$a0,0x8
.PF0f10ff2c:
/*  f10ff2c:	0fc47c20 */ 	jal	0xf11f080
/*  f10ff30:	02002825 */ 	move	$a1,$s0
/*  f10ff34:	50400006 */ 	beqzl	$v0,.PF0f10ff50
/*  f10ff38:	24040006 */ 	li	$a0,0x6
/*  f10ff3c:	0fc54ef0 */ 	jal	0xf153bc0
/*  f10ff40:	24040002 */ 	li	$a0,0x2
/*  f10ff44:	1000000d */ 	b	.PF0f10ff7c
/*  f10ff48:	2404001f */ 	li	$a0,0x1f
/*  f10ff4c:	24040006 */ 	li	$a0,0x6
.PF0f10ff50:
/*  f10ff50:	0fc47c20 */ 	jal	0xf11f080
/*  f10ff54:	02002825 */ 	move	$a1,$s0
/*  f10ff58:	10400005 */ 	beqz	$v0,.PF0f10ff70
/*  f10ff5c:	00000000 */ 	nop
/*  f10ff60:	0fc54ef0 */ 	jal	0xf153bc0
/*  f10ff64:	24040001 */ 	li	$a0,0x1
/*  f10ff68:	10000004 */ 	b	.PF0f10ff7c
/*  f10ff6c:	2404001f */ 	li	$a0,0x1f
.PF0f10ff70:
/*  f10ff70:	0fc54ef0 */ 	jal	0xf153bc0
/*  f10ff74:	00002025 */ 	move	$a0,$zero
/*  f10ff78:	2404001f */ 	li	$a0,0x1f
.PF0f10ff7c:
/*  f10ff7c:	0fc47c20 */ 	jal	0xf11f080
/*  f10ff80:	02002825 */ 	move	$a1,$s0
/*  f10ff84:	10400005 */ 	beqz	$v0,.PF0f10ff9c
/*  f10ff88:	2404001c */ 	li	$a0,0x1c
/*  f10ff8c:	240b0001 */ 	li	$t3,0x1
/*  f10ff90:	3c01800a */ 	lui	$at,0x800a
/*  f10ff94:	10000003 */ 	b	.PF0f10ffa4
/*  f10ff98:	ac2ba960 */ 	sw	$t3,-0x56a0($at)
.PF0f10ff9c:
/*  f10ff9c:	3c01800a */ 	lui	$at,0x800a
/*  f10ffa0:	ac20a960 */ 	sw	$zero,-0x56a0($at)
.PF0f10ffa4:
/*  f10ffa4:	0fc47c20 */ 	jal	0xf11f080
/*  f10ffa8:	02002825 */ 	move	$a1,$s0
/*  f10ffac:	10400005 */ 	beqz	$v0,.PF0f10ffc4
/*  f10ffb0:	2404001d */ 	li	$a0,0x1d
/*  f10ffb4:	240c0001 */ 	li	$t4,0x1
/*  f10ffb8:	3c01800a */ 	lui	$at,0x800a
/*  f10ffbc:	10000003 */ 	b	.PF0f10ffcc
/*  f10ffc0:	ac2ca958 */ 	sw	$t4,-0x56a8($at)
.PF0f10ffc4:
/*  f10ffc4:	3c01800a */ 	lui	$at,0x800a
/*  f10ffc8:	ac20a958 */ 	sw	$zero,-0x56a8($at)
.PF0f10ffcc:
/*  f10ffcc:	0fc47c20 */ 	jal	0xf11f080
/*  f10ffd0:	02002825 */ 	move	$a1,$s0
/*  f10ffd4:	10400005 */ 	beqz	$v0,.PF0f10ffec
/*  f10ffd8:	2404001e */ 	li	$a0,0x1e
/*  f10ffdc:	240d0001 */ 	li	$t5,0x1
/*  f10ffe0:	3c01800a */ 	lui	$at,0x800a
/*  f10ffe4:	10000003 */ 	b	.PF0f10fff4
/*  f10ffe8:	ac2da964 */ 	sw	$t5,-0x569c($at)
.PF0f10ffec:
/*  f10ffec:	3c01800a */ 	lui	$at,0x800a
/*  f10fff0:	ac20a964 */ 	sw	$zero,-0x569c($at)
.PF0f10fff4:
/*  f10fff4:	0fc47c20 */ 	jal	0xf11f080
/*  f10fff8:	02002825 */ 	move	$a1,$s0
/*  f10fffc:	10400005 */ 	beqz	$v0,.PF0f110014
/*  f110000:	24040044 */ 	li	$a0,0x44
/*  f110004:	240e0001 */ 	li	$t6,0x1
/*  f110008:	3c01800a */ 	lui	$at,0x800a
/*  f11000c:	10000003 */ 	b	.PF0f11001c
/*  f110010:	ac2ea95c */ 	sw	$t6,-0x56a4($at)
.PF0f110014:
/*  f110014:	3c01800a */ 	lui	$at,0x800a
/*  f110018:	ac20a95c */ 	sw	$zero,-0x56a4($at)
.PF0f11001c:
/*  f11001c:	3c01800a */ 	lui	$at,0x800a
/*  f110020:	a420a992 */ 	sh	$zero,-0x566e($at)
/*  f110024:	0fc47c20 */ 	jal	0xf11f080
/*  f110028:	02002825 */ 	move	$a1,$s0
/*  f11002c:	10400006 */ 	beqz	$v0,.PF0f110048
/*  f110030:	24040045 */ 	li	$a0,0x45
/*  f110034:	3c0f800a */ 	lui	$t7,0x800a
/*  f110038:	95efa992 */ 	lhu	$t7,-0x566e($t7)
/*  f11003c:	3c01800a */ 	lui	$at,0x800a
/*  f110040:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f110044:	a438a992 */ 	sh	$t8,-0x566e($at)
.PF0f110048:
/*  f110048:	0fc47c20 */ 	jal	0xf11f080
/*  f11004c:	02002825 */ 	move	$a1,$s0
/*  f110050:	10400006 */ 	beqz	$v0,.PF0f11006c
/*  f110054:	24040046 */ 	li	$a0,0x46
/*  f110058:	3c19800a */ 	lui	$t9,0x800a
/*  f11005c:	9739a992 */ 	lhu	$t9,-0x566e($t9)
/*  f110060:	3c01800a */ 	lui	$at,0x800a
/*  f110064:	37280002 */ 	ori	$t0,$t9,0x2
/*  f110068:	a428a992 */ 	sh	$t0,-0x566e($at)
.PF0f11006c:
/*  f11006c:	0fc47c20 */ 	jal	0xf11f080
/*  f110070:	02002825 */ 	move	$a1,$s0
/*  f110074:	10400006 */ 	beqz	$v0,.PF0f110090
/*  f110078:	3c04800a */ 	lui	$a0,0x800a
/*  f11007c:	3c09800a */ 	lui	$t1,0x800a
/*  f110080:	9529a992 */ 	lhu	$t1,-0x566e($t1)
/*  f110084:	3c01800a */ 	lui	$at,0x800a
/*  f110088:	352a0004 */ 	ori	$t2,$t1,0x4
/*  f11008c:	a42aa992 */ 	sh	$t2,-0x566e($at)
.PF0f110090:
/*  f110090:	0fc5bdd7 */ 	jal	0xf16f75c
/*  f110094:	9484a992 */ 	lhu	$a0,-0x566e($a0)
/*  f110098:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11009c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1100a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1100a4:	03e00008 */ 	jr	$ra
/*  f1100a8:	00000000 */ 	nop
);
#else
void savefileApplyOptions(struct savefile_solo *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;

	optionsSetForwardPitch(player1, bitGetByIndex(SAVEFILEFLAG_P1_FORWARDPITCH, &file->flags));
	optionsSetAutoAim(player1, bitGetByIndex(SAVEFILEFLAG_P1_AUTOAIM, &file->flags));
	optionsSetAimControl(player1, bitGetByIndex(SAVEFILEFLAG_P1_AIMCONTROL, &file->flags));
	optionsSetSightOnScreen(player1, bitGetByIndex(SAVEFILEFLAG_P1_SIGHTONSCREEN, &file->flags));
	optionsSetLookAhead(player1, bitGetByIndex(SAVEFILEFLAG_P1_LOOKAHEAD, &file->flags));
	optionsSetAmmoOnScreen(player1, bitGetByIndex(SAVEFILEFLAG_P1_AMMOONSCREEN, &file->flags));
	optionsSetHeadRoll(player1, bitGetByIndex(SAVEFILEFLAG_P1_HEADROLL, &file->flags));
	optionsSetShowGunFunction(player1, bitGetByIndex(SAVEFILEFLAG_P1_SHOWGUNFUNCTION, &file->flags));
	optionsSetAlwaysShowTarget(player1, bitGetByIndex(SAVEFILEFLAG_P1_ALWAYSSHOWTARGET, &file->flags));
	optionsSetShowZoomRange(player1, bitGetByIndex(SAVEFILEFLAG_P1_SHOWZOOMRANGE, &file->flags));
	optionsSetShowMissionTime(player1, bitGetByIndex(SAVEFILEFLAG_P1_SHOWMISSIONTIME, &file->flags));
	optionsSetPaintball(player1, bitGetByIndex(SAVEFILEFLAG_P1_PAINTBALL, &file->flags));

	optionsSetForwardPitch(player2, bitGetByIndex(SAVEFILEFLAG_P2_FORWARDPITCH, &file->flags));
	optionsSetAutoAim(player2, bitGetByIndex(SAVEFILEFLAG_P2_AUTOAIM, &file->flags));
	optionsSetAimControl(player2, bitGetByIndex(SAVEFILEFLAG_P2_AIMCONTROL, &file->flags));
	optionsSetSightOnScreen(player2, bitGetByIndex(SAVEFILEFLAG_P2_SIGHTONSCREEN, &file->flags));
	optionsSetLookAhead(player2, bitGetByIndex(SAVEFILEFLAG_P2_LOOKAHEAD, &file->flags));
	optionsSetAmmoOnScreen(player2, bitGetByIndex(SAVEFILEFLAG_P2_AMMOONSCREEN, &file->flags));
	optionsSetHeadRoll(player2, bitGetByIndex(SAVEFILEFLAG_P2_HEADROLL, &file->flags));
	optionsSetShowGunFunction(player2, bitGetByIndex(SAVEFILEFLAG_P2_SHOWGUNFUNCTION, &file->flags));
	optionsSetAlwaysShowTarget(player2, bitGetByIndex(SAVEFILEFLAG_P2_ALWAYSSHOWTARGET, &file->flags));
	optionsSetShowZoomRange(player2, bitGetByIndex(SAVEFILEFLAG_P2_SHOWZOOMRANGE, &file->flags));
	optionsSetShowMissionTime(player2, bitGetByIndex(SAVEFILEFLAG_P2_SHOWMISSIONTIME, &file->flags));
	optionsSetPaintball(player2, bitGetByIndex(SAVEFILEFLAG_P2_PAINTBALL, &file->flags));

	optionsSetInGameSubtitles(bitGetByIndex(SAVEFILEFLAG_INGAMESUBTITLES, &file->flags));
	optionsSetCutsceneSubtitles(bitGetByIndex(SAVEFILEFLAG_CUTSCENESUBTITLES, &file->flags));

	// Duplicate
	optionsSetPaintball(player2, bitGetByIndex(SAVEFILEFLAG_P2_PAINTBALL, &file->flags));

	g_Vars.langfilteron = bitGetByIndex(SAVEFILEFLAG_LANGFILTERON, &file->flags);

	if (bitGetByIndex(SAVEFILEFLAG_HIRES, &file->flags)) {
		if (IS4MB()) {
			optionsSetHiRes(false);
		} else {
			optionsSetHiRes(true);
		}
	} else {
		optionsSetHiRes(false);
	}

	if (IS4MB()) {
		optionsSetScreenSplit(SCREENSPLIT_HORIZONTAL);
		optionsSetScreenRatio(SCREENRATIO_NORMAL);
	} else {
		optionsSetScreenSplit(bitGetByIndex(SAVEFILEFLAG_SCREENSPLIT, &file->flags));
		optionsSetScreenRatio(bitGetByIndex(SAVEFILEFLAG_SCREENRATIO, &file->flags));
	}

	if (bitGetByIndex(SAVEFILEFLAG_SCREENSIZE_CINEMA, &file->flags)) {
		optionsSetScreenSize(SCREENSIZE_CINEMA);
	} else if (bitGetByIndex(SAVEFILEFLAG_SCREENSIZE_WIDE, &file->flags)) {
		optionsSetScreenSize(SCREENSIZE_WIDE);
	} else {
		optionsSetScreenSize(SCREENSIZE_FULL);
	}

	g_Vars.pendingantiplayernum = bitGetByIndex(SAVEFILEFLAG_ANTIPLAYERNUM, &file->flags) ? 1 : 0;
	g_Vars.coopradaron = bitGetByIndex(SAVEFILEFLAG_COOPRADARON, &file->flags) ? 1 : 0;
	g_Vars.coopfriendlyfire = bitGetByIndex(SAVEFILEFLAG_COOPFRIENDLYFIRE, &file->flags) ? 1 : 0;
	g_Vars.antiradaron = bitGetByIndex(SAVEFILEFLAG_ANTIRADARON, &file->flags) ? 1 : 0;
}
#endif

#if VERSION >= VERSION_PAL_FINAL
const char var7f1b4bd0pf[] = "Dark";

GLOBAL_ASM(
glabel savefileLoadDefaults
/*  f1100ac:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1100b0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1100b4:	3c12800a */ 	lui	$s2,0x800a
/*  f1100b8:	2652a510 */ 	addiu	$s2,$s2,-23280
/*  f1100bc:	8e420298 */ 	lw	$v0,0x298($s2)
/*  f1100c0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1100c4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1100c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1100cc:	04410005 */ 	bgez	$v0,.PF0f1100e4
/*  f1100d0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1100d4:	8e4e029c */ 	lw	$t6,0x29c($s2)
/*  f1100d8:	24110004 */ 	li	$s1,0x4
/*  f1100dc:	05c00003 */ 	bltz	$t6,.PF0f1100ec
/*  f1100e0:	00000000 */ 	nop
.PF0f1100e4:
/*  f1100e4:	10000001 */ 	b	.PF0f1100ec
/*  f1100e8:	00008825 */ 	move	$s1,$zero
.PF0f1100ec:
/*  f1100ec:	04410005 */ 	bgez	$v0,.PF0f110104
/*  f1100f0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1100f4:	8e4f029c */ 	lw	$t7,0x29c($s2)
/*  f1100f8:	24100005 */ 	li	$s0,0x5
/*  f1100fc:	05e00003 */ 	bltz	$t7,.PF0f11010c
/*  f110100:	00000000 */ 	nop
.PF0f110104:
/*  f110104:	10000001 */ 	b	.PF0f11010c
/*  f110108:	24100001 */ 	li	$s0,0x1
.PF0f11010c:
/*  f11010c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f110110:	0c004bb0 */ 	jal	0x12ec0
/*  f110114:	24a54bd0 */ 	addiu	$a1,$a1,0x4bd0
/*  f110118:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f11011c:	24045000 */ 	li	$a0,0x5000
/*  f110120:	9058000b */ 	lbu	$t8,0xb($v0)
/*  f110124:	a040000c */ 	sb	$zero,0xc($v0)
/*  f110128:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f11012c:	3308ff07 */ 	andi	$t0,$t8,0xff07
/*  f110130:	310900f8 */ 	andi	$t1,$t0,0xf8
/*  f110134:	a048000b */ 	sb	$t0,0xb($v0)
/*  f110138:	0c0039df */ 	jal	0xe77c
/*  f11013c:	a049000b */ 	sb	$t1,0xb($v0)
/*  f110140:	0fc54f08 */ 	jal	0xf153c20
/*  f110144:	24045000 */ 	li	$a0,0x5000
/*  f110148:	0c003c3b */ 	jal	0xf0ec
/*  f11014c:	24040001 */ 	li	$a0,0x1
/*  f110150:	02202025 */ 	move	$a0,$s1
/*  f110154:	0fc54cf7 */ 	jal	0xf1533dc
/*  f110158:	00002825 */ 	move	$a1,$zero
/*  f11015c:	02002025 */ 	move	$a0,$s0
/*  f110160:	0fc54cf7 */ 	jal	0xf1533dc
/*  f110164:	00002825 */ 	move	$a1,$zero
/*  f110168:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f11016c:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f110170:	0fc47c2e */ 	jal	0xf11f0b8
/*  f110174:	02002025 */ 	move	$a0,$s0
/*  f110178:	00002025 */ 	move	$a0,$zero
/*  f11017c:	02002825 */ 	move	$a1,$s0
/*  f110180:	0fc47c0b */ 	jal	0xf11f02c
/*  f110184:	00003025 */ 	move	$a2,$zero
/*  f110188:	24040001 */ 	li	$a0,0x1
/*  f11018c:	02002825 */ 	move	$a1,$s0
/*  f110190:	0fc47c0b */ 	jal	0xf11f02c
/*  f110194:	24060001 */ 	li	$a2,0x1
/*  f110198:	24040002 */ 	li	$a0,0x2
/*  f11019c:	02002825 */ 	move	$a1,$s0
/*  f1101a0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101a4:	00003025 */ 	move	$a2,$zero
/*  f1101a8:	24040003 */ 	li	$a0,0x3
/*  f1101ac:	02002825 */ 	move	$a1,$s0
/*  f1101b0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101b4:	24060001 */ 	li	$a2,0x1
/*  f1101b8:	24040004 */ 	li	$a0,0x4
/*  f1101bc:	02002825 */ 	move	$a1,$s0
/*  f1101c0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101c4:	24060001 */ 	li	$a2,0x1
/*  f1101c8:	24040005 */ 	li	$a0,0x5
/*  f1101cc:	02002825 */ 	move	$a1,$s0
/*  f1101d0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101d4:	24060001 */ 	li	$a2,0x1
/*  f1101d8:	24040009 */ 	li	$a0,0x9
/*  f1101dc:	02002825 */ 	move	$a1,$s0
/*  f1101e0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101e4:	24060001 */ 	li	$a2,0x1
/*  f1101e8:	2404000a */ 	li	$a0,0xa
/*  f1101ec:	02002825 */ 	move	$a1,$s0
/*  f1101f0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1101f4:	24060001 */ 	li	$a2,0x1
/*  f1101f8:	2404000b */ 	li	$a0,0xb
/*  f1101fc:	02002825 */ 	move	$a1,$s0
/*  f110200:	0fc47c0b */ 	jal	0xf11f02c
/*  f110204:	24060001 */ 	li	$a2,0x1
/*  f110208:	24040015 */ 	li	$a0,0x15
/*  f11020c:	02002825 */ 	move	$a1,$s0
/*  f110210:	0fc47c0b */ 	jal	0xf11f02c
/*  f110214:	24060001 */ 	li	$a2,0x1
/*  f110218:	24040017 */ 	li	$a0,0x17
/*  f11021c:	02002825 */ 	move	$a1,$s0
/*  f110220:	0fc47c0b */ 	jal	0xf11f02c
/*  f110224:	24060001 */ 	li	$a2,0x1
/*  f110228:	2404001a */ 	li	$a0,0x1a
/*  f11022c:	02002825 */ 	move	$a1,$s0
/*  f110230:	0fc47c0b */ 	jal	0xf11f02c
/*  f110234:	00003025 */ 	move	$a2,$zero
/*  f110238:	24040020 */ 	li	$a0,0x20
/*  f11023c:	02002825 */ 	move	$a1,$s0
/*  f110240:	0fc47c0b */ 	jal	0xf11f02c
/*  f110244:	00003025 */ 	move	$a2,$zero
/*  f110248:	2404000c */ 	li	$a0,0xc
/*  f11024c:	02002825 */ 	move	$a1,$s0
/*  f110250:	0fc47c0b */ 	jal	0xf11f02c
/*  f110254:	00003025 */ 	move	$a2,$zero
/*  f110258:	2404000d */ 	li	$a0,0xd
/*  f11025c:	02002825 */ 	move	$a1,$s0
/*  f110260:	0fc47c0b */ 	jal	0xf11f02c
/*  f110264:	24060001 */ 	li	$a2,0x1
/*  f110268:	2404000e */ 	li	$a0,0xe
/*  f11026c:	02002825 */ 	move	$a1,$s0
/*  f110270:	0fc47c0b */ 	jal	0xf11f02c
/*  f110274:	00003025 */ 	move	$a2,$zero
/*  f110278:	2404000f */ 	li	$a0,0xf
/*  f11027c:	02002825 */ 	move	$a1,$s0
/*  f110280:	0fc47c0b */ 	jal	0xf11f02c
/*  f110284:	24060001 */ 	li	$a2,0x1
/*  f110288:	24040010 */ 	li	$a0,0x10
/*  f11028c:	02002825 */ 	move	$a1,$s0
/*  f110290:	0fc47c0b */ 	jal	0xf11f02c
/*  f110294:	24060001 */ 	li	$a2,0x1
/*  f110298:	24040011 */ 	li	$a0,0x11
/*  f11029c:	02002825 */ 	move	$a1,$s0
/*  f1102a0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102a4:	24060001 */ 	li	$a2,0x1
/*  f1102a8:	24040012 */ 	li	$a0,0x12
/*  f1102ac:	02002825 */ 	move	$a1,$s0
/*  f1102b0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102b4:	24060001 */ 	li	$a2,0x1
/*  f1102b8:	24040013 */ 	li	$a0,0x13
/*  f1102bc:	02002825 */ 	move	$a1,$s0
/*  f1102c0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102c4:	24060001 */ 	li	$a2,0x1
/*  f1102c8:	24040014 */ 	li	$a0,0x14
/*  f1102cc:	02002825 */ 	move	$a1,$s0
/*  f1102d0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102d4:	00003025 */ 	move	$a2,$zero
/*  f1102d8:	24040016 */ 	li	$a0,0x16
/*  f1102dc:	02002825 */ 	move	$a1,$s0
/*  f1102e0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102e4:	24060001 */ 	li	$a2,0x1
/*  f1102e8:	24040018 */ 	li	$a0,0x18
/*  f1102ec:	02002825 */ 	move	$a1,$s0
/*  f1102f0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1102f4:	24060001 */ 	li	$a2,0x1
/*  f1102f8:	2404001b */ 	li	$a0,0x1b
/*  f1102fc:	02002825 */ 	move	$a1,$s0
/*  f110300:	0fc47c0b */ 	jal	0xf11f02c
/*  f110304:	00003025 */ 	move	$a2,$zero
/*  f110308:	24040021 */ 	li	$a0,0x21
/*  f11030c:	02002825 */ 	move	$a1,$s0
/*  f110310:	0fc47c0b */ 	jal	0xf11f02c
/*  f110314:	00003025 */ 	move	$a2,$zero
/*  f110318:	24040019 */ 	li	$a0,0x19
/*  f11031c:	02002825 */ 	move	$a1,$s0
/*  f110320:	0fc47c0b */ 	jal	0xf11f02c
/*  f110324:	00003025 */ 	move	$a2,$zero
/*  f110328:	24040007 */ 	li	$a0,0x7
/*  f11032c:	02002825 */ 	move	$a1,$s0
/*  f110330:	0fc47c0b */ 	jal	0xf11f02c
/*  f110334:	00003025 */ 	move	$a2,$zero
/*  f110338:	24040008 */ 	li	$a0,0x8
/*  f11033c:	02002825 */ 	move	$a1,$s0
/*  f110340:	0fc47c0b */ 	jal	0xf11f02c
/*  f110344:	00003025 */ 	move	$a2,$zero
/*  f110348:	24040006 */ 	li	$a0,0x6
/*  f11034c:	02002825 */ 	move	$a1,$s0
/*  f110350:	0fc47c0b */ 	jal	0xf11f02c
/*  f110354:	00003025 */ 	move	$a2,$zero
/*  f110358:	24040022 */ 	li	$a0,0x22
/*  f11035c:	02002825 */ 	move	$a1,$s0
/*  f110360:	0fc47c0b */ 	jal	0xf11f02c
/*  f110364:	00003025 */ 	move	$a2,$zero
/*  f110368:	24040040 */ 	li	$a0,0x40
/*  f11036c:	02002825 */ 	move	$a1,$s0
/*  f110370:	0fc47c0b */ 	jal	0xf11f02c
/*  f110374:	00003025 */ 	move	$a2,$zero
/*  f110378:	24040041 */ 	li	$a0,0x41
/*  f11037c:	02002825 */ 	move	$a1,$s0
/*  f110380:	0fc47c0b */ 	jal	0xf11f02c
/*  f110384:	00003025 */ 	move	$a2,$zero
/*  f110388:	24040042 */ 	li	$a0,0x42
/*  f11038c:	02002825 */ 	move	$a1,$s0
/*  f110390:	0fc47c0b */ 	jal	0xf11f02c
/*  f110394:	00003025 */ 	move	$a2,$zero
/*  f110398:	24040043 */ 	li	$a0,0x43
/*  f11039c:	02002825 */ 	move	$a1,$s0
/*  f1103a0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1103a4:	00003025 */ 	move	$a2,$zero
/*  f1103a8:	2404001c */ 	li	$a0,0x1c
/*  f1103ac:	02002825 */ 	move	$a1,$s0
/*  f1103b0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1103b4:	24060001 */ 	li	$a2,0x1
/*  f1103b8:	2404001d */ 	li	$a0,0x1d
/*  f1103bc:	02002825 */ 	move	$a1,$s0
/*  f1103c0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1103c4:	24060001 */ 	li	$a2,0x1
/*  f1103c8:	2404001e */ 	li	$a0,0x1e
/*  f1103cc:	02002825 */ 	move	$a1,$s0
/*  f1103d0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1103d4:	24060001 */ 	li	$a2,0x1
/*  f1103d8:	2404001f */ 	li	$a0,0x1f
/*  f1103dc:	02002825 */ 	move	$a1,$s0
/*  f1103e0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1103e4:	24060001 */ 	li	$a2,0x1
/*  f1103e8:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f1103ec:	3c10800a */ 	lui	$s0,0x800a
/*  f1103f0:	261027b4 */ 	addiu	$s0,$s0,0x27b4
/*  f1103f4:	30ca0001 */ 	andi	$t2,$a2,0x1
/*  f1103f8:	394b0001 */ 	xori	$t3,$t2,0x1
/*  f1103fc:	2d660001 */ 	sltiu	$a2,$t3,0x1
/*  f110400:	02002825 */ 	move	$a1,$s0
/*  f110404:	0fc47c0b */ 	jal	0xf11f02c
/*  f110408:	24040044 */ 	li	$a0,0x44
/*  f11040c:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f110410:	24040045 */ 	li	$a0,0x45
/*  f110414:	02002825 */ 	move	$a1,$s0
/*  f110418:	30cc0002 */ 	andi	$t4,$a2,0x2
/*  f11041c:	398d0002 */ 	xori	$t5,$t4,0x2
/*  f110420:	0fc47c0b */ 	jal	0xf11f02c
/*  f110424:	2da60001 */ 	sltiu	$a2,$t5,0x1
/*  f110428:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f11042c:	24040046 */ 	li	$a0,0x46
/*  f110430:	02002825 */ 	move	$a1,$s0
/*  f110434:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f110438:	39cf0004 */ 	xori	$t7,$t6,0x4
/*  f11043c:	0fc47c0b */ 	jal	0xf11f02c
/*  f110440:	2de60001 */ 	sltiu	$a2,$t7,0x1
/*  f110444:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f110448:	00009025 */ 	move	$s2,$zero
/*  f11044c:	24030003 */ 	li	$v1,0x3
/*  f110450:	a480001e */ 	sh	$zero,0x1e($a0)
.PF0f110454:
/*  f110454:	00008025 */ 	move	$s0,$zero
/*  f110458:	00801025 */ 	move	$v0,$a0
.PF0f11045c:
/*  f11045c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110460:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f110464:	1603fffd */ 	bne	$s0,$v1,.PF0f11045c
/*  f110468:	a440001e */ 	sh	$zero,0x1e($v0)
/*  f11046c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f110470:	2a410015 */ 	slti	$at,$s2,0x15
/*  f110474:	1420fff7 */ 	bnez	$at,.PF0f110454
/*  f110478:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f11047c:	00009025 */ 	move	$s2,$zero
/*  f110480:	24110005 */ 	li	$s1,0x5
/*  f110484:	24100001 */ 	li	$s0,0x1
.PF0f110488:
/*  f110488:	02402025 */ 	move	$a0,$s2
.PF0f11048c:
/*  f11048c:	02002825 */ 	move	$a1,$s0
/*  f110490:	0fc67543 */ 	jal	0xf19d50c
/*  f110494:	00003025 */ 	move	$a2,$zero
/*  f110498:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11049c:	5611fffb */ 	bnel	$s0,$s1,.PF0f11048c
/*  f1104a0:	02402025 */ 	move	$a0,$s2
/*  f1104a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1104a8:	2a41001e */ 	slti	$at,$s2,0x1e
/*  f1104ac:	5420fff6 */ 	bnezl	$at,.PF0f110488
/*  f1104b0:	24100001 */ 	li	$s0,0x1
/*  f1104b4:	0fc67037 */ 	jal	0xf19c0dc
/*  f1104b8:	00000000 */ 	nop
/*  f1104bc:	3c02800a */ 	lui	$v0,0x800a
/*  f1104c0:	3c03800a */ 	lui	$v1,0x800a
/*  f1104c4:	246327ac */ 	addiu	$v1,$v1,0x27ac
/*  f1104c8:	244227a0 */ 	addiu	$v0,$v0,0x27a0
.PF0f1104cc:
/*  f1104cc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1104d0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1104d4:	1420fffd */ 	bnez	$at,.PF0f1104cc
/*  f1104d8:	ac40009c */ 	sw	$zero,0x9c($v0)
/*  f1104dc:	3c02800a */ 	lui	$v0,0x800a
/*  f1104e0:	3c03800a */ 	lui	$v1,0x800a
/*  f1104e4:	246327a9 */ 	addiu	$v1,$v1,0x27a9
/*  f1104e8:	244227a0 */ 	addiu	$v0,$v0,0x27a0
.PF0f1104ec:
/*  f1104ec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1104f0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1104f4:	1420fffd */ 	bnez	$at,.PF0f1104ec
/*  f1104f8:	a04000ab */ 	sb	$zero,0xab($v0)
/*  f1104fc:	3c02800a */ 	lui	$v0,0x800a
/*  f110500:	3c03800a */ 	lui	$v1,0x800a
/*  f110504:	246327a6 */ 	addiu	$v1,$v1,0x27a6
/*  f110508:	244227a0 */ 	addiu	$v0,$v0,0x27a0
.PF0f11050c:
/*  f11050c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f110510:	1443fffe */ 	bne	$v0,$v1,.PF0f11050c
/*  f110514:	a04000b4 */ 	sb	$zero,0xb4($v0)
/*  f110518:	0fc43ee5 */ 	jal	0xf10fb94
/*  f11051c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f110520:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f110524:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110528:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11052c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110530:	03e00008 */ 	jr	$ra
/*  f110534:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#else
void savefileLoadDefaults(struct savefile_solo *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;
	s32 i;
	s32 j;

	strcpy(file->name, "Dark");
	file->thumbnail = 0;
	file->autodifficulty = 0;
	file->autostageindex = 0;
	file->totaltime = 0;
	audioSetSfxVolume(0x5000);
	optionsSetMusicVolume(0x5000);
	audioSetSoundMode(SOUNDMODE_STEREO);
	optionsSetControlMode(player1, CONTROLMODE_11);
	optionsSetControlMode(player2, CONTROLMODE_11);
	savefileClearAllFlags(&file->flags);

	bitSetByIndex(SAVEFILEFLAG_P1_FORWARDPITCH, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_P1_AUTOAIM, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_AIMCONTROL, &file->flags, AIMCONTROL_HOLD);
	bitSetByIndex(SAVEFILEFLAG_P1_SIGHTONSCREEN, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_LOOKAHEAD, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_AMMOONSCREEN, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_HEADROLL, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_SHOWGUNFUNCTION, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_INGAMESUBTITLES, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_ALWAYSSHOWTARGET, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_SHOWZOOMRANGE, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P1_SHOWMISSIONTIME, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_P1_PAINTBALL, &file->flags, false);

	bitSetByIndex(SAVEFILEFLAG_P2_FORWARDPITCH, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_P2_AUTOAIM, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_AIMCONTROL, &file->flags, AIMCONTROL_HOLD);
	bitSetByIndex(SAVEFILEFLAG_P2_SIGHTONSCREEN, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_LOOKAHEAD, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_AMMOONSCREEN, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_HEADROLL, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_SHOWGUNFUNCTION, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_CUTSCENESUBTITLES, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_P2_ALWAYSSHOWTARGET, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_SHOWZOOMRANGE, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_P2_SHOWMISSIONTIME, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_P2_PAINTBALL, &file->flags, false);

	bitSetByIndex(SAVEFILEFLAG_SCREENSPLIT, &file->flags, SCREENSPLIT_HORIZONTAL);
	bitSetByIndex(SAVEFILEFLAG_SCREENRATIO, &file->flags, SCREENRATIO_NORMAL);
	bitSetByIndex(SAVEFILEFLAG_SCREENSIZE_CINEMA, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_SCREENSIZE_WIDE, &file->flags, false);

	bitSetByIndex(SAVEFILEFLAG_HIRES, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_LANGFILTERON, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_41, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_42, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_43, &file->flags, false);
	bitSetByIndex(SAVEFILEFLAG_COOPRADARON, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_COOPFRIENDLYFIRE, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_ANTIRADARON, &file->flags, true);
	bitSetByIndex(SAVEFILEFLAG_ANTIPLAYERNUM, &file->flags, 1);

	file->unk1e = 0;

	for (i = 0; i < ARRAYCOUNT(file->besttimes); i++) {
		for (j = 0; j < ARRAYCOUNT(file->besttimes[0]); j++) {
			file->besttimes[i][j] = 0;
		}
	}

	for (i = 0; i < 30; i++) {
		for (j = 1; j != 5; j++) {
			mpSetChallengeCompletedByAnyPlayerWithNumPlayers(i, j, false);
		}
	}

	mpDetermineUnlockedFeatures();

	for (i = 0; i < ARRAYCOUNT(g_SoloSaveFile.coopcompletions); i++) {
		g_SoloSaveFile.coopcompletions[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_SoloSaveFile.firingrangescores); i++) {
		g_SoloSaveFile.firingrangescores[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_SoloSaveFile.weaponsfound); i++) {
		g_SoloSaveFile.weaponsfound[i] = 0;
	}

	savefileApplyOptions(file);
}
#endif

const char var7f1b38e8[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b391c[] = "pdoptions.c";
const char var7f1b3928[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b395c[] = "pdoptions.c";
const char var7f1b3968[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b399c[] = "pdoptions.c";
const char var7f1b39a8[] = "";
const char var7f1b39ac[] = "";
const char var7f1b39b0[] = "fileGuid";
const char var7f1b39bc[] = "bossfile.c";
const char var7f1b39c8[] = "";
const char var7f1b39cc[] = "";
const char var7f1b39d0[] = "Rebuilding pakWad %d:\n";

const u32 var7f1b39e8[] = {0x00000080};
const u32 var7f1b39ec[] = {0x00000040};
const u32 var7f1b39f0[] = {0x00000020};
const u32 var7f1b39f4[] = {0x00000008};
const u32 var7f1b39f8[] = {0x04000102};
const u32 var7f1b39fc[] = {0x03000000};
const u32 var7f1b3a00[] = {0x01020304};
const u32 var7f1b3a04[] = {0x00000000};

const char var7f1b3a08[] = "tc != NULL";
const char var7f1b3a14[] = "gamefile.c";

GLOBAL_ASM(
glabel func0f10fac8
/*  f10fac8:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f10facc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10fad0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10fad4:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10fad8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10fadc:	00808025 */ 	or	$s0,$a0,$zero
/*  f10fae0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f10fae4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f10fae8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f10faec:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10faf0:	04410005 */ 	bgez	$v0,.L0f10fb08
/*  f10faf4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10faf8:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10fafc:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f10fb00:	05c00003 */ 	bltz	$t6,.L0f10fb10
/*  f10fb04:	00000000 */ 	nop
.L0f10fb08:
/*  f10fb08:	10000001 */ 	b	.L0f10fb10
/*  f10fb0c:	00008825 */ 	or	$s1,$zero,$zero
.L0f10fb10:
/*  f10fb10:	04410005 */ 	bgez	$v0,.L0f10fb28
/*  f10fb14:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f10fb18:	8c6f029c */ 	lw	$t7,0x29c($v1)
/*  f10fb1c:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f10fb20:	05e00003 */ 	bltz	$t7,.L0f10fb30
/*  f10fb24:	00000000 */ 	nop
.L0f10fb28:
/*  f10fb28:	10000001 */ 	b	.L0f10fb30
/*  f10fb2c:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f10fb30:
/*  f10fb30:	060000d6 */ 	bltz	$s0,.L0f10fe8c
/*  f10fb34:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10fb38:	0fc35517 */ 	jal	func0f0d545c
/*  f10fb3c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb40:	00102600 */ 	sll	$a0,$s0,0x18
/*  f10fb44:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f10fb48:	3c05800a */ 	lui	$a1,%hi(g_FilemgrLoadedMainFile)
/*  f10fb4c:	8ca522c0 */ 	lw	$a1,%lo(g_FilemgrLoadedMainFile)($a1)
/*  f10fb50:	03002025 */ 	or	$a0,$t8,$zero
/*  f10fb54:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f10fb58:	0fc45a00 */ 	jal	func0f116800
/*  f10fb5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f10fb60:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f10fb64:	144000c7 */ 	bnez	$v0,.L0f10fe84
/*  f10fb68:	ac2221f8 */ 	sw	$v0,%lo(var800a21f8)($at)
/*  f10fb6c:	0fc41d3b */ 	jal	cheatsDisableAll
/*  f10fb70:	00000000 */ 	nop
/*  f10fb74:	3c05800a */ 	lui	$a1,%hi(g_SoloSaveFile)
/*  f10fb78:	24a52200 */ 	addiu	$a1,$a1,%lo(g_SoloSaveFile)
/*  f10fb7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb80:	0fc35539 */ 	jal	func0f0d54e4
/*  f10fb84:	00003025 */ 	or	$a2,$zero,$zero
/*  f10fb88:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb8c:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fb90:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10fb94:	3c03800a */ 	lui	$v1,%hi(g_SoloSaveFile)
/*  f10fb98:	24632200 */ 	addiu	$v1,$v1,%lo(g_SoloSaveFile)
/*  f10fb9c:	906a000b */ 	lbu	$t2,0xb($v1)
/*  f10fba0:	000248c0 */ 	sll	$t1,$v0,0x3
/*  f10fba4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fba8:	314bff07 */ 	andi	$t3,$t2,0xff07
/*  f10fbac:	012b6025 */ 	or	$t4,$t1,$t3
/*  f10fbb0:	a06c000b */ 	sb	$t4,0xb($v1)
/*  f10fbb4:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fbb8:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f10fbbc:	3c01800a */ 	lui	$at,%hi(g_SoloSaveFile+0x10)
/*  f10fbc0:	ac222210 */ 	sw	$v0,%lo(g_SoloSaveFile+0x10)($at)
/*  f10fbc4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fbc8:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fbcc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f10fbd0:	3c03800a */ 	lui	$v1,%hi(g_SoloSaveFile)
/*  f10fbd4:	24632200 */ 	addiu	$v1,$v1,%lo(g_SoloSaveFile)
/*  f10fbd8:	906f000b */ 	lbu	$t7,0xb($v1)
/*  f10fbdc:	304e0007 */ 	andi	$t6,$v0,0x7
/*  f10fbe0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fbe4:	31f8fff8 */ 	andi	$t8,$t7,0xfff8
/*  f10fbe8:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f10fbec:	a079000b */ 	sb	$t9,0xb($v1)
/*  f10fbf0:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fbf4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10fbf8:	3c01800a */ 	lui	$at,%hi(g_SoloSaveFile+0xc)
/*  f10fbfc:	a022220c */ 	sb	$v0,%lo(g_SoloSaveFile+0xc)($at)
/*  f10fc00:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc04:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fc08:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f10fc0c:	00022880 */ 	sll	$a1,$v0,0x2
/*  f10fc10:	2ca100fc */ 	sltiu	$at,$a1,0xfc
/*  f10fc14:	54200003 */ 	bnezl	$at,.L0f10fc24
/*  f10fc18:	00a02025 */ 	or	$a0,$a1,$zero
/*  f10fc1c:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f10fc20:	00a02025 */ 	or	$a0,$a1,$zero
.L0f10fc24:
/*  f10fc24:	000441c0 */ 	sll	$t0,$a0,0x7
/*  f10fc28:	0c003a87 */ 	jal	audioSetSfxVolume
/*  f10fc2c:	3104ffff */ 	andi	$a0,$t0,0xffff
/*  f10fc30:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc34:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fc38:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f10fc3c:	00022880 */ 	sll	$a1,$v0,0x2
/*  f10fc40:	2ca100fc */ 	sltiu	$at,$a1,0xfc
/*  f10fc44:	54200003 */ 	bnezl	$at,.L0f10fc54
/*  f10fc48:	00a02025 */ 	or	$a0,$a1,$zero
/*  f10fc4c:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f10fc50:	00a02025 */ 	or	$a0,$a1,$zero
.L0f10fc54:
/*  f10fc54:	000449c0 */ 	sll	$t1,$a0,0x7
/*  f10fc58:	0fc54bdc */ 	jal	optionsSetMusicVolume
/*  f10fc5c:	3124ffff */ 	andi	$a0,$t1,0xffff
/*  f10fc60:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc64:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fc68:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f10fc6c:	0c003ce3 */ 	jal	audioSetSoundMode
/*  f10fc70:	00402025 */ 	or	$a0,$v0,$zero
/*  f10fc74:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc78:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fc7c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f10fc80:	02202025 */ 	or	$a0,$s1,$zero
/*  f10fc84:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10fc88:	00402825 */ 	or	$a1,$v0,$zero
/*  f10fc8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc90:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fc94:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f10fc98:	02402025 */ 	or	$a0,$s2,$zero
/*  f10fc9c:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10fca0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10fca4:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f10fca8:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0xa)
/*  f10fcac:	2631220a */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0xa)
/*  f10fcb0:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
.L0f10fcb4:
/*  f10fcb4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcb8:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fcbc:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fcc0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fcc4:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10fcc8:	1420fffa */ 	bnez	$at,.L0f10fcb4
/*  f10fccc:	a2020013 */ 	sb	$v0,0x13($s0)
/*  f10fcd0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcd4:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fcd8:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f10fcdc:	3c01800a */ 	lui	$at,%hi(g_SoloSaveFile+0x1e)
/*  f10fce0:	3c13800a */ 	lui	$s3,%hi(g_SoloSaveFile)
/*  f10fce4:	a422221e */ 	sh	$v0,%lo(g_SoloSaveFile+0x1e)($at)
/*  f10fce8:	26732200 */ 	addiu	$s3,$s3,%lo(g_SoloSaveFile)
/*  f10fcec:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f10fcf0:	00008025 */ 	or	$s0,$zero,$zero
.L0f10fcf4:
/*  f10fcf4:	02608825 */ 	or	$s1,$s3,$zero
.L0f10fcf8:
/*  f10fcf8:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcfc:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fd00:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f10fd04:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fd08:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f10fd0c:	1612fffa */ 	bne	$s0,$s2,.L0f10fcf8
/*  f10fd10:	a622001e */ 	sh	$v0,0x1e($s1)
/*  f10fd14:	3c0c800a */ 	lui	$t4,%hi(g_SoloSaveFile+0x7e)
/*  f10fd18:	258c227e */ 	addiu	$t4,$t4,%lo(g_SoloSaveFile+0x7e)
/*  f10fd1c:	26730006 */ 	addiu	$s3,$s3,0x6
/*  f10fd20:	026c082b */ 	sltu	$at,$s3,$t4
/*  f10fd24:	5420fff3 */ 	bnezl	$at,.L0f10fcf4
/*  f10fd28:	00008025 */ 	or	$s0,$zero,$zero
/*  f10fd2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f10fd30:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f10fd34:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f10fd38:
/*  f10fd38:	02802025 */ 	or	$a0,$s4,$zero
.L0f10fd3c:
/*  f10fd3c:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fd40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10fd44:	02202025 */ 	or	$a0,$s1,$zero
/*  f10fd48:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fd4c:	0fc67103 */ 	jal	mpSetChallengeCompletedByAnyPlayerWithNumPlayers
/*  f10fd50:	00403025 */ 	or	$a2,$v0,$zero
/*  f10fd54:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fd58:	5612fff8 */ 	bnel	$s0,$s2,.L0f10fd3c
/*  f10fd5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fd60:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f10fd64:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f10fd68:	5420fff3 */ 	bnezl	$at,.L0f10fd38
/*  f10fd6c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f10fd70:	0fc66bf7 */ 	jal	mpDetermineUnlockedFeatures
/*  f10fd74:	00000000 */ 	nop
/*  f10fd78:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f10fd7c:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0xc)
/*  f10fd80:	2631220c */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0xc)
/*  f10fd84:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
.L0f10fd88:
/*  f10fd88:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fd8c:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fd90:	24050015 */ 	addiu	$a1,$zero,0x15
/*  f10fd94:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10fd98:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10fd9c:	1420fffa */ 	bnez	$at,.L0f10fd88
/*  f10fda0:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f10fda4:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f10fda8:	3c12800a */ 	lui	$s2,%hi(g_SoloSaveFile+0x9)
/*  f10fdac:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0x8)
/*  f10fdb0:	26312208 */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0x8)
/*  f10fdb4:	26522209 */ 	addiu	$s2,$s2,%lo(g_SoloSaveFile+0x9)
/*  f10fdb8:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
.L0f10fdbc:
/*  f10fdbc:	16110003 */ 	bne	$s0,$s1,.L0f10fdcc
/*  f10fdc0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fdc4:	10000001 */ 	b	.L0f10fdcc
/*  f10fdc8:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f10fdcc:
/*  f10fdcc:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fdd0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fdd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fdd8:	0212082b */ 	sltu	$at,$s0,$s2
/*  f10fddc:	1420fff7 */ 	bnez	$at,.L0f10fdbc
/*  f10fde0:	a20200ab */ 	sb	$v0,0xab($s0)
/*  f10fde4:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f10fde8:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0x4)
/*  f10fdec:	26312204 */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0x4)
/*  f10fdf0:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
.L0f10fdf4:
/*  f10fdf4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fdf8:	0fc354fe */ 	jal	savefileGetInteger
/*  f10fdfc:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fe00:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fe04:	1611fffb */ 	bne	$s0,$s1,.L0f10fdf4
/*  f10fe08:	a20200b4 */ 	sb	$v0,0xb4($s0)
/*  f10fe0c:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile+0x14)
/*  f10fe10:	26102214 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile+0x14)
/*  f10fe14:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe18:	0fc47961 */ 	jal	bitGetByIndex
/*  f10fe1c:	24040041 */ 	addiu	$a0,$zero,0x41
/*  f10fe20:	50400004 */ 	beqzl	$v0,.L0f10fe34
/*  f10fe24:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f10fe28:	0fc672ce */ 	jal	frSetWeaponFound
/*  f10fe2c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f10fe30:	24040042 */ 	addiu	$a0,$zero,0x42
.L0f10fe34:
/*  f10fe34:	0fc47961 */ 	jal	bitGetByIndex
/*  f10fe38:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe3c:	50400004 */ 	beqzl	$v0,.L0f10fe50
/*  f10fe40:	24040043 */ 	addiu	$a0,$zero,0x43
/*  f10fe44:	0fc672ce */ 	jal	frSetWeaponFound
/*  f10fe48:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10fe4c:	24040043 */ 	addiu	$a0,$zero,0x43
.L0f10fe50:
/*  f10fe50:	0fc47961 */ 	jal	bitGetByIndex
/*  f10fe54:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe58:	10400003 */ 	beqz	$v0,.L0f10fe68
/*  f10fe5c:	00000000 */ 	nop
/*  f10fe60:	0fc672ce */ 	jal	frSetWeaponFound
/*  f10fe64:	24040022 */ 	addiu	$a0,$zero,0x22
.L0f10fe68:
/*  f10fe68:	0fc35531 */ 	jal	func0f0d54c4
/*  f10fe6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fe70:	3c04800a */ 	lui	$a0,%hi(g_SoloSaveFile)
/*  f10fe74:	0fc43c81 */ 	jal	savefileApplyOptions
/*  f10fe78:	24842200 */ 	addiu	$a0,$a0,%lo(g_SoloSaveFile)
/*  f10fe7c:	10000003 */ 	b	.L0f10fe8c
/*  f10fe80:	00001025 */ 	or	$v0,$zero,$zero
.L0f10fe84:
/*  f10fe84:	10000001 */ 	b	.L0f10fe8c
/*  f10fe88:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f10fe8c:
/*  f10fe8c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f10fe90:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10fe94:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10fe98:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10fe9c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f10fea0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f10fea4:	03e00008 */ 	jr	$ra
/*  f10fea8:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f10feac
/*  f11091c:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f110920:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f110924:	3c12800a */ 	lui	$s2,0x800a
/*  f110928:	2652a510 */ 	addiu	$s2,$s2,-23280
/*  f11092c:	8e420298 */ 	lw	$v0,0x298($s2)
/*  f110930:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f110934:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f110938:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f11093c:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f110940:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f110944:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f110948:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f11094c:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f110950:	04410005 */ 	bgez	$v0,.PF0f110968
/*  f110954:	afa60150 */ 	sw	$a2,0x150($sp)
/*  f110958:	8e4e029c */ 	lw	$t6,0x29c($s2)
/*  f11095c:	24110004 */ 	li	$s1,0x4
/*  f110960:	05c00003 */ 	bltz	$t6,.PF0f110970
/*  f110964:	00000000 */ 	nop
.PF0f110968:
/*  f110968:	10000001 */ 	b	.PF0f110970
/*  f11096c:	00008825 */ 	move	$s1,$zero
.PF0f110970:
/*  f110970:	04410005 */ 	bgez	$v0,.PF0f110988
/*  f110974:	24140001 */ 	li	$s4,0x1
/*  f110978:	8e4f029c */ 	lw	$t7,0x29c($s2)
/*  f11097c:	24130005 */ 	li	$s3,0x5
/*  f110980:	05e00003 */ 	bltz	$t7,.PF0f110990
/*  f110984:	00000000 */ 	nop
.PF0f110988:
/*  f110988:	10000001 */ 	b	.PF0f110990
/*  f11098c:	24130001 */ 	li	$s3,0x1
.PF0f110990:
/*  f110990:	3c018007 */ 	lui	$at,0x8007
/*  f110994:	ac3460a0 */ 	sw	$s4,0x60a0($at)
/*  f110998:	0fc54d0c */ 	jal	0xf153430
/*  f11099c:	02202025 */ 	move	$a0,$s1
/*  f1109a0:	3c10800a */ 	lui	$s0,0x800a
/*  f1109a4:	261027b4 */ 	addiu	$s0,$s0,0x27b4
/*  f1109a8:	02002825 */ 	move	$a1,$s0
/*  f1109ac:	00002025 */ 	move	$a0,$zero
/*  f1109b0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1109b4:	00403025 */ 	move	$a2,$v0
/*  f1109b8:	0fc54d15 */ 	jal	0xf153454
/*  f1109bc:	02202025 */ 	move	$a0,$s1
/*  f1109c0:	02802025 */ 	move	$a0,$s4
/*  f1109c4:	02002825 */ 	move	$a1,$s0
/*  f1109c8:	0fc47c0b */ 	jal	0xf11f02c
/*  f1109cc:	00403025 */ 	move	$a2,$v0
/*  f1109d0:	0fc54d27 */ 	jal	0xf15349c
/*  f1109d4:	02202025 */ 	move	$a0,$s1
/*  f1109d8:	24040002 */ 	li	$a0,0x2
/*  f1109dc:	02002825 */ 	move	$a1,$s0
/*  f1109e0:	0fc47c0b */ 	jal	0xf11f02c
/*  f1109e4:	00403025 */ 	move	$a2,$v0
/*  f1109e8:	0fc54d30 */ 	jal	0xf1534c0
/*  f1109ec:	02202025 */ 	move	$a0,$s1
/*  f1109f0:	24040003 */ 	li	$a0,0x3
/*  f1109f4:	02002825 */ 	move	$a1,$s0
/*  f1109f8:	0fc47c0b */ 	jal	0xf11f02c
/*  f1109fc:	00403025 */ 	move	$a2,$v0
/*  f110a00:	0fc54d1e */ 	jal	0xf153478
/*  f110a04:	02202025 */ 	move	$a0,$s1
/*  f110a08:	24040004 */ 	li	$a0,0x4
/*  f110a0c:	02002825 */ 	move	$a1,$s0
/*  f110a10:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a14:	00403025 */ 	move	$a2,$v0
/*  f110a18:	0fc54d39 */ 	jal	0xf1534e4
/*  f110a1c:	02202025 */ 	move	$a0,$s1
/*  f110a20:	24040005 */ 	li	$a0,0x5
/*  f110a24:	02002825 */ 	move	$a1,$s0
/*  f110a28:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a2c:	00403025 */ 	move	$a2,$v0
/*  f110a30:	0fc54d75 */ 	jal	0xf1535d4
/*  f110a34:	02202025 */ 	move	$a0,$s1
/*  f110a38:	24040009 */ 	li	$a0,0x9
/*  f110a3c:	02002825 */ 	move	$a1,$s0
/*  f110a40:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a44:	00403025 */ 	move	$a2,$v0
/*  f110a48:	0fc54d42 */ 	jal	0xf153508
/*  f110a4c:	02202025 */ 	move	$a0,$s1
/*  f110a50:	2404000a */ 	li	$a0,0xa
/*  f110a54:	02002825 */ 	move	$a1,$s0
/*  f110a58:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a5c:	00403025 */ 	move	$a2,$v0
/*  f110a60:	0fc54d4b */ 	jal	0xf15352c
/*  f110a64:	02202025 */ 	move	$a0,$s1
/*  f110a68:	24040015 */ 	li	$a0,0x15
/*  f110a6c:	02002825 */ 	move	$a1,$s0
/*  f110a70:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a74:	00403025 */ 	move	$a2,$v0
/*  f110a78:	0fc54d54 */ 	jal	0xf153550
/*  f110a7c:	02202025 */ 	move	$a0,$s1
/*  f110a80:	24040017 */ 	li	$a0,0x17
/*  f110a84:	02002825 */ 	move	$a1,$s0
/*  f110a88:	0fc47c0b */ 	jal	0xf11f02c
/*  f110a8c:	00403025 */ 	move	$a2,$v0
/*  f110a90:	0fc54d66 */ 	jal	0xf153598
/*  f110a94:	02202025 */ 	move	$a0,$s1
/*  f110a98:	2404001a */ 	li	$a0,0x1a
/*  f110a9c:	02002825 */ 	move	$a1,$s0
/*  f110aa0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110aa4:	00403025 */ 	move	$a2,$v0
/*  f110aa8:	0fc54d5d */ 	jal	0xf153574
/*  f110aac:	02202025 */ 	move	$a0,$s1
/*  f110ab0:	24040020 */ 	li	$a0,0x20
/*  f110ab4:	02002825 */ 	move	$a1,$s0
/*  f110ab8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110abc:	00403025 */ 	move	$a2,$v0
/*  f110ac0:	0fc54d0c */ 	jal	0xf153430
/*  f110ac4:	02602025 */ 	move	$a0,$s3
/*  f110ac8:	2404000c */ 	li	$a0,0xc
/*  f110acc:	02002825 */ 	move	$a1,$s0
/*  f110ad0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110ad4:	00403025 */ 	move	$a2,$v0
/*  f110ad8:	0fc54d15 */ 	jal	0xf153454
/*  f110adc:	02602025 */ 	move	$a0,$s3
/*  f110ae0:	2404000d */ 	li	$a0,0xd
/*  f110ae4:	02002825 */ 	move	$a1,$s0
/*  f110ae8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110aec:	00403025 */ 	move	$a2,$v0
/*  f110af0:	0fc54d27 */ 	jal	0xf15349c
/*  f110af4:	02602025 */ 	move	$a0,$s3
/*  f110af8:	2404000e */ 	li	$a0,0xe
/*  f110afc:	02002825 */ 	move	$a1,$s0
/*  f110b00:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b04:	00403025 */ 	move	$a2,$v0
/*  f110b08:	0fc54d30 */ 	jal	0xf1534c0
/*  f110b0c:	02602025 */ 	move	$a0,$s3
/*  f110b10:	2404000f */ 	li	$a0,0xf
/*  f110b14:	02002825 */ 	move	$a1,$s0
/*  f110b18:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b1c:	00403025 */ 	move	$a2,$v0
/*  f110b20:	0fc54d1e */ 	jal	0xf153478
/*  f110b24:	02602025 */ 	move	$a0,$s3
/*  f110b28:	24040010 */ 	li	$a0,0x10
/*  f110b2c:	02002825 */ 	move	$a1,$s0
/*  f110b30:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b34:	00403025 */ 	move	$a2,$v0
/*  f110b38:	0fc54d39 */ 	jal	0xf1534e4
/*  f110b3c:	02602025 */ 	move	$a0,$s3
/*  f110b40:	24040011 */ 	li	$a0,0x11
/*  f110b44:	02002825 */ 	move	$a1,$s0
/*  f110b48:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b4c:	00403025 */ 	move	$a2,$v0
/*  f110b50:	0fc54d75 */ 	jal	0xf1535d4
/*  f110b54:	02602025 */ 	move	$a0,$s3
/*  f110b58:	24040012 */ 	li	$a0,0x12
/*  f110b5c:	02002825 */ 	move	$a1,$s0
/*  f110b60:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b64:	00403025 */ 	move	$a2,$v0
/*  f110b68:	0fc54d42 */ 	jal	0xf153508
/*  f110b6c:	02602025 */ 	move	$a0,$s3
/*  f110b70:	24040013 */ 	li	$a0,0x13
/*  f110b74:	02002825 */ 	move	$a1,$s0
/*  f110b78:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b7c:	00403025 */ 	move	$a2,$v0
/*  f110b80:	0fc54d4b */ 	jal	0xf15352c
/*  f110b84:	02602025 */ 	move	$a0,$s3
/*  f110b88:	24040016 */ 	li	$a0,0x16
/*  f110b8c:	02002825 */ 	move	$a1,$s0
/*  f110b90:	0fc47c0b */ 	jal	0xf11f02c
/*  f110b94:	00403025 */ 	move	$a2,$v0
/*  f110b98:	0fc54d54 */ 	jal	0xf153550
/*  f110b9c:	02602025 */ 	move	$a0,$s3
/*  f110ba0:	24040018 */ 	li	$a0,0x18
/*  f110ba4:	02002825 */ 	move	$a1,$s0
/*  f110ba8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110bac:	00403025 */ 	move	$a2,$v0
/*  f110bb0:	0fc54d66 */ 	jal	0xf153598
/*  f110bb4:	02602025 */ 	move	$a0,$s3
/*  f110bb8:	2404001b */ 	li	$a0,0x1b
/*  f110bbc:	02002825 */ 	move	$a1,$s0
/*  f110bc0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110bc4:	00403025 */ 	move	$a2,$v0
/*  f110bc8:	0fc54d5d */ 	jal	0xf153574
/*  f110bcc:	02602025 */ 	move	$a0,$s3
/*  f110bd0:	24040021 */ 	li	$a0,0x21
/*  f110bd4:	02002825 */ 	move	$a1,$s0
/*  f110bd8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110bdc:	00403025 */ 	move	$a2,$v0
/*  f110be0:	0fc54ef9 */ 	jal	0xf153be4
/*  f110be4:	00000000 */ 	nop
/*  f110be8:	24040019 */ 	li	$a0,0x19
/*  f110bec:	02002825 */ 	move	$a1,$s0
/*  f110bf0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110bf4:	00403025 */ 	move	$a2,$v0
/*  f110bf8:	0fc54ef3 */ 	jal	0xf153bcc
/*  f110bfc:	00000000 */ 	nop
/*  f110c00:	24040007 */ 	li	$a0,0x7
/*  f110c04:	02002825 */ 	move	$a1,$s0
/*  f110c08:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c0c:	00403025 */ 	move	$a2,$v0
/*  f110c10:	0fc54eed */ 	jal	0xf153bb4
/*  f110c14:	00000000 */ 	nop
/*  f110c18:	00543026 */ 	xor	$a2,$v0,$s4
/*  f110c1c:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110c20:	24040006 */ 	li	$a0,0x6
/*  f110c24:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c28:	02002825 */ 	move	$a1,$s0
/*  f110c2c:	0fc54eed */ 	jal	0xf153bb4
/*  f110c30:	00000000 */ 	nop
/*  f110c34:	24150002 */ 	li	$s5,0x2
/*  f110c38:	00553026 */ 	xor	$a2,$v0,$s5
/*  f110c3c:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110c40:	24040008 */ 	li	$a0,0x8
/*  f110c44:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c48:	02002825 */ 	move	$a1,$s0
/*  f110c4c:	3c188007 */ 	lui	$t8,0x8007
/*  f110c50:	8f1809a8 */ 	lw	$t8,0x9a8($t8)
/*  f110c54:	24040022 */ 	li	$a0,0x22
/*  f110c58:	02002825 */ 	move	$a1,$s0
/*  f110c5c:	02983026 */ 	xor	$a2,$s4,$t8
/*  f110c60:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c64:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110c68:	0fc54d6f */ 	jal	0xf1535bc
/*  f110c6c:	00000000 */ 	nop
/*  f110c70:	2404000b */ 	li	$a0,0xb
/*  f110c74:	02002825 */ 	move	$a1,$s0
/*  f110c78:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c7c:	00403025 */ 	move	$a2,$v0
/*  f110c80:	0fc54d72 */ 	jal	0xf1535c8
/*  f110c84:	00000000 */ 	nop
/*  f110c88:	24040014 */ 	li	$a0,0x14
/*  f110c8c:	02002825 */ 	move	$a1,$s0
/*  f110c90:	0fc47c0b */ 	jal	0xf11f02c
/*  f110c94:	00403025 */ 	move	$a2,$v0
/*  f110c98:	24040040 */ 	li	$a0,0x40
/*  f110c9c:	02002825 */ 	move	$a1,$s0
/*  f110ca0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110ca4:	924604e3 */ 	lbu	$a2,0x4e3($s2)
/*  f110ca8:	0fc676f5 */ 	jal	0xf19dbd4
/*  f110cac:	24040020 */ 	li	$a0,0x20
/*  f110cb0:	24040041 */ 	li	$a0,0x41
/*  f110cb4:	02002825 */ 	move	$a1,$s0
/*  f110cb8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110cbc:	00403025 */ 	move	$a2,$v0
/*  f110cc0:	0fc676f5 */ 	jal	0xf19dbd4
/*  f110cc4:	24040021 */ 	li	$a0,0x21
/*  f110cc8:	24040042 */ 	li	$a0,0x42
/*  f110ccc:	02002825 */ 	move	$a1,$s0
/*  f110cd0:	0fc47c0b */ 	jal	0xf11f02c
/*  f110cd4:	00403025 */ 	move	$a2,$v0
/*  f110cd8:	0fc676f5 */ 	jal	0xf19dbd4
/*  f110cdc:	24040022 */ 	li	$a0,0x22
/*  f110ce0:	24040043 */ 	li	$a0,0x43
/*  f110ce4:	02002825 */ 	move	$a1,$s0
/*  f110ce8:	0fc47c0b */ 	jal	0xf11f02c
/*  f110cec:	00403025 */ 	move	$a2,$v0
/*  f110cf0:	0fc54eed */ 	jal	0xf153bb4
/*  f110cf4:	00000000 */ 	nop
/*  f110cf8:	50400002 */ 	beqzl	$v0,.PF0f110d04
/*  f110cfc:	8e590450 */ 	lw	$t9,0x450($s2)
/*  f110d00:	8e590450 */ 	lw	$t9,0x450($s2)
.PF0f110d04:
/*  f110d04:	2404001f */ 	li	$a0,0x1f
/*  f110d08:	02002825 */ 	move	$a1,$s0
/*  f110d0c:	02993026 */ 	xor	$a2,$s4,$t9
/*  f110d10:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d14:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d18:	8e480448 */ 	lw	$t0,0x448($s2)
/*  f110d1c:	2404001c */ 	li	$a0,0x1c
/*  f110d20:	02002825 */ 	move	$a1,$s0
/*  f110d24:	02883026 */ 	xor	$a2,$s4,$t0
/*  f110d28:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d2c:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d30:	8e490454 */ 	lw	$t1,0x454($s2)
/*  f110d34:	2404001d */ 	li	$a0,0x1d
/*  f110d38:	02002825 */ 	move	$a1,$s0
/*  f110d3c:	02893026 */ 	xor	$a2,$s4,$t1
/*  f110d40:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d44:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d48:	8e4a044c */ 	lw	$t2,0x44c($s2)
/*  f110d4c:	2404001e */ 	li	$a0,0x1e
/*  f110d50:	02002825 */ 	move	$a1,$s0
/*  f110d54:	028a3026 */ 	xor	$a2,$s4,$t2
/*  f110d58:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d5c:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d60:	964b0482 */ 	lhu	$t3,0x482($s2)
/*  f110d64:	24040044 */ 	li	$a0,0x44
/*  f110d68:	02002825 */ 	move	$a1,$s0
/*  f110d6c:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f110d70:	028c3026 */ 	xor	$a2,$s4,$t4
/*  f110d74:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d78:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d7c:	964d0482 */ 	lhu	$t5,0x482($s2)
/*  f110d80:	24040045 */ 	li	$a0,0x45
/*  f110d84:	02002825 */ 	move	$a1,$s0
/*  f110d88:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f110d8c:	02ae3026 */ 	xor	$a2,$s5,$t6
/*  f110d90:	0fc47c0b */ 	jal	0xf11f02c
/*  f110d94:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f110d98:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f110d9c:	24040046 */ 	li	$a0,0x46
/*  f110da0:	02002825 */ 	move	$a1,$s0
/*  f110da4:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f110da8:	39f80004 */ 	xori	$t8,$t7,0x4
/*  f110dac:	0fc47c0b */ 	jal	0xf11f02c
/*  f110db0:	2f060001 */ 	sltiu	$a2,$t8,0x1
/*  f110db4:	8fb90148 */ 	lw	$t9,0x148($sp)
/*  f110db8:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f110dbc:	2402ffff */ 	li	$v0,-1
/*  f110dc0:	072000b6 */ 	bltz	$t9,.PF0f11109c
/*  f110dc4:	00000000 */ 	nop
/*  f110dc8:	0fc3567f */ 	jal	0xf0d59fc
/*  f110dcc:	02802025 */ 	move	$a0,$s4
/*  f110dd0:	3c12800a */ 	lui	$s2,0x800a
/*  f110dd4:	265227a0 */ 	addiu	$s2,$s2,0x27a0
/*  f110dd8:	02402825 */ 	move	$a1,$s2
/*  f110ddc:	0fc356d1 */ 	jal	0xf0d5b44
/*  f110de0:	02802025 */ 	move	$a0,$s4
/*  f110de4:	9245000b */ 	lbu	$a1,0xb($s2)
/*  f110de8:	02802025 */ 	move	$a0,$s4
/*  f110dec:	24060005 */ 	li	$a2,0x5
/*  f110df0:	000540c2 */ 	srl	$t0,$a1,0x3
/*  f110df4:	0fc35626 */ 	jal	0xf0d5898
/*  f110df8:	01002825 */ 	move	$a1,$t0
/*  f110dfc:	02802025 */ 	move	$a0,$s4
/*  f110e00:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f110e04:	0fc35626 */ 	jal	0xf0d5898
/*  f110e08:	24060020 */ 	li	$a2,0x20
/*  f110e0c:	8e450008 */ 	lw	$a1,0x8($s2)
/*  f110e10:	02802025 */ 	move	$a0,$s4
/*  f110e14:	24060002 */ 	li	$a2,0x2
/*  f110e18:	30a90007 */ 	andi	$t1,$a1,0x7
/*  f110e1c:	0fc35626 */ 	jal	0xf0d5898
/*  f110e20:	01202825 */ 	move	$a1,$t1
/*  f110e24:	02802025 */ 	move	$a0,$s4
/*  f110e28:	9245000c */ 	lbu	$a1,0xc($s2)
/*  f110e2c:	0fc35626 */ 	jal	0xf0d5898
/*  f110e30:	24060005 */ 	li	$a2,0x5
/*  f110e34:	3c028006 */ 	lui	$v0,0x8006
/*  f110e38:	9442da68 */ 	lhu	$v0,-0x2598($v0)
/*  f110e3c:	02802025 */ 	move	$a0,$s4
/*  f110e40:	24060006 */ 	li	$a2,0x6
/*  f110e44:	28415001 */ 	slti	$at,$v0,0x5001
/*  f110e48:	54200004 */ 	bnezl	$at,.PF0f110e5c
/*  f110e4c:	00403825 */ 	move	$a3,$v0
/*  f110e50:	10000002 */ 	b	.PF0f110e5c
/*  f110e54:	24075000 */ 	li	$a3,0x5000
/*  f110e58:	00403825 */ 	move	$a3,$v0
.PF0f110e5c:
/*  f110e5c:	000729c3 */ 	sra	$a1,$a3,0x7
/*  f110e60:	00055082 */ 	srl	$t2,$a1,0x2
/*  f110e64:	0fc35626 */ 	jal	0xf0d5898
/*  f110e68:	01402825 */ 	move	$a1,$t2
/*  f110e6c:	0fc54f00 */ 	jal	0xf153c00
/*  f110e70:	00000000 */ 	nop
/*  f110e74:	000229c3 */ 	sra	$a1,$v0,0x7
/*  f110e78:	00055882 */ 	srl	$t3,$a1,0x2
/*  f110e7c:	01602825 */ 	move	$a1,$t3
/*  f110e80:	02802025 */ 	move	$a0,$s4
/*  f110e84:	0fc35626 */ 	jal	0xf0d5898
/*  f110e88:	24060006 */ 	li	$a2,0x6
/*  f110e8c:	3c058006 */ 	lui	$a1,0x8006
/*  f110e90:	8ca5da6c */ 	lw	$a1,-0x2594($a1)
/*  f110e94:	02802025 */ 	move	$a0,$s4
/*  f110e98:	0fc35626 */ 	jal	0xf0d5898
/*  f110e9c:	24060002 */ 	li	$a2,0x2
/*  f110ea0:	0fc54cf0 */ 	jal	0xf1533c0
/*  f110ea4:	02202025 */ 	move	$a0,$s1
/*  f110ea8:	02802025 */ 	move	$a0,$s4
/*  f110eac:	00402825 */ 	move	$a1,$v0
/*  f110eb0:	0fc35626 */ 	jal	0xf0d5898
/*  f110eb4:	24060003 */ 	li	$a2,0x3
/*  f110eb8:	0fc54cf0 */ 	jal	0xf1533c0
/*  f110ebc:	02602025 */ 	move	$a0,$s3
/*  f110ec0:	02802025 */ 	move	$a0,$s4
/*  f110ec4:	00402825 */ 	move	$a1,$v0
/*  f110ec8:	0fc35626 */ 	jal	0xf0d5898
/*  f110ecc:	24060003 */ 	li	$a2,0x3
/*  f110ed0:	3c10800a */ 	lui	$s0,0x800a
/*  f110ed4:	3c11800a */ 	lui	$s1,0x800a
/*  f110ed8:	263127aa */ 	addiu	$s1,$s1,0x27aa
/*  f110edc:	261027a0 */ 	addiu	$s0,$s0,0x27a0
/*  f110ee0:	02802025 */ 	move	$a0,$s4
.PF0f110ee4:
/*  f110ee4:	92050014 */ 	lbu	$a1,0x14($s0)
/*  f110ee8:	0fc35626 */ 	jal	0xf0d5898
/*  f110eec:	24060008 */ 	li	$a2,0x8
/*  f110ef0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110ef4:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110ef8:	5420fffa */ 	bnezl	$at,.PF0f110ee4
/*  f110efc:	02802025 */ 	move	$a0,$s4
/*  f110f00:	02802025 */ 	move	$a0,$s4
/*  f110f04:	9645001e */ 	lhu	$a1,0x1e($s2)
/*  f110f08:	0fc35626 */ 	jal	0xf0d5898
/*  f110f0c:	24060010 */ 	li	$a2,0x10
/*  f110f10:	3c15800a */ 	lui	$s5,0x800a
/*  f110f14:	26b527a0 */ 	addiu	$s5,$s5,0x27a0
/*  f110f18:	24130006 */ 	li	$s3,0x6
/*  f110f1c:	00008825 */ 	move	$s1,$zero
.PF0f110f20:
/*  f110f20:	02a09025 */ 	move	$s2,$s5
.PF0f110f24:
/*  f110f24:	02802025 */ 	move	$a0,$s4
/*  f110f28:	96450020 */ 	lhu	$a1,0x20($s2)
/*  f110f2c:	0fc35626 */ 	jal	0xf0d5898
/*  f110f30:	2406000c */ 	li	$a2,0xc
/*  f110f34:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f110f38:	1633fffa */ 	bne	$s1,$s3,.PF0f110f24
/*  f110f3c:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f110f40:	3c0c800a */ 	lui	$t4,0x800a
/*  f110f44:	258c281e */ 	addiu	$t4,$t4,0x281e
/*  f110f48:	26b50006 */ 	addiu	$s5,$s5,0x6
/*  f110f4c:	02ac082b */ 	sltu	$at,$s5,$t4
/*  f110f50:	5420fff3 */ 	bnezl	$at,.PF0f110f20
/*  f110f54:	00008825 */ 	move	$s1,$zero
/*  f110f58:	00008825 */ 	move	$s1,$zero
/*  f110f5c:	24120005 */ 	li	$s2,0x5
/*  f110f60:	24100001 */ 	li	$s0,0x1
.PF0f110f64:
/*  f110f64:	02202025 */ 	move	$a0,$s1
.PF0f110f68:
/*  f110f68:	0fc67537 */ 	jal	0xf19d4dc
/*  f110f6c:	02002825 */ 	move	$a1,$s0
/*  f110f70:	02802025 */ 	move	$a0,$s4
/*  f110f74:	00402825 */ 	move	$a1,$v0
/*  f110f78:	0fc35626 */ 	jal	0xf0d5898
/*  f110f7c:	24060001 */ 	li	$a2,0x1
/*  f110f80:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110f84:	5612fff8 */ 	bnel	$s0,$s2,.PF0f110f68
/*  f110f88:	02202025 */ 	move	$a0,$s1
/*  f110f8c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f110f90:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f110f94:	5420fff3 */ 	bnezl	$at,.PF0f110f64
/*  f110f98:	24100001 */ 	li	$s0,0x1
/*  f110f9c:	3c10800a */ 	lui	$s0,0x800a
/*  f110fa0:	3c11800a */ 	lui	$s1,0x800a
/*  f110fa4:	263127ac */ 	addiu	$s1,$s1,0x27ac
/*  f110fa8:	261027a0 */ 	addiu	$s0,$s0,0x27a0
/*  f110fac:	02802025 */ 	move	$a0,$s4
.PF0f110fb0:
/*  f110fb0:	8e0500a0 */ 	lw	$a1,0xa0($s0)
/*  f110fb4:	0fc35626 */ 	jal	0xf0d5898
/*  f110fb8:	24060015 */ 	li	$a2,0x15
/*  f110fbc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110fc0:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110fc4:	5420fffa */ 	bnezl	$at,.PF0f110fb0
/*  f110fc8:	02802025 */ 	move	$a0,$s4
/*  f110fcc:	3c10800a */ 	lui	$s0,0x800a
/*  f110fd0:	3c12800a */ 	lui	$s2,0x800a
/*  f110fd4:	3c11800a */ 	lui	$s1,0x800a
/*  f110fd8:	263127a8 */ 	addiu	$s1,$s1,0x27a8
/*  f110fdc:	265227a9 */ 	addiu	$s2,$s2,0x27a9
/*  f110fe0:	261027a0 */ 	addiu	$s0,$s0,0x27a0
.PF0f110fe4:
/*  f110fe4:	16110003 */ 	bne	$s0,$s1,.PF0f110ff4
/*  f110fe8:	02802025 */ 	move	$a0,$s4
/*  f110fec:	10000002 */ 	b	.PF0f110ff8
/*  f110ff0:	24070002 */ 	li	$a3,0x2
.PF0f110ff4:
/*  f110ff4:	24070008 */ 	li	$a3,0x8
.PF0f110ff8:
/*  f110ff8:	920500ac */ 	lbu	$a1,0xac($s0)
/*  f110ffc:	0fc35626 */ 	jal	0xf0d5898
/*  f111000:	00e03025 */ 	move	$a2,$a3
/*  f111004:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f111008:	0212082b */ 	sltu	$at,$s0,$s2
/*  f11100c:	1420fff5 */ 	bnez	$at,.PF0f110fe4
/*  f111010:	00000000 */ 	nop
/*  f111014:	3c10800a */ 	lui	$s0,0x800a
/*  f111018:	3c11800a */ 	lui	$s1,0x800a
/*  f11101c:	263127a4 */ 	addiu	$s1,$s1,0x27a4
/*  f111020:	261027a0 */ 	addiu	$s0,$s0,0x27a0
/*  f111024:	02802025 */ 	move	$a0,$s4
.PF0f111028:
/*  f111028:	920500b5 */ 	lbu	$a1,0xb5($s0)
/*  f11102c:	0fc35626 */ 	jal	0xf0d5898
/*  f111030:	24060008 */ 	li	$a2,0x8
/*  f111034:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f111038:	5611fffb */ 	bnel	$s0,$s1,.PF0f111028
/*  f11103c:	02802025 */ 	move	$a0,$s4
/*  f111040:	0fc35699 */ 	jal	0xf0d5a64
/*  f111044:	02802025 */ 	move	$a0,$s4
/*  f111048:	27ad0140 */ 	addiu	$t5,$sp,0x140
/*  f11104c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f111050:	83a4014b */ 	lb	$a0,0x14b($sp)
/*  f111054:	8fa5014c */ 	lw	$a1,0x14c($sp)
/*  f111058:	24060080 */ 	li	$a2,0x80
/*  f11105c:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f111060:	0fc45cc2 */ 	jal	0xf117308
/*  f111064:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f111068:	3c01800a */ 	lui	$at,0x800a
/*  f11106c:	14400009 */ 	bnez	$v0,.PF0f111094
/*  f111070:	ac222798 */ 	sw	$v0,0x2798($at)
/*  f111074:	8fae0140 */ 	lw	$t6,0x140($sp)
/*  f111078:	97af0152 */ 	lhu	$t7,0x152($sp)
/*  f11107c:	3c03800a */ 	lui	$v1,0x800a
/*  f111080:	24632860 */ 	addiu	$v1,$v1,0x2860
/*  f111084:	00001025 */ 	move	$v0,$zero
/*  f111088:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f11108c:	10000003 */ 	b	.PF0f11109c
/*  f111090:	a46f0004 */ 	sh	$t7,0x4($v1)
.PF0f111094:
/*  f111094:	10000001 */ 	b	.PF0f11109c
/*  f111098:	2402ffff */ 	li	$v0,-1
.PF0f11109c:
/*  f11109c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1110a0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1110a4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1110a8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1110ac:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1110b0:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f1110b4:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f1110b8:	03e00008 */ 	jr	$ra
/*  f1110bc:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#else
GLOBAL_ASM(
glabel func0f10feac
/*  f10feac:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f10feb0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f10feb4:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f10feb8:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f10febc:	8e820298 */ 	lw	$v0,0x298($s4)
/*  f10fec0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f10fec4:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f10fec8:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f10fecc:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f10fed0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f10fed4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10fed8:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f10fedc:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f10fee0:	04410005 */ 	bgez	$v0,.L0f10fef8
/*  f10fee4:	afa60150 */ 	sw	$a2,0x150($sp)
/*  f10fee8:	8e8e029c */ 	lw	$t6,0x29c($s4)
/*  f10feec:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f10fef0:	05c00003 */ 	bltz	$t6,.L0f10ff00
/*  f10fef4:	00000000 */ 	nop
.L0f10fef8:
/*  f10fef8:	10000001 */ 	b	.L0f10ff00
/*  f10fefc:	00009825 */ 	or	$s3,$zero,$zero
.L0f10ff00:
/*  f10ff00:	04410005 */ 	bgez	$v0,.L0f10ff18
/*  f10ff04:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f10ff08:	8e8f029c */ 	lw	$t7,0x29c($s4)
/*  f10ff0c:	24110005 */ 	addiu	$s1,$zero,0x5
/*  f10ff10:	05e00003 */ 	bltz	$t7,.L0f10ff20
/*  f10ff14:	00000000 */ 	nop
.L0f10ff18:
/*  f10ff18:	10000001 */ 	b	.L0f10ff20
/*  f10ff1c:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f10ff20:
/*  f10ff20:	3c018007 */ 	lui	$at,%hi(g_FileLists+0x10)
/*  f10ff24:	ac325bd0 */ 	sw	$s2,%lo(g_FileLists+0x10)($at)
/*  f10ff28:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f10ff2c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff30:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile+0x14)
/*  f10ff34:	26102214 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile+0x14)
/*  f10ff38:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10ff40:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ff44:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff48:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f10ff4c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff50:	02402025 */ 	or	$a0,$s2,$zero
/*  f10ff54:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff58:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ff5c:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff60:	0fc549fb */ 	jal	optionsGetAimControl
/*  f10ff64:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10ff6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff70:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ff74:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff78:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f10ff7c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff80:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10ff84:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff88:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ff8c:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff90:	0fc549f2 */ 	jal	optionsGetLookAhead
/*  f10ff94:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff98:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10ff9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffa0:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ffa4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffa8:	0fc54a0d */ 	jal	optionsGetAmmoOnScreen
/*  f10ffac:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffb0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10ffb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffb8:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ffbc:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffc0:	0fc54a49 */ 	jal	optionsGetHeadRoll
/*  f10ffc4:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffc8:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f10ffcc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffd0:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ffd4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffd8:	0fc54a16 */ 	jal	optionsGetShowGunFunction
/*  f10ffdc:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffe0:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f10ffe4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffe8:	0fc4794c */ 	jal	bitSetByIndex
/*  f10ffec:	00403025 */ 	or	$a2,$v0,$zero
/*  f10fff0:	0fc54a1f */ 	jal	optionsGetAlwaysShowTarget
/*  f10fff4:	02602025 */ 	or	$a0,$s3,$zero
/*  f10fff8:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f10fffc:	02002825 */ 	or	$a1,$s0,$zero
/*  f110000:	0fc4794c */ 	jal	bitSetByIndex
/*  f110004:	00403025 */ 	or	$a2,$v0,$zero
/*  f110008:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f11000c:	02602025 */ 	or	$a0,$s3,$zero
/*  f110010:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f110014:	02002825 */ 	or	$a1,$s0,$zero
/*  f110018:	0fc4794c */ 	jal	bitSetByIndex
/*  f11001c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110020:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f110024:	02602025 */ 	or	$a0,$s3,$zero
/*  f110028:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f11002c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110030:	0fc4794c */ 	jal	bitSetByIndex
/*  f110034:	00403025 */ 	or	$a2,$v0,$zero
/*  f110038:	0fc54a31 */ 	jal	optionsGetPaintball
/*  f11003c:	02602025 */ 	or	$a0,$s3,$zero
/*  f110040:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f110044:	02002825 */ 	or	$a1,$s0,$zero
/*  f110048:	0fc4794c */ 	jal	bitSetByIndex
/*  f11004c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110050:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f110054:	02202025 */ 	or	$a0,$s1,$zero
/*  f110058:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f11005c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110060:	0fc4794c */ 	jal	bitSetByIndex
/*  f110064:	00403025 */ 	or	$a2,$v0,$zero
/*  f110068:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f11006c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110070:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f110074:	02002825 */ 	or	$a1,$s0,$zero
/*  f110078:	0fc4794c */ 	jal	bitSetByIndex
/*  f11007c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110080:	0fc549fb */ 	jal	optionsGetAimControl
/*  f110084:	02202025 */ 	or	$a0,$s1,$zero
/*  f110088:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f11008c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110090:	0fc4794c */ 	jal	bitSetByIndex
/*  f110094:	00403025 */ 	or	$a2,$v0,$zero
/*  f110098:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f11009c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100a0:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f1100a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100a8:	0fc4794c */ 	jal	bitSetByIndex
/*  f1100ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100b0:	0fc549f2 */ 	jal	optionsGetLookAhead
/*  f1100b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100b8:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f1100bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100c0:	0fc4794c */ 	jal	bitSetByIndex
/*  f1100c4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100c8:	0fc54a0d */ 	jal	optionsGetAmmoOnScreen
/*  f1100cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100d0:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f1100d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100d8:	0fc4794c */ 	jal	bitSetByIndex
/*  f1100dc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100e0:	0fc54a49 */ 	jal	optionsGetHeadRoll
/*  f1100e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100e8:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f1100ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100f0:	0fc4794c */ 	jal	bitSetByIndex
/*  f1100f4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100f8:	0fc54a16 */ 	jal	optionsGetShowGunFunction
/*  f1100fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f110100:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f110104:	02002825 */ 	or	$a1,$s0,$zero
/*  f110108:	0fc4794c */ 	jal	bitSetByIndex
/*  f11010c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110110:	0fc54a1f */ 	jal	optionsGetAlwaysShowTarget
/*  f110114:	02202025 */ 	or	$a0,$s1,$zero
/*  f110118:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f11011c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110120:	0fc4794c */ 	jal	bitSetByIndex
/*  f110124:	00403025 */ 	or	$a2,$v0,$zero
/*  f110128:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f11012c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110130:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f110134:	02002825 */ 	or	$a1,$s0,$zero
/*  f110138:	0fc4794c */ 	jal	bitSetByIndex
/*  f11013c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110140:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f110144:	02202025 */ 	or	$a0,$s1,$zero
/*  f110148:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f11014c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110150:	0fc4794c */ 	jal	bitSetByIndex
/*  f110154:	00403025 */ 	or	$a2,$v0,$zero
/*  f110158:	0fc54a31 */ 	jal	optionsGetPaintball
/*  f11015c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110160:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f110164:	02002825 */ 	or	$a1,$s0,$zero
/*  f110168:	0fc4794c */ 	jal	bitSetByIndex
/*  f11016c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110170:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f110174:	00000000 */ 	nop
/*  f110178:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f11017c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110180:	0fc4794c */ 	jal	bitSetByIndex
/*  f110184:	00403025 */ 	or	$a2,$v0,$zero
/*  f110188:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f11018c:	00000000 */ 	nop
/*  f110190:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f110194:	02002825 */ 	or	$a1,$s0,$zero
/*  f110198:	0fc4794c */ 	jal	bitSetByIndex
/*  f11019c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1101a0:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f1101a4:	00000000 */ 	nop
/*  f1101a8:	00523026 */ 	xor	$a2,$v0,$s2
/*  f1101ac:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101b0:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f1101b4:	0fc4794c */ 	jal	bitSetByIndex
/*  f1101b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101bc:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f1101c0:	00000000 */ 	nop
/*  f1101c4:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f1101c8:	00553026 */ 	xor	$a2,$v0,$s5
/*  f1101cc:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101d0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f1101d4:	0fc4794c */ 	jal	bitSetByIndex
/*  f1101d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101dc:	3c188007 */ 	lui	$t8,%hi(g_ViMode)
/*  f1101e0:	8f1806c8 */ 	lw	$t8,%lo(g_ViMode)($t8)
/*  f1101e4:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f1101e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101ec:	02583026 */ 	xor	$a2,$s2,$t8
/*  f1101f0:	0fc4794c */ 	jal	bitSetByIndex
/*  f1101f4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101f8:	0fc54a43 */ 	jal	optionsGetInGameSubtitles
/*  f1101fc:	00000000 */ 	nop
/*  f110200:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f110204:	02002825 */ 	or	$a1,$s0,$zero
/*  f110208:	0fc4794c */ 	jal	bitSetByIndex
/*  f11020c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110210:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f110214:	00000000 */ 	nop
/*  f110218:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f11021c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110220:	0fc4794c */ 	jal	bitSetByIndex
/*  f110224:	00403025 */ 	or	$a2,$v0,$zero
/*  f110228:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f11022c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110230:	0fc4794c */ 	jal	bitSetByIndex
/*  f110234:	928604e3 */ 	lbu	$a2,0x4e3($s4)
/*  f110238:	0fc672b5 */ 	jal	frIsWeaponFound
/*  f11023c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f110240:	24040041 */ 	addiu	$a0,$zero,0x41
/*  f110244:	02002825 */ 	or	$a1,$s0,$zero
/*  f110248:	0fc4794c */ 	jal	bitSetByIndex
/*  f11024c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110250:	0fc672b5 */ 	jal	frIsWeaponFound
/*  f110254:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f110258:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f11025c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110260:	0fc4794c */ 	jal	bitSetByIndex
/*  f110264:	00403025 */ 	or	$a2,$v0,$zero
/*  f110268:	0fc672b5 */ 	jal	frIsWeaponFound
/*  f11026c:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f110270:	24040043 */ 	addiu	$a0,$zero,0x43
/*  f110274:	02002825 */ 	or	$a1,$s0,$zero
/*  f110278:	0fc4794c */ 	jal	bitSetByIndex
/*  f11027c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110280:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f110284:	00000000 */ 	nop
/*  f110288:	50400002 */ 	beqzl	$v0,.L0f110294
/*  f11028c:	8e990450 */ 	lw	$t9,0x450($s4)
/*  f110290:	8e990450 */ 	lw	$t9,0x450($s4)
.L0f110294:
/*  f110294:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f110298:	02002825 */ 	or	$a1,$s0,$zero
/*  f11029c:	02593026 */ 	xor	$a2,$s2,$t9
/*  f1102a0:	0fc4794c */ 	jal	bitSetByIndex
/*  f1102a4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102a8:	8e880448 */ 	lw	$t0,0x448($s4)
/*  f1102ac:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f1102b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102b4:	02483026 */ 	xor	$a2,$s2,$t0
/*  f1102b8:	0fc4794c */ 	jal	bitSetByIndex
/*  f1102bc:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102c0:	8e890454 */ 	lw	$t1,0x454($s4)
/*  f1102c4:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f1102c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102cc:	02493026 */ 	xor	$a2,$s2,$t1
/*  f1102d0:	0fc4794c */ 	jal	bitSetByIndex
/*  f1102d4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102d8:	8e8a044c */ 	lw	$t2,0x44c($s4)
/*  f1102dc:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f1102e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102e4:	024a3026 */ 	xor	$a2,$s2,$t2
/*  f1102e8:	0fc4794c */ 	jal	bitSetByIndex
/*  f1102ec:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102f0:	8fab0148 */ 	lw	$t3,0x148($sp)
/*  f1102f4:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f1102f8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f1102fc:	056000b6 */ 	bltz	$t3,.L0f1105d8
/*  f110300:	00000000 */ 	nop
/*  f110304:	0fc35517 */ 	jal	func0f0d545c
/*  f110308:	02802025 */ 	or	$a0,$s4,$zero
/*  f11030c:	3c12800a */ 	lui	$s2,%hi(g_SoloSaveFile)
/*  f110310:	26522200 */ 	addiu	$s2,$s2,%lo(g_SoloSaveFile)
/*  f110314:	02402825 */ 	or	$a1,$s2,$zero
/*  f110318:	0fc35569 */ 	jal	func0f0d55a4
/*  f11031c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110320:	9245000b */ 	lbu	$a1,0xb($s2)
/*  f110324:	02802025 */ 	or	$a0,$s4,$zero
/*  f110328:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f11032c:	000560c2 */ 	srl	$t4,$a1,0x3
/*  f110330:	0fc354be */ 	jal	savefileGetSomething
/*  f110334:	01802825 */ 	or	$a1,$t4,$zero
/*  f110338:	02802025 */ 	or	$a0,$s4,$zero
/*  f11033c:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f110340:	0fc354be */ 	jal	savefileGetSomething
/*  f110344:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f110348:	8e450008 */ 	lw	$a1,0x8($s2)
/*  f11034c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110350:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f110354:	30ad0007 */ 	andi	$t5,$a1,0x7
/*  f110358:	0fc354be */ 	jal	savefileGetSomething
/*  f11035c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f110360:	02802025 */ 	or	$a0,$s4,$zero
/*  f110364:	9245000c */ 	lbu	$a1,0xc($s2)
/*  f110368:	0fc354be */ 	jal	savefileGetSomething
/*  f11036c:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f110370:	3c028006 */ 	lui	$v0,%hi(g_SfxVolume)
/*  f110374:	9442ddc8 */ 	lhu	$v0,%lo(g_SfxVolume)($v0)
/*  f110378:	02802025 */ 	or	$a0,$s4,$zero
/*  f11037c:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f110380:	28415001 */ 	slti	$at,$v0,0x5001
/*  f110384:	54200004 */ 	bnezl	$at,.L0f110398
/*  f110388:	00403825 */ 	or	$a3,$v0,$zero
/*  f11038c:	10000002 */ 	b	.L0f110398
/*  f110390:	24075000 */ 	addiu	$a3,$zero,0x5000
/*  f110394:	00403825 */ 	or	$a3,$v0,$zero
.L0f110398:
/*  f110398:	000729c3 */ 	sra	$a1,$a3,0x7
/*  f11039c:	00057082 */ 	srl	$t6,$a1,0x2
/*  f1103a0:	0fc354be */ 	jal	savefileGetSomething
/*  f1103a4:	01c02825 */ 	or	$a1,$t6,$zero
/*  f1103a8:	0fc54bd4 */ 	jal	optionsGetMusicVolume
/*  f1103ac:	00000000 */ 	nop
/*  f1103b0:	000229c3 */ 	sra	$a1,$v0,0x7
/*  f1103b4:	00057882 */ 	srl	$t7,$a1,0x2
/*  f1103b8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f1103bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103c0:	0fc354be */ 	jal	savefileGetSomething
/*  f1103c4:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f1103c8:	3c058006 */ 	lui	$a1,%hi(g_SoundMode)
/*  f1103cc:	8ca5ddcc */ 	lw	$a1,%lo(g_SoundMode)($a1)
/*  f1103d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103d4:	0fc354be */ 	jal	savefileGetSomething
/*  f1103d8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1103dc:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f1103e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1103e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1103ec:	0fc354be */ 	jal	savefileGetSomething
/*  f1103f0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1103f4:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f1103f8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1103fc:	02802025 */ 	or	$a0,$s4,$zero
/*  f110400:	00402825 */ 	or	$a1,$v0,$zero
/*  f110404:	0fc354be */ 	jal	savefileGetSomething
/*  f110408:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f11040c:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f110410:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0xa)
/*  f110414:	2631220a */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0xa)
/*  f110418:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
/*  f11041c:	02802025 */ 	or	$a0,$s4,$zero
.L0f110420:
/*  f110420:	92050014 */ 	lbu	$a1,0x14($s0)
/*  f110424:	0fc354be */ 	jal	savefileGetSomething
/*  f110428:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f11042c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110430:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110434:	5420fffa */ 	bnezl	$at,.L0f110420
/*  f110438:	02802025 */ 	or	$a0,$s4,$zero
/*  f11043c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110440:	9645001e */ 	lhu	$a1,0x1e($s2)
/*  f110444:	0fc354be */ 	jal	savefileGetSomething
/*  f110448:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f11044c:	3c15800a */ 	lui	$s5,%hi(g_SoloSaveFile)
/*  f110450:	26b52200 */ 	addiu	$s5,$s5,%lo(g_SoloSaveFile)
/*  f110454:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f110458:	00008825 */ 	or	$s1,$zero,$zero
.L0f11045c:
/*  f11045c:	02a09025 */ 	or	$s2,$s5,$zero
.L0f110460:
/*  f110460:	02802025 */ 	or	$a0,$s4,$zero
/*  f110464:	96450020 */ 	lhu	$a1,0x20($s2)
/*  f110468:	0fc354be */ 	jal	savefileGetSomething
/*  f11046c:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f110470:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f110474:	1633fffa */ 	bne	$s1,$s3,.L0f110460
/*  f110478:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f11047c:	3c18800a */ 	lui	$t8,%hi(g_SoloSaveFile+0x7e)
/*  f110480:	2718227e */ 	addiu	$t8,$t8,%lo(g_SoloSaveFile+0x7e)
/*  f110484:	26b50006 */ 	addiu	$s5,$s5,0x6
/*  f110488:	02b8082b */ 	sltu	$at,$s5,$t8
/*  f11048c:	5420fff3 */ 	bnezl	$at,.L0f11045c
/*  f110490:	00008825 */ 	or	$s1,$zero,$zero
/*  f110494:	00008825 */ 	or	$s1,$zero,$zero
/*  f110498:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f11049c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f1104a0:
/*  f1104a0:	02202025 */ 	or	$a0,$s1,$zero
.L0f1104a4:
/*  f1104a4:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f1104a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1104ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f1104b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1104b4:	0fc354be */ 	jal	savefileGetSomething
/*  f1104b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1104bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1104c0:	5612fff8 */ 	bnel	$s0,$s2,.L0f1104a4
/*  f1104c4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1104c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1104cc:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f1104d0:	5420fff3 */ 	bnezl	$at,.L0f1104a0
/*  f1104d4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1104d8:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f1104dc:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0xc)
/*  f1104e0:	2631220c */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0xc)
/*  f1104e4:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
/*  f1104e8:	02802025 */ 	or	$a0,$s4,$zero
.L0f1104ec:
/*  f1104ec:	8e0500a0 */ 	lw	$a1,0xa0($s0)
/*  f1104f0:	0fc354be */ 	jal	savefileGetSomething
/*  f1104f4:	24060015 */ 	addiu	$a2,$zero,0x15
/*  f1104f8:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1104fc:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110500:	5420fffa */ 	bnezl	$at,.L0f1104ec
/*  f110504:	02802025 */ 	or	$a0,$s4,$zero
/*  f110508:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f11050c:	3c12800a */ 	lui	$s2,%hi(g_SoloSaveFile+0x9)
/*  f110510:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0x8)
/*  f110514:	26312208 */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0x8)
/*  f110518:	26522209 */ 	addiu	$s2,$s2,%lo(g_SoloSaveFile+0x9)
/*  f11051c:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
.L0f110520:
/*  f110520:	16110003 */ 	bne	$s0,$s1,.L0f110530
/*  f110524:	02802025 */ 	or	$a0,$s4,$zero
/*  f110528:	10000002 */ 	b	.L0f110534
/*  f11052c:	24070002 */ 	addiu	$a3,$zero,0x2
.L0f110530:
/*  f110530:	24070008 */ 	addiu	$a3,$zero,0x8
.L0f110534:
/*  f110534:	920500ac */ 	lbu	$a1,0xac($s0)
/*  f110538:	0fc354be */ 	jal	savefileGetSomething
/*  f11053c:	00e03025 */ 	or	$a2,$a3,$zero
/*  f110540:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110544:	0212082b */ 	sltu	$at,$s0,$s2
/*  f110548:	1420fff5 */ 	bnez	$at,.L0f110520
/*  f11054c:	00000000 */ 	nop
/*  f110550:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f110554:	3c11800a */ 	lui	$s1,%hi(g_SoloSaveFile+0x4)
/*  f110558:	26312204 */ 	addiu	$s1,$s1,%lo(g_SoloSaveFile+0x4)
/*  f11055c:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
/*  f110560:	02802025 */ 	or	$a0,$s4,$zero
.L0f110564:
/*  f110564:	920500b5 */ 	lbu	$a1,0xb5($s0)
/*  f110568:	0fc354be */ 	jal	savefileGetSomething
/*  f11056c:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f110570:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110574:	5611fffb */ 	bnel	$s0,$s1,.L0f110564
/*  f110578:	02802025 */ 	or	$a0,$s4,$zero
/*  f11057c:	0fc35531 */ 	jal	func0f0d54c4
/*  f110580:	02802025 */ 	or	$a0,$s4,$zero
/*  f110584:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f110588:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f11058c:	83a4014b */ 	lb	$a0,0x14b($sp)
/*  f110590:	8fa5014c */ 	lw	$a1,0x14c($sp)
/*  f110594:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f110598:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f11059c:	0fc45a0a */ 	jal	func0f116828
/*  f1105a0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1105a4:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f1105a8:	14400009 */ 	bnez	$v0,.L0f1105d0
/*  f1105ac:	ac2221f8 */ 	sw	$v0,%lo(var800a21f8)($at)
/*  f1105b0:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f1105b4:	97a90152 */ 	lhu	$t1,0x152($sp)
/*  f1105b8:	3c03800a */ 	lui	$v1,%hi(g_FilemgrLoadedMainFile)
/*  f1105bc:	246322c0 */ 	addiu	$v1,$v1,%lo(g_FilemgrLoadedMainFile)
/*  f1105c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1105c4:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f1105c8:	10000003 */ 	b	.L0f1105d8
/*  f1105cc:	a4690004 */ 	sh	$t1,0x4($v1)
.L0f1105d0:
/*  f1105d0:	10000001 */ 	b	.L0f1105d8
/*  f1105d4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f1105d8:
/*  f1105d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1105dc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1105e0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1105e4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1105e8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1105ec:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f1105f0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f1105f4:	03e00008 */ 	jr	$ra
/*  f1105f8:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#endif

void savefileGetOverview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time)
{
	s32 sp18[56];

	func0f0d5484(sp18, arg0, 0xf);
	func0f0d54e4(sp18, name, 0);

	*stage = savefileGetInteger(sp18, 5);
	*time = savefileGetInteger(sp18, 0x20);
	*difficulty = savefileGetInteger(sp18, 2);
}
