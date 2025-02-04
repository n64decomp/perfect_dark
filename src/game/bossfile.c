#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/lang.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/bossfile.h"
#include "game/bg.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/fault.h"
#include "lib/snd.h"
#include "data.h"
#include "types.h"

u8 var800a22d0[0x5b];
u8 g_AltTitleUnlocked;
u8 g_AltTitleEnabled;

void bossfile_load(void);
void bossfile_set_defaults(void);

void bossfile_set_defaults2(void)
{
	bossfile_set_defaults();
}

void bossfile_set_and_save_defaults(void)
{
	bossfile_set_defaults();
	bossfile_save();
}

bool bossfile_load_full(void)
{
	bossfile_load();

#if VERSION >= VERSION_PAL_BETA
	lang_set_european(g_Vars.language);
#endif

	return true;
}

void func0f1106ec(void)
{
	// empty
}

void func0f1106f4(u8 *dst)
{
	bcopy(var800a22d0, dst, sizeof(var800a22d0));
}

u32 bossfile_find_file_id(void)
{
	struct pakfileheader header;
	u32 fileids[513];
	u32 candidate = 0;
	s32 i;

	if (pak_get_file_ids_by_type(SAVEDEVICE_GAMEPAK, PAKFILETYPE_BOSS, fileids) == 0) {
		for (i = 0; fileids[i] != 0; i++) {
			pak_find_file(SAVEDEVICE_GAMEPAK, fileids[i], &header);

			if (!header.occupied) {
				candidate = fileids[i];
				break;
			}
		}

		for (i = 0; fileids[i] != 0; i++) {
			pak_find_file(SAVEDEVICE_GAMEPAK, fileids[i], &header);

			if (header.occupied) {
				candidate = fileids[i];
				break;
			}
		}
	}

	return candidate;
}

void bossfile_load(void)
{
	bool failed = false;
	struct savebuffer buffer;
	s32 i;
	s32 fileid;
	struct fileguid guid;

	fileid = bossfile_find_file_id();

	if (fileid == 0) {
		failed = true;
	} else {
		savebuffer_reset(&buffer);

		if (pak_read_body_at_guid(SAVEDEVICE_GAMEPAK, fileid, buffer.bytes, 0) != 0) {
			failed = true;
		}
	}

	if (!failed) {
		u8 tracknum;

		savebuffer_read_guid(&buffer, &guid);

		g_Vars.bossfileid = guid.fileid;
		g_Vars.bossdeviceserial = guid.deviceserial;

		g_BossFile.unk89 = savebuffer_read_bits(&buffer, 1);

		g_Vars.language = savebuffer_read_bits(&buffer, 4);

		for (i = 0; i < ARRAYCOUNT(g_BossFile.teamnames); i++) {
			savebuffer_read_string(&buffer, g_BossFile.teamnames[i], 1);
		}

		tracknum = savebuffer_read_bits(&buffer, 8);

		if (tracknum == 0xff) {
			g_BossFile.tracknum = -1;
		} else {
			g_BossFile.tracknum = tracknum;
		}

		for (i = 0; i < ARRAYCOUNT(g_BossFile.multipletracknums); i++) {
			g_BossFile.multipletracknums[i] = savebuffer_read_bits(&buffer, 8);
		}

		g_BossFile.usingmultipletunes = savebuffer_read_bits(&buffer, 1);
		g_AltTitleUnlocked = savebuffer_read_bits(&buffer, 1);
		g_AltTitleEnabled = savebuffer_read_bits(&buffer, 1);

		savebuffer_print(&buffer);
	}

	if (failed) {
		bossfile_set_defaults();
		bossfile_save();
	}
}

void bossfile_save(void)
{
	volatile bool sp12c = false;
	struct savebuffer buffer;
	struct fileguid guid;
	u32 stack;
	s32 i;
	s32 fileid;

	savebuffer_reset(&buffer);

	guid.fileid = g_Vars.bossfileid;
	guid.deviceserial = g_Vars.bossdeviceserial;

	savebuffer_write_guid(&buffer, &guid);

	savebuffer_write_bits(&buffer, g_BossFile.unk89, 1);
	savebuffer_write_bits(&buffer, g_Vars.language, 4);

	for (i = 0; i < ARRAYCOUNT(g_BossFile.teamnames); i++) {
		savebuffer_write_string(&buffer, g_BossFile.teamnames[i]);
	}

	if (g_BossFile.tracknum == -1) {
		savebuffer_write_bits(&buffer, 0xff, 8);
	} else {
		savebuffer_write_bits(&buffer, g_BossFile.tracknum, 8);
	}

	for (i = 0; i < ARRAYCOUNT(g_BossFile.multipletracknums); i++) {
		savebuffer_write_bits(&buffer, g_BossFile.multipletracknums[i], 8);
	}

	savebuffer_write_bits(&buffer, g_BossFile.usingmultipletunes, 1);
	savebuffer_write_bits(&buffer, g_AltTitleUnlocked, 1);
	savebuffer_write_bits(&buffer, g_AltTitleEnabled, 1);

	savebuffer_print(&buffer);

	fileid = bossfile_find_file_id();

	if (fileid == 0) {
		fault_assert("fileGuid", "bossfile.c", VERSION >= VERSION_PAL_BETA ? 377 : 375);
	}

	if (pak_save_at_guid(SAVEDEVICE_GAMEPAK, fileid, PAKFILETYPE_BOSS, buffer.bytes, NULL, 0) != 0) {
		sp12c = true;
	}
}

void bossfile_set_defaults(void)
{
	g_BossFile.teamnames[0][0] = '\0';
	g_BossFile.teamnames[1][0] = '\0';
	g_BossFile.teamnames[2][0] = '\0';
	g_BossFile.teamnames[3][0] = '\0';
	g_BossFile.teamnames[4][0] = '\0';
	g_BossFile.teamnames[5][0] = '\0';
	g_BossFile.teamnames[6][0] = '\0';
	g_BossFile.teamnames[7][0] = '\0';

	g_BossFile.tracknum = -1;
	mp_enable_all_multi_tracks();
	g_BossFile.usingmultipletunes = false;
	g_BossFile.unk89 = 0;
	g_BossFile.locktype = MPLOCKTYPE_NONE;
	g_Vars.bossfileid = 0;
	g_Vars.bossdeviceserial = 0;
	g_Vars.language = (PAL ? 7 : 0);
	g_AltTitleUnlocked = 0;
	g_AltTitleEnabled = false;

	bossfile_save();
}
