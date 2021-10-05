#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/game_0b69d0.h"
#include "game/savebuffer.h"
#include "game/bg.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_0bfb0.h"
#include "lib/snd.h"
#include "lib/lib_126b0.h"
#include "data.h"
#include "types.h"

u8 *gamefileGetFlags(void)
{
	return g_GameFile.flags;
}

void gamefileSetFlag(u32 value)
{
	pakSetBitflag(value, g_GameFile.flags, true);
}

void gamefileUnsetFlag(u32 value)
{
	pakSetBitflag(value, g_GameFile.flags, false);
}

u32 gamefileHasFlag(u32 value)
{
	return pakHasBitflag(value, g_GameFile.flags);
}

void gamefilePrintFlags(void)
{
	s32 i;

	for (i = 0x23; i != 0x4f; i++) {
		osSyncPrintf("Flag %d = %s", i,
				pakHasBitflag(i, g_GameFile.flags) ? "TRUE" : "FALSE");
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel gamefileApplyOptions
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
/*  f10fbf8:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fbfc:	02002825 */ 	move	$a1,$s0
/*  f10fc00:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc04:	0fc54d7e */ 	jal	optionsSetForwardPitch
/*  f10fc08:	00402825 */ 	move	$a1,$v0
/*  f10fc0c:	24040001 */ 	li	$a0,0x1
/*  f10fc10:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc14:	02002825 */ 	move	$a1,$s0
/*  f10fc18:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc1c:	0fc54d94 */ 	jal	optionsSetAutoAim
/*  f10fc20:	00402825 */ 	move	$a1,$v0
/*  f10fc24:	24040002 */ 	li	$a0,0x2
/*  f10fc28:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc2c:	02002825 */ 	move	$a1,$s0
/*  f10fc30:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc34:	0fc54dc0 */ 	jal	optionsSetAimControl
/*  f10fc38:	00402825 */ 	move	$a1,$v0
/*  f10fc3c:	24040003 */ 	li	$a0,0x3
/*  f10fc40:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc44:	02002825 */ 	move	$a1,$s0
/*  f10fc48:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc4c:	0fc54dd6 */ 	jal	optionsSetSightOnScreen
/*  f10fc50:	00402825 */ 	move	$a1,$v0
/*  f10fc54:	24040004 */ 	li	$a0,0x4
/*  f10fc58:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc5c:	02002825 */ 	move	$a1,$s0
/*  f10fc60:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc64:	0fc54daa */ 	jal	optionsSetLookAhead
/*  f10fc68:	00402825 */ 	move	$a1,$v0
/*  f10fc6c:	24040005 */ 	li	$a0,0x5
/*  f10fc70:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc74:	02002825 */ 	move	$a1,$s0
/*  f10fc78:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc7c:	0fc54dec */ 	jal	optionsSetAmmoOnScreen
/*  f10fc80:	00402825 */ 	move	$a1,$v0
/*  f10fc84:	24040009 */ 	li	$a0,0x9
/*  f10fc88:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fc8c:	02002825 */ 	move	$a1,$s0
/*  f10fc90:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fc94:	0fc54e76 */ 	jal	optionsSetHeadRoll
/*  f10fc98:	00402825 */ 	move	$a1,$v0
/*  f10fc9c:	2404000a */ 	li	$a0,0xa
/*  f10fca0:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fca4:	02002825 */ 	move	$a1,$s0
/*  f10fca8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcac:	0fc54e02 */ 	jal	optionsSetShowGunFunction
/*  f10fcb0:	00402825 */ 	move	$a1,$v0
/*  f10fcb4:	24040015 */ 	li	$a0,0x15
/*  f10fcb8:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fcbc:	02002825 */ 	move	$a1,$s0
/*  f10fcc0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcc4:	0fc54e18 */ 	jal	optionsSetAlwaysShowTarget
/*  f10fcc8:	00402825 */ 	move	$a1,$v0
/*  f10fccc:	24040017 */ 	li	$a0,0x17
/*  f10fcd0:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fcd4:	02002825 */ 	move	$a1,$s0
/*  f10fcd8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcdc:	0fc54e2e */ 	jal	optionsSetShowZoomRange
/*  f10fce0:	00402825 */ 	move	$a1,$v0
/*  f10fce4:	2404001a */ 	li	$a0,0x1a
/*  f10fce8:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fcec:	02002825 */ 	move	$a1,$s0
/*  f10fcf0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fcf4:	0fc54e5a */ 	jal	optionsSetShowMissionTime
/*  f10fcf8:	00402825 */ 	move	$a1,$v0
/*  f10fcfc:	24040020 */ 	li	$a0,0x20
/*  f10fd00:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd04:	02002825 */ 	move	$a1,$s0
/*  f10fd08:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fd0c:	0fc54e44 */ 	jal	optionsSetPaintball
/*  f10fd10:	00402825 */ 	move	$a1,$v0
/*  f10fd14:	2404000c */ 	li	$a0,0xc
/*  f10fd18:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd1c:	02002825 */ 	move	$a1,$s0
/*  f10fd20:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd24:	0fc54d7e */ 	jal	optionsSetForwardPitch
/*  f10fd28:	00402825 */ 	move	$a1,$v0
/*  f10fd2c:	2404000d */ 	li	$a0,0xd
/*  f10fd30:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd34:	02002825 */ 	move	$a1,$s0
/*  f10fd38:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd3c:	0fc54d94 */ 	jal	optionsSetAutoAim
/*  f10fd40:	00402825 */ 	move	$a1,$v0
/*  f10fd44:	2404000e */ 	li	$a0,0xe
/*  f10fd48:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd4c:	02002825 */ 	move	$a1,$s0
/*  f10fd50:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd54:	0fc54dc0 */ 	jal	optionsSetAimControl
/*  f10fd58:	00402825 */ 	move	$a1,$v0
/*  f10fd5c:	2404000f */ 	li	$a0,0xf
/*  f10fd60:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd64:	02002825 */ 	move	$a1,$s0
/*  f10fd68:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd6c:	0fc54dd6 */ 	jal	optionsSetSightOnScreen
/*  f10fd70:	00402825 */ 	move	$a1,$v0
/*  f10fd74:	24040010 */ 	li	$a0,0x10
/*  f10fd78:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd7c:	02002825 */ 	move	$a1,$s0
/*  f10fd80:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd84:	0fc54daa */ 	jal	optionsSetLookAhead
/*  f10fd88:	00402825 */ 	move	$a1,$v0
/*  f10fd8c:	24040011 */ 	li	$a0,0x11
/*  f10fd90:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fd94:	02002825 */ 	move	$a1,$s0
/*  f10fd98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fd9c:	0fc54dec */ 	jal	optionsSetAmmoOnScreen
/*  f10fda0:	00402825 */ 	move	$a1,$v0
/*  f10fda4:	24040012 */ 	li	$a0,0x12
/*  f10fda8:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fdac:	02002825 */ 	move	$a1,$s0
/*  f10fdb0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdb4:	0fc54e76 */ 	jal	optionsSetHeadRoll
/*  f10fdb8:	00402825 */ 	move	$a1,$v0
/*  f10fdbc:	24040013 */ 	li	$a0,0x13
/*  f10fdc0:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fdc4:	02002825 */ 	move	$a1,$s0
/*  f10fdc8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdcc:	0fc54e02 */ 	jal	optionsSetShowGunFunction
/*  f10fdd0:	00402825 */ 	move	$a1,$v0
/*  f10fdd4:	24040016 */ 	li	$a0,0x16
/*  f10fdd8:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fddc:	02002825 */ 	move	$a1,$s0
/*  f10fde0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fde4:	0fc54e18 */ 	jal	optionsSetAlwaysShowTarget
/*  f10fde8:	00402825 */ 	move	$a1,$v0
/*  f10fdec:	24040018 */ 	li	$a0,0x18
/*  f10fdf0:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fdf4:	02002825 */ 	move	$a1,$s0
/*  f10fdf8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fdfc:	0fc54e2e */ 	jal	optionsSetShowZoomRange
/*  f10fe00:	00402825 */ 	move	$a1,$v0
/*  f10fe04:	2404001b */ 	li	$a0,0x1b
/*  f10fe08:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe0c:	02002825 */ 	move	$a1,$s0
/*  f10fe10:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe14:	0fc54e5a */ 	jal	optionsSetShowMissionTime
/*  f10fe18:	00402825 */ 	move	$a1,$v0
/*  f10fe1c:	24040021 */ 	li	$a0,0x21
/*  f10fe20:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe24:	02002825 */ 	move	$a1,$s0
/*  f10fe28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe2c:	0fc54e44 */ 	jal	optionsSetPaintball
/*  f10fe30:	00402825 */ 	move	$a1,$v0
/*  f10fe34:	2404000b */ 	li	$a0,0xb
/*  f10fe38:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe3c:	02002825 */ 	move	$a1,$s0
/*  f10fe40:	0fc54e70 */ 	jal	optionsSetInGameSubtitles
/*  f10fe44:	00402025 */ 	move	$a0,$v0
/*  f10fe48:	24040014 */ 	li	$a0,0x14
/*  f10fe4c:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe50:	02002825 */ 	move	$a1,$s0
/*  f10fe54:	0fc54e73 */ 	jal	optionsSetCutsceneSubtitles
/*  f10fe58:	00402025 */ 	move	$a0,$v0
/*  f10fe5c:	24040021 */ 	li	$a0,0x21
/*  f10fe60:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe64:	02002825 */ 	move	$a1,$s0
/*  f10fe68:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fe6c:	0fc54e44 */ 	jal	optionsSetPaintball
/*  f10fe70:	00402825 */ 	move	$a1,$v0
/*  f10fe74:	24040040 */ 	li	$a0,0x40
/*  f10fe78:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe7c:	02002825 */ 	move	$a1,$s0
/*  f10fe80:	3c01800a */ 	lui	$at,0x800a
/*  f10fe84:	a022a9f3 */ 	sb	$v0,-0x560d($at)
/*  f10fe88:	24040022 */ 	li	$a0,0x22
/*  f10fe8c:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10fe90:	02002825 */ 	move	$a1,$s0
/*  f10fe94:	1040000d */ 	beqz	$v0,.PF0f10fecc
/*  f10fe98:	3c098009 */ 	lui	$t1,0x8009
/*  f10fe9c:	91291040 */ 	lbu	$t1,0x1040($t1)
/*  f10fea0:	24010001 */ 	li	$at,0x1
/*  f10fea4:	15210005 */ 	bne	$t1,$at,.PF0f10febc
/*  f10fea8:	00000000 */ 	nop
/*  f10feac:	0fc2f26f */ 	jal	optionsSetHiRes
/*  f10feb0:	00002025 */ 	move	$a0,$zero
/*  f10feb4:	10000007 */ 	b	.PF0f10fed4
/*  f10feb8:	00000000 */ 	nop
.PF0f10febc:
/*  f10febc:	0fc2f26f */ 	jal	optionsSetHiRes
/*  f10fec0:	24040001 */ 	li	$a0,0x1
/*  f10fec4:	10000003 */ 	b	.PF0f10fed4
/*  f10fec8:	00000000 */ 	nop
.PF0f10fecc:
/*  f10fecc:	0fc2f26f */ 	jal	optionsSetHiRes
/*  f10fed0:	00002025 */ 	move	$a0,$zero
.PF0f10fed4:
/*  f10fed4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f10fed8:	914a1040 */ 	lbu	$t2,0x1040($t2)
/*  f10fedc:	24010001 */ 	li	$at,0x1
/*  f10fee0:	55410008 */ 	bnel	$t2,$at,.PF0f10ff04
/*  f10fee4:	24040019 */ 	li	$a0,0x19
/*  f10fee8:	0fc54efc */ 	jal	optionsSetScreenSplit
/*  f10feec:	00002025 */ 	move	$a0,$zero
/*  f10fef0:	0fc54ef6 */ 	jal	optionsSetScreenRatio
/*  f10fef4:	00002025 */ 	move	$a0,$zero
/*  f10fef8:	1000000c */ 	b	.PF0f10ff2c
/*  f10fefc:	24040008 */ 	li	$a0,0x8
/*  f10ff00:	24040019 */ 	li	$a0,0x19
.PF0f10ff04:
/*  f10ff04:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10ff08:	02002825 */ 	move	$a1,$s0
/*  f10ff0c:	0fc54efc */ 	jal	optionsSetScreenSplit
/*  f10ff10:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10ff14:	24040007 */ 	li	$a0,0x7
/*  f10ff18:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10ff1c:	02002825 */ 	move	$a1,$s0
/*  f10ff20:	0fc54ef6 */ 	jal	optionsSetScreenRatio
/*  f10ff24:	00402025 */ 	move	$a0,$v0
/*  f10ff28:	24040008 */ 	li	$a0,0x8
.PF0f10ff2c:
/*  f10ff2c:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10ff30:	02002825 */ 	move	$a1,$s0
/*  f10ff34:	50400006 */ 	beqzl	$v0,.PF0f10ff50
/*  f10ff38:	24040006 */ 	li	$a0,0x6
/*  f10ff3c:	0fc54ef0 */ 	jal	optionsSetScreenSize
/*  f10ff40:	24040002 */ 	li	$a0,0x2
/*  f10ff44:	1000000d */ 	b	.PF0f10ff7c
/*  f10ff48:	2404001f */ 	li	$a0,0x1f
/*  f10ff4c:	24040006 */ 	li	$a0,0x6
.PF0f10ff50:
/*  f10ff50:	0fc47c20 */ 	jal	pakHasBitflag
/*  f10ff54:	02002825 */ 	move	$a1,$s0
/*  f10ff58:	10400005 */ 	beqz	$v0,.PF0f10ff70
/*  f10ff5c:	00000000 */ 	nop
/*  f10ff60:	0fc54ef0 */ 	jal	optionsSetScreenSize
/*  f10ff64:	24040001 */ 	li	$a0,0x1
/*  f10ff68:	10000004 */ 	b	.PF0f10ff7c
/*  f10ff6c:	2404001f */ 	li	$a0,0x1f
.PF0f10ff70:
/*  f10ff70:	0fc54ef0 */ 	jal	optionsSetScreenSize
/*  f10ff74:	00002025 */ 	move	$a0,$zero
/*  f10ff78:	2404001f */ 	li	$a0,0x1f
.PF0f10ff7c:
/*  f10ff7c:	0fc47c20 */ 	jal	pakHasBitflag
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
/*  f10ffa4:	0fc47c20 */ 	jal	pakHasBitflag
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
/*  f10ffcc:	0fc47c20 */ 	jal	pakHasBitflag
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
/*  f10fff4:	0fc47c20 */ 	jal	pakHasBitflag
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
/*  f110024:	0fc47c20 */ 	jal	pakHasBitflag
/*  f110028:	02002825 */ 	move	$a1,$s0
/*  f11002c:	10400006 */ 	beqz	$v0,.PF0f110048
/*  f110030:	24040045 */ 	li	$a0,0x45
/*  f110034:	3c0f800a */ 	lui	$t7,0x800a
/*  f110038:	95efa992 */ 	lhu	$t7,-0x566e($t7)
/*  f11003c:	3c01800a */ 	lui	$at,0x800a
/*  f110040:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f110044:	a438a992 */ 	sh	$t8,-0x566e($at)
.PF0f110048:
/*  f110048:	0fc47c20 */ 	jal	pakHasBitflag
/*  f11004c:	02002825 */ 	move	$a1,$s0
/*  f110050:	10400006 */ 	beqz	$v0,.PF0f11006c
/*  f110054:	24040046 */ 	li	$a0,0x46
/*  f110058:	3c19800a */ 	lui	$t9,0x800a
/*  f11005c:	9739a992 */ 	lhu	$t9,-0x566e($t9)
/*  f110060:	3c01800a */ 	lui	$at,0x800a
/*  f110064:	37280002 */ 	ori	$t0,$t9,0x2
/*  f110068:	a428a992 */ 	sh	$t0,-0x566e($at)
.PF0f11006c:
/*  f11006c:	0fc47c20 */ 	jal	pakHasBitflag
/*  f110070:	02002825 */ 	move	$a1,$s0
/*  f110074:	10400006 */ 	beqz	$v0,.PF0f110090
/*  f110078:	3c04800a */ 	lui	$a0,0x800a
/*  f11007c:	3c09800a */ 	lui	$t1,0x800a
/*  f110080:	9529a992 */ 	lhu	$t1,-0x566e($t1)
/*  f110084:	3c01800a */ 	lui	$at,0x800a
/*  f110088:	352a0004 */ 	ori	$t2,$t1,0x4
/*  f11008c:	a42aa992 */ 	sh	$t2,-0x566e($at)
.PF0f110090:
/*  f110090:	0fc5bdd7 */ 	jal	func0f16f75c
/*  f110094:	9484a992 */ 	lhu	$a0,-0x566e($a0)
/*  f110098:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11009c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1100a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1100a4:	03e00008 */ 	jr	$ra
/*  f1100a8:	00000000 */ 	nop
);
#else
void gamefileApplyOptions(struct gamefile *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;

	optionsSetForwardPitch(player1, pakHasBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags));
	optionsSetAutoAim(player1, pakHasBitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags));
	optionsSetAimControl(player1, pakHasBitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags));
	optionsSetSightOnScreen(player1, pakHasBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags));
	optionsSetLookAhead(player1, pakHasBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags));
	optionsSetAmmoOnScreen(player1, pakHasBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags));
	optionsSetHeadRoll(player1, pakHasBitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags));
	optionsSetShowGunFunction(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags));
	optionsSetAlwaysShowTarget(player1, pakHasBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags));
	optionsSetShowZoomRange(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags));
	optionsSetShowMissionTime(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags));
	optionsSetPaintball(player1, pakHasBitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags));

	optionsSetForwardPitch(player2, pakHasBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags));
	optionsSetAutoAim(player2, pakHasBitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags));
	optionsSetAimControl(player2, pakHasBitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags));
	optionsSetSightOnScreen(player2, pakHasBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags));
	optionsSetLookAhead(player2, pakHasBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags));
	optionsSetAmmoOnScreen(player2, pakHasBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags));
	optionsSetHeadRoll(player2, pakHasBitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags));
	optionsSetShowGunFunction(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags));
	optionsSetAlwaysShowTarget(player2, pakHasBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags));
	optionsSetShowZoomRange(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags));
	optionsSetShowMissionTime(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags));
	optionsSetPaintball(player2, pakHasBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	optionsSetInGameSubtitles(pakHasBitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags));
	optionsSetCutsceneSubtitles(pakHasBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags));

	// Duplicate
	optionsSetPaintball(player2, pakHasBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	g_Vars.langfilteron = pakHasBitflag(GAMEFILEFLAG_LANGFILTERON, file->flags);

	if (pakHasBitflag(GAMEFILEFLAG_HIRES, file->flags)) {
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
		optionsSetScreenSplit(pakHasBitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags));
		optionsSetScreenRatio(pakHasBitflag(GAMEFILEFLAG_SCREENRATIO, file->flags));
	}

	if (pakHasBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags)) {
		optionsSetScreenSize(SCREENSIZE_CINEMA);
	} else if (pakHasBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags)) {
		optionsSetScreenSize(SCREENSIZE_WIDE);
	} else {
		optionsSetScreenSize(SCREENSIZE_FULL);
	}

	g_Vars.pendingantiplayernum = pakHasBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags) ? 1 : 0;
	g_Vars.coopradaron = pakHasBitflag(GAMEFILEFLAG_COOPRADARON, file->flags) ? 1 : 0;
	g_Vars.coopfriendlyfire = pakHasBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags) ? 1 : 0;
	g_Vars.antiradaron = pakHasBitflag(GAMEFILEFLAG_ANTIRADARON, file->flags) ? 1 : 0;
}
#endif

#if VERSION >= VERSION_PAL_FINAL
const char var7f1b4bd0pf[] = "Dark";

GLOBAL_ASM(
glabel gamefileLoadDefaults
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
/*  f110110:	0c004bb0 */ 	jal	strcpy
/*  f110114:	24a54bd0 */ 	addiu	$a1,$a1,0x4bd0
/*  f110118:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f11011c:	24045000 */ 	li	$a0,0x5000
/*  f110120:	9058000b */ 	lbu	$t8,0xb($v0)
/*  f110124:	a040000c */ 	sb	$zero,0xc($v0)
/*  f110128:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f11012c:	3308ff07 */ 	andi	$t0,$t8,0xff07
/*  f110130:	310900f8 */ 	andi	$t1,$t0,0xf8
/*  f110134:	a048000b */ 	sb	$t0,0xb($v0)
/*  f110138:	0c0039df */ 	jal	sndSetSfxVolume
/*  f11013c:	a049000b */ 	sb	$t1,0xb($v0)
/*  f110140:	0fc54f08 */ 	jal	optionsSetMusicVolume
/*  f110144:	24045000 */ 	li	$a0,0x5000
/*  f110148:	0c003c3b */ 	jal	sndSetSoundMode
/*  f11014c:	24040001 */ 	li	$a0,0x1
/*  f110150:	02202025 */ 	move	$a0,$s1
/*  f110154:	0fc54cf7 */ 	jal	optionsSetControlMode
/*  f110158:	00002825 */ 	move	$a1,$zero
/*  f11015c:	02002025 */ 	move	$a0,$s0
/*  f110160:	0fc54cf7 */ 	jal	optionsSetControlMode
/*  f110164:	00002825 */ 	move	$a1,$zero
/*  f110168:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f11016c:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f110170:	0fc47c2e */ 	jal	pakClearAllBitflags
/*  f110174:	02002025 */ 	move	$a0,$s0
/*  f110178:	00002025 */ 	move	$a0,$zero
/*  f11017c:	02002825 */ 	move	$a1,$s0
/*  f110180:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110184:	00003025 */ 	move	$a2,$zero
/*  f110188:	24040001 */ 	li	$a0,0x1
/*  f11018c:	02002825 */ 	move	$a1,$s0
/*  f110190:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110194:	24060001 */ 	li	$a2,0x1
/*  f110198:	24040002 */ 	li	$a0,0x2
/*  f11019c:	02002825 */ 	move	$a1,$s0
/*  f1101a0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101a4:	00003025 */ 	move	$a2,$zero
/*  f1101a8:	24040003 */ 	li	$a0,0x3
/*  f1101ac:	02002825 */ 	move	$a1,$s0
/*  f1101b0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101b4:	24060001 */ 	li	$a2,0x1
/*  f1101b8:	24040004 */ 	li	$a0,0x4
/*  f1101bc:	02002825 */ 	move	$a1,$s0
/*  f1101c0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101c4:	24060001 */ 	li	$a2,0x1
/*  f1101c8:	24040005 */ 	li	$a0,0x5
/*  f1101cc:	02002825 */ 	move	$a1,$s0
/*  f1101d0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101d4:	24060001 */ 	li	$a2,0x1
/*  f1101d8:	24040009 */ 	li	$a0,0x9
/*  f1101dc:	02002825 */ 	move	$a1,$s0
/*  f1101e0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101e4:	24060001 */ 	li	$a2,0x1
/*  f1101e8:	2404000a */ 	li	$a0,0xa
/*  f1101ec:	02002825 */ 	move	$a1,$s0
/*  f1101f0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1101f4:	24060001 */ 	li	$a2,0x1
/*  f1101f8:	2404000b */ 	li	$a0,0xb
/*  f1101fc:	02002825 */ 	move	$a1,$s0
/*  f110200:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110204:	24060001 */ 	li	$a2,0x1
/*  f110208:	24040015 */ 	li	$a0,0x15
/*  f11020c:	02002825 */ 	move	$a1,$s0
/*  f110210:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110214:	24060001 */ 	li	$a2,0x1
/*  f110218:	24040017 */ 	li	$a0,0x17
/*  f11021c:	02002825 */ 	move	$a1,$s0
/*  f110220:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110224:	24060001 */ 	li	$a2,0x1
/*  f110228:	2404001a */ 	li	$a0,0x1a
/*  f11022c:	02002825 */ 	move	$a1,$s0
/*  f110230:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110234:	00003025 */ 	move	$a2,$zero
/*  f110238:	24040020 */ 	li	$a0,0x20
/*  f11023c:	02002825 */ 	move	$a1,$s0
/*  f110240:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110244:	00003025 */ 	move	$a2,$zero
/*  f110248:	2404000c */ 	li	$a0,0xc
/*  f11024c:	02002825 */ 	move	$a1,$s0
/*  f110250:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110254:	00003025 */ 	move	$a2,$zero
/*  f110258:	2404000d */ 	li	$a0,0xd
/*  f11025c:	02002825 */ 	move	$a1,$s0
/*  f110260:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110264:	24060001 */ 	li	$a2,0x1
/*  f110268:	2404000e */ 	li	$a0,0xe
/*  f11026c:	02002825 */ 	move	$a1,$s0
/*  f110270:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110274:	00003025 */ 	move	$a2,$zero
/*  f110278:	2404000f */ 	li	$a0,0xf
/*  f11027c:	02002825 */ 	move	$a1,$s0
/*  f110280:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110284:	24060001 */ 	li	$a2,0x1
/*  f110288:	24040010 */ 	li	$a0,0x10
/*  f11028c:	02002825 */ 	move	$a1,$s0
/*  f110290:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110294:	24060001 */ 	li	$a2,0x1
/*  f110298:	24040011 */ 	li	$a0,0x11
/*  f11029c:	02002825 */ 	move	$a1,$s0
/*  f1102a0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102a4:	24060001 */ 	li	$a2,0x1
/*  f1102a8:	24040012 */ 	li	$a0,0x12
/*  f1102ac:	02002825 */ 	move	$a1,$s0
/*  f1102b0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102b4:	24060001 */ 	li	$a2,0x1
/*  f1102b8:	24040013 */ 	li	$a0,0x13
/*  f1102bc:	02002825 */ 	move	$a1,$s0
/*  f1102c0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102c4:	24060001 */ 	li	$a2,0x1
/*  f1102c8:	24040014 */ 	li	$a0,0x14
/*  f1102cc:	02002825 */ 	move	$a1,$s0
/*  f1102d0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102d4:	00003025 */ 	move	$a2,$zero
/*  f1102d8:	24040016 */ 	li	$a0,0x16
/*  f1102dc:	02002825 */ 	move	$a1,$s0
/*  f1102e0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102e4:	24060001 */ 	li	$a2,0x1
/*  f1102e8:	24040018 */ 	li	$a0,0x18
/*  f1102ec:	02002825 */ 	move	$a1,$s0
/*  f1102f0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1102f4:	24060001 */ 	li	$a2,0x1
/*  f1102f8:	2404001b */ 	li	$a0,0x1b
/*  f1102fc:	02002825 */ 	move	$a1,$s0
/*  f110300:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110304:	00003025 */ 	move	$a2,$zero
/*  f110308:	24040021 */ 	li	$a0,0x21
/*  f11030c:	02002825 */ 	move	$a1,$s0
/*  f110310:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110314:	00003025 */ 	move	$a2,$zero
/*  f110318:	24040019 */ 	li	$a0,0x19
/*  f11031c:	02002825 */ 	move	$a1,$s0
/*  f110320:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110324:	00003025 */ 	move	$a2,$zero
/*  f110328:	24040007 */ 	li	$a0,0x7
/*  f11032c:	02002825 */ 	move	$a1,$s0
/*  f110330:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110334:	00003025 */ 	move	$a2,$zero
/*  f110338:	24040008 */ 	li	$a0,0x8
/*  f11033c:	02002825 */ 	move	$a1,$s0
/*  f110340:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110344:	00003025 */ 	move	$a2,$zero
/*  f110348:	24040006 */ 	li	$a0,0x6
/*  f11034c:	02002825 */ 	move	$a1,$s0
/*  f110350:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110354:	00003025 */ 	move	$a2,$zero
/*  f110358:	24040022 */ 	li	$a0,0x22
/*  f11035c:	02002825 */ 	move	$a1,$s0
/*  f110360:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110364:	00003025 */ 	move	$a2,$zero
/*  f110368:	24040040 */ 	li	$a0,0x40
/*  f11036c:	02002825 */ 	move	$a1,$s0
/*  f110370:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110374:	00003025 */ 	move	$a2,$zero
/*  f110378:	24040041 */ 	li	$a0,0x41
/*  f11037c:	02002825 */ 	move	$a1,$s0
/*  f110380:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110384:	00003025 */ 	move	$a2,$zero
/*  f110388:	24040042 */ 	li	$a0,0x42
/*  f11038c:	02002825 */ 	move	$a1,$s0
/*  f110390:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110394:	00003025 */ 	move	$a2,$zero
/*  f110398:	24040043 */ 	li	$a0,0x43
/*  f11039c:	02002825 */ 	move	$a1,$s0
/*  f1103a0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1103a4:	00003025 */ 	move	$a2,$zero
/*  f1103a8:	2404001c */ 	li	$a0,0x1c
/*  f1103ac:	02002825 */ 	move	$a1,$s0
/*  f1103b0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1103b4:	24060001 */ 	li	$a2,0x1
/*  f1103b8:	2404001d */ 	li	$a0,0x1d
/*  f1103bc:	02002825 */ 	move	$a1,$s0
/*  f1103c0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1103c4:	24060001 */ 	li	$a2,0x1
/*  f1103c8:	2404001e */ 	li	$a0,0x1e
/*  f1103cc:	02002825 */ 	move	$a1,$s0
/*  f1103d0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1103d4:	24060001 */ 	li	$a2,0x1
/*  f1103d8:	2404001f */ 	li	$a0,0x1f
/*  f1103dc:	02002825 */ 	move	$a1,$s0
/*  f1103e0:	0fc47c0b */ 	jal	pakSetBitflag
/*  f1103e4:	24060001 */ 	li	$a2,0x1
/*  f1103e8:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f1103ec:	3c10800a */ 	lui	$s0,0x800a
/*  f1103f0:	261027b4 */ 	addiu	$s0,$s0,0x27b4
/*  f1103f4:	30ca0001 */ 	andi	$t2,$a2,0x1
/*  f1103f8:	394b0001 */ 	xori	$t3,$t2,0x1
/*  f1103fc:	2d660001 */ 	sltiu	$a2,$t3,0x1
/*  f110400:	02002825 */ 	move	$a1,$s0
/*  f110404:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110408:	24040044 */ 	li	$a0,0x44
/*  f11040c:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f110410:	24040045 */ 	li	$a0,0x45
/*  f110414:	02002825 */ 	move	$a1,$s0
/*  f110418:	30cc0002 */ 	andi	$t4,$a2,0x2
/*  f11041c:	398d0002 */ 	xori	$t5,$t4,0x2
/*  f110420:	0fc47c0b */ 	jal	pakSetBitflag
/*  f110424:	2da60001 */ 	sltiu	$a2,$t5,0x1
/*  f110428:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f11042c:	24040046 */ 	li	$a0,0x46
/*  f110430:	02002825 */ 	move	$a1,$s0
/*  f110434:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f110438:	39cf0004 */ 	xori	$t7,$t6,0x4
/*  f11043c:	0fc47c0b */ 	jal	pakSetBitflag
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
/*  f110490:	0fc67543 */ 	jal	mpSetChallengeCompletedByAnyPlayerWithNumPlayers
/*  f110494:	00003025 */ 	move	$a2,$zero
/*  f110498:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11049c:	5611fffb */ 	bnel	$s0,$s1,.PF0f11048c
/*  f1104a0:	02402025 */ 	move	$a0,$s2
/*  f1104a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1104a8:	2a41001e */ 	slti	$at,$s2,0x1e
/*  f1104ac:	5420fff6 */ 	bnezl	$at,.PF0f110488
/*  f1104b0:	24100001 */ 	li	$s0,0x1
/*  f1104b4:	0fc67037 */ 	jal	mpDetermineUnlockedFeatures
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
/*  f110518:	0fc43ee5 */ 	jal	gamefileApplyOptions
/*  f11051c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f110520:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f110524:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110528:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11052c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110530:	03e00008 */ 	jr	$ra
/*  f110534:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#else
void gamefileLoadDefaults(struct gamefile *file)
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
	sndSetSfxVolume(0x5000);
	optionsSetMusicVolume(0x5000);
	sndSetSoundMode(SOUNDMODE_STEREO);
	optionsSetControlMode(player1, CONTROLMODE_11);
	optionsSetControlMode(player2, CONTROLMODE_11);
	pakClearAllBitflags(file->flags);

	pakSetBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags, AIMCONTROL_HOLD);
	pakSetBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags, AIMCONTROL_HOLD);
	pakSetBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags, SCREENSPLIT_HORIZONTAL);
	pakSetBitflag(GAMEFILEFLAG_SCREENRATIO, file->flags, SCREENRATIO_NORMAL);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_HIRES, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_LANGFILTERON, file->flags, false);

#if VERSION >= VERSION_NTSC_1_0
	pakSetBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, file->flags, false);
#endif

	pakSetBitflag(GAMEFILEFLAG_COOPRADARON, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_ANTIRADARON, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags, 1);

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

	for (i = 0; i < ARRAYCOUNT(g_GameFile.coopcompletions); i++) {
		g_GameFile.coopcompletions[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
		g_GameFile.firingrangescores[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound); i++) {
		g_GameFile.weaponsfound[i] = 0;
	}

	gamefileApplyOptions(file);
}
#endif

const char var7f1b38e8[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b391c[] = "pdoptions.c";
const char var7f1b3928[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b395c[] = "pdoptions.c";
const char var7f1b3968[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b399c[] = "pdoptions.c";

s32 gamefileLoad(s32 device)
{
	s32 p1index;
	s32 p2index;
	u32 volume;
	s32 i;
	s32 j;
	struct savebuffer buffer;
	s32 ret;
	u32 stack;

	p1index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 0 : 4;
	p2index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 1 : 5;

	if (device >= 0) {
		savebufferClear(&buffer);
		ret = pakReadBodyAtGuid(device, g_GameFileGuid.fileid, buffer.bytes, 0);
		g_FilemgrLastPakError = ret;

		if (ret == 0) {
			cheatsDisableAll();
			savebufferReadString(&buffer, g_GameFile.name, 0);
			g_GameFile.thumbnail = savebufferReadBits(&buffer, 5);
			g_GameFile.totaltime = savebufferReadBits(&buffer, 32);
			g_GameFile.autodifficulty = savebufferReadBits(&buffer, 2);
			g_GameFile.autostageindex = savebufferReadBits(&buffer, 5);

			volume = savebufferReadBits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			sndSetSfxVolume((volume & 0x1ff) * 128);

			volume = savebufferReadBits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			optionsSetMusicVolume((volume & 0x1ff) * 128);

			sndSetSoundMode(savebufferReadBits(&buffer, 2));
			optionsSetControlMode(p1index, savebufferReadBits(&buffer, 3));
			optionsSetControlMode(p2index, savebufferReadBits(&buffer, 3));

			for (i = 0; i < 10; i++) {
				g_GameFile.flags[i] = savebufferReadBits(&buffer, 8);
			}

			g_GameFile.unk1e = savebufferReadBits(&buffer, 16);

			for (i = 0; i < NUM_SOLOSTAGES; i++) {
				for (j = 0; j < 3; j++) {
					g_GameFile.besttimes[i][j] = savebufferReadBits(&buffer, 12);
				}
			}

			for (i = 0; i < 30; i++) {
				for (j = 1; j < 5; j++) {
					mpSetChallengeCompletedByAnyPlayerWithNumPlayers(i, j, savebufferReadBits(&buffer, 1));
				}
			}

			mpDetermineUnlockedFeatures();

			for (i = 0; i < 3; i++) {
				g_GameFile.coopcompletions[i] = savebufferReadBits(&buffer, 21);
			}

			for (i = 0; i < 9; i++) {
				s32 numbits = i == 8 ? 2 : 8;
				g_GameFile.firingrangescores[i] = savebufferReadBits(&buffer, numbits);
			}

			for (i = 0; i < 4; i++) {
				g_GameFile.weaponsfound[i] = savebufferReadBits(&buffer, 8);
			}

#if VERSION >= VERSION_NTSC_1_0
			if (pakHasBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_TIMEDMINE);
			}

			if (pakHasBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_PROXIMITYMINE);
			}

			if (pakHasBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_REMOTEMINE);
			}
#endif

			func0f0d54c4(&buffer);
			gamefileApplyOptions(&g_GameFile);

			return 0;
		}

		return -1;
	}

	return -1;
}

s32 gamefileSave(s32 device, s32 fileid, u16 deviceserial)
{
	u32 stack;
	s32 newfileid;
	s32 ret;
	s32 i;
	s32 j;
	s32 p1index;
	s32 p2index;
	struct savebuffer buffer;

	p1index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 0 : 4;
	p2index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 1 : 5;

	var80075bd0[0] = 1;

	pakSetBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, g_GameFile.flags, optionsGetForwardPitch(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AUTOAIM, g_GameFile.flags, optionsGetAutoAim(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AIMCONTROL, g_GameFile.flags, optionsGetAimControl(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, g_GameFile.flags, optionsGetSightOnScreen(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, g_GameFile.flags, optionsGetLookAhead(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, g_GameFile.flags, optionsGetAmmoOnScreen(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_HEADROLL, g_GameFile.flags, optionsGetHeadRoll(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, g_GameFile.flags, optionsGetShowGunFunction(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, g_GameFile.flags, optionsGetAlwaysShowTarget(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, g_GameFile.flags, optionsGetShowZoomRange(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, g_GameFile.flags, optionsGetShowMissionTime(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_PAINTBALL, g_GameFile.flags, optionsGetPaintball(p1index));

	pakSetBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, g_GameFile.flags, optionsGetForwardPitch(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AUTOAIM, g_GameFile.flags, optionsGetAutoAim(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AIMCONTROL, g_GameFile.flags, optionsGetAimControl(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, g_GameFile.flags, optionsGetSightOnScreen(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, g_GameFile.flags, optionsGetLookAhead(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, g_GameFile.flags, optionsGetAmmoOnScreen(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_HEADROLL, g_GameFile.flags, optionsGetHeadRoll(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, g_GameFile.flags, optionsGetShowGunFunction(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, g_GameFile.flags, optionsGetAlwaysShowTarget(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, g_GameFile.flags, optionsGetShowZoomRange(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, g_GameFile.flags, optionsGetShowMissionTime(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_PAINTBALL, g_GameFile.flags, optionsGetPaintball(p2index));

	pakSetBitflag(GAMEFILEFLAG_SCREENSPLIT, g_GameFile.flags, optionsGetScreenSplit());
	pakSetBitflag(GAMEFILEFLAG_SCREENRATIO, g_GameFile.flags, optionsGetScreenRatio());

#if VERSION >= VERSION_NTSC_1_0
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, g_GameFile.flags, optionsGetScreenSize() == SCREENSIZE_WIDE);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, g_GameFile.flags, optionsGetScreenSize() == SCREENSIZE_CINEMA);
#else
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, g_GameFile.flags, optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, g_GameFile.flags, optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA);
#endif

	pakSetBitflag(GAMEFILEFLAG_HIRES, g_GameFile.flags, g_ViMode == VIMODE_HIRES);
	pakSetBitflag(GAMEFILEFLAG_INGAMESUBTITLES, g_GameFile.flags, optionsGetInGameSubtitles());
	pakSetBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, g_GameFile.flags, optionsGetCutsceneSubtitles());
	pakSetBitflag(GAMEFILEFLAG_LANGFILTERON, g_GameFile.flags, g_Vars.langfilteron);

#if VERSION >= VERSION_NTSC_1_0
	pakSetBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_TIMEDMINE));
	pakSetBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_PROXIMITYMINE));
	pakSetBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_REMOTEMINE));
#endif

#if VERSION >= VERSION_NTSC_1_0
	switch (optionsGetScreenSize())
#else
	switch (optionsGetEffectiveScreenSize())
#endif
	{
	case SCREENSIZE_FULL:
		break;
	case SCREENSIZE_WIDE:
		break;
	case SCREENSIZE_CINEMA:
		break;
	}

	pakSetBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, g_GameFile.flags, g_Vars.pendingantiplayernum == 1);
	pakSetBitflag(GAMEFILEFLAG_COOPRADARON, g_GameFile.flags, g_Vars.coopradaron == 1);
	pakSetBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, g_GameFile.flags, g_Vars.coopfriendlyfire == 1);
	pakSetBitflag(GAMEFILEFLAG_ANTIRADARON, g_GameFile.flags, g_Vars.antiradaron == 1);

#if PAL
	pakSetBitflag(GAMEFILEFLAG_44, g_GameFile.flags, (g_Vars.unk000482 & 0x01) == 0x01);
	pakSetBitflag(GAMEFILEFLAG_45, g_GameFile.flags, (g_Vars.unk000482 & 0x02) == 0x02);
	pakSetBitflag(GAMEFILEFLAG_46, g_GameFile.flags, (g_Vars.unk000482 & 0x04) == 0x04);
#endif

	if (device >= 0) {
		savebufferClear(&buffer);
		func0f0d55a4(&buffer, g_GameFile.name);

		savebufferOr(&buffer, g_GameFile.thumbnail, 5);
		savebufferOr(&buffer, g_GameFile.totaltime, 32);
		savebufferOr(&buffer, g_GameFile.autodifficulty, 2);
		savebufferOr(&buffer, g_GameFile.autostageindex, 5);
		savebufferOr(&buffer, (u32)(VOLUME(g_SfxVolume) >> 7) >> 2, 6);
		savebufferOr(&buffer, (u32)(optionsGetMusicVolume() >> 7) >> 2, 6);
		savebufferOr(&buffer, g_SoundMode, 2);
		savebufferOr(&buffer, optionsGetControlMode(p1index), 3);
		savebufferOr(&buffer, optionsGetControlMode(p2index), 3);

		for (i = 0; i < 10; i++) {
			savebufferOr(&buffer, g_GameFile.flags[i], 8);
		}

		savebufferOr(&buffer, g_GameFile.unk1e, 16);

		for (i = 0; i < NUM_SOLOSTAGES; i++) {
			for (j = 0; j < 3; j++) {
				savebufferOr(&buffer, g_GameFile.besttimes[i][j], 12);
			}
		}

		for (i = 0; i < 30; i++) {
			for (j = 1; j < 5; j++) {
				savebufferOr(&buffer, mpIsChallengeCompletedByAnyPlayerWithNumPlayers(i, j), 1);
			}
		}

		for (i = 0; i < 3; i++) {
			savebufferOr(&buffer, g_GameFile.coopcompletions[i], 21);
		}

		for (i = 0; i < 9; i++) {
			savebufferOr(&buffer, g_GameFile.firingrangescores[i], i == 8 ? 2 : 8);
		}

		for (i = 0; i < 4; i++) {
			savebufferOr(&buffer, g_GameFile.weaponsfound[i], 8);
		}

		func0f0d54c4(&buffer);

		ret = pakSaveAtGuid(device, fileid, PAKFILETYPE_GAME, buffer.bytes, &newfileid, 0);
		g_FilemgrLastPakError = ret;

		if (ret == 0) {
			g_GameFileGuid.fileid = newfileid;
			g_GameFileGuid.deviceserial = deviceserial;

			return 0;
		}

		return -1;
	}

	return -1;
}

void gamefileGetOverview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, arg0, 15);
	savebufferReadString(&buffer, name, false);

	*stage = savebufferReadBits(&buffer, 5);

#if VERSION >= VERSION_NTSC_1_0
	*time = savebufferReadBits(&buffer, 32);
#else
	*time = (u16) savebufferReadBits(&buffer, 32);
#endif

	*difficulty = savebufferReadBits(&buffer, 2);
}
