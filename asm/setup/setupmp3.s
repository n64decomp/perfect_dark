#
# Area 52 (MP)
#

.set HEADERLEN, 0x20
.include "asm/include/setup.inc"

props:
	endprops

intro:
	outfit OUTFIT_DEFAULT
	endintro

paths:
	endpaths

func1000_0038:
	cmd01b2_mponly 20
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

functions:
	register_function func1000_0038 0x1000
	endfunctions

.align 4
