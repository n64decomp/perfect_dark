#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u8 var8005ef20 = 254;

u8 var8009a4e0[456][2];

GLOBAL_ASM(
glabel func00017ce0
/*    17ce0:	3c03800a */ 	lui	$v1,%hi(g_BgPortals)
/*    17ce4:	8c634cc8 */ 	lw	$v1,%lo(g_BgPortals)($v1)
/*    17ce8:	000470c0 */ 	sll	$t6,$a0,0x3
/*    17cec:	3c013f80 */ 	lui	$at,0x3f80
/*    17cf0:	006e7821 */ 	addu	$t7,$v1,$t6
/*    17cf4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    17cf8:	44815000 */ 	mtc1	$at,$f10
/*    17cfc:	3c014f80 */ 	lui	$at,0x4f80
/*    17d00:	03031021 */ 	addu	$v0,$t8,$v1
/*    17d04:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*    17d08:	2443000c */ 	addiu	$v1,$v0,0xc
/*    17d0c:	24070001 */ 	addiu	$a3,$zero,0x1
/*    17d10:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*    17d14:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*    17d18:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17d1c:	c448000c */ 	lwc1	$f8,0xc($v0)
/*    17d20:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17d24:	90460000 */ 	lbu	$a2,0x0($v0)
/*    17d28:	44868000 */ 	mtc1	$a2,$f16
/*    17d2c:	04c10004 */ 	bgez	$a2,.L00017d40
/*    17d30:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    17d34:	44812000 */ 	mtc1	$at,$f4
/*    17d38:	00000000 */ 	nop
/*    17d3c:	46049480 */ 	add.s	$f18,$f18,$f4
.L00017d40:
/*    17d40:	28c10002 */ 	slti	$at,$a2,0x2
/*    17d44:	14200013 */ 	bnez	$at,.L00017d94
/*    17d48:	46125003 */ 	div.s	$f0,$f10,$f18
/*    17d4c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d50:
/*    17d50:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*    17d54:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*    17d58:	24e70001 */ 	addiu	$a3,$a3,0x1
/*    17d5c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d60:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*    17d64:	2463000c */ 	addiu	$v1,$v1,12
/*    17d68:	e4b00000 */ 	swc1	$f16,0x0($a1)
/*    17d6c:	c46afffc */ 	lwc1	$f10,-0x4($v1)
/*    17d70:	460a2480 */ 	add.s	$f18,$f4,$f10
/*    17d74:	e4b20004 */ 	swc1	$f18,0x4($a1)
/*    17d78:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*    17d7c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d80:	e4b00008 */ 	swc1	$f16,0x8($a1)
/*    17d84:	90590000 */ 	lbu	$t9,0x0($v0)
/*    17d88:	00f9082a */ 	slt	$at,$a3,$t9
/*    17d8c:	5420fff0 */ 	bnezl	$at,.L00017d50
/*    17d90:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d94:
/*    17d94:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    17d98:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*    17d9c:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    17da0:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    17da4:	00000000 */ 	nop
/*    17da8:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    17dac:	00000000 */ 	nop
/*    17db0:	46004402 */ 	mul.s	$f16,$f8,$f0
/*    17db4:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*    17db8:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17dbc:	03e00008 */ 	jr	$ra
/*    17dc0:	e4b00008 */ 	swc1	$f16,0x8($a1)
);

#if VERSION < VERSION_NTSC_1_0
bool portal00018e34nb(s32 portalnum)
{
	return g_BgPortals[portalnum].flags & PORTALFLAG_02;
}

void portal00018e54nb(s32 portalnum)
{
	g_BgPortals[portalnum].flags |= PORTALFLAG_02;
}

void portal00018e74nb(s32 portalnum)
{
	g_BgPortals[portalnum].flags &= (~PORTALFLAG_02 & 0xff);
}
#endif

/**
 * Add roomnum to the rooms list, provided it's not already there and there's
 * space available at the end of the list.
 *
 * The list is assumed to have 16 slots, with the last being reserved for the
 * -1 terminator.
 */
void portal00017dc4(s16 *rooms, s16 roomnum)
{
	s32 i;

	for (i = 0; i < 16 && rooms[i] != -1; i++) {
		if (rooms[i] == roomnum) {
			return;
		}
	}

	if (i < 15) {
		rooms[i] = roomnum;
		rooms[i + 1] = -1;
	}
}

s32 portal00017e30(s32 portalnum, struct coord *arg1, struct coord *arg2)
{
	s32 i;
	struct coord sp60;
	struct portalvertices *pvertices;
	struct coord *curr;
	struct coord *next;
	struct coord sp48;
	u8 lastside;
	f32 sp40[1];
	struct coord sp34;
	f32 value1;
	f32 value2;
	f32 tmp;
	u32 stack;

	lastside = 0;
	pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	value1 = arg1->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg1->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg1->f[2] * (var800a4ccc + portalnum)->coord.f[2];
	value2 = arg2->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg2->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg2->f[2] * (var800a4ccc + portalnum)->coord.f[2];

	if (value1 < (var800a4ccc + portalnum)->unk0c) {
		if (value2 < (var800a4ccc + portalnum)->unk0c) {
			return 0;
		}
	} else if ((var800a4ccc + portalnum)->unk10 < value1 && (var800a4ccc + portalnum)->unk10 < value2) {
		return 0;
	}

	sp60.f[0] = arg2->f[0] - arg1->f[0];
	sp60.f[1] = arg2->f[1] - arg1->f[1];
	sp60.f[2] = arg2->f[2] - arg1->f[2];

	var8007fcb4 = (value1 + value2) * 0.5f - (var800a4ccc + portalnum)->unk0c;

	curr = &pvertices->vertices[0];
	next = &pvertices->vertices[1];

	for (i = 0; i < pvertices->count; i++) {
		if (i + 1 == pvertices->count) {
			next = &pvertices->vertices[0];
		}

		sp48.f[0] = next->f[0] - curr->f[0];
		sp48.f[1] = next->f[1] - curr->f[1];
		sp48.f[2] = next->f[2] - curr->f[2];

		sp34.f[0] = sp48.f[1] * sp60.f[2] - sp48.f[2] * sp60.f[1];
		sp34.f[1] = sp48.f[2] * sp60.f[0] - sp48.f[0] * sp60.f[2];
		sp34.f[2] = sp48.f[0] * sp60.f[1] - sp48.f[1] * sp60.f[0];

		tmp = sp34.f[0] * sp34.f[0] + sp34.f[1] * sp34.f[1] + sp34.f[2] * sp34.f[2];

		if (tmp == 0.0f) {
			return 0;
		}

		sp40[0] = sp34.f[0] * curr->f[0] + sp34.f[1] * curr->f[1] + sp34.f[2] * curr->f[2];
		tmp = sp34.f[0] * arg1->f[0] + sp34.f[1] * arg1->f[1] + sp34.f[2] * arg1->f[2];

		if (tmp < sp40[0]) {
			if (lastside == 2) {
				return 0;
			}

			lastside = 1;
		} else {
			if (lastside == 1) {
				return 0;
			}

			lastside = 2;
		}

		curr++;
		next++;
	}

	return (value1 < (var800a4ccc + portalnum)->unk0c) ? 1 : 2;
}

void portal00018148(struct coord *pos1, struct coord *pos2, s16 *rooms1, s16 *rooms2, s16 *rooms3, s32 arg5)
{
	s32 i;
	s32 j;
	s32 roomnum;
	s32 numportals;
	s16 *portalnums;
	s16 rooms9c[16];
	s16 rooms7c[16];
	s16 rooms5c[16];

	for (i = 0; i < 8; i++) {
		rooms9c[i] = rooms1[i];
		rooms5c[i] = rooms1[i];

		if (rooms1[i] == -1) {
			break;
		}
	}

	var8005ef20++;

	if (var8005ef20 == 255) {
		for (i = 0; i < g_NumPortalThings; i++) {
			var8009a4e0[i][0] = 0xff;
		}

		var8005ef20 = 0;
	}

	do {
		rooms7c[0] = -1;

		for (j = 0; (roomnum = rooms9c[j]) != -1 && j < 16; j++) {
			numportals = g_Rooms[roomnum].numportals;
			portalnums = &g_RoomPortals[g_Rooms[roomnum].roomportallistoffset];

			for (i = 0; i < numportals; i++) {
				s32 portalnum = *portalnums;
				u8 *s1 = var8009a4e0[portalnum];

				if (s1[0] != var8005ef20) {
					s1[0] = var8005ef20;
					s1[1] = portal00017e30(portalnum, pos1, pos2);
				}

				if (s1[1] != 0) {
					if (s1[1] == 1) {
						if (roomnum == g_BgPortals[portalnum].roomnum1) {
							portal00017dc4(rooms7c, g_BgPortals[portalnum].roomnum2);
							portal00017dc4(rooms5c, g_BgPortals[portalnum].roomnum2);
							s1[1] = 0;
						}
					}

					if (s1[1] == 2) {
						if (roomnum == g_BgPortals[portalnum].roomnum2) {
							portal00017dc4(rooms7c, g_BgPortals[portalnum].roomnum1);
							portal00017dc4(rooms5c, g_BgPortals[portalnum].roomnum1);
							s1[1] = 0;
						}
					}
				}

				portalnums++;
			}
		}

		if (rooms7c[0] == -1) {
			break;
		}

		for (i = 0; i < 16; i++) {
			rooms9c[i] = rooms7c[i];

			if (rooms7c[i] == -1) {
				break;
			}
		}
	} while (rooms7c[0] != -1);

	for (i = 0; i < 7 && rooms9c[i] != -1; i++) {
		rooms2[i] = rooms9c[i];
	}

	rooms2[i] = -1;

	if (rooms3 != NULL) {
		for (i = 0; i < arg5; i++) {
			rooms3[i] = rooms5c[i];

			if (rooms5c[i] == -1) {
				break;
			}
		}

		rooms3[i] = -1;
	}
}
