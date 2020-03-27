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
#include "types.h"

GLOBAL_ASM(
glabel __osSiDeviceBusy
/*    51c60:	3c0ea480 */ 	lui	$t6,0xa480
/*    51c64:	8dc40018 */ 	lw	$a0,0x18($t6)
/*    51c68:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    51c6c:	308f0003 */ 	andi	$t7,$a0,0x3
/*    51c70:	11e00003 */ 	beqz	$t7,.L00051c80
/*    51c74:	00000000 */ 	sll	$zero,$zero,0x0
/*    51c78:	10000002 */ 	beqz	$zero,.L00051c84
/*    51c7c:	24020001 */ 	addiu	$v0,$zero,0x1
.L00051c80:
/*    51c80:	00001025 */ 	or	$v0,$zero,$zero
.L00051c84:
/*    51c84:	03e00008 */ 	jr	$ra
/*    51c88:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    51c8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel __osProbeTLB
/*    51c90:	40085000 */ 	mfc0	$t0,$10
/*    51c94:	310900ff */ 	andi	$t1,$t0,0xff
/*    51c98:	2401e000 */ 	addiu	$at,$zero,-8192
/*    51c9c:	00815024 */ 	and	$t2,$a0,$at
/*    51ca0:	012a4825 */ 	or	$t1,$t1,$t2
/*    51ca4:	40895000 */ 	mtc0	$t1,$10
/*    51ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cac:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cb4:	42000008 */ 	tlbp
/*    51cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cc0:	400b0000 */ 	mfc0	$t3,$0
/*    51cc4:	3c018000 */ 	lui	$at,0x8000
/*    51cc8:	01615824 */ 	and	$t3,$t3,$at
/*    51ccc:	1560001a */ 	bnez	$t3,.L00051d38
/*    51cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cd4:	42000001 */ 	tlbr
/*    51cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    51cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    51ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*    51ce4:	400b2800 */ 	mfc0	$t3,$5
/*    51ce8:	216b2000 */ 	addi	$t3,$t3,0x2000
/*    51cec:	000b5842 */ 	srl	$t3,$t3,0x1
/*    51cf0:	01646024 */ 	and	$t4,$t3,$a0
/*    51cf4:	15800004 */ 	bnez	$t4,.L00051d08
/*    51cf8:	216bffff */ 	addi	$t3,$t3,-1
/*    51cfc:	40021000 */ 	mfc0	$v0,$2
/*    51d00:	10000002 */ 	beqz	$zero,.L00051d0c
/*    51d04:	00000000 */ 	sll	$zero,$zero,0x0
.L00051d08:
/*    51d08:	40021800 */ 	mfc0	$v0,$3
.L00051d0c:
/*    51d0c:	304d0002 */ 	andi	$t5,$v0,0x2
/*    51d10:	11a00009 */ 	beqz	$t5,.L00051d38
/*    51d14:	00000000 */ 	sll	$zero,$zero,0x0
/*    51d18:	3c013fff */ 	lui	$at,0x3fff
/*    51d1c:	3421ffc0 */ 	ori	$at,$at,0xffc0
/*    51d20:	00411024 */ 	and	$v0,$v0,$at
/*    51d24:	00021180 */ 	sll	$v0,$v0,0x6
/*    51d28:	008b6824 */ 	and	$t5,$a0,$t3
/*    51d2c:	004d1020 */ 	add	$v0,$v0,$t5
/*    51d30:	10000002 */ 	beqz	$zero,.L00051d3c
/*    51d34:	00000000 */ 	sll	$zero,$zero,0x0
.L00051d38:
/*    51d38:	2402ffff */ 	addiu	$v0,$zero,-1
.L00051d3c:
/*    51d3c:	40885000 */ 	mtc0	$t0,$10
/*    51d40:	03e00008 */ 	jr	$ra
/*    51d44:	00000000 */ 	sll	$zero,$zero,0x0
/*    51d48:	00000000 */ 	sll	$zero,$zero,0x0
/*    51d4c:	00000000 */ 	sll	$zero,$zero,0x0
);