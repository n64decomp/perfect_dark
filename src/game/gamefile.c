#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/player.h"
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
#include "lib/fault.h"
#include "lib/snd.h"
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
/*  f10feac:	0fc2f26f */ 	jal	playerSetHiResEnabled
/*  f10feb0:	00002025 */ 	move	$a0,$zero
/*  f10feb4:	10000007 */ 	b	.PF0f10fed4
/*  f10feb8:	00000000 */ 	nop
.PF0f10febc:
/*  f10febc:	0fc2f26f */ 	jal	playerSetHiResEnabled
/*  f10fec0:	24040001 */ 	li	$a0,0x1
/*  f10fec4:	10000003 */ 	b	.PF0f10fed4
/*  f10fec8:	00000000 */ 	nop
.PF0f10fecc:
/*  f10fecc:	0fc2f26f */ 	jal	playerSetHiResEnabled
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
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel gamefileApplyOptions
/*  f10f954:	3c03800a */ 	lui	$v1,0x800a
/*  f10f958:	2463e4d0 */ 	addiu	$v1,$v1,-6960
/*  f10f95c:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10f960:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10f964:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10f968:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10f96c:	04410005 */ 	bgez	$v0,.PB0f10f984
/*  f10f970:	00803025 */ 	move	$a2,$a0
/*  f10f974:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10f978:	240f0004 */ 	li	$t7,0x4
/*  f10f97c:	05c20004 */ 	bltzl	$t6,.PB0f10f990
/*  f10f980:	afaf0024 */ 	sw	$t7,0x24($sp)
.PB0f10f984:
/*  f10f984:	10000002 */ 	b	.PB0f10f990
/*  f10f988:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10f98c:	afaf0024 */ 	sw	$t7,0x24($sp)
.PB0f10f990:
/*  f10f990:	04410004 */ 	bgez	$v0,.PB0f10f9a4
/*  f10f994:	00002025 */ 	move	$a0,$zero
/*  f10f998:	8c78029c */ 	lw	$t8,0x29c($v1)
/*  f10f99c:	24080005 */ 	li	$t0,0x5
/*  f10f9a0:	07000003 */ 	bltz	$t8,.PB0f10f9b0
.PB0f10f9a4:
/*  f10f9a4:	24190001 */ 	li	$t9,0x1
/*  f10f9a8:	10000002 */ 	b	.PB0f10f9b4
/*  f10f9ac:	afb90020 */ 	sw	$t9,0x20($sp)
.PB0f10f9b0:
/*  f10f9b0:	afa80020 */ 	sw	$t0,0x20($sp)
.PB0f10f9b4:
/*  f10f9b4:	24d00014 */ 	addiu	$s0,$a2,0x14
/*  f10f9b8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10f9bc:	02002825 */ 	move	$a1,$s0
/*  f10f9c0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f9c4:	0fc54f3e */ 	jal	0xf153cf8
/*  f10f9c8:	00402825 */ 	move	$a1,$v0
/*  f10f9cc:	24040001 */ 	li	$a0,0x1
/*  f10f9d0:	0fc47b90 */ 	jal	0xf11ee40
/*  f10f9d4:	02002825 */ 	move	$a1,$s0
/*  f10f9d8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f9dc:	0fc54f54 */ 	jal	0xf153d50
/*  f10f9e0:	00402825 */ 	move	$a1,$v0
/*  f10f9e4:	24040002 */ 	li	$a0,0x2
/*  f10f9e8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10f9ec:	02002825 */ 	move	$a1,$s0
/*  f10f9f0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f9f4:	0fc54f80 */ 	jal	0xf153e00
/*  f10f9f8:	00402825 */ 	move	$a1,$v0
/*  f10f9fc:	24040003 */ 	li	$a0,0x3
/*  f10fa00:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa04:	02002825 */ 	move	$a1,$s0
/*  f10fa08:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa0c:	0fc54f96 */ 	jal	0xf153e58
/*  f10fa10:	00402825 */ 	move	$a1,$v0
/*  f10fa14:	24040004 */ 	li	$a0,0x4
/*  f10fa18:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa1c:	02002825 */ 	move	$a1,$s0
/*  f10fa20:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa24:	0fc54f6a */ 	jal	0xf153da8
/*  f10fa28:	00402825 */ 	move	$a1,$v0
/*  f10fa2c:	24040005 */ 	li	$a0,0x5
/*  f10fa30:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa34:	02002825 */ 	move	$a1,$s0
/*  f10fa38:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa3c:	0fc54fac */ 	jal	0xf153eb0
/*  f10fa40:	00402825 */ 	move	$a1,$v0
/*  f10fa44:	24040009 */ 	li	$a0,0x9
/*  f10fa48:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa4c:	02002825 */ 	move	$a1,$s0
/*  f10fa50:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa54:	0fc55036 */ 	jal	0xf1540d8
/*  f10fa58:	00402825 */ 	move	$a1,$v0
/*  f10fa5c:	2404000a */ 	li	$a0,0xa
/*  f10fa60:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa64:	02002825 */ 	move	$a1,$s0
/*  f10fa68:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa6c:	0fc54fc2 */ 	jal	0xf153f08
/*  f10fa70:	00402825 */ 	move	$a1,$v0
/*  f10fa74:	24040015 */ 	li	$a0,0x15
/*  f10fa78:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa7c:	02002825 */ 	move	$a1,$s0
/*  f10fa80:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa84:	0fc54fd8 */ 	jal	0xf153f60
/*  f10fa88:	00402825 */ 	move	$a1,$v0
/*  f10fa8c:	24040017 */ 	li	$a0,0x17
/*  f10fa90:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fa94:	02002825 */ 	move	$a1,$s0
/*  f10fa98:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fa9c:	0fc54fee */ 	jal	0xf153fb8
/*  f10faa0:	00402825 */ 	move	$a1,$v0
/*  f10faa4:	2404001a */ 	li	$a0,0x1a
/*  f10faa8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10faac:	02002825 */ 	move	$a1,$s0
/*  f10fab0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10fab4:	0fc5501a */ 	jal	0xf154068
/*  f10fab8:	00402825 */ 	move	$a1,$v0
/*  f10fabc:	24040020 */ 	li	$a0,0x20
/*  f10fac0:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fac4:	02002825 */ 	move	$a1,$s0
/*  f10fac8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10facc:	0fc55004 */ 	jal	0xf154010
/*  f10fad0:	00402825 */ 	move	$a1,$v0
/*  f10fad4:	2404000c */ 	li	$a0,0xc
/*  f10fad8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fadc:	02002825 */ 	move	$a1,$s0
/*  f10fae0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fae4:	0fc54f3e */ 	jal	0xf153cf8
/*  f10fae8:	00402825 */ 	move	$a1,$v0
/*  f10faec:	2404000d */ 	li	$a0,0xd
/*  f10faf0:	0fc47b90 */ 	jal	0xf11ee40
/*  f10faf4:	02002825 */ 	move	$a1,$s0
/*  f10faf8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fafc:	0fc54f54 */ 	jal	0xf153d50
/*  f10fb00:	00402825 */ 	move	$a1,$v0
/*  f10fb04:	2404000e */ 	li	$a0,0xe
/*  f10fb08:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb0c:	02002825 */ 	move	$a1,$s0
/*  f10fb10:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb14:	0fc54f80 */ 	jal	0xf153e00
/*  f10fb18:	00402825 */ 	move	$a1,$v0
/*  f10fb1c:	2404000f */ 	li	$a0,0xf
/*  f10fb20:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb24:	02002825 */ 	move	$a1,$s0
/*  f10fb28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb2c:	0fc54f96 */ 	jal	0xf153e58
/*  f10fb30:	00402825 */ 	move	$a1,$v0
/*  f10fb34:	24040010 */ 	li	$a0,0x10
/*  f10fb38:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb3c:	02002825 */ 	move	$a1,$s0
/*  f10fb40:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb44:	0fc54f6a */ 	jal	0xf153da8
/*  f10fb48:	00402825 */ 	move	$a1,$v0
/*  f10fb4c:	24040011 */ 	li	$a0,0x11
/*  f10fb50:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb54:	02002825 */ 	move	$a1,$s0
/*  f10fb58:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb5c:	0fc54fac */ 	jal	0xf153eb0
/*  f10fb60:	00402825 */ 	move	$a1,$v0
/*  f10fb64:	24040012 */ 	li	$a0,0x12
/*  f10fb68:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb6c:	02002825 */ 	move	$a1,$s0
/*  f10fb70:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb74:	0fc55036 */ 	jal	0xf1540d8
/*  f10fb78:	00402825 */ 	move	$a1,$v0
/*  f10fb7c:	24040013 */ 	li	$a0,0x13
/*  f10fb80:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb84:	02002825 */ 	move	$a1,$s0
/*  f10fb88:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fb8c:	0fc54fc2 */ 	jal	0xf153f08
/*  f10fb90:	00402825 */ 	move	$a1,$v0
/*  f10fb94:	24040016 */ 	li	$a0,0x16
/*  f10fb98:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fb9c:	02002825 */ 	move	$a1,$s0
/*  f10fba0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fba4:	0fc54fd8 */ 	jal	0xf153f60
/*  f10fba8:	00402825 */ 	move	$a1,$v0
/*  f10fbac:	24040018 */ 	li	$a0,0x18
/*  f10fbb0:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fbb4:	02002825 */ 	move	$a1,$s0
/*  f10fbb8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fbbc:	0fc54fee */ 	jal	0xf153fb8
/*  f10fbc0:	00402825 */ 	move	$a1,$v0
/*  f10fbc4:	2404001b */ 	li	$a0,0x1b
/*  f10fbc8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fbcc:	02002825 */ 	move	$a1,$s0
/*  f10fbd0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fbd4:	0fc5501a */ 	jal	0xf154068
/*  f10fbd8:	00402825 */ 	move	$a1,$v0
/*  f10fbdc:	24040021 */ 	li	$a0,0x21
/*  f10fbe0:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fbe4:	02002825 */ 	move	$a1,$s0
/*  f10fbe8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fbec:	0fc55004 */ 	jal	0xf154010
/*  f10fbf0:	00402825 */ 	move	$a1,$v0
/*  f10fbf4:	2404000b */ 	li	$a0,0xb
/*  f10fbf8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fbfc:	02002825 */ 	move	$a1,$s0
/*  f10fc00:	0fc55030 */ 	jal	0xf1540c0
/*  f10fc04:	00402025 */ 	move	$a0,$v0
/*  f10fc08:	24040014 */ 	li	$a0,0x14
/*  f10fc0c:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fc10:	02002825 */ 	move	$a1,$s0
/*  f10fc14:	0fc55033 */ 	jal	0xf1540cc
/*  f10fc18:	00402025 */ 	move	$a0,$v0
/*  f10fc1c:	24040021 */ 	li	$a0,0x21
/*  f10fc20:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fc24:	02002825 */ 	move	$a1,$s0
/*  f10fc28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10fc2c:	0fc55004 */ 	jal	0xf154010
/*  f10fc30:	00402825 */ 	move	$a1,$v0
/*  f10fc34:	24040040 */ 	li	$a0,0x40
/*  f10fc38:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fc3c:	02002825 */ 	move	$a1,$s0
/*  f10fc40:	3c01800a */ 	lui	$at,0x800a
/*  f10fc44:	a022e9b3 */ 	sb	$v0,-0x164d($at)
/*  f10fc48:	24040022 */ 	li	$a0,0x22
/*  f10fc4c:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fc50:	02002825 */ 	move	$a1,$s0
/*  f10fc54:	1040000d */ 	beqz	$v0,.PB0f10fc8c
/*  f10fc58:	3c098009 */ 	lui	$t1,0x8009
/*  f10fc5c:	91292fd0 */ 	lbu	$t1,0x2fd0($t1)
/*  f10fc60:	24010001 */ 	li	$at,0x1
/*  f10fc64:	15210005 */ 	bne	$t1,$at,.PB0f10fc7c
/*  f10fc68:	00000000 */ 	nop
/*  f10fc6c:	0fc2f22b */ 	jal	0xf0bc8ac
/*  f10fc70:	00002025 */ 	move	$a0,$zero
/*  f10fc74:	10000007 */ 	b	.PB0f10fc94
/*  f10fc78:	00000000 */ 	nop
.PB0f10fc7c:
/*  f10fc7c:	0fc2f22b */ 	jal	0xf0bc8ac
/*  f10fc80:	24040001 */ 	li	$a0,0x1
/*  f10fc84:	10000003 */ 	b	.PB0f10fc94
/*  f10fc88:	00000000 */ 	nop
.PB0f10fc8c:
/*  f10fc8c:	0fc2f22b */ 	jal	0xf0bc8ac
/*  f10fc90:	00002025 */ 	move	$a0,$zero
.PB0f10fc94:
/*  f10fc94:	3c0a8009 */ 	lui	$t2,0x8009
/*  f10fc98:	914a2fd0 */ 	lbu	$t2,0x2fd0($t2)
/*  f10fc9c:	24010001 */ 	li	$at,0x1
/*  f10fca0:	55410008 */ 	bnel	$t2,$at,.PB0f10fcc4
/*  f10fca4:	24040019 */ 	li	$a0,0x19
/*  f10fca8:	0fc550bc */ 	jal	0xf1542f0
/*  f10fcac:	00002025 */ 	move	$a0,$zero
/*  f10fcb0:	0fc550b6 */ 	jal	0xf1542d8
/*  f10fcb4:	00002025 */ 	move	$a0,$zero
/*  f10fcb8:	1000000c */ 	b	.PB0f10fcec
/*  f10fcbc:	24040008 */ 	li	$a0,0x8
/*  f10fcc0:	24040019 */ 	li	$a0,0x19
.PB0f10fcc4:
/*  f10fcc4:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fcc8:	02002825 */ 	move	$a1,$s0
/*  f10fccc:	0fc550bc */ 	jal	0xf1542f0
/*  f10fcd0:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10fcd4:	24040007 */ 	li	$a0,0x7
/*  f10fcd8:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fcdc:	02002825 */ 	move	$a1,$s0
/*  f10fce0:	0fc550b6 */ 	jal	0xf1542d8
/*  f10fce4:	00402025 */ 	move	$a0,$v0
/*  f10fce8:	24040008 */ 	li	$a0,0x8
.PB0f10fcec:
/*  f10fcec:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fcf0:	02002825 */ 	move	$a1,$s0
/*  f10fcf4:	50400006 */ 	beqzl	$v0,.PB0f10fd10
/*  f10fcf8:	24040006 */ 	li	$a0,0x6
/*  f10fcfc:	0fc550b0 */ 	jal	0xf1542c0
/*  f10fd00:	24040002 */ 	li	$a0,0x2
/*  f10fd04:	1000000d */ 	b	.PB0f10fd3c
/*  f10fd08:	2404001f */ 	li	$a0,0x1f
/*  f10fd0c:	24040006 */ 	li	$a0,0x6
.PB0f10fd10:
/*  f10fd10:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fd14:	02002825 */ 	move	$a1,$s0
/*  f10fd18:	10400005 */ 	beqz	$v0,.PB0f10fd30
/*  f10fd1c:	00000000 */ 	nop
/*  f10fd20:	0fc550b0 */ 	jal	0xf1542c0
/*  f10fd24:	24040001 */ 	li	$a0,0x1
/*  f10fd28:	10000004 */ 	b	.PB0f10fd3c
/*  f10fd2c:	2404001f */ 	li	$a0,0x1f
.PB0f10fd30:
/*  f10fd30:	0fc550b0 */ 	jal	0xf1542c0
/*  f10fd34:	00002025 */ 	move	$a0,$zero
/*  f10fd38:	2404001f */ 	li	$a0,0x1f
.PB0f10fd3c:
/*  f10fd3c:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fd40:	02002825 */ 	move	$a1,$s0
/*  f10fd44:	10400005 */ 	beqz	$v0,.PB0f10fd5c
/*  f10fd48:	2404001c */ 	li	$a0,0x1c
/*  f10fd4c:	240b0001 */ 	li	$t3,0x1
/*  f10fd50:	3c01800a */ 	lui	$at,0x800a
/*  f10fd54:	10000003 */ 	b	.PB0f10fd64
/*  f10fd58:	ac2be920 */ 	sw	$t3,-0x16e0($at)
.PB0f10fd5c:
/*  f10fd5c:	3c01800a */ 	lui	$at,0x800a
/*  f10fd60:	ac20e920 */ 	sw	$zero,-0x16e0($at)
.PB0f10fd64:
/*  f10fd64:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fd68:	02002825 */ 	move	$a1,$s0
/*  f10fd6c:	10400005 */ 	beqz	$v0,.PB0f10fd84
/*  f10fd70:	2404001d */ 	li	$a0,0x1d
/*  f10fd74:	240c0001 */ 	li	$t4,0x1
/*  f10fd78:	3c01800a */ 	lui	$at,0x800a
/*  f10fd7c:	10000003 */ 	b	.PB0f10fd8c
/*  f10fd80:	ac2ce918 */ 	sw	$t4,-0x16e8($at)
.PB0f10fd84:
/*  f10fd84:	3c01800a */ 	lui	$at,0x800a
/*  f10fd88:	ac20e918 */ 	sw	$zero,-0x16e8($at)
.PB0f10fd8c:
/*  f10fd8c:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fd90:	02002825 */ 	move	$a1,$s0
/*  f10fd94:	10400005 */ 	beqz	$v0,.PB0f10fdac
/*  f10fd98:	2404001e */ 	li	$a0,0x1e
/*  f10fd9c:	240d0001 */ 	li	$t5,0x1
/*  f10fda0:	3c01800a */ 	lui	$at,0x800a
/*  f10fda4:	10000003 */ 	b	.PB0f10fdb4
/*  f10fda8:	ac2de924 */ 	sw	$t5,-0x16dc($at)
.PB0f10fdac:
/*  f10fdac:	3c01800a */ 	lui	$at,0x800a
/*  f10fdb0:	ac20e924 */ 	sw	$zero,-0x16dc($at)
.PB0f10fdb4:
/*  f10fdb4:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fdb8:	02002825 */ 	move	$a1,$s0
/*  f10fdbc:	10400005 */ 	beqz	$v0,.PB0f10fdd4
/*  f10fdc0:	24040044 */ 	li	$a0,0x44
/*  f10fdc4:	240e0001 */ 	li	$t6,0x1
/*  f10fdc8:	3c01800a */ 	lui	$at,0x800a
/*  f10fdcc:	10000003 */ 	b	.PB0f10fddc
/*  f10fdd0:	ac2ee91c */ 	sw	$t6,-0x16e4($at)
.PB0f10fdd4:
/*  f10fdd4:	3c01800a */ 	lui	$at,0x800a
/*  f10fdd8:	ac20e91c */ 	sw	$zero,-0x16e4($at)
.PB0f10fddc:
/*  f10fddc:	3c01800a */ 	lui	$at,0x800a
/*  f10fde0:	a420e952 */ 	sh	$zero,-0x16ae($at)
/*  f10fde4:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fde8:	02002825 */ 	move	$a1,$s0
/*  f10fdec:	10400006 */ 	beqz	$v0,.PB0f10fe08
/*  f10fdf0:	24040045 */ 	li	$a0,0x45
/*  f10fdf4:	3c0f800a */ 	lui	$t7,0x800a
/*  f10fdf8:	95efe952 */ 	lhu	$t7,-0x16ae($t7)
/*  f10fdfc:	3c01800a */ 	lui	$at,0x800a
/*  f10fe00:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f10fe04:	a438e952 */ 	sh	$t8,-0x16ae($at)
.PB0f10fe08:
/*  f10fe08:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fe0c:	02002825 */ 	move	$a1,$s0
/*  f10fe10:	10400006 */ 	beqz	$v0,.PB0f10fe2c
/*  f10fe14:	24040046 */ 	li	$a0,0x46
/*  f10fe18:	3c19800a */ 	lui	$t9,0x800a
/*  f10fe1c:	9739e952 */ 	lhu	$t9,-0x16ae($t9)
/*  f10fe20:	3c01800a */ 	lui	$at,0x800a
/*  f10fe24:	37280002 */ 	ori	$t0,$t9,0x2
/*  f10fe28:	a428e952 */ 	sh	$t0,-0x16ae($at)
.PB0f10fe2c:
/*  f10fe2c:	0fc47b90 */ 	jal	0xf11ee40
/*  f10fe30:	02002825 */ 	move	$a1,$s0
/*  f10fe34:	10400006 */ 	beqz	$v0,.PB0f10fe50
/*  f10fe38:	3c04800a */ 	lui	$a0,0x800a
/*  f10fe3c:	3c09800a */ 	lui	$t1,0x800a
/*  f10fe40:	9529e952 */ 	lhu	$t1,-0x16ae($t1)
/*  f10fe44:	3c01800a */ 	lui	$at,0x800a
/*  f10fe48:	352a0004 */ 	ori	$t2,$t1,0x4
/*  f10fe4c:	a42ae952 */ 	sh	$t2,-0x16ae($at)
.PB0f10fe50:
/*  f10fe50:	0fc5c097 */ 	jal	0xf17025c
/*  f10fe54:	9484e952 */ 	lhu	$a0,-0x16ae($a0)
/*  f10fe58:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10fe5c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10fe60:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10fe64:	03e00008 */ 	jr	$ra
/*  f10fe68:	00000000 */ 	nop
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
			playerSetHiResEnabled(false);
		} else {
			playerSetHiResEnabled(true);
		}
	} else {
		playerSetHiResEnabled(false);
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
#elif VERSION >= VERSION_PAL_BETA
const char var7f1b4bd0pf[] = "Dark";

GLOBAL_ASM(
glabel gamefileLoadDefaults
/*  f10fe6c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10fe70:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10fe74:	3c12800a */ 	lui	$s2,0x800a
/*  f10fe78:	2652e4d0 */ 	addiu	$s2,$s2,-6960
/*  f10fe7c:	8e420298 */ 	lw	$v0,0x298($s2)
/*  f10fe80:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f10fe84:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10fe88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10fe8c:	04410005 */ 	bgez	$v0,.PB0f10fea4
/*  f10fe90:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f10fe94:	8e4e029c */ 	lw	$t6,0x29c($s2)
/*  f10fe98:	24110004 */ 	li	$s1,0x4
/*  f10fe9c:	05c00003 */ 	bltz	$t6,.PB0f10feac
/*  f10fea0:	00000000 */ 	nop
.PB0f10fea4:
/*  f10fea4:	10000001 */ 	b	.PB0f10feac
/*  f10fea8:	00008825 */ 	move	$s1,$zero
.PB0f10feac:
/*  f10feac:	04410005 */ 	bgez	$v0,.PB0f10fec4
/*  f10feb0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f10feb4:	8e4f029c */ 	lw	$t7,0x29c($s2)
/*  f10feb8:	24100005 */ 	li	$s0,0x5
/*  f10febc:	05e00003 */ 	bltz	$t7,.PB0f10fecc
/*  f10fec0:	00000000 */ 	nop
.PB0f10fec4:
/*  f10fec4:	10000001 */ 	b	.PB0f10fecc
/*  f10fec8:	24100001 */ 	li	$s0,0x1
.PB0f10fecc:
/*  f10fecc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f10fed0:	0c004cbc */ 	jal	0x132f0
/*  f10fed4:	24a55620 */ 	addiu	$a1,$a1,0x5620
/*  f10fed8:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f10fedc:	24045000 */ 	li	$a0,0x5000
/*  f10fee0:	9058000b */ 	lbu	$t8,0xb($v0)
/*  f10fee4:	a040000c */ 	sb	$zero,0xc($v0)
/*  f10fee8:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f10feec:	3308ff07 */ 	andi	$t0,$t8,0xff07
/*  f10fef0:	310900f8 */ 	andi	$t1,$t0,0xf8
/*  f10fef4:	a048000b */ 	sb	$t0,0xb($v0)
/*  f10fef8:	0c003a93 */ 	jal	0xea4c
/*  f10fefc:	a049000b */ 	sb	$t1,0xb($v0)
/*  f10ff00:	0fc550c8 */ 	jal	0xf154320
/*  f10ff04:	24045000 */ 	li	$a0,0x5000
/*  f10ff08:	0c003cef */ 	jal	0xf3bc
/*  f10ff0c:	24040001 */ 	li	$a0,0x1
/*  f10ff10:	02202025 */ 	move	$a0,$s1
/*  f10ff14:	0fc54eb7 */ 	jal	0xf153adc
/*  f10ff18:	00002825 */ 	move	$a1,$zero
/*  f10ff1c:	02002025 */ 	move	$a0,$s0
/*  f10ff20:	0fc54eb7 */ 	jal	0xf153adc
/*  f10ff24:	00002825 */ 	move	$a1,$zero
/*  f10ff28:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f10ff2c:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f10ff30:	0fc47b9e */ 	jal	0xf11ee78
/*  f10ff34:	02002025 */ 	move	$a0,$s0
/*  f10ff38:	00002025 */ 	move	$a0,$zero
/*  f10ff3c:	02002825 */ 	move	$a1,$s0
/*  f10ff40:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff44:	00003025 */ 	move	$a2,$zero
/*  f10ff48:	24040001 */ 	li	$a0,0x1
/*  f10ff4c:	02002825 */ 	move	$a1,$s0
/*  f10ff50:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff54:	24060001 */ 	li	$a2,0x1
/*  f10ff58:	24040002 */ 	li	$a0,0x2
/*  f10ff5c:	02002825 */ 	move	$a1,$s0
/*  f10ff60:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff64:	00003025 */ 	move	$a2,$zero
/*  f10ff68:	24040003 */ 	li	$a0,0x3
/*  f10ff6c:	02002825 */ 	move	$a1,$s0
/*  f10ff70:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff74:	24060001 */ 	li	$a2,0x1
/*  f10ff78:	24040004 */ 	li	$a0,0x4
/*  f10ff7c:	02002825 */ 	move	$a1,$s0
/*  f10ff80:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff84:	24060001 */ 	li	$a2,0x1
/*  f10ff88:	24040005 */ 	li	$a0,0x5
/*  f10ff8c:	02002825 */ 	move	$a1,$s0
/*  f10ff90:	0fc47b7b */ 	jal	0xf11edec
/*  f10ff94:	24060001 */ 	li	$a2,0x1
/*  f10ff98:	24040009 */ 	li	$a0,0x9
/*  f10ff9c:	02002825 */ 	move	$a1,$s0
/*  f10ffa0:	0fc47b7b */ 	jal	0xf11edec
/*  f10ffa4:	24060001 */ 	li	$a2,0x1
/*  f10ffa8:	2404000a */ 	li	$a0,0xa
/*  f10ffac:	02002825 */ 	move	$a1,$s0
/*  f10ffb0:	0fc47b7b */ 	jal	0xf11edec
/*  f10ffb4:	24060001 */ 	li	$a2,0x1
/*  f10ffb8:	2404000b */ 	li	$a0,0xb
/*  f10ffbc:	02002825 */ 	move	$a1,$s0
/*  f10ffc0:	0fc47b7b */ 	jal	0xf11edec
/*  f10ffc4:	24060001 */ 	li	$a2,0x1
/*  f10ffc8:	24040015 */ 	li	$a0,0x15
/*  f10ffcc:	02002825 */ 	move	$a1,$s0
/*  f10ffd0:	0fc47b7b */ 	jal	0xf11edec
/*  f10ffd4:	24060001 */ 	li	$a2,0x1
/*  f10ffd8:	24040017 */ 	li	$a0,0x17
/*  f10ffdc:	02002825 */ 	move	$a1,$s0
/*  f10ffe0:	0fc47b7b */ 	jal	0xf11edec
/*  f10ffe4:	24060001 */ 	li	$a2,0x1
/*  f10ffe8:	2404001a */ 	li	$a0,0x1a
/*  f10ffec:	02002825 */ 	move	$a1,$s0
/*  f10fff0:	0fc47b7b */ 	jal	0xf11edec
/*  f10fff4:	00003025 */ 	move	$a2,$zero
/*  f10fff8:	24040020 */ 	li	$a0,0x20
/*  f10fffc:	02002825 */ 	move	$a1,$s0
/*  f110000:	0fc47b7b */ 	jal	0xf11edec
/*  f110004:	00003025 */ 	move	$a2,$zero
/*  f110008:	2404000c */ 	li	$a0,0xc
/*  f11000c:	02002825 */ 	move	$a1,$s0
/*  f110010:	0fc47b7b */ 	jal	0xf11edec
/*  f110014:	00003025 */ 	move	$a2,$zero
/*  f110018:	2404000d */ 	li	$a0,0xd
/*  f11001c:	02002825 */ 	move	$a1,$s0
/*  f110020:	0fc47b7b */ 	jal	0xf11edec
/*  f110024:	24060001 */ 	li	$a2,0x1
/*  f110028:	2404000e */ 	li	$a0,0xe
/*  f11002c:	02002825 */ 	move	$a1,$s0
/*  f110030:	0fc47b7b */ 	jal	0xf11edec
/*  f110034:	00003025 */ 	move	$a2,$zero
/*  f110038:	2404000f */ 	li	$a0,0xf
/*  f11003c:	02002825 */ 	move	$a1,$s0
/*  f110040:	0fc47b7b */ 	jal	0xf11edec
/*  f110044:	24060001 */ 	li	$a2,0x1
/*  f110048:	24040010 */ 	li	$a0,0x10
/*  f11004c:	02002825 */ 	move	$a1,$s0
/*  f110050:	0fc47b7b */ 	jal	0xf11edec
/*  f110054:	24060001 */ 	li	$a2,0x1
/*  f110058:	24040011 */ 	li	$a0,0x11
/*  f11005c:	02002825 */ 	move	$a1,$s0
/*  f110060:	0fc47b7b */ 	jal	0xf11edec
/*  f110064:	24060001 */ 	li	$a2,0x1
/*  f110068:	24040012 */ 	li	$a0,0x12
/*  f11006c:	02002825 */ 	move	$a1,$s0
/*  f110070:	0fc47b7b */ 	jal	0xf11edec
/*  f110074:	24060001 */ 	li	$a2,0x1
/*  f110078:	24040013 */ 	li	$a0,0x13
/*  f11007c:	02002825 */ 	move	$a1,$s0
/*  f110080:	0fc47b7b */ 	jal	0xf11edec
/*  f110084:	24060001 */ 	li	$a2,0x1
/*  f110088:	24040014 */ 	li	$a0,0x14
/*  f11008c:	02002825 */ 	move	$a1,$s0
/*  f110090:	0fc47b7b */ 	jal	0xf11edec
/*  f110094:	00003025 */ 	move	$a2,$zero
/*  f110098:	24040016 */ 	li	$a0,0x16
/*  f11009c:	02002825 */ 	move	$a1,$s0
/*  f1100a0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100a4:	24060001 */ 	li	$a2,0x1
/*  f1100a8:	24040018 */ 	li	$a0,0x18
/*  f1100ac:	02002825 */ 	move	$a1,$s0
/*  f1100b0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100b4:	24060001 */ 	li	$a2,0x1
/*  f1100b8:	2404001b */ 	li	$a0,0x1b
/*  f1100bc:	02002825 */ 	move	$a1,$s0
/*  f1100c0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100c4:	00003025 */ 	move	$a2,$zero
/*  f1100c8:	24040021 */ 	li	$a0,0x21
/*  f1100cc:	02002825 */ 	move	$a1,$s0
/*  f1100d0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100d4:	00003025 */ 	move	$a2,$zero
/*  f1100d8:	24040019 */ 	li	$a0,0x19
/*  f1100dc:	02002825 */ 	move	$a1,$s0
/*  f1100e0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100e4:	00003025 */ 	move	$a2,$zero
/*  f1100e8:	24040007 */ 	li	$a0,0x7
/*  f1100ec:	02002825 */ 	move	$a1,$s0
/*  f1100f0:	0fc47b7b */ 	jal	0xf11edec
/*  f1100f4:	00003025 */ 	move	$a2,$zero
/*  f1100f8:	24040008 */ 	li	$a0,0x8
/*  f1100fc:	02002825 */ 	move	$a1,$s0
/*  f110100:	0fc47b7b */ 	jal	0xf11edec
/*  f110104:	00003025 */ 	move	$a2,$zero
/*  f110108:	24040006 */ 	li	$a0,0x6
/*  f11010c:	02002825 */ 	move	$a1,$s0
/*  f110110:	0fc47b7b */ 	jal	0xf11edec
/*  f110114:	00003025 */ 	move	$a2,$zero
/*  f110118:	24040022 */ 	li	$a0,0x22
/*  f11011c:	02002825 */ 	move	$a1,$s0
/*  f110120:	0fc47b7b */ 	jal	0xf11edec
/*  f110124:	00003025 */ 	move	$a2,$zero
/*  f110128:	24040040 */ 	li	$a0,0x40
/*  f11012c:	02002825 */ 	move	$a1,$s0
/*  f110130:	0fc47b7b */ 	jal	0xf11edec
/*  f110134:	00003025 */ 	move	$a2,$zero
/*  f110138:	24040041 */ 	li	$a0,0x41
/*  f11013c:	02002825 */ 	move	$a1,$s0
/*  f110140:	0fc47b7b */ 	jal	0xf11edec
/*  f110144:	00003025 */ 	move	$a2,$zero
/*  f110148:	24040042 */ 	li	$a0,0x42
/*  f11014c:	02002825 */ 	move	$a1,$s0
/*  f110150:	0fc47b7b */ 	jal	0xf11edec
/*  f110154:	00003025 */ 	move	$a2,$zero
/*  f110158:	24040043 */ 	li	$a0,0x43
/*  f11015c:	02002825 */ 	move	$a1,$s0
/*  f110160:	0fc47b7b */ 	jal	0xf11edec
/*  f110164:	00003025 */ 	move	$a2,$zero
/*  f110168:	2404001c */ 	li	$a0,0x1c
/*  f11016c:	02002825 */ 	move	$a1,$s0
/*  f110170:	0fc47b7b */ 	jal	0xf11edec
/*  f110174:	24060001 */ 	li	$a2,0x1
/*  f110178:	2404001d */ 	li	$a0,0x1d
/*  f11017c:	02002825 */ 	move	$a1,$s0
/*  f110180:	0fc47b7b */ 	jal	0xf11edec
/*  f110184:	24060001 */ 	li	$a2,0x1
/*  f110188:	2404001e */ 	li	$a0,0x1e
/*  f11018c:	02002825 */ 	move	$a1,$s0
/*  f110190:	0fc47b7b */ 	jal	0xf11edec
/*  f110194:	24060001 */ 	li	$a2,0x1
/*  f110198:	2404001f */ 	li	$a0,0x1f
/*  f11019c:	02002825 */ 	move	$a1,$s0
/*  f1101a0:	0fc47b7b */ 	jal	0xf11edec
/*  f1101a4:	24060001 */ 	li	$a2,0x1
/*  f1101a8:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f1101ac:	3c10800a */ 	lui	$s0,0x800a
/*  f1101b0:	26106744 */ 	addiu	$s0,$s0,0x6744
/*  f1101b4:	30ca0001 */ 	andi	$t2,$a2,0x1
/*  f1101b8:	394b0001 */ 	xori	$t3,$t2,0x1
/*  f1101bc:	2d660001 */ 	sltiu	$a2,$t3,0x1
/*  f1101c0:	02002825 */ 	move	$a1,$s0
/*  f1101c4:	0fc47b7b */ 	jal	0xf11edec
/*  f1101c8:	24040044 */ 	li	$a0,0x44
/*  f1101cc:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f1101d0:	24040045 */ 	li	$a0,0x45
/*  f1101d4:	02002825 */ 	move	$a1,$s0
/*  f1101d8:	30cc0002 */ 	andi	$t4,$a2,0x2
/*  f1101dc:	398d0002 */ 	xori	$t5,$t4,0x2
/*  f1101e0:	0fc47b7b */ 	jal	0xf11edec
/*  f1101e4:	2da60001 */ 	sltiu	$a2,$t5,0x1
/*  f1101e8:	96460482 */ 	lhu	$a2,0x482($s2)
/*  f1101ec:	24040046 */ 	li	$a0,0x46
/*  f1101f0:	02002825 */ 	move	$a1,$s0
/*  f1101f4:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f1101f8:	39cf0004 */ 	xori	$t7,$t6,0x4
/*  f1101fc:	0fc47b7b */ 	jal	0xf11edec
/*  f110200:	2de60001 */ 	sltiu	$a2,$t7,0x1
/*  f110204:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f110208:	00009025 */ 	move	$s2,$zero
/*  f11020c:	24030003 */ 	li	$v1,0x3
/*  f110210:	a480001e */ 	sh	$zero,0x1e($a0)
.PB0f110214:
/*  f110214:	00008025 */ 	move	$s0,$zero
/*  f110218:	00801025 */ 	move	$v0,$a0
.PB0f11021c:
/*  f11021c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110220:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f110224:	1603fffd */ 	bne	$s0,$v1,.PB0f11021c
/*  f110228:	a440001e */ 	sh	$zero,0x1e($v0)
/*  f11022c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f110230:	2a410015 */ 	slti	$at,$s2,0x15
/*  f110234:	1420fff7 */ 	bnez	$at,.PB0f110214
/*  f110238:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f11023c:	00009025 */ 	move	$s2,$zero
/*  f110240:	24110005 */ 	li	$s1,0x5
/*  f110244:	24100001 */ 	li	$s0,0x1
.PB0f110248:
/*  f110248:	02402025 */ 	move	$a0,$s2
.PB0f11024c:
/*  f11024c:	02002825 */ 	move	$a1,$s0
/*  f110250:	0fc67829 */ 	jal	0xf19e0a4
/*  f110254:	00003025 */ 	move	$a2,$zero
/*  f110258:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11025c:	5611fffb */ 	bnel	$s0,$s1,.PB0f11024c
/*  f110260:	02402025 */ 	move	$a0,$s2
/*  f110264:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f110268:	2a41001e */ 	slti	$at,$s2,0x1e
/*  f11026c:	5420fff6 */ 	bnezl	$at,.PB0f110248
/*  f110270:	24100001 */ 	li	$s0,0x1
/*  f110274:	0fc67317 */ 	jal	0xf19cc5c
/*  f110278:	00000000 */ 	nop
/*  f11027c:	3c02800a */ 	lui	$v0,0x800a
/*  f110280:	3c03800a */ 	lui	$v1,0x800a
/*  f110284:	2463673c */ 	addiu	$v1,$v1,0x673c
/*  f110288:	24426730 */ 	addiu	$v0,$v0,0x6730
.PB0f11028c:
/*  f11028c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f110290:	0043082b */ 	sltu	$at,$v0,$v1
/*  f110294:	1420fffd */ 	bnez	$at,.PB0f11028c
/*  f110298:	ac40009c */ 	sw	$zero,0x9c($v0)
/*  f11029c:	3c02800a */ 	lui	$v0,0x800a
/*  f1102a0:	3c03800a */ 	lui	$v1,0x800a
/*  f1102a4:	24636739 */ 	addiu	$v1,$v1,0x6739
/*  f1102a8:	24426730 */ 	addiu	$v0,$v0,0x6730
.PB0f1102ac:
/*  f1102ac:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1102b0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1102b4:	1420fffd */ 	bnez	$at,.PB0f1102ac
/*  f1102b8:	a04000ab */ 	sb	$zero,0xab($v0)
/*  f1102bc:	3c02800a */ 	lui	$v0,0x800a
/*  f1102c0:	3c03800a */ 	lui	$v1,0x800a
/*  f1102c4:	24636736 */ 	addiu	$v1,$v1,0x6736
/*  f1102c8:	24426730 */ 	addiu	$v0,$v0,0x6730
.PB0f1102cc:
/*  f1102cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1102d0:	1443fffe */ 	bne	$v0,$v1,.PB0f1102cc
/*  f1102d4:	a04000b4 */ 	sb	$zero,0xb4($v0)
/*  f1102d8:	0fc43e55 */ 	jal	0xf10f954
/*  f1102dc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1102e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1102e4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1102e8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1102ec:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1102f0:	03e00008 */ 	jr	$ra
/*  f1102f4:	27bd0028 */ 	addiu	$sp,$sp,0x28
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
#if VERSION >= VERSION_NTSC_1_0
	sndSetSfxVolume(0x5000);
	optionsSetMusicVolume(0x5000);
#else
	sndSetSfxVolume(0x7f80);
	optionsSetMusicVolume(0x7f80);
#endif
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

#if VERSION >= VERSION_NTSC_1_0
	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound); i++)
#else
	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound) - 2; i++)
#endif
	{
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

#if VERSION >= VERSION_NTSC_1_0
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

	pakSetBitflag(GAMEFILEFLAG_HIRES, g_GameFile.flags, g_ViRes == VIRES_HI);
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
#else
GLOBAL_ASM(
glabel gamefileSave
/*  f10a380:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f10a384:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f10a388:	3c14800a */ 	lui	$s4,0x800a
/*  f10a38c:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f10a390:	8e820298 */ 	lw	$v0,0x298($s4)
/*  f10a394:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f10a398:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f10a39c:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f10a3a0:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f10a3a4:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f10a3a8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10a3ac:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f10a3b0:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f10a3b4:	04410005 */ 	bgez	$v0,.NB0f10a3cc
/*  f10a3b8:	afa60150 */ 	sw	$a2,0x150($sp)
/*  f10a3bc:	8e8e029c */ 	lw	$t6,0x29c($s4)
/*  f10a3c0:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f10a3c4:	05c00003 */ 	bltz	$t6,.NB0f10a3d4
/*  f10a3c8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f10a3cc:
/*  f10a3cc:	10000001 */ 	beqz	$zero,.NB0f10a3d4
/*  f10a3d0:	00008825 */ 	or	$s1,$zero,$zero
.NB0f10a3d4:
/*  f10a3d4:	04410005 */ 	bgez	$v0,.NB0f10a3ec
/*  f10a3d8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f10a3dc:	8e8f029c */ 	lw	$t7,0x29c($s4)
/*  f10a3e0:	24130005 */ 	addiu	$s3,$zero,0x5
/*  f10a3e4:	05e00003 */ 	bltz	$t7,.NB0f10a3f4
/*  f10a3e8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f10a3ec:
/*  f10a3ec:	10000001 */ 	beqz	$zero,.NB0f10a3f4
/*  f10a3f0:	24130001 */ 	addiu	$s3,$zero,0x1
.NB0f10a3f4:
/*  f10a3f4:	3c018007 */ 	lui	$at,0x8007
/*  f10a3f8:	ac327f70 */ 	sw	$s2,0x7f70($at)
/*  f10a3fc:	0fc5339c */ 	jal	optionsGetForwardPitch
/*  f10a400:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a404:	3c10800a */ 	lui	$s0,0x800a
/*  f10a408:	26106704 */ 	addiu	$s0,$s0,0x6704
/*  f10a40c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a410:	00002025 */ 	or	$a0,$zero,$zero
/*  f10a414:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a418:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a41c:	0fc533a5 */ 	jal	optionsGetAutoAim
/*  f10a420:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a424:	02402025 */ 	or	$a0,$s2,$zero
/*  f10a428:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a42c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a430:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a434:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f10a438:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a43c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10a440:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a444:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a448:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a44c:	0fc533c0 */ 	jal	optionsGetSightOnScreen
/*  f10a450:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a454:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10a458:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a45c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a460:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a464:	0fc533ae */ 	jal	optionsGetLookAhead
/*  f10a468:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a46c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10a470:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a474:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a478:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a47c:	0fc533c9 */ 	jal	optionsGetAmmoOnScreen
/*  f10a480:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a484:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10a488:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a48c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a490:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a494:	0fc53405 */ 	jal	optionsGetHeadRoll
/*  f10a498:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a49c:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f10a4a0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a4a4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a4a8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a4ac:	0fc533d2 */ 	jal	optionsGetShowGunFunction
/*  f10a4b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a4b4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f10a4b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a4bc:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a4c0:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a4c4:	0fc533db */ 	jal	optionsGetAlwaysShowTarget
/*  f10a4c8:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a4cc:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f10a4d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a4d4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a4d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a4dc:	0fc533e4 */ 	jal	optionsGetShowZoomRange
/*  f10a4e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a4e4:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f10a4e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a4ec:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a4f0:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a4f4:	0fc533f6 */ 	jal	optionsGetShowMissionTime
/*  f10a4f8:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a4fc:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f10a500:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a504:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a508:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a50c:	0fc533ed */ 	jal	optionsGetPaintball
/*  f10a510:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a514:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f10a518:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a51c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a520:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a524:	0fc5339c */ 	jal	optionsGetForwardPitch
/*  f10a528:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a52c:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f10a530:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a534:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a538:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a53c:	0fc533a5 */ 	jal	optionsGetAutoAim
/*  f10a540:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a544:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f10a548:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a54c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a550:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a554:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f10a558:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a55c:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f10a560:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a564:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a568:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a56c:	0fc533c0 */ 	jal	optionsGetSightOnScreen
/*  f10a570:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a574:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f10a578:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a57c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a580:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a584:	0fc533ae */ 	jal	optionsGetLookAhead
/*  f10a588:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a58c:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f10a590:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a594:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a598:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a59c:	0fc533c9 */ 	jal	optionsGetAmmoOnScreen
/*  f10a5a0:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a5a4:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f10a5a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a5ac:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a5b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a5b4:	0fc53405 */ 	jal	optionsGetHeadRoll
/*  f10a5b8:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a5bc:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f10a5c0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a5c4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a5c8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a5cc:	0fc533d2 */ 	jal	optionsGetShowGunFunction
/*  f10a5d0:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a5d4:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f10a5d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a5dc:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a5e0:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a5e4:	0fc533db */ 	jal	optionsGetAlwaysShowTarget
/*  f10a5e8:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a5ec:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f10a5f0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a5f4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a5f8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a5fc:	0fc533e4 */ 	jal	optionsGetShowZoomRange
/*  f10a600:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a604:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f10a608:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a60c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a610:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a614:	0fc533f6 */ 	jal	optionsGetShowMissionTime
/*  f10a618:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a61c:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f10a620:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a624:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a628:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a62c:	0fc533ed */ 	jal	optionsGetPaintball
/*  f10a630:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a634:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10a638:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a63c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a640:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a644:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f10a648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a64c:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f10a650:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a654:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a658:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a65c:	0fc53582 */ 	jal	optionsGetScreenRatio
/*  f10a660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a664:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f10a668:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a66c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a670:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a674:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f10a678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a67c:	00523026 */ 	xor	$a2,$v0,$s2
/*  f10a680:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a684:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10a688:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a68c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a690:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f10a694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a698:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f10a69c:	00553026 */ 	xor	$a2,$v0,$s5
/*  f10a6a0:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a6a4:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f10a6a8:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a6ac:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a6b0:	3c188007 */ 	lui	$t8,0x8007
/*  f10a6b4:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f10a6b8:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f10a6bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a6c0:	02583026 */ 	xor	$a2,$s2,$t8
/*  f10a6c4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a6c8:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a6cc:	0fc533ff */ 	jal	optionsGetInGameSubtitles
/*  f10a6d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a6d4:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f10a6d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a6dc:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a6e0:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a6e4:	0fc53402 */ 	jal	optionsGetCutsceneSubtitles
/*  f10a6e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a6ec:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f10a6f0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a6f4:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a6f8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10a6fc:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f10a700:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a704:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a708:	928604e3 */ 	lbu	$a2,0x4e3($s4)
/*  f10a70c:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f10a710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a714:	50400002 */ 	beqzl	$v0,.NB0f10a720
/*  f10a718:	8e990450 */ 	lw	$t9,0x450($s4)
/*  f10a71c:	8e990450 */ 	lw	$t9,0x450($s4)
.NB0f10a720:
/*  f10a720:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f10a724:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a728:	02593026 */ 	xor	$a2,$s2,$t9
/*  f10a72c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a730:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a734:	8e880448 */ 	lw	$t0,0x448($s4)
/*  f10a738:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f10a73c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a740:	02483026 */ 	xor	$a2,$s2,$t0
/*  f10a744:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a748:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a74c:	8e890454 */ 	lw	$t1,0x454($s4)
/*  f10a750:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f10a754:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a758:	02493026 */ 	xor	$a2,$s2,$t1
/*  f10a75c:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a760:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a764:	8e8a044c */ 	lw	$t2,0x44c($s4)
/*  f10a768:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f10a76c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a770:	024a3026 */ 	xor	$a2,$s2,$t2
/*  f10a774:	0fc460eb */ 	jal	pakSetBitflag
/*  f10a778:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f10a77c:	8fab0148 */ 	lw	$t3,0x148($sp)
/*  f10a780:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f10a784:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10a788:	056000ae */ 	bltz	$t3,.NB0f10aa44
/*  f10a78c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a790:	0fc34ad1 */ 	jal	savebufferClear
/*  f10a794:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a798:	3c12800a */ 	lui	$s2,0x800a
/*  f10a79c:	265266f0 */ 	addiu	$s2,$s2,0x66f0
/*  f10a7a0:	02402825 */ 	or	$a1,$s2,$zero
/*  f10a7a4:	0fc34b23 */ 	jal	func0f0d55a4
/*  f10a7a8:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a7ac:	9245000b */ 	lbu	$a1,0xb($s2)
/*  f10a7b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a7b4:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f10a7b8:	000560c2 */ 	srl	$t4,$a1,0x3
/*  f10a7bc:	0fc34a9e */ 	jal	savebufferOr
/*  f10a7c0:	01802825 */ 	or	$a1,$t4,$zero
/*  f10a7c4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a7c8:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f10a7cc:	0fc34a9e */ 	jal	savebufferOr
/*  f10a7d0:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f10a7d4:	8e450008 */ 	lw	$a1,0x8($s2)
/*  f10a7d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a7dc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f10a7e0:	30ad0007 */ 	andi	$t5,$a1,0x7
/*  f10a7e4:	0fc34a9e */ 	jal	savebufferOr
/*  f10a7e8:	01a02825 */ 	or	$a1,$t5,$zero
/*  f10a7ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a7f0:	9245000c */ 	lbu	$a1,0xc($s2)
/*  f10a7f4:	0fc34a9e */ 	jal	savebufferOr
/*  f10a7f8:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f10a7fc:	3c078006 */ 	lui	$a3,0x8006
/*  f10a800:	94e7f6e8 */ 	lhu	$a3,-0x918($a3)
/*  f10a804:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a808:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f10a80c:	000771c3 */ 	sra	$t6,$a3,0x7
/*  f10a810:	0fc34a9e */ 	jal	savebufferOr
/*  f10a814:	000e2882 */ 	srl	$a1,$t6,0x2
/*  f10a818:	0fc5358f */ 	jal	optionsGetMusicVolume
/*  f10a81c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a820:	000229c3 */ 	sra	$a1,$v0,0x7
/*  f10a824:	00057882 */ 	srl	$t7,$a1,0x2
/*  f10a828:	01e02825 */ 	or	$a1,$t7,$zero
/*  f10a82c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a830:	0fc34a9e */ 	jal	savebufferOr
/*  f10a834:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f10a838:	3c078006 */ 	lui	$a3,0x8006
/*  f10a83c:	8ce5f6ec */ 	lw	$a1,-0x914($a3)
/*  f10a840:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a844:	0fc34a9e */ 	jal	savebufferOr
/*  f10a848:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f10a84c:	0fc53380 */ 	jal	optionsGetControlMode
/*  f10a850:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a854:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a858:	00402825 */ 	or	$a1,$v0,$zero
/*  f10a85c:	0fc34a9e */ 	jal	savebufferOr
/*  f10a860:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f10a864:	0fc53380 */ 	jal	optionsGetControlMode
/*  f10a868:	02602025 */ 	or	$a0,$s3,$zero
/*  f10a86c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a870:	00402825 */ 	or	$a1,$v0,$zero
/*  f10a874:	0fc34a9e */ 	jal	savebufferOr
/*  f10a878:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f10a87c:	3c10800a */ 	lui	$s0,0x800a
/*  f10a880:	3c11800a */ 	lui	$s1,0x800a
/*  f10a884:	263166fa */ 	addiu	$s1,$s1,0x66fa
/*  f10a888:	261066f0 */ 	addiu	$s0,$s0,0x66f0
/*  f10a88c:	02802025 */ 	or	$a0,$s4,$zero
.NB0f10a890:
/*  f10a890:	92050014 */ 	lbu	$a1,0x14($s0)
/*  f10a894:	0fc34a9e */ 	jal	savebufferOr
/*  f10a898:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f10a89c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10a8a0:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10a8a4:	5420fffa */ 	bnezl	$at,.NB0f10a890
/*  f10a8a8:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a8ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a8b0:	9645001e */ 	lhu	$a1,0x1e($s2)
/*  f10a8b4:	0fc34a9e */ 	jal	savebufferOr
/*  f10a8b8:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f10a8bc:	3c15800a */ 	lui	$s5,0x800a
/*  f10a8c0:	26b566f0 */ 	addiu	$s5,$s5,0x66f0
/*  f10a8c4:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f10a8c8:	00008825 */ 	or	$s1,$zero,$zero
.NB0f10a8cc:
/*  f10a8cc:	02a09025 */ 	or	$s2,$s5,$zero
.NB0f10a8d0:
/*  f10a8d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a8d4:	96450020 */ 	lhu	$a1,0x20($s2)
/*  f10a8d8:	0fc34a9e */ 	jal	savebufferOr
/*  f10a8dc:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f10a8e0:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f10a8e4:	1633fffa */ 	bne	$s1,$s3,.NB0f10a8d0
/*  f10a8e8:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f10a8ec:	3c18800a */ 	lui	$t8,0x800a
/*  f10a8f0:	2718676e */ 	addiu	$t8,$t8,0x676e
/*  f10a8f4:	26b50006 */ 	addiu	$s5,$s5,0x6
/*  f10a8f8:	02b8082b */ 	sltu	$at,$s5,$t8
/*  f10a8fc:	5420fff3 */ 	bnezl	$at,.NB0f10a8cc
/*  f10a900:	00008825 */ 	or	$s1,$zero,$zero
/*  f10a904:	00008825 */ 	or	$s1,$zero,$zero
/*  f10a908:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f10a90c:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f10a910:
/*  f10a910:	02202025 */ 	or	$a0,$s1,$zero
.NB0f10a914:
/*  f10a914:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f10a918:	02002825 */ 	or	$a1,$s0,$zero
/*  f10a91c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a920:	00402825 */ 	or	$a1,$v0,$zero
/*  f10a924:	0fc34a9e */ 	jal	savebufferOr
/*  f10a928:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10a92c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10a930:	5612fff8 */ 	bnel	$s0,$s2,.NB0f10a914
/*  f10a934:	02202025 */ 	or	$a0,$s1,$zero
/*  f10a938:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f10a93c:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f10a940:	5420fff3 */ 	bnezl	$at,.NB0f10a910
/*  f10a944:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f10a948:	3c10800a */ 	lui	$s0,0x800a
/*  f10a94c:	3c11800a */ 	lui	$s1,0x800a
/*  f10a950:	263166fc */ 	addiu	$s1,$s1,0x66fc
/*  f10a954:	261066f0 */ 	addiu	$s0,$s0,0x66f0
/*  f10a958:	02802025 */ 	or	$a0,$s4,$zero
.NB0f10a95c:
/*  f10a95c:	8e0500a0 */ 	lw	$a1,0xa0($s0)
/*  f10a960:	0fc34a9e */ 	jal	savebufferOr
/*  f10a964:	24060015 */ 	addiu	$a2,$zero,0x15
/*  f10a968:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10a96c:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10a970:	5420fffa */ 	bnezl	$at,.NB0f10a95c
/*  f10a974:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a978:	3c10800a */ 	lui	$s0,0x800a
/*  f10a97c:	3c12800a */ 	lui	$s2,0x800a
/*  f10a980:	3c11800a */ 	lui	$s1,0x800a
/*  f10a984:	263166f8 */ 	addiu	$s1,$s1,0x66f8
/*  f10a988:	265266f9 */ 	addiu	$s2,$s2,0x66f9
/*  f10a98c:	261066f0 */ 	addiu	$s0,$s0,0x66f0
.NB0f10a990:
/*  f10a990:	16110003 */ 	bne	$s0,$s1,.NB0f10a9a0
/*  f10a994:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a998:	10000002 */ 	beqz	$zero,.NB0f10a9a4
/*  f10a99c:	24060002 */ 	addiu	$a2,$zero,0x2
.NB0f10a9a0:
/*  f10a9a0:	24060008 */ 	addiu	$a2,$zero,0x8
.NB0f10a9a4:
/*  f10a9a4:	0fc34a9e */ 	jal	savebufferOr
/*  f10a9a8:	920500ac */ 	lbu	$a1,0xac($s0)
/*  f10a9ac:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10a9b0:	0212082b */ 	sltu	$at,$s0,$s2
/*  f10a9b4:	1420fff6 */ 	bnez	$at,.NB0f10a990
/*  f10a9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a9bc:	3c10800a */ 	lui	$s0,0x800a
/*  f10a9c0:	3c11800a */ 	lui	$s1,0x800a
/*  f10a9c4:	263166f4 */ 	addiu	$s1,$s1,0x66f4
/*  f10a9c8:	261066f0 */ 	addiu	$s0,$s0,0x66f0
/*  f10a9cc:	02802025 */ 	or	$a0,$s4,$zero
.NB0f10a9d0:
/*  f10a9d0:	920500b5 */ 	lbu	$a1,0xb5($s0)
/*  f10a9d4:	0fc34a9e */ 	jal	savebufferOr
/*  f10a9d8:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f10a9dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10a9e0:	5611fffb */ 	bnel	$s0,$s1,.NB0f10a9d0
/*  f10a9e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a9e8:	0fc34aeb */ 	jal	func0f0d54c4
/*  f10a9ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f10a9f0:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f10a9f4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f10a9f8:	83a4014b */ 	lb	$a0,0x14b($sp)
/*  f10a9fc:	8fa5014c */ 	lw	$a1,0x14c($sp)
/*  f10aa00:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f10aa04:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f10aa08:	0fc442fb */ 	jal	pakSaveAtGuid
/*  f10aa0c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f10aa10:	3c01800a */ 	lui	$at,0x800a
/*  f10aa14:	14400009 */ 	bnez	$v0,.NB0f10aa3c
/*  f10aa18:	ac2266e8 */ 	sw	$v0,0x66e8($at)
/*  f10aa1c:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f10aa20:	97a90152 */ 	lhu	$t1,0x152($sp)
/*  f10aa24:	3c03800a */ 	lui	$v1,0x800a
/*  f10aa28:	246367b0 */ 	addiu	$v1,$v1,0x67b0
/*  f10aa2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10aa30:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f10aa34:	10000003 */ 	beqz	$zero,.NB0f10aa44
/*  f10aa38:	a4690004 */ 	sh	$t1,0x4($v1)
.NB0f10aa3c:
/*  f10aa3c:	10000001 */ 	beqz	$zero,.NB0f10aa44
/*  f10aa40:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f10aa44:
/*  f10aa44:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f10aa48:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f10aa4c:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f10aa50:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f10aa54:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f10aa58:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f10aa5c:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f10aa60:	03e00008 */ 	jr	$ra
/*  f10aa64:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#endif

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
