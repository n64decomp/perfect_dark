#
# Complex (MP)
#

.set HEADERLEN, 0x20
.include "asm/include/setup.inc"

props:
	endprops

intro:
	intro_weapon WEAPON_PP9I, -1
	ammo AMMOTYPE_PISTOL, 100
	outfit OUTFIT_DEFAULT
	endintro

paths:
	endpaths

functions:
	endfunctions

.align 4
