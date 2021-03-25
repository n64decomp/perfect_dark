#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/libc/ll.h"
#include "lib/lib_4e090.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel bcmp
/*    4e090:	28c10010 */ 	slti	$at,$a2,0x10
/*    4e094:	14200037 */ 	bnez	$at,.L0004e174
/*    4e098:	00851026 */ 	xor	$v0,$a0,$a1
/*    4e09c:	30420003 */ 	andi	$v0,$v0,0x3
/*    4e0a0:	14400019 */ 	bnez	$v0,.L0004e108
/*    4e0a4:	0004c023 */ 	negu	$t8,$a0
/*    4e0a8:	33180003 */ 	andi	$t8,$t8,0x3
/*    4e0ac:	13000007 */ 	beqz	$t8,.L0004e0cc
/*    4e0b0:	00d83023 */ 	subu	$a2,$a2,$t8
/*    4e0b4:	00601025 */ 	or	$v0,$v1,$zero
/*    4e0b8:	88820000 */ 	lwl	$v0,0x0($a0)
/*    4e0bc:	88a30000 */ 	lwl	$v1,0x0($a1)
/*    4e0c0:	00982021 */ 	addu	$a0,$a0,$t8
/*    4e0c4:	00b82821 */ 	addu	$a1,$a1,$t8
/*    4e0c8:	14430036 */ 	bne	$v0,$v1,.L0004e1a4
.L0004e0cc:
/*    4e0cc:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e0d0:	00c13824 */ 	and	$a3,$a2,$at
/*    4e0d4:	10e00027 */ 	beqz	$a3,.L0004e174
/*    4e0d8:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e0dc:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e0e0:	8c820000 */ 	lw	$v0,0x0($a0)
.L0004e0e4:
/*    4e0e4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    4e0e8:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4e0ec:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    4e0f0:	1443002c */ 	bne	$v0,$v1,.L0004e1a4
/*    4e0f4:	00000000 */ 	nop
/*    4e0f8:	5487fffa */ 	bnel	$a0,$a3,.L0004e0e4
/*    4e0fc:	8c820000 */ 	lw	$v0,0x0($a0)
/*    4e100:	1000001c */ 	b	.L0004e174
/*    4e104:	00000000 */ 	nop
.L0004e108:
/*    4e108:	00053823 */ 	negu	$a3,$a1
/*    4e10c:	30e70003 */ 	andi	$a3,$a3,0x3
/*    4e110:	10e0000a */ 	beqz	$a3,.L0004e13c
/*    4e114:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e118:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e11c:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e120:
/*    4e120:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    4e124:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4e128:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4e12c:	1443001d */ 	bne	$v0,$v1,.L0004e1a4
/*    4e130:	00000000 */ 	nop
/*    4e134:	5487fffa */ 	bnel	$a0,$a3,.L0004e120
/*    4e138:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e13c:
/*    4e13c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e140:	00c13824 */ 	and	$a3,$a2,$at
/*    4e144:	10e0000b */ 	beqz	$a3,.L0004e174
/*    4e148:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e14c:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e150:	88820000 */ 	lwl	$v0,0x0($a0)
.L0004e154:
/*    4e154:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    4e158:	98820003 */ 	lwr	$v0,0x3($a0)
/*    4e15c:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4e160:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    4e164:	1443000f */ 	bne	$v0,$v1,.L0004e1a4
/*    4e168:	00000000 */ 	nop
/*    4e16c:	5487fff9 */ 	bnel	$a0,$a3,.L0004e154
/*    4e170:	88820000 */ 	lwl	$v0,0x0($a0)
.L0004e174:
/*    4e174:	18c00009 */ 	blez	$a2,.L0004e19c
/*    4e178:	00c43821 */ 	addu	$a3,$a2,$a0
/*    4e17c:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e180:
/*    4e180:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    4e184:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4e188:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4e18c:	14430005 */ 	bne	$v0,$v1,.L0004e1a4
/*    4e190:	00000000 */ 	nop
/*    4e194:	5487fffa */ 	bnel	$a0,$a3,.L0004e180
/*    4e198:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e19c:
/*    4e19c:	03e00008 */ 	jr	$ra
/*    4e1a0:	00001025 */ 	or	$v0,$zero,$zero
.L0004e1a4:
/*    4e1a4:	03e00008 */ 	jr	$ra
/*    4e1a8:	24020001 */ 	addiu	$v0,$zero,0x1
);
