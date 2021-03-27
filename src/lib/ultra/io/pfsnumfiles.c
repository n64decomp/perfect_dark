#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osPfsNumFiles(OSPfs *pfs, s32 *max_files, s32 *files_used)
{
	int j;
	s32 ret;
	__OSDir dir;
	int files;

	files = 0;

	if ((pfs->status & PFS_INITIALIZED) == 0) {
		return PFS_ERR_INVALID;
	}

	ERRCK(__osCheckId(pfs));

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	for (j = 0; j < pfs->dir_size; j++) {
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&dir));

		if (dir.company_code != 0 && dir.game_code != 0) {
			files++;
		}
	}

	*files_used = files;
	*max_files = pfs->dir_size;

	return __osPfsGetStatus(pfs->queue, pfs->channel);
}
