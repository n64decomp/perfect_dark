#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_096890.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f096890
/*  f096890:	28817fe0 */ 	slti	$at,$a0,0x7fe0
/*  f096894:	14200006 */ 	bnez	$at,.L0f0968b0
/*  f096898:	24030007 */ 	addiu	$v1,$zero,0x7
/*  f09689c:	3c068007 */ 	lui	$a2,%hi(var8006af8c)
/*  f0968a0:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f0968a4:	24c6af8c */ 	addiu	$a2,$a2,%lo(var8006af8c)
/*  f0968a8:	1000000d */ 	beqz	$zero,.L0f0968e0
/*  f0968ac:	24848020 */ 	addiu	$a0,$a0,-32736
.L0f0968b0:
/*  f0968b0:	28817800 */ 	slti	$at,$a0,0x7800
/*  f0968b4:	14200007 */ 	bnez	$at,.L0f0968d4
/*  f0968b8:	240301ff */ 	addiu	$v1,$zero,0x1ff
/*  f0968bc:	3c068007 */ 	lui	$a2,%hi(var8006af0c)
/*  f0968c0:	2403001f */ 	addiu	$v1,$zero,0x1f
/*  f0968c4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0968c8:	24c6af0c */ 	addiu	$a2,$a2,%lo(var8006af0c)
/*  f0968cc:	10000004 */ 	beqz	$zero,.L0f0968e0
/*  f0968d0:	24848800 */ 	addiu	$a0,$a0,-30720
.L0f0968d4:
/*  f0968d4:	3c068007 */ 	lui	$a2,%hi(var8006ae90)
/*  f0968d8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f0968dc:	24c6ae90 */ 	addiu	$a2,$a2,%lo(var8006ae90)
.L0f0968e0:
/*  f0968e0:	00a47007 */ 	srav	$t6,$a0,$a1
/*  f0968e4:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0968e8:	00cf4021 */ 	addu	$t0,$a2,$t7
/*  f0968ec:	95070000 */ 	lhu	$a3,0x0($t0)
/*  f0968f0:	95090002 */ 	lhu	$t1,0x2($t0)
/*  f0968f4:	0083c824 */ 	and	$t9,$a0,$v1
/*  f0968f8:	00e9c023 */ 	subu	$t8,$a3,$t1
/*  f0968fc:	03190019 */ 	multu	$t8,$t9
/*  f096900:	00005012 */ 	mflo	$t2
/*  f096904:	00aa5807 */ 	srav	$t3,$t2,$a1
/*  f096908:	03e00008 */ 	jr	$ra
/*  f09690c:	00eb1023 */ 	subu	$v0,$a3,$t3
);

GLOBAL_ASM(
glabel func0f096910
/*  f096910:	00042c00 */ 	sll	$a1,$a0,0x10
/*  f096914:	00057403 */ 	sra	$t6,$a1,0x10
/*  f096918:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09691c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096920:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f096924:	05c00003 */ 	bltz	$t6,.L0f096934
/*  f096928:	01c02825 */ 	or	$a1,$t6,$zero
/*  f09692c:	10000002 */ 	beqz	$zero,.L0f096938
/*  f096930:	01c02025 */ 	or	$a0,$t6,$zero
.L0f096934:
/*  f096934:	00052023 */ 	negu	$a0,$a1
.L0f096938:
/*  f096938:	0fc25a24 */ 	jal	func0f096890
/*  f09693c:	a7a5001a */ 	sh	$a1,0x1a($sp)
/*  f096940:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f096944:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f096948:	00402025 */ 	or	$a0,$v0,$zero
/*  f09694c:	04a10003 */ 	bgez	$a1,.L0f09695c
/*  f096950:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f096954:	340fffff */ 	dli	$t7,0xffff
/*  f096958:	01e22023 */ 	subu	$a0,$t7,$v0
.L0f09695c:
/*  f09695c:	03e00008 */ 	jr	$ra
/*  f096960:	3082ffff */ 	andi	$v0,$a0,0xffff
);

GLOBAL_ASM(
glabel func0f096964
/*  f096964:	00042c00 */ 	sll	$a1,$a0,0x10
/*  f096968:	00057403 */ 	sra	$t6,$a1,0x10
/*  f09696c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f096970:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096974:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f096978:	05c00003 */ 	bltz	$t6,.L0f096988
/*  f09697c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f096980:	10000002 */ 	beqz	$zero,.L0f09698c
/*  f096984:	01c02025 */ 	or	$a0,$t6,$zero
.L0f096988:
/*  f096988:	00052023 */ 	negu	$a0,$a1
.L0f09698c:
/*  f09698c:	0fc25a24 */ 	jal	func0f096890
/*  f096990:	a7a5001a */ 	sh	$a1,0x1a($sp)
/*  f096994:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f096998:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09699c:	24018000 */ 	addiu	$at,$zero,-32768
/*  f0969a0:	04a00004 */ 	bltz	$a1,.L0f0969b4
/*  f0969a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0969a8:	240f7fff */ 	addiu	$t7,$zero,0x7fff
/*  f0969ac:	10000002 */ 	beqz	$zero,.L0f0969b8
/*  f0969b0:	01e22023 */ 	subu	$a0,$t7,$v0
.L0f0969b4:
/*  f0969b4:	00412021 */ 	addu	$a0,$v0,$at
.L0f0969b8:
/*  f0969b8:	00041400 */ 	sll	$v0,$a0,0x10
/*  f0969bc:	0002c403 */ 	sra	$t8,$v0,0x10
/*  f0969c0:	03e00008 */ 	jr	$ra
/*  f0969c4:	03001025 */ 	or	$v0,$t8,$zero
/*  f0969c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0969cc:	00000000 */ 	sll	$zero,$zero,0x0
);
