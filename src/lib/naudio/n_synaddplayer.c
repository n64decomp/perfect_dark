#include <os_internal.h>
#include "n_synthInternals.h"

void n_alSynAddSndPlayer(ALPlayer *client)
{
	OSIntMask mask = osSetIntMask(OS_IM_NONE);

	client->samplesLeft = n_syn->curSamples;

	client->next = n_syn->head;
	n_syn->head = client;

	osSetIntMask(mask);
}

void n_alSynAddSeqPlayer(ALPlayer *client)
{
	OSIntMask mask = osSetIntMask(OS_IM_NONE);

	client->samplesLeft = n_syn->curSamples;

	client->next = n_syn->head;
	n_syn->head = client;

	osSetIntMask(mask);
}
