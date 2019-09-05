# vi: ft=asm

.macro register_path label id param
	.word  \label
	.byte  \id
	.byte  \param
	.short 0
.endm

.macro endpaths
	.word 0
	.word 0
.endm

.macro beginpath id flags
	.byte \id
	.byte 0
	.short \flags
.endm

.macro pad pad_id
	.word \pad_id
.endm

.macro endpath
	.word 0xffffffff
.endm
