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
#include "lib/lib_0e9d0.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_38d30.h"
#include "lib/lib_39c80.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3ccf0.h"
#include "lib/lib_3cdc0.h"
#include "lib/lib_3cef0.h"
#include "lib/lib_3d280.h"
#include "lib/lib_3e3e0.h"
#include "lib/lib_3e730.h"
#include "types.h"

const u32 var70054740[] = {0x70031ce0};
const u32 var70054744[] = {0x700325ac};
const u32 var70054748[] = {0x70033010};
const u32 var7005474c[] = {0x70032730};
const u32 var70054750[] = {0x70033010};
const u32 var70054754[] = {0x70033010};
const u32 var70054758[] = {0x70033010};
const u32 var7005475c[] = {0x70032a3c};
const u32 var70054760[] = {0x70033010};
const u32 var70054764[] = {0x70033010};
const u32 var70054768[] = {0x70033010};
const u32 var7005476c[] = {0x70033010};
const u32 var70054770[] = {0x70033010};
const u32 var70054774[] = {0x70033010};
const u32 var70054778[] = {0x70033010};
const u32 var7005477c[] = {0x700327d4};

GLOBAL_ASM(
glabel func000317f0
/*    317f0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    317f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    317f8:	afa40040 */ 	sw	$a0,0x40($sp)
/*    317fc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31800:	3c188006 */ 	lui	$t8,%hi(var8005f12c)
/*    31804:	8f18f12c */ 	lw	$t8,%lo(var8005f12c)($t8)
/*    31808:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3180c:	af0f0044 */ 	sw	$t7,0x44($t8)
/*    31810:	3c198006 */ 	lui	$t9,%hi(var8005f12c)
/*    31814:	8f39f12c */ 	lw	$t9,%lo(var8005f12c)($t9)
/*    31818:	af20003c */ 	sw	$zero,0x3c($t9)
/*    3181c:	3c098006 */ 	lui	$t1,%hi(var8005f12c)
/*    31820:	8d29f12c */ 	lw	$t1,%lo(var8005f12c)($t1)
/*    31824:	24083e80 */ 	addiu	$t0,$zero,0x3e80
/*    31828:	ad280048 */ 	sw	$t0,0x48($t1)
/*    3182c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    31830:	00002025 */ 	or	$a0,$zero,$zero
/*    31834:	00002825 */ 	or	$a1,$zero,$zero
/*    31838:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    3183c:	8d46000c */ 	lw	$a2,0xc($t2)
/*    31840:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31844:	000b6080 */ 	sll	$t4,$t3,0x2
/*    31848:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3184c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    31850:	018b6023 */ 	subu	$t4,$t4,$t3
/*    31854:	000c6080 */ 	sll	$t4,$t4,0x2
/*    31858:	0c00bec5 */ 	jal	func0002fb14
/*    3185c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    31860:	afa20038 */ 	sw	$v0,0x38($sp)
/*    31864:	3c0e8006 */ 	lui	$t6,%hi(var8005f12c)
/*    31868:	8dcef12c */ 	lw	$t6,%lo(var8005f12c)($t6)
/*    3186c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    31870:	adcd0040 */ 	sw	$t5,0x40($t6)
/*    31874:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    31878:	00002025 */ 	or	$a0,$zero,$zero
/*    3187c:	00002825 */ 	or	$a1,$zero,$zero
/*    31880:	8df80004 */ 	lw	$t8,0x4($t7)
/*    31884:	8de6000c */ 	lw	$a2,0xc($t7)
/*    31888:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3188c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*    31890:	0338c823 */ 	subu	$t9,$t9,$t8
/*    31894:	0019c880 */ 	sll	$t9,$t9,0x2
/*    31898:	0c00bec5 */ 	jal	func0002fb14
/*    3189c:	afb90010 */ 	sw	$t9,0x10($sp)
/*    318a0:	afa20038 */ 	sw	$v0,0x38($sp)
/*    318a4:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    318a8:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    318ac:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    318b0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*    318b4:	24840014 */ 	addiu	$a0,$a0,20
/*    318b8:	0c00f134 */ 	jal	func0003c4d0
/*    318bc:	8d060004 */ 	lw	$a2,0x4($t0)
/*    318c0:	3c098006 */ 	lui	$t1,%hi(var8005f12c)
/*    318c4:	8d29f12c */ 	lw	$t1,%lo(var8005f12c)($t1)
/*    318c8:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    318cc:	8d2a0040 */ 	lw	$t2,0x40($t1)
/*    318d0:	ac2af128 */ 	sw	$t2,%lo(var8005f128)($at)
/*    318d4:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    318d8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    318dc:	afab003c */ 	sw	$t3,0x3c($sp)
/*    318e0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    318e4:	2da10002 */ 	sltiu	$at,$t5,0x2
/*    318e8:	14200018 */ 	bnez	$at,.L0003194c
/*    318ec:	00000000 */ 	nop
.L000318f0:
/*    318f0:	3c0e8006 */ 	lui	$t6,%hi(var8005f12c)
/*    318f4:	8dcef12c */ 	lw	$t6,%lo(var8005f12c)($t6)
/*    318f8:	8dcf0040 */ 	lw	$t7,0x40($t6)
/*    318fc:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    31900:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    31904:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    31908:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3190c:	0338c821 */ 	addu	$t9,$t9,$t8
/*    31910:	0019c880 */ 	sll	$t9,$t9,0x2
/*    31914:	0338c823 */ 	subu	$t9,$t9,$t8
/*    31918:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3191c:	03284821 */ 	addu	$t1,$t9,$t0
/*    31920:	01202025 */ 	or	$a0,$t1,$zero
/*    31924:	0c00c5dc */ 	jal	alLink
/*    31928:	2525ffb4 */ 	addiu	$a1,$t1,-76
/*    3192c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    31930:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    31934:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    31938:	afab003c */ 	sw	$t3,0x3c($sp)
/*    3193c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    31940:	016d082b */ 	sltu	$at,$t3,$t5
/*    31944:	1420ffea */ 	bnez	$at,.L000318f0
/*    31948:	00000000 */ 	nop
.L0003194c:
/*    3194c:	0c00ccde */ 	jal	func00033378
/*    31950:	00002025 */ 	or	$a0,$zero,$zero
/*    31954:	0c00cd8d */ 	jal	func00033634
/*    31958:	00002025 */ 	or	$a0,$zero,$zero
/*    3195c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31960:	00002025 */ 	or	$a0,$zero,$zero
/*    31964:	00002825 */ 	or	$a1,$zero,$zero
/*    31968:	95cf0010 */ 	lhu	$t7,0x10($t6)
/*    3196c:	8dc6000c */ 	lw	$a2,0xc($t6)
/*    31970:	24070002 */ 	addiu	$a3,$zero,0x2
/*    31974:	0c00bec5 */ 	jal	func0002fb14
/*    31978:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    3197c:	3c01800a */ 	lui	$at,%hi(var8009c334)
/*    31980:	ac22c334 */ 	sw	$v0,%lo(var8009c334)($at)
/*    31984:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    31988:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    3198c:	97190010 */ 	lhu	$t9,0x10($t8)
/*    31990:	13200010 */ 	beqz	$t9,.L000319d4
/*    31994:	00000000 */ 	nop
.L00031998:
/*    31998:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    3199c:	3c09800a */ 	lui	$t1,%hi(var8009c334)
/*    319a0:	8d29c334 */ 	lw	$t1,%lo(var8009c334)($t1)
/*    319a4:	000a6040 */ 	sll	$t4,$t2,0x1
/*    319a8:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*    319ac:	012c5821 */ 	addu	$t3,$t1,$t4
/*    319b0:	a5680000 */ 	sh	$t0,0x0($t3)
/*    319b4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    319b8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    319bc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    319c0:	afae003c */ 	sw	$t6,0x3c($sp)
/*    319c4:	95f80010 */ 	lhu	$t8,0x10($t7)
/*    319c8:	01d8082b */ 	sltu	$at,$t6,$t8
/*    319cc:	1420fff2 */ 	bnez	$at,.L00031998
/*    319d0:	00000000 */ 	nop
.L000319d4:
/*    319d4:	3c198006 */ 	lui	$t9,%hi(var8005f12c)
/*    319d8:	8f39f12c */ 	lw	$t9,%lo(var8005f12c)($t9)
/*    319dc:	af200000 */ 	sw	$zero,0x0($t9)
/*    319e0:	3c098006 */ 	lui	$t1,%hi(var8005f12c)
/*    319e4:	8d29f12c */ 	lw	$t1,%lo(var8005f12c)($t1)
/*    319e8:	3c0a7003 */ 	lui	$t2,%hi(func00031a68)
/*    319ec:	254a1a68 */ 	addiu	$t2,$t2,%lo(func00031a68)
/*    319f0:	ad2a0008 */ 	sw	$t2,0x8($t1)
/*    319f4:	3c0c8006 */ 	lui	$t4,%hi(var8005f12c)
/*    319f8:	8d8cf12c */ 	lw	$t4,%lo(var8005f12c)($t4)
/*    319fc:	ad8c0004 */ 	sw	$t4,0x4($t4)
/*    31a00:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    31a04:	0c00f240 */ 	jal	func0003c900
/*    31a08:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    31a0c:	24080020 */ 	addiu	$t0,$zero,0x20
/*    31a10:	a7a80028 */ 	sh	$t0,0x28($sp)
/*    31a14:	3c0b8006 */ 	lui	$t3,%hi(var8005f12c)
/*    31a18:	8d6bf12c */ 	lw	$t3,%lo(var8005f12c)($t3)
/*    31a1c:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    31a20:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31a24:	25640014 */ 	addiu	$a0,$t3,0x14
/*    31a28:	0c00f184 */ 	jal	alEvtqPostEvent
/*    31a2c:	8d660048 */ 	lw	$a2,0x48($t3)
/*    31a30:	3c0d8006 */ 	lui	$t5,%hi(var8005f12c)
/*    31a34:	8dadf12c */ 	lw	$t5,%lo(var8005f12c)($t5)
/*    31a38:	25a40014 */ 	addiu	$a0,$t5,0x14
/*    31a3c:	0c00f15b */ 	jal	func0003c56c
/*    31a40:	25a50028 */ 	addiu	$a1,$t5,0x28
/*    31a44:	3c0f8006 */ 	lui	$t7,%hi(var8005f12c)
/*    31a48:	8deff12c */ 	lw	$t7,%lo(var8005f12c)($t7)
/*    31a4c:	ade2004c */ 	sw	$v0,0x4c($t7)
/*    31a50:	10000001 */ 	b	.L00031a58
/*    31a54:	00000000 */ 	nop
.L00031a58:
/*    31a58:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    31a5c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    31a60:	03e00008 */ 	jr	$ra
/*    31a64:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00031a68
/*    31a68:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    31a6c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    31a70:	afa40030 */ 	sw	$a0,0x30($sp)
/*    31a74:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    31a78:	afae002c */ 	sw	$t6,0x2c($sp)
.L00031a7c:
/*    31a7c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    31a80:	24010020 */ 	addiu	$at,$zero,0x20
/*    31a84:	85f80028 */ 	lh	$t8,0x28($t7)
/*    31a88:	1701000d */ 	bne	$t8,$at,.L00031ac0
/*    31a8c:	00000000 */ 	nop
/*    31a90:	10000001 */ 	b	.L00031a98
/*    31a94:	00000000 */ 	nop
.L00031a98:
/*    31a98:	24190020 */ 	addiu	$t9,$zero,0x20
/*    31a9c:	a7b9001c */ 	sh	$t9,0x1c($sp)
/*    31aa0:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    31aa4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    31aa8:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31aac:	25040014 */ 	addiu	$a0,$t0,0x14
/*    31ab0:	0c00f184 */ 	jal	alEvtqPostEvent
/*    31ab4:	8d060048 */ 	lw	$a2,0x48($t0)
/*    31ab8:	10000006 */ 	b	.L00031ad4
/*    31abc:	00000000 */ 	nop
.L00031ac0:
/*    31ac0:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    31ac4:	0c00c6cd */ 	jal	func00031b34
/*    31ac8:	24840028 */ 	addiu	$a0,$a0,40
/*    31acc:	10000001 */ 	b	.L00031ad4
/*    31ad0:	00000000 */ 	nop
.L00031ad4:
/*    31ad4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    31ad8:	25240014 */ 	addiu	$a0,$t1,0x14
/*    31adc:	0c00f15b */ 	jal	func0003c56c
/*    31ae0:	25250028 */ 	addiu	$a1,$t1,0x28
/*    31ae4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    31ae8:	ad42004c */ 	sw	$v0,0x4c($t2)
/*    31aec:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    31af0:	8d6c004c */ 	lw	$t4,0x4c($t3)
/*    31af4:	1180ffe1 */ 	beqz	$t4,.L00031a7c
/*    31af8:	00000000 */ 	nop
/*    31afc:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    31b00:	8dae0050 */ 	lw	$t6,0x50($t5)
/*    31b04:	8daf004c */ 	lw	$t7,0x4c($t5)
/*    31b08:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    31b0c:	adb80050 */ 	sw	$t8,0x50($t5)
/*    31b10:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    31b14:	10000003 */ 	b	.L00031b24
/*    31b18:	8f22004c */ 	lw	$v0,0x4c($t9)
/*    31b1c:	10000001 */ 	b	.L00031b24
/*    31b20:	00000000 */ 	nop
.L00031b24:
/*    31b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    31b28:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    31b2c:	03e00008 */ 	jr	$ra
/*    31b30:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00031b34
/*    31b34:	27bdff48 */ 	addiu	$sp,$sp,-184
/*    31b38:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    31b3c:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*    31b40:	afb10030 */ 	sw	$s1,0x30($sp)
/*    31b44:	afb0002c */ 	sw	$s0,0x2c($sp)
/*    31b48:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    31b4c:	afae0068 */ 	sw	$t6,0x68($sp)
/*    31b50:	afa00064 */ 	sw	$zero,0x64($sp)
/*    31b54:	afa00060 */ 	sw	$zero,0x60($sp)
/*    31b58:	afa0005c */ 	sw	$zero,0x5c($sp)
.L00031b5c:
/*    31b5c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    31b60:	11e0000b */ 	beqz	$t7,.L00031b90
/*    31b64:	00000000 */ 	nop
/*    31b68:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31b6c:	afb80088 */ 	sw	$t8,0x88($sp)
/*    31b70:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    31b74:	97280000 */ 	lhu	$t0,0x0($t9)
/*    31b78:	a7a80084 */ 	sh	$t0,0x84($sp)
/*    31b7c:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*    31b80:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    31b84:	afaa008c */ 	sw	$t2,0x8c($sp)
/*    31b88:	27ab0084 */ 	addiu	$t3,$sp,0x84
/*    31b8c:	afab00b8 */ 	sw	$t3,0xb8($sp)
.L00031b90:
/*    31b90:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    31b94:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    31b98:	afad0060 */ 	sw	$t5,0x60($sp)
/*    31b9c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31ba0:	3c018000 */ 	lui	$at,0x8000
/*    31ba4:	01c17824 */ 	and	$t7,$t6,$at
/*    31ba8:	15e00001 */ 	bnez	$t7,.L00031bb0
/*    31bac:	00000000 */ 	nop
.L00031bb0:
/*    31bb0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31bb4:	8f190008 */ 	lw	$t9,0x8($t8)
/*    31bb8:	afb900ac */ 	sw	$t9,0xac($sp)
/*    31bbc:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31bc0:	15000006 */ 	bnez	$t0,.L00031bdc
/*    31bc4:	00000000 */ 	nop
/*    31bc8:	27a4005a */ 	addiu	$a0,$sp,0x5a
/*    31bcc:	0c00cc9d */ 	jal	func00033274
/*    31bd0:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    31bd4:	10000529 */ 	b	.L0003307c
/*    31bd8:	00000000 */ 	nop
.L00031bdc:
/*    31bdc:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    31be0:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    31be4:	afaa00a8 */ 	sw	$t2,0xa8($sp)
/*    31be8:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    31bec:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    31bf0:	afac005c */ 	sw	$t4,0x5c($sp)
/*    31bf4:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    31bf8:	95b00000 */ 	lhu	$s0,0x0($t5)
/*    31bfc:	2a010201 */ 	slti	$at,$s0,0x201
/*    31c00:	14200012 */ 	bnez	$at,.L00031c4c
/*    31c04:	00000000 */ 	nop
/*    31c08:	24010400 */ 	addiu	$at,$zero,0x400
/*    31c0c:	12010267 */ 	beq	$s0,$at,.L000325ac
/*    31c10:	00000000 */ 	nop
/*    31c14:	24010800 */ 	addiu	$at,$zero,0x800
/*    31c18:	120103ef */ 	beq	$s0,$at,.L00032bd8
/*    31c1c:	00000000 */ 	nop
/*    31c20:	24011000 */ 	addiu	$at,$zero,0x1000
/*    31c24:	12010261 */ 	beq	$s0,$at,.L000325ac
/*    31c28:	00000000 */ 	nop
/*    31c2c:	24012000 */ 	addiu	$at,$zero,0x2000
/*    31c30:	1201036a */ 	beq	$s0,$at,.L000329dc
/*    31c34:	00000000 */ 	nop
/*    31c38:	24014000 */ 	addiu	$at,$zero,0x4000
/*    31c3c:	12010330 */ 	beq	$s0,$at,.L00032900
/*    31c40:	00000000 */ 	nop
/*    31c44:	100004f2 */ 	b	.L00033010
/*    31c48:	00000000 */ 	nop
.L00031c4c:
/*    31c4c:	2a010081 */ 	slti	$at,$s0,0x81
/*    31c50:	14200009 */ 	bnez	$at,.L00031c78
/*    31c54:	00000000 */ 	nop
/*    31c58:	24010100 */ 	addiu	$at,$zero,0x100
/*    31c5c:	120102f7 */ 	beq	$s0,$at,.L0003283c
/*    31c60:	00000000 */ 	nop
/*    31c64:	24010200 */ 	addiu	$at,$zero,0x200
/*    31c68:	120104d3 */ 	beq	$s0,$at,.L00032fb8
/*    31c6c:	00000000 */ 	nop
/*    31c70:	100004e7 */ 	b	.L00033010
/*    31c74:	00000000 */ 	nop
.L00031c78:
/*    31c78:	2a010041 */ 	slti	$at,$s0,0x41
/*    31c7c:	14200006 */ 	bnez	$at,.L00031c98
/*    31c80:	00000000 */ 	nop
/*    31c84:	24010080 */ 	addiu	$at,$zero,0x80
/*    31c88:	120104c7 */ 	beq	$s0,$at,.L00032fa8
/*    31c8c:	00000000 */ 	nop
/*    31c90:	100004df */ 	b	.L00033010
/*    31c94:	00000000 */ 	nop
.L00031c98:
/*    31c98:	2a010011 */ 	slti	$at,$s0,0x11
/*    31c9c:	14200006 */ 	bnez	$at,.L00031cb8
/*    31ca0:	00000000 */ 	nop
/*    31ca4:	24010040 */ 	addiu	$at,$zero,0x40
/*    31ca8:	12010436 */ 	beq	$s0,$at,.L00032d84
/*    31cac:	00000000 */ 	nop
/*    31cb0:	100004d7 */ 	b	.L00033010
/*    31cb4:	00000000 */ 	nop
.L00031cb8:
/*    31cb8:	260effff */ 	addiu	$t6,$s0,-1
/*    31cbc:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*    31cc0:	102004d3 */ 	beqz	$at,.L00033010
/*    31cc4:	00000000 */ 	nop
/*    31cc8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    31ccc:	3c017005 */ 	lui	$at,%hi(var70054740)
/*    31cd0:	002e0821 */ 	addu	$at,$at,$t6
/*    31cd4:	8c2e4740 */ 	lw	$t6,%lo(var70054740)($at)
/*    31cd8:	01c00008 */ 	jr	$t6
/*    31cdc:	00000000 */ 	nop
/*    31ce0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    31ce4:	24010005 */ 	addiu	$at,$zero,0x5
/*    31ce8:	91f80045 */ 	lbu	$t8,0x45($t7)
/*    31cec:	13010006 */ 	beq	$t8,$at,.L00031d08
/*    31cf0:	00000000 */ 	nop
/*    31cf4:	24010004 */ 	addiu	$at,$zero,0x4
/*    31cf8:	13010003 */ 	beq	$t8,$at,.L00031d08
/*    31cfc:	00000000 */ 	nop
/*    31d00:	100004de */ 	b	.L0003307c
/*    31d04:	00000000 */ 	nop
.L00031d08:
/*    31d08:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31d0c:	93280043 */ 	lbu	$t0,0x43($t9)
/*    31d10:	a7a800b2 */ 	sh	$t0,0xb2($sp)
/*    31d14:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    31d18:	912a0040 */ 	lbu	$t2,0x40($t1)
/*    31d1c:	a7aa00b0 */ 	sh	$t2,0xb0($sp)
/*    31d20:	a3a000b4 */ 	sb	$zero,0xb4($sp)
/*    31d24:	3c0c8006 */ 	lui	$t4,%hi(var8005f12c)
/*    31d28:	8d8cf12c */ 	lw	$t4,%lo(var8005f12c)($t4)
/*    31d2c:	3c0b8006 */ 	lui	$t3,%hi(var8005f130)
/*    31d30:	856bf130 */ 	lh	$t3,%lo(var8005f130)($t3)
/*    31d34:	8d8d0044 */ 	lw	$t5,0x44($t4)
/*    31d38:	016d702a */ 	slt	$t6,$t3,$t5
/*    31d3c:	39ce0001 */ 	xori	$t6,$t6,0x1
/*    31d40:	afae0070 */ 	sw	$t6,0x70($sp)
/*    31d44:	8faf0070 */ 	lw	$t7,0x70($sp)
/*    31d48:	11e00006 */ 	beqz	$t7,.L00031d64
/*    31d4c:	00000000 */ 	nop
/*    31d50:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31d54:	93190044 */ 	lbu	$t9,0x44($t8)
/*    31d58:	33280010 */ 	andi	$t0,$t9,0x10
/*    31d5c:	11000006 */ 	beqz	$t0,.L00031d78
/*    31d60:	00000000 */ 	nop
.L00031d64:
/*    31d64:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    31d68:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*    31d6c:	0c00f278 */ 	jal	func0003c9e0
/*    31d70:	2484000c */ 	addiu	$a0,$a0,0xc
/*    31d74:	afa20064 */ 	sw	$v0,0x64($sp)
.L00031d78:
/*    31d78:	8fa90064 */ 	lw	$t1,0x64($sp)
/*    31d7c:	1520005f */ 	bnez	$t1,.L00031efc
/*    31d80:	00000000 */ 	nop
/*    31d84:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    31d88:	914c0044 */ 	lbu	$t4,0x44($t2)
/*    31d8c:	318b0012 */ 	andi	$t3,$t4,0x12
/*    31d90:	15600004 */ 	bnez	$t3,.L00031da4
/*    31d94:	00000000 */ 	nop
/*    31d98:	8d4d0034 */ 	lw	$t5,0x34($t2)
/*    31d9c:	19a00011 */ 	blez	$t5,.L00031de4
/*    31da0:	00000000 */ 	nop
.L00031da4:
/*    31da4:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    31da8:	240e0004 */ 	addiu	$t6,$zero,0x4
/*    31dac:	a1ee0045 */ 	sb	$t6,0x45($t7)
/*    31db0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31db4:	8f190034 */ 	lw	$t9,0x34($t8)
/*    31db8:	2728ffff */ 	addiu	$t0,$t9,-1
/*    31dbc:	af080034 */ 	sw	$t0,0x34($t8)
/*    31dc0:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    31dc4:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    31dc8:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*    31dcc:	34068235 */ 	dli	$a2,0x8235
/*    31dd0:	00003825 */ 	or	$a3,$zero,$zero
/*    31dd4:	0c00f184 */ 	jal	alEvtqPostEvent
/*    31dd8:	24840014 */ 	addiu	$a0,$a0,20
/*    31ddc:	10000045 */ 	b	.L00031ef4
/*    31de0:	00000000 */ 	nop
.L00031de4:
/*    31de4:	8fa90070 */ 	lw	$t1,0x70($sp)
/*    31de8:	11200040 */ 	beqz	$t1,.L00031eec
/*    31dec:	00000000 */ 	nop
/*    31df0:	3c0c8006 */ 	lui	$t4,%hi(var8005f124)
/*    31df4:	8d8cf124 */ 	lw	$t4,%lo(var8005f124)($t4)
/*    31df8:	afac0054 */ 	sw	$t4,0x54($sp)
.L00031dfc:
/*    31dfc:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    31e00:	916a0044 */ 	lbu	$t2,0x44($t3)
/*    31e04:	314d0012 */ 	andi	$t5,$t2,0x12
/*    31e08:	15a0001c */ 	bnez	$t5,.L00031e7c
/*    31e0c:	00000000 */ 	nop
/*    31e10:	314e0004 */ 	andi	$t6,$t2,0x4
/*    31e14:	11c00019 */ 	beqz	$t6,.L00031e7c
/*    31e18:	00000000 */ 	nop
/*    31e1c:	916f0045 */ 	lbu	$t7,0x45($t3)
/*    31e20:	24010003 */ 	addiu	$at,$zero,0x3
/*    31e24:	11e10015 */ 	beq	$t7,$at,.L00031e7c
/*    31e28:	00000000 */ 	nop
/*    31e2c:	afa00070 */ 	sw	$zero,0x70($sp)
/*    31e30:	24190080 */ 	addiu	$t9,$zero,0x80
/*    31e34:	a7b90044 */ 	sh	$t9,0x44($sp)
/*    31e38:	8fa80054 */ 	lw	$t0,0x54($sp)
/*    31e3c:	afa80048 */ 	sw	$t0,0x48($sp)
/*    31e40:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    31e44:	24180003 */ 	addiu	$t8,$zero,0x3
/*    31e48:	a1380045 */ 	sb	$t8,0x45($t1)
/*    31e4c:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    31e50:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    31e54:	27a50044 */ 	addiu	$a1,$sp,0x44
/*    31e58:	240603e8 */ 	addiu	$a2,$zero,0x3e8
/*    31e5c:	00003825 */ 	or	$a3,$zero,$zero
/*    31e60:	0c00f184 */ 	jal	alEvtqPostEvent
/*    31e64:	24840014 */ 	addiu	$a0,$a0,20
/*    31e68:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    31e6c:	00002825 */ 	or	$a1,$zero,$zero
/*    31e70:	240603e8 */ 	addiu	$a2,$zero,0x3e8
/*    31e74:	0c00f33c */ 	jal	func0003ccf0
/*    31e78:	2484000c */ 	addiu	$a0,$a0,0xc
.L00031e7c:
/*    31e7c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*    31e80:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    31e84:	afad0054 */ 	sw	$t5,0x54($sp)
/*    31e88:	8faa0070 */ 	lw	$t2,0x70($sp)
/*    31e8c:	11400004 */ 	beqz	$t2,.L00031ea0
/*    31e90:	00000000 */ 	nop
/*    31e94:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    31e98:	15c0ffd8 */ 	bnez	$t6,.L00031dfc
/*    31e9c:	00000000 */ 	nop
.L00031ea0:
/*    31ea0:	8fab0070 */ 	lw	$t3,0x70($sp)
/*    31ea4:	1560000d */ 	bnez	$t3,.L00031edc
/*    31ea8:	00000000 */ 	nop
/*    31eac:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31eb0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    31eb4:	af2f0034 */ 	sw	$t7,0x34($t9)
/*    31eb8:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    31ebc:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    31ec0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*    31ec4:	240603e9 */ 	addiu	$a2,$zero,0x3e9
/*    31ec8:	00003825 */ 	or	$a3,$zero,$zero
/*    31ecc:	0c00f184 */ 	jal	alEvtqPostEvent
/*    31ed0:	24840014 */ 	addiu	$a0,$a0,20
/*    31ed4:	10000003 */ 	b	.L00031ee4
/*    31ed8:	00000000 */ 	nop
.L00031edc:
/*    31edc:	0c00cc24 */ 	jal	func00033090
/*    31ee0:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00031ee4:
/*    31ee4:	10000003 */ 	b	.L00031ef4
/*    31ee8:	00000000 */ 	nop
.L00031eec:
/*    31eec:	0c00cc24 */ 	jal	func00033090
/*    31ef0:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00031ef4:
/*    31ef4:	10000461 */ 	b	.L0003307c
/*    31ef8:	00000000 */ 	nop
.L00031efc:
/*    31efc:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31f00:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31f04:	8d180000 */ 	lw	$t8,0x0($t0)
/*    31f08:	c588002c */ 	lwc1	$f8,0x2c($t4)
/*    31f0c:	c5900028 */ 	lwc1	$f16,0x28($t4)
/*    31f10:	8f090000 */ 	lw	$t1,0x0($t8)
/*    31f14:	44892000 */ 	mtc1	$t1,$f4
/*    31f18:	00000000 */ 	nop
/*    31f1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    31f20:	46083283 */ 	div.s	$f10,$f6,$f8
/*    31f24:	46105483 */ 	div.s	$f18,$f10,$f16
/*    31f28:	4600910d */ 	trunc.w.s	$f4,$f18
/*    31f2c:	440a2000 */ 	mfc1	$t2,$f4
/*    31f30:	00000000 */ 	nop
/*    31f34:	afaa0080 */ 	sw	$t2,0x80($sp)
/*    31f38:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31f3c:	91cb0044 */ 	lbu	$t3,0x44($t6)
/*    31f40:	316f0002 */ 	andi	$t7,$t3,0x2
/*    31f44:	11e00004 */ 	beqz	$t7,.L00031f58
/*    31f48:	00000000 */ 	nop
/*    31f4c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31f50:	10000029 */ 	b	.L00031ff8
/*    31f54:	af200048 */ 	sw	$zero,0x48($t9)
.L00031f58:
/*    31f58:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31f5c:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31f60:	8d180000 */ 	lw	$t8,0x0($t0)
/*    31f64:	c58a002c */ 	lwc1	$f10,0x2c($t4)
/*    31f68:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    31f6c:	8f090004 */ 	lw	$t1,0x4($t8)
/*    31f70:	44893000 */ 	mtc1	$t1,$f6
/*    31f74:	00000000 */ 	nop
/*    31f78:	46803220 */ 	cvt.s.w	$f8,$f6
/*    31f7c:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    31f80:	46128103 */ 	div.s	$f4,$f16,$f18
/*    31f84:	4600218d */ 	trunc.w.s	$f6,$f4
/*    31f88:	440a3000 */ 	mfc1	$t2,$f6
/*    31f8c:	00000000 */ 	nop
/*    31f90:	afaa0040 */ 	sw	$t2,0x40($sp)
/*    31f94:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31f98:	3c010053 */ 	lui	$at,0x53
/*    31f9c:	3421ec61 */ 	ori	$at,$at,0xec61
/*    31fa0:	01c1082a */ 	slt	$at,$t6,$at
/*    31fa4:	14200004 */ 	bnez	$at,.L00031fb8
/*    31fa8:	00000000 */ 	nop
/*    31fac:	3c0b0053 */ 	lui	$t3,0x53
/*    31fb0:	356bec60 */ 	ori	$t3,$t3,0xec60
/*    31fb4:	afab0040 */ 	sw	$t3,0x40($sp)
.L00031fb8:
/*    31fb8:	3c198006 */ 	lui	$t9,%hi(var8005f12c)
/*    31fbc:	8f39f12c */ 	lw	$t9,%lo(var8005f12c)($t9)
/*    31fc0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    31fc4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31fc8:	8f280050 */ 	lw	$t0,0x50($t9)
/*    31fcc:	3c01000f */ 	lui	$at,0xf
/*    31fd0:	34214240 */ 	ori	$at,$at,0x4240
/*    31fd4:	01e8c021 */ 	addu	$t8,$t7,$t0
/*    31fd8:	03014821 */ 	addu	$t1,$t8,$at
/*    31fdc:	ad890048 */ 	sw	$t1,0x48($t4)
/*    31fe0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    31fe4:	8daa0048 */ 	lw	$t2,0x48($t5)
/*    31fe8:	05410003 */ 	bgez	$t2,.L00031ff8
/*    31fec:	00000000 */ 	nop
/*    31ff0:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31ff4:	adc00048 */ 	sw	$zero,0x48($t6)
.L00031ff8:
/*    31ff8:	8fab0080 */ 	lw	$t3,0x80($sp)
/*    31ffc:	3c010053 */ 	lui	$at,0x53
/*    32000:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32004:	0161082a */ 	slt	$at,$t3,$at
/*    32008:	14200005 */ 	bnez	$at,.L00032020
/*    3200c:	00000000 */ 	nop
/*    32010:	0c00cc24 */ 	jal	func00033090
/*    32014:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32018:	10000418 */ 	b	.L0003307c
/*    3201c:	00000000 */ 	nop
.L00032020:
/*    32020:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32024:	932f0044 */ 	lbu	$t7,0x44($t9)
/*    32028:	35e80004 */ 	ori	$t0,$t7,0x4
/*    3202c:	a3280044 */ 	sb	$t0,0x44($t9)
/*    32030:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    32034:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32038:	8f090000 */ 	lw	$t1,0x0($t8)
/*    3203c:	912c000c */ 	lbu	$t4,0xc($t1)
/*    32040:	a5ac003a */ 	sh	$t4,0x3a($t5)
/*    32044:	87aa00b2 */ 	lh	$t2,0xb2($sp)
/*    32048:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    3204c:	a1ca0043 */ 	sb	$t2,0x43($t6)
/*    32050:	3c0b8006 */ 	lui	$t3,%hi(var8005f12c)
/*    32054:	8d6bf12c */ 	lw	$t3,%lo(var8005f12c)($t3)
/*    32058:	8fa80080 */ 	lw	$t0,0x80($sp)
/*    3205c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32060:	8d6f0050 */ 	lw	$t7,0x50($t3)
/*    32064:	01e8c821 */ 	addu	$t9,$t7,$t0
/*    32068:	af19003c */ 	sw	$t9,0x3c($t8)
/*    3206c:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32070:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*    32074:	3c09800a */ 	lui	$t1,%hi(var8009c334)
/*    32078:	8519003a */ 	lh	$t9,0x3a($t0)
/*    3207c:	85180038 */ 	lh	$t8,0x38($t0)
/*    32080:	918d0002 */ 	lbu	$t5,0x2($t4)
/*    32084:	8d29c334 */ 	lw	$t1,%lo(var8009c334)($t1)
/*    32088:	03380019 */ 	multu	$t9,$t8
/*    3208c:	31aa001f */ 	andi	$t2,$t5,0x1f
/*    32090:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32094:	000a7040 */ 	sll	$t6,$t2,0x1
/*    32098:	012e5821 */ 	addu	$t3,$t1,$t6
/*    3209c:	91aa000d */ 	lbu	$t2,0xd($t5)
/*    320a0:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    320a4:	856f0000 */ 	lh	$t7,0x0($t3)
/*    320a8:	00006012 */ 	mflo	$t4
/*    320ac:	00000000 */ 	nop
/*    320b0:	00000000 */ 	nop
/*    320b4:	018a0019 */ 	multu	$t4,$t2
/*    320b8:	00004812 */ 	mflo	$t1
/*    320bc:	00000000 */ 	nop
/*    320c0:	00000000 */ 	nop
/*    320c4:	0121001a */ 	div	$zero,$t1,$at
/*    320c8:	00007012 */ 	mflo	$t6
/*    320cc:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    320d0:	00000000 */ 	nop
/*    320d4:	01ee0019 */ 	multu	$t7,$t6
/*    320d8:	00005812 */ 	mflo	$t3
/*    320dc:	00000000 */ 	nop
/*    320e0:	00000000 */ 	nop
/*    320e4:	0161001a */ 	div	$zero,$t3,$at
/*    320e8:	00004012 */ 	mflo	$t0
/*    320ec:	1d000003 */ 	bgtz	$t0,.L000320fc
/*    320f0:	00000000 */ 	nop
/*    320f4:	10000023 */ 	b	.L00032184
/*    320f8:	afa00078 */ 	sw	$zero,0x78($sp)
.L000320fc:
/*    320fc:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32100:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*    32104:	3c19800a */ 	lui	$t9,%hi(var8009c334)
/*    32108:	85cb003a */ 	lh	$t3,0x3a($t6)
/*    3210c:	85c80038 */ 	lh	$t0,0x38($t6)
/*    32110:	930d0002 */ 	lbu	$t5,0x2($t8)
/*    32114:	8f39c334 */ 	lw	$t9,%lo(var8009c334)($t9)
/*    32118:	01680019 */ 	multu	$t3,$t0
/*    3211c:	31ac001f */ 	andi	$t4,$t5,0x1f
/*    32120:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32124:	000c5040 */ 	sll	$t2,$t4,0x1
/*    32128:	032a4821 */ 	addu	$t1,$t9,$t2
/*    3212c:	91ac000d */ 	lbu	$t4,0xd($t5)
/*    32130:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32134:	852f0000 */ 	lh	$t7,0x0($t1)
/*    32138:	0000c012 */ 	mflo	$t8
/*    3213c:	00000000 */ 	nop
/*    32140:	00000000 */ 	nop
/*    32144:	030c0019 */ 	multu	$t8,$t4
/*    32148:	0000c812 */ 	mflo	$t9
/*    3214c:	00000000 */ 	nop
/*    32150:	00000000 */ 	nop
/*    32154:	0321001a */ 	div	$zero,$t9,$at
/*    32158:	00005012 */ 	mflo	$t2
/*    3215c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32160:	00000000 */ 	nop
/*    32164:	01ea0019 */ 	multu	$t7,$t2
/*    32168:	00004812 */ 	mflo	$t1
/*    3216c:	00000000 */ 	nop
/*    32170:	00000000 */ 	nop
/*    32174:	0121001a */ 	div	$zero,$t1,$at
/*    32178:	00007012 */ 	mflo	$t6
/*    3217c:	25cbffff */ 	addiu	$t3,$t6,-1
/*    32180:	afab0078 */ 	sw	$t3,0x78($sp)
.L00032184:
/*    32184:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32188:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    3218c:	910d0041 */ 	lbu	$t5,0x41($t0)
/*    32190:	930c000c */ 	lbu	$t4,0xc($t8)
/*    32194:	01acc821 */ 	addu	$t9,$t5,$t4
/*    32198:	272fffc0 */ 	addiu	$t7,$t9,-64
/*    3219c:	afaf0074 */ 	sw	$t7,0x74($sp)
/*    321a0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    321a4:	19400003 */ 	blez	$t2,.L000321b4
/*    321a8:	00000000 */ 	nop
/*    321ac:	10000002 */ 	b	.L000321b8
/*    321b0:	01408025 */ 	or	$s0,$t2,$zero
.L000321b4:
/*    321b4:	00008025 */ 	or	$s0,$zero,$zero
.L000321b8:
/*    321b8:	2a01007f */ 	slti	$at,$s0,0x7f
/*    321bc:	10200009 */ 	beqz	$at,.L000321e4
/*    321c0:	00000000 */ 	nop
/*    321c4:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    321c8:	19200003 */ 	blez	$t1,.L000321d8
/*    321cc:	00000000 */ 	nop
/*    321d0:	10000002 */ 	b	.L000321dc
/*    321d4:	01208825 */ 	or	$s1,$t1,$zero
.L000321d8:
/*    321d8:	00008825 */ 	or	$s1,$zero,$zero
.L000321dc:
/*    321dc:	10000003 */ 	b	.L000321ec
/*    321e0:	a3b100a7 */ 	sb	$s1,0xa7($sp)
.L000321e4:
/*    321e4:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    321e8:	a3ae00a7 */ 	sb	$t6,0xa7($sp)
.L000321ec:
/*    321ec:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*    321f0:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    321f4:	91ac0003 */ 	lbu	$t4,0x3($t5)
/*    321f8:	91680042 */ 	lbu	$t0,0x42($t3)
/*    321fc:	3199000f */ 	andi	$t9,$t4,0xf
/*    32200:	001978c0 */ 	sll	$t7,$t9,0x3
/*    32204:	3118007f */ 	andi	$t8,$t0,0x7f
/*    32208:	030f5021 */ 	addu	$t2,$t8,$t7
/*    3220c:	afaa007c */ 	sw	$t2,0x7c($sp)
/*    32210:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*    32214:	05210003 */ 	bgez	$t1,.L00032224
/*    32218:	00000000 */ 	nop
/*    3221c:	10000002 */ 	b	.L00032228
/*    32220:	00008025 */ 	or	$s0,$zero,$zero
.L00032224:
/*    32224:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L00032228:
/*    32228:	2a010080 */ 	slti	$at,$s0,0x80
/*    3222c:	14200004 */ 	bnez	$at,.L00032240
/*    32230:	00000000 */ 	nop
/*    32234:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    32238:	10000008 */ 	b	.L0003225c
/*    3223c:	afae007c */ 	sw	$t6,0x7c($sp)
.L00032240:
/*    32240:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    32244:	05610003 */ 	bgez	$t3,.L00032254
/*    32248:	00000000 */ 	nop
/*    3224c:	10000002 */ 	b	.L00032258
/*    32250:	00008825 */ 	or	$s1,$zero,$zero
.L00032254:
/*    32254:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L00032258:
/*    32258:	afb1007c */ 	sw	$s1,0x7c($sp)
.L0003225c:
/*    3225c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32260:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    32264:	91ac0042 */ 	lbu	$t4,0x42($t5)
/*    32268:	31990080 */ 	andi	$t9,$t4,0x80
/*    3226c:	0119c025 */ 	or	$t8,$t0,$t9
/*    32270:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    32274:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32278:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    3227c:	93a900a7 */ 	lbu	$t1,0xa7($sp)
/*    32280:	c5e8002c */ 	lwc1	$f8,0x2c($t7)
/*    32284:	c5ea0028 */ 	lwc1	$f10,0x28($t7)
/*    32288:	8d450008 */ 	lw	$a1,0x8($t2)
/*    3228c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    32290:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    32294:	44809000 */ 	mtc1	$zero,$f18
/*    32298:	8fab0080 */ 	lw	$t3,0x80($sp)
/*    3229c:	afa00020 */ 	sw	$zero,0x20($sp)
/*    322a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*    322a4:	8fa70078 */ 	lw	$a3,0x78($sp)
/*    322a8:	25e4000c */ 	addiu	$a0,$t7,0xc
/*    322ac:	44068000 */ 	mfc1	$a2,$f16
/*    322b0:	afa90010 */ 	sw	$t1,0x10($sp)
/*    322b4:	afae0014 */ 	sw	$t6,0x14($sp)
/*    322b8:	afab0024 */ 	sw	$t3,0x24($sp)
/*    322bc:	0c00f370 */ 	jal	func0003cdc0
/*    322c0:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*    322c4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    322c8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    322cc:	a18d0045 */ 	sb	$t5,0x45($t4)
/*    322d0:	3c088006 */ 	lui	$t0,%hi(var8005f130)
/*    322d4:	8508f130 */ 	lh	$t0,%lo(var8005f130)($t0)
/*    322d8:	3c018006 */ 	lui	$at,%hi(var8005f130)
/*    322dc:	25190001 */ 	addiu	$t9,$t0,0x1
/*    322e0:	a439f130 */ 	sh	$t9,%lo(var8005f130)($at)
/*    322e4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    322e8:	930a0044 */ 	lbu	$t2,0x44($t8)
/*    322ec:	314f0002 */ 	andi	$t7,$t2,0x2
/*    322f0:	15e000ac */ 	bnez	$t7,.L000325a4
/*    322f4:	00000000 */ 	nop
/*    322f8:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    322fc:	15200085 */ 	bnez	$t1,.L00032514
/*    32300:	00000000 */ 	nop
/*    32304:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    32308:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    3230c:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*    32310:	916d000d */ 	lbu	$t5,0xd($t3)
/*    32314:	a58d003a */ 	sh	$t5,0x3a($t4)
/*    32318:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3231c:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*    32320:	3c08800a */ 	lui	$t0,%hi(var8009c334)
/*    32324:	856d003a */ 	lh	$t5,0x3a($t3)
/*    32328:	856c0038 */ 	lh	$t4,0x38($t3)
/*    3232c:	93380002 */ 	lbu	$t8,0x2($t9)
/*    32330:	8d08c334 */ 	lw	$t0,%lo(var8009c334)($t0)
/*    32334:	01ac0019 */ 	multu	$t5,$t4
/*    32338:	330a001f */ 	andi	$t2,$t8,0x1f
/*    3233c:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    32340:	000a7840 */ 	sll	$t7,$t2,0x1
/*    32344:	010f4821 */ 	addu	$t1,$t0,$t7
/*    32348:	930a000d */ 	lbu	$t2,0xd($t8)
/*    3234c:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32350:	852e0000 */ 	lh	$t6,0x0($t1)
/*    32354:	0000c812 */ 	mflo	$t9
/*    32358:	00000000 */ 	nop
/*    3235c:	00000000 */ 	nop
/*    32360:	032a0019 */ 	multu	$t9,$t2
/*    32364:	00004012 */ 	mflo	$t0
/*    32368:	00000000 */ 	nop
/*    3236c:	00000000 */ 	nop
/*    32370:	0101001a */ 	div	$zero,$t0,$at
/*    32374:	00007812 */ 	mflo	$t7
/*    32378:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    3237c:	00000000 */ 	nop
/*    32380:	01cf0019 */ 	multu	$t6,$t7
/*    32384:	00004812 */ 	mflo	$t1
/*    32388:	00000000 */ 	nop
/*    3238c:	00000000 */ 	nop
/*    32390:	0121001a */ 	div	$zero,$t1,$at
/*    32394:	00005812 */ 	mflo	$t3
/*    32398:	1d600003 */ 	bgtz	$t3,.L000323a8
/*    3239c:	00000000 */ 	nop
/*    323a0:	10000023 */ 	b	.L00032430
/*    323a4:	afa00078 */ 	sw	$zero,0x78($sp)
.L000323a8:
/*    323a8:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    323ac:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*    323b0:	3c0d800a */ 	lui	$t5,%hi(var8009c334)
/*    323b4:	85e9003a */ 	lh	$t1,0x3a($t7)
/*    323b8:	85eb0038 */ 	lh	$t3,0x38($t7)
/*    323bc:	91980002 */ 	lbu	$t8,0x2($t4)
/*    323c0:	8dadc334 */ 	lw	$t5,%lo(var8009c334)($t5)
/*    323c4:	012b0019 */ 	multu	$t1,$t3
/*    323c8:	3319001f */ 	andi	$t9,$t8,0x1f
/*    323cc:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    323d0:	00195040 */ 	sll	$t2,$t9,0x1
/*    323d4:	01aa4021 */ 	addu	$t0,$t5,$t2
/*    323d8:	9319000d */ 	lbu	$t9,0xd($t8)
/*    323dc:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    323e0:	850e0000 */ 	lh	$t6,0x0($t0)
/*    323e4:	00006012 */ 	mflo	$t4
/*    323e8:	00000000 */ 	nop
/*    323ec:	00000000 */ 	nop
/*    323f0:	01990019 */ 	multu	$t4,$t9
/*    323f4:	00006812 */ 	mflo	$t5
/*    323f8:	00000000 */ 	nop
/*    323fc:	00000000 */ 	nop
/*    32400:	01a1001a */ 	div	$zero,$t5,$at
/*    32404:	00005012 */ 	mflo	$t2
/*    32408:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    3240c:	00000000 */ 	nop
/*    32410:	01ca0019 */ 	multu	$t6,$t2
/*    32414:	00004012 */ 	mflo	$t0
/*    32418:	00000000 */ 	nop
/*    3241c:	00000000 */ 	nop
/*    32420:	0101001a */ 	div	$zero,$t0,$at
/*    32424:	00007812 */ 	mflo	$t7
/*    32428:	25e9ffff */ 	addiu	$t1,$t7,-1
/*    3242c:	afa90078 */ 	sw	$t1,0x78($sp)
.L00032430:
/*    32430:	8fab00ac */ 	lw	$t3,0xac($sp)
/*    32434:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32438:	8d780000 */ 	lw	$t8,0x0($t3)
/*    3243c:	c7280028 */ 	lwc1	$f8,0x28($t9)
/*    32440:	c730002c */ 	lwc1	$f16,0x2c($t9)
/*    32444:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*    32448:	448c2000 */ 	mtc1	$t4,$f4
/*    3244c:	00000000 */ 	nop
/*    32450:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    32454:	46083283 */ 	div.s	$f10,$f6,$f8
/*    32458:	46105483 */ 	div.s	$f18,$f10,$f16
/*    3245c:	4600910d */ 	trunc.w.s	$f4,$f18
/*    32460:	440e2000 */ 	mfc1	$t6,$f4
/*    32464:	00000000 */ 	nop
/*    32468:	afae0080 */ 	sw	$t6,0x80($sp)
/*    3246c:	8faa0080 */ 	lw	$t2,0x80($sp)
/*    32470:	3c010053 */ 	lui	$at,0x53
/*    32474:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32478:	0141082a */ 	slt	$at,$t2,$at
/*    3247c:	14200005 */ 	bnez	$at,.L00032494
/*    32480:	00000000 */ 	nop
/*    32484:	0c00cc24 */ 	jal	func00033090
/*    32488:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    3248c:	100002fb */ 	b	.L0003307c
/*    32490:	00000000 */ 	nop
.L00032494:
/*    32494:	3c088006 */ 	lui	$t0,%hi(var8005f12c)
/*    32498:	8d08f12c */ 	lw	$t0,%lo(var8005f12c)($t0)
/*    3249c:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    324a0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    324a4:	8d0f0050 */ 	lw	$t7,0x50($t0)
/*    324a8:	01e95821 */ 	addu	$t3,$t7,$t1
/*    324ac:	af0b003c */ 	sw	$t3,0x3c($t8)
/*    324b0:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    324b4:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    324b8:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    324bc:	0c00f33c */ 	jal	func0003ccf0
/*    324c0:	2484000c */ 	addiu	$a0,$a0,0xc
/*    324c4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    324c8:	a7ac0094 */ 	sh	$t4,0x94($sp)
/*    324cc:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    324d0:	afb90098 */ 	sw	$t9,0x98($sp)
/*    324d4:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    324d8:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    324dc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    324e0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    324e4:	00003825 */ 	or	$a3,$zero,$zero
/*    324e8:	0c00f184 */ 	jal	alEvtqPostEvent
/*    324ec:	24840014 */ 	addiu	$a0,$a0,20
/*    324f0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    324f4:	91ae0044 */ 	lbu	$t6,0x44($t5)
/*    324f8:	31ca0020 */ 	andi	$t2,$t6,0x20
/*    324fc:	11400003 */ 	beqz	$t2,.L0003250c
/*    32500:	00000000 */ 	nop
/*    32504:	0c00cc40 */ 	jal	func00033100
/*    32508:	8fa40060 */ 	lw	$a0,0x60($sp)
.L0003250c:
/*    3250c:	10000025 */ 	b	.L000325a4
/*    32510:	00000000 */ 	nop
.L00032514:
/*    32514:	24080040 */ 	addiu	$t0,$zero,0x40
/*    32518:	a7a80094 */ 	sh	$t0,0x94($sp)
/*    3251c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32520:	afaf0098 */ 	sw	$t7,0x98($sp)
/*    32524:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32528:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    3252c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    32530:	c58a002c */ 	lwc1	$f10,0x2c($t4)
/*    32534:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    32538:	8d780000 */ 	lw	$t8,0x0($t3)
/*    3253c:	44983000 */ 	mtc1	$t8,$f6
/*    32540:	00000000 */ 	nop
/*    32544:	46803220 */ 	cvt.s.w	$f8,$f6
/*    32548:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    3254c:	46128103 */ 	div.s	$f4,$f16,$f18
/*    32550:	4600218d */ 	trunc.w.s	$f6,$f4
/*    32554:	440d3000 */ 	mfc1	$t5,$f6
/*    32558:	00000000 */ 	nop
/*    3255c:	afad0080 */ 	sw	$t5,0x80($sp)
/*    32560:	8fae0080 */ 	lw	$t6,0x80($sp)
/*    32564:	3c010053 */ 	lui	$at,0x53
/*    32568:	3421ec61 */ 	ori	$at,$at,0xec61
/*    3256c:	01c1082a */ 	slt	$at,$t6,$at
/*    32570:	14200005 */ 	bnez	$at,.L00032588
/*    32574:	00000000 */ 	nop
/*    32578:	0c00cc24 */ 	jal	func00033090
/*    3257c:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32580:	100002be */ 	b	.L0003307c
/*    32584:	00000000 */ 	nop
.L00032588:
/*    32588:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    3258c:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    32590:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    32594:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32598:	00003825 */ 	or	$a3,$zero,$zero
/*    3259c:	0c00f184 */ 	jal	alEvtqPostEvent
/*    325a0:	24840014 */ 	addiu	$a0,$a0,20
.L000325a4:
/*    325a4:	1000029c */ 	b	.L00033018
/*    325a8:	00000000 */ 	nop
.L000325ac:
/*    325ac:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*    325b0:	24011000 */ 	addiu	$at,$zero,0x1000
/*    325b4:	95480000 */ 	lhu	$t0,0x0($t2)
/*    325b8:	15010006 */ 	bne	$t0,$at,.L000325d4
/*    325bc:	00000000 */ 	nop
/*    325c0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    325c4:	91e90044 */ 	lbu	$t1,0x44($t7)
/*    325c8:	312b0002 */ 	andi	$t3,$t1,0x2
/*    325cc:	11600056 */ 	beqz	$t3,.L00032728
/*    325d0:	00000000 */ 	nop
.L000325d4:
/*    325d4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    325d8:	24010001 */ 	addiu	$at,$zero,0x1
/*    325dc:	93100045 */ 	lbu	$s0,0x45($t8)
/*    325e0:	12010009 */ 	beq	$s0,$at,.L00032608
/*    325e4:	00000000 */ 	nop
/*    325e8:	24010004 */ 	addiu	$at,$zero,0x4
/*    325ec:	12010040 */ 	beq	$s0,$at,.L000326f0
/*    325f0:	00000000 */ 	nop
/*    325f4:	24010005 */ 	addiu	$at,$zero,0x5
/*    325f8:	1201003d */ 	beq	$s0,$at,.L000326f0
/*    325fc:	00000000 */ 	nop
/*    32600:	1000003f */ 	b	.L00032700
/*    32604:	00000000 */ 	nop
.L00032608:
/*    32608:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    3260c:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    32610:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    32614:	24060040 */ 	addiu	$a2,$zero,0x40
/*    32618:	0c00cc60 */ 	jal	func00033180
/*    3261c:	24840014 */ 	addiu	$a0,$a0,20
/*    32620:	8fac00ac */ 	lw	$t4,0xac($sp)
/*    32624:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32628:	8d990000 */ 	lw	$t9,0x0($t4)
/*    3262c:	c5d00028 */ 	lwc1	$f16,0x28($t6)
/*    32630:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*    32634:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*    32638:	448d4000 */ 	mtc1	$t5,$f8
/*    3263c:	00000000 */ 	nop
/*    32640:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    32644:	46105483 */ 	div.s	$f18,$f10,$f16
/*    32648:	46049183 */ 	div.s	$f6,$f18,$f4
/*    3264c:	4600320d */ 	trunc.w.s	$f8,$f6
/*    32650:	44084000 */ 	mfc1	$t0,$f8
/*    32654:	00000000 */ 	nop
/*    32658:	afa80080 */ 	sw	$t0,0x80($sp)
/*    3265c:	8faf0080 */ 	lw	$t7,0x80($sp)
/*    32660:	3c010053 */ 	lui	$at,0x53
/*    32664:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32668:	01e1082a */ 	slt	$at,$t7,$at
/*    3266c:	14200005 */ 	bnez	$at,.L00032684
/*    32670:	00000000 */ 	nop
/*    32674:	0c00cc24 */ 	jal	func00033090
/*    32678:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    3267c:	10000022 */ 	b	.L00032708
/*    32680:	00000000 */ 	nop
.L00032684:
/*    32684:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32688:	00002825 */ 	or	$a1,$zero,$zero
/*    3268c:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32690:	0c00f33c */ 	jal	func0003ccf0
/*    32694:	2484000c */ 	addiu	$a0,$a0,0xc
/*    32698:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    3269c:	11200010 */ 	beqz	$t1,.L000326e0
/*    326a0:	00000000 */ 	nop
/*    326a4:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    326a8:	a7ab0094 */ 	sh	$t3,0x94($sp)
/*    326ac:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    326b0:	afb80098 */ 	sw	$t8,0x98($sp)
/*    326b4:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    326b8:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    326bc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    326c0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    326c4:	00003825 */ 	or	$a3,$zero,$zero
/*    326c8:	0c00f184 */ 	jal	alEvtqPostEvent
/*    326cc:	24840014 */ 	addiu	$a0,$a0,20
/*    326d0:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    326d4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    326d8:	10000003 */ 	b	.L000326e8
/*    326dc:	a32c0045 */ 	sb	$t4,0x45($t9)
.L000326e0:
/*    326e0:	0c00cc24 */ 	jal	func00033090
/*    326e4:	8fa40060 */ 	lw	$a0,0x60($sp)
.L000326e8:
/*    326e8:	10000007 */ 	b	.L00032708
/*    326ec:	00000000 */ 	nop
.L000326f0:
/*    326f0:	0c00cc24 */ 	jal	func00033090
/*    326f4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    326f8:	10000003 */ 	b	.L00032708
/*    326fc:	00000000 */ 	nop
.L00032700:
/*    32700:	10000001 */ 	b	.L00032708
/*    32704:	00000000 */ 	nop
.L00032708:
/*    32708:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    3270c:	24010002 */ 	addiu	$at,$zero,0x2
/*    32710:	95ae0000 */ 	lhu	$t6,0x0($t5)
/*    32714:	15c10004 */ 	bne	$t6,$at,.L00032728
/*    32718:	00000000 */ 	nop
/*    3271c:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    32720:	240a1000 */ 	addiu	$t2,$zero,0x1000
/*    32724:	a50a0000 */ 	sh	$t2,0x0($t0)
.L00032728:
/*    32728:	1000023b */ 	b	.L00033018
/*    3272c:	00000000 */ 	nop
/*    32730:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*    32734:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32738:	8de90008 */ 	lw	$t1,0x8($t7)
/*    3273c:	a1690041 */ 	sb	$t1,0x41($t3)
/*    32740:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32744:	24010001 */ 	addiu	$at,$zero,0x1
/*    32748:	930c0045 */ 	lbu	$t4,0x45($t8)
/*    3274c:	1581001f */ 	bne	$t4,$at,.L000327cc
/*    32750:	00000000 */ 	nop
/*    32754:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32758:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    3275c:	932d0041 */ 	lbu	$t5,0x41($t9)
/*    32760:	91ca000c */ 	lbu	$t2,0xc($t6)
/*    32764:	01aa4021 */ 	addu	$t0,$t5,$t2
/*    32768:	250fffc0 */ 	addiu	$t7,$t0,-64
/*    3276c:	afaf0074 */ 	sw	$t7,0x74($sp)
/*    32770:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    32774:	19200003 */ 	blez	$t1,.L00032784
/*    32778:	00000000 */ 	nop
/*    3277c:	10000002 */ 	b	.L00032788
/*    32780:	01208025 */ 	or	$s0,$t1,$zero
.L00032784:
/*    32784:	00008025 */ 	or	$s0,$zero,$zero
.L00032788:
/*    32788:	2a01007f */ 	slti	$at,$s0,0x7f
/*    3278c:	10200009 */ 	beqz	$at,.L000327b4
/*    32790:	00000000 */ 	nop
/*    32794:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    32798:	19600003 */ 	blez	$t3,.L000327a8
/*    3279c:	00000000 */ 	nop
/*    327a0:	10000002 */ 	b	.L000327ac
/*    327a4:	01608825 */ 	or	$s1,$t3,$zero
.L000327a8:
/*    327a8:	00008825 */ 	or	$s1,$zero,$zero
.L000327ac:
/*    327ac:	10000003 */ 	b	.L000327bc
/*    327b0:	a3b100a7 */ 	sb	$s1,0xa7($sp)
.L000327b4:
/*    327b4:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    327b8:	a3b800a7 */ 	sb	$t8,0xa7($sp)
.L000327bc:
/*    327bc:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    327c0:	93a500a7 */ 	lbu	$a1,0xa7($sp)
/*    327c4:	0c00f3bc */ 	jal	func0003cef0
/*    327c8:	2484000c */ 	addiu	$a0,$a0,0xc
.L000327cc:
/*    327cc:	10000212 */ 	b	.L00033018
/*    327d0:	00000000 */ 	nop
/*    327d4:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    327d8:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    327dc:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*    327e0:	e72a002c */ 	swc1	$f10,0x2c($t9)
/*    327e4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    327e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    327ec:	91cd0045 */ 	lbu	$t5,0x45($t6)
/*    327f0:	15a10010 */ 	bne	$t5,$at,.L00032834
/*    327f4:	00000000 */ 	nop
/*    327f8:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    327fc:	c550002c */ 	lwc1	$f16,0x2c($t2)
/*    32800:	c5520028 */ 	lwc1	$f18,0x28($t2)
/*    32804:	2544000c */ 	addiu	$a0,$t2,0xc
/*    32808:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    3280c:	44052000 */ 	mfc1	$a1,$f4
/*    32810:	0c00f3e8 */ 	jal	func0003cfa0
/*    32814:	00000000 */ 	nop
/*    32818:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    3281c:	910f0044 */ 	lbu	$t7,0x44($t0)
/*    32820:	31e90020 */ 	andi	$t1,$t7,0x20
/*    32824:	11200003 */ 	beqz	$t1,.L00032834
/*    32828:	00000000 */ 	nop
/*    3282c:	0c00cc40 */ 	jal	func00033100
/*    32830:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00032834:
/*    32834:	100001f8 */ 	b	.L00033018
/*    32838:	00000000 */ 	nop
.L0003283c:
/*    3283c:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*    32840:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32844:	8d780008 */ 	lw	$t8,0x8($t3)
/*    32848:	a1980042 */ 	sb	$t8,0x42($t4)
/*    3284c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32850:	24010001 */ 	addiu	$at,$zero,0x1
/*    32854:	932e0045 */ 	lbu	$t6,0x45($t9)
/*    32858:	15c10027 */ 	bne	$t6,$at,.L000328f8
/*    3285c:	00000000 */ 	nop
/*    32860:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*    32864:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32868:	91e90003 */ 	lbu	$t1,0x3($t7)
/*    3286c:	91aa0042 */ 	lbu	$t2,0x42($t5)
/*    32870:	312b000f */ 	andi	$t3,$t1,0xf
/*    32874:	000bc0c0 */ 	sll	$t8,$t3,0x3
/*    32878:	3148007f */ 	andi	$t0,$t2,0x7f
/*    3287c:	01186021 */ 	addu	$t4,$t0,$t8
/*    32880:	afac007c */ 	sw	$t4,0x7c($sp)
/*    32884:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*    32888:	07210003 */ 	bgez	$t9,.L00032898
/*    3288c:	00000000 */ 	nop
/*    32890:	10000002 */ 	b	.L0003289c
/*    32894:	00008025 */ 	or	$s0,$zero,$zero
.L00032898:
/*    32898:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L0003289c:
/*    3289c:	2a010080 */ 	slti	$at,$s0,0x80
/*    328a0:	14200004 */ 	bnez	$at,.L000328b4
/*    328a4:	00000000 */ 	nop
/*    328a8:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    328ac:	10000008 */ 	b	.L000328d0
/*    328b0:	afae007c */ 	sw	$t6,0x7c($sp)
.L000328b4:
/*    328b4:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    328b8:	05a10003 */ 	bgez	$t5,.L000328c8
/*    328bc:	00000000 */ 	nop
/*    328c0:	10000002 */ 	b	.L000328cc
/*    328c4:	00008825 */ 	or	$s1,$zero,$zero
.L000328c8:
/*    328c8:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L000328cc:
/*    328cc:	afb1007c */ 	sw	$s1,0x7c($sp)
.L000328d0:
/*    328d0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    328d4:	8faa007c */ 	lw	$t2,0x7c($sp)
/*    328d8:	91e90042 */ 	lbu	$t1,0x42($t7)
/*    328dc:	312b0080 */ 	andi	$t3,$t1,0x80
/*    328e0:	014b4025 */ 	or	$t0,$t2,$t3
/*    328e4:	afa8007c */ 	sw	$t0,0x7c($sp)
/*    328e8:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    328ec:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*    328f0:	0c00f414 */ 	jal	func0003d050
/*    328f4:	2484000c */ 	addiu	$a0,$a0,0xc
.L000328f8:
/*    328f8:	100001c7 */ 	b	.L00033018
/*    328fc:	00000000 */ 	nop
.L00032900:
/*    32900:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32904:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    32908:	930c0042 */ 	lbu	$t4,0x42($t8)
/*    3290c:	8daf0008 */ 	lw	$t7,0x8($t5)
/*    32910:	3199007f */ 	andi	$t9,$t4,0x7f
/*    32914:	31e90080 */ 	andi	$t1,$t7,0x80
/*    32918:	312a00ff */ 	andi	$t2,$t1,0xff
/*    3291c:	332e00ff */ 	andi	$t6,$t9,0xff
/*    32920:	01ca5825 */ 	or	$t3,$t6,$t2
/*    32924:	a30b0042 */ 	sb	$t3,0x42($t8)
/*    32928:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    3292c:	24010001 */ 	addiu	$at,$zero,0x1
/*    32930:	910c0045 */ 	lbu	$t4,0x45($t0)
/*    32934:	15810027 */ 	bne	$t4,$at,.L000329d4
/*    32938:	00000000 */ 	nop
/*    3293c:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*    32940:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32944:	912e0003 */ 	lbu	$t6,0x3($t1)
/*    32948:	932d0042 */ 	lbu	$t5,0x42($t9)
/*    3294c:	31ca000f */ 	andi	$t2,$t6,0xf
/*    32950:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    32954:	31af007f */ 	andi	$t7,$t5,0x7f
/*    32958:	01ebc021 */ 	addu	$t8,$t7,$t3
/*    3295c:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    32960:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    32964:	05010003 */ 	bgez	$t0,.L00032974
/*    32968:	00000000 */ 	nop
/*    3296c:	10000002 */ 	b	.L00032978
/*    32970:	00008025 */ 	or	$s0,$zero,$zero
.L00032974:
/*    32974:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L00032978:
/*    32978:	2a010080 */ 	slti	$at,$s0,0x80
/*    3297c:	14200004 */ 	bnez	$at,.L00032990
/*    32980:	00000000 */ 	nop
/*    32984:	240c007f */ 	addiu	$t4,$zero,0x7f
/*    32988:	10000008 */ 	b	.L000329ac
/*    3298c:	afac007c */ 	sw	$t4,0x7c($sp)
.L00032990:
/*    32990:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*    32994:	07210003 */ 	bgez	$t9,.L000329a4
/*    32998:	00000000 */ 	nop
/*    3299c:	10000002 */ 	b	.L000329a8
/*    329a0:	00008825 */ 	or	$s1,$zero,$zero
.L000329a4:
/*    329a4:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L000329a8:
/*    329a8:	afb1007c */ 	sw	$s1,0x7c($sp)
.L000329ac:
/*    329ac:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    329b0:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    329b4:	912e0042 */ 	lbu	$t6,0x42($t1)
/*    329b8:	31ca0080 */ 	andi	$t2,$t6,0x80
/*    329bc:	01aa7825 */ 	or	$t7,$t5,$t2
/*    329c0:	afaf007c */ 	sw	$t7,0x7c($sp)
/*    329c4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    329c8:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*    329cc:	0c00f414 */ 	jal	func0003d050
/*    329d0:	2484000c */ 	addiu	$a0,$a0,0xc
.L000329d4:
/*    329d4:	10000190 */ 	b	.L00033018
/*    329d8:	00000000 */ 	nop
.L000329dc:
/*    329dc:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*    329e0:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    329e4:	8d780008 */ 	lw	$t8,0x8($t3)
/*    329e8:	a1180043 */ 	sb	$t8,0x43($t0)
/*    329ec:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    329f0:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    329f4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    329f8:	8d2e003c */ 	lw	$t6,0x3c($t1)
/*    329fc:	91990043 */ 	lbu	$t9,0x43($t4)
/*    32a00:	032e082a */ 	slt	$at,$t9,$t6
/*    32a04:	14200003 */ 	bnez	$at,.L00032a14
/*    32a08:	00000000 */ 	nop
/*    32a0c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32a10:	a1a00043 */ 	sb	$zero,0x43($t5)
.L00032a14:
/*    32a14:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32a18:	24010001 */ 	addiu	$at,$zero,0x1
/*    32a1c:	914f0045 */ 	lbu	$t7,0x45($t2)
/*    32a20:	15e10004 */ 	bne	$t7,$at,.L00032a34
/*    32a24:	00000000 */ 	nop
/*    32a28:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32a2c:	91780043 */ 	lbu	$t8,0x43($t3)
/*    32a30:	a5780024 */ 	sh	$t8,0x24($t3)
.L00032a34:
/*    32a34:	10000178 */ 	b	.L00033018
/*    32a38:	00000000 */ 	nop
/*    32a3c:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    32a40:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32a44:	8d0c0008 */ 	lw	$t4,0x8($t0)
/*    32a48:	a52c0038 */ 	sh	$t4,0x38($t1)
/*    32a4c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32a50:	24010001 */ 	addiu	$at,$zero,0x1
/*    32a54:	932e0045 */ 	lbu	$t6,0x45($t9)
/*    32a58:	15c1005d */ 	bne	$t6,$at,.L00032bd0
/*    32a5c:	00000000 */ 	nop
/*    32a60:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32a64:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*    32a68:	3c0d800a */ 	lui	$t5,%hi(var8009c334)
/*    32a6c:	8539003a */ 	lh	$t9,0x3a($t1)
/*    32a70:	852e0038 */ 	lh	$t6,0x38($t1)
/*    32a74:	914f0002 */ 	lbu	$t7,0x2($t2)
/*    32a78:	8dadc334 */ 	lw	$t5,%lo(var8009c334)($t5)
/*    32a7c:	032e0019 */ 	multu	$t9,$t6
/*    32a80:	31f8001f */ 	andi	$t8,$t7,0x1f
/*    32a84:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    32a88:	00185840 */ 	sll	$t3,$t8,0x1
/*    32a8c:	01ab4021 */ 	addu	$t0,$t5,$t3
/*    32a90:	91f8000d */ 	lbu	$t8,0xd($t7)
/*    32a94:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32a98:	850c0000 */ 	lh	$t4,0x0($t0)
/*    32a9c:	00005012 */ 	mflo	$t2
/*    32aa0:	00000000 */ 	nop
/*    32aa4:	00000000 */ 	nop
/*    32aa8:	01580019 */ 	multu	$t2,$t8
/*    32aac:	00006812 */ 	mflo	$t5
/*    32ab0:	00000000 */ 	nop
/*    32ab4:	00000000 */ 	nop
/*    32ab8:	01a1001a */ 	div	$zero,$t5,$at
/*    32abc:	00005812 */ 	mflo	$t3
/*    32ac0:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32ac4:	00000000 */ 	nop
/*    32ac8:	018b0019 */ 	multu	$t4,$t3
/*    32acc:	00004012 */ 	mflo	$t0
/*    32ad0:	00000000 */ 	nop
/*    32ad4:	00000000 */ 	nop
/*    32ad8:	0101001a */ 	div	$zero,$t0,$at
/*    32adc:	00004812 */ 	mflo	$t1
/*    32ae0:	1d200003 */ 	bgtz	$t1,.L00032af0
/*    32ae4:	00000000 */ 	nop
/*    32ae8:	10000023 */ 	b	.L00032b78
/*    32aec:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032af0:
/*    32af0:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32af4:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*    32af8:	3c19800a */ 	lui	$t9,%hi(var8009c334)
/*    32afc:	8568003a */ 	lh	$t0,0x3a($t3)
/*    32b00:	85690038 */ 	lh	$t1,0x38($t3)
/*    32b04:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    32b08:	8f39c334 */ 	lw	$t9,%lo(var8009c334)($t9)
/*    32b0c:	01090019 */ 	multu	$t0,$t1
/*    32b10:	31ea001f */ 	andi	$t2,$t7,0x1f
/*    32b14:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    32b18:	000ac040 */ 	sll	$t8,$t2,0x1
/*    32b1c:	03386821 */ 	addu	$t5,$t9,$t8
/*    32b20:	91ea000d */ 	lbu	$t2,0xd($t7)
/*    32b24:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32b28:	85ac0000 */ 	lh	$t4,0x0($t5)
/*    32b2c:	00007012 */ 	mflo	$t6
/*    32b30:	00000000 */ 	nop
/*    32b34:	00000000 */ 	nop
/*    32b38:	01ca0019 */ 	multu	$t6,$t2
/*    32b3c:	0000c812 */ 	mflo	$t9
/*    32b40:	00000000 */ 	nop
/*    32b44:	00000000 */ 	nop
/*    32b48:	0321001a */ 	div	$zero,$t9,$at
/*    32b4c:	0000c012 */ 	mflo	$t8
/*    32b50:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32b54:	00000000 */ 	nop
/*    32b58:	01980019 */ 	multu	$t4,$t8
/*    32b5c:	00006812 */ 	mflo	$t5
/*    32b60:	00000000 */ 	nop
/*    32b64:	00000000 */ 	nop
/*    32b68:	01a1001a */ 	div	$zero,$t5,$at
/*    32b6c:	00005812 */ 	mflo	$t3
/*    32b70:	2568ffff */ 	addiu	$t0,$t3,-1
/*    32b74:	afa80078 */ 	sw	$t0,0x78($sp)
.L00032b78:
/*    32b78:	3c0e8006 */ 	lui	$t6,%hi(var8005f12c)
/*    32b7c:	8dcef12c */ 	lw	$t6,%lo(var8005f12c)($t6)
/*    32b80:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32b84:	8dca0050 */ 	lw	$t2,0x50($t6)
/*    32b88:	8d2f003c */ 	lw	$t7,0x3c($t1)
/*    32b8c:	01eac823 */ 	subu	$t9,$t7,$t2
/*    32b90:	2b2103e8 */ 	slti	$at,$t9,0x3e8
/*    32b94:	10200003 */ 	beqz	$at,.L00032ba4
/*    32b98:	00000000 */ 	nop
/*    32b9c:	10000007 */ 	b	.L00032bbc
/*    32ba0:	241003e8 */ 	addiu	$s0,$zero,0x3e8
.L00032ba4:
/*    32ba4:	3c0d8006 */ 	lui	$t5,%hi(var8005f12c)
/*    32ba8:	8dadf12c */ 	lw	$t5,%lo(var8005f12c)($t5)
/*    32bac:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32bb0:	8dab0050 */ 	lw	$t3,0x50($t5)
/*    32bb4:	8d98003c */ 	lw	$t8,0x3c($t4)
/*    32bb8:	030b8023 */ 	subu	$s0,$t8,$t3
.L00032bbc:
/*    32bbc:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32bc0:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32bc4:	02003025 */ 	or	$a2,$s0,$zero
/*    32bc8:	0c00f33c */ 	jal	func0003ccf0
/*    32bcc:	2484000c */ 	addiu	$a0,$a0,0xc
.L00032bd0:
/*    32bd0:	10000111 */ 	b	.L00033018
/*    32bd4:	00000000 */ 	nop
.L00032bd8:
/*    32bd8:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32bdc:	24010001 */ 	addiu	$at,$zero,0x1
/*    32be0:	91090045 */ 	lbu	$t1,0x45($t0)
/*    32be4:	15210065 */ 	bne	$t1,$at,.L00032d7c
/*    32be8:	00000000 */ 	nop
/*    32bec:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    32bf0:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32bf4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    32bf8:	c72a0028 */ 	lwc1	$f10,0x28($t9)
/*    32bfc:	c732002c */ 	lwc1	$f18,0x2c($t9)
/*    32c00:	8dea0008 */ 	lw	$t2,0x8($t7)
/*    32c04:	448a3000 */ 	mtc1	$t2,$f6
/*    32c08:	00000000 */ 	nop
/*    32c0c:	46803220 */ 	cvt.s.w	$f8,$f6
/*    32c10:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    32c14:	46128103 */ 	div.s	$f4,$f16,$f18
/*    32c18:	4600218d */ 	trunc.w.s	$f6,$f4
/*    32c1c:	440d3000 */ 	mfc1	$t5,$f6
/*    32c20:	00000000 */ 	nop
/*    32c24:	afad0080 */ 	sw	$t5,0x80($sp)
/*    32c28:	8fb80080 */ 	lw	$t8,0x80($sp)
/*    32c2c:	3c010053 */ 	lui	$at,0x53
/*    32c30:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32c34:	0301082a */ 	slt	$at,$t8,$at
/*    32c38:	14200005 */ 	bnez	$at,.L00032c50
/*    32c3c:	00000000 */ 	nop
/*    32c40:	0c00cc24 */ 	jal	func00033090
/*    32c44:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32c48:	100000f3 */ 	b	.L00033018
/*    32c4c:	00000000 */ 	nop
.L00032c50:
/*    32c50:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32c54:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*    32c58:	3c0b800a */ 	lui	$t3,%hi(var8009c334)
/*    32c5c:	858d003a */ 	lh	$t5,0x3a($t4)
/*    32c60:	85980038 */ 	lh	$t8,0x38($t4)
/*    32c64:	91090002 */ 	lbu	$t1,0x2($t0)
/*    32c68:	8d6bc334 */ 	lw	$t3,%lo(var8009c334)($t3)
/*    32c6c:	01b80019 */ 	multu	$t5,$t8
/*    32c70:	312e001f */ 	andi	$t6,$t1,0x1f
/*    32c74:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32c78:	000e7840 */ 	sll	$t7,$t6,0x1
/*    32c7c:	016f5021 */ 	addu	$t2,$t3,$t7
/*    32c80:	912e000d */ 	lbu	$t6,0xd($t1)
/*    32c84:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32c88:	85590000 */ 	lh	$t9,0x0($t2)
/*    32c8c:	00004012 */ 	mflo	$t0
/*    32c90:	00000000 */ 	nop
/*    32c94:	00000000 */ 	nop
/*    32c98:	010e0019 */ 	multu	$t0,$t6
/*    32c9c:	00005812 */ 	mflo	$t3
/*    32ca0:	00000000 */ 	nop
/*    32ca4:	00000000 */ 	nop
/*    32ca8:	0161001a */ 	div	$zero,$t3,$at
/*    32cac:	00007812 */ 	mflo	$t7
/*    32cb0:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32cb4:	00000000 */ 	nop
/*    32cb8:	032f0019 */ 	multu	$t9,$t7
/*    32cbc:	00005012 */ 	mflo	$t2
/*    32cc0:	00000000 */ 	nop
/*    32cc4:	00000000 */ 	nop
/*    32cc8:	0141001a */ 	div	$zero,$t2,$at
/*    32ccc:	00006012 */ 	mflo	$t4
/*    32cd0:	1d800003 */ 	bgtz	$t4,.L00032ce0
/*    32cd4:	00000000 */ 	nop
/*    32cd8:	10000023 */ 	b	.L00032d68
/*    32cdc:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032ce0:
/*    32ce0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32ce4:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*    32ce8:	3c0d800a */ 	lui	$t5,%hi(var8009c334)
/*    32cec:	85ea003a */ 	lh	$t2,0x3a($t7)
/*    32cf0:	85ec0038 */ 	lh	$t4,0x38($t7)
/*    32cf4:	93090002 */ 	lbu	$t1,0x2($t8)
/*    32cf8:	8dadc334 */ 	lw	$t5,%lo(var8009c334)($t5)
/*    32cfc:	014c0019 */ 	multu	$t2,$t4
/*    32d00:	3128001f */ 	andi	$t0,$t1,0x1f
/*    32d04:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32d08:	00087040 */ 	sll	$t6,$t0,0x1
/*    32d0c:	01ae5821 */ 	addu	$t3,$t5,$t6
/*    32d10:	9128000d */ 	lbu	$t0,0xd($t1)
/*    32d14:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32d18:	85790000 */ 	lh	$t9,0x0($t3)
/*    32d1c:	0000c012 */ 	mflo	$t8
/*    32d20:	00000000 */ 	nop
/*    32d24:	00000000 */ 	nop
/*    32d28:	03080019 */ 	multu	$t8,$t0
/*    32d2c:	00006812 */ 	mflo	$t5
/*    32d30:	00000000 */ 	nop
/*    32d34:	00000000 */ 	nop
/*    32d38:	01a1001a */ 	div	$zero,$t5,$at
/*    32d3c:	00007012 */ 	mflo	$t6
/*    32d40:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32d44:	00000000 */ 	nop
/*    32d48:	032e0019 */ 	multu	$t9,$t6
/*    32d4c:	00005812 */ 	mflo	$t3
/*    32d50:	00000000 */ 	nop
/*    32d54:	00000000 */ 	nop
/*    32d58:	0161001a */ 	div	$zero,$t3,$at
/*    32d5c:	00007812 */ 	mflo	$t7
/*    32d60:	25eaffff */ 	addiu	$t2,$t7,-1
/*    32d64:	afaa0078 */ 	sw	$t2,0x78($sp)
.L00032d68:
/*    32d68:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32d6c:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32d70:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32d74:	0c00f33c */ 	jal	func0003ccf0
/*    32d78:	2484000c */ 	addiu	$a0,$a0,0xc
.L00032d7c:
/*    32d7c:	100000a6 */ 	b	.L00033018
/*    32d80:	00000000 */ 	nop
.L00032d84:
/*    32d84:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32d88:	91890044 */ 	lbu	$t1,0x44($t4)
/*    32d8c:	31380002 */ 	andi	$t8,$t1,0x2
/*    32d90:	17000083 */ 	bnez	$t8,.L00032fa0
/*    32d94:	00000000 */ 	nop
/*    32d98:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    32d9c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32da0:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*    32da4:	91b9000d */ 	lbu	$t9,0xd($t5)
/*    32da8:	a5d9003a */ 	sh	$t9,0x3a($t6)
/*    32dac:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32db0:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*    32db4:	3c0b800a */ 	lui	$t3,%hi(var8009c334)
/*    32db8:	85b9003a */ 	lh	$t9,0x3a($t5)
/*    32dbc:	85ae0038 */ 	lh	$t6,0x38($t5)
/*    32dc0:	91ea0002 */ 	lbu	$t2,0x2($t7)
/*    32dc4:	8d6bc334 */ 	lw	$t3,%lo(var8009c334)($t3)
/*    32dc8:	032e0019 */ 	multu	$t9,$t6
/*    32dcc:	314c001f */ 	andi	$t4,$t2,0x1f
/*    32dd0:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    32dd4:	000c4840 */ 	sll	$t1,$t4,0x1
/*    32dd8:	0169c021 */ 	addu	$t8,$t3,$t1
/*    32ddc:	914c000d */ 	lbu	$t4,0xd($t2)
/*    32de0:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32de4:	87080000 */ 	lh	$t0,0x0($t8)
/*    32de8:	00007812 */ 	mflo	$t7
/*    32dec:	00000000 */ 	nop
/*    32df0:	00000000 */ 	nop
/*    32df4:	01ec0019 */ 	multu	$t7,$t4
/*    32df8:	00005812 */ 	mflo	$t3
/*    32dfc:	00000000 */ 	nop
/*    32e00:	00000000 */ 	nop
/*    32e04:	0161001a */ 	div	$zero,$t3,$at
/*    32e08:	00004812 */ 	mflo	$t1
/*    32e0c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32e10:	00000000 */ 	nop
/*    32e14:	01090019 */ 	multu	$t0,$t1
/*    32e18:	0000c012 */ 	mflo	$t8
/*    32e1c:	00000000 */ 	nop
/*    32e20:	00000000 */ 	nop
/*    32e24:	0301001a */ 	div	$zero,$t8,$at
/*    32e28:	00006812 */ 	mflo	$t5
/*    32e2c:	1da00003 */ 	bgtz	$t5,.L00032e3c
/*    32e30:	00000000 */ 	nop
/*    32e34:	10000023 */ 	b	.L00032ec4
/*    32e38:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032e3c:
/*    32e3c:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32e40:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*    32e44:	3c19800a */ 	lui	$t9,%hi(var8009c334)
/*    32e48:	8538003a */ 	lh	$t8,0x3a($t1)
/*    32e4c:	852d0038 */ 	lh	$t5,0x38($t1)
/*    32e50:	91ca0002 */ 	lbu	$t2,0x2($t6)
/*    32e54:	8f39c334 */ 	lw	$t9,%lo(var8009c334)($t9)
/*    32e58:	030d0019 */ 	multu	$t8,$t5
/*    32e5c:	314f001f */ 	andi	$t7,$t2,0x1f
/*    32e60:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    32e64:	000f6040 */ 	sll	$t4,$t7,0x1
/*    32e68:	032c5821 */ 	addu	$t3,$t9,$t4
/*    32e6c:	914f000d */ 	lbu	$t7,0xd($t2)
/*    32e70:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32e74:	85680000 */ 	lh	$t0,0x0($t3)
/*    32e78:	00007012 */ 	mflo	$t6
/*    32e7c:	00000000 */ 	nop
/*    32e80:	00000000 */ 	nop
/*    32e84:	01cf0019 */ 	multu	$t6,$t7
/*    32e88:	0000c812 */ 	mflo	$t9
/*    32e8c:	00000000 */ 	nop
/*    32e90:	00000000 */ 	nop
/*    32e94:	0321001a */ 	div	$zero,$t9,$at
/*    32e98:	00006012 */ 	mflo	$t4
/*    32e9c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32ea0:	00000000 */ 	nop
/*    32ea4:	010c0019 */ 	multu	$t0,$t4
/*    32ea8:	00005812 */ 	mflo	$t3
/*    32eac:	00000000 */ 	nop
/*    32eb0:	00000000 */ 	nop
/*    32eb4:	0161001a */ 	div	$zero,$t3,$at
/*    32eb8:	00004812 */ 	mflo	$t1
/*    32ebc:	2538ffff */ 	addiu	$t8,$t1,-1
/*    32ec0:	afb80078 */ 	sw	$t8,0x78($sp)
.L00032ec4:
/*    32ec4:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32ec8:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32ecc:	8daa0000 */ 	lw	$t2,0x0($t5)
/*    32ed0:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*    32ed4:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    32ed8:	8d4e0004 */ 	lw	$t6,0x4($t2)
/*    32edc:	448e4000 */ 	mtc1	$t6,$f8
/*    32ee0:	00000000 */ 	nop
/*    32ee4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    32ee8:	46105483 */ 	div.s	$f18,$f10,$f16
/*    32eec:	46049183 */ 	div.s	$f6,$f18,$f4
/*    32ef0:	4600320d */ 	trunc.w.s	$f8,$f6
/*    32ef4:	44084000 */ 	mfc1	$t0,$f8
/*    32ef8:	00000000 */ 	nop
/*    32efc:	afa80080 */ 	sw	$t0,0x80($sp)
/*    32f00:	8fac0080 */ 	lw	$t4,0x80($sp)
/*    32f04:	3c010053 */ 	lui	$at,0x53
/*    32f08:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32f0c:	0181082a */ 	slt	$at,$t4,$at
/*    32f10:	14200005 */ 	bnez	$at,.L00032f28
/*    32f14:	00000000 */ 	nop
/*    32f18:	0c00cc24 */ 	jal	func00033090
/*    32f1c:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32f20:	1000003d */ 	b	.L00033018
/*    32f24:	00000000 */ 	nop
.L00032f28:
/*    32f28:	3c0b8006 */ 	lui	$t3,%hi(var8005f12c)
/*    32f2c:	8d6bf12c */ 	lw	$t3,%lo(var8005f12c)($t3)
/*    32f30:	8fb80080 */ 	lw	$t8,0x80($sp)
/*    32f34:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32f38:	8d690050 */ 	lw	$t1,0x50($t3)
/*    32f3c:	01386821 */ 	addu	$t5,$t1,$t8
/*    32f40:	ad4d003c */ 	sw	$t5,0x3c($t2)
/*    32f44:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32f48:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32f4c:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32f50:	0c00f33c */ 	jal	func0003ccf0
/*    32f54:	2484000c */ 	addiu	$a0,$a0,0xc
/*    32f58:	240e0002 */ 	addiu	$t6,$zero,0x2
/*    32f5c:	a7ae0094 */ 	sh	$t6,0x94($sp)
/*    32f60:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32f64:	afaf0098 */ 	sw	$t7,0x98($sp)
/*    32f68:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    32f6c:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    32f70:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    32f74:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32f78:	00003825 */ 	or	$a3,$zero,$zero
/*    32f7c:	0c00f184 */ 	jal	alEvtqPostEvent
/*    32f80:	24840014 */ 	addiu	$a0,$a0,20
/*    32f84:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32f88:	93280044 */ 	lbu	$t0,0x44($t9)
/*    32f8c:	310c0020 */ 	andi	$t4,$t0,0x20
/*    32f90:	11800003 */ 	beqz	$t4,.L00032fa0
/*    32f94:	00000000 */ 	nop
/*    32f98:	0c00cc40 */ 	jal	func00033100
/*    32f9c:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00032fa0:
/*    32fa0:	1000001d */ 	b	.L00033018
/*    32fa4:	00000000 */ 	nop
.L00032fa8:
/*    32fa8:	0c00cc24 */ 	jal	func00033090
/*    32fac:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32fb0:	10000019 */ 	b	.L00033018
/*    32fb4:	00000000 */ 	nop
.L00032fb8:
/*    32fb8:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32fbc:	91690044 */ 	lbu	$t1,0x44($t3)
/*    32fc0:	31380010 */ 	andi	$t8,$t1,0x10
/*    32fc4:	13000010 */ 	beqz	$t8,.L00033008
/*    32fc8:	00000000 */ 	nop
/*    32fcc:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32fd0:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    32fd4:	c54a002c */ 	lwc1	$f10,0x2c($t2)
/*    32fd8:	85460038 */ 	lh	$a2,0x38($t2)
/*    32fdc:	91470041 */ 	lbu	$a3,0x41($t2)
/*    32fe0:	8da4000c */ 	lw	$a0,0xc($t5)
/*    32fe4:	8da50008 */ 	lw	$a1,0x8($t5)
/*    32fe8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    32fec:	914e0042 */ 	lbu	$t6,0x42($t2)
/*    32ff0:	afae0014 */ 	sw	$t6,0x14($sp)
/*    32ff4:	914f0043 */ 	lbu	$t7,0x43($t2)
/*    32ff8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    32ffc:	8d590030 */ 	lw	$t9,0x30($t2)
/*    33000:	0c00ce08 */ 	jal	func00033820
/*    33004:	afb9001c */ 	sw	$t9,0x1c($sp)
.L00033008:
/*    33008:	10000003 */ 	b	.L00033018
/*    3300c:	00000000 */ 	nop
.L00033010:
/*    33010:	10000001 */ 	b	.L00033018
/*    33014:	00000000 */ 	nop
.L00033018:
/*    33018:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    3301c:	950c0000 */ 	lhu	$t4,0x0($t0)
/*    33020:	318b02d1 */ 	andi	$t3,$t4,0x2d1
/*    33024:	afab006c */ 	sw	$t3,0x6c($sp)
/*    33028:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    3302c:	11200008 */ 	beqz	$t1,.L00033050
/*    33030:	afa90060 */ 	sw	$t1,0x60($sp)
/*    33034:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*    33038:	17000005 */ 	bnez	$t8,.L00033050
/*    3303c:	00000000 */ 	nop
/*    33040:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    33044:	91ae0044 */ 	lbu	$t6,0x44($t5)
/*    33048:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    3304c:	afaf0068 */ 	sw	$t7,0x68($sp)
.L00033050:
/*    33050:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    33054:	15400007 */ 	bnez	$t2,.L00033074
/*    33058:	00000000 */ 	nop
/*    3305c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    33060:	13200004 */ 	beqz	$t9,.L00033074
/*    33064:	00000000 */ 	nop
/*    33068:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*    3306c:	1100fabb */ 	beqz	$t0,.L00031b5c
/*    33070:	00000000 */ 	nop
.L00033074:
/*    33074:	10000001 */ 	b	.L0003307c
/*    33078:	00000000 */ 	nop
.L0003307c:
/*    3307c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    33080:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*    33084:	8fb10030 */ 	lw	$s1,0x30($sp)
/*    33088:	03e00008 */ 	jr	$ra
/*    3308c:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func00033090
/*    33090:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33094:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33098:	afa40018 */ 	sw	$a0,0x18($sp)
/*    3309c:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    330a0:	91cf0044 */ 	lbu	$t7,0x44($t6)
/*    330a4:	31f80004 */ 	andi	$t8,$t7,0x4
/*    330a8:	13000007 */ 	beqz	$t8,.L000330c8
/*    330ac:	00000000 */ 	nop
/*    330b0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330b4:	0c00f440 */ 	jal	func0003d100
/*    330b8:	2484000c */ 	addiu	$a0,$a0,0xc
/*    330bc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330c0:	0c00f468 */ 	jal	func0003d1a0
/*    330c4:	2484000c */ 	addiu	$a0,$a0,0xc
.L000330c8:
/*    330c8:	0c00cd93 */ 	jal	func0003364c
/*    330cc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330d0:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    330d4:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    330d8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    330dc:	3406ffff */ 	dli	$a2,0xffff
/*    330e0:	0c00cc60 */ 	jal	func00033180
/*    330e4:	24840014 */ 	addiu	$a0,$a0,20
/*    330e8:	10000001 */ 	b	.L000330f0
/*    330ec:	00000000 */ 	nop
.L000330f0:
/*    330f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    330f4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    330f8:	03e00008 */ 	jr	$ra
/*    330fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033100
/*    33100:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33108:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3310c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    33110:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    33114:	8df80004 */ 	lw	$t8,0x4($t7)
/*    33118:	0c00e7f8 */ 	jal	func00039fe0
/*    3311c:	83040005 */ 	lb	$a0,0x5($t8)
/*    33120:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    33124:	c724002c */ 	lwc1	$f4,0x2c($t9)
/*    33128:	46040182 */ 	mul.s	$f6,$f0,$f4
/*    3312c:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    33130:	24080010 */ 	addiu	$t0,$zero,0x10
/*    33134:	a7a80020 */ 	sh	$t0,0x20($sp)
/*    33138:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3313c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    33140:	27aa001c */ 	addiu	$t2,$sp,0x1c
/*    33144:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    33148:	afab0028 */ 	sw	$t3,0x28($sp)
/*    3314c:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33150:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33154:	27a50020 */ 	addiu	$a1,$sp,0x20
/*    33158:	34068235 */ 	dli	$a2,0x8235
/*    3315c:	00003825 */ 	or	$a3,$zero,$zero
/*    33160:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33164:	24840014 */ 	addiu	$a0,$a0,20
/*    33168:	10000001 */ 	b	.L00033170
/*    3316c:	00000000 */ 	nop
.L00033170:
/*    33170:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33174:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33178:	03e00008 */ 	jr	$ra
/*    3317c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033180
/*    33180:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33188:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3318c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33190:	afa60038 */ 	sw	$a2,0x38($sp)
/*    33194:	0c012194 */ 	jal	osSetIntMask
/*    33198:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3319c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    331a0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    331a4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    331a8:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    331ac:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    331b0:	13000028 */ 	beqz	$t8,.L00033254
/*    331b4:	00000000 */ 	nop
.L000331b8:
/*    331b8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    331bc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    331c0:	afa80028 */ 	sw	$t0,0x28($sp)
/*    331c4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    331c8:	afa90024 */ 	sw	$t1,0x24($sp)
/*    331cc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    331d0:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    331d4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    331d8:	256c000c */ 	addiu	$t4,$t3,0xc
/*    331dc:	afac001c */ 	sw	$t4,0x1c($sp)
/*    331e0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    331e4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    331e8:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    331ec:	15cf0014 */ 	bne	$t6,$t7,.L00033240
/*    331f0:	00000000 */ 	nop
/*    331f4:	95b80000 */ 	lhu	$t8,0x0($t5)
/*    331f8:	97b9003a */ 	lhu	$t9,0x3a($sp)
/*    331fc:	03194024 */ 	and	$t0,$t8,$t9
/*    33200:	1100000f */ 	beqz	$t0,.L00033240
/*    33204:	00000000 */ 	nop
/*    33208:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3320c:	11200007 */ 	beqz	$t1,.L0003322c
/*    33210:	00000000 */ 	nop
/*    33214:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    33218:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3321c:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    33220:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*    33224:	016e7821 */ 	addu	$t7,$t3,$t6
/*    33228:	ad4f0008 */ 	sw	$t7,0x8($t2)
.L0003322c:
/*    3322c:	0c00c5e9 */ 	jal	alUnlink
/*    33230:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33234:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33238:	0c00c5dc */ 	jal	alLink
/*    3323c:	8fa50030 */ 	lw	$a1,0x30($sp)
.L00033240:
/*    33240:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    33244:	afad002c */ 	sw	$t5,0x2c($sp)
/*    33248:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3324c:	1700ffda */ 	bnez	$t8,.L000331b8
/*    33250:	00000000 */ 	nop
.L00033254:
/*    33254:	0c012194 */ 	jal	osSetIntMask
/*    33258:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    3325c:	10000001 */ 	b	.L00033264
/*    33260:	00000000 */ 	nop
.L00033264:
/*    33264:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33268:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3326c:	03e00008 */ 	jr	$ra
/*    33270:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033274
/*    33274:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33278:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3327c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33280:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33284:	0c012194 */ 	jal	osSetIntMask
/*    33288:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3328c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33290:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33294:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33298:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3329c:	3c0f8006 */ 	lui	$t7,%hi(var8005f128)
/*    332a0:	8deff128 */ 	lw	$t7,%lo(var8005f128)($t7)
/*    332a4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    332a8:	3c188006 */ 	lui	$t8,%hi(var8005f124)
/*    332ac:	8f18f124 */ 	lw	$t8,%lo(var8005f124)($t8)
/*    332b0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    332b4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    332b8:	a7a0002a */ 	sh	$zero,0x2a($sp)
/*    332bc:	13200008 */ 	beqz	$t9,.L000332e0
/*    332c0:	00000000 */ 	nop
.L000332c4:
/*    332c4:	97a8002a */ 	lhu	$t0,0x2a($sp)
/*    332c8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    332cc:	25090001 */ 	addiu	$t1,$t0,0x1
/*    332d0:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*    332d4:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    332d8:	1560fffa */ 	bnez	$t3,.L000332c4
/*    332dc:	afab0020 */ 	sw	$t3,0x20($sp)
.L000332e0:
/*    332e0:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    332e4:	a7a00028 */ 	sh	$zero,0x28($sp)
/*    332e8:	11800008 */ 	beqz	$t4,.L0003330c
/*    332ec:	00000000 */ 	nop
.L000332f0:
/*    332f0:	97ad0028 */ 	lhu	$t5,0x28($sp)
/*    332f4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    332f8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    332fc:	a7ae0028 */ 	sh	$t6,0x28($sp)
/*    33300:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33304:	1700fffa */ 	bnez	$t8,.L000332f0
/*    33308:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0003330c:
/*    3330c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33310:	a7a00026 */ 	sh	$zero,0x26($sp)
/*    33314:	13200008 */ 	beqz	$t9,.L00033338
/*    33318:	00000000 */ 	nop
.L0003331c:
/*    3331c:	97a80026 */ 	lhu	$t0,0x26($sp)
/*    33320:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33324:	25090001 */ 	addiu	$t1,$t0,0x1
/*    33328:	a7a90026 */ 	sh	$t1,0x26($sp)
/*    3332c:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    33330:	1560fffa */ 	bnez	$t3,.L0003331c
/*    33334:	afab0018 */ 	sw	$t3,0x18($sp)
.L00033338:
/*    33338:	97ac0028 */ 	lhu	$t4,0x28($sp)
/*    3333c:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    33340:	a5ac0000 */ 	sh	$t4,0x0($t5)
/*    33344:	97ae002a */ 	lhu	$t6,0x2a($sp)
/*    33348:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3334c:	a5ee0000 */ 	sh	$t6,0x0($t7)
/*    33350:	0c012194 */ 	jal	osSetIntMask
/*    33354:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33358:	10000003 */ 	b	.L00033368
/*    3335c:	97a20026 */ 	lhu	$v0,0x26($sp)
/*    33360:	10000001 */ 	b	.L00033368
/*    33364:	00000000 */ 	nop
.L00033368:
/*    33368:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3336c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33370:	03e00008 */ 	jr	$ra
/*    33374:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033378
/*    33378:	3c018006 */ 	lui	$at,%hi(var8005f13c)
/*    3337c:	ac24f13c */ 	sw	$a0,%lo(var8005f13c)($at)
/*    33380:	03e00008 */ 	jr	$ra
/*    33384:	00000000 */ 	nop
/*    33388:	03e00008 */ 	jr	$ra
/*    3338c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033390
/*    33390:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33394:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33398:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3339c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    333a0:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    333a4:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    333a8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    333ac:	3c188006 */ 	lui	$t8,%hi(var8005f134)
/*    333b0:	8f18f134 */ 	lw	$t8,%lo(var8005f134)($t8)
/*    333b4:	3c088006 */ 	lui	$t0,%hi(var8005f138)
/*    333b8:	8d08f138 */ 	lw	$t0,%lo(var8005f138)($t0)
/*    333bc:	3c018006 */ 	lui	$at,%hi(var8005f134)
/*    333c0:	27190001 */ 	addiu	$t9,$t8,0x1
/*    333c4:	ac39f134 */ 	sw	$t9,%lo(var8005f134)($at)
/*    333c8:	0119082a */ 	slt	$at,$t0,$t9
/*    333cc:	1020000a */ 	beqz	$at,.L000333f8
/*    333d0:	00000000 */ 	nop
/*    333d4:	3c098006 */ 	lui	$t1,%hi(var8005f134)
/*    333d8:	8d29f134 */ 	lw	$t1,%lo(var8005f134)($t1)
/*    333dc:	3c018006 */ 	lui	$at,%hi(var8005f138)
/*    333e0:	ac29f138 */ 	sw	$t1,%lo(var8005f138)($at)
/*    333e4:	3c0a8006 */ 	lui	$t2,%hi(var8005f134)
/*    333e8:	8d4af134 */ 	lw	$t2,%lo(var8005f134)($t2)
/*    333ec:	29410011 */ 	slti	$at,$t2,0x11
/*    333f0:	14200001 */ 	bnez	$at,.L000333f8
/*    333f4:	00000000 */ 	nop
.L000333f8:
/*    333f8:	0c012194 */ 	jal	osSetIntMask
/*    333fc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33400:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    33404:	3c0b8006 */ 	lui	$t3,%hi(var8005f128)
/*    33408:	8d6bf128 */ 	lw	$t3,%lo(var8005f128)($t3)
/*    3340c:	afab0024 */ 	sw	$t3,0x24($sp)
/*    33410:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33414:	1180007d */ 	beqz	$t4,.L0003360c
/*    33418:	00000000 */ 	nop
/*    3341c:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33420:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    33424:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    33428:	ac2ef128 */ 	sw	$t6,%lo(var8005f128)($at)
/*    3342c:	0c00c5e9 */ 	jal	alUnlink
/*    33430:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    33434:	3c0f8006 */ 	lui	$t7,%hi(var8005f120)
/*    33438:	8deff120 */ 	lw	$t7,%lo(var8005f120)($t7)
/*    3343c:	11e0000f */ 	beqz	$t7,.L0003347c
/*    33440:	00000000 */ 	nop
/*    33444:	3c188006 */ 	lui	$t8,%hi(var8005f120)
/*    33448:	8f18f120 */ 	lw	$t8,%lo(var8005f120)($t8)
/*    3344c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    33450:	af380000 */ 	sw	$t8,0x0($t9)
/*    33454:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    33458:	ad000004 */ 	sw	$zero,0x4($t0)
/*    3345c:	3c0a8006 */ 	lui	$t2,%hi(var8005f120)
/*    33460:	8d4af120 */ 	lw	$t2,%lo(var8005f120)($t2)
/*    33464:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    33468:	ad490004 */ 	sw	$t1,0x4($t2)
/*    3346c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    33470:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33474:	1000000c */ 	b	.L000334a8
/*    33478:	ac2bf120 */ 	sw	$t3,%lo(var8005f120)($at)
.L0003347c:
/*    3347c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33480:	ad800004 */ 	sw	$zero,0x4($t4)
/*    33484:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33488:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3348c:	adae0000 */ 	sw	$t6,0x0($t5)
/*    33490:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33494:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33498:	ac2ff120 */ 	sw	$t7,%lo(var8005f120)($at)
/*    3349c:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    334a0:	3c018006 */ 	lui	$at,%hi(var8005f124)
/*    334a4:	ac38f124 */ 	sw	$t8,%lo(var8005f124)($at)
.L000334a8:
/*    334a8:	0c012194 */ 	jal	osSetIntMask
/*    334ac:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    334b0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    334b4:	8f280000 */ 	lw	$t0,0x0($t9)
/*    334b8:	8d090004 */ 	lw	$t1,0x4($t0)
/*    334bc:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    334c0:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*    334c4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    334c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    334cc:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    334d0:	ad8b0008 */ 	sw	$t3,0x8($t4)
/*    334d4:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    334d8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    334dc:	25cd0040 */ 	addiu	$t5,$t6,0x40
/*    334e0:	a1ed0040 */ 	sb	$t5,0x40($t7)
/*    334e4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    334e8:	24180005 */ 	addiu	$t8,$zero,0x5
/*    334ec:	a3380045 */ 	sb	$t8,0x45($t9)
/*    334f0:	3c013f80 */ 	lui	$at,0x3f80
/*    334f4:	44812000 */ 	mtc1	$at,$f4
/*    334f8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    334fc:	e504002c */ 	swc1	$f4,0x2c($t0)
/*    33500:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33504:	24090002 */ 	addiu	$t1,$zero,0x2
/*    33508:	ad490034 */ 	sw	$t1,0x34($t2)
/*    3350c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33510:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33514:	916c0003 */ 	lbu	$t4,0x3($t3)
/*    33518:	318e00f0 */ 	andi	$t6,$t4,0xf0
/*    3351c:	a1ae0044 */ 	sb	$t6,0x44($t5)
/*    33520:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33524:	ade00030 */ 	sw	$zero,0x30($t7)
/*    33528:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3352c:	93190044 */ 	lbu	$t9,0x44($t8)
/*    33530:	33280020 */ 	andi	$t0,$t9,0x20
/*    33534:	1100000e */ 	beqz	$t0,.L00033570
/*    33538:	00000000 */ 	nop
/*    3353c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    33540:	91240004 */ 	lbu	$a0,0x4($t1)
/*    33544:	00800821 */ 	addu	$at,$a0,$zero
/*    33548:	00012080 */ 	sll	$a0,$at,0x2
/*    3354c:	00812023 */ 	subu	$a0,$a0,$at
/*    33550:	000420c0 */ 	sll	$a0,$a0,0x3
/*    33554:	00812021 */ 	addu	$a0,$a0,$at
/*    33558:	00042080 */ 	sll	$a0,$a0,0x2
/*    3355c:	0c00e7f8 */ 	jal	func00039fe0
/*    33560:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    33564:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33568:	1000000e */ 	b	.L000335a4
/*    3356c:	e5400028 */ 	swc1	$f0,0x28($t2)
.L00033570:
/*    33570:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33574:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    33578:	816d0005 */ 	lb	$t5,0x5($t3)
/*    3357c:	000c7080 */ 	sll	$t6,$t4,0x2
/*    33580:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    33584:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    33588:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    3358c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    33590:	01cd2021 */ 	addu	$a0,$t6,$t5
/*    33594:	0c00e7f8 */ 	jal	func00039fe0
/*    33598:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    3359c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    335a0:	e5e00028 */ 	swc1	$f0,0x28($t7)
.L000335a4:
/*    335a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    335a8:	13000005 */ 	beqz	$t8,.L000335c0
/*    335ac:	00000000 */ 	nop
/*    335b0:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    335b4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    335b8:	35090002 */ 	ori	$t1,$t0,0x2
/*    335bc:	a3290044 */ 	sb	$t1,0x44($t9)
.L000335c0:
/*    335c0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    335c4:	a1400042 */ 	sb	$zero,0x42($t2)
/*    335c8:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    335cc:	240c0040 */ 	addiu	$t4,$zero,0x40
/*    335d0:	a16c0041 */ 	sb	$t4,0x41($t3)
/*    335d4:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    335d8:	240e7fff */ 	addiu	$t6,$zero,0x7fff
/*    335dc:	a5ae0038 */ 	sh	$t6,0x38($t5)
/*    335e0:	3c0f8006 */ 	lui	$t7,%hi(var8005f13c)
/*    335e4:	8deff13c */ 	lw	$t7,%lo(var8005f13c)($t7)
/*    335e8:	11e00006 */ 	beqz	$t7,.L00033604
/*    335ec:	00000000 */ 	nop
/*    335f0:	3c198006 */ 	lui	$t9,%hi(var8005f13c)
/*    335f4:	8f39f13c */ 	lw	$t9,%lo(var8005f13c)($t9)
/*    335f8:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    335fc:	0320f809 */ 	jalr	$t9
/*    33600:	8f040008 */ 	lw	$a0,0x8($t8)
.L00033604:
/*    33604:	10000003 */ 	b	.L00033614
/*    33608:	00000000 */ 	nop
.L0003360c:
/*    3360c:	0c012194 */ 	jal	osSetIntMask
/*    33610:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L00033614:
/*    33614:	10000003 */ 	b	.L00033624
/*    33618:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3361c:	10000001 */ 	b	.L00033624
/*    33620:	00000000 */ 	nop
.L00033624:
/*    33624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33628:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3362c:	03e00008 */ 	jr	$ra
/*    33630:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033634
/*    33634:	3c018006 */ 	lui	$at,%hi(var8005f140)
/*    33638:	ac24f140 */ 	sw	$a0,%lo(var8005f140)($at)
/*    3363c:	03e00008 */ 	jr	$ra
/*    33640:	00000000 */ 	nop
/*    33644:	03e00008 */ 	jr	$ra
/*    33648:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003364c
/*    3364c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33650:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33654:	afa40018 */ 	sw	$a0,0x18($sp)
/*    33658:	3c0e8006 */ 	lui	$t6,%hi(var8005f134)
/*    3365c:	8dcef134 */ 	lw	$t6,%lo(var8005f134)($t6)
/*    33660:	3c018006 */ 	lui	$at,%hi(var8005f134)
/*    33664:	25cfffff */ 	addiu	$t7,$t6,-1
/*    33668:	ac2ff134 */ 	sw	$t7,%lo(var8005f134)($at)
/*    3366c:	3c188006 */ 	lui	$t8,%hi(var8005f120)
/*    33670:	8f18f120 */ 	lw	$t8,%lo(var8005f120)($t8)
/*    33674:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33678:	17190005 */ 	bne	$t8,$t9,.L00033690
/*    3367c:	00000000 */ 	nop
/*    33680:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33684:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33688:	8d090000 */ 	lw	$t1,0x0($t0)
/*    3368c:	ac29f120 */ 	sw	$t1,%lo(var8005f120)($at)
.L00033690:
/*    33690:	3c0a8006 */ 	lui	$t2,%hi(var8005f124)
/*    33694:	8d4af124 */ 	lw	$t2,%lo(var8005f124)($t2)
/*    33698:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    3369c:	154b0005 */ 	bne	$t2,$t3,.L000336b4
/*    336a0:	00000000 */ 	nop
/*    336a4:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    336a8:	3c018006 */ 	lui	$at,%hi(var8005f124)
/*    336ac:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    336b0:	ac2df124 */ 	sw	$t5,%lo(var8005f124)($at)
.L000336b4:
/*    336b4:	0c00c5e9 */ 	jal	alUnlink
/*    336b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    336bc:	3c0e8006 */ 	lui	$t6,%hi(var8005f128)
/*    336c0:	8dcef128 */ 	lw	$t6,%lo(var8005f128)($t6)
/*    336c4:	11c0000f */ 	beqz	$t6,.L00033704
/*    336c8:	00000000 */ 	nop
/*    336cc:	3c0f8006 */ 	lui	$t7,%hi(var8005f128)
/*    336d0:	8deff128 */ 	lw	$t7,%lo(var8005f128)($t7)
/*    336d4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    336d8:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    336dc:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    336e0:	af200004 */ 	sw	$zero,0x4($t9)
/*    336e4:	3c098006 */ 	lui	$t1,%hi(var8005f128)
/*    336e8:	8d29f128 */ 	lw	$t1,%lo(var8005f128)($t1)
/*    336ec:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    336f0:	ad280004 */ 	sw	$t0,0x4($t1)
/*    336f4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    336f8:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    336fc:	10000009 */ 	b	.L00033724
/*    33700:	ac2af128 */ 	sw	$t2,%lo(var8005f128)($at)
.L00033704:
/*    33704:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33708:	ad600004 */ 	sw	$zero,0x4($t3)
/*    3370c:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33710:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33714:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*    33718:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    3371c:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    33720:	ac2ef128 */ 	sw	$t6,%lo(var8005f128)($at)
.L00033724:
/*    33724:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33728:	91f80044 */ 	lbu	$t8,0x44($t7)
/*    3372c:	33190004 */ 	andi	$t9,$t8,0x4
/*    33730:	13200006 */ 	beqz	$t9,.L0003374c
/*    33734:	00000000 */ 	nop
/*    33738:	3c088006 */ 	lui	$t0,%hi(var8005f130)
/*    3373c:	8508f130 */ 	lh	$t0,%lo(var8005f130)($t0)
/*    33740:	3c018006 */ 	lui	$at,%hi(var8005f130)
/*    33744:	2509ffff */ 	addiu	$t1,$t0,-1
/*    33748:	a429f130 */ 	sh	$t1,%lo(var8005f130)($at)
.L0003374c:
/*    3374c:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33750:	a1400045 */ 	sb	$zero,0x45($t2)
/*    33754:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33758:	8d6d0030 */ 	lw	$t5,0x30($t3)
/*    3375c:	11a0000b */ 	beqz	$t5,.L0003378c
/*    33760:	00000000 */ 	nop
/*    33764:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33768:	8d8e0030 */ 	lw	$t6,0x30($t4)
/*    3376c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    33770:	15ec0004 */ 	bne	$t7,$t4,.L00033784
/*    33774:	00000000 */ 	nop
/*    33778:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    3377c:	8f190030 */ 	lw	$t9,0x30($t8)
/*    33780:	af200000 */ 	sw	$zero,0x0($t9)
.L00033784:
/*    33784:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33788:	ad000030 */ 	sw	$zero,0x30($t0)
.L0003378c:
/*    3378c:	3c098006 */ 	lui	$t1,%hi(var8005f140)
/*    33790:	8d29f140 */ 	lw	$t1,%lo(var8005f140)($t1)
/*    33794:	11200006 */ 	beqz	$t1,.L000337b0
/*    33798:	00000000 */ 	nop
/*    3379c:	3c198006 */ 	lui	$t9,%hi(var8005f140)
/*    337a0:	8f39f140 */ 	lw	$t9,%lo(var8005f140)($t9)
/*    337a4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    337a8:	0320f809 */ 	jalr	$t9
/*    337ac:	8d440008 */ 	lw	$a0,0x8($t2)
.L000337b0:
/*    337b0:	10000001 */ 	b	.L000337b8
/*    337b4:	00000000 */ 	nop
.L000337b8:
/*    337b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    337bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    337c0:	03e00008 */ 	jr	$ra
/*    337c4:	00000000 */ 	nop
/*    337c8:	30a500ff */ 	andi	$a1,$a1,0xff
/*    337cc:	10800004 */ 	beqz	$a0,.L000337e0
/*    337d0:	00000000 */ 	nop
/*    337d4:	00057400 */ 	sll	$t6,$a1,0x10
/*    337d8:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    337dc:	a08f0040 */ 	sb	$t7,0x40($a0)
.L000337e0:
/*    337e0:	03e00008 */ 	jr	$ra
/*    337e4:	00000000 */ 	nop
/*    337e8:	03e00008 */ 	jr	$ra
/*    337ec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000337f0
/*    337f0:	10800005 */ 	beqz	$a0,.L00033808
/*    337f4:	00000000 */ 	nop
/*    337f8:	03e00008 */ 	jr	$ra
/*    337fc:	90820045 */ 	lbu	$v0,0x45($a0)
/*    33800:	10000003 */ 	b	.L00033810
/*    33804:	00000000 */ 	nop
.L00033808:
/*    33808:	03e00008 */ 	jr	$ra
/*    3380c:	00001025 */ 	or	$v0,$zero,$zero
.L00033810:
/*    33810:	03e00008 */ 	jr	$ra
/*    33814:	00000000 */ 	nop
/*    33818:	03e00008 */ 	jr	$ra
/*    3381c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033820
/*    33820:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    33824:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33828:	afa40060 */ 	sw	$a0,0x60($sp)
/*    3382c:	afa50064 */ 	sw	$a1,0x64($sp)
/*    33830:	afa60068 */ 	sw	$a2,0x68($sp)
/*    33834:	afa7006c */ 	sw	$a3,0x6c($sp)
/*    33838:	afa00058 */ 	sw	$zero,0x58($sp)
/*    3383c:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    33840:	afa00040 */ 	sw	$zero,0x40($sp)
/*    33844:	0c0040d8 */ 	jal	func00010360
/*    33848:	00000000 */ 	nop
/*    3384c:	10400003 */ 	beqz	$v0,.L0003385c
/*    33850:	00000000 */ 	nop
/*    33854:	100000af */ 	b	.L00033b14
/*    33858:	00001025 */ 	or	$v0,$zero,$zero
.L0003385c:
/*    3385c:	87ae0066 */ 	lh	$t6,0x66($sp)
/*    33860:	11c000a2 */ 	beqz	$t6,.L00033aec
/*    33864:	00000000 */ 	nop
.L00033868:
/*    33868:	0c003d27 */ 	jal	func0000f49c
/*    3386c:	87a40066 */ 	lh	$a0,0x66($sp)
/*    33870:	afa20050 */ 	sw	$v0,0x50($sp)
/*    33874:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    33878:	0c00cce4 */ 	jal	func00033390
/*    3387c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    33880:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    33884:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33888:	11e00064 */ 	beqz	$t7,.L00033a1c
/*    3388c:	00000000 */ 	nop
/*    33890:	3c198006 */ 	lui	$t9,%hi(var8005f12c)
/*    33894:	8f39f12c */ 	lw	$t9,%lo(var8005f12c)($t9)
/*    33898:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3389c:	af38003c */ 	sw	$t8,0x3c($t9)
/*    338a0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    338a4:	a7a8002c */ 	sh	$t0,0x2c($sp)
/*    338a8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338ac:	afa90030 */ 	sw	$t1,0x30($sp)
/*    338b0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    338b4:	93aa006f */ 	lbu	$t2,0x6f($sp)
/*    338b8:	916c0041 */ 	lbu	$t4,0x41($t3)
/*    338bc:	014c6821 */ 	addu	$t5,$t2,$t4
/*    338c0:	25aeffc0 */ 	addiu	$t6,$t5,-64
/*    338c4:	afae003c */ 	sw	$t6,0x3c($sp)
/*    338c8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    338cc:	29e10080 */ 	slti	$at,$t7,0x80
/*    338d0:	14200004 */ 	bnez	$at,.L000338e4
/*    338d4:	00000000 */ 	nop
/*    338d8:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    338dc:	10000005 */ 	b	.L000338f4
/*    338e0:	afb8003c */ 	sw	$t8,0x3c($sp)
.L000338e4:
/*    338e4:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    338e8:	07210002 */ 	bgez	$t9,.L000338f4
/*    338ec:	00000000 */ 	nop
/*    338f0:	afa0003c */ 	sw	$zero,0x3c($sp)
.L000338f4:
/*    338f4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    338f8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338fc:	a1280041 */ 	sb	$t0,0x41($t1)
/*    33900:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    33904:	97ab006a */ 	lhu	$t3,0x6a($sp)
/*    33908:	854c0038 */ 	lh	$t4,0x38($t2)
/*    3390c:	016c0019 */ 	multu	$t3,$t4
/*    33910:	00006812 */ 	mflo	$t5
/*    33914:	000d73c2 */ 	srl	$t6,$t5,0xf
/*    33918:	a54e0038 */ 	sh	$t6,0x38($t2)
/*    3391c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33920:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    33924:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    33928:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    3392c:	e5e8002c */ 	swc1	$f8,0x2c($t7)
/*    33930:	93b80077 */ 	lbu	$t8,0x77($sp)
/*    33934:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33938:	a3380042 */ 	sb	$t8,0x42($t9)
/*    3393c:	93a8007b */ 	lbu	$t0,0x7b($sp)
/*    33940:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33944:	a1280043 */ 	sb	$t0,0x43($t1)
/*    33948:	87ab0066 */ 	lh	$t3,0x66($sp)
/*    3394c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    33950:	a58b0046 */ 	sh	$t3,0x46($t4)
/*    33954:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    33958:	ada00048 */ 	sw	$zero,0x48($t5)
/*    3395c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    33960:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    33964:	914f0001 */ 	lbu	$t7,0x1($t2)
/*    33968:	000fc180 */ 	sll	$t8,$t7,0x6
/*    3396c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33970:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    33974:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33978:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3397c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    33980:	0018c080 */ 	sll	$t8,$t8,0x2
/*    33984:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33988:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3398c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33990:	afb80044 */ 	sw	$t8,0x44($sp)
/*    33994:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33998:	93280044 */ 	lbu	$t0,0x44($t9)
/*    3399c:	31090010 */ 	andi	$t1,$t0,0x10
/*    339a0:	11200014 */ 	beqz	$t1,.L000339f4
/*    339a4:	00000000 */ 	nop
/*    339a8:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    339ac:	2401ffef */ 	addiu	$at,$zero,-17
/*    339b0:	916c0044 */ 	lbu	$t4,0x44($t3)
/*    339b4:	01816824 */ 	and	$t5,$t4,$at
/*    339b8:	a16d0044 */ 	sb	$t5,0x44($t3)
/*    339bc:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    339c0:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    339c4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    339c8:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    339cc:	00003825 */ 	or	$a3,$zero,$zero
/*    339d0:	24840014 */ 	addiu	$a0,$a0,20
/*    339d4:	0c00f184 */ 	jal	alEvtqPostEvent
/*    339d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    339dc:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    339e0:	25ca0001 */ 	addiu	$t2,$t6,0x1
/*    339e4:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    339e8:	87af0066 */ 	lh	$t7,0x66($sp)
/*    339ec:	10000009 */ 	b	.L00033a14
/*    339f0:	a7af004e */ 	sh	$t7,0x4e($sp)
.L000339f4:
/*    339f4:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    339f8:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    339fc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    33a00:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    33a04:	00003825 */ 	or	$a3,$zero,$zero
/*    33a08:	24840014 */ 	addiu	$a0,$a0,20
/*    33a0c:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33a10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L00033a14:
/*    33a14:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    33a18:	afb80058 */ 	sw	$t8,0x58($sp)
.L00033a1c:
/*    33a1c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    33a20:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    33a24:	03284821 */ 	addu	$t1,$t9,$t0
/*    33a28:	afa90040 */ 	sw	$t1,0x40($sp)
/*    33a2c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    33a30:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33a34:	afad0054 */ 	sw	$t5,0x54($sp)
/*    33a38:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    33a3c:	916a0002 */ 	lbu	$t2,0x2($t3)
/*    33a40:	916e0000 */ 	lbu	$t6,0x0($t3)
/*    33a44:	314f00c0 */ 	andi	$t7,$t2,0xc0
/*    33a48:	000fc080 */ 	sll	$t8,$t7,0x2
/*    33a4c:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    33a50:	a7b90066 */ 	sh	$t9,0x66($sp)
/*    33a54:	87a80066 */ 	lh	$t0,0x66($sp)
/*    33a58:	11000004 */ 	beqz	$t0,.L00033a6c
/*    33a5c:	00000000 */ 	nop
/*    33a60:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33a64:	1520ff80 */ 	bnez	$t1,.L00033868
/*    33a68:	00000000 */ 	nop
.L00033a6c:
/*    33a6c:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    33a70:	1180001e */ 	beqz	$t4,.L00033aec
/*    33a74:	00000000 */ 	nop
/*    33a78:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    33a7c:	91ab0044 */ 	lbu	$t3,0x44($t5)
/*    33a80:	356a0001 */ 	ori	$t2,$t3,0x1
/*    33a84:	a1aa0044 */ 	sb	$t2,0x44($t5)
/*    33a88:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33a8c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33a90:	adcf0030 */ 	sw	$t7,0x30($t6)
/*    33a94:	87b8004e */ 	lh	$t8,0x4e($sp)
/*    33a98:	13000014 */ 	beqz	$t8,.L00033aec
/*    33a9c:	00000000 */ 	nop
/*    33aa0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    33aa4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33aa8:	35090010 */ 	ori	$t1,$t0,0x10
/*    33aac:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33ab0:	240c0200 */ 	addiu	$t4,$zero,0x200
/*    33ab4:	a7ac001c */ 	sh	$t4,0x1c($sp)
/*    33ab8:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    33abc:	afab0020 */ 	sw	$t3,0x20($sp)
/*    33ac0:	87aa004e */ 	lh	$t2,0x4e($sp)
/*    33ac4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    33ac8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    33acc:	afad0028 */ 	sw	$t5,0x28($sp)
/*    33ad0:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33ad4:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33ad8:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33adc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    33ae0:	00003825 */ 	or	$a3,$zero,$zero
/*    33ae4:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33ae8:	24840014 */ 	addiu	$a0,$a0,20
.L00033aec:
/*    33aec:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33af0:	11e00004 */ 	beqz	$t7,.L00033b04
/*    33af4:	00000000 */ 	nop
/*    33af8:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33afc:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*    33b00:	af0e0000 */ 	sw	$t6,0x0($t8)
.L00033b04:
/*    33b04:	10000003 */ 	b	.L00033b14
/*    33b08:	8fa20058 */ 	lw	$v0,0x58($sp)
/*    33b0c:	10000001 */ 	b	.L00033b14
/*    33b10:	00000000 */ 	nop
.L00033b14:
/*    33b14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33b18:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    33b1c:	03e00008 */ 	jr	$ra
/*    33b20:	00000000 */ 	nop
);

#if VERSION >= VERSION_NTSC_FINAL
GLOBAL_ASM(
glabel audioStop
/*    33b24:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33b28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33b2c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33b30:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    33b34:	11c00009 */ 	beqz	$t6,.L00033b5c
/*    33b38:	00000000 */ 	nop
/*    33b3c:	91cf0044 */ 	lbu	$t7,0x44($t6)
/*    33b40:	31f80002 */ 	andi	$t8,$t7,0x2
/*    33b44:	13000005 */ 	beqz	$t8,.L00033b5c
/*    33b48:	00000000 */ 	nop
/*    33b4c:	0c00cef0 */ 	jal	func00033bc0
/*    33b50:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    33b54:	10000014 */ 	b	.L00033ba8
/*    33b58:	00000000 */ 	nop
.L00033b5c:
/*    33b5c:	24190400 */ 	addiu	$t9,$zero,0x400
/*    33b60:	a7b90018 */ 	sh	$t9,0x18($sp)
/*    33b64:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    33b68:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    33b6c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    33b70:	1120000d */ 	beqz	$t1,.L00033ba8
/*    33b74:	00000000 */ 	nop
/*    33b78:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    33b7c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33b80:	914b0044 */ 	lbu	$t3,0x44($t2)
/*    33b84:	01616024 */ 	and	$t4,$t3,$at
/*    33b88:	a14c0044 */ 	sb	$t4,0x44($t2)
/*    33b8c:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33b90:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33b94:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33b98:	00003025 */ 	or	$a2,$zero,$zero
/*    33b9c:	00003825 */ 	or	$a3,$zero,$zero
/*    33ba0:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33ba4:	24840014 */ 	addiu	$a0,$a0,20
.L00033ba8:
/*    33ba8:	10000001 */ 	b	.L00033bb0
/*    33bac:	00000000 */ 	nop
.L00033bb0:
/*    33bb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33bb4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33bb8:	03e00008 */ 	jr	$ra
/*    33bbc:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel audioStop
/*    33b24:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33b28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33b2c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33b30:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    33b34:	91cf0044 */ 	lbu	$t7,0x44($t6)
/*    33b38:	31f80002 */ 	andi	$t8,$t7,0x2
/*    33b3c:	13000005 */ 	beqz	$t8,.L00033b54
/*    33b40:	00000000 */ 	nop
/*    33b44:	0c00ceee */ 	jal	0x33bb8
/*    33b48:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    33b4c:	10000014 */ 	b	.L00033ba0
/*    33b50:	00000000 */ 	nop
.L00033b54:
/*    33b54:	24190400 */ 	addiu	$t9,$zero,0x400
/*    33b58:	a7b90018 */ 	sh	$t9,0x18($sp)
/*    33b5c:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    33b60:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    33b64:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    33b68:	1120000d */ 	beqz	$t1,.L00033ba0
/*    33b6c:	00000000 */ 	nop
/*    33b70:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    33b74:	2401ffef */ 	addiu	$at,$zero,-17
/*    33b78:	914b0044 */ 	lbu	$t3,0x44($t2)
/*    33b7c:	01616024 */ 	and	$t4,$t3,$at
/*    33b80:	a14c0044 */ 	sb	$t4,0x44($t2)
/*    33b84:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33b88:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33b8c:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33b90:	00003025 */ 	or	$a2,$zero,$zero
/*    33b94:	00003825 */ 	or	$a3,$zero,$zero
/*    33b98:	0c00f184 */ 	jal	0x3c610
/*    33b9c:	24840014 */ 	addiu	$a0,$a0,0x14
.L00033ba0:
/*    33ba0:	10000001 */ 	b	.L00033ba8
/*    33ba4:	00000000 */ 	nop
.L00033ba8:
/*    33ba8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33bac:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33bb0:	03e00008 */ 	jr	$ra
/*    33bb4:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func00033bc0
/*    33bc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33bc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33bc8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33bcc:	240e0080 */ 	addiu	$t6,$zero,0x80
/*    33bd0:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    33bd4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    33bd8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    33bdc:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    33be0:	1300000d */ 	beqz	$t8,.L00033c18
/*    33be4:	00000000 */ 	nop
/*    33be8:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    33bec:	2401ffef */ 	addiu	$at,$zero,-17
/*    33bf0:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33bf4:	01014824 */ 	and	$t1,$t0,$at
/*    33bf8:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33bfc:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33c00:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33c04:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33c08:	00003025 */ 	or	$a2,$zero,$zero
/*    33c0c:	00003825 */ 	or	$a3,$zero,$zero
/*    33c10:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33c14:	24840014 */ 	addiu	$a0,$a0,20
.L00033c18:
/*    33c18:	10000001 */ 	b	.L00033c20
/*    33c1c:	00000000 */ 	nop
.L00033c20:
/*    33c20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33c24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33c28:	03e00008 */ 	jr	$ra
/*    33c2c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033c30
/*    33c30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33c34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33c38:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33c3c:	0c012194 */ 	jal	osSetIntMask
/*    33c40:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33c44:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33c48:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33c4c:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33c50:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33c54:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33c58:	11e0001d */ 	beqz	$t7,.L00033cd0
/*    33c5c:	00000000 */ 	nop
.L00033c60:
/*    33c60:	24180400 */ 	addiu	$t8,$zero,0x400
/*    33c64:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33c68:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33c6c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33c70:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33c74:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33c78:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33c7c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33c80:	156a000d */ 	bne	$t3,$t2,.L00033cb8
/*    33c84:	00000000 */ 	nop
/*    33c88:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33c8c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33c90:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33c94:	01a17024 */ 	and	$t6,$t5,$at
/*    33c98:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33c9c:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33ca0:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33ca4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33ca8:	00003025 */ 	or	$a2,$zero,$zero
/*    33cac:	00003825 */ 	or	$a3,$zero,$zero
/*    33cb0:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33cb4:	24840014 */ 	addiu	$a0,$a0,20
.L00033cb8:
/*    33cb8:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33cbc:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33cc0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33cc4:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33cc8:	1720ffe5 */ 	bnez	$t9,.L00033c60
/*    33ccc:	00000000 */ 	nop
.L00033cd0:
/*    33cd0:	0c012194 */ 	jal	osSetIntMask
/*    33cd4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33cd8:	10000001 */ 	b	.L00033ce0
/*    33cdc:	00000000 */ 	nop
.L00033ce0:
/*    33ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33ce4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33ce8:	03e00008 */ 	jr	$ra
/*    33cec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033cf0
/*    33cf0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33cf8:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33cfc:	0c012194 */ 	jal	osSetIntMask
/*    33d00:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33d04:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33d08:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33d0c:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33d10:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33d14:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d18:	11e0001d */ 	beqz	$t7,.L00033d90
/*    33d1c:	00000000 */ 	nop
.L00033d20:
/*    33d20:	24180080 */ 	addiu	$t8,$zero,0x80
/*    33d24:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33d28:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33d30:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33d34:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33d38:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33d3c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33d40:	156a000d */ 	bne	$t3,$t2,.L00033d78
/*    33d44:	00000000 */ 	nop
/*    33d48:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33d4c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33d50:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33d54:	01a17024 */ 	and	$t6,$t5,$at
/*    33d58:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33d5c:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33d60:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33d64:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33d68:	00003025 */ 	or	$a2,$zero,$zero
/*    33d6c:	00003825 */ 	or	$a3,$zero,$zero
/*    33d70:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33d74:	24840014 */ 	addiu	$a0,$a0,20
.L00033d78:
/*    33d78:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d7c:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33d80:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33d84:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d88:	1720ffe5 */ 	bnez	$t9,.L00033d20
/*    33d8c:	00000000 */ 	nop
.L00033d90:
/*    33d90:	0c012194 */ 	jal	osSetIntMask
/*    33d94:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33d98:	10000001 */ 	b	.L00033da0
/*    33d9c:	00000000 */ 	nop
.L00033da0:
/*    33da0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33da4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33da8:	03e00008 */ 	jr	$ra
/*    33dac:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033db0
/*    33db0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33db4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33db8:	0c00cf3c */ 	jal	func00033cf0
/*    33dbc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33dc0:	10000001 */ 	b	.L00033dc8
/*    33dc4:	00000000 */ 	nop
.L00033dc8:
/*    33dc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33dcc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33dd0:	03e00008 */ 	jr	$ra
/*    33dd4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033dd8
/*    33dd8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33ddc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33de0:	0c00cf0c */ 	jal	func00033c30
/*    33de4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33de8:	10000001 */ 	b	.L00033df0
/*    33dec:	00000000 */ 	nop
.L00033df0:
/*    33df0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33df4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33df8:	03e00008 */ 	jr	$ra
/*    33dfc:	00000000 */ 	nop
/*    33e00:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e08:	0c00cf0c */ 	jal	func00033c30
/*    33e0c:	24040011 */ 	addiu	$a0,$zero,0x11
/*    33e10:	10000001 */ 	b	.L00033e18
/*    33e14:	00000000 */ 	nop
.L00033e18:
/*    33e18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e20:	03e00008 */ 	jr	$ra
/*    33e24:	00000000 */ 	nop
/*    33e28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e30:	0c00cf0c */ 	jal	func00033c30
/*    33e34:	24040003 */ 	addiu	$a0,$zero,0x3
/*    33e38:	10000001 */ 	b	.L00033e40
/*    33e3c:	00000000 */ 	nop
.L00033e40:
/*    33e40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e48:	03e00008 */ 	jr	$ra
/*    33e4c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033e50
/*    33e50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33e54:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e58:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33e5c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    33e60:	afa60030 */ 	sw	$a2,0x30($sp)
/*    33e64:	87ae002e */ 	lh	$t6,0x2e($sp)
/*    33e68:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    33e6c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    33e70:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    33e74:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    33e78:	afb80020 */ 	sw	$t8,0x20($sp)
/*    33e7c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    33e80:	1320000a */ 	beqz	$t9,.L00033eac
/*    33e84:	00000000 */ 	nop
/*    33e88:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33e8c:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33e90:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33e94:	00003025 */ 	or	$a2,$zero,$zero
/*    33e98:	00003825 */ 	or	$a3,$zero,$zero
/*    33e9c:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33ea0:	24840014 */ 	addiu	$a0,$a0,20
/*    33ea4:	10000001 */ 	b	.L00033eac
/*    33ea8:	00000000 */ 	nop
.L00033eac:
/*    33eac:	10000001 */ 	b	.L00033eb4
/*    33eb0:	00000000 */ 	nop
.L00033eb4:
/*    33eb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33eb8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33ebc:	03e00008 */ 	jr	$ra
/*    33ec0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033ec4
/*    33ec4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    33ec8:	308400ff */ 	andi	$a0,$a0,0xff
/*    33ecc:	3c0e800a */ 	lui	$t6,%hi(var8009c334)
/*    33ed0:	8dcec334 */ 	lw	$t6,%lo(var8009c334)($t6)
/*    33ed4:	11c00005 */ 	beqz	$t6,.L00033eec
/*    33ed8:	00000000 */ 	nop
/*    33edc:	00047840 */ 	sll	$t7,$a0,0x1
/*    33ee0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    33ee4:	10000002 */ 	b	.L00033ef0
/*    33ee8:	87050000 */ 	lh	$a1,0x0($t8)
.L00033eec:
/*    33eec:	00002825 */ 	or	$a1,$zero,$zero
.L00033ef0:
/*    33ef0:	10000003 */ 	b	.L00033f00
/*    33ef4:	30a2ffff */ 	andi	$v0,$a1,0xffff
/*    33ef8:	10000001 */ 	b	.L00033f00
/*    33efc:	00000000 */ 	nop
.L00033f00:
/*    33f00:	03e00008 */ 	jr	$ra
/*    33f04:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00033f08
/*    33f08:	3c028006 */ 	lui	$v0,%hi(var8005f120)
/*    33f0c:	03e00008 */ 	jr	$ra
/*    33f10:	8c42f120 */ 	lw	$v0,%lo(var8005f120)($v0)
/*    33f14:	03e00008 */ 	jr	$ra
/*    33f18:	00000000 */ 	nop
/*    33f1c:	03e00008 */ 	jr	$ra
/*    33f20:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033f24
/*    33f24:	3c0e8006 */ 	lui	$t6,%hi(var8005f12c)
/*    33f28:	8dcef12c */ 	lw	$t6,%lo(var8005f12c)($t6)
/*    33f2c:	03e00008 */ 	jr	$ra
/*    33f30:	8dc20050 */ 	lw	$v0,0x50($t6)
/*    33f34:	03e00008 */ 	jr	$ra
/*    33f38:	00000000 */ 	nop
/*    33f3c:	03e00008 */ 	jr	$ra
/*    33f40:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033f44
/*    33f44:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    33f48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33f4c:	afa40038 */ 	sw	$a0,0x38($sp)
/*    33f50:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    33f54:	3c0e800a */ 	lui	$t6,%hi(var8009c334)
/*    33f58:	8dcec334 */ 	lw	$t6,%lo(var8009c334)($t6)
/*    33f5c:	11c0002e */ 	beqz	$t6,.L00034018
/*    33f60:	00000000 */ 	nop
/*    33f64:	0c012194 */ 	jal	osSetIntMask
/*    33f68:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33f6c:	afa20034 */ 	sw	$v0,0x34($sp)
/*    33f70:	3c0f8006 */ 	lui	$t7,%hi(var8005f120)
/*    33f74:	8deff120 */ 	lw	$t7,%lo(var8005f120)($t7)
/*    33f78:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    33f7c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    33f80:	3c19800a */ 	lui	$t9,%hi(var8009c334)
/*    33f84:	8f39c334 */ 	lw	$t9,%lo(var8009c334)($t9)
/*    33f88:	97b8003e */ 	lhu	$t8,0x3e($sp)
/*    33f8c:	00084840 */ 	sll	$t1,$t0,0x1
/*    33f90:	03295021 */ 	addu	$t2,$t9,$t1
/*    33f94:	a5580000 */ 	sh	$t8,0x0($t2)
/*    33f98:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    33f9c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    33fa0:	1160001b */ 	beqz	$t3,.L00034010
/*    33fa4:	00000000 */ 	nop
.L00033fa8:
/*    33fa8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33fac:	93b9003b */ 	lbu	$t9,0x3b($sp)
/*    33fb0:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    33fb4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    33fb8:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    33fbc:	31e8001f */ 	andi	$t0,$t7,0x1f
/*    33fc0:	1519000c */ 	bne	$t0,$t9,.L00033ff4
/*    33fc4:	00000000 */ 	nop
/*    33fc8:	24090800 */ 	addiu	$t1,$zero,0x800
/*    33fcc:	a7a9001c */ 	sh	$t1,0x1c($sp)
/*    33fd0:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    33fd4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    33fd8:	3c048006 */ 	lui	$a0,%hi(var8005f12c)
/*    33fdc:	8c84f12c */ 	lw	$a0,%lo(var8005f12c)($a0)
/*    33fe0:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33fe4:	00003025 */ 	or	$a2,$zero,$zero
/*    33fe8:	00003825 */ 	or	$a3,$zero,$zero
/*    33fec:	0c00f184 */ 	jal	alEvtqPostEvent
/*    33ff0:	24840014 */ 	addiu	$a0,$a0,20
.L00033ff4:
/*    33ff4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    33ff8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33ffc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    34000:	afab002c */ 	sw	$t3,0x2c($sp)
/*    34004:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    34008:	15a0ffe7 */ 	bnez	$t5,.L00033fa8
/*    3400c:	afad0030 */ 	sw	$t5,0x30($sp)
.L00034010:
/*    34010:	0c012194 */ 	jal	osSetIntMask
/*    34014:	8fa40034 */ 	lw	$a0,0x34($sp)
.L00034018:
/*    34018:	10000001 */ 	b	.L00034020
/*    3401c:	00000000 */ 	nop
.L00034020:
/*    34020:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    34024:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    34028:	03e00008 */ 	jr	$ra
/*    3402c:	00000000 */ 	nop
);
