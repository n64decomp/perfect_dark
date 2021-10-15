#include "n_synthInternals.h"
#include <os.h>

/*
 * WARNING: THE FOLLOWING CONSTANT MUST BE KEPT IN SYNC
 * WITH SCALING IN MICROCODE!!!
 */
#define	SCALE 16384.0f

/*
 * the following arrays contain default parameters for
 * a few hopefully useful effects.
 */
#define ms *(((s32)((f32)44.1))&~0x7)

s32 SMALLROOM_PARAMS_N[26] = {
	/* sections	 length */
	3,           55 ms,
	/*                                        chorus  chorus  filter
	input    output   fbcoef  ffcoef  gain    rate    depth   coef  */
	0    ms, 29.6 ms, 9830,   -9830,  0,      0,      0,      0,
	10.4 ms, 20.8 ms, 3276,   -3276,  0x3fff, 0,      0,      0,
	0    ms, 33   ms, 5000,   0,      0,      0,      0,      0x5000,
};

s32 BIGROOM_PARAMS_N[10] = {
	0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};

GLOBAL_ASM(
glabel func0003b710
.late_rodata
glabel var70054ac0
.word 0x40490fdb
glabel var70054ac4
.word 0x3fb504f4
.text
/*    3b710:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3b714:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3b718:	afa60030 */ 	sw	$a2,0x30($sp)
/*    3b71c:	afa70034 */ 	sw	$a3,0x34($sp)
/*    3b720:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*    3b724:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*    3b728:	3c014348 */ 	lui	$at,0x4348
/*    3b72c:	44814000 */ 	mtc1	$at,$f8
/*    3b730:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*    3b734:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*    3b738:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    3b73c:	4604503e */ 	c.le.s	$f10,$f4
/*    3b740:	00000000 */ 	nop
/*    3b744:	45000006 */ 	bc1f	.L0003b760
/*    3b748:	00000000 */ 	nop
/*    3b74c:	3c014348 */ 	lui	$at,0x4348
/*    3b750:	44819000 */ 	mtc1	$at,$f18
/*    3b754:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*    3b758:	46128181 */ 	sub.s	$f6,$f16,$f18
/*    3b75c:	e7a6002c */ 	swc1	$f6,0x2c($sp)
.L0003b760:
/*    3b760:	3c017005 */ 	lui	$at,%hi(var70054ac0)
/*    3b764:	c4244ac0 */ 	lwc1	$f4,%lo(var70054ac0)($at)
/*    3b768:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*    3b76c:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*    3b770:	46044282 */ 	mul.s	$f10,$f8,$f4
/*    3b774:	460083a1 */ 	cvt.d.s	$f14,$f16
/*    3b778:	0fc259d4 */ 	jal	atan2f
/*    3b77c:	46005321 */ 	cvt.d.s	$f12,$f10
/*    3b780:	44829000 */ 	mtc1	$v0,$f18
/*    3b784:	00000000 */ 	nop
/*    3b788:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    3b78c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*    3b790:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    3b794:	46084102 */ 	mul.s	$f4,$f8,$f8
/*    3b798:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    3b79c:	3c017005 */ 	lui	$at,%hi(var70054ac4)
/*    3b7a0:	c4304ac4 */ 	lwc1	$f16,%lo(var70054ac4)($at)
/*    3b7a4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*    3b7a8:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    3b7ac:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3b7b0:	46069203 */ 	div.s	$f8,$f18,$f6
/*    3b7b4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    3b7b8:	3c013f80 */ 	lui	$at,0x3f80
/*    3b7bc:	44812000 */ 	mtc1	$at,$f4
/*    3b7c0:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*    3b7c4:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*    3b7c8:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    3b7cc:	460a2400 */ 	add.s	$f16,$f4,$f10
/*    3b7d0:	46128180 */ 	add.s	$f6,$f16,$f18
/*    3b7d4:	46065203 */ 	div.s	$f8,$f10,$f6
/*    3b7d8:	e5c80000 */ 	swc1	$f8,0x0($t6)
/*    3b7dc:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3b7e0:	3c014000 */ 	lui	$at,0x4000
/*    3b7e4:	44818000 */ 	mtc1	$at,$f16
/*    3b7e8:	c5e40000 */ 	lwc1	$f4,0x0($t7)
/*    3b7ec:	46102482 */ 	mul.s	$f18,$f4,$f16
/*    3b7f0:	e5f20004 */ 	swc1	$f18,0x4($t7)
/*    3b7f4:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    3b7f8:	c70a0000 */ 	lwc1	$f10,0x0($t8)
/*    3b7fc:	e70a0008 */ 	swc1	$f10,0x8($t8)
/*    3b800:	3c013f80 */ 	lui	$at,0x3f80
/*    3b804:	44814000 */ 	mtc1	$at,$f8
/*    3b808:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    3b80c:	3c014000 */ 	lui	$at,0x4000
/*    3b810:	44818000 */ 	mtc1	$at,$f16
/*    3b814:	46083101 */ 	sub.s	$f4,$f6,$f8
/*    3b818:	3c013f80 */ 	lui	$at,0x3f80
/*    3b81c:	44815000 */ 	mtc1	$at,$f10
/*    3b820:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    3b824:	46102482 */ 	mul.s	$f18,$f4,$f16
/*    3b828:	46065200 */ 	add.s	$f8,$f10,$f6
/*    3b82c:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*    3b830:	46044400 */ 	add.s	$f16,$f8,$f4
/*    3b834:	46109283 */ 	div.s	$f10,$f18,$f16
/*    3b838:	e72a0004 */ 	swc1	$f10,0x4($t9)
/*    3b83c:	3c013f80 */ 	lui	$at,0x3f80
/*    3b840:	44813000 */ 	mtc1	$at,$f6
/*    3b844:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    3b848:	44815000 */ 	mtc1	$at,$f10
/*    3b84c:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*    3b850:	46083100 */ 	add.s	$f4,$f6,$f8
/*    3b854:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    3b858:	46085180 */ 	add.s	$f6,$f10,$f8
/*    3b85c:	46122401 */ 	sub.s	$f16,$f4,$f18
/*    3b860:	46123100 */ 	add.s	$f4,$f6,$f18
/*    3b864:	46048283 */ 	div.s	$f10,$f16,$f4
/*    3b868:	e50a0008 */ 	swc1	$f10,0x8($t0)
/*    3b86c:	10000001 */ 	b	.L0003b874
/*    3b870:	00000000 */ 	nop
.L0003b874:
/*    3b874:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3b878:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3b87c:	03e00008 */ 	jr	$ra
/*    3b880:	00000000 */ 	nop
);

void _init_lpfilter(ALLowPass *lp)
{
	s32 i, temp;
	s16 fc;
	f32 ffc, fcoef;
	f32 scale;

	temp = lp->fc * SCALE;
	fc = temp >> 15;
	lp->fgain = SCALE - fc;

	lp->first = 0;

	for (i = 0; i < 8; i++) {
		lp->fcvec.fccoef[i] = 0;
	}

	lp->fcvec.fccoef[i++] = fc;
	scale = SCALE;
	fcoef = ffc = fc / scale;

	for (; i < 16; i++) {
		fcoef *= ffc;
		lp->fcvec.fccoef[i] = (s16)(fcoef * scale);
	}
}

f32 func0003b9d4(s32 arg0)
{
	f32 mult;
	f32 value;

	value = 1.0f;

	if (arg0 >= 0) {
		mult = 1.0594631433487f;
	} else {
		mult = 0.94387429952621f;
		arg0 = -arg0;
	}

	while (arg0) {
		if (arg0 & 1) {
			value *= mult;
		}

		mult *= mult;
		arg0 >>= 1;
	}

	return value;
}

GLOBAL_ASM(
glabel func0003ba64
.late_rodata
glabel var70054ad0
.word 0x46d12000
glabel var70054ad4
.word 0x46d12000
.text
/*    3ba64:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    3ba68:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3ba6c:	afa40040 */ 	sw	$a0,0x40($sp)
/*    3ba70:	afa50044 */ 	sw	$a1,0x44($sp)
/*    3ba74:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    3ba78:	85cf0002 */ 	lh	$t7,0x2($t6)
/*    3ba7c:	15e00003 */ 	bnez	$t7,.L0003ba8c
/*    3ba80:	00000000 */ 	nop
/*    3ba84:	1000006e */ 	b	.L0003bc40
/*    3ba88:	00000000 */ 	nop
.L0003ba8c:
/*    3ba8c:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    3ba90:	87190002 */ 	lh	$t9,0x2($t8)
/*    3ba94:	2b21000a */ 	slti	$at,$t9,0xa
/*    3ba98:	10200004 */ 	beqz	$at,.L0003baac
/*    3ba9c:	00000000 */ 	nop
/*    3baa0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    3baa4:	2408000a */ 	addiu	$t0,$zero,0xa
/*    3baa8:	a5280002 */ 	sh	$t0,0x2($t1)
.L0003baac:
/*    3baac:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bab0:	3c014120 */ 	lui	$at,0x4120
/*    3bab4:	44819000 */ 	mtc1	$at,$f18
/*    3bab8:	854c0002 */ 	lh	$t4,0x2($t2)
/*    3babc:	854b0000 */ 	lh	$t3,0x0($t2)
/*    3bac0:	44814000 */ 	mtc1	$at,$f8
/*    3bac4:	448c5000 */ 	mtc1	$t4,$f10
/*    3bac8:	448b2000 */ 	mtc1	$t3,$f4
/*    3bacc:	27ad0024 */ 	addiu	$t5,$sp,0x24
/*    3bad0:	46805420 */ 	cvt.s.w	$f16,$f10
/*    3bad4:	afad0010 */ 	sw	$t5,0x10($sp)
/*    3bad8:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*    3badc:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    3bae0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3bae4:	46128103 */ 	div.s	$f4,$f16,$f18
/*    3bae8:	46083380 */ 	add.s	$f14,$f6,$f8
/*    3baec:	44062000 */ 	mfc1	$a2,$f4
/*    3baf0:	0c00edc4 */ 	jal	func0003b710
/*    3baf4:	00000000 */ 	nop
/*    3baf8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    3bafc:	afae003c */ 	sw	$t6,0x3c($sp)
.L0003bb00:
/*    3bb00:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3bb04:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    3bb08:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3bb0c:	01f94021 */ 	addu	$t0,$t7,$t9
/*    3bb10:	a5000008 */ 	sh	$zero,0x8($t0)
/*    3bb14:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    3bb18:	252b0001 */ 	addiu	$t3,$t1,0x1
/*    3bb1c:	29610008 */ 	slti	$at,$t3,0x8
/*    3bb20:	1420fff7 */ 	bnez	$at,.L0003bb00
/*    3bb24:	afab003c */ 	sw	$t3,0x3c($sp)
/*    3bb28:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bb2c:	3c014300 */ 	lui	$at,0x4300
/*    3bb30:	44815000 */ 	mtc1	$at,$f10
/*    3bb34:	854c0002 */ 	lh	$t4,0x2($t2)
/*    3bb38:	3c017005 */ 	lui	$at,%hi(var70054ad0)
/*    3bb3c:	c4324ad0 */ 	lwc1	$f18,%lo(var70054ad0)($at)
/*    3bb40:	448c3000 */ 	mtc1	$t4,$f6
/*    3bb44:	27ad0030 */ 	addiu	$t5,$sp,0x30
/*    3bb48:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3bb4c:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*    3bb50:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    3bb54:	46109101 */ 	sub.s	$f4,$f18,$f16
/*    3bb58:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    3bb5c:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3bb60:	44185000 */ 	mfc1	$t8,$f10
/*    3bb64:	00000000 */ 	nop
/*    3bb68:	a5580008 */ 	sh	$t8,0x8($t2)
/*    3bb6c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    3bb70:	3c014300 */ 	lui	$at,0x4300
/*    3bb74:	44813000 */ 	mtc1	$at,$f6
/*    3bb78:	85f90002 */ 	lh	$t9,0x2($t7)
/*    3bb7c:	3c017005 */ 	lui	$at,%hi(var70054ad4)
/*    3bb80:	c4284ad4 */ 	lwc1	$f8,%lo(var70054ad4)($at)
/*    3bb84:	44999000 */ 	mtc1	$t9,$f18
/*    3bb88:	27a80030 */ 	addiu	$t0,$sp,0x30
/*    3bb8c:	46809420 */ 	cvt.s.w	$f16,$f18
/*    3bb90:	c5120004 */ 	lwc1	$f18,0x4($t0)
/*    3bb94:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    3bb98:	46044281 */ 	sub.s	$f10,$f8,$f4
/*    3bb9c:	460a9402 */ 	mul.s	$f16,$f18,$f10
/*    3bba0:	4600818d */ 	trunc.w.s	$f6,$f16
/*    3bba4:	440b3000 */ 	mfc1	$t3,$f6
/*    3bba8:	00000000 */ 	nop
/*    3bbac:	a5eb000a */ 	sh	$t3,0xa($t7)
/*    3bbb0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3bbb4:	a580000c */ 	sh	$zero,0xc($t4)
/*    3bbb8:	27ad0024 */ 	addiu	$t5,$sp,0x24
/*    3bbbc:	3c01c680 */ 	lui	$at,0xc680
/*    3bbc0:	44812000 */ 	mtc1	$at,$f4
/*    3bbc4:	c5a80004 */ 	lwc1	$f8,0x4($t5)
/*    3bbc8:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bbcc:	46044482 */ 	mul.s	$f18,$f8,$f4
/*    3bbd0:	4600928d */ 	trunc.w.s	$f10,$f18
/*    3bbd4:	44185000 */ 	mfc1	$t8,$f10
/*    3bbd8:	00000000 */ 	nop
/*    3bbdc:	a5580018 */ 	sh	$t8,0x18($t2)
/*    3bbe0:	27b90024 */ 	addiu	$t9,$sp,0x24
/*    3bbe4:	3c01c680 */ 	lui	$at,0xc680
/*    3bbe8:	44813000 */ 	mtc1	$at,$f6
/*    3bbec:	c7300008 */ 	lwc1	$f16,0x8($t9)
/*    3bbf0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    3bbf4:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    3bbf8:	4600410d */ 	trunc.w.s	$f4,$f8
/*    3bbfc:	44092000 */ 	mfc1	$t1,$f4
/*    3bc00:	00000000 */ 	nop
/*    3bc04:	a569001a */ 	sh	$t1,0x1a($t3)
/*    3bc08:	240f000a */ 	addiu	$t7,$zero,0xa
/*    3bc0c:	afaf003c */ 	sw	$t7,0x3c($sp)
.L0003bc10:
/*    3bc10:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    3bc14:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3bc18:	000d7040 */ 	sll	$t6,$t5,0x1
/*    3bc1c:	018ec021 */ 	addu	$t8,$t4,$t6
/*    3bc20:	a7000008 */ 	sh	$zero,0x8($t8)
/*    3bc24:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    3bc28:	25590001 */ 	addiu	$t9,$t2,0x1
/*    3bc2c:	2b210010 */ 	slti	$at,$t9,0x10
/*    3bc30:	1420fff7 */ 	bnez	$at,.L0003bc10
/*    3bc34:	afb9003c */ 	sw	$t9,0x3c($sp)
/*    3bc38:	10000001 */ 	b	.L0003bc40
/*    3bc3c:	00000000 */ 	nop
.L0003bc40:
/*    3bc40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3bc44:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    3bc48:	03e00008 */ 	jr	$ra
/*    3bc4c:	00000000 */ 	nop
);

void n_alFxNew(ALFx **fx_ar, ALSynConfig *c, s16 bus, ALHeap *hp)
{
	u16 i, j, k;
	s32 *param = 0;
	ALDelay	*d;
	ALFx *r;

	*fx_ar = r = (ALFx *)alHeapAlloc(hp, 1, sizeof(ALFx));

	switch (c->fxTypes[bus]) {
	case 6:
		param = c->params[bus];
		break;
	default:
		param = BIGROOM_PARAMS_N;
		break;
	}

	j = 0;

	r->section_count = param[j++];
	r->length = param[j++];

	r->delay = alHeapAlloc(hp, r->section_count, sizeof(ALDelay));
	r->base = alHeapAlloc(hp, r->length, sizeof(s16));
	r->input = r->base;
	r->unk24 = alHeapAlloc(hp, r->length, sizeof(s16));
	r->unk2c = r->unk24;

	for (k=0; k < r->length; k++) {
		r->base[k] = r->unk24[k] = 0;
	}

	for ( i=0; i<r->section_count; i++ ){
		d = &r->delay[i];
		d->input  = param[j++];
		d->output = param[j++];
		d->fbcoef = param[j++];
		d->ffcoef = param[j++];
		d->gain   = param[j++];

		if (param[j]) {
#define RANGE 2.0f
			/*	    d->rsinc     = ((f32) param[j++])/0xffffff; */
			d->rsinc = ((((f32)param[j++])/1000) * RANGE)/c->outputRate;

			/*
			 * the following constant is derived from:
			 *
			 *		ratio = 2^(cents/1200)
			 *
			 * and therefore for hundredths of a cent
			 *			           x
			 *		ln(ratio) = ---------------
			 *			    (120,000)/ln(2)
			 * where
			 *		120,000/ln(2) = 173123.40...
			 */
#define CONVERT 173123.404906676f
#define LENGTH	(d->output - d->input)
			d->rsgain 	 = (((f32) param[j++])/CONVERT) * LENGTH;
			d->rsval	 = 1.0f;
			d->rsdelta	 = 0.0f;
			d->rs 	 = alHeapAlloc(hp, 1, sizeof(ALResampler));
			d->rs->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
			d->rs->unk18 = alHeapAlloc(hp, 1, 0x20);
			d->rs->delta = 0.0f;
			d->rs->first = 1;
		} else {
			d->rs = 0;
			j++;
			j++;
		}

		if (param[j]) {
			d->lp = alHeapAlloc(hp, 1, sizeof(ALLowPass));
			d->lp->fstate = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
			d->lp->unk30 = alHeapAlloc(hp, 1, 8);
			d->lp->fc = param[j++];
			_init_lpfilter(d->lp);
		} else {
			d->lp = 0;
			j++;
		}
	}
}

void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp)
{
	mv->dc_state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
	mv->dc_lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
	mv->dc_dma = dmaNew(&mv->dc_dmaState);
	mv->dc_lastsam = 0;
	mv->dc_first = 1;
	mv->dc_memin = 0;

	mv->rs_state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
	mv->rs_delta  = 0.0f;
	mv->rs_first  = 1;
	mv->rs_ratio = 1.0f;
	mv->rs_upitch = 0;

	mv->em_state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
	mv->em_first = 1;
	mv->em_motion = AL_STOPPED;
	mv->em_volume = 1;
	mv->em_ltgt = 1;
	mv->em_rtgt = 1;
	mv->em_cvolL = 1;
	mv->em_cvolR = 1;
	mv->em_dryamt = 0;
	mv->em_wetamt = 0;
	mv->em_lratm = 1;
	mv->em_lratl = 0;
	mv->em_lratm = 1;
	mv->em_lratl = 0;
	mv->em_delta = 0;
	mv->em_segEnd = 0;
	mv->em_pan = 0;
	mv->em_ctrlList = 0;
	mv->em_ctrlTail = 0;
	mv->unk8c = 0;
	mv->unk92 = 0;
	mv->unk90 = 0;
	mv->unkbc = alHeapAlloc(hp, 1, 8);
	mv->unkb8 = 0;
}
