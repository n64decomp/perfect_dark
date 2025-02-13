#include <ultra64.h>
#include <n_libaudio.h>
#include "naudio/n_abi.h"
#include "ultra/audio/synthInternals.h"
#include "naudio/n_synthInternals.h"
#include "lib/mp3.h"
#include "mp3/mp3.h"
#include "types.h"

/**
 * These two ABI commands are used in this file, but the format of the data
 * doesn't match the format used by n_audio's ABI.
 */
#define	aMp3ExecDma(pkt, a, b)                               \
{                                                            \
	Acmd *_a = (Acmd *)pkt;                                  \
	_a->words.w0 = _SHIFTL(0x07, 24, 8) | _SHIFTL(a, 0, 16); \
	_a->words.w1 = b;                                        \
}

#define	aMp3SetAddr(pkt, a)              \
{                                        \
	Acmd *_a = (Acmd *)pkt;              \
	_a->words.w0 = _SHIFTL(0x08, 24, 8); \
	_a->words.w1 = a;                    \
}

#define N_EQPOWER_LENGTH 128

struct mp3vars g_Mp3Vars;
struct asistream *g_AsiStream;

void mp3_set_dma_func(void *fn);
s32 mp3_handle_dma(s32 arg0, u8 *arg1, s32 arg2, s32 arg3);
void mp3_dma(void);

extern f32 *var8009c6d8;
extern f32 *var8009c6dc;
extern struct mp3decfourbytes *var8009c640;
extern f32 *var8009c644;

void mp3_update_vars(struct mp3vars *vars);

void mp3_init(ALHeap *heap)
{
	bzero(&g_Mp3Vars, sizeof(struct mp3vars));

#if VERSION < VERSION_NTSC_1_0
	rmon_printf("MPEG : RWI -> Allocating %d bytes for ASISTREAM from audio heap\n", sizeof(struct asistream));
#endif

	g_AsiStream = alHeapAlloc(heap, sizeof(struct asistream), 1);
	var8005f6f8 = alHeapAlloc(heap, 1, 34 * 256 * sizeof(var8005f6f8[0]));
	var8005f6fc = alHeapAlloc(heap, 1, 34 * 256 * sizeof(var8005f6fc[0]));
	var8009c6d8 = alHeapAlloc(heap, 256 * sizeof(var8009c6d8[0]), 1);
	var8009c6dc = alHeapAlloc(heap, 256 * sizeof(var8009c6dc[0]), 1);
	var8009c640 = alHeapAlloc(heap, 10500 * sizeof(struct mp3decfourbytes), 1);
	var8009c644 = alHeapAlloc(heap, 8192 * sizeof(var8009c644[0]), 1);

	mp3main_init();

	g_Mp3Vars.em_state = alHeapAlloc(heap, 1, ALIGN16(sizeof(ENVMIX_STATE)));
	g_Mp3Vars.var8009c3d4[0] = alHeapAlloc(heap, 1, 0x440);
	g_Mp3Vars.state = MP3STATE_IDLE;
	g_Mp3Vars.currentvol = AL_VOL_FULL;
	g_Mp3Vars.currentpan = g_Mp3Vars.targetpan = AL_PAN_CENTER;
	g_Mp3Vars.em_volume = AL_VOL_FULL;
	g_Mp3Vars.em_pan = AL_PAN_CENTER;
	g_Mp3Vars.em_cvolL = (n_eqpower[g_Mp3Vars.em_pan & 0x7f] * g_Mp3Vars.em_volume) >> 15;
	g_Mp3Vars.em_cvolR = (n_eqpower[N_EQPOWER_LENGTH - (g_Mp3Vars.em_pan & 0x7f) - 1] * g_Mp3Vars.em_volume) >> 15;
	g_Mp3Vars.em_first = 1;
	g_Mp3Vars.em_dryamt = 0x7ffc;
	g_Mp3Vars.em_wetamt = (g_Mp3Vars.em_pan & 0x80) ? 1 : 0;

	mp3_set_dma_func(mp3_handle_dma);
}

void mp3_play_file(s32 romaddr, s32 filesize)
{
	if (g_Mp3Vars.dmafunc == NULL) {
		return;
	}

	g_Mp3Vars.romaddr = romaddr;
	g_Mp3Vars.filesize = filesize;
	g_Mp3Vars.dmaoffset = 0;
	g_Mp3Vars.var8009c3e8 = 0;
	g_Mp3Vars.currentvol = AL_VOL_FULL;
	g_Mp3Vars.statetimer = 5;

	mp3_dma();

	g_Mp3Vars.state = MP3STATE_LOADING;
}

void mp3_stop(void)
{
	g_Mp3Vars.state = MP3STATE_STOPPED;
}

void mp3_pause(void)
{
	/**
	 * @bug: Pausing while the MP3 system is still in MP3STATE_LOADING causes
	 * the pause to be ignored. This is what makes speech skipping possible.
	 * Additionally, after unpausing the MP3 system is in MP3STATE_UNPAUSING for
	 * a few frames, so pauses during this time is also ignored.
	 */
	if (g_Mp3Vars.state == MP3STATE_PLAYING) {
		g_Mp3Vars.state = MP3STATE_PAUSED;
	}
}

void mp3_unpause(void)
{
	if (g_Mp3Vars.state == MP3STATE_PAUSED) {
		g_Mp3Vars.statetimer = 5;
		g_Mp3Vars.state = MP3STATE_UNPAUSING;
	}
}

s32 mp3_is_busy(void)
{
	if (g_Mp3Vars.state == MP3STATE_PLAYING
			|| g_Mp3Vars.state == MP3STATE_LOADING
			|| g_Mp3Vars.state == MP3STATE_UNPAUSING
			|| g_Mp3Vars.state == MP3STATE_PAUSED) {
		return g_Mp3Vars.state;
	} else {
		return 0;
	}
}

void mp3_set_vol(s32 vol, bool arg1)
{
	if (vol < 0) {
		g_Mp3Vars.currentvol = 0;
	} else if (vol > AL_VOL_FULL) {
		g_Mp3Vars.currentvol = AL_VOL_FULL;
	} else {
		g_Mp3Vars.currentvol = vol;
	}

	g_Mp3Vars.var8009c3e8 = arg1;
}

void mp3_set_pan(s32 pan, bool immediate)
{
	if (pan > 255) {
		pan = 255;
	}

	if (pan < 0) {
		pan = 0;
	}

	g_Mp3Vars.targetpan = pan;

	if (immediate) {
		g_Mp3Vars.currentpan = g_Mp3Vars.targetpan;
	}
}

void mp3_00037fa8(s32 arg0, s32 arg1)
{
	// empty
}

bool mp3_make_samples(s32 arg0, Acmd **cmd)
{
	s32 i;
	s32 diff;
	s32 numchannels = 0;
	struct mp3thing *sp58;
	struct mp3thing *sp54 = NULL;
	s32 sp50;
	s32 sp4c = N_AL_MAIN_L_OUT;
	s32 sp48 = N_AL_MAIN_R_OUT;

	if (g_Mp3Vars.currentpan != g_Mp3Vars.targetpan) {
		diff = g_Mp3Vars.targetpan - g_Mp3Vars.currentpan;

		if (diff >= -2 && diff <= 2) {
			g_Mp3Vars.currentpan += diff;
		} else if (diff >= 3) {
			g_Mp3Vars.currentpan += 2;
		} else {
			g_Mp3Vars.currentpan -= 2;
		}
	}

	if (g_Mp3Vars.state == MP3STATE_LOADING) {
		mp3_dma();

		if (g_Mp3Vars.statetimer == 0) {
			g_Mp3Vars.stream = mp3main_start_file(0, g_Mp3Vars.dmafunc, g_Mp3Vars.filesize);

			if (g_Mp3Vars.stream == NULL) {
				g_Mp3Vars.state = MP3STATE_IDLE;
				return false;
			} else {
				g_Mp3Vars.state = MP3STATE_PLAYING;
				g_Mp3Vars.em_first = 1;
				g_Mp3Vars.var8009c3c8 = NULL;
				g_Mp3Vars.var8009c3cc = 0;
				g_Mp3Vars.var8009c3d0 = 0;
				g_Mp3Vars.var8009c3d8 = 0;

				bzero(g_Mp3Vars.var8009c3d4[0], 0x440);
			}
		} else {
			g_Mp3Vars.statetimer--;
		}
	}

	if (g_Mp3Vars.state == MP3STATE_UNPAUSING) {
		mp3_dma();

		if (g_Mp3Vars.statetimer == 0) {
			g_Mp3Vars.state = MP3STATE_PLAYING;
		} else {
			g_Mp3Vars.statetimer--;
		}
	}

	if (g_Mp3Vars.state == MP3STATE_PLAYING) {
		if (arg0 + g_Mp3Vars.var8009c3d0 > g_Mp3Vars.var8009c3cc) {
			g_Mp3Vars.var8009c3cc -= g_Mp3Vars.var8009c3d0;

			if (g_Mp3Vars.var8009c3cc != 0 && g_Mp3Vars.var8009c3c8 != NULL) {
				sp54 = (struct mp3thing *)(g_Mp3Vars.var8009c3d0 + g_Mp3Vars.var8009c3c8->unk00);
				sp50 = g_Mp3Vars.var8009c3cc;
			}

			g_Mp3Vars.var8009c3d0 = 0;
			g_Mp3Vars.var8009c3cc = 0;

			if (mp3main_continue_file(g_Mp3Vars.stream, &sp58, &numchannels)) {
				g_Mp3Vars.var8009c3c8 = sp58;

				for (i = 0; i < numchannels; i++) {
					aMp3SetAddr((*cmd)++, osVirtualToPhysical(g_Mp3Vars.var8009c3d4[i]));
					aMp3ExecDma((*cmd)++, g_Mp3Vars.var8009c3d8, osVirtualToPhysical(sp58));

					sp58++;
				}

				g_Mp3Vars.var8009c3d8 = (g_Mp3Vars.var8009c3d8 - 0x24) & 0x1e;
				g_Mp3Vars.var8009c3cc = 0x240;
				g_Mp3Vars.dualchannel = numchannels == 2;
			} else {
				// empty
			}
		}

		mp3_dma();

		if (!g_Mp3Vars.dualchannel) {
			sp4c = 0;
		}

		if (sp54 != NULL) {
			n_aLoadBuffer((*cmd)++, sp50 + sp50, sp4c, osVirtualToPhysical(sp54));

			if (g_Mp3Vars.dualchannel) {
				sp54++;
				n_aLoadBuffer((*cmd)++, sp50 + sp50, sp48, osVirtualToPhysical(sp54));
			}

			sp4c += sp50 + sp50;
			sp48 += sp50 + sp50;
			arg0 -= sp50;
		}

		if (arg0 > 0 && g_Mp3Vars.var8009c3c8 != NULL) {
			sp54 = (struct mp3thing *)(g_Mp3Vars.var8009c3d0 * 2 + (uintptr_t)g_Mp3Vars.var8009c3c8);

			n_aLoadBuffer((*cmd)++, arg0 + arg0, sp4c, osVirtualToPhysical(sp54));

			if (g_Mp3Vars.dualchannel) {
				sp54++;
				n_aLoadBuffer((*cmd)++, arg0 + arg0, sp48, osVirtualToPhysical(sp54));
			}

			g_Mp3Vars.var8009c3d0 += arg0;
		}

		mp3_update_vars(&g_Mp3Vars);

		if (!g_Mp3Vars.dualchannel) {
			aClearBuffer((*cmd)++, N_AL_MAIN_L_OUT, N_AL_TEMP_2);

			if (g_Mp3Vars.em_first) {
				g_Mp3Vars.em_first = 0;

				g_Mp3Vars.em_ltgt = (g_Mp3Vars.em_volume * n_eqpower[g_Mp3Vars.em_pan & 0x7f]) >> 15;
				g_Mp3Vars.em_lratm = _getRate(g_Mp3Vars.em_cvolL, g_Mp3Vars.em_ltgt, g_Mp3Vars.em_segEnd, &g_Mp3Vars.em_lratl);

				g_Mp3Vars.em_rtgt = (g_Mp3Vars.em_volume * n_eqpower[N_EQPOWER_LENGTH - (g_Mp3Vars.em_pan & 0x7f) - 1]) >> 15;
				g_Mp3Vars.em_rratm = _getRate(g_Mp3Vars.em_cvolR, g_Mp3Vars.em_rtgt, g_Mp3Vars.em_segEnd, &g_Mp3Vars.em_rratl);

				n_aSetVolume((*cmd)++, A_VOL | A_LEFT, g_Mp3Vars.em_cvolL, g_Mp3Vars.em_dryamt, g_Mp3Vars.em_wetamt);
				n_aSetVolume((*cmd)++, A_VOL | A_RIGHT, g_Mp3Vars.em_rtgt, g_Mp3Vars.em_rratm, g_Mp3Vars.em_rratl);
				n_aSetVolume((*cmd)++, A_RATE, g_Mp3Vars.em_ltgt, g_Mp3Vars.em_lratm, g_Mp3Vars.em_lratl);
				n_aEnvMixer((*cmd)++, A_INIT, g_Mp3Vars.em_cvolR, osVirtualToPhysical(g_Mp3Vars.em_state));
			} else {
				n_aEnvMixer((*cmd)++, A_CONTINUE, 0, osVirtualToPhysical(g_Mp3Vars.em_state));
			}

			g_Mp3Vars.em_delta += SAMPLES;

			if (g_Mp3Vars.em_delta > g_Mp3Vars.em_segEnd) {
				g_Mp3Vars.em_delta = g_Mp3Vars.em_segEnd;
			}
		}
	} else {
		return false;
	}

	return true;
}

void mp3_update_vars(struct mp3vars *vars)
{
	if (vars->em_volume != vars->currentvol || vars->em_pan != vars->currentpan) {
		if (vars->em_delta >= vars->em_segEnd) {
			vars->em_ltgt = (n_eqpower[vars->em_pan & 0x7f] * vars->em_volume >> 15);
			vars->em_rtgt = (n_eqpower[N_EQPOWER_LENGTH - (vars->em_pan & 0x7f) - 1] * vars->em_volume >> 15);
			vars->em_delta = vars->em_segEnd;
			vars->em_cvolL = vars->em_ltgt;
			vars->em_cvolR = vars->em_rtgt;
		} else {
			vars->em_cvolL = _getVol(vars->em_cvolL, vars->em_delta, vars->em_lratm, vars->em_lratl);
			vars->em_cvolR = _getVol(vars->em_cvolR, vars->em_delta, vars->em_rratm, vars->em_rratl);
		}

		if (vars->em_cvolL == 0) {
			vars->em_cvolL = 1;
		}

		if (vars->em_cvolR == 0) {
			vars->em_cvolR = 1;
		}

		vars->em_volume = vars->currentvol;

		if (vars->em_pan != vars->currentpan) {
			if (var8009c340.headphone) {
				vars->em_pan = ((s16)(vars->currentpan & 0x7f) >> 1) + 32;
			} else {
				if (var8009c340.mono) {
					vars->em_pan = AL_PAN_CENTER;
				} else {
					vars->em_pan = vars->currentpan;
				}
			}

			vars->em_pan &= (vars->currentpan & 0x80) + 127;

			vars->em_wetamt = (vars->em_pan & 0x80) ? 1 : 0;
		}

		vars->em_delta = 0;
		vars->em_segEnd = SAMPLE184(vars->var8009c3e8);
		vars->em_first = 1;
	}
}

void mp3_set_dma_func(void *fn)
{
	g_Mp3Vars.dmafunc = fn;
}

s32 mp3_handle_dma(s32 arg0, u8 *dst, s32 len, s32 dmaoffset)
{
	u8 *bufptr;
	ALDMAproc proc;

	if (dmaoffset != -1) {
		g_Mp3Vars.dmaoffset = dmaoffset;
	}

	if (g_Mp3Vars.dmaoffset + len > g_Mp3Vars.filesize) {
		len = g_Mp3Vars.filesize - g_Mp3Vars.dmaoffset;
	}

	proc = n_syn->dma(&bufptr);
	bufptr = (u8 *) OS_K0_TO_PHYSICAL(proc(g_Mp3Vars.romaddr + g_Mp3Vars.dmaoffset, len, NULL));

	bcopy(bufptr, dst, len);

	g_Mp3Vars.dmaoffset += len;

	return len;
}

void mp3_dma(void)
{
	u8 *bufptr;
	ALDMAproc proc;

	proc = n_syn->dma(&bufptr);

	proc(g_Mp3Vars.romaddr + g_Mp3Vars.dmaoffset, 0x400, NULL);
}
