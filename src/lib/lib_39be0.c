#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00039be0
/*    39be0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    39be4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    39be8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    39bec:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    39bf0:	240e000d */ 	addiu	$t6,$zero,0xd
/*    39bf4:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    39bf8:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    39bfc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    39c00:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    39c04:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    39c08:	00003025 */ 	or	$a2,$zero,$zero
/*    39c0c:	00003825 */ 	or	$a3,$zero,$zero
/*    39c10:	0c00f184 */ 	jal	alEvtqPostEvent
/*    39c14:	24840048 */ 	addiu	$a0,$a0,0x48
/*    39c18:	10000001 */ 	b	.L00039c20
/*    39c1c:	00000000 */ 	nop
.L00039c20:
/*    39c20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    39c24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    39c28:	03e00008 */ 	jr	$ra
/*    39c2c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00039c30
/*    39c30:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    39c34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    39c38:	afa40028 */ 	sw	$a0,0x28($sp)
/*    39c3c:	240e000f */ 	addiu	$t6,$zero,0xf
/*    39c40:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    39c44:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    39c48:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    39c4c:	00003025 */ 	or	$a2,$zero,$zero
/*    39c50:	00003825 */ 	or	$a3,$zero,$zero
/*    39c54:	0c00f184 */ 	jal	alEvtqPostEvent
/*    39c58:	24840048 */ 	addiu	$a0,$a0,0x48
/*    39c5c:	10000001 */ 	b	.L00039c64
/*    39c60:	00000000 */ 	nop
.L00039c64:
/*    39c64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    39c68:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    39c6c:	03e00008 */ 	jr	$ra
/*    39c70:	00000000 */ 	nop
);
