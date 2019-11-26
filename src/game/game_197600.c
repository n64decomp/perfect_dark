#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/chr/chr.h"
#include "game/game_066310.h"
#include "game/game_097970.h"
#include "game/game_0b0420.h"
#include "game/game_0f09f0.h"
#include "game/game_11ecf0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "library/library_12dc0.h"

const u32 var7f1b8fd0[] = {0x48742400};
const u32 var7f1b8fd4[] = {0x3eb33333};
const u32 var7f1b8fd8[] = {0x7f197b34};
const u32 var7f1b8fdc[] = {0x7f197b24};
const u32 var7f1b8fe0[] = {0x7f197b6c};
const u32 var7f1b8fe4[] = {0x7f197ba8};
const u32 var7f1b8fe8[] = {0x7f197be4};
const u32 var7f1b8fec[] = {0x7f197be4};
const u32 var7f1b8ff0[] = {0x7f197be4};
const u32 var7f1b8ff4[] = {0x7f197be4};
const u32 var7f1b8ff8[] = {0x7f197be4};
const u32 var7f1b8ffc[] = {0x7f197be4};
const u32 var7f1b9000[] = {0x7f197be4};
const u32 var7f1b9004[] = {0x7f197be4};
const u32 var7f1b9008[] = {0x7f197be4};
const u32 var7f1b900c[] = {0x7f197b50};
const u32 var7f1b9010[] = {0x7f198508};
const u32 var7f1b9014[] = {0x7f198570};
const u32 var7f1b9018[] = {0x7f198588};
const u32 var7f1b901c[] = {0x7f1985a0};
const u32 var7f1b9020[] = {0x7f1985b8};
const u32 var7f1b9024[] = {0x7f198bd8};
const u32 var7f1b9028[] = {0x7f1985dc};
const u32 var7f1b902c[] = {0x7f198644};
const u32 var7f1b9030[] = {0x7f19865c};
const u32 var7f1b9034[] = {0x7f198bd8};
const u32 var7f1b9038[] = {0x7f198674};
const u32 var7f1b903c[] = {0x7f198698};
const u32 var7f1b9040[] = {0x7f1986bc};
const u32 var7f1b9044[] = {0x7f198730};
const u32 var7f1b9048[] = {0x7f198748};
const u32 var7f1b904c[] = {0x7f198bd8};
const u32 var7f1b9050[] = {0x7f198bd8};
const u32 var7f1b9054[] = {0x7f198760};
const u32 var7f1b9058[] = {0x7f198794};
const u32 var7f1b905c[] = {0x7f1987b8};
const u32 var7f1b9060[] = {0x7f198bd8};
const u32 var7f1b9064[] = {0x7f198bd8};
const u32 var7f1b9068[] = {0x7f1987d0};
const u32 var7f1b906c[] = {0x7f1987e8};
const u32 var7f1b9070[] = {0x7f19880c};
const u32 var7f1b9074[] = {0x7f198960};
const u32 var7f1b9078[] = {0x7f198978};
const u32 var7f1b907c[] = {0x7f198a04};
const u32 var7f1b9080[] = {0x7f198bd8};
const u32 var7f1b9084[] = {0x7f198bd8};
const u32 var7f1b9088[] = {0x7f198ba0};
const u32 var7f1b908c[] = {0x3991a2b4};
const u32 var7f1b9090[] = {0x3f666666};
const u32 var7f1b9094[] = {0x44bb8000};
const u32 var7f1b9098[] = {0x00000000};
const u32 var7f1b909c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f197600
/*  f197600:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f197604:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197608:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f19760c:	8c8802d4 */ 	lw	$t0,0x2d4($a0)
/*  f197610:	24010004 */ 	addiu	$at,$zero,0x4
/*  f197614:	00003825 */ 	or	$a3,$zero,$zero
/*  f197618:	810f0074 */ 	lb	$t7,0x74($t0)
/*  f19761c:	00004825 */ 	or	$t1,$zero,$zero
/*  f197620:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f197624:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f197628:	93190047 */ 	lbu	$t9,0x47($t8)
/*  f19762c:	57210004 */ 	bnel	$t9,$at,.L0f197640
/*  f197630:	8d05004c */ 	lw	$a1,0x4c($t0)
/*  f197634:	1000000d */ 	beqz	$zero,.L0f19766c
/*  f197638:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f19763c:	8d05004c */ 	lw	$a1,0x4c($t0)
.L0f197640:
/*  f197640:	8d040020 */ 	lw	$a0,0x20($t0)
/*  f197644:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f197648:	00055880 */ 	sll	$t3,$a1,0x2
/*  f19764c:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f197650:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197654:	0fc6638e */ 	jal	func0f198e38
/*  f197658:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f19765c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f197660:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f197664:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f197668:	00401825 */ 	or	$v1,$v0,$zero
.L0f19766c:
/*  f19766c:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f197670:	00037080 */ 	sll	$t6,$v1,0x2
/*  f197674:	24010032 */ 	addiu	$at,$zero,0x32
/*  f197678:	91a402a0 */ 	lbu	$a0,0x2a0($t5)
/*  f19767c:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f197680:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f197684:	1481003c */ 	bne	$a0,$at,.L0f197778
/*  f197688:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19768c:	8502000a */ 	lh	$v0,0xa($t0)
/*  f197690:	3c068008 */ 	lui	$a2,%hi(var80087e98)
/*  f197694:	24c67e98 */ 	addiu	$a2,$a2,%lo(var80087e98)
/*  f197698:	04400037 */ 	bltz	$v0,.L0f197778
/*  f19769c:	0102c021 */ 	addu	$t8,$t0,$v0
/*  f1976a0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1976a4:	3c0f800b */ 	lui	$t7,0x800b
/*  f1976a8:	85b9017e */ 	lh	$t9,0x17e($t5)
/*  f1976ac:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1976b0:	8defc4d0 */ 	lw	$t7,-0x3b30($t7)
/*  f1976b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1976b8:	9309016c */ 	lbu	$t1,0x16c($t8)
/*  f1976bc:	13210049 */ 	beq	$t9,$at,.L0f1977e4
/*  f1976c0:	8de7001c */ 	lw	$a3,0x1c($t7)
/*  f1976c4:	10600003 */ 	beqz	$v1,.L0f1976d4
/*  f1976c8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1976cc:	14610045 */ 	bne	$v1,$at,.L0f1977e4
/*  f1976d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1976d4:
/*  f1976d4:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f1976d8:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f1976dc:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f1976e0:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f1976e4:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f1976e8:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f1976ec:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1976f0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1976f4:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f1976f8:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f1976fc:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f197700:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f197704:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f197708:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f19770c:	c4f00010 */ 	lwc1	$f16,0x10($a3)
/*  f197710:	3c017f1c */ 	lui	$at,%hi(var7f1b8fd0)
/*  f197714:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f197718:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f19771c:	8fa30064 */ 	lw	$v1,0x64($sp)
/*  f197720:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f197724:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f197728:	c4328fd0 */ 	lwc1	$f18,%lo(var7f1b8fd0)($at)
/*  f19772c:	00035880 */ 	sll	$t3,$v1,0x2
/*  f197730:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f197734:	3c0c8008 */ 	lui	$t4,%hi(var80087e50)
/*  f197738:	01635823 */ 	subu	$t3,$t3,$v1
/*  f19773c:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f197740:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f197744:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f197748:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f19774c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f197750:	258c7e50 */ 	addiu	$t4,$t4,%lo(var80087e50)
/*  f197754:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f197758:	4612803c */ 	c.lt.s	$f16,$f18
/*  f19775c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197760:	45000020 */ 	bc1f	.L0f1977e4
/*  f197764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197768:	016c3021 */ 	addu	$a2,$t3,$t4
/*  f19776c:	00403825 */ 	or	$a3,$v0,$zero
/*  f197770:	1000001c */ 	beqz	$zero,.L0f1977e4
/*  f197774:	8d090128 */ 	lw	$t1,0x128($t0)
.L0f197778:
/*  f197778:	25ef7e50 */ 	addiu	$t7,$t7,0x7e50
/*  f19777c:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f197780:	1481000b */ 	bne	$a0,$at,.L0f1977b0
/*  f197784:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f197788:	85020008 */ 	lh	$v0,0x8($t0)
/*  f19778c:	3c0d800b */ 	lui	$t5,0x800b
/*  f197790:	04400007 */ 	bltz	$v0,.L0f1977b0
/*  f197794:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f197798:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f19779c:	8dadc4d0 */ 	lw	$t5,-0x3b30($t5)
/*  f1977a0:	0102c821 */ 	addu	$t9,$t0,$v0
/*  f1977a4:	9329016c */ 	lbu	$t1,0x16c($t9)
/*  f1977a8:	1000000e */ 	beqz	$zero,.L0f1977e4
/*  f1977ac:	8da7001c */ 	lw	$a3,0x1c($t5)
.L0f1977b0:
/*  f1977b0:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f1977b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1977b8:	856c017e */ 	lh	$t4,0x17e($t3)
/*  f1977bc:	01602025 */ 	or	$a0,$t3,$zero
/*  f1977c0:	11810008 */ 	beq	$t4,$at,.L0f1977e4
/*  f1977c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1977c8:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f1977cc:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f1977d0:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f1977d4:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f1977d8:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1977dc:	00403825 */ 	or	$a3,$v0,$zero
/*  f1977e0:	8d090128 */ 	lw	$t1,0x128($t0)
.L0f1977e4:
/*  f1977e4:	50e000c0 */ 	beqzl	$a3,.L0f197ae8
/*  f1977e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1977ec:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f1977f0:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1977f4:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f1977f8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f1977fc:	0fc64a92 */ 	jal	func0f192a48
/*  f197800:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f197804:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f197808:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f19780c:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f197810:	104000b4 */ 	beqz	$v0,.L0f197ae4
/*  f197814:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f197818:	24e50008 */ 	addiu	$a1,$a3,0x8
/*  f19781c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f197820:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f197824:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f197828:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f19782c:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197830:	0fc1250e */ 	jal	chrGetDistanceToCoord
/*  f197834:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f197838:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f19783c:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f197840:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f197844:	8dcf02d4 */ 	lw	$t7,0x2d4($t6)
/*  f197848:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f19784c:	c4cc0004 */ 	lwc1	$f12,0x4($a2)
/*  f197850:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f197854:	c4ce0008 */ 	lwc1	$f14,0x8($a2)
/*  f197858:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f19785c:	93020048 */ 	lbu	$v0,0x48($t8)
/*  f197860:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f197864:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f197868:	14400007 */ 	bnez	$v0,.L0f197888
/*  f19786c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f197870:	3c017f1c */ 	lui	$at,%hi(var7f1b8fd4)
/*  f197874:	c4248fd4 */ 	lwc1	$f4,%lo(var7f1b8fd4)($at)
/*  f197878:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19787c:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f197880:	10000008 */ 	beqz	$zero,.L0f1978a4
/*  f197884:	81020074 */ 	lb	$v0,0x74($t0)
.L0f197888:
/*  f197888:	14c20005 */ 	bne	$a2,$v0,.L0f1978a0
/*  f19788c:	3c013f00 */ 	lui	$at,0x3f00
/*  f197890:	44813000 */ 	mtc1	$at,$f6
/*  f197894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197898:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f19789c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1978a0:
/*  f1978a0:	81020074 */ 	lb	$v0,0x74($t0)
.L0f1978a4:
/*  f1978a4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1978a8:	14c20005 */ 	bne	$a2,$v0,.L0f1978c0
/*  f1978ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1978b0:	3c0141c8 */ 	lui	$at,0x41c8
/*  f1978b4:	44814000 */ 	mtc1	$at,$f8
/*  f1978b8:	10000008 */ 	beqz	$zero,.L0f1978dc
/*  f1978bc:	46081080 */ 	add.s	$f2,$f2,$f8
.L0f1978c0:
/*  f1978c0:	10410002 */ 	beq	$v0,$at,.L0f1978cc
/*  f1978c4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1978c8:	14410004 */ 	bne	$v0,$at,.L0f1978dc
.L0f1978cc:
/*  f1978cc:	3c0141c8 */ 	lui	$at,0x41c8
/*  f1978d0:	44815000 */ 	mtc1	$at,$f10
/*  f1978d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1978d8:	460a6301 */ 	sub.s	$f12,$f12,$f10
.L0f1978dc:
/*  f1978dc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1978e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1978e4:	45020004 */ 	bc1fl	.L0f1978f8
/*  f1978e8:	4600103e */ 	c.le.s	$f2,$f0
/*  f1978ec:	10000015 */ 	beqz	$zero,.L0f197944
/*  f1978f0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1978f4:	4600103e */ 	c.le.s	$f2,$f0
.L0f1978f8:
/*  f1978f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1978fc:	45020008 */ 	bc1fl	.L0f197920
/*  f197900:	4600603e */ 	c.le.s	$f12,$f0
/*  f197904:	460c003c */ 	c.lt.s	$f0,$f12
/*  f197908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19790c:	45020004 */ 	bc1fl	.L0f197920
/*  f197910:	4600603e */ 	c.le.s	$f12,$f0
/*  f197914:	1000000b */ 	beqz	$zero,.L0f197944
/*  f197918:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f19791c:	4600603e */ 	c.le.s	$f12,$f0
.L0f197920:
/*  f197920:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f197924:	45000007 */ 	bc1f	.L0f197944
/*  f197928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19792c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f197930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197934:	45000003 */ 	bc1f	.L0f197944
/*  f197938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19793c:	10000001 */ 	beqz	$zero,.L0f197944
/*  f197940:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f197944:
/*  f197944:	14c20006 */ 	bne	$a2,$v0,.L0f197960
/*  f197948:	00401825 */ 	or	$v1,$v0,$zero
/*  f19794c:	51200005 */ 	beqzl	$t1,.L0f197964
/*  f197950:	ad000050 */ 	sw	$zero,0x50($t0)
/*  f197954:	8d0d0050 */ 	lw	$t5,0x50($t0)
/*  f197958:	10ed0003 */ 	beq	$a3,$t5,.L0f197968
/*  f19795c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197960:
/*  f197960:	ad000050 */ 	sw	$zero,0x50($t0)
.L0f197964:
/*  f197964:	a100009d */ 	sb	$zero,0x9d($t0)
.L0f197968:
/*  f197968:	15430005 */ 	bne	$t2,$v1,.L0f197980
/*  f19796c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197970:	55200025 */ 	bnezl	$t1,.L0f197a08
/*  f197974:	8d0200d0 */ 	lw	$v0,0xd0($t0)
/*  f197978:	10000022 */ 	beqz	$zero,.L0f197a04
/*  f19797c:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f197980:
/*  f197980:	54c30021 */ 	bnel	$a2,$v1,.L0f197a08
/*  f197984:	8d0200d0 */ 	lw	$v0,0xd0($t0)
/*  f197988:	55200011 */ 	bnezl	$t1,.L0f1979d0
/*  f19798c:	8d0b0050 */ 	lw	$t3,0x50($t0)
/*  f197990:	ad070050 */ 	sw	$a3,0x50($t0)
/*  f197994:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197998:	0c004b70 */ 	jal	random
/*  f19799c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f1979a0:	24010078 */ 	addiu	$at,$zero,0x78
/*  f1979a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1979a8:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f1979ac:	0000c810 */ 	mfhi	$t9
/*  f1979b0:	272c0014 */ 	addiu	$t4,$t9,0x14
/*  f1979b4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1979b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1979bc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1979c0:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f1979c4:	1000000f */ 	beqz	$zero,.L0f197a04
/*  f1979c8:	a10c009d */ 	sb	$t4,0x9d($t0)
/*  f1979cc:	8d0b0050 */ 	lw	$t3,0x50($t0)
.L0f1979d0:
/*  f1979d0:	3c04800a */ 	lui	$a0,0x800a
/*  f1979d4:	5160000c */ 	beqzl	$t3,.L0f197a08
/*  f1979d8:	8d0200d0 */ 	lw	$v0,0xd0($t0)
/*  f1979dc:	8c849ff8 */ 	lw	$a0,-0x6008($a0)
/*  f1979e0:	9105009d */ 	lbu	$a1,0x9d($t0)
/*  f1979e4:	0085082a */ 	slt	$at,$a0,$a1
/*  f1979e8:	10200004 */ 	beqz	$at,.L0f1979fc
/*  f1979ec:	00a47023 */ 	subu	$t6,$a1,$a0
/*  f1979f0:	a10e009d */ 	sb	$t6,0x9d($t0)
/*  f1979f4:	10000003 */ 	beqz	$zero,.L0f197a04
/*  f1979f8:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f1979fc:
/*  f1979fc:	ad000050 */ 	sw	$zero,0x50($t0)
/*  f197a00:	a100009d */ 	sb	$zero,0x9d($t0)
.L0f197a04:
/*  f197a04:	8d0200d0 */ 	lw	$v0,0xd0($t0)
.L0f197a08:
/*  f197a08:	a1030074 */ 	sb	$v1,0x74($t0)
/*  f197a0c:	3c0f800a */ 	lui	$t7,0x800a
/*  f197a10:	04420005 */ 	bltzl	$v0,.L0f197a28
/*  f197a14:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f197a18:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f197a1c:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f197a20:	ad1800d0 */ 	sw	$t8,0xd0($t0)
/*  f197a24:	8fad0050 */ 	lw	$t5,0x50($sp)
.L0f197a28:
/*  f197a28:	15a30009 */ 	bne	$t5,$v1,.L0f197a50
/*  f197a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197a30:	1143002c */ 	beq	$t2,$v1,.L0f197ae4
/*  f197a34:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f197a38:	832c0007 */ 	lb	$t4,0x7($t9)
/*  f197a3c:	10cc0004 */ 	beq	$a2,$t4,.L0f197a50
/*  f197a40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197a44:	8d0b00d0 */ 	lw	$t3,0xd0($t0)
/*  f197a48:	5d600027 */ 	bgtzl	$t3,.L0f197ae8
/*  f197a4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f197a50:
/*  f197a50:	10c3000b */ 	beq	$a2,$v1,.L0f197a80
/*  f197a54:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f197a58:	106a0011 */ 	beq	$v1,$t2,.L0f197aa0
/*  f197a5c:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f197a60:	24010003 */ 	addiu	$at,$zero,0x3
/*  f197a64:	10610012 */ 	beq	$v1,$at,.L0f197ab0
/*  f197a68:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f197a6c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f197a70:	10610015 */ 	beq	$v1,$at,.L0f197ac8
/*  f197a74:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f197a78:	10000019 */ 	beqz	$zero,.L0f197ae0
/*  f197a7c:	240e003c */ 	addiu	$t6,$zero,0x3c
.L0f197a80:
/*  f197a80:	3c06461c */ 	lui	$a2,0x461c
/*  f197a84:	34c64000 */ 	ori	$a2,$a2,0x4000
/*  f197a88:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f197a8c:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f197a90:	0fc130ba */ 	jal	func0f04c2e8
/*  f197a94:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197a98:	10000010 */ 	beqz	$zero,.L0f197adc
/*  f197a9c:	8fa80054 */ 	lw	$t0,0x54($sp)
.L0f197aa0:
/*  f197aa0:	0fc0eb63 */ 	jal	func0f03ad8c
/*  f197aa4:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197aa8:	1000000c */ 	beqz	$zero,.L0f197adc
/*  f197aac:	8fa80054 */ 	lw	$t0,0x54($sp)
.L0f197ab0:
/*  f197ab0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f197ab4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f197ab8:	0fc0eadd */ 	jal	func0f03ab74
/*  f197abc:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197ac0:	10000006 */ 	beqz	$zero,.L0f197adc
/*  f197ac4:	8fa80054 */ 	lw	$t0,0x54($sp)
.L0f197ac8:
/*  f197ac8:	00e02825 */ 	or	$a1,$a3,$zero
/*  f197acc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f197ad0:	0fc0eadd */ 	jal	func0f03ab74
/*  f197ad4:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f197ad8:	8fa80054 */ 	lw	$t0,0x54($sp)
.L0f197adc:
/*  f197adc:	240e003c */ 	addiu	$t6,$zero,0x3c
.L0f197ae0:
/*  f197ae0:	ad0e00d0 */ 	sw	$t6,0xd0($t0)
.L0f197ae4:
/*  f197ae4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f197ae8:
/*  f197ae8:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f197aec:	03e00008 */ 	jr	$ra
/*  f197af0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197af4
/*  f197af4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f197af8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f197afc:	2ca1000e */ 	sltiu	$at,$a1,0xe
/*  f197b00:	00808025 */ 	or	$s0,$a0,$zero
/*  f197b04:	10200037 */ 	beqz	$at,.L0f197be4
/*  f197b08:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f197b0c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f197b10:	3c017f1c */ 	lui	$at,%hi(var7f1b8fd8)
/*  f197b14:	002e0821 */ 	addu	$at,$at,$t6
/*  f197b18:	8c2e8fd8 */ 	lw	$t6,%lo(var7f1b8fd8)($at)
/*  f197b1c:	01c00008 */ 	jr	$t6
/*  f197b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197b24:	0fc3f598 */ 	jal	func0f0fd660
/*  f197b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197b2c:	10000030 */ 	beqz	$zero,.L0f197bf0
/*  f197b30:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f197b34:	3c0f800a */ 	lui	$t7,0x800a
/*  f197b38:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f197b3c:	02002025 */ 	or	$a0,$s0,$zero
/*  f197b40:	0fc6491d */ 	jal	func0f192474
/*  f197b44:	8de500bc */ 	lw	$a1,0xbc($t7)
/*  f197b48:	10000029 */ 	beqz	$zero,.L0f197bf0
/*  f197b4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f197b50:	3c18800a */ 	lui	$t8,0x800a
/*  f197b54:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f197b58:	02002025 */ 	or	$a0,$s0,$zero
/*  f197b5c:	0fc6492b */ 	jal	func0f1924ac
/*  f197b60:	8f0500bc */ 	lw	$a1,0xbc($t8)
/*  f197b64:	10000022 */ 	beqz	$zero,.L0f197bf0
/*  f197b68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f197b6c:	3c19800a */ 	lui	$t9,0x800a
/*  f197b70:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f197b74:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f197b78:	0fc0f917 */ 	jal	func0f03e45c
/*  f197b7c:	8d040004 */ 	lw	$a0,0x4($t0)
/*  f197b80:	3c09800a */ 	lui	$t1,0x800a
/*  f197b84:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f197b88:	44070000 */ 	mfc1	$a3,$f0
/*  f197b8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f197b90:	8d2200bc */ 	lw	$v0,0xbc($t1)
/*  f197b94:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f197b98:	0fc6493a */ 	jal	func0f1924e8
/*  f197b9c:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f197ba0:	10000013 */ 	beqz	$zero,.L0f197bf0
/*  f197ba4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f197ba8:	3c0a800a */ 	lui	$t2,0x800a
/*  f197bac:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f197bb0:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f197bb4:	0fc0f917 */ 	jal	func0f03e45c
/*  f197bb8:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f197bbc:	3c0c800a */ 	lui	$t4,0x800a
/*  f197bc0:	8d8ca244 */ 	lw	$t4,-0x5dbc($t4)
/*  f197bc4:	44070000 */ 	mfc1	$a3,$f0
/*  f197bc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f197bcc:	8d8200bc */ 	lw	$v0,0xbc($t4)
/*  f197bd0:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f197bd4:	0fc6495f */ 	jal	func0f19257c
/*  f197bd8:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f197bdc:	10000004 */ 	beqz	$zero,.L0f197bf0
/*  f197be0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f197be4:
/*  f197be4:	0fc64984 */ 	jal	func0f192610
/*  f197be8:	02002025 */ 	or	$a0,$s0,$zero
/*  f197bec:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f197bf0:
/*  f197bf0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f197bf4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f197bf8:	03e00008 */ 	jr	$ra
/*  f197bfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197c00
/*  f197c00:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197c04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197c08:	10800015 */ 	beqz	$a0,.L0f197c60
/*  f197c0c:	00803025 */ 	or	$a2,$a0,$zero
/*  f197c10:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f197c14:	50400013 */ 	beqzl	$v0,.L0f197c64
/*  f197c18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197c1c:	804e0018 */ 	lb	$t6,0x18($v0)
/*  f197c20:	00001825 */ 	or	$v1,$zero,$zero
/*  f197c24:	00002025 */ 	or	$a0,$zero,$zero
/*  f197c28:	19c0000b */ 	blez	$t6,.L0f197c58
/*  f197c2c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f197c30:	8c4f0014 */ 	lw	$t7,0x14($v0)
.L0f197c34:
/*  f197c34:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f197c38:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f197c3c:	af050000 */ 	sw	$a1,0x0($t8)
/*  f197c40:	8cc202d4 */ 	lw	$v0,0x2d4($a2)
/*  f197c44:	24840014 */ 	addiu	$a0,$a0,0x14
/*  f197c48:	80590018 */ 	lb	$t9,0x18($v0)
/*  f197c4c:	0079082a */ 	slt	$at,$v1,$t9
/*  f197c50:	5420fff8 */ 	bnezl	$at,.L0f197c34
/*  f197c54:	8c4f0014 */ 	lw	$t7,0x14($v0)
.L0f197c58:
/*  f197c58:	0fc47bba */ 	jal	dprint
/*  f197c5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197c60:
/*  f197c60:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f197c64:
/*  f197c64:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f197c68:	03e00008 */ 	jr	$ra
/*  f197c6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197c70
/*  f197c70:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197c74:	10800004 */ 	beqz	$a0,.L0f197c88
/*  f197c78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197c7c:	8c8602d4 */ 	lw	$a2,0x2d4($a0)
/*  f197c80:	54c00004 */ 	bnezl	$a2,.L0f197c94
/*  f197c84:	80c50018 */ 	lb	$a1,0x18($a2)
.L0f197c88:
/*  f197c88:	10000015 */ 	beqz	$zero,.L0f197ce0
/*  f197c8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f197c90:	80c50018 */ 	lb	$a1,0x18($a2)
.L0f197c94:
/*  f197c94:	00001025 */ 	or	$v0,$zero,$zero
/*  f197c98:	18a0000e */ 	blez	$a1,.L0f197cd4
/*  f197c9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197ca0:	8cc70014 */ 	lw	$a3,0x14($a2)
/*  f197ca4:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f197ca8:	00002025 */ 	or	$a0,$zero,$zero
/*  f197cac:	00e01825 */ 	or	$v1,$a3,$zero
.L0f197cb0:
/*  f197cb0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f197cb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f197cb8:	0045082a */ 	slt	$at,$v0,$a1
/*  f197cbc:	14ce0003 */ 	bne	$a2,$t6,.L0f197ccc
/*  f197cc0:	24630014 */ 	addiu	$v1,$v1,0x14
/*  f197cc4:	10000006 */ 	beqz	$zero,.L0f197ce0
/*  f197cc8:	00e41021 */ 	addu	$v0,$a3,$a0
.L0f197ccc:
/*  f197ccc:	1420fff8 */ 	bnez	$at,.L0f197cb0
/*  f197cd0:	24840014 */ 	addiu	$a0,$a0,0x14
.L0f197cd4:
/*  f197cd4:	0fc47bba */ 	jal	dprint
/*  f197cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197cdc:	00001025 */ 	or	$v0,$zero,$zero
.L0f197ce0:
/*  f197ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197ce4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f197ce8:	03e00008 */ 	jr	$ra
/*  f197cec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197cf0
/*  f197cf0:	10800004 */ 	beqz	$a0,.L0f197d04
/*  f197cf4:	00a03825 */ 	or	$a3,$a1,$zero
/*  f197cf8:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f197cfc:	54400004 */ 	bnezl	$v0,.L0f197d10
/*  f197d00:	80440018 */ 	lb	$a0,0x18($v0)
.L0f197d04:
/*  f197d04:	03e00008 */ 	jr	$ra
/*  f197d08:	00001025 */ 	or	$v0,$zero,$zero
/*  f197d0c:	80440018 */ 	lb	$a0,0x18($v0)
.L0f197d10:
/*  f197d10:	00002825 */ 	or	$a1,$zero,$zero
/*  f197d14:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f197d18:	1880001b */ 	blez	$a0,.L0f197d88
/*  f197d1c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f197d20:	8c460014 */ 	lw	$a2,0x14($v0)
/*  f197d24:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f197d28:
/*  f197d28:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f197d2c:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f197d30:	00c01825 */ 	or	$v1,$a2,$zero
/*  f197d34:	15020005 */ 	bne	$t0,$v0,.L0f197d4c
/*  f197d38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197d3c:	00041080 */ 	sll	$v0,$a0,0x2
/*  f197d40:	00441021 */ 	addu	$v0,$v0,$a0
/*  f197d44:	1000000d */ 	beqz	$zero,.L0f197d7c
/*  f197d48:	00021080 */ 	sll	$v0,$v0,0x2
.L0f197d4c:
/*  f197d4c:	51220004 */ 	beql	$t1,$v0,.L0f197d60
/*  f197d50:	846e0004 */ 	lh	$t6,0x4($v1)
/*  f197d54:	55420007 */ 	bnel	$t2,$v0,.L0f197d74
/*  f197d58:	00041080 */ 	sll	$v0,$a0,0x2
/*  f197d5c:	846e0004 */ 	lh	$t6,0x4($v1)
.L0f197d60:
/*  f197d60:	54ee0004 */ 	bnel	$a3,$t6,.L0f197d74
/*  f197d64:	00041080 */ 	sll	$v0,$a0,0x2
/*  f197d68:	03e00008 */ 	jr	$ra
/*  f197d6c:	00601025 */ 	or	$v0,$v1,$zero
/*  f197d70:	00041080 */ 	sll	$v0,$a0,0x2
.L0f197d74:
/*  f197d74:	00441021 */ 	addu	$v0,$v0,$a0
/*  f197d78:	00021080 */ 	sll	$v0,$v0,0x2
.L0f197d7c:
/*  f197d7c:	00a2082a */ 	slt	$at,$a1,$v0
/*  f197d80:	1420ffe9 */ 	bnez	$at,.L0f197d28
/*  f197d84:	24c60014 */ 	addiu	$a2,$a2,0x14
.L0f197d88:
/*  f197d88:	00001025 */ 	or	$v0,$zero,$zero
/*  f197d8c:	03e00008 */ 	jr	$ra
/*  f197d90:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197d94
/*  f197d94:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f197d98:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f197d9c:	10800025 */ 	beqz	$a0,.L0f197e34
/*  f197da0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f197da4:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f197da8:	50400023 */ 	beqzl	$v0,.L0f197e38
/*  f197dac:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f197db0:	80440018 */ 	lb	$a0,0x18($v0)
/*  f197db4:	00002825 */ 	or	$a1,$zero,$zero
/*  f197db8:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f197dbc:	5880001e */ 	blezl	$a0,.L0f197e38
/*  f197dc0:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f197dc4:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f197dc8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f197dcc:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f197dd0:	00603025 */ 	or	$a2,$v1,$zero
.L0f197dd4:
/*  f197dd4:	8cc70000 */ 	lw	$a3,0x0($a2)
/*  f197dd8:	00c01025 */ 	or	$v0,$a2,$zero
/*  f197ddc:	15070005 */ 	bne	$t0,$a3,.L0f197df4
/*  f197de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197de4:	00041080 */ 	sll	$v0,$a0,0x2
/*  f197de8:	00441021 */ 	addu	$v0,$v0,$a0
/*  f197dec:	1000000d */ 	beqz	$zero,.L0f197e24
/*  f197df0:	00021080 */ 	sll	$v0,$v0,0x2
.L0f197df4:
/*  f197df4:	51270004 */ 	beql	$t1,$a3,.L0f197e08
/*  f197df8:	844e0004 */ 	lh	$t6,0x4($v0)
/*  f197dfc:	55470007 */ 	bnel	$t2,$a3,.L0f197e1c
/*  f197e00:	00041080 */ 	sll	$v0,$a0,0x2
/*  f197e04:	844e0004 */ 	lh	$t6,0x4($v0)
.L0f197e08:
/*  f197e08:	160e0003 */ 	bne	$s0,$t6,.L0f197e18
/*  f197e0c:	00657821 */ 	addu	$t7,$v1,$a1
/*  f197e10:	10000008 */ 	beqz	$zero,.L0f197e34
/*  f197e14:	ade80000 */ 	sw	$t0,0x0($t7)
.L0f197e18:
/*  f197e18:	00041080 */ 	sll	$v0,$a0,0x2
.L0f197e1c:
/*  f197e1c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f197e20:	00021080 */ 	sll	$v0,$v0,0x2
.L0f197e24:
/*  f197e24:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f197e28:	00a2082a */ 	slt	$at,$a1,$v0
/*  f197e2c:	1420ffe9 */ 	bnez	$at,.L0f197dd4
/*  f197e30:	24c60014 */ 	addiu	$a2,$a2,0x14
.L0f197e34:
/*  f197e34:	8fb00004 */ 	lw	$s0,0x4($sp)
.L0f197e38:
/*  f197e38:	03e00008 */ 	jr	$ra
/*  f197e3c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f197e40
/*  f197e40:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197e44:	10800004 */ 	beqz	$a0,.L0f197e58
/*  f197e48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197e4c:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f197e50:	15c00003 */ 	bnez	$t6,.L0f197e60
/*  f197e54:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197e58:
/*  f197e58:	10000008 */ 	beqz	$zero,.L0f197e7c
/*  f197e5c:	00001025 */ 	or	$v0,$zero,$zero
.L0f197e60:
/*  f197e60:	0fc65f3c */ 	jal	func0f197cf0
/*  f197e64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197e68:	50400004 */ 	beqzl	$v0,.L0f197e7c
/*  f197e6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f197e70:	10000002 */ 	beqz	$zero,.L0f197e7c
/*  f197e74:	8c420000 */ 	lw	$v0,0x0($v0)
/*  f197e78:	00001025 */ 	or	$v0,$zero,$zero
.L0f197e7c:
/*  f197e7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197e80:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f197e84:	03e00008 */ 	jr	$ra
/*  f197e88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197e8c
/*  f197e8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197e90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197e94:	10800005 */ 	beqz	$a0,.L0f197eac
/*  f197e98:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f197e9c:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f197ea0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f197ea4:	15c00003 */ 	bnez	$t6,.L0f197eb4
/*  f197ea8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197eac:
/*  f197eac:	10000011 */ 	beqz	$zero,.L0f197ef4
/*  f197eb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f197eb4:
/*  f197eb4:	0fc65f90 */ 	jal	func0f197e40
/*  f197eb8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f197ebc:	1440000c */ 	bnez	$v0,.L0f197ef0
/*  f197ec0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f197ec4:	0fc65f1c */ 	jal	func0f197c70
/*  f197ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197ecc:	10400006 */ 	beqz	$v0,.L0f197ee8
/*  f197ed0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f197ed4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f197ed8:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f197edc:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f197ee0:	a4590006 */ 	sh	$t9,0x6($v0)
/*  f197ee4:	a4580004 */ 	sh	$t8,0x4($v0)
.L0f197ee8:
/*  f197ee8:	10000002 */ 	beqz	$zero,.L0f197ef4
/*  f197eec:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f197ef0:
/*  f197ef0:	00001025 */ 	or	$v0,$zero,$zero
.L0f197ef4:
/*  f197ef4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197ef8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f197efc:	03e00008 */ 	jr	$ra
/*  f197f00:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197f04
/*  f197f04:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197f08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197f0c:	0fc65f3c */ 	jal	func0f197cf0
/*  f197f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197f14:	10400002 */ 	beqz	$v0,.L0f197f20
/*  f197f18:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f197f1c:	ac4e0000 */ 	sw	$t6,0x0($v0)
.L0f197f20:
/*  f197f20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197f24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f197f28:	03e00008 */ 	jr	$ra
/*  f197f2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f197f30
/*  f197f30:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f197f34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f197f38:	0fc65f3c */ 	jal	func0f197cf0
/*  f197f3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197f40:	10400007 */ 	beqz	$v0,.L0f197f60
/*  f197f44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f197f48:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f197f4c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f197f50:	55c10004 */ 	bnel	$t6,$at,.L0f197f64
/*  f197f54:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f197f58:	10000002 */ 	beqz	$zero,.L0f197f64
/*  f197f5c:	84420006 */ 	lh	$v0,0x6($v0)
.L0f197f60:
/*  f197f60:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f197f64:
/*  f197f64:	03e00008 */ 	jr	$ra
/*  f197f68:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f197f6c
/*  f197f6c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f197f70:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f197f74:	00809825 */ 	or	$s3,$a0,$zero
/*  f197f78:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f197f7c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f197f80:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f197f84:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f197f88:	10800004 */ 	beqz	$a0,.L0f197f9c
/*  f197f8c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f197f90:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f197f94:	55c00004 */ 	bnezl	$t6,.L0f197fa8
/*  f197f98:	90af0000 */ 	lbu	$t7,0x0($a1)
.L0f197f9c:
/*  f197f9c:	10000029 */ 	beqz	$zero,.L0f198044
/*  f197fa0:	00001025 */ 	or	$v0,$zero,$zero
/*  f197fa4:	90af0000 */ 	lbu	$t7,0x0($a1)
.L0f197fa8:
/*  f197fa8:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f197fac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f197fb0:	15e10011 */ 	bne	$t7,$at,.L0f197ff8
/*  f197fb4:	00408825 */ 	or	$s1,$v0,$zero
/*  f197fb8:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f197fbc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f197fc0:	57010020 */ 	bnel	$t8,$at,.L0f198044
/*  f197fc4:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f197fc8:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f197fcc:	02602025 */ 	or	$a0,$s3,$zero
/*  f197fd0:	0fc65fa3 */ 	jal	func0f197e8c
/*  f197fd4:	02002825 */ 	or	$a1,$s0,$zero
/*  f197fd8:	10400019 */ 	beqz	$v0,.L0f198040
/*  f197fdc:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f197fe0:	02602025 */ 	or	$a0,$s3,$zero
/*  f197fe4:	0fc65f3c */ 	jal	func0f197cf0
/*  f197fe8:	02002825 */ 	or	$a1,$s0,$zero
/*  f197fec:	86390006 */ 	lh	$t9,0x6($s1)
/*  f197ff0:	10000013 */ 	beqz	$zero,.L0f198040
/*  f197ff4:	a4590006 */ 	sh	$t9,0x6($v0)
.L0f197ff8:
/*  f197ff8:	92280003 */ 	lbu	$t0,0x3($s1)
/*  f197ffc:	24010014 */ 	addiu	$at,$zero,0x14
/*  f198000:	00408825 */ 	or	$s1,$v0,$zero
/*  f198004:	1501000e */ 	bne	$t0,$at,.L0f198040
/*  f198008:	00008025 */ 	or	$s0,$zero,$zero
/*  f19800c:	24120013 */ 	addiu	$s2,$zero,0x13
.L0f198010:
/*  f198010:	9629005e */ 	lhu	$t1,0x5e($s1)
/*  f198014:	59200008 */ 	blezl	$t1,.L0f198038
/*  f198018:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19801c:	0fc668c7 */ 	jal	func0f19a31c
/*  f198020:	26040001 */ 	addiu	$a0,$s0,0x1
/*  f198024:	18400003 */ 	blez	$v0,.L0f198034
/*  f198028:	00402825 */ 	or	$a1,$v0,$zero
/*  f19802c:	0fc65fa3 */ 	jal	func0f197e8c
/*  f198030:	02602025 */ 	or	$a0,$s3,$zero
.L0f198034:
/*  f198034:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f198038:
/*  f198038:	1612fff5 */ 	bne	$s0,$s2,.L0f198010
/*  f19803c:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f198040:
/*  f198040:	8fa2002c */ 	lw	$v0,0x2c($sp)
.L0f198044:
/*  f198044:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f198048:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19804c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f198050:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f198054:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f198058:	03e00008 */ 	jr	$ra
/*  f19805c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f198060:	03e00008 */ 	jr	$ra
/*  f198064:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel func0f198068
/*  f198068:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f19806c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f198070:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f198074:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f198078:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f19807c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f198080:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f198084:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f198088:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f19808c:	3c16800b */ 	lui	$s6,%hi(var800acb88)
/*  f198090:	3c1e8008 */ 	lui	$s8,%hi(mpweaponstable)
/*  f198094:	00c08825 */ 	or	$s1,$a2,$zero
/*  f198098:	0080b825 */ 	or	$s7,$a0,$zero
/*  f19809c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f1980a0:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1980a4:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f1980a8:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f1980ac:	27de7268 */ 	addiu	$s8,$s8,%lo(mpweaponstable)
/*  f1980b0:	26d6cb88 */ 	addiu	$s6,$s6,%lo(var800acb88)
/*  f1980b4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1980b8:	00c09825 */ 	or	$s3,$a2,$zero
/*  f1980bc:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f1980c0:	00a0a825 */ 	or	$s5,$a1,$zero
.L0f1980c4:
/*  f1980c4:	92ce0018 */ 	lbu	$t6,0x18($s6)
/*  f1980c8:	27b90080 */ 	addiu	$t9,$sp,0x80
/*  f1980cc:	27ad007c */ 	addiu	$t5,$sp,0x7c
/*  f1980d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1980d4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1980d8:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f1980dc:	03cfc021 */ 	addu	$t8,$s8,$t7
/*  f1980e0:	93100000 */ 	lbu	$s0,0x0($t8)
/*  f1980e4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f1980e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1980ec:	aeb00000 */ 	sw	$s0,0x0($s5)
/*  f1980f0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1980f4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1980f8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1980fc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f198100:	0fc6637e */ 	jal	func0f198df8
/*  f198104:	02002825 */ 	or	$a1,$s0,$zero
/*  f198108:	27ae0078 */ 	addiu	$t6,$sp,0x78
/*  f19810c:	27af0074 */ 	addiu	$t7,$sp,0x74
/*  f198110:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f198114:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f198118:	02e02025 */ 	or	$a0,$s7,$zero
/*  f19811c:	02002825 */ 	or	$a1,$s0,$zero
/*  f198120:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f198124:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f198128:	0fc6637e */ 	jal	func0f198df8
/*  f19812c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f198130:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f198134:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f198138:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19813c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f198140:	0319082a */ 	slt	$at,$t8,$t9
/*  f198144:	14200003 */ 	bnez	$at,.L0f198154
/*  f198148:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f19814c:	10000003 */ 	beqz	$zero,.L0f19815c
/*  f198150:	ae780000 */ 	sw	$t8,0x0($s3)
.L0f198154:
/*  f198154:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f198158:	ae6d0000 */ 	sw	$t5,0x0($s3)
.L0f19815c:
/*  f19815c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f198160:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f198164:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f198168:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f19816c:	01cf082a */ 	slt	$at,$t6,$t7
/*  f198170:	54200004 */ 	bnezl	$at,.L0f198184
/*  f198174:	ae990000 */ 	sw	$t9,0x0($s4)
/*  f198178:	10000002 */ 	beqz	$zero,.L0f198184
/*  f19817c:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f198180:	ae990000 */ 	sw	$t9,0x0($s4)
.L0f198184:
/*  f198184:	2a410018 */ 	slti	$at,$s2,0x18
/*  f198188:	1420ffce */ 	bnez	$at,.L0f1980c4
/*  f19818c:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f198190:	00004025 */ 	or	$t0,$zero,$zero
/*  f198194:	8fab008c */ 	lw	$t3,0x8c($sp)
/*  f198198:	24070006 */ 	addiu	$a3,$zero,0x6
.L0f19819c:
/*  f19819c:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f1981a0:	29410006 */ 	slti	$at,$t2,0x6
/*  f1981a4:	01002025 */ 	or	$a0,$t0,$zero
/*  f1981a8:	1020000f */ 	beqz	$at,.L0f1981e8
/*  f1981ac:	01401025 */ 	or	$v0,$t2,$zero
/*  f1981b0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1981b4:	02381821 */ 	addu	$v1,$s1,$t8
.L0f1981b8:
/*  f1981b8:	00046880 */ 	sll	$t5,$a0,0x2
/*  f1981bc:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f1981c0:	8dee0000 */ 	lw	$t6,0x0($t7)
/*  f1981c4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f1981c8:	01d9082a */ 	slt	$at,$t6,$t9
/*  f1981cc:	50200003 */ 	beqzl	$at,.L0f1981dc
/*  f1981d0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1981d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1981d8:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f1981dc:
/*  f1981dc:	1447fff6 */ 	bne	$v0,$a3,.L0f1981b8
/*  f1981e0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1981e4:	8fab008c */ 	lw	$t3,0x8c($sp)
.L0f1981e8:
/*  f1981e8:	10880015 */ 	beq	$a0,$t0,.L0f198240
/*  f1981ec:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1981f0:	00089080 */ 	sll	$s2,$t0,0x2
/*  f1981f4:	00041080 */ 	sll	$v0,$a0,0x2
/*  f1981f8:	02329821 */ 	addu	$s3,$s1,$s2
/*  f1981fc:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f198200:	02221821 */ 	addu	$v1,$s1,$v0
/*  f198204:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f198208:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f19820c:	0192a021 */ 	addu	$s4,$t4,$s2
/*  f198210:	ae650000 */ 	sw	$a1,0x0($s3)
/*  f198214:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f198218:	01823021 */ 	addu	$a2,$t4,$v0
/*  f19821c:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f198220:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f198224:	0172a821 */ 	addu	$s5,$t3,$s2
/*  f198228:	ae850000 */ 	sw	$a1,0x0($s4)
/*  f19822c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f198230:	01624821 */ 	addu	$t1,$t3,$v0
/*  f198234:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f198238:	ad2f0000 */ 	sw	$t7,0x0($t1)
/*  f19823c:	aea50000 */ 	sw	$a1,0x0($s5)
.L0f198240:
/*  f198240:	1547ffd6 */ 	bne	$t2,$a3,.L0f19819c
/*  f198244:	01404025 */ 	or	$t0,$t2,$zero
/*  f198248:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19824c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f198250:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f198254:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f198258:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f19825c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f198260:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f198264:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f198268:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f19826c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f198270:	03e00008 */ 	jr	$ra
/*  f198274:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0f198278
/*  f198278:	3c03800b */ 	lui	$v1,%hi(var800acb88)
/*  f19827c:	3c07800b */ 	lui	$a3,0x800b
/*  f198280:	3c048008 */ 	lui	$a0,%hi(mpweaponstable)
/*  f198284:	24847268 */ 	addiu	$a0,$a0,%lo(mpweaponstable)
/*  f198288:	24e7cb8e */ 	addiu	$a3,$a3,-13426
/*  f19828c:	2463cb88 */ 	addiu	$v1,$v1,%lo(var800acb88)
/*  f198290:	2406005b */ 	addiu	$a2,$zero,0x5b
/*  f198294:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f198298:	906e0018 */ 	lbu	$t6,0x18($v1)
.L0f19829c:
/*  f19829c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1982a0:	01c50019 */ 	multu	$t6,$a1
/*  f1982a4:	00007812 */ 	mflo	$t7
/*  f1982a8:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f1982ac:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f1982b0:	14460003 */ 	bne	$v0,$a2,.L0f1982c0
/*  f1982b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1982b8:	03e00008 */ 	jr	$ra
/*  f1982bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1982c0:
/*  f1982c0:	5467fff6 */ 	bnel	$v1,$a3,.L0f19829c
/*  f1982c4:	906e0018 */ 	lbu	$t6,0x18($v1)
/*  f1982c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1982cc:	03e00008 */ 	jr	$ra
/*  f1982d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1982d4
/*  f1982d4:	3c05800b */ 	lui	$a1,%hi(var800acb88)
/*  f1982d8:	3c068008 */ 	lui	$a2,%hi(mpweaponstable)
/*  f1982dc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f1982e0:	24c67268 */ 	addiu	$a2,$a2,%lo(mpweaponstable)
/*  f1982e4:	24a5cb88 */ 	addiu	$a1,$a1,%lo(var800acb88)
/*  f1982e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1982ec:	24080006 */ 	addiu	$t0,$zero,0x6
/*  f1982f0:	2407000a */ 	addiu	$a3,$zero,0xa
.L0f1982f4:
/*  f1982f4:	90ae0018 */ 	lbu	$t6,0x18($a1)
/*  f1982f8:	28410006 */ 	slti	$at,$v0,0x6
/*  f1982fc:	01c70019 */ 	multu	$t6,$a3
/*  f198300:	00007812 */ 	mflo	$t7
/*  f198304:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f198308:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f19830c:	54990006 */ 	bnel	$a0,$t9,.L0f198328
/*  f198310:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f198314:	50200004 */ 	beqzl	$at,.L0f198328
/*  f198318:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19831c:	03e00008 */ 	jr	$ra
/*  f198320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198324:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f198328:
/*  f198328:	1448fff2 */ 	bne	$v0,$t0,.L0f1982f4
/*  f19832c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f198330:	03e00008 */ 	jr	$ra
/*  f198334:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f198338
/*  f198338:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f19833c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f198340:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f198344:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f198348:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f19834c:	00004025 */ 	or	$t0,$zero,$zero
/*  f198350:	00005025 */ 	or	$t2,$zero,$zero
/*  f198354:	04e00014 */ 	bltz	$a3,.L0f1983a8
/*  f198358:	00004825 */ 	or	$t1,$zero,$zero
/*  f19835c:	14c00007 */ 	bnez	$a2,.L0f19837c
/*  f198360:	0005c100 */ 	sll	$t8,$a1,0x4
/*  f198364:	3c198008 */ 	lui	$t9,0x8008
/*  f198368:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f19836c:	97397eb4 */ 	lhu	$t9,0x7eb4($t9)
/*  f198370:	00195bc2 */ 	srl	$t3,$t9,0xf
/*  f198374:	50eb000d */ 	beql	$a3,$t3,.L0f1983ac
/*  f198378:	8fab0054 */ 	lw	$t3,0x54($sp)
.L0f19837c:
/*  f19837c:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f198380:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f198384:	3c0f8008 */ 	lui	$t7,0x8008
/*  f198388:	11800053 */ 	beqz	$t4,.L0f1984d8
/*  f19838c:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f198390:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f198394:	95ef7eb4 */ 	lhu	$t7,0x7eb4($t7)
/*  f198398:	000fc440 */ 	sll	$t8,$t7,0x11
/*  f19839c:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f1983a0:	54f9004e */ 	bnel	$a3,$t9,.L0f1984dc
/*  f1983a4:	8fb90054 */ 	lw	$t9,0x54($sp)
.L0f1983a8:
/*  f1983a8:	8fab0054 */ 	lw	$t3,0x54($sp)
.L0f1983ac:
/*  f1983ac:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1983b0:	3c0d8008 */ 	lui	$t5,%hi(var80087eb0)
/*  f1983b4:	25ad7eb0 */ 	addiu	$t5,$t5,%lo(var80087eb0)
/*  f1983b8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f1983bc:	10c00004 */ 	beqz	$a2,.L0f1983d0
/*  f1983c0:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f1983c4:	90480002 */ 	lbu	$t0,0x2($v0)
/*  f1983c8:	10000003 */ 	beqz	$zero,.L0f1983d8
/*  f1983cc:	904a0003 */ 	lbu	$t2,0x3($v0)
.L0f1983d0:
/*  f1983d0:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f1983d4:	904a0001 */ 	lbu	$t2,0x1($v0)
.L0f1983d8:
/*  f1983d8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f1983dc:	51c0003f */ 	beqzl	$t6,.L0f1984dc
/*  f1983e0:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f1983e4:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f1983e8:	5080003c */ 	beqzl	$a0,.L0f1984dc
/*  f1983ec:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f1983f0:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f1983f4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1983f8:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1983fc:	90430048 */ 	lbu	$v1,0x48($v0)
/*  f198400:	14600003 */ 	bnez	$v1,.L0f198410
/*  f198404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198408:	10000004 */ 	beqz	$zero,.L0f19841c
/*  f19840c:	24090064 */ 	addiu	$t1,$zero,0x64
.L0f198410:
/*  f198410:	54610003 */ 	bnel	$v1,$at,.L0f198420
/*  f198414:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f198418:	24090032 */ 	addiu	$t1,$zero,0x32
.L0f19841c:
/*  f19841c:	90430047 */ 	lbu	$v1,0x47($v0)
.L0f198420:
/*  f198420:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f198424:	24010002 */ 	addiu	$at,$zero,0x2
/*  f198428:	14a30025 */ 	bne	$a1,$v1,.L0f1984c0
/*  f19842c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198430:	24010018 */ 	addiu	$at,$zero,0x18
/*  f198434:	15e10003 */ 	bne	$t7,$at,.L0f198444
/*  f198438:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f19843c:	10000026 */ 	beqz	$zero,.L0f1984d8
/*  f198440:	2528012c */ 	addiu	$t0,$t1,0x12c
.L0f198444:
/*  f198444:	24010019 */ 	addiu	$at,$zero,0x19
/*  f198448:	17010003 */ 	bne	$t8,$at,.L0f198458
/*  f19844c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f198450:	10000021 */ 	beqz	$zero,.L0f1984d8
/*  f198454:	2528012b */ 	addiu	$t0,$t1,0x12b
.L0f198458:
/*  f198458:	24010017 */ 	addiu	$at,$zero,0x17
/*  f19845c:	17210003 */ 	bne	$t9,$at,.L0f19846c
/*  f198460:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f198464:	1000001c */ 	beqz	$zero,.L0f1984d8
/*  f198468:	25280118 */ 	addiu	$t0,$t1,0x118
.L0f19846c:
/*  f19846c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f198470:	15610005 */ 	bne	$t3,$at,.L0f198488
/*  f198474:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f198478:	51800004 */ 	beqzl	$t4,.L0f19848c
/*  f19847c:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f198480:	10000015 */ 	beqz	$zero,.L0f1984d8
/*  f198484:	25280117 */ 	addiu	$t0,$t1,0x117
.L0f198488:
/*  f198488:	8fad0054 */ 	lw	$t5,0x54($sp)
.L0f19848c:
/*  f19848c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f198490:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f198494:	15a10005 */ 	bne	$t5,$at,.L0f1984ac
/*  f198498:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f19849c:	51c00004 */ 	beqzl	$t6,.L0f1984b0
/*  f1984a0:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f1984a4:	1000000c */ 	beqz	$zero,.L0f1984d8
/*  f1984a8:	25280104 */ 	addiu	$t0,$t1,0x104
.L0f1984ac:
/*  f1984ac:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f1984b0:
/*  f1984b0:	55e1000a */ 	bnel	$t7,$at,.L0f1984dc
/*  f1984b4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f1984b8:	10000007 */ 	beqz	$zero,.L0f1984d8
/*  f1984bc:	252800f0 */ 	addiu	$t0,$t1,0xf0
.L0f1984c0:
/*  f1984c0:	14610005 */ 	bne	$v1,$at,.L0f1984d8
/*  f1984c4:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f1984c8:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1984cc:	57010003 */ 	bnel	$t8,$at,.L0f1984dc
/*  f1984d0:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f1984d4:	2528012c */ 	addiu	$t0,$t1,0x12c
.L0f1984d8:
/*  f1984d8:	8fb90054 */ 	lw	$t9,0x54($sp)
.L0f1984dc:
/*  f1984dc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f1984e0:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1984e4:	272bffff */ 	addiu	$t3,$t9,-1
/*  f1984e8:	2d61001f */ 	sltiu	$at,$t3,0x1f
/*  f1984ec:	102001ba */ 	beqz	$at,.L0f198bd8
/*  f1984f0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1984f4:	3c017f1c */ 	lui	$at,%hi(var7f1b9010)
/*  f1984f8:	002b0821 */ 	addu	$at,$at,$t3
/*  f1984fc:	8c2b9010 */ 	lw	$t3,%lo(var7f1b9010)($at)
/*  f198500:	01600008 */ 	jr	$t3
/*  f198504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198508:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f19850c:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f198510:	518001b2 */ 	beqzl	$t4,.L0f198bdc
/*  f198514:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198518:	11a001af */ 	beqz	$t5,.L0f198bd8
/*  f19851c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f198520:	85cf017e */ 	lh	$t7,0x17e($t6)
/*  f198524:	2401ffff */ 	addiu	$at,$zero,-1
/*  f198528:	51e1000f */ 	beql	$t7,$at,.L0f198568
/*  f19852c:	00004025 */ 	or	$t0,$zero,$zero
/*  f198530:	0fc64580 */ 	jal	func0f191600
/*  f198534:	01c02025 */ 	or	$a0,$t6,$zero
/*  f198538:	28410002 */ 	slti	$at,$v0,0x2
/*  f19853c:	14200009 */ 	bnez	$at,.L0f198564
/*  f198540:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f198544:	8f1902d4 */ 	lw	$t9,0x2d4($t8)
/*  f198548:	2408001a */ 	addiu	$t0,$zero,0x1a
/*  f19854c:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*  f198550:	916c0048 */ 	lbu	$t4,0x48($t3)
/*  f198554:	59800004 */ 	blezl	$t4,.L0f198568
/*  f198558:	00004025 */ 	or	$t0,$zero,$zero
/*  f19855c:	1000019e */ 	beqz	$zero,.L0f198bd8
/*  f198560:	240a001a */ 	addiu	$t2,$zero,0x1a
.L0f198564:
/*  f198564:	00004025 */ 	or	$t0,$zero,$zero
.L0f198568:
/*  f198568:	1000019b */ 	beqz	$zero,.L0f198bd8
/*  f19856c:	00005025 */ 	or	$t2,$zero,$zero
/*  f198570:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f198574:	51a00199 */ 	beqzl	$t5,.L0f198bdc
/*  f198578:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f19857c:	2408000f */ 	addiu	$t0,$zero,0xf
/*  f198580:	10000195 */ 	beqz	$zero,.L0f198bd8
/*  f198584:	240a000f */ 	addiu	$t2,$zero,0xf
/*  f198588:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f19858c:	51e00193 */ 	beqzl	$t7,.L0f198bdc
/*  f198590:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198594:	2408000e */ 	addiu	$t0,$zero,0xe
/*  f198598:	1000018f */ 	beqz	$zero,.L0f198bd8
/*  f19859c:	240a000e */ 	addiu	$t2,$zero,0xe
/*  f1985a0:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f1985a4:	51c0018d */ 	beqzl	$t6,.L0f198bdc
/*  f1985a8:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1985ac:	24080010 */ 	addiu	$t0,$zero,0x10
/*  f1985b0:	10000189 */ 	beqz	$zero,.L0f198bd8
/*  f1985b4:	240a0010 */ 	addiu	$t2,$zero,0x10
/*  f1985b8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f1985bc:	57000187 */ 	bnezl	$t8,.L0f198bdc
/*  f1985c0:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1985c4:	10c00003 */ 	beqz	$a2,.L0f1985d4
/*  f1985c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1985cc:	10000182 */ 	beqz	$zero,.L0f198bd8
/*  f1985d0:	2408005b */ 	addiu	$t0,$zero,0x5b
.L0f1985d4:
/*  f1985d4:	10000180 */ 	beqz	$zero,.L0f198bd8
/*  f1985d8:	2408003f */ 	addiu	$t0,$zero,0x3f
/*  f1985dc:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f1985e0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f1985e4:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f1985e8:	8d620004 */ 	lw	$v0,0x4($t3)
/*  f1985ec:	904c0047 */ 	lbu	$t4,0x47($v0)
/*  f1985f0:	50ac017a */ 	beql	$a1,$t4,.L0f198bdc
/*  f1985f4:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1985f8:	11a0000c */ 	beqz	$t5,.L0f19862c
/*  f1985fc:	3c0f800b */ 	lui	$t7,0x800b
/*  f198600:	8defcb94 */ 	lw	$t7,-0x346c($t7)
/*  f198604:	31ee0001 */ 	andi	$t6,$t7,0x1
/*  f198608:	51c00174 */ 	beqzl	$t6,.L0f198bdc
/*  f19860c:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198610:	90580048 */ 	lbu	$t8,0x48($v0)
/*  f198614:	2b010002 */ 	slti	$at,$t8,0x2
/*  f198618:	54200170 */ 	bnezl	$at,.L0f198bdc
/*  f19861c:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198620:	2408006e */ 	addiu	$t0,$zero,0x6e
/*  f198624:	1000016c */ 	beqz	$zero,.L0f198bd8
/*  f198628:	240a0096 */ 	addiu	$t2,$zero,0x96
.L0f19862c:
/*  f19862c:	10c00003 */ 	beqz	$a2,.L0f19863c
/*  f198630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198634:	10000168 */ 	beqz	$zero,.L0f198bd8
/*  f198638:	2408005a */ 	addiu	$t0,$zero,0x5a
.L0f19863c:
/*  f19863c:	10000166 */ 	beqz	$zero,.L0f198bd8
/*  f198640:	2408003e */ 	addiu	$t0,$zero,0x3e
/*  f198644:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f198648:	53200164 */ 	beqzl	$t9,.L0f198bdc
/*  f19864c:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198650:	24080011 */ 	addiu	$t0,$zero,0x11
/*  f198654:	10000160 */ 	beqz	$zero,.L0f198bd8
/*  f198658:	240a0011 */ 	addiu	$t2,$zero,0x11
/*  f19865c:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f198660:	5160015e */ 	beqzl	$t3,.L0f198bdc
/*  f198664:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198668:	24080012 */ 	addiu	$t0,$zero,0x12
/*  f19866c:	1000015a */ 	beqz	$zero,.L0f198bd8
/*  f198670:	240a0012 */ 	addiu	$t2,$zero,0x12
/*  f198674:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f198678:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f19867c:	8daf02d4 */ 	lw	$t7,0x2d4($t5)
/*  f198680:	8dee0210 */ 	lw	$t6,0x210($t7)
/*  f198684:	31d80001 */ 	andi	$t8,$t6,0x1
/*  f198688:	55980154 */ 	bnel	$t4,$t8,.L0f198bdc
/*  f19868c:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198690:	10000151 */ 	beqz	$zero,.L0f198bd8
/*  f198694:	2508ffff */ 	addiu	$t0,$t0,-1
/*  f198698:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f19869c:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f1986a0:	8d6d02d4 */ 	lw	$t5,0x2d4($t3)
/*  f1986a4:	8daf0210 */ 	lw	$t7,0x210($t5)
/*  f1986a8:	31ee0001 */ 	andi	$t6,$t7,0x1
/*  f1986ac:	572e014b */ 	bnel	$t9,$t6,.L0f198bdc
/*  f1986b0:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1986b4:	10000148 */ 	beqz	$zero,.L0f198bd8
/*  f1986b8:	2508ffff */ 	addiu	$t0,$t0,-1
/*  f1986bc:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1986c0:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f1986c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1986c8:	8d8402d4 */ 	lw	$a0,0x2d4($t4)
/*  f1986cc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1986d0:	8c98004c */ 	lw	$t8,0x4c($a0)
/*  f1986d4:	00186980 */ 	sll	$t5,$t8,0x6
/*  f1986d8:	05a20140 */ 	bltzl	$t5,.L0f198bdc
/*  f1986dc:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1986e0:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f1986e4:	0fc666f9 */ 	jal	func0f199be4
/*  f1986e8:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f1986ec:	284101f5 */ 	slti	$at,$v0,0x1f5
/*  f1986f0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f1986f4:	14200138 */ 	bnez	$at,.L0f198bd8
/*  f1986f8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f1986fc:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f198700:	8de402d4 */ 	lw	$a0,0x2d4($t7)
/*  f198704:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f198708:	932e0048 */ 	lbu	$t6,0x48($t9)
/*  f19870c:	59c00133 */ 	blezl	$t6,.L0f198bdc
/*  f198710:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198714:	8c820210 */ 	lw	$v0,0x210($a0)
/*  f198718:	2401000a */ 	addiu	$at,$zero,0xa
/*  f19871c:	0041001b */ 	divu	$zero,$v0,$at
/*  f198720:	00006010 */ 	mfhi	$t4
/*  f198724:	010c4021 */ 	addu	$t0,$t0,$t4
/*  f198728:	1000012b */ 	beqz	$zero,.L0f198bd8
/*  f19872c:	014c5021 */ 	addu	$t2,$t2,$t4
/*  f198730:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f198734:	53000129 */ 	beqzl	$t8,.L0f198bdc
/*  f198738:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f19873c:	00004025 */ 	or	$t0,$zero,$zero
/*  f198740:	10000125 */ 	beqz	$zero,.L0f198bd8
/*  f198744:	00005025 */ 	or	$t2,$zero,$zero
/*  f198748:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f19874c:	51600123 */ 	beqzl	$t3,.L0f198bdc
/*  f198750:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198754:	00004025 */ 	or	$t0,$zero,$zero
/*  f198758:	1000011f */ 	beqz	$zero,.L0f198bd8
/*  f19875c:	00005025 */ 	or	$t2,$zero,$zero
/*  f198760:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f198764:	8da402d4 */ 	lw	$a0,0x2d4($t5)
/*  f198768:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f19876c:	91f90047 */ 	lbu	$t9,0x47($t7)
/*  f198770:	50b9011a */ 	beql	$a1,$t9,.L0f198bdc
/*  f198774:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198778:	8c8c0210 */ 	lw	$t4,0x210($a0)
/*  f19877c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f198780:	31980001 */ 	andi	$t8,$t4,0x1
/*  f198784:	55d80115 */ 	bnel	$t6,$t8,.L0f198bdc
/*  f198788:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f19878c:	10000112 */ 	beqz	$zero,.L0f198bd8
/*  f198790:	2508fff1 */ 	addiu	$t0,$t0,-15
/*  f198794:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f198798:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f19879c:	8daf02d4 */ 	lw	$t7,0x2d4($t5)
/*  f1987a0:	8df90210 */ 	lw	$t9,0x210($t7)
/*  f1987a4:	332c0001 */ 	andi	$t4,$t9,0x1
/*  f1987a8:	556c010c */ 	bnel	$t3,$t4,.L0f198bdc
/*  f1987ac:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1987b0:	10000109 */ 	beqz	$zero,.L0f198bd8
/*  f1987b4:	2508ffff */ 	addiu	$t0,$t0,-1
/*  f1987b8:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f1987bc:	51c00107 */ 	beqzl	$t6,.L0f198bdc
/*  f1987c0:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1987c4:	24080013 */ 	addiu	$t0,$zero,0x13
/*  f1987c8:	10000103 */ 	beqz	$zero,.L0f198bd8
/*  f1987cc:	240a0050 */ 	addiu	$t2,$zero,0x50
/*  f1987d0:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f1987d4:	53000101 */ 	beqzl	$t8,.L0f198bdc
/*  f1987d8:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1987dc:	00004025 */ 	or	$t0,$zero,$zero
/*  f1987e0:	100000fd */ 	beqz	$zero,.L0f198bd8
/*  f1987e4:	00005025 */ 	or	$t2,$zero,$zero
/*  f1987e8:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f1987ec:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f1987f0:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f1987f4:	8f2b0210 */ 	lw	$t3,0x210($t9)
/*  f1987f8:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f1987fc:	55ac00f7 */ 	bnel	$t5,$t4,.L0f198bdc
/*  f198800:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198804:	100000f4 */ 	beqz	$zero,.L0f198bd8
/*  f198808:	2508ffff */ 	addiu	$t0,$t0,-1
/*  f19880c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f198810:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f198814:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f198818:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f19881c:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f198820:	904f0047 */ 	lbu	$t7,0x47($v0)
/*  f198824:	14af0026 */ 	bne	$a1,$t7,.L0f1988c0
/*  f198828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19882c:	532000eb */ 	beqzl	$t9,.L0f198bdc
/*  f198830:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198834:	904b0048 */ 	lbu	$t3,0x48($v0)
/*  f198838:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f19883c:	5960001e */ 	blezl	$t3,.L0f1988b8
/*  f198840:	00004025 */ 	or	$t0,$zero,$zero
/*  f198844:	51a000e5 */ 	beqzl	$t5,.L0f198bdc
/*  f198848:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f19884c:	85cc017e */ 	lh	$t4,0x17e($t6)
/*  f198850:	2401ffff */ 	addiu	$at,$zero,-1
/*  f198854:	01c02025 */ 	or	$a0,$t6,$zero
/*  f198858:	11810014 */ 	beq	$t4,$at,.L0f1988ac
/*  f19885c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198860:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f198864:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f198868:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f19886c:	0fc633fe */ 	jal	func0f18cff8
/*  f198870:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f198874:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f198878:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19887c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f198880:	8f0402d4 */ 	lw	$a0,0x2d4($t8)
/*  f198884:	00827821 */ 	addu	$t7,$a0,$v0
/*  f198888:	91f9016c */ 	lbu	$t9,0x16c($t7)
/*  f19888c:	17200007 */ 	bnez	$t9,.L0f1988ac
/*  f198890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198894:	8c8b0210 */ 	lw	$t3,0x210($a0)
/*  f198898:	316d0001 */ 	andi	$t5,$t3,0x1
/*  f19889c:	15a00003 */ 	bnez	$t5,.L0f1988ac
/*  f1988a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1988a4:	100000cc */ 	beqz	$zero,.L0f198bd8
/*  f1988a8:	2508000a */ 	addiu	$t0,$t0,0xa
.L0f1988ac:
/*  f1988ac:	100000ca */ 	beqz	$zero,.L0f198bd8
/*  f1988b0:	2508fff6 */ 	addiu	$t0,$t0,-10
/*  f1988b4:	00004025 */ 	or	$t0,$zero,$zero
.L0f1988b8:
/*  f1988b8:	100000c7 */ 	beqz	$zero,.L0f198bd8
/*  f1988bc:	00005025 */ 	or	$t2,$zero,$zero
.L0f1988c0:
/*  f1988c0:	518000c6 */ 	beqzl	$t4,.L0f198bdc
/*  f1988c4:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1988c8:	904e0048 */ 	lbu	$t6,0x48($v0)
/*  f1988cc:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f1988d0:	29c10002 */ 	slti	$at,$t6,0x2
/*  f1988d4:	54200020 */ 	bnezl	$at,.L0f198958
/*  f1988d8:	00004025 */ 	or	$t0,$zero,$zero
/*  f1988dc:	130000be */ 	beqz	$t8,.L0f198bd8
/*  f1988e0:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f1988e4:	85f9017e */ 	lh	$t9,0x17e($t7)
/*  f1988e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1988ec:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1988f0:	53210016 */ 	beql	$t9,$at,.L0f19894c
/*  f1988f4:	2508fff1 */ 	addiu	$t0,$t0,-15
/*  f1988f8:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f1988fc:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f198900:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f198904:	0fc633fe */ 	jal	func0f18cff8
/*  f198908:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19890c:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f198910:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f198914:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f198918:	8d6402d4 */ 	lw	$a0,0x2d4($t3)
/*  f19891c:	00826821 */ 	addu	$t5,$a0,$v0
/*  f198920:	91ac016c */ 	lbu	$t4,0x16c($t5)
/*  f198924:	55800009 */ 	bnezl	$t4,.L0f19894c
/*  f198928:	2508fff1 */ 	addiu	$t0,$t0,-15
/*  f19892c:	8c8e0210 */ 	lw	$t6,0x210($a0)
/*  f198930:	31d80001 */ 	andi	$t8,$t6,0x1
/*  f198934:	57000005 */ 	bnezl	$t8,.L0f19894c
/*  f198938:	2508fff1 */ 	addiu	$t0,$t0,-15
/*  f19893c:	240800b2 */ 	addiu	$t0,$zero,0xb2
/*  f198940:	100000a5 */ 	beqz	$zero,.L0f198bd8
/*  f198944:	240a00bc */ 	addiu	$t2,$zero,0xbc
/*  f198948:	2508fff1 */ 	addiu	$t0,$t0,-15
.L0f19894c:
/*  f19894c:	100000a2 */ 	beqz	$zero,.L0f198bd8
/*  f198950:	254afff1 */ 	addiu	$t2,$t2,-15
/*  f198954:	00004025 */ 	or	$t0,$zero,$zero
.L0f198958:
/*  f198958:	1000009f */ 	beqz	$zero,.L0f198bd8
/*  f19895c:	00005025 */ 	or	$t2,$zero,$zero
/*  f198960:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f198964:	5320009d */ 	beqzl	$t9,.L0f198bdc
/*  f198968:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f19896c:	00004025 */ 	or	$t0,$zero,$zero
/*  f198970:	10000099 */ 	beqz	$zero,.L0f198bd8
/*  f198974:	00005025 */ 	or	$t2,$zero,$zero
/*  f198978:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f19897c:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f198980:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f198984:	11e0000c */ 	beqz	$t7,.L0f1989b8
/*  f198988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19898c:	8d6d02d4 */ 	lw	$t5,0x2d4($t3)
/*  f198990:	240a00b0 */ 	addiu	$t2,$zero,0xb0
/*  f198994:	00004025 */ 	or	$t0,$zero,$zero
/*  f198998:	8dac0004 */ 	lw	$t4,0x4($t5)
/*  f19899c:	918e0048 */ 	lbu	$t6,0x48($t4)
/*  f1989a0:	19c00003 */ 	blez	$t6,.L0f1989b0
/*  f1989a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1989a8:	1000008b */ 	beqz	$zero,.L0f198bd8
/*  f1989ac:	2408009e */ 	addiu	$t0,$zero,0x9e
.L0f1989b0:
/*  f1989b0:	10000089 */ 	beqz	$zero,.L0f198bd8
/*  f1989b4:	00005025 */ 	or	$t2,$zero,$zero
.L0f1989b8:
/*  f1989b8:	1300000f */ 	beqz	$t8,.L0f1989f8
/*  f1989bc:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f1989c0:	872f017e */ 	lh	$t7,0x17e($t9)
/*  f1989c4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1989c8:	51e1000c */ 	beql	$t7,$at,.L0f1989fc
/*  f1989cc:	24080031 */ 	addiu	$t0,$zero,0x31
/*  f1989d0:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f1989d4:	03202025 */ 	or	$a0,$t9,$zero
/*  f1989d8:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*  f1989dc:	00004025 */ 	or	$t0,$zero,$zero
/*  f1989e0:	856d02d8 */ 	lh	$t5,0x2d8($t3)
/*  f1989e4:	29a10dad */ 	slti	$at,$t5,0xdad
/*  f1989e8:	54200004 */ 	bnezl	$at,.L0f1989fc
/*  f1989ec:	24080031 */ 	addiu	$t0,$zero,0x31
/*  f1989f0:	10000079 */ 	beqz	$zero,.L0f198bd8
/*  f1989f4:	00005025 */ 	or	$t2,$zero,$zero
.L0f1989f8:
/*  f1989f8:	24080031 */ 	addiu	$t0,$zero,0x31
.L0f1989fc:
/*  f1989fc:	10000076 */ 	beqz	$zero,.L0f198bd8
/*  f198a00:	240a00bc */ 	addiu	$t2,$zero,0xbc
/*  f198a04:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f198a08:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f198a0c:	51800073 */ 	beqzl	$t4,.L0f198bdc
/*  f198a10:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198a14:	85d8017e */ 	lh	$t8,0x17e($t6)
/*  f198a18:	2401ffff */ 	addiu	$at,$zero,-1
/*  f198a1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f198a20:	13010008 */ 	beq	$t8,$at,.L0f198a44
/*  f198a24:	01c02025 */ 	or	$a0,$t6,$zero
/*  f198a28:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f198a2c:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f198a30:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f198a34:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f198a38:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f198a3c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f198a40:	85e502d8 */ 	lh	$a1,0x2d8($t7)
.L0f198a44:
/*  f198a44:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f198a48:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f198a4c:	28a11388 */ 	slti	$at,$a1,0x1388
/*  f198a50:	13200025 */ 	beqz	$t9,.L0f198ae8
/*  f198a54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198a58:	8d6402d4 */ 	lw	$a0,0x2d4($t3)
/*  f198a5c:	00004025 */ 	or	$t0,$zero,$zero
/*  f198a60:	28a10dad */ 	slti	$at,$a1,0xdad
/*  f198a64:	8c8d0004 */ 	lw	$t5,0x4($a0)
/*  f198a68:	91ac0048 */ 	lbu	$t4,0x48($t5)
/*  f198a6c:	1d800003 */ 	bgtz	$t4,.L0f198a7c
/*  f198a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198a74:	10000058 */ 	beqz	$zero,.L0f198bd8
/*  f198a78:	00005025 */ 	or	$t2,$zero,$zero
.L0f198a7c:
/*  f198a7c:	5420000c */ 	bnezl	$at,.L0f198ab0
/*  f198a80:	8c830210 */ 	lw	$v1,0x210($a0)
/*  f198a84:	8c830210 */ 	lw	$v1,0x210($a0)
/*  f198a88:	2401008c */ 	addiu	$at,$zero,0x8c
/*  f198a8c:	30780001 */ 	andi	$t8,$v1,0x1
/*  f198a90:	57000007 */ 	bnezl	$t8,.L0f198ab0
/*  f198a94:	8c830210 */ 	lw	$v1,0x210($a0)
/*  f198a98:	0061001b */ 	divu	$zero,$v1,$at
/*  f198a9c:	00004010 */ 	mfhi	$t0
/*  f198aa0:	25080030 */ 	addiu	$t0,$t0,0x30
/*  f198aa4:	1000004c */ 	beqz	$zero,.L0f198bd8
/*  f198aa8:	240a00bc */ 	addiu	$t2,$zero,0xbc
/*  f198aac:	8c830210 */ 	lw	$v1,0x210($a0)
.L0f198ab0:
/*  f198ab0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f198ab4:	00004025 */ 	or	$t0,$zero,$zero
/*  f198ab8:	0061001b */ 	divu	$zero,$v1,$at
/*  f198abc:	00007010 */ 	mfhi	$t6
/*  f198ac0:	2401008c */ 	addiu	$at,$zero,0x8c
/*  f198ac4:	15c00006 */ 	bnez	$t6,.L0f198ae0
/*  f198ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198acc:	0061001b */ 	divu	$zero,$v1,$at
/*  f198ad0:	00004010 */ 	mfhi	$t0
/*  f198ad4:	25080030 */ 	addiu	$t0,$t0,0x30
/*  f198ad8:	1000003f */ 	beqz	$zero,.L0f198bd8
/*  f198adc:	240a00bc */ 	addiu	$t2,$zero,0xbc
.L0f198ae0:
/*  f198ae0:	1000003d */ 	beqz	$zero,.L0f198bd8
/*  f198ae4:	00005025 */ 	or	$t2,$zero,$zero
.L0f198ae8:
/*  f198ae8:	1420000a */ 	bnez	$at,.L0f198b14
/*  f198aec:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f198af0:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f198af4:	240a0030 */ 	addiu	$t2,$zero,0x30
/*  f198af8:	8f2b0210 */ 	lw	$t3,0x210($t9)
/*  f198afc:	316d0001 */ 	andi	$t5,$t3,0x1
/*  f198b00:	51a00036 */ 	beqzl	$t5,.L0f198bdc
/*  f198b04:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198b08:	00004025 */ 	or	$t0,$zero,$zero
/*  f198b0c:	10000032 */ 	beqz	$zero,.L0f198bd8
/*  f198b10:	00005025 */ 	or	$t2,$zero,$zero
.L0f198b14:
/*  f198b14:	28a10dad */ 	slti	$at,$a1,0xdad
/*  f198b18:	1420002f */ 	bnez	$at,.L0f198bd8
/*  f198b1c:	00051823 */ 	negu	$v1,$a1
/*  f198b20:	3c010001 */ 	lui	$at,0x1
/*  f198b24:	34213880 */ 	ori	$at,$at,0x3880
/*  f198b28:	00036100 */ 	sll	$t4,$v1,0x4
/*  f198b2c:	01811821 */ 	addu	$v1,$t4,$at
/*  f198b30:	240105dc */ 	addiu	$at,$zero,0x5dc
/*  f198b34:	0061001a */ 	div	$zero,$v1,$at
/*  f198b38:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f198b3c:	00001012 */ 	mflo	$v0
/*  f198b40:	2c410010 */ 	sltiu	$at,$v0,0x10
/*  f198b44:	14200002 */ 	bnez	$at,.L0f198b50
/*  f198b48:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f198b4c:	2402000f */ 	addiu	$v0,$zero,0xf
.L0f198b50:
/*  f198b50:	00420019 */ 	multu	$v0,$v0
/*  f198b54:	8c830210 */ 	lw	$v1,0x210($a0)
/*  f198b58:	306f0001 */ 	andi	$t7,$v1,0x1
/*  f198b5c:	00001012 */ 	mflo	$v0
/*  f198b60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198b68:	00420019 */ 	multu	$v0,$v0
/*  f198b6c:	00001012 */ 	mflo	$v0
/*  f198b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198b74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198b78:	00420019 */ 	multu	$v0,$v0
/*  f198b7c:	00001012 */ 	mflo	$v0
/*  f198b80:	0043082b */ 	sltu	$at,$v0,$v1
/*  f198b84:	50200015 */ 	beqzl	$at,.L0f198bdc
/*  f198b88:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198b8c:	11e00012 */ 	beqz	$t7,.L0f198bd8
/*  f198b90:	240a0030 */ 	addiu	$t2,$zero,0x30
/*  f198b94:	00004025 */ 	or	$t0,$zero,$zero
/*  f198b98:	1000000f */ 	beqz	$zero,.L0f198bd8
/*  f198b9c:	00005025 */ 	or	$t2,$zero,$zero
/*  f198ba0:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f198ba4:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f198ba8:	5320000c */ 	beqzl	$t9,.L0f198bdc
/*  f198bac:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198bb0:	856d017e */ 	lh	$t5,0x17e($t3)
/*  f198bb4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f198bb8:	01602025 */ 	or	$a0,$t3,$zero
/*  f198bbc:	51a10007 */ 	beql	$t5,$at,.L0f198bdc
/*  f198bc0:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f198bc4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f198bc8:	0fc64580 */ 	jal	func0f191600
/*  f198bcc:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f198bd0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f198bd4:	8faa0048 */ 	lw	$t2,0x48($sp)
.L0f198bd8:
/*  f198bd8:	8fac0070 */ 	lw	$t4,0x70($sp)
.L0f198bdc:
/*  f198bdc:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f198be0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f198be4:	1180006b */ 	beqz	$t4,.L0f198d94
/*  f198be8:	3c013f80 */ 	lui	$at,0x3f80
/*  f198bec:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f198bf0:	44810000 */ 	mtc1	$at,$f0
/*  f198bf4:	00001825 */ 	or	$v1,$zero,$zero
/*  f198bf8:	18400013 */ 	blez	$v0,.L0f198c48
/*  f198bfc:	46000386 */ 	mov.s	$f14,$f0
/*  f198c00:	3c0e800b */ 	lui	$t6,0x800b
/*  f198c04:	8dcec530 */ 	lw	$t6,-0x3ad0($t6)
/*  f198c08:	8c980488 */ 	lw	$t8,0x488($a0)
/*  f198c0c:	3c014561 */ 	lui	$at,0x4561
/*  f198c10:	004e0019 */ 	multu	$v0,$t6
/*  f198c14:	44982000 */ 	mtc1	$t8,$f4
/*  f198c18:	44814000 */ 	mtc1	$at,$f8
/*  f198c1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f198c20:	00007812 */ 	mflo	$t7
/*  f198c24:	448f8000 */ 	mtc1	$t7,$f16
/*  f198c28:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f198c2c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f198c30:	46125383 */ 	div.s	$f14,$f10,$f18
/*  f198c34:	4600703c */ 	c.lt.s	$f14,$f0
/*  f198c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198c3c:	45020003 */ 	bc1fl	.L0f198c4c
/*  f198c40:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f198c44:	46000386 */ 	mov.s	$f14,$f0
.L0f198c48:
/*  f198c48:	8fa40054 */ 	lw	$a0,0x54($sp)
.L0f198c4c:
/*  f198c4c:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f198c50:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f198c54:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f198c58:	0fc660b5 */ 	jal	func0f1982d4
/*  f198c5c:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*  f198c60:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f198c64:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f198c68:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f198c6c:	c7ae002c */ 	lwc1	$f14,0x2c($sp)
/*  f198c70:	04400048 */ 	bltz	$v0,.L0f198d94
/*  f198c74:	00402825 */ 	or	$a1,$v0,$zero
/*  f198c78:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f198c7c:	8fa20058 */ 	lw	$v0,0x58($sp)
/*  f198c80:	000560c0 */ 	sll	$t4,$a1,0x3
/*  f198c84:	8dab02d4 */ 	lw	$t3,0x2d4($t5)
/*  f198c88:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f198c8c:	3c017f1c */ 	lui	$at,%hi(var7f1b908c)
/*  f198c90:	016cc021 */ 	addu	$t8,$t3,$t4
/*  f198c94:	03197021 */ 	addu	$t6,$t8,$t9
/*  f198c98:	8dcf0274 */ 	lw	$t7,0x274($t6)
/*  f198c9c:	c428908c */ 	lwc1	$f8,%lo(var7f1b908c)($at)
/*  f198ca0:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*  f198ca4:	448f2000 */ 	mtc1	$t7,$f4
/*  f198ca8:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f198cac:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f198cb0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f198cb4:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f198cb8:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f198cbc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f198cc0:	03201025 */ 	or	$v0,$t9,$zero
/*  f198cc4:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f198cc8:	0fc25e5c */ 	jal	func0f097970
/*  f198ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198cd0:	44808000 */ 	mtc1	$zero,$f16
/*  f198cd4:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f198cd8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f198cdc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f198ce0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f198ce4:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f198ce8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f198cec:	45000019 */ 	bc1f	.L0f198d54
/*  f198cf0:	c7ae002c */ 	lwc1	$f14,0x2c($sp)
/*  f198cf4:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f198cf8:	000568c0 */ 	sll	$t5,$a1,0x3
/*  f198cfc:	8f2402d4 */ 	lw	$a0,0x2d4($t9)
/*  f198d00:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f198d04:	008d5821 */ 	addu	$t3,$a0,$t5
/*  f198d08:	01621821 */ 	addu	$v1,$t3,$v0
/*  f198d0c:	91980048 */ 	lbu	$t8,0x48($t4)
/*  f198d10:	c4620214 */ 	lwc1	$f2,0x214($v1)
/*  f198d14:	2b010002 */ 	slti	$at,$t8,0x2
/*  f198d18:	14200005 */ 	bnez	$at,.L0f198d30
/*  f198d1c:	3c014040 */ 	lui	$at,0x4040
/*  f198d20:	44815000 */ 	mtc1	$at,$f10
/*  f198d24:	c4720244 */ 	lwc1	$f18,0x244($v1)
/*  f198d28:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f198d2c:	46041081 */ 	sub.s	$f2,$f2,$f4
.L0f198d30:
/*  f198d30:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f198d34:	3c014120 */ 	lui	$at,0x4120
/*  f198d38:	44813000 */ 	mtc1	$at,$f6
/*  f198d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198d40:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f198d44:	460e4403 */ 	div.s	$f16,$f8,$f14
/*  f198d48:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f198d4c:	44035000 */ 	mfc1	$v1,$f10
/*  f198d50:	00000000 */ 	sll	$zero,$zero,0x0
.L0f198d54:
/*  f198d54:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f198d58:	2861001f */ 	slti	$at,$v1,0x1f
/*  f198d5c:	14200002 */ 	bnez	$at,.L0f198d68
/*  f198d60:	8de402d4 */ 	lw	$a0,0x2d4($t7)
/*  f198d64:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f198d68:
/*  f198d68:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f198d6c:	00996821 */ 	addu	$t5,$a0,$t9
/*  f198d70:	8dab02a8 */ 	lw	$t3,0x2a8($t5)
/*  f198d74:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f198d78:	01034021 */ 	addu	$t0,$t0,$v1
/*  f198d7c:	05010002 */ 	bgez	$t0,.L0f198d88
/*  f198d80:	01435021 */ 	addu	$t2,$t2,$v1
/*  f198d84:	00004025 */ 	or	$t0,$zero,$zero
.L0f198d88:
/*  f198d88:	05430003 */ 	bgezl	$t2,.L0f198d98
/*  f198d8c:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f198d90:	00005025 */ 	or	$t2,$zero,$zero
.L0f198d94:
/*  f198d94:	8fac0064 */ 	lw	$t4,0x64($sp)
.L0f198d98:
/*  f198d98:	ad880000 */ 	sw	$t0,0x0($t4)
/*  f198d9c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f198da0:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f198da4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f198da8:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f198dac:	03e00008 */ 	jr	$ra
/*  f198db0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f198db4
/*  f198db4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f198db8:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f198dbc:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f198dc0:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f198dc4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f198dc8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f198dcc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f198dd0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f198dd4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f198dd8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f198ddc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f198de0:	0fc660ce */ 	jal	func0f198338
/*  f198de4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f198de8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f198dec:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f198df0:	03e00008 */ 	jr	$ra
/*  f198df4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f198df8
/*  f198df8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f198dfc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f198e00:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f198e04:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f198e08:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f198e0c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f198e10:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f198e14:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f198e18:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f198e1c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f198e20:	0fc660ce */ 	jal	func0f198338
/*  f198e24:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f198e28:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f198e2c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f198e30:	03e00008 */ 	jr	$ra
/*  f198e34:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f198e38
/*  f198e38:	10a00008 */ 	beqz	$a1,.L0f198e5c
/*  f198e3c:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f198e40:	00047100 */ 	sll	$t6,$a0,0x4
/*  f198e44:	3c028008 */ 	lui	$v0,0x8008
/*  f198e48:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f198e4c:	94427eb4 */ 	lhu	$v0,0x7eb4($v0)
/*  f198e50:	00027d80 */ 	sll	$t7,$v0,0x16
/*  f198e54:	03e00008 */ 	jr	$ra
/*  f198e58:	000f1702 */ 	srl	$v0,$t7,0x1c
.L0f198e5c:
/*  f198e5c:	3c028008 */ 	lui	$v0,0x8008
/*  f198e60:	00591021 */ 	addu	$v0,$v0,$t9
/*  f198e64:	94427eb4 */ 	lhu	$v0,0x7eb4($v0)
/*  f198e68:	00024480 */ 	sll	$t0,$v0,0x12
/*  f198e6c:	00081702 */ 	srl	$v0,$t0,0x1c
/*  f198e70:	03e00008 */ 	jr	$ra
/*  f198e74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f198e78
/*  f198e78:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f198e7c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f198e80:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f198e84:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f198e88:	91f80047 */ 	lbu	$t8,0x47($t7)
/*  f198e8c:	17010015 */ 	bne	$t8,$at,.L0f198ee4
/*  f198e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198e94:	10c0000b */ 	beqz	$a2,.L0f198ec4
/*  f198e98:	00055900 */ 	sll	$t3,$a1,0x4
/*  f198e9c:	0005c900 */ 	sll	$t9,$a1,0x4
/*  f198ea0:	3c088008 */ 	lui	$t0,0x8008
/*  f198ea4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f198ea8:	95087eb4 */ 	lhu	$t0,0x7eb4($t0)
/*  f198eac:	00084d80 */ 	sll	$t1,$t0,0x16
/*  f198eb0:	00095702 */ 	srl	$t2,$t1,0x1c
/*  f198eb4:	1140000b */ 	beqz	$t2,.L0f198ee4
/*  f198eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198ebc:	03e00008 */ 	jr	$ra
/*  f198ec0:	00001025 */ 	or	$v0,$zero,$zero
.L0f198ec4:
/*  f198ec4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f198ec8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f198ecc:	958c7eb4 */ 	lhu	$t4,0x7eb4($t4)
/*  f198ed0:	000c6c80 */ 	sll	$t5,$t4,0x12
/*  f198ed4:	000d7702 */ 	srl	$t6,$t5,0x1c
/*  f198ed8:	11c00002 */ 	beqz	$t6,.L0f198ee4
/*  f198edc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198ee0:	00001825 */ 	or	$v1,$zero,$zero
.L0f198ee4:
/*  f198ee4:	03e00008 */ 	jr	$ra
/*  f198ee8:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f198eec
/*  f198eec:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f198ef0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f198ef4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f198ef8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f198efc:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f198f00:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f198f04:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f198f08:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f198f0c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f198f10:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f198f14:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f198f18:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f198f1c:	00802825 */ 	or	$a1,$a0,$zero
/*  f198f20:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f198f24:	afa00098 */ 	sw	$zero,0x98($sp)
/*  f198f28:	10800155 */ 	beqz	$a0,.L0f199480
/*  f198f2c:	0000b025 */ 	or	$s6,$zero,$zero
/*  f198f30:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f198f34:	50400153 */ 	beqzl	$v0,.L0f199484
/*  f198f38:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f198f3c:	8c440020 */ 	lw	$a0,0x20($v0)
/*  f198f40:	afa500a0 */ 	sw	$a1,0xa0($sp)
/*  f198f44:	0fc660b5 */ 	jal	func0f1982d4
/*  f198f48:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f198f4c:	0440000e */ 	bltz	$v0,.L0f198f88
/*  f198f50:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198f54:	8c99004c */ 	lw	$t9,0x4c($a0)
/*  f198f58:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f198f5c:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f198f60:	00194080 */ 	sll	$t0,$t9,0x2
/*  f198f64:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*  f198f68:	00095080 */ 	sll	$t2,$t1,0x2
/*  f198f6c:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f198f70:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f198f74:	030a1821 */ 	addu	$v1,$t8,$t2
/*  f198f78:	8c6b0274 */ 	lw	$t3,0x274($v1)
/*  f198f7c:	8eec0038 */ 	lw	$t4,0x38($s7)
/*  f198f80:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f198f84:	ac6d0274 */ 	sw	$t5,0x274($v1)
.L0f198f88:
/*  f198f88:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198f8c:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f198f90:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f198f94:	8eef0038 */ 	lw	$t7,0x38($s7)
/*  f198f98:	8c8e02c0 */ 	lw	$t6,0x2c0($a0)
/*  f198f9c:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f198fa0:	07210021 */ 	bgez	$t9,.L0f199028
/*  f198fa4:	ac9902c0 */ 	sw	$t9,0x2c0($a0)
/*  f198fa8:	0c004b70 */ 	jal	random
/*  f198fac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f198fb0:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f198fb4:	0041001b */ 	divu	$zero,$v0,$at
/*  f198fb8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198fbc:	00004810 */ 	mfhi	$t1
/*  f198fc0:	25380e10 */ 	addiu	$t8,$t1,0xe10
/*  f198fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b9090)
/*  f198fc8:	ac9802c0 */ 	sw	$t8,0x2c0($a0)
/*  f198fcc:	c4209090 */ 	lwc1	$f0,%lo(var7f1b9090)($at)
/*  f198fd0:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f198fd4:	0000f025 */ 	or	$s8,$zero,$zero
/*  f198fd8:	00801825 */ 	or	$v1,$a0,$zero
/*  f198fdc:	c46c0244 */ 	lwc1	$f12,0x244($v1)
/*  f198fe0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f198fe4:	c4700248 */ 	lwc1	$f16,0x248($v1)
/*  f198fe8:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f198fec:	13c2000a */ 	beq	$s8,$v0,.L0f199018
/*  f198ff0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f198ff4:
/*  f198ff4:	46008382 */ 	mul.s	$f14,$f16,$f0
/*  f198ff8:	c46c024c */ 	lwc1	$f12,0x24c($v1)
/*  f198ffc:	c4700250 */ 	lwc1	$f16,0x250($v1)
/*  f199000:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f199004:	e4720244 */ 	swc1	$f18,0x244($v1)
/*  f199008:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f19900c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f199010:	17c2fff8 */ 	bne	$s8,$v0,.L0f198ff4
/*  f199014:	e46e0240 */ 	swc1	$f14,0x240($v1)
.L0f199018:
/*  f199018:	46008382 */ 	mul.s	$f14,$f16,$f0
/*  f19901c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f199020:	e472023c */ 	swc1	$f18,0x23c($v1)
/*  f199024:	e46e0240 */ 	swc1	$f14,0x240($v1)
.L0f199028:
/*  f199028:	8c8a02a4 */ 	lw	$t2,0x2a4($a0)
/*  f19902c:	8eeb0038 */ 	lw	$t3,0x38($s7)
/*  f199030:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f199034:	0581003a */ 	bgez	$t4,.L0f199120
/*  f199038:	ac8c02a4 */ 	sw	$t4,0x2a4($a0)
/*  f19903c:	0c004b70 */ 	jal	random
/*  f199040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199044:	24010bb8 */ 	addiu	$at,$zero,0xbb8
/*  f199048:	0041001b */ 	divu	$zero,$v0,$at
/*  f19904c:	8fb00090 */ 	lw	$s0,0x90($sp)
/*  f199050:	00007010 */ 	mfhi	$t6
/*  f199054:	25cf0258 */ 	addiu	$t7,$t6,0x258
/*  f199058:	0000f025 */ 	or	$s8,$zero,$zero
/*  f19905c:	00008825 */ 	or	$s1,$zero,$zero
/*  f199060:	2415001e */ 	addiu	$s5,$zero,0x1e
/*  f199064:	24140064 */ 	addiu	$s4,$zero,0x64
/*  f199068:	24130018 */ 	addiu	$s3,$zero,0x18
/*  f19906c:	241200c8 */ 	addiu	$s2,$zero,0xc8
/*  f199070:	ae0f02a4 */ 	sw	$t7,0x2a4($s0)
.L0f199074:
/*  f199074:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f199078:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19907c:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f199080:	93220048 */ 	lbu	$v0,0x48($t9)
/*  f199084:	1440000c */ 	bnez	$v0,.L0f1990b8
/*  f199088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19908c:	0c004b70 */ 	jal	random
/*  f199090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199094:	0052001b */ 	divu	$zero,$v0,$s2
/*  f199098:	00004010 */ 	mfhi	$t0
/*  f19909c:	2509ff9c */ 	addiu	$t1,$t0,-100
/*  f1990a0:	16400002 */ 	bnez	$s2,.L0f1990ac
/*  f1990a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1990a8:	0007000d */ 	break	0x7
.L0f1990ac:
/*  f1990ac:	ae0902a8 */ 	sw	$t1,0x2a8($s0)
/*  f1990b0:	10000018 */ 	beqz	$zero,.L0f199114
/*  f1990b4:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1990b8:
/*  f1990b8:	1441000c */ 	bne	$v0,$at,.L0f1990ec
/*  f1990bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1990c0:	0c004b70 */ 	jal	random
/*  f1990c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1990c8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f1990cc:	0000c010 */ 	mfhi	$t8
/*  f1990d0:	270affce */ 	addiu	$t2,$t8,-50
/*  f1990d4:	16800002 */ 	bnez	$s4,.L0f1990e0
/*  f1990d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1990dc:	0007000d */ 	break	0x7
.L0f1990e0:
/*  f1990e0:	ae0a02a8 */ 	sw	$t2,0x2a8($s0)
/*  f1990e4:	1000000b */ 	beqz	$zero,.L0f199114
/*  f1990e8:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1990ec:
/*  f1990ec:	0c004b70 */ 	jal	random
/*  f1990f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1990f4:	0055001b */ 	divu	$zero,$v0,$s5
/*  f1990f8:	00005810 */ 	mfhi	$t3
/*  f1990fc:	256cfff1 */ 	addiu	$t4,$t3,-15
/*  f199100:	ae0c02a8 */ 	sw	$t4,0x2a8($s0)
/*  f199104:	16a00002 */ 	bnez	$s5,.L0f199110
/*  f199108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19910c:	0007000d */ 	break	0x7
.L0f199110:
/*  f199110:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f199114:
/*  f199114:	1633ffd7 */ 	bne	$s1,$s3,.L0f199074
/*  f199118:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19911c:	8fa40090 */ 	lw	$a0,0x90($sp)
.L0f199120:
/*  f199120:	8c8d020c */ 	lw	$t5,0x20c($a0)
/*  f199124:	8eee0038 */ 	lw	$t6,0x38($s7)
/*  f199128:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f19912c:	05e1000c */ 	bgez	$t7,.L0f199160
/*  f199130:	ac8f020c */ 	sw	$t7,0x20c($a0)
/*  f199134:	0c004b70 */ 	jal	random
/*  f199138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19913c:	24010258 */ 	addiu	$at,$zero,0x258
/*  f199140:	0041001b */ 	divu	$zero,$v0,$at
/*  f199144:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f199148:	00004010 */ 	mfhi	$t0
/*  f19914c:	25090078 */ 	addiu	$t1,$t0,0x78
/*  f199150:	0c004b70 */ 	jal	random
/*  f199154:	af09020c */ 	sw	$t1,0x20c($t8)
/*  f199158:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f19915c:	ac820210 */ 	sw	$v0,0x210($a0)
.L0f199160:
/*  f199160:	8c8b00c8 */ 	lw	$t3,0xc8($a0)
/*  f199164:	556000c7 */ 	bnezl	$t3,.L0f199484
/*  f199168:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19916c:	8c8c00c4 */ 	lw	$t4,0xc4($a0)
/*  f199170:	558000c4 */ 	bnezl	$t4,.L0f199484
/*  f199174:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199178:	908d004e */ 	lbu	$t5,0x4e($a0)
/*  f19917c:	5da000c1 */ 	bgtzl	$t5,.L0f199484
/*  f199180:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199184:	908e004d */ 	lbu	$t6,0x4d($a0)
/*  f199188:	5dc000be */ 	bgtzl	$t6,.L0f199484
/*  f19918c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199190:	848f00e2 */ 	lh	$t7,0xe2($a0)
/*  f199194:	5de000bb */ 	bgtzl	$t7,.L0f199484
/*  f199198:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19919c:	849900e0 */ 	lh	$t9,0xe0($a0)
/*  f1991a0:	5f2000b8 */ 	bgtzl	$t9,.L0f199484
/*  f1991a4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1991a8:	8c880044 */ 	lw	$t0,0x44($a0)
/*  f1991ac:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f1991b0:	550000b4 */ 	bnezl	$t0,.L0f199484
/*  f1991b4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1991b8:	913802a0 */ 	lbu	$t8,0x2a0($t1)
/*  f1991bc:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1991c0:	17010002 */ 	bne	$t8,$at,.L0f1991cc
/*  f1991c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1991c8:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f1991cc:
/*  f1991cc:	16c00009 */ 	bnez	$s6,.L0f1991f4
/*  f1991d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1991d4:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*  f1991d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1991dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1991e0:	914b0047 */ 	lbu	$t3,0x47($t2)
/*  f1991e4:	15610003 */ 	bne	$t3,$at,.L0f1991f4
/*  f1991e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1991ec:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f1991f0:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f1991f4:
/*  f1991f4:	56c00055 */ 	bnezl	$s6,.L0f19934c
/*  f1991f8:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f1991fc:	80830018 */ 	lb	$v1,0x18($a0)
/*  f199200:	00009825 */ 	or	$s3,$zero,$zero
/*  f199204:	241effff */ 	addiu	$s8,$zero,-1
/*  f199208:	0460004f */ 	bltz	$v1,.L0f199348
/*  f19920c:	24170003 */ 	addiu	$s7,$zero,0x3
/*  f199210:	27b6007c */ 	addiu	$s6,$sp,0x7c
/*  f199214:	27b50080 */ 	addiu	$s5,$sp,0x80
/*  f199218:	2411ffff */ 	addiu	$s1,$zero,-1
.L0f19921c:
/*  f19921c:	07c10003 */ 	bgez	$s8,.L0f19922c
/*  f199220:	00009025 */ 	or	$s2,$zero,$zero
/*  f199224:	1000000d */ 	beqz	$zero,.L0f19925c
/*  f199228:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f19922c:
/*  f19922c:	8c8d0014 */ 	lw	$t5,0x14($a0)
/*  f199230:	001e7080 */ 	sll	$t6,$s8,0x2
/*  f199234:	01de7021 */ 	addu	$t6,$t6,$s8
/*  f199238:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19923c:	01ae9021 */ 	addu	$s2,$t5,$t6
/*  f199240:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f199244:	24010001 */ 	addiu	$at,$zero,0x1
/*  f199248:	50410004 */ 	beql	$v0,$at,.L0f19925c
/*  f19924c:	86510004 */ 	lh	$s1,0x4($s2)
/*  f199250:	16e20002 */ 	bne	$s7,$v0,.L0f19925c
/*  f199254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199258:	86510004 */ 	lh	$s1,0x4($s2)
.L0f19925c:
/*  f19925c:	06200036 */ 	bltz	$s1,.L0f199338
/*  f199260:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f199264:	3c198008 */ 	lui	$t9,%hi(var80087eb0)
/*  f199268:	27397eb0 */ 	addiu	$t9,$t9,%lo(var80087eb0)
/*  f19926c:	00117900 */ 	sll	$t7,$s1,0x4
/*  f199270:	01f9a021 */ 	addu	$s4,$t7,$t9
.L0f199274:
/*  f199274:	12000005 */ 	beqz	$s0,.L0f19928c
/*  f199278:	96830004 */ 	lhu	$v1,0x4($s4)
/*  f19927c:	00031440 */ 	sll	$v0,$v1,0x11
/*  f199280:	000247c2 */ 	srl	$t0,$v0,0x1f
/*  f199284:	10000002 */ 	beqz	$zero,.L0f199290
/*  f199288:	01001025 */ 	or	$v0,$t0,$zero
.L0f19928c:
/*  f19928c:	000313c2 */ 	srl	$v0,$v1,0xf
.L0f199290:
/*  f199290:	10400024 */ 	beqz	$v0,.L0f199324
/*  f199294:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f199298:	02202825 */ 	or	$a1,$s1,$zero
/*  f19929c:	0fc6639e */ 	jal	func0f198e78
/*  f1992a0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1992a4:	1040001f */ 	beqz	$v0,.L0f199324
/*  f1992a8:	0012182b */ 	sltu	$v1,$zero,$s2
/*  f1992ac:	10600004 */ 	beqz	$v1,.L0f1992c0
/*  f1992b0:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1992b4:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f1992b8:	02e91826 */ 	xor	$v1,$s7,$t1
/*  f1992bc:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f1992c0:
/*  f1992c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1992c4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1992c8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1992cc:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f1992d0:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f1992d4:	0fc6636d */ 	jal	func0f198db4
/*  f1992d8:	afb60018 */ 	sw	$s6,0x18($sp)
/*  f1992dc:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f1992e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1992e4:	0313082a */ 	slt	$at,$t8,$s3
/*  f1992e8:	5420000f */ 	bnezl	$at,.L0f199328
/*  f1992ec:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f1992f0:	0fc6666c */ 	jal	func0f1999b0
/*  f1992f4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1992f8:	10400007 */ 	beqz	$v0,.L0f199318
/*  f1992fc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199300:	02202825 */ 	or	$a1,$s1,$zero
/*  f199304:	02003025 */ 	or	$a2,$s0,$zero
/*  f199308:	0fc666f9 */ 	jal	func0f199be4
/*  f19930c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199310:	58400005 */ 	blezl	$v0,.L0f199328
/*  f199314:	2610ffff */ 	addiu	$s0,$s0,-1
.L0f199318:
/*  f199318:	8fb30080 */ 	lw	$s3,0x80($sp)
/*  f19931c:	afb1009c */ 	sw	$s1,0x9c($sp)
/*  f199320:	afb00098 */ 	sw	$s0,0x98($sp)
.L0f199324:
/*  f199324:	2610ffff */ 	addiu	$s0,$s0,-1
.L0f199328:
/*  f199328:	0601ffd2 */ 	bgez	$s0,.L0f199274
/*  f19932c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199330:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199334:	80830018 */ 	lb	$v1,0x18($a0)
.L0f199338:
/*  f199338:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f19933c:	03c3082a */ 	slt	$at,$s8,$v1
/*  f199340:	5420ffb6 */ 	bnezl	$at,.L0f19921c
/*  f199344:	2411ffff */ 	addiu	$s1,$zero,-1
.L0f199348:
/*  f199348:	8fab009c */ 	lw	$t3,0x9c($sp)
.L0f19934c:
/*  f19934c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f199350:	24170003 */ 	addiu	$s7,$zero,0x3
/*  f199354:	1561002b */ 	bne	$t3,$at,.L0f199404
/*  f199358:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f19935c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f199360:	0fc666f9 */ 	jal	func0f199be4
/*  f199364:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199368:	28410002 */ 	slti	$at,$v0,0x2
/*  f19936c:	14200025 */ 	bnez	$at,.L0f199404
/*  f199370:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f199374:	858d017e */ 	lh	$t5,0x17e($t4)
/*  f199378:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19937c:	51a10022 */ 	beql	$t5,$at,.L0f199408
/*  f199380:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199384:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f199388:	01802025 */ 	or	$a0,$t4,$zero
/*  f19938c:	0fc633fe */ 	jal	func0f18cff8
/*  f199390:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f199394:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f199398:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19939c:	3c014348 */ 	lui	$at,0x4348
/*  f1993a0:	8dcf02d4 */ 	lw	$t7,0x2d4($t6)
/*  f1993a4:	44818000 */ 	mtc1	$at,$f16
/*  f1993a8:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f1993ac:	c512013c */ 	lwc1	$f18,0x13c($t0)
/*  f1993b0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f1993b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1993b8:	45020013 */ 	bc1fl	.L0f199408
/*  f1993bc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f1993c0:	0fc0a221 */ 	jal	chrGetTargetPosition
/*  f1993c4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1993c8:	0fc633fe */ 	jal	func0f18cff8
/*  f1993cc:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1993d0:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f1993d4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1993d8:	3c017f1c */ 	lui	$at,%hi(var7f1b9094)
/*  f1993dc:	8d3802d4 */ 	lw	$t8,0x2d4($t1)
/*  f1993e0:	c4269094 */ 	lwc1	$f6,%lo(var7f1b9094)($at)
/*  f1993e4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1993e8:	030a5821 */ 	addu	$t3,$t8,$t2
/*  f1993ec:	c564013c */ 	lwc1	$f4,0x13c($t3)
/*  f1993f0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1993f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1993f8:	45020003 */ 	bc1fl	.L0f199408
/*  f1993fc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199400:	afad0098 */ 	sw	$t5,0x98($sp)
.L0f199404:
/*  f199404:	8fa40090 */ 	lw	$a0,0x90($sp)
.L0f199408:
/*  f199408:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f19940c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f199410:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f199414:	918f0047 */ 	lbu	$t7,0x47($t4)
/*  f199418:	56ef0016 */ 	bnel	$s7,$t7,.L0f199474
/*  f19941c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f199420:	17210008 */ 	bne	$t9,$at,.L0f199444
/*  f199424:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f199428:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19942c:	0fc666f9 */ 	jal	func0f199be4
/*  f199430:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199434:	18400003 */ 	blez	$v0,.L0f199444
/*  f199438:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f19943c:	1000000c */ 	beqz	$zero,.L0f199470
/*  f199440:	afa80098 */ 	sw	$t0,0x98($sp)
.L0f199444:
/*  f199444:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f199448:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19944c:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199450:	15c10007 */ 	bne	$t6,$at,.L0f199470
/*  f199454:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f199458:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19945c:	0fc666f9 */ 	jal	func0f199be4
/*  f199460:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199464:	18400002 */ 	blez	$v0,.L0f199470
/*  f199468:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f19946c:	afa90098 */ 	sw	$t1,0x98($sp)
.L0f199470:
/*  f199470:	8fa400a0 */ 	lw	$a0,0xa0($sp)
.L0f199474:
/*  f199474:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f199478:	0fc6652c */ 	jal	func0f1994b0
/*  f19947c:	8fa60098 */ 	lw	$a2,0x98($sp)
.L0f199480:
/*  f199480:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f199484:
/*  f199484:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f199488:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f19948c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f199490:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f199494:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f199498:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f19949c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f1994a0:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f1994a4:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f1994a8:	03e00008 */ 	jr	$ra
/*  f1994ac:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f1994b0
/*  f1994b0:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1994b4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1994b8:	00809025 */ 	or	$s2,$a0,$zero
/*  f1994bc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1994c0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1994c4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1994c8:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f1994cc:	10800006 */ 	beqz	$a0,.L0f1994e8
/*  f1994d0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f1994d4:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f1994d8:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f1994dc:	24010057 */ 	addiu	$at,$zero,0x57
/*  f1994e0:	14400003 */ 	bnez	$v0,.L0f1994f0
/*  f1994e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1994e8:
/*  f1994e8:	100000a2 */ 	beqz	$zero,.L0f199774
/*  f1994ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f1994f0:
/*  f1994f0:	15c10003 */ 	bne	$t6,$at,.L0f199500
/*  f1994f4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1994f8:	1000009e */ 	beqz	$zero,.L0f199774
/*  f1994fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f199500:
/*  f199500:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f199504:	24010001 */ 	addiu	$at,$zero,0x1
/*  f199508:	02402025 */ 	or	$a0,$s2,$zero
/*  f19950c:	51e10009 */ 	beql	$t7,$at,.L0f199534
/*  f199510:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f199514:	0fc65f3c */ 	jal	func0f197cf0
/*  f199518:	01e02825 */ 	or	$a1,$t7,$zero
/*  f19951c:	14400004 */ 	bnez	$v0,.L0f199530
/*  f199520:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f199524:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f199528:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f19952c:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f199530:
/*  f199530:	8fb90064 */ 	lw	$t9,0x64($sp)
.L0f199534:
/*  f199534:	8e2a0020 */ 	lw	$t2,0x20($s1)
/*  f199538:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f19953c:	02204025 */ 	or	$t0,$s1,$zero
/*  f199540:	032a5826 */ 	xor	$t3,$t9,$t2
/*  f199544:	000b582b */ 	sltu	$t3,$zero,$t3
/*  f199548:	afab0048 */ 	sw	$t3,0x48($sp)
/*  f19954c:	8e2d004c */ 	lw	$t5,0x4c($s1)
/*  f199550:	2419003c */ 	addiu	$t9,$zero,0x3c
/*  f199554:	02202025 */ 	or	$a0,$s1,$zero
/*  f199558:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f19955c:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f199560:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f199564:	0018c02b */ 	sltu	$t8,$zero,$t8
/*  f199568:	11600016 */ 	beqz	$t3,.L0f1995c4
/*  f19956c:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f199570:	ae3900cc */ 	sw	$t9,0xcc($s1)
/*  f199574:	00002825 */ 	or	$a1,$zero,$zero
/*  f199578:	02203025 */ 	or	$a2,$s1,$zero
/*  f19957c:	02403825 */ 	or	$a3,$s2,$zero
/*  f199580:	24090004 */ 	addiu	$t1,$zero,0x4
.L0f199584:
/*  f199584:	ad0000c4 */ 	sw	$zero,0xc4($t0)
/*  f199588:	a080004d */ 	sb	$zero,0x4d($a0)
/*  f19958c:	a4c000e0 */ 	sh	$zero,0xe0($a2)
/*  f199590:	8ce20170 */ 	lw	$v0,0x170($a3)
/*  f199594:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f199598:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f19959c:	10400006 */ 	beqz	$v0,.L0f1995b8
/*  f1995a0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f1995a4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f1995a8:	8c6a0040 */ 	lw	$t2,0x40($v1)
/*  f1995ac:	354d0004 */ 	ori	$t5,$t2,0x4
/*  f1995b0:	ac6d0040 */ 	sw	$t5,0x40($v1)
/*  f1995b4:	ace00170 */ 	sw	$zero,0x170($a3)
.L0f1995b8:
/*  f1995b8:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f1995bc:	14a9fff1 */ 	bne	$a1,$t1,.L0f199584
/*  f1995c0:	24e70004 */ 	addiu	$a3,$a3,0x4
.L0f1995c4:
/*  f1995c4:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f1995c8:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f1995cc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1995d0:	15c00002 */ 	bnez	$t6,.L0f1995dc
/*  f1995d4:	02204025 */ 	or	$t0,$s1,$zero
/*  f1995d8:	11800012 */ 	beqz	$t4,.L0f199624
.L0f1995dc:
/*  f1995dc:	24100008 */ 	addiu	$s0,$zero,0x8
.L0f1995e0:
/*  f1995e0:	8d070024 */ 	lw	$a3,0x24($t0)
/*  f1995e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1995e8:	58e0000c */ 	blezl	$a3,.L0f19961c
/*  f1995ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1995f0:	8e26004c */ 	lw	$a2,0x4c($s1)
/*  f1995f4:	8e250020 */ 	lw	$a1,0x20($s1)
/*  f1995f8:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f1995fc:	00067880 */ 	sll	$t7,$a2,0x2
/*  f199600:	000f37c2 */ 	srl	$a2,$t7,0x1f
/*  f199604:	0fc6678f */ 	jal	func0f199e3c
/*  f199608:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f19960c:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f199610:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f199614:	ad000024 */ 	sw	$zero,0x24($t0)
/*  f199618:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f19961c:
/*  f19961c:	1470fff0 */ 	bne	$v1,$s0,.L0f1995e0
/*  f199620:	25080004 */ 	addiu	$t0,$t0,0x4
.L0f199624:
/*  f199624:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f199628:	922e004c */ 	lbu	$t6,0x4c($s1)
/*  f19962c:	00195140 */ 	sll	$t2,$t9,0x5
/*  f199630:	314d0020 */ 	andi	$t5,$t2,0x20
/*  f199634:	31ccffdf */ 	andi	$t4,$t6,0xffdf
/*  f199638:	01ac7825 */ 	or	$t7,$t5,$t4
/*  f19963c:	a22f004c */ 	sb	$t7,0x4c($s1)
/*  f199640:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f199644:	ae380020 */ 	sw	$t8,0x20($s1)
/*  f199648:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f19964c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f199650:	51600011 */ 	beqzl	$t3,.L0f199698
/*  f199654:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f199658:	1720000e */ 	bnez	$t9,.L0f199694
/*  f19965c:	00008025 */ 	or	$s0,$zero,$zero
/*  f199660:	02403825 */ 	or	$a3,$s2,$zero
.L0f199664:
/*  f199664:	8cea0170 */ 	lw	$t2,0x170($a3)
/*  f199668:	02402025 */ 	or	$a0,$s2,$zero
/*  f19966c:	02002825 */ 	or	$a1,$s0,$zero
/*  f199670:	11400004 */ 	beqz	$t2,.L0f199684
/*  f199674:	00003025 */ 	or	$a2,$zero,$zero
/*  f199678:	0fc66690 */ 	jal	func0f199a40
/*  f19967c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f199680:	8fa7002c */ 	lw	$a3,0x2c($sp)
.L0f199684:
/*  f199684:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f199688:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19968c:	1601fff5 */ 	bne	$s0,$at,.L0f199664
/*  f199690:	24e70004 */ 	addiu	$a3,$a3,0x4
.L0f199694:
/*  f199694:	8fae0048 */ 	lw	$t6,0x48($sp)
.L0f199698:
/*  f199698:	55c00018 */ 	bnezl	$t6,.L0f1996fc
/*  f19969c:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f1996a0:	0fc4a2bd */ 	jal	func0f128af4
/*  f1996a4:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f1996a8:	04400013 */ 	bltz	$v0,.L0f1996f8
/*  f1996ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f1996b0:	8fad005c */ 	lw	$t5,0x5c($sp)
/*  f1996b4:	51a00011 */ 	beqzl	$t5,.L0f1996fc
/*  f1996b8:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f1996bc:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f1996c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1996c4:	5581000d */ 	bnel	$t4,$at,.L0f1996fc
/*  f1996c8:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f1996cc:	8e4f0174 */ 	lw	$t7,0x174($s2)
/*  f1996d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1996d4:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f1996d8:	55e00008 */ 	bnezl	$t7,.L0f1996fc
/*  f1996dc:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f1996e0:	0fc22eb4 */ 	jal	func0f08bad0
/*  f1996e4:	3c071000 */ 	lui	$a3,0x1000
/*  f1996e8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1996ec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1996f0:	0fc66690 */ 	jal	func0f199a40
/*  f1996f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f1996f8:
/*  f1996f8:	8fa40064 */ 	lw	$a0,0x64($sp)
.L0f1996fc:
/*  f1996fc:	0fc2c401 */ 	jal	func0f0b1004
/*  f199700:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f199704:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f199708:	10800004 */ 	beqz	$a0,.L0f19971c
/*  f19970c:	00001825 */ 	or	$v1,$zero,$zero
/*  f199710:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f199714:	38980003 */ 	xori	$t8,$a0,0x3
/*  f199718:	2f040001 */ 	sltiu	$a0,$t8,0x1
.L0f19971c:
/*  f19971c:	922e004c */ 	lbu	$t6,0x4c($s1)
/*  f199720:	00805825 */ 	or	$t3,$a0,$zero
/*  f199724:	000bc980 */ 	sll	$t9,$t3,0x6
/*  f199728:	332a0040 */ 	andi	$t2,$t9,0x40
/*  f19972c:	31cdffbf */ 	andi	$t5,$t6,0xffbf
/*  f199730:	014d6025 */ 	or	$t4,$t2,$t5
/*  f199734:	a22c004c */ 	sb	$t4,0x4c($s1)
/*  f199738:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f19973c:	02403825 */ 	or	$a3,$s2,$zero
.L0f199740:
/*  f199740:	8ce20170 */ 	lw	$v0,0x170($a3)
/*  f199744:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f199748:	10400007 */ 	beqz	$v0,.L0f199768
/*  f19974c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199750:	8e4f02d4 */ 	lw	$t7,0x2d4($s2)
/*  f199754:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f199758:	8df8004c */ 	lw	$t8,0x4c($t7)
/*  f19975c:	00185880 */ 	sll	$t3,$t8,0x2
/*  f199760:	000bcfc2 */ 	srl	$t9,$t3,0x1f
/*  f199764:	a1d9005f */ 	sb	$t9,0x5f($t6)
.L0f199768:
/*  f199768:	1464fff5 */ 	bne	$v1,$a0,.L0f199740
/*  f19976c:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f199770:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f199774:
/*  f199774:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f199778:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19977c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f199780:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f199784:	03e00008 */ 	jr	$ra
/*  f199788:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f19978c
/*  f19978c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f199790:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f199794:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f199798:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f19979c:	00809825 */ 	or	$s3,$a0,$zero
/*  f1997a0:	30d400ff */ 	andi	$s4,$a2,0xff
/*  f1997a4:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f1997a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1997ac:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f1997b0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1997b4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1997b8:	10800061 */ 	beqz	$a0,.L0f199940
/*  f1997bc:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1997c0:	8c8402d4 */ 	lw	$a0,0x2d4($a0)
/*  f1997c4:	5080005f */ 	beqzl	$a0,.L0f199944
/*  f1997c8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1997cc:	80830018 */ 	lb	$v1,0x18($a0)
/*  f1997d0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1997d4:	18600047 */ 	blez	$v1,.L0f1998f4
/*  f1997d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1997dc:	8c8e0014 */ 	lw	$t6,0x14($a0)
.L0f1997e0:
/*  f1997e0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1997e4:	01d28821 */ 	addu	$s1,$t6,$s2
/*  f1997e8:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f1997ec:	54410006 */ 	bnel	$v0,$at,.L0f199808
/*  f1997f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1997f4:	00031080 */ 	sll	$v0,$v1,0x2
/*  f1997f8:	00431021 */ 	addu	$v0,$v0,$v1
/*  f1997fc:	10000039 */ 	beqz	$zero,.L0f1998e4
/*  f199800:	00021080 */ 	sll	$v0,$v0,0x2
/*  f199804:	24010001 */ 	addiu	$at,$zero,0x1
.L0f199808:
/*  f199808:	10410003 */ 	beq	$v0,$at,.L0f199818
/*  f19980c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f199810:	54410030 */ 	bnel	$v0,$at,.L0f1998d4
/*  f199814:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
.L0f199818:
/*  f199818:	16800004 */ 	bnez	$s4,.L0f19982c
/*  f19981c:	3c050800 */ 	lui	$a1,0x800
/*  f199820:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f199824:	56af002b */ 	bnel	$s5,$t7,.L0f1998d4
/*  f199828:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
.L0f19982c:
/*  f19982c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f199830:	86240004 */ 	lh	$a0,0x4($s1)
/*  f199834:	1040000d */ 	beqz	$v0,.L0f19986c
/*  f199838:	3c18800a */ 	lui	$t8,0x800a
/*  f19983c:	8f18a2d8 */ 	lw	$t8,-0x5d28($t8)
/*  f199840:	3c19800b */ 	lui	$t9,0x800b
/*  f199844:	53000023 */ 	beqzl	$t8,.L0f1998d4
/*  f199848:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
/*  f19984c:	9339cb98 */ 	lbu	$t9,-0x3468($t9)
/*  f199850:	24010002 */ 	addiu	$at,$zero,0x2
/*  f199854:	5721001f */ 	bnel	$t9,$at,.L0f1998d4
/*  f199858:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
/*  f19985c:	86280004 */ 	lh	$t0,0x4($s1)
/*  f199860:	24010036 */ 	addiu	$at,$zero,0x36
/*  f199864:	5501001b */ 	bnel	$t0,$at,.L0f1998d4
/*  f199868:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
.L0f19986c:
/*  f19986c:	0fc4a2bd */ 	jal	func0f128af4
/*  f199870:	86240004 */ 	lh	$a0,0x4($s1)
/*  f199874:	18400016 */ 	blez	$v0,.L0f1998d0
/*  f199878:	00402825 */ 	or	$a1,$v0,$zero
/*  f19987c:	86260004 */ 	lh	$a2,0x4($s1)
/*  f199880:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f199884:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f199888:	02602025 */ 	or	$a0,$s3,$zero
/*  f19988c:	0fc22e3a */ 	jal	func0f08b8e8
/*  f199890:	3c072000 */ 	lui	$a3,0x2000
/*  f199894:	1040000e */ 	beqz	$v0,.L0f1998d0
/*  f199898:	00408025 */ 	or	$s0,$v0,$zero
/*  f19989c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1998a0:	0fc20a59 */ 	jal	func0f082964
/*  f1998a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1998a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1998ac:	0fc20c1f */ 	jal	func0f08307c
/*  f1998b0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1998b4:	86290004 */ 	lh	$t1,0x4($s1)
/*  f1998b8:	24010057 */ 	addiu	$at,$zero,0x57
/*  f1998bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f1998c0:	55210004 */ 	bnel	$t1,$at,.L0f1998d4
/*  f1998c4:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
/*  f1998c8:	0fc61ca2 */ 	jal	func0f187288
/*  f1998cc:	02002825 */ 	or	$a1,$s0,$zero
.L0f1998d0:
/*  f1998d0:	8e6402d4 */ 	lw	$a0,0x2d4($s3)
.L0f1998d4:
/*  f1998d4:	80830018 */ 	lb	$v1,0x18($a0)
/*  f1998d8:	00031080 */ 	sll	$v0,$v1,0x2
/*  f1998dc:	00431021 */ 	addu	$v0,$v0,$v1
/*  f1998e0:	00021080 */ 	sll	$v0,$v0,0x2
.L0f1998e4:
/*  f1998e4:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1998e8:	0242082a */ 	slt	$at,$s2,$v0
/*  f1998ec:	5420ffbc */ 	bnezl	$at,.L0f1997e0
/*  f1998f0:	8c8e0014 */ 	lw	$t6,0x14($a0)
.L0f1998f4:
/*  f1998f4:	12800003 */ 	beqz	$s4,.L0f199904
/*  f1998f8:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f1998fc:	50200006 */ 	beqzl	$at,.L0f199918
/*  f199900:	02602025 */ 	or	$a0,$s3,$zero
.L0f199904:
/*  f199904:	56800008 */ 	bnezl	$s4,.L0f199928
/*  f199908:	8e6b0014 */ 	lw	$t3,0x14($s3)
/*  f19990c:	8c8a0020 */ 	lw	$t2,0x20($a0)
/*  f199910:	16aa0004 */ 	bne	$s5,$t2,.L0f199924
/*  f199914:	02602025 */ 	or	$a0,$s3,$zero
.L0f199918:
/*  f199918:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19991c:	0fc6652c */ 	jal	func0f1994b0
/*  f199920:	00003025 */ 	or	$a2,$zero,$zero
.L0f199924:
/*  f199924:	8e6b0014 */ 	lw	$t3,0x14($s3)
.L0f199928:
/*  f199928:	02602025 */ 	or	$a0,$s3,$zero
/*  f19992c:	356c0001 */ 	ori	$t4,$t3,0x1
/*  f199930:	16800003 */ 	bnez	$s4,.L0f199940
/*  f199934:	ae6c0014 */ 	sw	$t4,0x14($s3)
/*  f199938:	0fc65f65 */ 	jal	func0f197d94
/*  f19993c:	02a02825 */ 	or	$a1,$s5,$zero
.L0f199940:
/*  f199940:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f199944:
/*  f199944:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f199948:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f19994c:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f199950:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f199954:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f199958:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f19995c:	03e00008 */ 	jr	$ra
/*  f199960:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f199964
/*  f199964:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f199968:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19996c:	0fc665e3 */ 	jal	func0f19978c
/*  f199970:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f199974:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199978:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19997c:	03e00008 */ 	jr	$ra
/*  f199980:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199984
/*  f199984:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f199988:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19998c:	0fc665e3 */ 	jal	func0f19978c
/*  f199990:	00003025 */ 	or	$a2,$zero,$zero
/*  f199994:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199998:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19999c:	03e00008 */ 	jr	$ra
/*  f1999a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1999a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1999a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1999ac:	00000000 */ 	sll	$zero,$zero,0x0
);
