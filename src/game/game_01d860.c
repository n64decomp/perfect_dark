#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_1668e0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f01d860
/*  f01d860:	3c0e8008 */ 	lui	$t6,0x8008
/*  f01d864:	8dce4120 */ 	lw	$t6,0x4120($t6)
/*  f01d868:	00001825 */ 	or	$v1,$zero,$zero
/*  f01d86c:	240600f8 */ 	addiu	$a2,$zero,0xf8
/*  f01d870:	11c00011 */ 	beqz	$t6,.L0f01d8b8
/*  f01d874:	3c05800b */ 	lui	$a1,%hi(var800aabb8)
/*  f01d878:	24a5abb8 */ 	addiu	$a1,$a1,%lo(var800aabb8)
/*  f01d87c:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f01d880:
/*  f01d880:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f01d884:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f01d888:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f01d88c:	0004c382 */ 	srl	$t8,$a0,0xe
/*  f01d890:	13000007 */ 	beqz	$t8,.L0f01d8b0
/*  f01d894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d898:	904a0000 */ 	lbu	$t2,0x0($v0)
/*  f01d89c:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f01d8a0:	00194980 */ 	sll	$t1,$t9,0x6
/*  f01d8a4:	314bff3f */ 	andi	$t3,$t2,0xff3f
/*  f01d8a8:	012b6025 */ 	or	$t4,$t1,$t3
/*  f01d8ac:	a04c0000 */ 	sb	$t4,0x0($v0)
.L0f01d8b0:
/*  f01d8b0:	5466fff3 */ 	bnel	$v1,$a2,.L0f01d880
/*  f01d8b4:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f01d8b8:
/*  f01d8b8:	03e00008 */ 	jr	$ra
/*  f01d8bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01d8c0
/*  f01d8c0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f01d8c4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f01d8c8:	3c148008 */ 	lui	$s4,%hi(var80082050)
/*  f01d8cc:	26942050 */ 	addiu	$s4,$s4,%lo(var80082050)
/*  f01d8d0:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f01d8d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f01d8d8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f01d8dc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f01d8e0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f01d8e4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f01d8e8:	19c0001e */ 	blez	$t6,.L0f01d964
/*  f01d8ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f01d8f0:	3c13800a */ 	lui	$s3,%hi(var800a6668)
/*  f01d8f4:	3c12800a */ 	lui	$s2,%hi(var800a6660)
/*  f01d8f8:	26526660 */ 	addiu	$s2,$s2,%lo(var800a6660)
/*  f01d8fc:	26736668 */ 	addiu	$s3,$s3,%lo(var800a6668)
/*  f01d900:	00008825 */ 	or	$s1,$zero,$zero
/*  f01d904:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f01d908:
/*  f01d908:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f01d90c:	87190000 */ 	lh	$t9,0x0($t8)
/*  f01d910:	0722000f */ 	bltzl	$t9,.L0f01d950
/*  f01d914:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f01d918:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f01d91c:	01101021 */ 	addu	$v0,$t0,$s0
/*  f01d920:	90490000 */ 	lbu	$t1,0x0($v0)
/*  f01d924:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f01d928:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f01d92c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f01d930:	01706021 */ 	addu	$t4,$t3,$s0
/*  f01d934:	918d0000 */ 	lbu	$t5,0x0($t4)
/*  f01d938:	29a10002 */ 	slti	$at,$t5,0x2
/*  f01d93c:	54200004 */ 	bnezl	$at,.L0f01d950
/*  f01d940:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f01d944:	0fc59a5b */ 	jal	func0f16696c
/*  f01d948:	02002025 */ 	or	$a0,$s0,$zero
/*  f01d94c:	8e8e0000 */ 	lw	$t6,0x0($s4)
.L0f01d950:
/*  f01d950:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f01d954:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f01d958:	020e082a */ 	slt	$at,$s0,$t6
/*  f01d95c:	5420ffea */ 	bnezl	$at,.L0f01d908
/*  f01d960:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f01d964:
/*  f01d964:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f01d968:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01d96c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f01d970:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f01d974:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f01d978:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f01d97c:	03e00008 */ 	jr	$ra
/*  f01d980:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f01d984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d98c:	00000000 */ 	sll	$zero,$zero,0x0
);
