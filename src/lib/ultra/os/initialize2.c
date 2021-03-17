#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

/**
 * Note: This file is included in PAL only.
 */

typedef struct {
	unsigned int inst1;
	unsigned int inst2;
	unsigned int inst3;
	unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble;
extern u32 osAppNMIBuffer;

u32 var80060fe0pf = 0;
u32 var80060fe4pf = 62500000;
s32 osViClock = VI_NTSC_CLOCK;
u32 var80060fecpf = 0;
u32 var80060ff0pf = OS_IM_ALL;

GLOBAL_ASM(
glabel osInitialize2
/*    517c0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    517c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    517c8:	240e0001 */ 	li	$t6,0x1
/*    517cc:	3c018009 */ 	lui	$at,0x8009
/*    517d0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    517d4:	afa00030 */ 	sw	$zero,0x30($sp)
/*    517d8:	0c012974 */ 	jal	__osGetSR
/*    517dc:	ac2e0fb0 */ 	sw	$t6,0xfb0($at)
/*    517e0:	00408025 */ 	move	$s0,$v0
/*    517e4:	3c012000 */ 	lui	$at,0x2000
/*    517e8:	0c012970 */ 	jal	__osSetSR
/*    517ec:	02012025 */ 	or	$a0,$s0,$at
/*    517f0:	3c040100 */ 	lui	$a0,0x100
/*    517f4:	0c011eb8 */ 	jal	__osSetFpcCsr
/*    517f8:	34840800 */ 	ori	$a0,$a0,0x800
/*    517fc:	3c041fc0 */ 	lui	$a0,0x1fc0
/*    51800:	348407fc */ 	ori	$a0,$a0,0x7fc
/*    51804:	0c012978 */ 	jal	__osSiRawReadIo
/*    51808:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    5180c:	10400007 */ 	beqz	$v0,.PF0005182c
/*    51810:	00000000 */ 	nop
.PF00051814:
/*    51814:	3c041fc0 */ 	lui	$a0,0x1fc0
/*    51818:	348407fc */ 	ori	$a0,$a0,0x7fc
/*    5181c:	0c012978 */ 	jal	__osSiRawReadIo
/*    51820:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    51824:	1440fffb */ 	bnez	$v0,.PF00051814
/*    51828:	00000000 */ 	nop
.PF0005182c:
/*    5182c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    51830:	3c041fc0 */ 	lui	$a0,0x1fc0
/*    51834:	348407fc */ 	ori	$a0,$a0,0x7fc
/*    51838:	34af0008 */ 	ori	$t7,$a1,0x8
/*    5183c:	0c01298c */ 	jal	__osSiRawWriteIo
/*    51840:	01e02825 */ 	move	$a1,$t7
/*    51844:	10400009 */ 	beqz	$v0,.PF0005186c
/*    51848:	00000000 */ 	nop
.PF0005184c:
/*    5184c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    51850:	3c041fc0 */ 	lui	$a0,0x1fc0
/*    51854:	348407fc */ 	ori	$a0,$a0,0x7fc
/*    51858:	34b80008 */ 	ori	$t8,$a1,0x8
/*    5185c:	0c01298c */ 	jal	__osSiRawWriteIo
/*    51860:	03002825 */ 	move	$a1,$t8
/*    51864:	1440fff9 */ 	bnez	$v0,.PF0005184c
/*    51868:	00000000 */ 	nop
.PF0005186c:
/*    5186c:	3c087000 */ 	lui	$t0,0x7000
/*    51870:	250834c0 */ 	addiu	$t0,$t0,0x34c0
/*    51874:	8d010000 */ 	lw	$at,0x0($t0)
/*    51878:	3c198000 */ 	lui	$t9,0x8000
/*    5187c:	3c0d7000 */ 	lui	$t5,0x7000
/*    51880:	af210000 */ 	sw	$at,0x0($t9)
/*    51884:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*    51888:	25ad34c0 */ 	addiu	$t5,$t5,0x34c0
/*    5188c:	3c0c8000 */ 	lui	$t4,0x8000
/*    51890:	af2b0004 */ 	sw	$t3,0x4($t9)
/*    51894:	8d010008 */ 	lw	$at,0x8($t0)
/*    51898:	358c0080 */ 	ori	$t4,$t4,0x80
/*    5189c:	3c097000 */ 	lui	$t1,0x7000
/*    518a0:	af210008 */ 	sw	$at,0x8($t9)
/*    518a4:	8d0b000c */ 	lw	$t3,0xc($t0)
/*    518a8:	252934c0 */ 	addiu	$t1,$t1,0x34c0
/*    518ac:	3c0a8000 */ 	lui	$t2,0x8000
/*    518b0:	af2b000c */ 	sw	$t3,0xc($t9)
/*    518b4:	8da10000 */ 	lw	$at,0x0($t5)
/*    518b8:	354a0100 */ 	ori	$t2,$t2,0x100
/*    518bc:	3c0e7000 */ 	lui	$t6,0x7000
/*    518c0:	ad810000 */ 	sw	$at,0x0($t4)
/*    518c4:	8db80004 */ 	lw	$t8,0x4($t5)
/*    518c8:	25ce34c0 */ 	addiu	$t6,$t6,0x34c0
/*    518cc:	3c0f8000 */ 	lui	$t7,0x8000
/*    518d0:	ad980004 */ 	sw	$t8,0x4($t4)
/*    518d4:	8da10008 */ 	lw	$at,0x8($t5)
/*    518d8:	35ef0180 */ 	ori	$t7,$t7,0x180
/*    518dc:	3c048000 */ 	lui	$a0,0x8000
/*    518e0:	ad810008 */ 	sw	$at,0x8($t4)
/*    518e4:	8db8000c */ 	lw	$t8,0xc($t5)
/*    518e8:	24050190 */ 	li	$a1,0x190
/*    518ec:	ad98000c */ 	sw	$t8,0xc($t4)
/*    518f0:	8d210000 */ 	lw	$at,0x0($t1)
/*    518f4:	ad410000 */ 	sw	$at,0x0($t2)
/*    518f8:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*    518fc:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*    51900:	8d210008 */ 	lw	$at,0x8($t1)
/*    51904:	ad410008 */ 	sw	$at,0x8($t2)
/*    51908:	8d2b000c */ 	lw	$t3,0xc($t1)
/*    5190c:	ad4b000c */ 	sw	$t3,0xc($t2)
/*    51910:	8dc10000 */ 	lw	$at,0x0($t6)
/*    51914:	ade10000 */ 	sw	$at,0x0($t7)
/*    51918:	8dd80004 */ 	lw	$t8,0x4($t6)
/*    5191c:	adf80004 */ 	sw	$t8,0x4($t7)
/*    51920:	8dc10008 */ 	lw	$at,0x8($t6)
/*    51924:	ade10008 */ 	sw	$at,0x8($t7)
/*    51928:	8dd8000c */ 	lw	$t8,0xc($t6)
/*    5192c:	0c0129a0 */ 	jal	osWritebackDCache
/*    51930:	adf8000c */ 	sw	$t8,0xc($t7)
/*    51934:	3c048000 */ 	lui	$a0,0x8000
/*    51938:	0c011e94 */ 	jal	osInvalICache
/*    5193c:	24050190 */ 	li	$a1,0x190
/*    51940:	0c01469a */ 	jal	func00051a68pf
/*    51944:	00000000 */ 	nop
/*    51948:	0c014820 */ 	jal	osUnmapTLBAll
/*    5194c:	00000000 */ 	nop
/*    51950:	0c000bf0 */ 	jal	osMapTLBRdb
/*    51954:	00000000 */ 	nop
/*    51958:	3c048006 */ 	lui	$a0,0x8006
/*    5195c:	3c058006 */ 	lui	$a1,0x8006
/*    51960:	8ca5cc14 */ 	lw	$a1,-0x33ec($a1)
/*    51964:	8c84cc10 */ 	lw	$a0,-0x33f0($a0)
/*    51968:	24060000 */ 	li	$a2,0x0
/*    5196c:	0c0136da */ 	jal	__ll_mul
/*    51970:	24070003 */ 	li	$a3,0x3
/*    51974:	afa20020 */ 	sw	$v0,0x20($sp)
/*    51978:	afa30024 */ 	sw	$v1,0x24($sp)
/*    5197c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    51980:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    51984:	24060000 */ 	li	$a2,0x0
/*    51988:	0c01369a */ 	jal	__ull_div
/*    5198c:	24070004 */ 	li	$a3,0x4
/*    51990:	3c088000 */ 	lui	$t0,0x8000
/*    51994:	8d08030c */ 	lw	$t0,0x30c($t0)
/*    51998:	3c018006 */ 	lui	$at,0x8006
/*    5199c:	ac22cc10 */ 	sw	$v0,-0x33f0($at)
/*    519a0:	15000005 */ 	bnez	$t0,.PF000519b8
/*    519a4:	ac23cc14 */ 	sw	$v1,-0x33ec($at)
/*    519a8:	3c048000 */ 	lui	$a0,0x8000
/*    519ac:	2484031c */ 	addiu	$a0,$a0,0x31c
/*    519b0:	0c0129c0 */ 	jal	bzero
/*    519b4:	24050040 */ 	li	$a1,0x40
.PF000519b8:
/*    519b8:	3c198000 */ 	lui	$t9,0x8000
/*    519bc:	8f390300 */ 	lw	$t9,0x300($t9)
/*    519c0:	17200006 */ 	bnez	$t9,.PF000519dc
/*    519c4:	00000000 */ 	nop
/*    519c8:	3c0a02f5 */ 	lui	$t2,0x2f5
/*    519cc:	354ab2d2 */ 	ori	$t2,$t2,0xb2d2
/*    519d0:	3c018006 */ 	lui	$at,0x8006
/*    519d4:	1000000f */ 	b	.PF00051a14
/*    519d8:	ac2a0fe8 */ 	sw	$t2,0xfe8($at)
.PF000519dc:
/*    519dc:	3c098000 */ 	lui	$t1,0x8000
/*    519e0:	8d290300 */ 	lw	$t1,0x300($t1)
/*    519e4:	24010002 */ 	li	$at,0x2
/*    519e8:	15210006 */ 	bne	$t1,$at,.PF00051a04
/*    519ec:	00000000 */ 	nop
/*    519f0:	3c0b02e6 */ 	lui	$t3,0x2e6
/*    519f4:	356b025c */ 	ori	$t3,$t3,0x25c
/*    519f8:	3c018006 */ 	lui	$at,0x8006
/*    519fc:	10000005 */ 	b	.PF00051a14
/*    51a00:	ac2b0fe8 */ 	sw	$t3,0xfe8($at)
.PF00051a04:
/*    51a04:	3c0d02e6 */ 	lui	$t5,0x2e6
/*    51a08:	35add354 */ 	ori	$t5,$t5,0xd354
/*    51a0c:	3c018006 */ 	lui	$at,0x8006
/*    51a10:	ac2d0fe8 */ 	sw	$t5,0xfe8($at)
.PF00051a14:
/*    51a14:	0c0129e8 */ 	jal	__osGetCause
/*    51a18:	00000000 */ 	nop
/*    51a1c:	304c1000 */ 	andi	$t4,$v0,0x1000
/*    51a20:	11800003 */ 	beqz	$t4,.PF00051a30
/*    51a24:	00000000 */ 	nop
.PF00051a28:
/*    51a28:	1000ffff */ 	b	.PF00051a28
/*    51a2c:	00000000 */ 	nop
.PF00051a30:
/*    51a30:	240f0001 */ 	li	$t7,0x1
/*    51a34:	3c0ea450 */ 	lui	$t6,0xa450
/*    51a38:	adcf0008 */ 	sw	$t7,0x8($t6)
/*    51a3c:	24183fff */ 	li	$t8,0x3fff
/*    51a40:	3c08a450 */ 	lui	$t0,0xa450
/*    51a44:	ad180010 */ 	sw	$t8,0x10($t0)
/*    51a48:	2419000f */ 	li	$t9,0xf
/*    51a4c:	3c0aa450 */ 	lui	$t2,0xa450
/*    51a50:	ad590014 */ 	sw	$t9,0x14($t2)
/*    51a54:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    51a58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    51a5c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    51a60:	03e00008 */ 	jr	$ra
/*    51a64:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00051a68pf
/*    51a68:	240e0007 */ 	li	$t6,0x7
/*    51a6c:	3c018009 */ 	lui	$at,0x8009
/*    51a70:	a02e07f4 */ 	sb	$t6,0x7f4($at)
/*    51a74:	3c0fa460 */ 	lui	$t7,0xa460
/*    51a78:	8df80014 */ 	lw	$t8,0x14($t7)
/*    51a7c:	3c018009 */ 	lui	$at,0x8009
/*    51a80:	3c19a460 */ 	lui	$t9,0xa460
/*    51a84:	a03807f5 */ 	sb	$t8,0x7f5($at)
/*    51a88:	8f280018 */ 	lw	$t0,0x18($t9)
/*    51a8c:	3c018009 */ 	lui	$at,0x8009
/*    51a90:	3c09a460 */ 	lui	$t1,0xa460
/*    51a94:	a02807f8 */ 	sb	$t0,0x7f8($at)
/*    51a98:	8d2a001c */ 	lw	$t2,0x1c($t1)
/*    51a9c:	3c018009 */ 	lui	$at,0x8009
/*    51aa0:	3c0ba460 */ 	lui	$t3,0xa460
/*    51aa4:	a02a07f6 */ 	sb	$t2,0x7f6($at)
/*    51aa8:	8d6c0020 */ 	lw	$t4,0x20($t3)
/*    51aac:	3c018009 */ 	lui	$at,0x8009
/*    51ab0:	240d0007 */ 	li	$t5,0x7
/*    51ab4:	a02c07f7 */ 	sb	$t4,0x7f7($at)
/*    51ab8:	3c018009 */ 	lui	$at,0x8009
/*    51abc:	a02d086c */ 	sb	$t5,0x86c($at)
/*    51ac0:	3c0ea460 */ 	lui	$t6,0xa460
/*    51ac4:	8dcf0024 */ 	lw	$t7,0x24($t6)
/*    51ac8:	3c018009 */ 	lui	$at,0x8009
/*    51acc:	3c18a460 */ 	lui	$t8,0xa460
/*    51ad0:	a02f086d */ 	sb	$t7,0x86d($at)
/*    51ad4:	8f190028 */ 	lw	$t9,0x28($t8)
/*    51ad8:	3c018009 */ 	lui	$at,0x8009
/*    51adc:	3c08a460 */ 	lui	$t0,0xa460
/*    51ae0:	a0390870 */ 	sb	$t9,0x870($at)
/*    51ae4:	8d09002c */ 	lw	$t1,0x2c($t0)
/*    51ae8:	3c018009 */ 	lui	$at,0x8009
/*    51aec:	3c0aa460 */ 	lui	$t2,0xa460
/*    51af0:	a029086e */ 	sb	$t1,0x86e($at)
/*    51af4:	8d4b0030 */ 	lw	$t3,0x30($t2)
/*    51af8:	3c018009 */ 	lui	$at,0x8009
/*    51afc:	03e00008 */ 	jr	$ra
/*    51b00:	a02b086f */ 	sb	$t3,0x86f($at)
);
