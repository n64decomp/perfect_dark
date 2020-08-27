#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_0f09f0.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_176080.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f16cfa0
/*  f16cfa0:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x4b4)
/*  f16cfa4:	8dcea474 */ 	lw	$t6,%lo(g_Vars+0x4b4)($t6)
/*  f16cfa8:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f16cfac:	3c028008 */ 	lui	$v0,%hi(var800840ec)
/*  f16cfb0:	15c10003 */ 	bne	$t6,$at,.L0f16cfc0
/*  f16cfb4:	00000000 */ 	nop
/*  f16cfb8:	03e00008 */ 	jr	$ra
/*  f16cfbc:	24025000 */ 	addiu	$v0,$zero,0x5000
.L0f16cfc0:
/*  f16cfc0:	944240ec */ 	lhu	$v0,%lo(var800840ec)($v0)
/*  f16cfc4:	24035000 */ 	addiu	$v1,$zero,0x5000
/*  f16cfc8:	28415000 */ 	slti	$at,$v0,0x5000
/*  f16cfcc:	10200003 */ 	beqz	$at,.L0f16cfdc
/*  f16cfd0:	00000000 */ 	nop
/*  f16cfd4:	10000001 */ 	b	.L0f16cfdc
/*  f16cfd8:	00401825 */ 	or	$v1,$v0,$zero
.L0f16cfdc:
/*  f16cfdc:	3062ffff */ 	andi	$v0,$v1,0xffff
/*  f16cfe0:	03e00008 */ 	jr	$ra
/*  f16cfe4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f16cfe8
/*  f16cfe8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f16cfec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f16cff0:	3096ffff */ 	andi	$s6,$a0,0xffff
/*  f16cff4:	2ac15001 */ 	slti	$at,$s6,0x5001
/*  f16cff8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f16cffc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f16d000:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f16d004:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f16d008:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f16d00c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f16d010:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16d014:	14200002 */ 	bnez	$at,.L0f16d020
/*  f16d018:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f16d01c:	24165000 */ 	addiu	$s6,$zero,0x5000
.L0f16d020:
/*  f16d020:	3c11800b */ 	lui	$s1,%hi(var800aaa38)
/*  f16d024:	3c138009 */ 	lui	$s3,%hi(var80094ed8)
/*  f16d028:	26734ed8 */ 	addiu	$s3,$s3,%lo(var80094ed8)
/*  f16d02c:	2631aa38 */ 	addiu	$s1,$s1,%lo(var800aaa38)
/*  f16d030:	00008025 */ 	or	$s0,$zero,$zero
/*  f16d034:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f16d038:	24140108 */ 	addiu	$s4,$zero,0x108
/*  f16d03c:	24120005 */ 	addiu	$s2,$zero,0x5
.L0f16d040:
/*  f16d040:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f16d044:	5040000a */ 	beqzl	$v0,.L0f16d070
/*  f16d048:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d04c:	52420008 */ 	beql	$s2,$v0,.L0f16d070
/*  f16d050:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d054:	02140019 */ 	multu	$s0,$s4
/*  f16d058:	32c5ffff */ 	andi	$a1,$s6,0xffff
/*  f16d05c:	00007012 */ 	mflo	$t6
/*  f16d060:	026e2021 */ 	addu	$a0,$s3,$t6
/*  f16d064:	0c003f67 */ 	jal	func0000fd9c
/*  f16d068:	00000000 */ 	nop
/*  f16d06c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f16d070:
/*  f16d070:	1615fff3 */ 	bne	$s0,$s5,.L0f16d040
/*  f16d074:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f16d078:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f16d07c:	3c018008 */ 	lui	$at,%hi(var800840ec)
/*  f16d080:	a43640ec */ 	sh	$s6,%lo(var800840ec)($at)
/*  f16d084:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f16d088:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16d08c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f16d090:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16d094:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f16d098:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f16d09c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f16d0a0:	03e00008 */ 	jr	$ra
/*  f16d0a4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f16d0a8
/*  f16d0a8:	3c03800b */ 	lui	$v1,%hi(var800aaa38)
/*  f16d0ac:	3c07800b */ 	lui	$a3,%hi(var800aaa68)
/*  f16d0b0:	24e7aa68 */ 	addiu	$a3,$a3,%lo(var800aaa68)
/*  f16d0b4:	2463aa38 */ 	addiu	$v1,$v1,%lo(var800aaa38)
/*  f16d0b8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f16d0bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f16d0c0:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f16d0c4:
/*  f16d0c4:	548e0012 */ 	bnel	$a0,$t6,.L0f16d110
/*  f16d0c8:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d0cc:	50a00008 */ 	beqzl	$a1,.L0f16d0f0
/*  f16d0d0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f16d0d4:	10a20009 */ 	beq	$a1,$v0,.L0f16d0fc
/*  f16d0d8:	00000000 */ 	nop
/*  f16d0dc:	10a60009 */ 	beq	$a1,$a2,.L0f16d104
/*  f16d0e0:	00000000 */ 	nop
/*  f16d0e4:	1000000a */ 	b	.L0f16d110
/*  f16d0e8:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d0ec:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f16d0f0:
/*  f16d0f0:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f16d0f4:	03e00008 */ 	jr	$ra
/*  f16d0f8:	01e01025 */ 	or	$v0,$t7,$zero
.L0f16d0fc:
/*  f16d0fc:	03e00008 */ 	jr	$ra
/*  f16d100:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f16d104:
/*  f16d104:	03e00008 */ 	jr	$ra
/*  f16d108:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f16d10c:	24630010 */ 	addiu	$v1,$v1,0x10
.L0f16d110:
/*  f16d110:	5467ffec */ 	bnel	$v1,$a3,.L0f16d0c4
/*  f16d114:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f16d118:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d11c:	03e00008 */ 	jr	$ra
/*  f16d120:	00000000 */ 	nop
);

s32 func0f16d124(s32 arg0)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].unk00 == arg0) {
			if (var800aaa38[i].unk08) {
				return 2;
			}

			if (var800aaa38[i].unk04) {
				return 1;
			}
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f16d180
/*  f16d180:	3c02800b */ 	lui	$v0,%hi(var800aaa38)
/*  f16d184:	2442aa38 */ 	addiu	$v0,$v0,%lo(var800aaa38)
/*  f16d188:	00001825 */ 	or	$v1,$zero,$zero
/*  f16d18c:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f16d190:
/*  f16d190:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f16d194:	548e0004 */ 	bnel	$a0,$t6,.L0f16d1a8
/*  f16d198:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f16d19c:	03e00008 */ 	jr	$ra
/*  f16d1a0:	00601025 */ 	or	$v0,$v1,$zero
/*  f16d1a4:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f16d1a8:
/*  f16d1a8:	1465fff9 */ 	bne	$v1,$a1,.L0f16d190
/*  f16d1ac:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f16d1b0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16d1b4:	03e00008 */ 	jr	$ra
/*  f16d1b8:	00000000 */ 	nop
);

void func0f16d1bc(u32 arg0, u32 tracknum, f32 arg2, u16 volume)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
		var800aa5d8[var800840c4].tracknum = tracknum;
		var800aa5d8[var800840c4].unk0c = arg2;
		var800aa5d8[var800840c4].volume = volume;
		var800aa5d8[var800840c4].unk12 = 1;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d240(s32 arg0)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
		var800aa5d8[var800840c4].unk12 = 2;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d2ac(s32 arg0, f32 arg1, s32 arg2)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
		var800aa5d8[var800840c4].unk0c = arg1;
		var800aa5d8[var800840c4].unk08 = arg2;
		var800aa5d8[var800840c4].unk12 = 3;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d324(void)
{
	s32 i;

	if (var8005dda0 == 0) {
		for (i = 0; i < 4; i++) {
			var800aaa68[i] = 0;
			var800aaa78[i] = 0;
			var800aaa88[i] = 0;
		}

		func0f16d430();
		func0f16d3d0();
		func0f16d44c();

		var800840e8 = 0;
		var800840f0 = 0;
		g_AudioCurrentBgMusicNum = -1;
		var800840c8 = -1;
		var800840cc = -1;
		var800840d8 = 0;
	}
}

void func0f16d3d0(void)
{
	var800aa5d8[0].unk00 = 6;
	var800aa5d8[0].unk12 = 4;
	var800aa5d8[0].unk14 = var800840d4++;
	var800aa5d8[0].unk18 = 0;
	var800aa5d8[0].unk16 = 0;

	var800840c4 = 1;

	func0001190c();
}

void func0f16d430(void)
{
	var800840d0 = var800840e0;
	var800840e0 = 0;
}

void func0f16d44c(void)
{
	var800aa5d8[var800840c4].unk00 = 6;
	var800aa5d8[var800840c4].unk12 = 5;
	var800aa5d8[var800840c4].unk14 = var800840d4++;
	var800aa5d8[var800840c4].tracknum = var800840d0;
	var800840c4++;

	var800aa5d8[0].unk18 = 0;
	var800aa5d8[0].unk16 = 0;
}

#define TRACKNUM2() (var800840c8 != -1 ? var800840c8 : func0f176c40(var800aa5d0))

void func0f16d4b8(f32 arg0)
{
	if (TRACKNUM2() >= 0) {
		func0f16d1bc(1, TRACKNUM2(), arg0, func0f16cfa0());
	}
}

#define TRACKNUM() (var800840cc != -1 ? var800840cc : func0f176cd8(var800aa5d0))

void func0f16d548(f32 arg0)
{
	s32 pass = false;

	if (TRACKNUM() >= 0) {
		if (var800840cc != -1) {
			pass = true;
		} else if (audioIsAnyPlayerInRoomWithFlag4000()) {
			if (g_Vars.tickmode != TICKMODE_6 && TRACKNUM() != func0f176cd8(var800aa5d0)) {
				func0f16d240(5);
				audioSetAuxTrack(func0f176cd8(var800aa5d0));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		pass = func0f16d124(5);

		if (pass == 0 || pass == 2) {
			func0f16d1bc(5, TRACKNUM(), arg0, VOLUME(g_SfxVolume));
		}
	}
}

bool audioIsAnyPlayerInRoomWithFlag4000(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_6) {
		return false;
	}

	if (soloIsPaused()) {
		return false;
	}

	if (var800840e8) {
		return false;
	}

	if (var800840d8 && var800840dc) {
		return false;
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (g_Vars.players[i]->prop
				&& g_Vars.players[i]->prop->rooms
				&& g_Vars.players[i]->prop->rooms[0] != -1) {
			bool hasflag;

			if (g_Rooms[g_Vars.players[i]->prop->rooms[0]].flags & ROOMFLAG_4000) {
				hasflag = true;
			} else {
				hasflag = false;
			}

			if (hasflag) {
				return true;
			}
		}
	}

	return false;
}

void func0f16d89c(f32 arg0)
{
	func0f16d1bc(2, func0f176d20(var800aa5d0), arg0, func0f16cfa0());
}

void func0f16d8e0(f32 arg0)
{
	func0f16d1bc(3, menuChooseMusic(), arg0, func0f16cfa0());
}

void audioSetBgMusic(s32 tracknum)
{
	if (tracknum != g_AudioCurrentBgMusicNum) {
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(1, 0.5f, 1);
		func0f16d2ac(2, 0.5f, 1);
		func0f16d2ac(5, 0.5f, 1);
		func0f16d1bc(3, tracknum, 0, func0f16cfa0());
	}

	g_AudioCurrentBgMusicNum = tracknum;
}

void func0f16d9a8(s32 stagenum)
{
	var800aa5d0 = stagenum;

	func0f16d4b8(0);

	if (func0f176cd8(var800aa5d0) >= 0) {
		func0f16d548(0);
	}
}

void func0f16d9f0(s32 stagenum)
{
	var800aa5d0 = stagenum;
}

void func0f16d9fc(void)
{
	func0f16d430();
	func0f16d3d0();
	func0f16d44c();
}

void func0f16da2c(void)
{
	if (var800840d8 == 0 && func0f176d20(var800aa5d0) >= 0) {
		func0f16d240(2);
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(1, 0.5, 1);
		func0f16d89c(0);

		var800840d8 = 1;
	}
}

void func0f16daa4(void)
{
	if (var800840d8) {
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(2, 1, 0);

		if (g_Vars.unk0004c8 == 0) {
			func0f16d4b8(0.5);
		}

		var800840d8 = 0;
	}
}

void audioSetBgMusicForMenu(void)
{
	audioSetBgMusic(menuChooseMusic());
}

void func0f16db3c(void)
{
	func0f16d2ac(3, 1, 0);

	if (func0f16d0a8(2, 1)) {
		func0f16d89c(1);
	} else {
		func0f16d4b8(1);
	}

	g_AudioCurrentBgMusicNum = -1;
}

void audioPlaySoloDeathTrack(void)
{
	var800840e8 = 1;

	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);
	func0f16d240(5);
	func0f16d1bc(1, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > func0f16cfa0() ? VOLUME(g_SfxVolume) : func0f16cfa0());
	func0f16d44c();
}

void audioPlayMpDeathTrack(f32 arg0)
{
	func0f16d430();
	func0f16d1bc(4, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > func0f16cfa0() ? VOLUME(g_SfxVolume) : func0f16cfa0());
	func0f16d44c();
}

void func0f16dd14(void)
{
	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	func0f16d240(5);

	if (var800840d8) {
		func0f16d2ac(2, 0.1f, 1);
	} else {
		func0f16d2ac(1, 0.1f, 1);
	}

	audioPlayMpDeathTrack(0);
	var800840f0 = 1200;
	var800840dc = 1;
	func0f16d44c();
}

void func0f16ddb0(void)
{
	func0f16d2ac(4, 2, 0);

	if (var800840d8) {
		func0f16d89c(2);
	} else {
		func0f16d4b8(2);
	}

	var800840dc = 0;
}

void audioPlayTrack(s32 tracknum)
{
	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);
	func0f16d240(5);
	func0f16d1bc(1, tracknum, 0, func0f16cfa0());
	func0f16d44c();
}

void audioRestartTrack(void)
{
	func0f16d240(1);
	func0f16d240(5);
	func0f16d4b8(0.5f);
}

void func0f16deb8(s32 tracknum)
{
	func0f16d240(1);

	var800840c8 = tracknum;

	func0f16d4b8(0.5f);
}

void audioSetTrack(s32 tracknum)
{
	u32 volume;

	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);

	if (g_SfxVolume < func0f16cfa0()) {
		volume = func0f16cfa0();
	} else {
		volume = g_SfxVolume;
	}

	func0f16d1bc(1, tracknum, 0, volume);

	g_Vars.unk0004c8 = 1;
}

void audioRestartDefaultTrack(void)
{
	g_Vars.unk0004c8 = 0;

	if (var800624a4 == 0) {
		func0f16d240(1);
		func0f16d240(5);
		func0f16d4b8(0.5f);
	}
}

void audioSetAuxTrack(s32 tracknum)
{
	var800840cc = tracknum;
	func0f16d240(5);

	func0f16d1bc(5, tracknum, 0, VOLUME(g_SfxVolume));
}

void audioRestartAuxTrack(void)
{
	var800840cc = -1;
	func0f16d240(5);
}

void audioPlayXTrack(s32 index, u32 arg1, u32 duration)
{
	if (var800aaa68[index] == false) {
		var800aaa68[index] = true;
		var800aaa78[index] = arg1 * 240;
		var800aaa88[index] = duration * 240;
	}
}

void audioStopTrack(s32 index)
{
	s32 i;

	if (index >= 0) {
		var800aaa68[index] = false;
	} else {
		for (i = 0; i < 4; i++) {
			var800aaa68[i] = false;
			var800aaa78[i] = 0;
			var800aaa88[i] = 0;
		}

		if (var800840d8) {
			func0f16daa4();
		}
	}
}

void func0f16e138(void)
{
	if (var800840cc == -1) {
		if (audioIsAnyPlayerInRoomWithFlag4000()) {
			func0f16d548(1);
		} else if (func0f16d124(5) == 1) {
			func0f16d2ac(5, 1, 1);
		}
	} else {
		if (func0f176cd8(var800aa5d0) >= 0) {
			func0f16d548(1);
		}
	}
}

void func0f16e1cc(void)
{
	// empty
}
