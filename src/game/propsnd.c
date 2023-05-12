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

struct audiochannel *g_AudioChannels = NULL;

u32 g_AudioPrevUuid = 0x00000000;

static void func0f092a98(s32 channelnum);
static s32 propsnd0f0946b0(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, s16 *rooms, s16 soundnum, s32 arg6, f32 *arg7);
static s32 propsnd0f094d78(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, f32 arg4, bool arg5, struct audiochannel *channel);

bool func0f092610(struct prop *prop, s32 arg1)
{
	s32 i;

	for (i = 0; i < 40; i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
				&& prop == g_AudioChannels[i].prop
				&& (arg1 == g_AudioChannels[i].unk28 || arg1 == 1)) {
			return true;
		}
	}

	return false;
}

void func0f0926bc(struct prop *prop, s32 arg1, u16 arg2)
{
	s32 i;

	for (i = 0; i < 40; i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0 && channel->prop == prop) {
			if (!channel->flags || !arg2 || (arg2 & channel->flags)) {
				if (channel->unk28 == arg1 || arg1 == 1) {
					func0f092a98(i);
				}
			}
		}
	}
}

static s32 func0f0927d4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
	s32 result = 0;

	if (arg0 < arg3) {
		if (arg1 > 5501) {
			arg1 = 5501;
		}

		if (arg2 > 5801) {
			arg2 = 5801;
		}

		if (arg3 > 6000) {
			arg3 = 6000;
		}

		if (arg1 > arg0) {
			result = arg4;
		} else {
			if (arg2 > arg0) {
				result = arg4 - (s32)(sqrtf((arg0 - arg1) / (arg2 - arg1)) * (arg4 - 1000.0f));
			} else {
				result = (((arg3 - arg0) * 1000.0f) / (arg3 - arg2));
			}
		}
	}

	if (result > 0x7fff) {
		result = 0x7fff;
	}

	if (result < 40) {
		result = 0;
	}

	return result;
}

void propsnd0f09294c(struct prop *prop, s16 soundnum, s32 arg2)
{
	s32 i;

	if (propsnd0f0946b0(&prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0)) {
		// Return if this prop is already playing a sound
		for (i = 8; i < 40; i++) {
			if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
					&& g_AudioChannels[i].prop == prop
					&& g_AudioChannels[i].unk28 == arg2) {
				return;
			}
		}

		propsnd0f0939f8(NULL, prop, soundnum, -1, -1, 2, 0, arg2, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
	}
}

static void func0f092a98(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

	channel->flags2 |= 0x80;

	if (channel->flags & AUDIOCHANNELFLAG_FORHUDMSG) {
		hudmsgsHideByChannel(channelnum);
	}

	if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
		propDecrementSoundCount(channel->prop);
	}

	if ((channel->flags & AUDIOCHANNELFLAG_ISMP3)) {
		snd0000fbc4(channel->soundnum26);
	} else if (channel->audiohandle && sndGetState(channel->audiohandle) != AL_STOPPED) {
		audioStop(channel->audiohandle);
	}
}

s32 propsndGetSubtitleOpacity(s32 channelnum)
{
	if (channelnum == -1) {
		return 1;
	}

	if ((g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) == 0) {
		s32 value = g_AudioChannels[channelnum].unk06;

		if (value == -1 || value > 200) {
			s32 tmp = g_AudioChannels[channelnum].unk06 - 200;
			s32 opacity = tmp * 255 / 15800;

			if (opacity > 255) {
				opacity = 255;
			}

			return opacity;
		}
	}

	return 0;
}

static void propsndTickChannel(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

	if ((channel->flags2 & AUDIOCHANNELFLAG2_0080) == 0
			&& channel->unk28 != 11
			&& ((channel->audiohandle != NULL && sndGetState(channel->audiohandle) != AL_STOPPED)
				|| (channel->flags & AUDIOCHANNELFLAG_0002)
				|| (channel->flags & AUDIOCHANNELFLAG_1000)
				|| ((channel->flags & AUDIOCHANNELFLAG_ISMP3) && g_SndCurMp3.playing))) {
		struct coord *pos = NULL; // 50
		s16 *rooms = NULL; // 4c
		s32 sp48;
		s32 sp44;
		s32 sp40;
		f32 sp3c;

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

		if (g_Vars.langfilteron && (channel->flags2 & AUDIOCHANNELFLAG2_OFFENSIVE)) {
			channel->unk04 = 0;
		} else if (channel->flags2 & AUDIOCHANNELFLAG2_0010) {
			if ((channel->flags & AUDIOCHANNELFLAG_1000) == 0) {
				return;
			}

			channel->unk04 = channel->unk10;
		} else {
			if (pos && rooms) {
				s16 *tmprooms;

				if (channel->flags & AUDIOCHANNELFLAG_8000) {
					tmprooms = NULL;
				} else {
					tmprooms = rooms;
				}

				channel->unk04 = propsnd0f0946b0(pos, channel->unk34, channel->unk38, channel->unk3c,
						tmprooms, channel->soundnum26, channel->unk10, &channel->unk4c);
			}

			if ((channel->flags & AUDIOCHANNELFLAG_0020) == 0) {
				channel->unk0a = propsnd0f094d78(pos, channel->unk34, channel->unk38, channel->unk3c,
						channel->unk4c, channel->flags & AUDIOCHANNELFLAG_0800, channel);
			}
		}

		if (rooms != NULL && rooms[0] != -1) {
			channel->unk0c = 0;
			channel->unk1a = 1;
		} else {
			channel->unk0c = 0;
			channel->unk1a = 1;
		}

		if (channel->audiohandle != NULL && channel->unk44 > 0.0f) {
			if (channel->unk48 < 0.0f) {
				sp3c = channel->unk44;
			} else if (channel->unk20 > 0.0f) {
				sp3c = channel->unk48 + (channel->unk44 - channel->unk48) * g_Vars.lvupdate240 / channel->unk20;
			} else {
				sp3c = channel->unk44;
			}
		} else {
			sp3c = -1.0f;
		}

		sp44 = channel->unk0a;
		sp48 = channel->unk06;
		sp40 = channel->unk0c;

		if (channel->unk06 == -1) {
			sp48 = channel->unk04;
		} else if (channel->unk1c >= 0) {
			if (channel->unk1c > g_Vars.lvupdate60) {
				sp48 = channel->unk06 + (channel->unk04 - channel->unk06) * g_Vars.lvupdate60 / channel->unk1c;
			}

			channel->unk1c -= g_Vars.lvupdate60;
		} else if (channel->unk18 && channel->unk06 != channel->unk04) {
			f32 f12 = channel->unk04 - channel->unk06;
			f32 f14 = g_Vars.lvupdate60 * (1.0f / 6000.0f) * channel->unk18;

			if (absf(f12) > 1.0f) {
				if (f14 > 1.0f) {
					f14 = 1.0f;
				}

				if (absf(f14 * f12) > 1.0f) {
					sp48 = channel->unk06 + (s32) (f14 * f12);
				}
			}
		} else {
			sp48 = channel->unk04;
		}

		if (g_LvIsPaused
				|| (mpIsPaused() && (channel->flags2 & AUDIOCHANNELFLAG2_0002))
				|| (mpIsPaused() && PLAYERCOUNT() == 1)) {
			channel->unk06 = -1;
			sp48 = 0;
		}

		if (sp48 != channel->unk06) {
			channel->unk06 = sp48;
		} else {
			sp48 = -1;
		}

		if (channel->unk0a != channel->unk08) {
			if (channel->flags & AUDIOCHANNELFLAG_1000) {
				channel->unk08 = channel->unk0a;
				sp44 = channel->unk08;
			} else {
				s32 diff = channel->unk0a - channel->unk08;
				s32 lvupdate = g_Vars.lvupdate240 * 512 / 240;
				s32 dir = diff < 0 ? -1 : 1;
				s32 absdiff = ABS(diff);
				s32 amount = absdiff < lvupdate ? absdiff : lvupdate;

				channel->unk08 += amount * dir;
				sp44 = channel->unk08;
			}

			channel->flags |= AUDIOCHANNELFLAG_4000;
		} else {
			sp44 = -1;
		}

		if (sp40 != channel->unk0e) {
			channel->unk0e = sp40;
		} else {
			sp40 = -1;
		}

		if (sp3c > 0.0f && absf(sp3c - channel->unk48) > 0.01f) {
			channel->unk48 = sp3c;
		} else {
			sp3c = -1.0f;
		}

		if (channel->flags & AUDIOCHANNELFLAG_0002) {
			if (channel->unk06 > 0) {
				if (channel->flags & AUDIOCHANNELFLAG_2000) {
					channel->flags &= ~AUDIOCHANNELFLAG_2000;
					channel->flags |= AUDIOCHANNELFLAG_1000;
				}
			} else {
				if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0) {
					if (channel->audiohandle != NULL && sndGetState(channel->audiohandle) != AL_STOPPED) {
						audioStop(channel->audiohandle);
					}

					channel->flags |= AUDIOCHANNELFLAG_2000;
				}

				channel->flags &= ~AUDIOCHANNELFLAG_1000;
			}
		}

		if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0) {
			if (channel->flags & AUDIOCHANNELFLAG_1000) {
				if (channel->flags & AUDIOCHANNELFLAG_ISMP3) {
					sndStartMp3(channel->soundnum26, sp48, sp44, (channel->flags2 & AUDIOCHANNELFLAG2_0001) ? 1 : 0);
				} else {
					if (channel->flags & AUDIOCHANNELFLAG_0400) {
						if (sp48) {
							snd00010718(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
									channel->soundnum26, sp3c, channel->unk1a, sp40, 1);
						}
					} else {
						if (sp48) {
							snd00010718(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
									channel->soundnum26, sp3c, channel->unk1a, sp40, 1);
						}
					}
				}

				channel->flags &= ~AUDIOCHANNELFLAG_1000;
			} else {
				sndAdjust(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
						channel->soundnum26, sp3c, channel->unk1a, sp40, channel->flags & AUDIOCHANNELFLAG_4000);
			}
		}
	} else {
		if (channel->unk28 != 11) {
			if (channel->flags & AUDIOCHANNELFLAG_ISMP3) {
				if (!g_SndCurMp3.playing) {
					if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
						propDecrementSoundCount(channel->prop);
					}

					if (channel->flags & AUDIOCHANNELFLAG_FORHUDMSG) {
						hudmsgsHideByChannel(channelnum);
					}
				}

				channel->flags = AUDIOCHANNELFLAG_IDLE;
			} else if (channel->audiohandle == NULL) {
				if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
					propDecrementSoundCount(channel->prop);
				}

				channel->flags = AUDIOCHANNELFLAG_IDLE;
			}
		}
	}

	channel->flags &= ~AUDIOCHANNELFLAG_1000;
	channel->flags &= ~AUDIOCHANNELFLAG_4000;
}

void propsndTick(void)
{
	static s32 g_PropsndMaxActiveChannels = 0;
	s32 count = 0;
	s32 i;

	for (i = 0; i < 40; i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0) {
			propsndTickChannel(i);
			count++;
		}
	}

	if (g_PropsndMaxActiveChannels < count) {
		g_PropsndMaxActiveChannels = count;
	}
}

void func0f093630(struct prop *prop, f32 arg1, s32 arg2)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < 40; i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0 && g_AudioChannels[i].prop == prop) {
			g_AudioChannels[i].unk44 = arg1;

			if (arg2 > 0) {
				g_AudioChannels[i].unk20 = arg2 * 4;
			} else {
				g_AudioChannels[i].unk20 = -1;
			}

			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
			propsndTickChannel(i);
			osSetThreadPri(0, prevpri);
		}
	}
}

void func0f093790(struct prop *prop, s32 arg1)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < 40; i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0 && prop == g_AudioChannels[i].prop) {
			if (arg1 > 100) {
				arg1 = 100;
			}

			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

			g_AudioChannels[i].unk10 = arg1 * 32767 / 100;
			propsndTickChannel(i);

			osSetThreadPri(0, prevpri);
		}
	}
}

static void func0f0938ec(struct prop *prop)
{
	s32 lowestuuid = -1;
	s32 count = 0;
	s32 bestindex = -1;
	s32 i;

	for (i = 0; i < 40; i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0
				&& (channel->flags2 & AUDIOCHANNELFLAG2_0080) == 0
				&& prop == channel->prop
				&& channel->unk28 == 0x11) {
			count++;

			if (channel->uuid < lowestuuid) {
				lowestuuid = channel->uuid;
				bestindex = i;
			}
		}
	}

	if (1);

	if (count >= 2 && bestindex != -1) {
		func0f092a98(bestindex);
	}
}

s16 propsnd0f0939f8(
		struct audiochannel *channel,
		struct prop *prop,
		s16 soundnum,
		s16 padnum,
		s32 arg4,
		u16 flags,
		u16 flags2,
		s32 arg7,
		struct coord *pos,
		f32 arg9,
		s16 *rooms,
		s32 room,
		f32 arg12,
		f32 arg13,
		f32 arg14)
{
	union soundnumhack spac;
	OSPri prevpri;
	u32 stack[2];
	s32 tmp;

	struct pad pad;
	s32 i;
	s32 j;

	if (arg7 == 0x11) {
		func0f0938ec(prop);
	}

	spac.packed = soundnum;

	if (channel == NULL) {
		if (arg7 != 16 && var8005ddd4 > 12) {
			return -1;
		}

		for (i = 8; i < 40; i++) {
			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) {
				channel = &g_AudioChannels[i];
				channel->channelnum = i;
				break;
			}
		}
	}

	if (padnum >= 0) {
		pos = &g_Pads[padnum].pos;
		room = g_Pads[padnum].room;
		prop = NULL;
	}

	if (channel == NULL) {
		return -1;
	}

	if (g_AudioPrevUuid < 0xffffffff) {
		g_AudioPrevUuid++;
	} else {
		g_AudioPrevUuid = 0;
	}

	channel->flags = flags;
	channel->flags2 = flags2;
	channel->audiohandle = NULL;
	channel->unk06 = -1;
	channel->unk08 = -1;
	channel->unk0e = -1;
	channel->unk04 = (arg4 != -1) ? arg4 : -1;
	channel->unk0a = 64;
	channel->unk0c = 0;
	channel->unk10 = 0x7fff;
	channel->unk1a = 1;
	channel->unk44 = (arg9 > 0) ? arg9 : -1;
	channel->unk48 = channel->unk44;
	channel->unk20 = -1;
	channel->unk1c = -1;
	channel->padnum = padnum;
	channel->prop = prop;
	channel->unk28 = arg7;
	channel->unk12 = arg4;
	channel->unk40 = -1;
	channel->unk34 = (arg12 > 0) ? arg12 : 400;
	channel->unk38 = (arg13 > 0) ? arg13 : 2500;
	channel->unk3c = (arg14 > 0) ? arg14 : 3000;
	channel->unk18 = 0;
	channel->uuid = g_AudioPrevUuid;

	if (spac.hasconfig) {
		s32 id = spac.confignum;
		s32 confignum = g_AudioRussMappings[id].audioconfig_index;
		s32 newid = g_AudioRussMappings[id].soundnum;

		channel->unk34 = g_AudioConfigs[confignum].unk00;
		channel->unk38 = g_AudioConfigs[confignum].unk04;
		channel->unk3c = g_AudioConfigs[confignum].unk08;
		channel->unk18 = g_AudioConfigs[confignum].unk18;

		if (g_AudioConfigs[confignum].unk10 != 100) {
			channel->unk10 = g_AudioConfigs[confignum].unk10 * 327;
		}

		if (g_AudioConfigs[confignum].unk0c > 0) {
			channel->unk44 = g_AudioConfigs[confignum].unk0c;
		}

		tmp = g_AudioConfigs[confignum].unk14;

		if (tmp != -1) {
			channel->unk0a = tmp;
			channel->flags |= AUDIOCHANNELFLAG_0020;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_01) {
			channel->flags |= AUDIOCHANNELFLAG_0800;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_04) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0001;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_08) {
			if (channel->unk04 == -1) {
				channel->unk04 = channel->unk10;
			}

			channel->flags |= AUDIOCHANNELFLAG_8000;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_OFFENSIVE) {
			channel->flags2 |= AUDIOCHANNELFLAG2_OFFENSIVE;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_20) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0010;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_40) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0040;
		}

		channel->flags |= AUDIOCHANNELFLAG_0040;

		spac.packed = newid;
		spac.hasconfig = false;
		soundnum = spac.packed;
	}

	if (channel->unk18) {
		channel->flags |= AUDIOCHANNELFLAG_0002;
	}

	channel->soundnum26 = spac.packed;
	channel->unk2c = spac.id;

	if (sndIsFiltered(channel->unk2c)) {
		channel->flags2 |= AUDIOCHANNELFLAG2_OFFENSIVE;
	}

	if (spac.unk02) {
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

	if (pos) {
		channel->pos = *pos;
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

	if (!pos && !channel->prop) {
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

	if ((channel->flags2 & AUDIOCHANNELFLAG2_0010) && channel->unk04 == -1) {
		channel->unk04 = channel->unk10;
	}

	channel->flags |= AUDIOCHANNELFLAG_1000;

	if (sndIsMp3(soundnum)) {
		channel->flags |= AUDIOCHANNELFLAG_ISMP3;

		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		propsndTickChannel(channel->channelnum);
		osSetThreadPri(0, prevpri);
	} else {
		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		propsndTickChannel(channel->channelnum);
		osSetThreadPri(0, prevpri);
	}

	if (channel->flags & AUDIOCHANNELFLAG_0400) {
		channel->flags &= ~AUDIOCHANNELFLAG_0400;
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

	channel->flags &= ~AUDIOCHANNELFLAG_1000;

	return channel->channelnum;
}

s32 audioPlayFromProp(s32 channelnum, s16 soundnum, s32 arg2, struct prop *prop, s16 arg4, u16 arg5)
{
	s32 retchannelnum = -1;

	if (arg4 == 11) {
		if (channelnum >= 0 && channelnum <= 7) {
			if (g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) {
				g_AudioChannels[channelnum].soundnum26 = soundnum;
				g_AudioChannels[channelnum].unk28 = 11;
				g_AudioChannels[channelnum].flags &= ~AUDIOCHANNELFLAG_IDLE;
				retchannelnum = channelnum;
			} else {
				g_AudioChannels[channelnum].soundnum26 = soundnum;
				g_AudioChannels[channelnum].unk28 = 11;
				g_AudioChannels[channelnum].flags &= ~AUDIOCHANNELFLAG_IDLE;
				retchannelnum = channelnum;
			}
		} else {
			// empty
		}
	} else if (channelnum == 10) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
				(arg2 ? 0 : -1), arg5 | 0x0080, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
	} else if (channelnum < 0 || channelnum >= 8 || channelnum == 9) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
	} else {
		if ((g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) == 0) {
			func0f092a98(channelnum);
		}

		g_AudioChannels[channelnum].channelnum = channelnum;

		propsnd0f0939f8(&g_AudioChannels[channelnum], prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);

		retchannelnum = channelnum;
	}

	return retchannelnum;
}

void audioMuteChannel(s32 channelnum)
{
	if (channelnum == 10) {
		s32 i;

		for (i = 8; i < 40; i++) {
			if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
					&& (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_0080)) {
				func0f092a98(i);
			}
		}
	} else if (channelnum >= 0 && channelnum <= 7) {
		func0f092a98(channelnum);
	}
}

bool audioIsChannelIdle(s32 channelnum)
{
	if (channelnum >= 0 && channelnum <= 7) {
		return (g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) ? true : false;
	}

	if (channelnum == 10) {
		s32 i;

		for (i = 8; i < 40; i++) {
			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_0080) {
				return false;
			}
		}
	}

	return true;
}

void audioPlayFromProp2(s32 channelnum, s32 arg1, s16 padnum, struct prop *prop, s32 arg4, s32 arg5, s32 arg6, u16 arg7)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];
	bool a1 = (arg4 >= 6) ? true : false;
	bool a0 = (arg7 & 2) ? true : false;

	if (channelnum >= 0 && channelnum <= 7) {
		if (channel->unk28 == 11) {
			g_AudioChannels[channelnum].channelnum = (u16)channelnum;

			propsnd0f0939f8(&g_AudioChannels[channelnum], prop, channel->soundnum26, -1,
					-1, arg7, 0, 0, 0, -1, 0, -1, 400, arg5, arg6);
		} else {
			if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0 && arg1 >= 0) {
				channel->unk04 = arg1;
			}

			if (a1) {
				channel->unk1c = TICKS(arg4);
			}

			if (padnum != -1) {
				channel->padnum = padnum;
			}

			if (prop) {
				channel->prop = prop;
			}

			if (a0) {
				channel->flags |= AUDIOCHANNELFLAG_0002;
			}

			if ((channel->flags & AUDIOCHANNELFLAG_0040) == 0) {
				channel->unk34 = 400;
				channel->unk38 = arg5;
				channel->unk3c = arg6;
				channel->unk18 = 0;
			}

			if (!a1 || channel->unk1c == 0) {
				OSPri prevpri = osGetThreadPri(0);
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
				propsndTickChannel(channelnum);
				osSetThreadPri(0, prevpri);
			}
		}
	}
}

static s32 propsnd0f0946b0(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, s16 *rooms, s16 soundnum, s32 arg6, f32 *arg7)
{
	union soundnumhack sp6c;
	union soundnumhack sp68;
	f32 sp64;
	s16 sp62;
	s32 i;

	sp64 = arg3 + 10.0f;

	if (rooms != NULL) {
		sp62 = *rooms;
	} else {
		sp62 = -1;
	}

	sp68.packed = soundnum;
	sp6c.packed = soundnum;

	if (sp68.hasconfig) {
		s32 confignum = sp68.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		sp6c.packed = g_AudioRussMappings[confignum].soundnum;

		arg1 = g_AudioConfigs[index].unk00;
		arg2 = g_AudioConfigs[index].unk04;
		arg3 = g_AudioConfigs[index].unk08;

		if (arg3 < sp64) {
			sp64 = arg3;
		}
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		struct player *player = g_Vars.players[i];
		s32 camroom;

		if (sp6c.unk02 == 0) {
			camroom = player->cam_room;
		} else {
			camroom = -1;
		}

		func0f0056f4(camroom, &player->cam_pos, sp62, pos, 0, &sp64, 0);
	}

	if (arg7 != NULL) {
		*arg7 = sp64;
	}

	return func0f0927d4(sp64, arg1, arg2, arg3, arg6);
}

static s32 propsnd0f094940(s32 degrees, f32 arg1, struct audiochannel *channel)
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

	if (degrees >= -90 && degrees <= 90) {
		result = degrees * 0.7f + 64.0f;
	} else {
		s32 v0;
		s32 dir = degrees > 0 ? 1 : -1;
		s32 absdegrees = ABS(degrees);

		result = (s32) ((180 - absdegrees) * dir * 0.7f + 64.0f) + 128;
	}

	if (channel != NULL) {
		channel->unk14 = degrees;
		channel->unk16 = 100.0f * arg1;
	}

	return result;
}

static s32 propsnd0f094b1c(struct coord *pos, s32 arg1, f32 arg2, struct audiochannel *channel)
{
	s32 result = 64;
	u32 stack[4];
	s32 a0;
	f32 f2;

	if (PLAYERCOUNT() < 2) {
		struct coord *campos = &g_Vars.currentplayer->cam_pos;
		f32 sp3c;
		f32 sp38;

		f2 = -(atan2f(pos->x - campos->x, pos->z - campos->z) * 180.0f / M_PI + g_Vars.currentplayer->vv_theta);

		if (arg2 >= 0.0f) {
			sp3c = sinf(0.017453292f * f2);
			sp38 = cosf(0.017453292f * f2);

			sp3c *= arg2;

			f2 = atan2f(absf(sp3c), absf(sp38));

			if (!(sp3c >= 0.0f) || !(sp38 >= 0.0f)) {
				if (sp3c >= 0.0f) {
					f2 = M_PI - f2;
				} else if (sp38 >= 0.0f) {
					f2 = -f2;
				} else {
					f2 = -(M_PI - f2);
				}
			}

			a0 = (f2 * 57.295776f);
		} else {
			a0 = f2;
		}

		if (channel != NULL) {
			channel->unk14 = a0;
			channel->unk16 = 100.0f * arg2;
		}

		result = propsnd0f094940(a0, arg2, channel);
	}

	return result;
}

static s32 propsnd0f094d78(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, f32 arg4, bool arg5, struct audiochannel *channel)
{
	s32 result = 0x40;

	if (pos != NULL && arg4 > 0) {
		if (arg1 < 0) {
			arg1 = 400;
		}

		if (arg2 < 0) {
			arg2 = 2500;
		}

		if (arg3 < 0) {
			arg3 = 3000;
		}

		if (arg4 < arg3) {
			if (arg1 > 5501) {
				arg1 = 5501;
			}

			if (arg2 > 5801) {
				arg2 = 5801;
			}

			if (arg5 != 0) {
				if (!(arg4 < arg1)) {
					if (arg4 < arg2) {
						f32 f2 = (arg4 - arg1) / (arg2 - arg1);

						if (f2 < 0) {
							f2 = 0;
						}

						if (f2 > 1) {
							f2 = 1;
						}

						result = propsnd0f094b1c(pos, 0, f2, channel);
					} else {
						result = propsnd0f094b1c(pos, 0, -1, NULL);
					}
				}
			} else {
				result = propsnd0f094b1c(pos, 0, -1, channel);
			}
		}
	}

	return result;
}

void propsnd0f094ef4(struct coord *pos, s16 *rooms, s16 soundnum, s32 *arg3, s32 *arg4)
{
	f32 sp5c;
	f32 sp58;
	f32 sp54;
	struct audiorussmapping *russ;
	struct audioconfig *config;
	union soundnumhack sp48;
	union soundnumhack sp44;
	f32 sp40;
	bool sp3c;
	s32 index;
	s32 confignum;
	s32 zero = 0;

	sp5c = 400;
	sp58 = 2500;
	sp54 = 3000;
	if (1);
	sp44.packed = soundnum;
	sp40 = 9999999;
	sp3c = false;

	// To make this match, sp40 must be reloaded from the stack rather than
	// reuse its register. Calling a function invalidates the register, thus
	// forcing the compiler to emit code that reloads it from stack. Then an
	// optimisation pass in the compiler removes this branch and function call,
	// leaving the reload from stack in place.
	if (zero) {
		random();
	}

	if (sp44.hasconfig) {
		confignum = sp44.confignum;
		russ = &g_AudioRussMappings[confignum];
		index = russ->audioconfig_index;
		config = &g_AudioConfigs[index];
		sp5c = config->unk00;
		sp58 = config->unk04;
		sp54 = config->unk08;
		sp48.packed = russ->soundnum;

		if (config->flags & AUDIOCONFIGFLAG_01) {
			sp3c = true;
		}

		if (sp54 < sp40) {
			sp40 = sp54;
		}

		sp48.hasconfig = false;
		soundnum = sp48.packed;
	}

	*arg3 = propsnd0f0946b0(pos, sp5c, sp58, sp54, rooms, soundnum, 0x7fff, &sp40);
	*arg4 = propsnd0f094d78(pos, sp5c, sp58, sp54, sp40, sp3c, 0);
}

void func0f09505c(struct sndstate *handle, struct coord *pos, f32 arg2, f32 arg3, f32 arg4, s16 *rooms, s16 soundnum, s32 arg7, f32 *arg8)
{
	union soundnumhack sp5c;
	union soundnumhack sp58;
	f32 sp54;
	bool sp50;
	s32 sp4c;
	s32 pan;

	sp50 = false;
	sp54 = 9999999;
	sp58.packed = soundnum;

	if (arg8 == NULL) {
		arg8 = &sp54;
	}

	if (sp58.hasconfig) {
		s32 confignum = sp58.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		arg2 = g_AudioConfigs[index].unk00;
		arg3 = g_AudioConfigs[index].unk04;
		arg4 = g_AudioConfigs[index].unk08;
		sp5c.packed = g_AudioRussMappings[confignum].soundnum;

		if (g_AudioConfigs[index].flags & AUDIOCONFIGFLAG_01) {
			sp50 = true;
		}

		if (arg4 < *arg8) {
			*arg8 = arg4;
		}

		sp5c.hasconfig = false;
		soundnum = sp5c.packed;
	}

	sp4c = propsnd0f0946b0(pos, arg2, arg3, arg4, rooms, soundnum, arg7, arg8);
	pan = propsnd0f094d78(pos, arg2, arg3, arg4, *arg8, sp50, 0);
	sndAdjust(&handle, sndIsMp3(soundnum), sp4c, pan, soundnum, 1.0f, 1, -1, 1);
}

s32 propsndGetRandomSparkSound(void)
{
	return SFX_80B0 + (random() % 6);
}

/**
 * Get the duration for an MP3 file by channel number.
 *
 * All MP3 files are 24 kilobits per second
 * so this is just math based on the filesize.
 */
s32 propsndGetDuration60(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

	if (channelnum >= 0 && channelnum < 40
			&& (channel->flags & AUDIOCHANNELFLAG_IDLE) == 0
			&& (channel->flags & AUDIOCHANNELFLAG_ISMP3)) {
		union soundnumhack soundnum;
		soundnum.packed = channel->soundnum26;

		return fileGetRomSize(soundnum.id) * 60 / (1024 * 24 / 8);
	}

	return -1;
}
