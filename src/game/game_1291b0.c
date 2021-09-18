#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

u32 var8007e3c0 = 0xab8d9f77;
u32 var8007e3c4 = 0x81280783;

GLOBAL_ASM(
glabel func0f1291b0
/*  f1291b0:	3c048008 */ 	lui	$a0,%hi(var8007e3c0)
/*  f1291b4:	dc84e3c0 */ 	ld	$a0,%lo(var8007e3c0)($a0)
/*  f1291b8:	3c018008 */ 	lui	$at,%hi(var8007e3c0)
/*  f1291bc:	000437fc */ 	dsll32	$a2,$a0,0x1f
/*  f1291c0:	00042ff8 */ 	dsll	$a1,$a0,0x1f
/*  f1291c4:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*  f1291c8:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*  f1291cc:	0004233c */ 	dsll32	$a0,$a0,0xc
/*  f1291d0:	00c53025 */ 	or	$a2,$a2,$a1
/*  f1291d4:	0004203e */ 	dsrl32	$a0,$a0,0x0
/*  f1291d8:	00c43026 */ 	xor	$a2,$a2,$a0
/*  f1291dc:	0006253a */ 	dsrl	$a0,$a2,0x14
/*  f1291e0:	30840fff */ 	andi	$a0,$a0,0xfff
/*  f1291e4:	00862026 */ 	xor	$a0,$a0,$a2
/*  f1291e8:	0004103c */ 	dsll32	$v0,$a0,0x0
/*  f1291ec:	fc24e3c0 */ 	sd	$a0,%lo(var8007e3c0)($at)
/*  f1291f0:	03e00008 */ 	jr	$ra
/*  f1291f4:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0f1291f8
/*  f1291f8:	64840001 */ 	daddiu	$a0,$a0,0x1
/*  f1291fc:	3c018008 */ 	lui	$at,%hi(var8007e3c0)
/*  f129200:	fc24e3c0 */ 	sd	$a0,%lo(var8007e3c0)($at)
/*  f129204:	03e00008 */ 	jr	$ra
/*  f129208:	24040000 */ 	addiu	$a0,$zero,0x0
);
