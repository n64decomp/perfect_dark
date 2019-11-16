#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_066310.h"

const u32 var7f1a82c0[] = {0x7f01505c};
const u32 var7f1a82c4[] = {0x7f015068};
const u32 var7f1a82c8[] = {0x7f01505c};
const u32 var7f1a82cc[] = {0x7f01505c};
const u32 var7f1a82d0[] = {0x7f01505c};
const u32 var7f1a82d4[] = {0x7f01505c};
const u32 var7f1a82d8[] = {0x7f01505c};
const u32 var7f1a82dc[] = {0x7f01505c};
const u32 var7f1a82e0[] = {0x7f015068};
const u32 var7f1a82e4[] = {0x7f01505c};
const u32 var7f1a82e8[] = {0x7f01505c};
const u32 var7f1a82ec[] = {0x7f01505c};
const u32 var7f1a82f0[] = {0x7f01505c};
const u32 var7f1a82f4[] = {0x7f015068};
const u32 var7f1a82f8[] = {0x7f015068};
const u32 var7f1a82fc[] = {0x7f015068};
const u32 var7f1a8300[] = {0x7f01505c};
const u32 var7f1a8304[] = {0x7f015068};
const u32 var7f1a8308[] = {0x7f015068};
const u32 var7f1a830c[] = {0x7f01505c};
const u32 var7f1a8310[] = {0x7f01505c};
const u32 var7f1a8314[] = {0x7f015068};
const u32 var7f1a8318[] = {0x7f015068};
const u32 var7f1a831c[] = {0x7f015068};
const u32 var7f1a8320[] = {0x7f015068};
const u32 var7f1a8324[] = {0x7f015068};
const u32 var7f1a8328[] = {0x7f015068};
const u32 var7f1a832c[] = {0x7f015068};
const u32 var7f1a8330[] = {0x7f015068};
const u32 var7f1a8334[] = {0x7f015068};
const u32 var7f1a8338[] = {0x7f015068};
const u32 var7f1a833c[] = {0x7f015068};
const u32 var7f1a8340[] = {0x7f015068};
const u32 var7f1a8344[] = {0x7f015068};
const u32 var7f1a8348[] = {0x7f015068};
const u32 var7f1a834c[] = {0x7f01505c};
const u32 var7f1a8350[] = {0x7f015068};
const u32 var7f1a8354[] = {0x7f015068};
const u32 var7f1a8358[] = {0x7f01505c};
const u32 var7f1a835c[] = {0x7f01505c};
const u32 var7f1a8360[] = {0x7f01505c};
const u32 var7f1a8364[] = {0x7f01505c};
const u32 var7f1a8368[] = {0x7f01505c};
const u32 var7f1a836c[] = {0x7f015068};
const u32 var7f1a8370[] = {0x7f01505c};
const u32 var7f1a8374[] = {0x7f015068};
const u32 var7f1a8378[] = {0x7f01505c};
const u32 var7f1a837c[] = {0x7f01505c};
const u32 var7f1a8380[] = {0x7f015068};
const u32 var7f1a8384[] = {0x7f015068};
const u32 var7f1a8388[] = {0x7f01505c};
const u32 var7f1a838c[] = {0x7f015068};
const u32 var7f1a8390[] = {0x7f01505c};
const u32 var7f1a8394[] = {0x7f01505c};
const u32 var7f1a8398[] = {0x7f01505c};
const u32 var7f1a839c[] = {0x7f015068};
const u32 var7f1a83a0[] = {0x7f01505c};
const u32 var7f1a83a4[] = {0x7f015068};
const u32 var7f1a83a8[] = {0x7f01505c};
const u32 var7f1a83ac[] = {0x00000000};

GLOBAL_ASM(
glabel func0f015010
/*  f015010:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f015014:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f015018:	3c10800a */ 	lui	$s0,0x800a
/*  f01501c:	8e10d040 */ 	lw	$s0,-0x2fc0($s0)
/*  f015020:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f015024:	52000019 */ 	beqzl	$s0,.L0f01508c
/*  f015028:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f01502c:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f015030:	24010034 */ 	addiu	$at,$zero,0x34
/*  f015034:	10610014 */ 	beq	$v1,$at,.L0f015088
/*  f015038:	246effff */ 	addiu	$t6,$v1,-1
.L0f01503c:
/*  f01503c:	2dc1003b */ 	sltiu	$at,$t6,0x3b
/*  f015040:	10200009 */ 	beqz	$at,.L0f015068
/*  f015044:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f015048:	3c017f1b */ 	lui	$at,%hi(var7f1a82c0)
/*  f01504c:	002e0821 */ 	addu	$at,$at,$t6
/*  f015050:	8c2e82c0 */ 	lw	$t6,%lo(var7f1a82c0)($at)
/*  f015054:	01c00008 */ 	jr	$t6
/*  f015058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01505c:	02002025 */ 	or	$a0,$s0,$zero
/*  f015060:	0fc1acd3 */ 	jal	func0f06b34c
/*  f015064:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f015068:
/*  f015068:	0fc24784 */ 	jal	func0f091e10
/*  f01506c:	02002025 */ 	or	$a0,$s0,$zero
/*  f015070:	00027880 */ 	sll	$t7,$v0,0x2
/*  f015074:	01f08021 */ 	addu	$s0,$t7,$s0
/*  f015078:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f01507c:	24010034 */ 	addiu	$at,$zero,0x34
/*  f015080:	5461ffee */ 	bnel	$v1,$at,.L0f01503c
/*  f015084:	246effff */ 	addiu	$t6,$v1,-1
.L0f015088:
/*  f015088:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f01508c:
/*  f01508c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f015090:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f015094:	03e00008 */ 	jr	$ra
/*  f015098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01509c:	00000000 */ 	sll	$zero,$zero,0x0
);