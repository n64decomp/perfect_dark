#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSiCreateAccessQueue
/*    4a810:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a814:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a818:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4a81c:	3c018006 */ 	lui	$at,%hi(var80060950)
/*    4a820:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a824:	3c05800a */ 	lui	$a1,%hi(var8009c7c0)
/*    4a828:	ac2e0950 */ 	sw	$t6,%lo(var80060950)($at)
/*    4a82c:	24a5c7c0 */ 	addiu	$a1,$a1,%lo(var8009c7c0)
/*    4a830:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a834:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4a838:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a83c:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a840:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a844:	00002825 */ 	or	$a1,$zero,$zero
/*    4a848:	0c012238 */ 	jal	osSendMesg
/*    4a84c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a850:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a854:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a858:	03e00008 */ 	jr	$ra
/*    4a85c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osSiGetAccess
/*    4a860:	3c0e8006 */ 	lui	$t6,%hi(var80060950)
/*    4a864:	8dce0950 */ 	lw	$t6,%lo(var80060950)($t6)
/*    4a868:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4a86c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a870:	15c00003 */ 	bnez	$t6,.L0004a880
/*    4a874:	00000000 */ 	nop
/*    4a878:	0c012a04 */ 	jal	__osSiCreateAccessQueue
/*    4a87c:	00000000 */ 	nop
.L0004a880:
/*    4a880:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a884:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a888:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    4a88c:	0c0121bc */ 	jal	osRecvMesg
/*    4a890:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a894:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a898:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4a89c:	03e00008 */ 	jr	$ra
/*    4a8a0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osSiRelAccess
/*    4a8a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a8a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a8ac:	3c04800a */ 	lui	$a0,%hi(var8009c7c8)
/*    4a8b0:	2484c7c8 */ 	addiu	$a0,$a0,%lo(var8009c7c8)
/*    4a8b4:	00002825 */ 	or	$a1,$zero,$zero
/*    4a8b8:	0c012238 */ 	jal	osSendMesg
/*    4a8bc:	00003025 */ 	or	$a2,$zero,$zero
/*    4a8c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a8c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a8c8:	03e00008 */ 	jr	$ra
/*    4a8cc:	00000000 */ 	nop
);
