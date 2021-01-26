#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

GLOBAL_ASM(
glabel __osSiCreateAccessQueue
/*    4a810:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a814:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a818:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4a81c:	3c018006 */ 	lui	$at,%hi(__osSiAccessQueueEnabled)
/*    4a820:	3c04800a */ 	lui	$a0,%hi(__osSiAccessQueue)
/*    4a824:	3c05800a */ 	lui	$a1,%hi(var8009c7c0)
/*    4a828:	ac2e0950 */ 	sw	$t6,%lo(__osSiAccessQueueEnabled)($at)
/*    4a82c:	24a5c7c0 */ 	addiu	$a1,$a1,%lo(var8009c7c0)
/*    4a830:	2484c7c8 */ 	addiu	$a0,$a0,%lo(__osSiAccessQueue)
/*    4a834:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4a838:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a83c:	3c04800a */ 	lui	$a0,%hi(__osSiAccessQueue)
/*    4a840:	2484c7c8 */ 	addiu	$a0,$a0,%lo(__osSiAccessQueue)
/*    4a844:	00002825 */ 	or	$a1,$zero,$zero
/*    4a848:	0c012238 */ 	jal	osSendMesg
/*    4a84c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a850:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a854:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a858:	03e00008 */ 	jr	$ra
/*    4a85c:	00000000 */ 	nop
);

void __osSiGetAccess(void)
{
	OSMesg dummyMesg;

	if (!__osSiAccessQueueEnabled) {
		__osSiCreateAccessQueue();
	}

	osRecvMesg(&__osSiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void)
{
	osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
