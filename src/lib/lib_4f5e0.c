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
#include "lib/lib_04790.h"
#include "lib/lib_16110.h"
#include "lib/lib_48650.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4b5e0.h"
#include "lib/lib_4cde0.h"
#include "lib/lib_4f5e0.h"
#include "lib/lib_51d50.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004f5e0
/*    4f5e0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4f5e4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f5e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f5ec:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    4f5f0:	8c990000 */ 	lw	$t9,0x0($a0)
/*    4f5f4:	3c18800a */ 	lui	$t8,%hi(var8009c970)
/*    4f5f8:	2718c970 */ 	addiu	$t8,$t8,%lo(var8009c970)
/*    4f5fc:	000e7980 */ 	sll	$t7,$t6,0x6
/*    4f600:	33290008 */ 	andi	$t1,$t9,0x8
/*    4f604:	00808025 */ 	or	$s0,$a0,$zero
/*    4f608:	00a03825 */ 	or	$a3,$a1,$zero
/*    4f60c:	15200003 */ 	bnez	$t1,.L0004f61c
/*    4f610:	01f84021 */ 	addu	$t0,$t7,$t8
/*    4f614:	10000047 */ 	beqz	$zero,.L0004f734
/*    4f618:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004f61c:
/*    4f61c:	afa70034 */ 	sw	$a3,0x34($sp)
/*    4f620:	0c012a18 */ 	jal	__osSiGetAccess
/*    4f624:	afa80024 */ 	sw	$t0,0x24($sp)
/*    4f628:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    4f62c:	3c06800a */ 	lui	$a2,%hi(var8009c970)
/*    4f630:	24c6c970 */ 	addiu	$a2,$a2,%lo(var8009c970)
/*    4f634:	000b6180 */ 	sll	$t4,$t3,0x6
/*    4f638:	00cc6821 */ 	addu	$t5,$a2,$t4
/*    4f63c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4f640:	adaa003c */ 	sw	$t2,0x3c($t5)
/*    4f644:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4f648:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*    4f64c:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    4f650:	00001825 */ 	or	$v1,$zero,$zero
/*    4f654:	010e4021 */ 	addu	$t0,$t0,$t6
/*    4f658:	01001025 */ 	or	$v0,$t0,$zero
/*    4f65c:	24040020 */ 	addiu	$a0,$zero,0x20
.L0004f660:
/*    4f660:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4f664:	a0470007 */ 	sb	$a3,0x7($v0)
/*    4f668:	a0470008 */ 	sb	$a3,0x8($v0)
/*    4f66c:	a0470009 */ 	sb	$a3,0x9($v0)
/*    4f670:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4f674:	1464fffa */ 	bne	$v1,$a0,.L0004f660
/*    4f678:	a0470002 */ 	sb	$a3,0x2($v0)
/*    4f67c:	240f00fe */ 	addiu	$t7,$zero,0xfe
/*    4f680:	3c01800a */ 	lui	$at,%hi(var8009c820)
/*    4f684:	a02fc820 */ 	sb	$t7,%lo(var8009c820)($at)
/*    4f688:	8e180008 */ 	lw	$t8,0x8($s0)
/*    4f68c:	afa80024 */ 	sw	$t0,0x24($sp)
/*    4f690:	afa70034 */ 	sw	$a3,0x34($sp)
/*    4f694:	0018c980 */ 	sll	$t9,$t8,0x6
/*    4f698:	00d92821 */ 	addu	$a1,$a2,$t9
/*    4f69c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4f6a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4f6a4:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4f6a8:	00002825 */ 	or	$a1,$zero,$zero
/*    4f6ac:	0c0121bc */ 	jal	osRecvMesg
/*    4f6b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4f6b4:	8e090008 */ 	lw	$t1,0x8($s0)
/*    4f6b8:	3c0c800a */ 	lui	$t4,%hi(var8009c970)
/*    4f6bc:	258cc970 */ 	addiu	$t4,$t4,%lo(var8009c970)
/*    4f6c0:	00095980 */ 	sll	$t3,$t1,0x6
/*    4f6c4:	016c2821 */ 	addu	$a1,$t3,$t4
/*    4f6c8:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4f6cc:	00002025 */ 	or	$a0,$zero,$zero
/*    4f6d0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4f6d4:	00002825 */ 	or	$a1,$zero,$zero
/*    4f6d8:	0c0121bc */ 	jal	osRecvMesg
/*    4f6dc:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4f6e0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4f6e4:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    4f6e8:	91100002 */ 	lbu	$s0,0x2($t0)
/*    4f6ec:	320a00c0 */ 	andi	$t2,$s0,0xc0
/*    4f6f0:	1540000d */ 	bnez	$t2,.L0004f728
/*    4f6f4:	01408025 */ 	or	$s0,$t2,$zero
/*    4f6f8:	54e00007 */ 	bnezl	$a3,.L0004f718
/*    4f6fc:	910e0026 */ 	lbu	$t6,0x26($t0)
/*    4f700:	910d0026 */ 	lbu	$t5,0x26($t0)
/*    4f704:	11a00008 */ 	beqz	$t5,.L0004f728
/*    4f708:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f70c:	10000006 */ 	beqz	$zero,.L0004f728
/*    4f710:	24100004 */ 	addiu	$s0,$zero,0x4
/*    4f714:	910e0026 */ 	lbu	$t6,0x26($t0)
.L0004f718:
/*    4f718:	240100eb */ 	addiu	$at,$zero,0xeb
/*    4f71c:	11c10002 */ 	beq	$t6,$at,.L0004f728
/*    4f720:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f724:	24100004 */ 	addiu	$s0,$zero,0x4
.L0004f728:
/*    4f728:	0c012a29 */ 	jal	__osSiRelAccess
/*    4f72c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f730:	02001025 */ 	or	$v0,$s0,$zero
.L0004f734:
/*    4f734:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4f738:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4f73c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4f740:	03e00008 */ 	jr	$ra
/*    4f744:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004f748
/*    4f748:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    4f74c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4f750:	00803025 */ 	or	$a2,$a0,$zero
/*    4f754:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4f758:	240f0023 */ 	addiu	$t7,$zero,0x23
/*    4f75c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4f760:	24190003 */ 	addiu	$t9,$zero,0x3
/*    4f764:	240800c0 */ 	addiu	$t0,$zero,0xc0
/*    4f768:	a3ae0024 */ 	sb	$t6,0x24($sp)
/*    4f76c:	a3af0025 */ 	sb	$t7,0x25($sp)
/*    4f770:	a3b80026 */ 	sb	$t8,0x26($sp)
/*    4f774:	a3b90027 */ 	sb	$t9,0x27($sp)
/*    4f778:	a3a80028 */ 	sb	$t0,0x28($sp)
/*    4f77c:	afa60050 */ 	sw	$a2,0x50($sp)
/*    4f780:	24040600 */ 	addiu	$a0,$zero,0x600
/*    4f784:	0c014754 */ 	jal	func00051d50
/*    4f788:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    4f78c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*    4f790:	3449c000 */ 	ori	$t1,$v0,0xc000
/*    4f794:	a3a90029 */ 	sb	$t1,0x29($sp)
/*    4f798:	10c00012 */ 	beqz	$a2,.L0004f7e4
/*    4f79c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*    4f7a0:	18c00010 */ 	blez	$a2,.L0004f7e4
/*    4f7a4:	00001025 */ 	or	$v0,$zero,$zero
/*    4f7a8:	30c50003 */ 	andi	$a1,$a2,0x3
/*    4f7ac:	10a00006 */ 	beqz	$a1,.L0004f7c8
/*    4f7b0:	00a02025 */ 	or	$a0,$a1,$zero
.L0004f7b4:
/*    4f7b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4f7b8:	a0600000 */ 	sb	$zero,0x0($v1)
/*    4f7bc:	1482fffd */ 	bne	$a0,$v0,.L0004f7b4
/*    4f7c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4f7c4:	10460007 */ 	beq	$v0,$a2,.L0004f7e4
.L0004f7c8:
/*    4f7c8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4f7cc:	a0600001 */ 	sb	$zero,0x1($v1)
/*    4f7d0:	a0600002 */ 	sb	$zero,0x2($v1)
/*    4f7d4:	a0600003 */ 	sb	$zero,0x3($v1)
/*    4f7d8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4f7dc:	1446fffa */ 	bne	$v0,$a2,.L0004f7c8
/*    4f7e0:	a060fffc */ 	sb	$zero,-0x4($v1)
.L0004f7e4:
/*    4f7e4:	27aa0024 */ 	addiu	$t2,$sp,0x24
/*    4f7e8:	254c0024 */ 	addiu	$t4,$t2,0x24
/*    4f7ec:	00606825 */ 	or	$t5,$v1,$zero
.L0004f7f0:
/*    4f7f0:	8d410000 */ 	lw	$at,0x0($t2)
/*    4f7f4:	254a000c */ 	addiu	$t2,$t2,0xc
/*    4f7f8:	25ad000c */ 	addiu	$t5,$t5,0xc
/*    4f7fc:	a9a1fff4 */ 	swl	$at,-0xc($t5)
/*    4f800:	b9a1fff7 */ 	swr	$at,-0x9($t5)
/*    4f804:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*    4f808:	a9a1fff8 */ 	swl	$at,-0x8($t5)
/*    4f80c:	b9a1fffb */ 	swr	$at,-0x5($t5)
/*    4f810:	8d41fffc */ 	lw	$at,-0x4($t2)
/*    4f814:	a9a1fffc */ 	swl	$at,-0x4($t5)
/*    4f818:	154cfff5 */ 	bne	$t2,$t4,.L0004f7f0
/*    4f81c:	b9a1ffff */ 	swr	$at,-0x1($t5)
/*    4f820:	91410000 */ 	lbu	$at,0x0($t2)
/*    4f824:	240e00fe */ 	addiu	$t6,$zero,0xfe
/*    4f828:	24630027 */ 	addiu	$v1,$v1,0x27
/*    4f82c:	a1a10000 */ 	sb	$at,0x0($t5)
/*    4f830:	914c0001 */ 	lbu	$t4,0x1($t2)
/*    4f834:	a1ac0001 */ 	sb	$t4,0x1($t5)
/*    4f838:	91410002 */ 	lbu	$at,0x2($t2)
/*    4f83c:	a1a10002 */ 	sb	$at,0x2($t5)
/*    4f840:	a06e0000 */ 	sb	$t6,0x0($v1)
/*    4f844:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4f848:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*    4f84c:	03e00008 */ 	jr	$ra
/*    4f850:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004f854
/*    4f854:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    4f858:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f85c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f860:	afa40048 */ 	sw	$a0,0x48($sp)
/*    4f864:	afa60050 */ 	sw	$a2,0x50($sp)
/*    4f868:	aca40004 */ 	sw	$a0,0x4($a1)
/*    4f86c:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    4f870:	241800ff */ 	addiu	$t8,$zero,0xff
/*    4f874:	00a08025 */ 	or	$s0,$a1,$zero
/*    4f878:	a0b80065 */ 	sb	$t8,0x65($a1)
/*    4f87c:	aca00000 */ 	sw	$zero,0x0($a1)
/*    4f880:	00a02025 */ 	or	$a0,$a1,$zero
/*    4f884:	acaf0008 */ 	sw	$t7,0x8($a1)
/*    4f888:	0c013378 */ 	jal	func0004cde0
/*    4f88c:	240500fe */ 	addiu	$a1,$zero,0xfe
/*    4f890:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f894:	14410005 */ 	bne	$v0,$at,.L0004f8ac
/*    4f898:	00401825 */ 	or	$v1,$v0,$zero
/*    4f89c:	02002025 */ 	or	$a0,$s0,$zero
/*    4f8a0:	0c013378 */ 	jal	func0004cde0
/*    4f8a4:	24050080 */ 	addiu	$a1,$zero,0x80
/*    4f8a8:	00401825 */ 	or	$v1,$v0,$zero
.L0004f8ac:
/*    4f8ac:	10400003 */ 	beqz	$v0,.L0004f8bc
/*    4f8b0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    4f8b4:	10000039 */ 	beqz	$zero,.L0004f99c
/*    4f8b8:	00601025 */ 	or	$v0,$v1,$zero
.L0004f8bc:
/*    4f8bc:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    4f8c0:	24060400 */ 	addiu	$a2,$zero,0x400
/*    4f8c4:	0c012e18 */ 	jal	__osContRamRead
/*    4f8c8:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    4f8cc:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f8d0:	14410002 */ 	bne	$v0,$at,.L0004f8dc
/*    4f8d4:	00401825 */ 	or	$v1,$v0,$zero
/*    4f8d8:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f8dc:
/*    4f8dc:	10600003 */ 	beqz	$v1,.L0004f8ec
/*    4f8e0:	93b90043 */ 	lbu	$t9,0x43($sp)
/*    4f8e4:	1000002d */ 	beqz	$zero,.L0004f99c
/*    4f8e8:	00601025 */ 	or	$v0,$v1,$zero
.L0004f8ec:
/*    4f8ec:	240100fe */ 	addiu	$at,$zero,0xfe
/*    4f8f0:	17210003 */ 	bne	$t9,$at,.L0004f900
/*    4f8f4:	02002025 */ 	or	$a0,$s0,$zero
/*    4f8f8:	10000028 */ 	beqz	$zero,.L0004f99c
/*    4f8fc:	2402000b */ 	addiu	$v0,$zero,0xb
.L0004f900:
/*    4f900:	0c013378 */ 	jal	func0004cde0
/*    4f904:	24050080 */ 	addiu	$a1,$zero,0x80
/*    4f908:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f90c:	14410002 */ 	bne	$v0,$at,.L0004f918
/*    4f910:	00401825 */ 	or	$v1,$v0,$zero
/*    4f914:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f918:
/*    4f918:	10600003 */ 	beqz	$v1,.L0004f928
/*    4f91c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    4f920:	1000001e */ 	beqz	$zero,.L0004f99c
/*    4f924:	00601025 */ 	or	$v0,$v1,$zero
.L0004f928:
/*    4f928:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    4f92c:	24060400 */ 	addiu	$a2,$zero,0x400
/*    4f930:	0c012e18 */ 	jal	__osContRamRead
/*    4f934:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    4f938:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f93c:	14410002 */ 	bne	$v0,$at,.L0004f948
/*    4f940:	00401825 */ 	or	$v1,$v0,$zero
/*    4f944:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f948:
/*    4f948:	10600003 */ 	beqz	$v1,.L0004f958
/*    4f94c:	93a80043 */ 	lbu	$t0,0x43($sp)
/*    4f950:	10000012 */ 	beqz	$zero,.L0004f99c
/*    4f954:	00601025 */ 	or	$v0,$v1,$zero
.L0004f958:
/*    4f958:	24010080 */ 	addiu	$at,$zero,0x80
/*    4f95c:	51010004 */ 	beql	$t0,$at,.L0004f970
/*    4f960:	8e090000 */ 	lw	$t1,0x0($s0)
/*    4f964:	1000000d */ 	beqz	$zero,.L0004f99c
/*    4f968:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4f96c:	8e090000 */ 	lw	$t1,0x0($s0)
.L0004f970:
/*    4f970:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    4f974:	3c0d800a */ 	lui	$t5,%hi(var8009c970)
/*    4f978:	312a0008 */ 	andi	$t2,$t1,0x8
/*    4f97c:	15400004 */ 	bnez	$t2,.L0004f990
/*    4f980:	00046180 */ 	sll	$t4,$a0,0x6
/*    4f984:	25adc970 */ 	addiu	$t5,$t5,%lo(var8009c970)
/*    4f988:	0c013dd2 */ 	jal	func0004f748
/*    4f98c:	018d2821 */ 	addu	$a1,$t4,$t5
.L0004f990:
/*    4f990:	240e0008 */ 	addiu	$t6,$zero,0x8
/*    4f994:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*    4f998:	00001025 */ 	or	$v0,$zero,$zero
.L0004f99c:
/*    4f99c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4f9a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4f9a4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    4f9a8:	03e00008 */ 	jr	$ra
/*    4f9ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004f9b0
/*    4f9b0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4f9b4:	3c017006 */ 	lui	$at,0x7006
/*    4f9b8:	c4249fd0 */ 	lwc1	$f4,-0x6030($at)
/*    4f9bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f9c0:	00808025 */ 	or	$s0,$a0,$zero
/*    4f9c4:	3c01800a */ 	lui	$at,0x800a
/*    4f9c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f9cc:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4f9d0:	afa60038 */ 	sw	$a2,0x38($sp)
/*    4f9d4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    4f9d8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*    4f9dc:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    4f9e0:	27a40038 */ 	addiu	$a0,$sp,0x38
/*    4f9e4:	0c0011e4 */ 	jal	scaleTo1
/*    4f9e8:	e424ca70 */ 	swc1	$f4,-0x3590($at)
/*    4f9ec:	3c01800a */ 	lui	$at,0x800a
/*    4f9f0:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4f9f4:	c426ca70 */ 	lwc1	$f6,-0x3590($at)
/*    4f9f8:	46066302 */ 	mul.s	$f12,$f12,$f6
/*    4f9fc:	0c0068f7 */ 	jal	sinf
/*    4fa00:	e7ac0034 */ 	swc1	$f12,0x34($sp)
/*    4fa04:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4fa08:	0c0068f4 */ 	jal	cosf
/*    4fa0c:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*    4fa10:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*    4fa14:	c7b20040 */ 	lwc1	$f18,0x40($sp)
/*    4fa18:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*    4fa1c:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*    4fa20:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fa24:	46129282 */ 	mul.s	$f10,$f18,$f18
/*    4fa28:	0c012974 */ 	jal	sqrtf
/*    4fa2c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    4fa30:	02002025 */ 	or	$a0,$s0,$zero
/*    4fa34:	0c012918 */ 	jal	func0004a460
/*    4fa38:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*    4fa3c:	44806000 */ 	mtc1	$zero,$f12
/*    4fa40:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*    4fa44:	c7a20028 */ 	lwc1	$f2,0x28($sp)
/*    4fa48:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*    4fa4c:	460c7032 */ 	c.eq.s	$f14,$f12
/*    4fa50:	3c013f80 */ 	lui	$at,0x3f80
/*    4fa54:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fa58:	45030041 */ 	bc1tl	.L0004fb60
/*    4fa5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fa60:	44812000 */ 	mtc1	$at,$f4
/*    4fa64:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    4fa68:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*    4fa6c:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    4fa70:	460e2003 */ 	div.s	$f0,$f4,$f14
/*    4fa74:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    4fa78:	46003207 */ 	neg.s	$f8,$f6
/*    4fa7c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*    4fa80:	46045181 */ 	sub.s	$f6,$f10,$f4
/*    4fa84:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    4fa88:	e6080000 */ 	swc1	$f8,0x0($s0)
/*    4fa8c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    4fa90:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4fa94:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*    4fa98:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*    4fa9c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    4faa0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4faa4:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    4faa8:	46082181 */ 	sub.s	$f6,$f4,$f8
/*    4faac:	46003282 */ 	mul.s	$f10,$f6,$f0
/*    4fab0:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*    4fab4:	460e8182 */ 	mul.s	$f6,$f16,$f14
/*    4fab8:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    4fabc:	e60c0030 */ 	swc1	$f12,0x30($s0)
/*    4fac0:	460e1282 */ 	mul.s	$f10,$f2,$f14
/*    4fac4:	46002207 */ 	neg.s	$f8,$f4
/*    4fac8:	e6080020 */ 	swc1	$f8,0x20($s0)
/*    4facc:	e6060004 */ 	swc1	$f6,0x4($s0)
/*    4fad0:	e60a0014 */ 	swc1	$f10,0x14($s0)
/*    4fad4:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    4fad8:	e60c0034 */ 	swc1	$f12,0x34($s0)
/*    4fadc:	46002207 */ 	neg.s	$f8,$f4
/*    4fae0:	e6080024 */ 	swc1	$f8,0x24($s0)
/*    4fae4:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fae8:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4faec:	46068282 */ 	mul.s	$f10,$f16,$f6
/*    4faf0:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4faf4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*    4faf8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fafc:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb00:	46085101 */ 	sub.s	$f4,$f10,$f8
/*    4fb04:	46008287 */ 	neg.s	$f10,$f16
/*    4fb08:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    4fb0c:	e6060008 */ 	swc1	$f6,0x8($s0)
/*    4fb10:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*    4fb14:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fb18:	46085102 */ 	mul.s	$f4,$f10,$f8
/*    4fb1c:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*    4fb20:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb24:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fb28:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    4fb2c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    4fb30:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    4fb34:	44815000 */ 	mtc1	$at,$f10
/*    4fb38:	e6080018 */ 	swc1	$f8,0x18($s0)
/*    4fb3c:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4fb40:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*    4fb44:	e60c000c */ 	swc1	$f12,0xc($s0)
/*    4fb48:	46002187 */ 	neg.s	$f6,$f4
/*    4fb4c:	e60c001c */ 	swc1	$f12,0x1c($s0)
/*    4fb50:	e6060028 */ 	swc1	$f6,0x28($s0)
/*    4fb54:	e60c002c */ 	swc1	$f12,0x2c($s0)
/*    4fb58:	e60a003c */ 	swc1	$f10,0x3c($s0)
/*    4fb5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004fb60:
/*    4fb60:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4fb64:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4fb68:	03e00008 */ 	jr	$ra
/*    4fb6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fb70:	44856000 */ 	mtc1	$a1,$f12
/*    4fb74:	44867000 */ 	mtc1	$a2,$f14
/*    4fb78:	44878000 */ 	mtc1	$a3,$f16
/*    4fb7c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    4fb80:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*    4fb84:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4fb88:	afa40060 */ 	sw	$a0,0x60($sp)
/*    4fb8c:	44056000 */ 	mfc1	$a1,$f12
/*    4fb90:	44067000 */ 	mfc1	$a2,$f14
/*    4fb94:	44078000 */ 	mfc1	$a3,$f16
/*    4fb98:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fb9c:	0c013e6c */ 	jal	func0004f9b0
/*    4fba0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4fba4:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fba8:	0c0128d8 */ 	jal	func0004a360
/*    4fbac:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    4fbb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fbb4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    4fbb8:	03e00008 */ 	jr	$ra
/*    4fbbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004fbc0
/*    4fbc0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4fbc4:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4fbc8:	00802825 */ 	or	$a1,$a0,$zero
/*    4fbcc:	24a44000 */ 	addiu	$a0,$a1,0x4000
/*    4fbd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4fbd4:	308effff */ 	andi	$t6,$a0,0xffff
/*    4fbd8:	0c013efc */ 	jal	func0004fbf0
/*    4fbdc:	01c02025 */ 	or	$a0,$t6,$zero
/*    4fbe0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4fbe4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4fbe8:	03e00008 */ 	jr	$ra
/*    4fbec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004fbf0
/*    4fbf0:	308effff */ 	andi	$t6,$a0,0xffff
/*    4fbf4:	000e7902 */ 	srl	$t7,$t6,0x4
/*    4fbf8:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    4fbfc:	33190400 */ 	andi	$t9,$t8,0x400
/*    4fc00:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4fc04:	13200008 */ 	beqz	$t9,.L0004fc28
/*    4fc08:	03001025 */ 	or	$v0,$t8,$zero
/*    4fc0c:	330803ff */ 	andi	$t0,$t8,0x3ff
/*    4fc10:	00084840 */ 	sll	$t1,$t0,0x1
/*    4fc14:	00095023 */ 	negu	$t2,$t1
/*    4fc18:	3c038006 */ 	lui	$v1,%hi(var800611ec+0x2)
/*    4fc1c:	006a1821 */ 	addu	$v1,$v1,$t2
/*    4fc20:	10000006 */ 	beqz	$zero,.L0004fc3c
/*    4fc24:	846311ee */ 	lh	$v1,%lo(var800611ec+0x2)($v1)
.L0004fc28:
/*    4fc28:	304b03ff */ 	andi	$t3,$v0,0x3ff
/*    4fc2c:	000b6040 */ 	sll	$t4,$t3,0x1
/*    4fc30:	3c038006 */ 	lui	$v1,%hi(var800609f0)
/*    4fc34:	006c1821 */ 	addu	$v1,$v1,$t4
/*    4fc38:	846309f0 */ 	lh	$v1,%lo(var800609f0)($v1)
.L0004fc3c:
/*    4fc3c:	304d0800 */ 	andi	$t5,$v0,0x800
/*    4fc40:	11a00005 */ 	beqz	$t5,.L0004fc58
/*    4fc44:	00601025 */ 	or	$v0,$v1,$zero
/*    4fc48:	00031023 */ 	negu	$v0,$v1
/*    4fc4c:	00027400 */ 	sll	$t6,$v0,0x10
/*    4fc50:	03e00008 */ 	jr	$ra
/*    4fc54:	000e1403 */ 	sra	$v0,$t6,0x10
.L0004fc58:
/*    4fc58:	03e00008 */ 	jr	$ra
/*    4fc5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004fc60
/*    4fc60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4fc64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4fc68:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4fc6c:	afa60020 */ 	sw	$a2,0x20($sp)
/*    4fc70:	afa70024 */ 	sw	$a3,0x24($sp)
/*    4fc74:	0c012918 */ 	jal	func0004a460
/*    4fc78:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4fc7c:	c7a40020 */ 	lwc1	$f4,0x20($sp)
/*    4fc80:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*    4fc84:	3c014000 */ 	lui	$at,0x4000
/*    4fc88:	44814000 */ 	mtc1	$at,$f8
/*    4fc8c:	46062001 */ 	sub.s	$f0,$f4,$f6
/*    4fc90:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    4fc94:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*    4fc98:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*    4fc9c:	46004283 */ 	div.s	$f10,$f8,$f0
/*    4fca0:	c7b2002c */ 	lwc1	$f18,0x2c($sp)
/*    4fca4:	44813000 */ 	mtc1	$at,$f6
/*    4fca8:	3c01c000 */ 	lui	$at,0xc000
/*    4fcac:	46128301 */ 	sub.s	$f12,$f16,$f18
/*    4fcb0:	00001825 */ 	or	$v1,$zero,$zero
/*    4fcb4:	24040004 */ 	addiu	$a0,$zero,0x4
/*    4fcb8:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*    4fcbc:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    4fcc0:	44815000 */ 	mtc1	$at,$f10
/*    4fcc4:	3c013f80 */ 	lui	$at,0x3f80
/*    4fcc8:	46047081 */ 	sub.s	$f2,$f14,$f4
/*    4fccc:	460c5103 */ 	div.s	$f4,$f10,$f12
/*    4fcd0:	46023203 */ 	div.s	$f8,$f6,$f2
/*    4fcd4:	e4440028 */ 	swc1	$f4,0x28($v0)
/*    4fcd8:	e4480014 */ 	swc1	$f8,0x14($v0)
/*    4fcdc:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*    4fce0:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    4fce4:	46083280 */ 	add.s	$f10,$f6,$f8
/*    4fce8:	46005107 */ 	neg.s	$f4,$f10
/*    4fcec:	46002183 */ 	div.s	$f6,$f4,$f0
/*    4fcf0:	e4460030 */ 	swc1	$f6,0x30($v0)
/*    4fcf4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    4fcf8:	46087280 */ 	add.s	$f10,$f14,$f8
/*    4fcfc:	46128200 */ 	add.s	$f8,$f16,$f18
/*    4fd00:	46005107 */ 	neg.s	$f4,$f10
/*    4fd04:	46004287 */ 	neg.s	$f10,$f8
/*    4fd08:	46022183 */ 	div.s	$f6,$f4,$f2
/*    4fd0c:	460c5103 */ 	div.s	$f4,$f10,$f12
/*    4fd10:	e4460034 */ 	swc1	$f6,0x34($v0)
/*    4fd14:	44813000 */ 	mtc1	$at,$f6
/*    4fd18:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fd1c:	e446003c */ 	swc1	$f6,0x3c($v0)
/*    4fd20:	e4440038 */ 	swc1	$f4,0x38($v0)
/*    4fd24:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*    4fd28:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*    4fd2c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4fd30:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*    4fd34:	46004302 */ 	mul.s	$f12,$f8,$f0
/*    4fd38:	c44e0008 */ 	lwc1	$f14,0x8($v0)
/*    4fd3c:	10640010 */ 	beq	$v1,$a0,.L0004fd80
/*    4fd40:	c450000c */ 	lwc1	$f16,0xc($v0)
.L0004fd44:
/*    4fd44:	46009282 */ 	mul.s	$f10,$f18,$f0
/*    4fd48:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*    4fd4c:	c4520014 */ 	lwc1	$f18,0x14($v0)
/*    4fd50:	46007182 */ 	mul.s	$f6,$f14,$f0
/*    4fd54:	c44e0018 */ 	lwc1	$f14,0x18($v0)
/*    4fd58:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4fd5c:	46008102 */ 	mul.s	$f4,$f16,$f0
/*    4fd60:	c450001c */ 	lwc1	$f16,0x1c($v0)
/*    4fd64:	e44c0000 */ 	swc1	$f12,0x0($v0)
/*    4fd68:	46004302 */ 	mul.s	$f12,$f8,$f0
/*    4fd6c:	e44a0004 */ 	swc1	$f10,0x4($v0)
/*    4fd70:	e4460008 */ 	swc1	$f6,0x8($v0)
/*    4fd74:	24420010 */ 	addiu	$v0,$v0,0x10
/*    4fd78:	1464fff2 */ 	bne	$v1,$a0,.L0004fd44
/*    4fd7c:	e444fffc */ 	swc1	$f4,-0x4($v0)
.L0004fd80:
/*    4fd80:	46009282 */ 	mul.s	$f10,$f18,$f0
/*    4fd84:	24420010 */ 	addiu	$v0,$v0,0x10
/*    4fd88:	e44cfff0 */ 	swc1	$f12,-0x10($v0)
/*    4fd8c:	46007182 */ 	mul.s	$f6,$f14,$f0
/*    4fd90:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fd94:	46008102 */ 	mul.s	$f4,$f16,$f0
/*    4fd98:	e44afff4 */ 	swc1	$f10,-0xc($v0)
/*    4fd9c:	e446fff8 */ 	swc1	$f6,-0x8($v0)
/*    4fda0:	e444fffc */ 	swc1	$f4,-0x4($v0)
/*    4fda4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4fda8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4fdac:	03e00008 */ 	jr	$ra
/*    4fdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fdb4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    4fdb8:	44856000 */ 	mtc1	$a1,$f12
/*    4fdbc:	44867000 */ 	mtc1	$a2,$f14
/*    4fdc0:	44878000 */ 	mtc1	$a3,$f16
/*    4fdc4:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*    4fdc8:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*    4fdcc:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*    4fdd0:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    4fdd4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4fdd8:	afa40068 */ 	sw	$a0,0x68($sp)
/*    4fddc:	44056000 */ 	mfc1	$a1,$f12
/*    4fde0:	44067000 */ 	mfc1	$a2,$f14
/*    4fde4:	44078000 */ 	mfc1	$a3,$f16
/*    4fde8:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4fdec:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4fdf0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    4fdf4:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    4fdf8:	0c013f18 */ 	jal	func0004fc60
/*    4fdfc:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    4fe00:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4fe04:	0c0128d8 */ 	jal	func0004a360
/*    4fe08:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    4fe0c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4fe10:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    4fe14:	03e00008 */ 	jr	$ra
/*    4fe18:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fe1c:	00000000 */ 	sll	$zero,$zero,0x0
);
