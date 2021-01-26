#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

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

void __osPiGetAccess(void)
{
	OSMesg dummyMesg;

	if (!__osPiAccessQueueEnabled) {
		__osPiCreateAccessQueue();
	}

	osRecvMesg(&__osPiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osPiRelAccess(void)
{
	osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
