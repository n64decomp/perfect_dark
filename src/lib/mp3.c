#include <ultra64.h>
#include <n_libaudio.h>
#include "naudio/n_abi.h"
#include "lib/mp3.h"
#include "mp3/mp3.h"
#include "types.h"

/**
 * These two ABI commands are used in this file, but the format of the data
 * doesn't match the format used by n_audio's ABI.
 */
#define	acmd07(pkt, a, b)                                    \
{                                                            \
	Acmd *_a = (Acmd *)pkt;                                  \
	_a->words.w0 = _SHIFTL(0x07, 24, 8) | _SHIFTL(a, 0, 16); \
	_a->words.w1 = b;                                        \
}

#define	acmd08(pkt, a)                   \
{                                        \
	Acmd *_a = (Acmd *)pkt;              \
	_a->words.w0 = _SHIFTL(0x08, 24, 8); \
	_a->words.w1 = a;                    \
}

struct mp3vars g_Mp3Vars;
struct asistream *g_AsiStream;

static void func00038924(struct mp3vars *vars);
static s32 func00038ba8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3);
static void mp3Dma(void);

extern f32 *var8009c6d8;
extern f32 *var8009c6dc;
extern struct mp3decfourbytes *var8009c640;
extern f32 *var8009c644;

void mp3Init(ALHeap *heap)
{
	bzero(&g_Mp3Vars, sizeof(struct mp3vars));

	g_AsiStream = alHeapAlloc(heap, sizeof(struct asistream), 1);
	var8005f6f8 = alHeapAlloc(heap, 1, 0x2200);
	var8005f6fc = alHeapAlloc(heap, 1, 0x2200);

	var8009c6d8 = alHeapAlloc(heap, 256 * sizeof(f32), 1);
	var8009c6dc = alHeapAlloc(heap, 256 * sizeof(f32), 1);
	var8009c640 = alHeapAlloc(heap, 10500 * sizeof(struct mp3decfourbytes), 1);
	var8009c644 = alHeapAlloc(heap, 8192 * sizeof(f32), 1);

	mp3mainInit();

	g_Mp3Vars.var8009c398 = alHeapAlloc(heap, 1, 0x50);
	*(u8 **)((u32)&g_Mp3Vars+0x44) = alHeapAlloc(heap, 1, 0x440);

	g_Mp3Vars.var8009c3e0 = 0;
	g_Mp3Vars.var8009c3e4 = 0x7fff;
	g_Mp3Vars.var8009c3ec = g_Mp3Vars.var8009c3ee = 0x40;
	g_Mp3Vars.var8009c39e = 0x7fff;
	g_Mp3Vars.var8009c39c = 0x40;

	g_Mp3Vars.ivol1 = (n_eqpower[g_Mp3Vars.var8009c39c & 0x7f] * g_Mp3Vars.var8009c39e) >> 15;
	g_Mp3Vars.ivol2 = (n_eqpower[127 - (g_Mp3Vars.var8009c39c & 0x7f)] * g_Mp3Vars.var8009c39e) >> 15;

	g_Mp3Vars.var8009c3b4 = 1;
	g_Mp3Vars.var8009c3a4 = 0x7ffc;

	if (g_Mp3Vars.var8009c39c & 0x80) {
		g_Mp3Vars.var8009c3a6 = 1;
	} else {
		g_Mp3Vars.var8009c3a6 = 0;
	}

	g_Mp3Vars.var8009c3dc = func00038ba8;
}

void mp3PlayFile(s32 romaddr, s32 filesize)
{
	if (g_Mp3Vars.var8009c3dc == NULL) {
		return;
	}

	g_Mp3Vars.romaddr = romaddr;
	g_Mp3Vars.filesize = filesize;
	g_Mp3Vars.var8009c3c4 = 0;
	g_Mp3Vars.var8009c3e8 = 0;
	g_Mp3Vars.var8009c3e4 = 0x7fff;
	g_Mp3Vars.var8009c3f0 = 5;

	mp3Dma();

	g_Mp3Vars.var8009c3e0 = 4;
}

void func00037e38(void)
{
	if (g_Mp3Vars.var8009c3e0 == 1) {
		g_Mp3Vars.var8009c3e0 = 2;
	}
}

void func00037e68(void)
{
	if (g_Mp3Vars.var8009c3e0 == 2) {
		g_Mp3Vars.var8009c3f0 = 5;
		g_Mp3Vars.var8009c3e0 = 5;
	}
}

s32 func00037ea4(void)
{
	if (g_Mp3Vars.var8009c3e0 == 1
			|| g_Mp3Vars.var8009c3e0 == 4
			|| g_Mp3Vars.var8009c3e0 == 5
			|| g_Mp3Vars.var8009c3e0 == 2) {
		return g_Mp3Vars.var8009c3e0;
	} else {
		return 0;
	}
}

void func00037f08(s32 arg0, bool arg1)
{
	if (arg0 < 0) {
		g_Mp3Vars.var8009c3e4 = 0;
	} else if (arg0 > 0x7fff) {
		g_Mp3Vars.var8009c3e4 = 0x7fff;
	} else {
		g_Mp3Vars.var8009c3e4 = arg0;
	}

	g_Mp3Vars.var8009c3e8 = arg1;
}

void func00037f5c(s32 arg0, bool arg1)
{
	if (arg0 > 255) {
		arg0 = 255;
	}

	if (arg0 < 0) {
		arg0 = 0;
	}

	g_Mp3Vars.var8009c3ee = arg0;

	if (arg1) {
		g_Mp3Vars.var8009c3ec = g_Mp3Vars.var8009c3ee;
	}
}

s32 func00037fc0(s32 arg0, Acmd **cmd)
{
	s32 i;
	s32 sp60;
	s32 sp5c = 0;
	struct mp3thing *sp58;
	struct mp3thing *sp54 = NULL;
	s32 sp50;
	s32 sp4c = 0x4e0;
	s32 sp48 = 0x650;

	if (g_Mp3Vars.var8009c3ec != g_Mp3Vars.var8009c3ee) {
		sp60 = g_Mp3Vars.var8009c3ee - g_Mp3Vars.var8009c3ec;

		if (sp60 >= -2 && sp60 <= 2) {
			g_Mp3Vars.var8009c3ec += sp60;
		} else if (sp60 >= 3) {
			g_Mp3Vars.var8009c3ec += 2;
		} else {
			g_Mp3Vars.var8009c3ec -= 2;
		}
	}

	if (g_Mp3Vars.var8009c3e0 == 4) {
		mp3Dma();

		if (g_Mp3Vars.var8009c3f0 == 0) {
			g_Mp3Vars.var8009c394 = mp3main00044460(0, g_Mp3Vars.var8009c3dc, g_Mp3Vars.filesize);

			if (g_Mp3Vars.var8009c394 == NULL) {
				g_Mp3Vars.var8009c3e0 = 0;
				return 0;
			} else {
				g_Mp3Vars.var8009c3e0 = 1;
				g_Mp3Vars.var8009c3b4 = 1;
				g_Mp3Vars.var8009c3c8 = 0;
				g_Mp3Vars.var8009c3cc = 0;
				g_Mp3Vars.var8009c3d0 = 0;
				g_Mp3Vars.var8009c3d8 = 0;

				bzero(*(u32 **)&g_Mp3Vars.var8009c3d4, 0x440);
			}
		} else {
			g_Mp3Vars.var8009c3f0--;
		}
	}

	if (g_Mp3Vars.var8009c3e0 == 5) {
		mp3Dma();

		if (g_Mp3Vars.var8009c3f0 == 0) {
			g_Mp3Vars.var8009c3e0 = 1;
		} else {
			g_Mp3Vars.var8009c3f0--;
		}
	}

	if (g_Mp3Vars.var8009c3e0 == 1) {
		if (arg0 + g_Mp3Vars.var8009c3d0 > g_Mp3Vars.var8009c3cc) {
			g_Mp3Vars.var8009c3cc -= g_Mp3Vars.var8009c3d0;

			if (g_Mp3Vars.var8009c3cc != 0 && g_Mp3Vars.var8009c3c8 != 0) {
				sp54 = (struct mp3thing *)(g_Mp3Vars.var8009c3d0 + g_Mp3Vars.var8009c3c8->unk00);
				sp50 = g_Mp3Vars.var8009c3cc;
			}

			g_Mp3Vars.var8009c3d0 = 0;
			g_Mp3Vars.var8009c3cc = 0;

			if (mp3main0004453c(g_Mp3Vars.var8009c394, &sp58, &sp5c)) {
				g_Mp3Vars.var8009c3c8 = sp58;

				for (i = 0; i < sp5c; i++) {
					acmd08((*cmd)++, osVirtualToPhysical(g_Mp3Vars.var8009c3d4_arr[i]));
					acmd07((*cmd)++, g_Mp3Vars.var8009c3d8, osVirtualToPhysical(sp58));

					sp58++;
				}

				g_Mp3Vars.var8009c3d8 = (g_Mp3Vars.var8009c3d8 - 0x24) & 0x1e;
				g_Mp3Vars.var8009c3cc = 0x240;
				g_Mp3Vars.var8009c3f1 = sp5c == 2;
			} else {
				// empty
			}
		}

		mp3Dma();

		if (g_Mp3Vars.var8009c3f1 == 0) {
			sp4c = 0;
		}

		if (sp54 != NULL) {
			n_aLoadBuffer((*cmd)++, sp50 + sp50, sp4c, osVirtualToPhysical(sp54));

			if (g_Mp3Vars.var8009c3f1) {
				sp54++;
				n_aLoadBuffer((*cmd)++, sp50 + sp50, sp48, osVirtualToPhysical(sp54));
			}

			sp4c += sp50 + sp50;
			sp48 += sp50 + sp50;
			arg0 -= sp50;
		}

		if (arg0 > 0 && g_Mp3Vars.var8009c3c8) {
			sp54 = (struct mp3thing *)(g_Mp3Vars.var8009c3d0 * 2 + (u32)g_Mp3Vars.var8009c3c8);

			n_aLoadBuffer((*cmd)++, arg0 + arg0, sp4c, osVirtualToPhysical(sp54));

			if (g_Mp3Vars.var8009c3f1) {
				sp54++;
				n_aLoadBuffer((*cmd)++, arg0 + arg0, sp48, osVirtualToPhysical(sp54));
			}

			g_Mp3Vars.var8009c3d0 += arg0;
		}

		func00038924(&g_Mp3Vars);

		if (!g_Mp3Vars.var8009c3f1) {
			aClearBuffer((*cmd)++, 0x4e0, 0x2e0);

			if (g_Mp3Vars.var8009c3b4) {
				g_Mp3Vars.var8009c3b4 = 0;

				g_Mp3Vars.var8009c3ac = n_eqpower[g_Mp3Vars.var8009c39c & 0x7f] * g_Mp3Vars.var8009c39e >> 0xf;
				g_Mp3Vars.ratem1 = _getRate(g_Mp3Vars.ivol1, g_Mp3Vars.var8009c3ac, g_Mp3Vars.var8009c3bc, &g_Mp3Vars.ratel1);

				g_Mp3Vars.var8009c3b2 = n_eqpower[0x7f - (g_Mp3Vars.var8009c39c & 0x7f)] * g_Mp3Vars.var8009c39e >> 0xf;
				g_Mp3Vars.ratem2 = _getRate(g_Mp3Vars.ivol2, g_Mp3Vars.var8009c3b2, g_Mp3Vars.var8009c3bc, &g_Mp3Vars.ratel2);

				n_aSetVolume((*cmd)++, A_VOL | A_LEFT, g_Mp3Vars.ivol1, g_Mp3Vars.var8009c3a4, g_Mp3Vars.var8009c3a6);
				n_aSetVolume((*cmd)++, A_VOL | A_RIGHT, g_Mp3Vars.var8009c3b2, g_Mp3Vars.ratem2, g_Mp3Vars.ratel2);
				n_aSetVolume((*cmd)++, A_RATE, g_Mp3Vars.var8009c3ac, g_Mp3Vars.ratem1, g_Mp3Vars.ratel1);
				n_aEnvMixer((*cmd)++, 1, g_Mp3Vars.ivol2, osVirtualToPhysical(g_Mp3Vars.var8009c398));
			} else {
				n_aEnvMixer((*cmd)++, 0, 0, osVirtualToPhysical(g_Mp3Vars.var8009c398));
			}

			g_Mp3Vars.samples += 184;

			if (g_Mp3Vars.samples > g_Mp3Vars.var8009c3bc) {
				g_Mp3Vars.samples = g_Mp3Vars.var8009c3bc;
			}
		}
	} else {
		return 0;
	}

	return 1;
}

static void func00038924(struct mp3vars *vars)
{
	if (vars->var8009c39e != vars->var8009c3e4 || vars->var8009c39c != vars->var8009c3ec) {
		if (vars->samples >= vars->var8009c3bc) {
			vars->var8009c3ac = (n_eqpower[vars->var8009c39c & 0x7f] * vars->var8009c39e >> 15);
			vars->var8009c3b2 = (n_eqpower[127 - (vars->var8009c39c & 0x7f)] * vars->var8009c39e >> 15);
			vars->samples = vars->var8009c3bc;
			vars->ivol1 = vars->var8009c3ac;
			vars->ivol2 = vars->var8009c3b2;
		} else {
			vars->ivol1 = _getVol(vars->ivol1, vars->samples, vars->ratem1, vars->ratel1);
			vars->ivol2 = _getVol(vars->ivol2, vars->samples, vars->ratem2, vars->ratel2);
		}

		if (vars->ivol1 == 0) {
			vars->ivol1 = 1;
		}

		if (vars->ivol2 == 0) {
			vars->ivol2 = 1;
		}

		vars->var8009c39e = vars->var8009c3e4;

		if (vars->var8009c39c != vars->var8009c3ec) {
			if (var8009c340.headphone) {
				vars->var8009c39c = ((s16)(vars->var8009c3ec & 0x7f) >> 1) + 32;
			} else {
				if (var8009c340.mono) {
					vars->var8009c39c = 64;
				} else {
					vars->var8009c39c = vars->var8009c3ec;
				}
			}

			vars->var8009c39c &= (vars->var8009c3ec & 0x80) + 0x7f;

			vars->var8009c3a6 = (vars->var8009c39c & 0x80) ? 1 : 0;
		}

		vars->samples = 0;
		vars->var8009c3bc = (vars->var8009c3e8 + 183) / 184 * 184;
		vars->var8009c3b4 = 1;
	}
}

static s32 func00038ba8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3)
{
	u32 sp1c;
	ALDMAproc proc;

	if (arg3 != -1) {
		g_Mp3Vars.var8009c3c4 = arg3;
	}

	if (g_Mp3Vars.var8009c3c4 + arg2 > g_Mp3Vars.filesize) {
		arg2 = g_Mp3Vars.filesize - g_Mp3Vars.var8009c3c4;
	}

	proc = n_syn->dma(&sp1c);
	sp1c = OS_K0_TO_PHYSICAL(proc(g_Mp3Vars.romaddr + g_Mp3Vars.var8009c3c4, arg2, 0));

	bcopy((u8 *)sp1c, arg1, arg2);

	g_Mp3Vars.var8009c3c4 += arg2;

	return arg2;
}

static void mp3Dma(void)
{
	u32 state;
	ALDMAproc proc;

	proc = n_syn->dma(&state);

	proc(g_Mp3Vars.romaddr + g_Mp3Vars.var8009c3c4, 0x400, 0);
}
