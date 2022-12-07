#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

// When adding or removing items from this table you must also update the
// STAGEINDEX constants in constants.h.
struct stagetableentry g_Stages[61] = {
	//       id,                  ?, lia, liw, lih, ?, bg,               tiles,              pads,              setup,           mpsetp,             ?                0x18,            0x1c, ?, ?,  ?, 0x24,      0x28,   ?,   ?,   ?  ?
	/*0x00*/ STAGE_MAIANSOS,      2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_SEV_PADS,  FILE_USETUPSEV,  FILE_UMP_SETUPSEV,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x01*/ STAGE_TEST_SILO,     2, 255, 100, 100, 0, FILE_BG_OAT_SEG,  FILE_BG_OAT_TILES,  FILE_BG_OAT_PADS,  FILE_USETUPSILO, FILE_UMP_SETUPSILO, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x02*/ STAGE_WAR,           2, 255, 100, 100, 0, FILE_BG_SHO_SEG,  FILE_BG_SHO_TILES,  FILE_BG_STAT_PADS, FILE_USETUPSTAT, FILE_UMP_SETUPSTAT, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x03*/ STAGE_MP_RAVINE,     2, 255, 100, 100, 0, FILE_BG_AREC_SEG, FILE_BG_AREC_TILES, FILE_BG_AREC_PADS, FILE_USETUPAREC, FILE_UMP_SETUPAREC, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x04*/ STAGE_TEST_ARCH,     2, 255, 100, 100, 0, FILE_BG_ARCH_SEG, FILE_BG_ARCH_TILES, FILE_BG_ARCH_PADS, FILE_USETUPARCH, FILE_UMP_SETUPARCH, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x05*/ STAGE_ESCAPE,        2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_TRA_PADS,  FILE_USETUPTRA,  FILE_UMP_SETUPTRA,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x06*/ STAGE_TEST_DEST,     2, 255, 100, 100, 0, FILE_BG_DEST_SEG, FILE_BG_DEST_TILES, FILE_BG_DEST_PADS, FILE_USETUPDEST, FILE_UMP_SETUPDEST, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x07*/ STAGE_RETAKING,      2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_SEVB_PADS, FILE_USETUPSEVB, FILE_UMP_SETUPSEVB, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x08*/ STAGE_CRASHSITE,     2, 255, 100, 100, 0, FILE_BG_AZT_SEG,  FILE_BG_AZT_TILES,  FILE_BG_AZT_PADS,  FILE_USETUPAZT,  FILE_UMP_SETUPAZT,  1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x09*/ STAGE_CHICAGO,       2, 255, 100, 100, 0, FILE_BG_PETE_SEG, FILE_BG_PETE_TILES, FILE_BG_PETE_PADS, FILE_USETUPPETE, FILE_UMP_SETUPPETE, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0a*/ STAGE_G5BUILDING,    2, 255, 100, 100, 0, FILE_BG_DEPO_SEG, FILE_BG_DEPO_TILES, FILE_BG_DEPO_PADS, FILE_USETUPDEPO, FILE_UMP_SETUPDEPO, 1,                1,   100,             0, 0, 20, 220, 0x3e19999a, -1,  400, 0,   1,
	/*0x0b*/ STAGE_MP_COMPLEX,    2, 255, 100, 100, 0, FILE_BG_REF_SEG,  FILE_BG_REF_TILES,  FILE_BG_REF_PADS,  FILE_USETUPREF,  FILE_UMP_SETUPREF,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0c*/ STAGE_MP_G5BUILDING, 2, 255, 100, 100, 0, FILE_BG_CRYP_SEG, FILE_BG_CRYP_TILES, FILE_BG_CRYP_PADS, FILE_USETUPCRYP, FILE_UMP_SETUPCRYP, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x0d*/ STAGE_PELAGIC,       2, 255, 100, 100, 0, FILE_BG_DAM_SEG,  FILE_BG_DAM_TILES,  FILE_BG_DAM_PADS,  FILE_USETUPDAM,  FILE_UMP_SETUPDAM,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0e*/ STAGE_EXTRACTION,    2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_ARK_PADS,  FILE_USETUPARK,  FILE_UMP_SETUPARK,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0f*/ STAGE_TEST_RUN,      2, 255, 100, 100, 0, FILE_BG_RUN_SEG,  FILE_BG_RUN_TILES,  FILE_BG_RUN_PADS,  FILE_USETUPRUN,  FILE_UMP_SETUPRUN,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x10*/ STAGE_24,            2, 255, 100, 100, 0, FILE_BG_SEVX_SEG, FILE_BG_SEVX_TILES, FILE_BG_SEVX_PADS, FILE_USETUPSEVX, FILE_UMP_SETUPSEVX, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x11*/ STAGE_MP_TEMPLE,     2, 255, 100, 100, 0, FILE_BG_JUN_SEG,  FILE_BG_JUN_TILES,  FILE_BG_JUN_PADS,  FILE_USETUPJUN,  FILE_UMP_SETUPJUN,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x12*/ STAGE_CITRAINING,    2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_DISH_PADS, FILE_USETUPDISH, FILE_UMP_SETUPDISH, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x13*/ STAGE_AIRBASE,       2, 255, 100, 100, 0, FILE_BG_CAVE_SEG, FILE_BG_CAVE_TILES, FILE_BG_CAVE_PADS, FILE_USETUPCAVE, FILE_UMP_SETUPCAVE, 1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x14*/ STAGE_28,            2, 255, 100, 100, 0, FILE_BG_CAT_SEG,  FILE_BG_CAT_TILES,  FILE_BG_CAT_PADS,  FILE_USETUPCAT,  FILE_UMP_SETUPCAT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 200, 800, 400, 1,
	/*0x15*/ STAGE_MP_PIPES,      2, 255, 100, 100, 0, FILE_BG_CRAD_SEG, FILE_BG_CRAD_TILES, FILE_BG_CRAD_PADS, FILE_USETUPCRAD, FILE_UMP_SETUPCRAD, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x16*/ STAGE_SKEDARRUINS,   2, 255, 100, 100, 0, FILE_BG_SHO_SEG,  FILE_BG_SHO_TILES,  FILE_BG_SHO_PADS,  FILE_USETUPSHO,  FILE_UMP_SETUPSHO,  1,                1,   100,             0, 0, 20, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x17*/ STAGE_2B,            2, 255, 100, 100, 0, FILE_BG_SEVX_SEG, FILE_BG_SEVX_TILES, FILE_BG_SEVX_PADS, FILE_USETUPSEVX, FILE_UMP_SETUPSEVX, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x18*/ STAGE_VILLA,         2, 255, 100, 100, 0, FILE_BG_ELD_SEG,  FILE_BG_ELD_TILES,  FILE_BG_ELD_PADS,  FILE_USETUPELD,  FILE_UMP_SETUPELD,  1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x19*/ STAGE_DEFENSE,       2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_IMP_PADS,  FILE_USETUPIMP,  FILE_UMP_SETUPIMP,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1a*/ STAGE_TEST_ASH,      2, 255, 100, 100, 0, FILE_BG_ASH_SEG,  FILE_BG_ASH_TILES,  FILE_BG_ASH_PADS,  FILE_USETUPASH,  FILE_UMP_SETUPASH,  1,                1,   100,             0, 0, -1, 500, 0x3e19999a, -1,  400, 0,   1,
	/*0x1b*/ STAGE_INFILTRATION,  2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_LUE_PADS,  FILE_USETUPLUE,  FILE_UMP_SETUPLUE,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1c*/ STAGE_DEFECTION,     2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_AME_PADS,  FILE_USETUPAME,  FILE_UMP_SETUPAME,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1d*/ STAGE_AIRFORCEONE,   2, 255, 100, 100, 0, FILE_BG_RIT_SEG,  FILE_BG_RIT_TILES,  FILE_BG_RIT_PADS,  FILE_USETUPRIT,  FILE_UMP_SETUPRIT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1e*/ STAGE_MP_SKEDAR,     2, 255, 100, 100, 0, FILE_BG_OAT_SEG,  FILE_BG_OAT_TILES,  FILE_BG_OAT_PADS,  FILE_USETUPOAT,  FILE_UMP_SETUPOAT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x1f*/ STAGE_INVESTIGATION, 2, 255, 100, 100, 0, FILE_BG_EAR_SEG,  FILE_BG_EAR_TILES,  FILE_BG_EAR_PADS,  FILE_USETUPEAR,  FILE_UMP_SETUPEAR,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x20*/ STAGE_ATTACKSHIP,    2, 255, 100, 100, 0, FILE_BG_LEE_SEG,  FILE_BG_LEE_TILES,  FILE_BG_LEE_PADS,  FILE_USETUPLEE,  FILE_UMP_SETUPLEE,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x21*/ STAGE_RESCUE,        2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_LIP_PADS,  FILE_USETUPLIP,  FILE_UMP_SETUPLIP,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x22*/ STAGE_TEST_LEN,      2, 255, 100, 100, 0, FILE_BG_LEN_SEG,  FILE_BG_LEN_TILES,  FILE_BG_LEN_PADS,  FILE_USETUPLEN,  FILE_UMP_SETUPLEN,  0.10040000081062, 1,   6.6844921112061, 0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x23*/ STAGE_MBR,           2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_AME_PADS,  FILE_USETUPWAX,  FILE_UMP_SETUPWAX,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x24*/ STAGE_DEEPSEA,       8, 96,  80,  200, 0, FILE_BG_PAM_SEG,  FILE_BG_PAM_TILES,  FILE_BG_PAM_PADS,  FILE_USETUPPAM,  FILE_UMP_SETUPPAM,  1,                1,   100,             0, 0, 30, 255, 0x3e4ccccd, 300, 600, 0,   1,
	/*0x25*/ STAGE_TEST_UFF,      2, 255, 100, 100, 0, FILE_BG_UFF_SEG,  FILE_BG_UFF_TILES,  FILE_BG_UFF_PADS,  FILE_USETUPUFF,  FILE_UMP_SETUPUFF,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x26*/ STAGE_TEST_OLD,      2, 255, 100, 100, 0, FILE_BG_OLD_SEG,  FILE_BG_OLD_TILES,  FILE_BG_OLD_PADS,  FILE_USETUPOLD,  FILE_UMP_SETUPOLD,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x27*/ STAGE_DUEL,          2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_ATE_PADS,  FILE_USETUPATE,  FILE_UMP_SETUPATE,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x28*/ STAGE_TEST_LAM,      2, 255, 100, 100, 0, FILE_BG_LAM_SEG,  FILE_BG_LAM_TILES,  FILE_BG_LAM_PADS,  FILE_USETUPLAM,  FILE_UMP_SETUPLAM,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x29*/ STAGE_MP_BASE,       2, 255, 100, 100, 0, FILE_BG_MP1_SEG,  FILE_BG_MP1_TILES,  FILE_BG_MP1_PADS,  FILE_USETUPMP1,  FILE_UMP_SETUPMP1,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2a*/ STAGE_TEST_MP2,      2, 255, 100, 100, 0, FILE_BG_MP2_SEG,  FILE_BG_MP2_TILES,  FILE_BG_MP2_PADS,  FILE_USETUPMP2,  FILE_UMP_SETUPMP2,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2b*/ STAGE_MP_AREA52,     2, 255, 100, 100, 0, FILE_BG_MP3_SEG,  FILE_BG_MP3_TILES,  FILE_BG_MP3_PADS,  FILE_USETUPMP3,  FILE_UMP_SETUPMP3,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2c*/ STAGE_MP_WAREHOUSE,  2, 255, 100, 100, 0, FILE_BG_MP4_SEG,  FILE_BG_MP4_TILES,  FILE_BG_MP4_PADS,  FILE_USETUPMP4,  FILE_UMP_SETUPMP4,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2d*/ STAGE_MP_CARPARK,    2, 255, 100, 100, 0, FILE_BG_MP5_SEG,  FILE_BG_MP5_TILES,  FILE_BG_MP5_PADS,  FILE_USETUPMP5,  FILE_UMP_SETUPMP5,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2e*/ STAGE_TEST_MP6,      2, 255, 100, 100, 0, FILE_BG_MP6_SEG,  FILE_BG_MP6_TILES,  FILE_BG_MP6_PADS,  FILE_USETUPMP6,  FILE_UMP_SETUPMP6,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2f*/ STAGE_TEST_MP7,      2, 255, 100, 100, 0, FILE_BG_MP7_SEG,  FILE_BG_MP7_TILES,  FILE_BG_MP7_PADS,  FILE_USETUPMP7,  FILE_UMP_SETUPMP7,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x30*/ STAGE_TEST_MP8,      2, 255, 100, 100, 0, FILE_BG_MP8_SEG,  FILE_BG_MP8_TILES,  FILE_BG_MP8_PADS,  FILE_USETUPMP8,  FILE_UMP_SETUPMP8,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x31*/ STAGE_MP_RUINS,      2, 255, 100, 100, 0, FILE_BG_MP9_SEG,  FILE_BG_MP9_TILES,  FILE_BG_MP9_PADS,  FILE_USETUPMP9,  FILE_UMP_SETUPMP9,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x32*/ STAGE_MP_SEWERS,     2, 255, 100, 100, 0, FILE_BG_MP10_SEG, FILE_BG_MP10_TILES, FILE_BG_MP10_PADS, FILE_USETUPMP10, FILE_UMP_SETUPMP10, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x33*/ STAGE_MP_FELICITY,   2, 255, 100, 100, 0, FILE_BG_MP11_SEG, FILE_BG_MP11_TILES, FILE_BG_MP11_PADS, FILE_USETUPMP11, FILE_UMP_SETUPMP11, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x34*/ STAGE_MP_FORTRESS,   2, 255, 100, 100, 0, FILE_BG_MP12_SEG, FILE_BG_MP12_TILES, FILE_BG_MP12_PADS, FILE_USETUPMP12, FILE_UMP_SETUPMP12, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x35*/ STAGE_MP_VILLA,      2, 255, 100, 100, 0, FILE_BG_MP13_SEG, FILE_BG_MP13_TILES, FILE_BG_MP13_PADS, FILE_USETUPMP13, FILE_UMP_SETUPMP13, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x36*/ STAGE_TEST_MP14,     2, 255, 100, 100, 0, FILE_BG_MP14_SEG, FILE_BG_MP14_TILES, FILE_BG_MP14_PADS, FILE_USETUPMP14, FILE_UMP_SETUPMP14, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x37*/ STAGE_MP_GRID,       2, 255, 100, 100, 0, FILE_BG_MP15_SEG, FILE_BG_MP15_TILES, FILE_BG_MP15_PADS, FILE_USETUPMP15, FILE_UMP_SETUPMP15, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x38*/ STAGE_TEST_MP16,     2, 255, 100, 100, 0, FILE_BG_MP16_SEG, FILE_BG_MP16_TILES, FILE_BG_MP16_PADS, FILE_USETUPMP16, FILE_UMP_SETUPMP16, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x39*/ STAGE_TEST_MP17,     2, 255, 100, 100, 0, FILE_BG_MP17_SEG, FILE_BG_MP17_TILES, FILE_BG_MP17_PADS, FILE_USETUPMP17, FILE_UMP_SETUPMP17, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3a*/ STAGE_TEST_MP18,     2, 255, 100, 100, 0, FILE_BG_MP18_SEG, FILE_BG_MP18_TILES, FILE_BG_MP18_PADS, FILE_USETUPMP18, FILE_UMP_SETUPMP18, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3b*/ STAGE_TEST_MP19,     2, 255, 100, 100, 0, FILE_BG_MP19_SEG, FILE_BG_MP19_TILES, FILE_BG_MP19_PADS, FILE_USETUPMP19, FILE_UMP_SETUPMP19, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3c*/ STAGE_TEST_MP20,     2, 255, 100, 100, 0, FILE_BG_MP20_SEG, FILE_BG_MP20_TILES, FILE_BG_MP20_PADS, FILE_USETUPMP20, FILE_UMP_SETUPMP20, 1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
};

struct stagetableentry *stageGetCurrent(void)
{
	struct stagetableentry *stage = g_Stages;
	struct stagetableentry *end = (struct stagetableentry *)(uintptr_t)stage + ARRAYCOUNT(g_Stages);
	s32 stagenum = g_Vars.stagenum;

	while (stage < end) {
		if (stage->id == stagenum) {
			return stage;
		}

		stage++;
	}

	return NULL;
}

s32 stageGetIndex(s32 stagenum)
{
	struct stagetableentry *stage = g_Stages;
	struct stagetableentry *end = (struct stagetableentry *)(uintptr_t)stage + ARRAYCOUNT(g_Stages);
	s32 i = 0;

	while (stage < end) {
		if (stage->id == stagenum) {
			return i;
		}

		stage++;
		i++;
	}

	return -1;
}
