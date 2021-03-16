#include <libultra_internal.h>
#include "data.h"

OSPifRam __osContPifRam;
u8 __osContLastCmd;
u8 __osMaxControllers;
u32 var8009c824;
u32 __osEepromTimer;
u32 var8009c82c;
u32 var8009c830;
u32 var8009c834;
u32 var8009c838;
u32 var8009c83c;
u32 var8009c840;
u32 var8009c844;
u32 __osEepromTimerQ;
u32 var8009c84c;
u32 var8009c850;
u32 var8009c854;
u32 var8009c858;
u32 var8009c85c;
u32 __osEepromTimerMsg;

u32 __osContInitialized = 0;

GLOBAL_ASM(
glabel osContInit
/*    4a980:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    4a984:	3c0e8006 */ 	lui	$t6,%hi(__osContInitialized)
/*    4a988:	8dce0960 */ 	lw	$t6,%lo(__osContInitialized)($t6)
/*    4a98c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4a990:	afa40070 */ 	sw	$a0,0x70($sp)
/*    4a994:	afa50074 */ 	sw	$a1,0x74($sp)
/*    4a998:	afa60078 */ 	sw	$a2,0x78($sp)
/*    4a99c:	11c00003 */ 	beqz	$t6,.L0004a9ac
/*    4a9a0:	afa00068 */ 	sw	$zero,0x68($sp)
/*    4a9a4:	1000004e */ 	b	.L0004aae0
/*    4a9a8:	00001025 */ 	or	$v0,$zero,$zero
.L0004a9ac:
/*    4a9ac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4a9b0:	3c018006 */ 	lui	$at,%hi(__osContInitialized)
/*    4a9b4:	0c012448 */ 	jal	osGetTime
/*    4a9b8:	ac2f0960 */ 	sw	$t7,%lo(__osContInitialized)($at)
/*    4a9bc:	afa20060 */ 	sw	$v0,0x60($sp)
/*    4a9c0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    4a9c4:	afa30064 */ 	sw	$v1,0x64($sp)
/*    4a9c8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*    4a9cc:	17000020 */ 	bnez	$t8,.L0004aa50
/*    4a9d0:	3c010165 */ 	lui	$at,0x165
/*    4a9d4:	3421a0bc */ 	ori	$at,$at,0xa0bc
/*    4a9d8:	0321082b */ 	sltu	$at,$t9,$at
/*    4a9dc:	1020001c */ 	beqz	$at,.L0004aa50
/*    4a9e0:	00000000 */ 	nop
/*    4a9e4:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4a9e8:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a9ec:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4a9f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4a9f4:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    4a9f8:	8fa90064 */ 	lw	$t1,0x64($sp)
/*    4a9fc:	3c0b0165 */ 	lui	$t3,0x165
/*    4aa00:	356ba0bc */ 	ori	$t3,$t3,0xa0bc
/*    4aa04:	240a0000 */ 	addiu	$t2,$zero,0x0
/*    4aa08:	240c0000 */ 	addiu	$t4,$zero,0x0
/*    4aa0c:	240d0000 */ 	addiu	$t5,$zero,0x0
/*    4aa10:	27ae0028 */ 	addiu	$t6,$sp,0x28
/*    4aa14:	27af006c */ 	addiu	$t7,$sp,0x6c
/*    4aa18:	01483023 */ 	subu	$a2,$t2,$t0
/*    4aa1c:	0169082b */ 	sltu	$at,$t3,$t1
/*    4aa20:	00c13023 */ 	subu	$a2,$a2,$at
/*    4aa24:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    4aa28:	afae0018 */ 	sw	$t6,0x18($sp)
/*    4aa2c:	afad0014 */ 	sw	$t5,0x14($sp)
/*    4aa30:	afac0010 */ 	sw	$t4,0x10($sp)
/*    4aa34:	27a40040 */ 	addiu	$a0,$sp,0x40
/*    4aa38:	0c0122c8 */ 	jal	osSetTimer
/*    4aa3c:	01693823 */ 	subu	$a3,$t3,$t1
/*    4aa40:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4aa44:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aa48:	0c0121bc */ 	jal	osRecvMesg
/*    4aa4c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0004aa50:
/*    4aa50:	24180004 */ 	addiu	$t8,$zero,0x4
/*    4aa54:	3c01800a */ 	lui	$at,%hi(__osContLastCmd+0x1)
/*    4aa58:	a038c821 */ 	sb	$t8,%lo(__osContLastCmd+0x1)($at)
/*    4aa5c:	0c012af0 */ 	jal	__osPackRequestData
/*    4aa60:	00002025 */ 	or	$a0,$zero,$zero
/*    4aa64:	3c05800a */ 	lui	$a1,%hi(__osContPifRam)
/*    4aa68:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(__osContPifRam)
/*    4aa6c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4aa70:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4aa74:	afa20068 */ 	sw	$v0,0x68($sp)
/*    4aa78:	8fa40070 */ 	lw	$a0,0x70($sp)
/*    4aa7c:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aa80:	0c0121bc */ 	jal	osRecvMesg
/*    4aa84:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aa88:	3c05800a */ 	lui	$a1,%hi(__osContPifRam)
/*    4aa8c:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(__osContPifRam)
/*    4aa90:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4aa94:	00002025 */ 	or	$a0,$zero,$zero
/*    4aa98:	afa20068 */ 	sw	$v0,0x68($sp)
/*    4aa9c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*    4aaa0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4aaa4:	0c0121bc */ 	jal	osRecvMesg
/*    4aaa8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aaac:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    4aab0:	0c012abc */ 	jal	__osContGetInitData
/*    4aab4:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    4aab8:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4aabc:	0c012a04 */ 	jal	__osSiCreateAccessQueue
/*    4aac0:	a020c820 */ 	sb	$zero,%lo(__osContLastCmd)($at)
/*    4aac4:	3c04800a */ 	lui	$a0,%hi(__osEepromTimerQ)
/*    4aac8:	3c05800a */ 	lui	$a1,%hi(__osEepromTimerMsg)
/*    4aacc:	24a5c860 */ 	addiu	$a1,$a1,%lo(__osEepromTimerMsg)
/*    4aad0:	2484c848 */ 	addiu	$a0,$a0,%lo(__osEepromTimerQ)
/*    4aad4:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    4aad8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4aadc:	8fa20068 */ 	lw	$v0,0x68($sp)
.L0004aae0:
/*    4aae0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4aae4:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*    4aae8:	03e00008 */ 	jr	$ra
/*    4aaec:	00000000 */ 	nop
);

void __osContGetInitData(u8 *pattern, OSContStatus *data)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;
	u8 bits;
	bits = 0;
	ptr = (u8 *)&__osContPifRam;

	for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(__OSContRequestFormat), data++) {
		requestformat = *(__OSContRequestFormat *)ptr;
		data->errno = CHNL_ERR(requestformat);

		if (data->errno == 0) {
			data->type = (requestformat.typel << 8) | requestformat.typeh;
			data->status = requestformat.status;
			bits |= 1 << i;
		}
	}

	*pattern = bits;
}

void __osPackRequestData(u8 cmd)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;

	for (i = 0; i < ARRLEN(__osContPifRam.ramarray); i++) {
		__osContPifRam.ramarray[i] = 0;
	}

	__osContPifRam.pifstatus = CONT_CMD_EXE;

	ptr = (u8 *)&__osContPifRam.ramarray;

	requestformat.dummy = CONT_CMD_NOP;
	requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
	requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
	requestformat.cmd = cmd;
	requestformat.typeh = CONT_CMD_NOP;
	requestformat.typel = CONT_CMD_NOP;
	requestformat.status = CONT_CMD_NOP;
	requestformat.dummy1 = CONT_CMD_NOP;

	for (i = 0; i < __osMaxControllers; i++) {
		*(__OSContRequestFormat *)ptr = requestformat;
		ptr += sizeof(__OSContRequestFormat);
	}

	ptr[0] = CONT_CMD_END;
}
