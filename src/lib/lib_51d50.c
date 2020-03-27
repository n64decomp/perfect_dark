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
glabel func00051d50
/*    51d50:	afa40000 */ 	sw	$a0,0x0($sp)
/*    51d54:	308effff */ 	andi	$t6,$a0,0xffff
/*    51d58:	01c02025 */ 	or	$a0,$t6,$zero
/*    51d5c:	00001825 */ 	or	$v1,$zero,$zero
/*    51d60:	24020400 */ 	addiu	$v0,$zero,0x400
.L00051d64:
/*    51d64:	00037840 */ 	sll	$t7,$v1,0x1
/*    51d68:	0082c024 */ 	and	$t8,$a0,$v0
/*    51d6c:	13000008 */ 	beqz	$t8,.L00051d90
/*    51d70:	01e01825 */ 	or	$v1,$t7,$zero
/*    51d74:	31f90020 */ 	andi	$t9,$t7,0x20
/*    51d78:	13200003 */ 	beqz	$t9,.L00051d88
/*    51d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    51d80:	10000007 */ 	beqz	$zero,.L00051da0
/*    51d84:	39e30014 */ 	xori	$v1,$t7,0x14
.L00051d88:
/*    51d88:	10000005 */ 	beqz	$zero,.L00051da0
/*    51d8c:	24630001 */ 	addiu	$v1,$v1,0x1
.L00051d90:
/*    51d90:	30690020 */ 	andi	$t1,$v1,0x20
/*    51d94:	11200002 */ 	beqz	$t1,.L00051da0
/*    51d98:	386a0015 */ 	xori	$t2,$v1,0x15
/*    51d9c:	01401825 */ 	or	$v1,$t2,$zero
.L00051da0:
/*    51da0:	00025842 */ 	srl	$t3,$v0,0x1
/*    51da4:	1560ffef */ 	bnez	$t3,.L00051d64
/*    51da8:	01601025 */ 	or	$v0,$t3,$zero
/*    51dac:	00036040 */ 	sll	$t4,$v1,0x1
/*    51db0:	318d0020 */ 	andi	$t5,$t4,0x20
/*    51db4:	11a00002 */ 	beqz	$t5,.L00051dc0
/*    51db8:	01801825 */ 	or	$v1,$t4,$zero
/*    51dbc:	39830015 */ 	xori	$v1,$t4,0x15
.L00051dc0:
/*    51dc0:	00037840 */ 	sll	$t7,$v1,0x1
/*    51dc4:	31f80020 */ 	andi	$t8,$t7,0x20
/*    51dc8:	13000002 */ 	beqz	$t8,.L00051dd4
/*    51dcc:	01e01825 */ 	or	$v1,$t7,$zero
/*    51dd0:	39e30015 */ 	xori	$v1,$t7,0x15
.L00051dd4:
/*    51dd4:	00034040 */ 	sll	$t0,$v1,0x1
/*    51dd8:	31090020 */ 	andi	$t1,$t0,0x20
/*    51ddc:	11200002 */ 	beqz	$t1,.L00051de8
/*    51de0:	01001825 */ 	or	$v1,$t0,$zero
/*    51de4:	39030015 */ 	xori	$v1,$t0,0x15
.L00051de8:
/*    51de8:	00035840 */ 	sll	$t3,$v1,0x1
/*    51dec:	316c0020 */ 	andi	$t4,$t3,0x20
/*    51df0:	11800002 */ 	beqz	$t4,.L00051dfc
/*    51df4:	01601825 */ 	or	$v1,$t3,$zero
/*    51df8:	39630015 */ 	xori	$v1,$t3,0x15
.L00051dfc:
/*    51dfc:	00037040 */ 	sll	$t6,$v1,0x1
/*    51e00:	31cf0020 */ 	andi	$t7,$t6,0x20
/*    51e04:	11e00002 */ 	beqz	$t7,.L00051e10
/*    51e08:	01c01825 */ 	or	$v1,$t6,$zero
/*    51e0c:	39c30015 */ 	xori	$v1,$t6,0x15
.L00051e10:
/*    51e10:	00601025 */ 	or	$v0,$v1,$zero
/*    51e14:	3059001f */ 	andi	$t9,$v0,0x1f
/*    51e18:	03e00008 */ 	jr	$ra
/*    51e1c:	03201025 */ 	or	$v0,$t9,$zero
);

GLOBAL_ASM(
glabel func00051e20
/*    51e20:	00802825 */ 	or	$a1,$a0,$zero
/*    51e24:	00001825 */ 	or	$v1,$zero,$zero
/*    51e28:	24020020 */ 	addiu	$v0,$zero,0x20
.L00051e2c:
/*    51e2c:	24040080 */ 	addiu	$a0,$zero,0x80
/*    51e30:	90a60000 */ 	lbu	$a2,0x0($a1)
.L00051e34:
/*    51e34:	00037040 */ 	sll	$t6,$v1,0x1
/*    51e38:	00c47824 */ 	and	$t7,$a2,$a0
/*    51e3c:	11e00008 */ 	beqz	$t7,.L00051e60
/*    51e40:	01c01825 */ 	or	$v1,$t6,$zero
/*    51e44:	31d80100 */ 	andi	$t8,$t6,0x100
/*    51e48:	13000003 */ 	beqz	$t8,.L00051e58
/*    51e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    51e50:	10000007 */ 	beqz	$zero,.L00051e70
/*    51e54:	39c30084 */ 	xori	$v1,$t6,0x84
.L00051e58:
/*    51e58:	10000005 */ 	beqz	$zero,.L00051e70
/*    51e5c:	24630001 */ 	addiu	$v1,$v1,0x1
.L00051e60:
/*    51e60:	30680100 */ 	andi	$t0,$v1,0x100
/*    51e64:	11000002 */ 	beqz	$t0,.L00051e70
/*    51e68:	38690085 */ 	xori	$t1,$v1,0x85
/*    51e6c:	01201825 */ 	or	$v1,$t1,$zero
.L00051e70:
/*    51e70:	00045042 */ 	srl	$t2,$a0,0x1
/*    51e74:	1540ffef */ 	bnez	$t2,.L00051e34
/*    51e78:	01402025 */ 	or	$a0,$t2,$zero
/*    51e7c:	2442ffff */ 	addiu	$v0,$v0,-1
/*    51e80:	1440ffea */ 	bnez	$v0,.L00051e2c
/*    51e84:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    51e88:	00035840 */ 	sll	$t3,$v1,0x1
.L00051e8c:
/*    51e8c:	316c0100 */ 	andi	$t4,$t3,0x100
/*    51e90:	11800002 */ 	beqz	$t4,.L00051e9c
/*    51e94:	01601825 */ 	or	$v1,$t3,$zero
/*    51e98:	39630085 */ 	xori	$v1,$t3,0x85
.L00051e9c:
/*    51e9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    51ea0:	2c410008 */ 	sltiu	$at,$v0,0x8
/*    51ea4:	5420fff9 */ 	bnezl	$at,.L00051e8c
/*    51ea8:	00035840 */ 	sll	$t3,$v1,0x1
/*    51eac:	03e00008 */ 	jr	$ra
/*    51eb0:	306200ff */ 	andi	$v0,$v1,0xff
/*    51eb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    51eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    51ebc:	00000000 */ 	sll	$zero,$zero,0x0
);