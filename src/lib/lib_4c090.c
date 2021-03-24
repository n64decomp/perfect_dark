#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4d6f0.h"
#include "data.h"
#include "types.h"

s32 g_PfsPrevChannel = -1;
u8 g_PfsPrevBank = 250;

u16 __osSumCalc(u8 *ptr, int length)
{
	int i;
	u32 sum;
	u8 *tmp;

	sum = 0;
	tmp = ptr;

	for (i = 0; i < length; i++) {
		sum += *tmp++;
	}

	return sum & 0xffff;
}

s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
	u16 data = 0;
	u32 i;

	*csum = *icsum = 0;

	for (i = 0; i < ((sizeof(__OSPackId) - sizeof(u32)) / sizeof(u8)); i += 2) {
		data = *(u16 *)((u32)ptr + i);
		*csum += data;
		*icsum += ~data;
	}

	return 0;
}

GLOBAL_ASM(
glabel __osRepairPackId
/*    4c200:	27bdff60 */ 	addiu	$sp,$sp,-160
/*    4c204:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4c208:	afb60038 */ 	sw	$s6,0x38($sp)
/*    4c20c:	afb50034 */ 	sw	$s5,0x34($sp)
/*    4c210:	afb40030 */ 	sw	$s4,0x30($sp)
/*    4c214:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    4c218:	afb20028 */ 	sw	$s2,0x28($sp)
/*    4c21c:	afb10024 */ 	sw	$s1,0x24($sp)
/*    4c220:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4c224:	240effff */ 	addiu	$t6,$zero,-1
/*    4c228:	00809025 */ 	or	$s2,$a0,$zero
/*    4c22c:	00c0a025 */ 	or	$s4,$a2,$zero
/*    4c230:	00a0b025 */ 	or	$s6,$a1,$zero
/*    4c234:	00009825 */ 	or	$s3,$zero,$zero
/*    4c238:	0c012144 */ 	jal	osGetCount
/*    4c23c:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4c240:	ae820004 */ 	sw	$v0,0x4($s4)
/*    4c244:	8ed9000c */ 	lw	$t9,0xc($s6)
/*    4c248:	8ed80008 */ 	lw	$t8,0x8($s6)
/*    4c24c:	02402025 */ 	or	$a0,$s2,$zero
/*    4c250:	ae99000c */ 	sw	$t9,0xc($s4)
/*    4c254:	ae980008 */ 	sw	$t8,0x8($s4)
/*    4c258:	8ec90014 */ 	lw	$t1,0x14($s6)
/*    4c25c:	8ec80010 */ 	lw	$t0,0x10($s6)
/*    4c260:	ae890014 */ 	sw	$t1,0x14($s4)
/*    4c264:	ae880010 */ 	sw	$t0,0x10($s4)
/*    4c268:	924f0065 */ 	lbu	$t7,0x65($s2)
/*    4c26c:	51e00008 */ 	beqzl	$t7,.L0004c290
/*    4c270:	27b1007c */ 	addiu	$s1,$sp,0x7c
/*    4c274:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c278:	00002825 */ 	or	$a1,$zero,$zero
/*    4c27c:	50400004 */ 	beqzl	$v0,.L0004c290
/*    4c280:	27b1007c */ 	addiu	$s1,$sp,0x7c
/*    4c284:	100000a9 */ 	b	.L0004c52c
/*    4c288:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4c28c:	27b1007c */ 	addiu	$s1,$sp,0x7c
.L0004c290:
/*    4c290:	0220a825 */ 	or	$s5,$s1,$zero
/*    4c294:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*    4c298:	02402025 */ 	or	$a0,$s2,$zero
.L0004c29c:
/*    4c29c:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c2a0:	326500ff */ 	andi	$a1,$s3,0xff
/*    4c2a4:	10400003 */ 	beqz	$v0,.L0004c2b4
/*    4c2a8:	00003025 */ 	or	$a2,$zero,$zero
/*    4c2ac:	1000009f */ 	b	.L0004c52c
/*    4c2b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c2b4:
/*    4c2b4:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c2b8:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c2bc:	0c012e18 */ 	jal	__osContRamRead
/*    4c2c0:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c2c4:	10400003 */ 	beqz	$v0,.L0004c2d4
/*    4c2c8:	366b0080 */ 	ori	$t3,$s3,0x80
/*    4c2cc:	10000097 */ 	b	.L0004c52c
/*    4c2d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c2d4:
/*    4c2d4:	a3ab007c */ 	sb	$t3,0x7c($sp)
/*    4c2d8:	27a2007d */ 	addiu	$v0,$sp,0x7d
.L0004c2dc:
/*    4c2dc:	904c0000 */ 	lbu	$t4,0x0($v0)
/*    4c2e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4c2e4:	0050082b */ 	sltu	$at,$v0,$s0
/*    4c2e8:	01806827 */ 	nor	$t5,$t4,$zero
/*    4c2ec:	1420fffb */ 	bnez	$at,.L0004c2dc
/*    4c2f0:	a04dffff */ 	sb	$t5,-0x1($v0)
/*    4c2f4:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c2f8:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c2fc:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4c300:	00003025 */ 	or	$a2,$zero,$zero
/*    4c304:	0c012d84 */ 	jal	__osContRamWrite
/*    4c308:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c30c:	10400003 */ 	beqz	$v0,.L0004c31c
/*    4c310:	00003025 */ 	or	$a2,$zero,$zero
/*    4c314:	10000085 */ 	b	.L0004c52c
/*    4c318:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c31c:
/*    4c31c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c320:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c324:	0c012e18 */ 	jal	__osContRamRead
/*    4c328:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*    4c32c:	10400003 */ 	beqz	$v0,.L0004c33c
/*    4c330:	27a3005c */ 	addiu	$v1,$sp,0x5c
/*    4c334:	1000007d */ 	b	.L0004c52c
/*    4c338:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c33c:
/*    4c33c:	27a2007c */ 	addiu	$v0,$sp,0x7c
.L0004c340:
/*    4c340:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    4c344:	90580000 */ 	lbu	$t8,0x0($v0)
/*    4c348:	55d80006 */ 	bnel	$t6,$t8,.L0004c364
/*    4c34c:	27b9007c */ 	addiu	$t9,$sp,0x7c
/*    4c350:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4c354:	0071082b */ 	sltu	$at,$v1,$s1
/*    4c358:	1420fff9 */ 	bnez	$at,.L0004c340
/*    4c35c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4c360:	27b9007c */ 	addiu	$t9,$sp,0x7c
.L0004c364:
/*    4c364:	14790018 */ 	bne	$v1,$t9,.L0004c3c8
/*    4c368:	02402025 */ 	or	$a0,$s2,$zero
/*    4c36c:	5a600013 */ 	blezl	$s3,.L0004c3bc
/*    4c370:	26730001 */ 	addiu	$s3,$s3,0x1
/*    4c374:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c378:	00002825 */ 	or	$a1,$zero,$zero
/*    4c37c:	10400003 */ 	beqz	$v0,.L0004c38c
/*    4c380:	00003025 */ 	or	$a2,$zero,$zero
/*    4c384:	10000069 */ 	b	.L0004c52c
/*    4c388:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c38c:
/*    4c38c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c390:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c394:	0c012e18 */ 	jal	__osContRamRead
/*    4c398:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c39c:	10400003 */ 	beqz	$v0,.L0004c3ac
/*    4c3a0:	93a8007c */ 	lbu	$t0,0x7c($sp)
/*    4c3a4:	10000061 */ 	b	.L0004c52c
/*    4c3a8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c3ac:
/*    4c3ac:	24010080 */ 	addiu	$at,$zero,0x80
/*    4c3b0:	55010006 */ 	bnel	$t0,$at,.L0004c3cc
/*    4c3b4:	92490065 */ 	lbu	$t1,0x65($s2)
/*    4c3b8:	26730001 */ 	addiu	$s3,$s3,0x1
.L0004c3bc:
/*    4c3bc:	2a61003e */ 	slti	$at,$s3,0x3e
/*    4c3c0:	5420ffb6 */ 	bnezl	$at,.L0004c29c
/*    4c3c4:	02402025 */ 	or	$a0,$s2,$zero
.L0004c3c8:
/*    4c3c8:	92490065 */ 	lbu	$t1,0x65($s2)
.L0004c3cc:
/*    4c3cc:	02402025 */ 	or	$a0,$s2,$zero
/*    4c3d0:	11200007 */ 	beqz	$t1,.L0004c3f0
/*    4c3d4:	00000000 */ 	nop
/*    4c3d8:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c3dc:	00002825 */ 	or	$a1,$zero,$zero
/*    4c3e0:	10400003 */ 	beqz	$v0,.L0004c3f0
/*    4c3e4:	00000000 */ 	nop
/*    4c3e8:	10000050 */ 	b	.L0004c52c
/*    4c3ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c3f0:
/*    4c3f0:	1a600003 */ 	blez	$s3,.L0004c400
/*    4c3f4:	02802025 */ 	or	$a0,$s4,$zero
/*    4c3f8:	10000002 */ 	b	.L0004c404
/*    4c3fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004c400:
/*    4c400:	00001025 */ 	or	$v0,$zero,$zero
.L0004c404:
/*    4c404:	96cf0018 */ 	lhu	$t7,0x18($s6)
/*    4c408:	a293001a */ 	sb	$s3,0x1a($s4)
/*    4c40c:	2685001c */ 	addiu	$a1,$s4,0x1c
/*    4c410:	31eafffe */ 	andi	$t2,$t7,0xfffe
/*    4c414:	01425825 */ 	or	$t3,$t2,$v0
/*    4c418:	a68b0018 */ 	sh	$t3,0x18($s4)
/*    4c41c:	92cc001b */ 	lbu	$t4,0x1b($s6)
/*    4c420:	2686001e */ 	addiu	$a2,$s4,0x1e
/*    4c424:	0c013041 */ 	jal	__osIdCheckSum
/*    4c428:	a28c001b */ 	sb	$t4,0x1b($s4)
/*    4c42c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    4c430:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    4c434:	24180004 */ 	addiu	$t8,$zero,0x4
/*    4c438:	24190006 */ 	addiu	$t9,$zero,0x6
/*    4c43c:	a7ad0048 */ 	sh	$t5,0x48($sp)
/*    4c440:	a7ae004a */ 	sh	$t6,0x4a($sp)
/*    4c444:	a7b8004c */ 	sh	$t8,0x4c($sp)
/*    4c448:	a7b9004e */ 	sh	$t9,0x4e($sp)
/*    4c44c:	27b00048 */ 	addiu	$s0,$sp,0x48
/*    4c450:	27b10050 */ 	addiu	$s1,$sp,0x50
/*    4c454:	8e440004 */ 	lw	$a0,0x4($s2)
.L0004c458:
/*    4c458:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c45c:	96060000 */ 	lhu	$a2,0x0($s0)
/*    4c460:	24080001 */ 	addiu	$t0,$zero,0x1
/*    4c464:	afa80010 */ 	sw	$t0,0x10($sp)
/*    4c468:	0c012d84 */ 	jal	__osContRamWrite
/*    4c46c:	02803825 */ 	or	$a3,$s4,$zero
/*    4c470:	10400003 */ 	beqz	$v0,.L0004c480
/*    4c474:	26100002 */ 	addiu	$s0,$s0,0x2
/*    4c478:	1000002c */ 	b	.L0004c52c
/*    4c47c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c480:
/*    4c480:	0211082b */ 	sltu	$at,$s0,$s1
/*    4c484:	5420fff4 */ 	bnezl	$at,.L0004c458
/*    4c488:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c48c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c490:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c494:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c498:	0c012e18 */ 	jal	__osContRamRead
/*    4c49c:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c4a0:	10400003 */ 	beqz	$v0,.L0004c4b0
/*    4c4a4:	02801825 */ 	or	$v1,$s4,$zero
/*    4c4a8:	10000020 */ 	b	.L0004c52c
/*    4c4ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c4b0:
/*    4c4b0:	27a2007c */ 	addiu	$v0,$sp,0x7c
/*    4c4b4:	27a4009c */ 	addiu	$a0,$sp,0x9c
.L0004c4b8:
/*    4c4b8:	90490000 */ 	lbu	$t1,0x0($v0)
/*    4c4bc:	906f0000 */ 	lbu	$t7,0x0($v1)
/*    4c4c0:	512f0004 */ 	beql	$t1,$t7,.L0004c4d4
/*    4c4c4:	904a0001 */ 	lbu	$t2,0x1($v0)
/*    4c4c8:	10000017 */ 	b	.L0004c528
/*    4c4cc:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c4d0:	904a0001 */ 	lbu	$t2,0x1($v0)
.L0004c4d4:
/*    4c4d4:	906b0001 */ 	lbu	$t3,0x1($v1)
/*    4c4d8:	514b0004 */ 	beql	$t2,$t3,.L0004c4ec
/*    4c4dc:	904c0002 */ 	lbu	$t4,0x2($v0)
/*    4c4e0:	10000011 */ 	b	.L0004c528
/*    4c4e4:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c4e8:	904c0002 */ 	lbu	$t4,0x2($v0)
.L0004c4ec:
/*    4c4ec:	906d0002 */ 	lbu	$t5,0x2($v1)
/*    4c4f0:	518d0004 */ 	beql	$t4,$t5,.L0004c504
/*    4c4f4:	904e0003 */ 	lbu	$t6,0x3($v0)
/*    4c4f8:	1000000b */ 	b	.L0004c528
/*    4c4fc:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c500:	904e0003 */ 	lbu	$t6,0x3($v0)
.L0004c504:
/*    4c504:	90780003 */ 	lbu	$t8,0x3($v1)
/*    4c508:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4c50c:	11d80003 */ 	beq	$t6,$t8,.L0004c51c
/*    4c510:	00000000 */ 	nop
/*    4c514:	10000004 */ 	b	.L0004c528
/*    4c518:	2402000b */ 	addiu	$v0,$zero,0xb
.L0004c51c:
/*    4c51c:	1444ffe6 */ 	bne	$v0,$a0,.L0004c4b8
/*    4c520:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4c524:	00001025 */ 	or	$v0,$zero,$zero
.L0004c528:
/*    4c528:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c52c:
/*    4c52c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4c530:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4c534:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4c538:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4c53c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4c540:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    4c544:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    4c548:	03e00008 */ 	jr	$ra
/*    4c54c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

// Mismatch: j = 0 needs to be removed from the for loop so it uses
// the earlier assign, but this creates significantly different code.
//s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid)
//{
//	s32 ret;
//	u8 temp[32];
//	u8 comp[32];
//	u8 mask;
//	int i;
//	int j;
//	u16 index[4];
//
//	ret = 0;
//	mask = 0;
//	j = 0;
//
//	newid->repaired = -1;
//	newid->random = osGetCount();
//	newid->serial_mid = badid->serial_mid;
//	newid->serial_low = badid->serial_low;
//
//	if (pfs->activebank != 0) {
//		ERRCK(__osPfsSelectBank(pfs, 0));
//	}
//
//	for (j = 0; j < PFS_MAX_BANKS; j++) {
//		ERRCK(__osPfsSelectBank(pfs, j));
//
//		ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)&temp));
//
//		temp[0] = j | 0x80;
//
//		for (i = 1; i < ARRLEN(temp); i++) {
//			temp[i] = ~temp[i];
//		}
//
//		ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, (u8*)temp, FALSE));
//		ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)&comp));
//
//		for (i = 0; i < ARRLEN(temp); i++) {
//			if (comp[i] != temp[i]) {
//				break;
//			}
//		}
//
//		if (i != ARRLEN(temp)) {
//			break;
//		}
//
//		if (j > 0) {
//			ERRCK(__osPfsSelectBank(pfs, 0));
//
//			ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)temp));
//
//			if (temp[0] != 128) {
//				break;
//			}
//		}
//	}
//
//	if (pfs->activebank != 0) {
//		ERRCK(__osPfsSelectBank(pfs, 0));
//	}
//
//	if (j > 0) {
//		mask = 1;
//	} else {
//		mask = 0;
//	}
//
//	newid->deviceid = (badid->deviceid & (u16)~1) | mask;
//	newid->banks = j;
//	newid->version = badid->version;
//
//	__osIdCheckSum((u16*)newid, &newid->checksum, &newid->inverted_checksum);
//
//	index[0] = 1;
//	index[1] = 3;
//	index[2] = 4;
//	index[3] = 6;
//
//	for (i = 0; i < ARRLEN(index); i++) {
//		ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[i], (u8*)newid, TRUE));
//	}
//
//	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
//
//	for (i = 0; i < ARRLEN(temp); i++) {
//		if (temp[i] != ((u8 *)newid)[i]) {
//			return PFS_ERR_DEVICE;
//		}
//	}
//
//	return 0;
//}

s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp)
{
	u16 index[4];
	s32 ret;
	u16 sum;
	u16 isum;
	int i;
	int j;

	ret = 0;

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	index[0] = 1;
	index[1] = 3;
	index[2] = 4;
	index[3] = 6;

	for (i = 1; i < ARRLEN(index); i++) {
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, index[i], (u8*)temp));
		__osIdCheckSum((u16 *)temp, &sum, &isum);

		if (temp->checksum == sum && temp->inverted_checksum == isum) {
			break;
		}
	}

	if (i == ARRLEN(index)) {
		return PFS_ERR_ID_FATAL;
	}

	for (j = 0; j < ARRLEN(index); j++) {
		if (j != i) {
			ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[j], (u8*)temp, TRUE));
		}
	}

	return 0;
}

s32 __osGetId(OSPfs *pfs)
{
	u16 sum;
	u16 isum;
	u8 temp[32];
	__OSPackId newid;
	s32 ret;
	__OSPackId *id;

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0))
	}

	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));

	__osIdCheckSum((u16*)temp, &sum, &isum);

	id = (__OSPackId*)temp;

	if (id->checksum != sum || id->inverted_checksum != isum) {
		ret = __osCheckPackId(pfs, id);

		if (ret == PFS_ERR_ID_FATAL) {
			ERRCK(__osRepairPackId(pfs, id, &newid));
			id = &newid;
		} else if (ret != 0) {
			return ret;
		}
	}

	if ((id->deviceid & 1) == 0) {
		ERRCK(__osRepairPackId(pfs, id, &newid));
		id = &newid;

		if ((id->deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, 0x20);

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 16;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));

	return 0;
}

GLOBAL_ASM(
glabel func0004c860
/*    4c860:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    4c864:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4c868:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4c86c:	908e0065 */ 	lbu	$t6,0x65($a0)
/*    4c870:	00808025 */ 	or	$s0,$a0,$zero
/*    4c874:	51c0000f */ 	beqzl	$t6,.L0004c8b4
/*    4c878:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c87c:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c880:	00002825 */ 	or	$a1,$zero,$zero
/*    4c884:	24010002 */ 	addiu	$at,$zero,0x2
/*    4c888:	14410005 */ 	bne	$v0,$at,.L0004c8a0
/*    4c88c:	00401825 */ 	or	$v1,$v0,$zero
/*    4c890:	02002025 */ 	or	$a0,$s0,$zero
/*    4c894:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c898:	00002825 */ 	or	$a1,$zero,$zero
/*    4c89c:	00401825 */ 	or	$v1,$v0,$zero
.L0004c8a0:
/*    4c8a0:	50400004 */ 	beqzl	$v0,.L0004c8b4
/*    4c8a4:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c8a8:	1000001d */ 	b	.L0004c920
/*    4c8ac:	00601025 */ 	or	$v0,$v1,$zero
/*    4c8b0:	8e040004 */ 	lw	$a0,0x4($s0)
.L0004c8b4:
/*    4c8b4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c8b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c8bc:	0c012e18 */ 	jal	__osContRamRead
/*    4c8c0:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    4c8c4:	1040000d */ 	beqz	$v0,.L0004c8fc
/*    4c8c8:	24010002 */ 	addiu	$at,$zero,0x2
/*    4c8cc:	10410003 */ 	beq	$v0,$at,.L0004c8dc
/*    4c8d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c8d4:	10000013 */ 	b	.L0004c924
/*    4c8d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c8dc:
/*    4c8dc:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c8e0:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c8e4:	0c012e18 */ 	jal	__osContRamRead
/*    4c8e8:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    4c8ec:	50400004 */ 	beqzl	$v0,.L0004c900
/*    4c8f0:	2604000c */ 	addiu	$a0,$s0,0xc
/*    4c8f4:	1000000b */ 	b	.L0004c924
/*    4c8f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c8fc:
/*    4c8fc:	2604000c */ 	addiu	$a0,$s0,0xc
.L0004c900:
/*    4c900:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    4c904:	0c013824 */ 	jal	func0004e090
/*    4c908:	24060020 */ 	addiu	$a2,$zero,0x20
/*    4c90c:	50400004 */ 	beqzl	$v0,.L0004c920
/*    4c910:	00001025 */ 	or	$v0,$zero,$zero
/*    4c914:	10000002 */ 	b	.L0004c920
/*    4c918:	24020002 */ 	addiu	$v0,$zero,0x2
/*    4c91c:	00001025 */ 	or	$v0,$zero,$zero
.L0004c920:
/*    4c920:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c924:
/*    4c924:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4c928:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    4c92c:	03e00008 */ 	jr	$ra
/*    4c930:	00000000 */ 	nop
);

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank)
{
	u8 sum;
	int j;
	s32 ret;
	int offset;
	u8 *addr;
	static __OSInode prevnode;

	if (flag == 0 && bank == g_PfsPrevBank && pfs->channel == g_PfsPrevChannel) {
		bcopy(&prevnode, inode, sizeof(__OSInode));
		return 0;
	}

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	offset = (bank > 0) ? 1 : pfs->inode_start_page;

	if (flag == PFS_WRITE) {
		inode->inode_page[0].inode_t.page = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);
	}

	for (j = 0; j < 8; j++) {
		addr = ((u8 *)inode->inode_page + j * 32);

		if (flag == PFS_WRITE) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, FALSE);
			ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, FALSE);
		} else {
			ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
		}

		if (ret != 0) {
			return ret;
		}
	}

	if (flag == PFS_READ) {
		sum = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);

		if (sum != inode->inode_page[0].inode_t.page) {
			for (j = 0; j < PFS_ONE_PAGE; j++) {
				addr = ((u8 *)inode->inode_page + j * 32);
				ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr);
			}

			sum = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);

			if (sum != inode->inode_page[0].inode_t.page) {
				return PFS_ERR_INCONSISTENT;
			}

			for (j = 0; j < PFS_ONE_PAGE; j++) {
				addr = ((u8 *)inode->inode_page + j * 32);
				ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
			}
		}
	}

	g_PfsPrevBank = bank;
	bcopy(inode, &prevnode, sizeof(__OSInode));
	g_PfsPrevChannel = pfs->channel;

	return 0;
}
