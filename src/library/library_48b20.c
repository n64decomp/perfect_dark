#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048b20
/*    48b20:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    48b24:	afa40020 */ 	sw	$a0,0x20($sp)
/*    48b28:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    48b2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    48b30:	afa60028 */ 	sw	$a2,0x28($sp)
/*    48b34:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    48b38:	adc00000 */ 	sw	$zero,0x0($t6)
/*    48b3c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    48b40:	ade00004 */ 	sw	$zero,0x4($t7)
/*    48b44:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    48b48:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    48b4c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    48b50:	ad19000c */ 	sw	$t9,0xc($t0)
/*    48b54:	ad180008 */ 	sw	$t8,0x8($t0)
/*    48b58:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    48b5c:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    48b60:	15400003 */ 	bnez	$t2,.L00048b70
/*    48b64:	00000000 */ 	sll	$zero,$zero,0x0
/*    48b68:	11600005 */ 	beqz	$t3,.L00048b80
/*    48b6c:	00000000 */ 	sll	$zero,$zero,0x0
.L00048b70:
/*    48b70:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    48b74:	ad2a0010 */ 	sw	$t2,0x10($t1)
/*    48b78:	10000006 */ 	beqz	$zero,.L00048b94
/*    48b7c:	ad2b0014 */ 	sw	$t3,0x14($t1)
.L00048b80:
/*    48b80:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    48b84:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    48b88:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    48b8c:	adcc0010 */ 	sw	$t4,0x10($t6)
/*    48b90:	adcd0014 */ 	sw	$t5,0x14($t6)
.L00048b94:
/*    48b94:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    48b98:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    48b9c:	af0f0018 */ 	sw	$t7,0x18($t8)
/*    48ba0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    48ba4:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    48ba8:	ad19001c */ 	sw	$t9,0x1c($t0)
/*    48bac:	0c01250a */ 	jal	func00049428
/*    48bb0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    48bb4:	3c0a8006 */ 	lui	$t2,0x8006
/*    48bb8:	8d4a08a0 */ 	lw	$t2,0x8a0($t2)
/*    48bbc:	afa20018 */ 	sw	$v0,0x18($sp)
/*    48bc0:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    48bc4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    48bc8:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    48bcc:	15690004 */ 	bne	$t3,$t1,.L00048be0
/*    48bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    48bd4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    48bd8:	0c0124ed */ 	jal	func000493b4
/*    48bdc:	8fa5001c */ 	lw	$a1,0x1c($sp)
.L00048be0:
/*    48be0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    48be4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    48be8:	00001025 */ 	or	$v0,$zero,$zero
/*    48bec:	03e00008 */ 	jr	$ra
/*    48bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*    48bf4:	00000000 */ 	sll	$zero,$zero,0x0
/*    48bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*    48bfc:	00000000 */ 	sll	$zero,$zero,0x0
);