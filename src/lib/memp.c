#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/boot.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

/**
 * memp - memory pool allocation system.
 *
 * Memp is the main memory allocation system in the game. Memp's heap size is
 * around 1MB without the expansion pak, and around 5MB with the expansion pak.
 *
 * There are other memory systems in the game, particularly mema, graphics
 * memory and the audio heap, which are all allocated out of memp.
 *
 * The memp system has two banks - onboard and expansion - which refer to the
 * onboard memory and expansion pak memory if present. If the expansion pak is
 * present, it's used entirely for memp.
 *
 * Each bank consists of 8 pools, which start off overlapping. Care must be
 * taken to not allocate from the wrong pool at the wrong time. In practice it
 * appears only two pools are used which makes this easy:
 *
 * MEMPOOL_PERMANENT (index 6) is for permanent data and is never cleared.
 * MEMPOOL_STAGE (index 4) is for general data and is cleared on stage load.
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
 *
 * Freeing individual allocations is not supported by memp. The only way to free
 * memp memory is to load a new stage which wipes the stage pool.
 */

struct memorypool {
	/*0x00*/ u8 *start;
	/*0x04*/ u8 *leftpos;
	/*0x08*/ u8 *rightpos;
	/*0x0c*/ u8 *end;
	/*0x10*/ u8 *prevallocation;
};

struct memorypool g_MempOnboardPools[9];
struct memorypool g_MempExpansionPools[9];

/**
 * Initialise memp by initialising the banks and pools.
 *
 * The arguments passed are the onboard start and length that can be used.
 * If the expansion pak is present, the entire pak is used for the second bank.
 */
void mempSetHeap(u8 *heapstart, u32 heaplen)
{
	s32 i;
	u8 *extraend;

	for (i = 0; i < 9; i++) {
		g_MempOnboardPools[i].start = 0;
		g_MempOnboardPools[i].leftpos = 0;
		g_MempOnboardPools[i].rightpos = 0;
		g_MempOnboardPools[i].prevallocation = 0;

		g_MempExpansionPools[i].start = 0;
		g_MempExpansionPools[i].leftpos = 0;
		g_MempExpansionPools[i].rightpos = 0;
		g_MempExpansionPools[i].prevallocation = 0;
	}

	g_MempOnboardPools[MEMPOOL_0].start = heapstart;
	g_MempOnboardPools[MEMPOOL_0].rightpos = heapstart + heaplen;
	g_MempOnboardPools[MEMPOOL_PERMANENT].start = heapstart;
	g_MempOnboardPools[MEMPOOL_PERMANENT].rightpos = heapstart + heaplen;
	g_MempOnboardPools[MEMPOOL_STAGE].start = heapstart;
	g_MempOnboardPools[MEMPOOL_STAGE].rightpos = heapstart + heaplen;

	// If 8MB, reserve the entire expansion pak for the stage pool
	extraend = (u8 *) K0BASE + g_OsMemSize - FRAMEBUFFER_SIZE;

	g_MempExpansionPools[MEMPOOL_STAGE].start = (u8 *) K0BASE + 4 * 1024 * 1024 + FRAMEBUFFER_SIZE;
	g_MempExpansionPools[MEMPOOL_STAGE].rightpos = extraend;

	for (i = 0; i < 9; i++) {
		g_MempOnboardPools[i].end = g_MempOnboardPools[i].rightpos;
		g_MempExpansionPools[i].end = g_MempExpansionPools[i].rightpos;
	}
}

/**
 * Return the amount of free space in the stage pool.
 *
 * If using the expansion pak, it's assumed that the onboard pool is full
 * so only the expansion pool is checked.
 */
u32 mempGetStageFree(void)
{
	u32 free;

	free = g_MempExpansionPools[MEMPOOL_STAGE].rightpos - g_MempExpansionPools[MEMPOOL_STAGE].leftpos;

	return free;
}

void *mempGetNextStageAllocation(void)
{
	void *next;

	next = g_MempExpansionPools[MEMPOOL_STAGE].leftpos;

	return next;
}

static void *mempAllocFromBank(struct memorypool *pool, u32 size, u8 poolnum)
{
	u8 *allocation;

	pool += poolnum;

	allocation = pool->leftpos;

	if (pool->leftpos == 0) {
		return allocation;
	}

	if (pool->leftpos > pool->rightpos) {
		return 0;
	}

	if (pool->leftpos + size > pool->rightpos) {
		return 0;
	}

	pool->leftpos += size;
	pool->prevallocation = allocation;

	if (1);

	return (void *)allocation;
}

extern u8 g_LvOom;
extern u32 g_LvOomSize;

void *mempAlloc(u32 len, u8 pool)
{
	void *allocation = mempAllocFromBank(g_MempOnboardPools, len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = mempAllocFromBank(g_MempExpansionPools, len, pool);

	if (allocation) {
		return allocation;
	}

	if (pool != MEMPOOL_8 && pool != MEMPOOL_7 && len) {
		g_LvOom = 'p';
		g_LvOomSize = len;
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
 * If it allocates past the rightpos of the pool it could lead to memory corruption.
 */
s32 mempRealloc(void *allocation, s32 newsize, u8 poolnum)
{
	struct memorypool *pool = &g_MempOnboardPools[poolnum];
	s32 origsize;
	s32 growsize;

	if (pool->prevallocation != allocation) {
		pool = &g_MempExpansionPools[poolnum];

		if (pool->prevallocation != allocation) {
			return 2;
		}
	}

	origsize = pool->leftpos - pool->prevallocation;
	growsize = newsize - origsize;

	if (growsize <= 0) {
		pool->leftpos += growsize;
		pool->leftpos = (u8 *)ALIGN16((u32)pool->leftpos);
		return 1;
	}

	pool->leftpos += growsize;
	return 1;
}

/**
 * Return the amount of free space in the given pool and bank.
 */
u32 mempGetPoolFree(u8 poolnum, u32 bank)
{
	struct memorypool *pool;

	if (bank == MEMBANK_ONBOARD) {
		pool = &g_MempOnboardPools[poolnum];
	} else {
		pool = &g_MempExpansionPools[poolnum];
	}

	return pool->rightpos - pool->leftpos;
}

/**
 * Reset the pool's left side to its start address, effectively freeing the left
 * side of the pool.
 *
 * If resetting the stage pool, close off the permanent pool and place the stage
 * pool immediately after it.
 *
 * Note the right side is not reset here.
 */
void mempResetPool(u8 pool)
{
	if (pool == MEMPOOL_STAGE) {
		g_MempOnboardPools[MEMPOOL_STAGE].start = g_MempOnboardPools[MEMPOOL_PERMANENT].leftpos;
		g_MempOnboardPools[MEMPOOL_PERMANENT].rightpos = g_MempOnboardPools[MEMPOOL_PERMANENT].leftpos;
		g_MempOnboardPools[MEMPOOL_PERMANENT].end = g_MempOnboardPools[MEMPOOL_PERMANENT].leftpos;
	}

	g_MempOnboardPools[pool].leftpos = g_MempOnboardPools[pool].start;
	g_MempExpansionPools[pool].leftpos = g_MempExpansionPools[pool].start;
	g_MempOnboardPools[pool].prevallocation = 0;
	g_MempExpansionPools[pool].prevallocation = 0;
}

/**
 * Setting leftpos to 0 means that this pool will refuse allocations from the
 * left.
 *
 * Setting rightpos to the end means it's resetting the right side and making
 * that available for allocations. It would have made more sense to do this in
 * mempResetPool instead.
 */
void mempDisablePool(u8 pool)
{
	g_MempOnboardPools[pool].leftpos = 0;
	g_MempExpansionPools[pool].leftpos = 0;
	g_MempOnboardPools[pool].rightpos = g_MempOnboardPools[pool].end;
	g_MempExpansionPools[pool].rightpos = g_MempExpansionPools[pool].end;
}

static void *mempAllocFromBankRight(struct memorypool *pool, u32 size, u8 poolnum)
{
	u8 *allocation;

	pool += poolnum;

	allocation = pool->rightpos;

	if (allocation == 0) {
		return allocation;
	}

	if (pool->rightpos < pool->leftpos) {
		return 0;
	}

	if (pool->rightpos - size < pool->leftpos) {
		return 0;
	}

	pool->rightpos -= size;

	return (void *)pool->rightpos;
}

void *mempAllocFromRight(u32 len, u8 pool)
{
	void *allocation = mempAllocFromBankRight(g_MempOnboardPools, len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = mempAllocFromBankRight(g_MempExpansionPools, len, pool);

	if (allocation) {
		return allocation;
	}

	return allocation;
}
