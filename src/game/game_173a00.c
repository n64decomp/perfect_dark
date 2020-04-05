#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_13b670.h"
#include "game/game_16e810.h"
#include "game/game_173a00.h"
#include "gvars/gvars.h"
#include "types.h"

const char var7f1b7ba0[] = "default";
const char var7f1b7ba8[] = "stone";
const char var7f1b7bb0[] = "wood";
const char var7f1b7bb8[] = "metal";
const char var7f1b7bc0[] = "glass";
const char var7f1b7bc8[] = "shallow water";
const char var7f1b7bd8[] = "snow";
const char var7f1b7be0[] = "dirt";
const char var7f1b7be8[] = "mud";
const char var7f1b7bec[] = "tile";
const char var7f1b7bf4[] = "metalobj";
const char var7f1b7c00[] = "chr";
const char var7f1b7c04[] = "glass xlu";
const char var7f1b7c10[] = "no hit";
const char var7f1b7c18[] = "deep water";
const char var7f1b7c24[] = "";
const char var7f1b7c28[] = "";
const char var7f1b7c2c[] = "";

GLOBAL_ASM(
glabel func0f173a00
/*  f173a00:	03e00008 */ 	jr	$ra
/*  f173a04:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173a08
/*  f173a08:	3c03800b */ 	lui	$v1,%hi(var800ab5b8)
/*  f173a0c:	3c04800b */ 	lui	$a0,%hi(var800ab718)
/*  f173a10:	3c02800b */ 	lui	$v0,%hi(var800ab7b8)
/*  f173a14:	2442b7b8 */ 	addiu	$v0,$v0,%lo(var800ab7b8)
/*  f173a18:	2484b718 */ 	addiu	$a0,$a0,%lo(var800ab718)
/*  f173a1c:	2463b5b8 */ 	addiu	$v1,$v1,%lo(var800ab5b8)
.L0f173a20:
/*  f173a20:	24840014 */ 	addiu	$a0,$a0,0x14
/*  f173a24:	2463002c */ 	addiu	$v1,$v1,0x2c
/*  f173a28:	ac60ffd4 */ 	sw	$zero,-0x2c($v1)
/*  f173a2c:	1482fffc */ 	bne	$a0,$v0,.L0f173a20
/*  f173a30:	ac80ffec */ 	sw	$zero,-0x14($a0)
/*  f173a34:	240effff */ 	addiu	$t6,$zero,-1
/*  f173a38:	3c01800b */ 	lui	$at,%hi(var800ab5b0)
/*  f173a3c:	03e00008 */ 	jr	$ra
/*  f173a40:	ac2eb5b0 */ 	sw	$t6,%lo(var800ab5b0)($at)
);

GLOBAL_ASM(
glabel func0f173a44
/*  f173a44:	3c03800b */ 	lui	$v1,%hi(var800ab5b0)
/*  f173a48:	2463b5b0 */ 	addiu	$v1,$v1,%lo(var800ab5b0)
/*  f173a4c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f173a50:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f173a54:	548e0004 */ 	bnel	$a0,$t6,.L0f173a68
/*  f173a58:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f173a5c:	03e00008 */ 	jr	$ra
/*  f173a60:	00001025 */ 	or	$v0,$zero,$zero
/*  f173a64:	ac640000 */ 	sw	$a0,0x0($v1)
.L0f173a68:
/*  f173a68:	03e00008 */ 	jr	$ra
/*  f173a6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173a70
/*  f173a70:	00047080 */ 	sll	$t6,$a0,0x2
/*  f173a74:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f173a78:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f173a7c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f173a80:	3c0f800b */ 	lui	$t7,%hi(var800ab5b8)
/*  f173a84:	25efb5b8 */ 	addiu	$t7,$t7,%lo(var800ab5b8)
/*  f173a88:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f173a8c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f173a90:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f173a94:	00001825 */ 	or	$v1,$zero,$zero
/*  f173a98:	53000027 */ 	beqzl	$t8,.L0f173b38
/*  f173a9c:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173aa0:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f173aa4:	54b90024 */ 	bnel	$a1,$t9,.L0f173b38
/*  f173aa8:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173aac:	8c480008 */ 	lw	$t0,0x8($v0)
/*  f173ab0:	54c80021 */ 	bnel	$a2,$t0,.L0f173b38
/*  f173ab4:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173ab8:	8c49000c */ 	lw	$t1,0xc($v0)
/*  f173abc:	8faa0010 */ 	lw	$t2,0x10($sp)
/*  f173ac0:	54e9001d */ 	bnel	$a3,$t1,.L0f173b38
/*  f173ac4:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173ac8:	8c4b0010 */ 	lw	$t3,0x10($v0)
/*  f173acc:	8fac0014 */ 	lw	$t4,0x14($sp)
/*  f173ad0:	554b0019 */ 	bnel	$t2,$t3,.L0f173b38
/*  f173ad4:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173ad8:	8c4d0014 */ 	lw	$t5,0x14($v0)
/*  f173adc:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f173ae0:	558d0015 */ 	bnel	$t4,$t5,.L0f173b38
/*  f173ae4:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173ae8:	8c4f0018 */ 	lw	$t7,0x18($v0)
/*  f173aec:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f173af0:	55cf0011 */ 	bnel	$t6,$t7,.L0f173b38
/*  f173af4:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173af8:	8c59001c */ 	lw	$t9,0x1c($v0)
/*  f173afc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f173b00:	5719000d */ 	bnel	$t8,$t9,.L0f173b38
/*  f173b04:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173b08:	8c490020 */ 	lw	$t1,0x20($v0)
/*  f173b0c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f173b10:	55090009 */ 	bnel	$t0,$t1,.L0f173b38
/*  f173b14:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173b18:	8c4b0024 */ 	lw	$t3,0x24($v0)
/*  f173b1c:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f173b20:	554b0005 */ 	bnel	$t2,$t3,.L0f173b38
/*  f173b24:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f173b28:	8c4d0028 */ 	lw	$t5,0x28($v0)
/*  f173b2c:	118d0015 */ 	beq	$t4,$t5,.L0f173b84
/*  f173b30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173b34:	8faf0010 */ 	lw	$t7,0x10($sp)
.L0f173b38:
/*  f173b38:	8fb80014 */ 	lw	$t8,0x14($sp)
/*  f173b3c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f173b40:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f173b44:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f173b48:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f173b4c:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f173b50:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f173b54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f173b58:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f173b5c:	ac450004 */ 	sw	$a1,0x4($v0)
/*  f173b60:	ac460008 */ 	sw	$a2,0x8($v0)
/*  f173b64:	ac47000c */ 	sw	$a3,0xc($v0)
/*  f173b68:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f173b6c:	ac580014 */ 	sw	$t8,0x14($v0)
/*  f173b70:	ac590018 */ 	sw	$t9,0x18($v0)
/*  f173b74:	ac48001c */ 	sw	$t0,0x1c($v0)
/*  f173b78:	ac490020 */ 	sw	$t1,0x20($v0)
/*  f173b7c:	ac4a0024 */ 	sw	$t2,0x24($v0)
/*  f173b80:	ac4b0028 */ 	sw	$t3,0x28($v0)
.L0f173b84:
/*  f173b84:	03e00008 */ 	jr	$ra
/*  f173b88:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f173b8c
/*  f173b8c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f173b90:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f173b94:	3c0f800b */ 	lui	$t7,%hi(var800ab718)
/*  f173b98:	25efb718 */ 	addiu	$t7,$t7,%lo(var800ab718)
/*  f173b9c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f173ba0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f173ba4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f173ba8:	00001825 */ 	or	$v1,$zero,$zero
/*  f173bac:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f173bb0:	5300000f */ 	beqzl	$t8,.L0f173bf0
/*  f173bb4:	8fad0010 */ 	lw	$t5,0x10($sp)
/*  f173bb8:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f173bbc:	54b9000c */ 	bnel	$a1,$t9,.L0f173bf0
/*  f173bc0:	8fad0010 */ 	lw	$t5,0x10($sp)
/*  f173bc4:	8c480008 */ 	lw	$t0,0x8($v0)
/*  f173bc8:	54c80009 */ 	bnel	$a2,$t0,.L0f173bf0
/*  f173bcc:	8fad0010 */ 	lw	$t5,0x10($sp)
/*  f173bd0:	8c49000c */ 	lw	$t1,0xc($v0)
/*  f173bd4:	8faa0010 */ 	lw	$t2,0x10($sp)
/*  f173bd8:	54e90005 */ 	bnel	$a3,$t1,.L0f173bf0
/*  f173bdc:	8fad0010 */ 	lw	$t5,0x10($sp)
/*  f173be0:	8c4b0010 */ 	lw	$t3,0x10($v0)
/*  f173be4:	114b0008 */ 	beq	$t2,$t3,.L0f173c08
/*  f173be8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173bec:	8fad0010 */ 	lw	$t5,0x10($sp)
.L0f173bf0:
/*  f173bf0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f173bf4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f173bf8:	ac450004 */ 	sw	$a1,0x4($v0)
/*  f173bfc:	ac460008 */ 	sw	$a2,0x8($v0)
/*  f173c00:	ac47000c */ 	sw	$a3,0xc($v0)
/*  f173c04:	ac4d0010 */ 	sw	$t5,0x10($v0)
.L0f173c08:
/*  f173c08:	03e00008 */ 	jr	$ra
/*  f173c0c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f173c10
/*  f173c10:	14a00003 */ 	bnez	$a1,.L0f173c20
/*  f173c14:	90830008 */ 	lbu	$v1,0x8($a0)
/*  f173c18:	03e00008 */ 	jr	$ra
/*  f173c1c:	00601025 */ 	or	$v0,$v1,$zero
.L0f173c20:
/*  f173c20:	8c8e000c */ 	lw	$t6,0xc($a0)
/*  f173c24:	3c02800b */ 	lui	$v0,%hi(var800ab538)
/*  f173c28:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f173c2c:	07010018 */ 	bgez	$t8,.L0f173c90
/*  f173c30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173c34:	8c42b538 */ 	lw	$v0,%lo(var800ab538)($v0)
/*  f173c38:	00003025 */ 	or	$a2,$zero,$zero
/*  f173c3c:	18400012 */ 	blez	$v0,.L0f173c88
/*  f173c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173c44:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f173c48:	3c07800b */ 	lui	$a3,%hi(var800aabd8)
/*  f173c4c:	24e7abd8 */ 	addiu	$a3,$a3,%lo(var800aabd8)
/*  f173c50:	0003cd02 */ 	srl	$t9,$v1,0x14
/*  f173c54:	03201825 */ 	or	$v1,$t9,$zero
.L0f173c58:
/*  f173c58:	84e80000 */ 	lh	$t0,0x0($a3)
/*  f173c5c:	14680006 */ 	bne	$v1,$t0,.L0f173c78
/*  f173c60:	00064900 */ 	sll	$t1,$a2,0x4
/*  f173c64:	01255021 */ 	addu	$t2,$t1,$a1
/*  f173c68:	3c02800b */ 	lui	$v0,%hi(var800aabd8+0x1)
/*  f173c6c:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f173c70:	03e00008 */ 	jr	$ra
/*  f173c74:	9042abd9 */ 	lbu	$v0,%lo(var800aabd8+0x1)($v0)
.L0f173c78:
/*  f173c78:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f173c7c:	00c2082a */ 	slt	$at,$a2,$v0
/*  f173c80:	1420fff5 */ 	bnez	$at,.L0f173c58
/*  f173c84:	24e70010 */ 	addiu	$a3,$a3,0x10
.L0f173c88:
/*  f173c88:	03e00008 */ 	jr	$ra
/*  f173c8c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f173c90:
/*  f173c90:	18a00006 */ 	blez	$a1,.L0f173cac
/*  f173c94:	00003025 */ 	or	$a2,$zero,$zero
.L0f173c98:
/*  f173c98:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f173c9c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f173ca0:	00035843 */ 	sra	$t3,$v1,0x1
/*  f173ca4:	14c5fffc */ 	bne	$a2,$a1,.L0f173c98
/*  f173ca8:	01601825 */ 	or	$v1,$t3,$zero
.L0f173cac:
/*  f173cac:	00601025 */ 	or	$v0,$v1,$zero
/*  f173cb0:	03e00008 */ 	jr	$ra
/*  f173cb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173cb8
/*  f173cb8:	14a00003 */ 	bnez	$a1,.L0f173cc8
/*  f173cbc:	90830009 */ 	lbu	$v1,0x9($a0)
/*  f173cc0:	03e00008 */ 	jr	$ra
/*  f173cc4:	00601025 */ 	or	$v0,$v1,$zero
.L0f173cc8:
/*  f173cc8:	8c8e000c */ 	lw	$t6,0xc($a0)
/*  f173ccc:	3c02800b */ 	lui	$v0,%hi(var800ab538)
/*  f173cd0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f173cd4:	07010018 */ 	bgez	$t8,.L0f173d38
/*  f173cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173cdc:	8c42b538 */ 	lw	$v0,%lo(var800ab538)($v0)
/*  f173ce0:	00003025 */ 	or	$a2,$zero,$zero
/*  f173ce4:	18400012 */ 	blez	$v0,.L0f173d30
/*  f173ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f173cec:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f173cf0:	3c07800b */ 	lui	$a3,%hi(var800aabd8)
/*  f173cf4:	24e7abd8 */ 	addiu	$a3,$a3,%lo(var800aabd8)
/*  f173cf8:	0003cd02 */ 	srl	$t9,$v1,0x14
/*  f173cfc:	03201825 */ 	or	$v1,$t9,$zero
.L0f173d00:
/*  f173d00:	84e80000 */ 	lh	$t0,0x0($a3)
/*  f173d04:	14680006 */ 	bne	$v1,$t0,.L0f173d20
/*  f173d08:	00064900 */ 	sll	$t1,$a2,0x4
/*  f173d0c:	01255021 */ 	addu	$t2,$t1,$a1
/*  f173d10:	3c02800b */ 	lui	$v0,%hi(var800aabe0)
/*  f173d14:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f173d18:	03e00008 */ 	jr	$ra
/*  f173d1c:	9042abe0 */ 	lbu	$v0,%lo(var800aabe0)($v0)
.L0f173d20:
/*  f173d20:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f173d24:	00c2082a */ 	slt	$at,$a2,$v0
/*  f173d28:	1420fff5 */ 	bnez	$at,.L0f173d00
/*  f173d2c:	24e70010 */ 	addiu	$a3,$a3,0x10
.L0f173d30:
/*  f173d30:	03e00008 */ 	jr	$ra
/*  f173d34:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f173d38:
/*  f173d38:	18a00006 */ 	blez	$a1,.L0f173d54
/*  f173d3c:	00003025 */ 	or	$a2,$zero,$zero
.L0f173d40:
/*  f173d40:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f173d44:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f173d48:	00035843 */ 	sra	$t3,$v1,0x1
/*  f173d4c:	14c5fffc */ 	bne	$a2,$a1,.L0f173d40
/*  f173d50:	01601825 */ 	or	$v1,$t3,$zero
.L0f173d54:
/*  f173d54:	00601025 */ 	or	$v0,$v1,$zero
/*  f173d58:	03e00008 */ 	jr	$ra
/*  f173d5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173d60
/*  f173d60:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f173d64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f173d68:	8c830008 */ 	lw	$v1,0x8($a0)
/*  f173d6c:	306e0003 */ 	andi	$t6,$v1,0x3
/*  f173d70:	0fc5cf04 */ 	jal	func0f173c10
/*  f173d74:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f173d78:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f173d7c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f173d80:	00402025 */ 	or	$a0,$v0,$zero
/*  f173d84:	14610008 */ 	bne	$v1,$at,.L0f173da8
/*  f173d88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f173d8c:	24420003 */ 	addiu	$v0,$v0,0x3
/*  f173d90:	04410003 */ 	bgez	$v0,.L0f173da0
/*  f173d94:	00027883 */ 	sra	$t7,$v0,0x2
/*  f173d98:	24410003 */ 	addiu	$at,$v0,0x3
/*  f173d9c:	00017883 */ 	sra	$t7,$at,0x2
.L0f173da0:
/*  f173da0:	10000019 */ 	beqz	$zero,.L0f173e08
/*  f173da4:	01e01025 */ 	or	$v0,$t7,$zero
.L0f173da8:
/*  f173da8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f173dac:	14610007 */ 	bne	$v1,$at,.L0f173dcc
/*  f173db0:	24820003 */ 	addiu	$v0,$a0,0x3
/*  f173db4:	04410003 */ 	bgez	$v0,.L0f173dc4
/*  f173db8:	0002c083 */ 	sra	$t8,$v0,0x2
/*  f173dbc:	24410003 */ 	addiu	$at,$v0,0x3
/*  f173dc0:	0001c083 */ 	sra	$t8,$at,0x2
.L0f173dc4:
/*  f173dc4:	10000010 */ 	beqz	$zero,.L0f173e08
/*  f173dc8:	03001025 */ 	or	$v0,$t8,$zero
.L0f173dcc:
/*  f173dcc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f173dd0:	14610008 */ 	bne	$v1,$at,.L0f173df4
/*  f173dd4:	2482000f */ 	addiu	$v0,$a0,0xf
/*  f173dd8:	24820007 */ 	addiu	$v0,$a0,0x7
/*  f173ddc:	04410003 */ 	bgez	$v0,.L0f173dec
/*  f173de0:	0002c8c3 */ 	sra	$t9,$v0,0x3
/*  f173de4:	24410007 */ 	addiu	$at,$v0,0x7
/*  f173de8:	0001c8c3 */ 	sra	$t9,$at,0x3
.L0f173dec:
/*  f173dec:	10000006 */ 	beqz	$zero,.L0f173e08
/*  f173df0:	03201025 */ 	or	$v0,$t9,$zero
.L0f173df4:
/*  f173df4:	04410003 */ 	bgez	$v0,.L0f173e04
/*  f173df8:	00024103 */ 	sra	$t0,$v0,0x4
/*  f173dfc:	2441000f */ 	addiu	$at,$v0,0xf
/*  f173e00:	00014103 */ 	sra	$t0,$at,0x4
.L0f173e04:
/*  f173e04:	01001025 */ 	or	$v0,$t0,$zero
.L0f173e08:
/*  f173e08:	03e00008 */ 	jr	$ra
/*  f173e0c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f173e10
/*  f173e10:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f173e14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f173e18:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f173e1c:	0fc5cf2e */ 	jal	func0f173cb8
/*  f173e20:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f173e24:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f173e28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f173e2c:	0fc5cf58 */ 	jal	func0f173d60
/*  f173e30:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f173e34:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f173e38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f173e3c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f173e40:	004e0019 */ 	multu	$v0,$t6
/*  f173e44:	00001012 */ 	mflo	$v0
/*  f173e48:	03e00008 */ 	jr	$ra
/*  f173e4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173e50
/*  f173e50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f173e54:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f173e58:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f173e5c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f173e60:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f173e64:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f173e68:	8c830008 */ 	lw	$v1,0x8($a0)
/*  f173e6c:	9082000b */ 	lbu	$v0,0xb($a0)
/*  f173e70:	00c08825 */ 	or	$s1,$a2,$zero
/*  f173e74:	306e0003 */ 	andi	$t6,$v1,0x3
/*  f173e78:	00027942 */ 	srl	$t7,$v0,0x5
/*  f173e7c:	00809825 */ 	or	$s3,$a0,$zero
/*  f173e80:	11e00003 */ 	beqz	$t7,.L0f173e90
/*  f173e84:	01c01825 */ 	or	$v1,$t6,$zero
/*  f173e88:	10000002 */ 	beqz	$zero,.L0f173e94
/*  f173e8c:	01e09025 */ 	or	$s2,$t7,$zero
.L0f173e90:
/*  f173e90:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f173e94:
/*  f173e94:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f173e98:	14620003 */ 	bne	$v1,$v0,.L0f173ea8
/*  f173e9c:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f173ea0:	1000000b */ 	beqz	$zero,.L0f173ed0
/*  f173ea4:	aca20000 */ 	sw	$v0,0x0($a1)
.L0f173ea8:
/*  f173ea8:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f173eac:	14620003 */ 	bne	$v1,$v0,.L0f173ebc
/*  f173eb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f173eb4:	10000006 */ 	beqz	$zero,.L0f173ed0
/*  f173eb8:	aca20000 */ 	sw	$v0,0x0($a1)
.L0f173ebc:
/*  f173ebc:	54610004 */ 	bnel	$v1,$at,.L0f173ed0
/*  f173ec0:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f173ec4:	10000002 */ 	beqz	$zero,.L0f173ed0
/*  f173ec8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f173ecc:	aca20000 */ 	sw	$v0,0x0($a1)
.L0f173ed0:
/*  f173ed0:	1a40000a */ 	blez	$s2,.L0f173efc
/*  f173ed4:	00008025 */ 	or	$s0,$zero,$zero
.L0f173ed8:
/*  f173ed8:	02602025 */ 	or	$a0,$s3,$zero
/*  f173edc:	0fc5cf84 */ 	jal	func0f173e10
/*  f173ee0:	02002825 */ 	or	$a1,$s0,$zero
/*  f173ee4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f173ee8:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f173eec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f173ef0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f173ef4:	1612fff8 */ 	bne	$s0,$s2,.L0f173ed8
/*  f173ef8:	ae280000 */ 	sw	$t0,0x0($s1)
.L0f173efc:
/*  f173efc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f173f00:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f173f04:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f173f08:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f173f0c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f173f10:	03e00008 */ 	jr	$ra
/*  f173f14:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f173f18
/*  f173f18:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f173f1c:	18800008 */ 	blez	$a0,.L0f173f40
/*  f173f20:	00001825 */ 	or	$v1,$zero,$zero
/*  f173f24:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f173f28:	00047043 */ 	sra	$t6,$a0,0x1
.L0f173f2c:
/*  f173f2c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f173f30:	19c00003 */ 	blez	$t6,.L0f173f40
/*  f173f34:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f173f38:	5462fffc */ 	bnel	$v1,$v0,.L0f173f2c
/*  f173f3c:	00047043 */ 	sra	$t6,$a0,0x1
.L0f173f40:
/*  f173f40:	03e00008 */ 	jr	$ra
/*  f173f44:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f173f48
/*  f173f48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f173f4c:	54810004 */ 	bnel	$a0,$at,.L0f173f60
/*  f173f50:	24010002 */ 	addiu	$at,$zero,0x2
/*  f173f54:	03e00008 */ 	jr	$ra
/*  f173f58:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f173f5c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f173f60:
/*  f173f60:	14810003 */ 	bne	$a0,$at,.L0f173f70
/*  f173f64:	00001025 */ 	or	$v0,$zero,$zero
/*  f173f68:	03e00008 */ 	jr	$ra
/*  f173f6c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f173f70:
/*  f173f70:	03e00008 */ 	jr	$ra
/*  f173f74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f173f78
/*  f173f78:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f173f7c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f173f80:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f173f84:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f173f88:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f173f8c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f173f90:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f173f94:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f173f98:	3c19800b */ 	lui	$t9,%hi(g_Textures)
/*  f173f9c:	8f39abc0 */ 	lw	$t9,%lo(g_Textures)($t9)
/*  f173fa0:	000e7d02 */ 	srl	$t7,$t6,0x14
/*  f173fa4:	00809025 */ 	or	$s2,$a0,$zero
/*  f173fa8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f173fac:	00a08825 */ 	or	$s1,$a1,$zero
/*  f173fb0:	90a40008 */ 	lbu	$a0,0x8($a1)
/*  f173fb4:	0fc5cfc6 */ 	jal	func0f173f18
/*  f173fb8:	03198021 */ 	addu	$s0,$t8,$t9
/*  f173fbc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f173fc0:	0fc5cfc6 */ 	jal	func0f173f18
/*  f173fc4:	92240009 */ 	lbu	$a0,0x9($s1)
/*  f173fc8:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f173fcc:	02202025 */ 	or	$a0,$s1,$zero
/*  f173fd0:	0fc5cf58 */ 	jal	func0f173d60
/*  f173fd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f173fd8:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f173fdc:	02401825 */ 	or	$v1,$s2,$zero
/*  f173fe0:	3c01fa00 */ 	lui	$at,0xfa00
/*  f173fe4:	310900ff */ 	andi	$t1,$t0,0xff
/*  f173fe8:	00095200 */ 	sll	$t2,$t1,0x8
/*  f173fec:	01415825 */ 	or	$t3,$t2,$at
/*  f173ff0:	240cffff */ 	addiu	$t4,$zero,-1
/*  f173ff4:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f173ff8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f173ffc:	8e24000c */ 	lw	$a0,0xc($s1)
/*  f174000:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174004:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f174008:	00046f82 */ 	srl	$t5,$a0,0x1e
/*  f17400c:	0fc5ce91 */ 	jal	func0f173a44
/*  f174010:	000d2380 */ 	sll	$a0,$t5,0xe
/*  f174014:	1040000a */ 	beqz	$v0,.L0f174040
/*  f174018:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f17401c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f174020:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f174024:	02401025 */ 	or	$v0,$s2,$zero
/*  f174028:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f17402c:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f174030:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174034:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*  f174038:	00194380 */ 	sll	$t0,$t9,0xe
/*  f17403c:	ac480004 */ 	sw	$t0,0x4($v0)
.L0f174040:
/*  f174040:	920c0004 */ 	lbu	$t4,0x4($s0)
/*  f174044:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f174048:	8e220008 */ 	lw	$v0,0x8($s1)
/*  f17404c:	318d000f */ 	andi	$t5,$t4,0xf
/*  f174050:	00ed0019 */ 	multu	$a3,$t5
/*  f174054:	000a5f02 */ 	srl	$t3,$t2,0x1c
/*  f174058:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17405c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174060:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f174064:	00022ec0 */ 	sll	$a1,$v0,0x1b
/*  f174068:	00054f42 */ 	srl	$t1,$a1,0x1d
/*  f17406c:	01202825 */ 	or	$a1,$t1,$zero
/*  f174070:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f174074:	00002025 */ 	or	$a0,$zero,$zero
/*  f174078:	00007012 */ 	mflo	$t6
/*  f17407c:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f174080:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f174084:	92190005 */ 	lbu	$t9,0x5($s0)
/*  f174088:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f17408c:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f174090:	00194102 */ 	srl	$t0,$t9,0x4
/*  f174094:	03084823 */ 	subu	$t1,$t8,$t0
/*  f174098:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f17409c:	960c0004 */ 	lhu	$t4,0x4($s0)
/*  f1740a0:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f1740a4:	30460003 */ 	andi	$a2,$v0,0x3
/*  f1740a8:	318d000f */ 	andi	$t5,$t4,0xf
/*  f1740ac:	014d5823 */ 	subu	$t3,$t2,$t5
/*  f1740b0:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f1740b4:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f1740b8:	0fc5ce9c */ 	jal	func0f173a70
/*  f1740bc:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f1740c0:	1040003c */ 	beqz	$v0,.L0f1741b4
/*  f1740c4:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f1740c8:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*  f1740cc:	3c01f500 */ 	lui	$at,0xf500
/*  f1740d0:	30ef01ff */ 	andi	$t7,$a3,0x1ff
/*  f1740d4:	000acec0 */ 	sll	$t9,$t2,0x1b
/*  f1740d8:	314d0003 */ 	andi	$t5,$t2,0x3
/*  f1740dc:	920a0004 */ 	lbu	$t2,0x4($s0)
/*  f1740e0:	000d5cc0 */ 	sll	$t3,$t5,0x13
/*  f1740e4:	0019c742 */ 	srl	$t8,$t9,0x1d
/*  f1740e8:	314d000f */ 	andi	$t5,$t2,0xf
/*  f1740ec:	00ed0019 */ 	multu	$a3,$t5
/*  f1740f0:	33080007 */ 	andi	$t0,$t8,0x7
/*  f1740f4:	00084d40 */ 	sll	$t1,$t0,0x15
/*  f1740f8:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1740fc:	01216025 */ 	or	$t4,$t1,$at
/*  f174100:	018b7025 */ 	or	$t6,$t4,$t3
/*  f174104:	000fca40 */ 	sll	$t9,$t7,0x9
/*  f174108:	00084f02 */ 	srl	$t1,$t0,0x1c
/*  f17410c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f174110:	02401825 */ 	or	$v1,$s2,$zero
/*  f174114:	00006012 */ 	mflo	$t4
/*  f174118:	012c5821 */ 	addu	$t3,$t1,$t4
/*  f17411c:	316f01ff */ 	andi	$t7,$t3,0x1ff
/*  f174120:	030f7025 */ 	or	$t6,$t8,$t7
/*  f174124:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f174128:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f17412c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174130:	0fc5cfd2 */ 	jal	func0f173f48
/*  f174134:	00002025 */ 	or	$a0,$zero,$zero
/*  f174138:	00002025 */ 	or	$a0,$zero,$zero
/*  f17413c:	0fc5cfd2 */ 	jal	func0f173f48
/*  f174140:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f174144:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f174148:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f17414c:	96180004 */ 	lhu	$t8,0x4($s0)
/*  f174150:	30590003 */ 	andi	$t9,$v0,0x3
/*  f174154:	306a0003 */ 	andi	$t2,$v1,0x3
/*  f174158:	000a6c80 */ 	sll	$t5,$t2,0x12
/*  f17415c:	00194200 */ 	sll	$t0,$t9,0x8
/*  f174160:	010d4825 */ 	or	$t1,$t0,$t5
/*  f174164:	01987823 */ 	subu	$t7,$t4,$t8
/*  f174168:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f17416c:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f174170:	920f0005 */ 	lbu	$t7,0x5($s0)
/*  f174174:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f174178:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f17417c:	01395025 */ 	or	$t2,$t1,$t9
/*  f174180:	310d000f */ 	andi	$t5,$t0,0xf
/*  f174184:	000d5a80 */ 	sll	$t3,$t5,0xa
/*  f174188:	014b6025 */ 	or	$t4,$t2,$t3
/*  f17418c:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f174190:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f174194:	030e4823 */ 	subu	$t1,$t8,$t6
/*  f174198:	3139000f */ 	andi	$t9,$t1,0xf
/*  f17419c:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f1741a0:	00194100 */ 	sll	$t0,$t9,0x4
/*  f1741a4:	01886825 */ 	or	$t5,$t4,$t0
/*  f1741a8:	314b000f */ 	andi	$t3,$t2,0xf
/*  f1741ac:	01ab7825 */ 	or	$t7,$t5,$t3
/*  f1741b0:	af0f0004 */ 	sw	$t7,0x4($t8)
.L0f1741b4:
/*  f1741b4:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f1741b8:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1741bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1741c0:	14820007 */ 	bne	$a0,$v0,.L0f1741e0
/*  f1741c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1741c8:	8e2e000c */ 	lw	$t6,0xc($s1)
/*  f1741cc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1741d0:	07200003 */ 	bltz	$t9,.L0f1741e0
/*  f1741d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1741d8:	10000001 */ 	beqz	$zero,.L0f1741e0
/*  f1741dc:	00401825 */ 	or	$v1,$v0,$zero
.L0f1741e0:
/*  f1741e0:	14820007 */ 	bne	$a0,$v0,.L0f174200
/*  f1741e4:	00602825 */ 	or	$a1,$v1,$zero
/*  f1741e8:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f1741ec:	000c5080 */ 	sll	$t2,$t4,0x2
/*  f1741f0:	05420004 */ 	bltzl	$t2,.L0f174204
/*  f1741f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1741f8:	10000002 */ 	beqz	$zero,.L0f174204
/*  f1741fc:	00401825 */ 	or	$v1,$v0,$zero
.L0f174200:
/*  f174200:	00001825 */ 	or	$v1,$zero,$zero
.L0f174204:
/*  f174204:	14820007 */ 	bne	$a0,$v0,.L0f174224
/*  f174208:	00603025 */ 	or	$a2,$v1,$zero
/*  f17420c:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f174210:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f174214:	05e20004 */ 	bltzl	$t7,.L0f174228
/*  f174218:	00001825 */ 	or	$v1,$zero,$zero
/*  f17421c:	10000002 */ 	beqz	$zero,.L0f174228
/*  f174220:	00401825 */ 	or	$v1,$v0,$zero
.L0f174224:
/*  f174224:	00001825 */ 	or	$v1,$zero,$zero
.L0f174228:
/*  f174228:	92380008 */ 	lbu	$t8,0x8($s1)
/*  f17422c:	270effff */ 	addiu	$t6,$t8,-1
/*  f174230:	000e4880 */ 	sll	$t1,$t6,0x2
/*  f174234:	14820007 */ 	bne	$a0,$v0,.L0f174254
/*  f174238:	00693821 */ 	addu	$a3,$v1,$t1
/*  f17423c:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f174240:	00194080 */ 	sll	$t0,$t9,0x2
/*  f174244:	05020004 */ 	bltzl	$t0,.L0f174258
/*  f174248:	00001825 */ 	or	$v1,$zero,$zero
/*  f17424c:	10000002 */ 	beqz	$zero,.L0f174258
/*  f174250:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f174254:
/*  f174254:	00001825 */ 	or	$v1,$zero,$zero
.L0f174258:
/*  f174258:	922a0009 */ 	lbu	$t2,0x9($s1)
/*  f17425c:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f174260:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f174264:	254dffff */ 	addiu	$t5,$t2,-1
/*  f174268:	000d5880 */ 	sll	$t3,$t5,0x2
/*  f17426c:	006b8021 */ 	addu	$s0,$v1,$t3
/*  f174270:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f174274:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f174278:	0fc5cee3 */ 	jal	func0f173b8c
/*  f17427c:	00002025 */ 	or	$a0,$zero,$zero
/*  f174280:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f174284:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f174288:	1040000f */ 	beqz	$v0,.L0f1742c8
/*  f17428c:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f174290:	30af0fff */ 	andi	$t7,$a1,0xfff
/*  f174294:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f174298:	02401025 */ 	or	$v0,$s2,$zero
/*  f17429c:	3c01f200 */ 	lui	$at,0xf200
/*  f1742a0:	30ec0fff */ 	andi	$t4,$a3,0xfff
/*  f1742a4:	000c4300 */ 	sll	$t0,$t4,0xc
/*  f1742a8:	03017025 */ 	or	$t6,$t8,$at
/*  f1742ac:	30c90fff */ 	andi	$t1,$a2,0xfff
/*  f1742b0:	320a0fff */ 	andi	$t2,$s0,0xfff
/*  f1742b4:	010a6825 */ 	or	$t5,$t0,$t2
/*  f1742b8:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f1742bc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1742c0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1742c4:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f1742c8:
/*  f1742c8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1742cc:	02401025 */ 	or	$v0,$s2,$zero
/*  f1742d0:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1742d4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1742d8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1742dc:	03e00008 */ 	jr	$ra
/*  f1742e0:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1742e4
/*  f1742e4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f1742e8:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f1742ec:	90c2000b */ 	lbu	$v0,0xb($a2)
/*  f1742f0:	00808025 */ 	or	$s0,$a0,$zero
/*  f1742f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1742f8:	00027142 */ 	srl	$t6,$v0,0x5
/*  f1742fc:	11c00003 */ 	beqz	$t6,.L0f17430c
/*  f174300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174304:	10000001 */ 	beqz	$zero,.L0f17430c
/*  f174308:	25c3ffff */ 	addiu	$v1,$t6,-1
.L0f17430c:
/*  f17430c:	50e0001a */ 	beqzl	$a3,.L0f174378
/*  f174310:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f174314:	10a0000d */ 	beqz	$a1,.L0f17434c
/*  f174318:	02001025 */ 	or	$v0,$s0,$zero
/*  f17431c:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f174320:	2401c7ff */ 	addiu	$at,$zero,-14337
/*  f174324:	0003c2c0 */ 	sll	$t8,$v1,0xb
/*  f174328:	00817824 */ 	and	$t7,$a0,$at
/*  f17432c:	01f81025 */ 	or	$v0,$t7,$t8
/*  f174330:	50440018 */ 	beql	$v0,$a0,.L0f174394
/*  f174334:	02001025 */ 	or	$v0,$s0,$zero
/*  f174338:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f17433c:	8cb90004 */ 	lw	$t9,0x4($a1)
/*  f174340:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174344:	10000012 */ 	beqz	$zero,.L0f174390
/*  f174348:	ae19fffc */ 	sw	$t9,-0x4($s0)
.L0f17434c:
/*  f17434c:	30680007 */ 	andi	$t0,$v1,0x7
/*  f174350:	00084ac0 */ 	sll	$t1,$t0,0xb
/*  f174354:	3c01bb00 */ 	lui	$at,0xbb00
/*  f174358:	01215025 */ 	or	$t2,$t1,$at
/*  f17435c:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f174360:	240cffff */ 	addiu	$t4,$zero,-1
/*  f174364:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f174368:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f17436c:	10000008 */ 	beqz	$zero,.L0f174390
/*  f174370:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174374:	8cad0000 */ 	lw	$t5,0x0($a1)
.L0f174378:
/*  f174378:	2401c7ff */ 	addiu	$at,$zero,-14337
/*  f17437c:	0003c2c0 */ 	sll	$t8,$v1,0xb
/*  f174380:	01a17024 */ 	and	$t6,$t5,$at
/*  f174384:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f174388:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f17438c:	acb90000 */ 	sw	$t9,0x0($a1)
.L0f174390:
/*  f174390:	02001025 */ 	or	$v0,$s0,$zero
.L0f174394:
/*  f174394:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f174398:	03e00008 */ 	jr	$ra
/*  f17439c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f1743a0
/*  f1743a0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f1743a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1743a8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1743ac:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1743b0:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f1743b4:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1743b8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1743bc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1743c0:	0fc5cf94 */ 	jal	func0f173e50
/*  f1743c4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1743c8:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f1743cc:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f1743d0:	3c01fd00 */ 	lui	$at,0xfd00
/*  f1743d4:	8d2e000c */ 	lw	$t6,0xc($t1)
/*  f1743d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1743dc:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f1743e0:	000e7f82 */ 	srl	$t7,$t6,0x1e
/*  f1743e4:	15e00065 */ 	bnez	$t7,.L0f17457c
/*  f1743e8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f1743ec:	8d380008 */ 	lw	$t8,0x8($t1)
/*  f1743f0:	31cf0003 */ 	andi	$t7,$t6,0x3
/*  f1743f4:	02001025 */ 	or	$v0,$s0,$zero
/*  f1743f8:	0018cec0 */ 	sll	$t9,$t8,0x1b
/*  f1743fc:	00195742 */ 	srl	$t2,$t9,0x1d
/*  f174400:	314b0007 */ 	andi	$t3,$t2,0x7
/*  f174404:	000b6540 */ 	sll	$t4,$t3,0x15
/*  f174408:	01816825 */ 	or	$t5,$t4,$at
/*  f17440c:	000fc4c0 */ 	sll	$t8,$t7,0x13
/*  f174410:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f174414:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f174418:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f17441c:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f174420:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f174424:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f174428:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f17442c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174430:	02001025 */ 	or	$v0,$s0,$zero
/*  f174434:	15600006 */ 	bnez	$t3,.L0f174450
/*  f174438:	3c0ce700 */ 	lui	$t4,0xe700
/*  f17443c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f174440:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174444:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f174448:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17444c:	ac6e0000 */ 	sw	$t6,0x0($v1)
.L0f174450:
/*  f174450:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f174454:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174458:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f17445c:	14c10019 */ 	bne	$a2,$at,.L0f1744c4
/*  f174460:	00002825 */ 	or	$a1,$zero,$zero
/*  f174464:	15000017 */ 	bnez	$t0,.L0f1744c4
/*  f174468:	3c07e600 */ 	lui	$a3,0xe600
/*  f17446c:	02001825 */ 	or	$v1,$s0,$zero
/*  f174470:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174474:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174478:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17447c:	02002025 */ 	or	$a0,$s0,$zero
/*  f174480:	3c0ff300 */ 	lui	$t7,0xf300
/*  f174484:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f174488:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f17448c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174490:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174494:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174498:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f17449c:	10200003 */ 	beqz	$at,.L0f1744ac
/*  f1744a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1744a4:	10000001 */ 	beqz	$zero,.L0f1744ac
/*  f1744a8:	00401825 */ 	or	$v1,$v0,$zero
.L0f1744ac:
/*  f1744ac:	306d0fff */ 	andi	$t5,$v1,0xfff
/*  f1744b0:	000dc300 */ 	sll	$t8,$t5,0xc
/*  f1744b4:	3c010700 */ 	lui	$at,0x700
/*  f1744b8:	0301c825 */ 	or	$t9,$t8,$at
/*  f1744bc:	100000b4 */ 	beqz	$zero,.L0f174790
/*  f1744c0:	ac990004 */ 	sw	$t9,0x4($a0)
.L0f1744c4:
/*  f1744c4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1744c8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1744cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1744d0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1744d4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1744d8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1744dc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1744e0:	0fc5ce9c */ 	jal	func0f173a70
/*  f1744e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1744e8:	1040000d */ 	beqz	$v0,.L0f174520
/*  f1744ec:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f1744f0:	8faa0094 */ 	lw	$t2,0x94($sp)
/*  f1744f4:	02001025 */ 	or	$v0,$s0,$zero
/*  f1744f8:	3c01f500 */ 	lui	$at,0xf500
/*  f1744fc:	314b0003 */ 	andi	$t3,$t2,0x3
/*  f174500:	000b64c0 */ 	sll	$t4,$t3,0x13
/*  f174504:	01817025 */ 	or	$t6,$t4,$at
/*  f174508:	310f01ff */ 	andi	$t7,$t0,0x1ff
/*  f17450c:	01cf6825 */ 	or	$t5,$t6,$t7
/*  f174510:	3c180500 */ 	lui	$t8,0x500
/*  f174514:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f174518:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f17451c:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174520:
/*  f174520:	02001825 */ 	or	$v1,$s0,$zero
/*  f174524:	3c07e600 */ 	lui	$a3,0xe600
/*  f174528:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17452c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174530:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174534:	02002025 */ 	or	$a0,$s0,$zero
/*  f174538:	3c19f300 */ 	lui	$t9,0xf300
/*  f17453c:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f174540:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174544:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174548:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f17454c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174550:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174554:	10200003 */ 	beqz	$at,.L0f174564
/*  f174558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17455c:	10000001 */ 	beqz	$zero,.L0f174564
/*  f174560:	00401825 */ 	or	$v1,$v0,$zero
.L0f174564:
/*  f174564:	306a0fff */ 	andi	$t2,$v1,0xfff
/*  f174568:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f17456c:	3c010500 */ 	lui	$at,0x500
/*  f174570:	01616025 */ 	or	$t4,$t3,$at
/*  f174574:	10000086 */ 	beqz	$zero,.L0f174790
/*  f174578:	ac8c0004 */ 	sw	$t4,0x4($a0)
.L0f17457c:
/*  f17457c:	8d2e0008 */ 	lw	$t6,0x8($t1)
/*  f174580:	3c01fd00 */ 	lui	$at,0xfd00
/*  f174584:	316c0003 */ 	andi	$t4,$t3,0x3
/*  f174588:	000e7ec0 */ 	sll	$t7,$t6,0x1b
/*  f17458c:	000f6f42 */ 	srl	$t5,$t7,0x1d
/*  f174590:	31b80007 */ 	andi	$t8,$t5,0x7
/*  f174594:	0018cd40 */ 	sll	$t9,$t8,0x15
/*  f174598:	03215025 */ 	or	$t2,$t9,$at
/*  f17459c:	000c74c0 */ 	sll	$t6,$t4,0x13
/*  f1745a0:	014e7825 */ 	or	$t7,$t2,$t6
/*  f1745a4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1745a8:	8d2d0004 */ 	lw	$t5,0x4($t1)
/*  f1745ac:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f1745b0:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f1745b4:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1745b8:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f1745bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1745c0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1745c4:	17000006 */ 	bnez	$t8,.L0f1745e0
/*  f1745c8:	3c19e700 */ 	lui	$t9,0xe700
/*  f1745cc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1745d0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1745d4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1745d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1745dc:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f1745e0:
/*  f1745e0:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f1745e4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1745e8:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f1745ec:	14c10019 */ 	bne	$a2,$at,.L0f174654
/*  f1745f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1745f4:	15000017 */ 	bnez	$t0,.L0f174654
/*  f1745f8:	3c07e600 */ 	lui	$a3,0xe600
/*  f1745fc:	02001825 */ 	or	$v1,$s0,$zero
/*  f174600:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174604:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174608:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17460c:	02002025 */ 	or	$a0,$s0,$zero
/*  f174610:	3c0cf300 */ 	lui	$t4,0xf300
/*  f174614:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f174618:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f17461c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174620:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174624:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174628:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f17462c:	10200003 */ 	beqz	$at,.L0f17463c
/*  f174630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174634:	10000001 */ 	beqz	$zero,.L0f17463c
/*  f174638:	00401825 */ 	or	$v1,$v0,$zero
.L0f17463c:
/*  f17463c:	306a0fff */ 	andi	$t2,$v1,0xfff
/*  f174640:	000a7300 */ 	sll	$t6,$t2,0xc
/*  f174644:	3c010700 */ 	lui	$at,0x700
/*  f174648:	01c17825 */ 	or	$t7,$t6,$at
/*  f17464c:	1000002f */ 	beqz	$zero,.L0f17470c
/*  f174650:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174654:
/*  f174654:	00003825 */ 	or	$a3,$zero,$zero
/*  f174658:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f17465c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174660:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f174664:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f174668:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f17466c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174670:	0fc5ce9c */ 	jal	func0f173a70
/*  f174674:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174678:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f17467c:	1040000d */ 	beqz	$v0,.L0f1746b4
/*  f174680:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f174684:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f174688:	02001025 */ 	or	$v0,$s0,$zero
/*  f17468c:	3c01f500 */ 	lui	$at,0xf500
/*  f174690:	31b80003 */ 	andi	$t8,$t5,0x3
/*  f174694:	0018ccc0 */ 	sll	$t9,$t8,0x13
/*  f174698:	03215825 */ 	or	$t3,$t9,$at
/*  f17469c:	310c01ff */ 	andi	$t4,$t0,0x1ff
/*  f1746a0:	016c5025 */ 	or	$t2,$t3,$t4
/*  f1746a4:	3c0e0500 */ 	lui	$t6,0x500
/*  f1746a8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1746ac:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1746b0:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f1746b4:
/*  f1746b4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1746b8:	3c07e600 */ 	lui	$a3,0xe600
/*  f1746bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1746c0:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f1746c4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1746c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1746cc:	3c0ff300 */ 	lui	$t7,0xf300
/*  f1746d0:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1746d4:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f1746d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1746dc:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f1746e0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f1746e4:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f1746e8:	10200003 */ 	beqz	$at,.L0f1746f8
/*  f1746ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1746f0:	10000001 */ 	beqz	$zero,.L0f1746f8
/*  f1746f4:	00401825 */ 	or	$v1,$v0,$zero
.L0f1746f8:
/*  f1746f8:	306d0fff */ 	andi	$t5,$v1,0xfff
/*  f1746fc:	000dc300 */ 	sll	$t8,$t5,0xc
/*  f174700:	3c010500 */ 	lui	$at,0x500
/*  f174704:	0301c825 */ 	or	$t9,$t8,$at
/*  f174708:	ac990004 */ 	sw	$t9,0x4($a0)
.L0f17470c:
/*  f17470c:	912b000a */ 	lbu	$t3,0xa($t1)
/*  f174710:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f174714:	240c03ff */ 	addiu	$t4,$zero,0x3ff
/*  f174718:	018b1023 */ 	subu	$v0,$t4,$t3
/*  f17471c:	0045082b */ 	sltu	$at,$v0,$a1
/*  f174720:	10200003 */ 	beqz	$at,.L0f174730
/*  f174724:	00003025 */ 	or	$a2,$zero,$zero
/*  f174728:	10000001 */ 	beqz	$zero,.L0f174730
/*  f17472c:	00403025 */ 	or	$a2,$v0,$zero
.L0f174730:
/*  f174730:	00a62823 */ 	subu	$a1,$a1,$a2
/*  f174734:	02001025 */ 	or	$v0,$s0,$zero
/*  f174738:	30af03ff */ 	andi	$t7,$a1,0x3ff
/*  f17473c:	000f6b80 */ 	sll	$t5,$t7,0xe
/*  f174740:	30c403ff */ 	andi	$a0,$a2,0x3ff
/*  f174744:	3c01f000 */ 	lui	$at,0xf000
/*  f174748:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17474c:	01a1c025 */ 	or	$t8,$t5,$at
/*  f174750:	00047080 */ 	sll	$t6,$a0,0x2
/*  f174754:	ac470000 */ 	sw	$a3,0x0($v0)
/*  f174758:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17475c:	030ec825 */ 	or	$t9,$t8,$t6
/*  f174760:	02001825 */ 	or	$v1,$s0,$zero
/*  f174764:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f174768:	912c000a */ 	lbu	$t4,0xa($t1)
/*  f17476c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f174770:	3c010600 */ 	lui	$at,0x600
/*  f174774:	01855821 */ 	addu	$t3,$t4,$a1
/*  f174778:	316a03ff */ 	andi	$t2,$t3,0x3ff
/*  f17477c:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f174780:	01c17825 */ 	or	$t7,$t6,$at
/*  f174784:	01e46825 */ 	or	$t5,$t7,$a0
/*  f174788:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f17478c:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174790:
/*  f174790:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f174794:	02001025 */ 	or	$v0,$s0,$zero
/*  f174798:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f17479c:	03e00008 */ 	jr	$ra
/*  f1747a0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f1747a4
/*  f1747a4:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f1747a8:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f1747ac:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f1747b0:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f1747b4:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f1747b8:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f1747bc:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f1747c0:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1747c4:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1747c8:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1747cc:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1747d0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1747d4:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f1747d8:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f1747dc:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f1747e0:	90a2000b */ 	lbu	$v0,0xb($a1)
/*  f1747e4:	8fb000d0 */ 	lw	$s0,0xd0($sp)
/*  f1747e8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f1747ec:	00027942 */ 	srl	$t7,$v0,0x5
/*  f1747f0:	0080b025 */ 	or	$s6,$a0,$zero
/*  f1747f4:	06000005 */ 	bltz	$s0,.L0f17480c
/*  f1747f8:	01e01025 */ 	or	$v0,$t7,$zero
/*  f1747fc:	020f082a */ 	slt	$at,$s0,$t7
/*  f174800:	50200003 */ 	beqzl	$at,.L0f174810
/*  f174804:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f174808:	02001025 */ 	or	$v0,$s0,$zero
.L0f17480c:
/*  f17480c:	8fa300cc */ 	lw	$v1,0xcc($sp)
.L0f174810:
/*  f174810:	00433021 */ 	addu	$a2,$v0,$v1
/*  f174814:	0066082a */ 	slt	$at,$v1,$a2
/*  f174818:	102000c1 */ 	beqz	$at,.L0f174b20
/*  f17481c:	0060f025 */ 	or	$s8,$v1,$zero
/*  f174820:	28610006 */ 	slti	$at,$v1,0x6
/*  f174824:	102000be */ 	beqz	$at,.L0f174b20
/*  f174828:	00639023 */ 	subu	$s2,$v1,$v1
/*  f17482c:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f174830:	02a02025 */ 	or	$a0,$s5,$zero
.L0f174834:
/*  f174834:	0fc5cf04 */ 	jal	func0f173c10
/*  f174838:	02402825 */ 	or	$a1,$s2,$zero
/*  f17483c:	0fc5cfc6 */ 	jal	func0f173f18
/*  f174840:	00402025 */ 	or	$a0,$v0,$zero
/*  f174844:	00409825 */ 	or	$s3,$v0,$zero
/*  f174848:	02a02025 */ 	or	$a0,$s5,$zero
/*  f17484c:	0fc5cf2e */ 	jal	func0f173cb8
/*  f174850:	02402825 */ 	or	$a1,$s2,$zero
/*  f174854:	0fc5cfc6 */ 	jal	func0f173f18
/*  f174858:	00402025 */ 	or	$a0,$v0,$zero
/*  f17485c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f174860:	02a02025 */ 	or	$a0,$s5,$zero
/*  f174864:	0fc5cf58 */ 	jal	func0f173d60
/*  f174868:	02402825 */ 	or	$a1,$s2,$zero
/*  f17486c:	00408025 */ 	or	$s0,$v0,$zero
/*  f174870:	02a02025 */ 	or	$a0,$s5,$zero
/*  f174874:	0fc5cf84 */ 	jal	func0f173e10
/*  f174878:	02402825 */ 	or	$a1,$s2,$zero
/*  f17487c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f174880:	8ea3000c */ 	lw	$v1,0xc($s5)
/*  f174884:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f174888:	00032782 */ 	srl	$a0,$v1,0x1e
/*  f17488c:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f174890:	00044380 */ 	sll	$t0,$a0,0xe
/*  f174894:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f174898:	0fc5ce91 */ 	jal	func0f173a44
/*  f17489c:	01002025 */ 	or	$a0,$t0,$zero
/*  f1748a0:	1040000a */ 	beqz	$v0,.L0f1748cc
/*  f1748a4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1748a8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1748ac:	35290e02 */ 	ori	$t1,$t1,0xe02
/*  f1748b0:	02c01025 */ 	or	$v0,$s6,$zero
/*  f1748b4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1748b8:	8eaa000c */ 	lw	$t2,0xc($s5)
/*  f1748bc:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f1748c0:	000a5f82 */ 	srl	$t3,$t2,0x1e
/*  f1748c4:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f1748c8:	ac4c0004 */ 	sw	$t4,0x4($v0)
.L0f1748cc:
/*  f1748cc:	8ea20008 */ 	lw	$v0,0x8($s5)
/*  f1748d0:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1748d4:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1748d8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f1748dc:	00022ec0 */ 	sll	$a1,$v0,0x1b
/*  f1748e0:	00056f42 */ 	srl	$t5,$a1,0x1d
/*  f1748e4:	01a02825 */ 	or	$a1,$t5,$zero
/*  f1748e8:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1748ec:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f1748f0:	afb40020 */ 	sw	$s4,0x20($sp)
/*  f1748f4:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f1748f8:	02003825 */ 	or	$a3,$s0,$zero
/*  f1748fc:	30460003 */ 	andi	$a2,$v0,0x3
/*  f174900:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f174904:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f174908:	0fc5ce9c */ 	jal	func0f173a70
/*  f17490c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f174910:	1040002c */ 	beqz	$v0,.L0f1749c4
/*  f174914:	02c08825 */ 	or	$s1,$s6,$zero
/*  f174918:	8eac0008 */ 	lw	$t4,0x8($s5)
/*  f17491c:	3c01f500 */ 	lui	$at,0xf500
/*  f174920:	321801ff */ 	andi	$t8,$s0,0x1ff
/*  f174924:	000ccec0 */ 	sll	$t9,$t4,0x1b
/*  f174928:	00194742 */ 	srl	$t0,$t9,0x1d
/*  f17492c:	31090007 */ 	andi	$t1,$t0,0x7
/*  f174930:	00095540 */ 	sll	$t2,$t1,0x15
/*  f174934:	8fa900b4 */ 	lw	$t1,0xb4($sp)
/*  f174938:	318d0003 */ 	andi	$t5,$t4,0x3
/*  f17493c:	000d74c0 */ 	sll	$t6,$t5,0x13
/*  f174940:	01415825 */ 	or	$t3,$t2,$at
/*  f174944:	016e7825 */ 	or	$t7,$t3,$t6
/*  f174948:	0018ca40 */ 	sll	$t9,$t8,0x9
/*  f17494c:	01f94025 */ 	or	$t0,$t7,$t9
/*  f174950:	312a01ff */ 	andi	$t2,$t1,0x1ff
/*  f174954:	010a6025 */ 	or	$t4,$t0,$t2
/*  f174958:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f17495c:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*  f174960:	0fc5cfd2 */ 	jal	func0f173f48
/*  f174964:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f174968:	00408025 */ 	or	$s0,$v0,$zero
/*  f17496c:	0fc5cfd2 */ 	jal	func0f173f48
/*  f174970:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f174974:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f174978:	33ce0007 */ 	andi	$t6,$s8,0x7
/*  f17497c:	000ec600 */ 	sll	$t8,$t6,0x18
/*  f174980:	000d5a00 */ 	sll	$t3,$t5,0x8
/*  f174984:	01787825 */ 	or	$t7,$t3,$t8
/*  f174988:	32190003 */ 	andi	$t9,$s0,0x3
/*  f17498c:	00194c80 */ 	sll	$t1,$t9,0x12
/*  f174990:	328a000f */ 	andi	$t2,$s4,0xf
/*  f174994:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f174998:	01e94025 */ 	or	$t0,$t7,$t1
/*  f17499c:	324e000f */ 	andi	$t6,$s2,0xf
/*  f1749a0:	000e5a80 */ 	sll	$t3,$t6,0xa
/*  f1749a4:	010c6825 */ 	or	$t5,$t0,$t4
/*  f1749a8:	3279000f */ 	andi	$t9,$s3,0xf
/*  f1749ac:	00197900 */ 	sll	$t7,$t9,0x4
/*  f1749b0:	01abc025 */ 	or	$t8,$t5,$t3
/*  f1749b4:	030f4825 */ 	or	$t1,$t8,$t7
/*  f1749b8:	324a000f */ 	andi	$t2,$s2,0xf
/*  f1749bc:	012a4025 */ 	or	$t0,$t1,$t2
/*  f1749c0:	ae280004 */ 	sw	$t0,0x4($s1)
.L0f1749c4:
/*  f1749c4:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f1749c8:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f1749cc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1749d0:	14430006 */ 	bne	$v0,$v1,.L0f1749ec
/*  f1749d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f1749d8:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f1749dc:	55800004 */ 	bnezl	$t4,.L0f1749f0
/*  f1749e0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1749e4:	10000002 */ 	beqz	$zero,.L0f1749f0
/*  f1749e8:	00608025 */ 	or	$s0,$v1,$zero
.L0f1749ec:
/*  f1749ec:	00008025 */ 	or	$s0,$zero,$zero
.L0f1749f0:
/*  f1749f0:	14430006 */ 	bne	$v0,$v1,.L0f174a0c
/*  f1749f4:	afb00090 */ 	sw	$s0,0x90($sp)
/*  f1749f8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f1749fc:	55c00004 */ 	bnezl	$t6,.L0f174a10
/*  f174a00:	00008025 */ 	or	$s0,$zero,$zero
/*  f174a04:	10000002 */ 	beqz	$zero,.L0f174a10
/*  f174a08:	00608025 */ 	or	$s0,$v1,$zero
.L0f174a0c:
/*  f174a0c:	00008025 */ 	or	$s0,$zero,$zero
.L0f174a10:
/*  f174a10:	0fc5cf04 */ 	jal	func0f173c10
/*  f174a14:	0200b825 */ 	or	$s7,$s0,$zero
/*  f174a18:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f174a1c:	00409825 */ 	or	$s3,$v0,$zero
/*  f174a20:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174a24:	15a10006 */ 	bne	$t5,$at,.L0f174a40
/*  f174a28:	2679ffff */ 	addiu	$t9,$s3,-1
/*  f174a2c:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f174a30:	55600004 */ 	bnezl	$t3,.L0f174a44
/*  f174a34:	00008025 */ 	or	$s0,$zero,$zero
/*  f174a38:	10000002 */ 	beqz	$zero,.L0f174a44
/*  f174a3c:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f174a40:
/*  f174a40:	00008025 */ 	or	$s0,$zero,$zero
.L0f174a44:
/*  f174a44:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f174a48:	0218a021 */ 	addu	$s4,$s0,$t8
/*  f174a4c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f174a50:	0fc5cf2e */ 	jal	func0f173cb8
/*  f174a54:	02402825 */ 	or	$a1,$s2,$zero
/*  f174a58:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f174a5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174a60:	00409825 */ 	or	$s3,$v0,$zero
/*  f174a64:	15e10006 */ 	bne	$t7,$at,.L0f174a80
/*  f174a68:	03c02025 */ 	or	$a0,$s8,$zero
/*  f174a6c:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f174a70:	55200004 */ 	bnezl	$t1,.L0f174a84
/*  f174a74:	00008025 */ 	or	$s0,$zero,$zero
/*  f174a78:	10000002 */ 	beqz	$zero,.L0f174a84
/*  f174a7c:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f174a80:
/*  f174a80:	00008025 */ 	or	$s0,$zero,$zero
.L0f174a84:
/*  f174a84:	266affff */ 	addiu	$t2,$s3,-1
/*  f174a88:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f174a8c:	02088821 */ 	addu	$s1,$s0,$t0
/*  f174a90:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f174a94:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f174a98:	02e03025 */ 	or	$a2,$s7,$zero
/*  f174a9c:	0fc5cee3 */ 	jal	func0f173b8c
/*  f174aa0:	02803825 */ 	or	$a3,$s4,$zero
/*  f174aa4:	10400013 */ 	beqz	$v0,.L0f174af4
/*  f174aa8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f174aac:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f174ab0:	3c01f200 */ 	lui	$at,0xf200
/*  f174ab4:	33cf0007 */ 	andi	$t7,$s8,0x7
/*  f174ab8:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f174abc:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f174ac0:	328a0fff */ 	andi	$t2,$s4,0xfff
/*  f174ac4:	000a4300 */ 	sll	$t0,$t2,0xc
/*  f174ac8:	01a15825 */ 	or	$t3,$t5,$at
/*  f174acc:	000f4e00 */ 	sll	$t1,$t7,0x18
/*  f174ad0:	02c01025 */ 	or	$v0,$s6,$zero
/*  f174ad4:	01286025 */ 	or	$t4,$t1,$t0
/*  f174ad8:	322e0fff */ 	andi	$t6,$s1,0xfff
/*  f174adc:	32f90fff */ 	andi	$t9,$s7,0xfff
/*  f174ae0:	0179c025 */ 	or	$t8,$t3,$t9
/*  f174ae4:	018e6825 */ 	or	$t5,$t4,$t6
/*  f174ae8:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f174aec:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f174af0:	26d60008 */ 	addiu	$s6,$s6,0x8
.L0f174af4:
/*  f174af4:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f174af8:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f174afc:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f174b00:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f174b04:	03cf082a */ 	slt	$at,$s8,$t7
/*  f174b08:	0179c021 */ 	addu	$t8,$t3,$t9
/*  f174b0c:	10200004 */ 	beqz	$at,.L0f174b20
/*  f174b10:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f174b14:	2bc10006 */ 	slti	$at,$s8,0x6
/*  f174b18:	5420ff46 */ 	bnezl	$at,.L0f174834
/*  f174b1c:	02a02025 */ 	or	$a0,$s5,$zero
.L0f174b20:
/*  f174b20:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f174b24:	02c01025 */ 	or	$v0,$s6,$zero
/*  f174b28:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f174b2c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f174b30:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f174b34:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f174b38:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f174b3c:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f174b40:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f174b44:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f174b48:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f174b4c:	03e00008 */ 	jr	$ra
/*  f174b50:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func0f174b54
/*  f174b54:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f174b58:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f174b5c:	00808025 */ 	or	$s0,$a0,$zero
/*  f174b60:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f174b64:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f174b68:	00a02025 */ 	or	$a0,$a1,$zero
/*  f174b6c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f174b70:	0fc5cf94 */ 	jal	func0f173e50
/*  f174b74:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f174b78:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f174b7c:	3c01fd00 */ 	lui	$at,0xfd00
/*  f174b80:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f174b84:	8d0e000c */ 	lw	$t6,0xc($t0)
/*  f174b88:	02001025 */ 	or	$v0,$s0,$zero
/*  f174b8c:	000e7f82 */ 	srl	$t7,$t6,0x1e
/*  f174b90:	15e00061 */ 	bnez	$t7,.L0f174d18
/*  f174b94:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f174b98:	8d180008 */ 	lw	$t8,0x8($t0)
/*  f174b9c:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f174ba0:	000e7cc0 */ 	sll	$t7,$t6,0x13
/*  f174ba4:	0018cec0 */ 	sll	$t9,$t8,0x1b
/*  f174ba8:	00194f42 */ 	srl	$t1,$t9,0x1d
/*  f174bac:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f174bb0:	000a5d40 */ 	sll	$t3,$t2,0x15
/*  f174bb4:	01616025 */ 	or	$t4,$t3,$at
/*  f174bb8:	018fc025 */ 	or	$t8,$t4,$t7
/*  f174bbc:	02001025 */ 	or	$v0,$s0,$zero
/*  f174bc0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f174bc4:	8d190004 */ 	lw	$t9,0x4($t0)
/*  f174bc8:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f174bcc:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f174bd0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f174bd4:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f174bd8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174bdc:	02001025 */ 	or	$v0,$s0,$zero
/*  f174be0:	15200006 */ 	bnez	$t1,.L0f174bfc
/*  f174be4:	3c0ae700 */ 	lui	$t2,0xe700
/*  f174be8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174bec:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174bf0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f174bf4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174bf8:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f174bfc:
/*  f174bfc:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f174c00:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174c04:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f174c08:	14c10018 */ 	bne	$a2,$at,.L0f174c6c
/*  f174c0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f174c10:	02001825 */ 	or	$v1,$s0,$zero
/*  f174c14:	3c07e600 */ 	lui	$a3,0xe600
/*  f174c18:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174c1c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174c20:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174c24:	02002025 */ 	or	$a0,$s0,$zero
/*  f174c28:	3c0df300 */ 	lui	$t5,0xf300
/*  f174c2c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f174c30:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174c34:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174c38:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174c3c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174c40:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174c44:	10200003 */ 	beqz	$at,.L0f174c54
/*  f174c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174c4c:	10000001 */ 	beqz	$zero,.L0f174c54
/*  f174c50:	00401825 */ 	or	$v1,$v0,$zero
.L0f174c54:
/*  f174c54:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f174c58:	000e6300 */ 	sll	$t4,$t6,0xc
/*  f174c5c:	3c010700 */ 	lui	$at,0x700
/*  f174c60:	01817825 */ 	or	$t7,$t4,$at
/*  f174c64:	100000ad */ 	beqz	$zero,.L0f174f1c
/*  f174c68:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174c6c:
/*  f174c6c:	00003825 */ 	or	$a3,$zero,$zero
/*  f174c70:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f174c74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174c78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f174c7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f174c80:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f174c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174c88:	0fc5ce9c */ 	jal	func0f173a70
/*  f174c8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174c90:	1040000b */ 	beqz	$v0,.L0f174cc0
/*  f174c94:	3c07e600 */ 	lui	$a3,0xe600
/*  f174c98:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f174c9c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174ca0:	3c01f500 */ 	lui	$at,0xf500
/*  f174ca4:	33190003 */ 	andi	$t9,$t8,0x3
/*  f174ca8:	00194cc0 */ 	sll	$t1,$t9,0x13
/*  f174cac:	01215025 */ 	or	$t2,$t1,$at
/*  f174cb0:	3c0b0500 */ 	lui	$t3,0x500
/*  f174cb4:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f174cb8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174cbc:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174cc0:
/*  f174cc0:	02001825 */ 	or	$v1,$s0,$zero
/*  f174cc4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174cc8:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174ccc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f174cd4:	3c0df300 */ 	lui	$t5,0xf300
/*  f174cd8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f174cdc:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174ce0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174ce4:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174ce8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174cec:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174cf0:	10200003 */ 	beqz	$at,.L0f174d00
/*  f174cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174cf8:	10000001 */ 	beqz	$zero,.L0f174d00
/*  f174cfc:	00401825 */ 	or	$v1,$v0,$zero
.L0f174d00:
/*  f174d00:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f174d04:	000e6300 */ 	sll	$t4,$t6,0xc
/*  f174d08:	3c010500 */ 	lui	$at,0x500
/*  f174d0c:	01817825 */ 	or	$t7,$t4,$at
/*  f174d10:	10000082 */ 	beqz	$zero,.L0f174f1c
/*  f174d14:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174d18:
/*  f174d18:	8d180008 */ 	lw	$t8,0x8($t0)
/*  f174d1c:	3c01fd00 */ 	lui	$at,0xfd00
/*  f174d20:	31cc0003 */ 	andi	$t4,$t6,0x3
/*  f174d24:	0018cec0 */ 	sll	$t9,$t8,0x1b
/*  f174d28:	00194f42 */ 	srl	$t1,$t9,0x1d
/*  f174d2c:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f174d30:	000a5d40 */ 	sll	$t3,$t2,0x15
/*  f174d34:	01616825 */ 	or	$t5,$t3,$at
/*  f174d38:	000c7cc0 */ 	sll	$t7,$t4,0x13
/*  f174d3c:	01afc025 */ 	or	$t8,$t5,$t7
/*  f174d40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f174d44:	8d190004 */ 	lw	$t9,0x4($t0)
/*  f174d48:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f174d4c:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f174d50:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f174d54:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f174d58:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d5c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174d60:	15200006 */ 	bnez	$t1,.L0f174d7c
/*  f174d64:	3c0ae700 */ 	lui	$t2,0xe700
/*  f174d68:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174d6c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174d70:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f174d74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d78:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f174d7c:
/*  f174d7c:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f174d80:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174d84:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f174d88:	14c10018 */ 	bne	$a2,$at,.L0f174dec
/*  f174d8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f174d90:	02001825 */ 	or	$v1,$s0,$zero
/*  f174d94:	3c07e600 */ 	lui	$a3,0xe600
/*  f174d98:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d9c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174da0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174da4:	02002025 */ 	or	$a0,$s0,$zero
/*  f174da8:	3c0ef300 */ 	lui	$t6,0xf300
/*  f174dac:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f174db0:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174db4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174db8:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174dbc:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174dc0:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174dc4:	10200003 */ 	beqz	$at,.L0f174dd4
/*  f174dc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174dcc:	10000001 */ 	beqz	$zero,.L0f174dd4
/*  f174dd0:	00401825 */ 	or	$v1,$v0,$zero
.L0f174dd4:
/*  f174dd4:	306c0fff */ 	andi	$t4,$v1,0xfff
/*  f174dd8:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f174ddc:	3c010700 */ 	lui	$at,0x700
/*  f174de0:	01a17825 */ 	or	$t7,$t5,$at
/*  f174de4:	1000002c */ 	beqz	$zero,.L0f174e98
/*  f174de8:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174dec:
/*  f174dec:	00003825 */ 	or	$a3,$zero,$zero
/*  f174df0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f174df4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174df8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f174dfc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f174e00:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f174e04:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174e08:	0fc5ce9c */ 	jal	func0f173a70
/*  f174e0c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174e10:	1040000b */ 	beqz	$v0,.L0f174e40
/*  f174e14:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f174e18:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f174e1c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174e20:	3c01f500 */ 	lui	$at,0xf500
/*  f174e24:	33190003 */ 	andi	$t9,$t8,0x3
/*  f174e28:	00194cc0 */ 	sll	$t1,$t9,0x13
/*  f174e2c:	01215025 */ 	or	$t2,$t1,$at
/*  f174e30:	3c0b0500 */ 	lui	$t3,0x500
/*  f174e34:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f174e38:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174e3c:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174e40:
/*  f174e40:	02001825 */ 	or	$v1,$s0,$zero
/*  f174e44:	3c07e600 */ 	lui	$a3,0xe600
/*  f174e48:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174e4c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174e50:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174e54:	02002025 */ 	or	$a0,$s0,$zero
/*  f174e58:	3c0ef300 */ 	lui	$t6,0xf300
/*  f174e5c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f174e60:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174e64:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174e68:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174e6c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174e70:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174e74:	10200003 */ 	beqz	$at,.L0f174e84
/*  f174e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f174e7c:	10000001 */ 	beqz	$zero,.L0f174e84
/*  f174e80:	00401825 */ 	or	$v1,$v0,$zero
.L0f174e84:
/*  f174e84:	306c0fff */ 	andi	$t4,$v1,0xfff
/*  f174e88:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f174e8c:	3c010500 */ 	lui	$at,0x500
/*  f174e90:	01a17825 */ 	or	$t7,$t5,$at
/*  f174e94:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174e98:
/*  f174e98:	9118000a */ 	lbu	$t8,0xa($t0)
/*  f174e9c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f174ea0:	241903ff */ 	addiu	$t9,$zero,0x3ff
/*  f174ea4:	03381023 */ 	subu	$v0,$t9,$t8
/*  f174ea8:	0045082b */ 	sltu	$at,$v0,$a1
/*  f174eac:	10200003 */ 	beqz	$at,.L0f174ebc
/*  f174eb0:	00003025 */ 	or	$a2,$zero,$zero
/*  f174eb4:	10000001 */ 	beqz	$zero,.L0f174ebc
/*  f174eb8:	00403025 */ 	or	$a2,$v0,$zero
.L0f174ebc:
/*  f174ebc:	00a62823 */ 	subu	$a1,$a1,$a2
/*  f174ec0:	02001025 */ 	or	$v0,$s0,$zero
/*  f174ec4:	30ab03ff */ 	andi	$t3,$a1,0x3ff
/*  f174ec8:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f174ecc:	30c403ff */ 	andi	$a0,$a2,0x3ff
/*  f174ed0:	3c01f000 */ 	lui	$at,0xf000
/*  f174ed4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174ed8:	01c16025 */ 	or	$t4,$t6,$at
/*  f174edc:	00045080 */ 	sll	$t2,$a0,0x2
/*  f174ee0:	ac470000 */ 	sw	$a3,0x0($v0)
/*  f174ee4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174ee8:	018a6825 */ 	or	$t5,$t4,$t2
/*  f174eec:	02001825 */ 	or	$v1,$s0,$zero
/*  f174ef0:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f174ef4:	910f000a */ 	lbu	$t7,0xa($t0)
/*  f174ef8:	01402025 */ 	or	$a0,$t2,$zero
/*  f174efc:	3c010600 */ 	lui	$at,0x600
/*  f174f00:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f174f04:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f174f08:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f174f0c:	01215025 */ 	or	$t2,$t1,$at
/*  f174f10:	01445825 */ 	or	$t3,$t2,$a0
/*  f174f14:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f174f18:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174f1c:
/*  f174f1c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f174f20:	02001025 */ 	or	$v0,$s0,$zero
/*  f174f24:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f174f28:	03e00008 */ 	jr	$ra
/*  f174f2c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f174f30
/*  f174f30:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f174f34:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f174f38:	00808825 */ 	or	$s1,$a0,$zero
/*  f174f3c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f174f40:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f174f44:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f174f48:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f174f4c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f174f50:	0fc5cfc6 */ 	jal	func0f173f18
/*  f174f54:	90a40008 */ 	lbu	$a0,0x8($a1)
/*  f174f58:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f174f5c:	0fc5cfc6 */ 	jal	func0f173f18
/*  f174f60:	92040009 */ 	lbu	$a0,0x9($s0)
/*  f174f64:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f174f68:	02002025 */ 	or	$a0,$s0,$zero
/*  f174f6c:	0fc5cf58 */ 	jal	func0f173d60
/*  f174f70:	00002825 */ 	or	$a1,$zero,$zero
/*  f174f74:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f174f78:	8e03000c */ 	lw	$v1,0xc($s0)
/*  f174f7c:	00037080 */ 	sll	$t6,$v1,0x2
/*  f174f80:	00032782 */ 	srl	$a0,$v1,0x1e
/*  f174f84:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f174f88:	0004c380 */ 	sll	$t8,$a0,0xe
/*  f174f8c:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f174f90:	0fc5ce91 */ 	jal	func0f173a44
/*  f174f94:	03002025 */ 	or	$a0,$t8,$zero
/*  f174f98:	10400009 */ 	beqz	$v0,.L0f174fc0
/*  f174f9c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f174fa0:	02201025 */ 	or	$v0,$s1,$zero
/*  f174fa4:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f174fa8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f174fac:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f174fb0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f174fb4:	00095782 */ 	srl	$t2,$t1,0x1e
/*  f174fb8:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f174fbc:	ac4b0004 */ 	sw	$t3,0x4($v0)
.L0f174fc0:
/*  f174fc0:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f174fc4:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f174fc8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f174fcc:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f174fd0:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f174fd4:	00022ec0 */ 	sll	$a1,$v0,0x1b
/*  f174fd8:	00056742 */ 	srl	$t4,$a1,0x1d
/*  f174fdc:	01802825 */ 	or	$a1,$t4,$zero
/*  f174fe0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174fe4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174fe8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f174fec:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f174ff0:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f174ff4:	30460003 */ 	andi	$a2,$v0,0x3
/*  f174ff8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f174ffc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f175000:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f175004:	0fc5ce9c */ 	jal	func0f173a70
/*  f175008:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f17500c:	1040002b */ 	beqz	$v0,.L0f1750bc
/*  f175010:	02201825 */ 	or	$v1,$s1,$zero
/*  f175014:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f175018:	3c01f500 */ 	lui	$at,0xf500
/*  f17501c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f175020:	000dcec0 */ 	sll	$t9,$t5,0x1b
/*  f175024:	00194f42 */ 	srl	$t1,$t9,0x1d
/*  f175028:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f17502c:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f175030:	000a5d40 */ 	sll	$t3,$t2,0x15
/*  f175034:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f175038:	000e7cc0 */ 	sll	$t7,$t6,0x13
/*  f17503c:	01616025 */ 	or	$t4,$t3,$at
/*  f175040:	332901ff */ 	andi	$t1,$t9,0x1ff
/*  f175044:	00095240 */ 	sll	$t2,$t1,0x9
/*  f175048:	018fc025 */ 	or	$t8,$t4,$t7
/*  f17504c:	030a5825 */ 	or	$t3,$t8,$t2
/*  f175050:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f175054:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f175058:	0fc5cfd2 */ 	jal	func0f173f48
/*  f17505c:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f175060:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f175064:	0fc5cfd2 */ 	jal	func0f173f48
/*  f175068:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f17506c:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f175070:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f175074:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f175078:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f17507c:	318f0007 */ 	andi	$t7,$t4,0x7
/*  f175080:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f175084:	000fce00 */ 	sll	$t9,$t7,0x18
/*  f175088:	01d94825 */ 	or	$t1,$t6,$t9
/*  f17508c:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f175090:	30780003 */ 	andi	$t8,$v1,0x3
/*  f175094:	00185480 */ 	sll	$t2,$t8,0x12
/*  f175098:	31ac000f */ 	andi	$t4,$t5,0xf
/*  f17509c:	012a5825 */ 	or	$t3,$t1,$t2
/*  f1750a0:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f1750a4:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f1750a8:	3338000f */ 	andi	$t8,$t9,0xf
/*  f1750ac:	00184900 */ 	sll	$t1,$t8,0x4
/*  f1750b0:	016f7025 */ 	or	$t6,$t3,$t7
/*  f1750b4:	01c95025 */ 	or	$t2,$t6,$t1
/*  f1750b8:	adaa0004 */ 	sw	$t2,0x4($t5)
.L0f1750bc:
/*  f1750bc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f1750c0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1750c4:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f1750c8:	14440005 */ 	bne	$v0,$a0,.L0f1750e0
/*  f1750cc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1750d0:	55000004 */ 	bnezl	$t0,.L0f1750e4
/*  f1750d4:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f1750d8:	10000002 */ 	beqz	$zero,.L0f1750e4
/*  f1750dc:	00801825 */ 	or	$v1,$a0,$zero
.L0f1750e0:
/*  f1750e0:	8fa80050 */ 	lw	$t0,0x50($sp)
.L0f1750e4:
/*  f1750e4:	14440005 */ 	bne	$v0,$a0,.L0f1750fc
/*  f1750e8:	00602825 */ 	or	$a1,$v1,$zero
/*  f1750ec:	55000004 */ 	bnezl	$t0,.L0f175100
/*  f1750f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1750f4:	10000002 */ 	beqz	$zero,.L0f175100
/*  f1750f8:	00801825 */ 	or	$v1,$a0,$zero
.L0f1750fc:
/*  f1750fc:	00001825 */ 	or	$v1,$zero,$zero
.L0f175100:
/*  f175100:	14440005 */ 	bne	$v0,$a0,.L0f175118
/*  f175104:	00603025 */ 	or	$a2,$v1,$zero
/*  f175108:	55000004 */ 	bnezl	$t0,.L0f17511c
/*  f17510c:	00001825 */ 	or	$v1,$zero,$zero
/*  f175110:	10000002 */ 	beqz	$zero,.L0f17511c
/*  f175114:	00801825 */ 	or	$v1,$a0,$zero
.L0f175118:
/*  f175118:	00001825 */ 	or	$v1,$zero,$zero
.L0f17511c:
/*  f17511c:	920c0008 */ 	lbu	$t4,0x8($s0)
/*  f175120:	258bffff */ 	addiu	$t3,$t4,-1
/*  f175124:	000b7880 */ 	sll	$t7,$t3,0x2
/*  f175128:	14440005 */ 	bne	$v0,$a0,.L0f175140
/*  f17512c:	006f3821 */ 	addu	$a3,$v1,$t7
/*  f175130:	55000004 */ 	bnezl	$t0,.L0f175144
/*  f175134:	00001825 */ 	or	$v1,$zero,$zero
/*  f175138:	10000002 */ 	beqz	$zero,.L0f175144
/*  f17513c:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f175140:
/*  f175140:	00001825 */ 	or	$v1,$zero,$zero
.L0f175144:
/*  f175144:	92190009 */ 	lbu	$t9,0x9($s0)
/*  f175148:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f17514c:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f175150:	2738ffff */ 	addiu	$t8,$t9,-1
/*  f175154:	00187080 */ 	sll	$t6,$t8,0x2
/*  f175158:	006e4021 */ 	addu	$t0,$v1,$t6
/*  f17515c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f175160:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f175164:	afa50060 */ 	sw	$a1,0x60($sp)
/*  f175168:	0fc5cee3 */ 	jal	func0f173b8c
/*  f17516c:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f175170:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f175174:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f175178:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f17517c:	10400013 */ 	beqz	$v0,.L0f1751cc
/*  f175180:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f175184:	30a90fff */ 	andi	$t1,$a1,0xfff
/*  f175188:	00095300 */ 	sll	$t2,$t1,0xc
/*  f17518c:	3c01f200 */ 	lui	$at,0xf200
/*  f175190:	01416825 */ 	or	$t5,$t2,$at
/*  f175194:	30cc0fff */ 	andi	$t4,$a2,0xfff
/*  f175198:	01ac5825 */ 	or	$t3,$t5,$t4
/*  f17519c:	02201025 */ 	or	$v0,$s1,$zero
/*  f1751a0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f1751a4:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f1751a8:	30ee0fff */ 	andi	$t6,$a3,0xfff
/*  f1751ac:	000e4b00 */ 	sll	$t1,$t6,0xc
/*  f1751b0:	31f90007 */ 	andi	$t9,$t7,0x7
/*  f1751b4:	0019c600 */ 	sll	$t8,$t9,0x18
/*  f1751b8:	03095025 */ 	or	$t2,$t8,$t1
/*  f1751bc:	310d0fff */ 	andi	$t5,$t0,0xfff
/*  f1751c0:	014d6025 */ 	or	$t4,$t2,$t5
/*  f1751c4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1751c8:	26310008 */ 	addiu	$s1,$s1,0x8
.L0f1751cc:
/*  f1751cc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1751d0:	02201025 */ 	or	$v0,$s1,$zero
/*  f1751d4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f1751d8:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f1751dc:	03e00008 */ 	jr	$ra
/*  f1751e0:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f1751e4
/*  f1751e4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1751e8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1751ec:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1751f0:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1751f4:	00a08825 */ 	or	$s1,$a1,$zero
/*  f1751f8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1751fc:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f175200:	00003025 */ 	or	$a2,$zero,$zero
/*  f175204:	0fc5d0e8 */ 	jal	func0f1743a0
/*  f175208:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f17520c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f175210:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f175214:	00408025 */ 	or	$s0,$v0,$zero
/*  f175218:	11c0000d */ 	beqz	$t6,.L0f175250
/*  f17521c:	00402025 */ 	or	$a0,$v0,$zero
/*  f175220:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f175224:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f175228:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f17522c:	02202825 */ 	or	$a1,$s1,$zero
/*  f175230:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f175234:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f175238:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17523c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f175240:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f175244:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f175248:	00408025 */ 	or	$s0,$v0,$zero
/*  f17524c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f175250:
/*  f175250:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f175254:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f175258:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f17525c:	02002025 */ 	or	$a0,$s0,$zero
/*  f175260:	02202825 */ 	or	$a1,$s1,$zero
/*  f175264:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f175268:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f17526c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f175270:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f175274:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f175278:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f17527c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f175280:	9224000b */ 	lbu	$a0,0xb($s1)
/*  f175284:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f175288:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f17528c:	00044942 */ 	srl	$t1,$a0,0x5
/*  f175290:	00408025 */ 	or	$s0,$v0,$zero
/*  f175294:	1540000f */ 	bnez	$t2,.L0f1752d4
/*  f175298:	00691821 */ 	addu	$v1,$v1,$t1
/*  f17529c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1752a0:	1521000c */ 	bne	$t1,$at,.L0f1752d4
/*  f1752a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1752a8:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f1752ac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1752b0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1752b4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1752b8:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f1752bc:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f1752c0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f1752c4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1752c8:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f1752cc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1752d0:	00408025 */ 	or	$s0,$v0,$zero
.L0f1752d4:
/*  f1752d4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1752d8:	3c0de700 */ 	lui	$t5,0xe700
/*  f1752dc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f1752e0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1752e4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1752e8:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f1752ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1752f0:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f1752f4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1752f8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1752fc:	ac2e44d0 */ 	sw	$t6,%lo(var800844d0)($at)
/*  f175300:	03e00008 */ 	jr	$ra
/*  f175304:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f175308
/*  f175308:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f17530c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f175310:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f175314:	00808025 */ 	or	$s0,$a0,$zero
/*  f175318:	00a09025 */ 	or	$s2,$a1,$zero
/*  f17531c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f175320:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f175324:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f175328:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f17532c:	00002825 */ 	or	$a1,$zero,$zero
/*  f175330:	0fc5cf84 */ 	jal	func0f173e10
/*  f175334:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f175338:	00408825 */ 	or	$s1,$v0,$zero
/*  f17533c:	02002025 */ 	or	$a0,$s0,$zero
/*  f175340:	0fc5d2d5 */ 	jal	func0f174b54
/*  f175344:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f175348:	3c0ee800 */ 	lui	$t6,0xe800
/*  f17534c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f175350:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f175354:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f175358:	02402825 */ 	or	$a1,$s2,$zero
/*  f17535c:	0fc5d0e8 */ 	jal	func0f1743a0
/*  f175360:	02203025 */ 	or	$a2,$s1,$zero
/*  f175364:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f175368:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f17536c:	00402025 */ 	or	$a0,$v0,$zero
/*  f175370:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f175374:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f175378:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f17537c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f175380:	0fc5cfde */ 	jal	func0f173f78
/*  f175384:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f175388:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f17538c:	00408025 */ 	or	$s0,$v0,$zero
/*  f175390:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f175394:	1320000f */ 	beqz	$t9,.L0f1753d4
/*  f175398:	00402025 */ 	or	$a0,$v0,$zero
/*  f17539c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f1753a0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1753a4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1753a8:	02402825 */ 	or	$a1,$s2,$zero
/*  f1753ac:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f1753b0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1753b4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f1753b8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1753bc:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f1753c0:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f1753c4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1753c8:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f1753cc:	00408025 */ 	or	$s0,$v0,$zero
/*  f1753d0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f1753d4:
/*  f1753d4:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f1753d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1753dc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1753e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1753e4:	02402825 */ 	or	$a1,$s2,$zero
/*  f1753e8:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f1753ec:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1753f0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f1753f4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1753f8:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f1753fc:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f175400:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f175404:	9244000b */ 	lbu	$a0,0xb($s2)
/*  f175408:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f17540c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f175410:	00046142 */ 	srl	$t4,$a0,0x5
/*  f175414:	00408025 */ 	or	$s0,$v0,$zero
/*  f175418:	15a0000f */ 	bnez	$t5,.L0f175458
/*  f17541c:	006c1821 */ 	addu	$v1,$v1,$t4
/*  f175420:	24010001 */ 	addiu	$at,$zero,0x1
/*  f175424:	1581000c */ 	bne	$t4,$at,.L0f175458
/*  f175428:	00402025 */ 	or	$a0,$v0,$zero
/*  f17542c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f175430:	240fffff */ 	addiu	$t7,$zero,-1
/*  f175434:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f175438:	02402825 */ 	or	$a1,$s2,$zero
/*  f17543c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f175440:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f175444:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f175448:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17544c:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f175450:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f175454:	00408025 */ 	or	$s0,$v0,$zero
.L0f175458:
/*  f175458:	02001825 */ 	or	$v1,$s0,$zero
/*  f17545c:	3c18e700 */ 	lui	$t8,0xe700
/*  f175460:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f175464:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f175468:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f17546c:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f175470:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f175474:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f175478:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f17547c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f175480:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f175484:	ac3944d0 */ 	sw	$t9,%lo(var800844d0)($at)
/*  f175488:	03e00008 */ 	jr	$ra
/*  f17548c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f175490
/*  f175490:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f175494:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f175498:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f17549c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1754a0:	00a08825 */ 	or	$s1,$a1,$zero
/*  f1754a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1754a8:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f1754ac:	0fc5d0e8 */ 	jal	func0f1743a0
/*  f1754b0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1754b4:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f1754b8:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1754bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1754c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1754c4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f1754c8:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1754cc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1754d0:	0fc5cfde */ 	jal	func0f173f78
/*  f1754d4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1754d8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f1754dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f1754e0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1754e4:	1300000f */ 	beqz	$t8,.L0f175524
/*  f1754e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1754ec:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f1754f0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1754f4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f1754f8:	02202825 */ 	or	$a1,$s1,$zero
/*  f1754fc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f175500:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f175504:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f175508:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f17550c:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f175510:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f175514:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f175518:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f17551c:	00408025 */ 	or	$s0,$v0,$zero
/*  f175520:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f175524:
/*  f175524:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f175528:	240affff */ 	addiu	$t2,$zero,-1
/*  f17552c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f175530:	02002025 */ 	or	$a0,$s0,$zero
/*  f175534:	02202825 */ 	or	$a1,$s1,$zero
/*  f175538:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f17553c:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f175540:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f175544:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f175548:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f17554c:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f175550:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f175554:	9224000b */ 	lbu	$a0,0xb($s1)
/*  f175558:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f17555c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f175560:	00045942 */ 	srl	$t3,$a0,0x5
/*  f175564:	00408025 */ 	or	$s0,$v0,$zero
/*  f175568:	1580000f */ 	bnez	$t4,.L0f1755a8
/*  f17556c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f175570:	24010001 */ 	addiu	$at,$zero,0x1
/*  f175574:	1561000c */ 	bne	$t3,$at,.L0f1755a8
/*  f175578:	00402025 */ 	or	$a0,$v0,$zero
/*  f17557c:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f175580:	240effff */ 	addiu	$t6,$zero,-1
/*  f175584:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f175588:	02202825 */ 	or	$a1,$s1,$zero
/*  f17558c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f175590:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f175594:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f175598:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f17559c:	0fc5d1e9 */ 	jal	func0f1747a4
/*  f1755a0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1755a4:	00408025 */ 	or	$s0,$v0,$zero
.L0f1755a8:
/*  f1755a8:	02001825 */ 	or	$v1,$s0,$zero
/*  f1755ac:	3c0fe700 */ 	lui	$t7,0xe700
/*  f1755b0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1755b4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1755b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1755bc:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f1755c0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1755c4:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f1755c8:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1755cc:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1755d0:	ac3844d0 */ 	sw	$t8,%lo(var800844d0)($at)
/*  f1755d4:	03e00008 */ 	jr	$ra
/*  f1755d8:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f1755dc
/*  f1755dc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1755e0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1755e4:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1755e8:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f1755ec:	0fc5d2d5 */ 	jal	func0f174b54
/*  f1755f0:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f1755f4:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f1755f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1755fc:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f175600:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f175604:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f175608:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17560c:	0fc5d3cc */ 	jal	func0f174f30
/*  f175610:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f175614:	3c0fe700 */ 	lui	$t7,0xe700
/*  f175618:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f17561c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f175620:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f175624:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f175628:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f17562c:	ac3844d0 */ 	sw	$t8,%lo(var800844d0)($at)
/*  f175630:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f175634:	03e00008 */ 	jr	$ra
/*  f175638:	24420008 */ 	addiu	$v0,$v0,0x8
);

GLOBAL_ASM(
glabel func0f17563c
/*  f17563c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f175640:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f175644:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f175648:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f17564c:	0fc5d2d5 */ 	jal	func0f174b54
/*  f175650:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f175654:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f175658:	00402025 */ 	or	$a0,$v0,$zero
/*  f17565c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f175660:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f175664:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f175668:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17566c:	0fc5d3cc */ 	jal	func0f174f30
/*  f175670:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f175674:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f175678:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f17567c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f175680:	00402025 */ 	or	$a0,$v0,$zero
/*  f175684:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f175688:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f17568c:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f175690:	0fc5d3cc */ 	jal	func0f174f30
/*  f175694:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f175698:	3c19e700 */ 	lui	$t9,0xe700
/*  f17569c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1756a0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1756a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1756a8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1756ac:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f1756b0:	ac2844d0 */ 	sw	$t0,%lo(var800844d0)($at)
/*  f1756b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1756b8:	03e00008 */ 	jr	$ra
/*  f1756bc:	24420008 */ 	addiu	$v0,$v0,0x8
);

GLOBAL_ASM(
glabel func0f1756c0
.late_rodata
glabel var7f1b7c30
.word func0f1756c0+0x544 # f175c04
glabel var7f1b7c34
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c38
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c3c
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c40
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c44
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c48
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c4c
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c50
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c54
.word func0f1756c0+0x74c # f175e0c
glabel var7f1b7c58
.word func0f1756c0+0x70c # f175dcc
glabel var7f1b7c5c
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c60
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c64
.word func0f1756c0+0x768 # f175e28
glabel var7f1b7c68
.word func0f1756c0+0x544 # f175c04
glabel var7f1b7c6c
.word func0f1756c0+0x114 # f1757d4
glabel var7f1b7c70
.word func0f1756c0+0x1c0 # f175880
glabel var7f1b7c74
.word func0f1756c0+0x224 # f1758e4
glabel var7f1b7c78
.word func0f1756c0+0x2bc # f17597c
glabel var7f1b7c7c
.word func0f1756c0+0x2f8 # f1759b8
glabel var7f1b7c80
.word func0f1756c0+0x330 # f1759f0
.text
/*  f1756c0:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f1756c4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1756c8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f1756cc:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f1756d0:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f1756d4:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f1756d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1756dc:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f1756e0:	000580c3 */ 	sra	$s0,$a1,0x3
/*  f1756e4:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f1756e8:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f1756ec:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f1756f0:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f1756f4:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1756f8:	afa60140 */ 	sw	$a2,0x140($sp)
/*  f1756fc:	afa70144 */ 	sw	$a3,0x144($sp)
/*  f175700:	afa0012c */ 	sw	$zero,0x12c($sp)
/*  f175704:	afae0104 */ 	sw	$t6,0x104($sp)
/*  f175708:	0000f025 */ 	or	$s8,$zero,$zero
/*  f17570c:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f175710:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f175714:	ac2044d0 */ 	sw	$zero,%lo(var800844d0)($at)
/*  f175718:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f17571c:	0080a825 */ 	or	$s5,$a0,$zero
/*  f175720:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f175724:	0fc5ce82 */ 	jal	func0f173a08
/*  f175728:	afb00128 */ 	sw	$s0,0x128($sp)
/*  f17572c:	0fc4f13c */ 	jal	func0f13c4f0
/*  f175730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175734:	10400006 */ 	beqz	$v0,.L0f175750
/*  f175738:	afa200e0 */ 	sw	$v0,0xe0($sp)
/*  f17573c:	27a20090 */ 	addiu	$v0,$sp,0x90
/*  f175740:	27a300a0 */ 	addiu	$v1,$sp,0xa0
.L0f175744:
/*  f175744:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f175748:	1443fffe */ 	bne	$v0,$v1,.L0f175744
/*  f17574c:	a040ffff */ 	sb	$zero,-0x1($v0)
.L0f175750:
/*  f175750:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f175754:	3c18800b */ 	lui	$t8,%hi(var800aabc8)
/*  f175758:	2718abc8 */ 	addiu	$t8,$t8,%lo(var800aabc8)
/*  f17575c:	15e00002 */ 	bnez	$t7,.L0f175768
/*  f175760:	27b70090 */ 	addiu	$s7,$sp,0x90
/*  f175764:	afb80144 */ 	sw	$t8,0x144($sp)
.L0f175768:
/*  f175768:	5a0001d5 */ 	blezl	$s0,.L0f175ec0
/*  f17576c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f175770:	92a30000 */ 	lbu	$v1,0x0($s5)
.L0f175774:
/*  f175774:	286100c1 */ 	slti	$at,$v1,0xc1
/*  f175778:	14200006 */ 	bnez	$at,.L0f175794
/*  f17577c:	00601025 */ 	or	$v0,$v1,$zero
/*  f175780:	240100e7 */ 	addiu	$at,$zero,0xe7
/*  f175784:	10410116 */ 	beq	$v0,$at,.L0f175be0
/*  f175788:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f17578c:	100001a7 */ 	beqz	$zero,.L0f175e2c
/*  f175790:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175794:
/*  f175794:	28410005 */ 	slti	$at,$v0,0x5
/*  f175798:	14200009 */ 	bnez	$at,.L0f1757c0
/*  f17579c:	2459ff4f */ 	addiu	$t9,$v0,-177
/*  f1757a0:	2f210010 */ 	sltiu	$at,$t9,0x10
/*  f1757a4:	102001a0 */ 	beqz	$at,.L0f175e28
/*  f1757a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1757ac:	3c017f1b */ 	lui	$at,%hi(var7f1b7c30)
/*  f1757b0:	00390821 */ 	addu	$at,$at,$t9
/*  f1757b4:	8c397c30 */ 	lw	$t9,%lo(var7f1b7c30)($at)
/*  f1757b8:	03200008 */ 	jr	$t9
/*  f1757bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1757c0:
/*  f1757c0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1757c4:	104100c8 */ 	beq	$v0,$at,.L0f175ae8
/*  f1757c8:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f1757cc:	10000197 */ 	beqz	$zero,.L0f175e2c
/*  f1757d0:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f1757d4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1757d8:	13c00003 */ 	beqz	$s8,.L0f1757e8
/*  f1757dc:	afac00e4 */ 	sw	$t4,0xe4($sp)
/*  f1757e0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1757e4:	afad00e8 */ 	sw	$t5,0xe8($sp)
.L0f1757e8:
/*  f1757e8:	8eb20004 */ 	lw	$s2,0x4($s5)
/*  f1757ec:	8eb30000 */ 	lw	$s3,0x0($s5)
/*  f1757f0:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f1757f4:	32440fff */ 	andi	$a0,$s2,0xfff
/*  f1757f8:	326f0200 */ 	andi	$t7,$s3,0x200
/*  f1757fc:	00809025 */ 	or	$s2,$a0,$zero
/*  f175800:	0fc5cd3a */ 	jal	func0f1734e8
/*  f175804:	01e09825 */ 	or	$s3,$t7,$zero
/*  f175808:	02402025 */ 	or	$a0,$s2,$zero
/*  f17580c:	0fc5cba3 */ 	jal	func0f172e8c
/*  f175810:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f175814:	10400006 */ 	beqz	$v0,.L0f175830
/*  f175818:	00408825 */ 	or	$s1,$v0,$zero
/*  f17581c:	8c58000c */ 	lw	$t8,0xc($v0)
/*  f175820:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f175824:	001967c2 */ 	srl	$t4,$t9,0x1f
/*  f175828:	10000002 */ 	beqz	$zero,.L0f175834
/*  f17582c:	afac00f4 */ 	sw	$t4,0xf4($sp)
.L0f175830:
/*  f175830:	afa000f4 */ 	sw	$zero,0xf4($sp)
.L0f175834:
/*  f175834:	104000aa */ 	beqz	$v0,.L0f175ae0
/*  f175838:	02c02025 */ 	or	$a0,$s6,$zero
/*  f17583c:	8fa70104 */ 	lw	$a3,0x104($sp)
/*  f175840:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f175844:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f175848:	02203025 */ 	or	$a2,$s1,$zero
/*  f17584c:	0fc5d0b9 */ 	jal	func0f1742e4
/*  f175850:	0000f025 */ 	or	$s8,$zero,$zero
/*  f175854:	8ea30000 */ 	lw	$v1,0x0($s5)
/*  f175858:	0040b025 */ 	or	$s6,$v0,$zero
/*  f17585c:	306d0007 */ 	andi	$t5,$v1,0x7
/*  f175860:	2da10005 */ 	sltiu	$at,$t5,0x5
/*  f175864:	1020006f */ 	beqz	$at,.L0f175a24
/*  f175868:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17586c:	3c017f1b */ 	lui	$at,%hi(var7f1b7c70)
/*  f175870:	002d0821 */ 	addu	$at,$at,$t5
/*  f175874:	8c2d7c70 */ 	lw	$t5,%lo(var7f1b7c70)($at)
/*  f175878:	01a00008 */ 	jr	$t5
/*  f17587c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175880:	8ea80004 */ 	lw	$t0,0x4($s5)
/*  f175884:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175888:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f17588c:	00087602 */ 	srl	$t6,$t0,0x18
/*  f175890:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f175894:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175898:	00034b82 */ 	srl	$t1,$v1,0xe
/*  f17589c:	00035282 */ 	srl	$t2,$v1,0xa
/*  f1758a0:	30d80003 */ 	andi	$t8,$a2,0x3
/*  f1758a4:	30f90003 */ 	andi	$t9,$a3,0x3
/*  f1758a8:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f1758ac:	312d000f */ 	andi	$t5,$t1,0xf
/*  f1758b0:	314e000f */ 	andi	$t6,$t2,0xf
/*  f1758b4:	03003025 */ 	or	$a2,$t8,$zero
/*  f1758b8:	03203825 */ 	or	$a3,$t9,$zero
/*  f1758bc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1758c0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1758c4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1758c8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1758cc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1758d0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1758d4:	0fc5d524 */ 	jal	func0f175490
/*  f1758d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f1758dc:	10000051 */ 	beqz	$zero,.L0f175a24
/*  f1758e0:	0040b025 */ 	or	$s6,$v0,$zero
/*  f1758e4:	8eb00004 */ 	lw	$s0,0x4($s5)
/*  f1758e8:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f1758ec:	00107b02 */ 	srl	$t7,$s0,0xc
/*  f1758f0:	31e40fff */ 	andi	$a0,$t7,0xfff
/*  f1758f4:	0fc5cd3a */ 	jal	func0f1734e8
/*  f1758f8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1758fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f175900:	0fc5cba3 */ 	jal	func0f172e8c
/*  f175904:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f175908:	10400046 */ 	beqz	$v0,.L0f175a24
/*  f17590c:	00405825 */ 	or	$t3,$v0,$zero
/*  f175910:	8ea30000 */ 	lw	$v1,0x0($s5)
/*  f175914:	8ea80004 */ 	lw	$t0,0x4($s5)
/*  f175918:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17591c:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175920:	0008ce02 */ 	srl	$t9,$t0,0x18
/*  f175924:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f175928:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f17592c:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175930:	00034b82 */ 	srl	$t1,$v1,0xe
/*  f175934:	00035282 */ 	srl	$t2,$v1,0xa
/*  f175938:	30cd0003 */ 	andi	$t5,$a2,0x3
/*  f17593c:	30ee0003 */ 	andi	$t6,$a3,0x3
/*  f175940:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f175944:	3138000f */ 	andi	$t8,$t1,0xf
/*  f175948:	3159000f */ 	andi	$t9,$t2,0xf
/*  f17594c:	01a03025 */ 	or	$a2,$t5,$zero
/*  f175950:	01c03825 */ 	or	$a3,$t6,$zero
/*  f175954:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f175958:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f17595c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f175960:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f175964:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f175968:	02c02025 */ 	or	$a0,$s6,$zero
/*  f17596c:	0fc5d4c2 */ 	jal	func0f175308
/*  f175970:	02202825 */ 	or	$a1,$s1,$zero
/*  f175974:	1000002b */ 	beqz	$zero,.L0f175a24
/*  f175978:	0040b025 */ 	or	$s6,$v0,$zero
/*  f17597c:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175980:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f175984:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175988:	30cc0003 */ 	andi	$t4,$a2,0x3
/*  f17598c:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f175990:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f175994:	01803025 */ 	or	$a2,$t4,$zero
/*  f175998:	01a03825 */ 	or	$a3,$t5,$zero
/*  f17599c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1759a0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1759a4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1759a8:	0fc5d479 */ 	jal	func0f1751e4
/*  f1759ac:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f1759b0:	1000001c */ 	beqz	$zero,.L0f175a24
/*  f1759b4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f1759b8:	00033582 */ 	srl	$a2,$v1,0x16
/*  f1759bc:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f1759c0:	00031482 */ 	srl	$v0,$v1,0x12
/*  f1759c4:	30cf0003 */ 	andi	$t7,$a2,0x3
/*  f1759c8:	30f80003 */ 	andi	$t8,$a3,0x3
/*  f1759cc:	30590003 */ 	andi	$t9,$v0,0x3
/*  f1759d0:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1759d4:	03003825 */ 	or	$a3,$t8,$zero
/*  f1759d8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1759dc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1759e0:	0fc5d58f */ 	jal	func0f17563c
/*  f1759e4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1759e8:	1000000e */ 	beqz	$zero,.L0f175a24
/*  f1759ec:	0040b025 */ 	or	$s6,$v0,$zero
/*  f1759f0:	00033582 */ 	srl	$a2,$v1,0x16
/*  f1759f4:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f1759f8:	00031482 */ 	srl	$v0,$v1,0x12
/*  f1759fc:	30cc0003 */ 	andi	$t4,$a2,0x3
/*  f175a00:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f175a04:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f175a08:	01803025 */ 	or	$a2,$t4,$zero
/*  f175a0c:	01a03825 */ 	or	$a3,$t5,$zero
/*  f175a10:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f175a14:	02c02025 */ 	or	$a0,$s6,$zero
/*  f175a18:	0fc5d577 */ 	jal	func0f1755dc
/*  f175a1c:	02202825 */ 	or	$a1,$s1,$zero
/*  f175a20:	0040b025 */ 	or	$s6,$v0,$zero
.L0f175a24:
/*  f175a24:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f175a28:	240106cb */ 	addiu	$at,$zero,0x6cb
/*  f175a2c:	11e0002c */ 	beqz	$t7,.L0f175ae0
/*  f175a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175a34:	56410005 */ 	bnel	$s2,$at,.L0f175a4c
/*  f175a38:	24010a6a */ 	addiu	$at,$zero,0xa6a
/*  f175a3c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175a44:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f175a48:	24010a6a */ 	addiu	$at,$zero,0xa6a
.L0f175a4c:
/*  f175a4c:	16410003 */ 	bne	$s2,$at,.L0f175a5c
/*  f175a50:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f175a54:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a58:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a5c:
/*  f175a5c:	24010a69 */ 	addiu	$at,$zero,0xa69
/*  f175a60:	16410003 */ 	bne	$s2,$at,.L0f175a70
/*  f175a64:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f175a68:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a6c:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a70:
/*  f175a70:	240106e2 */ 	addiu	$at,$zero,0x6e2
/*  f175a74:	16410003 */ 	bne	$s2,$at,.L0f175a84
/*  f175a78:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f175a7c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a80:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a84:
/*  f175a84:	240101c7 */ 	addiu	$at,$zero,0x1c7
/*  f175a88:	12410004 */ 	beq	$s2,$at,.L0f175a9c
/*  f175a8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175a90:	24010dae */ 	addiu	$at,$zero,0xdae
/*  f175a94:	56410004 */ 	bnel	$s2,$at,.L0f175aa8
/*  f175a98:	2401029b */ 	addiu	$at,$zero,0x29b
.L0f175a9c:
/*  f175a9c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175aa0:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f175aa4:	2401029b */ 	addiu	$at,$zero,0x29b
.L0f175aa8:
/*  f175aa8:	16410003 */ 	bne	$s2,$at,.L0f175ab8
/*  f175aac:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f175ab0:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175ab4:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175ab8:
/*  f175ab8:	2401090f */ 	addiu	$at,$zero,0x90f
/*  f175abc:	16410003 */ 	bne	$s2,$at,.L0f175acc
/*  f175ac0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175ac4:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175ac8:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175acc:
/*  f175acc:	24010a42 */ 	addiu	$at,$zero,0xa42
/*  f175ad0:	16410003 */ 	bne	$s2,$at,.L0f175ae0
/*  f175ad4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f175ad8:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175adc:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175ae0:
/*  f175ae0:	100000d7 */ 	beqz	$zero,.L0f175e40
/*  f175ae4:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f175ae8:
/*  f175ae8:	1300001e */ 	beqz	$t8,.L0f175b64
/*  f175aec:	3c0100ff */ 	lui	$at,0xff
/*  f175af0:	92a30001 */ 	lbu	$v1,0x1($s5)
/*  f175af4:	8eb30004 */ 	lw	$s3,0x4($s5)
/*  f175af8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f175afc:	00032102 */ 	srl	$a0,$v1,0x4
/*  f175b00:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f175b04:	3062000f */ 	andi	$v0,$v1,0xf
/*  f175b08:	0044a021 */ 	addu	$s4,$v0,$a0
/*  f175b0c:	0261c824 */ 	and	$t9,$s3,$at
/*  f175b10:	0054082a */ 	slt	$at,$v0,$s4
/*  f175b14:	03209825 */ 	or	$s3,$t9,$zero
/*  f175b18:	10200012 */ 	beqz	$at,.L0f175b64
/*  f175b1c:	00408825 */ 	or	$s1,$v0,$zero
/*  f175b20:	00026080 */ 	sll	$t4,$v0,0x2
/*  f175b24:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f175b28:	018d9021 */ 	addu	$s2,$t4,$t5
.L0f175b2c:
/*  f175b2c:	13c00007 */ 	beqz	$s8,.L0f175b4c
/*  f175b30:	02f18021 */ 	addu	$s0,$s7,$s1
/*  f175b34:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f175b38:	51c00005 */ 	beqzl	$t6,.L0f175b50
/*  f175b3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f175b40:	0fc4f01f */ 	jal	func0f13c07c
/*  f175b44:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f175b48:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f175b4c:
/*  f175b4c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f175b50:
/*  f175b50:	0234082a */ 	slt	$at,$s1,$s4
/*  f175b54:	ae530000 */ 	sw	$s3,0x0($s2)
/*  f175b58:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f175b5c:	1420fff3 */ 	bnez	$at,.L0f175b2c
/*  f175b60:	2673000c */ 	addiu	$s3,$s3,0xc
.L0f175b64:
/*  f175b64:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f175b68:	8fb80148 */ 	lw	$t8,0x148($sp)
/*  f175b6c:	51e00016 */ 	beqzl	$t7,.L0f175bc8
/*  f175b70:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175b74:	13000013 */ 	beqz	$t8,.L0f175bc4
/*  f175b78:	3c0100ff */ 	lui	$at,0xff
/*  f175b7c:	92a40001 */ 	lbu	$a0,0x1($s5)
/*  f175b80:	8ea50004 */ 	lw	$a1,0x4($s5)
/*  f175b84:	3421ffff */ 	ori	$at,$at,0xffff
/*  f175b88:	0004c902 */ 	srl	$t9,$a0,0x4
/*  f175b8c:	27240001 */ 	addiu	$a0,$t9,0x1
/*  f175b90:	00001825 */ 	or	$v1,$zero,$zero
/*  f175b94:	1880000b */ 	blez	$a0,.L0f175bc4
/*  f175b98:	00a16024 */ 	and	$t4,$a1,$at
/*  f175b9c:	030c1021 */ 	addu	$v0,$t8,$t4
.L0f175ba0:
/*  f175ba0:	844d0008 */ 	lh	$t5,0x8($v0)
/*  f175ba4:	844f000a */ 	lh	$t7,0xa($v0)
/*  f175ba8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f175bac:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f175bb0:	000fc843 */ 	sra	$t9,$t7,0x1
/*  f175bb4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f175bb8:	a44efffc */ 	sh	$t6,-0x4($v0)
/*  f175bbc:	1464fff8 */ 	bne	$v1,$a0,.L0f175ba0
/*  f175bc0:	a459fffe */ 	sh	$t9,-0x2($v0)
.L0f175bc4:
/*  f175bc4:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175bc8:
/*  f175bc8:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175bcc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175bd0:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175bd4:	8eb8fffc */ 	lw	$t8,-0x4($s5)
/*  f175bd8:	10000099 */ 	beqz	$zero,.L0f175e40
/*  f175bdc:	aed8fffc */ 	sw	$t8,-0x4($s6)
.L0f175be0:
/*  f175be0:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f175be4:	ac2d44d0 */ 	sw	$t5,%lo(var800844d0)($at)
/*  f175be8:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175bec:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175bf0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175bf4:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175bf8:	8eb9fffc */ 	lw	$t9,-0x4($s5)
/*  f175bfc:	10000090 */ 	beqz	$zero,.L0f175e40
/*  f175c00:	aed9fffc */ 	sw	$t9,-0x4($s6)
/*  f175c04:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f175c08:	13c00067 */ 	beqz	$s8,.L0f175da8
/*  f175c0c:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f175c10:	240100bf */ 	addiu	$at,$zero,0xbf
/*  f175c14:	54610015 */ 	bnel	$v1,$at,.L0f175c6c
/*  f175c18:	92a20007 */ 	lbu	$v0,0x7($s5)
/*  f175c1c:	92ad0005 */ 	lbu	$t5,0x5($s5)
/*  f175c20:	2401000a */ 	addiu	$at,$zero,0xa
/*  f175c24:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f175c28:	01a1001a */ 	div	$zero,$t5,$at
/*  f175c2c:	00007812 */ 	mflo	$t7
/*  f175c30:	02ef7021 */ 	addu	$t6,$s7,$t7
/*  f175c34:	a1d80000 */ 	sb	$t8,0x0($t6)
/*  f175c38:	92ac0006 */ 	lbu	$t4,0x6($s5)
/*  f175c3c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f175c40:	0181001a */ 	div	$zero,$t4,$at
/*  f175c44:	00006812 */ 	mflo	$t5
/*  f175c48:	02ed7821 */ 	addu	$t7,$s7,$t5
/*  f175c4c:	a1f90000 */ 	sb	$t9,0x0($t7)
/*  f175c50:	92ae0007 */ 	lbu	$t6,0x7($s5)
/*  f175c54:	01c1001a */ 	div	$zero,$t6,$at
/*  f175c58:	00006012 */ 	mflo	$t4
/*  f175c5c:	02ec6821 */ 	addu	$t5,$s7,$t4
/*  f175c60:	10000051 */ 	beqz	$zero,.L0f175da8
/*  f175c64:	a1b80000 */ 	sb	$t8,0x0($t5)
/*  f175c68:	92a20007 */ 	lbu	$v0,0x7($s5)
.L0f175c6c:
/*  f175c6c:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f175c70:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175c74:	0002c902 */ 	srl	$t9,$v0,0x4
/*  f175c78:	306f000f */ 	andi	$t7,$v1,0xf
/*  f175c7c:	172f0004 */ 	bne	$t9,$t7,.L0f175c90
/*  f175c80:	01e01825 */ 	or	$v1,$t7,$zero
/*  f175c84:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f175c88:	31cc000f */ 	andi	$t4,$t6,0xf
/*  f175c8c:	132c000b */ 	beq	$t9,$t4,.L0f175cbc
.L0f175c90:
/*  f175c90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f175c94:	02e3c021 */ 	addu	$t8,$s7,$v1
/*  f175c98:	a3020000 */ 	sb	$v0,0x0($t8)
/*  f175c9c:	92ad0007 */ 	lbu	$t5,0x7($s5)
/*  f175ca0:	000dc902 */ 	srl	$t9,$t5,0x4
/*  f175ca4:	02f97821 */ 	addu	$t7,$s7,$t9
/*  f175ca8:	a1e20000 */ 	sb	$v0,0x0($t7)
/*  f175cac:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f175cb0:	31cc000f */ 	andi	$t4,$t6,0xf
/*  f175cb4:	02ecc021 */ 	addu	$t8,$s7,$t4
/*  f175cb8:	a3020000 */ 	sb	$v0,0x0($t8)
.L0f175cbc:
/*  f175cbc:	96a30006 */ 	lhu	$v1,0x6($s5)
/*  f175cc0:	92a20006 */ 	lbu	$v0,0x6($s5)
/*  f175cc4:	00036b02 */ 	srl	$t5,$v1,0xc
/*  f175cc8:	3059000f */ 	andi	$t9,$v0,0xf
/*  f175ccc:	15b90004 */ 	bne	$t5,$t9,.L0f175ce0
/*  f175cd0:	03201025 */ 	or	$v0,$t9,$zero
/*  f175cd4:	92af0003 */ 	lbu	$t7,0x3($s5)
/*  f175cd8:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f175cdc:	11ae000b */ 	beq	$t5,$t6,.L0f175d0c
.L0f175ce0:
/*  f175ce0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f175ce4:	02e26021 */ 	addu	$t4,$s7,$v0
/*  f175ce8:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f175cec:	96b80006 */ 	lhu	$t8,0x6($s5)
/*  f175cf0:	00186b02 */ 	srl	$t5,$t8,0xc
/*  f175cf4:	02edc821 */ 	addu	$t9,$s7,$t5
/*  f175cf8:	a3230000 */ 	sb	$v1,0x0($t9)
/*  f175cfc:	92af0003 */ 	lbu	$t7,0x3($s5)
/*  f175d00:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f175d04:	02ee6021 */ 	addu	$t4,$s7,$t6
/*  f175d08:	a1830000 */ 	sb	$v1,0x0($t4)
.L0f175d0c:
/*  f175d0c:	92a30005 */ 	lbu	$v1,0x5($s5)
/*  f175d10:	96a20004 */ 	lhu	$v0,0x4($s5)
/*  f175d14:	0003c102 */ 	srl	$t8,$v1,0x4
/*  f175d18:	304d000f */ 	andi	$t5,$v0,0xf
/*  f175d1c:	170d0004 */ 	bne	$t8,$t5,.L0f175d30
/*  f175d20:	01a01025 */ 	or	$v0,$t5,$zero
/*  f175d24:	92b90002 */ 	lbu	$t9,0x2($s5)
/*  f175d28:	332f000f */ 	andi	$t7,$t9,0xf
/*  f175d2c:	130f000a */ 	beq	$t8,$t7,.L0f175d58
.L0f175d30:
/*  f175d30:	02e27021 */ 	addu	$t6,$s7,$v0
/*  f175d34:	a1c40000 */ 	sb	$a0,0x0($t6)
/*  f175d38:	92ac0005 */ 	lbu	$t4,0x5($s5)
/*  f175d3c:	000cc102 */ 	srl	$t8,$t4,0x4
/*  f175d40:	02f86821 */ 	addu	$t5,$s7,$t8
/*  f175d44:	a1a40000 */ 	sb	$a0,0x0($t5)
/*  f175d48:	92b90002 */ 	lbu	$t9,0x2($s5)
/*  f175d4c:	332f000f */ 	andi	$t7,$t9,0xf
/*  f175d50:	02ef7021 */ 	addu	$t6,$s7,$t7
/*  f175d54:	a1c40000 */ 	sb	$a0,0x0($t6)
.L0f175d58:
/*  f175d58:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f175d5c:	92a20004 */ 	lbu	$v0,0x4($s5)
/*  f175d60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175d64:	00036702 */ 	srl	$t4,$v1,0x1c
/*  f175d68:	3058000f */ 	andi	$t8,$v0,0xf
/*  f175d6c:	15980004 */ 	bne	$t4,$t8,.L0f175d80
/*  f175d70:	03001025 */ 	or	$v0,$t8,$zero
/*  f175d74:	96ad0002 */ 	lhu	$t5,0x2($s5)
/*  f175d78:	000dcb02 */ 	srl	$t9,$t5,0xc
/*  f175d7c:	1199000a */ 	beq	$t4,$t9,.L0f175da8
.L0f175d80:
/*  f175d80:	02e27821 */ 	addu	$t7,$s7,$v0
/*  f175d84:	a1e40000 */ 	sb	$a0,0x0($t7)
/*  f175d88:	8eae0004 */ 	lw	$t6,0x4($s5)
/*  f175d8c:	000e6702 */ 	srl	$t4,$t6,0x1c
/*  f175d90:	02ecc021 */ 	addu	$t8,$s7,$t4
/*  f175d94:	a3040000 */ 	sb	$a0,0x0($t8)
/*  f175d98:	96ad0002 */ 	lhu	$t5,0x2($s5)
/*  f175d9c:	000dcb02 */ 	srl	$t9,$t5,0xc
/*  f175da0:	02f97821 */ 	addu	$t7,$s7,$t9
/*  f175da4:	a1e40000 */ 	sb	$a0,0x0($t7)
.L0f175da8:
/*  f175da8:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f175dac:	ac2044d0 */ 	sw	$zero,%lo(var800844d0)($at)
/*  f175db0:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175db4:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175db8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175dbc:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175dc0:	8eb8fffc */ 	lw	$t8,-0x4($s5)
/*  f175dc4:	1000001e */ 	beqz	$zero,.L0f175e40
/*  f175dc8:	aed8fffc */ 	sw	$t8,-0x4($s6)
/*  f175dcc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f175dd0:	001e102b */ 	sltu	$v0,$zero,$s8
/*  f175dd4:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f175dd8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f175ddc:	10400003 */ 	beqz	$v0,.L0f175dec
/*  f175de0:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f175de4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f175de8:	afb900e8 */ 	sw	$t9,0xe8($sp)
.L0f175dec:
/*  f175dec:	afb6012c */ 	sw	$s6,0x12c($sp)
/*  f175df0:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175df4:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175df8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175dfc:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e00:	8eaefffc */ 	lw	$t6,-0x4($s5)
/*  f175e04:	1000000e */ 	beqz	$zero,.L0f175e40
/*  f175e08:	aecefffc */ 	sw	$t6,-0x4($s6)
/*  f175e0c:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175e10:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175e14:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175e18:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e1c:	8eb9fffc */ 	lw	$t9,-0x4($s5)
/*  f175e20:	10000007 */ 	beqz	$zero,.L0f175e40
/*  f175e24:	aed9fffc */ 	sw	$t9,-0x4($s6)
.L0f175e28:
/*  f175e28:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175e2c:
/*  f175e2c:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175e30:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175e34:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e38:	8eaefffc */ 	lw	$t6,-0x4($s5)
/*  f175e3c:	aecefffc */ 	sw	$t6,-0x4($s6)
.L0f175e40:
/*  f175e40:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f175e44:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f175e48:	25b8ffff */ 	addiu	$t8,$t5,-1
/*  f175e4c:	17200003 */ 	bnez	$t9,.L0f175e5c
/*  f175e50:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f175e54:	5f000017 */ 	bgtzl	$t8,.L0f175eb4
/*  f175e58:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f175e5c:
/*  f175e5c:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f175e60:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f175e64:	00008025 */ 	or	$s0,$zero,$zero
/*  f175e68:	55e00004 */ 	bnezl	$t7,.L0f175e7c
/*  f175e6c:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f175e70:	53c00010 */ 	beqzl	$s8,.L0f175eb4
/*  f175e74:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f175e78:	afa000e8 */ 	sw	$zero,0xe8($sp)
.L0f175e7c:
/*  f175e7c:	27b10090 */ 	addiu	$s1,$sp,0x90
.L0f175e80:
/*  f175e80:	922c0000 */ 	lbu	$t4,0x0($s1)
/*  f175e84:	00107080 */ 	sll	$t6,$s0,0x2
/*  f175e88:	03ae2021 */ 	addu	$a0,$sp,$t6
/*  f175e8c:	51800005 */ 	beqzl	$t4,.L0f175ea4
/*  f175e90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f175e94:	0fc4f01f */ 	jal	func0f13c07c
/*  f175e98:	8c8400a0 */ 	lw	$a0,0xa0($a0)
/*  f175e9c:	a2200000 */ 	sb	$zero,0x0($s1)
/*  f175ea0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f175ea4:
/*  f175ea4:	24010010 */ 	addiu	$at,$zero,0x10
/*  f175ea8:	1601fff5 */ 	bne	$s0,$at,.L0f175e80
/*  f175eac:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f175eb0:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f175eb4:
/*  f175eb4:	5da0fe2f */ 	bgtzl	$t5,.L0f175774
/*  f175eb8:	92a30000 */ 	lbu	$v1,0x0($s5)
/*  f175ebc:	8fb90140 */ 	lw	$t9,0x140($sp)
.L0f175ec0:
/*  f175ec0:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f175ec4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f175ec8:	02d91023 */ 	subu	$v0,$s6,$t9
/*  f175ecc:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f175ed0:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f175ed4:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f175ed8:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f175edc:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f175ee0:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f175ee4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f175ee8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f175eec:	03e00008 */ 	jr	$ra
/*  f175ef0:	27bd0138 */ 	addiu	$sp,$sp,0x138
);

GLOBAL_ASM(
glabel func0f175ef4
/*  f175ef4:	000670c3 */ 	sra	$t6,$a2,0x3
/*  f175ef8:	25c2ffff */ 	addiu	$v0,$t6,-1
/*  f175efc:	01c03025 */ 	or	$a2,$t6,$zero
/*  f175f00:	000218c0 */ 	sll	$v1,$v0,0x3
/*  f175f04:	00642021 */ 	addu	$a0,$v1,$a0
/*  f175f08:	00652821 */ 	addu	$a1,$v1,$a1
/*  f175f0c:	01c03825 */ 	or	$a3,$t6,$zero
/*  f175f10:	10c0000a */ 	beqz	$a2,.L0f175f3c
/*  f175f14:	00403025 */ 	or	$a2,$v0,$zero
.L0f175f18:
/*  f175f18:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f175f1c:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f175f20:	00c03825 */ 	or	$a3,$a2,$zero
/*  f175f24:	24a5fff8 */ 	addiu	$a1,$a1,-8
/*  f175f28:	2484fff8 */ 	addiu	$a0,$a0,-8
/*  f175f2c:	acb80008 */ 	sw	$t8,0x8($a1)
/*  f175f30:	acb9000c */ 	sw	$t9,0xc($a1)
/*  f175f34:	14c0fff8 */ 	bnez	$a2,.L0f175f18
/*  f175f38:	24c6ffff */ 	addiu	$a2,$a2,-1
.L0f175f3c:
/*  f175f3c:	03e00008 */ 	jr	$ra
/*  f175f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175f48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f175f4c:	00000000 */ 	sll	$zero,$zero,0x0
);
