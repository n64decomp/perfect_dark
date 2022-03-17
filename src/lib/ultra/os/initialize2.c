#include <os.h>
#include <os_internal.h>
#include <R4300.h>
#include <rcp.h>
#include "versions.h"

/**
 * Note: This file is included in PAL and JPN only.
 */

typedef struct {
	unsigned int inst1;
	unsigned int inst2;
	unsigned int inst3;
	unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble;
extern s32 osAppNMIBuffer[];

extern u32 __osFinalRom;
extern OSTime osClockRate;

OSTime osClockRate2 = 62500000;
s32 osViClock = VI_NTSC_CLOCK;
u32 var80060fecpf = 0;
u32 var80060ff0pf = OS_IM_ALL;

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel osInitialize2
/*  519d0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  519d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  519d8:	240e0001 */ 	li	$t6,0x1
/*  519dc:	3c018009 */ 	lui	$at,0x8009
/*  519e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  519e4:	afa00030 */ 	sw	$zero,0x30($sp)
/*  519e8:	0c0129f8 */ 	jal	__osGetSR
/*  519ec:	ac2e10d0 */ 	sw	$t6,0x10d0($at)
/*  519f0:	00408025 */ 	move	$s0,$v0
/*  519f4:	3c012000 */ 	lui	$at,0x2000
/*  519f8:	0c0129f4 */ 	jal	__osSetSR
/*  519fc:	02012025 */ 	or	$a0,$s0,$at
/*  51a00:	3c040100 */ 	lui	$a0,0x100
/*  51a04:	0c011f3c */ 	jal	__osSetFpcCsr
/*  51a08:	34840800 */ 	ori	$a0,$a0,0x800
/*  51a0c:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  51a10:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  51a14:	0c0129fc */ 	jal	__osSiRawReadIo
/*  51a18:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  51a1c:	10400007 */ 	beqz	$v0,.JF00051a3c
/*  51a20:	00000000 */ 	nop
.JF00051a24:
/*  51a24:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  51a28:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  51a2c:	0c0129fc */ 	jal	__osSiRawReadIo
/*  51a30:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  51a34:	1440fffb */ 	bnez	$v0,.JF00051a24
/*  51a38:	00000000 */ 	nop
.JF00051a3c:
/*  51a3c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  51a40:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  51a44:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  51a48:	34af0008 */ 	ori	$t7,$a1,0x8
/*  51a4c:	0c012a10 */ 	jal	__osSiRawWriteIo
/*  51a50:	01e02825 */ 	move	$a1,$t7
/*  51a54:	10400009 */ 	beqz	$v0,.JF00051a7c
/*  51a58:	00000000 */ 	nop
.JF00051a5c:
/*  51a5c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  51a60:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  51a64:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  51a68:	34b80008 */ 	ori	$t8,$a1,0x8
/*  51a6c:	0c012a10 */ 	jal	__osSiRawWriteIo
/*  51a70:	03002825 */ 	move	$a1,$t8
/*  51a74:	1440fff9 */ 	bnez	$v0,.JF00051a5c
/*  51a78:	00000000 */ 	nop
.JF00051a7c:
/*  51a7c:	3c087000 */ 	lui	$t0,0x7000
/*  51a80:	250834f0 */ 	addiu	$t0,$t0,0x34f0
/*  51a84:	8d010000 */ 	lw	$at,0x0($t0)
/*  51a88:	3c198000 */ 	lui	$t9,0x8000
/*  51a8c:	3c0d7000 */ 	lui	$t5,0x7000
/*  51a90:	af210000 */ 	sw	$at,0x0($t9)
/*  51a94:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  51a98:	25ad34f0 */ 	addiu	$t5,$t5,0x34f0
/*  51a9c:	3c0c8000 */ 	lui	$t4,0x8000
/*  51aa0:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  51aa4:	8d010008 */ 	lw	$at,0x8($t0)
/*  51aa8:	358c0080 */ 	ori	$t4,$t4,0x80
/*  51aac:	3c097000 */ 	lui	$t1,0x7000
/*  51ab0:	af210008 */ 	sw	$at,0x8($t9)
/*  51ab4:	8d0b000c */ 	lw	$t3,0xc($t0)
/*  51ab8:	252934f0 */ 	addiu	$t1,$t1,0x34f0
/*  51abc:	3c0a8000 */ 	lui	$t2,0x8000
/*  51ac0:	af2b000c */ 	sw	$t3,0xc($t9)
/*  51ac4:	8da10000 */ 	lw	$at,0x0($t5)
/*  51ac8:	354a0100 */ 	ori	$t2,$t2,0x100
/*  51acc:	3c0e7000 */ 	lui	$t6,0x7000
/*  51ad0:	ad810000 */ 	sw	$at,0x0($t4)
/*  51ad4:	8db80004 */ 	lw	$t8,0x4($t5)
/*  51ad8:	25ce34f0 */ 	addiu	$t6,$t6,0x34f0
/*  51adc:	3c0f8000 */ 	lui	$t7,0x8000
/*  51ae0:	ad980004 */ 	sw	$t8,0x4($t4)
/*  51ae4:	8da10008 */ 	lw	$at,0x8($t5)
/*  51ae8:	35ef0180 */ 	ori	$t7,$t7,0x180
/*  51aec:	3c048000 */ 	lui	$a0,0x8000
/*  51af0:	ad810008 */ 	sw	$at,0x8($t4)
/*  51af4:	8db8000c */ 	lw	$t8,0xc($t5)
/*  51af8:	24050190 */ 	li	$a1,0x190
/*  51afc:	ad98000c */ 	sw	$t8,0xc($t4)
/*  51b00:	8d210000 */ 	lw	$at,0x0($t1)
/*  51b04:	ad410000 */ 	sw	$at,0x0($t2)
/*  51b08:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  51b0c:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*  51b10:	8d210008 */ 	lw	$at,0x8($t1)
/*  51b14:	ad410008 */ 	sw	$at,0x8($t2)
/*  51b18:	8d2b000c */ 	lw	$t3,0xc($t1)
/*  51b1c:	ad4b000c */ 	sw	$t3,0xc($t2)
/*  51b20:	8dc10000 */ 	lw	$at,0x0($t6)
/*  51b24:	ade10000 */ 	sw	$at,0x0($t7)
/*  51b28:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  51b2c:	adf80004 */ 	sw	$t8,0x4($t7)
/*  51b30:	8dc10008 */ 	lw	$at,0x8($t6)
/*  51b34:	ade10008 */ 	sw	$at,0x8($t7)
/*  51b38:	8dd8000c */ 	lw	$t8,0xc($t6)
/*  51b3c:	0c012a24 */ 	jal	osWritebackDCache
/*  51b40:	adf8000c */ 	sw	$t8,0xc($t7)
/*  51b44:	3c048000 */ 	lui	$a0,0x8000
/*  51b48:	0c011f18 */ 	jal	osInvalICache
/*  51b4c:	24050190 */ 	li	$a1,0x190
/*  51b50:	0c01471e */ 	jal	osCartRomInit2
/*  51b54:	00000000 */ 	nop
/*  51b58:	0c0148a4 */ 	jal	osUnmapTLBAll
/*  51b5c:	00000000 */ 	nop
/*  51b60:	0c000bfc */ 	jal	osMapTLBRdb
/*  51b64:	00000000 */ 	nop
/*  51b68:	3c048006 */ 	lui	$a0,0x8006
/*  51b6c:	3c058006 */ 	lui	$a1,0x8006
/*  51b70:	8ca5ce24 */ 	lw	$a1,-0x31dc($a1)
/*  51b74:	8c84ce20 */ 	lw	$a0,-0x31e0($a0)
/*  51b78:	24060000 */ 	li	$a2,0x0
/*  51b7c:	0c01375e */ 	jal	__ll_mul
/*  51b80:	24070003 */ 	li	$a3,0x3
/*  51b84:	afa20020 */ 	sw	$v0,0x20($sp)
/*  51b88:	afa30024 */ 	sw	$v1,0x24($sp)
/*  51b8c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  51b90:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  51b94:	24060000 */ 	li	$a2,0x0
/*  51b98:	0c01371e */ 	jal	__ull_div
/*  51b9c:	24070004 */ 	li	$a3,0x4
/*  51ba0:	3c088000 */ 	lui	$t0,0x8000
/*  51ba4:	8d08030c */ 	lw	$t0,0x30c($t0)
/*  51ba8:	3c018006 */ 	lui	$at,0x8006
/*  51bac:	ac22ce20 */ 	sw	$v0,-0x31e0($at)
/*  51bb0:	15000005 */ 	bnez	$t0,.JF00051bc8
/*  51bb4:	ac23ce24 */ 	sw	$v1,-0x31dc($at)
/*  51bb8:	3c048000 */ 	lui	$a0,0x8000
/*  51bbc:	2484031c */ 	addiu	$a0,$a0,0x31c
/*  51bc0:	0c012a44 */ 	jal	bzero
/*  51bc4:	24050040 */ 	li	$a1,0x40
.JF00051bc8:
/*  51bc8:	3c198000 */ 	lui	$t9,0x8000
/*  51bcc:	8f390300 */ 	lw	$t9,0x300($t9)
/*  51bd0:	17200006 */ 	bnez	$t9,.JF00051bec
/*  51bd4:	00000000 */ 	nop
/*  51bd8:	3c0a02f5 */ 	lui	$t2,0x2f5
/*  51bdc:	354ab2d2 */ 	ori	$t2,$t2,0xb2d2
/*  51be0:	3c018006 */ 	lui	$at,0x8006
/*  51be4:	1000000f */ 	b	.JF00051c24
/*  51be8:	ac2a11f8 */ 	sw	$t2,0x11f8($at)
.JF00051bec:
/*  51bec:	3c098000 */ 	lui	$t1,0x8000
/*  51bf0:	8d290300 */ 	lw	$t1,0x300($t1)
/*  51bf4:	24010002 */ 	li	$at,0x2
/*  51bf8:	15210006 */ 	bne	$t1,$at,.JF00051c14
/*  51bfc:	00000000 */ 	nop
/*  51c00:	3c0b02e6 */ 	lui	$t3,0x2e6
/*  51c04:	356b025c */ 	ori	$t3,$t3,0x25c
/*  51c08:	3c018006 */ 	lui	$at,0x8006
/*  51c0c:	10000005 */ 	b	.JF00051c24
/*  51c10:	ac2b11f8 */ 	sw	$t3,0x11f8($at)
.JF00051c14:
/*  51c14:	3c0d02e6 */ 	lui	$t5,0x2e6
/*  51c18:	35add354 */ 	ori	$t5,$t5,0xd354
/*  51c1c:	3c018006 */ 	lui	$at,0x8006
/*  51c20:	ac2d11f8 */ 	sw	$t5,0x11f8($at)
.JF00051c24:
/*  51c24:	0c012a6c */ 	jal	__osGetCause
/*  51c28:	00000000 */ 	nop
/*  51c2c:	304c1000 */ 	andi	$t4,$v0,0x1000
/*  51c30:	11800003 */ 	beqz	$t4,.JF00051c40
/*  51c34:	00000000 */ 	nop
.JF00051c38:
/*  51c38:	1000ffff */ 	b	.JF00051c38
/*  51c3c:	00000000 */ 	nop
.JF00051c40:
/*  51c40:	240f0001 */ 	li	$t7,0x1
/*  51c44:	3c0ea450 */ 	lui	$t6,0xa450
/*  51c48:	adcf0008 */ 	sw	$t7,0x8($t6)
/*  51c4c:	24183fff */ 	li	$t8,0x3fff
/*  51c50:	3c08a450 */ 	lui	$t0,0xa450
/*  51c54:	ad180010 */ 	sw	$t8,0x10($t0)
/*  51c58:	2419000f */ 	li	$t9,0xf
/*  51c5c:	3c0aa450 */ 	lui	$t2,0xa450
/*  51c60:	ad590014 */ 	sw	$t9,0x14($t2)
/*  51c64:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  51c68:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  51c6c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  51c70:	03e00008 */ 	jr	$ra
/*  51c74:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_FINAL
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
/*    51940:	0c01469a */ 	jal	osCartRomInit2
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
#else
GLOBAL_ASM(
glabel osInitialize2
/*  52480:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  52484:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  52488:	240e0001 */ 	li	$t6,0x1
/*  5248c:	3c018009 */ 	lui	$at,0x8009
/*  52490:	afb00018 */ 	sw	$s0,0x18($sp)
/*  52494:	afa00030 */ 	sw	$zero,0x30($sp)
/*  52498:	0c012ca4 */ 	jal	__osGetSR
/*  5249c:	ac2e2f40 */ 	sw	$t6,0x2f40($at)
/*  524a0:	00408025 */ 	move	$s0,$v0
/*  524a4:	3c012000 */ 	lui	$at,0x2000
/*  524a8:	0c012ca0 */ 	jal	__osSetSR
/*  524ac:	02012025 */ 	or	$a0,$s0,$at
/*  524b0:	3c040100 */ 	lui	$a0,0x100
/*  524b4:	0c0121e8 */ 	jal	__osSetFpcCsr
/*  524b8:	34840800 */ 	ori	$a0,$a0,0x800
/*  524bc:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  524c0:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  524c4:	0c012ca8 */ 	jal	__osSiRawReadIo
/*  524c8:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  524cc:	10400007 */ 	beqz	$v0,.PB000524ec
/*  524d0:	00000000 */ 	nop
.PB000524d4:
/*  524d4:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  524d8:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  524dc:	0c012ca8 */ 	jal	__osSiRawReadIo
/*  524e0:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  524e4:	1440fffb */ 	bnez	$v0,.PB000524d4
/*  524e8:	00000000 */ 	nop
.PB000524ec:
/*  524ec:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  524f0:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  524f4:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  524f8:	34af0008 */ 	ori	$t7,$a1,0x8
/*  524fc:	0c012cbc */ 	jal	__osSiRawWriteIo
/*  52500:	01e02825 */ 	move	$a1,$t7
/*  52504:	10400009 */ 	beqz	$v0,.PB0005252c
/*  52508:	00000000 */ 	nop
.PB0005250c:
/*  5250c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  52510:	3c041fc0 */ 	lui	$a0,0x1fc0
/*  52514:	348407fc */ 	ori	$a0,$a0,0x7fc
/*  52518:	34b80008 */ 	ori	$t8,$a1,0x8
/*  5251c:	0c012cbc */ 	jal	__osSiRawWriteIo
/*  52520:	03002825 */ 	move	$a1,$t8
/*  52524:	1440fff9 */ 	bnez	$v0,.PB0005250c
/*  52528:	00000000 */ 	nop
.PB0005252c:
/*  5252c:	3c087000 */ 	lui	$t0,0x7000
/*  52530:	250834c0 */ 	addiu	$t0,$t0,0x34c0
/*  52534:	8d010000 */ 	lw	$at,0x0($t0)
/*  52538:	3c198000 */ 	lui	$t9,0x8000
/*  5253c:	3c0d7000 */ 	lui	$t5,0x7000
/*  52540:	af210000 */ 	sw	$at,0x0($t9)
/*  52544:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  52548:	25ad34c0 */ 	addiu	$t5,$t5,0x34c0
/*  5254c:	3c0c8000 */ 	lui	$t4,0x8000
/*  52550:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  52554:	8d010008 */ 	lw	$at,0x8($t0)
/*  52558:	358c0080 */ 	ori	$t4,$t4,0x80
/*  5255c:	3c097000 */ 	lui	$t1,0x7000
/*  52560:	af210008 */ 	sw	$at,0x8($t9)
/*  52564:	8d0b000c */ 	lw	$t3,0xc($t0)
/*  52568:	252934c0 */ 	addiu	$t1,$t1,0x34c0
/*  5256c:	3c0a8000 */ 	lui	$t2,0x8000
/*  52570:	af2b000c */ 	sw	$t3,0xc($t9)
/*  52574:	8da10000 */ 	lw	$at,0x0($t5)
/*  52578:	354a0100 */ 	ori	$t2,$t2,0x100
/*  5257c:	3c0e7000 */ 	lui	$t6,0x7000
/*  52580:	ad810000 */ 	sw	$at,0x0($t4)
/*  52584:	8db80004 */ 	lw	$t8,0x4($t5)
/*  52588:	25ce34c0 */ 	addiu	$t6,$t6,0x34c0
/*  5258c:	3c0f8000 */ 	lui	$t7,0x8000
/*  52590:	ad980004 */ 	sw	$t8,0x4($t4)
/*  52594:	8da10008 */ 	lw	$at,0x8($t5)
/*  52598:	35ef0180 */ 	ori	$t7,$t7,0x180
/*  5259c:	3c048000 */ 	lui	$a0,0x8000
/*  525a0:	ad810008 */ 	sw	$at,0x8($t4)
/*  525a4:	8db8000c */ 	lw	$t8,0xc($t5)
/*  525a8:	24050190 */ 	li	$a1,0x190
/*  525ac:	ad98000c */ 	sw	$t8,0xc($t4)
/*  525b0:	8d210000 */ 	lw	$at,0x0($t1)
/*  525b4:	ad410000 */ 	sw	$at,0x0($t2)
/*  525b8:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  525bc:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*  525c0:	8d210008 */ 	lw	$at,0x8($t1)
/*  525c4:	ad410008 */ 	sw	$at,0x8($t2)
/*  525c8:	8d2b000c */ 	lw	$t3,0xc($t1)
/*  525cc:	ad4b000c */ 	sw	$t3,0xc($t2)
/*  525d0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  525d4:	ade10000 */ 	sw	$at,0x0($t7)
/*  525d8:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  525dc:	adf80004 */ 	sw	$t8,0x4($t7)
/*  525e0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  525e4:	ade10008 */ 	sw	$at,0x8($t7)
/*  525e8:	8dd8000c */ 	lw	$t8,0xc($t6)
/*  525ec:	0c012cd0 */ 	jal	osWritebackDCache
/*  525f0:	adf8000c */ 	sw	$t8,0xc($t7)
/*  525f4:	3c048000 */ 	lui	$a0,0x8000
/*  525f8:	0c0121c4 */ 	jal	osInvalICache
/*  525fc:	24050190 */ 	li	$a1,0x190
/*  52600:	0c0149ca */ 	jal	osCartRomInit2
/*  52604:	00000000 */ 	nop
/*  52608:	0c014b50 */ 	jal	osUnmapTLBAll
/*  5260c:	00000000 */ 	nop
/*  52610:	0c000bf0 */ 	jal	osMapTLBRdb
/*  52614:	00000000 */ 	nop
/*  52618:	3c048006 */ 	lui	$a0,0x8006
/*  5261c:	3c058006 */ 	lui	$a1,0x8006
/*  52620:	8ca5d904 */ 	lw	$a1,-0x26fc($a1)
/*  52624:	8c84d900 */ 	lw	$a0,-0x2700($a0)
/*  52628:	24060000 */ 	li	$a2,0x0
/*  5262c:	0c013a0a */ 	jal	__ll_mul
/*  52630:	24070003 */ 	li	$a3,0x3
/*  52634:	afa20020 */ 	sw	$v0,0x20($sp)
/*  52638:	afa30024 */ 	sw	$v1,0x24($sp)
/*  5263c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  52640:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  52644:	24060000 */ 	li	$a2,0x0
/*  52648:	0c0139ca */ 	jal	__ull_div
/*  5264c:	24070004 */ 	li	$a3,0x4
/*  52650:	3c088000 */ 	lui	$t0,0x8000
/*  52654:	8d08030c */ 	lw	$t0,0x30c($t0)
/*  52658:	3c018006 */ 	lui	$at,0x8006
/*  5265c:	ac22d900 */ 	sw	$v0,-0x2700($at)
/*  52660:	15000005 */ 	bnez	$t0,.PB00052678
/*  52664:	ac23d904 */ 	sw	$v1,-0x26fc($at)
/*  52668:	3c048000 */ 	lui	$a0,0x8000
/*  5266c:	2484031c */ 	addiu	$a0,$a0,0x31c
/*  52670:	0c012cf0 */ 	jal	bzero
/*  52674:	24050040 */ 	li	$a1,0x40
.PB00052678:
/*  52678:	3c198000 */ 	lui	$t9,0x8000
/*  5267c:	8f390300 */ 	lw	$t9,0x300($t9)
/*  52680:	17200006 */ 	bnez	$t9,.PB0005269c
/*  52684:	00000000 */ 	nop
/*  52688:	3c0a02f5 */ 	lui	$t2,0x2f5
/*  5268c:	354ab2d2 */ 	ori	$t2,$t2,0xb2d2
/*  52690:	3c018006 */ 	lui	$at,0x8006
/*  52694:	1000000f */ 	b	.PB000526d4
/*  52698:	ac2a29d8 */ 	sw	$t2,0x29d8($at)
.PB0005269c:
/*  5269c:	3c098000 */ 	lui	$t1,0x8000
/*  526a0:	8d290300 */ 	lw	$t1,0x300($t1)
/*  526a4:	24010002 */ 	li	$at,0x2
/*  526a8:	15210006 */ 	bne	$t1,$at,.PB000526c4
/*  526ac:	00000000 */ 	nop
/*  526b0:	3c0b02e6 */ 	lui	$t3,0x2e6
/*  526b4:	356b025c */ 	ori	$t3,$t3,0x25c
/*  526b8:	3c018006 */ 	lui	$at,0x8006
/*  526bc:	10000005 */ 	b	.PB000526d4
/*  526c0:	ac2b29d8 */ 	sw	$t3,0x29d8($at)
.PB000526c4:
/*  526c4:	3c0d02e6 */ 	lui	$t5,0x2e6
/*  526c8:	35add354 */ 	ori	$t5,$t5,0xd354
/*  526cc:	3c018006 */ 	lui	$at,0x8006
/*  526d0:	ac2d29d8 */ 	sw	$t5,0x29d8($at)
.PB000526d4:
/*  526d4:	0c012d18 */ 	jal	__osGetCause
/*  526d8:	00000000 */ 	nop
/*  526dc:	304c1000 */ 	andi	$t4,$v0,0x1000
/*  526e0:	11800003 */ 	beqz	$t4,.PB000526f0
/*  526e4:	00000000 */ 	nop
.PB000526e8:
/*  526e8:	1000ffff */ 	b	.PB000526e8
/*  526ec:	00000000 */ 	nop
.PB000526f0:
/*  526f0:	240f0001 */ 	li	$t7,0x1
/*  526f4:	3c0ea450 */ 	lui	$t6,0xa450
/*  526f8:	adcf0008 */ 	sw	$t7,0x8($t6)
/*  526fc:	24183fff */ 	li	$t8,0x3fff
/*  52700:	3c08a450 */ 	lui	$t0,0xa450
/*  52704:	ad180010 */ 	sw	$t8,0x10($t0)
/*  52708:	2419000f */ 	li	$t9,0xf
/*  5270c:	3c0aa450 */ 	lui	$t2,0xa450
/*  52710:	ad590014 */ 	sw	$t9,0x14($t2)
/*  52714:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  52718:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  5271c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  52720:	03e00008 */ 	jr	$ra
/*  52724:	00000000 */ 	nop
);
#endif

OSPiHandle *osCartRomInit2(void);

// Mismatch: write to osClockRate needs to reuse $at, which happens if
// osClockRate is defined in this file, but it's writing to the one over in
// initialize.c, not the osClockRate2 in this file. Suspect these were both
// defined with the same name and that makerom allows duplicate variable names,
// merging them into one address.
//void osInitialize2()
//{
//	u32 pifdata;
//	u32 clock = 0;
//	__osFinalRom = TRUE;
//	__osSetSR(__osGetSR() | SR_CU1);
//	__osSetFpcCsr(FPCSR_FS | FPCSR_EV);
//
//	while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata));
//	while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8));
//
//	*(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
//	*(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
//	*(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
//	*(__osExceptionVector *)E_VEC = __osExceptionPreamble;
//
//	osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
//	osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
//
//	osCartRomInit2();
//	osUnmapTLBAll();
//	osMapTLBRdb();
//
//	osClockRate = osClockRate * 3 / 4;
//
//	if (osResetType == 0 /*cold reset */) {
//		bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
//	}
//
//	if (osTvType == OS_TV_PAL) {
//		osViClock = VI_PAL_CLOCK;
//	} else if (osTvType == OS_TV_MPAL) {
//		osViClock = VI_MPAL_CLOCK;
//	} else {
//		osViClock = VI_NTSC_CLOCK;
//	}
//
//	if (__osGetCause() & CAUSE_IP5) {
//		while (1);
//	}
//
//	*(u32 *)PHYS_TO_K1(AI_CONTROL_REG) = 1;
//	*(u32 *)PHYS_TO_K1(AI_DACRATE_REG) = 0x3fff;
//	*(u32 *)PHYS_TO_K1(AI_BITRATE_REG) = 0xf;
//}

extern OSPiHandle CartRomHandle;
extern OSPiHandle LeoDiskHandle;

/**
 * According to Nintendo's SDK this function should return a pointer to an
 * OSPiHandle, but the function only matches if the return statement is omitted.
 * By chance the value in v0 happens to be &CartRomHandle anyway.
 */
OSPiHandle *osCartRomInit2(void)
{
	CartRomHandle.type = DEVICE_TYPE_INIT;
	CartRomHandle.latency = IO_READ(0xa4600014);
	CartRomHandle.pulse = IO_READ(0xa4600018);
	CartRomHandle.pageSize = IO_READ(0xa460001c);
	CartRomHandle.relDuration = IO_READ(0xa4600020);

	LeoDiskHandle.type = DEVICE_TYPE_INIT;
	LeoDiskHandle.latency = IO_READ(0xa4600024);
	LeoDiskHandle.pulse = IO_READ(0xa4600028);
	LeoDiskHandle.pageSize = IO_READ(0xa460002c);
	LeoDiskHandle.relDuration = IO_READ(0xa4600030);
}
