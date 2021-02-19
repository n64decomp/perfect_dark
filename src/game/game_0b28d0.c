#include <ultra64.h>
#include "constants.h"
#include "game/game_0b28d0.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

u32 var8009dd00;
u32 var8009dd04;
u32 var8009dd08;
u32 var8009dd0c;
u32 var8009dd10;
u32 var8009dd14;
u32 var8009dd18;
u32 var8009dd1c;

u32 var800705a0 = 0x00000000;
u32 var800705a4 = 0x00000000;
bool var800705a8 = false;
u32 var800705ac = 0x00000000;
u32 var800705b0 = 0x00000000;
u32 var800705b4 = 0x00000000;
u32 var800705b8 = 0x00000000;
u32 var800705bc = 0x00000000;

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

GLOBAL_ASM(
glabel func0f0b2904
/*  f0b2904:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f0b2908:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f0b290c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0b2910:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b2914:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b2918:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b291c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b2920:	00004025 */ 	or	$t0,$zero,$zero
/*  f0b2924:	14620003 */ 	bne	$v1,$v0,.L0f0b2934
/*  f0b2928:	00004825 */ 	or	$t1,$zero,$zero
/*  f0b292c:	10000002 */ 	b	.L0f0b2938
/*  f0b2930:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b2934:
/*  f0b2934:	240a0023 */ 	addiu	$t2,$zero,0x23
.L0f0b2938:
/*  f0b2938:	19400012 */ 	blez	$t2,.L0f0b2984
/*  f0b293c:	3c0e800a */ 	lui	$t6,%hi(var8009dd10)
/*  f0b2940:	8dcedd10 */ 	lw	$t6,%lo(var8009dd10)($t6)
/*  f0b2944:	000978c0 */ 	sll	$t7,$t1,0x3
/*  f0b2948:	01cf5821 */ 	addu	$t3,$t6,$t7
/*  f0b294c:	8d780000 */ 	lw	$t8,0x0($t3)
.L0f0b2950:
/*  f0b2950:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f0b2954:	240a0023 */ 	addiu	$t2,$zero,0x23
/*  f0b2958:	13000002 */ 	beqz	$t8,.L0f0b2964
/*  f0b295c:	00000000 */ 	nop
/*  f0b2960:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0b2964:
/*  f0b2964:	14620003 */ 	bne	$v1,$v0,.L0f0b2974
/*  f0b2968:	256b0008 */ 	addiu	$t3,$t3,0x8
/*  f0b296c:	10000001 */ 	b	.L0f0b2974
/*  f0b2970:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b2974:
/*  f0b2974:	012a082a */ 	slt	$at,$t1,$t2
/*  f0b2978:	5420fff5 */ 	bnezl	$at,.L0f0b2950
/*  f0b297c:	8d780000 */ 	lw	$t8,0x0($t3)
/*  f0b2980:	00004825 */ 	or	$t1,$zero,$zero
.L0f0b2984:
/*  f0b2984:	54620004 */ 	bnel	$v1,$v0,.L0f0b2998
/*  f0b2988:	240a0019 */ 	addiu	$t2,$zero,0x19
/*  f0b298c:	10000002 */ 	b	.L0f0b2998
/*  f0b2990:	240a0018 */ 	addiu	$t2,$zero,0x18
/*  f0b2994:	240a0019 */ 	addiu	$t2,$zero,0x19
.L0f0b2998:
/*  f0b2998:	19400012 */ 	blez	$t2,.L0f0b29e4
/*  f0b299c:	3c19800a */ 	lui	$t9,%hi(var8009dd14)
/*  f0b29a0:	8f39dd14 */ 	lw	$t9,%lo(var8009dd14)($t9)
/*  f0b29a4:	000968c0 */ 	sll	$t5,$t1,0x3
/*  f0b29a8:	032d5821 */ 	addu	$t3,$t9,$t5
/*  f0b29ac:	8d6e0000 */ 	lw	$t6,0x0($t3)
.L0f0b29b0:
/*  f0b29b0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f0b29b4:	240a0019 */ 	addiu	$t2,$zero,0x19
/*  f0b29b8:	11c00002 */ 	beqz	$t6,.L0f0b29c4
/*  f0b29bc:	00000000 */ 	nop
/*  f0b29c0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0b29c4:
/*  f0b29c4:	14620003 */ 	bne	$v1,$v0,.L0f0b29d4
/*  f0b29c8:	256b0008 */ 	addiu	$t3,$t3,0x8
/*  f0b29cc:	10000001 */ 	b	.L0f0b29d4
/*  f0b29d0:	240a0018 */ 	addiu	$t2,$zero,0x18
.L0f0b29d4:
/*  f0b29d4:	012a082a */ 	slt	$at,$t1,$t2
/*  f0b29d8:	5420fff5 */ 	bnezl	$at,.L0f0b29b0
/*  f0b29dc:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0b29e0:	00004825 */ 	or	$t1,$zero,$zero
.L0f0b29e4:
/*  f0b29e4:	14620003 */ 	bne	$v1,$v0,.L0f0b29f4
/*  f0b29e8:	240a0014 */ 	addiu	$t2,$zero,0x14
/*  f0b29ec:	10000001 */ 	b	.L0f0b29f4
/*  f0b29f0:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b29f4:
/*  f0b29f4:	19400011 */ 	blez	$t2,.L0f0b2a3c
/*  f0b29f8:	3c0f800a */ 	lui	$t7,%hi(var8009dd18)
/*  f0b29fc:	8defdd18 */ 	lw	$t7,%lo(var8009dd18)($t7)
/*  f0b2a00:	0009c0c0 */ 	sll	$t8,$t1,0x3
/*  f0b2a04:	01f85821 */ 	addu	$t3,$t7,$t8
/*  f0b2a08:	8d790000 */ 	lw	$t9,0x0($t3)
.L0f0b2a0c:
/*  f0b2a0c:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f0b2a10:	240a0014 */ 	addiu	$t2,$zero,0x14
/*  f0b2a14:	13200002 */ 	beqz	$t9,.L0f0b2a20
/*  f0b2a18:	00000000 */ 	nop
/*  f0b2a1c:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0b2a20:
/*  f0b2a20:	14620003 */ 	bne	$v1,$v0,.L0f0b2a30
/*  f0b2a24:	256b0008 */ 	addiu	$t3,$t3,0x8
/*  f0b2a28:	10000001 */ 	b	.L0f0b2a30
/*  f0b2a2c:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b2a30:
/*  f0b2a30:	012a082a */ 	slt	$at,$t1,$t2
/*  f0b2a34:	5420fff5 */ 	bnezl	$at,.L0f0b2a0c
/*  f0b2a38:	8d790000 */ 	lw	$t9,0x0($t3)
.L0f0b2a3c:
/*  f0b2a3c:	3c098007 */ 	lui	$t1,%hi(var800705a0)
/*  f0b2a40:	8d2905a0 */ 	lw	$t1,%lo(var800705a0)($t1)
/*  f0b2a44:	00005025 */ 	or	$t2,$zero,$zero
/*  f0b2a48:	3c0b800a */ 	lui	$t3,%hi(var8009dd00)
/*  f0b2a4c:	1920000c */ 	blez	$t1,.L0f0b2a80
/*  f0b2a50:	000960c0 */ 	sll	$t4,$t1,0x3
/*  f0b2a54:	01896021 */ 	addu	$t4,$t4,$t1
/*  f0b2a58:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b2a5c:	8d6bdd00 */ 	lw	$t3,%lo(var8009dd00)($t3)
.L0f0b2a60:
/*  f0b2a60:	8d6d0008 */ 	lw	$t5,0x8($t3)
/*  f0b2a64:	254a0024 */ 	addiu	$t2,$t2,0x24
/*  f0b2a68:	014c082a */ 	slt	$at,$t2,$t4
/*  f0b2a6c:	11a00002 */ 	beqz	$t5,.L0f0b2a78
/*  f0b2a70:	00000000 */ 	nop
/*  f0b2a74:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f0b2a78:
/*  f0b2a78:	1420fff9 */ 	bnez	$at,.L0f0b2a60
/*  f0b2a7c:	256b0024 */ 	addiu	$t3,$t3,36
.L0f0b2a80:
/*  f0b2a80:	3c098007 */ 	lui	$t1,%hi(var800705a4)
/*  f0b2a84:	8d2905a4 */ 	lw	$t1,%lo(var800705a4)($t1)
/*  f0b2a88:	00005025 */ 	or	$t2,$zero,$zero
/*  f0b2a8c:	3c0b800a */ 	lui	$t3,%hi(var8009dd04)
/*  f0b2a90:	1920000f */ 	blez	$t1,.L0f0b2ad0
/*  f0b2a94:	000960c0 */ 	sll	$t4,$t1,0x3
/*  f0b2a98:	01896021 */ 	addu	$t4,$t4,$t1
/*  f0b2a9c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b2aa0:	01896023 */ 	subu	$t4,$t4,$t1
/*  f0b2aa4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b2aa8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0b2aac:	8d6bdd04 */ 	lw	$t3,%lo(var8009dd04)($t3)
.L0f0b2ab0:
/*  f0b2ab0:	856e0000 */ 	lh	$t6,0x0($t3)
/*  f0b2ab4:	254a008c */ 	addiu	$t2,$t2,0x8c
/*  f0b2ab8:	014c082a */ 	slt	$at,$t2,$t4
/*  f0b2abc:	112e0002 */ 	beq	$t1,$t6,.L0f0b2ac8
/*  f0b2ac0:	00000000 */ 	nop
/*  f0b2ac4:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f0b2ac8:
/*  f0b2ac8:	1420fff9 */ 	bnez	$at,.L0f0b2ab0
/*  f0b2acc:	256b008c */ 	addiu	$t3,$t3,140
.L0f0b2ad0:
/*  f0b2ad0:	3c098007 */ 	lui	$t1,%hi(var800705ac)
/*  f0b2ad4:	252905ac */ 	addiu	$t1,$t1,%lo(var800705ac)
/*  f0b2ad8:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f0b2adc:	01e4082a */ 	slt	$at,$t7,$a0
/*  f0b2ae0:	10200002 */ 	beqz	$at,.L0f0b2aec
/*  f0b2ae4:	00000000 */ 	nop
/*  f0b2ae8:	ad240000 */ 	sw	$a0,0x0($t1)
.L0f0b2aec:
/*  f0b2aec:	3c048007 */ 	lui	$a0,%hi(var800705b0)
/*  f0b2af0:	248405b0 */ 	addiu	$a0,$a0,%lo(var800705b0)
/*  f0b2af4:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0b2af8:	0305082a */ 	slt	$at,$t8,$a1
/*  f0b2afc:	10200002 */ 	beqz	$at,.L0f0b2b08
/*  f0b2b00:	00000000 */ 	nop
/*  f0b2b04:	ac850000 */ 	sw	$a1,0x0($a0)
.L0f0b2b08:
/*  f0b2b08:	3c048007 */ 	lui	$a0,%hi(var800705b4)
/*  f0b2b0c:	248405b4 */ 	addiu	$a0,$a0,%lo(var800705b4)
/*  f0b2b10:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f0b2b14:	0326082a */ 	slt	$at,$t9,$a2
/*  f0b2b18:	10200002 */ 	beqz	$at,.L0f0b2b24
/*  f0b2b1c:	00000000 */ 	nop
/*  f0b2b20:	ac860000 */ 	sw	$a2,0x0($a0)
.L0f0b2b24:
/*  f0b2b24:	3c048007 */ 	lui	$a0,%hi(var800705b8)
/*  f0b2b28:	248405b8 */ 	addiu	$a0,$a0,%lo(var800705b8)
/*  f0b2b2c:	8c8d0000 */ 	lw	$t5,0x0($a0)
/*  f0b2b30:	01a7082a */ 	slt	$at,$t5,$a3
/*  f0b2b34:	10200002 */ 	beqz	$at,.L0f0b2b40
/*  f0b2b38:	00000000 */ 	nop
/*  f0b2b3c:	ac870000 */ 	sw	$a3,0x0($a0)
.L0f0b2b40:
/*  f0b2b40:	3c048007 */ 	lui	$a0,%hi(var800705bc)
/*  f0b2b44:	248405bc */ 	addiu	$a0,$a0,%lo(var800705bc)
/*  f0b2b48:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0b2b4c:	01c8082a */ 	slt	$at,$t6,$t0
/*  f0b2b50:	10200002 */ 	beqz	$at,.L0f0b2b5c
/*  f0b2b54:	00000000 */ 	nop
/*  f0b2b58:	ac880000 */ 	sw	$t0,0x0($a0)
.L0f0b2b5c:
/*  f0b2b5c:	03e00008 */ 	jr	$ra
/*  f0b2b60:	00000000 */ 	nop
);

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
/*  f0b2c8c:	0c0048f2 */ 	jal	malloc
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
/*  f0b2cd4:	0c0048f2 */ 	jal	malloc
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
/*  f0b2f18:	0c0048f2 */ 	jal	malloc
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
/*  f0b300c:	0c0048f2 */ 	jal	malloc
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
/*  f0b3048:	0c008c28 */ 	jal	animInitialise
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
/*  f0b3084:	0c008be9 */ 	jal	func00022fa4
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

GLOBAL_ASM(
glabel func0f0b30ac
/*  f0b30ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b30b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b30b4:	0fc2cad9 */ 	jal	func0f0b2b64
/*  f0b30b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b30bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b30c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b30c4:	03e00008 */ 	jr	$ra
/*  f0b30c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel modelFree
/*  f0b30cc:	3c098009 */ 	lui	$t1,%hi(g_Is4Mb)
/*  f0b30d0:	25290af0 */ 	addiu	$t1,$t1,%lo(g_Is4Mb)
/*  f0b30d4:	91250000 */ 	lbu	$a1,0x0($t1)
/*  f0b30d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b30dc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0b30e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b30e4:	00803025 */ 	or	$a2,$a0,$zero
/*  f0b30e8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0b30ec:	14e50003 */ 	bne	$a3,$a1,.L0f0b30fc
/*  f0b30f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b30f4:	10000002 */ 	b	.L0f0b3100
/*  f0b30f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b30fc:
/*  f0b30fc:	24020023 */ 	addiu	$v0,$zero,0x23
.L0f0b3100:
/*  f0b3100:	18400016 */ 	blez	$v0,.L0f0b315c
/*  f0b3104:	3c0e800a */ 	lui	$t6,%hi(var8009dd10)
/*  f0b3108:	8dcedd10 */ 	lw	$t6,%lo(var8009dd10)($t6)
/*  f0b310c:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f0b3110:	240affff */ 	addiu	$t2,$zero,-1
/*  f0b3114:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f0b3118:	8c980000 */ 	lw	$t8,0x0($a0)
.L0f0b311c:
/*  f0b311c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b3120:	24020023 */ 	addiu	$v0,$zero,0x23
/*  f0b3124:	14d80006 */ 	bne	$a2,$t8,.L0f0b3140
/*  f0b3128:	00000000 */ 	nop
/*  f0b312c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0b3130:	acc00010 */ 	sw	$zero,0x10($a2)
/*  f0b3134:	a4ca0002 */ 	sh	$t2,0x2($a2)
/*  f0b3138:	10000008 */ 	b	.L0f0b315c
/*  f0b313c:	00e04025 */ 	or	$t0,$a3,$zero
.L0f0b3140:
/*  f0b3140:	14e50003 */ 	bne	$a3,$a1,.L0f0b3150
/*  f0b3144:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0b3148:	10000001 */ 	b	.L0f0b3150
/*  f0b314c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b3150:
/*  f0b3150:	0062082a */ 	slt	$at,$v1,$v0
/*  f0b3154:	5420fff1 */ 	bnezl	$at,.L0f0b311c
/*  f0b3158:	8c980000 */ 	lw	$t8,0x0($a0)
.L0f0b315c:
/*  f0b315c:	1500001e */ 	bnez	$t0,.L0f0b31d8
/*  f0b3160:	240affff */ 	addiu	$t2,$zero,-1
/*  f0b3164:	91250000 */ 	lbu	$a1,0x0($t1)
/*  f0b3168:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b316c:	24020019 */ 	addiu	$v0,$zero,0x19
/*  f0b3170:	14e50003 */ 	bne	$a3,$a1,.L0f0b3180
/*  f0b3174:	3c19800a */ 	lui	$t9,%hi(var8009dd14)
/*  f0b3178:	10000001 */ 	b	.L0f0b3180
/*  f0b317c:	24020018 */ 	addiu	$v0,$zero,0x18
.L0f0b3180:
/*  f0b3180:	18400015 */ 	blez	$v0,.L0f0b31d8
/*  f0b3184:	00000000 */ 	nop
/*  f0b3188:	8f39dd14 */ 	lw	$t9,%lo(var8009dd14)($t9)
/*  f0b318c:	000358c0 */ 	sll	$t3,$v1,0x3
/*  f0b3190:	032b2021 */ 	addu	$a0,$t9,$t3
/*  f0b3194:	8c8c0000 */ 	lw	$t4,0x0($a0)
.L0f0b3198:
/*  f0b3198:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b319c:	24020019 */ 	addiu	$v0,$zero,0x19
/*  f0b31a0:	14cc0006 */ 	bne	$a2,$t4,.L0f0b31bc
/*  f0b31a4:	00000000 */ 	nop
/*  f0b31a8:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0b31ac:	acc00010 */ 	sw	$zero,0x10($a2)
/*  f0b31b0:	a4ca0002 */ 	sh	$t2,0x2($a2)
/*  f0b31b4:	10000008 */ 	b	.L0f0b31d8
/*  f0b31b8:	00e04025 */ 	or	$t0,$a3,$zero
.L0f0b31bc:
/*  f0b31bc:	14e50003 */ 	bne	$a3,$a1,.L0f0b31cc
/*  f0b31c0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0b31c4:	10000001 */ 	b	.L0f0b31cc
/*  f0b31c8:	24020018 */ 	addiu	$v0,$zero,0x18
.L0f0b31cc:
/*  f0b31cc:	0062082a */ 	slt	$at,$v1,$v0
/*  f0b31d0:	5420fff1 */ 	bnezl	$at,.L0f0b3198
/*  f0b31d4:	8c8c0000 */ 	lw	$t4,0x0($a0)
.L0f0b31d8:
/*  f0b31d8:	5500001e */ 	bnezl	$t0,.L0f0b3254
/*  f0b31dc:	8cc40020 */ 	lw	$a0,0x20($a2)
/*  f0b31e0:	91250000 */ 	lbu	$a1,0x0($t1)
/*  f0b31e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b31e8:	24020014 */ 	addiu	$v0,$zero,0x14
/*  f0b31ec:	14e50003 */ 	bne	$a3,$a1,.L0f0b31fc
/*  f0b31f0:	3c0d800a */ 	lui	$t5,%hi(var8009dd18)
/*  f0b31f4:	10000001 */ 	b	.L0f0b31fc
/*  f0b31f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b31fc:
/*  f0b31fc:	58400015 */ 	blezl	$v0,.L0f0b3254
/*  f0b3200:	8cc40020 */ 	lw	$a0,0x20($a2)
/*  f0b3204:	8daddd18 */ 	lw	$t5,%lo(var8009dd18)($t5)
/*  f0b3208:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f0b320c:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f0b3210:	8c8f0000 */ 	lw	$t7,0x0($a0)
.L0f0b3214:
/*  f0b3214:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b3218:	24020014 */ 	addiu	$v0,$zero,0x14
/*  f0b321c:	14cf0005 */ 	bne	$a2,$t7,.L0f0b3234
/*  f0b3220:	00000000 */ 	nop
/*  f0b3224:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0b3228:	acc00010 */ 	sw	$zero,0x10($a2)
/*  f0b322c:	10000008 */ 	b	.L0f0b3250
/*  f0b3230:	a4ca0002 */ 	sh	$t2,0x2($a2)
.L0f0b3234:
/*  f0b3234:	14e50003 */ 	bne	$a3,$a1,.L0f0b3244
/*  f0b3238:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0b323c:	10000001 */ 	b	.L0f0b3244
/*  f0b3240:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b3244:
/*  f0b3244:	0062082a */ 	slt	$at,$v1,$v0
/*  f0b3248:	5420fff2 */ 	bnezl	$at,.L0f0b3214
/*  f0b324c:	8c8f0000 */ 	lw	$t7,0x0($a0)
.L0f0b3250:
/*  f0b3250:	8cc40020 */ 	lw	$a0,0x20($a2)
.L0f0b3254:
/*  f0b3254:	50800006 */ 	beqzl	$a0,.L0f0b3270
/*  f0b3258:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f0b325c:	0fc2ccce */ 	jal	animTurnOff
/*  f0b3260:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f0b3264:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f0b3268:	acc00020 */ 	sw	$zero,0x20($a2)
/*  f0b326c:	acc00008 */ 	sw	$zero,0x8($a2)
.L0f0b3270:
/*  f0b3270:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b3274:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b3278:	03e00008 */ 	jr	$ra
/*  f0b327c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b3280
/*  f0b3280:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b3284:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b3288:	0fc2cad9 */ 	jal	func0f0b2b64
/*  f0b328c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b3290:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b3294:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b3298:	03e00008 */ 	jr	$ra
/*  f0b329c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b32a0
/*  f0b32a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b32a4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0b32a8:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0b32ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b32b0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b32b4:	8c850008 */ 	lw	$a1,0x8($a0)
/*  f0b32b8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0b32bc:	0c008c42 */ 	jal	func00023108
/*  f0b32c0:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f0b32c4:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0b32c8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0b32cc:	0c008b54 */ 	jal	func00022d50
/*  f0b32d0:	8dc50000 */ 	lw	$a1,0x0($t6)
/*  f0b32d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b32d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b32dc:	03e00008 */ 	jr	$ra
/*  f0b32e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b32e4
/*  f0b32e4:	3c048007 */ 	lui	$a0,%hi(var800705a4)
/*  f0b32e8:	8c8405a4 */ 	lw	$a0,%lo(var800705a4)($a0)
/*  f0b32ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b32f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b32f4:	1880000e */ 	blez	$a0,.L0f0b3330
/*  f0b32f8:	3c05800a */ 	lui	$a1,%hi(var8009dd04)
/*  f0b32fc:	8ca5dd04 */ 	lw	$a1,%lo(var8009dd04)($a1)
/*  f0b3300:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b3304:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0b3308:	00a03825 */ 	or	$a3,$a1,$zero
.L0f0b330c:
/*  f0b330c:	84ee0000 */ 	lh	$t6,0x0($a3)
/*  f0b3310:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0b3314:	0044082a */ 	slt	$at,$v0,$a0
/*  f0b3318:	150e0003 */ 	bne	$t0,$t6,.L0f0b3328
/*  f0b331c:	24e7008c */ 	addiu	$a3,$a3,0x8c
/*  f0b3320:	03e00008 */ 	jr	$ra
/*  f0b3324:	00c51021 */ 	addu	$v0,$a2,$a1
.L0f0b3328:
/*  f0b3328:	1420fff8 */ 	bnez	$at,.L0f0b330c
/*  f0b332c:	24c6008c */ 	addiu	$a2,$a2,0x8c
.L0f0b3330:
/*  f0b3330:	03e00008 */ 	jr	$ra
/*  f0b3334:	00601025 */ 	or	$v0,$v1,$zero
);

void animTurnOff(struct anim *anim)
{
	anim->animnum = -1;
}
