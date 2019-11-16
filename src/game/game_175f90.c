#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_1668e0.h"
#include "game/game_175f50.h"
#include "library/library.h"

const char var7f1b7c90[] = "Apr  6 2000 15:05:01";
const char var7f1b7ca8[] = "";
const char var7f1b7cac[] = "";

void func0f175f90(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f175f98
/*  f175f98:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f175f9c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f175fa0:	0fc59ccc */ 	jal	func0f167330
/*  f175fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175fa8:	0c00494a */ 	jal	func00012528
/*  f175fac:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175fb0:	0fc59cbc */ 	jal	func0f1672f0
/*  f175fb4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175fb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f175fbc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f175fc0:	03e00008 */ 	jr	$ra
/*  f175fc4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f175fc8
/*  f175fc8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f175fcc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f175fd0:	0c004965 */ 	jal	func00012594
/*  f175fd4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175fd8:	0fc59cbc */ 	jal	func0f1672f0
/*  f175fdc:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175fe0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f175fe4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f175fe8:	03e00008 */ 	jr	$ra
/*  f175fec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175ff0:	3c027f1b */ 	lui	$v0,%hi(var7f1b7c90)
/*  f175ff4:	03e00008 */ 	jr	$ra
/*  f175ff8:	24427c90 */ 	addiu	$v0,$v0,%lo(var7f1b7c90)
/*  f175ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176000:	03e00008 */ 	jr	$ra
/*  f176004:	00801025 */ 	or	$v0,$a0,$zero
/*  f176008:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f17600c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f176010:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f176014:	03e00008 */ 	jr	$ra
/*  f176018:	00801025 */ 	or	$v0,$a0,$zero
/*  f17601c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f176020:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f176024:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f176028:	03e00008 */ 	jr	$ra
/*  f17602c:	00801025 */ 	or	$v0,$a0,$zero
/*  f176030:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f176034:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f176038:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f17603c:	03e00008 */ 	jr	$ra
/*  f176040:	00801025 */ 	or	$v0,$a0,$zero
/*  f176044:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f176048:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f17604c:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f176050:	03e00008 */ 	jr	$ra
/*  f176054:	00801025 */ 	or	$v0,$a0,$zero
/*  f176058:	03e00008 */ 	jr	$ra
/*  f17605c:	e7ac0000 */ 	swc1	$f12,0x0($sp)
/*  f176060:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f176064:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f176068:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f17606c:	03e00008 */ 	jr	$ra
/*  f176070:	00801025 */ 	or	$v0,$a0,$zero
/*  f176074:	03e00008 */ 	jr	$ra
/*  f176078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17607c:	00000000 */ 	sll	$zero,$zero,0x0
);
