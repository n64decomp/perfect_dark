#include "asm_helper.h"
.set noat
.set noreorder

.text
LEAF(segGetDataStart)
	lui   v0, %hi(_dataSegmentStart)
	jr    ra
	addiu v0, v0, %lo(_dataSegmentStart)
END(segGetDataStart)

LEAF(segGetDatazipRomStart)
	lui   v0, %hi(_datazipSegmentRomStart)
	jr    ra
	addiu v0, v0, %lo(_datazipSegmentRomStart)
END(segGetDatazipRomStart)

LEAF(segGetInflateRomStart)
	lui   v0, %hi(_inflateSegmentRomStart)
	jr    ra
	addiu v0, v0, %lo(_inflateSegmentRomStart)
END(segGetInflateRomStart)

LEAF(segGetInflateRomStart2)
	lui   v0, %hi(_inflateSegmentRomStart)
	jr    ra
	addiu v0, v0, %lo(_inflateSegmentRomStart)
END(segGetInflateRomStart2)

LEAF(segGetGamezipsRomStart)
	lui   v0, %hi(_gamezipSegmentRomStart)
	jr    ra
	addiu v0, v0, %lo(_gamezipSegmentRomStart)
END(segGetGamezipsRomStart)

LEAF(bootInflate)
	lui   a3, %hi(inflate1173)
	addiu a3, a3, %lo(inflate1173)
	jr    a3
	nop
END(bootInflate)
