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

void func0003b710(f32 outputrate, f32 arg1, f32 arg4, f32 *arg5, f32 *arg6);

void func0003ba64(struct fx *fx, f32 outputrate)
{
	s32 i;
	f32 sp30[3];
	f32 sp24[3];

	if (fx->unk02 == 0) {
		return;
	}

	if (fx->unk02 < 10) {
		fx->unk02 = 10;
	}

	func0003b710(outputrate, fx->unk00 + 10.0f, fx->unk02 / 10.0f, sp30, sp24);

	for (i = 3; i < 8; i++) {
		fx->unk08[i] = 0;
	}

	fx->unk08[0] = sp30[0] * (26768 - fx->unk02 * 128.0f);
	fx->unk08[1] = sp30[1] * (26768 - fx->unk02 * 128.0f);
	fx->unk08[2] = 0;
	fx->unk08[8] = sp24[1] * -16384;
	fx->unk08[9] = sp24[2] * -16384;

	for (i = 10; i < 16; i++) {
		fx->unk08[i] = 0;
	}
}

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
