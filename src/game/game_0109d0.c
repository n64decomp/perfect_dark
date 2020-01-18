#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_097a50.h"
#include "game/game_157db0.h"

const u32 var7f1a8230[] = {0x3f666666};
const u32 var7f1a8234[] = {0xc0490fdb};
const u32 var7f1a8238[] = {0x00000000};
const u32 var7f1a823c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f0109d0
/*  f0109d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0109d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0109d8:	0c003a61 */ 	jal	getCurrentStageId
/*  f0109dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0109e0:	2841005a */ 	slti	$at,$v0,0x5a
/*  f0109e4:	1020000a */ 	beqz	$at,.L0f010a10
/*  f0109e8:	240effff */ 	addiu	$t6,$zero,-1
/*  f0109ec:	3c018007 */ 	lui	$at,0x8007
/*  f0109f0:	3c02800a */ 	lui	$v0,%hi(var8009d088)
/*  f0109f4:	3c03800a */ 	lui	$v1,%hi(var8009d0b0)
/*  f0109f8:	ac2eae70 */ 	sw	$t6,-0x5190($at)
/*  f0109fc:	2463d0b0 */ 	addiu	$v1,$v1,%lo(var8009d0b0)
/*  f010a00:	2442d088 */ 	addiu	$v0,$v0,%lo(var8009d088)
.L0f010a04:
/*  f010a04:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010a08:	1443fffe */ 	bne	$v0,$v1,.L0f010a04
/*  f010a0c:	ac40fffc */ 	sw	$zero,-0x4($v0)
.L0f010a10:
/*  f010a10:	3c018007 */ 	lui	$at,0x8007
/*  f010a14:	3c02800a */ 	lui	$v0,%hi(g_Objectives)
/*  f010a18:	3c03800a */ 	lui	$v1,%hi(var8009d088)
/*  f010a1c:	ac20ae74 */ 	sw	$zero,-0x518c($at)
/*  f010a20:	2463d088 */ 	addiu	$v1,$v1,%lo(var8009d088)
/*  f010a24:	2442d060 */ 	addiu	$v0,$v0,%lo(g_Objectives)
.L0f010a28:
/*  f010a28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010a2c:	1443fffe */ 	bne	$v0,$v1,.L0f010a28
/*  f010a30:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f010a34:	3c01800a */ 	lui	$at,0x800a
/*  f010a38:	ac20d0b0 */ 	sw	$zero,-0x2f50($at)
/*  f010a3c:	3c01800a */ 	lui	$at,0x800a
/*  f010a40:	ac20d0b4 */ 	sw	$zero,-0x2f4c($at)
/*  f010a44:	3c01800a */ 	lui	$at,0x800a
/*  f010a48:	ac20d0b8 */ 	sw	$zero,-0x2f48($at)
/*  f010a4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f010a50:	3c01800a */ 	lui	$at,0x800a
/*  f010a54:	ac20d0bc */ 	sw	$zero,-0x2f44($at)
/*  f010a58:	3c01800a */ 	lui	$at,0x800a
/*  f010a5c:	ac20d0c0 */ 	sw	$zero,-0x2f40($at)
/*  f010a60:	03e00008 */ 	jr	$ra
/*  f010a64:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f010a68
/*  f010a68:	3c02800a */ 	lui	$v0,%hi(var8009d0b0)
/*  f010a6c:	2442d0b0 */ 	addiu	$v0,$v0,%lo(var8009d0b0)
/*  f010a70:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010a74:	ac8e0008 */ 	sw	$t6,0x8($a0)
/*  f010a78:	03e00008 */ 	jr	$ra
/*  f010a7c:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010a80
/*  f010a80:	3c02800a */ 	lui	$v0,%hi(var8009d0b4)
/*  f010a84:	2442d0b4 */ 	addiu	$v0,$v0,%lo(var8009d0b4)
/*  f010a88:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010a8c:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f010a90:	03e00008 */ 	jr	$ra
/*  f010a94:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010a98
/*  f010a98:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f010a9c:	3c01800a */ 	lui	$at,0x800a
/*  f010aa0:	3c038007 */ 	lui	$v1,%hi(var8006ae70)
/*  f010aa4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f010aa8:	002f0821 */ 	addu	$at,$at,$t7
/*  f010aac:	ac24d060 */ 	sw	$a0,-0x2fa0($at)
/*  f010ab0:	2463ae70 */ 	addiu	$v1,$v1,%lo(var8006ae70)
/*  f010ab4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f010ab8:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f010abc:	0302082a */ 	slt	$at,$t8,$v0
/*  f010ac0:	10200002 */ 	beqz	$at,.L0f010acc
/*  f010ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f010ac8:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f010acc:
/*  f010acc:	03e00008 */ 	jr	$ra
/*  f010ad0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f010ad4
/*  f010ad4:	3c02800a */ 	lui	$v0,%hi(g_RoomEnteredCriterias)
/*  f010ad8:	2442d0b8 */ 	addiu	$v0,$v0,%lo(g_RoomEnteredCriterias)
/*  f010adc:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010ae0:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f010ae4:	03e00008 */ 	jr	$ra
/*  f010ae8:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010aec
/*  f010aec:	3c02800a */ 	lui	$v0,%hi(g_MultiroomEnteredCriterias)
/*  f010af0:	2442d0bc */ 	addiu	$v0,$v0,%lo(g_MultiroomEnteredCriterias)
/*  f010af4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010af8:	ac8e0010 */ 	sw	$t6,0x10($a0)
/*  f010afc:	03e00008 */ 	jr	$ra
/*  f010b00:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010b04
/*  f010b04:	3c02800a */ 	lui	$v0,%hi(var8009d0c0)
/*  f010b08:	2442d0c0 */ 	addiu	$v0,$v0,%lo(var8009d0c0)
/*  f010b0c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010b10:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f010b14:	03e00008 */ 	jr	$ra
/*  f010b18:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f010b1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f010b20
/*  f010b20:	3c04800a */ 	lui	$a0,%hi(var8009d0d0)
/*  f010b24:	2484d0d0 */ 	addiu	$a0,$a0,%lo(var8009d0d0)
/*  f010b28:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f010b2c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f010b30:	3c01800a */ 	lui	$at,0x800a
/*  f010b34:	3c03800a */ 	lui	$v1,%hi(var8009d0e0)
/*  f010b38:	3c02800a */ 	lui	$v0,%hi(var8009d0f0)
/*  f010b3c:	ac20d0d8 */ 	sw	$zero,-0x2f28($at)
/*  f010b40:	2442d0f0 */ 	addiu	$v0,$v0,%lo(var8009d0f0)
/*  f010b44:	2463d0e0 */ 	addiu	$v1,$v1,%lo(var8009d0e0)
.L0f010b48:
/*  f010b48:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f010b4c:	1462fffe */ 	bne	$v1,$v0,.L0f010b48
/*  f010b50:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b54:	3c02800a */ 	lui	$v0,%hi(var8009da60)
/*  f010b58:	3c03800a */ 	lui	$v1,%hi(var8009d510)
/*  f010b5c:	2442da60 */ 	addiu	$v0,$v0,%lo(var8009da60)
/*  f010b60:	2463d510 */ 	addiu	$v1,$v1,%lo(var8009d510)
.L0f010b64:
/*  f010b64:	24630044 */ 	addiu	$v1,$v1,0x44
/*  f010b68:	0062082b */ 	sltu	$at,$v1,$v0
/*  f010b6c:	1420fffd */ 	bnez	$at,.L0f010b64
/*  f010b70:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b74:	3c018007 */ 	lui	$at,0x8007
/*  f010b78:	3c03800a */ 	lui	$v1,%hi(g_Fireslots)
/*  f010b7c:	3c04800a */ 	lui	$a0,%hi(var8009d510)
/*  f010b80:	ac200524 */ 	sw	$zero,0x524($at)
/*  f010b84:	2484d510 */ 	addiu	$a0,$a0,%lo(var8009d510)
/*  f010b88:	2463d150 */ 	addiu	$v1,$v1,%lo(g_Fireslots)
/*  f010b8c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f010b90:
/*  f010b90:	24630030 */ 	addiu	$v1,$v1,0x30
/*  f010b94:	1464fffe */ 	bne	$v1,$a0,.L0f010b90
/*  f010b98:	ac62ffd0 */ 	sw	$v0,-0x30($v1)
/*  f010b9c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f010ba0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f010ba4:	ac4002b0 */ 	sw	$zero,0x2b0($v0)
/*  f010ba8:	03e00008 */ 	jr	$ra
/*  f010bac:	ac4002b4 */ 	sw	$zero,0x2b4($v0)
);

GLOBAL_ASM(
glabel func0f010bb0
/*  f010bb0:	27bdf820 */ 	addiu	$sp,$sp,-2016
/*  f010bb4:	3c0f8006 */ 	lui	$t7,%hi(var80061bf0)
/*  f010bb8:	25ef1bf0 */ 	addiu	$t7,$t7,%lo(var80061bf0)
/*  f010bbc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f010bc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f010bc4:	25e807a4 */ 	addiu	$t0,$t7,0x7a4
/*  f010bc8:	27ae0038 */ 	addiu	$t6,$sp,0x38
.L0f010bcc:
/*  f010bcc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f010bd0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f010bd4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f010bd8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f010bdc:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f010be0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f010be4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f010be8:	15e8fff8 */ 	bne	$t7,$t0,.L0f010bcc
/*  f010bec:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f010bf0:	3c098009 */ 	lui	$t1,0x8009
/*  f010bf4:	91290af0 */ 	lbu	$t1,0xaf0($t1)
/*  f010bf8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f010bfc:	15210024 */ 	bne	$t1,$at,.L0f010c90
/*  f010c00:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f010c04:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f010c08:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f010c0c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f010c10:	00002825 */ 	or	$a1,$zero,$zero
/*  f010c14:	11400003 */ 	beqz	$t2,.L0f010c24
/*  f010c18:	00001825 */ 	or	$v1,$zero,$zero
/*  f010c1c:	10000001 */ 	beqz	$zero,.L0f010c24
/*  f010c20:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f010c24:
/*  f010c24:	8e0b0068 */ 	lw	$t3,0x68($s0)
/*  f010c28:	00002025 */ 	or	$a0,$zero,$zero
/*  f010c2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f010c30:	11600003 */ 	beqz	$t3,.L0f010c40
/*  f010c34:	3c068007 */ 	lui	$a2,0x8007
/*  f010c38:	10000001 */ 	beqz	$zero,.L0f010c40
/*  f010c3c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f010c40:
/*  f010c40:	8e0c0064 */ 	lw	$t4,0x64($s0)
/*  f010c44:	11800003 */ 	beqz	$t4,.L0f010c54
/*  f010c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f010c4c:	10000001 */ 	beqz	$zero,.L0f010c54
/*  f010c50:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f010c54:
/*  f010c54:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*  f010c58:	11a00003 */ 	beqz	$t5,.L0f010c68
/*  f010c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f010c60:	10000001 */ 	beqz	$zero,.L0f010c68
/*  f010c64:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f010c68:
/*  f010c68:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f010c6c:	0323c021 */ 	addu	$t8,$t9,$v1
/*  f010c70:	03054021 */ 	addu	$t0,$t8,$a1
/*  f010c74:	15010006 */ 	bne	$t0,$at,.L0f010c90
/*  f010c78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f010c7c:	8cc600ac */ 	lw	$a2,0xac($a2)
/*  f010c80:	24c6000f */ 	addiu	$a2,$a2,0xf
/*  f010c84:	34cf000f */ 	ori	$t7,$a2,0xf
/*  f010c88:	10000007 */ 	beqz	$zero,.L0f010ca8
/*  f010c8c:	39e6000f */ 	xori	$a2,$t7,0xf
.L0f010c90:
/*  f010c90:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f010c94:	0fc2777f */ 	jal	func0f09ddfc
/*  f010c98:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f010c9c:	2446000f */ 	addiu	$a2,$v0,0xf
/*  f010ca0:	34c9000f */ 	ori	$t1,$a2,0xf
/*  f010ca4:	3926000f */ 	xori	$a2,$t1,0xf
.L0f010ca8:
/*  f010ca8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f010cac:	0c0048f2 */ 	jal	func000123c8
/*  f010cb0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f010cb4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010cb8:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f010cbc:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f010cc0:	ad62158c */ 	sw	$v0,0x158c($t3)
/*  f010cc4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010cc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f010ccc:	a580159c */ 	sh	$zero,0x159c($t4)
/*  f010cd0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010cd4:	ada015a0 */ 	sw	$zero,0x15a0($t5)
/*  f010cd8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f010cdc:	af2015a4 */ 	sw	$zero,0x15a4($t9)
/*  f010ce0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f010ce4:	a30015b0 */ 	sb	$zero,0x15b0($t8)
/*  f010ce8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f010cec:	a10015b1 */ 	sb	$zero,0x15b1($t0)
/*  f010cf0:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f010cf4:	ade01588 */ 	sw	$zero,0x1588($t7)
/*  f010cf8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f010cfc:	adc51584 */ 	sw	$a1,0x1584($t6)
/*  f010d00:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010d04:	a14915ea */ 	sb	$t1,0x15ea($t2)
/*  f010d08:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010d0c:	a16015eb */ 	sb	$zero,0x15eb($t3)
/*  f010d10:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010d14:	908d1583 */ 	lbu	$t5,0x1583($a0)
/*  f010d18:	35b90002 */ 	ori	$t9,$t5,0x2
/*  f010d1c:	a0991583 */ 	sb	$t9,0x1583($a0)
/*  f010d20:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010d24:	27b90038 */ 	addiu	$t9,$sp,0x38
/*  f010d28:	90981583 */ 	lbu	$t8,0x1583($a0)
/*  f010d2c:	3308ff7f */ 	andi	$t0,$t8,0xff7f
/*  f010d30:	a0881583 */ 	sb	$t0,0x1583($a0)
/*  f010d34:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010d38:	272807a4 */ 	addiu	$t0,$t9,0x7a4
/*  f010d3c:	908f1583 */ 	lbu	$t7,0x1583($a0)
/*  f010d40:	31eefff7 */ 	andi	$t6,$t7,0xfff7
/*  f010d44:	a08e1583 */ 	sb	$t6,0x1583($a0)
/*  f010d48:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010d4c:	27ae0038 */ 	addiu	$t6,$sp,0x38
/*  f010d50:	a1251582 */ 	sb	$a1,0x1582($t1)
/*  f010d54:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010d58:	a14015e7 */ 	sb	$zero,0x15e7($t2)
/*  f010d5c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010d60:	25ca07a4 */ 	addiu	$t2,$t6,0x7a4
/*  f010d64:	908b1583 */ 	lbu	$t3,0x1583($a0)
/*  f010d68:	316cffdf */ 	andi	$t4,$t3,0xffdf
/*  f010d6c:	a08c1583 */ 	sb	$t4,0x1583($a0)
/*  f010d70:	8e0d0284 */ 	lw	$t5,0x284($s0)
.L0f010d74:
/*  f010d74:	8f210000 */ 	lw	$at,0x0($t9)
/*  f010d78:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f010d7c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f010d80:	ada1062c */ 	sw	$at,0x62c($t5)
/*  f010d84:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f010d88:	ada10630 */ 	sw	$at,0x630($t5)
/*  f010d8c:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f010d90:	1728fff8 */ 	bne	$t9,$t0,.L0f010d74
/*  f010d94:	ada10634 */ 	sw	$at,0x634($t5)
/*  f010d98:	8e0f0284 */ 	lw	$t7,0x284($s0)
.L0f010d9c:
/*  f010d9c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f010da0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f010da4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f010da8:	ade10dd0 */ 	sw	$at,0xdd0($t7)
/*  f010dac:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f010db0:	ade10dd4 */ 	sw	$at,0xdd4($t7)
/*  f010db4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f010db8:	15cafff8 */ 	bne	$t6,$t2,.L0f010d9c
/*  f010dbc:	ade10dd8 */ 	sw	$at,0xdd8($t7)
/*  f010dc0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010dc4:	00001825 */ 	or	$v1,$zero,$zero
/*  f010dc8:	908b0d0f */ 	lbu	$t3,0xd0f($a0)
/*  f010dcc:	316cffdf */ 	andi	$t4,$t3,0xffdf
/*  f010dd0:	a08c0d0f */ 	sb	$t4,0xd0f($a0)
/*  f010dd4:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f010dd8:	909814b3 */ 	lbu	$t8,0x14b3($a0)
/*  f010ddc:	3308ffdf */ 	andi	$t0,$t8,0xffdf
/*  f010de0:	a08814b3 */ 	sb	$t0,0x14b3($a0)
/*  f010de4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f010de8:	af201528 */ 	sw	$zero,0x1528($t9)
/*  f010dec:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010df0:	ada00d84 */ 	sw	$zero,0xd84($t5)
/*  f010df4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010df8:	a52015f2 */ 	sh	$zero,0x15f2($t1)
.L0f010dfc:
/*  f010dfc:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010e00:	01437021 */ 	addu	$t6,$t2,$v1
/*  f010e04:	a5c01518 */ 	sh	$zero,0x1518($t6)
/*  f010e08:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f010e0c:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f010e10:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f010e14:	28610008 */ 	slti	$at,$v1,0x8
/*  f010e18:	1420fff8 */ 	bnez	$at,.L0f010dfc
/*  f010e1c:	a5600d74 */ 	sh	$zero,0xd74($t3)
.L0f010e20:
/*  f010e20:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010e24:	0182c021 */ 	addu	$t8,$t4,$v0
/*  f010e28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010e2c:	28410084 */ 	slti	$at,$v0,0x84
/*  f010e30:	1420fffb */ 	bnez	$at,.L0f010e20
/*  f010e34:	af0017a8 */ 	sw	$zero,0x17a8($t8)
/*  f010e38:	00001025 */ 	or	$v0,$zero,$zero
/*  f010e3c:	2403001c */ 	addiu	$v1,$zero,0x1c
.L0f010e40:
/*  f010e40:	8e080288 */ 	lw	$t0,0x288($s0)
/*  f010e44:	0102c821 */ 	addu	$t9,$t0,$v0
/*  f010e48:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010e4c:	1443fffc */ 	bne	$v0,$v1,.L0f010e40
/*  f010e50:	af200000 */ 	sw	$zero,0x0($t9)
/*  f010e54:	3c013f80 */ 	lui	$at,0x3f80
/*  f010e58:	44811000 */ 	mtc1	$at,$f2
/*  f010e5c:	8e0d0288 */ 	lw	$t5,0x288($s0)
/*  f010e60:	3c017f1b */ 	lui	$at,%hi(var7f1a8230)
/*  f010e64:	c42c8230 */ 	lwc1	$f12,%lo(var7f1a8230)($at)
/*  f010e68:	ada0001c */ 	sw	$zero,0x1c($t5)
/*  f010e6c:	8e090288 */ 	lw	$t1,0x288($s0)
/*  f010e70:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f010e74:	44800000 */ 	mtc1	$zero,$f0
/*  f010e78:	ad200020 */ 	sw	$zero,0x20($t1)
/*  f010e7c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010e80:	3c017f1b */ 	lui	$at,%hi(var7f1a8234)
/*  f010e84:	00002025 */ 	or	$a0,$zero,$zero
/*  f010e88:	ad401940 */ 	sw	$zero,0x1940($t2)
/*  f010e8c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f010e90:	e5c215f8 */ 	swc1	$f2,0x15f8($t6)
/*  f010e94:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f010e98:	e5e215fc */ 	swc1	$f2,0x15fc($t7)
/*  f010e9c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010ea0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f010ea4:	ad601600 */ 	sw	$zero,0x1600($t3)
/*  f010ea8:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010eac:	ad801604 */ 	sw	$zero,0x1604($t4)
/*  f010eb0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f010eb4:	af001608 */ 	sw	$zero,0x1608($t8)
/*  f010eb8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f010ebc:	ad00160c */ 	sw	$zero,0x160c($t0)
/*  f010ec0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f010ec4:	af201610 */ 	sw	$zero,0x1610($t9)
/*  f010ec8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010ecc:	a1a21614 */ 	sb	$v0,0x1614($t5)
/*  f010ed0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010ed4:	a1221615 */ 	sb	$v0,0x1615($t1)
/*  f010ed8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010edc:	a1421616 */ 	sb	$v0,0x1616($t2)
/*  f010ee0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f010ee4:	a1c01617 */ 	sb	$zero,0x1617($t6)
/*  f010ee8:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010eec:	a56f1618 */ 	sh	$t7,0x1618($t3)
/*  f010ef0:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010ef4:	ad801620 */ 	sw	$zero,0x1620($t4)
/*  f010ef8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f010efc:	e7001660 */ 	swc1	$f0,0x1660($t8)
/*  f010f00:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f010f04:	e5001664 */ 	swc1	$f0,0x1664($t0)
/*  f010f08:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f010f0c:	e7201668 */ 	swc1	$f0,0x1668($t9)
/*  f010f10:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010f14:	e5a0166c */ 	swc1	$f0,0x166c($t5)
/*  f010f18:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010f1c:	e52c1670 */ 	swc1	$f12,0x1670($t1)
/*  f010f20:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010f24:	e5401674 */ 	swc1	$f0,0x1674($t2)
/*  f010f28:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f010f2c:	e5c01678 */ 	swc1	$f0,0x1678($t6)
/*  f010f30:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f010f34:	e5e0167c */ 	swc1	$f0,0x167c($t7)
/*  f010f38:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010f3c:	e5601680 */ 	swc1	$f0,0x1680($t3)
/*  f010f40:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010f44:	e58c1684 */ 	swc1	$f12,0x1684($t4)
/*  f010f48:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f010f4c:	e7001688 */ 	swc1	$f0,0x1688($t8)
/*  f010f50:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f010f54:	c4248234 */ 	lwc1	$f4,%lo(var7f1a8234)($at)
/*  f010f58:	e504168c */ 	swc1	$f4,0x168c($t0)
/*  f010f5c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f010f60:	e7201690 */ 	swc1	$f0,0x1690($t9)
/*  f010f64:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010f68:	ada016d4 */ 	sw	$zero,0x16d4($t5)
/*  f010f6c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010f70:	ad2518f0 */ 	sw	$a1,0x18f0($t1)
/*  f010f74:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f010f78:	e54016dc */ 	swc1	$f0,0x16dc($t2)
/*  f010f7c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f010f80:	e5c016e0 */ 	swc1	$f0,0x16e0($t6)
/*  f010f84:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f010f88:	e5e016e4 */ 	swc1	$f0,0x16e4($t7)
/*  f010f8c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f010f90:	ad6016e8 */ 	sw	$zero,0x16e8($t3)
/*  f010f94:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f010f98:	e58016ec */ 	swc1	$f0,0x16ec($t4)
/*  f010f9c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f010fa0:	0fc27450 */ 	jal	func0f09d140
/*  f010fa4:	e70016f0 */ 	swc1	$f0,0x16f0($t8)
/*  f010fa8:	0fc27450 */ 	jal	func0f09d140
/*  f010fac:	00002025 */ 	or	$a0,$zero,$zero
/*  f010fb0:	0fc27450 */ 	jal	func0f09d140
/*  f010fb4:	00002025 */ 	or	$a0,$zero,$zero
/*  f010fb8:	0fc27450 */ 	jal	func0f09d140
/*  f010fbc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f010fc0:	0fc27450 */ 	jal	func0f09d140
/*  f010fc4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f010fc8:	0fc27450 */ 	jal	func0f09d140
/*  f010fcc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f010fd0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f010fd4:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f010fd8:	3c014170 */ 	lui	$at,0x4170
/*  f010fdc:	ad0016d8 */ 	sw	$zero,0x16d8($t0)
/*  f010fe0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f010fe4:	44813000 */ 	mtc1	$at,$f6
/*  f010fe8:	3c014270 */ 	lui	$at,0x4270
/*  f010fec:	adb917a4 */ 	sw	$t9,0x17a4($t5)
/*  f010ff0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f010ff4:	44814000 */ 	mtc1	$at,$f8
/*  f010ff8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f010ffc:	e52616f4 */ 	swc1	$f6,0x16f4($t1)
/*  f011000:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f011004:	44815000 */ 	mtc1	$at,$f10
/*  f011008:	e54816f8 */ 	swc1	$f8,0x16f8($t2)
/*  f01100c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f011010:	e5ca16fc */ 	swc1	$f10,0x16fc($t6)
/*  f011014:	0fc59585 */ 	jal	stageGetIndex
/*  f011018:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f01101c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f011020:	1441000e */ 	bne	$v0,$at,.L0f01105c
/*  f011024:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f011028:	2463ff18 */ 	addiu	$v1,$v1,%lo(g_Weapons)
/*  f01102c:	8c6f00b8 */ 	lw	$t7,0xb8($v1)
/*  f011030:	24044c3d */ 	addiu	$a0,$zero,0x4c3d
/*  f011034:	3c01ff9f */ 	lui	$at,0xff9f
/*  f011038:	a5e40046 */ 	sh	$a0,0x46($t7)
/*  f01103c:	8c6b00b8 */ 	lw	$t3,0xb8($v1)
/*  f011040:	3421ffff */ 	ori	$at,$at,0xffff
/*  f011044:	a5640044 */ 	sh	$a0,0x44($t3)
/*  f011048:	8c6200b8 */ 	lw	$v0,0xb8($v1)
/*  f01104c:	8c4c004c */ 	lw	$t4,0x4c($v0)
/*  f011050:	0181c024 */ 	and	$t8,$t4,$at
/*  f011054:	10000024 */ 	beqz	$zero,.L0f0110e8
/*  f011058:	ac58004c */ 	sw	$t8,0x4c($v0)
.L0f01105c:
/*  f01105c:	0fc59585 */ 	jal	stageGetIndex
/*  f011060:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f011064:	24010009 */ 	addiu	$at,$zero,0x9
/*  f011068:	10410006 */ 	beq	$v0,$at,.L0f011084
/*  f01106c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011070:	0fc59585 */ 	jal	stageGetIndex
/*  f011074:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f011078:	24010023 */ 	addiu	$at,$zero,0x23
/*  f01107c:	1441000f */ 	bne	$v0,$at,.L0f0110bc
/*  f011080:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
.L0f011084:
/*  f011084:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f011088:	2463ff18 */ 	addiu	$v1,$v1,%lo(g_Weapons)
/*  f01108c:	8c6800b8 */ 	lw	$t0,0xb8($v1)
/*  f011090:	24044c3e */ 	addiu	$a0,$zero,0x4c3e
/*  f011094:	3c01ff9f */ 	lui	$at,0xff9f
/*  f011098:	a5040046 */ 	sh	$a0,0x46($t0)
/*  f01109c:	8c7900b8 */ 	lw	$t9,0xb8($v1)
/*  f0110a0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0110a4:	a7240044 */ 	sh	$a0,0x44($t9)
/*  f0110a8:	8c6200b8 */ 	lw	$v0,0xb8($v1)
/*  f0110ac:	8c4d004c */ 	lw	$t5,0x4c($v0)
/*  f0110b0:	01a14824 */ 	and	$t1,$t5,$at
/*  f0110b4:	1000000c */ 	beqz	$zero,.L0f0110e8
/*  f0110b8:	ac49004c */ 	sw	$t1,0x4c($v0)
.L0f0110bc:
/*  f0110bc:	2463ff18 */ 	addiu	$v1,$v1,%lo(g_Weapons)
/*  f0110c0:	8c6a00b8 */ 	lw	$t2,0xb8($v1)
/*  f0110c4:	24044c3c */ 	addiu	$a0,$zero,0x4c3c
/*  f0110c8:	3c010060 */ 	lui	$at,0x60
/*  f0110cc:	a5440046 */ 	sh	$a0,0x46($t2)
/*  f0110d0:	8c6e00b8 */ 	lw	$t6,0xb8($v1)
/*  f0110d4:	a5c40044 */ 	sh	$a0,0x44($t6)
/*  f0110d8:	8c6200b8 */ 	lw	$v0,0xb8($v1)
/*  f0110dc:	8c4f004c */ 	lw	$t7,0x4c($v0)
/*  f0110e0:	01e15825 */ 	or	$t3,$t7,$at
/*  f0110e4:	ac4b004c */ 	sw	$t3,0x4c($v0)
.L0f0110e8:
/*  f0110e8:	0fc273ab */ 	jal	func0f09ceac
/*  f0110ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0110f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0110f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0110f8:	27bd07e0 */ 	addiu	$sp,$sp,0x7e0
/*  f0110fc:	03e00008 */ 	jr	$ra
/*  f011100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01110c:	00000000 */ 	sll	$zero,$zero,0x0
);
