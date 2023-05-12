#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/mema.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

/**
 * mema - memory (ad hoc) allocation system.
 *
 * Mema's heap is 300KB and is itself allocated out of memp's stage pool.
 * Memp resets its stage pool each time a new stage is loaded, which means mema
 * is also reset each time a stage is loaded.
 *
 * Unlike memp, mema supports freeing of individual allocations. This makes it
 * a good system to use when the allocation is somewhat temporary and should be
 * freed without having to load a new stage. It's used by the (inaccessible)
 * Perfect Head editor, file listings and room code.
 *
 * Mema tracks what has been allocated by storing references to free spaces in
 * its spaces array. The allocations themselves are not referenced. When
 * initialising the spaces array, the first element is set to the entire heap
 * and the remaining elements are set to 0.
 *
 * This creates a bit of a terminology problem. Just remember that a memaspace
 * is not an allocation; it's a free space that is available for allocation.
 *
 * Due to the ability to free individual allocations, both the heap and the
 * spaces array can become fragmented. Mema supports defragmenting the spaces
 * array: entries are ordered by address, and back to back entries are merged.
 * The data in the heap itself is never moved, as that would require updating
 * pointers throughout the game code which mema cannot do.
 */

#define MAX_SPACES 124

struct memaspace {
	s32 addr;
	u32 size;
};

/**
 * This structure contains dummy entries before and after the spaces array.
 * These are used as start and end markers, but could have been avoided by
 * using loop counters (eg. a typical i < numspaces loop).
 */
struct memaheap {
	u32 unk000;
	struct memaspace start;
	struct memaspace spaces[MAX_SPACES];
	struct memaspace end1;
	struct memaspace end2;
};

s32 g_MemaHeapStart;
s32 g_MemaHeapSize;
struct memaheap g_MemaHeap;

static void memaSwap(struct memaspace *a, struct memaspace *b)
{
	u32 tempaddr = a->addr;
	u32 tempsize = a->size;
	a->addr = b->addr;
	a->size = b->size;
	b->addr = tempaddr;
	b->size = tempsize;
}

static void memaMerge(struct memaspace *a, struct memaspace *b)
{
	a->size += b->size;
	b->addr = 0;
	b->size = 0;
}

static bool memaDefragPass(struct memaheap *heap)
{
	bool merged = false;
	struct memaspace *prev = &heap->start;
	struct memaspace *curr = &heap->spaces[0];
	struct memaspace *last = &heap->spaces[MAX_SPACES - 1];
	u32 addr = 0;

	while (curr <= last) {
		if (curr->size != 0) {
			if (curr->addr < addr) {
				memaSwap(curr, prev);
			}

			if (prev->size + addr == curr->addr) {
				memaMerge(prev, curr);
				curr = prev;
				merged = true;
			}

			prev = curr;
			addr = curr->addr;
		}

		curr++;
	}

	return merged;
}

void memaDefrag(void)
{
	while (memaDefragPass(&g_MemaHeap));
}

/**
 * Defrag the spaces list in an attempt to free up any slot.
 *
 * If none can be found, return the smallest run of free space so it can be
 * overwritten by the caller.
 */
static struct memaspace *memaMakeSlot(struct memaheap *heap)
{
	struct memaspace *curr = &heap->spaces[0];
	struct memaspace *best;
	u32 min;
	s32 i;

	// Do 124 passes over the list. This ensures the list is in order by the
	// end. Though in most cases it's roughly in order anyway, and the excessive
	// looping is just wasting CPU cycles. In reality this situation probably
	// never occurs.
	for (i = 0; i < MAX_SPACES; i++) {
		while (curr <= &heap->spaces[MAX_SPACES - 1]) {
			if (curr->size == 0) {
				return curr;
			}

			if ((u32)curr[1].addr < (u32)curr[0].addr) {
				memaSwap(&curr[0], &curr[1]);
			}

			if (curr[1].addr == curr[0].size + curr[0].addr) {
				// Found two that can be merged
				curr[0].size += curr[1].size;
				curr[1].addr = 0;
				curr[1].size = 0;

				return &curr[1];
			}

			curr++;
		}

		curr = &heap->spaces[0];
	}

	// If this code is reached then the spaces list is so badly and unrepairably
	// fragmented that we can't find any slot to record the free space in.
	// Find the smallest run of free space and use that instead.
	// The caller will overwrite it with its own free allocation, causing the
	// original run of free space to be unusable until the mema heap is reset.
	min = 0xffffffff;
	best = curr;

	while (curr <= &heap->spaces[MAX_SPACES - 1]) {
		if (curr->size < min) {
			best = curr;
			min = curr->size;
		}

		curr++;
	}

	return best;
}

static void _memaFree(s32 addr, s32 size)
{
	// Choose an index in the spaces array which we'll mark a space as free,
	// based on how far into the heap the allocation is. This is a rough
	// estimate and doesn't need to be any particular index, but the defrag
	// function tries to order the spaces by address so the closer we get to it
	// the less work the defrag function will have to do should it be called.
	s32 index = (addr - g_MemaHeapStart) * MAX_SPACES / g_MemaHeapSize;
	struct memaspace *curr = &g_MemaHeap.spaces[index];

	// If the entry is taken, keep moving forward until a zero is found.
	while (curr->size != 0) {
		curr++;
	}

	// If we reached the end of the spaces list, go backwards instead
	if (curr->addr == -1) {
		curr = &g_MemaHeap.spaces[index];

		while (curr->size != 0) {
			curr--;
		}

		if (curr->addr == 0) {
			curr = memaMakeSlot(&g_MemaHeap);
		}
	}

	// Mark this space as free
	curr->addr = addr;
	curr->size = size;
}

void memaReset(void *heapaddr, u32 heapsize)
{
	struct memaspace *space;

	g_MemaHeap.unk000 = 0;

	g_MemaHeap.start.addr = 0;
	g_MemaHeap.start.size = 0;

	g_MemaHeap.end1.addr = 0xffffffff;
	g_MemaHeap.end1.size = 0;
	g_MemaHeap.end2.addr = 0xffffffff;
	g_MemaHeap.end2.size = 0xffffffff;

	for (space = &g_MemaHeap.spaces[0]; space <= &g_MemaHeap.spaces[MAX_SPACES - 1]; space++) {
		space->addr = 0;
		space->size = 0;
	}

	g_MemaHeap.spaces[0].addr = g_MemaHeapStart = (u32)heapaddr;
	g_MemaHeap.spaces[0].size = g_MemaHeapSize = heapsize;
}

void *memaAlloc(u32 size)
{
	u32 addr;
	u32 diff;
	s32 i;

	struct memaspace *curr = &g_MemaHeap.spaces[0];
	u32 bestdiff = 0xffffffff;
	struct memaspace *best = NULL;

	// Iterate up to the first 16 spaces, looking for the
	// smallest space that will accommodate the requested size.
	for (i = 0; i < 16; i++) {
		if (curr->size >= size) {
			if (curr->addr == 0xffffffff) {
				// Reached the end
				break;
			}

			diff = curr->size - size;

			if (diff < bestdiff) {
				bestdiff = diff;
				best = curr;

				// Stop looking if the space is small enough
				if (diff < 64 || diff < size / 4) {
					break;
				}
			}
		}

		curr++;
	}

	if (best == NULL) {
		// Keep iterating until we find a space that is big enough to fit.
		// The last space is marked as size 0xffffffff which prevents this loop
		// from iterating past the end of the spaces array.
		while (curr->size < size) {
			curr++;
		}

		if (curr->addr == 0xffffffff) {
			// There was no space, so attempt to free up some space
			// by doing several defrag passes
			for (i = 0; i < 8; i++) {
				memaDefragPass(&g_MemaHeap);
			}

			curr = &g_MemaHeap.spaces[0];

			while (curr->size < size) {
				curr++;
			}

			if (curr->addr == 0xffffffff) {
				return NULL;
			}
		}

		best = curr;
	}

	addr = best->addr;
	best->addr += size;
	best->size -= size;

	if (best->size == 0) {
		best->addr = 0;
	}

	return (void *)addr;
}

/**
 * Grow the allocation which currently *ends at* the given address.
 */
static s32 memaGrow(s32 addr, u32 amount)
{
	struct memaspace *curr = &g_MemaHeap.spaces[0];

	while (curr->addr != -1) {
		if (curr->addr == addr && curr->size >= amount) {
			goto found;
		}

		curr++;
	}

	return 0;

found:
	curr->addr += amount;
	curr->size -= amount;

	if (curr->size == 0) {
		curr->addr = 0;
	}

	return addr;
}

void memaFree(void *addr, s32 size)
{
	_memaFree((u32)addr, size);
}

/**
 * Find and return the largest amount of contiguous free space in the pool.
 * ie. the biggest allocation that mema can currently make.
 */
s32 memaGetLongestFree(void)
{
	struct memaspace *curr;
	s32 biggest = 0;

	memaDefrag();

	curr = &g_MemaHeap.spaces[0];

	while (curr->addr != -1) {
		if (curr->size > biggest) {
			biggest = curr->size;
		}

		curr++;
	}

	if (biggest) {
		return biggest;
	}

	return 0;
}

bool memaRealloc(s32 addr, u32 oldsize, u32 newsize)
{
	if (newsize > oldsize) {
		if (!memaGrow(addr + oldsize, newsize - oldsize)) {
			return false;
		}
	} else if (oldsize > newsize) {
		memaFree((void *)(addr + newsize), oldsize - newsize);
	}

	return true;
}
