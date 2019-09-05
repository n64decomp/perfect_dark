#
# Stage ID 0x3a
#

.set HEADERLEN, 0x20
.include "asm/include/setup.inc"

props:
	endprops

intro:
	endintro

path00:
	endpath

paths:
	endpaths

unregistered_func1:
	endfunction

unregistered_func2:
	cmd0185_mponly
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

functions:
	endfunctions

.align 4
