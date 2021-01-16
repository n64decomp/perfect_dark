#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/inventory/items.h"
#include "game/game_006bd0.h"
#include "game/title.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096750.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0abe70.h"
#include "game/game_0b0420.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0d5a90.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/explosions/explosions.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_1668e0.h"
#include "game/gfxmemory.h"
#include "game/core.h"
#include "game/music.h"
#include "game/game_16e810.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/training/training.h"
#include "game/training/training.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/pak/pak.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "gvars/gvars.h"
#include "lib/lib_04320.h"
#include "lib/lib_04840.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/memory.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ad160[] = "ACOUSTIC -> Allocating %d bytes for %d portal AV structures\n";
const char var7f1ad1a0[] = "ACOUSTIC -> DGD WARNING: portalAVInit no portals!\n";
const char var7f1ad1d4[] = "ACOUSTIC -> portalAVReset: checking propobj type %d\n";
const char var7f1ad20c[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOWFADE for portal %d\n";
const char var7f1ad250[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOW for portal %d\n";
const char var7f1ad290[] = "ACOUSTIC -> Portal %3d - A=%.2f, V=%.2f\n";
const char var7f1ad2bc[] = "ACOUSTIC -> DGD WARNING: portalAVReset no portals!\n";
const char var7f1ad2f0[] = "Acoustic Reset -> Allocating %d bytes for %d roomacousticdata structures\n";
const char var7f1ad33c[] = "ACOUSTIC ->    room %d bb %f %f\n";
const char var7f1ad360[] = "ACOUSTIC -> DGD: acousticReset room %d does not have a 3D bounding box => radata[room].roomvolume is bodged!\n";
const char var7f1ad3d0[] = "%s%sL2 -> Surface area bodged for room %d - using %f\n";
const char var7f1ad408[] = "";
const char var7f1ad40c[] = "";

void func0f0b63b0(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(255 * frac);
		value <<= 0;
		var8009ddc8[portalnum] = (var8009ddc8[portalnum] & 0xff00) | value;
	}
}

void func0f0b6470(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(15 * frac) & 0xf;
		var8009ddc8[portalnum] = (var8009ddc8[portalnum] & 0xf0ff) | (value << 8);
	}
}

f32 func0f0b6534(s32 arg0)
{
	f32 value = (var8009ddc8[arg0] & 0xff) * 0.0039215688593686f;

	return value;
}

f32 func0f0b656c(s32 arg0)
{
	f32 value = ((var8009ddc8[arg0] & 0xf00) >> 8) * 0.06666667f;

	return value;
}

void func0f0b65a8(s32 arg0)
{
	if (arg0 > 0) {
		var8009ddcc = arg0;
		var8009ddc8 = malloc(ALIGN16(arg0 * 2), MEMPOOL_STAGE);
	} else {
		var8009ddc8 = NULL;
	}
}

void func0f0b65f8(void)
{
	if (var8009ddc8) {
		struct prop *prop;
		s32 i;

		for (i = 0; i < var8009ddcc; i++) {
			func0f0b6470(i, 1);
			func0f0b63b0(i, 1);
		}

		prop = g_Vars.list1head;

		while (prop) {
			if (prop->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (obj->type == OBJTYPE_TINTEDGLASS) {
						struct tintedglassobj *glass = (struct tintedglassobj *)obj;

						if (glass->portalnum >= 0) {
							func0f0b6470(glass->portalnum, 0);
						}
					} else if (obj->type == OBJTYPE_GLASS) {
						struct glassobj *glass = (struct glassobj *)obj;

						if (glass->portalnum >= 0) {
							func0f0b6470(glass->portalnum, 0);
						}
					}
				}
			}

			prop = prop->next;
		}

		for (i = 0; i < var8009ddcc; i++) {
			func0f0b656c(i);
			func0f0b6534(i);
		}
	}
}

GLOBAL_ASM(
glabel acousticReset
.late_rodata
glabel var7f1ad418
.word 0x4b989680
.text
/*  f0b6764:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0b6768:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0b676c:	8d6402bc */ 	lw	$a0,0x2bc($t3)
/*  f0b6770:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0b6774:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b6778:	00047100 */ 	sll	$t6,$a0,0x4
/*  f0b677c:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f0b6780:	348f000f */ 	ori	$t7,$a0,0xf
/*  f0b6784:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0b6788:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0b678c:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0b6790:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f0b6794:	0c0048f2 */ 	jal	malloc
/*  f0b6798:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b679c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0b67a0:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0b67a4:	8d6302bc */ 	lw	$v1,0x2bc($t3)
/*  f0b67a8:	3c07800a */ 	lui	$a3,%hi(g_RoomAcousticData)
/*  f0b67ac:	24e7dd70 */ 	addiu	$a3,$a3,%lo(g_RoomAcousticData)
/*  f0b67b0:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0b67b4:	18600066 */ 	blez	$v1,.L0f0b6950
/*  f0b67b8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b67bc:	3c017f1b */ 	lui	$at,%hi(var7f1ad418)
/*  f0b67c0:	c438d418 */ 	lwc1	$f24,%lo(var7f1ad418)($at)
/*  f0b67c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b67c8:	4481b000 */ 	mtc1	$at,$f22
/*  f0b67cc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0b67d0:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f0b67d4:	44817000 */ 	mtc1	$at,$f14
/*  f0b67d8:	44808000 */ 	mtc1	$zero,$f16
/*  f0b67dc:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f0b67e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b67e4:	240c008c */ 	addiu	$t4,$zero,0x8c
/*  f0b67e8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f0b67ec:	8cf90000 */ 	lw	$t9,0x0($a3)
.L0f0b67f0:
/*  f0b67f0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b67f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b67f8:	03256821 */ 	addu	$t5,$t9,$a1
/*  f0b67fc:	e5b6000c */ 	swc1	$f22,0xc($t5)
/*  f0b6800:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b6804:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0b6808:	e5f60000 */ 	swc1	$f22,0x0($t7)
/*  f0b680c:	0006c8c0 */ 	sll	$t9,$a2,0x3
.L0f0b6810:
/*  f0b6810:	0326c821 */ 	addu	$t9,$t9,$a2
/*  f0b6814:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f0b6818:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0b681c:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f0b6820:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0b6824:	03196821 */ 	addu	$t5,$t8,$t9
/*  f0b6828:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0b682c:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f0b6830:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f0b6834:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b6838:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0b683c:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0b6840:	00000000 */ 	nop
/*  f0b6844:	45020009 */ 	bc1fl	.L0f0b686c
/*  f0b6848:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b684c:	460e1283 */ 	div.s	$f10,$f2,$f14
/*  f0b6850:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b6854:	01c51021 */ 	addu	$v0,$t6,$a1
/*  f0b6858:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0b685c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0b6860:	10000002 */ 	b	.L0f0b686c
/*  f0b6864:	e444000c */ 	swc1	$f4,0xc($v0)
/*  f0b6868:	00002025 */ 	or	$a0,$zero,$zero
.L0f0b686c:
/*  f0b686c:	546affe8 */ 	bnel	$v1,$t2,.L0f0b6810
/*  f0b6870:	0006c8c0 */ 	sll	$t9,$a2,0x3
/*  f0b6874:	5080002e */ 	beqzl	$a0,.L0f0b6930
/*  f0b6878:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b687c:	00cc0019 */ 	multu	$a2,$t4
/*  f0b6880:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f0b6884:	0000c012 */ 	mflo	$t8
/*  f0b6888:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0b688c:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f0b6890:	c4420024 */ 	lwc1	$f2,0x24($v0)
/*  f0b6894:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b6898:	00000000 */ 	nop
/*  f0b689c:	45020004 */ 	bc1fl	.L0f0b68b0
/*  f0b68a0:	46001481 */ 	sub.s	$f18,$f2,$f0
/*  f0b68a4:	10000003 */ 	b	.L0f0b68b4
/*  f0b68a8:	46001481 */ 	sub.s	$f18,$f2,$f0
/*  f0b68ac:	46001481 */ 	sub.s	$f18,$f2,$f0
.L0f0b68b0:
/*  f0b68b0:	46009487 */ 	neg.s	$f18,$f18
.L0f0b68b4:
/*  f0b68b4:	c440001c */ 	lwc1	$f0,0x1c($v0)
/*  f0b68b8:	c4420028 */ 	lwc1	$f2,0x28($v0)
/*  f0b68bc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b68c0:	00000000 */ 	nop
/*  f0b68c4:	45020004 */ 	bc1fl	.L0f0b68d8
/*  f0b68c8:	46001501 */ 	sub.s	$f20,$f2,$f0
/*  f0b68cc:	10000003 */ 	b	.L0f0b68dc
/*  f0b68d0:	46001501 */ 	sub.s	$f20,$f2,$f0
/*  f0b68d4:	46001501 */ 	sub.s	$f20,$f2,$f0
.L0f0b68d8:
/*  f0b68d8:	4600a507 */ 	neg.s	$f20,$f20
.L0f0b68dc:
/*  f0b68dc:	c4400020 */ 	lwc1	$f0,0x20($v0)
/*  f0b68e0:	c442002c */ 	lwc1	$f2,0x2c($v0)
/*  f0b68e4:	46149182 */ 	mul.s	$f6,$f18,$f20
/*  f0b68e8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b68ec:	00000000 */ 	nop
/*  f0b68f0:	45020004 */ 	bc1fl	.L0f0b6904
/*  f0b68f4:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0b68f8:	10000003 */ 	b	.L0f0b6908
/*  f0b68fc:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0b6900:	46001301 */ 	sub.s	$f12,$f2,$f0
.L0f0b6904:
/*  f0b6904:	46006307 */ 	neg.s	$f12,$f12
.L0f0b6908:
/*  f0b6908:	460c9202 */ 	mul.s	$f8,$f18,$f12
/*  f0b690c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0b6910:	460ca102 */ 	mul.s	$f4,$f20,$f12
/*  f0b6914:	03256821 */ 	addu	$t5,$t9,$a1
/*  f0b6918:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0b691c:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0b6920:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0b6924:	10000004 */ 	b	.L0f0b6938
/*  f0b6928:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*  f0b692c:	8cee0000 */ 	lw	$t6,0x0($a3)
.L0f0b6930:
/*  f0b6930:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0b6934:	e5f80000 */ 	swc1	$f24,0x0($t7)
.L0f0b6938:
/*  f0b6938:	8d6302bc */ 	lw	$v1,0x2bc($t3)
/*  f0b693c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b6940:	24a50010 */ 	addiu	$a1,$a1,0x10
/*  f0b6944:	00c3082a */ 	slt	$at,$a2,$v1
/*  f0b6948:	5420ffa9 */ 	bnezl	$at,.L0f0b67f0
/*  f0b694c:	8cf90000 */ 	lw	$t9,0x0($a3)
.L0f0b6950:
/*  f0b6950:	44808000 */ 	mtc1	$zero,$f16
/*  f0b6954:	1860000f */ 	blez	$v1,.L0f0b6994
/*  f0b6958:	00004025 */ 	or	$t0,$zero,$zero
/*  f0b695c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b6960:	8cf80000 */ 	lw	$t8,0x0($a3)
.L0f0b6964:
/*  f0b6964:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0b6968:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0b696c:	e7300008 */ 	swc1	$f16,0x8($t9)
/*  f0b6970:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0b6974:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0b6978:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b697c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f0b6980:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f0b6984:	8d6e02bc */ 	lw	$t6,0x2bc($t3)
/*  f0b6988:	010e082a */ 	slt	$at,$t0,$t6
/*  f0b698c:	5420fff5 */ 	bnezl	$at,.L0f0b6964
/*  f0b6990:	8cf80000 */ 	lw	$t8,0x0($a3)
.L0f0b6994:
/*  f0b6994:	3c02800a */ 	lui	$v0,%hi(var8009dd78)
/*  f0b6998:	3c04800a */ 	lui	$a0,%hi(var8009ddc8)
/*  f0b699c:	2484ddc8 */ 	addiu	$a0,$a0,%lo(var8009ddc8)
/*  f0b69a0:	2442dd78 */ 	addiu	$v0,$v0,%lo(var8009dd78)
/*  f0b69a4:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f0b69a8:
/*  f0b69a8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b69ac:	a443fff8 */ 	sh	$v1,-0x8($v0)
/*  f0b69b0:	1444fffd */ 	bne	$v0,$a0,.L0f0b69a8
/*  f0b69b4:	e450fffc */ 	swc1	$f16,-0x4($v0)
/*  f0b69b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b69bc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0b69c0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0b69c4:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0b69c8:	03e00008 */ 	jr	$ra
/*  f0b69cc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatch: regalloc for range variable
//void acousticReset(void)
//{
//	s32 i;
//	s32 j;
//	u32 size = ALIGN16(g_Vars.roomcount * sizeof(struct roomacousticdata));
//	f32 range;
//	f32 width;
//	f32 height;
//	f32 depth;
//	f32 halfsurfacearea;
//
//	osSyncPrintf("Acoustic Reset -> Allocating %d bytes for %d roomacousticdata structures\n", size, g_Vars.roomcount);
//
//	g_RoomAcousticData = malloc(size, MEMPOOL_STAGE);
//
//	for (i = 0; i < g_Vars.roomcount; i++) {
//		bool allgood = true;
//
//		g_RoomAcousticData[i].roomvolume = 1;
//		g_RoomAcousticData[i].surfacearea = 1;
//
//		for (j = 0; j < 3; j++) {
//			osSyncPrintf("ACOUSTIC ->    room %d bb %f %f\n", i, g_Rooms[i].bbmin[j], g_Rooms[i].bbmax[j]);
//
//			range = g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j];
//
//			if (range > 0) {
//				g_RoomAcousticData[i].roomvolume *= range / 100;
//			} else {
//				osSyncPrintf("ACOUSTIC -> DGD: acousticReset room %d does not have a 3D bounding box => radata[room].roomvolume is bodged!\n", i);
//				allgood = false;
//			}
//		}
//
//		if (allgood) {
//			if (g_Rooms[i].bbmin[0] < g_Rooms[i].bbmax[0]) {
//				width = g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0];
//			} else {
//				width = -(g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0]);
//			}
//
//			if (g_Rooms[i].bbmin[1] < g_Rooms[i].bbmax[1]) {
//				height = g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1];
//			} else {
//				height = -(g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1]);
//			}
//
//			if (g_Rooms[i].bbmin[2] < g_Rooms[i].bbmax[2]) {
//				depth = g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2];
//			} else {
//				depth = -(g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2]);
//			}
//
//			halfsurfacearea = width * height + width * depth + height * depth;
//
//			g_RoomAcousticData[i].surfacearea = halfsurfacearea + halfsurfacearea;
//		} else {
//			osSyncPrintf("%s%sL2 -> Surface area bodged for room %d - using %f\n", "", "", i, 20000000);
//			g_RoomAcousticData[i].surfacearea = 20000000;
//		}
//	}
//
//	for (j = 0; j < g_Vars.roomcount; j++) {
//		g_RoomAcousticData[j].unk08 = 0;
//		g_RoomAcousticData[j].unk04 = g_RoomAcousticData[j].unk08;
//	}
//
//	for (j = 0; j < ARRAYCOUNT(var8009dd78); j++) {
//		var8009dd78[j].unk00 = -1;
//		var8009dd78[j].unk04 = 0;
//	}
//}
