#include <ultra64.h>
#include "constants.h"
#include "types.h"

struct typea {
	u8 unk28;
	u8 unk29;
};

struct typeb {
	f32 unk28;
};

typedef struct oscData_s {
	struct oscData_s *next;
	u8 type;
	u8 stateFlags;
	u16 maxCount;
	u32 curCount;
	f32 unk0c;
	f32 unk10;
	u16 unk14;
	u16 unk16;
	f32 unk18;
	f32 unk1c;
	u16 unk20;
	u16 unk22;
	u16 unk24;
	u16 unk26;
	union {
		struct typea a;
		struct typeb b;
	} data;
} oscData;

oscData *freeOscStateList;
u32 var8009b874;
oscData oscStates[60];
u32 var8009c2c8;
u32 var8009c2cc;
N_ALSndPlayer var8009c2d0;

ALMicroTime updateOsc(void *oscState, f32 *updateVal);
ALMicroTime updateOscMain(oscData *statePtr, f32 *updateVal);
void func00030bd8(void *oscState);
ALMicroTime func000301e4(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6);

f32 func0002fc60(u8 arg0)
{
	f32 fVar1 = 1.0309929847717f;
	f32 fStack8 = 1.0f;

	while (arg0) {
		if (arg0 & 1) {
			fStack8 *= fVar1;
		}

		fVar1 *= fVar1;
		arg0 >>= 1;
	}

	return fStack8;
}

ALMicroTime initOsc(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6)
{
	oscData *state;
	ALMicroTime result = 0;

	if (oscDelay == 0) {
		return 0;
	}

	if (oscType != 1 && oscType != 0x80) {
		return func000301e4(oscState, initVal, oscType, oscRate, oscDepth, oscDelay, arg6);
	}

	if (freeOscStateList != NULL) {
		state = freeOscStateList;
		freeOscStateList = freeOscStateList->next;
		state->type = oscType;
		*oscState = state;
		result = oscDelay << 14;

		switch (oscType) {
		case 1:
			state->unk24 = 0;
			state->unk22 = 259 - oscRate;
			state->data.a.unk28 = oscDepth >> 1;
			state->data.a.unk29 = 127 - state->data.a.unk28;
			*initVal = state->data.a.unk29;
			break;
		case 0x80:
			state->data.b.unk28 = func0002fc60(oscDepth);
			state->unk24 = 0;
			state->unk22 = 259 - oscRate;
			*initVal = 1.0f;
			break;
		default:
			break;
		}
	}

	return result;
}

ALMicroTime updateOsc(void *oscState, f32 *updateVal)
{
	f32 sp2c;
	oscData *state = oscState;
	ALMicroTime result = AL_USEC_PER_FRAME;

	if (state->type != 1 && state->type != 0x80) {
		return updateOscMain(oscState, updateVal);
	}

	switch (state->type) {
	case 0x01:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * M_TAU);
		sp2c = sp2c * state->data.a.unk28;
		*updateVal = state->data.a.unk29 + sp2c;
		break;
	case 0x80:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * M_TAU) * state->data.b.unk28;
		*updateVal = alCents2Ratio(sp2c);
		break;
	default:
		break;
	}

	return result;
}

void stopOsc(void *oscState)
{
	oscData *state = (oscData *)oscState;

	if (state->type != 1 && state->type != 0x80) {
		func00030bd8(oscState);
	}

	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

f32 func000301a4(f32 value)
{
	// Almost value / (32768 / M_PI), but has a precision mismatch
	return sinf(value / 10430.379882812f);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func000301e4
.late_rodata
glabel var70054370pf
.word 0x469c4000
glabel var700546c0
.word 0x49742400
glabel var70054378pf
.word 0x469c4000
glabel var700546c4
.word func000301e4+0x2ec
glabel var700546c8
.word func000301e4+0x2ec
glabel var700546cc
.word func000301e4+0x2ec
glabel var700546d0
.word func000301e4+0x2ec
glabel var700546d4
.word func000301e4+0x364
glabel var700546d8
.word func000301e4+0x384
glabel var700546dc
.word func000301e4+0x364
glabel var700546e0
.word func000301e4+0x384
glabel var700546e4
.word func000301e4+0x3bc
glabel var700546e8
.word func000301e4+0x364
glabel var700546ec
.word func000301e4+0x364
glabel var700546f0
.word func000301e4+0x384
glabel var700546f4
.word 0x48f42400
.text
/*    2fae4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2fae8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2faec:	afa40020 */ 	sw	$a0,0x20($sp)
/*    2faf0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    2faf4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    2faf8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    2fafc:	93ae002f */ 	lbu	$t6,0x2f($sp)
/*    2fb00:	29c10064 */ 	slti	$at,$t6,0x64
/*    2fb04:	14200003 */ 	bnez	$at,.PF0002fb14
/*    2fb08:	00000000 */ 	nop
/*    2fb0c:	240f0063 */ 	li	$t7,0x63
/*    2fb10:	a3af002f */ 	sb	$t7,0x2f($sp)
.PF0002fb14:
/*    2fb14:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    2fb18:	2b010080 */ 	slti	$at,$t8,0x80
/*    2fb1c:	14200003 */ 	bnez	$at,.PF0002fb2c
/*    2fb20:	00000000 */ 	nop
/*    2fb24:	2419007f */ 	li	$t9,0x7f
/*    2fb28:	a3b90037 */ 	sb	$t9,0x37($sp)
.PF0002fb2c:
/*    2fb2c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    2fb30:	29010080 */ 	slti	$at,$t0,0x80
/*    2fb34:	14200003 */ 	bnez	$at,.PF0002fb44
/*    2fb38:	00000000 */ 	nop
/*    2fb3c:	2409007f */ 	li	$t1,0x7f
/*    2fb40:	a3a9003b */ 	sb	$t1,0x3b($sp)
.PF0002fb44:
/*    2fb44:	3c0a800a */ 	lui	$t2,0x800a
/*    2fb48:	8d4abdc0 */ 	lw	$t2,-0x4240($t2)
/*    2fb4c:	15400003 */ 	bnez	$t2,.PF0002fb5c
/*    2fb50:	00000000 */ 	nop
/*    2fb54:	1000010a */ 	b	.PF0002ff80
/*    2fb58:	00001025 */ 	move	$v0,$zero
.PF0002fb5c:
/*    2fb5c:	3c0b800a */ 	lui	$t3,0x800a
/*    2fb60:	8d6bbdc0 */ 	lw	$t3,-0x4240($t3)
/*    2fb64:	afab001c */ 	sw	$t3,0x1c($sp)
/*    2fb68:	93ac003b */ 	lbu	$t4,0x3b($sp)
/*    2fb6c:	15800009 */ 	bnez	$t4,.PF0002fb94
/*    2fb70:	00000000 */ 	nop
/*    2fb74:	3c013f80 */ 	lui	$at,0x3f80
/*    2fb78:	44812000 */ 	mtc1	$at,$f4
/*    2fb7c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    2fb80:	e5a40018 */ 	swc1	$f4,0x18($t5)
/*    2fb84:	44803000 */ 	mtc1	$zero,$f6
/*    2fb88:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    2fb8c:	10000013 */ 	b	.PF0002fbdc
/*    2fb90:	e5c6001c */ 	swc1	$f6,0x1c($t6)
.PF0002fb94:
/*    2fb94:	44804000 */ 	mtc1	$zero,$f8
/*    2fb98:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    2fb9c:	e5e80018 */ 	swc1	$f8,0x18($t7)
/*    2fba0:	93b8003b */ 	lbu	$t8,0x3b($sp)
/*    2fba4:	3c088006 */ 	lui	$t0,0x8006
/*    2fba8:	3c017005 */ 	lui	$at,0x7005
/*    2fbac:	0018c880 */ 	sll	$t9,$t8,0x2
/*    2fbb0:	01194021 */ 	addu	$t0,$t0,$t9
/*    2fbb4:	8d08ee00 */ 	lw	$t0,-0x1200($t0)
/*    2fbb8:	c4324370 */ 	lwc1	$f18,0x4370($at)
/*    2fbbc:	3c013f80 */ 	lui	$at,0x3f80
/*    2fbc0:	44885000 */ 	mtc1	$t0,$f10
/*    2fbc4:	44813000 */ 	mtc1	$at,$f6
/*    2fbc8:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    2fbcc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    2fbd0:	46128103 */ 	div.s	$f4,$f16,$f18
/*    2fbd4:	46043203 */ 	div.s	$f8,$f6,$f4
/*    2fbd8:	e528001c */ 	swc1	$f8,0x1c($t1)
.PF0002fbdc:
/*    2fbdc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    2fbe0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    2fbe4:	a16a0004 */ 	sb	$t2,0x4($t3)
/*    2fbe8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    2fbec:	a5800014 */ 	sh	$zero,0x14($t4)
/*    2fbf0:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    2fbf4:	3c017005 */ 	lui	$at,0x7005
/*    2fbf8:	c42a4374 */ 	lwc1	$f10,0x4374($at)
/*    2fbfc:	3c018006 */ 	lui	$at,0x8006
/*    2fc00:	000d7080 */ 	sll	$t6,$t5,0x2
/*    2fc04:	002e0821 */ 	addu	$at,$at,$t6
/*    2fc08:	c430effc */ 	lwc1	$f16,-0x1004($at)
/*    2fc0c:	3c017005 */ 	lui	$at,0x7005
/*    2fc10:	c4264378 */ 	lwc1	$f6,0x4378($at)
/*    2fc14:	46105483 */ 	div.s	$f18,$f10,$f16
/*    2fc18:	24180001 */ 	li	$t8,0x1
/*    2fc1c:	46069103 */ 	div.s	$f4,$f18,$f6
/*    2fc20:	444ff800 */ 	cfc1	$t7,$31
/*    2fc24:	44d8f800 */ 	ctc1	$t8,$31
/*    2fc28:	00000000 */ 	nop
/*    2fc2c:	46002224 */ 	cvt.w.s	$f8,$f4
/*    2fc30:	4458f800 */ 	cfc1	$t8,$31
/*    2fc34:	00000000 */ 	nop
/*    2fc38:	33010004 */ 	andi	$at,$t8,0x4
/*    2fc3c:	33180078 */ 	andi	$t8,$t8,0x78
/*    2fc40:	13000014 */ 	beqz	$t8,.PF0002fc94
/*    2fc44:	00000000 */ 	nop
/*    2fc48:	3c014f00 */ 	lui	$at,0x4f00
/*    2fc4c:	44814000 */ 	mtc1	$at,$f8
/*    2fc50:	24180001 */ 	li	$t8,0x1
/*    2fc54:	46082201 */ 	sub.s	$f8,$f4,$f8
/*    2fc58:	44d8f800 */ 	ctc1	$t8,$31
/*    2fc5c:	00000000 */ 	nop
/*    2fc60:	46004224 */ 	cvt.w.s	$f8,$f8
/*    2fc64:	4458f800 */ 	cfc1	$t8,$31
/*    2fc68:	00000000 */ 	nop
/*    2fc6c:	33010004 */ 	andi	$at,$t8,0x4
/*    2fc70:	33180078 */ 	andi	$t8,$t8,0x78
/*    2fc74:	17000005 */ 	bnez	$t8,.PF0002fc8c
/*    2fc78:	00000000 */ 	nop
/*    2fc7c:	44184000 */ 	mfc1	$t8,$f8
/*    2fc80:	3c018000 */ 	lui	$at,0x8000
/*    2fc84:	10000007 */ 	b	.PF0002fca4
/*    2fc88:	0301c025 */ 	or	$t8,$t8,$at
.PF0002fc8c:
/*    2fc8c:	10000005 */ 	b	.PF0002fca4
/*    2fc90:	2418ffff */ 	li	$t8,-1
.PF0002fc94:
/*    2fc94:	44184000 */ 	mfc1	$t8,$f8
/*    2fc98:	00000000 */ 	nop
/*    2fc9c:	0700fffb */ 	bltz	$t8,.PF0002fc8c
/*    2fca0:	00000000 */ 	nop
.PF0002fca4:
/*    2fca4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    2fca8:	44cff800 */ 	ctc1	$t7,$31
/*    2fcac:	a7380016 */ 	sh	$t8,0x16($t9)
/*    2fcb0:	00000000 */ 	nop
/*    2fcb4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    2fcb8:	24084e20 */ 	li	$t0,0x4e20
/*    2fcbc:	ad280008 */ 	sw	$t0,0x8($t1)
/*    2fcc0:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    2fcc4:	448a5000 */ 	mtc1	$t2,$f10
/*    2fcc8:	05410005 */ 	bgez	$t2,.PF0002fce0
/*    2fccc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    2fcd0:	3c014f80 */ 	lui	$at,0x4f80
/*    2fcd4:	44819000 */ 	mtc1	$at,$f18
/*    2fcd8:	00000000 */ 	nop
/*    2fcdc:	46128400 */ 	add.s	$f16,$f16,$f18
.PF0002fce0:
/*    2fce0:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*    2fce4:	93ab002b */ 	lbu	$t3,0x2b($sp)
/*    2fce8:	316c0080 */ 	andi	$t4,$t3,0x80
/*    2fcec:	11800027 */ 	beqz	$t4,.PF0002fd8c
/*    2fcf0:	00000000 */ 	nop
/*    2fcf4:	444df800 */ 	cfc1	$t5,$31
/*    2fcf8:	24040001 */ 	li	$a0,0x1
/*    2fcfc:	44c4f800 */ 	ctc1	$a0,$31
/*    2fd00:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    2fd04:	46003124 */ 	cvt.w.s	$f4,$f6
/*    2fd08:	4444f800 */ 	cfc1	$a0,$31
/*    2fd0c:	00000000 */ 	nop
/*    2fd10:	30810004 */ 	andi	$at,$a0,0x4
/*    2fd14:	30840078 */ 	andi	$a0,$a0,0x78
/*    2fd18:	10800014 */ 	beqz	$a0,.PF0002fd6c
/*    2fd1c:	00000000 */ 	nop
/*    2fd20:	3c014f00 */ 	lui	$at,0x4f00
/*    2fd24:	44812000 */ 	mtc1	$at,$f4
/*    2fd28:	24040001 */ 	li	$a0,0x1
/*    2fd2c:	46043101 */ 	sub.s	$f4,$f6,$f4
/*    2fd30:	44c4f800 */ 	ctc1	$a0,$31
/*    2fd34:	00000000 */ 	nop
/*    2fd38:	46002124 */ 	cvt.w.s	$f4,$f4
/*    2fd3c:	4444f800 */ 	cfc1	$a0,$31
/*    2fd40:	00000000 */ 	nop
/*    2fd44:	30810004 */ 	andi	$at,$a0,0x4
/*    2fd48:	30840078 */ 	andi	$a0,$a0,0x78
/*    2fd4c:	14800005 */ 	bnez	$a0,.PF0002fd64
/*    2fd50:	00000000 */ 	nop
/*    2fd54:	44042000 */ 	mfc1	$a0,$f4
/*    2fd58:	3c018000 */ 	lui	$at,0x8000
/*    2fd5c:	10000007 */ 	b	.PF0002fd7c
/*    2fd60:	00812025 */ 	or	$a0,$a0,$at
.PF0002fd64:
/*    2fd64:	10000005 */ 	b	.PF0002fd7c
/*    2fd68:	2404ffff */ 	li	$a0,-1
.PF0002fd6c:
/*    2fd6c:	44042000 */ 	mfc1	$a0,$f4
/*    2fd70:	00000000 */ 	nop
/*    2fd74:	0480fffb */ 	bltz	$a0,.PF0002fd64
/*    2fd78:	00000000 */ 	nop
.PF0002fd7c:
/*    2fd7c:	44cdf800 */ 	ctc1	$t5,$31
/*    2fd80:	0c00bd58 */ 	jal	func0002fc60
/*    2fd84:	00000000 */ 	nop
/*    2fd88:	e7a00018 */ 	swc1	$f0,0x18($sp)
.PF0002fd8c:
/*    2fd8c:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    2fd90:	2401ff7f */ 	li	$at,-129
/*    2fd94:	01c17824 */ 	and	$t7,$t6,$at
/*    2fd98:	a3af002b */ 	sb	$t7,0x2b($sp)
/*    2fd9c:	93b8002b */ 	lbu	$t8,0x2b($sp)
/*    2fda0:	2401ff7f */ 	li	$at,-129
/*    2fda4:	0301c824 */ 	and	$t9,$t8,$at
/*    2fda8:	2728fffe */ 	addiu	$t0,$t9,-2
/*    2fdac:	2d01000c */ 	sltiu	$at,$t0,0xc
/*    2fdb0:	10200047 */ 	beqz	$at,.PF0002fed0
/*    2fdb4:	00000000 */ 	nop
/*    2fdb8:	00084080 */ 	sll	$t0,$t0,0x2
/*    2fdbc:	3c017005 */ 	lui	$at,0x7005
/*    2fdc0:	00280821 */ 	addu	$at,$at,$t0
/*    2fdc4:	8c28437c */ 	lw	$t0,0x437c($at)
/*    2fdc8:	01000008 */ 	jr	$t0
/*    2fdcc:	00000000 */ 	nop
/*    2fdd0:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    2fdd4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    2fdd8:	e528000c */ 	swc1	$f8,0xc($t1)
/*    2fddc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    2fde0:	24010002 */ 	li	$at,0x2
/*    2fde4:	15410006 */ 	bne	$t2,$at,.PF0002fe00
/*    2fde8:	00000000 */ 	nop
/*    2fdec:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    2fdf0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    2fdf4:	46005487 */ 	neg.s	$f18,$f10
/*    2fdf8:	10000004 */ 	b	.PF0002fe0c
/*    2fdfc:	e5720010 */ 	swc1	$f18,0x10($t3)
.PF0002fe00:
/*    2fe00:	44808000 */ 	mtc1	$zero,$f16
/*    2fe04:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    2fe08:	e5900010 */ 	swc1	$f16,0x10($t4)
.PF0002fe0c:
/*    2fe0c:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    2fe10:	3c017005 */ 	lui	$at,0x7005
/*    2fe14:	c42643ac */ 	lwc1	$f6,0x43ac($at)
/*    2fe18:	3c018006 */ 	lui	$at,0x8006
/*    2fe1c:	000d7080 */ 	sll	$t6,$t5,0x2
/*    2fe20:	002e0821 */ 	addu	$at,$at,$t6
/*    2fe24:	c424effc */ 	lwc1	$f4,-0x1004($at)
/*    2fe28:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    2fe2c:	46043203 */ 	div.s	$f8,$f6,$f4
/*    2fe30:	4600428d */ 	trunc.w.s	$f10,$f8
/*    2fe34:	44185000 */ 	mfc1	$t8,$f10
/*    2fe38:	00000000 */ 	nop
/*    2fe3c:	af380008 */ 	sw	$t8,0x8($t9)
/*    2fe40:	10000025 */ 	b	.PF0002fed8
/*    2fe44:	00000000 */ 	nop
/*    2fe48:	44809000 */ 	mtc1	$zero,$f18
/*    2fe4c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    2fe50:	e5120010 */ 	swc1	$f18,0x10($t0)
/*    2fe54:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    2fe58:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    2fe5c:	e530000c */ 	swc1	$f16,0xc($t1)
/*    2fe60:	1000001d */ 	b	.PF0002fed8
/*    2fe64:	00000000 */ 	nop
/*    2fe68:	3c014000 */ 	lui	$at,0x4000
/*    2fe6c:	44812000 */ 	mtc1	$at,$f4
/*    2fe70:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    2fe74:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    2fe78:	46043203 */ 	div.s	$f8,$f6,$f4
/*    2fe7c:	e5480010 */ 	swc1	$f8,0x10($t2)
/*    2fe80:	3c014000 */ 	lui	$at,0x4000
/*    2fe84:	44819000 */ 	mtc1	$at,$f18
/*    2fe88:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    2fe8c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    2fe90:	46125403 */ 	div.s	$f16,$f10,$f18
/*    2fe94:	e570000c */ 	swc1	$f16,0xc($t3)
/*    2fe98:	1000000f */ 	b	.PF0002fed8
/*    2fe9c:	00000000 */ 	nop
/*    2fea0:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    2fea4:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    2fea8:	46003107 */ 	neg.s	$f4,$f6
/*    2feac:	e5840010 */ 	swc1	$f4,0x10($t4)
/*    2feb0:	3c014000 */ 	lui	$at,0x4000
/*    2feb4:	44815000 */ 	mtc1	$at,$f10
/*    2feb8:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    2febc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    2fec0:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*    2fec4:	e5b2000c */ 	swc1	$f18,0xc($t5)
/*    2fec8:	10000003 */ 	b	.PF0002fed8
/*    2fecc:	00000000 */ 	nop
.PF0002fed0:
/*    2fed0:	1000002b */ 	b	.PF0002ff80
/*    2fed4:	00001025 */ 	move	$v0,$zero
.PF0002fed8:
/*    2fed8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    2fedc:	91cf0004 */ 	lbu	$t7,0x4($t6)
/*    2fee0:	31f80080 */ 	andi	$t8,$t7,0x80
/*    2fee4:	1300000a */ 	beqz	$t8,.PF0002ff10
/*    2fee8:	00000000 */ 	nop
/*    2feec:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    2fef0:	c7300010 */ 	lwc1	$f16,0x10($t9)
/*    2fef4:	4600818d */ 	trunc.w.s	$f6,$f16
/*    2fef8:	44043000 */ 	mfc1	$a0,$f6
/*    2fefc:	0c00e638 */ 	jal	alCents2Ratio
/*    2ff00:	00000000 */ 	nop
/*    2ff04:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    2ff08:	10000008 */ 	b	.PF0002ff2c
/*    2ff0c:	e5200000 */ 	swc1	$f0,0x0($t1)
.PF0002ff10:
/*    2ff10:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    2ff14:	3c0142fe */ 	lui	$at,0x42fe
/*    2ff18:	44814000 */ 	mtc1	$at,$f8
/*    2ff1c:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*    2ff20:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    2ff24:	46082280 */ 	add.s	$f10,$f4,$f8
/*    2ff28:	e56a0000 */ 	swc1	$f10,0x0($t3)
.PF0002ff2c:
/*    2ff2c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    2ff30:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    2ff34:	adac0000 */ 	sw	$t4,0x0($t5)
/*    2ff38:	3c0e800a */ 	lui	$t6,0x800a
/*    2ff3c:	8dcebdc0 */ 	lw	$t6,-0x4240($t6)
/*    2ff40:	3c01800a */ 	lui	$at,0x800a
/*    2ff44:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    2ff48:	ac2fbdc0 */ 	sw	$t7,-0x4240($at)
/*    2ff4c:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    2ff50:	13000007 */ 	beqz	$t8,.PF0002ff70
/*    2ff54:	00000000 */ 	nop
/*    2ff58:	93b90037 */ 	lbu	$t9,0x37($sp)
/*    2ff5c:	3c028006 */ 	lui	$v0,0x8006
/*    2ff60:	00194080 */ 	sll	$t0,$t9,0x2
/*    2ff64:	00481021 */ 	addu	$v0,$v0,$t0
/*    2ff68:	10000005 */ 	b	.PF0002ff80
/*    2ff6c:	8c42ee00 */ 	lw	$v0,-0x1200($v0)
.PF0002ff70:
/*    2ff70:	10000003 */ 	b	.PF0002ff80
/*    2ff74:	24024e20 */ 	li	$v0,0x4e20
/*    2ff78:	10000001 */ 	b	.PF0002ff80
/*    2ff7c:	00000000 */ 	nop
.PF0002ff80:
/*    2ff80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2ff84:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    2ff88:	03e00008 */ 	jr	$ra
/*    2ff8c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func000301e4
.late_rodata
glabel var700546c0
.word 0x49742400
glabel var700546c4
.word func000301e4+0x2ec
glabel var700546c8
.word func000301e4+0x2ec
glabel var700546cc
.word func000301e4+0x2ec
glabel var700546d0
.word func000301e4+0x2ec
glabel var700546d4
.word func000301e4+0x364
glabel var700546d8
.word func000301e4+0x384
glabel var700546dc
.word func000301e4+0x364
glabel var700546e0
.word func000301e4+0x384
glabel var700546e4
.word func000301e4+0x3bc
glabel var700546e8
.word func000301e4+0x364
glabel var700546ec
.word func000301e4+0x364
glabel var700546f0
.word func000301e4+0x384
glabel var700546f4
.word 0x48f42400
.text
/*    301e4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    301e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    301ec:	afa40020 */ 	sw	$a0,0x20($sp)
/*    301f0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    301f4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    301f8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    301fc:	93ae002f */ 	lbu	$t6,0x2f($sp)
/*    30200:	29c10064 */ 	slti	$at,$t6,0x64
/*    30204:	14200003 */ 	bnez	$at,.L00030214
/*    30208:	00000000 */ 	nop
/*    3020c:	240f0063 */ 	addiu	$t7,$zero,0x63
/*    30210:	a3af002f */ 	sb	$t7,0x2f($sp)
.L00030214:
/*    30214:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    30218:	2b010080 */ 	slti	$at,$t8,0x80
/*    3021c:	14200003 */ 	bnez	$at,.L0003022c
/*    30220:	00000000 */ 	nop
/*    30224:	2419007f */ 	addiu	$t9,$zero,0x7f
/*    30228:	a3b90037 */ 	sb	$t9,0x37($sp)
.L0003022c:
/*    3022c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    30230:	29010080 */ 	slti	$at,$t0,0x80
/*    30234:	14200003 */ 	bnez	$at,.L00030244
/*    30238:	00000000 */ 	nop
/*    3023c:	2409007f */ 	addiu	$t1,$zero,0x7f
/*    30240:	a3a9003b */ 	sb	$t1,0x3b($sp)
.L00030244:
/*    30244:	3c0a800a */ 	lui	$t2,%hi(freeOscStateList)
/*    30248:	8d4ab870 */ 	lw	$t2,%lo(freeOscStateList)($t2)
/*    3024c:	15400003 */ 	bnez	$t2,.L0003025c
/*    30250:	00000000 */ 	nop
/*    30254:	1000010a */ 	b	.L00030680
/*    30258:	00001025 */ 	or	$v0,$zero,$zero
.L0003025c:
/*    3025c:	3c0b800a */ 	lui	$t3,%hi(freeOscStateList)
/*    30260:	8d6bb870 */ 	lw	$t3,%lo(freeOscStateList)($t3)
/*    30264:	afab001c */ 	sw	$t3,0x1c($sp)
/*    30268:	93ac003b */ 	lbu	$t4,0x3b($sp)
/*    3026c:	15800009 */ 	bnez	$t4,.L00030294
/*    30270:	00000000 */ 	nop
/*    30274:	3c013f80 */ 	lui	$at,0x3f80
/*    30278:	44812000 */ 	mtc1	$at,$f4
/*    3027c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    30280:	e5a40018 */ 	swc1	$f4,0x18($t5)
/*    30284:	44803000 */ 	mtc1	$zero,$f6
/*    30288:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    3028c:	10000013 */ 	b	.L000302dc
/*    30290:	e5c6001c */ 	swc1	$f6,0x1c($t6)
.L00030294:
/*    30294:	44804000 */ 	mtc1	$zero,$f8
/*    30298:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3029c:	e5e80018 */ 	swc1	$f8,0x18($t7)
/*    302a0:	93b8003b */ 	lbu	$t8,0x3b($sp)
/*    302a4:	3c088006 */ 	lui	$t0,%hi(var8005f150)
/*    302a8:	3c01467a */ 	lui	$at,0x467a
/*    302ac:	0018c880 */ 	sll	$t9,$t8,0x2
/*    302b0:	01194021 */ 	addu	$t0,$t0,$t9
/*    302b4:	8d08f150 */ 	lw	$t0,%lo(var8005f150)($t0)
/*    302b8:	44819000 */ 	mtc1	$at,$f18
/*    302bc:	3c013f80 */ 	lui	$at,0x3f80
/*    302c0:	44885000 */ 	mtc1	$t0,$f10
/*    302c4:	44813000 */ 	mtc1	$at,$f6
/*    302c8:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    302cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    302d0:	46128103 */ 	div.s	$f4,$f16,$f18
/*    302d4:	46043203 */ 	div.s	$f8,$f6,$f4
/*    302d8:	e528001c */ 	swc1	$f8,0x1c($t1)
.L000302dc:
/*    302dc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    302e0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    302e4:	a16a0004 */ 	sb	$t2,0x4($t3)
/*    302e8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    302ec:	a5800014 */ 	sh	$zero,0x14($t4)
/*    302f0:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    302f4:	3c017005 */ 	lui	$at,%hi(var700546c0)
/*    302f8:	c42a46c0 */ 	lwc1	$f10,%lo(var700546c0)($at)
/*    302fc:	3c018006 */ 	lui	$at,%hi(var8005f34c)
/*    30300:	000d7080 */ 	sll	$t6,$t5,0x2
/*    30304:	002e0821 */ 	addu	$at,$at,$t6
/*    30308:	c430f34c */ 	lwc1	$f16,%lo(var8005f34c)($at)
/*    3030c:	3c01467a */ 	lui	$at,0x467a
/*    30310:	44813000 */ 	mtc1	$at,$f6
/*    30314:	46105483 */ 	div.s	$f18,$f10,$f16
/*    30318:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3031c:	46069103 */ 	div.s	$f4,$f18,$f6
/*    30320:	444ff800 */ 	cfc1	$t7,$31
/*    30324:	44d8f800 */ 	ctc1	$t8,$31
/*    30328:	00000000 */ 	nop
/*    3032c:	46002224 */ 	cvt.w.s	$f8,$f4
/*    30330:	4458f800 */ 	cfc1	$t8,$31
/*    30334:	00000000 */ 	nop
/*    30338:	33010004 */ 	andi	$at,$t8,0x4
/*    3033c:	33180078 */ 	andi	$t8,$t8,0x78
/*    30340:	13000014 */ 	beqz	$t8,.L00030394
/*    30344:	00000000 */ 	nop
/*    30348:	3c014f00 */ 	lui	$at,0x4f00
/*    3034c:	44814000 */ 	mtc1	$at,$f8
/*    30350:	24180001 */ 	addiu	$t8,$zero,0x1
/*    30354:	46082201 */ 	sub.s	$f8,$f4,$f8
/*    30358:	44d8f800 */ 	ctc1	$t8,$31
/*    3035c:	00000000 */ 	nop
/*    30360:	46004224 */ 	cvt.w.s	$f8,$f8
/*    30364:	4458f800 */ 	cfc1	$t8,$31
/*    30368:	00000000 */ 	nop
/*    3036c:	33010004 */ 	andi	$at,$t8,0x4
/*    30370:	33180078 */ 	andi	$t8,$t8,0x78
/*    30374:	17000005 */ 	bnez	$t8,.L0003038c
/*    30378:	00000000 */ 	nop
/*    3037c:	44184000 */ 	mfc1	$t8,$f8
/*    30380:	3c018000 */ 	lui	$at,0x8000
/*    30384:	10000007 */ 	b	.L000303a4
/*    30388:	0301c025 */ 	or	$t8,$t8,$at
.L0003038c:
/*    3038c:	10000005 */ 	b	.L000303a4
/*    30390:	2418ffff */ 	addiu	$t8,$zero,-1
.L00030394:
/*    30394:	44184000 */ 	mfc1	$t8,$f8
/*    30398:	00000000 */ 	nop
/*    3039c:	0700fffb */ 	bltz	$t8,.L0003038c
/*    303a0:	00000000 */ 	nop
.L000303a4:
/*    303a4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    303a8:	44cff800 */ 	ctc1	$t7,$31
/*    303ac:	a7380016 */ 	sh	$t8,0x16($t9)
/*    303b0:	00000000 */ 	nop
/*    303b4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    303b8:	24083e80 */ 	addiu	$t0,$zero,0x3e80
/*    303bc:	ad280008 */ 	sw	$t0,0x8($t1)
/*    303c0:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    303c4:	448a5000 */ 	mtc1	$t2,$f10
/*    303c8:	05410005 */ 	bgez	$t2,.L000303e0
/*    303cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    303d0:	3c014f80 */ 	lui	$at,0x4f80
/*    303d4:	44819000 */ 	mtc1	$at,$f18
/*    303d8:	00000000 */ 	nop
/*    303dc:	46128400 */ 	add.s	$f16,$f16,$f18
.L000303e0:
/*    303e0:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*    303e4:	93ab002b */ 	lbu	$t3,0x2b($sp)
/*    303e8:	316c0080 */ 	andi	$t4,$t3,0x80
/*    303ec:	11800027 */ 	beqz	$t4,.L0003048c
/*    303f0:	00000000 */ 	nop
/*    303f4:	444df800 */ 	cfc1	$t5,$31
/*    303f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    303fc:	44c4f800 */ 	ctc1	$a0,$31
/*    30400:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    30404:	46003124 */ 	cvt.w.s	$f4,$f6
/*    30408:	4444f800 */ 	cfc1	$a0,$31
/*    3040c:	00000000 */ 	nop
/*    30410:	30810004 */ 	andi	$at,$a0,0x4
/*    30414:	30840078 */ 	andi	$a0,$a0,0x78
/*    30418:	10800014 */ 	beqz	$a0,.L0003046c
/*    3041c:	00000000 */ 	nop
/*    30420:	3c014f00 */ 	lui	$at,0x4f00
/*    30424:	44812000 */ 	mtc1	$at,$f4
/*    30428:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3042c:	46043101 */ 	sub.s	$f4,$f6,$f4
/*    30430:	44c4f800 */ 	ctc1	$a0,$31
/*    30434:	00000000 */ 	nop
/*    30438:	46002124 */ 	cvt.w.s	$f4,$f4
/*    3043c:	4444f800 */ 	cfc1	$a0,$31
/*    30440:	00000000 */ 	nop
/*    30444:	30810004 */ 	andi	$at,$a0,0x4
/*    30448:	30840078 */ 	andi	$a0,$a0,0x78
/*    3044c:	14800005 */ 	bnez	$a0,.L00030464
/*    30450:	00000000 */ 	nop
/*    30454:	44042000 */ 	mfc1	$a0,$f4
/*    30458:	3c018000 */ 	lui	$at,0x8000
/*    3045c:	10000007 */ 	b	.L0003047c
/*    30460:	00812025 */ 	or	$a0,$a0,$at
.L00030464:
/*    30464:	10000005 */ 	b	.L0003047c
/*    30468:	2404ffff */ 	addiu	$a0,$zero,-1
.L0003046c:
/*    3046c:	44042000 */ 	mfc1	$a0,$f4
/*    30470:	00000000 */ 	nop
/*    30474:	0480fffb */ 	bltz	$a0,.L00030464
/*    30478:	00000000 */ 	nop
.L0003047c:
/*    3047c:	44cdf800 */ 	ctc1	$t5,$31
/*    30480:	0c00bf18 */ 	jal	func0002fc60
/*    30484:	00000000 */ 	nop
/*    30488:	e7a00018 */ 	swc1	$f0,0x18($sp)
.L0003048c:
/*    3048c:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    30490:	2401ff7f */ 	addiu	$at,$zero,-129
/*    30494:	01c17824 */ 	and	$t7,$t6,$at
/*    30498:	a3af002b */ 	sb	$t7,0x2b($sp)
/*    3049c:	93b8002b */ 	lbu	$t8,0x2b($sp)
/*    304a0:	2401ff7f */ 	addiu	$at,$zero,-129
/*    304a4:	0301c824 */ 	and	$t9,$t8,$at
/*    304a8:	2728fffe */ 	addiu	$t0,$t9,-2
/*    304ac:	2d01000c */ 	sltiu	$at,$t0,0xc
/*    304b0:	10200047 */ 	beqz	$at,.L000305d0
/*    304b4:	00000000 */ 	nop
/*    304b8:	00084080 */ 	sll	$t0,$t0,0x2
/*    304bc:	3c017005 */ 	lui	$at,%hi(var700546c4)
/*    304c0:	00280821 */ 	addu	$at,$at,$t0
/*    304c4:	8c2846c4 */ 	lw	$t0,%lo(var700546c4)($at)
/*    304c8:	01000008 */ 	jr	$t0
/*    304cc:	00000000 */ 	nop
/*    304d0:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    304d4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    304d8:	e528000c */ 	swc1	$f8,0xc($t1)
/*    304dc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    304e0:	24010002 */ 	addiu	$at,$zero,0x2
/*    304e4:	15410006 */ 	bne	$t2,$at,.L00030500
/*    304e8:	00000000 */ 	nop
/*    304ec:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    304f0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    304f4:	46005487 */ 	neg.s	$f18,$f10
/*    304f8:	10000004 */ 	b	.L0003050c
/*    304fc:	e5720010 */ 	swc1	$f18,0x10($t3)
.L00030500:
/*    30500:	44808000 */ 	mtc1	$zero,$f16
/*    30504:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    30508:	e5900010 */ 	swc1	$f16,0x10($t4)
.L0003050c:
/*    3050c:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    30510:	3c017005 */ 	lui	$at,%hi(var700546f4)
/*    30514:	c42646f4 */ 	lwc1	$f6,%lo(var700546f4)($at)
/*    30518:	3c018006 */ 	lui	$at,%hi(var8005f34c)
/*    3051c:	000d7080 */ 	sll	$t6,$t5,0x2
/*    30520:	002e0821 */ 	addu	$at,$at,$t6
/*    30524:	c424f34c */ 	lwc1	$f4,%lo(var8005f34c)($at)
/*    30528:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3052c:	46043203 */ 	div.s	$f8,$f6,$f4
/*    30530:	4600428d */ 	trunc.w.s	$f10,$f8
/*    30534:	44185000 */ 	mfc1	$t8,$f10
/*    30538:	00000000 */ 	nop
/*    3053c:	af380008 */ 	sw	$t8,0x8($t9)
/*    30540:	10000025 */ 	b	.L000305d8
/*    30544:	00000000 */ 	nop
/*    30548:	44809000 */ 	mtc1	$zero,$f18
/*    3054c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    30550:	e5120010 */ 	swc1	$f18,0x10($t0)
/*    30554:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    30558:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3055c:	e530000c */ 	swc1	$f16,0xc($t1)
/*    30560:	1000001d */ 	b	.L000305d8
/*    30564:	00000000 */ 	nop
/*    30568:	3c014000 */ 	lui	$at,0x4000
/*    3056c:	44812000 */ 	mtc1	$at,$f4
/*    30570:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    30574:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    30578:	46043203 */ 	div.s	$f8,$f6,$f4
/*    3057c:	e5480010 */ 	swc1	$f8,0x10($t2)
/*    30580:	3c014000 */ 	lui	$at,0x4000
/*    30584:	44819000 */ 	mtc1	$at,$f18
/*    30588:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    3058c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    30590:	46125403 */ 	div.s	$f16,$f10,$f18
/*    30594:	e570000c */ 	swc1	$f16,0xc($t3)
/*    30598:	1000000f */ 	b	.L000305d8
/*    3059c:	00000000 */ 	nop
/*    305a0:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    305a4:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    305a8:	46003107 */ 	neg.s	$f4,$f6
/*    305ac:	e5840010 */ 	swc1	$f4,0x10($t4)
/*    305b0:	3c014000 */ 	lui	$at,0x4000
/*    305b4:	44815000 */ 	mtc1	$at,$f10
/*    305b8:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    305bc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    305c0:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*    305c4:	e5b2000c */ 	swc1	$f18,0xc($t5)
/*    305c8:	10000003 */ 	b	.L000305d8
/*    305cc:	00000000 */ 	nop
.L000305d0:
/*    305d0:	1000002b */ 	b	.L00030680
/*    305d4:	00001025 */ 	or	$v0,$zero,$zero
.L000305d8:
/*    305d8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    305dc:	91cf0004 */ 	lbu	$t7,0x4($t6)
/*    305e0:	31f80080 */ 	andi	$t8,$t7,0x80
/*    305e4:	1300000a */ 	beqz	$t8,.L00030610
/*    305e8:	00000000 */ 	nop
/*    305ec:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    305f0:	c7300010 */ 	lwc1	$f16,0x10($t9)
/*    305f4:	4600818d */ 	trunc.w.s	$f6,$f16
/*    305f8:	44043000 */ 	mfc1	$a0,$f6
/*    305fc:	0c00e7f8 */ 	jal	alCents2Ratio
/*    30600:	00000000 */ 	nop
/*    30604:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    30608:	10000008 */ 	b	.L0003062c
/*    3060c:	e5200000 */ 	swc1	$f0,0x0($t1)
.L00030610:
/*    30610:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    30614:	3c0142fe */ 	lui	$at,0x42fe
/*    30618:	44814000 */ 	mtc1	$at,$f8
/*    3061c:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*    30620:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    30624:	46082280 */ 	add.s	$f10,$f4,$f8
/*    30628:	e56a0000 */ 	swc1	$f10,0x0($t3)
.L0003062c:
/*    3062c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    30630:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    30634:	adac0000 */ 	sw	$t4,0x0($t5)
/*    30638:	3c0e800a */ 	lui	$t6,%hi(freeOscStateList)
/*    3063c:	8dceb870 */ 	lw	$t6,%lo(freeOscStateList)($t6)
/*    30640:	3c01800a */ 	lui	$at,%hi(freeOscStateList)
/*    30644:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    30648:	ac2fb870 */ 	sw	$t7,%lo(freeOscStateList)($at)
/*    3064c:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    30650:	13000007 */ 	beqz	$t8,.L00030670
/*    30654:	00000000 */ 	nop
/*    30658:	93b90037 */ 	lbu	$t9,0x37($sp)
/*    3065c:	3c028006 */ 	lui	$v0,%hi(var8005f150)
/*    30660:	00194080 */ 	sll	$t0,$t9,0x2
/*    30664:	00481021 */ 	addu	$v0,$v0,$t0
/*    30668:	10000005 */ 	b	.L00030680
/*    3066c:	8c42f150 */ 	lw	$v0,%lo(var8005f150)($v0)
.L00030670:
/*    30670:	10000003 */ 	b	.L00030680
/*    30674:	24023e80 */ 	addiu	$v0,$zero,0x3e80
/*    30678:	10000001 */ 	b	.L00030680
/*    3067c:	00000000 */ 	nop
.L00030680:
/*    30680:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    30684:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    30688:	03e00008 */ 	jr	$ra
/*    3068c:	00000000 */ 	nop
);
#endif

ALMicroTime updateOscMain(oscData *statePtr, f32 *updateVal)
{
	f32 sp24;
	f32 sp20;
	f32 sp1c;

	if ((statePtr->type & ~0x80) >= 6) {
		statePtr->unk14++;

		if (statePtr->unk14 >= statePtr->unk16) {
			statePtr->unk14 = 0;
		}

		sp20 = (f32)statePtr->unk14 / (f32)statePtr->unk16;
	}

	if (statePtr->unk1c != 0.0f) {
		statePtr->unk18 += statePtr->unk1c;

		if (statePtr->unk18 >= 1.0f) {
			statePtr->unk18 = 1.0f;
			statePtr->unk1c = 0.0f;
		}
	}

	sp24 = statePtr->unk0c;

	if (statePtr->unk18 != 1.0f) {
		sp24 *= statePtr->unk18;
	}

	switch (statePtr->type & ~0x80) {
	case 2:
	case 3:
	case 4:
	case 5:
		if (statePtr->unk14) {
			sp20 = sp24;
		} else {
			sp20 = statePtr->unk10;
		}
		statePtr->unk14 ^= 1;
		break;
	case 6:
	case 7:
		if (sp20 < 0.25f) {
			sp20 *= 4.0f * sp24;
		} else if (sp20 >= 0.75f) {
			sp20 -= 0.75f;
			sp20 *= 4.0f * sp24;
			sp20 -= sp24;
		} else {
			sp20 -= 0.25f;
			sp20 *= 4.0f * sp24;
			sp20 = sp24 - sp20;
		}
		sp20 += statePtr->unk10;
		break;
	case 8:
	case 9:
		sp20 = func000301a4(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		break;
	case 10:
	case 11:
		sp20 *= sp24;
		sp20 += statePtr->unk10;
		break;
	case 12:
	case 13:
		if (sp20 < 0.25f) {
			sp20 *= 4.0f * sp24;
		} else if (sp20 >= 0.75f) {
			sp20 -= 0.75f;
			sp20 *= 4.0f * sp24;
			sp20 -= sp24;
		} else {
			sp20 -= 0.25f;
			sp20 *= 4.0f * sp24;
			sp20 = sp24 - sp20;
		}

		sp1c = statePtr->unk10 + sp20;
		sp20 = (f32)statePtr->unk14 / (f32)statePtr->unk16;
		sp20 = func000301a4(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		sp20 += sp1c;
		sp20 /= 2.0f;
		break;
	}

	if (statePtr->type & 0x80) {
		*updateVal = alCents2Ratio(sp20);
	} else {
		*updateVal = sp20 + 127;
	}

	return statePtr->curCount;
}

void func00030bd8(void *oscState)
{
	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

void func00030bfc(s32 arg0, s32 count)
{
	oscData *item;
	s32 i;

	freeOscStateList = &oscStates[0];
	item = &oscStates[0];

	for (i = 0; i < count - 1; i++) {
		item->next = &oscStates[i + 1];
		item = item->next;
	}

	item->next = NULL;
}

void func00030c98(ALSeqpConfig *config)
{
	config->initOsc = initOsc;
	config->updateOsc = updateOsc;
	config->stopOsc = stopOsc;

	return;
}
