#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

OSPifRam __osPfsPifRam;

GLOBAL_ASM(
glabel osPfsIsPlug
/*     5770:	27bdff90 */ 	addiu	$sp,$sp,-112
/*     5774:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     5778:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     577c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     5780:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     5784:	00809025 */ 	or	$s2,$a0,$zero
/*     5788:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     578c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     5790:	afb60030 */ 	sw	$s6,0x30($sp)
/*     5794:	afb40028 */ 	sw	$s4,0x28($sp)
/*     5798:	afb30024 */ 	sw	$s3,0x24($sp)
/*     579c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     57a0:	afa50074 */ 	sw	$a1,0x74($sp)
/*     57a4:	0000a825 */ 	or	$s5,$zero,$zero
/*     57a8:	0c012a18 */ 	jal	__osSiGetAccess
/*     57ac:	24110001 */ 	addiu	$s1,$zero,0x1
/*     57b0:	3c1e800a */ 	lui	$s8,%hi(__osContLastCmd+0x1)
/*     57b4:	3c138009 */ 	lui	$s3,%hi(__osPfsPifRam)
/*     57b8:	26730a20 */ 	addiu	$s3,$s3,%lo(__osPfsPifRam)
/*     57bc:	27dec821 */ 	addiu	$s8,$s8,%lo(__osContLastCmd+0x1)
/*     57c0:	00008025 */ 	or	$s0,$zero,$zero
/*     57c4:	27b70054 */ 	addiu	$s7,$sp,0x54
/*     57c8:	27b60067 */ 	addiu	$s6,$sp,0x67
/*     57cc:	27b40068 */ 	addiu	$s4,$sp,0x68
.L000057d0:
/*     57d0:	0c00163f */ 	jal	__osPfsRequestData
/*     57d4:	00002025 */ 	or	$a0,$zero,$zero
/*     57d8:	24040001 */ 	addiu	$a0,$zero,0x1
/*     57dc:	0c012a34 */ 	jal	__osSiRawStartDma
/*     57e0:	02602825 */ 	or	$a1,$s3,$zero
/*     57e4:	02402025 */ 	or	$a0,$s2,$zero
/*     57e8:	02802825 */ 	or	$a1,$s4,$zero
/*     57ec:	0c0121bc */ 	jal	osRecvMesg
/*     57f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*     57f4:	00002025 */ 	or	$a0,$zero,$zero
/*     57f8:	0c012a34 */ 	jal	__osSiRawStartDma
/*     57fc:	02602825 */ 	or	$a1,$s3,$zero
/*     5800:	afa2006c */ 	sw	$v0,0x6c($sp)
/*     5804:	02402025 */ 	or	$a0,$s2,$zero
/*     5808:	02802825 */ 	or	$a1,$s4,$zero
/*     580c:	0c0121bc */ 	jal	osRecvMesg
/*     5810:	24060001 */ 	addiu	$a2,$zero,0x1
/*     5814:	02c02025 */ 	or	$a0,$s6,$zero
/*     5818:	0c00166c */ 	jal	__osPfsGetInitData
/*     581c:	02e02825 */ 	or	$a1,$s7,$zero
/*     5820:	93c30000 */ 	lbu	$v1,0x0($s8)
/*     5824:	27a20054 */ 	addiu	$v0,$sp,0x54
/*     5828:	5860000c */ 	blezl	$v1,.L0000585c
/*     582c:	02031026 */ 	xor	$v0,$s0,$v1
.L00005830:
/*     5830:	904e0002 */ 	lbu	$t6,0x2($v0)
/*     5834:	31cf0004 */ 	andi	$t7,$t6,0x4
/*     5838:	55e00004 */ 	bnezl	$t7,.L0000584c
/*     583c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     5840:	10000005 */ 	b	.L00005858
/*     5844:	2631ffff */ 	addiu	$s1,$s1,-1
/*     5848:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000584c:
/*     584c:	0203082a */ 	slt	$at,$s0,$v1
/*     5850:	1420fff7 */ 	bnez	$at,.L00005830
/*     5854:	24420004 */ 	addiu	$v0,$v0,0x4
.L00005858:
/*     5858:	02031026 */ 	xor	$v0,$s0,$v1
.L0000585c:
/*     585c:	14400002 */ 	bnez	$v0,.L00005868
/*     5860:	00008025 */ 	or	$s0,$zero,$zero
/*     5864:	00008825 */ 	or	$s1,$zero,$zero
.L00005868:
/*     5868:	1e20ffd9 */ 	bgtz	$s1,.L000057d0
/*     586c:	00000000 */ 	nop
/*     5870:	18600011 */ 	blez	$v1,.L000058b8
/*     5874:	27a20054 */ 	addiu	$v0,$sp,0x54
.L00005878:
/*     5878:	90580003 */ 	lbu	$t8,0x3($v0)
/*     587c:	5700000b */ 	bnezl	$t8,.L000058ac
/*     5880:	26100001 */ 	addiu	$s0,$s0,0x1
/*     5884:	90590002 */ 	lbu	$t9,0x2($v0)
/*     5888:	24090001 */ 	addiu	$t1,$zero,0x1
/*     588c:	02095004 */ 	sllv	$t2,$t1,$s0
/*     5890:	33280001 */ 	andi	$t0,$t9,0x1
/*     5894:	51000005 */ 	beqzl	$t0,.L000058ac
/*     5898:	26100001 */ 	addiu	$s0,$s0,0x1
/*     589c:	02aaa825 */ 	or	$s5,$s5,$t2
/*     58a0:	32ab00ff */ 	andi	$t3,$s5,0xff
/*     58a4:	0160a825 */ 	or	$s5,$t3,$zero
/*     58a8:	26100001 */ 	addiu	$s0,$s0,0x1
.L000058ac:
/*     58ac:	0203082a */ 	slt	$at,$s0,$v1
/*     58b0:	1420fff1 */ 	bnez	$at,.L00005878
/*     58b4:	24420004 */ 	addiu	$v0,$v0,0x4
.L000058b8:
/*     58b8:	0c012a29 */ 	jal	__osSiRelAccess
/*     58bc:	00000000 */ 	nop
/*     58c0:	8fac0074 */ 	lw	$t4,0x74($sp)
/*     58c4:	a1950000 */ 	sb	$s5,0x0($t4)
/*     58c8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     58cc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     58d0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     58d4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     58d8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     58dc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     58e0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     58e4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     58e8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     58ec:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     58f0:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*     58f4:	03e00008 */ 	jr	$ra
/*     58f8:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

void __osPfsRequestData(u8 cmd)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;
	ptr = (u8 *)&__osPfsPifRam;
	__osContLastCmd = cmd;
	__osPfsPifRam.pifstatus = CONT_CMD_EXE;

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

	*ptr = CONT_CMD_END;
}

void __osPfsGetInitData(u8 *pattern, OSContStatus *data)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;
	u8 bits;
	bits = 0;
	ptr = (u8 *)&__osPfsPifRam;

	for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(__OSContRequestFormat)) {
		requestformat = *(__OSContRequestFormat *)ptr;
		data->errno = CHNL_ERR(requestformat);

		if (data->errno == 0) {
			data->type = (requestformat.typel << 8) | (requestformat.typeh);
			data->status = requestformat.status;
			bits |= 1 << i;
		}

		data++;
	}

	*pattern = bits;
}
