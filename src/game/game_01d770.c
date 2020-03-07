#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_016100.h"
#include "game/game_01b0a0.h"
#include "game/game_01bea0.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_10ccd0.h"
#include "game/game_127910.h"
#include "game/game_131060.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_177e00.h"
#include "game/game_179060.h"
#include "game/game_187770.h"
#include "game/game_19aa80.h"
#include "game/game_19c990.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_13900.h"
#include "types.h"

const char var7f1a8640[] = "wettick";
const char var7f1a8648[] = "windspeed";

const u32 var7f1a8654[] = {0x00000000};
const u32 var7f1a8658[] = {0x00000000};
const u32 var7f1a865c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f01d770
/*  f01d770:	3c0e8008 */ 	lui	$t6,%hi(var8007f0c0)
/*  f01d774:	8dcef0c0 */ 	lw	$t6,%lo(var8007f0c0)($t6)
/*  f01d778:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01d77c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01d780:	11c00031 */ 	beqz	$t6,.L0f01d848
/*  f01d784:	3c028008 */ 	lui	$v0,%hi(var8007fc00)
/*  f01d788:	8c42fc00 */ 	lw	$v0,%lo(var8007fc00)($v0)
/*  f01d78c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f01d790:	3c0f800a */ 	lui	$t7,0x800a
/*  f01d794:	54410009 */ 	bnel	$v0,$at,.L0f01d7bc
/*  f01d798:	2401000a */ 	addiu	$at,$zero,0xa
/*  f01d79c:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f01d7a0:	3c01c4fa */ 	lui	$at,0xc4fa
/*  f01d7a4:	44813000 */ 	mtc1	$at,$f6
/*  f01d7a8:	c5e41bb8 */ 	lwc1	$f4,0x1bb8($t7)
/*  f01d7ac:	4606203c */ 	c.lt.s	$f4,$f6
/*  f01d7b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d7b4:	45010024 */ 	bc1t	.L0f01d848
/*  f01d7b8:	2401000a */ 	addiu	$at,$zero,0xa
.L0f01d7bc:
/*  f01d7bc:	14410004 */ 	bne	$v0,$at,.L0f01d7d0
/*  f01d7c0:	3c18800a */ 	lui	$t8,0x800a
/*  f01d7c4:	8f18a26c */ 	lw	$t8,-0x5d94($t8)
/*  f01d7c8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01d7cc:	1701001e */ 	bne	$t8,$at,.L0f01d848
.L0f01d7d0:
/*  f01d7d0:	3c047f1b */ 	lui	$a0,%hi(var7f1a8640)
/*  f01d7d4:	3c058006 */ 	lui	$a1,%hi(var80062954)
/*  f01d7d8:	24a52954 */ 	addiu	$a1,$a1,%lo(var80062954)
/*  f01d7dc:	0c0036cc */ 	jal	func0000db30
/*  f01d7e0:	24848640 */ 	addiu	$a0,$a0,%lo(var7f1a8640)
/*  f01d7e4:	3c047f1b */ 	lui	$a0,%hi(var7f1a8648)
/*  f01d7e8:	3c058006 */ 	lui	$a1,%hi(var80062950)
/*  f01d7ec:	24a52950 */ 	addiu	$a1,$a1,%lo(var80062950)
/*  f01d7f0:	0c0036cc */ 	jal	func0000db30
/*  f01d7f4:	24848648 */ 	addiu	$a0,$a0,%lo(var7f1a8648)
/*  f01d7f8:	3c198006 */ 	lui	$t9,%hi(var80062954)
/*  f01d7fc:	8f392954 */ 	lw	$t9,%lo(var80062954)($t9)
/*  f01d800:	3c048008 */ 	lui	$a0,%hi(var8007f0c0)
/*  f01d804:	53200011 */ 	beqzl	$t9,.L0f01d84c
/*  f01d808:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01d80c:	8c84f0c0 */ 	lw	$a0,%lo(var8007f0c0)($a0)
/*  f01d810:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01d814:	8c820020 */ 	lw	$v0,0x20($a0)
/*  f01d818:	10400005 */ 	beqz	$v0,.L0f01d830
/*  f01d81c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d820:	10410007 */ 	beq	$v0,$at,.L0f01d840
/*  f01d824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d828:	10000008 */ 	beqz	$zero,.L0f01d84c
/*  f01d82c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d830:
/*  f01d830:	0fc4c68c */ 	jal	func0f131a30
/*  f01d834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d838:	10000004 */ 	beqz	$zero,.L0f01d84c
/*  f01d83c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d840:
/*  f01d840:	0fc4c874 */ 	jal	func0f1321d0
/*  f01d844:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d848:
/*  f01d848:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d84c:
/*  f01d84c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01d850:	03e00008 */ 	jr	$ra
/*  f01d854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d85c:	00000000 */ 	sll	$zero,$zero,0x0
);
