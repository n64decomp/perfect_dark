#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/dlights.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/propobj.h"
#include "game/game_091e10.h"
#include "game/game_092610.h"
#include "game/game_0b3350.h"
#include "game/game_129900.h"
#include "game/game_12d3f0.h"
#include "game/wallhit.h"
#include "game/game_157db0.h"
#include "game/game_1668e0.h"
#include "game/game_166e40.h"
#include "game/utils.h"
#include "game/mplayer.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
#include "types.h"

const char var7f1b5230[] = "VTXSTORE : vtxfixrefs -> Start - p1=%x, p2=%x\n";
const char var7f1b5260[] = "vtxfixrefs : Part=%x -- Mapping ptr %x -> %x\n";
const char var7f1b5290[] = "VTXSTORE : vtxfixrefs -> End - Done=%d\n";
const char var7f1b52b8[] = "vtxstorecheck : memaFree -> %u bytes at Ptr=%x(%x)\n";
const char var7f1b52ec[] = "vtxstorecheck : At block 1 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5320[] = "vtxstorecheck : At block 2 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5354[] = "vtx buffer low, need to delete objects\n";
const char var7f1b537c[] = "getfreevertices : %d of type %d -> ref1=%x, ref2=%x\n";
const char var7f1b53b4[] = "vtxstore: 1st mema alloc of %u bytes\n";
const char var7f1b53dc[] = "getfreevertices : Return ptr = %x\n";
const char var7f1b5400[] = "vtxstore: Out of mema (returning NULL)\n";
const char var7f1b5428[] = "vtxstore: GROSS! CorspeCount > MAX_CORPSES corpses! Freeing corpse %x\n";
const char var7f1b5470[] = "vtxstore:  CorpseCount %d, Trying to free %d\n";
const char var7f1b54a0[] = "vtxstore: Freeing corpse %x\n";
const char var7f1b54c0[] = "vtxstore: Out of vertices type %d wanted %d free %d (returning NULL)\n";
const char var7f1b5508[] = "vtxstore: freevertices type %d, list %x\n";
const char var7f1b5534[] = "freevertices: address not found in array %x\n";
const char var7f1b5564[] = "";
const char var7f1b5568[] = "";
const char var7f1b556c[] = "";
const char var7f1b5570[] = "ecol";

GLOBAL_ASM(
glabel func0f129900
/*  f129900:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f129904:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f129908:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f12990c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f129910:	00077400 */ 	sll	$t6,$a3,0x10
/*  f129914:	000e3c03 */ 	sra	$a3,$t6,0x10
/*  f129918:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f12991c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f129920:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f129924:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f129928:	0fc4a7d5 */ 	jal	func0f129f54
/*  f12992c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f129930:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f129934:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f129938:	03e00008 */ 	jr	$ra
/*  f12993c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f129940
/*  f129940:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f129944:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f129948:	87ae007e */ 	lh	$t6,0x7e($sp)
/*  f12994c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f129950:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f129954:	00808025 */ 	or	$s0,$a0,$zero
/*  f129958:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12995c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f129960:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f129964:	15c00003 */ 	bnez	$t6,.L0f129974
/*  f129968:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f12996c:	10000061 */ 	beqz	$zero,.L0f129af4
/*  f129970:	00001025 */ 	or	$v0,$zero,$zero
.L0f129974:
/*  f129974:	12000016 */ 	beqz	$s0,.L0f1299d0
/*  f129978:	02202025 */ 	or	$a0,$s1,$zero
/*  f12997c:	27af0058 */ 	addiu	$t7,$sp,0x58
/*  f129980:	27b80044 */ 	addiu	$t8,$sp,0x44
/*  f129984:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f129988:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f12998c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f129990:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f129994:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f129998:	00003825 */ 	or	$a3,$zero,$zero
/*  f12999c:	0c00a959 */ 	jal	func0002a564
/*  f1299a0:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f1299a4:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f1299a8:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f1299ac:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f1299b0:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f1299b4:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f1299b8:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f1299bc:	0003cc03 */ 	sra	$t9,$v1,0x10
/*  f1299c0:	03201825 */ 	or	$v1,$t9,$zero
/*  f1299c4:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f1299c8:	10000014 */ 	beqz	$zero,.L0f129a1c
/*  f1299cc:	e7a8006c */ 	swc1	$f8,0x6c($sp)
.L0f1299d0:
/*  f1299d0:	27a90058 */ 	addiu	$t1,$sp,0x58
/*  f1299d4:	27aa0044 */ 	addiu	$t2,$sp,0x44
/*  f1299d8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f1299dc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f1299e0:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f1299e4:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f1299e8:	00003825 */ 	or	$a3,$zero,$zero
/*  f1299ec:	0c00a959 */ 	jal	func0002a564
/*  f1299f0:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f1299f4:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f1299f8:	c7b00048 */ 	lwc1	$f16,0x48($sp)
/*  f1299fc:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f129a00:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*  f129a04:	e7b00068 */ 	swc1	$f16,0x68($sp)
/*  f129a08:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f129a0c:	00035c03 */ 	sra	$t3,$v1,0x10
/*  f129a10:	01601825 */ 	or	$v1,$t3,$zero
/*  f129a14:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f129a18:	e7b2006c */ 	swc1	$f18,0x6c($sp)
.L0f129a1c:
/*  f129a1c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f129a20:	02002025 */ 	or	$a0,$s0,$zero
/*  f129a24:	02202825 */ 	or	$a1,$s1,$zero
/*  f129a28:	15800027 */ 	bnez	$t4,.L0f129ac8
/*  f129a2c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f129a30:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f129a34:	000d7403 */ 	sra	$t6,$t5,0x10
/*  f129a38:	19c00023 */ 	blez	$t6,.L0f129ac8
/*  f129a3c:	87af007e */ 	lh	$t7,0x7e($sp)
/*  f129a40:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f129a44:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f129a48:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f129a4c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f129a50:	3c198008 */ 	lui	$t9,%hi(g_ExplosionTypes)
/*  f129a54:	2739e4b8 */ 	addiu	$t9,$t9,%lo(g_ExplosionTypes)
/*  f129a58:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f129a5c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f129a60:	8449001c */ 	lh	$t1,0x1c($v0)
/*  f129a64:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f129a68:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f129a6c:	44895000 */ 	mtc1	$t1,$f10
/*  f129a70:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f129a74:	3c013f00 */ 	lui	$at,0x3f00
/*  f129a78:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f129a7c:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f129a80:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f129a84:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f129a88:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f129a8c:	44818000 */ 	mtc1	$at,$f16
/*  f129a90:	3c014296 */ 	lui	$at,0x4296
/*  f129a94:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f129a98:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f129a9c:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f129aa0:	4604003e */ 	c.le.s	$f0,$f4
/*  f129aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129aa8:	45030009 */ 	bc1tl	.L0f129ad0
/*  f129aac:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f129ab0:	44819000 */ 	mtc1	$at,$f18
/*  f129ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129ab8:	4612003e */ 	c.le.s	$f0,$f18
/*  f129abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129ac0:	45030003 */ 	bc1tl	.L0f129ad0
/*  f129ac4:	8faa0080 */ 	lw	$t2,0x80($sp)
.L0f129ac8:
/*  f129ac8:	00004025 */ 	or	$t0,$zero,$zero
/*  f129acc:	8faa0080 */ 	lw	$t2,0x80($sp)
.L0f129ad0:
/*  f129ad0:	27ab0064 */ 	addiu	$t3,$sp,0x64
/*  f129ad4:	27ac0058 */ 	addiu	$t4,$sp,0x58
/*  f129ad8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f129adc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f129ae0:	87a7007e */ 	lh	$a3,0x7e($sp)
/*  f129ae4:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f129ae8:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f129aec:	0fc4a7d5 */ 	jal	func0f129f54
/*  f129af0:	afaa0010 */ 	sw	$t2,0x10($sp)
.L0f129af4:
/*  f129af4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f129af8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f129afc:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f129b00:	03e00008 */ 	jr	$ra
/*  f129b04:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f129b08
/*  f129b08:	808303cc */ 	lb	$v1,0x3cc($a0)
/*  f129b0c:	3c0f8008 */ 	lui	$t7,%hi(g_ExplosionTypes)
/*  f129b10:	25efe4b8 */ 	addiu	$t7,$t7,%lo(g_ExplosionTypes)
/*  f129b14:	00037080 */ 	sll	$t6,$v1,0x2
/*  f129b18:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f129b1c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129b20:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f129b24:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129b28:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f129b2c:	2401000e */ 	addiu	$at,$zero,0xe
/*  f129b30:	14610015 */ 	bne	$v1,$at,.L0f129b88
/*  f129b34:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f129b38:	28a10021 */ 	slti	$at,$a1,0x21
/*  f129b3c:	54200013 */ 	bnezl	$at,.L0f129b8c
/*  f129b40:	44852000 */ 	mtc1	$a1,$f4
/*  f129b44:	44852000 */ 	mtc1	$a1,$f4
/*  f129b48:	3c014396 */ 	lui	$at,0x4396
/*  f129b4c:	44816000 */ 	mtc1	$at,$f12
/*  f129b50:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f129b54:	3c014040 */ 	lui	$at,0x4040
/*  f129b58:	44814000 */ 	mtc1	$at,$f8
/*  f129b5c:	3c014220 */ 	lui	$at,0x4220
/*  f129b60:	44818000 */ 	mtc1	$at,$f16
/*  f129b64:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f129b68:	46105080 */ 	add.s	$f2,$f10,$f16
/*  f129b6c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f129b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129b74:	45000009 */ 	bc1f	.L0f129b9c
/*  f129b78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129b7c:	46006086 */ 	mov.s	$f2,$f12
/*  f129b80:	03e00008 */ 	jr	$ra
/*  f129b84:	46006006 */ 	mov.s	$f0,$f12
.L0f129b88:
/*  f129b88:	44852000 */ 	mtc1	$a1,$f4
.L0f129b8c:
/*  f129b8c:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f129b90:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f129b94:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f129b98:	46089080 */ 	add.s	$f2,$f18,$f8
.L0f129b9c:
/*  f129b9c:	03e00008 */ 	jr	$ra
/*  f129ba0:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f129ba4
/*  f129ba4:	808303cc */ 	lb	$v1,0x3cc($a0)
/*  f129ba8:	3c0f8008 */ 	lui	$t7,%hi(g_ExplosionTypes)
/*  f129bac:	25efe4b8 */ 	addiu	$t7,$t7,%lo(g_ExplosionTypes)
/*  f129bb0:	00037080 */ 	sll	$t6,$v1,0x2
/*  f129bb4:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f129bb8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129bbc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f129bc0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129bc4:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f129bc8:	2401000e */ 	addiu	$at,$zero,0xe
/*  f129bcc:	14610007 */ 	bne	$v1,$at,.L0f129bec
/*  f129bd0:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f129bd4:	28a10021 */ 	slti	$at,$a1,0x21
/*  f129bd8:	14200004 */ 	bnez	$at,.L0f129bec
/*  f129bdc:	3c0141a0 */ 	lui	$at,0x41a0
/*  f129be0:	44811000 */ 	mtc1	$at,$f2
/*  f129be4:	03e00008 */ 	jr	$ra
/*  f129be8:	46001006 */ 	mov.s	$f0,$f2
.L0f129bec:
/*  f129bec:	44853000 */ 	mtc1	$a1,$f6
/*  f129bf0:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f129bf4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f129bf8:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f129bfc:	460a2080 */ 	add.s	$f2,$f4,$f10
/*  f129c00:	03e00008 */ 	jr	$ra
/*  f129c04:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f129c08
/*  f129c08:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f129c0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f129c10:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f129c14:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f129c18:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f129c1c:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f129c20:	3c188008 */ 	lui	$t8,%hi(g_ExplosionTypes)
/*  f129c24:	2718e4b8 */ 	addiu	$t8,$t8,%lo(g_ExplosionTypes)
/*  f129c28:	808e03cc */ 	lb	$t6,0x3cc($a0)
/*  f129c2c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f129c30:	00c02825 */ 	or	$a1,$a2,$zero
/*  f129c34:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f129c38:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f129c3c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f129c40:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f129c44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f129c48:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f129c4c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f129c50:	0fc4a6c2 */ 	jal	func0f129b08
/*  f129c54:	afa40024 */ 	sw	$a0,0x24($sp)
/*  f129c58:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f129c5c:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f129c60:	0fc4a6e9 */ 	jal	func0f129ba4
/*  f129c64:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f129c68:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f129c6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f129c70:	44818000 */ 	mtc1	$at,$f16
/*  f129c74:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f129c78:	44813000 */ 	mtc1	$at,$f6
/*  f129c7c:	c5040010 */ 	lwc1	$f4,0x10($t0)
/*  f129c80:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f129c84:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f129c88:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f129c8c:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f129c90:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*  f129c94:	46101202 */ 	mul.s	$f8,$f2,$f16
/*  f129c98:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f129c9c:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f129ca0:	460c4080 */ 	add.s	$f2,$f8,$f12
/*  f129ca4:	460c5380 */ 	add.s	$f14,$f10,$f12
/*  f129ca8:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f129cac:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f129cb0:	c4e6000c */ 	lwc1	$f6,0xc($a3)
/*  f129cb4:	460e3201 */ 	sub.s	$f8,$f6,$f14
/*  f129cb8:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f129cbc:	c4ea0010 */ 	lwc1	$f10,0x10($a3)
/*  f129cc0:	46025481 */ 	sub.s	$f18,$f10,$f2
/*  f129cc4:	e4520008 */ 	swc1	$f18,0x8($v0)
/*  f129cc8:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f129ccc:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f129cd0:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f129cd4:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f129cd8:	460e4280 */ 	add.s	$f10,$f8,$f14
/*  f129cdc:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f129ce0:	c4f20010 */ 	lwc1	$f18,0x10($a3)
/*  f129ce4:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f129ce8:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f129cec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f129cf0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f129cf4:	03e00008 */ 	jr	$ra
/*  f129cf8:	00000000 */ 	sll	$zero,$zero,0x0
);

void alertNearbyChrsToNoise(f32 *radius, struct coord *noisepos)
{
	u32 stack[2];
	s32 *end = (s32 *)&func0f084e58;
	s32 i;

	for (i = 0; i < g_NumChrsA; i++) {
		if (g_ChrsA[i].animdata
				&& chrGetTargetProp(&g_ChrsA[i]) == g_Vars.currentplayer->prop
				&& g_ChrsA[i].prop
				&& g_ChrsA[i].prop->type == PROPTYPE_CHR
				&& (g_ChrsA[i].prop->flags & 4)) {
			f32 distance = chrGetDistanceToCoord(&g_ChrsA[i], noisepos);

			if (distance == 0) {
				distance = 2;
			} else {
				distance = (10.0f * *radius * g_ChrsA[i].hearingscale) / distance;
			}

			if (distance > 1) {
				chrRecordLastHearTargetTime(&g_ChrsA[i]);
			}
		}
	}

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *ptr = (s32 *)&func0f084cf0;

		while (ptr < end) {
			checksum ^= *ptr;
			checksum <<= 1;
			ptr++;
		}

		if (checksum != 0xa17a4ca0) {
			struct explosiontype *type = &g_ExplosionTypes[0];
			s32 i;

			for (i = 0; i != NUM_EXPLOSIONTYPES - 1; i++) {
				type->rangeh = 80;
				type->rangev = 60;
				type->changerateh = 15;
				type->changeratev = 5;
				type->innersize = 1500;
				type->blastradius = 200;
				type->damageradius = 3600;
				type++;
			}
		}
	}
#endif
}

GLOBAL_ASM(
glabel func0f129f54
.late_rodata
glabel var7f1b557c
.word 0x481c4000
glabel var7f1b5580
.word 0x497423fe
glabel var7f1b5584
.word 0x40c907a9
.text
/*  f129f54:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f129f58:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f129f5c:	0007bc00 */ 	sll	$s7,$a3,0x10
/*  f129f60:	00177403 */ 	sra	$t6,$s7,0x10
/*  f129f64:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f129f68:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f129f6c:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f129f70:	0080f025 */ 	or	$s8,$a0,$zero
/*  f129f74:	01c0b825 */ 	or	$s7,$t6,$zero
/*  f129f78:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f129f7c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f129f80:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f129f84:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f129f88:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f129f8c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f129f90:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f129f94:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f129f98:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f129f9c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f129fa0:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f129fa4:	afa7016c */ 	sw	$a3,0x16c($sp)
/*  f129fa8:	11c00006 */ 	beqz	$t6,.L0f129fc4
/*  f129fac:	00005025 */ 	or	$t2,$zero,$zero
/*  f129fb0:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f129fb4:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f129fb8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f129fbc:	16cf0003 */ 	bne	$s6,$t7,.L0f129fcc
/*  f129fc0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f129fc4:
/*  f129fc4:	10000334 */ 	beqz	$zero,.L0f12ac98
/*  f129fc8:	00001025 */ 	or	$v0,$zero,$zero
.L0f129fcc:
/*  f129fcc:	16e7003f */ 	bne	$s7,$a3,.L0f12a0cc
/*  f129fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129fd4:	0fc2d5ee */ 	jal	func0f0b57b8
/*  f129fd8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f129fdc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f129fe0:	8fa30164 */ 	lw	$v1,0x164($sp)
/*  f129fe4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f129fe8:	3c017f1b */ 	lui	$at,%hi(var7f1b557c)
/*  f129fec:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f129ff0:	c4461bb0 */ 	lwc1	$f6,0x1bb0($v0)
/*  f129ff4:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f129ff8:	c44a1bb4 */ 	lwc1	$f10,0x1bb4($v0)
/*  f129ffc:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f12a000:	c4700008 */ 	lwc1	$f16,0x8($v1)
/*  f12a004:	c4521bb8 */ 	lwc1	$f18,0x1bb8($v0)
/*  f12a008:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f12a00c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f12a010:	c424557c */ 	lwc1	$f4,%lo(var7f1b557c)($at)
/*  f12a014:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f12a018:	460c6202 */ 	mul.s	$f8,$f12,$f12
/*  f12a01c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a020:	24421bb0 */ 	addiu	$v0,$v0,7088
/*  f12a024:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f12a028:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12a02c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f12a030:	46009182 */ 	mul.s	$f6,$f18,$f0
/*  f12a034:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a038:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f12a03c:	4608203c */ 	c.lt.s	$f4,$f8
/*  f12a040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a044:	45000021 */ 	bc1f	.L0f12a0cc
/*  f12a048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a04c:	0c004b70 */ 	jal	random
/*  f12a050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a054:	30580001 */ 	andi	$t8,$v0,0x1
/*  f12a058:	1700001a */ 	bnez	$t8,.L0f12a0c4
/*  f12a05c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a060:	13c0000e */ 	beqz	$s8,.L0f12a09c
/*  f12a064:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f12a068:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f12a06c:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a070:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a074:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a078:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a07c:	3c068008 */ 	lui	$a2,0x8008
/*  f12a080:	00d93021 */ 	addu	$a2,$a2,$t9
/*  f12a084:	90c6e4dc */ 	lbu	$a2,-0x1b24($a2)
/*  f12a088:	27c40008 */ 	addiu	$a0,$s8,0x8
/*  f12a08c:	0fc4ba08 */ 	jal	func0f12e820
/*  f12a090:	27c50028 */ 	addiu	$a1,$s8,0x28
/*  f12a094:	10000300 */ 	beqz	$zero,.L0f12ac98
/*  f12a098:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12a09c:
/*  f12a09c:	00176080 */ 	sll	$t4,$s7,0x2
/*  f12a0a0:	01976023 */ 	subu	$t4,$t4,$s7
/*  f12a0a4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a0a8:	01976023 */ 	subu	$t4,$t4,$s7
/*  f12a0ac:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a0b0:	3c068008 */ 	lui	$a2,0x8008
/*  f12a0b4:	00cc3021 */ 	addu	$a2,$a2,$t4
/*  f12a0b8:	90c6e4dc */ 	lbu	$a2,-0x1b24($a2)
/*  f12a0bc:	0fc4ba08 */ 	jal	func0f12e820
/*  f12a0c0:	02802825 */ 	or	$a1,$s4,$zero
.L0f12a0c4:
/*  f12a0c4:	100002f4 */ 	beqz	$zero,.L0f12ac98
/*  f12a0c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12a0cc:
/*  f12a0cc:	3c05800a */ 	lui	$a1,%hi(var800a3434)
/*  f12a0d0:	8ca53434 */ 	lw	$a1,%lo(var800a3434)($a1)
/*  f12a0d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f12a0d8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a0dc:	18a0000d */ 	blez	$a1,.L0f12a114
/*  f12a0e0:	3c04800a */ 	lui	$a0,%hi(var800a3430)
/*  f12a0e4:	8c843430 */ 	lw	$a0,%lo(var800a3430)($a0)
/*  f12a0e8:	00001825 */ 	or	$v1,$zero,$zero
/*  f12a0ec:	00801025 */ 	or	$v0,$a0,$zero
.L0f12a0f0:
/*  f12a0f0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f12a0f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a0f8:	0225082a */ 	slt	$at,$s1,$a1
/*  f12a0fc:	15a00003 */ 	bnez	$t5,.L0f12a10c
/*  f12a100:	24420478 */ 	addiu	$v0,$v0,0x478
/*  f12a104:	10000003 */ 	beqz	$zero,.L0f12a114
/*  f12a108:	00645021 */ 	addu	$t2,$v1,$a0
.L0f12a10c:
/*  f12a10c:	1420fff8 */ 	bnez	$at,.L0f12a0f0
/*  f12a110:	24630478 */ 	addiu	$v1,$v1,0x478
.L0f12a114:
/*  f12a114:	15400025 */ 	bnez	$t2,.L0f12a1ac
/*  f12a118:	02c02025 */ 	or	$a0,$s6,$zero
/*  f12a11c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f12a120:	18a00010 */ 	blez	$a1,.L0f12a164
/*  f12a124:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a128:	3c02800a */ 	lui	$v0,%hi(var800a3430)
/*  f12a12c:	8c423430 */ 	lw	$v0,%lo(var800a3430)($v0)
.L0f12a130:
/*  f12a130:	804e03cc */ 	lb	$t6,0x3cc($v0)
/*  f12a134:	54ee0008 */ 	bnel	$a3,$t6,.L0f12a158
/*  f12a138:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a13c:	844303c8 */ 	lh	$v1,0x3c8($v0)
/*  f12a140:	0083082a */ 	slt	$at,$a0,$v1
/*  f12a144:	50200004 */ 	beqzl	$at,.L0f12a158
/*  f12a148:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a14c:	00602025 */ 	or	$a0,$v1,$zero
/*  f12a150:	02203025 */ 	or	$a2,$s1,$zero
/*  f12a154:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f12a158:
/*  f12a158:	0225082a */ 	slt	$at,$s1,$a1
/*  f12a15c:	1420fff4 */ 	bnez	$at,.L0f12a130
/*  f12a160:	24420478 */ 	addiu	$v0,$v0,1144
.L0f12a164:
/*  f12a164:	04c00011 */ 	bltz	$a2,.L0f12a1ac
/*  f12a168:	3c11800a */ 	lui	$s1,%hi(var800a3430)
/*  f12a16c:	000680c0 */ 	sll	$s0,$a2,0x3
/*  f12a170:	26313430 */ 	addiu	$s1,$s1,%lo(var800a3430)
/*  f12a174:	02068021 */ 	addu	$s0,$s0,$a2
/*  f12a178:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f12a17c:	00108100 */ 	sll	$s0,$s0,0x4
/*  f12a180:	02068023 */ 	subu	$s0,$s0,$a2
/*  f12a184:	001080c0 */ 	sll	$s0,$s0,0x3
/*  f12a188:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f12a18c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f12a190:	0fc18ad9 */ 	jal	func0f062b64
/*  f12a194:	00e02825 */ 	or	$a1,$a3,$zero
/*  f12a198:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f12a19c:	03306021 */ 	addu	$t4,$t9,$s0
/*  f12a1a0:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f12a1a4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f12a1a8:	020d5021 */ 	addu	$t2,$s0,$t5
.L0f12a1ac:
/*  f12a1ac:	514002ba */ 	beqzl	$t2,.L0f12ac98
/*  f12a1b0:	000a102b */ 	sltu	$v0,$zero,$t2
/*  f12a1b4:	0fc180d6 */ 	jal	propAllocate
/*  f12a1b8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a1bc:	24010010 */ 	addiu	$at,$zero,0x10
/*  f12a1c0:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a1c4:	12e10006 */ 	beq	$s7,$at,.L0f12a1e0
/*  f12a1c8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f12a1cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12a1d0:	12e10003 */ 	beq	$s7,$at,.L0f12a1e0
/*  f12a1d4:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f12a1d8:	3c018008 */ 	lui	$at,0x8008
/*  f12a1dc:	ac2ee4a0 */ 	sw	$t6,-0x1b60($at)
.L0f12a1e0:
/*  f12a1e0:	104002ac */ 	beqz	$v0,.L0f12ac94
/*  f12a1e4:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f12a1e8:	240f0007 */ 	addiu	$t7,$zero,0x7
/*  f12a1ec:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f12a1f0:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f12a1f4:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f12a1f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a1fc:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f12a200:	c4f00004 */ 	lwc1	$f16,0x4($a3)
/*  f12a204:	e450000c */ 	swc1	$f16,0xc($v0)
/*  f12a208:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*  f12a20c:	e4520010 */ 	swc1	$f18,0x10($v0)
/*  f12a210:	86980000 */ 	lh	$t8,0x0($s4)
/*  f12a214:	12d80020 */ 	beq	$s6,$t8,.L0f12a298
/*  f12a218:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f12a21c:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a220:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a224:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a228:	3c0c8008 */ 	lui	$t4,%hi(g_ExplosionTypes)
/*  f12a22c:	00111040 */ 	sll	$v0,$s1,0x1
/*  f12a230:	02828021 */ 	addu	$s0,$s4,$v0
/*  f12a234:	258ce4b8 */ 	addiu	$t4,$t4,%lo(g_ExplosionTypes)
/*  f12a238:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a23c:	032c1821 */ 	addu	$v1,$t9,$t4
/*  f12a240:	86130000 */ 	lh	$s3,0x0($s0)
/*  f12a244:	afa3009c */ 	sw	$v1,0x9c($sp)
/*  f12a248:	24140007 */ 	addiu	$s4,$zero,0x7
/*  f12a24c:	02a29021 */ 	addu	$s2,$s5,$v0
/*  f12a250:	8fa3009c */ 	lw	$v1,0x9c($sp)
.L0f12a254:
/*  f12a254:	a6530028 */ 	sh	$s3,0x28($s2)
/*  f12a258:	86040000 */ 	lh	$a0,0x0($s0)
/*  f12a25c:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f12a260:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a264:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f12a268:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f12a26c:	44052000 */ 	mfc1	$a1,$f4
/*  f12a270:	0fc010e3 */ 	jal	func0f00438c
/*  f12a274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a278:	86130002 */ 	lh	$s3,0x2($s0)
/*  f12a27c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a280:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f12a284:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f12a288:	12d30003 */ 	beq	$s6,$s3,.L0f12a298
/*  f12a28c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a290:	5634fff0 */ 	bnel	$s1,$s4,.L0f12a254
/*  f12a294:	8fa3009c */ 	lw	$v1,0x9c($sp)
.L0f12a298:
/*  f12a298:	0017c080 */ 	sll	$t8,$s7,0x2
/*  f12a29c:	0317c023 */ 	subu	$t8,$t8,$s7
/*  f12a2a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a2a4:	00117040 */ 	sll	$t6,$s1,0x1
/*  f12a2a8:	0317c023 */ 	subu	$t8,$t8,$s7
/*  f12a2ac:	3c198008 */ 	lui	$t9,%hi(g_ExplosionTypes)
/*  f12a2b0:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f12a2b4:	2739e4b8 */ 	addiu	$t9,$t9,%lo(g_ExplosionTypes)
/*  f12a2b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a2bc:	a5f60028 */ 	sh	$s6,0x28($t7)
/*  f12a2c0:	03196021 */ 	addu	$t4,$t8,$t9
/*  f12a2c4:	afac009c */ 	sw	$t4,0x9c($sp)
/*  f12a2c8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a2cc:	0fc1814e */ 	jal	func0f060538
/*  f12a2d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a2d4:	0fc180bc */ 	jal	propHide
/*  f12a2d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a2dc:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a2e0:	3c188008 */ 	lui	$t8,0x8008
/*  f12a2e4:	2718e4e4 */ 	addiu	$t8,$t8,-6940
/*  f12a2e8:	a15703cc */ 	sb	$s7,0x3cc($t2)
/*  f12a2ec:	ad550000 */ 	sw	$s5,0x0($t2)
/*  f12a2f0:	ad5e0004 */ 	sw	$s8,0x4($t2)
/*  f12a2f4:	a54003c8 */ 	sh	$zero,0x3c8($t2)
/*  f12a2f8:	8fad0174 */ 	lw	$t5,0x174($sp)
/*  f12a2fc:	3c198008 */ 	lui	$t9,0x8008
/*  f12a300:	2739e880 */ 	addiu	$t9,$t9,-6016
/*  f12a304:	a14d03cd */ 	sb	$t5,0x3cd($t2)
/*  f12a308:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f12a30c:	a14e03ce */ 	sb	$t6,0x3ce($t2)
/*  f12a310:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f12a314:	51f80007 */ 	beql	$t7,$t8,.L0f12a334
/*  f12a318:	86ac0028 */ 	lh	$t4,0x28($s5)
/*  f12a31c:	11f90004 */ 	beq	$t7,$t9,.L0f12a330
/*  f12a320:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a324:	0fc10e70 */ 	jal	registerDangerousProp
/*  f12a328:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a32c:	8faa0158 */ 	lw	$t2,0x158($sp)
.L0f12a330:
/*  f12a330:	86ac0028 */ 	lh	$t4,0x28($s5)
.L0f12a334:
/*  f12a334:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f12a338:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f12a33c:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f12a340:	85a6001c */ 	lh	$a2,0x1c($t5)
/*  f12a344:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a348:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f12a34c:	0fc4a702 */ 	jal	func0f129c08
/*  f12a350:	02a03825 */ 	or	$a3,$s5,$zero
/*  f12a354:	3c013f80 */ 	lui	$at,0x3f80
/*  f12a358:	4481b000 */ 	mtc1	$at,$f22
/*  f12a35c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f12a360:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f12a364:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f12a368:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f12a36c:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f12a370:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f12a374:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f12a378:	c7b000cc */ 	lwc1	$f16,0xcc($sp)
/*  f12a37c:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f12a380:	46163102 */ 	mul.s	$f4,$f6,$f22
/*  f12a384:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f12a388:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f12a38c:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f12a390:	e7b200d8 */ 	swc1	$f18,0xd8($sp)
/*  f12a394:	000b40c0 */ 	sll	$t0,$t3,0x3
/*  f12a398:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f12a39c:	e7a400dc */ 	swc1	$f4,0xdc($sp)
/*  f12a3a0:	25294928 */ 	addiu	$t1,$t1,%lo(g_RoomPtrs)
/*  f12a3a4:	46163102 */ 	mul.s	$f4,$f6,$f22
/*  f12a3a8:	010b4021 */ 	addu	$t0,$t0,$t3
/*  f12a3ac:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a3b0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12a3b4:	010b4023 */ 	subu	$t0,$t0,$t3
/*  f12a3b8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12a3bc:	e7aa00c8 */ 	swc1	$f10,0xc8($sp)
/*  f12a3c0:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f12a3c4:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f12a3c8:	01c8c021 */ 	addu	$t8,$t6,$t0
/*  f12a3cc:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a3d0:	c7080018 */ 	lwc1	$f8,0x18($t8)
/*  f12a3d4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f12a3d8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12a3dc:	e54803e8 */ 	swc1	$f8,0x3e8($t2)
/*  f12a3e0:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f12a3e4:	01e8c821 */ 	addu	$t9,$t7,$t0
/*  f12a3e8:	c72a001c */ 	lwc1	$f10,0x1c($t9)
/*  f12a3ec:	e54a03ec */ 	swc1	$f10,0x3ec($t2)
/*  f12a3f0:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f12a3f4:	01886821 */ 	addu	$t5,$t4,$t0
/*  f12a3f8:	c5b00020 */ 	lwc1	$f16,0x20($t5)
/*  f12a3fc:	e55003f0 */ 	swc1	$f16,0x3f0($t2)
/*  f12a400:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a404:	01c8c021 */ 	addu	$t8,$t6,$t0
/*  f12a408:	c7120024 */ 	lwc1	$f18,0x24($t8)
/*  f12a40c:	814e03cc */ 	lb	$t6,0x3cc($t2)
/*  f12a410:	e55203f4 */ 	swc1	$f18,0x3f4($t2)
/*  f12a414:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f12a418:	01e8c821 */ 	addu	$t9,$t7,$t0
/*  f12a41c:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f12a420:	e54603f8 */ 	swc1	$f6,0x3f8($t2)
/*  f12a424:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f12a428:	01886821 */ 	addu	$t5,$t4,$t0
/*  f12a42c:	c5a4002c */ 	lwc1	$f4,0x2c($t5)
/*  f12a430:	a54b0400 */ 	sh	$t3,0x400($t2)
/*  f12a434:	a5560402 */ 	sh	$s6,0x402($t2)
/*  f12a438:	a14303cf */ 	sb	$v1,0x3cf($t2)
/*  f12a43c:	15c10003 */ 	bne	$t6,$at,.L0f12a44c
/*  f12a440:	e54403fc */ 	swc1	$f4,0x3fc($t2)
/*  f12a444:	100001c2 */ 	beqz	$zero,.L0f12ab50
/*  f12a448:	a14003cf */ 	sb	$zero,0x3cf($t2)
.L0f12a44c:
/*  f12a44c:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a450:	27b700e0 */ 	addiu	$s7,$sp,0xe0
/*  f12a454:	03087821 */ 	addu	$t7,$t8,$t0
/*  f12a458:	c5e80018 */ 	lwc1	$f8,0x18($t7)
/*  f12a45c:	e54803e8 */ 	swc1	$f8,0x3e8($t2)
/*  f12a460:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12a464:	03286021 */ 	addu	$t4,$t9,$t0
/*  f12a468:	c58a001c */ 	lwc1	$f10,0x1c($t4)
/*  f12a46c:	e54a03ec */ 	swc1	$f10,0x3ec($t2)
/*  f12a470:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f12a474:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f12a478:	c5d00020 */ 	lwc1	$f16,0x20($t6)
/*  f12a47c:	e55003f0 */ 	swc1	$f16,0x3f0($t2)
/*  f12a480:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a484:	03087821 */ 	addu	$t7,$t8,$t0
/*  f12a488:	c5f20024 */ 	lwc1	$f18,0x24($t7)
/*  f12a48c:	e55203f4 */ 	swc1	$f18,0x3f4($t2)
/*  f12a490:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12a494:	03286021 */ 	addu	$t4,$t9,$t0
/*  f12a498:	c5860028 */ 	lwc1	$f6,0x28($t4)
/*  f12a49c:	e54603f8 */ 	swc1	$f6,0x3f8($t2)
/*  f12a4a0:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f12a4a4:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f12a4a8:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*  f12a4ac:	a54b0400 */ 	sh	$t3,0x400($t2)
/*  f12a4b0:	a5560402 */ 	sh	$s6,0x402($t2)
/*  f12a4b4:	a14303cf */ 	sb	$v1,0x3cf($t2)
/*  f12a4b8:	e54403fc */ 	swc1	$f4,0x3fc($t2)
/*  f12a4bc:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a4c0:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f12a4c4:	03081021 */ 	addu	$v0,$t8,$t0
/*  f12a4c8:	804f0005 */ 	lb	$t7,0x5($v0)
/*  f12a4cc:	59e0018f */ 	blezl	$t7,.L0f12ab0c
/*  f12a4d0:	c55203e8 */ 	lwc1	$f18,0x3e8($t2)
/*  f12a4d4:	4480c000 */ 	mtc1	$zero,$f24
/*  f12a4d8:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f12a4dc:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f12a4e0:	844c000e */ 	lh	$t4,0xe($v0)
.L0f12a4e4:
/*  f12a4e4:	3c19800a */ 	lui	$t9,%hi(var800a4ce0)
/*  f12a4e8:	8f394ce0 */ 	lw	$t9,%lo(var800a4ce0)($t9)
/*  f12a4ec:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f12a4f0:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f12a4f4:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f12a4f8:	01c7c021 */ 	addu	$t8,$t6,$a3
/*  f12a4fc:	87040000 */ 	lh	$a0,0x0($t8)
/*  f12a500:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a504:	27a50104 */ 	addiu	$a1,$sp,0x104
/*  f12a508:	27a600f8 */ 	addiu	$a2,$sp,0xf8
/*  f12a50c:	0fc59401 */ 	jal	func0f165004
/*  f12a510:	afa40118 */ 	sw	$a0,0x118($sp)
/*  f12a514:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f12a518:	27a500f8 */ 	addiu	$a1,$sp,0xf8
/*  f12a51c:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f12a520:	0fc593e7 */ 	jal	func0f164f9c
/*  f12a524:	27a700c8 */ 	addiu	$a3,$sp,0xc8
/*  f12a528:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f12a52c:	25294928 */ 	addiu	$t1,$t1,%lo(g_RoomPtrs)
/*  f12a530:	10400168 */ 	beqz	$v0,.L0f12aad4
/*  f12a534:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a538:	8fa50118 */ 	lw	$a1,0x118($sp)
/*  f12a53c:	3c0c800a */ 	lui	$t4,%hi(g_PortalSomethings)
/*  f12a540:	8d8c4cc8 */ 	lw	$t4,%lo(g_PortalSomethings)($t4)
/*  f12a544:	240fffff */ 	addiu	$t7,$zero,-1
/*  f12a548:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*  f12a54c:	a7af00c4 */ 	sh	$t7,0xc4($sp)
/*  f12a550:	01991021 */ 	addu	$v0,$t4,$t9
/*  f12a554:	84430002 */ 	lh	$v1,0x2($v0)
/*  f12a558:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f12a55c:	00002025 */ 	or	$a0,$zero,$zero
/*  f12a560:	0000b025 */ 	or	$s6,$zero,$zero
/*  f12a564:	15a30004 */ 	bne	$t5,$v1,.L0f12a578
/*  f12a568:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f12a56c:	844e0004 */ 	lh	$t6,0x4($v0)
/*  f12a570:	10000002 */ 	beqz	$zero,.L0f12a57c
/*  f12a574:	a7ae00c6 */ 	sh	$t6,0xc6($sp)
.L0f12a578:
/*  f12a578:	a7a300c6 */ 	sh	$v1,0xc6($sp)
.L0f12a57c:
/*  f12a57c:	3c0f800a */ 	lui	$t7,%hi(var800a4ccc)
/*  f12a580:	8def4ccc */ 	lw	$t7,%lo(var800a4ccc)($t7)
/*  f12a584:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f12a588:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a58c:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f12a590:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f12a594:	27a500f8 */ 	addiu	$a1,$sp,0xf8
/*  f12a598:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f12a59c:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f12a5a0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f12a5a4:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f12a5a8:	4618903c */ 	c.lt.s	$f18,$f24
/*  f12a5ac:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f12a5b0:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f12a5b4:	45000003 */ 	bc1f	.L0f12a5c4
/*  f12a5b8:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f12a5bc:	46009187 */ 	neg.s	$f6,$f18
/*  f12a5c0:	e7a600ac */ 	swc1	$f6,0xac($sp)
.L0f12a5c4:
/*  f12a5c4:	c7a000b0 */ 	lwc1	$f0,0xb0($sp)
/*  f12a5c8:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f12a5cc:	4618003c */ 	c.lt.s	$f0,$f24
/*  f12a5d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a5d4:	45020003 */ 	bc1fl	.L0f12a5e4
/*  f12a5d8:	4618103c */ 	c.lt.s	$f2,$f24
/*  f12a5dc:	46000007 */ 	neg.s	$f0,$f0
/*  f12a5e0:	4618103c */ 	c.lt.s	$f2,$f24
.L0f12a5e4:
/*  f12a5e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a5e8:	45020004 */ 	bc1fl	.L0f12a5fc
/*  f12a5ec:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f12a5f0:	46001087 */ 	neg.s	$f2,$f2
/*  f12a5f4:	e7a200b4 */ 	swc1	$f2,0xb4($sp)
/*  f12a5f8:	c7a400ac */ 	lwc1	$f4,0xac($sp)
.L0f12a5fc:
/*  f12a5fc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f12a600:	4600203c */ 	c.lt.s	$f4,$f0
/*  f12a604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a608:	45020003 */ 	bc1fl	.L0f12a618
/*  f12a60c:	00041080 */ 	sll	$v0,$a0,0x2
/*  f12a610:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f12a614:	00041080 */ 	sll	$v0,$a0,0x2
.L0f12a618:
/*  f12a618:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f12a61c:	03a26021 */ 	addu	$t4,$sp,$v0
/*  f12a620:	c58800ac */ 	lwc1	$f8,0xac($t4)
/*  f12a624:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f12a628:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f12a62c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f12a630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a634:	45020004 */ 	bc1fl	.L0f12a648
/*  f12a638:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f12a63c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f12a640:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f12a644:	24990001 */ 	addiu	$t9,$a0,0x1
.L0f12a648:
/*  f12a648:	0326001a */ 	div	$zero,$t9,$a2
/*  f12a64c:	0000a010 */ 	mfhi	$s4
/*  f12a650:	248e0002 */ 	addiu	$t6,$a0,0x2
/*  f12a654:	27a20104 */ 	addiu	$v0,$sp,0x104
/*  f12a658:	01c6001a */ 	div	$zero,$t6,$a2
/*  f12a65c:	0000a810 */ 	mfhi	$s5
/*  f12a660:	00146880 */ 	sll	$t5,$s4,0x2
/*  f12a664:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f12a668:	00adf021 */ 	addu	$s8,$a1,$t5
/*  f12a66c:	004d1821 */ 	addu	$v1,$v0,$t5
/*  f12a670:	00b83821 */ 	addu	$a3,$a1,$t8
/*  f12a674:	00584021 */ 	addu	$t0,$v0,$t8
/*  f12a678:	c4720000 */ 	lwc1	$f18,0x0($v1)
/*  f12a67c:	c7d00000 */ 	lwc1	$f16,0x0($s8)
/*  f12a680:	c5040000 */ 	lwc1	$f4,0x0($t0)
/*  f12a684:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f12a688:	14c00002 */ 	bnez	$a2,.L0f12a694
/*  f12a68c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a690:	0007000d */ 	break	0x7
.L0f12a694:
/*  f12a694:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12a698:	14c10004 */ 	bne	$a2,$at,.L0f12a6ac
/*  f12a69c:	3c018000 */ 	lui	$at,0x8000
/*  f12a6a0:	17210002 */ 	bne	$t9,$at,.L0f12a6ac
/*  f12a6a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a6a8:	0006000d */ 	break	0x6
.L0f12a6ac:
/*  f12a6ac:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f12a6b0:	8fab008c */ 	lw	$t3,0x8c($sp)
/*  f12a6b4:	27af0104 */ 	addiu	$t7,$sp,0x104
/*  f12a6b8:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f12a6bc:	01a0a025 */ 	or	$s4,$t5,$zero
/*  f12a6c0:	14c00002 */ 	bnez	$a2,.L0f12a6cc
/*  f12a6c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a6c8:	0007000d */ 	break	0x7
.L0f12a6cc:
/*  f12a6cc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12a6d0:	14c10004 */ 	bne	$a2,$at,.L0f12a6e4
/*  f12a6d4:	3c018000 */ 	lui	$at,0x8000
/*  f12a6d8:	15c10002 */ 	bne	$t6,$at,.L0f12a6e4
/*  f12a6dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a6e0:	0006000d */ 	break	0x6
.L0f12a6e4:
/*  f12a6e4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f12a6e8:	0300a825 */ 	or	$s5,$t8,$zero
/*  f12a6ec:	27ac00f8 */ 	addiu	$t4,$sp,0xf8
/*  f12a6f0:	016f2821 */ 	addu	$a1,$t3,$t7
/*  f12a6f4:	45020003 */ 	bc1fl	.L0f12a704
/*  f12a6f8:	016c3021 */ 	addu	$a2,$t3,$t4
/*  f12a6fc:	46001006 */ 	mov.s	$f0,$f2
/*  f12a700:	016c3021 */ 	addu	$a2,$t3,$t4
.L0f12a704:
/*  f12a704:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f12a708:	c4d00000 */ 	lwc1	$f16,0x0($a2)
/*  f12a70c:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f12a710:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f12a714:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f12a718:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f12a71c:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f12a720:	e4d20000 */ 	swc1	$f18,0x0($a2)
/*  f12a724:	8fb9012c */ 	lw	$t9,0x12c($sp)
/*  f12a728:	001968c0 */ 	sll	$t5,$t9,0x3
/*  f12a72c:	01b96821 */ 	addu	$t5,$t5,$t9
/*  f12a730:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f12a734:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f12a738:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f12a73c:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f12a740:	01cb1021 */ 	addu	$v0,$t6,$t3
/*  f12a744:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f12a748:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f12a74c:	afa50070 */ 	sw	$a1,0x70($sp)
/*  f12a750:	460c103c */ 	c.lt.s	$f2,$f12
/*  f12a754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a758:	45020004 */ 	bc1fl	.L0f12a76c
/*  f12a75c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a760:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f12a764:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f12a768:	8fb80068 */ 	lw	$t8,0x68($sp)
.L0f12a76c:
/*  f12a76c:	c44c0024 */ 	lwc1	$f12,0x24($v0)
/*  f12a770:	c7000000 */ 	lwc1	$f0,0x0($t8)
/*  f12a774:	4600603c */ 	c.lt.s	$f12,$f0
/*  f12a778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a77c:	45020004 */ 	bc1fl	.L0f12a790
/*  f12a780:	87af00c6 */ 	lh	$t7,0xc6($sp)
/*  f12a784:	e70c0000 */ 	swc1	$f12,0x0($t8)
/*  f12a788:	c7000000 */ 	lwc1	$f0,0x0($t8)
/*  f12a78c:	87af00c6 */ 	lh	$t7,0xc6($sp)
.L0f12a790:
/*  f12a790:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f12a794:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f12a798:	000f60c0 */ 	sll	$t4,$t7,0x3
/*  f12a79c:	018f6021 */ 	addu	$t4,$t4,$t7
/*  f12a7a0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a7a4:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f12a7a8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a7ac:	008cc821 */ 	addu	$t9,$a0,$t4
/*  f12a7b0:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f12a7b4:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f12a7b8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12a7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a7c0:	45020003 */ 	bc1fl	.L0f12a7d0
/*  f12a7c4:	c4420024 */ 	lwc1	$f2,0x24($v0)
/*  f12a7c8:	e5cc0000 */ 	swc1	$f12,0x0($t6)
/*  f12a7cc:	c4420024 */ 	lwc1	$f2,0x24($v0)
.L0f12a7d0:
/*  f12a7d0:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a7d4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12a7d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a7dc:	45020003 */ 	bc1fl	.L0f12a7ec
/*  f12a7e0:	87b300c6 */ 	lh	$s3,0xc6($sp)
/*  f12a7e4:	e7020000 */ 	swc1	$f2,0x0($t8)
/*  f12a7e8:	87b300c6 */ 	lh	$s3,0xc6($sp)
.L0f12a7ec:
/*  f12a7ec:	001378c0 */ 	sll	$t7,$s3,0x3
/*  f12a7f0:	01f37821 */ 	addu	$t7,$t7,$s3
/*  f12a7f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a7f8:	01f37823 */ 	subu	$t7,$t7,$s3
/*  f12a7fc:	000f9880 */ 	sll	$s3,$t7,0x2
/*  f12a800:	00931021 */ 	addu	$v0,$a0,$s3
/*  f12a804:	804c0005 */ 	lb	$t4,0x5($v0)
/*  f12a808:	5980006b */ 	blezl	$t4,.L0f12a9b8
/*  f12a80c:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12a810:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a814:	844d000e */ 	lh	$t5,0xe($v0)
.L0f12a818:
/*  f12a818:	3c19800a */ 	lui	$t9,%hi(var800a4ce0)
/*  f12a81c:	8f394ce0 */ 	lw	$t9,%lo(var800a4ce0)($t9)
/*  f12a820:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f12a824:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f12a828:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f12a82c:	03117821 */ 	addu	$t7,$t8,$s1
/*  f12a830:	85f00000 */ 	lh	$s0,0x0($t7)
/*  f12a834:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f12a838:	02e03025 */ 	or	$a2,$s7,$zero
/*  f12a83c:	120c0055 */ 	beq	$s0,$t4,.L0f12a994
/*  f12a840:	02002025 */ 	or	$a0,$s0,$zero
/*  f12a844:	3c014120 */ 	lui	$at,0x4120
/*  f12a848:	44813000 */ 	mtc1	$at,$f6
/*  f12a84c:	02859021 */ 	addu	$s2,$s4,$a1
/*  f12a850:	afa30080 */ 	sw	$v1,0x80($sp)
/*  f12a854:	46163502 */ 	mul.s	$f20,$f6,$f22
/*  f12a858:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f12a85c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f12a860:	0fc59401 */ 	jal	func0f165004
/*  f12a864:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a868:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f12a86c:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f12a870:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f12a874:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f12a878:	25294928 */ 	addiu	$t1,$t1,%lo(g_RoomPtrs)
/*  f12a87c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f12a880:	46142200 */ 	add.s	$f8,$f4,$f20
/*  f12a884:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f12a888:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a88c:	4608503e */ 	c.le.s	$f10,$f8
/*  f12a890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a894:	45020040 */ 	bc1fl	.L0f12a998
/*  f12a898:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a89c:	c5100000 */ 	lwc1	$f16,0x0($t0)
/*  f12a8a0:	03b5c821 */ 	addu	$t9,$sp,$s5
/*  f12a8a4:	c72600ec */ 	lwc1	$f6,0xec($t9)
/*  f12a8a8:	46148480 */ 	add.s	$f18,$f16,$f20
/*  f12a8ac:	4612303e */ 	c.le.s	$f6,$f18
/*  f12a8b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a8b4:	45020038 */ 	bc1fl	.L0f12a998
/*  f12a8b8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a8bc:	c7c80000 */ 	lwc1	$f8,0x0($s8)
/*  f12a8c0:	02f47021 */ 	addu	$t6,$s7,$s4
/*  f12a8c4:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*  f12a8c8:	46144281 */ 	sub.s	$f10,$f8,$f20
/*  f12a8cc:	4604503e */ 	c.le.s	$f10,$f4
/*  f12a8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a8d4:	45020030 */ 	bc1fl	.L0f12a998
/*  f12a8d8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a8dc:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f12a8e0:	02f5c021 */ 	addu	$t8,$s7,$s5
/*  f12a8e4:	c7100000 */ 	lwc1	$f16,0x0($t8)
/*  f12a8e8:	46149181 */ 	sub.s	$f6,$f18,$f20
/*  f12a8ec:	4610303e */ 	c.le.s	$f6,$f16
/*  f12a8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a8f4:	45000027 */ 	bc1f	.L0f12a994
/*  f12a8f8:	3c0f800a */ 	lui	$t7,%hi(g_PortalSomethings)
/*  f12a8fc:	8def4cc8 */ 	lw	$t7,%lo(g_PortalSomethings)($t7)
/*  f12a900:	001060c0 */ 	sll	$t4,$s0,0x3
/*  f12a904:	87ad00c6 */ 	lh	$t5,0xc6($sp)
/*  f12a908:	01ec1021 */ 	addu	$v0,$t7,$t4
/*  f12a90c:	84430002 */ 	lh	$v1,0x2($v0)
/*  f12a910:	55a30005 */ 	bnel	$t5,$v1,.L0f12a928
/*  f12a914:	a7a300c4 */ 	sh	$v1,0xc4($sp)
/*  f12a918:	84590004 */ 	lh	$t9,0x4($v0)
/*  f12a91c:	10000002 */ 	beqz	$zero,.L0f12a928
/*  f12a920:	a7b900c4 */ 	sh	$t9,0xc4($sp)
/*  f12a924:	a7a300c4 */ 	sh	$v1,0xc4($sp)
.L0f12a928:
/*  f12a928:	87b800c4 */ 	lh	$t8,0xc4($sp)
/*  f12a92c:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a930:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f12a934:	001878c0 */ 	sll	$t7,$t8,0x3
/*  f12a938:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f12a93c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a940:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f12a944:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f12a948:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a94c:	01cf6021 */ 	addu	$t4,$t6,$t7
/*  f12a950:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f12a954:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f12a958:	c7280000 */ 	lwc1	$f8,0x0($t9)
/*  f12a95c:	4608003c */ 	c.lt.s	$f0,$f8
/*  f12a960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a964:	45020003 */ 	bc1fl	.L0f12a974
/*  f12a968:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a96c:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f12a970:	8fb80068 */ 	lw	$t8,0x68($sp)
.L0f12a974:
/*  f12a974:	c4400024 */ 	lwc1	$f0,0x24($v0)
/*  f12a978:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f12a97c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f12a980:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12a984:	4502000c */ 	bc1fl	.L0f12a9b8
/*  f12a988:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12a98c:	10000009 */ 	beqz	$zero,.L0f12a9b4
/*  f12a990:	e7000000 */ 	swc1	$f0,0x0($t8)
.L0f12a994:
/*  f12a994:	8d2e0000 */ 	lw	$t6,0x0($t1)
.L0f12a998:
/*  f12a998:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f12a99c:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f12a9a0:	01d31021 */ 	addu	$v0,$t6,$s3
/*  f12a9a4:	804f0005 */ 	lb	$t7,0x5($v0)
/*  f12a9a8:	02cf082a */ 	slt	$at,$s6,$t7
/*  f12a9ac:	5420ff9a */ 	bnezl	$at,.L0f12a818
/*  f12a9b0:	844d000e */ 	lh	$t5,0xe($v0)
.L0f12a9b4:
/*  f12a9b4:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
.L0f12a9b8:
/*  f12a9b8:	c7b00108 */ 	lwc1	$f16,0x108($sp)
/*  f12a9bc:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f12a9c0:	46165482 */ 	mul.s	$f18,$f10,$f22
/*  f12a9c4:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12a9c8:	2403001c */ 	addiu	$v1,$zero,0x1c
/*  f12a9cc:	46168182 */ 	mul.s	$f6,$f16,$f22
/*  f12a9d0:	e7b20104 */ 	swc1	$f18,0x104($sp)
/*  f12a9d4:	46164102 */ 	mul.s	$f4,$f8,$f22
/*  f12a9d8:	e7a60108 */ 	swc1	$f6,0x108($sp)
/*  f12a9dc:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f12a9e0:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f12a9e4:	e7a4010c */ 	swc1	$f4,0x10c($sp)
/*  f12a9e8:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12a9ec:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f12a9f0:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12a9f4:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12a9f8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12a9fc:	e7aa0100 */ 	swc1	$f10,0x100($sp)
/*  f12aa00:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa04:	01830019 */ 	multu	$t4,$v1
/*  f12aa08:	00006812 */ 	mflo	$t5
/*  f12aa0c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa10:	e73203e8 */ 	swc1	$f18,0x3e8($t9)
/*  f12aa14:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa18:	c7b00108 */ 	lwc1	$f16,0x108($sp)
/*  f12aa1c:	03030019 */ 	multu	$t8,$v1
/*  f12aa20:	00007012 */ 	mflo	$t6
/*  f12aa24:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa28:	e5f003ec */ 	swc1	$f16,0x3ec($t7)
/*  f12aa2c:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa30:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f12aa34:	01830019 */ 	multu	$t4,$v1
/*  f12aa38:	00006812 */ 	mflo	$t5
/*  f12aa3c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa40:	e72603f0 */ 	swc1	$f6,0x3f0($t9)
/*  f12aa44:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa48:	c7a800f8 */ 	lwc1	$f8,0xf8($sp)
/*  f12aa4c:	03030019 */ 	multu	$t8,$v1
/*  f12aa50:	00007012 */ 	mflo	$t6
/*  f12aa54:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa58:	e5e803f4 */ 	swc1	$f8,0x3f4($t7)
/*  f12aa5c:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa60:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12aa64:	01830019 */ 	multu	$t4,$v1
/*  f12aa68:	00006812 */ 	mflo	$t5
/*  f12aa6c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa70:	e72403f8 */ 	swc1	$f4,0x3f8($t9)
/*  f12aa74:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa78:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f12aa7c:	03030019 */ 	multu	$t8,$v1
/*  f12aa80:	00007012 */ 	mflo	$t6
/*  f12aa84:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa88:	e5ea03fc */ 	swc1	$f10,0x3fc($t7)
/*  f12aa8c:	914d03cf */ 	lbu	$t5,0x3cf($t2)
/*  f12aa90:	87ac00c6 */ 	lh	$t4,0xc6($sp)
/*  f12aa94:	01a30019 */ 	multu	$t5,$v1
/*  f12aa98:	0000c812 */ 	mflo	$t9
/*  f12aa9c:	0159c021 */ 	addu	$t8,$t2,$t9
/*  f12aaa0:	a70c0400 */ 	sh	$t4,0x400($t8)
/*  f12aaa4:	914f03cf */ 	lbu	$t7,0x3cf($t2)
/*  f12aaa8:	87ae00c4 */ 	lh	$t6,0xc4($sp)
/*  f12aaac:	01e30019 */ 	multu	$t7,$v1
/*  f12aab0:	00006812 */ 	mflo	$t5
/*  f12aab4:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aab8:	a72e0402 */ 	sh	$t6,0x402($t9)
/*  f12aabc:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aac0:	25980001 */ 	addiu	$t8,$t4,0x1
/*  f12aac4:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f12aac8:	29e10005 */ 	slti	$at,$t7,0x5
/*  f12aacc:	1020000e */ 	beqz	$at,.L0f12ab08
/*  f12aad0:	a15803cf */ 	sb	$t8,0x3cf($t2)
.L0f12aad4:
/*  f12aad4:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f12aad8:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f12aadc:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12aae0:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f12aae4:	25ae0002 */ 	addiu	$t6,$t5,0x2
/*  f12aae8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f12aaec:	afa40120 */ 	sw	$a0,0x120($sp)
/*  f12aaf0:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f12aaf4:	032c1021 */ 	addu	$v0,$t9,$t4
/*  f12aaf8:	80580005 */ 	lb	$t8,0x5($v0)
/*  f12aafc:	0098082a */ 	slt	$at,$a0,$t8
/*  f12ab00:	5420fe78 */ 	bnezl	$at,.L0f12a4e4
/*  f12ab04:	844c000e */ 	lh	$t4,0xe($v0)
.L0f12ab08:
/*  f12ab08:	c55203e8 */ 	lwc1	$f18,0x3e8($t2)
.L0f12ab0c:
/*  f12ab0c:	c54603ec */ 	lwc1	$f6,0x3ec($t2)
/*  f12ab10:	c54403f0 */ 	lwc1	$f4,0x3f0($t2)
/*  f12ab14:	46169402 */ 	mul.s	$f16,$f18,$f22
/*  f12ab18:	c55203f4 */ 	lwc1	$f18,0x3f4($t2)
/*  f12ab1c:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12ab20:	c54603f8 */ 	lwc1	$f6,0x3f8($t2)
/*  f12ab24:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12ab28:	e55003e8 */ 	swc1	$f16,0x3e8($t2)
/*  f12ab2c:	c54403fc */ 	lwc1	$f4,0x3fc($t2)
/*  f12ab30:	46169402 */ 	mul.s	$f16,$f18,$f22
/*  f12ab34:	e54803ec */ 	swc1	$f8,0x3ec($t2)
/*  f12ab38:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12ab3c:	e54a03f0 */ 	swc1	$f10,0x3f0($t2)
/*  f12ab40:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12ab44:	e55003f4 */ 	swc1	$f16,0x3f4($t2)
/*  f12ab48:	e54803f8 */ 	swc1	$f8,0x3f8($t2)
/*  f12ab4c:	e54a03fc */ 	swc1	$f10,0x3fc($t2)
.L0f12ab50:
/*  f12ab50:	8faf0174 */ 	lw	$t7,0x174($sp)
/*  f12ab54:	8fa20178 */ 	lw	$v0,0x178($sp)
/*  f12ab58:	3c017f1b */ 	lui	$at,%hi(var7f1b5580)
/*  f12ab5c:	11e00011 */ 	beqz	$t7,.L0f12aba4
/*  f12ab60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12ab64:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f12ab68:	8fa30180 */ 	lw	$v1,0x180($sp)
/*  f12ab6c:	e55203d0 */ 	swc1	$f18,0x3d0($t2)
/*  f12ab70:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f12ab74:	e55003d4 */ 	swc1	$f16,0x3d4($t2)
/*  f12ab78:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f12ab7c:	e54603d8 */ 	swc1	$f6,0x3d8($t2)
/*  f12ab80:	87ad017e */ 	lh	$t5,0x17e($sp)
/*  f12ab84:	a54d03ca */ 	sh	$t5,0x3ca($t2)
/*  f12ab88:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f12ab8c:	e54803dc */ 	swc1	$f8,0x3dc($t2)
/*  f12ab90:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f12ab94:	e54403e0 */ 	swc1	$f4,0x3e0($t2)
/*  f12ab98:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f12ab9c:	10000003 */ 	beqz	$zero,.L0f12abac
/*  f12aba0:	e54a03e4 */ 	swc1	$f10,0x3e4($t2)
.L0f12aba4:
/*  f12aba4:	c4325580 */ 	lwc1	$f18,%lo(var7f1b5580)($at)
/*  f12aba8:	e55203d0 */ 	swc1	$f18,0x3d0($t2)
.L0f12abac:
/*  f12abac:	a54e001c */ 	sh	$t6,0x1c($t2)
/*  f12abb0:	8fb90164 */ 	lw	$t9,0x164($sp)
/*  f12abb4:	c7300000 */ 	lwc1	$f16,0x0($t9)
/*  f12abb8:	e5500008 */ 	swc1	$f16,0x8($t2)
/*  f12abbc:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f12abc0:	c5860004 */ 	lwc1	$f6,0x4($t4)
/*  f12abc4:	e546000c */ 	swc1	$f6,0xc($t2)
/*  f12abc8:	8fb80164 */ 	lw	$t8,0x164($sp)
/*  f12abcc:	c7080008 */ 	lwc1	$f8,0x8($t8)
/*  f12abd0:	e5480010 */ 	swc1	$f8,0x10($t2)
/*  f12abd4:	0c004b70 */ 	jal	random
/*  f12abd8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12abdc:	44822000 */ 	mtc1	$v0,$f4
/*  f12abe0:	3c012f80 */ 	lui	$at,0x2f80
/*  f12abe4:	4481a000 */ 	mtc1	$at,$f20
/*  f12abe8:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12abec:	04410005 */ 	bgez	$v0,.L0f12ac04
/*  f12abf0:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f12abf4:	3c014f80 */ 	lui	$at,0x4f80
/*  f12abf8:	44819000 */ 	mtc1	$at,$f18
/*  f12abfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ac00:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f12ac04:
/*  f12ac04:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f12ac08:	3c013f00 */ 	lui	$at,0x3f00
/*  f12ac0c:	44813000 */ 	mtc1	$at,$f6
/*  f12ac10:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f12ac14:	c5f20010 */ 	lwc1	$f18,0x10($t7)
/*  f12ac18:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f12ac1c:	46164100 */ 	add.s	$f4,$f8,$f22
/*  f12ac20:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12ac24:	0c004b70 */ 	jal	random
/*  f12ac28:	e54a0014 */ 	swc1	$f10,0x14($t2)
/*  f12ac2c:	44828000 */ 	mtc1	$v0,$f16
/*  f12ac30:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12ac34:	04410005 */ 	bgez	$v0,.L0f12ac4c
/*  f12ac38:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f12ac3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ac40:	44814000 */ 	mtc1	$at,$f8
/*  f12ac44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ac48:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f12ac4c:
/*  f12ac4c:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f12ac50:	3c017f1b */ 	lui	$at,%hi(var7f1b5584)
/*  f12ac54:	c4325584 */ 	lwc1	$f18,%lo(var7f1b5584)($at)
/*  f12ac58:	a140001e */ 	sb	$zero,0x1e($t2)
/*  f12ac5c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x314)
/*  f12ac60:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12ac64:	e54a0018 */ 	swc1	$f10,0x18($t2)
/*  f12ac68:	8dada2d4 */ 	lw	$t5,%lo(g_Vars+0x314)($t5)
/*  f12ac6c:	51a00005 */ 	beqzl	$t5,.L0f12ac84
/*  f12ac70:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f12ac74:	0fc4bd7e */ 	jal	func0f12f5f8
/*  f12ac78:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12ac7c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12ac80:	8fa4009c */ 	lw	$a0,0x9c($sp)
.L0f12ac84:
/*  f12ac84:	8fa50164 */ 	lw	$a1,0x164($sp)
/*  f12ac88:	0fc4a73f */ 	jal	alertNearbyChrsToNoise
/*  f12ac8c:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12ac90:	8faa0158 */ 	lw	$t2,0x158($sp)
.L0f12ac94:
/*  f12ac94:	000a102b */ 	sltu	$v0,$zero,$t2
.L0f12ac98:
/*  f12ac98:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f12ac9c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f12aca0:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f12aca4:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f12aca8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f12acac:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f12acb0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f12acb4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f12acb8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f12acbc:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f12acc0:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f12acc4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f12acc8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f12accc:	03e00008 */ 	jr	$ra
/*  f12acd0:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f12acd4:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f12acd8:	3c018008 */ 	lui	$at,0x8008
/*  f12acdc:	ac22e4a0 */ 	sw	$v0,-0x1b60($at)
/*  f12ace0:	3c018008 */ 	lui	$at,0x8008
/*  f12ace4:	03e00008 */ 	jr	$ra
/*  f12ace8:	ac22e4a4 */ 	sw	$v0,-0x1b5c($at)
);

GLOBAL_ASM(
glabel func0f12acec
.late_rodata
glabel var7f1b5588
.word 0x3f4ccccd
glabel var7f1b558c
.word 0x38d1b717
.text
/*  f12acec:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f12acf0:	3c0e8008 */ 	lui	$t6,%hi(var8007e4a0)
/*  f12acf4:	8dcee4a0 */ 	lw	$t6,%lo(var8007e4a0)($t6)
/*  f12acf8:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f12acfc:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f12ad00:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12ad04:	00809025 */ 	or	$s2,$a0,$zero
/*  f12ad08:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f12ad0c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f12ad10:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f12ad14:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f12ad18:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f12ad1c:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f12ad20:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f12ad24:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f12ad28:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f12ad2c:	15c00006 */ 	bnez	$t6,.L0f12ad48
/*  f12ad30:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f12ad34:	44806000 */ 	mtc1	$zero,$f12
/*  f12ad38:	0c002a94 */ 	jal	func0000aa50
/*  f12ad3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ad40:	1000007a */ 	beqz	$zero,.L0f12af2c
/*  f12ad44:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f12ad48:
/*  f12ad48:	3c017f1b */ 	lui	$at,%hi(var7f1b5588)
/*  f12ad4c:	c4345588 */ 	lwc1	$f20,%lo(var7f1b5588)($at)
/*  f12ad50:	0c0068f4 */ 	jal	fcos
/*  f12ad54:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad58:	46000606 */ 	mov.s	$f24,$f0
/*  f12ad5c:	0c0068f7 */ 	jal	fsin
/*  f12ad60:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad64:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f12ad68:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f12ad6c:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad70:	4604c182 */ 	mul.s	$f6,$f24,$f4
/*  f12ad74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ad78:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f12ad7c:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f12ad80:	0c0068f7 */ 	jal	fsin
/*  f12ad84:	e7b00054 */ 	swc1	$f16,0x54($sp)
/*  f12ad88:	46000606 */ 	mov.s	$f24,$f0
/*  f12ad8c:	0c0068f4 */ 	jal	fcos
/*  f12ad90:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad94:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f12ad98:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f12ad9c:	3c04800a */ 	lui	$a0,%hi(var800a3434)
/*  f12ada0:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f12ada4:	8c843434 */ 	lw	$a0,%lo(var800a3434)($a0)
/*  f12ada8:	4480b000 */ 	mtc1	$zero,$f22
/*  f12adac:	4608c182 */ 	mul.s	$f6,$f24,$f8
/*  f12adb0:	3c14800a */ 	lui	$s4,%hi(var800a3430)
/*  f12adb4:	26943430 */ 	addiu	$s4,$s4,%lo(var800a3430)
/*  f12adb8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12adbc:	00008025 */ 	or	$s0,$zero,$zero
/*  f12adc0:	3c02800a */ 	lui	$v0,%hi(var800a3430)
/*  f12adc4:	3c014170 */ 	lui	$at,0x4170
/*  f12adc8:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f12adcc:	2415002c */ 	addiu	$s5,$zero,0x2c
/*  f12add0:	4600b506 */ 	mov.s	$f20,$f22
/*  f12add4:	1880002f */ 	blez	$a0,.L0f12ae94
/*  f12add8:	e7aa0050 */ 	swc1	$f10,0x50($sp)
/*  f12addc:	4481d000 */ 	mtc1	$at,$f26
/*  f12ade0:	3c017f1b */ 	lui	$at,%hi(var7f1b558c)
/*  f12ade4:	3c138008 */ 	lui	$s3,%hi(g_ExplosionTypes)
/*  f12ade8:	2673e4b8 */ 	addiu	$s3,$s3,%lo(g_ExplosionTypes)
/*  f12adec:	c438558c */ 	lwc1	$f24,%lo(var7f1b558c)($at)
/*  f12adf0:	8c423430 */ 	lw	$v0,%lo(var800a3430)($v0)
.L0f12adf4:
/*  f12adf4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f12adf8:	50600022 */ 	beqzl	$v1,.L0f12ae84
/*  f12adfc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12ae00:	c4700008 */ 	lwc1	$f16,0x8($v1)
/*  f12ae04:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f12ae08:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f12ae0c:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f12ae10:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f12ae14:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f12ae18:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f12ae1c:	46044081 */ 	sub.s	$f2,$f8,$f4
/*  f12ae20:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f12ae24:	460a3381 */ 	sub.s	$f14,$f6,$f10
/*  f12ae28:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f12ae2c:	46128200 */ 	add.s	$f8,$f16,$f18
/*  f12ae30:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f12ae34:	0c012974 */ 	jal	sqrtf
/*  f12ae38:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f12ae3c:	46160032 */ 	c.eq.s	$f0,$f22
/*  f12ae40:	46000086 */ 	mov.s	$f2,$f0
/*  f12ae44:	45020003 */ 	bc1fl	.L0f12ae54
/*  f12ae48:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f12ae4c:	4600c086 */ 	mov.s	$f2,$f24
/*  f12ae50:	8e8f0000 */ 	lw	$t7,0x0($s4)
.L0f12ae54:
/*  f12ae54:	3c04800a */ 	lui	$a0,%hi(var800a3434)
/*  f12ae58:	8c843434 */ 	lw	$a0,%lo(var800a3434)($a0)
/*  f12ae5c:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f12ae60:	805803cc */ 	lb	$t8,0x3cc($v0)
/*  f12ae64:	03150019 */ 	multu	$t8,$s5
/*  f12ae68:	0000c812 */ 	mflo	$t9
/*  f12ae6c:	02794021 */ 	addu	$t0,$s3,$t9
/*  f12ae70:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f12ae74:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f12ae78:	461a0282 */ 	mul.s	$f10,$f0,$f26
/*  f12ae7c:	460aa500 */ 	add.s	$f20,$f20,$f10
/*  f12ae80:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f12ae84:
/*  f12ae84:	0204082a */ 	slt	$at,$s0,$a0
/*  f12ae88:	26310478 */ 	addiu	$s1,$s1,0x478
/*  f12ae8c:	1420ffd9 */ 	bnez	$at,.L0f12adf4
/*  f12ae90:	24420478 */ 	addiu	$v0,$v0,1144
.L0f12ae94:
/*  f12ae94:	3c038008 */ 	lui	$v1,%hi(var8007e4a4)
/*  f12ae98:	2463e4a4 */ 	addiu	$v1,$v1,%lo(var8007e4a4)
/*  f12ae9c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f12aea0:	3c013f80 */ 	lui	$at,0x3f80
/*  f12aea4:	18400005 */ 	blez	$v0,.L0f12aebc
/*  f12aea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12aeac:	44818000 */ 	mtc1	$at,$f16
/*  f12aeb0:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f12aeb4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f12aeb8:	4610a500 */ 	add.s	$f20,$f20,$f16
.L0f12aebc:
/*  f12aebc:	3c038008 */ 	lui	$v1,%hi(var8007e4a0)
/*  f12aec0:	2463e4a0 */ 	addiu	$v1,$v1,%lo(var8007e4a0)
/*  f12aec4:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f12aec8:	254bffff */ 	addiu	$t3,$t2,-1
/*  f12aecc:	316d0002 */ 	andi	$t5,$t3,0x2
/*  f12aed0:	11a00005 */ 	beqz	$t5,.L0f12aee8
/*  f12aed4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f12aed8:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f12aedc:	e4540004 */ 	swc1	$f20,0x4($v0)
/*  f12aee0:	10000004 */ 	beqz	$zero,.L0f12aef4
/*  f12aee4:	4600a507 */ 	neg.s	$f20,$f20
.L0f12aee8:
/*  f12aee8:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f12aeec:	4600a487 */ 	neg.s	$f18,$f20
/*  f12aef0:	e4520004 */ 	swc1	$f18,0x4($v0)
.L0f12aef4:
/*  f12aef4:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f12aef8:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f12aefc:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f12af00:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f12af04:	4606a282 */ 	mul.s	$f10,$f20,$f6
/*  f12af08:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f12af0c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f12af10:	448f8000 */ 	mtc1	$t7,$f16
/*  f12af14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12af18:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f12af1c:	46149302 */ 	mul.s	$f12,$f18,$f20
/*  f12af20:	0c002a94 */ 	jal	func0000aa50
/*  f12af24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12af28:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f12af2c:
/*  f12af2c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f12af30:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f12af34:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f12af38:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f12af3c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f12af40:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f12af44:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f12af48:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f12af4c:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f12af50:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f12af54:	03e00008 */ 	jr	$ra
/*  f12af58:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f12af5c
/*  f12af5c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f12af60:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f12af64:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f12af68:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f12af6c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f12af70:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f12af74:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f12af78:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f12af7c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f12af80:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12af84:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f12af88:	808e03cc */ 	lb	$t6,0x3cc($a0)
/*  f12af8c:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12af90:	00c09025 */ 	or	$s2,$a2,$zero
/*  f12af94:	00e09825 */ 	or	$s3,$a3,$zero
/*  f12af98:	15c10004 */ 	bne	$t6,$at,.L0f12afac
/*  f12af9c:	0080a825 */ 	or	$s5,$a0,$zero
/*  f12afa0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f12afa4:	10000042 */ 	beqz	$zero,.L0f12b0b0
/*  f12afa8:	afaf005c */ 	sw	$t7,0x5c($sp)
.L0f12afac:
/*  f12afac:	92b803cf */ 	lbu	$t8,0x3cf($s5)
/*  f12afb0:	00008825 */ 	or	$s1,$zero,$zero
/*  f12afb4:	02a08025 */ 	or	$s0,$s5,$zero
/*  f12afb8:	1b00003d */ 	blez	$t8,.L0f12b0b0
/*  f12afbc:	24b40028 */ 	addiu	$s4,$a1,0x28
/*  f12afc0:	27b70048 */ 	addiu	$s7,$sp,0x48
/*  f12afc4:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f12afc8:	86190400 */ 	lh	$t9,0x400($s0)
.L0f12afcc:
/*  f12afcc:	02802025 */ 	or	$a0,$s4,$zero
/*  f12afd0:	02e02825 */ 	or	$a1,$s7,$zero
/*  f12afd4:	a7b90048 */ 	sh	$t9,0x48($sp)
/*  f12afd8:	86020402 */ 	lh	$v0,0x402($s0)
/*  f12afdc:	52c20004 */ 	beql	$s6,$v0,.L0f12aff0
/*  f12afe0:	a7b6004a */ 	sh	$s6,0x4a($sp)
/*  f12afe4:	10000002 */ 	beqz	$zero,.L0f12aff0
/*  f12afe8:	a7a2004a */ 	sh	$v0,0x4a($sp)
/*  f12afec:	a7b6004a */ 	sh	$s6,0x4a($sp)
.L0f12aff0:
/*  f12aff0:	0fc19620 */ 	jal	arrayIntersects
/*  f12aff4:	a7b6004c */ 	sh	$s6,0x4c($sp)
/*  f12aff8:	50400028 */ 	beqzl	$v0,.L0f12b09c
/*  f12affc:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b000:	c60403f4 */ 	lwc1	$f4,0x3f4($s0)
/*  f12b004:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f12b008:	4604303e */ 	c.le.s	$f6,$f4
/*  f12b00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b010:	45020022 */ 	bc1fl	.L0f12b09c
/*  f12b014:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b018:	c60803f8 */ 	lwc1	$f8,0x3f8($s0)
/*  f12b01c:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f12b020:	4608503e */ 	c.le.s	$f10,$f8
/*  f12b024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b028:	4502001c */ 	bc1fl	.L0f12b09c
/*  f12b02c:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b030:	c61003fc */ 	lwc1	$f16,0x3fc($s0)
/*  f12b034:	c6520008 */ 	lwc1	$f18,0x8($s2)
/*  f12b038:	4610903e */ 	c.le.s	$f18,$f16
/*  f12b03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b040:	45020016 */ 	bc1fl	.L0f12b09c
/*  f12b044:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b048:	c6640000 */ 	lwc1	$f4,0x0($s3)
/*  f12b04c:	c60603e8 */ 	lwc1	$f6,0x3e8($s0)
/*  f12b050:	4604303e */ 	c.le.s	$f6,$f4
/*  f12b054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b058:	45020010 */ 	bc1fl	.L0f12b09c
/*  f12b05c:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b060:	c6680004 */ 	lwc1	$f8,0x4($s3)
/*  f12b064:	c60a03ec */ 	lwc1	$f10,0x3ec($s0)
/*  f12b068:	4608503e */ 	c.le.s	$f10,$f8
/*  f12b06c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b070:	4502000a */ 	bc1fl	.L0f12b09c
/*  f12b074:	92a903cf */ 	lbu	$t1,0x3cf($s5)
/*  f12b078:	c6700008 */ 	lwc1	$f16,0x8($s3)
/*  f12b07c:	c61203f0 */ 	lwc1	$f18,0x3f0($s0)
/*  f12b080:	4610903e */ 	c.le.s	$f18,$f16
/*  f12b084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b088:	45000003 */ 	bc1f	.L0f12b098
/*  f12b08c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f12b090:	10000007 */ 	beqz	$zero,.L0f12b0b0
/*  f12b094:	afa8005c */ 	sw	$t0,0x5c($sp)
.L0f12b098:
/*  f12b098:	92a903cf */ 	lbu	$t1,0x3cf($s5)
.L0f12b09c:
/*  f12b09c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12b0a0:	2610001c */ 	addiu	$s0,$s0,0x1c
/*  f12b0a4:	0229082a */ 	slt	$at,$s1,$t1
/*  f12b0a8:	5420ffc8 */ 	bnezl	$at,.L0f12afcc
/*  f12b0ac:	86190400 */ 	lh	$t9,0x400($s0)
.L0f12b0b0:
/*  f12b0b0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f12b0b4:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f12b0b8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f12b0bc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f12b0c0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f12b0c4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f12b0c8:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f12b0cc:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f12b0d0:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f12b0d4:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f12b0d8:	03e00008 */ 	jr	$ra
/*  f12b0dc:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f12b0e0
.late_rodata
glabel var7f1b5590
.word 0x3f333333
glabel var7f1b5594
.word 0x3e99999a
glabel var7f1b5598
.word 0x3d4ccccd
glabel var7f1b559c
.word 0x3d4ccccd
.text
/*  f12b0e0:	27bdfc58 */ 	addiu	$sp,$sp,-936
/*  f12b0e4:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f12b0e8:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f12b0ec:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f12b0f0:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f12b0f4:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f12b0f8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f12b0fc:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f12b100:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f12b104:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f12b108:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f12b10c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f12b110:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f12b114:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f12b118:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f12b11c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f12b120:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f12b124:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f12b128:	3c088008 */ 	lui	$t0,%hi(g_ExplosionTypes)
/*  f12b12c:	2508e4b8 */ 	addiu	$t0,$t0,%lo(g_ExplosionTypes)
/*  f12b130:	afae03a0 */ 	sw	$t6,0x3a0($sp)
/*  f12b134:	81d803cc */ 	lb	$t8,0x3cc($t6)
/*  f12b138:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f12b13c:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f12b140:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f12b144:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12b148:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b14c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12b150:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b154:	03284821 */ 	addu	$t1,$t9,$t0
/*  f12b158:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f12b15c:	85c203c8 */ 	lh	$v0,0x3c8($t6)
/*  f12b160:	8fcb0038 */ 	lw	$t3,0x38($s8)
/*  f12b164:	0080b825 */ 	or	$s7,$a0,$zero
/*  f12b168:	284a0001 */ 	slti	$t2,$v0,0x1
/*  f12b16c:	19600289 */ 	blez	$t3,.L0f12bb94
/*  f12b170:	afaa0194 */ 	sw	$t2,0x194($sp)
/*  f12b174:	4480e000 */ 	mtc1	$zero,$f28
/*  f12b178:	c5240028 */ 	lwc1	$f4,0x28($t1)
/*  f12b17c:	461c203e */ 	c.le.s	$f4,$f28
/*  f12b180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b184:	45030284 */ 	bc1tl	.L0f12bb98
/*  f12b188:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12b18c:	11400006 */ 	beqz	$t2,.L0f12b1a8
/*  f12b190:	8fb9039c */ 	lw	$t9,0x39c($sp)
/*  f12b194:	8538001c */ 	lh	$t8,0x1c($t1)
/*  f12b198:	c53a0018 */ 	lwc1	$f26,0x18($t1)
/*  f12b19c:	44983000 */ 	mtc1	$t8,$f6
/*  f12b1a0:	10000011 */ 	beqz	$zero,.L0f12b1e8
/*  f12b1a4:	46803320 */ 	cvt.s.w	$f12,$f6
.L0f12b1a8:
/*  f12b1a8:	44822000 */ 	mtc1	$v0,$f4
/*  f12b1ac:	c7200014 */ 	lwc1	$f0,0x14($t9)
/*  f12b1b0:	c7220018 */ 	lwc1	$f2,0x18($t9)
/*  f12b1b4:	8728001c */ 	lh	$t0,0x1c($t9)
/*  f12b1b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12b1bc:	44884000 */ 	mtc1	$t0,$f8
/*  f12b1c0:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f12b1c4:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f12b1c8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f12b1cc:	460c4103 */ 	div.s	$f4,$f8,$f12
/*  f12b1d0:	46040680 */ 	add.s	$f26,$f0,$f4
/*  f12b1d4:	461a103c */ 	c.lt.s	$f2,$f26
/*  f12b1d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b1dc:	45020003 */ 	bc1fl	.L0f12b1ec
/*  f12b1e0:	8fa9039c */ 	lw	$t1,0x39c($sp)
/*  f12b1e4:	46001686 */ 	mov.s	$f26,$f2
.L0f12b1e8:
/*  f12b1e8:	8fa9039c */ 	lw	$t1,0x39c($sp)
.L0f12b1ec:
/*  f12b1ec:	3c0140e0 */ 	lui	$at,0x40e0
/*  f12b1f0:	44815000 */ 	mtc1	$at,$f10
/*  f12b1f4:	c5260020 */ 	lwc1	$f6,0x20($t1)
/*  f12b1f8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f12b1fc:	46086100 */ 	add.s	$f4,$f12,$f8
/*  f12b200:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f12b204:	440a5000 */ 	mfc1	$t2,$f10
/*  f12b208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b20c:	0142082a */ 	slt	$at,$t2,$v0
/*  f12b210:	54200261 */ 	bnezl	$at,.L0f12bb98
/*  f12b214:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12b218:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b21c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b220:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f12b224:	50410015 */ 	beql	$v0,$at,.L0f12b27c
/*  f12b228:	2401ffff */ 	addiu	$at,$zero,-1
.L0f12b22c:
/*  f12b22c:	0c004b70 */ 	jal	random
/*  f12b230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b234:	304b07ff */ 	andi	$t3,$v0,0x7ff
/*  f12b238:	2d6100f1 */ 	sltiu	$at,$t3,0xf1
/*  f12b23c:	10200008 */ 	beqz	$at,.L0f12b260
/*  f12b240:	8fac039c */ 	lw	$t4,0x39c($sp)
/*  f12b244:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12b248:	86c40028 */ 	lh	$a0,0x28($s6)
/*  f12b24c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f12b250:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12b254:	44054000 */ 	mfc1	$a1,$f8
/*  f12b258:	0fc010e3 */ 	jal	func0f00438c
/*  f12b25c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12b260:
/*  f12b260:	86ce002a */ 	lh	$t6,0x2a($s6)
/*  f12b264:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b268:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12b26c:	15c1ffef */ 	bne	$t6,$at,.L0f12b22c
/*  f12b270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b274:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b278:	2401ffff */ 	addiu	$at,$zero,-1
.L0f12b27c:
/*  f12b27c:	10410049 */ 	beq	$v0,$at,.L0f12b3a4
/*  f12b280:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f12b284:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b288:	27b50158 */ 	addiu	$s5,$sp,0x158
/*  f12b28c:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f12b290:	27b30164 */ 	addiu	$s3,$sp,0x164
.L0f12b294:
/*  f12b294:	1040003e */ 	beqz	$v0,.L0f12b390
/*  f12b298:	00408825 */ 	or	$s1,$v0,$zero
/*  f12b29c:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f12b2a0:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f12b2a4:	3c09800a */ 	lui	$t1,%hi(var800a4cc4)
/*  f12b2a8:	8d294cc4 */ 	lw	$t1,%lo(var800a4cc4)($t1)
/*  f12b2ac:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b2b0:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f12b2b4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f12b2b8:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f12b2bc:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f12b2c0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f12b2c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12b2c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b2cc:	012f1021 */ 	addu	$v0,$t1,$t7
/*  f12b2d0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f12b2d4:	81120008 */ 	lb	$s2,0x8($t0)
/*  f12b2d8:	c6f40008 */ 	lwc1	$f20,0x8($s7)
/*  f12b2dc:	c6f6000c */ 	lwc1	$f22,0xc($s7)
/*  f12b2e0:	c6f80010 */ 	lwc1	$f24,0x10($s7)
/*  f12b2e4:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f12b2e8:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12b2ec:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f12b2f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f12b2f4:	4604a501 */ 	sub.s	$f20,$f20,$f4
/*  f12b2f8:	460ab581 */ 	sub.s	$f22,$f22,$f10
/*  f12b2fc:	1a400024 */ 	blez	$s2,.L0f12b390
/*  f12b300:	4606c601 */ 	sub.s	$f24,$f24,$f6
/*  f12b304:	02202025 */ 	or	$a0,$s1,$zero
.L0f12b308:
/*  f12b308:	0fc003d4 */ 	jal	func0f000f50
/*  f12b30c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b310:	1040001c */ 	beqz	$v0,.L0f12b384
/*  f12b314:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b318:	0fc003e5 */ 	jal	func0f000f94
/*  f12b31c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b320:	10400018 */ 	beqz	$v0,.L0f12b384
/*  f12b324:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b328:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b32c:	0fc0037f */ 	jal	func0f000dfc
/*  f12b330:	02603025 */ 	or	$a2,$s3,$zero
/*  f12b334:	10400013 */ 	beqz	$v0,.L0f12b384
/*  f12b338:	c7a80164 */ 	lwc1	$f8,0x164($sp)
/*  f12b33c:	46144101 */ 	sub.s	$f4,$f8,$f20
/*  f12b340:	c7a8016c */ 	lwc1	$f8,0x16c($sp)
/*  f12b344:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f12b348:	e7ba0158 */ 	swc1	$f26,0x158($sp)
/*  f12b34c:	e7a4014c */ 	swc1	$f4,0x14c($sp)
/*  f12b350:	46184101 */ 	sub.s	$f4,$f8,$f24
/*  f12b354:	e7ba015c */ 	swc1	$f26,0x15c($sp)
/*  f12b358:	e7ba0160 */ 	swc1	$f26,0x160($sp)
/*  f12b35c:	46165181 */ 	sub.s	$f6,$f10,$f22
/*  f12b360:	e7a40154 */ 	swc1	$f4,0x154($sp)
/*  f12b364:	02802025 */ 	or	$a0,$s4,$zero
/*  f12b368:	02a02825 */ 	or	$a1,$s5,$zero
/*  f12b36c:	0fc5dcf2 */ 	jal	func0f1773c8
/*  f12b370:	e7a60150 */ 	swc1	$f6,0x150($sp)
/*  f12b374:	10400003 */ 	beqz	$v0,.L0f12b384
/*  f12b378:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b37c:	0fc006de */ 	jal	func0f001b78
/*  f12b380:	02002825 */ 	or	$a1,$s0,$zero
.L0f12b384:
/*  f12b384:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12b388:	5612ffdf */ 	bnel	$s0,$s2,.L0f12b308
/*  f12b38c:	02202025 */ 	or	$a0,$s1,$zero
.L0f12b390:
/*  f12b390:	86c2002a */ 	lh	$v0,0x2a($s6)
/*  f12b394:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b398:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12b39c:	1441ffbd */ 	bne	$v0,$at,.L0f12b294
/*  f12b3a0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12b3a4:
/*  f12b3a4:	27b00198 */ 	addiu	$s0,$sp,0x198
/*  f12b3a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b3ac:	26e40028 */ 	addiu	$a0,$s7,0x28
/*  f12b3b0:	0fc197e0 */ 	jal	roomGetProps
/*  f12b3b4:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f12b3b8:	87aa0198 */ 	lh	$t2,0x198($sp)
/*  f12b3bc:	0200a025 */ 	or	$s4,$s0,$zero
/*  f12b3c0:	27ab0198 */ 	addiu	$t3,$sp,0x198
/*  f12b3c4:	054001f3 */ 	bltz	$t2,.L0f12bb94
/*  f12b3c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f12b3cc:	4481f000 */ 	mtc1	$at,$f30
/*  f12b3d0:	85620000 */ 	lh	$v0,0x0($t3)
/*  f12b3d4:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f12b3d8:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f12b3dc:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.L0f12b3e0:
/*  f12b3e0:	8fcd0338 */ 	lw	$t5,0x338($s8)
/*  f12b3e4:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f12b3e8:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f12b3ec:	01826021 */ 	addu	$t4,$t4,$v0
/*  f12b3f0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f12b3f4:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f12b3f8:	521801e3 */ 	beql	$s0,$t8,.L0f12bb88
/*  f12b3fc:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b400:	86190002 */ 	lh	$t9,0x2($s0)
/*  f12b404:	572001e0 */ 	bnezl	$t9,.L0f12bb88
/*  f12b408:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b40c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f12b410:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12b414:	50410006 */ 	beql	$v0,$at,.L0f12b430
/*  f12b418:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f12b41c:	12c20003 */ 	beq	$s6,$v0,.L0f12b42c
/*  f12b420:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12b424:	14410105 */ 	bne	$v0,$at,.L0f12b83c
/*  f12b428:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12b42c:
/*  f12b42c:	8e110004 */ 	lw	$s1,0x4($s0)
.L0f12b430:
/*  f12b430:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f12b434:	c6f00008 */ 	lwc1	$f16,0x8($s7)
/*  f12b438:	c60e000c */ 	lwc1	$f14,0xc($s0)
/*  f12b43c:	c6ec000c */ 	lwc1	$f12,0xc($s7)
/*  f12b440:	46109501 */ 	sub.s	$f20,$f18,$f16
/*  f12b444:	c6100010 */ 	lwc1	$f16,0x10($s0)
/*  f12b448:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12b44c:	460c7581 */ 	sub.s	$f22,$f14,$f12
/*  f12b450:	00009025 */ 	or	$s2,$zero,$zero
/*  f12b454:	122001cb */ 	beqz	$s1,.L0f12bb84
/*  f12b458:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f12b45c:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12b460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b464:	45000024 */ 	bc1f	.L0f12b4f8
/*  f12b468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b46c:	4600d007 */ 	neg.s	$f0,$f26
/*  f12b470:	4614003e */ 	c.le.s	$f0,$f20
/*  f12b474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b478:	4500001f */ 	bc1f	.L0f12b4f8
/*  f12b47c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b480:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12b484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b488:	4500001b */ 	bc1f	.L0f12b4f8
/*  f12b48c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b490:	4616003e */ 	c.le.s	$f0,$f22
/*  f12b494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b498:	45000017 */ 	bc1f	.L0f12b4f8
/*  f12b49c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b4a0:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12b4a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b4a8:	45000013 */ 	bc1f	.L0f12b4f8
/*  f12b4ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b4b0:	4618003e */ 	c.le.s	$f0,$f24
/*  f12b4b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b4b8:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f12b4bc:	4500000e */ 	bc1f	.L0f12b4f8
/*  f12b4c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b4c4:	0fc248c1 */ 	jal	func0f092304
/*  f12b4c8:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f12b4cc:	10400009 */ 	beqz	$v0,.L0f12b4f4
/*  f12b4d0:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12b4d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b4d8:	27a60130 */ 	addiu	$a2,$sp,0x130
/*  f12b4dc:	0fc4abd7 */ 	jal	func0f12af5c
/*  f12b4e0:	27a70124 */ 	addiu	$a3,$sp,0x124
/*  f12b4e4:	10400004 */ 	beqz	$v0,.L0f12b4f8
/*  f12b4e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b4ec:	10000002 */ 	beqz	$zero,.L0f12b4f8
/*  f12b4f0:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f12b4f4:
/*  f12b4f4:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f12b4f8:
/*  f12b4f8:	1240000c */ 	beqz	$s2,.L0f12b52c
/*  f12b4fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b500:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f12b504:	16c80009 */ 	bne	$s6,$t0,.L0f12b52c
/*  f12b508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b50c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f12b510:	10400006 */ 	beqz	$v0,.L0f12b52c
/*  f12b514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b518:	9049005c */ 	lbu	$t1,0x5c($v0)
/*  f12b51c:	24010058 */ 	addiu	$at,$zero,0x58
/*  f12b520:	15210002 */ 	bne	$t1,$at,.L0f12b52c
/*  f12b524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b528:	a4400062 */ 	sh	$zero,0x62($v0)
.L0f12b52c:
/*  f12b52c:	12400195 */ 	beqz	$s2,.L0f12bb84
/*  f12b530:	3c017f1b */ 	lui	$at,%hi(var7f1b5590)
/*  f12b534:	461aa003 */ 	div.s	$f0,$f20,$f26
/*  f12b538:	8faf039c */ 	lw	$t7,0x39c($sp)
/*  f12b53c:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12b540:	8faa03a0 */ 	lw	$t2,0x3a0($sp)
/*  f12b544:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f12b548:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*  f12b54c:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b550:	46000086 */ 	mov.s	$f2,$f0
/*  f12b554:	45020003 */ 	bc1fl	.L0f12b564
/*  f12b558:	461ab003 */ 	div.s	$f0,$f22,$f26
/*  f12b55c:	46000087 */ 	neg.s	$f2,$f0
/*  f12b560:	461ab003 */ 	div.s	$f0,$f22,$f26
.L0f12b564:
/*  f12b564:	4602f081 */ 	sub.s	$f2,$f30,$f2
/*  f12b568:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b56c:	46000306 */ 	mov.s	$f12,$f0
/*  f12b570:	45020003 */ 	bc1fl	.L0f12b580
/*  f12b574:	461ac003 */ 	div.s	$f0,$f24,$f26
/*  f12b578:	46000307 */ 	neg.s	$f12,$f0
/*  f12b57c:	461ac003 */ 	div.s	$f0,$f24,$f26
.L0f12b580:
/*  f12b580:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12b584:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b588:	46000386 */ 	mov.s	$f14,$f0
/*  f12b58c:	45020003 */ 	bc1fl	.L0f12b59c
/*  f12b590:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12b594:	46000387 */ 	neg.s	$f14,$f0
/*  f12b598:	4602603c */ 	c.lt.s	$f12,$f2
.L0f12b59c:
/*  f12b59c:	46001506 */ 	mov.s	$f20,$f2
/*  f12b5a0:	460ef381 */ 	sub.s	$f14,$f30,$f14
/*  f12b5a4:	45020003 */ 	bc1fl	.L0f12b5b4
/*  f12b5a8:	4614703c */ 	c.lt.s	$f14,$f20
/*  f12b5ac:	46006506 */ 	mov.s	$f20,$f12
/*  f12b5b0:	4614703c */ 	c.lt.s	$f14,$f20
.L0f12b5b4:
/*  f12b5b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b5b8:	45000002 */ 	bc1f	.L0f12b5c4
/*  f12b5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b5c0:	46007506 */ 	mov.s	$f20,$f14
.L0f12b5c4:
/*  f12b5c4:	c4285590 */ 	lwc1	$f8,%lo(var7f1b5590)($at)
/*  f12b5c8:	3c017f1b */ 	lui	$at,%hi(var7f1b5594)
/*  f12b5cc:	c42a5594 */ 	lwc1	$f10,%lo(var7f1b5594)($at)
/*  f12b5d0:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f12b5d4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b5d8:	46103502 */ 	mul.s	$f20,$f6,$f16
/*  f12b5dc:	04600008 */ 	bltz	$v1,.L0f12b600
/*  f12b5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b5e4:	814b03ce */ 	lb	$t3,0x3ce($t2)
/*  f12b5e8:	146b0005 */ 	bne	$v1,$t3,.L0f12b600
/*  f12b5ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b5f0:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f12b5f4:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12b5f8:	55a00163 */ 	bnezl	$t5,.L0f12bb88
/*  f12b5fc:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b600:
/*  f12b600:	11c00060 */ 	beqz	$t6,.L0f12b784
/*  f12b604:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b608:	0fc199b3 */ 	jal	func0f0666cc
/*  f12b60c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f12b610:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12b614:	30581000 */ 	andi	$t8,$v0,0x1000
/*  f12b618:	57000023 */ 	bnezl	$t8,.L0f12b6a8
/*  f12b61c:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12b620:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f12b624:	3c010020 */ 	lui	$at,0x20
/*  f12b628:	34210400 */ 	ori	$at,$at,0x400
/*  f12b62c:	03214024 */ 	and	$t0,$t9,$at
/*  f12b630:	5500001d */ 	bnezl	$t0,.L0f12b6a8
/*  f12b634:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12b638:	0c004b70 */ 	jal	random
/*  f12b63c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b640:	44824000 */ 	mtc1	$v0,$f8
/*  f12b644:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b648:	04410005 */ 	bgez	$v0,.L0f12b660
/*  f12b64c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f12b650:	3c014f80 */ 	lui	$at,0x4f80
/*  f12b654:	44815000 */ 	mtc1	$at,$f10
/*  f12b658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b65c:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12b660:
/*  f12b660:	3c012f80 */ 	lui	$at,0x2f80
/*  f12b664:	44813000 */ 	mtc1	$at,$f6
/*  f12b668:	3c013f00 */ 	lui	$at,0x3f00
/*  f12b66c:	44815000 */ 	mtc1	$at,$f10
/*  f12b670:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f12b674:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12b678:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12b67c:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f12b680:	812f03ce */ 	lb	$t7,0x3ce($t1)
/*  f12b684:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f12b688:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f12b68c:	461e2180 */ 	add.s	$f6,$f4,$f30
/*  f12b690:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12b694:	44054000 */ 	mfc1	$a1,$f8
/*  f12b698:	0fc21414 */ 	jal	func0f085050
/*  f12b69c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b6a0:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12b6a4:	00025140 */ 	sll	$t2,$v0,0x5
.L0f12b6a8:
/*  f12b6a8:	05400136 */ 	bltz	$t2,.L0f12bb84
/*  f12b6ac:	00025900 */ 	sll	$t3,$v0,0x4
/*  f12b6b0:	05620135 */ 	bltzl	$t3,.L0f12bb88
/*  f12b6b4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b6b8:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f12b6bc:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12b6c0:	51a00131 */ 	beqzl	$t5,.L0f12bb88
/*  f12b6c4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b6c8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12b6cc:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f12b6d0:	e7bc00f8 */ 	swc1	$f28,0xf8($sp)
/*  f12b6d4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12b6d8:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f12b6dc:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12b6e0:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f12b6e4:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f12b6e8:	4606e032 */ 	c.eq.s	$f28,$f6
/*  f12b6ec:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12b6f0:	45000006 */ 	bc1f	.L0f12b70c
/*  f12b6f4:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f12b6f8:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f12b6fc:	4608e032 */ 	c.eq.s	$f28,$f8
/*  f12b700:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b704:	45030017 */ 	bc1tl	.L0f12b764
/*  f12b708:	4406e000 */ 	mfc1	$a2,$f28
.L0f12b70c:
/*  f12b70c:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f12b710:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12b714:	460a5102 */ 	mul.s	$f4,$f10,$f10
/*  f12b718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b71c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f12b720:	0c012974 */ 	jal	sqrtf
/*  f12b724:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f12b728:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12b72c:	3c014080 */ 	lui	$at,0x4080
/*  f12b730:	4502000c */ 	bc1fl	.L0f12b764
/*  f12b734:	4406e000 */ 	mfc1	$a2,$f28
/*  f12b738:	44814000 */ 	mtc1	$at,$f8
/*  f12b73c:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12b740:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12b744:	4608a282 */ 	mul.s	$f10,$f20,$f8
/*  f12b748:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f12b74c:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f12b750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b754:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f12b758:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12b75c:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12b760:	4406e000 */ 	mfc1	$a2,$f28
.L0f12b764:
/*  f12b764:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12b768:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f12b76c:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b770:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f12b774:	0fc20a87 */ 	jal	func0f082a1c
/*  f12b778:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f12b77c:	10000102 */ 	beqz	$zero,.L0f12bb88
/*  f12b780:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b784:
/*  f12b784:	0fc21a6a */ 	jal	objIsHealthy
/*  f12b788:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b78c:	104000fd */ 	beqz	$v0,.L0f12bb84
/*  f12b790:	3c017f1b */ 	lui	$at,%hi(var7f1b5598)
/*  f12b794:	c4285598 */ 	lwc1	$f8,%lo(var7f1b5598)($at)
/*  f12b798:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12b79c:	8e380040 */ 	lw	$t8,0x40($s1)
/*  f12b7a0:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f12b7a4:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f12b7a8:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12b7ac:	572000f6 */ 	bnezl	$t9,.L0f12bb88
/*  f12b7b0:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b7b4:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f12b7b8:	3c010020 */ 	lui	$at,0x20
/*  f12b7bc:	34210400 */ 	ori	$at,$at,0x400
/*  f12b7c0:	01014824 */ 	and	$t1,$t0,$at
/*  f12b7c4:	552000f0 */ 	bnezl	$t1,.L0f12bb88
/*  f12b7c8:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b7cc:	0c004b70 */ 	jal	random
/*  f12b7d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b7d4:	44823000 */ 	mtc1	$v0,$f6
/*  f12b7d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b7dc:	04410005 */ 	bgez	$v0,.L0f12b7f4
/*  f12b7e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f12b7e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f12b7e8:	44815000 */ 	mtc1	$at,$f10
/*  f12b7ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b7f0:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f12b7f4:
/*  f12b7f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f12b7f8:	44812000 */ 	mtc1	$at,$f4
/*  f12b7fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f12b800:	44815000 */ 	mtc1	$at,$f10
/*  f12b804:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f12b808:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12b80c:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12b810:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f12b814:	81ea03ce */ 	lb	$t2,0x3ce($t7)
/*  f12b818:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f12b81c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f12b820:	461e4100 */ 	add.s	$f4,$f8,$f30
/*  f12b824:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f12b828:	44053000 */ 	mfc1	$a1,$f6
/*  f12b82c:	0fc21414 */ 	jal	func0f085050
/*  f12b830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b834:	100000d4 */ 	beqz	$zero,.L0f12bb88
/*  f12b838:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b83c:
/*  f12b83c:	12a20003 */ 	beq	$s5,$v0,.L0f12b84c
/*  f12b840:	24010006 */ 	addiu	$at,$zero,0x6
/*  f12b844:	544100d0 */ 	bnel	$v0,$at,.L0f12bb88
/*  f12b848:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b84c:
/*  f12b84c:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12b850:	c6e80008 */ 	lwc1	$f8,0x8($s7)
/*  f12b854:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f12b858:	c6e6000c */ 	lwc1	$f6,0xc($s7)
/*  f12b85c:	46085581 */ 	sub.s	$f22,$f10,$f8
/*  f12b860:	c6e80010 */ 	lwc1	$f8,0x10($s7)
/*  f12b864:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f12b868:	00008825 */ 	or	$s1,$zero,$zero
/*  f12b86c:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12b870:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f12b874:	4500003d */ 	bc1f	.L0f12b96c
/*  f12b878:	46085601 */ 	sub.s	$f24,$f10,$f8
/*  f12b87c:	4600d007 */ 	neg.s	$f0,$f26
/*  f12b880:	4616003e */ 	c.le.s	$f0,$f22
/*  f12b884:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b888:	45000038 */ 	bc1f	.L0f12b96c
/*  f12b88c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b890:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12b894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b898:	45000034 */ 	bc1f	.L0f12b96c
/*  f12b89c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8a0:	4614003e */ 	c.le.s	$f0,$f20
/*  f12b8a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8a8:	45000030 */ 	bc1f	.L0f12b96c
/*  f12b8ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8b0:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12b8b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8b8:	4500002c */ 	bc1f	.L0f12b96c
/*  f12b8bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8c0:	4618003e */ 	c.le.s	$f0,$f24
/*  f12b8c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b8c8:	27a500e0 */ 	addiu	$a1,$sp,0xe0
/*  f12b8cc:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f12b8d0:	45000026 */ 	bc1f	.L0f12b96c
/*  f12b8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8d8:	0fc19881 */ 	jal	propGetBbox
/*  f12b8dc:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f12b8e0:	3c0141a0 */ 	lui	$at,0x41a0
/*  f12b8e4:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f12b8e8:	44812000 */ 	mtc1	$at,$f4
/*  f12b8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b8f0:	46040001 */ 	sub.s	$f0,$f0,$f4
/*  f12b8f4:	461c003e */ 	c.le.s	$f0,$f28
/*  f12b8f8:	e7a000e0 */ 	swc1	$f0,0xe0($sp)
/*  f12b8fc:	45020003 */ 	bc1fl	.L0f12b90c
/*  f12b900:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f12b904:	e7bc00e0 */ 	swc1	$f28,0xe0($sp)
/*  f12b908:	c6060008 */ 	lwc1	$f6,0x8($s0)
.L0f12b90c:
/*  f12b90c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f12b910:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f12b914:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12b918:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f12b91c:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f12b920:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b924:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f12b928:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f12b92c:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f12b930:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f12b934:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f12b938:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f12b93c:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f12b940:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f12b944:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b948:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f12b94c:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f12b950:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f12b954:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b958:	0fc4abd7 */ 	jal	func0f12af5c
/*  f12b95c:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f12b960:	10400002 */ 	beqz	$v0,.L0f12b96c
/*  f12b964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12b968:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f12b96c:
/*  f12b96c:	52200086 */ 	beqzl	$s1,.L0f12bb88
/*  f12b970:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b974:	461ab083 */ 	div.s	$f2,$f22,$f26
/*  f12b978:	3c0c8008 */ 	lui	$t4,%hi(var8007e930)
/*  f12b97c:	258ce930 */ 	addiu	$t4,$t4,%lo(var8007e930)
/*  f12b980:	8d810000 */ 	lw	$at,0x0($t4)
/*  f12b984:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f12b988:	8d8e0004 */ 	lw	$t6,0x4($t4)
/*  f12b98c:	ad610000 */ 	sw	$at,0x0($t3)
/*  f12b990:	8d810008 */ 	lw	$at,0x8($t4)
/*  f12b994:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f12b998:	00008825 */ 	or	$s1,$zero,$zero
/*  f12b99c:	ad610008 */ 	sw	$at,0x8($t3)
/*  f12b9a0:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f12b9a4:	26f30008 */ 	addiu	$s3,$s7,0x8
/*  f12b9a8:	461aa383 */ 	div.s	$f14,$f20,$f26
/*  f12b9ac:	46001006 */ 	mov.s	$f0,$f2
/*  f12b9b0:	461c103c */ 	c.lt.s	$f2,$f28
/*  f12b9b4:	461ac483 */ 	div.s	$f18,$f24,$f26
/*  f12b9b8:	46007306 */ 	mov.s	$f12,$f14
/*  f12b9bc:	45000002 */ 	bc1f	.L0f12b9c8
/*  f12b9c0:	46009406 */ 	mov.s	$f16,$f18
/*  f12b9c4:	46001007 */ 	neg.s	$f0,$f2
.L0f12b9c8:
/*  f12b9c8:	461c703c */ 	c.lt.s	$f14,$f28
/*  f12b9cc:	4600f501 */ 	sub.s	$f20,$f30,$f0
/*  f12b9d0:	45020003 */ 	bc1fl	.L0f12b9e0
/*  f12b9d4:	461c903c */ 	c.lt.s	$f18,$f28
/*  f12b9d8:	46007307 */ 	neg.s	$f12,$f14
/*  f12b9dc:	461c903c */ 	c.lt.s	$f18,$f28
.L0f12b9e0:
/*  f12b9e0:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12b9e4:	45020003 */ 	bc1fl	.L0f12b9f4
/*  f12b9e8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f12b9ec:	46009407 */ 	neg.s	$f16,$f18
/*  f12b9f0:	4614603c */ 	c.lt.s	$f12,$f20
.L0f12b9f4:
/*  f12b9f4:	4610f401 */ 	sub.s	$f16,$f30,$f16
/*  f12b9f8:	45020003 */ 	bc1fl	.L0f12ba08
/*  f12b9fc:	4614803c */ 	c.lt.s	$f16,$f20
/*  f12ba00:	46006506 */ 	mov.s	$f20,$f12
/*  f12ba04:	4614803c */ 	c.lt.s	$f16,$f20
.L0f12ba08:
/*  f12ba08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba0c:	45000002 */ 	bc1f	.L0f12ba18
/*  f12ba10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba14:	46008506 */ 	mov.s	$f20,$f16
.L0f12ba18:
/*  f12ba18:	4614a502 */ 	mul.s	$f20,$f20,$f20
/*  f12ba1c:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f12ba20:	3c014100 */ 	lui	$at,0x4100
/*  f12ba24:	44815000 */ 	mtc1	$at,$f10
/*  f12ba28:	c7080028 */ 	lwc1	$f8,0x28($t8)
/*  f12ba2c:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f12ba30:	3c017f1b */ 	lui	$at,%hi(var7f1b559c)
/*  f12ba34:	46144102 */ 	mul.s	$f4,$f8,$f20
/*  f12ba38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba3c:	460a2502 */ 	mul.s	$f20,$f4,$f10
/*  f12ba40:	1320001a */ 	beqz	$t9,.L0f12baac
/*  f12ba44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba48:	461cb032 */ 	c.eq.s	$f22,$f28
/*  f12ba4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba50:	45000005 */ 	bc1f	.L0f12ba68
/*  f12ba54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba58:	461cc032 */ 	c.eq.s	$f24,$f28
/*  f12ba5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba60:	45030019 */ 	bc1tl	.L0f12bac8
/*  f12ba64:	8fc80318 */ 	lw	$t0,0x318($s8)
.L0f12ba68:
/*  f12ba68:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f12ba6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba70:	4618c202 */ 	mul.s	$f8,$f24,$f24
/*  f12ba74:	0c012974 */ 	jal	sqrtf
/*  f12ba78:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f12ba7c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12ba80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba84:	45020010 */ 	bc1fl	.L0f12bac8
/*  f12ba88:	8fc80318 */ 	lw	$t0,0x318($s8)
/*  f12ba8c:	4600f083 */ 	div.s	$f2,$f30,$f0
/*  f12ba90:	e7bc00a4 */ 	swc1	$f28,0xa4($sp)
/*  f12ba94:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*  f12ba98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ba9c:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*  f12baa0:	e7b600a0 */ 	swc1	$f22,0xa0($sp)
/*  f12baa4:	10000007 */ 	beqz	$zero,.L0f12bac4
/*  f12baa8:	e7b800a8 */ 	swc1	$f24,0xa8($sp)
.L0f12baac:
/*  f12baac:	c424559c */ 	lwc1	$f4,%lo(var7f1b559c)($at)
/*  f12bab0:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12bab4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f12bab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12babc:	4606a502 */ 	mul.s	$f20,$f20,$f6
/*  f12bac0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12bac4:
/*  f12bac4:	8fc80318 */ 	lw	$t0,0x318($s8)
.L0f12bac8:
/*  f12bac8:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12bacc:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12bad0:	51000008 */ 	beqzl	$t0,.L0f12baf4
/*  f12bad4:	81e203ce */ 	lb	$v0,0x3ce($t7)
/*  f12bad8:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f12badc:	812403ce */ 	lb	$a0,0x3ce($t1)
/*  f12bae0:	5040001a */ 	beqzl	$v0,.L0f12bb4c
/*  f12bae4:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bae8:	10000017 */ 	beqz	$zero,.L0f12bb48
/*  f12baec:	8c51001c */ 	lw	$s1,0x1c($v0)
/*  f12baf0:	81e203ce */ 	lb	$v0,0x3ce($t7)
.L0f12baf4:
/*  f12baf4:	8fca0294 */ 	lw	$t2,0x294($s8)
/*  f12baf8:	55420005 */ 	bnel	$t2,$v0,.L0f12bb10
/*  f12bafc:	8fc30298 */ 	lw	$v1,0x298($s8)
/*  f12bb00:	8fcd02a0 */ 	lw	$t5,0x2a0($s8)
/*  f12bb04:	10000010 */ 	beqz	$zero,.L0f12bb48
/*  f12bb08:	8db100bc */ 	lw	$s1,0xbc($t5)
/*  f12bb0c:	8fc30298 */ 	lw	$v1,0x298($s8)
.L0f12bb10:
/*  f12bb10:	04620007 */ 	bltzl	$v1,.L0f12bb30
/*  f12bb14:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12bb18:	54620005 */ 	bnel	$v1,$v0,.L0f12bb30
/*  f12bb1c:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12bb20:	8fcb02a4 */ 	lw	$t3,0x2a4($s8)
/*  f12bb24:	10000008 */ 	beqz	$zero,.L0f12bb48
/*  f12bb28:	8d7100bc */ 	lw	$s1,0xbc($t3)
/*  f12bb2c:	8fc3029c */ 	lw	$v1,0x29c($s8)
.L0f12bb30:
/*  f12bb30:	04620006 */ 	bltzl	$v1,.L0f12bb4c
/*  f12bb34:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bb38:	54620004 */ 	bnel	$v1,$v0,.L0f12bb4c
/*  f12bb3c:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bb40:	8fcc02a8 */ 	lw	$t4,0x2a8($s8)
/*  f12bb44:	8d9100bc */ 	lw	$s1,0xbc($t4)
.L0f12bb48:
/*  f12bb48:	4405a000 */ 	mfc1	$a1,$f20
.L0f12bb4c:
/*  f12bb4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f12bb50:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f12bb54:	02203825 */ 	or	$a3,$s1,$zero
/*  f12bb58:	0fc0d104 */ 	jal	func0f034410
/*  f12bb5c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f12bb60:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f12bb64:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f12bb68:	56ae0007 */ 	bnel	$s5,$t6,.L0f12bb88
/*  f12bb6c:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12bb70:	17000004 */ 	bnez	$t8,.L0f12bb84
/*  f12bb74:	02402025 */ 	or	$a0,$s2,$zero
/*  f12bb78:	4406d000 */ 	mfc1	$a2,$f26
/*  f12bb7c:	0fc09c3d */ 	jal	func0f0270f4
/*  f12bb80:	02602825 */ 	or	$a1,$s3,$zero
.L0f12bb84:
/*  f12bb84:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12bb88:
/*  f12bb88:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f12bb8c:	0443fe14 */ 	bgezl	$v0,.L0f12b3e0
/*  f12bb90:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.L0f12bb94:
/*  f12bb94:	8fbf0074 */ 	lw	$ra,0x74($sp)
.L0f12bb98:
/*  f12bb98:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12bb9c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f12bba0:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f12bba4:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f12bba8:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f12bbac:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f12bbb0:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f12bbb4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f12bbb8:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f12bbbc:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f12bbc0:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f12bbc4:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f12bbc8:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f12bbcc:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f12bbd0:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f12bbd4:	03e00008 */ 	jr	$ra
/*  f12bbd8:	27bd03a8 */ 	addiu	$sp,$sp,0x3a8
);

GLOBAL_ASM(
glabel func0f12bbdc
.late_rodata
glabel var7f1b55a0
.word 0x40c907a9
glabel var7f1b55a4
.word 0x3e4ccccd
glabel var7f1b55a8
.word 0x3f4ccccd
.text
/*  f12bbdc:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f12bbe0:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f12bbe4:	afb70080 */ 	sw	$s7,0x80($sp)
/*  f12bbe8:	afb6007c */ 	sw	$s6,0x7c($sp)
/*  f12bbec:	afb50078 */ 	sw	$s5,0x78($sp)
/*  f12bbf0:	afb40074 */ 	sw	$s4,0x74($sp)
/*  f12bbf4:	afb30070 */ 	sw	$s3,0x70($sp)
/*  f12bbf8:	afb2006c */ 	sw	$s2,0x6c($sp)
/*  f12bbfc:	afb10068 */ 	sw	$s1,0x68($sp)
/*  f12bc00:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f12bc04:	f7b60058 */ 	sdc1	$f22,0x58($sp)
/*  f12bc08:	f7b40050 */ 	sdc1	$f20,0x50($sp)
/*  f12bc0c:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f12bc10:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f12bc14:	3c188008 */ 	lui	$t8,%hi(g_ExplosionTypes)
/*  f12bc18:	822e03cc */ 	lb	$t6,0x3cc($s1)
/*  f12bc1c:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f12bc20:	2718e4b8 */ 	addiu	$t8,$t8,%lo(g_ExplosionTypes)
/*  f12bc24:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f12bc28:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12bc2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12bc30:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12bc34:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12bc38:	8ea20038 */ 	lw	$v0,0x38($s5)
/*  f12bc3c:	01f8b021 */ 	addu	$s6,$t7,$t8
/*  f12bc40:	86d9001c */ 	lh	$t9,0x1c($s6)
/*  f12bc44:	0080b825 */ 	or	$s7,$a0,$zero
/*  f12bc48:	14400003 */ 	bnez	$v0,.L0f12bc58
/*  f12bc4c:	a7b9012e */ 	sh	$t9,0x12e($sp)
/*  f12bc50:	10000248 */ 	beqz	$zero,.L0f12c574
/*  f12bc54:	00001025 */ 	or	$v0,$zero,$zero
.L0f12bc58:
/*  f12bc58:	2841000f */ 	slti	$at,$v0,0xf
/*  f12bc5c:	50200007 */ 	beqzl	$at,.L0f12bc7c
/*  f12bc60:	3c014170 */ 	lui	$at,0x4170
/*  f12bc64:	44822000 */ 	mtc1	$v0,$f4
/*  f12bc68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bc6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12bc70:	10000005 */ 	beqz	$zero,.L0f12bc88
/*  f12bc74:	e7a60148 */ 	swc1	$f6,0x148($sp)
/*  f12bc78:	3c014170 */ 	lui	$at,0x4170
.L0f12bc7c:
/*  f12bc7c:	44814000 */ 	mtc1	$at,$f8
/*  f12bc80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bc84:	e7a80148 */ 	swc1	$f8,0x148($sp)
.L0f12bc88:
/*  f12bc88:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12bc8c:	87a8012e */ 	lh	$t0,0x12e($sp)
/*  f12bc90:	28c10008 */ 	slti	$at,$a2,0x8
/*  f12bc94:	14200141 */ 	bnez	$at,.L0f12c19c
/*  f12bc98:	00c8082a */ 	slt	$at,$a2,$t0
/*  f12bc9c:	1020013f */ 	beqz	$at,.L0f12c19c
/*  f12bca0:	02202025 */ 	or	$a0,$s1,$zero
/*  f12bca4:	0fc4a6c2 */ 	jal	func0f129b08
/*  f12bca8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f12bcac:	46000506 */ 	mov.s	$f20,$f0
/*  f12bcb0:	02202025 */ 	or	$a0,$s1,$zero
/*  f12bcb4:	0fc4a6e9 */ 	jal	func0f129ba4
/*  f12bcb8:	862503c8 */ 	lh	$a1,0x3c8($s1)
/*  f12bcbc:	3c013f00 */ 	lui	$at,0x3f00
/*  f12bcc0:	44815000 */ 	mtc1	$at,$f10
/*  f12bcc4:	c6f20008 */ 	lwc1	$f18,0x8($s7)
/*  f12bcc8:	44813000 */ 	mtc1	$at,$f6
/*  f12bccc:	460aa082 */ 	mul.s	$f2,$f20,$f10
/*  f12bcd0:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12bcd4:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f12bcd8:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12bcdc:	e7a4011c */ 	swc1	$f4,0x11c($sp)
/*  f12bce0:	c6e8000c */ 	lwc1	$f8,0xc($s7)
/*  f12bce4:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f12bce8:	e7aa0120 */ 	swc1	$f10,0x120($sp)
/*  f12bcec:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12bcf0:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12bcf4:	e7a40124 */ 	swc1	$f4,0x124($sp)
/*  f12bcf8:	c6e60008 */ 	lwc1	$f6,0x8($s7)
/*  f12bcfc:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f12bd00:	e7a80110 */ 	swc1	$f8,0x110($sp)
/*  f12bd04:	c6ea000c */ 	lwc1	$f10,0xc($s7)
/*  f12bd08:	460c5480 */ 	add.s	$f18,$f10,$f12
/*  f12bd0c:	e7b20114 */ 	swc1	$f18,0x114($sp)
/*  f12bd10:	c6e40010 */ 	lwc1	$f4,0x10($s7)
/*  f12bd14:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f12bd18:	e7a60118 */ 	swc1	$f6,0x118($sp)
/*  f12bd1c:	822903cc */ 	lb	$t1,0x3cc($s1)
/*  f12bd20:	5521000c */ 	bnel	$t1,$at,.L0f12bd54
/*  f12bd24:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12bd28:	862a03c8 */ 	lh	$t2,0x3c8($s1)
/*  f12bd2c:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12bd30:	29410020 */ 	slti	$at,$t2,0x20
/*  f12bd34:	10200006 */ 	beqz	$at,.L0f12bd50
/*  f12bd38:	3c014120 */ 	lui	$at,0x4120
/*  f12bd3c:	44814000 */ 	mtc1	$at,$f8
/*  f12bd40:	c6e4000c */ 	lwc1	$f4,0xc($s7)
/*  f12bd44:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f12bd48:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f12bd4c:	e6e6000c */ 	swc1	$f6,0xc($s7)
.L0f12bd50:
/*  f12bd50:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12bd54:
/*  f12bd54:	86cb001e */ 	lh	$t3,0x1e($s6)
/*  f12bd58:	87ac012e */ 	lh	$t4,0x12e($sp)
/*  f12bd5c:	44862000 */ 	mtc1	$a2,$f4
/*  f12bd60:	448b4000 */ 	mtc1	$t3,$f8
/*  f12bd64:	0000a025 */ 	or	$s4,$zero,$zero
/*  f12bd68:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f12bd6c:	3c012f80 */ 	lui	$at,0x2f80
/*  f12bd70:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f12bd74:	448c4000 */ 	mtc1	$t4,$f8
/*  f12bd78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bd7c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f12bd80:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f12bd84:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f12bd88:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f12bd8c:	440e9000 */ 	mfc1	$t6,$f18
/*  f12bd90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bd94:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f12bd98:	19e00100 */ 	blez	$t7,.L0f12c19c
/*  f12bd9c:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f12bda0:	4481b000 */ 	mtc1	$at,$f22
/*  f12bda4:	3c013f80 */ 	lui	$at,0x3f80
/*  f12bda8:	4481a000 */ 	mtc1	$at,$f20
/*  f12bdac:	24120028 */ 	addiu	$s2,$zero,0x28
/*  f12bdb0:	00001825 */ 	or	$v1,$zero,$zero
.L0f12bdb4:
/*  f12bdb4:	02208025 */ 	or	$s0,$s1,$zero
.L0f12bdb8:
/*  f12bdb8:	8618001c */ 	lh	$t8,0x1c($s0)
/*  f12bdbc:	570000f0 */ 	bnezl	$t8,.L0f12c180
/*  f12bdc0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12bdc4:	922403cf */ 	lbu	$a0,0x3cf($s1)
/*  f12bdc8:	50800006 */ 	beqzl	$a0,.L0f12bde4
/*  f12bdcc:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12bdd0:	823903cc */ 	lb	$t9,0x3cc($s1)
/*  f12bdd4:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12bdd8:	1721000f */ 	bne	$t9,$at,.L0f12be18
/*  f12bddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bde0:	c7a00120 */ 	lwc1	$f0,0x120($sp)
.L0f12bde4:
/*  f12bde4:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12bde8:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12bdec:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bdf0:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bdf4:	c7a8011c */ 	lwc1	$f8,0x11c($sp)
/*  f12bdf8:	00009825 */ 	or	$s3,$zero,$zero
/*  f12bdfc:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12be00:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12be04:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12be08:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12be0c:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12be10:	10000089 */ 	beqz	$zero,.L0f12c038
/*  f12be14:	e7a800fc */ 	swc1	$f8,0xfc($sp)
.L0f12be18:
/*  f12be18:	0064001a */ 	div	$zero,$v1,$a0
/*  f12be1c:	00009810 */ 	mfhi	$s3
/*  f12be20:	001340c0 */ 	sll	$t0,$s3,0x3
/*  f12be24:	01134023 */ 	subu	$t0,$t0,$s3
/*  f12be28:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12be2c:	02281021 */ 	addu	$v0,$s1,$t0
/*  f12be30:	c44603e8 */ 	lwc1	$f6,0x3e8($v0)
/*  f12be34:	14800002 */ 	bnez	$a0,.L0f12be40
/*  f12be38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12be3c:	0007000d */ 	break	0x7
.L0f12be40:
/*  f12be40:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12be44:	14810004 */ 	bne	$a0,$at,.L0f12be58
/*  f12be48:	3c018000 */ 	lui	$at,0x8000
/*  f12be4c:	14610002 */ 	bne	$v1,$at,.L0f12be58
/*  f12be50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12be54:	0006000d */ 	break	0x6
.L0f12be58:
/*  f12be58:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12be5c:	c44403ec */ 	lwc1	$f4,0x3ec($v0)
/*  f12be60:	e7a40100 */ 	swc1	$f4,0x100($sp)
/*  f12be64:	c44a03f0 */ 	lwc1	$f10,0x3f0($v0)
/*  f12be68:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12be6c:	e7aa0104 */ 	swc1	$f10,0x104($sp)
/*  f12be70:	c45203f4 */ 	lwc1	$f18,0x3f4($v0)
/*  f12be74:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f12be78:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
/*  f12be7c:	c44803f8 */ 	lwc1	$f8,0x3f8($v0)
/*  f12be80:	460a203c */ 	c.lt.s	$f4,$f10
/*  f12be84:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f12be88:	c44603fc */ 	lwc1	$f6,0x3fc($v0)
/*  f12be8c:	45000002 */ 	bc1f	.L0f12be98
/*  f12be90:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f12be94:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
.L0f12be98:
/*  f12be98:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12be9c:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f12bea0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f12bea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bea8:	45020003 */ 	bc1fl	.L0f12beb8
/*  f12beac:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12beb0:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12beb4:	c7a20124 */ 	lwc1	$f2,0x124($sp)
.L0f12beb8:
/*  f12beb8:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f12bebc:	4602403c */ 	c.lt.s	$f8,$f2
/*  f12bec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bec4:	45020003 */ 	bc1fl	.L0f12bed4
/*  f12bec8:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12becc:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12bed0:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
.L0f12bed4:
/*  f12bed4:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f12bed8:	4606603c */ 	c.lt.s	$f12,$f6
/*  f12bedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bee0:	45020003 */ 	bc1fl	.L0f12bef0
/*  f12bee4:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bee8:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12beec:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
.L0f12bef0:
/*  f12bef0:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12bef4:	4604703c */ 	c.lt.s	$f14,$f4
/*  f12bef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12befc:	45020003 */ 	bc1fl	.L0f12bf0c
/*  f12bf00:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bf04:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12bf08:	c7b00118 */ 	lwc1	$f16,0x118($sp)
.L0f12bf0c:
/*  f12bf0c:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12bf10:	460a803c */ 	c.lt.s	$f16,$f10
/*  f12bf14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bf18:	45020003 */ 	bc1fl	.L0f12bf28
/*  f12bf1c:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12bf20:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12bf24:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
.L0f12bf28:
/*  f12bf28:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12bf2c:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12bf30:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12bf34:	4612403e */ 	c.le.s	$f8,$f18
/*  f12bf38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bf3c:	4503000b */ 	bc1tl	.L0f12bf6c
/*  f12bf40:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12bf44:	4606203e */ 	c.le.s	$f4,$f6
/*  f12bf48:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12bf4c:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f12bf50:	45030006 */ 	bc1tl	.L0f12bf6c
/*  f12bf54:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12bf58:	460a903e */ 	c.le.s	$f18,$f10
/*  f12bf5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bf60:	45000035 */ 	bc1f	.L0f12c038
/*  f12bf64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bf68:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
.L0f12bf6c:
/*  f12bf6c:	00009825 */ 	or	$s3,$zero,$zero
/*  f12bf70:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12bf74:	c62603ec */ 	lwc1	$f6,0x3ec($s1)
/*  f12bf78:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f12bf7c:	c62403f0 */ 	lwc1	$f4,0x3f0($s1)
/*  f12bf80:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f12bf84:	e7a40104 */ 	swc1	$f4,0x104($sp)
/*  f12bf88:	c62a03f4 */ 	lwc1	$f10,0x3f4($s1)
/*  f12bf8c:	c7a4011c */ 	lwc1	$f4,0x11c($sp)
/*  f12bf90:	e7aa00f0 */ 	swc1	$f10,0xf0($sp)
/*  f12bf94:	c63203f8 */ 	lwc1	$f18,0x3f8($s1)
/*  f12bf98:	4604303c */ 	c.lt.s	$f6,$f4
/*  f12bf9c:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f12bfa0:	c62803fc */ 	lwc1	$f8,0x3fc($s1)
/*  f12bfa4:	45000002 */ 	bc1f	.L0f12bfb0
/*  f12bfa8:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f12bfac:	e7a400fc */ 	swc1	$f4,0xfc($sp)
.L0f12bfb0:
/*  f12bfb0:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12bfb4:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f12bfb8:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12bfbc:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12bfc0:	4600503c */ 	c.lt.s	$f10,$f0
/*  f12bfc4:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bfc8:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bfcc:	45020003 */ 	bc1fl	.L0f12bfdc
/*  f12bfd0:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12bfd4:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12bfd8:	c7b20104 */ 	lwc1	$f18,0x104($sp)
.L0f12bfdc:
/*  f12bfdc:	4602903c */ 	c.lt.s	$f18,$f2
/*  f12bfe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bfe4:	45020003 */ 	bc1fl	.L0f12bff4
/*  f12bfe8:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12bfec:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12bff0:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
.L0f12bff4:
/*  f12bff4:	4608603c */ 	c.lt.s	$f12,$f8
/*  f12bff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12bffc:	45020003 */ 	bc1fl	.L0f12c00c
/*  f12c000:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12c004:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12c008:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
.L0f12c00c:
/*  f12c00c:	4606703c */ 	c.lt.s	$f14,$f6
/*  f12c010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c014:	45020003 */ 	bc1fl	.L0f12c024
/*  f12c018:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f12c01c:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12c020:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
.L0f12c024:
/*  f12c024:	4604803c */ 	c.lt.s	$f16,$f4
/*  f12c028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c02c:	45000002 */ 	bc1f	.L0f12c038
/*  f12c030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c034:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
.L0f12c038:
/*  f12c038:	0c004b70 */ 	jal	random
/*  f12c03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c040:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f12c044:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12c048:	44823000 */ 	mtc1	$v0,$f6
/*  f12c04c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c050:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12c054:	04410004 */ 	bgez	$v0,.L0f12c068
/*  f12c058:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12c05c:	44815000 */ 	mtc1	$at,$f10
/*  f12c060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c064:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c068:
/*  f12c068:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12c06c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c070:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12c074:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c078:	0c004b70 */ 	jal	random
/*  f12c07c:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f12c080:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f12c084:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12c088:	44829000 */ 	mtc1	$v0,$f18
/*  f12c08c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c090:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f12c094:	04410004 */ 	bgez	$v0,.L0f12c0a8
/*  f12c098:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12c09c:	44814000 */ 	mtc1	$at,$f8
/*  f12c0a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c0a4:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f12c0a8:
/*  f12c0a8:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f12c0ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c0b0:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f12c0b4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f12c0b8:	0c004b70 */ 	jal	random
/*  f12c0bc:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f12c0c0:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12c0c4:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12c0c8:	44823000 */ 	mtc1	$v0,$f6
/*  f12c0cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c0d0:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12c0d4:	04410004 */ 	bgez	$v0,.L0f12c0e8
/*  f12c0d8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12c0dc:	44815000 */ 	mtc1	$at,$f10
/*  f12c0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c0e4:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c0e8:
/*  f12c0e8:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12c0ec:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f12c0f0:	a213001e */ 	sb	$s3,0x1e($s0)
/*  f12c0f4:	a609001c */ 	sh	$t1,0x1c($s0)
/*  f12c0f8:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12c0fc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c100:	0c004b70 */ 	jal	random
/*  f12c104:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f12c108:	44824000 */ 	mtc1	$v0,$f8
/*  f12c10c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c110:	04410004 */ 	bgez	$v0,.L0f12c124
/*  f12c114:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f12c118:	44815000 */ 	mtc1	$at,$f10
/*  f12c11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c120:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f12c124:
/*  f12c124:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f12c128:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c12c:	44812000 */ 	mtc1	$at,$f4
/*  f12c130:	c6c60010 */ 	lwc1	$f6,0x10($s6)
/*  f12c134:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f12c138:	46144280 */ 	add.s	$f10,$f8,$f20
/*  f12c13c:	46065482 */ 	mul.s	$f18,$f10,$f6
/*  f12c140:	0c004b70 */ 	jal	random
/*  f12c144:	e6120014 */ 	swc1	$f18,0x14($s0)
/*  f12c148:	44822000 */ 	mtc1	$v0,$f4
/*  f12c14c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c150:	04410004 */ 	bgez	$v0,.L0f12c164
/*  f12c154:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12c158:	44815000 */ 	mtc1	$at,$f10
/*  f12c15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c160:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f12c164:
/*  f12c164:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f12c168:	3c017f1b */ 	lui	$at,%hi(var7f1b55a0)
/*  f12c16c:	c43255a0 */ 	lwc1	$f18,%lo(var7f1b55a0)($at)
/*  f12c170:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f12c174:	10000004 */ 	beqz	$zero,.L0f12c188
/*  f12c178:	e6040018 */ 	swc1	$f4,0x18($s0)
/*  f12c17c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f12c180:
/*  f12c180:	1472ff0d */ 	bne	$v1,$s2,.L0f12bdb8
/*  f12c184:	26100018 */ 	addiu	$s0,$s0,0x18
.L0f12c188:
/*  f12c188:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f12c18c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12c190:	568aff08 */ 	bnel	$s4,$t2,.L0f12bdb4
/*  f12c194:	00001825 */ 	or	$v1,$zero,$zero
/*  f12c198:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12c19c:
/*  f12c19c:	3c012f80 */ 	lui	$at,0x2f80
/*  f12c1a0:	4481b000 */ 	mtc1	$at,$f22
/*  f12c1a4:	27b0013c */ 	addiu	$s0,$sp,0x13c
/*  f12c1a8:	27b20130 */ 	addiu	$s2,$sp,0x130
/*  f12c1ac:	02402825 */ 	or	$a1,$s2,$zero
/*  f12c1b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c1b4:	0fc4a702 */ 	jal	func0f129c08
/*  f12c1b8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f12c1bc:	26e60028 */ 	addiu	$a2,$s7,0x28
/*  f12c1c0:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f12c1c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c1c8:	02402825 */ 	or	$a1,$s2,$zero
/*  f12c1cc:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f12c1d0:	0fc59434 */ 	jal	func0f1650d0
/*  f12c1d4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12c1d8:	0fc4ac38 */ 	jal	func0f12b0e0
/*  f12c1dc:	02e02025 */ 	or	$a0,$s7,$zero
/*  f12c1e0:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c1e4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f12c1e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f12c1ec:	14c00016 */ 	bnez	$a2,.L0f12c248
/*  f12c1f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f12c1f4:	86c60026 */ 	lh	$a2,0x26($s6)
/*  f12c1f8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f12c1fc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f12c200:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12c204:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f12c208:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f12c20c:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f12c210:	44810000 */ 	mtc1	$at,$f0
/*  f12c214:	240effff */ 	addiu	$t6,$zero,-1
/*  f12c218:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f12c21c:	244d0028 */ 	addiu	$t5,$v0,0x28
/*  f12c220:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f12c224:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f12c228:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f12c22c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f12c230:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f12c234:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f12c238:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f12c23c:	0fc24e7e */ 	jal	func0f0939f8
/*  f12c240:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f12c244:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12c248:
/*  f12c248:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12c24c:	87b9012e */ 	lh	$t9,0x12e($sp)
/*  f12c250:	0000a025 */ 	or	$s4,$zero,$zero
/*  f12c254:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f12c258:	241203c0 */ 	addiu	$s2,$zero,0x3c0
/*  f12c25c:	00194043 */ 	sra	$t0,$t9,0x1
/*  f12c260:	44184000 */ 	mfc1	$t8,$f8
/*  f12c264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c268:	1b0000ac */ 	blez	$t8,.L0f12c51c
/*  f12c26c:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f12c270:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f12c274:	24c90001 */ 	addiu	$t1,$a2,0x1
.L0f12c278:
/*  f12c278:	a62903c8 */ 	sh	$t1,0x3c8($s1)
/*  f12c27c:	00001025 */ 	or	$v0,$zero,$zero
/*  f12c280:	02208025 */ 	or	$s0,$s1,$zero
.L0f12c284:
/*  f12c284:	8603001c */ 	lh	$v1,0x1c($s0)
/*  f12c288:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f12c28c:	18600002 */ 	blez	$v1,.L0f12c298
/*  f12c290:	246a0001 */ 	addiu	$t2,$v1,0x1
/*  f12c294:	a60a001c */ 	sh	$t2,0x1c($s0)
.L0f12c298:
/*  f12c298:	1452fffa */ 	bne	$v0,$s2,.L0f12c284
/*  f12c29c:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f12c2a0:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c2a4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f12c2a8:	87ab012e */ 	lh	$t3,0x12e($sp)
/*  f12c2ac:	14c10005 */ 	bne	$a2,$at,.L0f12c2c4
/*  f12c2b0:	24cc0014 */ 	addiu	$t4,$a2,0x14
/*  f12c2b4:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12c2b8:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12c2bc:	50410007 */ 	beql	$v0,$at,.L0f12c2dc
/*  f12c2c0:	24010001 */ 	addiu	$at,$zero,0x1
.L0f12c2c4:
/*  f12c2c4:	556c001a */ 	bnel	$t3,$t4,.L0f12c330
/*  f12c2c8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f12c2cc:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12c2d0:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12c2d4:	10410015 */ 	beq	$v0,$at,.L0f12c32c
/*  f12c2d8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f12c2dc:
/*  f12c2dc:	54410007 */ 	bnel	$v0,$at,.L0f12c2fc
/*  f12c2e0:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f12c2e4:	0c004b70 */ 	jal	random
/*  f12c2e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c2ec:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f12c2f0:	55a0000f */ 	bnezl	$t5,.L0f12c330
/*  f12c2f4:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f12c2f8:	8e220004 */ 	lw	$v0,0x4($s1)
.L0f12c2fc:
/*  f12c2fc:	26e40008 */ 	addiu	$a0,$s7,0x8
/*  f12c300:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f12c304:	10400007 */ 	beqz	$v0,.L0f12c324
/*  f12c308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c30c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f12c310:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f12c314:	0fc4ba08 */ 	jal	func0f12e820
/*  f12c318:	92c60024 */ 	lbu	$a2,0x24($s6)
/*  f12c31c:	10000004 */ 	beqz	$zero,.L0f12c330
/*  f12c320:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f12c324:
/*  f12c324:	0fc4ba08 */ 	jal	func0f12e820
/*  f12c328:	92c60024 */ 	lbu	$a2,0x24($s6)
.L0f12c32c:
/*  f12c32c:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f12c330:
/*  f12c330:	862f03c8 */ 	lh	$t7,0x3c8($s1)
/*  f12c334:	55cf0075 */ 	bnel	$t6,$t7,.L0f12c50c
/*  f12c338:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c33c:	823803cd */ 	lb	$t8,0x3cd($s1)
/*  f12c340:	53000072 */ 	beqzl	$t8,.L0f12c50c
/*  f12c344:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c348:	c6c00010 */ 	lwc1	$f0,0x10($s6)
/*  f12c34c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12c350:	44811000 */ 	mtc1	$at,$f2
/*  f12c354:	46000500 */ 	add.s	$f20,$f0,$f0
/*  f12c358:	00009825 */ 	or	$s3,$zero,$zero
/*  f12c35c:	4614103c */ 	c.lt.s	$f2,$f20
/*  f12c360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c364:	45000002 */ 	bc1f	.L0f12c370
/*  f12c368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c36c:	46001506 */ 	mov.s	$f20,$f2
.L0f12c370:
/*  f12c370:	0c004b70 */ 	jal	random
/*  f12c374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c378:	44829000 */ 	mtc1	$v0,$f18
/*  f12c37c:	3c017f1b */ 	lui	$at,%hi(var7f1b55a4)
/*  f12c380:	c42655a4 */ 	lwc1	$f6,%lo(var7f1b55a4)($at)
/*  f12c384:	04410005 */ 	bgez	$v0,.L0f12c39c
/*  f12c388:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12c38c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c390:	44815000 */ 	mtc1	$at,$f10
/*  f12c394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c398:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c39c:
/*  f12c39c:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f12c3a0:	3c017f1b */ 	lui	$at,%hi(var7f1b55a8)
/*  f12c3a4:	c42a55a8 */ 	lwc1	$f10,%lo(var7f1b55a8)($at)
/*  f12c3a8:	8eb90318 */ 	lw	$t9,0x318($s5)
/*  f12c3ac:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f12c3b0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c3b4:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12c3b8:	53200006 */ 	beqzl	$t9,.L0f12c3d4
/*  f12c3bc:	8ea2029c */ 	lw	$v0,0x29c($s5)
/*  f12c3c0:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f12c3c4:	822403ce */ 	lb	$a0,0x3ce($s1)
/*  f12c3c8:	10000018 */ 	beqz	$zero,.L0f12c42c
/*  f12c3cc:	00401825 */ 	or	$v1,$v0,$zero
/*  f12c3d0:	8ea2029c */ 	lw	$v0,0x29c($s5)
.L0f12c3d4:
/*  f12c3d4:	04420009 */ 	bltzl	$v0,.L0f12c3fc
/*  f12c3d8:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12c3dc:	822803ce */ 	lb	$t0,0x3ce($s1)
/*  f12c3e0:	54480006 */ 	bnel	$v0,$t0,.L0f12c3fc
/*  f12c3e4:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12c3e8:	8ea902a8 */ 	lw	$t1,0x2a8($s5)
/*  f12c3ec:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f12c3f0:	1000000e */ 	beqz	$zero,.L0f12c42c
/*  f12c3f4:	8d430004 */ 	lw	$v1,0x4($t2)
/*  f12c3f8:	8ea20298 */ 	lw	$v0,0x298($s5)
.L0f12c3fc:
/*  f12c3fc:	04420009 */ 	bltzl	$v0,.L0f12c424
/*  f12c400:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
/*  f12c404:	822b03ce */ 	lb	$t3,0x3ce($s1)
/*  f12c408:	544b0006 */ 	bnel	$v0,$t3,.L0f12c424
/*  f12c40c:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
/*  f12c410:	8eac02a4 */ 	lw	$t4,0x2a4($s5)
/*  f12c414:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f12c418:	10000004 */ 	beqz	$zero,.L0f12c42c
/*  f12c41c:	8da30004 */ 	lw	$v1,0x4($t5)
/*  f12c420:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
.L0f12c424:
/*  f12c424:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f12c428:	8de30004 */ 	lw	$v1,0x4($t7)
.L0f12c42c:
/*  f12c42c:	862603ca */ 	lh	$a2,0x3ca($s1)
/*  f12c430:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f12c434:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f12c438:	0006c8c0 */ 	sll	$t9,$a2,0x3
/*  f12c43c:	0326c821 */ 	addu	$t9,$t9,$a2
/*  f12c440:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12c444:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f12c448:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12c44c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f12c450:	8d020014 */ 	lw	$v0,0x14($t0)
/*  f12c454:	262903d0 */ 	addiu	$t1,$s1,0x3d0
/*  f12c458:	262a03dc */ 	addiu	$t2,$s1,0x3dc
/*  f12c45c:	5040002b */ 	beqzl	$v0,.L0f12c50c
/*  f12c460:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c464:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f12c468:	afaa008c */ 	sw	$t2,0x8c($sp)
/*  f12c46c:	8c4b000c */ 	lw	$t3,0xc($v0)
/*  f12c470:	26f00008 */ 	addiu	$s0,$s7,0x8
/*  f12c474:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c478:	11600009 */ 	beqz	$t3,.L0f12c4a0
/*  f12c47c:	01202825 */ 	or	$a1,$t1,$zero
/*  f12c480:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f12c484:	0fc58548 */ 	jal	func0f161520
/*  f12c488:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f12c48c:	10400004 */ 	beqz	$v0,.L0f12c4a0
/*  f12c490:	8fa300e4 */ 	lw	$v1,0xe4($sp)
/*  f12c494:	87b300dc */ 	lh	$s3,0xdc($sp)
/*  f12c498:	3a6c0002 */ 	xori	$t4,$s3,0x2
/*  f12c49c:	2d930001 */ 	sltiu	$s3,$t4,0x1
.L0f12c4a0:
/*  f12c4a0:	240d0007 */ 	addiu	$t5,$zero,0x7
/*  f12c4a4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f12c4a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12c4ac:	862e03ca */ 	lh	$t6,0x3ca($s1)
/*  f12c4b0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f12c4b4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f12c4b8:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f12c4bc:	afb9003c */ 	sw	$t9,0x3c($sp)
/*  f12c4c0:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f12c4c4:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f12c4c8:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f12c4cc:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f12c4d0:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f12c4d4:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f12c4d8:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f12c4dc:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f12c4e0:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f12c4e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f12c4e8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f12c4ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12c4f0:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f12c4f4:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f12c4f8:	02003025 */ 	or	$a2,$s0,$zero
/*  f12c4fc:	00003825 */ 	or	$a3,$zero,$zero
/*  f12c500:	0fc4fd41 */ 	jal	func0f13f504
/*  f12c504:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f12c508:	8fa80098 */ 	lw	$t0,0x98($sp)
.L0f12c50c:
/*  f12c50c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12c510:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c514:	5688ff58 */ 	bnel	$s4,$t0,.L0f12c278
/*  f12c518:	24c90001 */ 	addiu	$t1,$a2,0x1
.L0f12c51c:
/*  f12c51c:	3c014180 */ 	lui	$at,0x4180
/*  f12c520:	44813000 */ 	mtc1	$at,$f6
/*  f12c524:	c6c80020 */ 	lwc1	$f8,0x20($s6)
/*  f12c528:	87ab012e */ 	lh	$t3,0x12e($sp)
/*  f12c52c:	00001025 */ 	or	$v0,$zero,$zero
/*  f12c530:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f12c534:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f12c538:	440a9000 */ 	mfc1	$t2,$f18
/*  f12c53c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c540:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f12c544:	00cc082a */ 	slt	$at,$a2,$t4
/*  f12c548:	1420000a */ 	bnez	$at,.L0f12c574
/*  f12c54c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c550:	822d03cc */ 	lb	$t5,0x3cc($s1)
/*  f12c554:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12c558:	51a10004 */ 	beql	$t5,$at,.L0f12c56c
/*  f12c55c:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f12c560:	0fc10e62 */ 	jal	unregisterDangerousProp
/*  f12c564:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f12c568:	ae200000 */ 	sw	$zero,0x0($s1)
.L0f12c56c:
/*  f12c56c:	10000001 */ 	beqz	$zero,.L0f12c574
/*  f12c570:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12c574:
/*  f12c574:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f12c578:	d7b40050 */ 	ldc1	$f20,0x50($sp)
/*  f12c57c:	d7b60058 */ 	ldc1	$f22,0x58($sp)
/*  f12c580:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f12c584:	8fb10068 */ 	lw	$s1,0x68($sp)
/*  f12c588:	8fb2006c */ 	lw	$s2,0x6c($sp)
/*  f12c58c:	8fb30070 */ 	lw	$s3,0x70($sp)
/*  f12c590:	8fb40074 */ 	lw	$s4,0x74($sp)
/*  f12c594:	8fb50078 */ 	lw	$s5,0x78($sp)
/*  f12c598:	8fb6007c */ 	lw	$s6,0x7c($sp)
/*  f12c59c:	8fb70080 */ 	lw	$s7,0x80($sp)
/*  f12c5a0:	03e00008 */ 	jr	$ra
/*  f12c5a4:	27bd0168 */ 	addiu	$sp,$sp,0x168
);

GLOBAL_ASM(
glabel func0f12c5a8
/*  f12c5a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f12c5ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f12c5b0:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f12c5b4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f12c5b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f12c5bc:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f12c5c0:	c44a0018 */ 	lwc1	$f10,0x18($v0)
/*  f12c5c4:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f12c5c8:	c490000c */ 	lwc1	$f16,0xc($a0)
/*  f12c5cc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12c5d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f12c5d4:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f12c5d8:	44811000 */ 	mtc1	$at,$f2
/*  f12c5dc:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f12c5e0:	c48a0010 */ 	lwc1	$f10,0x10($a0)
/*  f12c5e4:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c5e8:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f12c5ec:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f12c5f0:	c4520038 */ 	lwc1	$f18,0x38($v0)
/*  f12c5f4:	46102200 */ 	add.s	$f8,$f4,$f16
/*  f12c5f8:	46089180 */ 	add.s	$f6,$f18,$f8
/*  f12c5fc:	46003287 */ 	neg.s	$f10,$f6
/*  f12c600:	e48a0014 */ 	swc1	$f10,0x14($a0)
/*  f12c604:	c4800014 */ 	lwc1	$f0,0x14($a0)
/*  f12c608:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12c60c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c610:	45020007 */ 	bc1fl	.L0f12c630
/*  f12c614:	46020481 */ 	sub.s	$f18,$f0,$f2
/*  f12c618:	44812000 */ 	mtc1	$at,$f4
/*  f12c61c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c620:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f12c624:	10000003 */ 	beqz	$zero,.L0f12c634
/*  f12c628:	e4900014 */ 	swc1	$f16,0x14($a0)
/*  f12c62c:	46020481 */ 	sub.s	$f18,$f0,$f2
.L0f12c630:
/*  f12c630:	e4920014 */ 	swc1	$f18,0x14($a0)
.L0f12c634:
/*  f12c634:	908e0001 */ 	lbu	$t6,0x1($a0)
/*  f12c638:	00001025 */ 	or	$v0,$zero,$zero
/*  f12c63c:	35cf0042 */ 	ori	$t7,$t6,0x42
/*  f12c640:	a08f0001 */ 	sb	$t7,0x1($a0)
/*  f12c644:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f12c648:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f12c64c:	03e00008 */ 	jr	$ra
/*  f12c650:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f12c654
/*  f12c654:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f12c658:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f12c65c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f12c660:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f12c664:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f12c668:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f12c66c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f12c670:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f12c674:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f12c678:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f12c67c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f12c680:	00809025 */ 	or	$s2,$a0,$zero
/*  f12c684:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f12c688:	14c00003 */ 	bnez	$a2,.L0f12c698
/*  f12c68c:	8c960004 */ 	lw	$s6,0x4($a0)
/*  f12c690:	100001a8 */ 	beqz	$zero,.L0f12cd34
/*  f12c694:	00a01025 */ 	or	$v0,$a1,$zero
.L0f12c698:
/*  f12c698:	86500028 */ 	lh	$s0,0x28($s2)
/*  f12c69c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f12c6a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f12c6a4:	12050016 */ 	beq	$s0,$a1,.L0f12c700
/*  f12c6a8:	3c03800a */ 	lui	$v1,%hi(g_RoomPtrs)
/*  f12c6ac:	8c634928 */ 	lw	$v1,%lo(g_RoomPtrs)($v1)
/*  f12c6b0:	2404008c */ 	addiu	$a0,$zero,0x8c
.L0f12c6b4:
/*  f12c6b4:	02040019 */ 	multu	$s0,$a0
/*  f12c6b8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f12c6bc:	00065040 */ 	sll	$t2,$a2,0x1
/*  f12c6c0:	024a5821 */ 	addu	$t3,$s2,$t2
/*  f12c6c4:	00007012 */ 	mflo	$t6
/*  f12c6c8:	006e1021 */ 	addu	$v0,$v1,$t6
/*  f12c6cc:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f12c6d0:	51e00009 */ 	beqzl	$t7,.L0f12c6f8
/*  f12c6d4:	85700028 */ 	lh	$s0,0x28($t3)
/*  f12c6d8:	84580002 */ 	lh	$t8,0x2($v0)
/*  f12c6dc:	53000006 */ 	beqzl	$t8,.L0f12c6f8
/*  f12c6e0:	85700028 */ 	lh	$s0,0x28($t3)
/*  f12c6e4:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f12c6e8:	33290004 */ 	andi	$t1,$t9,0x4
/*  f12c6ec:	15200004 */ 	bnez	$t1,.L0f12c700
/*  f12c6f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c6f4:	85700028 */ 	lh	$s0,0x28($t3)
.L0f12c6f8:
/*  f12c6f8:	1605ffee */ 	bne	$s0,$a1,.L0f12c6b4
/*  f12c6fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12c700:
/*  f12c700:	5205018c */ 	beql	$s0,$a1,.L0f12cd34
/*  f12c704:	02a01025 */ 	or	$v0,$s5,$zero
/*  f12c708:	0fc59b74 */ 	jal	func0f166dd0
/*  f12c70c:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c710:	0040f025 */ 	or	$s8,$v0,$zero
/*  f12c714:	26440028 */ 	addiu	$a0,$s2,0x28
/*  f12c718:	0fc2396a */ 	jal	func0f08e5a8
/*  f12c71c:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f12c720:	18400009 */ 	blez	$v0,.L0f12c748
/*  f12c724:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12c728:	87ac00ae */ 	lh	$t4,0xae($sp)
/*  f12c72c:	87a500a8 */ 	lh	$a1,0xa8($sp)
/*  f12c730:	87a600aa */ 	lh	$a2,0xaa($sp)
/*  f12c734:	87a700ac */ 	lh	$a3,0xac($sp)
/*  f12c738:	0fc57306 */ 	jal	func0f15cc18
/*  f12c73c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f12c740:	10000004 */ 	beqz	$zero,.L0f12c754
/*  f12c744:	0040a825 */ 	or	$s5,$v0,$zero
.L0f12c748:
/*  f12c748:	0fc572dd */ 	jal	func0f15cb74
/*  f12c74c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12c750:	0040a825 */ 	or	$s5,$v0,$zero
.L0f12c754:
/*  f12c754:	02a01025 */ 	or	$v0,$s5,$zero
/*  f12c758:	3c0e0001 */ 	lui	$t6,0x1
/*  f12c75c:	35ce3000 */ 	ori	$t6,$t6,0x3000
/*  f12c760:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12c764:	3c0db600 */ 	lui	$t5,0xb600
/*  f12c768:	3c0f0103 */ 	lui	$t7,0x103
/*  f12c76c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f12c770:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f12c774:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f12c778:	02a08825 */ 	or	$s1,$s5,$zero
/*  f12c77c:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f12c780:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f12c784:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12c788:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12c78c:	00402025 */ 	or	$a0,$v0,$zero
/*  f12c790:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f12c794:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12c798:	0fc59b5f */ 	jal	func0f166d7c
/*  f12c79c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12c7a0:	3c180600 */ 	lui	$t8,0x600
/*  f12c7a4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f12c7a8:	3c19800b */ 	lui	$t9,%hi(var800ab568)
/*  f12c7ac:	8f39b568 */ 	lw	$t9,%lo(var800ab568)($t9)
/*  f12c7b0:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f12c7b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f12c7b8:	0fc59e73 */ 	jal	func0f1679cc
/*  f12c7bc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f12c7c0:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f12c7c4:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f12c7c8:	8e640284 */ 	lw	$a0,0x284($s3)
/*  f12c7cc:	00408825 */ 	or	$s1,$v0,$zero
/*  f12c7d0:	3c098007 */ 	lui	$t1,%hi(var80070764)
/*  f12c7d4:	8c8500d8 */ 	lw	$a1,0xd8($a0)
/*  f12c7d8:	14a00013 */ 	bnez	$a1,.L0f12c828
/*  f12c7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c7e0:	8d290764 */ 	lw	$t1,%lo(var80070764)($t1)
/*  f12c7e4:	15200010 */ 	bnez	$t1,.L0f12c828
/*  f12c7e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c7ec:	8c830480 */ 	lw	$v1,0x480($a0)
/*  f12c7f0:	50600007 */ 	beqzl	$v1,.L0f12c810
/*  f12c7f4:	8c8c1c54 */ 	lw	$t4,0x1c54($a0)
/*  f12c7f8:	1060000b */ 	beqz	$v1,.L0f12c828
/*  f12c7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c800:	806a0037 */ 	lb	$t2,0x37($v1)
/*  f12c804:	15400008 */ 	bnez	$t2,.L0f12c828
/*  f12c808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c80c:	8c8c1c54 */ 	lw	$t4,0x1c54($a0)
.L0f12c810:
/*  f12c810:	8c8b00c4 */ 	lw	$t3,0xc4($a0)
/*  f12c814:	01806827 */ 	nor	$t5,$t4,$zero
/*  f12c818:	016d7024 */ 	and	$t6,$t3,$t5
/*  f12c81c:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f12c820:	55e00015 */ 	bnezl	$t7,.L0f12c878
/*  f12c824:	240effff */ 	addiu	$t6,$zero,-1
.L0f12c828:
/*  f12c828:	14a00015 */ 	bnez	$a1,.L0f12c880
/*  f12c82c:	3c188007 */ 	lui	$t8,%hi(var80070764)
/*  f12c830:	8f180764 */ 	lw	$t8,%lo(var80070764)($t8)
/*  f12c834:	57000013 */ 	bnezl	$t8,.L0f12c884
/*  f12c838:	948f0010 */ 	lhu	$t7,0x10($a0)
/*  f12c83c:	8c830480 */ 	lw	$v1,0x480($a0)
/*  f12c840:	50600007 */ 	beqzl	$v1,.L0f12c860
/*  f12c844:	8c8a1c54 */ 	lw	$t2,0x1c54($a0)
/*  f12c848:	5060000e */ 	beqzl	$v1,.L0f12c884
/*  f12c84c:	948f0010 */ 	lhu	$t7,0x10($a0)
/*  f12c850:	80790037 */ 	lb	$t9,0x37($v1)
/*  f12c854:	5720000b */ 	bnezl	$t9,.L0f12c884
/*  f12c858:	948f0010 */ 	lhu	$t7,0x10($a0)
/*  f12c85c:	8c8a1c54 */ 	lw	$t2,0x1c54($a0)
.L0f12c860:
/*  f12c860:	8c8900c4 */ 	lw	$t1,0xc4($a0)
/*  f12c864:	01406027 */ 	nor	$t4,$t2,$zero
/*  f12c868:	012c5824 */ 	and	$t3,$t1,$t4
/*  f12c86c:	316d0008 */ 	andi	$t5,$t3,0x8
/*  f12c870:	11a00003 */ 	beqz	$t5,.L0f12c880
/*  f12c874:	240effff */ 	addiu	$t6,$zero,-1
.L0f12c878:
/*  f12c878:	100000b1 */ 	beqz	$zero,.L0f12cb40
/*  f12c87c:	ac4e0000 */ 	sw	$t6,0x0($v0)
.L0f12c880:
/*  f12c880:	948f0010 */ 	lhu	$t7,0x10($a0)
.L0f12c884:
/*  f12c884:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12c888:	3c058008 */ 	lui	$a1,%hi(var8007e93c)
/*  f12c88c:	15e100a4 */ 	bne	$t7,$at,.L0f12cb20
/*  f12c890:	24a5e93c */ 	addiu	$a1,$a1,%lo(var8007e93c)
/*  f12c894:	c6440010 */ 	lwc1	$f4,0x10($s2)
/*  f12c898:	c4860020 */ 	lwc1	$f6,0x20($a0)
/*  f12c89c:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*  f12c8a0:	c48a0018 */ 	lwc1	$f10,0x18($a0)
/*  f12c8a4:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f12c8a8:	c484001c */ 	lwc1	$f4,0x1c($a0)
/*  f12c8ac:	c652000c */ 	lwc1	$f18,0xc($s2)
/*  f12c8b0:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f12c8b4:	24100080 */ 	addiu	$s0,$zero,0x80
/*  f12c8b8:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f12c8bc:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f12c8c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c8c4:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f12c8c8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12c8cc:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f12c8d0:	0c012974 */ 	jal	sqrtf
/*  f12c8d4:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f12c8d8:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f12c8dc:	3c014316 */ 	lui	$at,0x4316
/*  f12c8e0:	c70c0024 */ 	lwc1	$f12,0x24($t8)
/*  f12c8e4:	4600603c */ 	c.lt.s	$f12,$f0
/*  f12c8e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c8ec:	45020004 */ 	bc1fl	.L0f12c900
/*  f12c8f0:	44818000 */ 	mtc1	$at,$f16
/*  f12c8f4:	1000010f */ 	beqz	$zero,.L0f12cd34
/*  f12c8f8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f12c8fc:	44818000 */ 	mtc1	$at,$f16
.L0f12c900:
/*  f12c900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c904:	46106081 */ 	sub.s	$f2,$f12,$f16
/*  f12c908:	4600103c */ 	c.lt.s	$f2,$f0
/*  f12c90c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c910:	4502002d */ 	bc1fl	.L0f12c9c8
/*  f12c914:	460c0083 */ 	div.s	$f2,$f0,$f12
/*  f12c918:	46020101 */ 	sub.s	$f4,$f0,$f2
/*  f12c91c:	3c013f80 */ 	lui	$at,0x3f80
/*  f12c920:	44817000 */ 	mtc1	$at,$f14
/*  f12c924:	3c014300 */ 	lui	$at,0x4300
/*  f12c928:	46102183 */ 	div.s	$f6,$f4,$f16
/*  f12c92c:	44819000 */ 	mtc1	$at,$f18
/*  f12c930:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f12c934:	3c014f00 */ 	lui	$at,0x4f00
/*  f12c938:	46067201 */ 	sub.s	$f8,$f14,$f6
/*  f12c93c:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f12c940:	4459f800 */ 	cfc1	$t9,$31
/*  f12c944:	44d0f800 */ 	ctc1	$s0,$31
/*  f12c948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c94c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f12c950:	4450f800 */ 	cfc1	$s0,$31
/*  f12c954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c958:	32100078 */ 	andi	$s0,$s0,0x78
/*  f12c95c:	52000013 */ 	beqzl	$s0,.L0f12c9ac
/*  f12c960:	44102000 */ 	mfc1	$s0,$f4
/*  f12c964:	44812000 */ 	mtc1	$at,$f4
/*  f12c968:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f12c96c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f12c970:	44d0f800 */ 	ctc1	$s0,$31
/*  f12c974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c978:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f12c97c:	4450f800 */ 	cfc1	$s0,$31
/*  f12c980:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c984:	32100078 */ 	andi	$s0,$s0,0x78
/*  f12c988:	16000005 */ 	bnez	$s0,.L0f12c9a0
/*  f12c98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c990:	44102000 */ 	mfc1	$s0,$f4
/*  f12c994:	3c018000 */ 	lui	$at,0x8000
/*  f12c998:	10000007 */ 	beqz	$zero,.L0f12c9b8
/*  f12c99c:	02018025 */ 	or	$s0,$s0,$at
.L0f12c9a0:
/*  f12c9a0:	10000005 */ 	beqz	$zero,.L0f12c9b8
/*  f12c9a4:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f12c9a8:	44102000 */ 	mfc1	$s0,$f4
.L0f12c9ac:
/*  f12c9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c9b0:	0600fffb */ 	bltz	$s0,.L0f12c9a0
/*  f12c9b4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12c9b8:
/*  f12c9b8:	44d9f800 */ 	ctc1	$t9,$31
/*  f12c9bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c9c4:	460c0083 */ 	div.s	$f2,$f0,$f12
.L0f12c9c8:
/*  f12c9c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f12c9cc:	44817000 */ 	mtc1	$at,$f14
/*  f12c9d0:	3c0142fe */ 	lui	$at,0x42fe
/*  f12c9d4:	44810000 */ 	mtc1	$at,$f0
/*  f12c9d8:	3c014f00 */ 	lui	$at,0x4f00
/*  f12c9dc:	4602703c */ 	c.lt.s	$f14,$f2
/*  f12c9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c9e4:	45000002 */ 	bc1f	.L0f12c9f0
/*  f12c9e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12c9ec:	46007086 */ 	mov.s	$f2,$f14
.L0f12c9f0:
/*  f12c9f0:	46001182 */ 	mul.s	$f6,$f2,$f0
/*  f12c9f4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f12c9f8:	444af800 */ 	cfc1	$t2,$31
/*  f12c9fc:	44c9f800 */ 	ctc1	$t1,$31
/*  f12ca00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca04:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f12ca08:	4449f800 */ 	cfc1	$t1,$31
/*  f12ca0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca10:	31290078 */ 	andi	$t1,$t1,0x78
/*  f12ca14:	51200013 */ 	beqzl	$t1,.L0f12ca64
/*  f12ca18:	44094000 */ 	mfc1	$t1,$f8
/*  f12ca1c:	44814000 */ 	mtc1	$at,$f8
/*  f12ca20:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f12ca24:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f12ca28:	44c9f800 */ 	ctc1	$t1,$31
/*  f12ca2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca30:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f12ca34:	4449f800 */ 	cfc1	$t1,$31
/*  f12ca38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca3c:	31290078 */ 	andi	$t1,$t1,0x78
/*  f12ca40:	15200005 */ 	bnez	$t1,.L0f12ca58
/*  f12ca44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca48:	44094000 */ 	mfc1	$t1,$f8
/*  f12ca4c:	3c018000 */ 	lui	$at,0x8000
/*  f12ca50:	10000007 */ 	beqz	$zero,.L0f12ca70
/*  f12ca54:	01214825 */ 	or	$t1,$t1,$at
.L0f12ca58:
/*  f12ca58:	10000005 */ 	beqz	$zero,.L0f12ca70
/*  f12ca5c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f12ca60:	44094000 */ 	mfc1	$t1,$f8
.L0f12ca64:
/*  f12ca64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca68:	0520fffb */ 	bltz	$t1,.L0f12ca58
/*  f12ca6c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12ca70:
/*  f12ca70:	44caf800 */ 	ctc1	$t2,$31
/*  f12ca74:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f12ca78:	00096600 */ 	sll	$t4,$t1,0x18
/*  f12ca7c:	46027481 */ 	sub.s	$f18,$f14,$f2
/*  f12ca80:	3c014f00 */ 	lui	$at,0x4f00
/*  f12ca84:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f12ca88:	444bf800 */ 	cfc1	$t3,$31
/*  f12ca8c:	44cdf800 */ 	ctc1	$t5,$31
/*  f12ca90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ca94:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f12ca98:	444df800 */ 	cfc1	$t5,$31
/*  f12ca9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12caa0:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f12caa4:	51a00013 */ 	beqzl	$t5,.L0f12caf4
/*  f12caa8:	440d2000 */ 	mfc1	$t5,$f4
/*  f12caac:	44812000 */ 	mtc1	$at,$f4
/*  f12cab0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f12cab4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f12cab8:	44cdf800 */ 	ctc1	$t5,$31
/*  f12cabc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cac0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f12cac4:	444df800 */ 	cfc1	$t5,$31
/*  f12cac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cacc:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f12cad0:	15a00005 */ 	bnez	$t5,.L0f12cae8
/*  f12cad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cad8:	440d2000 */ 	mfc1	$t5,$f4
/*  f12cadc:	3c018000 */ 	lui	$at,0x8000
/*  f12cae0:	10000007 */ 	beqz	$zero,.L0f12cb00
/*  f12cae4:	01a16825 */ 	or	$t5,$t5,$at
.L0f12cae8:
/*  f12cae8:	10000005 */ 	beqz	$zero,.L0f12cb00
/*  f12caec:	240dffff */ 	addiu	$t5,$zero,-1
/*  f12caf0:	440d2000 */ 	mfc1	$t5,$f4
.L0f12caf4:
/*  f12caf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12caf8:	05a0fffb */ 	bltz	$t5,.L0f12cae8
/*  f12cafc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12cb00:
/*  f12cb00:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f12cb04:	018e7825 */ 	or	$t7,$t4,$t6
/*  f12cb08:	01f0c025 */ 	or	$t8,$t7,$s0
/*  f12cb0c:	3c018080 */ 	lui	$at,0x8080
/*  f12cb10:	0301c825 */ 	or	$t9,$t8,$at
/*  f12cb14:	44cbf800 */ 	ctc1	$t3,$31
/*  f12cb18:	10000009 */ 	beqz	$zero,.L0f12cb40
/*  f12cb1c:	ae390000 */ 	sw	$t9,0x0($s1)
.L0f12cb20:
/*  f12cb20:	3c047f1b */ 	lui	$a0,%hi(var7f1b5570)
/*  f12cb24:	0c0036cc */ 	jal	func0000db30
/*  f12cb28:	24845570 */ 	addiu	$a0,$a0,%lo(var7f1b5570)
/*  f12cb2c:	240affff */ 	addiu	$t2,$zero,-1
/*  f12cb30:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f12cb34:	3c098008 */ 	lui	$t1,%hi(var8007e93c)
/*  f12cb38:	8d29e93c */ 	lw	$t1,%lo(var8007e93c)($t1)
/*  f12cb3c:	ae290000 */ 	sw	$t1,0x0($s1)
.L0f12cb40:
/*  f12cb40:	3c0b0700 */ 	lui	$t3,0x700
/*  f12cb44:	356b0004 */ 	ori	$t3,$t3,0x4
/*  f12cb48:	02a08025 */ 	or	$s0,$s5,$zero
/*  f12cb4c:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f12cb50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cb54:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12cb58:	02202025 */ 	or	$a0,$s1,$zero
/*  f12cb5c:	3c138008 */ 	lui	$s3,%hi(g_ExplosionTypes)
/*  f12cb60:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f12cb64:	2673e4b8 */ 	addiu	$s3,$s3,%lo(g_ExplosionTypes)
/*  f12cb68:	2412000e */ 	addiu	$s2,$zero,0xe
/*  f12cb6c:	24170070 */ 	addiu	$s7,$zero,0x70
/*  f12cb70:	2414002c */ 	addiu	$s4,$zero,0x2c
.L0f12cb74:
/*  f12cb74:	3c08800b */ 	lui	$t0,%hi(var800ab570)
/*  f12cb78:	02a01025 */ 	or	$v0,$s5,$zero
/*  f12cb7c:	3c0dfd70 */ 	lui	$t5,0xfd70
/*  f12cb80:	2508b570 */ 	addiu	$t0,$t0,%lo(var800ab570)
/*  f12cb84:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f12cb88:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*  f12cb8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cb90:	02a01825 */ 	or	$v1,$s5,$zero
/*  f12cb94:	01977021 */ 	addu	$t6,$t4,$s7
/*  f12cb98:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f12cb9c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cba0:	3c18e600 */ 	lui	$t8,0xe600
/*  f12cba4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f12cba8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12cbac:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f12cbb0:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f12cbb4:	3c0a0761 */ 	lui	$t2,0x761
/*  f12cbb8:	354af000 */ 	ori	$t2,$t2,0xf000
/*  f12cbbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cbc0:	3c19f300 */ 	lui	$t9,0xf300
/*  f12cbc4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f12cbc8:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f12cbcc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f12cbd0:	3c09fd10 */ 	lui	$t1,0xfd10
/*  f12cbd4:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f12cbd8:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f12cbdc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cbe0:	02a03825 */ 	or	$a3,$s5,$zero
/*  f12cbe4:	01776821 */ 	addu	$t5,$t3,$s7
/*  f12cbe8:	8dac0004 */ 	lw	$t4,0x4($t5)
/*  f12cbec:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cbf0:	3c0ee600 */ 	lui	$t6,0xe600
/*  f12cbf4:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f12cbf8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f12cbfc:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f12cc00:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f12cc04:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cc08:	3c18050d */ 	lui	$t8,0x50d
/*  f12cc0c:	3718f000 */ 	ori	$t8,$t8,0xf000
/*  f12cc10:	3c0ff300 */ 	lui	$t7,0xf300
/*  f12cc14:	02a01825 */ 	or	$v1,$s5,$zero
/*  f12cc18:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f12cc1c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f12cc20:	3c19e700 */ 	lui	$t9,0xe700
/*  f12cc24:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f12cc28:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f12cc2c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cc30:	00008825 */ 	or	$s1,$zero,$zero
/*  f12cc34:	02c08025 */ 	or	$s0,$s6,$zero
.L0f12cc38:
/*  f12cc38:	8602001c */ 	lh	$v0,0x1c($s0)
/*  f12cc3c:	58400017 */ 	blezl	$v0,.L0f12cc9c
/*  f12cc40:	26310018 */ 	addiu	$s1,$s1,0x18
/*  f12cc44:	82c903cc */ 	lb	$t1,0x3cc($s6)
/*  f12cc48:	244affff */ 	addiu	$t2,$v0,-1
/*  f12cc4c:	448a3000 */ 	mtc1	$t2,$f6
/*  f12cc50:	01340019 */ 	multu	$t1,$s4
/*  f12cc54:	02c02025 */ 	or	$a0,$s6,$zero
/*  f12cc58:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f12cc5c:	26050008 */ 	addiu	$a1,$s0,0x8
/*  f12cc60:	02a03025 */ 	or	$a2,$s5,$zero
/*  f12cc64:	03c03825 */ 	or	$a3,$s8,$zero
/*  f12cc68:	00005812 */ 	mflo	$t3
/*  f12cc6c:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f12cc70:	c5b20020 */ 	lwc1	$f18,0x20($t5)
/*  f12cc74:	46124283 */ 	div.s	$f10,$f8,$f18
/*  f12cc78:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12cc7c:	440e2000 */ 	mfc1	$t6,$f4
/*  f12cc80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cc84:	564e0005 */ 	bnel	$s2,$t6,.L0f12cc9c
/*  f12cc88:	26310018 */ 	addiu	$s1,$s1,0x18
/*  f12cc8c:	0fc4b359 */ 	jal	func0f12cd64
/*  f12cc90:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f12cc94:	0040a825 */ 	or	$s5,$v0,$zero
/*  f12cc98:	26310018 */ 	addiu	$s1,$s1,0x18
.L0f12cc9c:
/*  f12cc9c:	2a2103c0 */ 	slti	$at,$s1,0x3c0
/*  f12cca0:	1420ffe5 */ 	bnez	$at,.L0f12cc38
/*  f12cca4:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f12cca8:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f12ccac:	0641ffb1 */ 	bgez	$s2,.L0f12cb74
/*  f12ccb0:	26f7fff8 */ 	addiu	$s7,$s7,-8
/*  f12ccb4:	3c0f0103 */ 	lui	$t7,0x103
/*  f12ccb8:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f12ccbc:	02a09025 */ 	or	$s2,$s5,$zero
/*  f12ccc0:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f12ccc4:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f12ccc8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f12cccc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12ccd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f12ccd4:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f12ccd8:	82d803cc */ 	lb	$t8,0x3cc($s6)
/*  f12ccdc:	3c014170 */ 	lui	$at,0x4170
/*  f12cce0:	44814000 */ 	mtc1	$at,$f8
/*  f12cce4:	03140019 */ 	multu	$t8,$s4
/*  f12cce8:	240203c0 */ 	addiu	$v0,$zero,0x3c0
/*  f12ccec:	00008825 */ 	or	$s1,$zero,$zero
/*  f12ccf0:	02c08025 */ 	or	$s0,$s6,$zero
/*  f12ccf4:	0000c812 */ 	mflo	$t9
/*  f12ccf8:	02795021 */ 	addu	$t2,$s3,$t9
/*  f12ccfc:	c5460020 */ 	lwc1	$f6,0x20($t2)
/*  f12cd00:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f12cd04:	4600928d */ 	trunc.w.s	$f10,$f18
/*  f12cd08:	44035000 */ 	mfc1	$v1,$f10
/*  f12cd0c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12cd10:
/*  f12cd10:	860b001c */ 	lh	$t3,0x1c($s0)
/*  f12cd14:	26310018 */ 	addiu	$s1,$s1,0x18
/*  f12cd18:	006b082a */ 	slt	$at,$v1,$t3
/*  f12cd1c:	10200002 */ 	beqz	$at,.L0f12cd28
/*  f12cd20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cd24:	a600001c */ 	sh	$zero,0x1c($s0)
.L0f12cd28:
/*  f12cd28:	1622fff9 */ 	bne	$s1,$v0,.L0f12cd10
/*  f12cd2c:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f12cd30:	02a01025 */ 	or	$v0,$s5,$zero
.L0f12cd34:
/*  f12cd34:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f12cd38:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f12cd3c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f12cd40:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f12cd44:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f12cd48:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f12cd4c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f12cd50:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f12cd54:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f12cd58:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f12cd5c:	03e00008 */ 	jr	$ra
/*  f12cd60:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel func0f12cd64
.late_rodata
glabel var7f1b55ac
.word 0x3f333333
glabel var7f1b55b0
.word 0x3f266666
glabel var7f1b55b4
.word 0x3f4ccccd
glabel var7f1b55b8
.word 0x3f16db6e
glabel var7f1b55bc
.word 0x3f324925
glabel var7f1b55c0
.word 0x3f524925
glabel var7f1b55c4
.word 0x3f76db6e
.text
/*  f12cd64:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f12cd68:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f12cd6c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f12cd70:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f12cd74:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12cd78:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f12cd7c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f12cd80:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f12cd84:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f12cd88:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f12cd8c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f12cd90:	0fc59e59 */ 	jal	func0f167964
/*  f12cd94:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f12cd98:	0fc2d5de */ 	jal	func0f0b5778
/*  f12cd9c:	00408025 */ 	or	$s0,$v0,$zero
/*  f12cda0:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f12cda4:	00405825 */ 	or	$t3,$v0,$zero
/*  f12cda8:	c636000c */ 	lwc1	$f22,0xc($s1)
/*  f12cdac:	914e03cf */ 	lbu	$t6,0x3cf($t2)
/*  f12cdb0:	c62e0000 */ 	lwc1	$f14,0x0($s1)
/*  f12cdb4:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f12cdb8:	19c000b4 */ 	blez	$t6,.L0f12d08c
/*  f12cdbc:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f12cdc0:	e7ae0068 */ 	swc1	$f14,0x68($sp)
/*  f12cdc4:	e7b0006c */ 	swc1	$f16,0x6c($sp)
/*  f12cdc8:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f12cdcc:	914803cf */ 	lbu	$t0,0x3cf($t2)
/*  f12cdd0:	4480c000 */ 	mtc1	$zero,$f24
/*  f12cdd4:	92290016 */ 	lbu	$t1,0x16($s1)
/*  f12cdd8:	00003825 */ 	or	$a3,$zero,$zero
/*  f12cddc:	19000043 */ 	blez	$t0,.L0f12ceec
/*  f12cde0:	4600c506 */ 	mov.s	$f20,$f24
/*  f12cde4:	01403025 */ 	or	$a2,$t2,$zero
/*  f12cde8:	27a50074 */ 	addiu	$a1,$sp,0x74
.L0f12cdec:
/*  f12cdec:	c4c403e8 */ 	lwc1	$f4,0x3e8($a2)
/*  f12cdf0:	460e203e */ 	c.le.s	$f4,$f14
/*  f12cdf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cdf8:	45020039 */ 	bc1fl	.L0f12cee0
/*  f12cdfc:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce00:	c4c603f4 */ 	lwc1	$f6,0x3f4($a2)
/*  f12ce04:	4606703e */ 	c.le.s	$f14,$f6
/*  f12ce08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ce0c:	45020034 */ 	bc1fl	.L0f12cee0
/*  f12ce10:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce14:	c4c803ec */ 	lwc1	$f8,0x3ec($a2)
/*  f12ce18:	4610403e */ 	c.le.s	$f8,$f16
/*  f12ce1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ce20:	4502002f */ 	bc1fl	.L0f12cee0
/*  f12ce24:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce28:	c4ca03f8 */ 	lwc1	$f10,0x3f8($a2)
/*  f12ce2c:	460a803e */ 	c.le.s	$f16,$f10
/*  f12ce30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ce34:	4502002a */ 	bc1fl	.L0f12cee0
/*  f12ce38:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce3c:	c4c403f0 */ 	lwc1	$f4,0x3f0($a2)
/*  f12ce40:	4612203e */ 	c.le.s	$f4,$f18
/*  f12ce44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ce48:	45020025 */ 	bc1fl	.L0f12cee0
/*  f12ce4c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce50:	c4c603fc */ 	lwc1	$f6,0x3fc($a2)
/*  f12ce54:	000778c0 */ 	sll	$t7,$a3,0x3
/*  f12ce58:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f12ce5c:	4606903e */ 	c.le.s	$f18,$f6
/*  f12ce60:	3c014780 */ 	lui	$at,0x4780
/*  f12ce64:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12ce68:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f12ce6c:	4502001c */ 	bc1fl	.L0f12cee0
/*  f12ce70:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce74:	44816000 */ 	mtc1	$at,$f12
/*  f12ce78:	014f1821 */ 	addu	$v1,$t2,$t7
.L0f12ce7c:
/*  f12ce7c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12ce80:	c46803e8 */ 	lwc1	$f8,0x3e8($v1)
/*  f12ce84:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12ce88:	46081001 */ 	sub.s	$f0,$f2,$f8
/*  f12ce8c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ce90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ce94:	45020003 */ 	bc1fl	.L0f12cea4
/*  f12ce98:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
/*  f12ce9c:	46000306 */ 	mov.s	$f12,$f0
/*  f12cea0:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
.L0f12cea4:
/*  f12cea4:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12cea8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ceac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ceb0:	45000002 */ 	bc1f	.L0f12cebc
/*  f12ceb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12ceb8:	46000306 */ 	mov.s	$f12,$f0
.L0f12cebc:
/*  f12cebc:	1445ffef */ 	bne	$v0,$a1,.L0f12ce7c
/*  f12cec0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cec4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f12cec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cecc:	45020004 */ 	bc1fl	.L0f12cee0
/*  f12ced0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ced4:	46006506 */ 	mov.s	$f20,$f12
/*  f12ced8:	00e04825 */ 	or	$t1,$a3,$zero
/*  f12cedc:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f12cee0:
/*  f12cee0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12cee4:	1420ffc1 */ 	bnez	$at,.L0f12cdec
/*  f12cee8:	24c6001c */ 	addiu	$a2,$a2,0x1c
.L0f12ceec:
/*  f12ceec:	3c017f1b */ 	lui	$at,%hi(var7f1b55ac)
/*  f12cef0:	c42c55ac */ 	lwc1	$f12,%lo(var7f1b55ac)($at)
/*  f12cef4:	0009c0c0 */ 	sll	$t8,$t1,0x3
/*  f12cef8:	0309c023 */ 	subu	$t8,$t8,$t1
/*  f12cefc:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf00:	3c017f1b */ 	lui	$at,%hi(var7f1b55b0)
/*  f12cf04:	c43255b0 */ 	lwc1	$f18,%lo(var7f1b55b0)($at)
/*  f12cf08:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12cf0c:	01582021 */ 	addu	$a0,$t2,$t8
/*  f12cf10:	3c017f1b */ 	lui	$at,%hi(var7f1b55b4)
/*  f12cf14:	c42e55b4 */ 	lwc1	$f14,%lo(var7f1b55b4)($at)
/*  f12cf18:	46001406 */ 	mov.s	$f16,$f2
/*  f12cf1c:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf20:	00001025 */ 	or	$v0,$zero,$zero
.L0f12cf24:
/*  f12cf24:	c46403f4 */ 	lwc1	$f4,0x3f4($v1)
/*  f12cf28:	c46603e8 */ 	lwc1	$f6,0x3e8($v1)
/*  f12cf2c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12cf30:	2841000c */ 	slti	$at,$v0,0xc
/*  f12cf34:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12cf38:	460e4002 */ 	mul.s	$f0,$f8,$f14
/*  f12cf3c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12cf40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cf44:	4500000b */ 	bc1f	.L0f12cf74
/*  f12cf48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cf4c:	460c0583 */ 	div.s	$f22,$f0,$f12
/*  f12cf50:	c62a000c */ 	lwc1	$f10,0xc($s1)
/*  f12cf54:	46125082 */ 	mul.s	$f2,$f10,$f18
/*  f12cf58:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f12cf5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cf60:	45000002 */ 	bc1f	.L0f12cf6c
/*  f12cf64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12cf68:	46001586 */ 	mov.s	$f22,$f2
.L0f12cf6c:
/*  f12cf6c:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf70:	46001406 */ 	mov.s	$f16,$f2
.L0f12cf74:
/*  f12cf74:	1420ffeb */ 	bnez	$at,.L0f12cf24
/*  f12cf78:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cf7c:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f12cf80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12cf84:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf88:	14410006 */ 	bne	$v0,$at,.L0f12cfa4
/*  f12cf8c:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f12cf90:	3c017f1b */ 	lui	$at,%hi(var7f1b55b8)
/*  f12cf94:	c42455b8 */ 	lwc1	$f4,%lo(var7f1b55b8)($at)
/*  f12cf98:	46041402 */ 	mul.s	$f16,$f2,$f4
/*  f12cf9c:	10000016 */ 	beqz	$zero,.L0f12cff8
/*  f12cfa0:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfa4:
/*  f12cfa4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12cfa8:	14410005 */ 	bne	$v0,$at,.L0f12cfc0
/*  f12cfac:	3c017f1b */ 	lui	$at,%hi(var7f1b55bc)
/*  f12cfb0:	c42655bc */ 	lwc1	$f6,%lo(var7f1b55bc)($at)
/*  f12cfb4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f12cfb8:	1000000f */ 	beqz	$zero,.L0f12cff8
/*  f12cfbc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfc0:
/*  f12cfc0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12cfc4:	14410006 */ 	bne	$v0,$at,.L0f12cfe0
/*  f12cfc8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12cfcc:	3c017f1b */ 	lui	$at,%hi(var7f1b55c0)
/*  f12cfd0:	c42855c0 */ 	lwc1	$f8,%lo(var7f1b55c0)($at)
/*  f12cfd4:	46081402 */ 	mul.s	$f16,$f2,$f8
/*  f12cfd8:	10000007 */ 	beqz	$zero,.L0f12cff8
/*  f12cfdc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfe0:
/*  f12cfe0:	14450004 */ 	bne	$v0,$a1,.L0f12cff4
/*  f12cfe4:	3c017f1b */ 	lui	$at,%hi(var7f1b55c4)
/*  f12cfe8:	c42a55c4 */ 	lwc1	$f10,%lo(var7f1b55c4)($at)
/*  f12cfec:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f12cff0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f12cff4:
/*  f12cff4:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cff8:
/*  f12cff8:	44819000 */ 	mtc1	$at,$f18
/*  f12cffc:	27a20068 */ 	addiu	$v0,$sp,0x68
.L0f12d000:
/*  f12d000:	c46c03f4 */ 	lwc1	$f12,0x3f4($v1)
/*  f12d004:	c46e03e8 */ 	lwc1	$f14,0x3e8($v1)
/*  f12d008:	460e6101 */ 	sub.s	$f4,$f12,$f14
/*  f12d00c:	4610203c */ 	c.lt.s	$f4,$f16
/*  f12d010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d014:	45020006 */ 	bc1fl	.L0f12d030
/*  f12d018:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f12d01c:	460c7180 */ 	add.s	$f6,$f14,$f12
/*  f12d020:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f12d024:	10000013 */ 	beqz	$zero,.L0f12d074
/*  f12d028:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f12d02c:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f12d030:
/*  f12d030:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12d034:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12d038:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d040:	45020005 */ 	bc1fl	.L0f12d058
/*  f12d044:	46106181 */ 	sub.s	$f6,$f12,$f16
/*  f12d048:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f12d04c:	10000009 */ 	beqz	$zero,.L0f12d074
/*  f12d050:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f12d054:	46106181 */ 	sub.s	$f6,$f12,$f16
.L0f12d058:
/*  f12d058:	46061001 */ 	sub.s	$f0,$f2,$f6
/*  f12d05c:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d064:	45020004 */ 	bc1fl	.L0f12d078
/*  f12d068:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12d06c:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f12d070:	e4480000 */ 	swc1	$f8,0x0($v0)
.L0f12d074:
/*  f12d074:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f12d078:
/*  f12d078:	1444ffe1 */ 	bne	$v0,$a0,.L0f12d000
/*  f12d07c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12d080:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f12d084:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f12d088:	c7b20070 */ 	lwc1	$f18,0x70($sp)
.L0f12d08c:
/*  f12d08c:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d090:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f12d094:	e7b00090 */ 	swc1	$f16,0x90($sp)
/*  f12d098:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f12d09c:	0c0068f4 */ 	jal	fcos
/*  f12d0a0:	afab00c8 */ 	sw	$t3,0xc8($sp)
/*  f12d0a4:	46160502 */ 	mul.s	$f20,$f0,$f22
/*  f12d0a8:	0c0068f7 */ 	jal	fsin
/*  f12d0ac:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d0b0:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f12d0b4:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f12d0b8:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f12d0bc:	c56a0000 */ 	lwc1	$f10,0x0($t3)
/*  f12d0c0:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f12d0c4:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f12d0c8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0cc:	240306e0 */ 	addiu	$v1,$zero,0x6e0
/*  f12d0d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12d0d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f12d0d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f12d0dc:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f12d0e0:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f12d0e4:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d0e8:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f12d0ec:	c56a0008 */ 	lwc1	$f10,0x8($t3)
/*  f12d0f0:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0f4:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f12d0f8:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f12d0fc:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f12d100:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d104:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f12d108:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f12d10c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d110:	e7a400b4 */ 	swc1	$f4,0xb4($sp)
/*  f12d114:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f12d118:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d11c:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
/*  f12d120:	c56a0010 */ 	lwc1	$f10,0x10($t3)
/*  f12d124:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d128:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f12d12c:	c5660014 */ 	lwc1	$f6,0x14($t3)
/*  f12d130:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d134:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f12d138:	c56a0018 */ 	lwc1	$f10,0x18($t3)
/*  f12d13c:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d140:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f12d144:	c5660010 */ 	lwc1	$f6,0x10($t3)
/*  f12d148:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d14c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f12d150:	c56a0014 */ 	lwc1	$f10,0x14($t3)
/*  f12d154:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d158:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f12d15c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f12d160:	c5660018 */ 	lwc1	$f6,0x18($t3)
/*  f12d164:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f12d168:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d16c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f12d170:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f12d174:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d178:	c58a0000 */ 	lwc1	$f10,0x0($t4)
/*  f12d17c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d180:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d184:	440d3000 */ 	mfc1	$t5,$f6
/*  f12d188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d18c:	a60d0000 */ 	sh	$t5,0x0($s0)
/*  f12d190:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f12d194:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f12d198:	46088281 */ 	sub.s	$f10,$f16,$f8
/*  f12d19c:	c5880004 */ 	lwc1	$f8,0x4($t4)
/*  f12d1a0:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d1a4:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1a8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d1ac:	440f2000 */ 	mfc1	$t7,$f4
/*  f12d1b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d1b4:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f12d1b8:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f12d1bc:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f12d1c0:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f12d1c4:	c5860008 */ 	lwc1	$f6,0x8($t4)
/*  f12d1c8:	a6030008 */ 	sh	$v1,0x8($s0)
/*  f12d1cc:	a600000a */ 	sh	$zero,0xa($s0)
/*  f12d1d0:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d1d4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d1d8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d1dc:	44195000 */ 	mfc1	$t9,$f10
/*  f12d1e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d1e4:	a6190004 */ 	sh	$t9,0x4($s0)
/*  f12d1e8:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f12d1ec:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f12d1f0:	46047180 */ 	add.s	$f6,$f14,$f4
/*  f12d1f4:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f12d1f8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1fc:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d200:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d204:	440e4000 */ 	mfc1	$t6,$f8
/*  f12d208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d20c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f12d210:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f12d214:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f12d218:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f12d21c:	c58a0004 */ 	lwc1	$f10,0x4($t4)
/*  f12d220:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d224:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d228:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d22c:	44183000 */ 	mfc1	$t8,$f6
/*  f12d230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d234:	a618000e */ 	sh	$t8,0xe($s0)
/*  f12d238:	c7a800b8 */ 	lwc1	$f8,0xb8($sp)
/*  f12d23c:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f12d240:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f12d244:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f12d248:	a6000014 */ 	sh	$zero,0x14($s0)
/*  f12d24c:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f12d250:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d254:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d258:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d25c:	440d2000 */ 	mfc1	$t5,$f4
/*  f12d260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d264:	a60d0010 */ 	sh	$t5,0x10($s0)
/*  f12d268:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f12d26c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f12d270:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f12d274:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12d278:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d27c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d280:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d284:	440f5000 */ 	mfc1	$t7,$f10
/*  f12d288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d28c:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f12d290:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f12d294:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f12d298:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f12d29c:	c5840004 */ 	lwc1	$f4,0x4($t4)
/*  f12d2a0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d2a4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d2a8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d2ac:	44194000 */ 	mfc1	$t9,$f8
/*  f12d2b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d2b4:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f12d2b8:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f12d2bc:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f12d2c0:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f12d2c4:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*  f12d2c8:	a6000020 */ 	sh	$zero,0x20($s0)
/*  f12d2cc:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f12d2d0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f12d2d4:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d2d8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d2dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f12d2e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d2e4:	a60e001c */ 	sh	$t6,0x1c($s0)
/*  f12d2e8:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f12d2ec:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f12d2f0:	46087281 */ 	sub.s	$f10,$f14,$f8
/*  f12d2f4:	c5880000 */ 	lwc1	$f8,0x0($t4)
/*  f12d2f8:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f12d2fc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d300:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d304:	44182000 */ 	mfc1	$t8,$f4
/*  f12d308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d30c:	a6180024 */ 	sh	$t8,0x24($s0)
/*  f12d310:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f12d314:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f12d318:	3c180430 */ 	lui	$t8,0x430
/*  f12d31c:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f12d320:	c5860004 */ 	lwc1	$f6,0x4($t4)
/*  f12d324:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d328:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d32c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d330:	440d5000 */ 	mfc1	$t5,$f10
/*  f12d334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d338:	a60d0026 */ 	sh	$t5,0x26($s0)
/*  f12d33c:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f12d340:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f12d344:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f12d348:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f12d34c:	a603002c */ 	sh	$v1,0x2c($s0)
/*  f12d350:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f12d354:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d358:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d35c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d360:	440f4000 */ 	mfc1	$t7,$f8
/*  f12d364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d368:	a60f0028 */ 	sh	$t7,0x28($s0)
.L0f12d36c:
/*  f12d36c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f12d370:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f12d374:	1485fffd */ 	bne	$a0,$a1,.L0f12d36c
/*  f12d378:	a040fffb */ 	sb	$zero,-0x5($v0)
/*  f12d37c:	8fa200d8 */ 	lw	$v0,0xd8($sp)
/*  f12d380:	37180030 */ 	ori	$t8,$t8,0x30
/*  f12d384:	02002025 */ 	or	$a0,$s0,$zero
/*  f12d388:	00402825 */ 	or	$a1,$v0,$zero
/*  f12d38c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f12d390:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f12d394:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f12d398:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12d39c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f12d3a0:	8fa300d8 */ 	lw	$v1,0xd8($sp)
/*  f12d3a4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f12d3a8:	3c19b100 */ 	lui	$t9,0xb100
/*  f12d3ac:	37390032 */ 	ori	$t9,$t9,0x32
/*  f12d3b0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f12d3b4:	240d2010 */ 	addiu	$t5,$zero,0x2010
/*  f12d3b8:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f12d3bc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f12d3c0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f12d3c4:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f12d3c8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f12d3cc:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f12d3d0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f12d3d4:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f12d3d8:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f12d3dc:	03e00008 */ 	jr	$ra
/*  f12d3e0:	24620008 */ 	addiu	$v0,$v1,0x8
/*  f12d3e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d3e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12d3ec:	00000000 */ 	sll	$zero,$zero,0x0
);
