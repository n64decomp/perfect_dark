#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

void n_alEvtqNew(ALEventQueue *evtq, ALEventListItem *items, s32 itemCount)
{
	s32 i;

	evtq->eventCount     = 0;
	evtq->allocList.next = 0;
	evtq->allocList.prev = 0;
	evtq->freeList.next  = 0;
	evtq->freeList.prev  = 0;

	for (i = 0; i < itemCount; i++) {
		alLink((ALLink *)&items[i], &evtq->freeList);
	}
}

ALMicroTime n_alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt)
{
	ALEventListItem *item;
	ALMicroTime delta;
	OSIntMask mask;

	mask = osSetIntMask(OS_IM_NONE);

	item = (ALEventListItem *)evtq->allocList.next;

	if (item) {
		alUnlink((ALLink *)item);
		bcopy(&item->evt, evt, sizeof(*evt));
		alLink((ALLink *)item, &evtq->freeList);
		delta = item->delta;
	} else {
		/* sct 11/28/95 - If we get here, most like we overflowed the event queue */
		/* with non-self-perpetuating events.  Eg. if we filled the evtq with volume */
		/* events, then when the seqp is told to play it will handle all the events */
		/* at once completely emptying out the queue.  At this point this problem */
		/* must be treated as an out of resource error and the evtq should be increased. */
		evt->type = -1;
		delta = 0;
	}

	osSetIntMask(mask);

	return delta;
}

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta, s32 arg3)
{
	ALEventListItem *item;
	ALEventListItem *nextItem;
	ALLink *node;
	s32 postAtEnd = 0;
	OSIntMask mask;

	mask = osSetIntMask(OS_IM_NONE);

	item = (ALEventListItem *)evtq->freeList.next;

	if (!item) {
		osSetIntMask(mask);
		return;
	}

	if (!item->node.next && !arg3) {
		osSetIntMask(mask);
		return;
	}

	alUnlink((ALLink *)item);
	bcopy(evt, &item->evt, sizeof(*evt));

	if (delta == AL_EVTQ_END) {
		postAtEnd = -1;
	}

	for (node = &evtq->allocList; node != 0; node = node->next) {
		if (!node->next) { /* end of the list */
			if (postAtEnd) {
				item->delta = 0;
			} else {
				item->delta = delta;
			}

			alLink((ALLink *)item, node);
			break;
		} else {
			nextItem = (ALEventListItem *)node->next;

			if (delta < nextItem->delta) {
				item->delta = delta;
				nextItem->delta -= delta;

				alLink((ALLink *)item, node);
				break;
			}

			delta -= nextItem->delta;
		}
	}

	osSetIntMask(mask);
}

void n_alEvtqFlushType(ALEventQueue *evtq, s16 type)
{
	ALLink *thisNode;
	ALLink *nextNode;
	ALEventListItem *thisItem, *nextItem;
	OSIntMask mask;

	mask = osSetIntMask(OS_IM_NONE);

	thisNode = evtq->allocList.next;

	while (thisNode != 0) {
		nextNode = thisNode->next;
		thisItem = (ALEventListItem *)thisNode;
		nextItem = (ALEventListItem *)nextNode;

		if (thisItem->evt.type == type) {
			if (nextItem) {
				nextItem->delta += thisItem->delta;
			}

			alUnlink(thisNode);
			alLink(thisNode, &evtq->freeList);
		}

		thisNode = nextNode;
	}

	osSetIntMask(mask);
}
