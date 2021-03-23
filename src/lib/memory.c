#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

struct memorypool g_OnboardMemoryPools[9];
u32 var800993b4;
struct memorypool g_ExpansionMemoryPools[9];
u32 var8009946c;

void func000121e0(void)
{
	// empty
}

/**
 * Initialise the memory allocation system by initialising the banks and pools.
 *
 * The system has two banks - onboard and expansion - which refer to the onboard
 * memory and expansion pak memory if present. The arguments passed are the
 * onboard start and length that can be used by the memory system. If the
 * expansion pak is present, the entire pak is used for the second bank.
 *
 * Each bank consists of 8 pools, which start off overlapping. Care must be
 * taken to not allocate from the wrong pool at the wrong time. In practice it
 * appears only two pools are used which makes this easy:
 *
 * MEMPOOL_PERMANENT (index 6) is for permanent data and is never cleared
 * MEMPOOL_STAGE (index 4) is for general data and is cleared on stage load
 *
 * After the permanent pool has finished its allocations, it is closed off and
 * the stage pool is then placed immediately after it. All allocations from
 * there on are made from the stage pool.
 *
 * Each pool has a start and end address. Allocations are typically served from
 * the left side of the pool but can also be allocated from the right side.
 * In practice right side allocations are only used once (by texture related
 * code).
 *
 * Resizing an allocation is also supported, but only from the left side and
 * only if it's the most recent allocation.
 */
void memInit(u32 heapstart, u32 heaplen)
{
	s32 i;
	u32 extraend;

	for (i = 0; i < 9; i++) {
		g_OnboardMemoryPools[i].start = 0;
		g_OnboardMemoryPools[i].leftpos = 0;
		g_OnboardMemoryPools[i].rightpos = 0;
		g_OnboardMemoryPools[i].prevallocation = 0;

		g_ExpansionMemoryPools[i].start = 0;
		g_ExpansionMemoryPools[i].leftpos = 0;
		g_ExpansionMemoryPools[i].rightpos = 0;
		g_ExpansionMemoryPools[i].prevallocation = 0;
	}

	g_OnboardMemoryPools[MEMPOOL_0].start = heapstart;
	g_OnboardMemoryPools[MEMPOOL_0].rightpos = heapstart + heaplen;
	g_OnboardMemoryPools[MEMPOOL_PERMANENT].start = heapstart;
	g_OnboardMemoryPools[MEMPOOL_PERMANENT].rightpos = heapstart + heaplen;
	g_OnboardMemoryPools[MEMPOOL_STAGE].start = heapstart;
	g_OnboardMemoryPools[MEMPOOL_STAGE].rightpos = heapstart + heaplen;

	// If 8MB, reserve the entire expansion pak for additional mempool 4
	extraend = 0x80000000 + initGetMemSize();

	if (initGetMemSize() > 4 * 1024 * 1024) {
		g_ExpansionMemoryPools[MEMPOOL_STAGE].start = 0x80400000;
		g_ExpansionMemoryPools[MEMPOOL_STAGE].rightpos = extraend;
	}

	for (i = 0; i < 9; i++) {
		g_OnboardMemoryPools[i].end = g_OnboardMemoryPools[i].rightpos;
		g_ExpansionMemoryPools[i].end = g_ExpansionMemoryPools[i].rightpos;
	}
}

u32 memGetPool4Available(void)
{
	u32 free;

	if (IS4MB()) {
		free = g_OnboardMemoryPools[MEMPOOL_STAGE].rightpos - g_OnboardMemoryPools[MEMPOOL_STAGE].leftpos;
	} else {
		free = g_ExpansionMemoryPools[MEMPOOL_STAGE].rightpos - g_ExpansionMemoryPools[MEMPOOL_STAGE].leftpos;
	}

	return free;
}

u32 memGetNextPool4Allocation(void)
{
	u32 next;

	if (IS4MB()) {
		next = g_OnboardMemoryPools[MEMPOOL_STAGE].leftpos;
	} else {
		next = g_ExpansionMemoryPools[MEMPOOL_STAGE].leftpos;
	}

	return next;
}

GLOBAL_ASM(
glabel memAllocFromBank
/*    12354:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    12358:	000e7880 */ 	sll	$t7,$t6,0x2
/*    1235c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    12360:	000f7880 */ 	sll	$t7,$t7,0x2
/*    12364:	afa60008 */ 	sw	$a2,0x8($sp)
/*    12368:	008f2021 */ 	addu	$a0,$a0,$t7
/*    1236c:	8c820004 */ 	lw	$v0,0x4($a0)
/*    12370:	00a03825 */ 	or	$a3,$a1,$zero
/*    12374:	14400003 */ 	bnez	$v0,.L00012384
/*    12378:	00401825 */ 	or	$v1,$v0,$zero
/*    1237c:	03e00008 */ 	jr	$ra
/*    12380:	00601025 */ 	or	$v0,$v1,$zero
.L00012384:
/*    12384:	8c850008 */ 	lw	$a1,0x8($a0)
/*    12388:	0047c021 */ 	addu	$t8,$v0,$a3
/*    1238c:	00a2082b */ 	sltu	$at,$a1,$v0
/*    12390:	50200004 */ 	beqzl	$at,.L000123a4
/*    12394:	00b8082b */ 	sltu	$at,$a1,$t8
/*    12398:	03e00008 */ 	jr	$ra
/*    1239c:	00001025 */ 	or	$v0,$zero,$zero
/*    123a0:	00b8082b */ 	sltu	$at,$a1,$t8
.L000123a4:
/*    123a4:	10200003 */ 	beqz	$at,.L000123b4
/*    123a8:	0047c821 */ 	addu	$t9,$v0,$a3
/*    123ac:	03e00008 */ 	jr	$ra
/*    123b0:	00001025 */ 	or	$v0,$zero,$zero
.L000123b4:
/*    123b4:	ac990004 */ 	sw	$t9,0x4($a0)
/*    123b8:	ac830010 */ 	sw	$v1,0x10($a0)
/*    123bc:	00601025 */ 	or	$v0,$v1,$zero
/*    123c0:	03e00008 */ 	jr	$ra
/*    123c4:	00000000 */ 	nop
);

//u32 memAllocFromBank(struct memorypool *pool, u32 size, u8 poolnum)
//{
//	u32 allocation;
//
//	pool += poolnum;
//
//	allocation = pool->leftpos;
//
//	if (pool->leftpos == 0) {
//		return allocation;
//	}
//
//	if (pool->leftpos > pool->rightpos) {
//		return 0;
//	}
//
//	if (pool->leftpos + size > pool->rightpos) {
//		return 0;
//	}
//
//	// Mismatch because allocation in the following statement should be
//	// pool->leftpos, but when this is changed it reuses the computed
//	// expression from above which results in different codegen.
//	pool->leftpos = allocation + size;
//	pool->prevallocation = allocation;
//
//	return allocation;
//}

#if VERSION >= VERSION_NTSC_1_0
void *malloc(u32 len, u8 pool)
{
	void *allocation = (void *)memAllocFromBank(g_OnboardMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = (void *)memAllocFromBank(g_ExpansionMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

	return allocation;
}
#else
GLOBAL_ASM(
glabel malloc
/*    12838:	27bdff78 */ 	addiu	$sp,$sp,-136
/*    1283c:	afa40088 */ 	sw	$a0,0x88($sp)
/*    12840:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    12844:	afa5008c */ 	sw	$a1,0x8c($sp)
/*    12848:	3c04800a */ 	lui	$a0,0x800a
/*    1284c:	2484c280 */ 	addiu	$a0,$a0,-15744
/*    12850:	93a6008f */ 	lbu	$a2,0x8f($sp)
/*    12854:	0c0049f1 */ 	jal	0x127c4
/*    12858:	8fa50088 */ 	lw	$a1,0x88($sp)
/*    1285c:	10400003 */ 	beqz	$v0,.NB0001286c
/*    12860:	3c04800a */ 	lui	$a0,0x800a
/*    12864:	10000036 */ 	beqz	$zero,.NB00012940
/*    12868:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB0001286c:
/*    1286c:	2484c338 */ 	addiu	$a0,$a0,-15560
/*    12870:	8fa50088 */ 	lw	$a1,0x88($sp)
/*    12874:	0c0049f1 */ 	jal	0x127c4
/*    12878:	93a6008f */ 	lbu	$a2,0x8f($sp)
/*    1287c:	10400003 */ 	beqz	$v0,.NB0001288c
/*    12880:	afa20084 */ 	sw	$v0,0x84($sp)
/*    12884:	1000002e */ 	beqz	$zero,.NB00012940
/*    12888:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB0001288c:
/*    1288c:	93a2008f */ 	lbu	$v0,0x8f($sp)
/*    12890:	24010008 */ 	addiu	$at,$zero,0x8
/*    12894:	10410028 */ 	beq	$v0,$at,.NB00012938
/*    12898:	24010007 */ 	addiu	$at,$zero,0x7
/*    1289c:	10410026 */ 	beq	$v0,$at,.NB00012938
/*    128a0:	8fae0088 */ 	lw	$t6,0x88($sp)
/*    128a4:	11c00024 */ 	beqz	$t6,.NB00012938
/*    128a8:	24010004 */ 	addiu	$at,$zero,0x4
/*    128ac:	14410011 */ 	bne	$v0,$at,.NB000128f4
/*    128b0:	24040006 */ 	addiu	$a0,$zero,0x6
/*    128b4:	24040004 */ 	addiu	$a0,$zero,0x4
/*    128b8:	0c004a7c */ 	jal	0x129f0
/*    128bc:	00002825 */ 	or	$a1,$zero,$zero
/*    128c0:	afa20028 */ 	sw	$v0,0x28($sp)
/*    128c4:	24040004 */ 	addiu	$a0,$zero,0x4
/*    128c8:	0c004a91 */ 	jal	0x12a44
/*    128cc:	00002825 */ 	or	$a1,$zero,$zero
/*    128d0:	3c057005 */ 	lui	$a1,0x7005
/*    128d4:	24a556f0 */ 	addiu	$a1,$a1,0x56f0
/*    128d8:	27a40034 */ 	addiu	$a0,$sp,0x34
/*    128dc:	8fa60088 */ 	lw	$a2,0x88($sp)
/*    128e0:	8fa70028 */ 	lw	$a3,0x28($sp)
/*    128e4:	0c004fc1 */ 	jal	0x13f04
/*    128e8:	afa20010 */ 	sw	$v0,0x10($sp)
/*    128ec:	1000000e */ 	beqz	$zero,.NB00012928
/*    128f0:	00000000 */ 	sll	$zero,$zero,0x0
.NB000128f4:
/*    128f4:	0c004a7c */ 	jal	0x129f0
/*    128f8:	00002825 */ 	or	$a1,$zero,$zero
/*    128fc:	afa20028 */ 	sw	$v0,0x28($sp)
/*    12900:	24040006 */ 	addiu	$a0,$zero,0x6
/*    12904:	0c004a91 */ 	jal	0x12a44
/*    12908:	00002825 */ 	or	$a1,$zero,$zero
/*    1290c:	3c057005 */ 	lui	$a1,0x7005
/*    12910:	24a55710 */ 	addiu	$a1,$a1,0x5710
/*    12914:	27a40034 */ 	addiu	$a0,$sp,0x34
/*    12918:	8fa60088 */ 	lw	$a2,0x88($sp)
/*    1291c:	8fa70028 */ 	lw	$a3,0x28($sp)
/*    12920:	0c004fc1 */ 	jal	0x13f04
/*    12924:	afa20010 */ 	sw	$v0,0x10($sp)
.NB00012928:
/*    12928:	0c003074 */ 	jal	0xc1d0
/*    1292c:	27a40034 */ 	addiu	$a0,$sp,0x34
/*    12930:	240f0045 */ 	addiu	$t7,$zero,0x45
/*    12934:	a00f0000 */ 	sb	$t7,0x0($zero)
.NB00012938:
/*    12938:	8fa20084 */ 	lw	$v0,0x84($sp)
/*    1293c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB00012940:
/*    12940:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*    12944:	03e00008 */ 	jr	$ra
/*    12948:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

/**
 * Reallocate the given allocation in the given pool.
 * The pointer will remain unchanged.
 *
 * The allocation must be the most recent allocation.
 *
 * @dangerous: This function does not check the limits of the memory pool.
 * If it allocates past the rightpos of the pool it could lead to memory corruption.
 */
s32 memReallocate(u32 allocation, s32 newsize, u8 poolnum)
{
	struct memorypool *pool = &g_OnboardMemoryPools[poolnum];
	s32 origsize;
	s32 growsize;

	if (pool->prevallocation != allocation) {
		pool = &g_ExpansionMemoryPools[poolnum];

		if (pool->prevallocation != allocation) {
			return 2;
		}
	}

	origsize = pool->leftpos - pool->prevallocation;
	growsize = newsize - origsize;

	if (growsize <= 0) {
		pool->leftpos += growsize;
		pool->leftpos = ALIGN16(pool->leftpos);
		return 1;
	}

	pool->leftpos += growsize;
	return 1;
}

void func000124cc(void)
{
	// empty
}

u32 memGetFree(u8 poolnum, u32 bank)
{
	struct memorypool *pool;

	if (bank == MEMBANK_ONBOARD) {
		pool = &g_OnboardMemoryPools[poolnum];
	} else {
		pool = &g_ExpansionMemoryPools[poolnum];
	}

	return pool->rightpos - pool->leftpos;
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012a44nb
/*    12a44:	afa40000 */ 	sw	$a0,0x0($sp)
/*    12a48:	308e00ff */ 	andi	$t6,$a0,0xff
/*    12a4c:	14a00008 */ 	bnez	$a1,.NB00012a70
/*    12a50:	01c02025 */ 	or	$a0,$t6,$zero
/*    12a54:	000e7880 */ 	sll	$t7,$t6,0x2
/*    12a58:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    12a5c:	3c18800a */ 	lui	$t8,0x800a
/*    12a60:	2718c280 */ 	addiu	$t8,$t8,-15744
/*    12a64:	000f7880 */ 	sll	$t7,$t7,0x2
/*    12a68:	10000007 */ 	beqz	$zero,.NB00012a88
/*    12a6c:	01f81821 */ 	addu	$v1,$t7,$t8
.NB00012a70:
/*    12a70:	0004c880 */ 	sll	$t9,$a0,0x2
/*    12a74:	0324c821 */ 	addu	$t9,$t9,$a0
/*    12a78:	3c08800a */ 	lui	$t0,0x800a
/*    12a7c:	2508c338 */ 	addiu	$t0,$t0,-15560
/*    12a80:	0019c880 */ 	sll	$t9,$t9,0x2
/*    12a84:	03281821 */ 	addu	$v1,$t9,$t0
.NB00012a88:
/*    12a88:	8c690008 */ 	lw	$t1,0x8($v1)
/*    12a8c:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*    12a90:	03e00008 */ 	jr	$ra
/*    12a94:	012a1023 */ 	subu	$v0,$t1,$t2
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012a98nb
/*    12a98:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12a9c:	00802825 */ 	or	$a1,$a0,$zero
/*    12aa0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12aa4:	30ae000f */ 	andi	$t6,$a1,0xf
/*    12aa8:	01c02825 */ 	or	$a1,$t6,$zero
/*    12aac:	0c004a0e */ 	jal	0x12838
/*    12ab0:	00042102 */ 	srl	$a0,$a0,0x4
/*    12ab4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12ab8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12abc:	03e00008 */ 	jr	$ra
/*    12ac0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

/**
 * Reset the pool's left side to its start address, effectively freeing the left
 * side of the pool.
 *
 * If resetting the stage pool, close off the permanent pool and place the stage
 * pool immediately after it.
 *
 * Note the right side is not reset here.
 */
void memResetPool(u8 pool)
{
	if (pool == MEMPOOL_STAGE) {
		g_OnboardMemoryPools[MEMPOOL_STAGE].start = g_OnboardMemoryPools[MEMPOOL_PERMANENT].leftpos;
		g_OnboardMemoryPools[MEMPOOL_PERMANENT].rightpos = g_OnboardMemoryPools[MEMPOOL_PERMANENT].leftpos;
		g_OnboardMemoryPools[MEMPOOL_PERMANENT].end = g_OnboardMemoryPools[MEMPOOL_PERMANENT].leftpos;
	}

	g_OnboardMemoryPools[pool].leftpos = g_OnboardMemoryPools[pool].start;
	g_ExpansionMemoryPools[pool].leftpos = g_ExpansionMemoryPools[pool].start;
	g_OnboardMemoryPools[pool].prevallocation = 0;
	g_ExpansionMemoryPools[pool].prevallocation = 0;
}

/**
 * Setting leftpos to 0 means that this pool will refuse allocations from the
 * left.
 *
 * Setting rightpos to the end means it's resetting the right side and making
 * that available for allocations. It would have made more sense to do this in
 * memResetPool instead.
 */
void memDisablePool(u8 pool)
{
	g_OnboardMemoryPools[pool].leftpos = 0;
	g_ExpansionMemoryPools[pool].leftpos = 0;
	g_OnboardMemoryPools[pool].rightpos = g_OnboardMemoryPools[pool].end;
	g_ExpansionMemoryPools[pool].rightpos = g_ExpansionMemoryPools[pool].end;
}

GLOBAL_ASM(
glabel memAllocFromBankRight
/*    125dc:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    125e0:	000e7880 */ 	sll	$t7,$t6,0x2
/*    125e4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    125e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    125ec:	afa60008 */ 	sw	$a2,0x8($sp)
/*    125f0:	008f2021 */ 	addu	$a0,$a0,$t7
/*    125f4:	8c820008 */ 	lw	$v0,0x8($a0)
/*    125f8:	14400003 */ 	bnez	$v0,.L00012608
/*    125fc:	00401825 */ 	or	$v1,$v0,$zero
/*    12600:	03e00008 */ 	jr	$ra
/*    12604:	00601025 */ 	or	$v0,$v1,$zero
.L00012608:
/*    12608:	8c830004 */ 	lw	$v1,0x4($a0)
/*    1260c:	00453023 */ 	subu	$a2,$v0,$a1
/*    12610:	0043082b */ 	sltu	$at,$v0,$v1
/*    12614:	50200004 */ 	beqzl	$at,.L00012628
/*    12618:	00c3082b */ 	sltu	$at,$a2,$v1
/*    1261c:	03e00008 */ 	jr	$ra
/*    12620:	00001025 */ 	or	$v0,$zero,$zero
/*    12624:	00c3082b */ 	sltu	$at,$a2,$v1
.L00012628:
/*    12628:	10200003 */ 	beqz	$at,.L00012638
/*    1262c:	00c01025 */ 	or	$v0,$a2,$zero
/*    12630:	03e00008 */ 	jr	$ra
/*    12634:	00001025 */ 	or	$v0,$zero,$zero
.L00012638:
/*    12638:	ac860008 */ 	sw	$a2,0x8($a0)
/*    1263c:	03e00008 */ 	jr	$ra
/*    12640:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel mallocFromRight
/*    12644:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12648:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1264c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12650:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    12654:	3c04800a */ 	lui	$a0,%hi(g_OnboardMemoryPools)
/*    12658:	24849300 */ 	addiu	$a0,$a0,%lo(g_OnboardMemoryPools)
/*    1265c:	93a6001f */ 	lbu	$a2,0x1f($sp)
/*    12660:	0c004977 */ 	jal	memAllocFromBankRight
/*    12664:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12668:	10400003 */ 	beqz	$v0,.L00012678
/*    1266c:	3c04800a */ 	lui	$a0,%hi(g_ExpansionMemoryPools)
/*    12670:	1000000b */ 	b	.L000126a0
/*    12674:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00012678:
/*    12678:	248493b8 */ 	addiu	$a0,$a0,%lo(g_ExpansionMemoryPools)
/*    1267c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12680:	0c004977 */ 	jal	memAllocFromBankRight
/*    12684:	93a6001f */ 	lbu	$a2,0x1f($sp)
/*    12688:	10400003 */ 	beqz	$v0,.L00012698
/*    1268c:	00401825 */ 	or	$v1,$v0,$zero
/*    12690:	10000003 */ 	b	.L000126a0
/*    12694:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00012698:
/*    12698:	00601025 */ 	or	$v0,$v1,$zero
/*    1269c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000126a0:
/*    126a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    126a4:	03e00008 */ 	jr	$ra
/*    126a8:	00000000 */ 	nop
);
