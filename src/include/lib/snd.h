#ifndef _IN_LIB_SND_H
#define _IN_LIB_SND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool snd_is_filtered(s32 audioid);
bool snd_is_playing_mp3(void);
u16 snd0000e9dc(void);
void snd_set_sfx_volume(u16 volume);
void snd0000ea80(u16 volume);
void snd_reset_cur_mp3(void);
void snd_load_sfx_ctl(void);
void snd_increment_ages(void);
ALEnvelope *snd_load_envelope(u32 offset, u16 index);
ALKeyMap *snd_load_keymap(u32 offset, u16 index);
ALADPCMBook *snd_load_adpcm_book(u32 offset, u16 index);
ALADPCMloop *snd_load_adpcm_loop(u32 offset, u16 index);
ALWaveTable *snd_load_wavetable(u32 offset, u16 index);
void snd_set_sound_mode(s32 mode);
ALSound *snd_load_sound(s16 soundnum);
void seq_init(struct seqinstance *seq);
void snd_init(void);
bool snd_is_mp3(s16 soundnum);
bool snd_stop_mp3(s16 arg0);
bool seq_play(struct seqinstance *seq, s32 tracknum);
u16 seq_get_volume(struct seqinstance *seq);
void seq_set_volume(struct seqinstance *seq, u16 volume);
void snd_handle_retrace(void);
void snd0000fe20(void);
void snd0000fe50(void);
void snd_tick(void);
bool snd_is_disabled(void);
void snd_start_mp3_by_filenum(u32 filenum);
void snd_adjust(struct sndstate **handle, bool ismp3, s32 vol, s32 pan, s32 soundnum, f32 pitch, s32 fxbus, s32 fxmix, bool forcefxmix);
struct sndstate *snd00010718(struct sndstate **handle, s32 flags, s32 volume, s32 pan, s32 soundnum, f32 pitch, s32 fxbus, s32 fxmix, bool forcefxmix);
struct sndstate *snd_start(s32 arg0, s16 sound, struct sndstate **handle, s32 volume, s32 pan, f32 pitch, s32 fxbus, s32 fxmix);
void snd_start_mp3(s16 soundnum, s32 volume, s32 pan, s32 responseflags);
void snd_play_nosedive(s32 seconds);
void snd_stop_nosedive(void);
void snd_tick_nosedive(void);
void snd_play_ufo(s32 seconds);
void snd_stop_ufo(void);
void snd_tick_ufo(void);

#endif
