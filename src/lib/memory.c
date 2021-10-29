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
void memInit(u8 *heapstart, u32 heaplen)
{
	s32 i;
	u8 *extraend;

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
#if VERSION >= VERSION_NTSC_1_0
	extraend = (u8 *)(0x80000000 + bootGetMemSize());
#else
	extraend = (u8 *)(0x80000000 + osGetMemSize());
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (bootGetMemSize() > 4 * 1024 * 1024)
#else
	if (osGetMemSize() > 4 * 1024 * 1024)
#endif
	{
		g_ExpansionMemoryPools[MEMPOOL_STAGE].start = (u8 *)0x80400000;
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

void *memGetNextPool4Allocation(void)
{
	void *next;

	if (IS4MB()) {
		next = g_OnboardMemoryPools[MEMPOOL_STAGE].leftpos;
	} else {
		next = g_ExpansionMemoryPools[MEMPOOL_STAGE].leftpos;
	}

	return next;
}

void *memAllocFromBank(struct memorypool *pool, u32 size, u8 poolnum)
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

void *malloc(u32 len, u8 pool)
{
	void *allocation = memAllocFromBank(g_OnboardMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = memAllocFromBank(g_ExpansionMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

#if VERSION < VERSION_NTSC_1_0
	if (pool != MEMPOOL_8 && pool != MEMPOOL_7 && len) {
		char buffer[80];
		u32 stack;
		u32 size;
		u32 free;

		if (pool == MEMPOOL_STAGE) {
			free = memGetFree(MEMPOOL_STAGE, MEMBANK_ONBOARD);
			size = memGetSize(MEMPOOL_STAGE, MEMBANK_ONBOARD);
			sprintf(buffer, "Out of mem - LEV: %d f %d s %d", len, free, size);
		} else {
			free = memGetFree(MEMPOOL_PERMANENT, MEMBANK_ONBOARD);
			size = memGetSize(MEMPOOL_PERMANENT, MEMBANK_ONBOARD);
			sprintf(buffer, "Out of mem - ETR: %d f %d s %d", len, free, size);
		}

		func0000c1d0nb(buffer);
		CRASH();
	}
#endif

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
s32 memReallocate(void *allocation, s32 newsize, u8 poolnum)
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
		pool->leftpos = (u8 *)ALIGN16((u32)pool->leftpos);
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
u32 memGetSize(u8 poolnum, u32 bank)
{
	struct memorypool *pool;

	if (bank == MEMBANK_ONBOARD) {
		pool = &g_OnboardMemoryPools[poolnum];
	} else {
		pool = &g_ExpansionMemoryPools[poolnum];
	}

	return pool->rightpos - pool->start;
}
#endif

#if VERSION < VERSION_NTSC_1_0
void *memAllocFromPackedWord(u32 word)
{
	return malloc(word >> 4, word & 0x0f);
}
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

void *memAllocFromBankRight(struct memorypool *pool, u32 size, u8 poolnum)
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

void *mallocFromRight(u32 len, u8 pool)
{
	void *allocation = memAllocFromBankRight(g_OnboardMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = memAllocFromBankRight(g_ExpansionMemoryPools, len, pool);

	if (allocation) {
		return allocation;
	}

	return allocation;
}
