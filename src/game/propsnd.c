#include <ultra64.h>
#include "constants.h"
#include "game/chraicommands.h"
#include "game/dlights.h"
#include "game/propsnd.h"
#include "game/atan2f.h"
#include "game/hudmsg.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

struct pschannel *g_PsChannels = NULL;

#if VERSION >= VERSION_NTSC_1_0
u32 g_AudioPrevUuid = 0;
#endif

s8 var8006ae18 = 0;
s8 var8006ae1c = 0;
s8 var8006ae20 = 0;
s8 var8006ae24 = 0;
s8 var8006ae28 = 0;
u32 var8006ae2c = 0;
u32 var8006ae30 = 0;
u32 var8006ae34 = 0;
u32 var8006ae38 = 0;
bool g_PsPrintAll = false;

u32 var8006ae40 = 0;
bool g_PsPrintFlagged = false;
u32 var8006ae48 = 1;
u32 var8006ae4c = 0;
s16 g_PsLastPositionalSoundnum = -1;
u32 var8006ae54 = 999;

void ps_stop_channel(s32 channelnum);
s32 ps_calculate_vol(struct coord *pos, f32 dist1, f32 dist2, f32 dist3, RoomNum *rooms, s16 soundnum, s32 arg6, f32 *playerdistptr);
s32 ps_calculate_pan(struct coord *pos, f32 dist1, f32 dist2, f32 dist3, f32 playerdist, bool specialpan, struct pschannel *channel);

bool ps_prop_has_sound_with_context(struct prop *prop, s32 type)
{
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		if ((g_PsChannels[i].flags & PSFLAG_FREE) == 0
				&& g_PsChannels[i].prop == prop
				&& (g_PsChannels[i].type == type || type == PSTYPE_GENERAL)) {
			return true;
		}
	}

	return false;
}

void ps_stop_sound(struct prop *prop, s32 type, u16 flags)
{
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		struct pschannel *channel = &g_PsChannels[i];

		if ((channel->flags & PSFLAG_FREE) == 0 && channel->prop == prop) {
			if (!channel->flags || !flags || (flags & channel->flags)) {
				if (channel->type == type || type == PSTYPE_GENERAL) {
					ps_stop_channel(i);
				}
			}
		}
	}
}

s32 ps_calculate_volume_from_distance(f32 playerdist, f32 dist1, f32 dist2, f32 dist3, s32 fullvolume)
{
	s32 result = 0;

	if (playerdist < dist3) {
		if (dist1 > 5501) {
			dist1 = 5501;
		}

		if (dist2 > 5801) {
			dist2 = 5801;
		}

		if (dist3 > 6000) {
			dist3 = 6000;
		}

		if (playerdist < dist1) {
			// Within dist1 -> vol full
			result = fullvolume;
		} else if (playerdist < dist2) {
			// Range dist1 to dist2 -> scale down using curve
			result = fullvolume - (s32) (sqrtf((playerdist - dist1) / (dist2 - dist1)) * (fullvolume - 1000.0f));
		} else {
			// Range dist2 to dist3 -> scale to zero linearly
			result = (dist3 - playerdist) * 1000.0f / (dist3 - dist2);
		}
	}

	if (result > AL_VOL_FULL) {
		result = AL_VOL_FULL;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (result < 40) {
		result = 0;
	}
#endif

	return result;
}

s32 ps_get_volume(s32 channelnum)
{
	return CHANNEL_IS_AI(channelnum) ? g_PsChannels[channelnum].currentvol : 0;
}

/**
 * Play the given soundnum for the prop, provided the prop doesn't already have
 * a sound playing with this type.
 */
void ps_create_if_not_dupe(struct prop *prop, s16 soundnum, s32 type)
{
	s32 i;

	if (ps_calculate_vol(&prop->pos, 400, 2500, 3000, prop->rooms, soundnum, AL_VOL_FULL, 0) != 0) {
		for (i = CHANNEL_HEAP_FIRST; i < CHANNELCOUNT(); i++) {
			if ((g_PsChannels[i].flags & PSFLAG_FREE) == 0
					&& g_PsChannels[i].prop == prop
					&& g_PsChannels[i].type == type) {
				return;
			}
		}

		ps_create(NULL, prop, soundnum, -1, -1, PSFLAG_REPEATING, 0, type, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
	}
}

/**
 * Stop the sound that's playing in the given channel.
 * The channel remains allocated and configured.
 */
void ps_stop_channel(s32 channelnum)
{
	struct pschannel *channel = &g_PsChannels[channelnum];

#if VERSION < VERSION_NTSC_1_0
	osSyncPrintf("SND : Stop -> Prop=%x, Id=%d\n", channel->prop, channelnum);
#endif

#if VERSION >= VERSION_NTSC_1_0
	channel->flags2 |= PSFLAG2_STOPPED;
#endif

	if (channel->flags & PSFLAG_FORHUDMSG) {
		hudmsgs_hide_by_channel(channelnum);
	}

	if (channel->flags & PSFLAG_FORPROP) {
		prop_decrement_sound_count(channel->prop);
	}

	if (channel->flags & PSFLAG_ISMP3) {
		snd_stop_mp3(channel->requestedsoundnum);
	} else if (channel->audiohandle && sndp_get_state(channel->audiohandle) != AL_STOPPED) {
		sndp_stop_sound(channel->audiohandle);
	}

#if VERSION < VERSION_NTSC_1_0
	channel->flags = PSFLAG_FREE;
#endif
}

void ps_print_channel(struct pschannel *channel)
{
	s32 i;

	for (i = 0; channel->rooms[i] != -1; i++) {
		// empty
	}
}

s32 ps_get_subtitle_opacity(s32 channelnum)
{
	if (channelnum == -1) {
		return 1;
	}

	if ((g_PsChannels[channelnum].flags & PSFLAG_FREE) == 0) {
		s32 value = g_PsChannels[channelnum].currentvol;

		if (value == -1 || value > 200) {
			s32 tmp = g_PsChannels[channelnum].currentvol - 200;
			s32 opacity = tmp * 255 / 15800;

			if (opacity > 255) {
				opacity = 255;
			}

			return opacity;
		}
	}

	return 0;
}

void ps_tick_channel(s32 channelnum)
{
	struct pschannel *channel = &g_PsChannels[channelnum];

#if VERSION >= VERSION_NTSC_1_0
	if ((channel->flags2 & PSFLAG2_STOPPED) == 0
			&& channel->type != PSTYPE_MARKER
			&& ((channel->audiohandle != NULL && sndp_get_state(channel->audiohandle) != AL_STOPPED)
				|| (channel->flags & PSFLAG_REPEATING)
				|| (channel->flags & PSFLAG_FIRSTTICK)
				|| ((channel->flags & PSFLAG_ISMP3) && snd_is_playing_mp3())))
#else
	if ((channel->audiohandle != NULL && sndp_get_state(channel->audiohandle) != AL_STOPPED)
			|| (channel->flags & PSFLAG_REPEATING)
			|| (channel->flags & PSFLAG_FIRSTTICK)
			|| ((channel->flags & PSFLAG_ISMP3) && snd_is_playing_mp3()))
#endif
	{
		struct coord *pos = NULL;
		RoomNum *rooms = NULL;
		s32 newvol;
		s32 newpan;
		s32 newfx;
		f32 newpitch;

		if (channel->prop) {
			pos = &channel->prop->pos;
			rooms = channel->prop->rooms;
		} else if (channel->rooms[0] != -1) {
			rooms = channel->rooms;
		}

		if (channel->posptr != NULL) {
			pos = channel->posptr;
		}

		if (1);

		if (g_Vars.langfilteron && (channel->flags2 & PSFLAG2_OFFENSIVE)) {
			channel->targetvol = 0;
		} else if (channel->flags2 & PSFLAG2_AMBIENT) {
			if (channel->flags & PSFLAG_FIRSTTICK) {
				channel->targetvol = channel->maxvol;
			} else {
				return;
			}
		} else {
			if (pos && rooms) {
				RoomNum *tmprooms;

				if (channel->flags & PSFLAG_IGNOREROOMS) {
					tmprooms = NULL;
				} else {
					tmprooms = rooms;
				}

				g_PsLastPositionalSoundnum = channel->resolvedsoundnum;

				channel->targetvol = ps_calculate_vol(pos, channel->dist1, channel->dist2, channel->dist3,
						tmprooms, channel->requestedsoundnum, channel->maxvol, &channel->distance);
			}

			if ((channel->flags & PSFLAG_HASCONFIGPAN) == 0) {
				channel->targetpan = ps_calculate_pan(pos, channel->dist1, channel->dist2, channel->dist3,
						channel->distance, channel->flags & PSFLAG_SPECIALPAN, channel);
			}
		}

		if (rooms != NULL && rooms[0] != -1) {
			channel->targetfx = 0;
			channel->fxbus = 1;
		} else {
			channel->targetfx = 0;
			channel->fxbus = 1;
		}

		if (channel->audiohandle != NULL && channel->targetpitch > 0.0f) {
			if (channel->currentpitch < 0.0f) {
				newpitch = channel->targetpitch;
			} else if (channel->pitchchangespeed > 0.0f) {
				newpitch = channel->currentpitch + (channel->targetpitch - channel->currentpitch) * g_Vars.lvupdate240 / channel->pitchchangespeed;
			} else {
				newpitch = channel->targetpitch;
			}
		} else {
			newpitch = -1.0f;
		}

		newpan = channel->targetpan;
		newvol = channel->currentvol;
		newfx = channel->targetfx;

		if (channel->currentvol == -1) {
			newvol = channel->targetvol;
		} else if (channel->volchangetimer60 >= 0) {
			osSyncPrintf("Propsnd : USING TIME 60\n");

			if (channel->volchangetimer60 > g_Vars.lvupdate60) {
				newvol = channel->currentvol + (channel->targetvol - channel->currentvol) * g_Vars.lvupdate60 / channel->volchangetimer60;
			}

			channel->volchangetimer60 -= g_Vars.lvupdate60;
		} else if (channel->volchangespeed && channel->currentvol != channel->targetvol) {
			f32 f12 = channel->targetvol - channel->currentvol;
#if VERSION >= VERSION_PAL_BETA
			f32 f14 = (1.0f / 6000.0f) * g_Vars.lvupdate60freal * channel->volchangespeed;
#else
			f32 f14 = (1.0f / 6000.0f) * g_Vars.lvupdate60 * channel->volchangespeed;
#endif

			if (ABS(f12) > 1.0f) {
				if (f14 > 1.0f) {
					f14 = 1.0f;
				}

				if (ABS(f14 * f12) > 1.0f) {
					newvol = channel->currentvol + (s32) (f14 * f12);
				}
			}
		} else {
			newvol = channel->targetvol;
		}

		if (lv_is_paused()
				|| (mp_is_paused() && (channel->flags2 & PSFLAG2_MPPAUSABLE))
				|| (mp_is_paused() && PLAYERCOUNT() == 1)) {
			channel->currentvol = -1;
			newvol = 0;
		}

		if (newvol != channel->currentvol) {
			channel->currentvol = newvol;
		} else {
			newvol = -1;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (channel->targetpan != channel->currentpan) {
			if (channel->flags & PSFLAG_FIRSTTICK) {
				channel->currentpan = channel->targetpan;
				newpan = channel->currentpan;
			} else {
				s32 diff = channel->targetpan - channel->currentpan;
				s32 lvupdate = g_Vars.lvupdate240 * 512 / 240;
				s32 dir = diff < 0 ? -1 : 1;
				s32 absdiff = ABS(diff);
				s32 amount = absdiff < lvupdate ? absdiff : lvupdate;

				channel->currentpan += amount * dir;
				newpan = channel->currentpan;
			}

			channel->flags |= PSFLAG_CHANGINGPAN;
		} else {
			newpan = -1;
		}
#else
		if (newpan != channel->currentpan) {
			channel->flags |= PSFLAG_CHANGINGPAN;
			channel->currentpan = newpan;
		} else {
			newpan = -1;
		}
#endif

		if (newfx != channel->currentfx) {
			channel->currentfx = newfx;
		} else {
			newfx = -1;
		}

		if (newpitch > 0.0f && ABS(newpitch - channel->currentpitch) > 0.01f) {
			channel->currentpitch = newpitch;
		} else {
			newpitch = -1.0f;
		}

		/**
		 * Channels which repeat (such as terminal hums) are stopped
		 * when out of range and resumed when range is re-entered.
		 */
		if (channel->flags & PSFLAG_REPEATING) {
			if (channel->currentvol > 0) {
				if (channel->flags & PSFLAG_OUTOFRANGE) {
					osSyncPrintf("PS_AUTO : Un-Pausing %d\n", channelnum);

					channel->flags &= ~PSFLAG_OUTOFRANGE;
					channel->flags |= PSFLAG_FIRSTTICK;
				}
			} else {
				if ((channel->flags & PSFLAG_OUTOFRANGE) == 0) {
					if (channel->audiohandle != NULL && sndp_get_state(channel->audiohandle) != AL_STOPPED) {
#if VERSION >= VERSION_NTSC_1_0
						sndp_stop_sound(channel->audiohandle);
#else
						osSyncPrintf("PS_AUTO : Pausing %d\n", channelnum);
						sndp_stop_sound(channel->audiohandle);
						channel->audiohandle = NULL;
#endif
					}

					channel->flags |= PSFLAG_OUTOFRANGE;
				}
#if VERSION >= VERSION_NTSC_1_0
				channel->flags &= ~PSFLAG_FIRSTTICK;
#endif
			}
		}

		/**
		 * Handle starting, restarting or adjusting the audio.
		 */
		if ((channel->flags & PSFLAG_OUTOFRANGE) == 0) {
			if (channel->flags & PSFLAG_FIRSTTICK) {
#if VERSION < VERSION_NTSC_1_0
				osSyncPrintf("SND : Propsound needs play : Id %d is flaged g\n", channelnum);
#endif


				if (channel->flags & PSFLAG_ISMP3) {
					snd_start_mp3(channel->requestedsoundnum, newvol, newpan, (channel->flags2 & PSFLAG2_RESPONDHELLO) ? 1 : 0);
				} else {
#if VERSION >= VERSION_NTSC_1_0
					if (channel->flags & PSFLAG_AMBIENT) {
						if (newvol) {
							snd_start_extra(&channel->audiohandle, channel->flags & PSFLAG_ISMP3, newvol, newpan,
									channel->requestedsoundnum, newpitch, channel->fxbus, newfx, true);
						}
					} else {
						if (newvol) {
							snd_start_extra(&channel->audiohandle, channel->flags & PSFLAG_ISMP3, newvol, newpan,
									channel->requestedsoundnum, newpitch, channel->fxbus, newfx, true);
						}
					}
#else
					snd_start_extra(&channel->audiohandle, channel->flags & PSFLAG_ISMP3, newvol, newpan,
							channel->requestedsoundnum, newpitch, channel->fxbus, newfx, true);
#endif
				}

				channel->flags &= ~PSFLAG_FIRSTTICK;
			} else {
				snd_adjust(&channel->audiohandle, channel->flags & PSFLAG_ISMP3, newvol, newpan,
						channel->requestedsoundnum, newpitch, channel->fxbus, newfx, channel->flags & PSFLAG_CHANGINGPAN);
			}
		}
	} else {
		/**
		 * The channel doesn't need to tick any more.
		 * If it's not marked, free it.
		 */
#if VERSION >= VERSION_NTSC_1_0
		if (channel->type != PSTYPE_MARKER) {
			if (channel->flags & PSFLAG_ISMP3) {
				if (!snd_is_playing_mp3()) {
					if (channel->flags & PSFLAG_FORPROP) {
						prop_decrement_sound_count(channel->prop);
					}

					if (channel->flags & PSFLAG_FORHUDMSG) {
						hudmsgs_hide_by_channel(channelnum);
					}
				}

				channel->flags = PSFLAG_FREE;
			} else if (channel->audiohandle == NULL) {
				if (channel->flags & PSFLAG_FORPROP) {
					prop_decrement_sound_count(channel->prop);
				}

				channel->flags = PSFLAG_FREE;
			}
		}
#else
		if (channel->flags & PSFLAG_ISMP3) {
			if (!snd_is_playing_mp3()) {
				if (channel->flags & PSFLAG_FORPROP) {
					prop_decrement_sound_count(channel->prop);
				}

				if (channel->flags & PSFLAG_FORHUDMSG) {
					hudmsgs_hide_by_channel(channelnum);
				}
			}
		} else if (channel->audiohandle == NULL) {
			if (channel->flags & PSFLAG_FORPROP) {
				prop_decrement_sound_count(channel->prop);
			}
		}

		channel->flags = PSFLAG_FREE;
#endif
	}

	if (g_PsPrintFlagged && (channel->flags2 & PSFLAG2_PRINTABLE)) {
		ps_print_channel(channel);
	}

#if VERSION >= VERSION_NTSC_1_0
	channel->flags &= ~PSFLAG_FIRSTTICK;
#endif

	channel->flags &= ~PSFLAG_CHANGINGPAN;
}

void ps_tick(void)
{
	static s32 peakcount = 0;
	s32 count = 0;
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		struct pschannel *channel = &g_PsChannels[i];

#if VERSION < VERSION_NTSC_1_0
		// Doing a proper check for the free flag here causes a regalloc mismatch.
		osSyncPrintf("AISND : Channel %d - %s", i, 1 ? "FREE" : "IN USE");
#endif

		if ((channel->flags & PSFLAG_FREE) == 0) {
			ps_tick_channel(i);
			count++;

#if VERSION >= VERSION_NTSC_1_0
			if (g_PsPrintAll) {
				ps_print_channel(&g_PsChannels[i]);
			}
#endif
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_PsPrintAll) {
		g_PsPrintAll = false;
	}
#endif

	if (count > peakcount) {
		peakcount = count;
	}

	osSyncPrintf("Propsnd : Using %d of %d (Peek = %d of %d)", count, CHANNELCOUNT(), peakcount, CHANNELCOUNT());
}

void ps_set_pitch(struct prop *prop, f32 targetpitch, s32 changespeed)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		if ((g_PsChannels[i].flags & PSFLAG_FREE) == 0 && g_PsChannels[i].prop == prop) {
			g_PsChannels[i].targetpitch = targetpitch;

			if (changespeed > 0) {
				g_PsChannels[i].pitchchangespeed = changespeed * 4;
			} else {
				g_PsChannels[i].pitchchangespeed = -1;
			}

#if VERSION >= VERSION_NTSC_1_0
			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
			ps_tick_channel(i);
			osSetThreadPri(0, prevpri);
#else
			ps_tick_channel(i);
#endif
		}
	}
}

void ps_set_volume(struct prop *prop, s32 volpercentage)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		if ((g_PsChannels[i].flags & PSFLAG_FREE) == 0 && prop == g_PsChannels[i].prop) {
#if VERSION >= VERSION_NTSC_1_0
			if (volpercentage > 100) {
				volpercentage = 100;
			}

			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

			g_PsChannels[i].maxvol = volpercentage * AL_VOL_FULL / 100;
			ps_tick_channel(i);

			osSetThreadPri(0, prevpri);
#else
			g_PsChannels[i].maxvol = volpercentage * AL_VOL_FULL / 100;
			ps_tick_channel(i);
#endif
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void ps_stop_one_shoot_channel(struct prop *prop)
{
	s32 lowestuuid = -1;
	s32 count = 0;
	s32 bestindex = -1;
	s32 i;

	for (i = 0; i < CHANNELCOUNT(); i++) {
		struct pschannel *channel = &g_PsChannels[i];

		if ((channel->flags & PSFLAG_FREE) == 0
				&& (channel->flags2 & PSFLAG2_STOPPED) == 0
				&& prop == channel->prop
				&& channel->type == PSTYPE_CHRSHOOT) {
			count++;

			if (channel->uuid < lowestuuid) {
				lowestuuid = channel->uuid;
				bestindex = i;
			}
		}
	}

	if (1);

	if (count >= 2 && bestindex != -1) {
		ps_stop_channel(bestindex);
	}
}
#endif

s16 ps_create(struct pschannel *channel, struct prop *prop, s16 soundnum, s16 padnum,
		s32 vol, u16 flags, u16 flags2, s32 type,
		struct coord *pos, f32 pitch, RoomNum *rooms, s32 room,
		f32 dist1, f32 dist2, f32 dist3)
{
	union soundnumhack spac;
	OSPri prevpri;
	u32 stack[2];
	s32 pan;

#if VERSION >= VERSION_NTSC_1_0
	struct pad pad;
	s32 i;
	s32 j;

	osSyncPrintf("AISOUND: aisoundnewtypeflags - Channel %d -> Playing sound number id=%d(%x)\n", channel, soundnum, soundnum);

	if (type == PSTYPE_CHRSHOOT) {
		ps_stop_one_shoot_channel(prop);
	}

	spac.packed = soundnum;

	if (channel == NULL) {
		if (type != PSTYPE_FOOTSTEP && g_SndNumPlaying > 12) {
			return -1;
		}

		for (i = CHANNEL_HEAP_FIRST; i < CHANNELCOUNT(); i++) {
			if (g_PsChannels[i].flags & PSFLAG_FREE) {
				channel = &g_PsChannels[i];
				channel->channelnum = i;
				break;
			}
		}
	}
#else
	s32 t4 = -1;
	struct pad pad;
	s32 i;
	s32 j;
	s32 count = 0;

	spac.packed = soundnum;

	if (channel == NULL) {
		for (i = CHANNEL_HEAP_FIRST; i < CHANNELCOUNT(); i++) {
			if (g_PsChannels[i].flags & PSFLAG_FREE) {
				channel = &g_PsChannels[i];
				if (i);

				if (type != PSTYPE_FOOTSTEP) {
					channel->channelnum = i;
				} else {
					t4 = i;
				}
				break;
			}

			if (type == PSTYPE_FOOTSTEP) {
				count++;
			}
		}
	}

	if (type == PSTYPE_FOOTSTEP) {
		if (count >= 12) {
			return -1;
		}

		if (t4 != -1) {
			channel = &g_PsChannels[t4];
			channel->channelnum = t4;
		} else {
			return -1;
		}
	}
#endif

	if (padnum >= 0) {
		pad_unpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);
		pos = &pad.pos;
		room = pad.room;
		prop = NULL;
	}

	if (channel == NULL) {
		return -1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_AudioPrevUuid < 0xffffffff) {
		g_AudioPrevUuid++;
	} else {
		g_AudioPrevUuid = 0;
	}
#endif

	channel->flags = flags;
	channel->flags2 = flags2;
	channel->audiohandle = NULL;
	channel->currentvol = -1;
	channel->currentpan = -1;
	channel->currentfx = -1;
	channel->targetvol = (vol != -1) ? vol : -1;
	channel->targetpan = AL_PAN_CENTER;
	channel->targetfx = 0;
	channel->maxvol = AL_VOL_FULL;
	channel->fxbus = 1;
	channel->targetpitch = (pitch > 0) ? pitch : -1;
	channel->currentpitch = channel->targetpitch;
	channel->pitchchangespeed = -1;
	channel->volchangetimer60 = -1;
	channel->padnum = padnum;
	channel->prop = prop;
	channel->type = type;
	channel->requestedvol = vol;
	channel->unk40 = -1;
	channel->dist1 = (dist1 > 0) ? dist1 : 400;
	channel->dist2 = (dist2 > 0) ? dist2 : 2500;
	channel->dist3 = (dist3 > 0) ? dist3 : 3000;
	channel->volchangespeed = 0;
#if VERSION >= VERSION_NTSC_1_0
	channel->uuid = g_AudioPrevUuid;
#endif

	if (spac.hasconfig) {
		s32 id = spac.confignum;
		s32 confignum = g_AudioRussMappings[id].audioconfig_index;
		s32 newid = g_AudioRussMappings[id].soundnum;

		channel->dist1 = g_AudioConfigs[confignum].dist1;
		channel->dist2 = g_AudioConfigs[confignum].dist2;
		channel->dist3 = g_AudioConfigs[confignum].dist3;
		channel->volchangespeed = g_AudioConfigs[confignum].volchangespeed;

		if (g_AudioConfigs[confignum].volpercentage != 100) {
			channel->maxvol = g_AudioConfigs[confignum].volpercentage * (AL_VOL_FULL / 100);
		}

		if (g_AudioConfigs[confignum].pitch > 0) {
			channel->targetpitch = g_AudioConfigs[confignum].pitch;
		}

		pan = g_AudioConfigs[confignum].pan;

		if (pan != -1) {
			channel->targetpan = pan;
			channel->flags |= PSFLAG_HASCONFIGPAN;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_SPECIALPAN) {
			channel->flags |= PSFLAG_SPECIALPAN;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_RESPONDHELLO) {
			channel->flags2 |= PSFLAG2_RESPONDHELLO;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_IGNOREROOMS) {
			if (channel->targetvol == -1) {
				channel->targetvol = channel->maxvol;
			}

			channel->flags |= PSFLAG_IGNOREROOMS;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_OFFENSIVE) {
			channel->flags2 |= PSFLAG2_OFFENSIVE;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_AMBIENT) {
			channel->flags2 |= PSFLAG2_AMBIENT;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_40) {
			channel->flags2 |= PSFLAG2_0040;
		}
#endif

		channel->flags |= PSFLAG_HASCONFIG;

		spac.packed = newid;
		spac.hasconfig = false;
		soundnum = spac.packed;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (channel->volchangespeed) {
		channel->flags |= PSFLAG_REPEATING;
	}
#endif

	channel->requestedsoundnum = spac.packed;
	channel->resolvedsoundnum = spac.id;

#if VERSION >= VERSION_NTSC_1_0
	if (snd_is_filtered(channel->resolvedsoundnum)) {
		channel->flags2 |= PSFLAG2_OFFENSIVE;
	}
#endif

	if (spac.unk02) {
		channel->flags2 |= PSFLAG2_AMBIENT;
	}

#if VERSION < VERSION_NTSC_1_0
	if (channel->flags2 & PSFLAG2_AMBIENT) {
		if (channel->targetvol == -1) {
			channel->targetvol = channel->maxvol;
		}
	}
#endif

	if (pos) {
		channel->pos.x = pos->x;
		channel->pos.y = pos->y;
		channel->pos.z = pos->z;
		channel->posptr = &channel->pos;
	} else {
		channel->posptr = NULL;
	}

	if (rooms) {
		// @dangerous: Array overflow will occur if rooms has more than 8 elements
		for (j = 0; rooms[j] != -1; j++) {
			channel->rooms[j] = rooms[j];
		}

		channel->rooms[j] = -1;
	} else if (room != -1) {
		channel->rooms[0] = room;
		channel->rooms[1] = -1;
	} else {
		channel->rooms[0] = -1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!pos && !channel->prop) {
		channel->flags2 |= PSFLAG2_AMBIENT;
	}

	if (channel->flags2 & PSFLAG2_AMBIENT) {
		if (channel->targetvol == -1) {
			channel->targetvol = channel->maxvol;
		}
	}
#endif

	channel->flags |= PSFLAG_FIRSTTICK;

	if (snd_is_mp3(soundnum)) {
		channel->flags |= PSFLAG_ISMP3;

#if VERSION >= VERSION_NTSC_1_0
		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		ps_tick_channel(channel->channelnum);
		osSetThreadPri(0, prevpri);
#else
		ps_tick_channel(channel->channelnum);
#endif
	} else {
		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		ps_tick_channel(channel->channelnum);
		osSetThreadPri(0, prevpri);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (channel->flags & PSFLAG_AMBIENT) {
		channel->flags &= ~PSFLAG_AMBIENT;
		channel->flags2 |= PSFLAG2_AMBIENT;
	}

	channel->flags &= ~PSFLAG_FIRSTTICK;
#else
	if (channel->flags & PSFLAG_AMBIENT) {
		channel->flags = PSFLAG_FREE;
	} else {
		channel->flags &= ~PSFLAG_FIRSTTICK;
	}
#endif

	return channel->channelnum;
}

s32 ps_create_from_ai(s32 channelnum, s16 soundnum, s32 vol, struct prop *prop, s16 type, u16 flags)
{
	s32 retchannelnum = -1;

#if VERSION < VERSION_NTSC_1_0
	osSyncPrintf("SND : Start -> Prop=%x, Id=%d, Vol=%d, Flags=%d, Type=%d\n", prop, soundnum, vol, flags, type);
#endif

	if (type == PSTYPE_MARKER) {
		if (CHANNEL_IS_AI(channelnum)) {
#if VERSION >= VERSION_NTSC_1_0
			if (g_PsChannels[channelnum].flags & PSFLAG_FREE) {
				osSyncPrintf("AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n", channelnum, soundnum, soundnum);
				g_PsChannels[channelnum].requestedsoundnum = soundnum;
				g_PsChannels[channelnum].type = PSTYPE_MARKER;
				g_PsChannels[channelnum].flags &= ~PSFLAG_FREE;
				retchannelnum = channelnum;
			} else {
				osSyncPrintf("AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n", channelnum, soundnum, soundnum);
				g_PsChannels[channelnum].requestedsoundnum = soundnum;
				g_PsChannels[channelnum].type = PSTYPE_MARKER;
				g_PsChannels[channelnum].flags &= ~PSFLAG_FREE;
				retchannelnum = channelnum;
			}
#else
			osSyncPrintf("AISOUND: Channel %d -> Playing sound number id=%d(%x))\n", channelnum, soundnum, soundnum);
			g_PsChannels[channelnum].requestedsoundnum = soundnum;
			g_PsChannels[channelnum].type = PSTYPE_MARKER;
			g_PsChannels[channelnum].flags &= ~PSFLAG_FREE;
			retchannelnum = channelnum;
#endif
		} else {
			// empty
		}
	} else {
		if (channelnum == CHANNEL_CUTSCENE) {
			/**
			 * The caller is indicating that this is a cutscene sound,
			 * and doesn't care which channel is used.
			 * Let ps_create choose the real channel number from the heap area.
			 *
			 * Flag PSFLAG_CUTSCENE is set so propsnd knows the channel is being
			 * used by a cutscene, and can be stopped once the cutscene ends.
			 */
			osSyncPrintf("AISOUND: CUTSCENE -> Playing sound number id=%d(%x))\n", soundnum, soundnum);

			retchannelnum = ps_create(NULL, prop, soundnum, -1,
					(vol ? 0 : -1), flags | PSFLAG_CUTSCENE, 0, type, 0, -1, 0, -1, -1, -1, -1);
		}
#if VERSION >= VERSION_NTSC_1_0
		else if (channelnum < 0 || channelnum >= CHANNEL_HEAP_FIRST || channelnum == CHANNEL_DONTCARE) {
			/**
			 * Requested channel is invalid, in the heap area, or caller doesn't
			 * care what channel is used.
			 * Allocate a channel automatically from the heap and return it.
			 */
			osSyncPrintf("AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d, Zero=%d\n",
					channelnum, soundnum, soundnum, prop, flags, type, 0);
			osSyncPrintf("AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d\n",
					channelnum, soundnum, soundnum, prop, flags, type);

			retchannelnum = ps_create(NULL, prop, soundnum, -1,
				(vol ? 0 : -1), flags, 0, type, 0, -1, 0, -1, -1, -1, -1);
		}
#else
		else if (channelnum == CHANNEL_DONTCARE) {
			osSyncPrintf("AISOUND: DONTCARE -> Playing sound number id=%d(%x))\n", soundnum, soundnum);
			retchannelnum = ps_create(NULL, prop, soundnum, -1, (vol ? 0 : -1), flags, 0, type, 0, -1, 0, -1, -1, -1, -1);
		} else if (channelnum < 0 || channelnum >= CHANNEL_HEAP_FIRST) {
			osSyncPrintf("AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x\n", channelnum, soundnum, soundnum, prop);
			retchannelnum = ps_create(NULL, prop, soundnum, -1, (vol ? 0 : -1), flags, 0, type, 0, -1, 0, -1, -1, -1, -1);
		}
#endif
		else {
			/**
			 * An AI script has asked for a specific channel in range 0-7.
			 * Replace the channel if necessary.
			 */
			if ((g_PsChannels[channelnum].flags & PSFLAG_FREE) == 0) {
#if VERSION < VERSION_NTSC_1_0
				osSyncPrintf("SERIOUS: Existing ai sound number %d (Sound id=%d(%x)) : KILLING\n",
						channelnum, g_PsChannels[channelnum].requestedsoundnum, g_PsChannels[channelnum].requestedsoundnum);
#endif

				ps_stop_channel(channelnum);
			}

			g_PsChannels[channelnum].channelnum = channelnum;

			ps_create(&g_PsChannels[channelnum], prop, soundnum, -1,
				(vol ? 0 : -1), flags, 0, type, 0, -1, 0, -1, -1, -1, -1);

			retchannelnum = channelnum;
		}
	}

	return retchannelnum;
}

void ps_mute_channel(s32 channelnum)
{
	if (channelnum == CHANNEL_CUTSCENE) {
		s32 i;

		osSyncPrintf("AISOUND: CUTSCENE -> Stopping all cutscene sounds\n");

		for (i = CHANNEL_HEAP_FIRST; i < CHANNELCOUNT(); i++) {
			if ((g_PsChannels[i].flags & PSFLAG_FREE) == 0
					&& (g_PsChannels[i].flags & PSFLAG_CUTSCENE)) {
				ps_stop_channel(i);
			}
		}
	} else if (CHANNEL_IS_AI(channelnum)) {
		osSyncPrintf("AISOUND: Stop sound channel %d\n", channelnum);
		ps_stop_channel(channelnum);
	}
}

bool ps_is_channel_free(s32 channelnum)
{
	if (CHANNEL_IS_AI(channelnum)) {
		return (g_PsChannels[channelnum].flags & PSFLAG_FREE) ? true : false;
	}

	if (channelnum == CHANNEL_CUTSCENE) {
		s32 i;

		for (i = CHANNEL_HEAP_FIRST; i < CHANNELCOUNT(); i++) {
			if (g_PsChannels[i].flags & PSFLAG_CUTSCENE) {
				return false;
			}
		}
	}

	return true;
}

void ps_modify(s32 channelnum, s32 volume, s16 padnum, struct prop *prop, s32 volchangetimer60, s32 dist2, s32 dist3, u16 flags)
{
	struct pschannel *channel = &g_PsChannels[channelnum];
	bool hastimer = (volchangetimer60 >= 6) ? true : false;
	bool repeating = (flags & PSFLAG_REPEATING) ? true : false;

	osSyncPrintf("AISOUND: Channel %d -> Setting params : Vol=%d, Pad=%d, Prop=%x, Time=%d, Far=%d, Silence=%d, Flags=%u\n",
			channelnum, volume, padnum, prop, volchangetimer60, dist2, dist3, flags);

	if (CHANNEL_IS_AI(channelnum)) {
		if (channel->type == PSTYPE_MARKER) {
			osSyncPrintf("AISOUND : This channel has a marker -> Shall start and use ID = %d(%x)\n", channelnum, &g_PsChannels[channelnum]);

			g_PsChannels[channelnum].channelnum = (u16)channelnum;

			ps_create(&g_PsChannels[channelnum], prop, channel->requestedsoundnum, -1,
					-1, flags, 0, PSTYPE_NONE, 0, -1, 0, -1, 400, dist2, dist3);
		} else {
			if ((channel->flags & PSFLAG_OUTOFRANGE) == 0 && volume >= 0) {
				channel->targetvol = volume;
			}

			if (hastimer) {
				channel->volchangetimer60 = TICKS(volchangetimer60);
			}

			if (padnum != -1) {
				channel->padnum = padnum;
			}

			if (prop) {
				channel->prop = prop;
			}

			if (repeating) {
				channel->flags |= PSFLAG_REPEATING;
			}

			if ((channel->flags & PSFLAG_HASCONFIG) == 0) {
				channel->dist1 = 400;
				channel->dist2 = dist2;
				channel->dist3 = dist3;
				channel->volchangespeed = 0;
			}

			if (!hastimer || channel->volchangetimer60 == 0) {
#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
				ps_tick_channel(channelnum);
				osSetThreadPri(0, prevpri);
#else
				ps_tick_channel(channelnum);
#endif
			}
		}
	}
}

s32 ps_calculate_vol(struct coord *pos, f32 dist1, f32 dist2, f32 dist3, RoomNum *rooms, s16 soundnum, s32 arg6, f32 *playerdistptr)
{
	union soundnumhack sp6c;
	union soundnumhack sp68;
	f32 playerdist;
	RoomNum roomnum;
	s32 s0;
	s32 i;

	playerdist = dist3 + 10.0f;

	if (rooms != NULL) {
		roomnum = *rooms;
	} else {
		roomnum = -1;
	}

	sp68.packed = soundnum;
	sp6c.packed = soundnum;

#if VERSION < VERSION_NTSC_1_0
	if (g_PsPrintAll) {
		playerdist = 9999999;
	}
#endif

	if (sp68.hasconfig) {
		s32 confignum = sp68.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		sp6c.packed = g_AudioRussMappings[confignum].soundnum;

		dist1 = g_AudioConfigs[index].dist1;
		dist2 = g_AudioConfigs[index].dist2;
		dist3 = g_AudioConfigs[index].dist3;

		if (dist3 < playerdist) {
			playerdist = dist3;
		}
	}

	if (var8006ae34 && var8006ae2c == sp6c.id) {
		s0 = 1;
	} else {
		s0 = 0;
	}

	// Figure out which player is closest and store their distance in playerdist
	for (i = 0; i < PLAYERCOUNT(); i++) {
		struct player *player = g_Vars.players[i];
		s32 camroom;

		if (sp6c.unk02 == 0) {
			camroom = player->cam_room;
		} else {
			camroom = -1;
		}

		lights_find_distance_through_rooms_with_limit(camroom, &player->cam_pos, roomnum, pos, 0, &playerdist, s0);
	}

	if (playerdistptr != NULL) {
		*playerdistptr = playerdist;
	}

	return ps_calculate_volume_from_distance(playerdist, dist1, dist2, dist3, arg6);
}

s32 ps_calculate_pan3(s32 degrees, f32 arg1, struct pschannel *channel)
{
	s32 result;

	while (degrees >= 180) {
		degrees -= 360;
	}

	while (degrees < -180) {
		degrees += 360;
	}

	switch (g_SoundMode) {
	default:
		{
			s32 absdegrees = degrees > 0 ? degrees : -degrees;
			s32 dir;
			s32 v1;

			if (absdegrees > 90) {
				absdegrees = 180 - absdegrees;
			}

			v1 = absdegrees && absdegrees;
			dir = (degrees > 0) ? (1) : (-1);

			if (v1);

			degrees = dir * absdegrees;
		}
		break;
	case SOUNDMODE_SURROUND:
		if (degrees > -45 && degrees < 45) {
			degrees *= 2;
		} else {
			s32 dir = degrees > 0 ? 1 : -1;
			s32 v1 = dir && dir;
			s32 absdegrees = degrees > 0 ? degrees : -degrees;
			s32 t4 = (180 - absdegrees) * 0.6666667f;

			if (v1);

			degrees = (180 - t4) * dir;
		}
		break;
	}

	/**
	 * At this point, in sound modes other than surround, degrees is:
	 *
	 *   0 if sound is in front
	 *  90 if sound is on the right
	 *   0 if sound is behind
	 * -90 if sound is to the left
	 *
	 * ...and scaled between those for angles between, so effectively a pan value.
	 *
	 * For surround mode, degrees is:
	 *
	 *        0 if sound is in front
	 *       90 if sound is 45 degrees to the right
	 * 180/-180 if sound is behind
	 *      -90 if sound is 45 degrees to the left
	 *
	 * So an actual degrees value but with weighting towards the front.
	 */

	if (degrees >= -90 && degrees <= 90) {
		result = AL_PAN_CENTER + degrees * 0.7f;
	} else {
		s32 v0;
		s32 dir = degrees > 0 ? 1 : -1;
		s32 absdegrees = ABS(degrees);

		result = 128 + (s32) (AL_PAN_CENTER + (180 - absdegrees) * dir * 0.7f);
	}

	if (channel != NULL) {
		channel->degrees = degrees;
		channel->unk16 = 100.0f * arg1;
	}

	return result;
}

s32 ps_calculate_pan2(struct coord *pos, s32 arg1, f32 arg2, struct pschannel *channel)
{
	s32 result = AL_PAN_CENTER;
	u32 stack[4];
	s32 degrees;
	f32 f2;

	if (PLAYERCOUNT() < 2) {
		struct coord *campos = &g_Vars.currentplayer->cam_pos;
		f32 sp3c;
		f32 sp38;

		f2 = -(atan2f(pos->x - campos->x, pos->z - campos->z) * 180.0f / DTOR(180) + g_Vars.currentplayer->vv_theta);

		if (arg2 >= 0.0f) {
			sp3c = sinf(0.017453292f * f2);
			sp38 = cosf(0.017453292f * f2);

			sp3c *= arg2;

			f2 = atan2f(ABSF(sp3c), ABSF(sp38));

			if (sp3c >= 0.0f && sp38 >= 0.0f) {
				// empty
			} else if (sp3c >= 0.0f) {
				f2 = DTOR(180) - f2;
			} else if (sp38 >= 0.0f) {
				f2 = -f2;
			} else {
				f2 = -(DTOR(180) - f2);
			}

			degrees = RTOD2(f2);
		} else {
			degrees = f2;
		}

		if (channel != NULL) {
			channel->degrees = degrees;
			channel->unk16 = 100.0f * arg2;
		}

		result = ps_calculate_pan3(degrees, arg2, channel);
	}

	return result;
}

s32 ps_calculate_pan(struct coord *pos, f32 dist1, f32 dist2, f32 dist3, f32 playerdist, bool specialpan, struct pschannel *channel)
{
	s32 result = AL_PAN_CENTER;

	if (pos != NULL && playerdist > 0) {
		if (dist1 < 0) {
			dist1 = 400;
		}

		if (dist2 < 0) {
			dist2 = 2500;
		}

		if (dist3 < 0) {
			dist3 = 3000;
		}

		if (playerdist < dist3) {
			if (dist1 > 5501) {
				dist1 = 5501;
			}

			if (dist2 > 5801) {
				dist2 = 5801;
			}

			if (specialpan) {
				if (playerdist < dist1) {
					// empty
				} else if (playerdist < dist2) {
					f32 frac = (playerdist - dist1) / (dist2 - dist1);

					if (frac < 0) {
						frac = 0;
					}

					if (frac > 1) {
						frac = 1;
					}

					result = ps_calculate_pan2(pos, 0, frac, channel);
				} else {
					result = ps_calculate_pan2(pos, 0, -1, NULL);
				}
			} else {
				result = ps_calculate_pan2(pos, 0, -1, channel);
			}
		}
	}

	return result;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * If the given soundnum were to play at the given world position, calculate the
 * final volume and pan and write them to the vol and pan pointers.
 */
void ps_get_theoretical_vol_pan(struct coord *pos, RoomNum *rooms, s16 soundnum, s32 *vol, s32 *pan)
{
	f32 dist1;
	f32 dist2;
	f32 dist3;
	struct audiorussmapping *russ;
	struct audioconfig *config;
	union soundnumhack sp48;
	union soundnumhack sp44;
	f32 distance;
	bool specialpan;
	s32 index;
	s32 confignum;
	f32 *distanceptr = &distance;

	dist1 = 400;
	dist2 = 2500;
	dist3 = 3000;

	sp44.packed = soundnum;
	distance = 9999999;
	specialpan = false;

	if (sp44.hasconfig) {
		confignum = sp44.confignum;
		russ = &g_AudioRussMappings[confignum];
		index = russ->audioconfig_index;
		config = &g_AudioConfigs[index];

		dist1 = config->dist1;
		dist2 = config->dist2;
		dist3 = config->dist3;

		sp48.packed = russ->soundnum;

		if (config->flags & AUDIOCONFIGFLAG_SPECIALPAN) {
			specialpan = true;
		}

		if (dist3 < *distanceptr) {
			*distanceptr = dist3;
		}

		sp48.hasconfig = false;
		soundnum = sp48.packed;
	}

	*vol = ps_calculate_vol(pos, dist1, dist2, dist3, rooms, soundnum, AL_VOL_FULL, distanceptr);
	*pan = ps_calculate_pan(pos, dist1, dist2, dist3, *distanceptr, specialpan, 0);
}
#endif

void ps_apply_vol_pan(struct sndstate *handle, struct coord *pos, f32 dist1, f32 dist2, f32 dist3, RoomNum *rooms, s16 soundnum, s32 arg7, f32 *distanceptr)
{
	union soundnumhack sp5c;
	union soundnumhack sp58;
	f32 distance;
	bool specialpan;
	s32 vol;
	s32 pan;

	specialpan = false;
	distance = 9999999;
	sp58.packed = soundnum;

	if (distanceptr == NULL) {
		distanceptr = &distance;
	}

	if (sp58.hasconfig) {
		s32 confignum = sp58.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		dist1 = g_AudioConfigs[index].dist1;
		dist2 = g_AudioConfigs[index].dist2;
		dist3 = g_AudioConfigs[index].dist3;

		sp5c.packed = g_AudioRussMappings[confignum].soundnum;

		if (g_AudioConfigs[index].flags & AUDIOCONFIGFLAG_SPECIALPAN) {
			specialpan = true;
		}

		if (dist3 < *distanceptr) {
			*distanceptr = dist3;
		}

		sp5c.hasconfig = false;
		soundnum = sp5c.packed;
	}

	vol = ps_calculate_vol(pos, dist1, dist2, dist3, rooms, soundnum, arg7, distanceptr);
	pan = ps_calculate_pan(pos, dist1, dist2, dist3, *distanceptr, specialpan, 0);

	snd_adjust(&handle, snd_is_mp3(soundnum), vol, pan, soundnum, 1.0f, 1, -1, 1);
}

s32 ps_get_random_spark_sound(void)
{
	s32 index = random() % 6;

	s16 sounds[] = {
		SFXMAP_80B0,
		SFXMAP_80B1,
		SFXMAP_80B2,
		SFXMAP_80B3,
		SFXMAP_80B4,
		SFXMAP_80B5,
	};

	return sounds[index];
}

Gfx *ps_render1(Gfx *gdl, s32 arg1)
{
	return gdl;
}

Gfx *ps_render2(Gfx *gdl, s32 arg1)
{
	return gdl;
}

void ps_debug(void)
{
	// empty
}

/**
 * Get the duration for an MP3 file by channel number.
 *
 * All MP3 files are 24 kilobits per second
 * so this is just math based on the filesize.
 */
s32 ps_get_duration60(s32 channelnum)
{
	struct pschannel *channel = &g_PsChannels[channelnum];

	if (channelnum >= 0 && channelnum < CHANNELCOUNT()
			&& (channel->flags & PSFLAG_FREE) == 0
			&& (channel->flags & PSFLAG_ISMP3)) {
		union soundnumhack soundnum;
		soundnum.packed = channel->requestedsoundnum;

		return file_get_rom_size(soundnum.id) * 60 / (1024 * 24 / 8);
	}

	return -1;
}
