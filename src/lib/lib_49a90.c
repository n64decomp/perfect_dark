#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_488e0.h"
#include "lib/lib_49a90.h"
#include "lib/lib_4b480.h"
#include "types.h"

GLOBAL_ASM(
glabel __osPiCreateAccessQueue
/*    49a90:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49a94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49a98:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    49a9c:	3c018006 */ 	lui	$at,0x8006
/*    49aa0:	3c04800a */ 	lui	$a0,%hi(var8009c7a8)
/*    49aa4:	3c05800a */ 	lui	$a1,%hi(var8009c7a0)
/*    49aa8:	ac2e0920 */ 	sw	$t6,0x920($at)
/*    49aac:	24a5c7a0 */ 	addiu	$a1,$a1,%lo(var8009c7a0)
/*    49ab0:	2484c7a8 */ 	addiu	$a0,$a0,%lo(var8009c7a8)
/*    49ab4:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    49ab8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    49abc:	3c04800a */ 	lui	$a0,%hi(var8009c7a8)
/*    49ac0:	2484c7a8 */ 	addiu	$a0,$a0,%lo(var8009c7a8)
/*    49ac4:	00002825 */ 	or	$a1,$zero,$zero
/*    49ac8:	0c012238 */ 	jal	osSendMesg
/*    49acc:	00003025 */ 	or	$a2,$zero,$zero
/*    49ad0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49ad4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49ad8:	03e00008 */ 	jr	$ra
/*    49adc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00049ae0
/*    49ae0:	3c0e8006 */ 	lui	$t6,%hi(var80060920)
/*    49ae4:	8dce0920 */ 	lw	$t6,%lo(var80060920)($t6)
/*    49ae8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    49aec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49af0:	15c00003 */ 	bnez	$t6,.L00049b00
/*    49af4:	00000000 */ 	sll	$zero,$zero,0x0
/*    49af8:	0c0126a4 */ 	jal	__osPiCreateAccessQueue
/*    49afc:	00000000 */ 	sll	$zero,$zero,0x0
.L00049b00:
/*    49b00:	3c04800a */ 	lui	$a0,%hi(var8009c7a8)
/*    49b04:	2484c7a8 */ 	addiu	$a0,$a0,%lo(var8009c7a8)
/*    49b08:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    49b0c:	0c0121bc */ 	jal	osRecvMesg
/*    49b10:	24060001 */ 	addiu	$a2,$zero,0x1
/*    49b14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49b18:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    49b1c:	03e00008 */ 	jr	$ra
/*    49b20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00049b24
/*    49b24:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49b28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49b2c:	3c04800a */ 	lui	$a0,%hi(var8009c7a8)
/*    49b30:	2484c7a8 */ 	addiu	$a0,$a0,%lo(var8009c7a8)
/*    49b34:	00002825 */ 	or	$a1,$zero,$zero
/*    49b38:	0c012238 */ 	jal	osSendMesg
/*    49b3c:	00003025 */ 	or	$a2,$zero,$zero
/*    49b40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49b44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49b48:	03e00008 */ 	jr	$ra
/*    49b4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel osPiRawStartDma
/*    49b50:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49b54:	3c03a460 */ 	lui	$v1,0xa460
/*    49b58:	34630010 */ 	ori	$v1,$v1,0x10
/*    49b5c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49b60:	afa40018 */ 	sw	$a0,0x18($sp)
/*    49b64:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    49b68:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49b6c:	00c02025 */ 	or	$a0,$a2,$zero
/*    49b70:	304e0003 */ 	andi	$t6,$v0,0x3
/*    49b74:	11c00005 */ 	beqz	$t6,.L00049b8c
/*    49b78:	00000000 */ 	sll	$zero,$zero,0x0
/*    49b7c:	8c620000 */ 	lw	$v0,0x0($v1)
.L00049b80:
/*    49b80:	304f0003 */ 	andi	$t7,$v0,0x3
/*    49b84:	55e0fffe */ 	bnezl	$t7,.L00049b80
/*    49b88:	8c620000 */ 	lw	$v0,0x0($v1)
.L00049b8c:
/*    49b8c:	0c012d20 */ 	jal	osVirtualToPhysical
/*    49b90:	afa70024 */ 	sw	$a3,0x24($sp)
/*    49b94:	8fa30018 */ 	lw	$v1,0x18($sp)
/*    49b98:	8fa70024 */ 	lw	$a3,0x24($sp)
/*    49b9c:	3c18a460 */ 	lui	$t8,0xa460
/*    49ba0:	af020000 */ 	sw	$v0,0x0($t8)
/*    49ba4:	3c198000 */ 	lui	$t9,0x8000
/*    49ba8:	8f390308 */ 	lw	$t9,0x308($t9)
/*    49bac:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    49bb0:	3c011fff */ 	lui	$at,0x1fff
/*    49bb4:	3421ffff */ 	ori	$at,$at,0xffff
/*    49bb8:	03284825 */ 	or	$t1,$t9,$t0
/*    49bbc:	01215024 */ 	and	$t2,$t1,$at
/*    49bc0:	3c0ba460 */ 	lui	$t3,0xa460
/*    49bc4:	10600006 */ 	beqz	$v1,.L00049be0
/*    49bc8:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*    49bcc:	24010001 */ 	addiu	$at,$zero,0x1
/*    49bd0:	10610007 */ 	beq	$v1,$at,.L00049bf0
/*    49bd4:	24eeffff */ 	addiu	$t6,$a3,-1
/*    49bd8:	1000000b */ 	beqz	$zero,.L00049c08
/*    49bdc:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049be0:
/*    49be0:	24ecffff */ 	addiu	$t4,$a3,-1
/*    49be4:	3c0da460 */ 	lui	$t5,0xa460
/*    49be8:	10000006 */ 	beqz	$zero,.L00049c04
/*    49bec:	adac000c */ 	sw	$t4,0xc($t5)
.L00049bf0:
/*    49bf0:	3c0fa460 */ 	lui	$t7,0xa460
/*    49bf4:	10000003 */ 	beqz	$zero,.L00049c04
/*    49bf8:	adee0008 */ 	sw	$t6,0x8($t7)
/*    49bfc:	10000002 */ 	beqz	$zero,.L00049c08
/*    49c00:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049c04:
/*    49c04:	00001025 */ 	or	$v0,$zero,$zero
.L00049c08:
/*    49c08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49c0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49c10:	03e00008 */ 	jr	$ra
/*    49c14:	00000000 */ 	sll	$zero,$zero,0x0
/*    49c18:	00000000 */ 	sll	$zero,$zero,0x0
/*    49c1c:	00000000 */ 	sll	$zero,$zero,0x0
);
