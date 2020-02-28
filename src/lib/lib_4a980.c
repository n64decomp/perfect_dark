#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_48b20.h"
#include "lib/lib_490b0.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4a980.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004a980
/*    4a980:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    4a984:	3c0e8006 */ 	lui	$t6,0x8006
/*    4a988:	8dce0960 */ 	lw	$t6,0x960($t6)
/*    4a98c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4a990:	afa40070 */ 	sw	$a0,0x70($sp)
/*    4a994:	afa50074 */ 	sw	$a1,0x74($sp)
/*    4a998:	afa60078 */ 	sw	$a2,0x78($sp)
/*    4a99c:	11c00003 */ 	beqz	$t6,.L0004a9ac
/*    4a9a0:	afa00068 */ 	sw	$zero,0x68($sp)
/*    4a9a4:	1000004e */ 	beqz	$zero,.L0004aae0
/*    4a9a8:	00001025 */ 	or	$v0,$zero,$zero
.L0004a9ac:
/*    4a9ac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4a9b0:	3c018006 */ 	lui	$at,0x8006
/*    4a9b4:	0c012448 */ 	jal	func00049120
/*    4a9b8:	ac2f0960 */ 	sw	$t7,0x960($at)
/*    4a9bc:	afa20060 */ 	sw	$v0,0x60($sp)
/*    4a9c0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    4a9c4:	afa30064 */ 	sw	$v1,0x64($sp)
/*    4a9c8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*    4a9cc:	17000020 */ 	bnez	$t8,.L0004aa50
/*    4a9d0:	3c010165 */ 	lui	$at,0x165
/*    4a9d4:	3421a0bc */ 	ori	$at,$at,0xa0bc
/*    4a9d8:	0321082b */ 	sltu	$at,$t9,$at
/*    4a9dc:	1020001c */ 	beqz	$at,.L0004aa50
/*    4a9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a9e4:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4a9e8:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a9ec:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4a9f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a9f4:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    4a9f8:	8fa90064 */ 	lw	$t1,0x64($sp)
/*    4a9fc:	3c0b0165 */ 	lui	$t3,0x165
/*    4aa00:	356ba0bc */ 	ori	$t3,$t3,0xa0bc
/*    4aa04:	240a0000 */ 	addiu	$t2,$zero,0x0
/*    4aa08:	240c0000 */ 	addiu	$t4,$zero,0x0
/*    4aa0c:	240d0000 */ 	addiu	$t5,$zero,0x0
/*    4aa10:	27ae0028 */ 	addiu	$t6,$sp,0x28
/*    4aa14:	27af006c */ 	addiu	$t7,$sp,0x6c
/*    4aa18:	01483023 */ 	subu	$a2,$t2,$t0
/*    4aa1c:	0169082b */ 	sltu	$at,$t3,$t1
/*    4aa20:	00c13023 */ 	subu	$a2,$a2,$at
/*    4aa24:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    4aa28:	afae0018 */ 	sw	$t6,0x18($sp)
/*    4aa2c:	afad0014 */ 	sw	$t5,0x14($sp)
/*    4aa30:	afac0010 */ 	sw	$t4,0x10($sp)
/*    4aa34:	27a40040 */ 	addiu	$a0,$sp,0x40
/*    4aa38:	0c0122c8 */ 	jal	func00048b20
/*    4aa3c:	01693823 */ 	subu	$a3,$t3,$t1
/*    4aa40:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4aa44:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aa48:	0c0121bc */ 	jal	osRecvMesg
/*    4aa4c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0004aa50:
/*    4aa50:	24180004 */ 	addiu	$t8,$zero,0x4
/*    4aa54:	3c01800a */ 	lui	$at,0x800a
/*    4aa58:	a038c821 */ 	sb	$t8,-0x37df($at)
/*    4aa5c:	0c012af0 */ 	jal	func0004abc0
/*    4aa60:	00002025 */ 	or	$a0,$zero,$zero
/*    4aa64:	3c05800a */ 	lui	$a1,%hi(var8009c7e0)
/*    4aa68:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(var8009c7e0)
/*    4aa6c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4aa70:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4aa74:	afa20068 */ 	sw	$v0,0x68($sp)
/*    4aa78:	8fa40070 */ 	lw	$a0,0x70($sp)
/*    4aa7c:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aa80:	0c0121bc */ 	jal	osRecvMesg
/*    4aa84:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aa88:	3c05800a */ 	lui	$a1,%hi(var8009c7e0)
/*    4aa8c:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(var8009c7e0)
/*    4aa90:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4aa94:	00002025 */ 	or	$a0,$zero,$zero
/*    4aa98:	afa20068 */ 	sw	$v0,0x68($sp)
/*    4aa9c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*    4aaa0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aaa4:	0c0121bc */ 	jal	osRecvMesg
/*    4aaa8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aaac:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    4aab0:	0c012abc */ 	jal	func0004aaf0
/*    4aab4:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    4aab8:	3c01800a */ 	lui	$at,0x800a
/*    4aabc:	0c012a04 */ 	jal	__osSiCreateAccessQueue
/*    4aac0:	a020c820 */ 	sb	$zero,-0x37e0($at)
/*    4aac4:	3c04800a */ 	lui	$a0,%hi(var8009c848)
/*    4aac8:	3c05800a */ 	lui	$a1,%hi(var8009c860)
/*    4aacc:	24a5c860 */ 	addiu	$a1,$a1,%lo(var8009c860)
/*    4aad0:	2484c848 */ 	addiu	$a0,$a0,%lo(var8009c848)
/*    4aad4:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4aad8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aadc:	8fa20068 */ 	lw	$v0,0x68($sp)
.L0004aae0:
/*    4aae0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4aae4:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*    4aae8:	03e00008 */ 	jr	$ra
/*    4aaec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004aaf0
/*    4aaf0:	3c0f800a */ 	lui	$t7,0x800a
/*    4aaf4:	91efc821 */ 	lbu	$t7,-0x37df($t7)
/*    4aaf8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4aafc:	3c0e800a */ 	lui	$t6,%hi(var8009c7e0)
/*    4ab00:	25cec7e0 */ 	addiu	$t6,$t6,%lo(var8009c7e0)
/*    4ab04:	a3a00007 */ 	sb	$zero,0x7($sp)
/*    4ab08:	afae0014 */ 	sw	$t6,0x14($sp)
/*    4ab0c:	19e00028 */ 	blez	$t7,.L0004abb0
/*    4ab10:	afa00008 */ 	sw	$zero,0x8($sp)
.L0004ab14:
/*    4ab14:	8fb90014 */ 	lw	$t9,0x14($sp)
/*    4ab18:	27b8000c */ 	addiu	$t8,$sp,0xc
/*    4ab1c:	8b210000 */ 	lwl	$at,0x0($t9)
/*    4ab20:	9b210003 */ 	lwr	$at,0x3($t9)
/*    4ab24:	af010000 */ 	sw	$at,0x0($t8)
/*    4ab28:	8b290004 */ 	lwl	$t1,0x4($t9)
/*    4ab2c:	9b290007 */ 	lwr	$t1,0x7($t9)
/*    4ab30:	af090004 */ 	sw	$t1,0x4($t8)
/*    4ab34:	93aa000e */ 	lbu	$t2,0xe($sp)
/*    4ab38:	314b00c0 */ 	andi	$t3,$t2,0xc0
/*    4ab3c:	000b6103 */ 	sra	$t4,$t3,0x4
/*    4ab40:	a0ac0003 */ 	sb	$t4,0x3($a1)
/*    4ab44:	90ad0003 */ 	lbu	$t5,0x3($a1)
/*    4ab48:	15a0000e */ 	bnez	$t5,.L0004ab84
/*    4ab4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ab50:	93ae0011 */ 	lbu	$t6,0x11($sp)
/*    4ab54:	93a80010 */ 	lbu	$t0,0x10($sp)
/*    4ab58:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    4ab5c:	000e7a00 */ 	sll	$t7,$t6,0x8
/*    4ab60:	01e8c025 */ 	or	$t8,$t7,$t0
/*    4ab64:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4ab68:	93b90012 */ 	lbu	$t9,0x12($sp)
/*    4ab6c:	a0b90002 */ 	sb	$t9,0x2($a1)
/*    4ab70:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    4ab74:	93a90007 */ 	lbu	$t1,0x7($sp)
/*    4ab78:	014b6004 */ 	sllv	$t4,$t3,$t2
/*    4ab7c:	012c6825 */ 	or	$t5,$t1,$t4
/*    4ab80:	a3ad0007 */ 	sb	$t5,0x7($sp)
.L0004ab84:
/*    4ab84:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    4ab88:	3c19800a */ 	lui	$t9,0x800a
/*    4ab8c:	9339c821 */ 	lbu	$t9,-0x37df($t9)
/*    4ab90:	8fa80014 */ 	lw	$t0,0x14($sp)
/*    4ab94:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    4ab98:	01f9082a */ 	slt	$at,$t7,$t9
/*    4ab9c:	25180008 */ 	addiu	$t8,$t0,0x8
/*    4aba0:	afb80014 */ 	sw	$t8,0x14($sp)
/*    4aba4:	afaf0008 */ 	sw	$t7,0x8($sp)
/*    4aba8:	1420ffda */ 	bnez	$at,.L0004ab14
/*    4abac:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0004abb0:
/*    4abb0:	93ab0007 */ 	lbu	$t3,0x7($sp)
/*    4abb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4abb8:	03e00008 */ 	jr	$ra
/*    4abbc:	a08b0000 */ 	sb	$t3,0x0($a0)
);

GLOBAL_ASM(
glabel func0004abc0
/*    4abc0:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4abc4:	308400ff */ 	andi	$a0,$a0,0xff
/*    4abc8:	afa00000 */ 	sw	$zero,0x0($sp)
.L0004abcc:
/*    4abcc:	8fae0000 */ 	lw	$t6,0x0($sp)
/*    4abd0:	8fb80000 */ 	lw	$t8,0x0($sp)
/*    4abd4:	3c01800a */ 	lui	$at,0x800a
/*    4abd8:	000e7880 */ 	sll	$t7,$t6,0x2
/*    4abdc:	002f0821 */ 	addu	$at,$at,$t7
/*    4abe0:	ac20c7e0 */ 	sw	$zero,-0x3820($at)
/*    4abe4:	27190001 */ 	addiu	$t9,$t8,0x1
/*    4abe8:	2b21000f */ 	slti	$at,$t9,0xf
/*    4abec:	1420fff7 */ 	bnez	$at,.L0004abcc
/*    4abf0:	afb90000 */ 	sw	$t9,0x0($sp)
/*    4abf4:	3c19800a */ 	lui	$t9,0x800a
/*    4abf8:	9339c821 */ 	lbu	$t9,-0x37df($t9)
/*    4abfc:	3c09800a */ 	lui	$t1,%hi(var8009c7e0)
/*    4ac00:	24080001 */ 	addiu	$t0,$zero,0x1
/*    4ac04:	3c01800a */ 	lui	$at,0x800a
/*    4ac08:	2529c7e0 */ 	addiu	$t1,$t1,%lo(var8009c7e0)
/*    4ac0c:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    4ac10:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    4ac14:	240c0003 */ 	addiu	$t4,$zero,0x3
/*    4ac18:	240d00ff */ 	addiu	$t5,$zero,0xff
/*    4ac1c:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4ac20:	240f00ff */ 	addiu	$t7,$zero,0xff
/*    4ac24:	241800ff */ 	addiu	$t8,$zero,0xff
/*    4ac28:	ac28c81c */ 	sw	$t0,-0x37e4($at)
/*    4ac2c:	afa9000c */ 	sw	$t1,0xc($sp)
/*    4ac30:	a3aa0004 */ 	sb	$t2,0x4($sp)
/*    4ac34:	a3ab0005 */ 	sb	$t3,0x5($sp)
/*    4ac38:	a3ac0006 */ 	sb	$t4,0x6($sp)
/*    4ac3c:	a3a40007 */ 	sb	$a0,0x7($sp)
/*    4ac40:	a3ad0008 */ 	sb	$t5,0x8($sp)
/*    4ac44:	a3ae0009 */ 	sb	$t6,0x9($sp)
/*    4ac48:	a3af000a */ 	sb	$t7,0xa($sp)
/*    4ac4c:	a3b8000b */ 	sb	$t8,0xb($sp)
/*    4ac50:	1b200013 */ 	blez	$t9,.L0004aca0
/*    4ac54:	afa00000 */ 	sw	$zero,0x0($sp)
.L0004ac58:
/*    4ac58:	27a90004 */ 	addiu	$t1,$sp,0x4
/*    4ac5c:	8d210000 */ 	lw	$at,0x0($t1)
/*    4ac60:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    4ac64:	3c18800a */ 	lui	$t8,0x800a
/*    4ac68:	a9010000 */ 	swl	$at,0x0($t0)
/*    4ac6c:	b9010003 */ 	swr	$at,0x3($t0)
/*    4ac70:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*    4ac74:	a90b0004 */ 	swl	$t3,0x4($t0)
/*    4ac78:	b90b0007 */ 	swr	$t3,0x7($t0)
/*    4ac7c:	8fae0000 */ 	lw	$t6,0x0($sp)
/*    4ac80:	9318c821 */ 	lbu	$t8,-0x37df($t8)
/*    4ac84:	8fac000c */ 	lw	$t4,0xc($sp)
/*    4ac88:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    4ac8c:	01f8082a */ 	slt	$at,$t7,$t8
/*    4ac90:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    4ac94:	afaf0000 */ 	sw	$t7,0x0($sp)
/*    4ac98:	1420ffef */ 	bnez	$at,.L0004ac58
/*    4ac9c:	afad000c */ 	sw	$t5,0xc($sp)
.L0004aca0:
/*    4aca0:	8faa000c */ 	lw	$t2,0xc($sp)
/*    4aca4:	241900fe */ 	addiu	$t9,$zero,0xfe
/*    4aca8:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    4acac:	03e00008 */ 	jr	$ra
/*    4acb0:	a1590000 */ 	sb	$t9,0x0($t2)
/*    4acb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4acb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4acbc:	00000000 */ 	sll	$zero,$zero,0x0
);