#ifndef IN_GAME_PROPSND_H
#define IN_GAME_PROPSND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void psReset(void);

void psStop(void);

bool psPropHasSoundWithContext(struct prop *prop, s32 type);
void psStopSound(struct prop *prop, s32 type, u16 flags);
s32 psCalculateVolumeFromDistance(f32 playerdist, f32 dist1, f32 dist2, f32 dist3, s32 fullvolume);
s32 psGetVolume(s32 channelnum);
void psCreateIfNotDupe(struct prop *prop, s16 soundnum, s32 type);
void psStopChannel(s32 channelnum);
void psPrintChannel(struct pschannel *channel);
s32 psGetSubtitleOpacity(s32 channelnum);
void psTickChannel(s32 channelnum);
void psTick(void);
void psSetPitch(struct prop *prop, f32 targetpitch, s32 changespeed);
void psSetVolume(struct prop *prop, s32 vol);
void psStopOneShootChannel(struct prop *prop);
s16 psCreate(struct pschannel *channel, struct prop *prop, s16 soundnum, s16 padnum, s32 vol, u16 flags, u16 flags2, s32 type, struct coord *pos, f32 pitch, RoomNum *rooms, s32 room, f32 dist1, f32 dist2, f32 dist3);
s32 psPlayFromProp(s32 channelnum, s16 soundnum, s32 vol, struct prop *prop, s16 type, u16 flags);
void psMuteChannel(s32 channelnum);
bool psIsChannelFree(s32 channelnum);
void psModify(s32 channelnum, s32 arg1, s16 padnum, struct prop *prop, s32 volchangetimer60, s32 dist2, s32 dist3, u16 flags);
s32 psCalculateVol(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, RoomNum *rooms, s16 soundnum, s32 arg6, f32 *arg7);
s32 psCalculatePan3(s32 degrees, f32 arg1, struct pschannel *channel);
s32 psCalculatePan2(struct coord *pos, s32 arg1, f32 arg2, struct pschannel *channel);
s32 psCalculatePan(struct coord *pos, f32 dist1, f32 dist2, f32 dist3, f32 playerdist, bool arg5, struct pschannel *channel);
void psGetTheoreticalVolPan(struct coord *pos, RoomNum *rooms, s16 soundnum, s32 *vol, s32 *pan);
void psApplyVolPan(struct sndstate *handle, struct coord *pos, f32 dist1, f32 dist2, f32 dist3, RoomNum *rooms, s16 soundnum, s32 arg7, f32 *distanceptr);
s32 psGetRandomSparkSound(void);
s32 psGetDuration60(s32 channelnum);

#endif
