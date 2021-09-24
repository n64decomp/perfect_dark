#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/game_0b69d0.h"
#include "game/savebuffer.h"
#include "game/bossfile.h"
#include "game/bg.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_0bfb0.h"
#include "lib/snd.h"
#include "lib/lib_126b0.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

u8 var800a22d0[0x5b];
s8 g_AltTitleUnlocked;
u8 g_AltTitleEnabled;

void bossfileSetDefaults2(void)
{
	bossfileSetDefaults();
}

void bossfileSetAndSaveDefaults(void)
{
	bossfileSetDefaults();
	bossfileSave();
}

bool bossfileLoadFull(void)
{
	bossfileLoad();

#if PAL
	func0f16f75c(g_Vars.unk000482);
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

u32 bossfileFindFileId(void)
{
	struct pakfileheader header;
	u32 fileids[513];
	u32 candidate = 0;
	s32 i;

	if (pakGetFileIdsByType(SAVEDEVICE_GAMEPAK, PAKFILETYPE_BOSS, fileids) == 0) {
		for (i = 0; fileids[i] != 0; i++) {
			pakFindFile(SAVEDEVICE_GAMEPAK, fileids[i], &header);

			if (!header.occupied) {
				candidate = fileids[i];
				break;
			}
		}

		for (i = 0; fileids[i] != 0; i++) {
			pakFindFile(SAVEDEVICE_GAMEPAK, fileids[i], &header);

			if (header.occupied) {
				candidate = fileids[i];
				break;
			}
		}
	}

	return candidate;
}

void bossfileLoad(void)
{
	bool failed = false;
	struct savebuffer buffer;
	s32 i;
	s32 fileid;
	struct fileguid guid;

	fileid = bossfileFindFileId();

	if (fileid == 0) {
		failed = true;
	} else {
		savebufferClear(&buffer);

		if (pakReadBodyAtGuid(SAVEDEVICE_GAMEPAK, fileid, buffer.bytes, 0) != 0) {
			failed = true;
		}
	}

	if (!failed) {
		u8 tracknum;

		savebufferReadGuid(&buffer, &guid);

		g_Vars.bossfileid = guid.fileid;
		g_Vars.bossdeviceserial = guid.deviceserial;

		g_BossFile.unk89 = savebufferReadBits(&buffer, 1);

		g_Vars.unk000482 = savebufferReadBits(&buffer, 4);

		for (i = 0; i < 8; i++) {
			savebufferReadString(&buffer, g_BossFile.teamnames[i], 1);
		}

		tracknum = savebufferReadBits(&buffer, 8);

		if (tracknum == 0xff) {
			g_BossFile.tracknum = -1;
		} else {
			g_BossFile.tracknum = tracknum;
		}

		for (i = 0; i < 6; i++) {
			g_BossFile.multipletracknums[i] = savebufferReadBits(&buffer, 8);
		}

		g_BossFile.usingmultipletunes = savebufferReadBits(&buffer, 1);
		g_AltTitleUnlocked = savebufferReadBits(&buffer, 1);
		g_AltTitleEnabled = savebufferReadBits(&buffer, 1);

		func0f0d54c4(&buffer);
	}

	if (failed) {
		bossfileSetDefaults();
		bossfileSave();
	}
}

void bossfileSave(void)
{
	volatile bool sp12c = false;
	struct savebuffer buffer;
	struct fileguid guid;
	u32 stack;
	s32 i;
	s32 fileid;

	savebufferClear(&buffer);

	guid.fileid = g_Vars.bossfileid;
	guid.deviceserial = g_Vars.bossdeviceserial;

	savebufferWriteGuid(&buffer, &guid);

	savebufferOr(&buffer, g_BossFile.unk89, 1);
	savebufferOr(&buffer, g_Vars.unk000482, 4);

	for (i = 0; i < 8; i++) {
		func0f0d55a4(&buffer, g_BossFile.teamnames[i]);
	}

	if (g_BossFile.tracknum == -1) {
		savebufferOr(&buffer, 0xff, 8);
	} else {
		savebufferOr(&buffer, g_BossFile.tracknum, 8);
	}

	for (i = 0; i < 6; i++) {
		savebufferOr(&buffer, g_BossFile.multipletracknums[i], 8);
	}

	savebufferOr(&buffer, g_BossFile.usingmultipletunes, 1);
	savebufferOr(&buffer, (u8)g_AltTitleUnlocked, 1);
	savebufferOr(&buffer, g_AltTitleEnabled, 1);

	func0f0d54c4(&buffer);

	fileid = bossfileFindFileId();

	if (fileid == 0) {
		faultAssert("fileGuid", "bossfile.c", PAL ? 377 : 375);
	}

	if (pakSaveAtGuid(SAVEDEVICE_GAMEPAK, fileid, PAKFILETYPE_BOSS, buffer.bytes, NULL, 0) != 0) {
		sp12c = true;
	}
}

void bossfileSetDefaults(void)
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
	mpEnableAllMultiTracks();
	g_BossFile.usingmultipletunes = false;
	g_BossFile.unk89 = 0;
	g_BossFile.locktype = MPLOCKTYPE_NONE;
	g_Vars.bossfileid = 0;
	g_Vars.bossdeviceserial = 0;
	g_Vars.unk000482 = (PAL ? 7 : 0);
	g_AltTitleUnlocked = 0;
	g_AltTitleEnabled = false;

	bossfileSave();
}
