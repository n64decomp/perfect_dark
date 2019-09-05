# vi: ft=asm

.macro spawn pad
	.word 0x00000000
	.word \pad
	.word 0
.endm

.macro intro_weapon weapon u1
	.word 0x00000001
	.word \weapon
	.word \u1
	.word 0
.endm

.macro ammo ammotype value
	.word 0x00000002
	.word \ammotype
	.word \value
	.word 0
.endm

.macro outfit outfit
	.word 0x00000005
	.word \outfit
.endm

.macro case id pad
	.word 0x00000009
	.word \id
	.word \pad
.endm

.macro case_respawn id pad
	.word 0x0000000a
	.word \id
	.word \pad
.endm

.macro hill room
	.word 0x0000000b
	.word \room
.endm

.macro endintro
	.word 0x0000000c
.endm
