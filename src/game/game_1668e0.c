#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_1668e0.h"
#include "gvars/gvars.h"
#include "library/library_159b0.h"
#include "types.h"

const char var7f1b76f0[] = "-mgfx";
const char var7f1b76f8[] = "-mgfx";
const char var7f1b7700[] = "-mgfxtra";
const char var7f1b770c[] = "-mgfxtra";
const char var7f1b7718[] = "-mvtx";
const char var7f1b7720[] = "-mvtx";
const char var7f1b7728[] = "";
const char var7f1b772c[] = "";
const char var7f1b7730[] = "fr: %d\n";
const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";

const u32 var7f1b7768[] = {0x00000000};
const u32 var7f1b776c[] = {0x00000000};
const u32 var7f1b7770[] = {0x7f1681e8};
const u32 var7f1b7774[] = {0x7f1681f0};
const u32 var7f1b7778[] = {0x7f1681f0};
const u32 var7f1b777c[] = {0x7f1681f0};
const u32 var7f1b7780[] = {0x7f1681f0};
const u32 var7f1b7784[] = {0x7f1681f0};
const u32 var7f1b7788[] = {0x7f1681f0};
const u32 var7f1b778c[] = {0x7f1681f0};
const u32 var7f1b7790[] = {0x7f1681f0};
const u32 var7f1b7794[] = {0x7f1681e8};
const u32 var7f1b7798[] = {0x7f1681f0};
const u32 var7f1b779c[] = {0x7f1681f0};
const u32 var7f1b77a0[] = {0x7f1681f0};
const u32 var7f1b77a4[] = {0x7f1681f0};
const u32 var7f1b77a8[] = {0x7f1681f0};
const u32 var7f1b77ac[] = {0x7f1681f0};
const u32 var7f1b77b0[] = {0x7f1681f0};
const u32 var7f1b77b4[] = {0x7f1681f0};
const u32 var7f1b77b8[] = {0x7f1681f0};
const u32 var7f1b77bc[] = {0x7f1681f0};
const u32 var7f1b77c0[] = {0x7f1681f0};
const u32 var7f1b77c4[] = {0x7f1681f0};
const u32 var7f1b77c8[] = {0x7f1681e8};
const u32 var7f1b77cc[] = {0x7f1681e8};
const u32 var7f1b77d0[] = {0x7f1681f0};
const u32 var7f1b77d4[] = {0x7f1681f0};
const u32 var7f1b77d8[] = {0x7f1681f0};
const u32 var7f1b77dc[] = {0x7f1681e8};
const u32 var7f1b77e0[] = {0x7f168a64};
const u32 var7f1b77e4[] = {0x7f168ac8};
const u32 var7f1b77e8[] = {0x7f168974};
const u32 var7f1b77ec[] = {0x7f168a64};
const u32 var7f1b77f0[] = {0x7f168ac8};
const u32 var7f1b77f4[] = {0x7f16894c};
const u32 var7f1b77f8[] = {0x7f168ac8};
const u32 var7f1b77fc[] = {0x7f168ac8};
const u32 var7f1b7800[] = {0x7f168c70};
const u32 var7f1b7804[] = {0x7f168c84};
const u32 var7f1b7808[] = {0x7f168c84};
const u32 var7f1b780c[] = {0x7f168c84};
const u32 var7f1b7810[] = {0x7f168c84};
const u32 var7f1b7814[] = {0x7f168c84};
const u32 var7f1b7818[] = {0x7f168c84};
const u32 var7f1b781c[] = {0x7f168c84};
const u32 var7f1b7820[] = {0x7f168c84};
const u32 var7f1b7824[] = {0x7f168c84};
const u32 var7f1b7828[] = {0x7f168c84};
const u32 var7f1b782c[] = {0x7f168c84};
const u32 var7f1b7830[] = {0x7f168c84};
const u32 var7f1b7834[] = {0x7f168c84};
const u32 var7f1b7838[] = {0x7f168c84};
const u32 var7f1b783c[] = {0x7f168c68};
const u32 var7f1b7840[] = {0x7f168c68};
const u32 var7f1b7844[] = {0x7f168c68};
const u32 var7f1b7848[] = {0x7f168c68};
const u32 var7f1b784c[] = {0x7f168c68};
const u32 var7f1b7850[] = {0x3f866666};
const u32 var7f1b7854[] = {0x3ca3d70b};
const u32 var7f1b7858[] = {0x3f8ccccd};
const u32 var7f1b785c[] = {0x3bda740e};
const u32 var7f1b7860[] = {0x3ca3d70b};
const u32 var7f1b7864[] = {0x3f8ccccd};
const u32 var7f1b7868[] = {0x3bda740e};
const u32 var7f1b786c[] = {0x3eb33333};
const u32 var7f1b7870[] = {0x3e4ccccd};
const u32 var7f1b7874[] = {0x3f19999a};
const u32 var7f1b7878[] = {0x3f8ccccd};
const u32 var7f1b787c[] = {0x3f333333};
const u32 var7f1b7880[] = {0x3f266666};
const u32 var7f1b7884[] = {0x3f19999a};
const u32 var7f1b7888[] = {0x3e4ccccd};
const u32 var7f1b788c[] = {0x3f8ccccd};
const u32 var7f1b7890[] = {0x3e4ccccd};
const u32 var7f1b7894[] = {0x3f19999a};
const u32 var7f1b7898[] = {0x3ef33334};
const u32 var7f1b789c[] = {0x3f19999a};
const u32 var7f1b78a0[] = {0x3e4ccccd};
const u32 var7f1b78a4[] = {0x3f4ccccd};
const u32 var7f1b78a8[] = {0x3f19999a};
const u32 var7f1b78ac[] = {0x3f8ccccd};
const u32 var7f1b78b0[] = {0x3f966666};
const u32 var7f1b78b4[] = {0x3e4ccccd};
const u32 var7f1b78b8[] = {0x3f8ccccd};
const u32 var7f1b78bc[] = {0x00000000};

const char var7f1b78c0[] = "null";
const char var7f1b78c8[] = "leveltune";
const char var7f1b78d4[] = "nrgtune,watchtune,mpdeathtune";
const char var7f1b78f4[] = "ambience";
const char var7f1b7900[] = "NULL";
const char var7f1b7908[] = "playing";
const char var7f1b7910[] = "paused";
const char var7f1b7918[] = "MUSIC : activedeath=%d\n";

GLOBAL_ASM(
glabel func0f1668e0
/*  f1668e0:	3c0e800a */ 	lui	$t6,0x800a
/*  f1668e4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f1668e8:	03e00008 */ 	jr	$ra
/*  f1668ec:	adc41700 */ 	sw	$a0,0x1700($t6)
);

GLOBAL_ASM(
glabel func0f1668f0
/*  f1668f0:	000578c0 */ 	sll	$t7,$a1,0x3
/*  f1668f4:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f1668f8:	3c0e800a */ 	lui	$t6,0x800a
/*  f1668fc:	8dce4928 */ 	lw	$t6,0x4928($t6)
/*  f166900:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f166904:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f166908:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f16690c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f166910:	a7040010 */ 	sh	$a0,0x10($t8)
/*  f166914:	3c19800a */ 	lui	$t9,0x800a
/*  f166918:	8f396664 */ 	lw	$t9,0x6664($t9)
/*  f16691c:	00044040 */ 	sll	$t0,$a0,0x1
/*  f166920:	03284821 */ 	addu	$t1,$t9,$t0
/*  f166924:	03e00008 */ 	jr	$ra
/*  f166928:	a5250000 */ 	sh	$a1,0x0($t1)
);

GLOBAL_ASM(
glabel func0f16692c
/*  f16692c:	000578c0 */ 	sll	$t7,$a1,0x3
/*  f166930:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f166934:	3c0e800a */ 	lui	$t6,0x800a
/*  f166938:	8dce4928 */ 	lw	$t6,0x4928($t6)
/*  f16693c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f166940:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f166944:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f166948:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16694c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f166950:	a7020010 */ 	sh	$v0,0x10($t8)
/*  f166954:	3c19800a */ 	lui	$t9,0x800a
/*  f166958:	8f396664 */ 	lw	$t9,0x6664($t9)
/*  f16695c:	00044040 */ 	sll	$t0,$a0,0x1
/*  f166960:	03284821 */ 	addu	$t1,$t9,$t0
/*  f166964:	03e00008 */ 	jr	$ra
/*  f166968:	a5220000 */ 	sh	$v0,0x0($t1)
);

GLOBAL_ASM(
glabel func0f16696c
/*  f16696c:	3c0e800a */ 	lui	$t6,0x800a
/*  f166970:	8dce6664 */ 	lw	$t6,0x6664($t6)
/*  f166974:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f166978:	00041040 */ 	sll	$v0,$a0,0x1
/*  f16697c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166980:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f166984:	85e50000 */ 	lh	$a1,0x0($t7)
/*  f166988:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16698c:	10a10006 */ 	beq	$a1,$at,.L0f1669a8
/*  f166990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166994:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f166998:	0fc59a4b */ 	jal	func0f16692c
/*  f16699c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1669a0:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f1669a4:	8fa40020 */ 	lw	$a0,0x20($sp)
.L0f1669a8:
/*  f1669a8:	3c19800a */ 	lui	$t9,0x800a
/*  f1669ac:	8f396660 */ 	lw	$t9,0x6660($t9)
/*  f1669b0:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f1669b4:	3c0a800a */ 	lui	$t2,0x800a
/*  f1669b8:	03244021 */ 	addu	$t0,$t9,$a0
/*  f1669bc:	a1180000 */ 	sb	$t8,0x0($t0)
/*  f1669c0:	8d4a6668 */ 	lw	$t2,0x6668($t2)
/*  f1669c4:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1669c8:	3c0c800a */ 	lui	$t4,0x800a
/*  f1669cc:	01425821 */ 	addu	$t3,$t2,$v0
/*  f1669d0:	a5690000 */ 	sh	$t1,0x0($t3)
/*  f1669d4:	8d8c666c */ 	lw	$t4,0x666c($t4)
/*  f1669d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1669dc:	44812000 */ 	mtc1	$at,$f4
/*  f1669e0:	00046880 */ 	sll	$t5,$a0,0x2
/*  f1669e4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f1669e8:	e5c40000 */ 	swc1	$f4,0x0($t6)
/*  f1669ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1669f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1669f4:	03e00008 */ 	jr	$ra
/*  f1669f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1669fc
/*  f1669fc:	3c028008 */ 	lui	$v0,0x8008
/*  f166a00:	8c422050 */ 	lw	$v0,0x2050($v0)
/*  f166a04:	00001825 */ 	or	$v1,$zero,$zero
/*  f166a08:	3c04800a */ 	lui	$a0,0x800a
/*  f166a0c:	18400014 */ 	blez	$v0,.L0f166a60
/*  f166a10:	3c06800a */ 	lui	$a2,%hi(var800a6668)
/*  f166a14:	8c846660 */ 	lw	$a0,0x6660($a0)
/*  f166a18:	24c66668 */ 	addiu	$a2,$a2,%lo(var800a6668)
/*  f166a1c:	2405ffff */ 	addiu	$a1,$zero,-1
.L0f166a20:
/*  f166a20:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f166a24:	29c10002 */ 	slti	$at,$t6,0x2
/*  f166a28:	5420000a */ 	bnezl	$at,.L0f166a54
/*  f166a2c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f166a30:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f166a34:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f166a38:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f166a3c:	87280000 */ 	lh	$t0,0x0($t9)
/*  f166a40:	54a80004 */ 	bnel	$a1,$t0,.L0f166a54
/*  f166a44:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f166a48:	03e00008 */ 	jr	$ra
/*  f166a4c:	00601025 */ 	or	$v0,$v1,$zero
/*  f166a50:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f166a54:
/*  f166a54:	0062082a */ 	slt	$at,$v1,$v0
/*  f166a58:	1420fff1 */ 	bnez	$at,.L0f166a20
/*  f166a5c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f166a60:
/*  f166a60:	00001025 */ 	or	$v0,$zero,$zero
/*  f166a64:	03e00008 */ 	jr	$ra
/*  f166a68:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f166a6c
/*  f166a6c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f166a70:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f166a74:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f166a78:	8cc204b4 */ 	lw	$v0,0x4b4($a2)
/*  f166a7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166a80:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f166a84:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f166a88:	0c00566c */ 	jal	func000159b0
/*  f166a8c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f166a90:	3c013f80 */ 	lui	$at,0x3f80
/*  f166a94:	44810000 */ 	mtc1	$at,$f0
/*  f166a98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f166a9c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f166aa0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f166aa4:	3c038008 */ 	lui	$v1,%hi(g_Stages)
/*  f166aa8:	2463fcc0 */ 	addiu	$v1,$v1,%lo(g_Stages)
/*  f166aac:	e4800000 */ 	swc1	$f0,0x0($a0)
/*  f166ab0:	e4800014 */ 	swc1	$f0,0x14($a0)
/*  f166ab4:	e4800028 */ 	swc1	$f0,0x28($a0)
/*  f166ab8:	846e05e8 */ 	lh	$t6,0x5e8($v1)
/*  f166abc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f166ac0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f166ac4:	104e000a */ 	beq	$v0,$t6,.L0f166af0
/*  f166ac8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f166acc:	846f0738 */ 	lh	$t7,0x738($v1)
/*  f166ad0:	104f0007 */ 	beq	$v0,$t7,.L0f166af0
/*  f166ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ad8:	84780118 */ 	lh	$t8,0x118($v1)
/*  f166adc:	10580004 */ 	beq	$v0,$t8,.L0f166af0
/*  f166ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ae4:	84790000 */ 	lh	$t9,0x0($v1)
/*  f166ae8:	54590004 */ 	bnel	$v0,$t9,.L0f166afc
/*  f166aec:	846804d0 */ 	lh	$t0,0x4d0($v1)
.L0f166af0:
/*  f166af0:	10a1001d */ 	beq	$a1,$at,.L0f166b68
/*  f166af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166af8:	846804d0 */ 	lh	$t0,0x4d0($v1)
.L0f166afc:
/*  f166afc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f166b00:	10480004 */ 	beq	$v0,$t0,.L0f166b14
/*  f166b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b08:	84690070 */ 	lh	$t1,0x70($v1)
/*  f166b0c:	54490004 */ 	bnel	$v0,$t1,.L0f166b20
/*  f166b10:	846a0620 */ 	lh	$t2,0x620($v1)
.L0f166b14:
/*  f166b14:	10a10014 */ 	beq	$a1,$at,.L0f166b68
/*  f166b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b1c:	846a0620 */ 	lh	$t2,0x620($v1)
.L0f166b20:
/*  f166b20:	24010001 */ 	addiu	$at,$zero,0x1
/*  f166b24:	104a0007 */ 	beq	$v0,$t2,.L0f166b44
/*  f166b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b2c:	846b0310 */ 	lh	$t3,0x310($v1)
/*  f166b30:	104b0004 */ 	beq	$v0,$t3,.L0f166b44
/*  f166b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b38:	846c07a8 */ 	lh	$t4,0x7a8($v1)
/*  f166b3c:	544c0004 */ 	bnel	$v0,$t4,.L0f166b50
/*  f166b40:	846d0700 */ 	lh	$t5,0x700($v1)
.L0f166b44:
/*  f166b44:	10a10008 */ 	beq	$a1,$at,.L0f166b68
/*  f166b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b4c:	846d0700 */ 	lh	$t5,0x700($v1)
.L0f166b50:
/*  f166b50:	3c03800a */ 	lui	$v1,%hi(var800a4cc4)
/*  f166b54:	24010071 */ 	addiu	$at,$zero,0x71
/*  f166b58:	144d0015 */ 	bne	$v0,$t5,.L0f166bb0
/*  f166b5c:	24634cc4 */ 	addiu	$v1,$v1,%lo(var800a4cc4)
/*  f166b60:	54a10014 */ 	bnel	$a1,$at,.L0f166bb4
/*  f166b64:	8c6a0000 */ 	lw	$t2,0x0($v1)
.L0f166b68:
/*  f166b68:	3c03800a */ 	lui	$v1,%hi(var800a4cc4)
/*  f166b6c:	24634cc4 */ 	addiu	$v1,$v1,%lo(var800a4cc4)
/*  f166b70:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f166b74:	00051080 */ 	sll	$v0,$a1,0x2
/*  f166b78:	00451021 */ 	addu	$v0,$v0,$a1
/*  f166b7c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f166b80:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f166b84:	c5e40004 */ 	lwc1	$f4,0x4($t7)
/*  f166b88:	e4840030 */ 	swc1	$f4,0x30($a0)
/*  f166b8c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f166b90:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f166b94:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f166b98:	e4860034 */ 	swc1	$f6,0x34($a0)
/*  f166b9c:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f166ba0:	01024821 */ 	addu	$t1,$t0,$v0
/*  f166ba4:	c528000c */ 	lwc1	$f8,0xc($t1)
/*  f166ba8:	10000019 */ 	beqz	$zero,.L0f166c10
/*  f166bac:	e4880038 */ 	swc1	$f8,0x38($a0)
.L0f166bb0:
/*  f166bb0:	8c6a0000 */ 	lw	$t2,0x0($v1)
.L0f166bb4:
/*  f166bb4:	00051080 */ 	sll	$v0,$a1,0x2
/*  f166bb8:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f166bbc:	00451021 */ 	addu	$v0,$v0,$a1
/*  f166bc0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f166bc4:	01425821 */ 	addu	$t3,$t2,$v0
/*  f166bc8:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f166bcc:	c5900038 */ 	lwc1	$f16,0x38($t4)
/*  f166bd0:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f166bd4:	e4920030 */ 	swc1	$f18,0x30($a0)
/*  f166bd8:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f166bdc:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f166be0:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f166be4:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f166be8:	c5e6003c */ 	lwc1	$f6,0x3c($t7)
/*  f166bec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f166bf0:	e4880034 */ 	swc1	$f8,0x34($a0)
/*  f166bf4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f166bf8:	8cc80284 */ 	lw	$t0,0x284($a2)
/*  f166bfc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f166c00:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f166c04:	c5100040 */ 	lwc1	$f16,0x40($t0)
/*  f166c08:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f166c0c:	e4920038 */ 	swc1	$f18,0x38($a0)
.L0f166c10:
/*  f166c10:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f166c14:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f166c18:	03e00008 */ 	jr	$ra
/*  f166c1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f166c20
/*  f166c20:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f166c24:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f166c28:	3c0e800a */ 	lui	$t6,0x800a
/*  f166c2c:	8dce4928 */ 	lw	$t6,0x4928($t6)
/*  f166c30:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f166c34:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f166c38:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f166c3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f166c40:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f166c44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f166c48:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f166c4c:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f166c50:	87300010 */ 	lh	$s0,0x10($t9)
/*  f166c54:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f166c58:	3c08800a */ 	lui	$t0,0x800a
/*  f166c5c:	12020015 */ 	beq	$s0,$v0,.L0f166cb4
/*  f166c60:	3c0a800a */ 	lui	$t2,0x800a
/*  f166c64:	8d4a6668 */ 	lw	$t2,0x6668($t2)
/*  f166c68:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f166c6c:	00105840 */ 	sll	$t3,$s0,0x1
/*  f166c70:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f166c74:	858d0000 */ 	lh	$t5,0x0($t4)
/*  f166c78:	8d091700 */ 	lw	$t1,0x1700($t0)
/*  f166c7c:	3c0f800a */ 	lui	$t7,0x800a
/*  f166c80:	00107080 */ 	sll	$t6,$s0,0x2
/*  f166c84:	152d000b */ 	bne	$t1,$t5,.L0f166cb4
/*  f166c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166c8c:	8def666c */ 	lw	$t7,0x666c($t7)
/*  f166c90:	3c018006 */ 	lui	$at,0x8006
/*  f166c94:	c426ef10 */ 	lwc1	$f6,-0x10f0($at)
/*  f166c98:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f166c9c:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f166ca0:	3c0a800a */ 	lui	$t2,0x800a
/*  f166ca4:	46062032 */ 	c.eq.s	$f4,$f6
/*  f166ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166cac:	45010012 */ 	bc1t	.L0f166cf8
/*  f166cb0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f166cb4:
/*  f166cb4:	12020003 */ 	beq	$s0,$v0,.L0f166cc4
/*  f166cb8:	02002025 */ 	or	$a0,$s0,$zero
/*  f166cbc:	0fc59a4b */ 	jal	func0f16692c
/*  f166cc0:	8fa50068 */ 	lw	$a1,0x68($sp)
.L0f166cc4:
/*  f166cc4:	0fc59a7f */ 	jal	func0f1669fc
/*  f166cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ccc:	00408025 */ 	or	$s0,$v0,$zero
/*  f166cd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f166cd4:	0fc59a3c */ 	jal	func0f1668f0
/*  f166cd8:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f166cdc:	3c19800a */ 	lui	$t9,0x800a
/*  f166ce0:	8f396660 */ 	lw	$t9,0x6660($t9)
/*  f166ce4:	3c0c800a */ 	lui	$t4,0x800a
/*  f166ce8:	3c0d800a */ 	lui	$t5,0x800a
/*  f166cec:	03304021 */ 	addu	$t0,$t9,$s0
/*  f166cf0:	10000006 */ 	beqz	$zero,.L0f166d0c
/*  f166cf4:	a1000000 */ 	sb	$zero,0x0($t0)
.L0f166cf8:
/*  f166cf8:	8d4a6660 */ 	lw	$t2,0x6660($t2)
/*  f166cfc:	02001025 */ 	or	$v0,$s0,$zero
/*  f166d00:	01505821 */ 	addu	$t3,$t2,$s0
/*  f166d04:	10000018 */ 	beqz	$zero,.L0f166d68
/*  f166d08:	a1600000 */ 	sb	$zero,0x0($t3)
.L0f166d0c:
/*  f166d0c:	8d8ca244 */ 	lw	$t4,-0x5dbc($t4)
/*  f166d10:	8dad6668 */ 	lw	$t5,0x6668($t5)
/*  f166d14:	00107840 */ 	sll	$t7,$s0,0x1
/*  f166d18:	8d891700 */ 	lw	$t1,0x1700($t4)
/*  f166d1c:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f166d20:	3c18800a */ 	lui	$t8,0x800a
/*  f166d24:	a5c90000 */ 	sh	$t1,0x0($t6)
/*  f166d28:	8f18666c */ 	lw	$t8,0x666c($t8)
/*  f166d2c:	3c018006 */ 	lui	$at,0x8006
/*  f166d30:	c428ef10 */ 	lwc1	$f8,-0x10f0($at)
/*  f166d34:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f166d38:	03194021 */ 	addu	$t0,$t8,$t9
/*  f166d3c:	e5080000 */ 	swc1	$f8,0x0($t0)
/*  f166d40:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f166d44:	0fc59a9b */ 	jal	func0f166a6c
/*  f166d48:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f166d4c:	3c0b800a */ 	lui	$t3,0x800a
/*  f166d50:	8d6b6670 */ 	lw	$t3,0x6670($t3)
/*  f166d54:	00105180 */ 	sll	$t2,$s0,0x6
/*  f166d58:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f166d5c:	0c005815 */ 	jal	func00016054
/*  f166d60:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f166d64:	02001025 */ 	or	$v0,$s0,$zero
.L0f166d68:
/*  f166d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f166d6c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f166d70:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f166d74:	03e00008 */ 	jr	$ra
/*  f166d78:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f166d7c
/*  f166d7c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f166d80:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166d84:	00803025 */ 	or	$a2,$a0,$zero
/*  f166d88:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f166d8c:	0fc59b08 */ 	jal	func0f166c20
/*  f166d90:	00a02025 */ 	or	$a0,$a1,$zero
/*  f166d94:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f166d98:	3c0e0102 */ 	lui	$t6,0x102
/*  f166d9c:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f166da0:	3c18800a */ 	lui	$t8,0x800a
/*  f166da4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f166da8:	8f186670 */ 	lw	$t8,0x6670($t8)
/*  f166dac:	00027980 */ 	sll	$t7,$v0,0x6
/*  f166db0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f166db4:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f166db8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f166dbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f166dc0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f166dc4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f166dc8:	03e00008 */ 	jr	$ra
/*  f166dcc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f166dd0
/*  f166dd0:	3c0f800a */ 	lui	$t7,0x800a
/*  f166dd4:	8def4cc4 */ 	lw	$t7,0x4cc4($t7)
/*  f166dd8:	00047080 */ 	sll	$t6,$a0,0x2
/*  f166ddc:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f166de0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f166de4:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f166de8:	03e00008 */ 	jr	$ra
/*  f166dec:	24420004 */ 	addiu	$v0,$v0,0x4
);

GLOBAL_ASM(
glabel func0f166df0
/*  f166df0:	3c03800a */ 	lui	$v1,%hi(var800a4cc4)
/*  f166df4:	24634cc4 */ 	addiu	$v1,$v1,%lo(var800a4cc4)
/*  f166df8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f166dfc:	00041080 */ 	sll	$v0,$a0,0x2
/*  f166e00:	00441021 */ 	addu	$v0,$v0,$a0
/*  f166e04:	00021080 */ 	sll	$v0,$v0,0x2
/*  f166e08:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f166e0c:	c5e40004 */ 	lwc1	$f4,0x4($t7)
/*  f166e10:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f166e14:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f166e18:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f166e1c:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f166e20:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f166e24:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f166e28:	01024821 */ 	addu	$t1,$t0,$v0
/*  f166e2c:	c528000c */ 	lwc1	$f8,0xc($t1)
/*  f166e30:	03e00008 */ 	jr	$ra
/*  f166e34:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f166e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e3c:	00000000 */ 	sll	$zero,$zero,0x0
);
