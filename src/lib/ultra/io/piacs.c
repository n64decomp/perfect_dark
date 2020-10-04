#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osPiCreateAccessQueue
/*    49a90:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49a94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49a98:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    49a9c:	3c018006 */ 	lui	$at,%hi(__osPiAccessQueueEnabled)
/*    49aa0:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    49aa4:	3c05800a */ 	lui	$a1,%hi(var8009c7a0)
/*    49aa8:	ac2e0920 */ 	sw	$t6,%lo(__osPiAccessQueueEnabled)($at)
/*    49aac:	24a5c7a0 */ 	addiu	$a1,$a1,%lo(var8009c7a0)
/*    49ab0:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    49ab4:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    49ab8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    49abc:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    49ac0:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    49ac4:	00002825 */ 	or	$a1,$zero,$zero
/*    49ac8:	0c012238 */ 	jal	osSendMesg
/*    49acc:	00003025 */ 	or	$a2,$zero,$zero
/*    49ad0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49ad4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49ad8:	03e00008 */ 	jr	$ra
/*    49adc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osPiGetAccess
/*    49ae0:	3c0e8006 */ 	lui	$t6,%hi(__osPiAccessQueueEnabled)
/*    49ae4:	8dce0920 */ 	lw	$t6,%lo(__osPiAccessQueueEnabled)($t6)
/*    49ae8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    49aec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49af0:	15c00003 */ 	bnez	$t6,.L00049b00
/*    49af4:	00000000 */ 	nop
/*    49af8:	0c0126a4 */ 	jal	__osPiCreateAccessQueue
/*    49afc:	00000000 */ 	nop
.L00049b00:
/*    49b00:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    49b04:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    49b08:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    49b0c:	0c0121bc */ 	jal	osRecvMesg
/*    49b10:	24060001 */ 	addiu	$a2,$zero,0x1
/*    49b14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49b18:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    49b1c:	03e00008 */ 	jr	$ra
/*    49b20:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osPiRelAccess
/*    49b24:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49b28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49b2c:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    49b30:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    49b34:	00002825 */ 	or	$a1,$zero,$zero
/*    49b38:	0c012238 */ 	jal	osSendMesg
/*    49b3c:	00003025 */ 	or	$a2,$zero,$zero
/*    49b40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49b44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49b48:	03e00008 */ 	jr	$ra
/*    49b4c:	00000000 */ 	nop
);
