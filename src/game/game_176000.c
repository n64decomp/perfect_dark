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

GLOBAL_ASM(
glabel func0f176000
/*  f176000:	03e00008 */ 	jr	$ra
/*  f176004:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f176008
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
