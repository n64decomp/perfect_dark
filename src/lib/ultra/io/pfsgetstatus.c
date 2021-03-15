#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

void __osPfsRequestOneChannel(int channel, int cmd);
void __osPfsGetOneChannelData(int channel, OSContStatus *data);

s32 __osPfsGetStatus(OSMesgQueue *queue, int channel)
{
	s32 ret;
	OSMesg dummy;
	OSContStatus data;

	ret = 0;
	var80060984 = 0xfa;

	__osPfsRequestOneChannel(channel, CONT_CMD_REQUEST_STATUS);
	ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
	osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
	ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
	osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
	__osPfsGetOneChannelData(channel, &data);

	if ((data.status & CONT_CARD_ON) && (data.status & CONT_CARD_PULL)) {
		return PFS_ERR_NEW_PACK;
	}

	if (data.errno != 0 || (data.status & CONT_CARD_ON) == 0) {
		return PFS_ERR_NOPACK;
	}

	if (data.status & CONT_ADDR_CRC_ER) {
		return PFS_ERR_CONTRFAIL;
	}

	return ret;
}

GLOBAL_ASM(
glabel __osPfsRequestOneChannel
/*    4bb60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4bb64:	3c068009 */ 	lui	$a2,%hi(__osPfsPifRam)
/*    4bb68:	240700fe */ 	addiu	$a3,$zero,0xfe
/*    4bb6c:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4bb70:	24c20a20 */ 	addiu	$v0,$a2,%lo(__osPfsPifRam)
/*    4bb74:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4bb78:	a027c820 */ 	sb	$a3,%lo(__osContLastCmd)($at)
/*    4bb7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4bb80:	ac4f003c */ 	sw	$t7,0x3c($v0)
/*    4bb84:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4bb88:	24190003 */ 	addiu	$t9,$zero,0x3
/*    4bb8c:	240800ff */ 	addiu	$t0,$zero,0xff
/*    4bb90:	240900ff */ 	addiu	$t1,$zero,0xff
/*    4bb94:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    4bb98:	a3b8000c */ 	sb	$t8,0xc($sp)
/*    4bb9c:	a3b9000d */ 	sb	$t9,0xd($sp)
/*    4bba0:	a3a5000e */ 	sb	$a1,0xe($sp)
/*    4bba4:	a3a8000f */ 	sb	$t0,0xf($sp)
/*    4bba8:	a3a90010 */ 	sb	$t1,0x10($sp)
/*    4bbac:	a3aa0011 */ 	sb	$t2,0x11($sp)
/*    4bbb0:	18800010 */ 	blez	$a0,.L0004bbf4
/*    4bbb4:	00001825 */ 	or	$v1,$zero,$zero
/*    4bbb8:	30860003 */ 	andi	$a2,$a0,0x3
/*    4bbbc:	10c00006 */ 	beqz	$a2,.L0004bbd8
/*    4bbc0:	00c02825 */ 	or	$a1,$a2,$zero
.L0004bbc4:
/*    4bbc4:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4bbc8:	a0400000 */ 	sb	$zero,0x0($v0)
/*    4bbcc:	14a3fffd */ 	bne	$a1,$v1,.L0004bbc4
/*    4bbd0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4bbd4:	10640007 */ 	beq	$v1,$a0,.L0004bbf4
.L0004bbd8:
/*    4bbd8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4bbdc:	a0400001 */ 	sb	$zero,0x1($v0)
/*    4bbe0:	a0400002 */ 	sb	$zero,0x2($v0)
/*    4bbe4:	a0400003 */ 	sb	$zero,0x3($v0)
/*    4bbe8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4bbec:	1464fffa */ 	bne	$v1,$a0,.L0004bbd8
/*    4bbf0:	a040fffc */ 	sb	$zero,-0x4($v0)
.L0004bbf4:
/*    4bbf4:	27ab000c */ 	addiu	$t3,$sp,0xc
/*    4bbf8:	8d610000 */ 	lw	$at,0x0($t3)
/*    4bbfc:	24420006 */ 	addiu	$v0,$v0,0x6
/*    4bc00:	a841fffa */ 	swl	$at,-0x6($v0)
/*    4bc04:	b841fffd */ 	swr	$at,-0x3($v0)
/*    4bc08:	91610004 */ 	lbu	$at,0x4($t3)
/*    4bc0c:	a041fffe */ 	sb	$at,-0x2($v0)
/*    4bc10:	916d0005 */ 	lbu	$t5,0x5($t3)
/*    4bc14:	a0470000 */ 	sb	$a3,0x0($v0)
/*    4bc18:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4bc1c:	03e00008 */ 	jr	$ra
/*    4bc20:	a04dffff */ 	sb	$t5,-0x1($v0)
);

void __osPfsGetOneChannelData(int channel, OSContStatus *data)
{
	u8 *ptr;
	__OSContRequestFormatShort requestformat;
	int i;

	ptr = (u8*)&__osPfsPifRam;

    for (i = 0; i < channel; i++) {
        ptr++;
	}

	requestformat = *(__OSContRequestFormatShort *)ptr;
	data->errno = CHNL_ERR(requestformat);

	if (data->errno == 0) {
		data->type = (requestformat.typel << 8) | (requestformat.typeh);
		data->status = requestformat.status;
	}
}
