#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel segGetDataStart
	lui   $v0, %hi(_dataSegmentStart)
	jr    $ra
	addiu $v0, $v0, %lo(_dataSegmentStart)

glabel segGetDatazipRomStart
	lui   $v0, %hi(_datazipSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_datazipSegmentRomStart)

glabel segGetInflateRomStart
	lui   $v0, %hi(_inflateSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_inflateSegmentRomStart)

glabel segGetInflateRomStart2
	lui   $v0, %hi(_inflateSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_inflateSegmentRomStart)

glabel segGetGamezipsRomStart
	lui   $v0, %hi(_gamezipSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_gamezipSegmentRomStart)

glabel bootInflate
	lui   $a3, %hi(inflate1173)
	addiu $a3, $a3, %lo(inflate1173)
	jr    $a3
	nop
