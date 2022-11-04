#include <ultra64.h>
#include "constants.h"
#include "game/menu.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/options.h"
#include "game/stagemusic.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "data.h"
#include "types.h"

#define FADETYPE_STOP  0
#define FADETYPE_PAUSE 1

s32 g_MusicStageNum;
struct musicevent g_MusicEventQueue[40];
struct var800aaa38 var800aaa38[3];
u32 g_AudioXReasonsActive[4];
s32 g_MusicXReasonMinDurations[4];
s32 g_MusicXReasonMaxDurations[4];

s32 g_MenuTrack = -1;
s32 g_MusicEventQueueLength = 0;
s32 g_TemporaryPrimaryTrack = -1;
s32 g_TemporaryAmbientTrack = -1;

#if VERSION >= VERSION_NTSC_1_0
s32 var800840d0 = -1;
#endif

u32 g_MusicNextEventId = 0;
bool g_MusicNrgIsActive = false;
bool g_MusicMpDeathIsPlaying = false;
s32 var800840e0 = 15;
s32 var800840e4 = 0;
bool g_MusicSoloDeathIsPlaying = false;

#if VERSION >= VERSION_NTSC_1_0
u16 g_MusicVolume = 0x5000;
#endif

s32 g_MusicDeathTimer240 = 0;     // Counts down 5 seconds while death music plays
s32 g_MusicAge60 = 0;             // The current age of the MP track being played
s32 g_MusicLife60 = TICKS(120); // The max age of any MP track (this value is changed in MP code)
s32 g_MusicSilenceTimer60 = 0;    // Counts down the 2 second silence between MP track changes

#if VERSION < VERSION_NTSC_1_0
const char var7f1b2030nb[] = "MUSIC : musicPlayLevel\n";
const char var7f1b2048nb[] = "MUSIC : SWITCHING TO CORRECT AMBIENT TUNE\n";
const char var7f1b2074nb[] = "musicStartLevel\n";
const char var7f1b2088nb[] = "musicEndLevel\n";
const char var7f1b2098nb[] = "musicStartNRG\n";
const char var7f1b20a8nb[] = "musicEndNRG\n";
const char var7f1b20b8nb[] = "musicStartWatch start\n";
const char var7f1b20d0nb[] = "musicEndWatch start\n";
const char var7f1b20e8nb[] = "musicEndWatch end\n";
const char var7f1b20fcnb[] = "musicStartDead\n";
const char var7f1b210cnb[] = "musicStartTemporary\n";
const char var7f1b2124nb[] = "musicEndTemporary\n";
const char var7f1b2138nb[] = "musicStartCutscene\n";
const char var7f1b214cnb[] = "musicEndCutscene\n";
const char var7f1b2160nb[] = "musicStartAmbient : Tune=%d\n";
const char var7f1b2180nb[] = "musicEndAmbient\n";
#endif

char *var80084100[] = {
	"null",
	"leveltune",
	"nrgtune,watchtune,mpdeathtune",
	"ambience",
	"NULL",
	"playing",
	"paused",
};

#if VERSION >= VERSION_PAL_FINAL
u32 var8008465cpf = 0;
#endif

const char var7f1b7918[] = "MUSIC : activedeath=%d\n";

u16 musicGetVolume(void)
{
#if VERSION >= VERSION_NTSC_1_0
	u32 volume;

	if (g_MusicVolume < 0x5000) {
		volume = g_MusicVolume;
	} else {
		volume = 0x5000;
	}

	return volume;
#else
	return optionsGetMusicVolume();
#endif
}

void musicSetVolume(u16 volume)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype != TRACKTYPE_NONE && var800aaa38[i].tracktype != TRACKTYPE_AMBIENT) {
			seqSetVolume(&g_SeqInstances[i], volume);
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	g_MusicVolume = volume;
#endif
}

bool func0f16d0a8(s32 tracktype, s32 arg1)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			switch (arg1) {
			case 0: return var800aaa38[i].unk04 <= 0;
			case 1: return var800aaa38[i].unk04;
			case 2: return var800aaa38[i].unk08;
			}
		}
	}

	return false;
}

s32 func0f16d124(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			if (var800aaa38[i].unk08) {
				return 2;
			}

			if (var800aaa38[i].unk04) {
				return 1;
			}
		}
	}

	return 0;
}

s32 musicGetChannelByTrackType(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			return i;
		}
	}

	return -1;
}

void musicQueueStartEvent(u32 tracktype, u32 tracknum, f32 arg2, u16 volume)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].tracknum = tracknum;
		g_MusicEventQueue[g_MusicEventQueueLength].unk0c = arg2;
		g_MusicEventQueue[g_MusicEventQueueLength].volume = volume;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_PLAY;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void musicQueueStopEvent(s32 tracktype)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_STOP;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void musicQueueFadeEvent(s32 tracktype, f32 arg1, bool fadetopause)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].unk0c = arg1;
		g_MusicEventQueue[g_MusicEventQueueLength].fadetopause = fadetopause;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_FADE;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void musicReset(void)
{
	s32 i;

	if (!g_SndDisabled) {
		for (i = 0; i < 4; i++) {
			g_AudioXReasonsActive[i] = 0;
			g_MusicXReasonMinDurations[i] = 0;
			g_MusicXReasonMaxDurations[i] = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		func0f16d430();
		musicQueueStopAllEvent();
		musicQueueType5Event();
#else
		musicQueueStopAllEvent();
#endif

		g_MusicSoloDeathIsPlaying = false;
		g_MusicDeathTimer240 = 0;
		g_MenuTrack = -1;
		g_TemporaryPrimaryTrack = -1;
		g_TemporaryAmbientTrack = -1;
		g_MusicNrgIsActive = false;
	}
}

void musicQueueStopAllEvent(void)
{
#if VERSION >= VERSION_NTSC_1_0
	g_MusicEventQueue[0].tracktype = TRACKTYPE_6;
#endif

	g_MusicEventQueue[0].eventtype = MUSICEVENTTYPE_STOPALL;
	g_MusicEventQueue[0].id = g_MusicNextEventId++;
	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;

	g_MusicEventQueueLength = 1;

	musicTickEvents();
}

#if VERSION >= VERSION_NTSC_1_0
void func0f16d430(void)
{
	var800840d0 = var800840e0;
	var800840e0 = 0;
}

void musicQueueType5Event(void)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = TRACKTYPE_6;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_5;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].tracknum = var800840d0;
	g_MusicEventQueueLength++;

	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;
}
#endif

#define PRIMARYTRACK() (g_TemporaryPrimaryTrack != -1 ? g_TemporaryPrimaryTrack : stageGetPrimaryTrack(g_MusicStageNum))

void musicStartPrimary(f32 arg0)
{
	if (PRIMARYTRACK() >= 0) {
		musicQueueStartEvent(TRACKTYPE_PRIMARY, PRIMARYTRACK(), arg0, musicGetVolume());
	}
}

#define AMBIENTTRACK() (g_TemporaryAmbientTrack != -1 ? g_TemporaryAmbientTrack : stageGetAmbientTrack(g_MusicStageNum))

#if VERSION >= VERSION_NTSC_1_0
void musicStartAmbient(f32 arg0)
{
	s32 pass = false;

	if (AMBIENTTRACK() >= 0) {
		if (g_TemporaryAmbientTrack != -1) {
			pass = true;
		} else if (musicIsAnyPlayerInAmbientRoom()) {
			if (g_Vars.tickmode != TICKMODE_CUTSCENE && AMBIENTTRACK() != stageGetAmbientTrack(g_MusicStageNum)) {
				musicQueueStopEvent(TRACKTYPE_AMBIENT);
				musicStartTemporaryAmbient(stageGetAmbientTrack(g_MusicStageNum));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		pass = func0f16d124(TRACKTYPE_AMBIENT);

		if (pass == 0 || pass == 2) {
			musicQueueStartEvent(TRACKTYPE_AMBIENT, AMBIENTTRACK(), arg0, VOLUME(g_SfxVolume));
		}
	}
}
#else
GLOBAL_ASM(
glabel musicStartAmbient
/*  f16821c:	3c028008 */ 	lui	$v0,0x8008
/*  f168220:	8c42694c */ 	lw	$v0,0x694c($v0)
/*  f168224:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f168228:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16822c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f168230:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f168234:	10410003 */ 	beq	$v0,$at,.NB0f168244
/*  f168238:	00002825 */ 	or	$a1,$zero,$zero
/*  f16823c:	10000007 */ 	beqz	$zero,.NB0f16825c
/*  f168240:	00401825 */ 	or	$v1,$v0,$zero
.NB0f168244:
/*  f168244:	3c04800b */ 	lui	$a0,0x800b
/*  f168248:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*  f16824c:	0fc5c65e */ 	jal	stageGetAmbientTrack
/*  f168250:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f168254:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f168258:	00401825 */ 	or	$v1,$v0,$zero
.NB0f16825c:
/*  f16825c:	0460002c */ 	bltz	$v1,.NB0f168310
/*  f168260:	3c0e8008 */ 	lui	$t6,0x8008
/*  f168264:	8dce694c */ 	lw	$t6,0x694c($t6)
/*  f168268:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16826c:	11c10003 */ 	beq	$t6,$at,.NB0f16827c
/*  f168270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f168274:	10000026 */ 	beqz	$zero,.NB0f168310
/*  f168278:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f16827c:
/*  f16827c:	0fc5a0df */ 	jal	musicIsAnyPlayerInAmbientRoom
/*  f168280:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f168284:	10400022 */ 	beqz	$v0,.NB0f168310
/*  f168288:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f16828c:	3c0f800a */ 	lui	$t7,0x800a
/*  f168290:	8defe96c */ 	lw	$t7,-0x1694($t7)
/*  f168294:	24010006 */ 	addiu	$at,$zero,0x6
/*  f168298:	3c028008 */ 	lui	$v0,0x8008
/*  f16829c:	51e1001c */ 	beql	$t7,$at,.NB0f168310
/*  f1682a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1682a4:	8c42694c */ 	lw	$v0,0x694c($v0)
/*  f1682a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1682ac:	3c04800b */ 	lui	$a0,0x800b
/*  f1682b0:	10410003 */ 	beq	$v0,$at,.NB0f1682c0
/*  f1682b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1682b8:	10000004 */ 	beqz	$zero,.NB0f1682cc
/*  f1682bc:	00401825 */ 	or	$v1,$v0,$zero
.NB0f1682c0:
/*  f1682c0:	0fc5c65e */ 	jal	stageGetAmbientTrack
/*  f1682c4:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*  f1682c8:	00401825 */ 	or	$v1,$v0,$zero
.NB0f1682cc:
/*  f1682cc:	3c04800b */ 	lui	$a0,0x800b
/*  f1682d0:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*  f1682d4:	0fc5c65e */ 	jal	stageGetAmbientTrack
/*  f1682d8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f1682dc:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f1682e0:	5043000b */ 	beql	$v0,$v1,.NB0f168310
/*  f1682e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1682e8:	0fc59fed */ 	jal	musicQueueStopEvent
/*  f1682ec:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f1682f0:	3c04800b */ 	lui	$a0,0x800b
/*  f1682f4:	0fc5c65e */ 	jal	stageGetAmbientTrack
/*  f1682f8:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*  f1682fc:	0fc5a2f1 */ 	jal	musicStartTemporaryAmbient
/*  f168300:	00402025 */ 	or	$a0,$v0,$zero
/*  f168304:	1000001a */ 	beqz	$zero,.NB0f168370
/*  f168308:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16830c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f168310:
/*  f168310:	50a00017 */ 	beqzl	$a1,.NB0f168370
/*  f168314:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f168318:	0fc59fa6 */ 	jal	func0f16d124
/*  f16831c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f168320:	10400002 */ 	beqz	$v0,.NB0f16832c
/*  f168324:	24010002 */ 	addiu	$at,$zero,0x2
/*  f168328:	14410010 */ 	bne	$v0,$at,.NB0f16836c
.NB0f16832c:
/*  f16832c:	3c028008 */ 	lui	$v0,0x8008
/*  f168330:	8c42694c */ 	lw	$v0,0x694c($v0)
/*  f168334:	2401ffff */ 	addiu	$at,$zero,-1
/*  f168338:	3c04800b */ 	lui	$a0,0x800b
/*  f16833c:	10410003 */ 	beq	$v0,$at,.NB0f16834c
/*  f168340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f168344:	10000004 */ 	beqz	$zero,.NB0f168358
/*  f168348:	00402825 */ 	or	$a1,$v0,$zero
.NB0f16834c:
/*  f16834c:	0fc5c65e */ 	jal	stageGetAmbientTrack
/*  f168350:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*  f168354:	00402825 */ 	or	$a1,$v0,$zero
.NB0f168358:
/*  f168358:	3c078006 */ 	lui	$a3,0x8006
/*  f16835c:	94e7f6e8 */ 	lhu	$a3,-0x918($a3)
/*  f168360:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f168364:	0fc59fcc */ 	jal	musicQueueStartEvent
/*  f168368:	8fa60020 */ 	lw	$a2,0x20($sp)
.NB0f16836c:
/*  f16836c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f168370:
/*  f168370:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f168374:	03e00008 */ 	jr	$ra
/*  f168378:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

bool musicIsAnyPlayerInAmbientRoom(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return false;
	}

	if (lvIsPaused()) {
		return false;
	}

	if (g_MusicSoloDeathIsPlaying) {
		return false;
	}

	if (g_MusicNrgIsActive && g_MusicMpDeathIsPlaying) {
		return false;
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (g_Vars.players[i]->prop
				&& g_Vars.players[i]->prop->rooms
				&& g_Vars.players[i]->prop->rooms[0] != -1) {
			bool hasflag;

			if (g_Rooms[g_Vars.players[i]->prop->rooms[0]].flags & ROOMFLAG_PLAYAMBIENTTRACK) {
				hasflag = true;
			} else {
				hasflag = false;
			}

			if (hasflag) {
				return true;
			}
		}
	}

	return false;
}

void musicStartNrg(f32 arg0)
{
	musicQueueStartEvent(TRACKTYPE_NRG, stageGetNrgTrack(g_MusicStageNum), arg0, musicGetVolume());
}

/**
 * Not called.
 */
void musicStartWatch(f32 arg0)
{
	musicQueueStartEvent(TRACKTYPE_MENU, menuChooseMusic(), arg0, musicGetVolume());
}

/**
 * Play a specific track as a menu track.
 *
 * Used in credits and the soundtrack dialog in MP setup.
 */
void musicStartTrackAsMenu(s32 tracknum)
{
	if (tracknum != g_MenuTrack) {
		musicQueueStopEvent(TRACKTYPE_MENU);
		musicQueueStopEvent(TRACKTYPE_DEATH);
		musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.5f, FADETYPE_PAUSE);
		musicQueueFadeEvent(TRACKTYPE_NRG, 0.5f, FADETYPE_PAUSE);
		musicQueueFadeEvent(TRACKTYPE_AMBIENT, 0.5f, FADETYPE_PAUSE);
		musicQueueStartEvent(TRACKTYPE_MENU, tracknum, 0, musicGetVolume());
	}

	g_MenuTrack = tracknum;
}

/**
 * Used when starting combat simulator matches.
 */
void musicSetStageAndStartMusic(s32 stagenum)
{
	g_MusicStageNum = stagenum;

	musicStartPrimary(0);

	if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(0);
	}
}

/**
 * Used for solo missions.
 */
void musicSetStage(s32 stagenum)
{
	g_MusicStageNum = stagenum;
}

void musicStop(void)
{
#if VERSION >= VERSION_NTSC_1_0
	func0f16d430();
	musicQueueStopAllEvent();
	musicQueueType5Event();
#else
	musicQueueStopAllEvent();
#endif
}

void musicActivateNrg(void)
{
#if VERSION >= VERSION_NTSC_1_0
	if (!g_MusicNrgIsActive)
#endif
	{
		if (stageGetNrgTrack(g_MusicStageNum) >= 0) {
			musicQueueStopEvent(TRACKTYPE_NRG);
			musicQueueStopEvent(TRACKTYPE_MENU);
			musicQueueStopEvent(TRACKTYPE_DEATH);
			musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.5, FADETYPE_PAUSE);
			musicStartNrg(0);

			g_MusicNrgIsActive = true;
		}
	}
}

void musicDeactivateNrg(void)
{
#if VERSION >= VERSION_NTSC_1_0
	if (g_MusicNrgIsActive)
#endif
	{
		musicQueueStopEvent(TRACKTYPE_MENU);
		musicQueueStopEvent(TRACKTYPE_DEATH);
		musicQueueFadeEvent(TRACKTYPE_NRG, 1, FADETYPE_STOP);

		if (g_Vars.dontplaynrg == false) {
			musicStartPrimary(0.5);
		}

		g_MusicNrgIsActive = false;
	}
}

/**
 * Called in many places when opening a pause menu.
 */
void musicStartMenu(void)
{
	musicStartTrackAsMenu(menuChooseMusic());
}

void musicEndMenu(void)
{
	musicQueueFadeEvent(TRACKTYPE_MENU, 1, FADETYPE_STOP);

	if (func0f16d0a8(TRACKTYPE_NRG, 1)) {
		musicStartNrg(1);
	} else {
		musicStartPrimary(1);
	}

	g_MenuTrack = -1;
}

void musicStartSoloDeath(void)
{
	g_MusicSoloDeathIsPlaying = true;

#if VERSION >= VERSION_NTSC_1_0
	func0f16d430();
#endif

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicQueueStartEvent(TRACKTYPE_PRIMARY, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());

#if VERSION >= VERSION_NTSC_1_0
	musicQueueType5Event();
#endif
}

void _musicStartMpDeath(f32 arg0)
{
#if VERSION >= VERSION_NTSC_1_0
	func0f16d430();
	musicQueueStartEvent(TRACKTYPE_DEATH, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());
	musicQueueType5Event();
#else
	musicQueueStartEvent(TRACKTYPE_DEATH, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());
#endif
}

void musicStartMpDeath(void)
{
#if VERSION >= VERSION_NTSC_1_0
	func0f16d430();
#endif

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);

	if (g_MusicNrgIsActive) {
		musicQueueFadeEvent(TRACKTYPE_NRG, 0.1f, FADETYPE_PAUSE);
	} else {
		musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.1f, FADETYPE_PAUSE);
	}

	_musicStartMpDeath(0);

	g_MusicDeathTimer240 = TICKS(1200);
	g_MusicMpDeathIsPlaying = true;

#if VERSION >= VERSION_NTSC_1_0
	musicQueueType5Event();
#endif
}

void musicEndDeath(void)
{
	musicQueueFadeEvent(TRACKTYPE_DEATH, 2, FADETYPE_STOP);

	if (g_MusicNrgIsActive) {
		musicStartNrg(2);
	} else {
		musicStartPrimary(2);
	}

	g_MusicMpDeathIsPlaying = false;
}

/**
 * Stop all other music and play the given track.
 *
 * It's used by the AI scripting language, specifically for CI training and
 * the Skedar King battle.
 *
 * The track type used is primary.
 */
void musicPlayTrackIsolated(s32 tracknum)
{
#if VERSION >= VERSION_NTSC_1_0
	func0f16d430();
#endif

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicQueueStartEvent(TRACKTYPE_PRIMARY, tracknum, 0, musicGetVolume());

#if VERSION >= VERSION_NTSC_1_0
	musicQueueType5Event();
#endif
}

/**
 * Restart the level's default tracks after using the isolated track above.
 *
 * It's used by the AI scripting language, specifically when ending CI training.
 */
void musicPlayDefaultTracks(void)
{
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicStartPrimary(0.5f);
}

/**
 * Used by the title screen, as well as AF1's NRG theme which never ends.
 */
void musicStartTemporaryPrimary(s32 tracknum)
{
	musicQueueStopEvent(TRACKTYPE_PRIMARY);

	g_TemporaryPrimaryTrack = tracknum;

	musicStartPrimary(0.5f);
}

/**
 * Used by AI scripting on each stage.
 *
 * The cutscene track is played with a primary tracktype.
 *
 * The NRG theme will not play while a cutscene theme is active.
 */
void musicStartCutscene(s32 tracknum)
{
	u32 volume;

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);

	if (g_SfxVolume < musicGetVolume()) {
		volume = musicGetVolume();
	} else {
		volume = g_SfxVolume;
	}

	musicQueueStartEvent(TRACKTYPE_PRIMARY, tracknum, 0, volume);

	g_Vars.dontplaynrg = true;
}

/**
 * Used by AI scripting on each stage.
 */
void musicEndCutscene(void)
{
	g_Vars.dontplaynrg = false;

	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicStartPrimary(0.5f);
}

/**
 * Used by AI scripting, and only to set the ambient track during the Defection
 * intro and Extraction outro to traffic noises.
 */
void musicStartTemporaryAmbient(s32 tracknum)
{
	g_TemporaryAmbientTrack = tracknum;
	musicQueueStopEvent(TRACKTYPE_AMBIENT);

	musicQueueStartEvent(TRACKTYPE_AMBIENT, tracknum, 0, VOLUME(g_SfxVolume));
}

void musicEndTemporaryAmbient(void)
{
	g_TemporaryAmbientTrack = -1;
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
}

void musicSetXReason(s32 reason, u32 minsecs, u32 maxsecs)
{
	if (g_AudioXReasonsActive[reason] == false) {
		g_AudioXReasonsActive[reason] = true;
		g_MusicXReasonMinDurations[reason] = minsecs * TICKS(240);
		g_MusicXReasonMaxDurations[reason] = maxsecs * TICKS(240);
	}
}

void musicUnsetXReason(s32 reason)
{
	s32 i;

	if (reason >= 0) {
		g_AudioXReasonsActive[reason] = false;
	} else {
		for (i = 0; i < 4; i++) {
			g_AudioXReasonsActive[i] = false;
			g_MusicXReasonMinDurations[i] = 0;
			g_MusicXReasonMaxDurations[i] = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_MusicNrgIsActive) {
			musicDeactivateNrg();
		}
#endif
	}
}

/**
 * Called by musicTick every 0.25 seconds.
 */
void musicTickAmbient(void)
{
	if (g_TemporaryAmbientTrack == -1) {
		if (musicIsAnyPlayerInAmbientRoom()) {
			musicStartAmbient(1);
		} else if (func0f16d124(TRACKTYPE_AMBIENT) == 1) {
			musicQueueFadeEvent(TRACKTYPE_AMBIENT, 1, FADETYPE_PAUSE);
		}
	} else if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(1);
	}
}

void func0f16e1cc(void)
{
	// empty
}
