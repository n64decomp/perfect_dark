#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel seg_get_data_start
	lui   $v0, %hi(_dataSegmentStart)
	jr    $ra
	addiu $v0, $v0, %lo(_dataSegmentStart)

glabel seg_get_datazip_rom_start
	lui   $v0, %hi(_datazipSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_datazipSegmentRomStart)

glabel seg_get_inflate_rom_start
	lui   $v0, %hi(_inflateSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_inflateSegmentRomStart)

glabel seg_get_inflate_rom_start2
	lui   $v0, %hi(_inflateSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_inflateSegmentRomStart)

glabel seg_get_gamezips_rom_start
	lui   $v0, %hi(_gamezipSegmentRomStart)
	jr    $ra
	addiu $v0, $v0, %lo(_gamezipSegmentRomStart)

glabel seg_inflate
	lui   $a3, %hi(inflate1173)
	addiu $a3, $a3, %lo(inflate1173)
	jr    $a3
	nop
