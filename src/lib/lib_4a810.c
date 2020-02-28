#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_488e0.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4ad80.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4e470.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004a810
/*    4a810:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a814:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a818:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4a81c:	3c018006 */ 	lui	$at,0x8006
/*    4a820:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a824:	3c05800a */ 	lui	$a1,%hi(var8009c7c0)
/*    4a828:	ac2e0950 */ 	sw	$t6,0x950($at)
/*    4a82c:	24a5c7c0 */ 	addiu	$a1,$a1,%lo(var8009c7c0)
/*    4a830:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a834:	0c0120d0 */ 	jal	func00048340
/*    4a838:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a83c:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a840:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a844:	00002825 */ 	or	$a1,$zero,$zero
/*    4a848:	0c012238 */ 	jal	func000488e0
/*    4a84c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a850:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a854:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a858:	03e00008 */ 	jr	$ra
/*    4a85c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004a860
/*    4a860:	3c0e8006 */ 	lui	$t6,0x8006
/*    4a864:	8dce0950 */ 	lw	$t6,0x950($t6)
/*    4a868:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4a86c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a870:	15c00003 */ 	bnez	$t6,.L0004a880
/*    4a874:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a878:	0c012a04 */ 	jal	func0004a810
/*    4a87c:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a880:
/*    4a880:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a884:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a888:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    4a88c:	0c0121bc */ 	jal	func000486f0
/*    4a890:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a894:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a898:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4a89c:	03e00008 */ 	jr	$ra
/*    4a8a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004a8a4
/*    4a8a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a8a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a8ac:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a8b0:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a8b4:	00002825 */ 	or	$a1,$zero,$zero
/*    4a8b8:	0c012238 */ 	jal	func000488e0
/*    4a8bc:	00003025 */ 	or	$a2,$zero,$zero
/*    4a8c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a8c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a8c8:	03e00008 */ 	jr	$ra
/*    4a8cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004a8d0
/*    4a8d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a8d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a8d8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4a8dc:	3c0ea480 */ 	lui	$t6,0xa480
/*    4a8e0:	8dcf0018 */ 	lw	$t7,0x18($t6)
/*    4a8e4:	00803025 */ 	or	$a2,$a0,$zero
/*    4a8e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    4a8ec:	31f80003 */ 	andi	$t8,$t7,0x3
/*    4a8f0:	13000003 */ 	beqz	$t8,.L0004a900
/*    4a8f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a8f8:	1000001c */ 	beqz	$zero,.L0004a96c
/*    4a8fc:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004a900:
/*    4a900:	14c10005 */ 	bne	$a2,$at,.L0004a918
/*    4a904:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a908:	24050040 */ 	addiu	$a1,$zero,0x40
/*    4a90c:	0c012b60 */ 	jal	func0004ad80
/*    4a910:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4a914:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0004a918:
/*    4a918:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a91c:	0c012d20 */ 	jal	func0004b480
/*    4a920:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4a924:	8fa60018 */ 	lw	$a2,0x18($sp)
/*    4a928:	3c19a480 */ 	lui	$t9,0xa480
/*    4a92c:	af220000 */ 	sw	$v0,0x0($t9)
/*    4a930:	14c00006 */ 	bnez	$a2,.L0004a94c
/*    4a934:	3c0a1fc0 */ 	lui	$t2,0x1fc0
/*    4a938:	3c081fc0 */ 	lui	$t0,0x1fc0
/*    4a93c:	350807c0 */ 	ori	$t0,$t0,0x7c0
/*    4a940:	3c09a480 */ 	lui	$t1,0xa480
/*    4a944:	10000004 */ 	beqz	$zero,.L0004a958
/*    4a948:	ad280004 */ 	sw	$t0,0x4($t1)
.L0004a94c:
/*    4a94c:	354a07c0 */ 	ori	$t2,$t2,0x7c0
/*    4a950:	3c0ba480 */ 	lui	$t3,0xa480
/*    4a954:	ad6a0010 */ 	sw	$t2,0x10($t3)
.L0004a958:
/*    4a958:	14c00003 */ 	bnez	$a2,.L0004a968
/*    4a95c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a960:	0c013920 */ 	jal	func0004e480
/*    4a964:	24050040 */ 	addiu	$a1,$zero,0x40
.L0004a968:
/*    4a968:	00001025 */ 	or	$v0,$zero,$zero
.L0004a96c:
/*    4a96c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a970:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a974:	03e00008 */ 	jr	$ra
/*    4a978:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a97c:	00000000 */ 	sll	$zero,$zero,0x0
);