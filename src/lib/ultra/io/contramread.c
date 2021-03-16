#include <libultra_internal.h>
#include "data.h"

u32 var80060970 = 0xffffffff;

GLOBAL_ASM(
glabel __osContRamRead
/*    4b860:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    4b864:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4b868:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4b86c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4b870:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4b874:	00a08825 */ 	or	$s1,$a1,$zero
/*    4b878:	0080b025 */ 	or	$s6,$a0,$zero
/*    4b87c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    4b880:	afb70034 */ 	sw	$s7,0x34($sp)
/*    4b884:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4b888:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4b88c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4b890:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4b894:	afa60068 */ 	sw	$a2,0x68($sp)
/*    4b898:	afa7006c */ 	sw	$a3,0x6c($sp)
/*    4b89c:	0c012a18 */ 	jal	__osSiGetAccess
/*    4b8a0:	24150002 */ 	addiu	$s5,$zero,0x2
/*    4b8a4:	97a5006a */ 	lhu	$a1,0x6a($sp)
/*    4b8a8:	3c1e8006 */ 	lui	$s8,%hi(var80060970)
/*    4b8ac:	3c17800a */ 	lui	$s7,%hi(__osContLastCmd)
/*    4b8b0:	3c148009 */ 	lui	$s4,%hi(__osPfsPifRam)
/*    4b8b4:	000570c3 */ 	sra	$t6,$a1,0x3
/*    4b8b8:	00057940 */ 	sll	$t7,$a1,0x5
/*    4b8bc:	afaf0040 */ 	sw	$t7,0x40($sp)
/*    4b8c0:	afae0044 */ 	sw	$t6,0x44($sp)
/*    4b8c4:	26940a20 */ 	addiu	$s4,$s4,%lo(__osPfsPifRam)
/*    4b8c8:	26f7c820 */ 	addiu	$s7,$s7,%lo(__osContLastCmd)
/*    4b8cc:	27de0970 */ 	addiu	$s8,$s8,%lo(var80060970)
.L0004b8d0:
/*    4b8d0:	92f80000 */ 	lbu	$t8,0x0($s7)
/*    4b8d4:	24010002 */ 	addiu	$at,$zero,0x2
/*    4b8d8:	97a5006a */ 	lhu	$a1,0x6a($sp)
/*    4b8dc:	17010003 */ 	bne	$t8,$at,.L0004b8ec
/*    4b8e0:	02808025 */ 	or	$s0,$s4,$zero
/*    4b8e4:	8fd90000 */ 	lw	$t9,0x0($s8)
/*    4b8e8:	12390023 */ 	beq	$s1,$t9,.L0004b978
.L0004b8ec:
/*    4b8ec:	24080002 */ 	addiu	$t0,$zero,0x2
/*    4b8f0:	a2e80000 */ 	sb	$t0,0x0($s7)
/*    4b8f4:	afd10000 */ 	sw	$s1,0x0($s8)
/*    4b8f8:	1a200010 */ 	blez	$s1,.L0004b93c
/*    4b8fc:	00001025 */ 	or	$v0,$zero,$zero
/*    4b900:	32240003 */ 	andi	$a0,$s1,0x3
/*    4b904:	10800006 */ 	beqz	$a0,.L0004b920
/*    4b908:	00801825 */ 	or	$v1,$a0,$zero
.L0004b90c:
/*    4b90c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4b910:	a2000000 */ 	sb	$zero,0x0($s0)
/*    4b914:	1462fffd */ 	bne	$v1,$v0,.L0004b90c
/*    4b918:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4b91c:	10510007 */ 	beq	$v0,$s1,.L0004b93c
.L0004b920:
/*    4b920:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4b924:	a2000000 */ 	sb	$zero,0x0($s0)
/*    4b928:	a2000001 */ 	sb	$zero,0x1($s0)
/*    4b92c:	a2000002 */ 	sb	$zero,0x2($s0)
/*    4b930:	a2000003 */ 	sb	$zero,0x3($s0)
/*    4b934:	1451fffa */ 	bne	$v0,$s1,.L0004b920
/*    4b938:	26100004 */ 	addiu	$s0,$s0,0x4
.L0004b93c:
/*    4b93c:	24090001 */ 	addiu	$t1,$zero,0x1
/*    4b940:	ae89003c */ 	sw	$t1,0x3c($s4)
/*    4b944:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    4b948:	240b0003 */ 	addiu	$t3,$zero,0x3
/*    4b94c:	240c0021 */ 	addiu	$t4,$zero,0x21
/*    4b950:	240d0002 */ 	addiu	$t5,$zero,0x2
/*    4b954:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4b958:	240f00fe */ 	addiu	$t7,$zero,0xfe
/*    4b95c:	a20a0000 */ 	sb	$t2,0x0($s0)
/*    4b960:	a20b0001 */ 	sb	$t3,0x1($s0)
/*    4b964:	a20c0002 */ 	sb	$t4,0x2($s0)
/*    4b968:	a20d0003 */ 	sb	$t5,0x3($s0)
/*    4b96c:	a20e0026 */ 	sb	$t6,0x26($s0)
/*    4b970:	10000002 */ 	b	.L0004b97c
/*    4b974:	a20f0027 */ 	sb	$t7,0x27($s0)
.L0004b978:
/*    4b978:	02918021 */ 	addu	$s0,$s4,$s1
.L0004b97c:
/*    4b97c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    4b980:	30a4ffff */ 	andi	$a0,$a1,0xffff
/*    4b984:	0c014754 */ 	jal	func00051d50
/*    4b988:	a2180004 */ 	sb	$t8,0x4($s0)
/*    4b98c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    4b990:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4b994:	02802825 */ 	or	$a1,$s4,$zero
/*    4b998:	00594025 */ 	or	$t0,$v0,$t9
/*    4b99c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4b9a0:	a2080005 */ 	sb	$t0,0x5($s0)
/*    4b9a4:	02c02025 */ 	or	$a0,$s6,$zero
/*    4b9a8:	00002825 */ 	or	$a1,$zero,$zero
/*    4b9ac:	0c0121bc */ 	jal	osRecvMesg
/*    4b9b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4b9b4:	00002025 */ 	or	$a0,$zero,$zero
/*    4b9b8:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4b9bc:	02802825 */ 	or	$a1,$s4,$zero
/*    4b9c0:	02c02025 */ 	or	$a0,$s6,$zero
/*    4b9c4:	00002825 */ 	or	$a1,$zero,$zero
/*    4b9c8:	0c0121bc */ 	jal	osRecvMesg
/*    4b9cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4b9d0:	92130002 */ 	lbu	$s3,0x2($s0)
/*    4b9d4:	26120006 */ 	addiu	$s2,$s0,0x6
/*    4b9d8:	326900c0 */ 	andi	$t1,$s3,0xc0
/*    4b9dc:	00099903 */ 	sra	$s3,$t1,0x4
/*    4b9e0:	56600014 */ 	bnezl	$s3,.L0004ba34
/*    4b9e4:	24130001 */ 	addiu	$s3,$zero,0x1
/*    4b9e8:	0c014788 */ 	jal	func00051e20
/*    4b9ec:	02402025 */ 	or	$a0,$s2,$zero
/*    4b9f0:	920b0026 */ 	lbu	$t3,0x26($s0)
/*    4b9f4:	02402025 */ 	or	$a0,$s2,$zero
/*    4b9f8:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*    4b9fc:	11620008 */ 	beq	$t3,$v0,.L0004ba20
/*    4ba00:	00000000 */ 	nop
/*    4ba04:	02c02025 */ 	or	$a0,$s6,$zero
/*    4ba08:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    4ba0c:	02202825 */ 	or	$a1,$s1,$zero
/*    4ba10:	1440000d */ 	bnez	$v0,.L0004ba48
/*    4ba14:	00409825 */ 	or	$s3,$v0,$zero
/*    4ba18:	10000006 */ 	b	.L0004ba34
/*    4ba1c:	24130004 */ 	addiu	$s3,$zero,0x4
.L0004ba20:
/*    4ba20:	0c012c5c */ 	jal	func0004b170
/*    4ba24:	24060020 */ 	addiu	$a2,$zero,0x20
/*    4ba28:	10000003 */ 	b	.L0004ba38
/*    4ba2c:	24010004 */ 	addiu	$at,$zero,0x4
/*    4ba30:	24130001 */ 	addiu	$s3,$zero,0x1
.L0004ba34:
/*    4ba34:	24010004 */ 	addiu	$at,$zero,0x4
.L0004ba38:
/*    4ba38:	16610003 */ 	bne	$s3,$at,.L0004ba48
/*    4ba3c:	2aa20000 */ 	slti	$v0,$s5,0x0
/*    4ba40:	1040ffa3 */ 	beqz	$v0,.L0004b8d0
/*    4ba44:	26b5ffff */ 	addiu	$s5,$s5,-1
.L0004ba48:
/*    4ba48:	0c012a29 */ 	jal	__osSiRelAccess
/*    4ba4c:	00000000 */ 	nop
/*    4ba50:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4ba54:	02601025 */ 	or	$v0,$s3,$zero
/*    4ba58:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4ba5c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4ba60:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4ba64:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4ba68:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4ba6c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4ba70:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4ba74:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    4ba78:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    4ba7c:	03e00008 */ 	jr	$ra
/*    4ba80:	27bd0060 */ 	addiu	$sp,$sp,0x60
);
