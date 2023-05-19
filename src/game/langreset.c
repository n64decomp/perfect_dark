#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u16 g_LangFiles[] = {
	/* 0*/ 0,
	/* 1*/ FILE_LAMEE,
	/* 2*/ FILE_LARCHE,
	/* 3*/ FILE_LARKE,
	/* 4*/ FILE_LASHE,
	/* 5*/ FILE_LAZTE,
	/* 6*/ FILE_LCATE,
	/* 7*/ FILE_LCAVEE,
	/* 8*/ FILE_LARECE,
	/* 9*/ FILE_LCRADE,
	/*10*/ FILE_LCRYPE,
	/*11*/ FILE_LDAME,
	/*12*/ FILE_LDEPOE,
	/*13*/ FILE_LDESTE,
	/*14*/ FILE_LDISHE,
	/*15*/ FILE_LEARE,
	/*16*/ FILE_LELDE,
	/*17*/ FILE_LIMPE,
	/*18*/ FILE_LJUNE,
	/*19*/ FILE_LLEEE,
	/*20*/ FILE_LLENE,
	/*21*/ FILE_LLIPE,
	/*22*/ FILE_LLUEE,
	/*23*/ FILE_LOATE,
	/*24*/ FILE_LPAME,
	/*25*/ FILE_LPETEE,
	/*26*/ FILE_LREFE,
	/*27*/ FILE_LRITE,
	/*28*/ FILE_LRUNE,
	/*29*/ FILE_LSEVBE,
	/*30*/ FILE_LSEVE,
	/*31*/ FILE_LSEVXE,
	/*32*/ FILE_LSEVXBE,
	/*33*/ FILE_LSHOE,
	/*34*/ FILE_LSILOE,
	/*35*/ FILE_LSTATE,
	/*36*/ FILE_LTRAE,
	/*37*/ FILE_LWAXE,
	/*38*/ FILE_LGUNE,
	/*39*/ FILE_LTITLEE,
	/*40*/ FILE_LMPMENUE,
	/*41*/ FILE_LPROPOBJE,
	/*42*/ FILE_LMPWEAPONSE,
	/*43*/ FILE_LOPTIONSE,
	/*44*/ FILE_LMISCE,
	/*45*/ FILE_LUFFE,
	/*46*/ FILE_LOLDE,
	/*47*/ FILE_LATEE,
	/*48*/ FILE_LLAME,
	/*49*/ FILE_LMP1E,
	/*50*/ FILE_LMP2E,
	/*51*/ FILE_LMP3E,
	/*52*/ FILE_LMP4E,
	/*53*/ FILE_LMP5E,
	/*54*/ FILE_LMP6E,
	/*55*/ FILE_LMP7E,
	/*56*/ FILE_LMP8E,
	/*57*/ FILE_LMP9E,
	/*58*/ FILE_LMP10E,
	/*59*/ FILE_LMP11E,
	/*60*/ FILE_LMP12E,
	/*61*/ FILE_LMP13E,
	/*62*/ FILE_LMP14E,
	/*63*/ FILE_LMP15E,
	/*64*/ FILE_LMP16E,
	/*65*/ FILE_LMP17E,
	/*66*/ FILE_LMP18E,
	/*67*/ FILE_LMP19E,
	/*68*/ FILE_LMP20E,
};

u32 langGetLangBankIndexFromStagenum(s32 stagenum)
{
	u32 bank = 0;

	switch (stagenum) {
	case STAGE_PELAGIC:       bank = LANGBANK_DAM; break;
	case STAGE_EXTRACTION:    bank = LANGBANK_ARK; break;
	case STAGE_MAIANSOS:      bank = LANGBANK_SEV; break;
	case STAGE_WAR:           bank = LANGBANK_STAT; break;
	case STAGE_CHICAGO:       bank = LANGBANK_PETE; break;
	case STAGE_G5BUILDING:    bank = LANGBANK_DEPO; break;
	case STAGE_ESCAPE:        bank = LANGBANK_TRA; break;
	case STAGE_CITRAINING:    bank = LANGBANK_DISH; break;
	case STAGE_DEFECTION:     bank = LANGBANK_AME; break;
	case STAGE_VILLA:         bank = LANGBANK_ELD; break;
	case STAGE_DEFENSE:       bank = LANGBANK_IMP; break;
	case STAGE_INVESTIGATION: bank = LANGBANK_EAR; break;
	case STAGE_ATTACKSHIP:    bank = LANGBANK_LEE; break;
	case STAGE_RESCUE:        bank = LANGBANK_LIP; break;
	case STAGE_INFILTRATION:  bank = LANGBANK_LUE; break;
	case STAGE_DEEPSEA:       bank = LANGBANK_PAM; break;
	case STAGE_SKEDARRUINS:   bank = LANGBANK_SHO; break;
	case STAGE_AIRFORCEONE:   bank = LANGBANK_RIT; break;
	case STAGE_CRASHSITE:     bank = LANGBANK_AZT; break;
	case STAGE_AIRBASE:       bank = LANGBANK_CAVE; break;
	case STAGE_DUEL:          bank = LANGBANK_ATE; break;
	case STAGE_MBR:           bank = LANGBANK_WAX; break;
	}

	return bank;
}

s32 langGetFileId(s32 bank)
{
	return g_LangFiles[bank];
}

void langPromoteOffsets(s32 banknum)
{
	u32 *bank = (u32 *) g_LangBanks[banknum];
	u32 endoffset;
	u32 offset;
	s32 i;

	for (i = 0; bank[i] == 0; i++);

	endoffset = bank[i];

	i = 0;
	offset = 0;

	while (offset < endoffset) {
		if (bank[i]) {
			bank[i] += (u32) bank;
		}

		offset += 4;
		i++;
	}
}

void langLoad(s32 bank)
{
	g_LangBanks[bank] = fileLoadToNew(g_LangFiles[bank], FILELOADMETHOD_DEFAULT);
	langPromoteOffsets(bank);
}

void langLoadToAddr(s32 bank, u8 *dst, s32 size)
{
	g_LangBanks[bank] = fileLoadToAddr(g_LangFiles[bank], FILELOADMETHOD_DEFAULT, dst, size);
	langPromoteOffsets(bank);
}

void langClearBank(s32 bank)
{
	g_LangBanks[bank] = NULL;
}


void langReset(s32 stagenum)
{
	s32 i;
	s32 size;

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		g_LangBanks[i] = NULL;
	}

	g_LangBanks[LANGBANK_GUN] = fileLoadToNew(langGetFileId(LANGBANK_GUN), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPMENU] = fileLoadToNew(langGetFileId(LANGBANK_MPMENU), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_PROPOBJ] = fileLoadToNew(langGetFileId(LANGBANK_PROPOBJ), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPWEAPONS] = fileLoadToNew(langGetFileId(LANGBANK_MPWEAPONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_OPTIONS] = fileLoadToNew(langGetFileId(LANGBANK_OPTIONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MISC] = fileLoadToNew(langGetFileId(LANGBANK_MISC), FILELOADMETHOD_DEFAULT);

	langPromoteOffsets(LANGBANK_GUN);
	langPromoteOffsets(LANGBANK_MPMENU);
	langPromoteOffsets(LANGBANK_PROPOBJ);
	langPromoteOffsets(LANGBANK_MPWEAPONS);
	langPromoteOffsets(LANGBANK_OPTIONS);
	langPromoteOffsets(LANGBANK_MISC);

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = fileLoadToNew(langGetFileId(LANGBANK_TITLE), FILELOADMETHOD_DEFAULT);
		langPromoteOffsets(LANGBANK_TITLE);
	}
}
