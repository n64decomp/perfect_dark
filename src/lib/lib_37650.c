#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_37650.h"
#include "lib/lib_3c4d0.h"
#include "data.h"
#include "types.h"

// This bss belongs in lib_37b00 but is here due to reordering issues
u32 var8009c390;
u32 var8009c394;
u32 var8009c398;
u32 var8009c39c;
u32 var8009c3a0;
u32 var8009c3a4;
u32 var8009c3a8;
u32 var8009c3ac;
u32 var8009c3b0;
u32 var8009c3b4;
u32 var8009c3b8;
u32 var8009c3bc;
u32 var8009c3c0;
u32 var8009c3c4;
u32 var8009c3c8;
u32 var8009c3cc;
u32 var8009c3d0;
u32 var8009c3d4;
u32 var8009c3d8;
u32 var8009c3dc;

GLOBAL_ASM(
glabel func00037650
/*    37650:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    37654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37658:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3765c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    37660:	240e000e */ 	addiu	$t6,$zero,0xe
/*    37664:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    37668:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3766c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    37670:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    37674:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    37678:	00003025 */ 	or	$a2,$zero,$zero
/*    3767c:	00003825 */ 	or	$a3,$zero,$zero
/*    37680:	0c00f184 */ 	jal	alEvtqPostEvent
/*    37684:	24840048 */ 	addiu	$a0,$a0,0x48
/*    37688:	10000001 */ 	b	.L00037690
/*    3768c:	00000000 */ 	nop
.L00037690:
/*    37690:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37694:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    37698:	03e00008 */ 	jr	$ra
/*    3769c:	00000000 */ 	nop
);
