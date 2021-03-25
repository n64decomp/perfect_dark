#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no)
{
	s32 j;
	s32 i;
	__OSDir dir;
	s32 ret = 0;
	s32 err;

	if (!(pfs->status & PFS_INITIALIZED)) {
		return PFS_ERR_INVALID;
	}

	if ((ret = __osCheckId(pfs)) != 0) {
		return ret;
	}

	for (j = 0; j < pfs->dir_size; j++) {
		if ((ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&dir)) != 0) {
			return ret;
		}

		if ((ret = __osPfsGetStatus(pfs->queue, pfs->channel)) != 0) {
			return ret;
		}

		if (dir.company_code == company_code && dir.game_code == game_code) {
			err = 0;

			if (game_name != NULL) {
				for (i = 0; i < PFS_FILE_NAME_LEN; i++) {
					if (dir.game_name[i] != game_name[i]) {
						err = 1;
						break;
					}
				}
			}

			if (ext_name != NULL && err == 0) {
				for (i = 0; i < PFS_FILE_EXT_LEN; i++) {
					if (dir.ext_name[i] != ext_name[i]) {
						err = 1;
						break;
					}
				}
			}

			if (err == 0) {
				*file_no = j;
				return ret;
			}
		}
	}

	*file_no = -1;

	return PFS_ERR_INVALID;
}
