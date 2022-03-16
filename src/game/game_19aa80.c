#include <ultra64.h>
#include "constants.h"
#include "game/chr/chrai.h"
#include "game/chr/chraicommands.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/bot.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

u8 g_MpFeaturesForceUnlocked[40];
u8 g_MpFeaturesUnlocked[80];

u32 g_MpChallengeIndex = 0;
struct mpconfigfull *g_MpCurrentChallengeConfig = NULL;

struct challenge g_MpChallenges[NUM_CHALLENGES] = {
	{ L_OPTIONS_406, MPCONFIG_CHALLENGE01 }, // "Challenge 1"
	{ L_OPTIONS_407, MPCONFIG_CHALLENGE02 }, // "Challenge 2"
	{ L_OPTIONS_408, MPCONFIG_CHALLENGE03 }, // "Challenge 3"
	{ L_OPTIONS_409, MPCONFIG_CHALLENGE04 }, // "Challenge 4"
	{ L_OPTIONS_410, MPCONFIG_CHALLENGE05 }, // "Challenge 5"
	{ L_OPTIONS_411, MPCONFIG_CHALLENGE06 }, // "Challenge 6"
	{ L_OPTIONS_412, MPCONFIG_CHALLENGE07 }, // "Challenge 7"
	{ L_OPTIONS_413, MPCONFIG_CHALLENGE08 }, // "Challenge 8"
	{ L_OPTIONS_414, MPCONFIG_CHALLENGE09 }, // "Challenge 9"
	{ L_OPTIONS_415, MPCONFIG_CHALLENGE10 }, // "Challenge 10"
	{ L_OPTIONS_416, MPCONFIG_CHALLENGE11 }, // "Challenge 11"
	{ L_OPTIONS_417, MPCONFIG_CHALLENGE12 }, // "Challenge 12"
	{ L_OPTIONS_418, MPCONFIG_CHALLENGE13 }, // "Challenge 13"
	{ L_OPTIONS_419, MPCONFIG_CHALLENGE14 }, // "Challenge 14"
	{ L_OPTIONS_420, MPCONFIG_CHALLENGE15 }, // "Challenge 15"
	{ L_OPTIONS_421, MPCONFIG_CHALLENGE16 }, // "Challenge 16"
	{ L_OPTIONS_422, MPCONFIG_CHALLENGE17 }, // "Challenge 17"
	{ L_OPTIONS_423, MPCONFIG_CHALLENGE18 }, // "Challenge 18"
	{ L_OPTIONS_424, MPCONFIG_CHALLENGE19 }, // "Challenge 19"
	{ L_OPTIONS_425, MPCONFIG_CHALLENGE20 }, // "Challenge 20"
	{ L_OPTIONS_426, MPCONFIG_CHALLENGE21 }, // "Challenge 21"
	{ L_OPTIONS_427, MPCONFIG_CHALLENGE22 }, // "Challenge 22"
	{ L_OPTIONS_428, MPCONFIG_CHALLENGE23 }, // "Challenge 23"
	{ L_OPTIONS_429, MPCONFIG_CHALLENGE24 }, // "Challenge 24"
	{ L_OPTIONS_430, MPCONFIG_CHALLENGE25 }, // "Challenge 25"
	{ L_OPTIONS_431, MPCONFIG_CHALLENGE26 }, // "Challenge 26"
	{ L_OPTIONS_432, MPCONFIG_CHALLENGE27 }, // "Challenge 27"
	{ L_OPTIONS_433, MPCONFIG_CHALLENGE28 }, // "Challenge 28"
	{ L_OPTIONS_434, MPCONFIG_CHALLENGE29 }, // "Challenge 29"
	{ L_OPTIONS_435, MPCONFIG_CHALLENGE30 }, // "Challenge 30"
};

/**
 * Find a position inside the given room and populate the pointer arguments with
 * information about the position.
 *
 * Used by bots in King of the Hill scenarios only. The room argument is always
 * a hill room.
 *
 * @bug: There is a possible array overflow in both the covernums and padnums
 * arrays. The for loops stop when the array is full, but the outer loop makes
 * them iterate again, and the check is only at the end of each for loop rather
 * than at the start.
 *
 * For covernums, the three variables declared above it are never written to the
 * stack, so the outer loop would need to iterate three times while covernums is
 * full in order to write into the caller's stack space. The only caller is
 * botTickUnpaused, and its first stack usage is 0x20 where it backs up s0.
 * So the outer loop would need to iterate 11 times before any damage could be
 * done.
 *
 * For padnums, any overflow will write into the rooms array, likely clearing
 * the -1 terminator in rooms[1] and affecting cover selection. Further
 * iterations of the outer loop would write into the cover struct, but this is
 * written before it's read so there's no issue there.
 *
 * It's likely that these don't ever overflow, or they overflow minimally which
 * has no serious effect, but this should be investigated further.
 */
bool botroomFindPos(s16 room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr)
{
	s32 i;
	struct waypoint *waypoint;
	s32 waypointnum;
	s32 covernums[40]; /// written to stack
	s32 covercount;
	struct cover cover; // written to stack
	s16 rooms[2]; // written to stack
	s32 padnums[40]; // written to stack
	s32 padcount;
	s32 totalcount;
	struct pad pad;
	bool sp54;
	bool sp50;
	s32 count;

	covercount = 0;
	padcount = 0;

	sp50 = 0;

	rooms[0] = room;
	rooms[1] = -1;

	totalcount = 0;

	do {
		sp54 = false;
		count = coverGetCount();

		for (i = 0; i < count; i++) {
			if (coverUnpack(i, &cover) && !coverIsSpecial(&cover) && arrayIntersects(cover.rooms, rooms)) {
				if (sp50 && (cover.flags & COVERFLAG_0100)) {
					coverUnsetFlag(i, COVERFLAG_0100);
					covernums[covercount] = i;
					covercount++;
					totalcount++;
				} else if ((cover.flags & COVERFLAG_0100) == 0) {
					covernums[covercount] = i;
					covercount++;
					totalcount++;
				} else {
					sp54 = true;
				}

				if (covercount >= ARRAYCOUNT(covernums)) {
					break;
				}
			}
		}

		if (g_StageSetup.waypoints != NULL) {
			count = g_Rooms[room].numwaypoints;

			for (i = 0; i < count; i++) {
				waypointnum = g_Vars.waypointnums[g_Rooms[room].firstwaypoint + i];
				waypoint = &g_StageSetup.waypoints[waypointnum];

				padUnpack(waypoint->padnum, PADFIELD_FLAGS, &pad);

				if (sp50 && (pad.flags & PADFLAG_20000)) {
					padUnsetFlag(waypoint->padnum, PADFLAG_20000);
					padnums[padcount] = waypoint->padnum;
					padcount++;
					totalcount++;
				} else if ((pad.flags & PADFLAG_20000) == 0) {
					padnums[padcount] = waypoint->padnum;
					padcount++;
					totalcount++;
				} else {
					sp54 = true;
				}

				if (padcount >= ARRAYCOUNT(padnums)) {
					break;
				}
			}
		}

		if (1);

		sp50 = sp54;
	} while (sp54 && !totalcount);

	if (!totalcount) {
		return false;
	}

	i = random() % totalcount;

	if (i < covercount) {
		coverUnpack(covernums[i], &cover);

		pos->x = cover.pos->x;
		pos->y = cover.pos->y;
		pos->z = cover.pos->z;

		*angleptr = atan2f(cover.look->z, cover.look->x);
		*padnumptr = -1;
		*covernumptr = covernums[i];
	} else {
		i -= covercount;
		padUnpack(padnums[i], PADFIELD_POS | PADFIELD_LOOK, &pad);

		pos->x = pad.pos.x;
		pos->y = pad.pos.y;
		pos->z = pad.pos.z;

		*angleptr = atan2f(pad.look.z, pad.look.x);
		*padnumptr = padnums[i];
		*covernumptr = -1;
	}

	return true;
}

bool func0f19af10(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & 1) != 0;
}

bool mpIsChallengeAvailableToPlayer(s32 chrnum, s32 challengeindex)
{
	if ((g_MpSetup.chrslots & (1 << chrnum)) == 0) {
		return 0;
	}

	return ((g_MpChallenges[challengeindex].availability & (2 << chrnum)) != 0);
}

bool mpIsChallengeAvailableToAnyPlayer(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & (((g_MpSetup.chrslots & 0xf) << 1) | 1)) != 0;
}

void mpDetermineUnlockedFeatures(void)
{
	s32 challengeindex;
	s32 numgifted; // number of unlocked but not completed challenges
	u8 flag;
	s32 prev;
	s32 i;
	s32 j;
	s32 k;

	// Clear all challenge availability
	for (challengeindex = 0; challengeindex < 30; challengeindex++) {
		g_MpChallenges[challengeindex].availability = 0;
	}

	numgifted = 0;

	// Mark challenges completed by any player
	for (challengeindex = 0; challengeindex < 30; challengeindex++) {
		flag = 0;

		if (mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 1)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 2)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 3)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 4)) {
			// Completed challenge
			flag = 1;
		} else if (challengeindex < 4) {
			// Not yet completed, but challenges 1-4 are always available
			flag = 1;
			numgifted++;
		} else if (challengeindex > 0
				&& (mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex - 1, 1)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex - 1, 2)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex - 1, 3)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex - 1, 4))) {
			// Challenges are available if their previous one is complete
			flag = 1;
			numgifted++;
		}
#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
		else if (debugIsAllChallengesEnabled()) {
			flag = 1;
		}
#endif

		g_MpChallenges[challengeindex].availability |= flag;
	}

	// Gift up to 4 challenges
	for (challengeindex = 0; numgifted < 4 && challengeindex < 30; challengeindex++) {
		if ((g_MpChallenges[challengeindex].availability & 1) == 0) {
			g_MpChallenges[challengeindex].availability |= 1;
			numgifted++;
		}
	}

	// Now same as above, but per player
	for (j = 0; j < 4; j++) {
		numgifted = 0;

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			flag = 0;

			if (mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 1)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 2)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 3)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 4)) {
				// Completed challenge
				flag = 2 << j;
			} else if (challengeindex < 4) {
				// Not yet completed, but challenges 1-4 are always available
				flag = 2 << j;
				numgifted++;
			} else if (challengeindex > 0) {
				// Challenges are available if their previous one is complete
				prev = challengeindex - 1;

				if (mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 1)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 2)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 3)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 4)) {
					flag = 2 << j;
					numgifted++;
				}
			}

			g_MpChallenges[challengeindex].availability |= flag;
		}

		// Gift up to 4 challenges
		for (challengeindex = 0; numgifted < 4 && challengeindex < 30; challengeindex++) {
			if ((g_MpChallenges[challengeindex].availability & (2 << j)) == 0) {
				g_MpChallenges[challengeindex].availability |= 2 << j;
				numgifted++;
			}
		}
	}

	for (j = 0; j < ARRAYCOUNT(g_MpFeaturesUnlocked); j++) {
		flag = 0;

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
				for (i = 0; i < 16; i++) {
					if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
						flag |= 1;
					}
				}
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
			if (g_MpFeaturesForceUnlocked[i] == j) {
				flag |= 1;
			}
		}

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			for (prev = 0; prev < 4; prev++) {
				if (mpIsChallengeAvailableToPlayer(prev, challengeindex)) {
					for (i = 0; i < 16; i++) {
						if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
							flag |= 2 << prev;
						}
					}
				}
			}
		}

		g_MpFeaturesUnlocked[j] = flag;
	}

	for (j = 0; j < func0f188bcc(); j++) {
		struct mpweapon *weapon = &g_MpWeapons[j];

		if (weapon->unlockfeature > 0 && func0f19cbcc(weapon->weaponnum)) {
			g_MpFeaturesUnlocked[weapon->unlockfeature] |= 1;
		}
	}

	func0f1895e8();

	// If the ability to have 8 simulants hasn't been unlocked, limit them to 4
	if (!mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
		for (k = 4; k < MAX_BOTS; k++) {
			if (g_MpSetup.chrslots & (1 << (4 + k))) {
				mpRemoveSimulant(k);
			}
		}

		if (g_Vars.mpquickteamnumsims > 4) {
			g_Vars.mpquickteamnumsims = 4;
		}
	}
}

void mpPerformSanityChecks(void)
{
	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		s32 numplayers = 0;
		s32 i;

		// Reset player handicaps
		for (i = 0; i < 4; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				g_PlayerConfigsArray[i].handicap = 0x80;
				numplayers++;
			}
		}

		// Turn off all simulants and turn them on if enabled
		// for this number of players
		g_MpSetup.chrslots &= 0x000f;

		for (i = 0; i != MAX_BOTS; i++) {
			g_BotConfigsArray[i].difficulty = g_MpSimulantDifficultiesPerNumPlayers[i][numplayers - 1];

			if (g_BotConfigsArray[i].difficulty != BOTDIFF_DISABLED) {
				g_MpSetup.chrslots |= 1 << (i + 4);
			}
		}

		if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			g_Vars.mphilltime = 10;
		}
	} else if (!mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
		// Limit to 4 players and 4 simulants
		g_MpSetup.chrslots &= 0x00ff;
	}
}

s32 mpGetNumAvailableChallenges(void)
{
	s32 challengeindex;
	s32 count = 0;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			count++;
		}
	}

	return count;
}

char *mpChallengeGetName(s32 challengeindex)
{
	return langGet(g_MpChallenges[challengeindex].name);
}

char *mpGetChallengeNameBySlot(s32 slot)
{
	s32 index = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (index == slot) {
				return mpChallengeGetName(i);
			}

			index++;
		}
	}

	return "";
}

void mpSetCurrentChallenge(s32 slotnum)
{
	s32 challengeindex;
	g_MpChallengeIndex = 0;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			if (slotnum == 0) {
				g_MpChallengeIndex = challengeindex;
				break;
			}

			slotnum--;
		}
	}

	func0f19c1cc();
}

s32 mpGetCurrentChallengeIndex(void)
{
	return g_MpChallengeIndex;
}

bool mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot(s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByAnyPlayerWithNumPlayers(i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

bool mpIsChallengeCompletedByChrWithNumPlayersBySlot(s32 mpchrnum, s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

extern u32 _mpstringsESegmentRomStart;
extern u32 _mpstringsJSegmentRomStart;
extern u32 _mpstringsPSegmentRomStart;
extern u32 _mpstringsGSegmentRomStart;
extern u32 _mpstringsFSegmentRomStart;
extern u32 _mpstringsSSegmentRomStart;
extern u32 _mpstringsISegmentRomStart;
extern u32 _mpstringsESegmentRomEnd;
extern u32 _mpstringsJSegmentRomEnd;
extern u32 _mpstringsPSegmentRomEnd;
extern u32 _mpstringsGSegmentRomEnd;
extern u32 _mpstringsFSegmentRomEnd;
extern u32 _mpstringsSSegmentRomEnd;
extern u32 _mpstringsISegmentRomEnd;

u32 *var800887c4 = &_mpstringsESegmentRomStart;
u32 *var800887c8 = &_mpstringsESegmentRomEnd;
u32 *var800887cc = &_mpstringsJSegmentRomStart;
u32 *var800887d0 = &_mpstringsJSegmentRomEnd;
u32 *var800887d4 = &_mpstringsPSegmentRomStart;
u32 *var800887d8 = &_mpstringsPSegmentRomEnd;
u32 *var800887dc = &_mpstringsGSegmentRomStart;
u32 *var800887e0 = &_mpstringsGSegmentRomEnd;
u32 *var800887e4 = &_mpstringsFSegmentRomStart;
u32 *var800887e8 = &_mpstringsFSegmentRomEnd;
u32 *var800887ec = &_mpstringsSSegmentRomStart;
u32 *var800887f0 = &_mpstringsSSegmentRomEnd;
u32 *var800887f4 = &_mpstringsISegmentRomStart;
u32 *var800887f8 = &_mpstringsISegmentRomEnd;

GLOBAL_ASM(
glabel mpLoadConfig
/*  f19b914:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f19b918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19b91c:	afa401c8 */ 	sw	$a0,0x1c8($sp)
/*  f19b920:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f19b924:	0fc5b9b5 */ 	jal	langGetFileNumOffset
/*  f19b928:	afa601d0 */ 	sw	$a2,0x1d0($sp)
/*  f19b92c:	3c0f8009 */ 	lui	$t7,%hi(var800887c4)
/*  f19b930:	25ef87c4 */ 	addiu	$t7,$t7,%lo(var800887c4)
/*  f19b934:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f19b938:	25e80030 */ 	addiu	$t0,$t7,0x30
/*  f19b93c:	27ae0018 */ 	addiu	$t6,$sp,0x18
.L0f19b940:
/*  f19b940:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b944:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f19b948:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f19b94c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f19b950:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f19b954:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f19b958:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f19b95c:	15e8fff8 */ 	bne	$t7,$t0,.L0f19b940
/*  f19b960:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f19b964:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b968:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f19b96c:	3c0b007d */ 	lui	$t3,%hi(_mpconfigsSegmentRomStart)
/*  f19b970:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19b974:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f19b978:	8fa901c8 */ 	lw	$t1,0x1c8($sp)
/*  f19b97c:	256b0a40 */ 	addiu	$t3,$t3,%lo(_mpconfigsSegmentRomStart)
/*  f19b980:	8fa401cc */ 	lw	$a0,0x1cc($sp)
/*  f19b984:	00095080 */ 	sll	$t2,$t1,0x2
/*  f19b988:	01495023 */ 	subu	$t2,$t2,$t1
/*  f19b98c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f19b990:	01495021 */ 	addu	$t2,$t2,$t1
/*  f19b994:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f19b998:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f19b99c:	0c003522 */ 	jal	dmaExecWithAutoAlign
/*  f19b9a0:	24060068 */ 	addiu	$a2,$zero,0x68
/*  f19b9a4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f19b9a8:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f19b9ac:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f19b9b0:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f19b9b4:	03ad1821 */ 	addu	$v1,$sp,$t5
/*  f19b9b8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19b9bc:	8c630018 */ 	lw	$v1,0x18($v1)
/*  f19b9c0:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f19b9c4:	0018c180 */ 	sll	$t8,$t8,0x6
/*  f19b9c8:	afa201c4 */ 	sw	$v0,0x1c4($sp)
/*  f19b9cc:	24060140 */ 	addiu	$a2,$zero,0x140
/*  f19b9d0:	0c003522 */ 	jal	dmaExecWithAutoAlign
/*  f19b9d4:	00782821 */ 	addu	$a1,$v1,$t8
/*  f19b9d8:	8fa701c4 */ 	lw	$a3,0x1c4($sp)
/*  f19b9dc:	00404825 */ 	or	$t1,$v0,$zero
/*  f19b9e0:	244e0138 */ 	addiu	$t6,$v0,0x138
/*  f19b9e4:	00e05025 */ 	or	$t2,$a3,$zero
.L0f19b9e8:
/*  f19b9e8:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19b9ec:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19b9f0:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f19b9f4:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f19b9f8:	a941005c */ 	swl	$at,0x5c($t2)
/*  f19b9fc:	b941005f */ 	swr	$at,0x5f($t2)
/*  f19ba00:	8921fff8 */ 	lwl	$at,-0x8($t1)
/*  f19ba04:	9921fffb */ 	lwr	$at,-0x5($t1)
/*  f19ba08:	a9410060 */ 	swl	$at,0x60($t2)
/*  f19ba0c:	b9410063 */ 	swr	$at,0x63($t2)
/*  f19ba10:	8921fffc */ 	lwl	$at,-0x4($t1)
/*  f19ba14:	9921ffff */ 	lwr	$at,-0x1($t1)
/*  f19ba18:	a9410064 */ 	swl	$at,0x64($t2)
/*  f19ba1c:	152efff2 */ 	bne	$t1,$t6,.L0f19b9e8
/*  f19ba20:	b9410067 */ 	swr	$at,0x67($t2)
/*  f19ba24:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19ba28:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19ba2c:	00e01025 */ 	or	$v0,$a3,$zero
/*  f19ba30:	a9410068 */ 	swl	$at,0x68($t2)
/*  f19ba34:	b941006b */ 	swr	$at,0x6b($t2)
/*  f19ba38:	892e0004 */ 	lwl	$t6,0x4($t1)
/*  f19ba3c:	992e0007 */ 	lwr	$t6,0x7($t1)
/*  f19ba40:	a94e006c */ 	swl	$t6,0x6c($t2)
/*  f19ba44:	b94e006f */ 	swr	$t6,0x6f($t2)
/*  f19ba48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ba4c:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f19ba50:	03e00008 */ 	jr	$ra
/*  f19ba54:	00000000 */ 	nop
);

// Mismatch because the arguments to an addu instruction are swapped.
// It's the addu for calculating &bank[confignum].
//struct mpconfigfull *mpLoadConfig(s32 confignum, u8 *buffer, s32 len)
//{
//	struct mpconfigfull *mpconfig;
//	u8 buffer2[sizeof(struct mpstrings) + 40];
//	struct mpstrings *loadedstrings;
//	struct mpstrings *bank;
//	u32 language_id = langGetFileNumOffset();
//	extern struct mpconfig _mpconfigsSegmentRomStart[];
//	extern struct mpstrings _mpstringsESegmentRomStart;
//	extern struct mpstrings _mpstringsJSegmentRomStart;
//	extern struct mpstrings _mpstringsPSegmentRomStart;
//	extern struct mpstrings _mpstringsGSegmentRomStart;
//	extern struct mpstrings _mpstringsFSegmentRomStart;
//	extern struct mpstrings _mpstringsSSegmentRomStart;
//	extern struct mpstrings _mpstringsISegmentRomStart;
//	extern struct mpstrings _mpstringsESegmentRomEnd;
//	extern struct mpstrings _mpstringsJSegmentRomEnd;
//	extern struct mpstrings _mpstringsPSegmentRomEnd;
//	extern struct mpstrings _mpstringsGSegmentRomEnd;
//	extern struct mpstrings _mpstringsFSegmentRomEnd;
//	extern struct mpstrings _mpstringsSSegmentRomEnd;
//	extern struct mpstrings _mpstringsISegmentRomEnd;
//
//	struct mpstrings *banks[][2] = {
//		{ &_mpstringsESegmentRomStart, &_mpstringsESegmentRomEnd },
//		{ &_mpstringsJSegmentRomStart, &_mpstringsJSegmentRomEnd },
//		{ &_mpstringsPSegmentRomStart, &_mpstringsPSegmentRomEnd },
//		{ &_mpstringsGSegmentRomStart, &_mpstringsGSegmentRomEnd },
//		{ &_mpstringsFSegmentRomStart, &_mpstringsFSegmentRomEnd },
//		{ &_mpstringsSSegmentRomStart, &_mpstringsSSegmentRomEnd },
//		{ &_mpstringsISegmentRomStart, &_mpstringsISegmentRomEnd },
//	};
//
//	// Load mpconfigs
//	mpconfig = dmaExecWithAutoAlign(buffer, &_mpconfigsSegmentRomStart[confignum], sizeof(struct mpconfig));
//
//	// Load mpstrings
//	bank = banks[language_id][0];
//	loadedstrings = dmaExecWithAutoAlign(buffer2, &bank[confignum], sizeof(struct mpstrings));
//
//	mpconfig->strings = *loadedstrings;
//
//	return mpconfig;
//}

struct mpconfigfull *mpLoadChallenge(s32 challengeindex, u8 *buffer, s32 len)
{
	return mpLoadConfig(g_MpChallenges[challengeindex].confignum, buffer, len);
}

struct mpconfigfull *mpGetNthAvailableChallengeSomething(s32 n, u8 *buffer, s32 len)
{
	s32 numavailable = 0;
	s32 challengeindex;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			if (numavailable == n) {
				return mpLoadChallenge(challengeindex, buffer, len);
			}

			numavailable++;
		}
	}

	return 0;
}

struct mpconfigfull *mpLoadCurrentChallenge(u8 *buffer, s32 len)
{
	return mpLoadChallenge(g_MpChallengeIndex, buffer, len);
}

/**
 * This is adding featurenum to the array, provided it's unique.
 */
s32 mpForceUnlockFeature(s32 featurenum, u8 *array, s32 tail, s32 len)
{
	s32 i;

	for (i = 0; i < tail; i++) {
		if (array[i] == featurenum) {
			break;
		}
	}

	if (i >= tail && tail < len) {
		array[tail] = featurenum;
		tail++;
	}

	return tail;
}

s32 mpForceUnlockSetupFeatures(struct mpsetup *setup, u8 *array, s32 len)
{
	s32 index = 0;
	s32 i;

	// Force unlock the weapons (if never held before)
	for (i = 0; i < 6; i++) {
		s32 featurenum = g_MpWeapons[setup->weapons[i]].unlockfeature;

		if (featurenum) {
			index = mpForceUnlockFeature(featurenum, array, index, len);
		}
	}

	// Force unlock the stage
	for (i = 0; i < mpGetNumStages(); i++) {
		if (g_MpArenas[i].stagenum == setup->stagenum) {
			s32 featurenum = g_MpArenas[i].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}
	}

	// Force unlock the scenario
	if (setup->scenario <= MPSCENARIO_CAPTURETHECASE) {
		s32 featurenum = g_MpScenarioOverviews[setup->scenario].requirefeature;

		if (featurenum) {
			index = mpForceUnlockFeature(featurenum, array, index, len);
		}
	}

	// Force unlock the scenario options
	if (setup->options & MPOPTION_ONEHITKILLS) {
		index = mpForceUnlockFeature(MPFEATURE_ONEHITKILLS, array, index, len);
	}

	if (setup->options & (MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART)) {
		index = mpForceUnlockFeature(MPFEATURE_SLOWMOTION, array, index, len);
	}

	return index;
}

void mpForceUnlockConfigFeatures(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex)
{
	s32 index = mpForceUnlockSetupFeatures(&config->setup, array, len);
	s32 featurenum;
	s32 numplayers;
	s32 i;

	for (i = 0; i < 8; i++) {
		s32 simtype = mpFindBotProfile(config->simulants[i].type, BOTDIFF_NORMAL);

		if (simtype >= 0) {
			featurenum = g_BotProfiles[simtype].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		for (numplayers = 0; numplayers < 4; numplayers++) {
			simtype = mpFindBotProfile(0, config->simulants[i].difficulties[numplayers]);

			if (simtype >= 0) {
				featurenum = g_BotProfiles[simtype].requirefeature;

				if (featurenum) {
					index = mpForceUnlockFeature(featurenum, array, index, len);
				}
			}
		}

		if (config->simulants[i].mpbodynum < NUM_MPBODIES) {
			featurenum = g_MpBodies[config->simulants[i].mpbodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		if (config->simulants[i].mpheadnum < NUM_MPHEADS) {
			featurenum = g_MpHeads[config->simulants[i].mpheadnum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (challengeindex >= 25) {
		index = mpForceUnlockFeature(MPFEATURE_BOTDIFF_DARK, array, index, len);
	} else if (challengeindex >= 20) {
		index = mpForceUnlockFeature(MPFEATURE_STAGE_CARPARK, array, index, len);
	} else if (challengeindex >= 15) {
		index = mpForceUnlockFeature(MPFEATURE_SCENARIO_PAC, array, index, len);
	}

	if (challengeindex >= 10) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, array, index, len);
	}
#else
	if (challengeindex >= 10) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, array, index, len);
	}

	if (challengeindex >= 15) {
		index = mpForceUnlockFeature(MPFEATURE_SCENARIO_PAC, array, index, len);
	}

	if (challengeindex >= 20) {
		index = mpForceUnlockFeature(MPFEATURE_STAGE_CARPARK, array, index, len);
	}
#endif

	// Clear the remainder of the array
	for (i = index; i < len; i++) {
		array[i] = 0;
	}
}

void mpForceUnlockSimulantFeatures(void)
{
	s32 numsims = 0;
	s32 index = mpForceUnlockSetupFeatures(&g_MpSetup, g_MpFeaturesForceUnlocked, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	s32 i;

	for (i = 0; i < 8; i++) {
		// Force unlock the simulant type
		s32 simtypeindex = mpFindBotProfile(g_BotConfigsArray[i].type, BOTDIFF_NORMAL);

		if (simtypeindex >= 0) {
			s32 featurenum = g_BotProfiles[simtypeindex].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant difficulty
		simtypeindex = mpFindBotProfile(BOTTYPE_GENERAL, g_BotConfigsArray[i].difficulty);

		if (simtypeindex >= 0) {
			s32 featurenum = g_BotProfiles[simtypeindex].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		if (simtypeindex >= 0) {
			numsims++;
		}

		// Force unlock the simulant's body
		if (g_BotConfigsArray[i].base.mpbodynum < NUM_MPBODIES) {
			s32 featurenum = g_MpBodies[g_BotConfigsArray[i].base.mpbodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant's head
		if (g_BotConfigsArray[i].base.mpheadnum < NUM_MPHEADS) {
			s32 featurenum = g_MpHeads[g_BotConfigsArray[i].base.mpheadnum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}
	}

	// Force unlock 8 simulants
	if (numsims > 4) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	}

	// Clear the remainder of the array
	for (i = index; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	mpDetermineUnlockedFeatures();
}

void func0f19c190(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	mpDetermineUnlockedFeatures();
}

void func0f19c1cc(void)
{
	s32 i;
	u8 buffer[458];

	mpApplyConfig(mpLoadCurrentChallenge(buffer, 458));
	mpSetLock(MPLOCKTYPE_CHALLENGE, 5);

	for (i = 0; i < 4; i++) {
		g_PlayerConfigsArray[i].base.team = 0;
	}
}

s32 mpRemoveLock(void)
{
	return mpSetLock(MPLOCKTYPE_NONE, 0);
}

void mpLoadAndStoreCurrentChallenge(u8 *buffer, s32 len)
{
	g_MpCurrentChallengeConfig = mpLoadCurrentChallenge(buffer, len);
}

void mpClearCurrentChallenge(void)
{
	g_MpCurrentChallengeConfig = NULL;
}

bool mpIsChallengeLoaded(void)
{
	return g_MpCurrentChallengeConfig != NULL;
}

char *mpGetCurrentChallengeDescription(void)
{
	if (g_MpCurrentChallengeConfig) {
		return g_MpCurrentChallengeConfig->strings.description;
	}

	return "";
}

char *mpconfigGetDescription(struct mpconfigfull *mpconfig)
{
	if (mpconfig) {
		return mpconfig->strings.description;
	}

	return "";
}

/**
 * Return the index of the first incomplete challenge, but if it's in the first
 * 4 then return index 4 because the first 4 are always shown.
 */
s32 mpGetAutoFocusedChallengeIndex(s32 mpchrnum)
{
	s32 challengeindex;
	s32 index = 0;

	for (challengeindex = 29; challengeindex >= 0; challengeindex--) {
		if (mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 1) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 2) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 3) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 4)) {
			index = challengeindex + 1;
			break;
		}
	}

	if (index < 4) {
		index = 4;
	}

	return index;
}

char *mpChallengeGetNameWithArg(s32 arg0, s32 challengeindex)
{
	return langGet(g_MpChallenges[challengeindex].name);
}

bool mpIsChallengeCompletedByPlayerWithNumPlayers2(s32 mpchrnum, s32 index, s32 numplayers)
{
	return mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, index, numplayers);
}

bool mpIsChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & 1) != 0;
}

void mpSetChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 1;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~1;
}

bool mpIsChallengeCompletedByPlayerWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & (2 << mpchrnum)) != 0;
}

void mpSetChallengeCompletedByPlayerWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 2 << mpchrnum;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~(2 << mpchrnum);
}

bool mpIsChallengeCompleteForEndscreen(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 result = false;
	s32 aborted = false;
	s32 i;
	u32 stack;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);

		if (g_Vars.currentplayer->aborted) {
			aborted = true;
		}
	}

	setCurrentPlayerNum(prevplayernum);

	if (!aborted) {
		struct ranking rankings[12];
		mpGetTeamRankings(rankings);

		if (rankings[0].teamnum == 0) {
			result = true;
		}
	}

	return result;
}

#if VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel mpConsiderMarkingCurrentChallengeComplete
/*  f19e354:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19e358:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f19e35c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19e360:	0fc67875 */ 	jal	mpIsChallengeCompleteForEndscreen
/*  f19e364:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19e368:	3c0e800a */ 	lui	$t6,0x800a
/*  f19e36c:	8dce6700 */ 	lw	$t6,0x6700($t6)
/*  f19e370:	3c0f800a */ 	lui	$t7,0x800a
/*  f19e374:	55c0008c */ 	bnezl	$t6,.PB0f19e5a8
/*  f19e378:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19e37c:	8def6704 */ 	lw	$t7,0x6704($t7)
/*  f19e380:	55e00089 */ 	bnezl	$t7,.PB0f19e5a8
/*  f19e384:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19e388:	14400004 */ 	bnez	$v0,.PB0f19e39c
/*  f19e38c:	00000000 */ 	nop
/*  f19e390:	0fc4810c */ 	jal	debugIsSetCompleteEnabled
/*  f19e394:	00000000 */ 	nop
/*  f19e398:	10400082 */ 	beqz	$v0,.PB0f19e5a4
.PB0f19e39c:
/*  f19e39c:	3c10800a */ 	lui	$s0,0x800a
/*  f19e3a0:	2610e4d0 */ 	addiu	$s0,$s0,-6960
/*  f19e3a4:	8e18006c */ 	lw	$t8,0x6c($s0)
/*  f19e3a8:	3c048009 */ 	lui	$a0,0x8009
/*  f19e3ac:	24060001 */ 	li	$a2,0x1
/*  f19e3b0:	53000004 */ 	beqzl	$t8,.PB0f19e3c4
/*  f19e3b4:	00004825 */ 	move	$t1,$zero
/*  f19e3b8:	10000002 */ 	b	.PB0f19e3c4
/*  f19e3bc:	24090001 */ 	li	$t1,0x1
/*  f19e3c0:	00004825 */ 	move	$t1,$zero
.PB0f19e3c4:
/*  f19e3c4:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f19e3c8:	53200004 */ 	beqzl	$t9,.PB0f19e3dc
/*  f19e3cc:	00004025 */ 	move	$t0,$zero
/*  f19e3d0:	10000002 */ 	b	.PB0f19e3dc
/*  f19e3d4:	24080001 */ 	li	$t0,0x1
/*  f19e3d8:	00004025 */ 	move	$t0,$zero
.PB0f19e3dc:
/*  f19e3dc:	8e0a0064 */ 	lw	$t2,0x64($s0)
/*  f19e3e0:	00001825 */ 	move	$v1,$zero
/*  f19e3e4:	11400003 */ 	beqz	$t2,.PB0f19e3f4
/*  f19e3e8:	00000000 */ 	nop
/*  f19e3ec:	10000001 */ 	b	.PB0f19e3f4
/*  f19e3f0:	24030001 */ 	li	$v1,0x1
.PB0f19e3f4:
/*  f19e3f4:	8e0b0070 */ 	lw	$t3,0x70($s0)
/*  f19e3f8:	00001025 */ 	move	$v0,$zero
/*  f19e3fc:	11600003 */ 	beqz	$t3,.PB0f19e40c
/*  f19e400:	00000000 */ 	nop
/*  f19e404:	10000001 */ 	b	.PB0f19e40c
/*  f19e408:	24020001 */ 	li	$v0,0x1
.PB0f19e40c:
/*  f19e40c:	00436021 */ 	addu	$t4,$v0,$v1
/*  f19e410:	01886821 */ 	addu	$t5,$t4,$t0
/*  f19e414:	01a92821 */ 	addu	$a1,$t5,$t1
/*  f19e418:	0fc67829 */ 	jal	mpSetChallengeCompletedByAnyPlayerWithNumPlayers
/*  f19e41c:	8c84a990 */ 	lw	$a0,-0x5670($a0)
/*  f19e420:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f19e424:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f19e428:	00008825 */ 	move	$s1,$zero
/*  f19e42c:	11e00003 */ 	beqz	$t7,.PB0f19e43c
/*  f19e430:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f19e434:	10000002 */ 	b	.PB0f19e440
/*  f19e438:	24090001 */ 	li	$t1,0x1
.PB0f19e43c:
/*  f19e43c:	00004825 */ 	move	$t1,$zero
.PB0f19e440:
/*  f19e440:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f19e444:	00004025 */ 	move	$t0,$zero
/*  f19e448:	00001825 */ 	move	$v1,$zero
/*  f19e44c:	13000003 */ 	beqz	$t8,.PB0f19e45c
/*  f19e450:	00001025 */ 	move	$v0,$zero
/*  f19e454:	10000001 */ 	b	.PB0f19e45c
/*  f19e458:	24080001 */ 	li	$t0,0x1
.PB0f19e45c:
/*  f19e45c:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f19e460:	13200003 */ 	beqz	$t9,.PB0f19e470
/*  f19e464:	00000000 */ 	nop
/*  f19e468:	10000001 */ 	b	.PB0f19e470
/*  f19e46c:	24030001 */ 	li	$v1,0x1
.PB0f19e470:
/*  f19e470:	8e0a0070 */ 	lw	$t2,0x70($s0)
/*  f19e474:	11400003 */ 	beqz	$t2,.PB0f19e484
/*  f19e478:	00000000 */ 	nop
/*  f19e47c:	10000001 */ 	b	.PB0f19e484
/*  f19e480:	24020001 */ 	li	$v0,0x1
.PB0f19e484:
/*  f19e484:	00435821 */ 	addu	$t3,$v0,$v1
/*  f19e488:	01686021 */ 	addu	$t4,$t3,$t0
/*  f19e48c:	01896821 */ 	addu	$t5,$t4,$t1
/*  f19e490:	19a00040 */ 	blez	$t5,.PB0f19e594
/*  f19e494:	00000000 */ 	nop
.PB0f19e498:
/*  f19e498:	0fc4a783 */ 	jal	setCurrentPlayerNum
/*  f19e49c:	02202025 */ 	move	$a0,$s1
/*  f19e4a0:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f19e4a4:	3c058009 */ 	lui	$a1,0x8009
/*  f19e4a8:	24070001 */ 	li	$a3,0x1
/*  f19e4ac:	11c00003 */ 	beqz	$t6,.PB0f19e4bc
/*  f19e4b0:	00004825 */ 	move	$t1,$zero
/*  f19e4b4:	10000001 */ 	b	.PB0f19e4bc
/*  f19e4b8:	24090001 */ 	li	$t1,0x1
.PB0f19e4bc:
/*  f19e4bc:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f19e4c0:	00004025 */ 	move	$t0,$zero
/*  f19e4c4:	00001825 */ 	move	$v1,$zero
/*  f19e4c8:	11e00003 */ 	beqz	$t7,.PB0f19e4d8
/*  f19e4cc:	00001025 */ 	move	$v0,$zero
/*  f19e4d0:	10000001 */ 	b	.PB0f19e4d8
/*  f19e4d4:	24080001 */ 	li	$t0,0x1
.PB0f19e4d8:
/*  f19e4d8:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f19e4dc:	13000003 */ 	beqz	$t8,.PB0f19e4ec
/*  f19e4e0:	00000000 */ 	nop
/*  f19e4e4:	10000001 */ 	b	.PB0f19e4ec
/*  f19e4e8:	24030001 */ 	li	$v1,0x1
.PB0f19e4ec:
/*  f19e4ec:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f19e4f0:	13200003 */ 	beqz	$t9,.PB0f19e500
/*  f19e4f4:	00000000 */ 	nop
/*  f19e4f8:	10000001 */ 	b	.PB0f19e500
/*  f19e4fc:	24020001 */ 	li	$v0,0x1
.PB0f19e500:
/*  f19e500:	8e0a0288 */ 	lw	$t2,0x288($s0)
/*  f19e504:	00435821 */ 	addu	$t3,$v0,$v1
/*  f19e508:	01686021 */ 	addu	$t4,$t3,$t0
/*  f19e50c:	01893021 */ 	addu	$a2,$t4,$t1
/*  f19e510:	8ca5a990 */ 	lw	$a1,-0x5670($a1)
/*  f19e514:	0fc67854 */ 	jal	mpSetChallengeCompletedByPlayerWithNumPlayers
/*  f19e518:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f19e51c:	8e0d006c */ 	lw	$t5,0x6c($s0)
/*  f19e520:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19e524:	00004825 */ 	move	$t1,$zero
/*  f19e528:	11a00003 */ 	beqz	$t5,.PB0f19e538
/*  f19e52c:	00004025 */ 	move	$t0,$zero
/*  f19e530:	10000001 */ 	b	.PB0f19e538
/*  f19e534:	24090001 */ 	li	$t1,0x1
.PB0f19e538:
/*  f19e538:	8e0e0068 */ 	lw	$t6,0x68($s0)
/*  f19e53c:	00001825 */ 	move	$v1,$zero
/*  f19e540:	00001025 */ 	move	$v0,$zero
/*  f19e544:	11c00003 */ 	beqz	$t6,.PB0f19e554
/*  f19e548:	00000000 */ 	nop
/*  f19e54c:	10000001 */ 	b	.PB0f19e554
/*  f19e550:	24080001 */ 	li	$t0,0x1
.PB0f19e554:
/*  f19e554:	8e0f0064 */ 	lw	$t7,0x64($s0)
/*  f19e558:	11e00003 */ 	beqz	$t7,.PB0f19e568
/*  f19e55c:	00000000 */ 	nop
/*  f19e560:	10000001 */ 	b	.PB0f19e568
/*  f19e564:	24030001 */ 	li	$v1,0x1
.PB0f19e568:
/*  f19e568:	8e180070 */ 	lw	$t8,0x70($s0)
/*  f19e56c:	13000003 */ 	beqz	$t8,.PB0f19e57c
/*  f19e570:	00000000 */ 	nop
/*  f19e574:	10000001 */ 	b	.PB0f19e57c
/*  f19e578:	24020001 */ 	li	$v0,0x1
.PB0f19e57c:
/*  f19e57c:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f19e580:	03285021 */ 	addu	$t2,$t9,$t0
/*  f19e584:	01495821 */ 	addu	$t3,$t2,$t1
/*  f19e588:	022b082a */ 	slt	$at,$s1,$t3
/*  f19e58c:	1420ffc2 */ 	bnez	$at,.PB0f19e498
/*  f19e590:	00000000 */ 	nop
.PB0f19e594:
/*  f19e594:	0fc4a783 */ 	jal	setCurrentPlayerNum
/*  f19e598:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f19e59c:	0fc67317 */ 	jal	mpDetermineUnlockedFeatures
/*  f19e5a0:	00000000 */ 	nop
.PB0f19e5a4:
/*  f19e5a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PB0f19e5a8:
/*  f19e5a8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19e5ac:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19e5b0:	03e00008 */ 	jr	$ra
/*  f19e5b4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#else
void mpConsiderMarkingCurrentChallengeComplete(void)
{
	bool result = mpIsChallengeCompleteForEndscreen();

#if VERSION >= VERSION_NTSC_1_0
	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result)
#else
	if (result && g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0)
#endif
	{
		u32 prevplayernum;
		s32 i;

		mpSetChallengeCompletedByAnyPlayerWithNumPlayers(g_MpChallengeIndex, PLAYERCOUNT(), 1);
		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			mpSetChallengeCompletedByPlayerWithNumPlayers(g_Vars.currentplayerstats->mpindex, g_MpChallengeIndex, PLAYERCOUNT(), true);
		}

		setCurrentPlayerNum(prevplayernum);
		mpDetermineUnlockedFeatures();
	}
}
#endif

bool mpIsFeatureUnlocked(s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & 1) != 0;
}

bool mpIsFeatureUnlockedByPlayer(u32 numplayers, s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & (2 << numplayers)) != 0;
}

bool mpIsFeatureUnlockedByDefault(s32 featurenum)
{
	if (featurenum) {
		return false;
	}

	return true;
}
