#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osPfsInitPak2(OSMesgQueue *queue, OSPfs *pfs, s32 channel)
{
	s32 ret;
	u16 csum;
	u16 icsum;
	__OSPackId oldid;
	__OSPackId *id;
	__OSPackId newid;

	__osSiGetAccess();
	ret = __osPfsGetStatus(queue, channel);
	__osSiRelAccess();

	if (ret != 0) {
		return ret;
	}

	pfs->queue = queue;
	pfs->channel = channel;
	pfs->status = 0;

	ret = func00051778(pfs);

	if (ret != 0) {
		return ret;
	}

	ret = __osPfsSelectBank(pfs, 0);

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(pfs->queue, pfs->channel, 1, (u8 *)&oldid);

	if (ret != 0) {
		return ret;
	}

	__osIdCheckSum((u16 *)&oldid, &csum, &icsum);

	id = &oldid;

	if ((oldid.checksum != csum || oldid.inverted_checksum != icsum)) {
		ret = __osCheckPackId(pfs, &oldid);

		if (ret != 0) {
			pfs->status |= PFS_ID_BROKEN;
			return ret;
		}
	}

	if ((oldid.deviceid & 1) == 0) {
		ret = __osRepairPackId(pfs, &oldid, &newid);

		if (ret != 0) {
			if (ret == PFS_ERR_ID_FATAL) {
				pfs->status |= PFS_ID_BROKEN;
			}

			return ret;
		}

		id = &newid;

		if ((newid.deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, sizeof(*id));

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 16;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

	ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);

	if (ret != 0) {
		return ret;
	}

	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;

	return ret;
}

GLOBAL_ASM(
glabel func00051778
/*    51778:	27bdff68 */ 	addiu	$sp,$sp,-152
/*    5177c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    51780:	afb00020 */ 	sw	$s0,0x20($sp)
/*    51784:	00808025 */ 	or	$s0,$a0,$zero
/*    51788:	0c013378 */ 	jal	__osPfsSelectBank
/*    5178c:	00002825 */ 	or	$a1,$zero,$zero
/*    51790:	10400003 */ 	beqz	$v0,.L000517a0
/*    51794:	00003025 */ 	or	$a2,$zero,$zero
/*    51798:	10000034 */ 	b	.L0005186c
/*    5179c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000517a0:
/*    517a0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    517a4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    517a8:	0c012e18 */ 	jal	__osContRamRead
/*    517ac:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    517b0:	10400003 */ 	beqz	$v0,.L000517c0
/*    517b4:	27a30070 */ 	addiu	$v1,$sp,0x70
/*    517b8:	1000002c */ 	b	.L0005186c
/*    517bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000517c0:
/*    517c0:	00001025 */ 	or	$v0,$zero,$zero
/*    517c4:	24040020 */ 	addiu	$a0,$zero,0x20
.L000517c8:
/*    517c8:	244e0001 */ 	addiu	$t6,$v0,0x1
/*    517cc:	244f0002 */ 	addiu	$t7,$v0,0x2
/*    517d0:	24580003 */ 	addiu	$t8,$v0,0x3
/*    517d4:	a0620000 */ 	sb	$v0,0x0($v1)
/*    517d8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    517dc:	a0780003 */ 	sb	$t8,0x3($v1)
/*    517e0:	a06f0002 */ 	sb	$t7,0x2($v1)
/*    517e4:	a06e0001 */ 	sb	$t6,0x1($v1)
/*    517e8:	1444fff7 */ 	bne	$v0,$a0,.L000517c8
/*    517ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*    517f0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    517f4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    517f8:	afa00010 */ 	sw	$zero,0x10($sp)
/*    517fc:	00003025 */ 	or	$a2,$zero,$zero
/*    51800:	0c012d84 */ 	jal	__osContRamWrite
/*    51804:	27a70070 */ 	addiu	$a3,$sp,0x70
/*    51808:	10400003 */ 	beqz	$v0,.L00051818
/*    5180c:	00003025 */ 	or	$a2,$zero,$zero
/*    51810:	10000016 */ 	b	.L0005186c
/*    51814:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00051818:
/*    51818:	8e040004 */ 	lw	$a0,0x4($s0)
/*    5181c:	8e050008 */ 	lw	$a1,0x8($s0)
/*    51820:	0c012e18 */ 	jal	__osContRamRead
/*    51824:	27a70050 */ 	addiu	$a3,$sp,0x50
/*    51828:	10400003 */ 	beqz	$v0,.L00051838
/*    5182c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    51830:	1000000e */ 	b	.L0005186c
/*    51834:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00051838:
/*    51838:	27a50050 */ 	addiu	$a1,$sp,0x50
/*    5183c:	0c013824 */ 	jal	bcmp
/*    51840:	24060020 */ 	addiu	$a2,$zero,0x20
/*    51844:	10400003 */ 	beqz	$v0,.L00051854
/*    51848:	00003025 */ 	or	$a2,$zero,$zero
/*    5184c:	10000006 */ 	b	.L00051868
/*    51850:	2402000b */ 	addiu	$v0,$zero,0xb
.L00051854:
/*    51854:	8e040004 */ 	lw	$a0,0x4($s0)
/*    51858:	8e050008 */ 	lw	$a1,0x8($s0)
/*    5185c:	afa00010 */ 	sw	$zero,0x10($sp)
/*    51860:	0c012d84 */ 	jal	__osContRamWrite
/*    51864:	27a70030 */ 	addiu	$a3,$sp,0x30
.L00051868:
/*    51868:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0005186c:
/*    5186c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    51870:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*    51874:	03e00008 */ 	jr	$ra
/*    51878:	00000000 */ 	nop
);
