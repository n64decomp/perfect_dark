# Tile files are implemented here using assembly macros because it doesn't
# appear to be possible to do it in C in a sane way. Some rooms have no tiles,
# and you cannot declare an empty array in C.

.data

.set VERSION_NTSC_BETA,  0
.set VERSION_NTSC_1_0,   1
.set VERSION_NTSC_FINAL, 2
.set VERSION_PAL_BETA,   3
.set VERSION_PAL_FINAL,  4
.set VERSION_JPN_FINAL,  5

.macro tileabstract numverts, ai, flags, u4, u6, u8, ua, uc
	.short \numverts
	.byte  \ai
	.byte  \flags
	.short \u4
	.short \u6
	.short \u8
	.short \ua
	.short \uc
.endm

.macro tilevert x, y, z
	.short \x
	.short \y
	.short \z
.endm

.macro tile3 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3
	tileabstract 3, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
.endm

.macro tile4 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4
	tileabstract 4, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
.endm

.macro tile5 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5
	tileabstract 5, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
.endm

.macro tile6 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6
	tileabstract 6, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
.endm

.macro tile7 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7
	tileabstract 7, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
.endm

.macro tile8 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8
	tileabstract 8, \ai, \flags, \u4, \u6, \u8, \ua, \uc
	tilevert \x1, \y1, \z1
	tilevert \x2, \y2, \z2
	tilevert \x3, \y3, \z3
	tilevert \x4, \y4, \z4
	tilevert \x5, \y5, \z5
	tilevert \x6, \y6, \z6
	tilevert \x7, \y7, \z7
	tilevert \x8, \y8, \z8
.endm

.macro tile9 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9
	tileabstract 9, \ai, \flags, \u4, \u6, \u8, \ua, \uc
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

.macro tile11 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10, x11, y11, z11
	tileabstract 11, \ai, \flags, \u4, \u6, \u8, \ua, \uc
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

.macro tile12 ai, flags, u4, u6, u8, ua, uc, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10, x11, y11, z11, x12, y12, z12
	tileabstract 12, \ai, \flags, \u4, \u6, \u8, \ua, \uc
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
