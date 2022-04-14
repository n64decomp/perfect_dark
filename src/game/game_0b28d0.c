#include <ultra64.h>
#include "constants.h"
#include "game/game_0b28d0.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

struct var8009dd00 *var8009dd00;
struct anim *var8009dd04;
u32 var8009dd08;
u32 var8009dd0c;
struct var8009dd10 *var8009dd10;
struct var8009dd10 *var8009dd14;
struct var8009dd10 *var8009dd18;
u32 var8009dd1c;

s32 var800705a0 = 0;
s32 var800705a4 = 0;
bool var800705a8 = false;
s32 var800705ac = 0;
s32 var800705b0 = 0;
s32 var800705b4 = 0;
s32 var800705b8 = 0;
s32 var800705bc = 0;

#define NUMTHINGS1() (IS4MB() ? 0 : 35)
#define NUMTHINGS2() (IS4MB() ? 24 : 25)
#define NUMTHINGS3() (IS4MB() ? 0 : 20)

GLOBAL_ASM(
glabel func0f0b28d0
/*  f0b28d0:	84a30014 */ 	lh	$v1,0x14($a1)
/*  f0b28d4:	28620001 */ 	slti	$v0,$v1,0x1
/*  f0b28d8:	14400008 */ 	bnez	$v0,.L0f0b28fc
/*  f0b28dc:	00000000 */ 	nop
/*  f0b28e0:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0b28e4:	0002702b */ 	sltu	$t6,$zero,$v0
/*  f0b28e8:	11c00004 */ 	beqz	$t6,.L0f0b28fc
/*  f0b28ec:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0b28f0:	848f0002 */ 	lh	$t7,0x2($a0)
/*  f0b28f4:	01e3102a */ 	slt	$v0,$t7,$v1
/*  f0b28f8:	38420001 */ 	xori	$v0,$v0,0x1
.L0f0b28fc:
/*  f0b28fc:	03e00008 */ 	jr	$ra
/*  f0b2900:	00000000 */ 	nop
);

void func0f0b2904(void)
{
	s32 i;
	s32 count1 = 0;
	s32 count2 = 0;
	s32 count3 = 0;
	s32 count4 = 0;
	s32 count5 = 0;

	for (i = 0; i < NUMTHINGS1(); i++) {
		if (var8009dd10[i].model) {
			count1++;
		}
	}

	for (i = 0; i < NUMTHINGS2(); i++) {
		if (var8009dd14[i].model) {
			count2++;
		}
	}

	for (i = 0; i < NUMTHINGS3(); i++) {
		if (var8009dd18[i].model) {
			count3++;
		}
	}

	for (i = 0; i < var800705a0; i++) {
		if (var8009dd00[i].unk08) {
			count4++;
		}
	}

	for (i = 0; i < var800705a4; i++) {
		if (var8009dd04[i].animnum != -1) {
			count5++;
		}
	}

	if (count1 > var800705ac) {
		var800705ac = count1;
	}

	if (count2 > var800705b0) {
		var800705b0 = count2;
	}

	if (count3 > var800705b4) {
		var800705b4 = count3;
	}

	if (count4 > var800705b8) {
		var800705b8 = count4;
	}

	if (count5 > var800705bc) {
		var800705bc = count5;
	}

	if (IS4MB());
}

GLOBAL_ASM(
glabel func0f0b2b64
/*  f0b2b64:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0b2b68:	3c0f8007 */ 	lui	$t7,%hi(var800705a8)
/*  f0b2b6c:	8def05a8 */ 	lw	$t7,%lo(var800705a8)($t7)
/*  f0b2b70:	240effff */ 	addiu	$t6,$zero,-1
/*  f0b2b74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b2b78:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0b2b7c:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0b2b80:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f0b2b84:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0b2b88:	15e00027 */ 	bnez	$t7,.L0f0b2c28
/*  f0b2b8c:	a7ae0036 */ 	sh	$t6,0x36($sp)
/*  f0b2b90:	3c188007 */ 	lui	$t8,%hi(var800705a0)
/*  f0b2b94:	8f1805a0 */ 	lw	$t8,%lo(var800705a0)($t8)
/*  f0b2b98:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2b9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b2ba0:	1b000021 */ 	blez	$t8,.L0f0b2c28
/*  f0b2ba4:	3c08800a */ 	lui	$t0,%hi(var8009dd00)
/*  f0b2ba8:	2508dd00 */ 	addiu	$t0,$t0,%lo(var8009dd00)
/*  f0b2bac:	8d070000 */ 	lw	$a3,0x0($t0)
.L0f0b2bb0:
/*  f0b2bb0:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0b2bb4:	00e3c821 */ 	addu	$t9,$a3,$v1
/*  f0b2bb8:	8f2b0008 */ 	lw	$t3,0x8($t9)
/*  f0b2bbc:	00672021 */ 	addu	$a0,$v1,$a3
/*  f0b2bc0:	15600012 */ 	bnez	$t3,.L0f0b2c0c
/*  f0b2bc4:	00000000 */ 	nop
/*  f0b2bc8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0b2bcc:	0fc2ca34 */ 	jal	func0f0b28d0
/*  f0b2bd0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0b2bd4:	3c08800a */ 	lui	$t0,%hi(var8009dd00)
/*  f0b2bd8:	2508dd00 */ 	addiu	$t0,$t0,%lo(var8009dd00)
/*  f0b2bdc:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0b2be0:	1040000a */ 	beqz	$v0,.L0f0b2c0c
/*  f0b2be4:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f0b2be8:	8d070000 */ 	lw	$a3,0x0($t0)
/*  f0b2bec:	00676021 */ 	addu	$t4,$v1,$a3
/*  f0b2bf0:	afac003c */ 	sw	$t4,0x3c($sp)
/*  f0b2bf4:	00e31021 */ 	addu	$v0,$a3,$v1
/*  f0b2bf8:	8c4d0010 */ 	lw	$t5,0x10($v0)
/*  f0b2bfc:	afad0038 */ 	sw	$t5,0x38($sp)
/*  f0b2c00:	844e0002 */ 	lh	$t6,0x2($v0)
/*  f0b2c04:	10000008 */ 	b	.L0f0b2c28
/*  f0b2c08:	a7ae0036 */ 	sh	$t6,0x36($sp)
.L0f0b2c0c:
/*  f0b2c0c:	3c0f8007 */ 	lui	$t7,%hi(var800705a0)
/*  f0b2c10:	8def05a0 */ 	lw	$t7,%lo(var800705a0)($t7)
/*  f0b2c14:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2c18:	24630024 */ 	addiu	$v1,$v1,0x24
/*  f0b2c1c:	00cf082a */ 	slt	$at,$a2,$t7
/*  f0b2c20:	5420ffe3 */ 	bnezl	$at,.L0f0b2bb0
/*  f0b2c24:	8d070000 */ 	lw	$a3,0x0($t0)
.L0f0b2c28:
/*  f0b2c28:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0b2c2c:	3c048007 */ 	lui	$a0,%hi(var800705a0)
/*  f0b2c30:	570000fa */ 	bnezl	$t8,.L0f0b301c
/*  f0b2c34:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0b2c38:	8c8405a0 */ 	lw	$a0,%lo(var800705a0)($a0)
/*  f0b2c3c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2c40:	3c07800a */ 	lui	$a3,%hi(var8009dd00)
/*  f0b2c44:	1880000e */ 	blez	$a0,.L0f0b2c80
/*  f0b2c48:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b2c4c:	8ce7dd00 */ 	lw	$a3,%lo(var8009dd00)($a3)
/*  f0b2c50:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b2c54:	00e01025 */ 	or	$v0,$a3,$zero
.L0f0b2c58:
/*  f0b2c58:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f0b2c5c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2c60:	00c4082a */ 	slt	$at,$a2,$a0
/*  f0b2c64:	17200004 */ 	bnez	$t9,.L0f0b2c78
/*  f0b2c68:	24420024 */ 	addiu	$v0,$v0,0x24
/*  f0b2c6c:	00675821 */ 	addu	$t3,$v1,$a3
/*  f0b2c70:	10000003 */ 	b	.L0f0b2c80
/*  f0b2c74:	afab003c */ 	sw	$t3,0x3c($sp)
.L0f0b2c78:
/*  f0b2c78:	1420fff7 */ 	bnez	$at,.L0f0b2c58
/*  f0b2c7c:	24630024 */ 	addiu	$v1,$v1,0x24
.L0f0b2c80:
/*  f0b2c80:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f0b2c84:	15800004 */ 	bnez	$t4,.L0f0b2c98
/*  f0b2c88:	00000000 */ 	nop
/*  f0b2c8c:	0c0048f2 */ 	jal	mempAlloc
/*  f0b2c90:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f0b2c94:	afa2003c */ 	sw	$v0,0x3c($sp)
.L0f0b2c98:
/*  f0b2c98:	3c0d8007 */ 	lui	$t5,%hi(var800705a8)
/*  f0b2c9c:	8dad05a8 */ 	lw	$t5,%lo(var800705a8)($t5)
/*  f0b2ca0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0b2ca4:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0b2ca8:	51a0000f */ 	beqzl	$t5,.L0f0b2ce8
/*  f0b2cac:	85690014 */ 	lh	$t1,0x14($t3)
/*  f0b2cb0:	85c90014 */ 	lh	$t1,0x14($t6)
/*  f0b2cb4:	592000d9 */ 	blezl	$t1,.L0f0b301c
/*  f0b2cb8:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0b2cbc:	a7a90036 */ 	sh	$t1,0x36($sp)
/*  f0b2cc0:	87a40036 */ 	lh	$a0,0x36($sp)
/*  f0b2cc4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b2cc8:	00047880 */ 	sll	$t7,$a0,0x2
/*  f0b2ccc:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f0b2cd0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f0b2cd4:	0c0048f2 */ 	jal	mempAlloc
/*  f0b2cd8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f0b2cdc:	100000ce */ 	b	.L0f0b3018
/*  f0b2ce0:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0b2ce4:	85690014 */ 	lh	$t1,0x14($t3)
.L0f0b2ce8:
/*  f0b2ce8:	29210100 */ 	slti	$at,$t1,0x100
/*  f0b2cec:	102000aa */ 	beqz	$at,.L0f0b2f98
/*  f0b2cf0:	29210005 */ 	slti	$at,$t1,0x5
/*  f0b2cf4:	10200023 */ 	beqz	$at,.L0f0b2d84
/*  f0b2cf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b2cfc:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b2d00:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f0b2d04:	91440000 */ 	lbu	$a0,0x0($t2)
/*  f0b2d08:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b2d0c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2d10:	15040003 */ 	bne	$t0,$a0,.L0f0b2d20
/*  f0b2d14:	24020023 */ 	addiu	$v0,$zero,0x23
/*  f0b2d18:	10000001 */ 	b	.L0f0b2d20
/*  f0b2d1c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2d20:
/*  f0b2d20:	18400018 */ 	blez	$v0,.L0f0b2d84
/*  f0b2d24:	3c0c800a */ 	lui	$t4,%hi(var8009dd10)
/*  f0b2d28:	8d8cdd10 */ 	lw	$t4,%lo(var8009dd10)($t4)
/*  f0b2d2c:	000668c0 */ 	sll	$t5,$a2,0x3
/*  f0b2d30:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f0b2d34:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f0b2d38:
/*  f0b2d38:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2d3c:	24020023 */ 	addiu	$v0,$zero,0x23
/*  f0b2d40:	15c00009 */ 	bnez	$t6,.L0f0b2d68
/*  f0b2d44:	00000000 */ 	nop
/*  f0b2d48:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*  f0b2d4c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0b2d50:	01002825 */ 	or	$a1,$t0,$zero
/*  f0b2d54:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f0b2d58:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b2d5c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f0b2d60:	10000008 */ 	b	.L0f0b2d84
/*  f0b2d64:	87290014 */ 	lh	$t1,0x14($t9)
.L0f0b2d68:
/*  f0b2d68:	15040003 */ 	bne	$t0,$a0,.L0f0b2d78
/*  f0b2d6c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0b2d70:	10000001 */ 	b	.L0f0b2d78
/*  f0b2d74:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2d78:
/*  f0b2d78:	00c2082a */ 	slt	$at,$a2,$v0
/*  f0b2d7c:	5420ffee */ 	bnezl	$at,.L0f0b2d38
/*  f0b2d80:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f0b2d84:
/*  f0b2d84:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b2d88:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f0b2d8c:	14a00024 */ 	bnez	$a1,.L0f0b2e20
/*  f0b2d90:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b2d94:	29210035 */ 	slti	$at,$t1,0x35
/*  f0b2d98:	10200021 */ 	beqz	$at,.L0f0b2e20
/*  f0b2d9c:	00000000 */ 	nop
/*  f0b2da0:	91440000 */ 	lbu	$a0,0x0($t2)
/*  f0b2da4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2da8:	24020019 */ 	addiu	$v0,$zero,0x19
/*  f0b2dac:	15040003 */ 	bne	$t0,$a0,.L0f0b2dbc
/*  f0b2db0:	3c0b800a */ 	lui	$t3,%hi(var8009dd14)
/*  f0b2db4:	10000001 */ 	b	.L0f0b2dbc
/*  f0b2db8:	24020018 */ 	addiu	$v0,$zero,0x18
.L0f0b2dbc:
/*  f0b2dbc:	18400018 */ 	blez	$v0,.L0f0b2e20
/*  f0b2dc0:	00000000 */ 	nop
/*  f0b2dc4:	8d6bdd14 */ 	lw	$t3,%lo(var8009dd14)($t3)
/*  f0b2dc8:	000660c0 */ 	sll	$t4,$a2,0x3
/*  f0b2dcc:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f0b2dd0:	8c6d0000 */ 	lw	$t5,0x0($v1)
.L0f0b2dd4:
/*  f0b2dd4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2dd8:	24020019 */ 	addiu	$v0,$zero,0x19
/*  f0b2ddc:	15a00009 */ 	bnez	$t5,.L0f0b2e04
/*  f0b2de0:	00000000 */ 	nop
/*  f0b2de4:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f0b2de8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f0b2dec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b2df0:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f0b2df4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b2df8:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f0b2dfc:	10000008 */ 	b	.L0f0b2e20
/*  f0b2e00:	87090014 */ 	lh	$t1,0x14($t8)
.L0f0b2e04:
/*  f0b2e04:	15040003 */ 	bne	$t0,$a0,.L0f0b2e14
/*  f0b2e08:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0b2e0c:	10000001 */ 	b	.L0f0b2e14
/*  f0b2e10:	24020018 */ 	addiu	$v0,$zero,0x18
.L0f0b2e14:
/*  f0b2e14:	00c2082a */ 	slt	$at,$a2,$v0
/*  f0b2e18:	5420ffee */ 	bnezl	$at,.L0f0b2dd4
/*  f0b2e1c:	8c6d0000 */ 	lw	$t5,0x0($v1)
.L0f0b2e20:
/*  f0b2e20:	14a00025 */ 	bnez	$a1,.L0f0b2eb8
/*  f0b2e24:	29210101 */ 	slti	$at,$t1,0x101
/*  f0b2e28:	10200023 */ 	beqz	$at,.L0f0b2eb8
/*  f0b2e2c:	00000000 */ 	nop
/*  f0b2e30:	91440000 */ 	lbu	$a0,0x0($t2)
/*  f0b2e34:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2e38:	24020014 */ 	addiu	$v0,$zero,0x14
/*  f0b2e3c:	15040003 */ 	bne	$t0,$a0,.L0f0b2e4c
/*  f0b2e40:	3c19800a */ 	lui	$t9,%hi(var8009dd18)
/*  f0b2e44:	10000001 */ 	b	.L0f0b2e4c
/*  f0b2e48:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2e4c:
/*  f0b2e4c:	1840001a */ 	blez	$v0,.L0f0b2eb8
/*  f0b2e50:	00000000 */ 	nop
/*  f0b2e54:	8f39dd18 */ 	lw	$t9,%lo(var8009dd18)($t9)
/*  f0b2e58:	000658c0 */ 	sll	$t3,$a2,0x3
/*  f0b2e5c:	032b1821 */ 	addu	$v1,$t9,$t3
/*  f0b2e60:	8c6c0000 */ 	lw	$t4,0x0($v1)
.L0f0b2e64:
/*  f0b2e64:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2e68:	1580000b */ 	bnez	$t4,.L0f0b2e98
/*  f0b2e6c:	00000000 */ 	nop
/*  f0b2e70:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f0b2e74:	10400008 */ 	beqz	$v0,.L0f0b2e98
/*  f0b2e78:	00000000 */ 	nop
/*  f0b2e7c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0b2e80:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0b2e84:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b2e88:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b2e8c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0b2e90:	10000009 */ 	b	.L0f0b2eb8
/*  f0b2e94:	85c90014 */ 	lh	$t1,0x14($t6)
.L0f0b2e98:
/*  f0b2e98:	15040003 */ 	bne	$t0,$a0,.L0f0b2ea8
/*  f0b2e9c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0b2ea0:	10000002 */ 	b	.L0f0b2eac
/*  f0b2ea4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2ea8:
/*  f0b2ea8:	24020014 */ 	addiu	$v0,$zero,0x14
.L0f0b2eac:
/*  f0b2eac:	00c2082a */ 	slt	$at,$a2,$v0
/*  f0b2eb0:	5420ffec */ 	bnezl	$at,.L0f0b2e64
/*  f0b2eb4:	8c6c0000 */ 	lw	$t4,0x0($v1)
.L0f0b2eb8:
/*  f0b2eb8:	14a0003a */ 	bnez	$a1,.L0f0b2fa4
/*  f0b2ebc:	29210101 */ 	slti	$at,$t1,0x101
/*  f0b2ec0:	50200039 */ 	beqzl	$at,.L0f0b2fa8
/*  f0b2ec4:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0b2ec8:	91440000 */ 	lbu	$a0,0x0($t2)
/*  f0b2ecc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b2ed0:	24020014 */ 	addiu	$v0,$zero,0x14
/*  f0b2ed4:	15040003 */ 	bne	$t0,$a0,.L0f0b2ee4
/*  f0b2ed8:	3c0f800a */ 	lui	$t7,%hi(var8009dd18)
/*  f0b2edc:	10000001 */ 	b	.L0f0b2ee4
/*  f0b2ee0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2ee4:
/*  f0b2ee4:	58400030 */ 	blezl	$v0,.L0f0b2fa8
/*  f0b2ee8:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0b2eec:	8defdd18 */ 	lw	$t7,%lo(var8009dd18)($t7)
/*  f0b2ef0:	000638c0 */ 	sll	$a3,$a2,0x3
/*  f0b2ef4:	01e71821 */ 	addu	$v1,$t7,$a3
/*  f0b2ef8:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f0b2efc:
/*  f0b2efc:	5700001b */ 	bnezl	$t8,.L0f0b2f6c
/*  f0b2f00:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2f04:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f0b2f08:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b2f0c:	57200017 */ 	bnezl	$t9,.L0f0b2f6c
/*  f0b2f10:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b2f14:	24040400 */ 	addiu	$a0,$zero,0x400
/*  f0b2f18:	0c0048f2 */ 	jal	mempAlloc
/*  f0b2f1c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f0b2f20:	3c04800a */ 	lui	$a0,%hi(var8009dd10)
/*  f0b2f24:	2484dd10 */ 	addiu	$a0,$a0,%lo(var8009dd10)
/*  f0b2f28:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*  f0b2f2c:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f0b2f30:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b2f34:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f0b2f38:	01676021 */ 	addu	$t4,$t3,$a3
/*  f0b2f3c:	ad820004 */ 	sw	$v0,0x4($t4)
/*  f0b2f40:	8c8d0008 */ 	lw	$t5,0x8($a0)
/*  f0b2f44:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f0b2f48:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b2f4c:	01a71821 */ 	addu	$v1,$t5,$a3
/*  f0b2f50:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f0b2f54:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f0b2f58:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b2f5c:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f0b2f60:	10000010 */ 	b	.L0f0b2fa4
/*  f0b2f64:	87090014 */ 	lh	$t1,0x14($t8)
/*  f0b2f68:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0b2f6c:
/*  f0b2f6c:	24e70008 */ 	addiu	$a3,$a3,8
/*  f0b2f70:	15040003 */ 	bne	$t0,$a0,.L0f0b2f80
/*  f0b2f74:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0b2f78:	10000002 */ 	b	.L0f0b2f84
/*  f0b2f7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b2f80:
/*  f0b2f80:	24020014 */ 	addiu	$v0,$zero,0x14
.L0f0b2f84:
/*  f0b2f84:	00c2082a */ 	slt	$at,$a2,$v0
/*  f0b2f88:	5420ffdc */ 	bnezl	$at,.L0f0b2efc
/*  f0b2f8c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0b2f90:	10000005 */ 	b	.L0f0b2fa8
/*  f0b2f94:	8fb90044 */ 	lw	$t9,0x44($sp)
.L0f0b2f98:
/*  f0b2f98:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b2f9c:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f0b2fa0:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0b2fa4:
/*  f0b2fa4:	8fb90044 */ 	lw	$t9,0x44($sp)
.L0f0b2fa8:
/*  f0b2fa8:	13200003 */ 	beqz	$t9,.L0f0b2fb8
/*  f0b2fac:	240b0100 */ 	addiu	$t3,$zero,0x100
/*  f0b2fb0:	10000009 */ 	b	.L0f0b2fd8
/*  f0b2fb4:	a7ab0036 */ 	sh	$t3,0x36($sp)
.L0f0b2fb8:
/*  f0b2fb8:	914c0000 */ 	lbu	$t4,0x0($t2)
/*  f0b2fbc:	240e0100 */ 	addiu	$t6,$zero,0x100
/*  f0b2fc0:	240d0034 */ 	addiu	$t5,$zero,0x34
/*  f0b2fc4:	550c0004 */ 	bnel	$t0,$t4,.L0f0b2fd8
/*  f0b2fc8:	a7ae0036 */ 	sh	$t6,0x36($sp)
/*  f0b2fcc:	10000002 */ 	b	.L0f0b2fd8
/*  f0b2fd0:	a7ad0036 */ 	sh	$t5,0x36($sp)
/*  f0b2fd4:	a7ae0036 */ 	sh	$t6,0x36($sp)
.L0f0b2fd8:
/*  f0b2fd8:	87af0036 */ 	lh	$t7,0x36($sp)
/*  f0b2fdc:	01e9082a */ 	slt	$at,$t7,$t1
/*  f0b2fe0:	50200003 */ 	beqzl	$at,.L0f0b2ff0
/*  f0b2fe4:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f0b2fe8:	a7a90036 */ 	sh	$t1,0x36($sp)
/*  f0b2fec:	8fb80038 */ 	lw	$t8,0x38($sp)
.L0f0b2ff0:
/*  f0b2ff0:	5700000a */ 	bnezl	$t8,.L0f0b301c
/*  f0b2ff4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0b2ff8:	87a40036 */ 	lh	$a0,0x36($sp)
/*  f0b2ffc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b3000:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f0b3004:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f0b3008:	348b000f */ 	ori	$t3,$a0,0xf
/*  f0b300c:	0c0048f2 */ 	jal	mempAlloc
/*  f0b3010:	3964000f */ 	xori	$a0,$t3,0xf
/*  f0b3014:	afa20038 */ 	sw	$v0,0x38($sp)
.L0f0b3018:
/*  f0b3018:	8fad003c */ 	lw	$t5,0x3c($sp)
.L0f0b301c:
/*  f0b301c:	51a00015 */ 	beqzl	$t5,.L0f0b3074
/*  f0b3020:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f0b3024:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0b3028:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0b302c:	51c00010 */ 	beqzl	$t6,.L0f0b3070
/*  f0b3030:	af000020 */ 	sw	$zero,0x20($t8)
/*  f0b3034:	0fc2ccb9 */ 	jal	func0f0b32e4
/*  f0b3038:	00000000 */ 	nop
/*  f0b303c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f0b3040:	10400005 */ 	beqz	$v0,.L0f0b3058
/*  f0b3044:	ade20020 */ 	sw	$v0,0x20($t7)
/*  f0b3048:	0c008c28 */ 	jal	animInit
/*  f0b304c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b3050:	10000008 */ 	b	.L0f0b3074
/*  f0b3054:	8fb9003c */ 	lw	$t9,0x3c($sp)
.L0f0b3058:
/*  f0b3058:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0b305c:	0fc2cc33 */ 	jal	modelFree
/*  f0b3060:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f0b3064:	10000003 */ 	b	.L0f0b3074
/*  f0b3068:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f0b306c:	af000020 */ 	sw	$zero,0x20($t8)
.L0f0b3070:
/*  f0b3070:	8fb9003c */ 	lw	$t9,0x3c($sp)
.L0f0b3074:
/*  f0b3074:	13200008 */ 	beqz	$t9,.L0f0b3098
/*  f0b3078:	03202025 */ 	or	$a0,$t9,$zero
/*  f0b307c:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0b3080:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0b3084:	0c008be9 */ 	jal	modelInit
/*  f0b3088:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b308c:	87ab0036 */ 	lh	$t3,0x36($sp)
/*  f0b3090:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f0b3094:	a58b0002 */ 	sh	$t3,0x2($t4)
.L0f0b3098:
/*  f0b3098:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b309c:	8fa2003c */ 	lw	$v0,0x3c($sp)
/*  f0b30a0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0b30a4:	03e00008 */ 	jr	$ra
/*  f0b30a8:	00000000 */ 	nop
);

struct model *modelInstantiate(struct modelfiledata *modelfiledata)
{
	return func0f0b2b64(modelfiledata, false);
}

void modelFree(struct model *model)
{
	bool done = false;
	s32 i;

	for (i = 0; i < NUMTHINGS1(); i++) {
		if (var8009dd10[i].model == model) {
			var8009dd10[i].model = NULL;

			model->rwdatas = NULL;
			model->unk02 = -1;

			done = true;
			break;
		}
	}

	if (!done) {
		for (i = 0; i < NUMTHINGS2(); i++) {
			if (var8009dd14[i].model == model) {
				var8009dd14[i].model = NULL;

				model->rwdatas = NULL;
				model->unk02 = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		for (i = 0; i < NUMTHINGS3(); i++) {
			if (var8009dd18[i].model == model) {
				var8009dd18[i].model = NULL;

				model->rwdatas = NULL;
				model->unk02 = -1;
				break;
			}
		}
	}

	if (model->anim) {
		animTurnOff(model->anim);
		model->anim = NULL;
	}

	model->filedata = NULL;
}

struct model *func0f0b3280(struct modelfiledata *modelfiledata)
{
	return func0f0b2b64(modelfiledata, true);
}

void func0f0b32a0(struct model *model, struct modelnode *node, struct modelfiledata *headmodeldef)
{
	model00023108(model, model->filedata, node, headmodeldef);
	modelInitRwData(model, headmodeldef->rootnode);
}

struct anim *func0f0b32e4(void)
{
	s32 i;
	struct anim *anim = NULL;

	for (i = 0; i < var800705a4; i++) {
		if (var8009dd04[i].animnum == -1) {
			anim = &var8009dd04[i];
			break;
		}
	}

	return anim;
}

void animTurnOff(struct anim *anim)
{
	anim->animnum = -1;
}
