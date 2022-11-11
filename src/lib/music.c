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

s32 musicHandlePlayEvent(struct musicevent *event, s32 result)
{
	s32 i;
	u8 value;
	s32 j;
	s32 index;

	switch (event->tracktype) {
	case TRACKTYPE_NONE:
		osSyncPrintf("OFF");
		break;
	case TRACKTYPE_PRIMARY:
		osSyncPrintf("LEVELTUNE");
		break;
	case TRACKTYPE_NRG:
		osSyncPrintf("NRGTUNE");
		break;
	case TRACKTYPE_MENU:
		osSyncPrintf("WATCHTUNE");
		break;
	case TRACKTYPE_DEATH:
		osSyncPrintf("MPDEATHTUNE");
		break;
	case TRACKTYPE_AMBIENT:
		osSyncPrintf("AMBIENCE");
		break;
	}

	osSyncPrintf(" after %d %s\n", event->failcount, event->failcount != 1 ? "Attempts" : "Attempt");

	// Check if this tracktype is currently in use. If it is then that's
	// an error - the caller should have stopped the existing track first.
	for (i = 0; i < 3; i++) {
		if (event->tracktype == var800aaa38[i].tracktype && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			value = event->tracktype == TRACKTYPE_AMBIENT ? 24 : 32;

			for (j = 0; j < 16; j++) {
				func00039e5c(g_SeqInstances[i].seqp, j, 0xff, value);
				osSyncPrintf("MUSIC(Play) : Unpaused midi channel %d for state %d\n", j, event->tracktype);
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
				osSyncPrintf("MUSIC(Play) : Starting, Guid=%u, Midi=%d, Tune=%d\n", event->id, 0, event->tracktype);

				if (seqPlay(&g_SeqInstances[i], event->tracknum)) {
					seqSetVolume(&g_SeqInstances[i], event->volume);

					var800aaa38[i].tracktype = event->tracktype;
					var800aaa38[i].unk04 = 1;
					var800aaa38[i].unk08 = 0;
					var800aaa38[i].unk0c = 0;

					osSyncPrintf("MUSIC(Play) : Done\n");

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
					osSyncPrintf("MUSIC(Play) : About to dump the fading channel %d as a same state play request is waiting\n", index);
					break;
				}
			}

			if (index == -1) {
				if (event->failcount >= 3) {
					for (i = 0; i < 3; i++) {
						if (var800aaa38[i].tracktype == TRACKTYPE_AMBIENT
								&& n_alCSPGetState(g_SeqInstances[i].seqp) != AL_STOPPED) {
							index = i;
							osSyncPrintf("MUSIC(Play) : About to dump the ambience channel %d\n", index);
							osSyncPrintf("MUSIC(Play) : Reason : A play request is waiting - State = %d\n", event->tracktype);
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
				osSyncPrintf("MUSIC(Play) : SERIOUS -> Out of MIDI channels - Attempt = %d\n", event->failcount);

				if (event->failcount >= 6) {
					osSyncPrintf("MUSIC(Play) : SERIOUS -> Tried %d times to play tune : Giving up\n", event->failcount);
					result = RESULT_OK_BREAK;
				}
			}
		}
	}

	return result;
}

const char var70053ee0[] = "MUSIC : Fading to pause\n";
const char var70053efc[] = "Music : Update Rate = %d";
const char var70053f18[] = "MUSIC TICK : Queue size = %d\n";
const char var70053f38[] = "MUSIC : Tick -> Channel %d (State=%d) has faded to stop : Dumping\n";
const char var70053f7c[] = "MUSIC : WARNING -> Force fade termination\n";
const char var70053fa8[] = "MUSIC TICK : Job Guid = %u\n";

s32 musicHandleStopEvent(struct musicevent *event, s32 result)
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

s32 musicHandleFadeEvent(struct musicevent *event, s32 result)
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

s32 musicHandleStopAllEvent(s32 result)
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

#if VERSION >= VERSION_NTSC_1_0
s32 musicHandleEvent5(struct musicevent *event, s32 result)
{
	var800840e0 = event->tracknum;
	return RESULT_OK_NEXT;
}
#endif

void musicTickEvents(void)
{
	s32 i;
	s32 j;
	s32 result;
	struct musicevent *event;

	if (!g_SndDisabled) {
		if (g_MusicEventQueueLength);

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
}

void musicTick(void)
{
	s32 i;
	bool playnrg = false;

	if (!g_SndDisabled) {
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

#if VERSION >= VERSION_NTSC_1_0
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
#else
		if (g_Vars.lvupdate240 != 0) {
			if (func0f16d0a8(TRACKTYPE_NRG, 1)) {
				if (!playnrg) {
					musicDeactivateNrg();
				}
			} else {
				if (playnrg && !g_Vars.dontplaynrg) {
					musicActivateNrg();
				}
			}
		}
#endif

		// Check if the player is in an ambient room every 0.25 seconds
		if (g_Vars.lvupdate240 > g_MusicNextAmbientTick240) {
			musicTickAmbient();
			g_MusicNextAmbientTick240 = TICKS(60);
		} else {
			g_MusicNextAmbientTick240 -= g_Vars.lvupdate240;
		}

		musicTickEvents();
	}
}

bool musicIsTrackTypePlaying(s32 tracktype)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		if (tracktype == var800aaa38[i].tracktype && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			return true;
		}
	}

	return false;
}

#if VERSION < VERSION_NTSC_1_0
bool musicAreTracksPlaying(u8 bits)
{
	if ((bits & 0x01) && !musicIsTrackTypePlaying(TRACKTYPE_PRIMARY)) {
		return false;
	}

	if ((bits & 0x02) && !musicIsTrackTypePlaying(TRACKTYPE_NRG)) {
		return false;
	}

	if ((bits & 0x04) && !musicIsTrackTypePlaying(TRACKTYPE_MENU)) {
		return false;
	}

	if ((bits & 0x08) && !musicIsTrackTypePlaying(TRACKTYPE_DEATH)) {
		return false;
	}

	if ((bits & 0x10) && !musicIsTrackTypePlaying(TRACKTYPE_AMBIENT)) {
		return false;
	}

	return true;
}
#endif
