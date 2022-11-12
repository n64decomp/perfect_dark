#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel segInflate
	lui   $a3, %hi(inflate1173)
	addiu $a3, $a3, %lo(inflate1173)
	jr    $a3
	nop
