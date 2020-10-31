#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/pak/pak.h"
#include "gvars/gvars.h"
#include "lib/lib_04a80.h"
#include "lib/main.h"
#include "lib/lib_13900.h"
#include "lib/lib_4f5e0.h"
#include "types.h"

const char var70054080[] = "joyReset\n";
const char var7005408c[] = "joyReset: doing nothing\n";
const char var700540a8[] = "debugjoy";
const char var700540b4[] = "JOY : g_EnableCyclicPolling=%d";
const char var700540d4[] = "JOY : g_JoyReCheckInterval=%d";
const char var700540f4[] = "JOY : g_JoyReCheckEventIn=%d";
const char var70054114[] = "JOY : g_JoyRecheckDone=%d";
const char var70054130[] = "osContStartReadData -> Failed - CONT_NO_RESPONSE_ERROR\n";
const char var70054168[] = "osContStartReadData -> Failed - CONT_OVERRUN_ERROR\n";
const char var7005419c[] = "joyTickRetrace:joy%derrno%d->%d\n";
const char var700541c0[] = "joyTickRetrace:joy%derrno%d->%d\n";

const u32 var700541e4[] = {0x700156a4};
const u32 var700541e8[] = {0x700156d8};
const u32 var700541ec[] = {0x700157a8};
const u32 var700541f0[] = {0x700157d8};
const u32 var700541f4[] = {0x7001581c};
const u32 var700541f8[] = {0x7001580c};
const u32 var700541fc[] = {0x00000000};

struct contdata *var8005ee60 = &var80099a60[0];
bool g_ContBusy = false;
u32 var8005ee68 = 0x00000000;
u32 var8005ee6c[4] = {0};
u32 var8005ee7c[4] = {0};
u32 var8005ee8c[4] = {0};
u32 var8005ee9c[4] = {0};
u8 g_ConnectedControllers = 0;
u32 var8005eeb0 = 0x00000000;
bool var8005eeb4 = false;
u32 var8005eeb8 = 0x00000001;
u32 var8005eebc = 0x00000000;
u32 var8005eec0 = 0x00000001;
u32 var8005eec4 = 0x00000000;
u32 var8005eec8 = 0x00000000;
s32 var8005eecc = 0;
u32 var8005eed0 = 0x00000000;
u32 var8005eed4 = 0x00000000;
u8 var8005eed8 = 0;
u32 var8005eedc = 0x00000001;
u32 var8005eee0 = 0x00000000;
u32 var8005eee4 = 0xffffffff;
u32 var8005eee8 = 0x00000000;
u32 var8005eeec = 0x00000000;
u32 var8005eef0 = 0x00000001;
u32 var8005eef4 = 0x00000000;
u32 var8005eef8 = 0x00000000;
u32 var8005eefc = 0x00000000;
u32 var8005ef00 = 0xff000000;

void func00013900(void)
{
	if (var8005eef0) {
		func000150e8();
		var8005eef0 = false;
	}
}

void func00013938(void)
{
	if (!var8005eef0) {
		func00015144();
		var8005eef0 = true;
	}
}

void func00013974(u32 value)
{
	var8005eeec = value;
}

u32 func00013980(void)
{
	return var8005eeec;
}

void func0001398c(s32 value)
{
	var8005eee4 = var8005eee0 = value * 11000;
}

void func000139c8(void)
{
	func0001398c(10);
}

/**
 * Remove an item from the beginning of the var80099f48 array,
 * shift the rest of the array back and return the removed item.
 */
s32 func000139e8(void)
{
	s32 result = 0;
	s32 i;

	if (var8005eecc) {
		result = var80099f48[0];

		if (var8005eecc > 1) {
			for (i = 0; i < var8005eecc; i++) {
				var80099f48[i] = var80099f48[i + 1];
			}

			var8005eecc--;
		}
	}

	return result;
}

void func00013a40(u8 arg0)
{
	if (var8005eecc + 1 >= 100) {
		func000139e8();
	}

	if (var8005eecc == 0 || arg0 != var80099f44[var8005eecc + 3]) {
		var80099f48[var8005eecc] = arg0;
		var8005eecc++;
	}
}

GLOBAL_ASM(
glabel func00013ab8
/*    13ab8:	3c0e8006 */ 	lui	$t6,%hi(var8005eedc)
/*    13abc:	8dceeedc */ 	lw	$t6,%lo(var8005eedc)($t6)
/*    13ac0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    13ac4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13ac8:	11c0005c */ 	beqz	$t6,.L00013c3c
/*    13acc:	00803825 */ 	or	$a3,$a0,$zero
/*    13ad0:	24010002 */ 	addiu	$at,$zero,0x2
/*    13ad4:	10810010 */ 	beq	$a0,$at,.L00013b18
/*    13ad8:	3c0f8006 */ 	lui	$t7,%hi(var8005eee0)
/*    13adc:	8defeee0 */ 	lw	$t7,%lo(var8005eee0)($t7)
/*    13ae0:	51e00057 */ 	beqzl	$t7,.L00013c40
/*    13ae4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13ae8:	1480000b */ 	bnez	$a0,.L00013b18
/*    13aec:	3c188006 */ 	lui	$t8,%hi(var8005eebc)
/*    13af0:	8f18eebc */ 	lw	$t8,%lo(var8005eebc)($t8)
/*    13af4:	3c198006 */ 	lui	$t9,%hi(var8005eef0)
/*    13af8:	3c088006 */ 	lui	$t0,%hi(var8005eeec)
/*    13afc:	13000004 */ 	beqz	$t8,.L00013b10
/*    13b00:	00000000 */ 	nop
/*    13b04:	8f39eef0 */ 	lw	$t9,%lo(var8005eef0)($t9)
/*    13b08:	5720004d */ 	bnezl	$t9,.L00013c40
/*    13b0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013b10:
/*    13b10:	8d08eeec */ 	lw	$t0,%lo(var8005eeec)($t0)
/*    13b14:	11000049 */ 	beqz	$t0,.L00013c3c
.L00013b18:
/*    13b18:	3c098006 */ 	lui	$t1,%hi(var8005eefc)
/*    13b1c:	8d29eefc */ 	lw	$t1,%lo(var8005eefc)($t1)
/*    13b20:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    13b24:	3c018006 */ 	lui	$at,%hi(var8005eefc)
/*    13b28:	15200044 */ 	bnez	$t1,.L00013c3c
/*    13b2c:	3c0b8006 */ 	lui	$t3,%hi(var8005eef4)
/*    13b30:	8d6beef4 */ 	lw	$t3,%lo(var8005eef4)($t3)
/*    13b34:	ac2aeefc */ 	sw	$t2,%lo(var8005eefc)($at)
/*    13b38:	3c018006 */ 	lui	$at,%hi(var8005eef8)
/*    13b3c:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13b40:	0c012144 */ 	jal	osGetCount
/*    13b44:	ac2beef8 */ 	sw	$t3,%lo(var8005eef8)($at)
/*    13b48:	3c0c8006 */ 	lui	$t4,%hi(var8005eef8)
/*    13b4c:	8d8ceef8 */ 	lw	$t4,%lo(var8005eef8)($t4)
/*    13b50:	3c068006 */ 	lui	$a2,%hi(var8005eee0)
/*    13b54:	8cc6eee0 */ 	lw	$a2,%lo(var8005eee0)($a2)
/*    13b58:	3c018006 */ 	lui	$at,%hi(var8005eef4)
/*    13b5c:	004c1823 */ 	subu	$v1,$v0,$t4
/*    13b60:	ac22eef4 */ 	sw	$v0,%lo(var8005eef4)($at)
/*    13b64:	00032202 */ 	srl	$a0,$v1,0x8
/*    13b68:	00062840 */ 	sll	$a1,$a2,0x1
/*    13b6c:	00a4082b */ 	sltu	$at,$a1,$a0
/*    13b70:	10200002 */ 	beqz	$at,.L00013b7c
/*    13b74:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13b78:	00a02025 */ 	or	$a0,$a1,$zero
.L00013b7c:
/*    13b7c:	3c038006 */ 	lui	$v1,%hi(var8005eee4)
/*    13b80:	2463eee4 */ 	addiu	$v1,$v1,%lo(var8005eee4)
/*    13b84:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    13b88:	24010002 */ 	addiu	$at,$zero,0x2
/*    13b8c:	3c028006 */ 	lui	$v0,%hi(var8005eee8)
/*    13b90:	01c47823 */ 	subu	$t7,$t6,$a0
/*    13b94:	05e00009 */ 	bltz	$t7,.L00013bbc
/*    13b98:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    13b9c:	10e10007 */ 	beq	$a3,$at,.L00013bbc
/*    13ba0:	24010001 */ 	addiu	$at,$zero,0x1
/*    13ba4:	14e10023 */ 	bne	$a3,$at,.L00013c34
/*    13ba8:	00000000 */ 	nop
/*    13bac:	05e10021 */ 	bgez	$t7,.L00013c34
/*    13bb0:	000fc023 */ 	negu	$t8,$t7
/*    13bb4:	00d8082a */ 	slt	$at,$a2,$t8
/*    13bb8:	1020001e */ 	beqz	$at,.L00013c34
.L00013bbc:
/*    13bbc:	2442eee8 */ 	addiu	$v0,$v0,%lo(var8005eee8)
/*    13bc0:	8c590000 */ 	lw	$t9,0x0($v0)
/*    13bc4:	a3a00027 */ 	sb	$zero,0x27($sp)
/*    13bc8:	27280001 */ 	addiu	$t0,$t9,0x1
/*    13bcc:	10e00004 */ 	beqz	$a3,.L00013be0
/*    13bd0:	ac480000 */ 	sw	$t0,0x0($v0)
/*    13bd4:	0c00543a */ 	jal	func000150e8
/*    13bd8:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13bdc:	8fa70030 */ 	lw	$a3,0x30($sp)
.L00013be0:
/*    13be0:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    13be4:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    13be8:	27a50027 */ 	addiu	$a1,$sp,0x27
/*    13bec:	0c0015dc */ 	jal	osPfsIsPlug
/*    13bf0:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13bf4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13bf8:	50e00005 */ 	beqzl	$a3,.L00013c10
/*    13bfc:	93a40027 */ 	lbu	$a0,0x27($sp)
/*    13c00:	0c005451 */ 	jal	func00015144
/*    13c04:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13c08:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13c0c:	93a40027 */ 	lbu	$a0,0x27($sp)
.L00013c10:
/*    13c10:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13c14:	34890010 */ 	ori	$t1,$a0,0x10
/*    13c18:	312400ff */ 	andi	$a0,$t1,0xff
/*    13c1c:	0c004e90 */ 	jal	func00013a40
/*    13c20:	a3a40027 */ 	sb	$a0,0x27($sp)
/*    13c24:	3c0b8006 */ 	lui	$t3,%hi(var8005eee0)
/*    13c28:	8d6beee0 */ 	lw	$t3,%lo(var8005eee0)($t3)
/*    13c2c:	3c018006 */ 	lui	$at,%hi(var8005eee4)
/*    13c30:	ac2beee4 */ 	sw	$t3,%lo(var8005eee4)($at)
.L00013c34:
/*    13c34:	3c018006 */ 	lui	$at,%hi(var8005eefc)
/*    13c38:	ac20eefc */ 	sw	$zero,%lo(var8005eefc)($at)
.L00013c3c:
/*    13c3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013c40:
/*    13c40:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    13c44:	03e00008 */ 	jr	$ra
/*    13c48:	00000000 */ 	nop
);

void func00013c4c(s8 index)
{
	u8 value = var8005eed8 & ~(1 << index);

	func00013a40(value);
}

void contSystemInit(void)
{
	s32 i;
	s32 j;

	osCreateMesgQueue(&var80099ec0, &var80099eb8, 1);
	osCreateMesgQueue(&var80099ee0, &var80099ed8, 1);
	osCreateMesgQueue(&var80099f00, &var80099ef8, 1);
	osCreateMesgQueue(&var80099f20, &var80099f18, 1);
	osCreateMesgQueue(&var80099e78, &var80099e90, 10);

	osSetEventMesg(OS_EVENT_SI, &var80099e78, NULL);

	var8005eeb0 = 1;
	var8005eec4 = 0;
	var8005eec8 = 0;

	for (i = 0; i < 2; i++) {
		var80099a60[i].newestindex = 0;
		var80099a60[i].oldestindex = 0;
		var80099a60[i].unk1e8 = 0;
		var80099a60[i].unk1ec = 0;
		var80099a60[i].unk200 = -1;

		for (j = 0; j < 4; j++) {
			var80099a60[i].samples[0].pads[j].button = 0;
			var80099a60[i].samples[0].pads[j].stick_x = 0;
			var80099a60[i].samples[0].pads[j].stick_y = 0;
			var80099a60[i].samples[0].pads[j].errno = 0;
		}
	}

	for (i = 0; i < 4; i++) {
		var80099e68[i] = 0;
	}
}

void func00013dd4(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var80099e68[i] = 60;
	}
}

void func00013dfc(void)
{
	OSMesg msg;

	if (var8005eeb0) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);

		func00013e84();

		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);

		var8005eec0 = 1;
	}
}

GLOBAL_ASM(
glabel func00013e84
/*    13e84:	3c028006 */ 	lui	$v0,%hi(var8005eeb8)
/*    13e88:	2442eeb8 */ 	addiu	$v0,$v0,%lo(var8005eeb8)
/*    13e8c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    13e90:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    13e94:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    13e98:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13e9c:	11c00018 */ 	beqz	$t6,.L00013f00
/*    13ea0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    13ea4:	3c11800a */ 	lui	$s1,%hi(var80099e78)
/*    13ea8:	3c058006 */ 	lui	$a1,%hi(g_ConnectedControllers)
/*    13eac:	3c06800a */ 	lui	$a2,%hi(var80099f38)
/*    13eb0:	26249e78 */ 	addiu	$a0,$s1,%lo(var80099e78)
/*    13eb4:	ac400000 */ 	sw	$zero,0x0($v0)
/*    13eb8:	24c69f38 */ 	addiu	$a2,$a2,%lo(var80099f38)
/*    13ebc:	0c012a60 */ 	jal	osContInit
/*    13ec0:	24a5eeac */ 	addiu	$a1,$a1,%lo(g_ConnectedControllers)
/*    13ec4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    13ec8:	3c018006 */ 	lui	$at,%hi(var8005eeb4)
/*    13ecc:	ac2feeb4 */ 	sw	$t7,%lo(var8005eeb4)($at)
/*    13ed0:	00008025 */ 	or	$s0,$zero,$zero
/*    13ed4:	24110004 */ 	addiu	$s1,$zero,0x4
/*    13ed8:	00102600 */ 	sll	$a0,$s0,0x18
.L00013edc:
/*    13edc:	0004c603 */ 	sra	$t8,$a0,0x18
/*    13ee0:	03002025 */ 	or	$a0,$t8,$zero
/*    13ee4:	0c0054f1 */ 	jal	func000153c4
/*    13ee8:	00002825 */ 	or	$a1,$zero,$zero
/*    13eec:	26100001 */ 	addiu	$s0,$s0,0x1
/*    13ef0:	5611fffa */ 	bnel	$s0,$s1,.L00013edc
/*    13ef4:	00102600 */ 	sll	$a0,$s0,0x18
/*    13ef8:	1000001d */ 	b	.L00013f70
/*    13efc:	00000000 */ 	nop
.L00013f00:
/*    13f00:	3c11800a */ 	lui	$s1,%hi(var80099e78)
/*    13f04:	26319e78 */ 	addiu	$s1,$s1,%lo(var80099e78)
/*    13f08:	2410000f */ 	addiu	$s0,$zero,0xf
/*    13f0c:	0c013cd4 */ 	jal	osContStartQuery
/*    13f10:	02202025 */ 	or	$a0,$s1,$zero
/*    13f14:	02202025 */ 	or	$a0,$s1,$zero
/*    13f18:	00002825 */ 	or	$a1,$zero,$zero
/*    13f1c:	0c0121bc */ 	jal	osRecvMesg
/*    13f20:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13f24:	3c04800a */ 	lui	$a0,%hi(var80099f38)
/*    13f28:	0c013cf5 */ 	jal	osContGetQuery
/*    13f2c:	24849f38 */ 	addiu	$a0,$a0,%lo(var80099f38)
/*    13f30:	3c03800a */ 	lui	$v1,%hi(var80099f38)
/*    13f34:	24639f38 */ 	addiu	$v1,$v1,%lo(var80099f38)
/*    13f38:	00001025 */ 	or	$v0,$zero,$zero
/*    13f3c:	24110004 */ 	addiu	$s1,$zero,0x4
.L00013f40:
/*    13f40:	90790003 */ 	lbu	$t9,0x3($v1)
/*    13f44:	24090001 */ 	addiu	$t1,$zero,0x1
/*    13f48:	00495004 */ 	sllv	$t2,$t1,$v0
/*    13f4c:	33280008 */ 	andi	$t0,$t9,0x8
/*    13f50:	51000003 */ 	beqzl	$t0,.L00013f60
/*    13f54:	24420001 */ 	addiu	$v0,$v0,0x1
/*    13f58:	020a8023 */ 	subu	$s0,$s0,$t2
/*    13f5c:	24420001 */ 	addiu	$v0,$v0,0x1
.L00013f60:
/*    13f60:	1451fff7 */ 	bne	$v0,$s1,.L00013f40
/*    13f64:	24630004 */ 	addiu	$v1,$v1,0x4
/*    13f68:	3c018006 */ 	lui	$at,%hi(g_ConnectedControllers)
/*    13f6c:	a030eeac */ 	sb	$s0,%lo(g_ConnectedControllers)($at)
.L00013f70:
/*    13f70:	3c068006 */ 	lui	$a2,%hi(g_ConnectedControllers)
/*    13f74:	3c0b8006 */ 	lui	$t3,%hi(var8005ef00)
/*    13f78:	916bef00 */ 	lbu	$t3,%lo(var8005ef00)($t3)
/*    13f7c:	90c6eeac */ 	lbu	$a2,%lo(g_ConnectedControllers)($a2)
/*    13f80:	00001025 */ 	or	$v0,$zero,$zero
/*    13f84:	00001825 */ 	or	$v1,$zero,$zero
/*    13f88:	10cb000f */ 	beq	$a2,$t3,.L00013fc8
/*    13f8c:	00c02025 */ 	or	$a0,$a2,$zero
/*    13f90:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*    13f94:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*    13f98:	240c0001 */ 	addiu	$t4,$zero,0x1
.L00013f9c:
/*    13f9c:	004c6804 */ 	sllv	$t5,$t4,$v0
/*    13fa0:	008d7024 */ 	and	$t6,$a0,$t5
/*    13fa4:	11c00003 */ 	beqz	$t6,.L00013fb4
/*    13fa8:	00a37821 */ 	addu	$t7,$a1,$v1
/*    13fac:	a1e204dc */ 	sb	$v0,0x4dc($t7)
/*    13fb0:	24630001 */ 	addiu	$v1,$v1,0x1
.L00013fb4:
/*    13fb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    13fb8:	5451fff8 */ 	bnel	$v0,$s1,.L00013f9c
/*    13fbc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    13fc0:	3c018006 */ 	lui	$at,%hi(var8005ef00)
/*    13fc4:	a026ef00 */ 	sb	$a2,%lo(var8005ef00)($at)
.L00013fc8:
/*    13fc8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    13fcc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    13fd0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    13fd4:	03e00008 */ 	jr	$ra
/*    13fd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

s8 contGetFreeSlot(void)
{
	s32 i;

	if (var8005ee60->unk200 >= 0) {
		return var8005ee60->unk200;
	}

	for (i = 0; i < 4; i++) {
		if ((g_ConnectedControllers & (1 << i)) == 0) {
			return i;
		}
	}

	return 4;
}

u32 contGetConnectedControllers(void)
{
	return g_ConnectedControllers;
}

GLOBAL_ASM(
glabel func00014058
/*    14058:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    1405c:	afb00004 */ 	sw	$s0,0x4($sp)
/*    14060:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    14064:	8c8f01e8 */ 	lw	$t7,0x1e8($a0)
/*    14068:	24100014 */ 	addiu	$s0,$zero,0x14
/*    1406c:	00001025 */ 	or	$v0,$zero,$zero
/*    14070:	ac8e01e4 */ 	sw	$t6,0x1e4($a0)
/*    14074:	ac8f01e0 */ 	sw	$t7,0x1e0($a0)
/*    14078:	0002c040 */ 	sll	$t8,$v0,0x1
.L0001407c:
/*    1407c:	00981821 */ 	addu	$v1,$a0,$t8
/*    14080:	a46001f0 */ 	sh	$zero,0x1f0($v1)
/*    14084:	a46001f8 */ 	sh	$zero,0x1f8($v1)
/*    14088:	8c9901e0 */ 	lw	$t9,0x1e0($a0)
/*    1408c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14090:	3c18800a */ 	lui	$t8,%hi(var80099e68)
/*    14094:	27189e68 */ 	addiu	$t8,$t8,%lo(var80099e68)
/*    14098:	10b9005e */ 	beq	$a1,$t9,.L00014214
/*    1409c:	24ae0001 */ 	addiu	$t6,$a1,0x1
/*    140a0:	01d0001a */ 	div	$zero,$t6,$s0
/*    140a4:	00023880 */ 	sll	$a3,$v0,0x2
/*    140a8:	00003010 */ 	mfhi	$a2
/*    140ac:	00e23823 */ 	subu	$a3,$a3,$v0
/*    140b0:	00027880 */ 	sll	$t7,$v0,0x2
/*    140b4:	01f86021 */ 	addu	$t4,$t7,$t8
/*    140b8:	00073840 */ 	sll	$a3,$a3,0x1
/*    140bc:	16000002 */ 	bnez	$s0,.L000140c8
/*    140c0:	00000000 */ 	nop
/*    140c4:	0007000d */ 	break	0x7
.L000140c8:
/*    140c8:	2401ffff */ 	addiu	$at,$zero,-1
/*    140cc:	16010004 */ 	bne	$s0,$at,.L000140e0
/*    140d0:	3c018000 */ 	lui	$at,0x8000
/*    140d4:	15c10002 */ 	bne	$t6,$at,.L000140e0
/*    140d8:	00000000 */ 	nop
/*    140dc:	0006000d */ 	break	0x6
.L000140e0:
/*    140e0:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L000140e4:
/*    140e4:	01f0001a */ 	div	$zero,$t7,$s0
/*    140e8:	0006c880 */ 	sll	$t9,$a2,0x2
/*    140ec:	0326c823 */ 	subu	$t9,$t9,$a2
/*    140f0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    140f4:	00997021 */ 	addu	$t6,$a0,$t9
/*    140f8:	0000c010 */ 	mfhi	$t8
/*    140fc:	0018c880 */ 	sll	$t9,$t8,0x2
/*    14100:	0338c823 */ 	subu	$t9,$t9,$t8
/*    14104:	01c74021 */ 	addu	$t0,$t6,$a3
/*    14108:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    1410c:	00997021 */ 	addu	$t6,$a0,$t9
/*    14110:	95050000 */ 	lhu	$a1,0x0($t0)
/*    14114:	16000002 */ 	bnez	$s0,.L00014120
/*    14118:	00000000 */ 	nop
/*    1411c:	0007000d */ 	break	0x7
.L00014120:
/*    14120:	2401ffff */ 	addiu	$at,$zero,-1
/*    14124:	16010004 */ 	bne	$s0,$at,.L00014138
/*    14128:	3c018000 */ 	lui	$at,0x8000
/*    1412c:	15e10002 */ 	bne	$t7,$at,.L00014138
/*    14130:	00000000 */ 	nop
/*    14134:	0006000d */ 	break	0x6
.L00014138:
/*    14138:	01c77821 */ 	addu	$t7,$t6,$a3
/*    1413c:	95e90000 */ 	lhu	$t1,0x0($t7)
/*    14140:	947801f0 */ 	lhu	$t8,0x1f0($v1)
/*    14144:	00a05025 */ 	or	$t2,$a1,$zero
/*    14148:	0120c827 */ 	nor	$t9,$t1,$zero
/*    1414c:	00b97024 */ 	and	$t6,$a1,$t9
/*    14150:	030e7825 */ 	or	$t7,$t8,$t6
/*    14154:	947901f8 */ 	lhu	$t9,0x1f8($v1)
/*    14158:	00a0c027 */ 	nor	$t8,$a1,$zero
/*    1415c:	a46f01f0 */ 	sh	$t7,0x1f0($v1)
/*    14160:	03097024 */ 	and	$t6,$t8,$t1
/*    14164:	032e7825 */ 	or	$t7,$t9,$t6
/*    14168:	a46f01f8 */ 	sh	$t7,0x1f8($v1)
/*    1416c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    14170:	01205825 */ 	or	$t3,$t1,$zero
/*    14174:	59a00017 */ 	blezl	$t5,.L000141d4
/*    14178:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    1417c:	95180000 */ 	lhu	$t8,0x0($t0)
/*    14180:	57000012 */ 	bnezl	$t8,.L000141cc
/*    14184:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14188:	81050002 */ 	lb	$a1,0x2($t0)
/*    1418c:	28a1000f */ 	slti	$at,$a1,0xf
/*    14190:	5020000e */ 	beqzl	$at,.L000141cc
/*    14194:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14198:	28a1fff2 */ 	slti	$at,$a1,-14
/*    1419c:	5420000b */ 	bnezl	$at,.L000141cc
/*    141a0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141a4:	81050003 */ 	lb	$a1,0x3($t0)
/*    141a8:	28a1000f */ 	slti	$at,$a1,0xf
/*    141ac:	50200007 */ 	beqzl	$at,.L000141cc
/*    141b0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141b4:	28a1fff2 */ 	slti	$at,$a1,-14
/*    141b8:	54200004 */ 	bnezl	$at,.L000141cc
/*    141bc:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141c0:	10000003 */ 	b	.L000141d0
/*    141c4:	ad800000 */ 	sw	$zero,0x0($t4)
/*    141c8:	25b9ffff */ 	addiu	$t9,$t5,-1
.L000141cc:
/*    141cc:	ad990000 */ 	sw	$t9,0x0($t4)
.L000141d0:
/*    141d0:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
.L000141d4:
/*    141d4:	50ce0010 */ 	beql	$a2,$t6,.L00014218
/*    141d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*    141dc:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*    141e0:	01f0001a */ 	div	$zero,$t7,$s0
/*    141e4:	00003010 */ 	mfhi	$a2
/*    141e8:	16000002 */ 	bnez	$s0,.L000141f4
/*    141ec:	00000000 */ 	nop
/*    141f0:	0007000d */ 	break	0x7
.L000141f4:
/*    141f4:	2401ffff */ 	addiu	$at,$zero,-1
/*    141f8:	16010004 */ 	bne	$s0,$at,.L0001420c
/*    141fc:	3c018000 */ 	lui	$at,0x8000
/*    14200:	15e10002 */ 	bne	$t7,$at,.L0001420c
/*    14204:	00000000 */ 	nop
/*    14208:	0006000d */ 	break	0x6
.L0001420c:
/*    1420c:	1000ffb5 */ 	b	.L000140e4
/*    14210:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L00014214:
/*    14214:	24420001 */ 	addiu	$v0,$v0,0x1
.L00014218:
/*    14218:	0002c600 */ 	sll	$t8,$v0,0x18
/*    1421c:	00181603 */ 	sra	$v0,$t8,0x18
/*    14220:	28410004 */ 	slti	$at,$v0,0x4
/*    14224:	5420ff95 */ 	bnezl	$at,.L0001407c
/*    14228:	0002c040 */ 	sll	$t8,$v0,0x1
/*    1422c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*    14230:	03e00008 */ 	jr	$ra
/*    14234:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

/**
 * The use of the static variable suggests that the function is able to be
 * called recursively, but its behaviour should not be run when recursing.
 */
void func00014238(void)
{
	static bool doingit = false;
	s32 i;

	if (doingit == false) {
		doingit = true;

		for (i = 0; i < 4; i++) {
			if (func000155f4(i) == 13) {
				func0f116db0(i, 11);
			}
		}

		if (var8005eec4 == 0) {
			func0001561c();
		}

		doingit = false;
	}
}

u32 var8005ef08 = 0x00000000;

#if VERSION >= VERSION_NTSC_FINAL
GLOBAL_ASM(
glabel func000142f0
/*    142f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    142f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    142f8:	3c047005 */ 	lui	$a0,%hi(var700540a8)
/*    142fc:	3c058006 */ 	lui	$a1,%hi(var8005ef08)
/*    14300:	24a5ef08 */ 	addiu	$a1,$a1,%lo(var8005ef08)
/*    14304:	0c0036cc */ 	jal	func0000db30
/*    14308:	248440a8 */ 	addiu	$a0,$a0,%lo(var700540a8)
/*    1430c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x4d0)
/*    14310:	91cea490 */ 	lbu	$t6,%lo(g_Vars+0x4d0)($t6)
/*    14314:	11c00003 */ 	beqz	$t6,.L00014324
/*    14318:	00000000 */ 	nop
/*    1431c:	0c004eae */ 	jal	func00013ab8
/*    14320:	24040001 */ 	addiu	$a0,$zero,0x1
.L00014324:
/*    14324:	3c028006 */ 	lui	$v0,%hi(var8005eec4)
/*    14328:	8c42eec4 */ 	lw	$v0,%lo(var8005eec4)($v0)
/*    1432c:	3c04800a */ 	lui	$a0,%hi(var80099a60+0x204)
/*    14330:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099a60+0x204)
/*    14334:	10400008 */ 	beqz	$v0,.L00014358
/*    14338:	3c05800a */ 	lui	$a1,%hi(var80099a60+0x3e4)
/*    1433c:	0040f809 */ 	jalr	$v0
/*    14340:	8ca59e44 */ 	lw	$a1,%lo(var80099a60+0x3e4)($a1)
/*    14344:	3c01800a */ 	lui	$at,%hi(var80099a60+0x3ec)
/*    14348:	3c04800a */ 	lui	$a0,%hi(var80099a60+0x204)
/*    1434c:	ac229e4c */ 	sw	$v0,%lo(var80099a60+0x3ec)($at)
/*    14350:	0c005016 */ 	jal	func00014058
/*    14354:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099a60+0x204)
.L00014358:
/*    14358:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    1435c:	0c005016 */ 	jal	func00014058
/*    14360:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14364:	3c028006 */ 	lui	$v0,%hi(var8005eec8)
/*    14368:	8c42eec8 */ 	lw	$v0,%lo(var8005eec8)($v0)
/*    1436c:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    14370:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14374:	10400004 */ 	beqz	$v0,.L00014388
/*    14378:	00000000 */ 	nop
/*    1437c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14380:	0040f809 */ 	jalr	$v0
/*    14384:	8c8601e0 */ 	lw	$a2,0x1e0($a0)
.L00014388:
/*    14388:	0c005431 */ 	jal	func000150c4
/*    1438c:	00000000 */ 	nop
/*    14390:	10400011 */ 	beqz	$v0,.L000143d8
/*    14394:	3c0f8006 */ 	lui	$t7,%hi(var8005eec0)
/*    14398:	8defeec0 */ 	lw	$t7,%lo(var8005eec0)($t7)
/*    1439c:	51e0000f */ 	beqzl	$t7,.L000143dc
/*    143a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143a4:	0c005207 */ 	jal	contGetNumSamples
/*    143a8:	00000000 */ 	nop
/*    143ac:	5c40000b */ 	bgtzl	$v0,.L000143dc
/*    143b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143b4:	0c00543a */ 	jal	func000150e8
/*    143b8:	00000000 */ 	nop
/*    143bc:	0c00508e */ 	jal	func00014238
/*    143c0:	00000000 */ 	nop
/*    143c4:	0c005451 */ 	jal	func00015144
/*    143c8:	00000000 */ 	nop
/*    143cc:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    143d0:	0c005016 */ 	jal	func00014058
/*    143d4:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
.L000143d8:
/*    143d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000143dc:
/*    143dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    143e0:	03e00008 */ 	jr	$ra
/*    143e4:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func000142f0
/*    142f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    142f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    142f8:	3c047005 */ 	lui	$a0,%hi(var700540a8)
/*    142fc:	3c058006 */ 	lui	$a1,%hi(var8005ef08)
/*    14300:	24a5ef08 */ 	addiu	$a1,$a1,%lo(var8005ef08)
/*    14304:	0c0036cc */ 	jal	func0000db30
/*    14308:	248440a8 */ 	addiu	$a0,$a0,%lo(var700540a8)
/*    1430c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x4d0)
/*    14310:	91cea490 */ 	lbu	$t6,%lo(g_Vars+0x4d0)($t6)
/*    14314:	11c00003 */ 	beqz	$t6,.L00014324
/*    14318:	00000000 */ 	nop
/*    1431c:	0c004eae */ 	jal	func00013ab8
/*    14320:	24040001 */ 	addiu	$a0,$zero,0x1
.L00014324:
/*    14324:	3c028006 */ 	lui	$v0,%hi(var8005eec4)
/*    14328:	8c42eec4 */ 	lw	$v0,%lo(var8005eec4)($v0)
/*    1432c:	3c04800a */ 	lui	$a0,%hi(var80099a60+0x204)
/*    14330:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099a60+0x204)
/*    14334:	10400008 */ 	beqz	$v0,.L00014358
/*    14338:	3c05800a */ 	lui	$a1,%hi(var80099a60+0x3e4)
/*    1433c:	0040f809 */ 	jalr	$v0
/*    14340:	8ca59e44 */ 	lw	$a1,%lo(var80099a60+0x3e4)($a1)
/*    14344:	3c01800a */ 	lui	$at,%hi(var80099a60+0x3ec)
/*    14348:	3c04800a */ 	lui	$a0,%hi(var80099a60+0x204)
/*    1434c:	ac229e4c */ 	sw	$v0,%lo(var80099a60+0x3ec)($at)
/*    14350:	0c005016 */ 	jal	func00014058
/*    14354:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099a60+0x204)
.L00014358:
/*    14358:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    1435c:	0c005016 */ 	jal	func00014058
/*    14360:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14364:	3c028006 */ 	lui	$v0,%hi(var8005eec8)
/*    14368:	8c42eec8 */ 	lw	$v0,%lo(var8005eec8)($v0)
/*    1436c:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    14370:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14374:	10400004 */ 	beqz	$v0,.L00014388
/*    14378:	00000000 */ 	nop
/*    1437c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14380:	0040f809 */ 	jalr	$v0
/*    14384:	8c8601e0 */ 	lw	$a2,0x1e0($a0)
.L00014388:
/*    14388:	0c005431 */ 	jal	func000150c4
/*    1438c:	00000000 */ 	nop
/*    14390:	10400011 */ 	beqz	$v0,.L000143d8
/*    14394:	3c0f8006 */ 	lui	$t7,%hi(var8005eec0)
/*    14398:	8defeec0 */ 	lw	$t7,%lo(var8005eec0)($t7)
/*    1439c:	51e0000f */ 	beqzl	$t7,.L000143dc
/*    143a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143a4:	0c005207 */ 	jal	contGetNumSamples
/*    143a8:	00000000 */ 	nop
/*    143ac:	5c40000b */ 	bgtzl	$v0,.L000143dc
/*    143b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143b4:	0c00543a */ 	jal	func000150e8
/*    143b8:	00000000 */ 	nop
/*    143bc:	0c005451 */ 	jal	func00015144
/*    143c0:	00000000 */ 	nop
/*    143c4:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    143c8:	0c005016 */ 	jal	func00014058
/*    143cc:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    143d0:	0c00508e */ 	jal	func00014238
/*    143d4:	00000000 */ 	nop
.L000143d8:
/*    143d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000143dc:
/*    143dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    143e0:	03e00008 */ 	jr	$ra
/*    143e4:	00000000 */ 	nop
);
#endif

s32 contStartReadData(OSMesgQueue *mq)
{
	return osContStartReadData(mq);
}

void contReadData(void)
{
	s32 index = (var80099a60[0].unk1e8 + 1) % 20;

	if (index == var80099a60[0].oldestindex) {
		// If the sample queue is full, don't overwrite the oldest sample.
		// Instead, overwrite the most recent.
		index = var80099a60[0].unk1e8;
	}

	osContGetReadData(var80099a60[0].samples[index].pads);

	var80099a60[0].unk1e8 = index;
	var80099a60[0].unk1ec = (var80099a60[0].unk1e8 + 19) % 20;
}

void contPoll(void)
{
	OSMesg msg;
	s8 i;

	if (osRecvMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK) == 0) {
		if (g_ContBusy) {
			osRecvMesg(&var80099e78, &msg, OS_MESG_BLOCK);

			g_ContBusy = false;
			contReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno == 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno != 0)
						|| (var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno != 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno == 0)) {
					func00013e84();
					break;
				}
			}
		}

		osSendMesg(&var80099ee0, &msg, OS_MESG_NOBLOCK);

		var8005ee68++;

		func00013ab8(0);
		return;
	}

	if (osRecvMesg(&var80099f00, &msg, OS_MESG_NOBLOCK) == 0) {
		var8005ee68--;

		if (var8005ee68 == 0) {
			contStartReadData(&var80099e78);
			g_ContBusy = true;
		}

		osSendMesg(&var80099f20, &msg, OS_MESG_NOBLOCK);
		return;
	}

	if (var8005eeb4) {
		if (var8005ee68) {
			func00013ab8(0);
			return;
		}

		if (osRecvMesg(&var80099e78, &msg, OS_MESG_NOBLOCK) == 0) {
			static s32 count = 0;

			g_ContBusy = false;
			contReadData();

			// Check if error state has changed for any controller
			for (i = 0; i < 4; i++) {
				if ((var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno == 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno != 0)
						|| (var80099a60[0].samples[var80099a60[0].unk1e8].pads[i].errno != 0 && var80099a60[0].samples[var80099a60[0].unk1ec].pads[i].errno == 0)) {
					func00013e84();
					break;
				}
			}

			func00014238();
			func00013ab8(0);

			contStartReadData(&var80099e78);
			g_ContBusy = true;

			count++;

			if (count >= 60) {
				s32 i;

				for (i = 0; i < 4; i++) {
					if (var8005ee6c[i] || var8005ee7c[i] || var8005ee8c[i] || var8005ee9c[i]) {
						var8005ee6c[i] = 0;
						var8005ee7c[i] = 0;
						var8005ee8c[i] = 0;
						var8005ee9c[i] = 0;
					}
				}

				count = 0;
			}
		}
	}
}

void func00014810(bool value)
{
	var8005eec0 = value;
}

s32 contGetNumSamples(void)
{
	return (var8005ee60->newestindex - var8005ee60->oldestindex + 20) % 20;
}

s32 func00014848(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee6c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->oldestindex + samplenum + 1) % 20].pads[contpadnum].stick_x;
}

s32 func00014904(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->oldestindex + samplenum + 1) % 20].pads[contpadnum].stick_y;
}

s32 func000149c0(s32 samplenum, s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[(var8005ee60->oldestindex + samplenum) % 20].pads[contpadnum].stick_y;
}

u16 func00014a78(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	button = var8005ee60->samples[(var8005ee60->oldestindex + samplenum + 1) % 20].pads[contpadnum].button;

	return button & mask;
}

u16 func00014b50(s32 samplenum, s8 contpadnum, u16 mask)
{
	u16 button1;
	u16 button2;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee9c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	button1 = var8005ee60->samples[(var8005ee60->oldestindex + samplenum + 1) % 20].pads[contpadnum].button;
	button2 = var8005ee60->samples[(var8005ee60->oldestindex + samplenum) % 20].pads[contpadnum].button;

	return (button1 & ~button2) & mask;
}

s32 func00014c98(u32 *arg0, s8 contpadnum, u16 mask)
{
	s32 count = 0;
	s32 index = 0;
	s32 i;
	u16 button;

	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	i = (var8005ee60->oldestindex + 1) % 20;

	while (true) {
		if (arg0 == NULL || arg0[index]) {
			button = var8005ee60->samples[i].pads[contpadnum].button;

			if (button & mask) {
				count++;
			}
		}

		if (i == var8005ee60->newestindex) {
			break;
		}

		i = (i + 1) % 20;
		index++;
	}

	return count;
}

s8 contGetStickX(s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee6c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->newestindex].pads[contpadnum].stick_x;
}

s8 contGetStickY(s8 contpadnum)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee7c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->newestindex].pads[contpadnum].stick_y;
}

u16 contGetButtons(s8 contpadnum, u16 mask)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee8c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->samples[var8005ee60->newestindex].pads[contpadnum].button & mask;
}

u16 func00015020(s8 contpadnum, u16 mask)
{
	if (var8005ee60->unk200 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		var8005ee9c[contpadnum]++;
		return 0;
	}

	if (var80099e68[contpadnum] > 0) {
		return 0;
	}

	return var8005ee60->unk1f0[contpadnum] & mask;
}

GLOBAL_ASM(
glabel func000150c4
/*    150c4:	3c0e8006 */ 	lui	$t6,%hi(var8005eebc)
/*    150c8:	8dceeebc */ 	lw	$t6,%lo(var8005eebc)($t6)
/*    150cc:	24030001 */ 	addiu	$v1,$zero,0x1
/*    150d0:	11c00003 */ 	beqz	$t6,.L000150e0
/*    150d4:	00000000 */ 	nop
/*    150d8:	03e00008 */ 	jr	$ra
/*    150dc:	00001025 */ 	or	$v0,$zero,$zero
.L000150e0:
/*    150e0:	03e00008 */ 	jr	$ra
/*    150e4:	00601025 */ 	or	$v0,$v1,$zero
);

void func000150e8(void)
{
	OSMesg msg;

	if (var8005eebc == 0) {
		osSendMesg(&var80099ec0, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099ee0, &msg, OS_MESG_BLOCK);
	}

	var8005eebc++;
}

void func00015144(void)
{
	OSMesg msg;

	var8005eebc--;

	if (var8005eebc == 0) {
		osSendMesg(&var80099f00, &msg, OS_MESG_NOBLOCK);
		osRecvMesg(&var80099f20, &msg, OS_MESG_BLOCK);
	}
}

GLOBAL_ASM(
glabel func0001519c
/*    1519c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    151a0:	afb40028 */ 	sw	$s4,0x28($sp)
/*    151a4:	3c14800a */ 	lui	$s4,%hi(var80099e78)
/*    151a8:	26949e78 */ 	addiu	$s4,$s4,%lo(var80099e78)
/*    151ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    151b0:	3c05800a */ 	lui	$a1,%hi(var80099e90)
/*    151b4:	afb30024 */ 	sw	$s3,0x24($sp)
/*    151b8:	afb20020 */ 	sw	$s2,0x20($sp)
/*    151bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    151c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    151c4:	24a59e90 */ 	addiu	$a1,$a1,%lo(var80099e90)
/*    151c8:	02802025 */ 	or	$a0,$s4,$zero
/*    151cc:	0c0120d0 */ 	jal	osCreateMesgQueue
/*    151d0:	2406000a */ 	addiu	$a2,$zero,0xa
/*    151d4:	24040005 */ 	addiu	$a0,$zero,0x5
/*    151d8:	02802825 */ 	or	$a1,$s4,$zero
/*    151dc:	0c012148 */ 	jal	osSetEventMesg
/*    151e0:	00003025 */ 	or	$a2,$zero,$zero
/*    151e4:	3c12800a */ 	lui	$s2,%hi(var800a3180)
/*    151e8:	26523180 */ 	addiu	$s2,$s2,%lo(var800a3180)
/*    151ec:	00008025 */ 	or	$s0,$zero,$zero
/*    151f0:	24130068 */ 	addiu	$s3,$zero,0x68
/*    151f4:	24110004 */ 	addiu	$s1,$zero,0x4
.L000151f8:
/*    151f8:	16110003 */ 	bne	$s0,$s1,.L00015208
/*    151fc:	02802025 */ 	or	$a0,$s4,$zero
/*    15200:	10000005 */ 	b	.L00015218
/*    15204:	00003825 */ 	or	$a3,$zero,$zero
.L00015208:
/*    15208:	02130019 */ 	multu	$s0,$s3
/*    1520c:	00007012 */ 	mflo	$t6
/*    15210:	024e3821 */ 	addu	$a3,$s2,$t6
/*    15214:	00000000 */ 	nop
.L00015218:
/*    15218:	00e02825 */ 	or	$a1,$a3,$zero
/*    1521c:	0c013e15 */ 	jal	func0004f854
/*    15220:	02003025 */ 	or	$a2,$s0,$zero
/*    15224:	1440001f */ 	bnez	$v0,.L000152a4
/*    15228:	00002825 */ 	or	$a1,$zero,$zero
/*    1522c:	16110003 */ 	bne	$s0,$s1,.L0001523c
/*    15230:	00000000 */ 	nop
/*    15234:	10000005 */ 	b	.L0001524c
/*    15238:	00003825 */ 	or	$a3,$zero,$zero
.L0001523c:
/*    1523c:	02130019 */ 	multu	$s0,$s3
/*    15240:	00007812 */ 	mflo	$t7
/*    15244:	024f3821 */ 	addu	$a3,$s2,$t7
/*    15248:	00000000 */ 	nop
.L0001524c:
/*    1524c:	0c013d78 */ 	jal	func0004f5e0
/*    15250:	00e02025 */ 	or	$a0,$a3,$zero
/*    15254:	16110003 */ 	bne	$s0,$s1,.L00015264
/*    15258:	00002825 */ 	or	$a1,$zero,$zero
/*    1525c:	10000005 */ 	b	.L00015274
/*    15260:	00003825 */ 	or	$a3,$zero,$zero
.L00015264:
/*    15264:	02130019 */ 	multu	$s0,$s3
/*    15268:	0000c012 */ 	mflo	$t8
/*    1526c:	02583821 */ 	addu	$a3,$s2,$t8
/*    15270:	00000000 */ 	nop
.L00015274:
/*    15274:	0c013d78 */ 	jal	func0004f5e0
/*    15278:	00e02025 */ 	or	$a0,$a3,$zero
/*    1527c:	16110003 */ 	bne	$s0,$s1,.L0001528c
/*    15280:	00002825 */ 	or	$a1,$zero,$zero
/*    15284:	10000005 */ 	b	.L0001529c
/*    15288:	00003825 */ 	or	$a3,$zero,$zero
.L0001528c:
/*    1528c:	02130019 */ 	multu	$s0,$s3
/*    15290:	0000c812 */ 	mflo	$t9
/*    15294:	02593821 */ 	addu	$a3,$s2,$t9
/*    15298:	00000000 */ 	nop
.L0001529c:
/*    1529c:	0c013d78 */ 	jal	func0004f5e0
/*    152a0:	00e02025 */ 	or	$a0,$a3,$zero
.L000152a4:
/*    152a4:	26100001 */ 	addiu	$s0,$s0,0x1
/*    152a8:	1611ffd3 */ 	bne	$s0,$s1,.L000151f8
/*    152ac:	00000000 */ 	nop
/*    152b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    152b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    152b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    152bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    152c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    152c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    152c8:	03e00008 */ 	jr	$ra
/*    152cc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func000152d0
/*    152d0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*    152d4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*    152d8:	8cf80318 */ 	lw	$t8,0x318($a3)
/*    152dc:	00047600 */ 	sll	$t6,$a0,0x18
/*    152e0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    152e4:	afa40000 */ 	sw	$a0,0x0($sp)
/*    152e8:	13000008 */ 	beqz	$t8,.L0001530c
/*    152ec:	01e02025 */ 	or	$a0,$t7,$zero
/*    152f0:	000fc9c0 */ 	sll	$t9,$t7,0x7
/*    152f4:	00f94021 */ 	addu	$t0,$a3,$t9
/*    152f8:	8d0900e4 */ 	lw	$t1,0xe4($t0)
/*    152fc:	240affff */ 	addiu	$t2,$zero,-1
/*    15300:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15304:	03e00008 */ 	jr	$ra
/*    15308:	acca0000 */ 	sw	$t2,0x0($a2)
.L0001530c:
/*    1530c:	000459c0 */ 	sll	$t3,$a0,0x7
/*    15310:	aca40000 */ 	sw	$a0,0x0($a1)
/*    15314:	00eb6021 */ 	addu	$t4,$a3,$t3
/*    15318:	8d8d00e4 */ 	lw	$t5,0xe4($t4)
/*    1531c:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers+0x44)
/*    15320:	000d7080 */ 	sll	$t6,$t5,0x2
/*    15324:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    15328:	000e7140 */ 	sll	$t6,$t6,0x5
/*    1532c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    15330:	91efc7fc */ 	lbu	$t7,%lo(g_MpPlayers+0x44)($t7)
/*    15334:	240effff */ 	addiu	$t6,$zero,-1
/*    15338:	29e10004 */ 	slti	$at,$t7,0x4
/*    1533c:	5420001f */ 	bnezl	$at,.L000153bc
/*    15340:	acce0000 */ 	sw	$t6,0x0($a2)
/*    15344:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*    15348:	00001025 */ 	or	$v0,$zero,$zero
/*    1534c:	00001825 */ 	or	$v1,$zero,$zero
/*    15350:	13000003 */ 	beqz	$t8,.L00015360
/*    15354:	00002825 */ 	or	$a1,$zero,$zero
/*    15358:	10000001 */ 	b	.L00015360
/*    1535c:	24020001 */ 	addiu	$v0,$zero,0x1
.L00015360:
/*    15360:	8cf90068 */ 	lw	$t9,0x68($a3)
/*    15364:	13200003 */ 	beqz	$t9,.L00015374
/*    15368:	00000000 */ 	nop
/*    1536c:	10000001 */ 	b	.L00015374
/*    15370:	24030001 */ 	addiu	$v1,$zero,0x1
.L00015374:
/*    15374:	8ce80064 */ 	lw	$t0,0x64($a3)
/*    15378:	11000003 */ 	beqz	$t0,.L00015388
/*    1537c:	00000000 */ 	nop
/*    15380:	10000001 */ 	b	.L00015388
/*    15384:	24050001 */ 	addiu	$a1,$zero,0x1
.L00015388:
/*    15388:	8ce90070 */ 	lw	$t1,0x70($a3)
/*    1538c:	00003825 */ 	or	$a3,$zero,$zero
/*    15390:	11200003 */ 	beqz	$t1,.L000153a0
/*    15394:	00000000 */ 	nop
/*    15398:	10000001 */ 	b	.L000153a0
/*    1539c:	24070001 */ 	addiu	$a3,$zero,0x1
.L000153a0:
/*    153a0:	00e55021 */ 	addu	$t2,$a3,$a1
/*    153a4:	01435821 */ 	addu	$t3,$t2,$v1
/*    153a8:	01626021 */ 	addu	$t4,$t3,$v0
/*    153ac:	01846821 */ 	addu	$t5,$t4,$a0
/*    153b0:	03e00008 */ 	jr	$ra
/*    153b4:	accd0000 */ 	sw	$t5,0x0($a2)
/*    153b8:	acce0000 */ 	sw	$t6,0x0($a2)
.L000153bc:
/*    153bc:	03e00008 */ 	jr	$ra
/*    153c0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000153c4
/*    153c4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    153c8:	00043600 */ 	sll	$a2,$a0,0x18
/*    153cc:	00067603 */ 	sra	$t6,$a2,0x18
/*    153d0:	24010004 */ 	addiu	$at,$zero,0x4
/*    153d4:	01c03025 */ 	or	$a2,$t6,$zero
/*    153d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    153dc:	afa40028 */ 	sw	$a0,0x28($sp)
/*    153e0:	11c10070 */ 	beq	$t6,$at,.L000155a4
/*    153e4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    153e8:	000e7880 */ 	sll	$t7,$t6,0x2
/*    153ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    153f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    153f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    153f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    153fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    15400:	000f7880 */ 	sll	$t7,$t7,0x2
/*    15404:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    15408:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*    1540c:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*    15410:	000f7880 */ 	sll	$t7,$t7,0x2
/*    15414:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    15418:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    1541c:	8f220000 */ 	lw	$v0,0x0($t9)
/*    15420:	24010002 */ 	addiu	$at,$zero,0x2
/*    15424:	1041005f */ 	beq	$v0,$at,.L000155a4
/*    15428:	24010003 */ 	addiu	$at,$zero,0x3
/*    1542c:	5041005e */ 	beql	$v0,$at,.L000155a8
/*    15430:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15434:	50a00005 */ 	beqzl	$a1,.L0001544c
/*    15438:	24010004 */ 	addiu	$at,$zero,0x4
/*    1543c:	0c00543a */ 	jal	func000150e8
/*    15440:	a3ae002b */ 	sb	$t6,0x2b($sp)
/*    15444:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    15448:	24010004 */ 	addiu	$at,$zero,0x4
.L0001544c:
/*    1544c:	14c10003 */ 	bne	$a2,$at,.L0001545c
/*    15450:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    15454:	10000009 */ 	b	.L0001547c
/*    15458:	00003825 */ 	or	$a3,$zero,$zero
.L0001545c:
/*    1545c:	00064880 */ 	sll	$t1,$a2,0x2
/*    15460:	01264823 */ 	subu	$t1,$t1,$a2
/*    15464:	00094880 */ 	sll	$t1,$t1,0x2
/*    15468:	01264821 */ 	addu	$t1,$t1,$a2
/*    1546c:	3c0a800a */ 	lui	$t2,%hi(var800a3180)
/*    15470:	254a3180 */ 	addiu	$t2,$t2,%lo(var800a3180)
/*    15474:	000948c0 */ 	sll	$t1,$t1,0x3
/*    15478:	012a3821 */ 	addu	$a3,$t1,$t2
.L0001547c:
/*    1547c:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    15480:	00e02825 */ 	or	$a1,$a3,$zero
/*    15484:	0c013e15 */ 	jal	func0004f854
/*    15488:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    1548c:	14400034 */ 	bnez	$v0,.L00015560
/*    15490:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    15494:	24010004 */ 	addiu	$at,$zero,0x4
/*    15498:	14c10003 */ 	bne	$a2,$at,.L000154a8
/*    1549c:	00002825 */ 	or	$a1,$zero,$zero
/*    154a0:	10000009 */ 	b	.L000154c8
/*    154a4:	00003825 */ 	or	$a3,$zero,$zero
.L000154a8:
/*    154a8:	00065880 */ 	sll	$t3,$a2,0x2
/*    154ac:	01665823 */ 	subu	$t3,$t3,$a2
/*    154b0:	000b5880 */ 	sll	$t3,$t3,0x2
/*    154b4:	01665821 */ 	addu	$t3,$t3,$a2
/*    154b8:	3c0c800a */ 	lui	$t4,%hi(var800a3180)
/*    154bc:	258c3180 */ 	addiu	$t4,$t4,%lo(var800a3180)
/*    154c0:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    154c4:	016c3821 */ 	addu	$a3,$t3,$t4
.L000154c8:
/*    154c8:	00e02025 */ 	or	$a0,$a3,$zero
/*    154cc:	0c013d78 */ 	jal	func0004f5e0
/*    154d0:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    154d4:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    154d8:	24010004 */ 	addiu	$at,$zero,0x4
/*    154dc:	00002825 */ 	or	$a1,$zero,$zero
/*    154e0:	14c10003 */ 	bne	$a2,$at,.L000154f0
/*    154e4:	00066880 */ 	sll	$t5,$a2,0x2
/*    154e8:	10000008 */ 	b	.L0001550c
/*    154ec:	00003825 */ 	or	$a3,$zero,$zero
.L000154f0:
/*    154f0:	01a66823 */ 	subu	$t5,$t5,$a2
/*    154f4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    154f8:	01a66821 */ 	addu	$t5,$t5,$a2
/*    154fc:	3c0e800a */ 	lui	$t6,%hi(var800a3180)
/*    15500:	25ce3180 */ 	addiu	$t6,$t6,%lo(var800a3180)
/*    15504:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    15508:	01ae3821 */ 	addu	$a3,$t5,$t6
.L0001550c:
/*    1550c:	00e02025 */ 	or	$a0,$a3,$zero
/*    15510:	0c013d78 */ 	jal	func0004f5e0
/*    15514:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    15518:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    1551c:	24010004 */ 	addiu	$at,$zero,0x4
/*    15520:	00002825 */ 	or	$a1,$zero,$zero
/*    15524:	14c10003 */ 	bne	$a2,$at,.L00015534
/*    15528:	00067880 */ 	sll	$t7,$a2,0x2
/*    1552c:	10000008 */ 	b	.L00015550
/*    15530:	00003825 */ 	or	$a3,$zero,$zero
.L00015534:
/*    15534:	01e67823 */ 	subu	$t7,$t7,$a2
/*    15538:	000f7880 */ 	sll	$t7,$t7,0x2
/*    1553c:	01e67821 */ 	addu	$t7,$t7,$a2
/*    15540:	3c18800a */ 	lui	$t8,%hi(var800a3180)
/*    15544:	27183180 */ 	addiu	$t8,$t8,%lo(var800a3180)
/*    15548:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    1554c:	01f83821 */ 	addu	$a3,$t7,$t8
.L00015550:
/*    15550:	00e02025 */ 	or	$a0,$a3,$zero
/*    15554:	0c013d78 */ 	jal	func0004f5e0
/*    15558:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    1555c:	83a6002b */ 	lb	$a2,0x2b($sp)
.L00015560:
/*    15560:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    15564:	53200004 */ 	beqzl	$t9,.L00015578
/*    15568:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    1556c:	0c005451 */ 	jal	func00015144
/*    15570:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    15574:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L00015578:
/*    15578:	24010006 */ 	addiu	$at,$zero,0x6
/*    1557c:	8c620004 */ 	lw	$v0,0x4($v1)
/*    15580:	10410004 */ 	beq	$v0,$at,.L00015594
/*    15584:	24010007 */ 	addiu	$at,$zero,0x7
/*    15588:	10410002 */ 	beq	$v0,$at,.L00015594
/*    1558c:	24080005 */ 	addiu	$t0,$zero,0x5
/*    15590:	ac680004 */ 	sw	$t0,0x4($v1)
.L00015594:
/*    15594:	3c01bf80 */ 	lui	$at,0xbf80
/*    15598:	44812000 */ 	mtc1	$at,$f4
/*    1559c:	00000000 */ 	nop
/*    155a0:	e46402b4 */ 	swc1	$f4,0x2b4($v1)
.L000155a4:
/*    155a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000155a8:
/*    155a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    155ac:	03e00008 */ 	jr	$ra
/*    155b0:	00000000 */ 	nop
);

s32 func000155b4(s8 index)
{
	return var800a2380[index].unk010;
}

s32 func000155f4(s8 index)
{
	return func000155b4(index);
}

GLOBAL_ASM(
glabel func0001561c
/*    1561c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    15620:	afb30020 */ 	sw	$s3,0x20($sp)
/*    15624:	afb00014 */ 	sw	$s0,0x14($sp)
/*    15628:	afb50028 */ 	sw	$s5,0x28($sp)
/*    1562c:	afb40024 */ 	sw	$s4,0x24($sp)
/*    15630:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    15634:	afb10018 */ 	sw	$s1,0x18($sp)
/*    15638:	3c10800a */ 	lui	$s0,%hi(var800a2380)
/*    1563c:	3c13800a */ 	lui	$s3,%hi(var800a3180)
/*    15640:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    15644:	26733180 */ 	addiu	$s3,$s3,%lo(var800a3180)
/*    15648:	26102380 */ 	addiu	$s0,$s0,%lo(var800a2380)
/*    1564c:	00008825 */ 	or	$s1,$zero,$zero
/*    15650:	24120004 */ 	addiu	$s2,$zero,0x4
/*    15654:	24140068 */ 	addiu	$s4,$zero,0x68
/*    15658:	24150002 */ 	addiu	$s5,$zero,0x2
.L0001565c:
/*    1565c:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*    15660:	2401000b */ 	addiu	$at,$zero,0xb
/*    15664:	55c1006e */ 	bnel	$t6,$at,.L00015820
/*    15668:	26310001 */ 	addiu	$s1,$s1,0x1
/*    1566c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*    15670:	24010001 */ 	addiu	$at,$zero,0x1
/*    15674:	55e1006a */ 	bnel	$t7,$at,.L00015820
/*    15678:	26310001 */ 	addiu	$s1,$s1,0x1
/*    1567c:	8e180004 */ 	lw	$t8,0x4($s0)
/*    15680:	2719fffd */ 	addiu	$t9,$t8,-3
/*    15684:	2f210006 */ 	sltiu	$at,$t9,0x6
/*    15688:	10200064 */ 	beqz	$at,.L0001581c
/*    1568c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    15690:	3c017005 */ 	lui	$at,%hi(var700541e4)
/*    15694:	00390821 */ 	addu	$at,$at,$t9
/*    15698:	8c3941e4 */ 	lw	$t9,%lo(var700541e4)($at)
/*    1569c:	03200008 */ 	jr	$t9
/*    156a0:	00000000 */ 	nop
/*    156a4:	24080004 */ 	addiu	$t0,$zero,0x4
/*    156a8:	16320003 */ 	bne	$s1,$s2,.L000156b8
/*    156ac:	ae080004 */ 	sw	$t0,0x4($s0)
/*    156b0:	10000005 */ 	b	.L000156c8
/*    156b4:	00002025 */ 	or	$a0,$zero,$zero
.L000156b8:
/*    156b8:	02340019 */ 	multu	$s1,$s4
/*    156bc:	00004812 */ 	mflo	$t1
/*    156c0:	02692021 */ 	addu	$a0,$s3,$t1
/*    156c4:	00000000 */ 	nop
.L000156c8:
/*    156c8:	0c013d78 */ 	jal	func0004f5e0
/*    156cc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    156d0:	10000053 */ 	b	.L00015820
/*    156d4:	26310001 */ 	addiu	$s1,$s1,0x1
/*    156d8:	8e030284 */ 	lw	$v1,0x284($s0)
/*    156dc:	2401ffff */ 	addiu	$at,$zero,-1
/*    156e0:	50610024 */ 	beql	$v1,$at,.L00015774
/*    156e4:	3c013f80 */ 	lui	$at,0x3f80
/*    156e8:	8e02028c */ 	lw	$v0,0x28c($s0)
/*    156ec:	1440000d */ 	bnez	$v0,.L00015724
/*    156f0:	00000000 */ 	nop
/*    156f4:	16320003 */ 	bne	$s1,$s2,.L00015704
/*    156f8:	00000000 */ 	nop
/*    156fc:	10000005 */ 	b	.L00015714
/*    15700:	00002025 */ 	or	$a0,$zero,$zero
.L00015704:
/*    15704:	02340019 */ 	multu	$s1,$s4
/*    15708:	00005012 */ 	mflo	$t2
/*    1570c:	026a2021 */ 	addu	$a0,$s3,$t2
/*    15710:	00000000 */ 	nop
.L00015714:
/*    15714:	0c013d78 */ 	jal	func0004f5e0
/*    15718:	24050001 */ 	addiu	$a1,$zero,0x1
/*    1571c:	1000000e */ 	b	.L00015758
/*    15720:	8e02028c */ 	lw	$v0,0x28c($s0)
.L00015724:
/*    15724:	5462000d */ 	bnel	$v1,$v0,.L0001575c
/*    15728:	8e0d0288 */ 	lw	$t5,0x288($s0)
/*    1572c:	16320003 */ 	bne	$s1,$s2,.L0001573c
/*    15730:	00000000 */ 	nop
/*    15734:	10000005 */ 	b	.L0001574c
/*    15738:	00002025 */ 	or	$a0,$zero,$zero
.L0001573c:
/*    1573c:	02340019 */ 	multu	$s1,$s4
/*    15740:	00005812 */ 	mflo	$t3
/*    15744:	026b2021 */ 	addu	$a0,$s3,$t3
/*    15748:	00000000 */ 	nop
.L0001574c:
/*    1574c:	0c013d78 */ 	jal	func0004f5e0
/*    15750:	00002825 */ 	or	$a1,$zero,$zero
/*    15754:	8e02028c */ 	lw	$v0,0x28c($s0)
.L00015758:
/*    15758:	8e0d0288 */ 	lw	$t5,0x288($s0)
.L0001575c:
/*    1575c:	244c0001 */ 	addiu	$t4,$v0,0x1
/*    15760:	ae0c028c */ 	sw	$t4,0x28c($s0)
/*    15764:	55ac0003 */ 	bnel	$t5,$t4,.L00015774
/*    15768:	3c013f80 */ 	lui	$at,0x3f80
/*    1576c:	ae00028c */ 	sw	$zero,0x28c($s0)
/*    15770:	3c013f80 */ 	lui	$at,0x3f80
.L00015774:
/*    15774:	44813000 */ 	mtc1	$at,$f6
/*    15778:	c60402b4 */ 	lwc1	$f4,0x2b4($s0)
/*    1577c:	44808000 */ 	mtc1	$zero,$f16
/*    15780:	240f0005 */ 	addiu	$t7,$zero,0x5
/*    15784:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    15788:	e60802b4 */ 	swc1	$f8,0x2b4($s0)
/*    1578c:	c60a02b4 */ 	lwc1	$f10,0x2b4($s0)
/*    15790:	4610503c */ 	c.lt.s	$f10,$f16
/*    15794:	00000000 */ 	nop
/*    15798:	45020021 */ 	bc1fl	.L00015820
/*    1579c:	26310001 */ 	addiu	$s1,$s1,0x1
/*    157a0:	1000001e */ 	b	.L0001581c
/*    157a4:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*    157a8:	16320003 */ 	bne	$s1,$s2,.L000157b8
/*    157ac:	ae150004 */ 	sw	$s5,0x4($s0)
/*    157b0:	10000005 */ 	b	.L000157c8
/*    157b4:	00002025 */ 	or	$a0,$zero,$zero
.L000157b8:
/*    157b8:	02340019 */ 	multu	$s1,$s4
/*    157bc:	0000c012 */ 	mflo	$t8
/*    157c0:	02782021 */ 	addu	$a0,$s3,$t8
/*    157c4:	00000000 */ 	nop
.L000157c8:
/*    157c8:	0c013d78 */ 	jal	func0004f5e0
/*    157cc:	00002825 */ 	or	$a1,$zero,$zero
/*    157d0:	10000013 */ 	b	.L00015820
/*    157d4:	26310001 */ 	addiu	$s1,$s1,0x1
/*    157d8:	16320003 */ 	bne	$s1,$s2,.L000157e8
/*    157dc:	00000000 */ 	nop
/*    157e0:	10000005 */ 	b	.L000157f8
/*    157e4:	00002025 */ 	or	$a0,$zero,$zero
.L000157e8:
/*    157e8:	02340019 */ 	multu	$s1,$s4
/*    157ec:	0000c812 */ 	mflo	$t9
/*    157f0:	02792021 */ 	addu	$a0,$s3,$t9
/*    157f4:	00000000 */ 	nop
.L000157f8:
/*    157f8:	0c013d78 */ 	jal	func0004f5e0
/*    157fc:	00002825 */ 	or	$a1,$zero,$zero
/*    15800:	24080007 */ 	addiu	$t0,$zero,0x7
/*    15804:	10000005 */ 	b	.L0001581c
/*    15808:	ae080004 */ 	sw	$t0,0x4($s0)
/*    1580c:	3c01bf80 */ 	lui	$at,0xbf80
/*    15810:	44819000 */ 	mtc1	$at,$f18
/*    15814:	ae150004 */ 	sw	$s5,0x4($s0)
/*    15818:	e61202b4 */ 	swc1	$f18,0x2b4($s0)
.L0001581c:
/*    1581c:	26310001 */ 	addiu	$s1,$s1,0x1
.L00015820:
/*    15820:	1632ff8e */ 	bne	$s1,$s2,.L0001565c
/*    15824:	261002cc */ 	addiu	$s0,$s0,0x2cc
/*    15828:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1582c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    15830:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    15834:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    15838:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    1583c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    15840:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    15844:	03e00008 */ 	jr	$ra
/*    15848:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    1584c:	00000000 */ 	nop
/*    15850:	03e00008 */ 	jr	$ra
/*    15854:	00000000 */ 	nop
/*    15858:	00000000 */ 	nop
/*    1585c:	00000000 */ 	nop
);
