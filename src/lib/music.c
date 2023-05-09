#include <ultra64.h>
#include <n_libaudio.h>
#include "constants.h"
#include "game/music.h"
#include "game/game_176080.h"
#include "game/stagemusic.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "lib/lib_39c80.h"
#include "data.h"
#include "types.h"

#define RESULT_FAIL     0
#define RESULT_OK_NEXT  1
#define RESULT_OK_BREAK 2

const u8 var70053ca0[] = {0, 0, 0, 0, 0, 5};

s32 g_MusicNextAmbientTick240 = -1;

static s32 musicHandlePlayEvent(struct musicevent *event, s32 result)
{
	s32 i;
	u8 value;
	s32 j;
	s32 index;

	switch (event->tracktype) {
	case TRACKTYPE_NONE:
		break;
	case TRACKTYPE_PRIMARY:
		break;
	case TRACKTYPE_NRG:
		break;
	case TRACKTYPE_MENU:
		break;
	case TRACKTYPE_DEATH:
		break;
	case TRACKTYPE_AMBIENT:
		break;
	}


	// Check if this tracktype is currently in use. If it is then that's
	// an error - the caller should have stopped the existing track first.
	for (i = 0; i < 3; i++) {
		if (event->tracktype == var800aaa38[i].tracktype && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			value = event->tracktype == TRACKTYPE_AMBIENT ? 24 : 32;

			for (j = 0; j < 16; j++) {
				func00039e5c(g_SeqInstances[i].seqp, j, 0xff, value);
			}

			var800aaa38[i].unk08 = 0;
			var800aaa38[i].unk0c = 0;

			event->eventtype = 0;
			result = RESULT_OK_BREAK;
			break;
		}
	}

	if (result == RESULT_FAIL) {
		// Find an unused channel
		for (i = 0; i < 3; i++) {
			if (n_alCSPGetState(g_SeqInstances[i].seqp) == AL_STOPPED) {

				if (seqPlay(&g_SeqInstances[i], event->tracknum)) {
					seqSetVolume(&g_SeqInstances[i], event->volume);

					var800aaa38[i].tracktype = event->tracktype;
					var800aaa38[i].unk04 = 1;
					var800aaa38[i].unk08 = 0;
					var800aaa38[i].unk0c = 0;


					result = RESULT_OK_BREAK;
				}
				break;
			}
		}

		if (result == RESULT_FAIL) {
			index = -1;

			for (i = 0; i < 3; i++) {
				if ((var800aaa38[i].tracktype == TRACKTYPE_NONE || event->tracktype == var800aaa38[i].tracktype)
						&& n_alCSPGetState(g_SeqInstances[i].seqp) != AL_STOPPED) {
					index = i;
					break;
				}
			}

			if (index == -1) {
				if (event->failcount >= 3) {
					for (i = 0; i < 3; i++) {
						if (var800aaa38[i].tracktype == TRACKTYPE_AMBIENT
								&& n_alCSPGetState(g_SeqInstances[i].seqp) != AL_STOPPED) {
							index = i;
							break;
						}
					}
				}
			}

			if (index != -1) {
				n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[index].seqp);

				var800aaa38[index].tracktype = TRACKTYPE_NONE;
				var800aaa38[index].unk04 = 0;
				var800aaa38[index].unk08 = 0;
				var800aaa38[index].unk0c = 0;
			} else {
				event->failcount++;

				if (event->failcount >= 6) {
					result = RESULT_OK_BREAK;
				}
			}
		}
	}

	return result;
}


static s32 musicHandleStopEvent(struct musicevent *event, s32 result)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		if (event->tracktype == var800aaa38[i].tracktype) {
			n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

			var800aaa38[i].tracktype = TRACKTYPE_NONE;
			var800aaa38[i].unk04 = 0;
			var800aaa38[i].unk08 = 0;
			var800aaa38[i].unk0c = 0;

			break;
		}
	}

	return RESULT_OK_NEXT;
}

static s32 musicHandleFadeEvent(struct musicevent *event, s32 result)
{
	s32 i;
	s32 j;

	for (i = 0; i < 3; i++) {
		if (event->tracktype == var800aaa38[i].tracktype && var800aaa38[i].unk04 != 0) {
			for (j = 0; j < 16; j++) {
				func00039e5c(g_SeqInstances[i].seqp, j, var70053ca0[event->tracktype], 32);
			}

			var800aaa38[i].unk04 = event->fadetopause;
			var800aaa38[i].unk08 = event->fadetopause;
			var800aaa38[i].unk0c = g_SeqInstances[i].seqp->chanState[0].unk0d;
		}
	}

	return RESULT_OK_NEXT;
}

static s32 musicHandleStopAllEvent(s32 result)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

		var800aaa38[i].tracktype = 0;
		var800aaa38[i].unk04 = 0;
		var800aaa38[i].unk08 = 0;
		var800aaa38[i].unk0c = 0;
	}

	return RESULT_OK_NEXT;
}

static s32 musicHandleEvent5(struct musicevent *event, s32 result)
{
	var800840e0 = event->tracknum;
	return RESULT_OK_NEXT;
}

void musicTickEvents(void)
{
	s32 i;
	s32 j;
	s32 result;
	struct musicevent *event;

	for (i = 0; i < 3; i++) {
		if (var800aaa38[i].unk04 == 0 && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			if (g_SeqInstances[i].seqp->chanState[0].unk0d <= var70053ca0[var800aaa38[i].tracktype]) {
				n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

				var800aaa38[i].tracktype = TRACKTYPE_NONE;
				var800aaa38[i].unk04 = 0;
				var800aaa38[i].unk08 = 0;
				var800aaa38[i].unk0c = 0;
			} else if (g_SeqInstances[i].seqp->chanState[0].unk0d == var800aaa38[i].unk0c) {
				n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

				var800aaa38[i].tracktype = TRACKTYPE_NONE;
				var800aaa38[i].unk04 = 0;
				var800aaa38[i].unk08 = 0;
				var800aaa38[i].unk0c = 0;
			}
		}
	}

	// Figure out which events can be removed from the queue due to later
	// events superseding them. This loop just marks those events as
	// removable by setting their tracktype to none.
	for (i = g_MusicEventQueueLength - 1; i >= 0; i--) {
		event = &g_MusicEventQueue[i];

		if (event->eventtype == MUSICEVENTTYPE_5) {
			continue;
		}

		if (event->tracktype == TRACKTYPE_NONE) {
			continue;
		}

		for (j = i - 1; j >= 0; j--) {
			struct musicevent *earlier = &g_MusicEventQueue[j];

			if (event->eventtype == MUSICEVENTTYPE_STOPALL) {
				earlier->tracktype = TRACKTYPE_NONE;
				continue;
			}

			if (earlier->eventtype == MUSICEVENTTYPE_5) {
				continue;
			}

			if (earlier->tracktype == TRACKTYPE_NONE) {
				continue;
			}

			if (earlier->tracktype == event->tracktype) {
				switch (event->eventtype) {
				case MUSICEVENTTYPE_STOP:
					earlier->tracktype = TRACKTYPE_NONE;
					break;
				case MUSICEVENTTYPE_PLAY:
					switch (earlier->eventtype) {
					case MUSICEVENTTYPE_PLAY:
					case MUSICEVENTTYPE_FADE:
						earlier->tracktype = TRACKTYPE_NONE;
						break;
					}
					break;
				case MUSICEVENTTYPE_FADE:
					if (earlier->eventtype == MUSICEVENTTYPE_FADE) {
						earlier->tracktype = TRACKTYPE_NONE;
					}
					break;
				}
			}
		}
	}

	// Remove the marked events from the queue, shift the remaining
	// events forward and recount the queue length.
	for (i = 0, j = 0; i < g_MusicEventQueueLength; i++) {
		if (g_MusicEventQueue[i].tracktype) {
			g_MusicEventQueue[j] = g_MusicEventQueue[i];
			j++;

			g_MusicEventQueueLength += 0;
		}
	}

	g_MusicEventQueueLength = j;

	event = &g_MusicEventQueue[0];

	if (var800840e0 == 0 || var800840e4 < g_Vars.diffframe240) {
		var800840e4 = var800840e0;

		while (g_MusicEventQueueLength) {
			event->numattempts++;

			result = RESULT_FAIL;

			switch (event->eventtype) {
			case MUSICEVENTTYPE_PLAY:
				result = musicHandlePlayEvent(event, 0);
				break;
			case MUSICEVENTTYPE_STOP:
				result = musicHandleStopEvent(event, 0);
				break;
			case MUSICEVENTTYPE_FADE:
				result = musicHandleFadeEvent(event, 0);
				break;
			case MUSICEVENTTYPE_STOPALL:
				result = musicHandleStopAllEvent(0);
				break;
			case MUSICEVENTTYPE_5:
				result = musicHandleEvent5(event, 0);
				break;
			}

			if (result != RESULT_FAIL) {
				// Remove the item from the queue
				g_MusicEventQueueLength--;

				for (i = 0; i < g_MusicEventQueueLength; i++) {
					g_MusicEventQueue[i] = g_MusicEventQueue[i + 1];
				}

				// Break from processing further events on this frame
				// if requested
				if (result == RESULT_OK_BREAK) {
					break;
				}
			} else {
				break;
			}
		}
	}

	if (var800840e0) {
		var800840e4 -= g_Vars.diffframe240;
	} else {
		var800840e4 = 0;
	}
}

void musicTick(void)
{
	s32 i;
	bool playnrg = false;

	if (g_MusicDeathTimer240 > 0
			&& (g_Vars.normmplayerisrunning
				|| (g_Vars.antiplayernum >= 0 && !g_Vars.bond->isdead)
				|| (g_Vars.coopplayernum >= 0 && (!g_Vars.bond->isdead || !g_Vars.coop->isdead)))) {
		// Someone is dying in MP, or anti is dying, or *one* person is dying in coop
		g_MusicSilenceTimer60 = 0;
		g_MusicDeathTimer240 -= g_Vars.lvupdate240;

		if (g_MusicDeathTimer240 <= 0) {
			musicEndDeath();

			// The death is complete. Are we due to start a new track?
			if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning && g_MusicLife60 < g_MusicAge60) {
				g_MusicAge60 = 0;
				musicQueueStopEvent(TRACKTYPE_MENU);
				musicQueueStopEvent(TRACKTYPE_DEATH);
				musicQueueStopEvent(TRACKTYPE_PRIMARY);
				musicQueueStartEvent(TRACKTYPE_PRIMARY, stageGetPrimaryTrack(g_MusicStageNum), 0, musicGetVolume());
			}
		}
	} else if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning && g_MusicLife60 < g_MusicAge60) {
		// Due to start a new track. Fade out the old one,
		// then start a 2 second time before starting the new one.
		g_MusicAge60 = 0;
		musicQueueFadeEvent(TRACKTYPE_PRIMARY, 2, 1);
		g_MusicSilenceTimer60 = TICKS(120);
	}

	if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning) {
		g_MusicAge60 += g_Vars.diffframe60;

		// If the silence timer is set, it means we're transitioning between
		// songs in multiplayer. Tick the timer down, and when it reaches
		// zero start a new track.
		if (g_MusicSilenceTimer60 > 0) {
			g_MusicSilenceTimer60 -= g_Vars.diffframe60;

			if (g_MusicSilenceTimer60 <= 0) {
				musicQueueStopEvent(TRACKTYPE_MENU);
				musicQueueStopEvent(TRACKTYPE_DEATH);
				musicQueueStopEvent(TRACKTYPE_PRIMARY);
				musicQueueStartEvent(TRACKTYPE_PRIMARY, stageGetPrimaryTrack(g_MusicStageNum), 0, musicGetVolume());
			}
		}
	}

	// Handle stopping of NRG tune
	for (i = 0; i < 4; i++) {
		if (g_AudioXReasonsActive[i] || g_MusicXReasonMinDurations[i] > 0) {
			if (g_MusicXReasonMinDurations[i] >= g_Vars.lvupdate240) {
				g_MusicXReasonMinDurations[i] -= g_Vars.lvupdate240;
			} else {
				g_MusicXReasonMinDurations[i] = 0;
			}

			if (g_MusicXReasonMaxDurations[i] != 0) {
				if (g_MusicXReasonMaxDurations[i] >= g_Vars.lvupdate240) {
					g_MusicXReasonMaxDurations[i] -= g_Vars.lvupdate240;
				} else {
					g_MusicXReasonMaxDurations[i] = 0;
				}

				if (g_MusicXReasonMaxDurations[i] != 0) {
					if (g_AudioXReasonsActive[i] || g_MusicXReasonMinDurations[i]) {
						playnrg = true;
					}
				} else {
					g_AudioXReasonsActive[i] = 0;
				}
			}
		}
	}

	if (g_Vars.lvupdate240 != 0) {
		if (g_MusicNrgIsActive) {
			if (!playnrg) {
				musicDeactivateNrg();
			}
		} else {
			if (playnrg && !g_Vars.dontplaynrg) {
				musicActivateNrg();
			}
		}
	}

	// Check if the player is in an ambient room every 0.25 seconds
	if (g_Vars.lvupdate240 > g_MusicNextAmbientTick240) {
		musicTickAmbient();
		g_MusicNextAmbientTick240 = TICKS(60);
	} else {
		g_MusicNextAmbientTick240 -= g_Vars.lvupdate240;
	}

	musicTickEvents();
}
