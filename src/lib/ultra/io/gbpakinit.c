#include <os_internal.h>
#include "controller.h"
#include "siint.h"

OSTimer var80090ab0;
OSMesgQueue g_GbpakMesgQueue;
OSMesg g_GbpakMesg;

s32 osGbpakInit(OSMesgQueue *queue, OSPfs *pfs, int channel)
{
	s32 ret;
	s32 i;
	u8 buffer[32];

	pfs->status = 0;

	for (i = 0; i < 32; i++) {
		buffer[i] = 0xfe;
	}

	ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(queue, channel, 0x400, buffer);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (buffer[31] == 0xfe) {
		return PFS_ERR_DEVICE;
	}

	for (i = 0; i < 32; i++) {
		buffer[i] = 0x84;
	}

	ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(queue, channel, 0x400, buffer);

	if (ret == 2) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (buffer[31] != 0x84) {
		return PFS_ERR_DEVICE;
	}

	ret = __osPfsGetStatus(queue, channel);

	if (ret != 0) {
		return ret;
	}

	osCreateMesgQueue(&g_GbpakMesgQueue, &g_GbpakMesg, 1);
	osSetTimer(&var80090ab0, OS_CPU_COUNTER / 50, 0, &g_GbpakMesgQueue, &g_GbpakMesg);
	osRecvMesg(&g_GbpakMesgQueue, 0, OS_MESG_BLOCK);

	pfs->queue = queue;
	pfs->status = PFS_GBPAK_INITIALIZED;
	pfs->channel = channel;
	pfs->activebank = 132;
	pfs->banks = 255;
	pfs->version = 255;
	pfs->dir_size = 255;

	return 0;
}
