#
# Pipes (MP)
#

.set HEADERLEN, 0x20
.include "asm/include/setup.inc"

props:
	endprops

intro:
	intro_weapon WEAPON_FALCON2, -1
	ammo AMMOTYPE_PISTOL, 100
	endintro

paths:
	endpaths

functions:
	endfunctions

.align 4
