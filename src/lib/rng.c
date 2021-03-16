#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

u64 g_RngSeed = 0xab8d9f7781280783;

GLOBAL_ASM(
glabel random
/*    12dc0:	3c048006 */ 	lui	$a0,%hi(g_RngSeed)
/*    12dc4:	dc84ee00 */ 	ld	$a0,%lo(g_RngSeed)($a0)
/*    12dc8:	3c018006 */ 	lui	$at,%hi(g_RngSeed)
/*    12dcc:	000437fc */ 	dsll32	$a2,$a0,0x1f
/*    12dd0:	00042ff8 */ 	dsll	$a1,$a0,0x1f
/*    12dd4:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12dd8:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12ddc:	0004233c */ 	dsll32	$a0,$a0,0xc
/*    12de0:	00c53025 */ 	or	$a2,$a2,$a1
/*    12de4:	0004203e */ 	dsrl32	$a0,$a0,0x0
/*    12de8:	00c43026 */ 	xor	$a2,$a2,$a0
/*    12dec:	0006253a */ 	dsrl	$a0,$a2,0x14
/*    12df0:	30840fff */ 	andi	$a0,$a0,0xfff
/*    12df4:	00862026 */ 	xor	$a0,$a0,$a2
/*    12df8:	0004103c */ 	dsll32	$v0,$a0,0x0
/*    12dfc:	fc24ee00 */ 	sd	$a0,%lo(g_RngSeed)($at)
/*    12e00:	03e00008 */ 	jr	$ra
/*    12e04:	0002103f */ 	dsra32	$v0,$v0,0x0
);

// Commented because ld isn't happy with bitshifting a u64.
//u32 random(void)
//{
//	g_RngSeed = ((g_RngSeed << 63) >> 31 | (g_RngSeed << 31) >> 32) ^ (g_RngSeed << 44) >> 32;
//	g_RngSeed = g_RngSeed >> 20 & 0xfff ^ g_RngSeed;
//
//	return g_RngSeed;
//}

GLOBAL_ASM(
glabel rngSetSeed
/*    12e08:	64840001 */ 	daddiu	$a0,$a0,0x1
/*    12e0c:	3c018006 */ 	lui	$at,%hi(g_RngSeed)
/*    12e10:	fc24ee00 */ 	sd	$a0,%lo(g_RngSeed)($at)
/*    12e14:	03e00008 */ 	jr	$ra
/*    12e18:	24040000 */ 	addiu	$a0,$zero,0x0
);

GLOBAL_ASM(
glabel func00012e1c
/*    12e1c:	dc870000 */ 	ld	$a3,0x0($a0)
/*    12e20:	000737fc */ 	dsll32	$a2,$a3,0x1f
/*    12e24:	00072ff8 */ 	dsll	$a1,$a3,0x1f
/*    12e28:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12e2c:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12e30:	00073b3c */ 	dsll32	$a3,$a3,0xc
/*    12e34:	00c53025 */ 	or	$a2,$a2,$a1
/*    12e38:	0007383e */ 	dsrl32	$a3,$a3,0x0
/*    12e3c:	00c73026 */ 	xor	$a2,$a2,$a3
/*    12e40:	00063d3a */ 	dsrl	$a3,$a2,0x14
/*    12e44:	30e70fff */ 	andi	$a3,$a3,0xfff
/*    12e48:	00e63826 */ 	xor	$a3,$a3,$a2
/*    12e4c:	0007103c */ 	dsll32	$v0,$a3,0x0
/*    12e50:	fc870000 */ 	sd	$a3,0x0($a0)
/*    12e54:	03e00008 */ 	jr	$ra
/*    12e58:	0002103f */ 	dsra32	$v0,$v0,0x0
);
