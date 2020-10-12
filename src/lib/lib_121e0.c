#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

void func000121e0(void)
{
	// empty
}

void memInit(u32 heapstart, u32 heaplen)
{
	s32 i;
	u32 extraend;

	// Memory pool 9 is not cleared? Doesn't appear to be used anyway.
	// Maybe the array is only 0-8?
	for (i = 0; i < 9; i++) {
		g_PrimaryMemoryPools[i].start = 0;
		g_PrimaryMemoryPools[i].nextallocation = 0;
		g_PrimaryMemoryPools[i].end = 0;
		g_PrimaryMemoryPools[i].prevallocation = 0;

		g_SecondaryMemoryPools[i].start = 0;
		g_SecondaryMemoryPools[i].nextallocation = 0;
		g_SecondaryMemoryPools[i].end = 0;
		g_SecondaryMemoryPools[i].prevallocation = 0;
	}

	g_PrimaryMemoryPools[0].start = heapstart;
	g_PrimaryMemoryPools[0].end = heapstart + heaplen;
	g_PrimaryMemoryPools[6].start = heapstart;
	g_PrimaryMemoryPools[6].end = heapstart + heaplen;
	g_PrimaryMemoryPools[4].start = heapstart;
	g_PrimaryMemoryPools[4].end = heapstart + heaplen;

	extraend = 0x80000000 + osGetMemSize();

	if (osGetMemSize() > 4 * 1024 * 1024) {
		g_SecondaryMemoryPools[4].start = 0x80400000;
		g_SecondaryMemoryPools[4].end = extraend;
	}

	for (i = 0; i < 9; i++) {
		g_PrimaryMemoryPools[i].unk0c = g_PrimaryMemoryPools[i].end;
		g_SecondaryMemoryPools[i].unk0c = g_SecondaryMemoryPools[i].end;
	}
}

u32 memGetPool4Available(void)
{
	u32 free;

	if (IS4MB()) {
		free = g_PrimaryMemoryPools[4].end - g_PrimaryMemoryPools[4].nextallocation;
	} else {
		free = g_SecondaryMemoryPools[4].end - g_SecondaryMemoryPools[4].nextallocation;
	}

	return free;
}

u32 memGetNextPool4Allocation(void)
{
	u32 next;

	if (IS4MB()) {
		next = g_PrimaryMemoryPools[4].nextallocation;
	} else {
		next = g_SecondaryMemoryPools[4].nextallocation;
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
//	allocation = pool->nextallocation;
//
//	if (pool->nextallocation == 0) {
//		return allocation;
//	}
//
//	if (pool->nextallocation > pool->end) {
//		return 0;
//	}
//
//	if (pool->nextallocation + size > pool->end) {
//		return 0;
//	}
//
//	// Mismatch because allocation in the following statement should be
//	// pool->nextallocation, but when this is changed it reuses the computed
//	// expression from above which results in different codegen.
//	pool->nextallocation = allocation + size;
//	pool->prevallocation = allocation;
//
//	return allocation;
//}

void *malloc(u32 len, u8 pool)
{
	void *allocation = (void *)memAllocFromBank(&g_PrimaryMemoryPools[0], len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = (void *)memAllocFromBank(&g_SecondaryMemoryPools[0], len, pool);

	if (allocation) {
		return allocation;
	}

	return allocation;
}

/**
 * Reallocate the given allocation in the given pool.
 * The pointer will remain unchanged.
 *
 * The allocation must be the most recent allocation.
 *
 * @dangerous: This function does not check the limits of the memory pool.
 * If it allocates past the end of the pool it could lead to memory corruption.
 */
s32 memReallocate(u32 allocation, s32 newsize, u8 poolnum)
{
	struct memorypool *pool = &g_PrimaryMemoryPools[poolnum];
	s32 origsize;
	s32 growsize;

	if (pool->prevallocation != allocation) {
		pool = &g_SecondaryMemoryPools[poolnum];

		if (pool->prevallocation != allocation) {
			return 2;
		}
	}

	origsize = pool->nextallocation - pool->prevallocation;
	growsize = newsize - origsize;

	if (growsize <= 0) {
		pool->nextallocation += growsize;
		pool->nextallocation = ALIGN16(pool->nextallocation);
		return 1;
	}

	pool->nextallocation += growsize;
	return 1;
}

void func000124cc(void)
{
	// empty
}

u32 memGetFree(u8 poolnum, u32 bank)
{
	struct memorypool *pool;

	if (bank == MEMBANK_PRIMARY) {
		pool = &g_PrimaryMemoryPools[poolnum];
	} else {
		pool = &g_SecondaryMemoryPools[poolnum];
	}

	return pool->end - pool->nextallocation;
}

void memResetPool(u8 pool)
{
	// When resetting mempool 4, put it immediately after mempool 6 and close
	// off mempool 6. Perhaps mempool 6 is only allocated to during stage load
	// and mempool 4 is dynamic stuff which can happen after?
	if (pool == 4) {
		g_PrimaryMemoryPools[4].start = g_PrimaryMemoryPools[6].nextallocation;
		g_PrimaryMemoryPools[6].end = g_PrimaryMemoryPools[6].nextallocation;
		g_PrimaryMemoryPools[6].unk0c = g_PrimaryMemoryPools[6].nextallocation;
	}

	g_PrimaryMemoryPools[pool].nextallocation = g_PrimaryMemoryPools[pool].start;
	g_SecondaryMemoryPools[pool].nextallocation = g_SecondaryMemoryPools[pool].start;
	g_PrimaryMemoryPools[pool].prevallocation = 0;
	g_SecondaryMemoryPools[pool].prevallocation = 0;
}

/**
 * Setting nextallocation to 0 means that this pool will refuse all allocations.
 */
void memDisablePool(u8 pool)
{
	g_PrimaryMemoryPools[pool].nextallocation = 0;
	g_SecondaryMemoryPools[pool].nextallocation = 0;
	g_PrimaryMemoryPools[pool].end = g_PrimaryMemoryPools[pool].unk0c;
	g_SecondaryMemoryPools[pool].end = g_SecondaryMemoryPools[pool].unk0c;
}

GLOBAL_ASM(
glabel func000125dc
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
glabel func00012644
/*    12644:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12648:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1264c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12650:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    12654:	3c04800a */ 	lui	$a0,%hi(g_PrimaryMemoryPools)
/*    12658:	24849300 */ 	addiu	$a0,$a0,%lo(g_PrimaryMemoryPools)
/*    1265c:	93a6001f */ 	lbu	$a2,0x1f($sp)
/*    12660:	0c004977 */ 	jal	func000125dc
/*    12664:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12668:	10400003 */ 	beqz	$v0,.L00012678
/*    1266c:	3c04800a */ 	lui	$a0,%hi(g_SecondaryMemoryPools)
/*    12670:	1000000b */ 	b	.L000126a0
/*    12674:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00012678:
/*    12678:	248493b8 */ 	addiu	$a0,$a0,%lo(g_SecondaryMemoryPools)
/*    1267c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12680:	0c004977 */ 	jal	func000125dc
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
/*    126ac:	00000000 */ 	nop
);
