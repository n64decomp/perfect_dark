extern void *_dataSegmentStart;
extern void *_datazipSegmentRomStart;
extern void *_inflateSegmentRomStart;
extern void *_gamezipSegmentRomStart;

void *segGetDataStart(void)
{
	return &_dataSegmentStart;
}

void *segGetDatazipRomStart(void)
{
	return &_datazipSegmentRomStart;
}

void *segGetInflateRomStart(void)
{
	return &_inflateSegmentRomStart;
}

void *segGetInflateRomStart2(void)
{
	return &_inflateSegmentRomStart;
}

void *segGetGamezipsRomStart(void)
{
	return &_gamezipSegmentRomStart;
}

GLOBAL_ASM(
glabel bootInflate
/*     16ac:	3c077020 */ 	lui	$a3,%hi(inflate1173)
/*     16b0:	24e7126c */ 	addiu	$a3,$a3,%lo(inflate1173)
/*     16b4:	00e00008 */ 	jr	$a3
/*     16b8:	00000000 */ 	nop
/*     16bc:	00000000 */ 	nop
);
