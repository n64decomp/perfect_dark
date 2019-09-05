#
# Stage ID 0x3f
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
	cmd0185_mponly
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

functions:
	register_function func1000_0038 0x1000
	endfunctions

.align 4
