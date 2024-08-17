#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

extern u8 *g_LangBuffer;
extern s32 g_LangBufferSize;

void lang_reset(s32 stagenum)
{
	s32 i;
	s32 size;

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		g_LangBanks[i] = NULL;
	}

#if VERSION >= VERSION_PAL_BETA
	// PAL and newer have to support switching languages mid-stage. To do this,
	// lang_reload iterates the bank pointers and reloads them if they're
	// non-zero. Here it's using lang_reload to do the initial load by setting
	// the desired banks to dummy (non-zero) values so lang_reload will load them.
	g_LangBanks[LANGBANK_GUN] = (void *)1;
	g_LangBanks[LANGBANK_MPMENU] = (void *)1;
	g_LangBanks[LANGBANK_PROPOBJ] = (void *)1;
	g_LangBanks[LANGBANK_MPWEAPONS] = (void *)1;
	g_LangBanks[LANGBANK_OPTIONS] = (void *)1;
	g_LangBanks[LANGBANK_MISC] = (void *)1;

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = (void *)1;
	}

	if (stagenum == STAGE_CITRAINING) {
		size = 108000;
	} else {
		size = 56000;

		if (IS8MB()) {
			size = 68000;
		}
	}

	g_LangBuffer = memp_alloc(ALIGN16(size), MEMPOOL_STAGE);
	g_LangBufferSize = size;

	lang_reload();
#else
	// Versions prior to PAL load the language directly
	g_LangBanks[LANGBANK_GUN] = file_load_to_new(lang_get_file_id(LANGBANK_GUN), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPMENU] = file_load_to_new(lang_get_file_id(LANGBANK_MPMENU), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_PROPOBJ] = file_load_to_new(lang_get_file_id(LANGBANK_PROPOBJ), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPWEAPONS] = file_load_to_new(lang_get_file_id(LANGBANK_MPWEAPONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_OPTIONS] = file_load_to_new(lang_get_file_id(LANGBANK_OPTIONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MISC] = file_load_to_new(lang_get_file_id(LANGBANK_MISC), FILELOADMETHOD_DEFAULT);

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = file_load_to_new(lang_get_file_id(LANGBANK_TITLE), FILELOADMETHOD_DEFAULT);
	}
#endif
}
