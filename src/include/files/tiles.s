# Tile files are implemented here using assembly macros because it doesn't
# appear to be possible to do it in C in a sane way. Some rooms have no tiles,
# and you cannot declare an empty array in C.

.data

.set FLOORTYPE_DEFAULT, 0
.set FLOORTYPE_WOOD,    1
.set FLOORTYPE_STONE,   2
.set FLOORTYPE_CARPET,  3
.set FLOORTYPE_METAL,   4
.set FLOORTYPE_MUD,     5
.set FLOORTYPE_WATER,   6
.set FLOORTYPE_DIRT,    7
.set FLOORTYPE_SNOW,    8

.set TILEFLAG_0001,           0x0001
.set TILEFLAG_0002,           0x0002
.set TILEFLAG_0004,           0x0004
.set TILEFLAG_0008,           0x0008
.set TILEFLAG_0010,           0x0010
.set TILEFLAG_0020,           0x0020
.set TILEFLAG_LADDER,         0x0040
.set TILEFLAG_0080,           0x0080
.set TILEFLAG_0100,           0x0100
.set TILEFLAG_UNDERWATER,     0x0200
.set TILEFLAG_0400,           0x0400
.set TILEFLAG_AIBOTCROUCH,    0x0800
.set TILEFLAG_AIBOTDUCK,      0x1000
.set TILEFLAG_2000,           0x2000
.set TILEFLAG_DIE,            0x4000
.set TILEFLAG_CLIMBABLELEDGE, 0x8000

.set VERSION_NTSC_BETA,  0
.set VERSION_NTSC_1_0,   1
.set VERSION_NTSC_FINAL, 2
.set VERSION_PAL_BETA,   3
.set VERSION_PAL_FINAL,  4
.set VERSION_JPN_FINAL,  5

.macro tileabstract numverts, flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour
	.byte  0
	.byte  \numverts
	.short \flags
	.short \floortype
	.byte  \xmin
	.byte  \ymin
	.byte  \zmin
	.byte  \xmax
	.byte  \ymax
	.byte  \zmax
	.short \floorcolour
.endm

.macro tilevert x, y, z
	.short \x
	.short \y
	.short \z
.endm

.macro tile3 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3
	tileabstract 3, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
.endm

.macro tile4 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4
	tileabstract 4, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
.endm

.macro tile5 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5
	tileabstract 5, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
.endm

.macro tile6 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6
	tileabstract 6, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
.endm

.macro tile7 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7
	tileabstract 7, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
.endm

.macro tile8 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8
	tileabstract 8, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
	tilevert \x8, \y8, \z8
.endm

.macro tile9 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9
	tileabstract 9, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
	tilevert \x8, \y8, \z8
	tilevert \x9, \y9, \z9
.endm

.macro tile11 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10, x11, y11, z11
	tileabstract 11, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
	tilevert \x8, \y8, \z8
	tilevert \x9, \y9, \z9
	tilevert \x10, \y10, \z10
	tilevert \x11, \y11, \z11
.endm

.macro tile12 flags, floortype, xmin, ymin, zmin, xmax, ymax, zmax, floorcolour, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10, x11, y11, z11, x12, y12, z12
	tileabstract 12, \flags, \floortype, \xmin, \ymin, \zmin, \xmax, \ymax, \zmax, \floorcolour
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
	tilevert \x8, \y8, \z8
	tilevert \x9, \y9, \z9
	tilevert \x10, \y10, \z10
	tilevert \x11, \y11, \z11
	tilevert \x12, \y12, \z12
.endm
