#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/audiodma.h"
#include "data.h"
#include "types.h"

#define ADMA_MAX_ITEMS 80
#define ADMA_ITEM_SIZE 0x400

struct admaitem {
	ALLink node;
	s32 startaddr;
	s32 lastframe;
	u8 *ptr;
};

struct admastate {
	u8 initialised;
	struct admaitem *firstused;
	struct admaitem *firstfree;
};

s32 g_AdmaNumItemsThisFrame = 0;

struct admastate g_AdmaState;
struct admaitem g_AdmaItems[ADMA_MAX_ITEMS];
OSIoMesg g_AdmaIoMsgs[ADMA_MAX_ITEMS];
OSMesgQueue g_AdmaMesgQueue;
OSMesg g_AdmaMesgs[ADMA_MAX_ITEMS];
u32 g_AdmaCurFrame;

void admaInit(void)
{
	osCreateMesgQueue(&g_AdmaMesgQueue, g_AdmaMesgs, ARRAYCOUNT(g_AdmaMesgs));
}

/**
 * This routine handles the DMA'ing of samples from ROM to RAM. First it checks
 * the current buffers to see if the samples needed are already in place.
 * Because buffers are linked sequentially by the addresses where the samples
 * are on ROM, it doesn't need to check all of them, only up to the address that
 * that it needs. If it finds one, it returns the address of that buffer. If it
 * doesn't find the samples that it needs, it will initiate a DMA of the samples
 * that it needs. In either case, it updates the lastframe variable, to indicate
 * that this buffer was last used in this frame. This is important for the
 * admaBeginFrame routine.
 */
static s32 admaExec(s32 offset, s32 len, void *state)
{
	void *foundbuffer;
	s32 delta;
	struct admaitem *item = g_AdmaState.firstused;
	struct admaitem *lastitem = NULL;
	s32 end = offset + len;
	s32 buffend;

	// Check to see if a buffer already contains the sample
	while (item) {
		buffend = item->startaddr + ADMA_ITEM_SIZE;

		if (item->startaddr > offset) {
			break;
		}

		if (end <= buffend) {
			item->lastframe = g_AdmaCurFrame;
			foundbuffer = item->ptr + offset - item->startaddr;

			return osVirtualToPhysical(foundbuffer);
		}

		lastitem = item;
		item = (struct admaitem *) item->node.next;
	}

	// We'll have to DMA it
	item = g_AdmaState.firstfree;

	// If there are no free slots, the N64 SDK's demo program instructs you to
	// "send back a bogus pointer, it's better than nothing".
	// @bug: This can make incorrect audio play when the DMA queue is full.
	if (item == NULL) {
		return osVirtualToPhysical(g_AdmaState.firstused);
	}

	g_AdmaState.firstfree = (struct admaitem *) item->node.next;
	alUnlink(&item->node);

	if (lastitem) {
		// Insert in the middle or at the tail of the list.
		// (The list is sorted by ROM offset, and lastitem is the
		// last item prior to the ROM offset of the current DMA.)
		alLink(&item->node, &lastitem->node);
	} else if (g_AdmaState.firstused) {
		// Prepend to the head of the list
		lastitem = g_AdmaState.firstused;
		g_AdmaState.firstused = item;
		item->node.next = &lastitem->node;
		item->node.prev = NULL;
		lastitem->node.prev = &item->node;
	} else {
		// The list was empty
		g_AdmaState.firstused = item;
		item->node.next = NULL;
		item->node.prev = NULL;
	}

	foundbuffer = item->ptr;
	delta = offset & 1;
	offset -= delta;
	item->startaddr = offset;
	item->lastframe = g_AdmaCurFrame;

	osInvalDCache((void *) PHYS_TO_K0(offset), ADMA_ITEM_SIZE);

	osPiStartDma(&g_AdmaIoMsgs[g_AdmaNumItemsThisFrame++], OS_MESG_PRI_HIGH, OS_READ, offset, foundbuffer, ADMA_ITEM_SIZE, &g_AdmaMesgQueue);

	return osVirtualToPhysical(foundbuffer) + delta;
}

/**
 * Initialize the DMA buffers and return the address of the procedure that will
 * be used to DMA the samples from ROM to RAM. This routine will be called once
 * for each physical voice that is created. In this case, because we know where
 * all the buffers are, and since they are not attached to a specific voice, we
 * will only really do any initialization the first time. After that we just
 * return the address to the DMA routine.
 */
void *admaNew(struct admastate **state)
{
	s32 max = ADMA_MAX_ITEMS;
	s32 i;

	if (!g_AdmaState.initialised) {
		g_AdmaState.firstfree = g_AdmaItems;

		for (i = 0; i < max - 1; i++) {
			alLink(&g_AdmaItems[i + 1].node, &g_AdmaItems[i].node);
			g_AdmaItems[i].ptr = alHeapAlloc(&g_SndHeap, 1, ADMA_ITEM_SIZE);
		}

		g_AdmaState.initialised = true;
	}

	*state = &g_AdmaState;

	return &admaExec;
}

/**
 * Remove old items from the list, increment the
 * frame counter and reset the number of items to 0.
 */
void admaBeginFrame(void)
{
	struct admaitem *item = g_AdmaState.firstused;

	while (item) {
		struct admaitem *next = (struct admaitem *) item->node.next;

		// If item->lastframe is 0xfffffffe then that value + 1 will never
		// be less than g_AdmaCurFrame and the item would never be removed from
		// the list. But it would take over 2 years of play time for this
		// situation to occur, so not flagging this as a bug.
		if (item->lastframe + 1 < g_AdmaCurFrame) {
			// Remove it
			if (g_AdmaState.firstused == item) {
				g_AdmaState.firstused = (struct admaitem *) item->node.next;
			}

			alUnlink(&item->node);

			if (g_AdmaState.firstfree) {
				alLink(&item->node, &g_AdmaState.firstfree->node);
			} else {
				g_AdmaState.firstfree = item;
				item->node.next = NULL;
				item->node.prev = NULL;
			}
		}

		item = next;
	}

	g_AdmaCurFrame++;
	g_AdmaNumItemsThisFrame = 0;
}

/**
 * Receive all messages from the message queue.
 *
 * The message queue isn't really used. The audio DMA system just wants to fire
 * off DMA requests and then forget about them. If the data arrives in time for
 * playback then great, otherwise nothing can be done. But osPiStartDma requires
 * a message queue, and that means the messages have to be read off it at some
 * point. This is done here.
 */
void admaReceiveAll(void)
{
	s32 i;

	/**
	 * Don't block here. If dma's aren't complete, you've had an audio
	 * overrun. Bad news, but go for it anyway, and try and recover.
	 */
	for (i = 0; i < g_AdmaNumItemsThisFrame; i++) {
		if (osRecvMesg(&g_AdmaMesgQueue, 0, OS_MESG_NOBLOCK) == -1) {
			// empty
		}
	}
}
