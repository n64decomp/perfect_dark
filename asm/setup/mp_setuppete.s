#
# Chicago
#

.set HEADERLEN, 0x40
.include "asm/include/setup.inc"

props:
	briefing 0, 0x0020
	briefing 1, 0x0024
	briefing 2, 0x0028
	briefing 3, 0x002c
	briefing 4, 0x0030

	beginobjective 0, 0x0034, DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD
	endobjective

	beginobjective 1, 0x0038, DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD
	endobjective

	beginobjective 2, 0x003c, DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD
	endobjective
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

text_stagename:
	.ascii "S T .  P E T E R S B U R G\n"
	.byte  0x00

	.align 2

text_briefing1:
	.ascii "use the stolen tank to chase the car containing natalya. you are up against a time limit.\n"
	.byte  0x00

	.align 2

text_briefing2:
	.ascii "\n"
	.byte  0x00

	.align 2

text_briefing3:
	.ascii "\n"
	.byte  0x00

	.align 2

text_briefing4:
	.ascii "\n"
	.byte  0x00

	.align 2

text_objective1:
	.ascii "\n\n\n"
	.byte  0x00

	.align 2

text_objective2:
	.ascii "\n\n\n"
	.byte  0x00

	.align 2

text_objective3:
	.ascii "\n"
	.byte  0x00

	.align 2

.align 4
