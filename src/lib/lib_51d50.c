#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u8 __osContAddressCrc(u16 inaddr)
{
	u32 crc;
	u32 mask;
	u32 addr = inaddr;

	crc = 0;

	for (mask = 0x400; mask != 0; mask >>= 1) {
		crc *= 2;

		if (addr & mask) {
			if (crc & 0x20) {
				crc ^= 20;
			} else {
				crc++;
			}
		} else {
			if (crc & 0x20) {
				crc ^= 21;
			}
		}
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	return crc & 0x1f;
}

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
/*    51e4c:	00000000 */ 	nop
/*    51e50:	10000007 */ 	b	.L00051e70
/*    51e54:	39c30084 */ 	xori	$v1,$t6,0x84
.L00051e58:
/*    51e58:	10000005 */ 	b	.L00051e70
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
);
