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
glabel memcpy
/*    4a5e0:	00801025 */ 	or	$v0,$a0,$zero
/*    4a5e4:	10c00007 */ 	beqz	$a2,.L0004a604
/*    4a5e8:	00a01825 */ 	or	$v1,$a1,$zero
.L0004a5ec:
/*    4a5ec:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    4a5f0:	24c6ffff */ 	addiu	$a2,$a2,-1
/*    4a5f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4a5f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4a5fc:	14c0fffb */ 	bnez	$a2,.L0004a5ec
/*    4a600:	a04effff */ 	sb	$t6,-0x1($v0)
.L0004a604:
/*    4a604:	03e00008 */ 	jr	$ra
/*    4a608:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0004a60c
/*    4a60c:	908e0000 */ 	lbu	$t6,0x0($a0)
/*    4a610:	00801825 */ 	or	$v1,$a0,$zero
/*    4a614:	11c00005 */ 	beqz	$t6,.L0004a62c
/*    4a618:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a61c:	906f0001 */ 	lbu	$t7,0x1($v1)
.L0004a620:
/*    4a620:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4a624:	55e0fffe */ 	bnezl	$t7,.L0004a620
/*    4a628:	906f0001 */ 	lbu	$t7,0x1($v1)
.L0004a62c:
/*    4a62c:	03e00008 */ 	jr	$ra
/*    4a630:	00641023 */ 	subu	$v0,$v1,$a0
);

// func0004a634
GLOBAL_ASM(
glabel strchr
/*    4a634:	90830000 */ 	lbu	$v1,0x0($a0)
/*    4a638:	30ae00ff */ 	andi	$t6,$a1,0xff
/*    4a63c:	30a200ff */ 	andi	$v0,$a1,0xff
/*    4a640:	51c3000a */ 	beql	$t6,$v1,.L0004a66c
/*    4a644:	00801025 */ 	or	$v0,$a0,$zero
.L0004a648:
/*    4a648:	54600004 */ 	bnezl	$v1,.L0004a65c
/*    4a64c:	90830001 */ 	lbu	$v1,0x1($a0)
/*    4a650:	03e00008 */ 	jr	$ra
/*    4a654:	00001025 */ 	or	$v0,$zero,$zero
/*    4a658:	90830001 */ 	lbu	$v1,0x1($a0)
.L0004a65c:
/*    4a65c:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4a660:	1443fff9 */ 	bne	$v0,$v1,.L0004a648
/*    4a664:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a668:	00801025 */ 	or	$v0,$a0,$zero
.L0004a66c:
/*    4a66c:	03e00008 */ 	jr	$ra
/*    4a670:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a674:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a678:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a67c:	00000000 */ 	sll	$zero,$zero,0x0
);