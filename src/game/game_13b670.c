#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/game_13b670.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

/**
 * dyntex - dynamic textures
 *
 * This file handles textures which animate automatically, such as water.
 *
 * The dyntex system maintains three conceptually nested arrays: rooms, types
 * and vertices.
 *
 * Rooms are the first tier. Rooms will only exist in the array if they contain
 * animated textures. Rooms contain types.
 *
 * Types are a type of animation. Linear is the most common, but there's also
 * ocean waves, and some specific types such as Attack Ship triangular arrows.
 * Types contain vertices.
 *
 * Vertices contain an offset to the graphics vertex, as well as a copy of its
 * S and T values.
 *
 * The caller should call dyntexSetCurrentRoom and dyntexSetCurrentType, then
 * add vertices with dyntexAddVertex. Lastly, dyntexTickRoom should be called
 * on each tick for each nearby room. dyntexTickRoom can be called multiple
 * times on the same frame (such as if there's two players), as dyntex will
 * ensure it's only updated once per frame.
 *
 * Data is added to dyntex during gameplay as rooms are loaded. When a room is
 * unloaded the data remains in the dyntex arrays. When a room is loaded again
 * dyntex will not add it a second time.
 */

struct dyntexroom {
	u16 roomnum;
	u16 typelistoffset;
	u16 numtypes;
	s32 updatedframe;
};

struct dyntextype {
	u16 type : 7;
	u16 initialised : 1;
	u8 numvertices;
	u16 vertexlistoffset;
};

struct dyntexvtx {
	u16 offset;
	s16 s;
	s16 t;
};

const char var7f1b5960[] = "modula";
const char var7f1b5968[] = "ripsize";

s32 g_DyntexVerticesMax;
s32 g_DyntexTypesMax;
s32 g_DyntexRoomsMax;
struct dyntexvtx *g_DyntexVertices;
struct dyntextype *g_DyntexTypes;
struct dyntexroom *g_DyntexRooms;

s32 g_DyntexCurRoom = -1;
s32 g_DyntexCurType = -1;
bool g_DyntexRoomPopulated = false;
bool g_DyntexTypePopulated = false;
s32 g_DyntexRoomsCount = 0;
s32 g_DyntexTypesCount = 0;
s32 g_DyntexVerticesCount = 0;
u32 var8007f6fc = 0x00000041;
u32 var8007f700 = 0x00000016;
u32 var8007f704 = 0x0000001d;
u32 var8007f708 = 0x0000004a;
u32 var8007f70c = 0x00000006;
u32 var8007f710 = 0x00000006;
u32 var8007f714 = 0x00000038;
u32 var8007f718 = 0x000003d5;
u32 var8007f71c = 0x00000018;
u32 var8007f720 = 0x00000018;
u32 var8007f724 = 0x00000034;
u32 var8007f728 = 0x000002f7;
u32 var8007f72c = 0x00000012;
u32 var8007f730 = 0x00000012;

void dyntexUpdateLinear(struct gfxvtx *vertices, struct dyntextype *type);
void dyntexUpdateOcean(struct gfxvtx *vertices, struct dyntextype *type);
void dyntexUpdateArrows(struct gfxvtx *vertices, struct dyntextype *type);

GLOBAL_ASM(
glabel dyntexUpdateLinear
/*  f13b670:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13b674:	c4241634 */ 	lwc1	$f4,%lo(var80061634)($at)
/*  f13b678:	3c014120 */ 	lui	$at,0x4120
/*  f13b67c:	44813000 */ 	mtc1	$at,$f6
/*  f13b680:	3c014580 */ 	lui	$at,0x4580
/*  f13b684:	44815000 */ 	mtc1	$at,$f10
/*  f13b688:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f13b68c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f13b690:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f13b694:	90a90001 */ 	lbu	$t1,0x1($a1)
/*  f13b698:	3c08800a */ 	lui	$t0,%hi(g_DyntexVertices)
/*  f13b69c:	00808025 */ 	or	$s0,$a0,$zero
/*  f13b6a0:	2508418c */ 	addiu	$t0,$t0,%lo(g_DyntexVertices)
/*  f13b6a4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f13b6a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f13b6ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f13b6b0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13b6b4:	44029000 */ 	mfc1	$v0,$f18
/*  f13b6b8:	00000000 */ 	nop
/*  f13b6bc:	04410004 */ 	bgez	$v0,.L0f13b6d0
/*  f13b6c0:	304f0fff */ 	andi	$t7,$v0,0xfff
/*  f13b6c4:	11e00002 */ 	beqz	$t7,.L0f13b6d0
/*  f13b6c8:	00000000 */ 	nop
/*  f13b6cc:	25eff000 */ 	addiu	$t7,$t7,-4096
.L0f13b6d0:
/*  f13b6d0:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f13b6d4:	1920001c */ 	blez	$t1,.L0f13b748
/*  f13b6d8:	00181403 */ 	sra	$v0,$t8,0x10
/*  f13b6dc:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b6e0:
/*  f13b6e0:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f13b6e4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13b6e8:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13b6ec:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f13b6f0:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f13b6f4:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f13b6f8:	01a63821 */ 	addu	$a3,$t5,$a2
/*  f13b6fc:	94ee0000 */ 	lhu	$t6,0x0($a3)
/*  f13b700:	84ef0004 */ 	lh	$t7,0x4($a3)
/*  f13b704:	01d02021 */ 	addu	$a0,$t6,$s0
/*  f13b708:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13b70c:	a498000a */ 	sh	$t8,0xa($a0)
/*  f13b710:	94a90002 */ 	lhu	$t1,0x2($a1)
/*  f13b714:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f13b718:	00095880 */ 	sll	$t3,$t1,0x2
/*  f13b71c:	01695823 */ 	subu	$t3,$t3,$t1
/*  f13b720:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f13b724:	032b5021 */ 	addu	$t2,$t9,$t3
/*  f13b728:	01466021 */ 	addu	$t4,$t2,$a2
/*  f13b72c:	858d0002 */ 	lh	$t5,0x2($t4)
/*  f13b730:	24c60006 */ 	addiu	$a2,$a2,0x6
/*  f13b734:	a48d0008 */ 	sh	$t5,0x8($a0)
/*  f13b738:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f13b73c:	006e082a */ 	slt	$at,$v1,$t6
/*  f13b740:	5420ffe7 */ 	bnezl	$at,.L0f13b6e0
/*  f13b744:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b748:
/*  f13b748:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f13b74c:	03e00008 */ 	jr	$ra
/*  f13b750:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

void dyntexUpdateReset(struct gfxvtx *vertices, struct dyntextype *type)
{
	s32 i;

	for (i = 0; i < type->numvertices; i++) {
		struct gfxvtx *vertex = (struct gfxvtx *)((s32)vertices + g_DyntexVertices[type->vertexlistoffset + i].offset);

		vertex->unk08 = 0;
		vertex->unk0a = 0;
	}
}

void dyntexUpdateMonitor(struct gfxvtx *vertices, struct dyntextype *type)
{
	s16 tmp = (s32) (var80061634 * 4.0f * 4096.0f) % 4096;
	s32 i;

	for (i = 0; i < type->numvertices; i++) {
		struct gfxvtx *vertex = (struct gfxvtx *)((s32)vertices + g_DyntexVertices[type->vertexlistoffset + i].offset);

		vertex->unk0a = g_DyntexVertices[type->vertexlistoffset + i].t - tmp;
		vertex->unk08 = g_DyntexVertices[type->vertexlistoffset + i].s;
	}
}

GLOBAL_ASM(
glabel dyntexUpdateOcean
.late_rodata
glabel var7f1b5970
.word 0x40c907a9
.text
/*  f13b8a0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f13b8a4:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13b8a8:	c4241634 */ 	lwc1	$f4,%lo(var80061634)($at)
/*  f13b8ac:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13b8b0:	44813000 */ 	mtc1	$at,$f6
/*  f13b8b4:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f13b8b8:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f13b8bc:	00a09025 */ 	or	$s2,$a1,$zero
/*  f13b8c0:	0080a825 */ 	or	$s5,$a0,$zero
/*  f13b8c4:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f13b8c8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f13b8cc:	3c047f1b */ 	lui	$a0,%hi(var7f1b5960)
/*  f13b8d0:	3c058008 */ 	lui	$a1,%hi(var8007f700)
/*  f13b8d4:	46062602 */ 	mul.s	$f24,$f4,$f6
/*  f13b8d8:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f13b8dc:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f13b8e0:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f13b8e4:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f13b8e8:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f13b8ec:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f13b8f0:	24a5f700 */ 	addiu	$a1,$a1,%lo(var8007f700)
/*  f13b8f4:	0c0036cc */ 	jal	mainOverrideVariable
/*  f13b8f8:	24845960 */ 	addiu	$a0,$a0,%lo(var7f1b5960)
/*  f13b8fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b5968)
/*  f13b900:	3c058008 */ 	lui	$a1,%hi(var8007f6fc)
/*  f13b904:	24a5f6fc */ 	addiu	$a1,$a1,%lo(var8007f6fc)
/*  f13b908:	0c0036cc */ 	jal	mainOverrideVariable
/*  f13b90c:	24845968 */ 	addiu	$a0,$a0,%lo(var7f1b5968)
/*  f13b910:	924e0001 */ 	lbu	$t6,0x1($s2)
/*  f13b914:	00009825 */ 	or	$s3,$zero,$zero
/*  f13b918:	00008025 */ 	or	$s0,$zero,$zero
/*  f13b91c:	19c00083 */ 	blez	$t6,.L0f13bb2c
/*  f13b920:	3c017f1b */ 	lui	$at,%hi(var7f1b5970)
/*  f13b924:	3c11800a */ 	lui	$s1,%hi(g_DyntexVertices)
/*  f13b928:	2631418c */ 	addiu	$s1,$s1,%lo(g_DyntexVertices)
/*  f13b92c:	c4365970 */ 	lwc1	$f22,%lo(var7f1b5970)($at)
/*  f13b930:	96580002 */ 	lhu	$t8,0x2($s2)
.L0f13b934:
/*  f13b934:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f13b938:	3c0b8008 */ 	lui	$t3,%hi(var8007f700)
/*  f13b93c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13b940:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f13b944:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13b948:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f13b94c:	8d6bf700 */ 	lw	$t3,%lo(var8007f700)($t3)
/*  f13b950:	01101021 */ 	addu	$v0,$t0,$s0
/*  f13b954:	844a0004 */ 	lh	$t2,0x4($v0)
/*  f13b958:	94490000 */ 	lhu	$t1,0x0($v0)
/*  f13b95c:	448b9000 */ 	mtc1	$t3,$f18
/*  f13b960:	014b001b */ 	divu	$zero,$t2,$t3
/*  f13b964:	00006010 */ 	mfhi	$t4
/*  f13b968:	448c4000 */ 	mtc1	$t4,$f8
/*  f13b96c:	0135a021 */ 	addu	$s4,$t1,$s5
/*  f13b970:	15600002 */ 	bnez	$t3,.L0f13b97c
/*  f13b974:	00000000 */ 	nop
/*  f13b978:	0007000d */ 	break	0x7
.L0f13b97c:
/*  f13b97c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13b980:	05810004 */ 	bgez	$t4,.L0f13b994
/*  f13b984:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b988:	44818000 */ 	mtc1	$at,$f16
/*  f13b98c:	00000000 */ 	nop
/*  f13b990:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f13b994:
/*  f13b994:	05610005 */ 	bgez	$t3,.L0f13b9ac
/*  f13b998:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13b99c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b9a0:	44813000 */ 	mtc1	$at,$f6
/*  f13b9a4:	00000000 */ 	nop
/*  f13b9a8:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f13b9ac:
/*  f13b9ac:	46045203 */ 	div.s	$f8,$f10,$f4
/*  f13b9b0:	46184400 */ 	add.s	$f16,$f8,$f24
/*  f13b9b4:	46168502 */ 	mul.s	$f20,$f16,$f22
/*  f13b9b8:	0c0068f7 */ 	jal	sinf
/*  f13b9bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f13b9c0:	964e0002 */ 	lhu	$t6,0x2($s2)
/*  f13b9c4:	3c098008 */ 	lui	$t1,%hi(var8007f6fc)
/*  f13b9c8:	8d29f6fc */ 	lw	$t1,%lo(var8007f6fc)($t1)
/*  f13b9cc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f13b9d0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f13b9d4:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f13b9d8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f13b9dc:	44899000 */ 	mtc1	$t1,$f18
/*  f13b9e0:	01b87821 */ 	addu	$t7,$t5,$t8
/*  f13b9e4:	01f0c821 */ 	addu	$t9,$t7,$s0
/*  f13b9e8:	87280004 */ 	lh	$t0,0x4($t9)
/*  f13b9ec:	05210005 */ 	bgez	$t1,.L0f13ba04
/*  f13b9f0:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f13b9f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b9f8:	44815000 */ 	mtc1	$at,$f10
/*  f13b9fc:	00000000 */ 	nop
/*  f13ba00:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f13ba04:
/*  f13ba04:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f13ba08:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ba0c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f13ba10:	440c4000 */ 	mfc1	$t4,$f8
/*  f13ba14:	00000000 */ 	nop
/*  f13ba18:	000c5c00 */ 	sll	$t3,$t4,0x10
/*  f13ba1c:	000b7403 */ 	sra	$t6,$t3,0x10
/*  f13ba20:	01c86821 */ 	addu	$t5,$t6,$t0
/*  f13ba24:	a68d000a */ 	sh	$t5,0xa($s4)
/*  f13ba28:	964f0002 */ 	lhu	$t7,0x2($s2)
/*  f13ba2c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f13ba30:	3c0e8008 */ 	lui	$t6,%hi(var8007f700)
/*  f13ba34:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f13ba38:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f13ba3c:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13ba40:	03194821 */ 	addu	$t1,$t8,$t9
/*  f13ba44:	01305021 */ 	addu	$t2,$t1,$s0
/*  f13ba48:	854c0002 */ 	lh	$t4,0x2($t2)
/*  f13ba4c:	8dcef700 */ 	lw	$t6,%lo(var8007f700)($t6)
/*  f13ba50:	258b0016 */ 	addiu	$t3,$t4,0x16
/*  f13ba54:	016e001b */ 	divu	$zero,$t3,$t6
/*  f13ba58:	00004010 */ 	mfhi	$t0
/*  f13ba5c:	44888000 */ 	mtc1	$t0,$f16
/*  f13ba60:	15c00002 */ 	bnez	$t6,.L0f13ba6c
/*  f13ba64:	00000000 */ 	nop
/*  f13ba68:	0007000d */ 	break	0x7
.L0f13ba6c:
/*  f13ba6c:	448e3000 */ 	mtc1	$t6,$f6
/*  f13ba70:	05010004 */ 	bgez	$t0,.L0f13ba84
/*  f13ba74:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13ba78:	44815000 */ 	mtc1	$at,$f10
/*  f13ba7c:	00000000 */ 	nop
/*  f13ba80:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f13ba84:
/*  f13ba84:	05c10005 */ 	bgez	$t6,.L0f13ba9c
/*  f13ba88:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13ba8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ba90:	44814000 */ 	mtc1	$at,$f8
/*  f13ba94:	00000000 */ 	nop
/*  f13ba98:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f13ba9c:
/*  f13ba9c:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f13baa0:	46188280 */ 	add.s	$f10,$f16,$f24
/*  f13baa4:	46165502 */ 	mul.s	$f20,$f10,$f22
/*  f13baa8:	0c0068f4 */ 	jal	cosf
/*  f13baac:	4600a306 */ 	mov.s	$f12,$f20
/*  f13bab0:	964f0002 */ 	lhu	$t7,0x2($s2)
/*  f13bab4:	3c0c8008 */ 	lui	$t4,%hi(var8007f6fc)
/*  f13bab8:	8d8cf6fc */ 	lw	$t4,%lo(var8007f6fc)($t4)
/*  f13babc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f13bac0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13bac4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f13bac8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f13bacc:	448c3000 */ 	mtc1	$t4,$f6
/*  f13bad0:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f13bad4:	03304821 */ 	addu	$t1,$t9,$s0
/*  f13bad8:	852a0002 */ 	lh	$t2,0x2($t1)
/*  f13badc:	05810005 */ 	bgez	$t4,.L0f13baf4
/*  f13bae0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13bae4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13bae8:	44819000 */ 	mtc1	$at,$f18
/*  f13baec:	00000000 */ 	nop
/*  f13baf0:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f13baf4:
/*  f13baf4:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f13baf8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f13bafc:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f13bb00:	4600240d */ 	trunc.w.s	$f16,$f4
/*  f13bb04:	44088000 */ 	mfc1	$t0,$f16
/*  f13bb08:	00000000 */ 	nop
/*  f13bb0c:	00087400 */ 	sll	$t6,$t0,0x10
/*  f13bb10:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f13bb14:	01ea6821 */ 	addu	$t5,$t7,$t2
/*  f13bb18:	a68d0008 */ 	sh	$t5,0x8($s4)
/*  f13bb1c:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f13bb20:	0278082a */ 	slt	$at,$s3,$t8
/*  f13bb24:	5420ff83 */ 	bnezl	$at,.L0f13b934
/*  f13bb28:	96580002 */ 	lhu	$t8,0x2($s2)
.L0f13bb2c:
/*  f13bb2c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f13bb30:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f13bb34:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f13bb38:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f13bb3c:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f13bb40:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f13bb44:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f13bb48:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f13bb4c:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f13bb50:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f13bb54:	03e00008 */ 	jr	$ra
/*  f13bb58:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel dyntexUpdateArrows
/*  f13bb5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13bb60:	44812000 */ 	mtc1	$at,$f4
/*  f13bb64:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13bb68:	c4261634 */ 	lwc1	$f6,%lo(var80061634)($at)
/*  f13bb6c:	3c014270 */ 	lui	$at,0x4270
/*  f13bb70:	44815000 */ 	mtc1	$at,$f10
/*  f13bb74:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f13bb78:	3c014100 */ 	lui	$at,0x4100
/*  f13bb7c:	44819000 */ 	mtc1	$at,$f18
/*  f13bb80:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f13bb84:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f13bb88:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f13bb8c:	90b90001 */ 	lbu	$t9,0x1($a1)
/*  f13bb90:	3c08800a */ 	lui	$t0,%hi(g_DyntexVertices)
/*  f13bb94:	00808025 */ 	or	$s0,$a0,$zero
/*  f13bb98:	2508418c */ 	addiu	$t0,$t0,%lo(g_DyntexVertices)
/*  f13bb9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f13bba0:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f13bba4:	00003025 */ 	or	$a2,$zero,$zero
/*  f13bba8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f13bbac:	44023000 */ 	mfc1	$v0,$f6
/*  f13bbb0:	00000000 */ 	nop
/*  f13bbb4:	04410004 */ 	bgez	$v0,.L0f13bbc8
/*  f13bbb8:	304f0007 */ 	andi	$t7,$v0,0x7
/*  f13bbbc:	11e00002 */ 	beqz	$t7,.L0f13bbc8
/*  f13bbc0:	00000000 */ 	nop
/*  f13bbc4:	25effff8 */ 	addiu	$t7,$t7,-8
.L0f13bbc8:
/*  f13bbc8:	1b20001c */ 	blez	$t9,.L0f13bc3c
/*  f13bbcc:	000f1200 */ 	sll	$v0,$t7,0x8
/*  f13bbd0:	94aa0002 */ 	lhu	$t2,0x2($a1)
.L0f13bbd4:
/*  f13bbd4:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f13bbd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13bbdc:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f13bbe0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f13bbe4:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f13bbe8:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f13bbec:	01863821 */ 	addu	$a3,$t4,$a2
/*  f13bbf0:	94ed0000 */ 	lhu	$t5,0x0($a3)
/*  f13bbf4:	84ee0002 */ 	lh	$t6,0x2($a3)
/*  f13bbf8:	01b02021 */ 	addu	$a0,$t5,$s0
/*  f13bbfc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13bc00:	a48f0008 */ 	sh	$t7,0x8($a0)
/*  f13bc04:	94b90002 */ 	lhu	$t9,0x2($a1)
/*  f13bc08:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f13bc0c:	00195080 */ 	sll	$t2,$t9,0x2
/*  f13bc10:	01595023 */ 	subu	$t2,$t2,$t9
/*  f13bc14:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f13bc18:	030a4821 */ 	addu	$t1,$t8,$t2
/*  f13bc1c:	01265821 */ 	addu	$t3,$t1,$a2
/*  f13bc20:	856c0004 */ 	lh	$t4,0x4($t3)
/*  f13bc24:	24c60006 */ 	addiu	$a2,$a2,0x6
/*  f13bc28:	a48c000a */ 	sh	$t4,0xa($a0)
/*  f13bc2c:	90ad0001 */ 	lbu	$t5,0x1($a1)
/*  f13bc30:	006d082a */ 	slt	$at,$v1,$t5
/*  f13bc34:	5420ffe7 */ 	bnezl	$at,.L0f13bbd4
/*  f13bc38:	94aa0002 */ 	lhu	$t2,0x2($a1)
.L0f13bc3c:
/*  f13bc3c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f13bc40:	03e00008 */ 	jr	$ra
/*  f13bc44:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

void dyntexTickRoom(s32 roomnum, struct gfxvtx *vertices)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < g_DyntexRoomsCount; i++) {
		if (g_DyntexRooms[i].roomnum == roomnum) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		return;
	}

	if (g_Vars.lvframenum == g_DyntexRooms[index].updatedframe) {
		return;
	}

	for (i = 0; i < g_DyntexRooms[index].numtypes; i++) {
		struct dyntextype *type = &g_DyntexTypes[g_DyntexRooms[index].typelistoffset + i];
		s32 mins = 32767;
		s32 maxs = -32766;
		s32 mint = 32767;
		s32 maxt = -32766;

		if (!type->initialised) {
			s32 adds = 0;
			s32 addt = 0;

			if (1);

			// @bug: Using i for both outer and inner loops
			for (i = 0; i < type->numvertices; i++) {
				struct gfxvtx *vertex = (struct gfxvtx *)((s32)vertices + g_DyntexVertices[type->vertexlistoffset + i].offset);

				g_DyntexVertices[type->vertexlistoffset + i].s = vertex->unk08;
				g_DyntexVertices[type->vertexlistoffset + i].t = vertex->unk0a;

				if (vertex->unk08 < mins) {
					mins = vertex->unk08;
				}

				if (vertex->unk0a < mint) {
					mint = vertex->unk0a;
				}

				if (vertex->unk08 > maxs) {
					maxs = vertex->unk08;
				}

				if (vertex->unk0a > maxt) {
					maxt = vertex->unk0a;
				}
			}

			type->initialised = true;

			if (mins < -0x5d00) {
				adds = 0x2000;
			}

			if (mint < -0x5d00) {
				addt = 0x2000;
			}

			if (maxs > 0x5d00) {
				adds = -0x2000;
			}

			if (maxt > 0x5d00) {
				addt = -0x2000;
			}

			if (adds || addt) {
				for (i = 0; i < type->numvertices; i++) {
					g_DyntexVertices[type->vertexlistoffset + i].s += adds;
					g_DyntexVertices[type->vertexlistoffset + i].t += addt;
				}
			}
		}

		switch (g_DyntexTypes[g_DyntexRooms[index].typelistoffset + i].type) {
		case DYNTEXTYPE_RIVER:
			dyntexUpdateLinear(vertices, type);
			break;
		case DYNTEXTYPE_MONITOR:
			dyntexUpdateMonitor(vertices, type);
			break;
		case DYNTEXTYPE_OCEAN:
			dyntexUpdateOcean(vertices, type);
			break;
		case DYNTEXTYPE_ARROWS:
			dyntexUpdateArrows(vertices, type);
			break;
		case DYNTEXTYPE_TELEPORTAL:
			// Deep Sea - teleports enabled and not SA disabled
			if (chrHasStageFlag(0, 0x00000100) && !chrHasStageFlag(0, 0x00010000)) {
				dyntexUpdateLinear(vertices, type);
			}
			break;
		case DYNTEXTYPE_POWERRING:
			if (chrHasStageFlag(0, 0x00010000)) {
				// Attack Ship engines are destroyed
				dyntexUpdateReset(vertices, type);
			} else {
				// Attack Ship engines are healthy
				dyntexUpdateLinear(vertices, type);
			}
			break;
		case DYNTEXTYPE_POWERJUICE:
			if (!chrHasStageFlag(0, 0x00010000)) {
				// Attack Ship engines are healthy
				dyntexUpdateLinear(vertices, type);
			}
			break;
		}
	}

	g_DyntexRooms[index].updatedframe = g_Vars.lvframenum;
}

void dyntexAddVertex(struct gfxvtx *vertex)
{
	if (g_DyntexCurRoom < 0) {
		return;
	}

	if (g_DyntexVerticesCount == g_DyntexVerticesMax) {
		return;
	}

	if (!g_DyntexRoomPopulated) {
		if (g_DyntexTypesCount >= g_DyntexTypesMax || g_DyntexRoomsCount >= g_DyntexRoomsMax) {
			return;
		}

		g_DyntexRooms[g_DyntexRoomsCount].roomnum = g_DyntexCurRoom;
		g_DyntexRooms[g_DyntexRoomsCount].typelistoffset = g_DyntexTypesCount;
		g_DyntexRooms[g_DyntexRoomsCount].numtypes = 0;
		g_DyntexRooms[g_DyntexRoomsCount].updatedframe = 0;

		g_Rooms[g_DyntexCurRoom].flags |= ROOMFLAG_HASDYNTEX;

		g_DyntexRoomsCount++;
		g_DyntexRoomPopulated = true;
	}

	if (!g_DyntexTypePopulated) {
		if (g_DyntexTypesCount >= g_DyntexTypesMax) {
			return;
		}

		g_DyntexTypes[g_DyntexTypesCount].type = g_DyntexCurType;
		g_DyntexTypes[g_DyntexTypesCount].initialised = false;
		g_DyntexTypes[g_DyntexTypesCount].numvertices = 0;
		g_DyntexTypes[g_DyntexTypesCount].vertexlistoffset = g_DyntexVerticesCount;
		g_DyntexTypesCount++;

		g_DyntexRooms[g_DyntexRoomsCount - 1].numtypes++;
		g_DyntexTypePopulated = true;
	}

	g_DyntexVertices[g_DyntexVerticesCount].offset = (u16)vertex;
	g_DyntexVerticesCount++;

	g_DyntexTypes[g_DyntexTypesCount - 1].numvertices++;
}

void dyntexSetCurrentType(s16 type)
{
	// Air Base - don't animate anything (exterior water)
	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		return;
	}

	// Investigation - don't animate the puddle of water behind the glass
	if (g_StageIndex == STAGEINDEX_INVESTIGATION && type == DYNTEXTYPE_RIVER) {
		return;
	}

	// Villa - don't animate shallow water
	if (g_StageIndex == STAGEINDEX_VILLA && type == DYNTEXTYPE_RIVER) {
		return;
	}

	// Power juice and power rings exist on Deep Sea and Attack Ship.
	//
	// Deep Sea - in the SA megaweapon
	// Attack Ship - in the engine's power node
	//
	// These both use a linear animation, but Attack Ship's are conditional on
	// the ship's engines running. To avoid doing a stage check on every tick,
	// Deep Sea's are retyped to the river type which uses an unconditional
	// linear animation. Attack Ship's remains as is.
	if (g_StageIndex != STAGEINDEX_ATTACKSHIP && (type == DYNTEXTYPE_POWERJUICE || type == DYNTEXTYPE_POWERRING)) {
		type = DYNTEXTYPE_RIVER;
	}

	if (type != g_DyntexCurType) {
		g_DyntexTypePopulated = false;
	}

	g_DyntexCurType = type;
}

void dyntexSetCurrentRoom(s16 roomnum)
{
	s32 i;

	if (roomnum >= 0) {
		for (i = 0; i < g_DyntexRoomsCount; i++) {
			if (g_DyntexRooms[i].roomnum == roomnum) {
				return;
			}
		}
	}

	if (g_DyntexRooms != NULL) {
		g_DyntexRoomPopulated = false;
		g_DyntexTypePopulated = false;
		g_DyntexCurRoom = roomnum;
		g_DyntexCurType = -1;
	}
}

void dyntexReset(void)
{
	u32 size3;
	u32 size2;
	u32 size1;

	g_DyntexCurRoom = -1;
	g_DyntexCurType = -1;
	g_DyntexRoomPopulated = false;
	g_DyntexRoomsCount = 0;
	g_DyntexTypesCount = 0;
	g_DyntexVerticesCount = 0;

	g_DyntexVerticesMax = 1200;
	g_DyntexTypesMax = 50;
	g_DyntexRoomsMax = 50;

	size1 = ALIGN64(g_DyntexTypesMax * sizeof(struct dyntextype));
	g_DyntexTypes = mempAlloc(size1, MEMPOOL_STAGE);

	size2 = ALIGN64(g_DyntexVerticesMax * sizeof(struct dyntexvtx));
	g_DyntexVertices = mempAlloc(size2, MEMPOOL_STAGE);

	size3 = ALIGN64(g_DyntexRoomsMax * sizeof(struct dyntexroom));
	g_DyntexRooms = mempAlloc(size3, MEMPOOL_STAGE);

	if (g_DyntexVerticesMax);
	if (g_DyntexTypesMax);
	if (size1);
}

void dyntex0f13c4e8(void)
{
	// empty
}

bool dyntexHasRoom(void)
{
	return g_DyntexCurRoom >= 0;
}
