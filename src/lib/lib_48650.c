#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_034f0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048650
/*    48650:	400c6000 */ 	mfc0	$t4,$12
/*    48654:	3182ff01 */ 	andi	$v0,$t4,0xff01
/*    48658:	3c088006 */ 	lui	$t0,%hi(var8005cf70)
/*    4865c:	2508cf70 */ 	addiu	$t0,$t0,%lo(var8005cf70)
/*    48660:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*    48664:	2401ffff */ 	addiu	$at,$zero,-1
/*    48668:	01614026 */ 	xor	$t0,$t3,$at
/*    4866c:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*    48670:	00481025 */ 	or	$v0,$v0,$t0
/*    48674:	3c0aa430 */ 	lui	$t2,0xa430
/*    48678:	8d4a000c */ 	lw	$t2,0xc($t2)
/*    4867c:	11400005 */ 	beqz	$t2,.L00048694
/*    48680:	000b4c02 */ 	srl	$t1,$t3,0x10
/*    48684:	2401ffff */ 	addiu	$at,$zero,-1
/*    48688:	01214826 */ 	xor	$t1,$t1,$at
/*    4868c:	3129003f */ 	andi	$t1,$t1,0x3f
/*    48690:	01495025 */ 	or	$t2,$t2,$t1
.L00048694:
/*    48694:	000a5400 */ 	sll	$t2,$t2,0x10
/*    48698:	004a1025 */ 	or	$v0,$v0,$t2
/*    4869c:	3c01003f */ 	lui	$at,0x3f
/*    486a0:	00814024 */ 	and	$t0,$a0,$at
/*    486a4:	010b4024 */ 	and	$t0,$t0,$t3
/*    486a8:	000843c2 */ 	srl	$t0,$t0,0xf
/*    486ac:	3c0a7006 */ 	lui	$t2,%hi(var70059e30)
/*    486b0:	01485021 */ 	addu	$t2,$t2,$t0
/*    486b4:	954a9e30 */ 	lhu	$t2,%lo(var70059e30)($t2)
/*    486b8:	3c01a430 */ 	lui	$at,0xa430
/*    486bc:	ac2a000c */ 	sw	$t2,0xc($at)
/*    486c0:	3088ff01 */ 	andi	$t0,$a0,0xff01
/*    486c4:	3169ff00 */ 	andi	$t1,$t3,0xff00
/*    486c8:	01094024 */ 	and	$t0,$t0,$t1
/*    486cc:	3c01ffff */ 	lui	$at,0xffff
/*    486d0:	342100ff */ 	ori	$at,$at,0xff
/*    486d4:	01816024 */ 	and	$t4,$t4,$at
/*    486d8:	01886025 */ 	or	$t4,$t4,$t0
/*    486dc:	408c6000 */ 	mtc0	$t4,$12
/*    486e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    486e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    486e8:	03e00008 */ 	jr	$ra
/*    486ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel osRecvMesg
/*    486f0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    486f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    486f8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    486fc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    48700:	afa60030 */ 	sw	$a2,0x30($sp)
/*    48704:	afb10018 */ 	sw	$s1,0x18($sp)
/*    48708:	0c01256c */ 	jal	__osDisableInt
/*    4870c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    48710:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    48714:	00408025 */ 	or	$s0,$v0,$zero
/*    48718:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    4871c:	15e00012 */ 	bnez	$t7,.L00048768
/*    48720:	00000000 */ 	sll	$zero,$zero,0x0
.L00048724:
/*    48724:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    48728:	17000005 */ 	bnez	$t8,.L00048740
/*    4872c:	00000000 */ 	sll	$zero,$zero,0x0
/*    48730:	0c012588 */ 	jal	__osRestoreInt
/*    48734:	02002025 */ 	or	$a0,$s0,$zero
/*    48738:	10000036 */ 	beqz	$zero,.L00048814
/*    4873c:	2402ffff */ 	addiu	$v0,$zero,-1
.L00048740:
/*    48740:	3c088006 */ 	lui	$t0,%hi(var80060940)
/*    48744:	8d080940 */ 	lw	$t0,%lo(var80060940)($t0)
/*    48748:	24190008 */ 	addiu	$t9,$zero,0x8
/*    4874c:	a5190010 */ 	sh	$t9,0x10($t0)
/*    48750:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    48754:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    48758:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    4875c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    48760:	1140fff0 */ 	beqz	$t2,.L00048724
/*    48764:	00000000 */ 	sll	$zero,$zero,0x0
.L00048768:
/*    48768:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    4876c:	11600008 */ 	beqz	$t3,.L00048790
/*    48770:	00000000 */ 	sll	$zero,$zero,0x0
/*    48774:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    48778:	8d8e000c */ 	lw	$t6,0xc($t4)
/*    4877c:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*    48780:	000e7880 */ 	sll	$t7,$t6,0x2
/*    48784:	01afc021 */ 	addu	$t8,$t5,$t7
/*    48788:	8f190000 */ 	lw	$t9,0x0($t8)
/*    4878c:	ad790000 */ 	sw	$t9,0x0($t3)
.L00048790:
/*    48790:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    48794:	8d09000c */ 	lw	$t1,0xc($t0)
/*    48798:	8d0c0010 */ 	lw	$t4,0x10($t0)
/*    4879c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    487a0:	014c001a */ 	div	$zero,$t2,$t4
/*    487a4:	00007010 */ 	mfhi	$t6
/*    487a8:	ad0e000c */ 	sw	$t6,0xc($t0)
/*    487ac:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    487b0:	15800002 */ 	bnez	$t4,.L000487bc
/*    487b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    487b8:	0007000d */ 	break	0x7
.L000487bc:
/*    487bc:	2401ffff */ 	addiu	$at,$zero,-1
/*    487c0:	15810004 */ 	bne	$t4,$at,.L000487d4
/*    487c4:	3c018000 */ 	lui	$at,0x8000
/*    487c8:	15410002 */ 	bne	$t2,$at,.L000487d4
/*    487cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    487d0:	0006000d */ 	break	0x6
.L000487d4:
/*    487d4:	8daf0008 */ 	lw	$t7,0x8($t5)
/*    487d8:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    487dc:	adb80008 */ 	sw	$t8,0x8($t5)
/*    487e0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    487e4:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*    487e8:	8d690000 */ 	lw	$t1,0x0($t3)
/*    487ec:	11200006 */ 	beqz	$t1,.L00048808
/*    487f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    487f4:	0c000f40 */ 	jal	__osPopThread
/*    487f8:	27240004 */ 	addiu	$a0,$t9,0x4
/*    487fc:	00408825 */ 	or	$s1,$v0,$zero
/*    48800:	0c01207c */ 	jal	osStartThread
/*    48804:	02202025 */ 	or	$a0,$s1,$zero
.L00048808:
/*    48808:	0c012588 */ 	jal	__osRestoreInt
/*    4880c:	02002025 */ 	or	$a0,$s0,$zero
/*    48810:	00001025 */ 	or	$v0,$zero,$zero
.L00048814:
/*    48814:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48818:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    4881c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    48820:	03e00008 */ 	jr	$ra
/*    48824:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48828:	00000000 */ 	sll	$zero,$zero,0x0
/*    4882c:	00000000 */ 	sll	$zero,$zero,0x0
);