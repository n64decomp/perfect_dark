/* GNU as assembler macros for F3D GBI */

/* commands with no parameters */
.macro f3d_noparam cmd
   .word (\cmd << 24), 0x00000000
.endm

.macro gsImmp1 cmd, param
   .word (\cmd << 24), \param
.endm

/* DMA helper */
.macro gsDma1p cmd, segAddr, length, params
   .byte \cmd, \params
   .hword \length
   .word \segAddr
.endm

/* 01: G_MTX */
/* params */
.set G_MTX_MODELVIEW,  0x00
.set G_MTX_PROJECTION, 0x01
.set G_MTX_MUL,        0x00
.set G_MTX_LOAD,       0x02
.set G_MTX_NOPUSH,     0x00
.set G_MTX_PUSH,       0x04

.set G_MTX, 0x01
.macro gsSPMatrix matrix, params
   gsDma1p G_MTX, \matrix, 64, \params
.endm

/* 02: reserved */

/* 03: G_MOVEMEM */
.set G_MOVEMEM, 0x03
.set G_MV_L0, 0x86
.macro gsSPLight light, num
   gsDma1p G_MOVEMEM, \light, 16, ((\num)-1)*2+G_MV_L0
.endm

/* 04: G_VTX */
.set G_VTX, 0x04
.macro gsSPVertex verts, num, index
   gsDma1p G_VTX, \verts, 16*\num, ((\num)-1)<<4|(\index)
.endm

/* 05: reserved */

/* 06: G_DL */
.set G_DL, 0x06
.set G_DL_PUSH,   0x00
.set G_DL_NOPUSH, 0x01
.macro gsSPDisplayList dl
   gsDma1p G_DL, \dl, 0, G_DL_PUSH
.endm
.macro gsSPBranchList dl
   gsDma1p G_DL, \dl, 0, G_DL_NOPUSH
.endm

/* geometry mode flags */
.set G_ZBUFFER,            0x00000001
.set G_SHADE,              0x00000004
.set G_SHADING_SMOOTH,     0x00000200
.set G_CULL_FRONT,         0x00001000
.set G_CULL_BACK,          0x00002000
.set G_FOG,                0x00010000
.set G_LIGHTING,           0x00020000
.set G_TEXTURE_GEN,        0x00040000
.set G_TEXTURE_GEN_LINEAR, 0x00080000

/* B3: G_RDPHALF_2 */
.set G_RDPHALF_2, 0xB3

/* B4: G_RDPHALF_1 */
.set G_RDPHALF_1, 0xB4

/* B6: G_CLEARGEOMETRYMODE */
.set G_CLEARGEOMETRYMODE, 0xB6
.macro gsSPClearGeometryMode flags
   .word G_CLEARGEOMETRYMODE << 24
   .word \flags
.endm

/* B7: G_SETGEOMETRYMODE */
.set G_SETGEOMETRYMODE, 0xB7
.macro gsSPSetGeometryMode flags
   .word G_SETGEOMETRYMODE << 24
   .word \flags
.endm

/* B8: G_ENDDL */
.set G_ENDDL, 0xB8
.macro gsSPEndDisplayList
   f3d_noparam G_ENDDL
.endm

/* B9: G_SETOTHERMODE_L */
.set G_SETOTHERMODE_L, 0xB9
/* G_SETOTHERMODE_L sft: shift count */
.set G_MDSFT_ALPHACOMPARE, 0
.set G_MDSFT_ZSRCSEL,      2
.set G_MDSFT_RENDERMODE,   3
.set G_MDSFT_BLENDER,     16

/* BA: G_SETOTHERMODE_H */
.set G_SETOTHERMODE_H, 0xBA
/* G_SETOTHERMODE_H sft: shift count */
.set G_MDSFT_ALPHADITHER,  4
.set G_MDSFT_RGBDITHER,    6
.set G_MDSFT_COMBKEY,      8
.set G_MDSFT_TEXTCONV,     9
.set G_MDSFT_TEXTFILT,    12
.set G_MDSFT_TEXTLUT,     14
.set G_MDSFT_TEXTLOD,     16
.set G_MDSFT_TEXTDETAIL,  17
.set G_MDSFT_TEXTPERSP,   19
.set G_MDSFT_CYCLETYPE,   20
.set G_MDSFT_PIPELINE,    23

.macro gsSPSetOtherMode cmd, sft, len, data
   .word ((\cmd & 0xFF) << 24) | ((\sft & 0xFF) << 8) | (\len & 0xFF)
   .word \data
.endm

/* BB: G_TEXTURE */
.set G_TEXTURE, 0xBB
.macro gsSPTexture scaleS, scaleT, level, tile, enable
   .word (G_TEXTURE << 24) | ((\level & 0x7) << 11) | ((\tile & 0x7) << 8) | \enable
   .word ((\scaleS & 0xFFFF) << 16) | (\scaleT & 0xFFFF)
.endm

/* BC: G_MOVEWORD */
.set G_MOVEWORD, 0xBC
.macro gsMoveWd index, offset, data
   .word G_MOVEWORD << 24 | ((\index & 0xFFFF) << 8) | (\offset & 0xFF)
   .word \data
.endm

/* BF: G_TRI1 */
.set G_TRI1, 0xBF
.macro gsSP1Triangle v0, v1, v2, flag
   .word G_TRI1 << 24
   .byte \flag, \v0*10, \v1*10, \v2*10
.endm

/* C0: G_NOOP */
.set G_NOOP, 0xC0
.macro gsDPNoOp
   f3d_noparam G_NOOP
.endm

/* E6: G_RDPLOADSYNC */
.set G_RDPLOADSYNC, 0xE6
.macro gsDPLoadSync
   f3d_noparam G_RDPLOADSYNC
.endm

/* E7: G_RDPPIPESYNC */
.set G_RDPPIPESYNC, 0xE7
.macro gsDPPipeSync
   f3d_noparam G_RDPPIPESYNC
.endm

/* E8: G_RDPTILESYNC */
.set G_RDPTILESYNC, 0xE8
.macro gsDPTileSync
   f3d_noparam G_RDPTILESYNC
.endm

/* E9: G_RDPFULLSYNC */
.set G_RDPFULLSYNC, 0xE9
.macro gsDPFullSync
   f3d_noparam G_RDPFULLSYNC
.endm

/* F0: G_LOADTLUT */
.set G_LOADTLUT, 0xF0
.macro gsDPLoadTLUTCmd tile, count
   .word G_LOADTLUT << 24
   .word ((\tile & 0x7) << 24) | (\count & 0x3FFF) << 10
.endm

/* F1: unused */

/* F2: G_SETTILESIZE */
.set G_SETTILESIZE, 0xF2
.macro gsDPSetTileSize tile, uls, ult, lrs, lrt
   .word (G_SETTILESIZE << 24) | ((\uls & 0x0FFF) << 12) | (\ult & 0x0FFF)
   .word ((\tile & 0x7) << 24) | ((\lrs & 0x0FFF) << 12) | (\lrt & 0x0FFF)
.endm

/* F3: G_LOADBLOCK */
.set G_LOADBLOCK, 0xF3
.macro gsDPLoadBlock tile, uls, ult, lrs, dxt
   .word (G_LOADBLOCK << 24) | ((\uls & 0x0FFF) << 12) | (\ult & 0x0FFF)
   .word ((\tile & 0x7) << 24) | ((\lrs & 0x0FFF) << 12) | (\dxt & 0x0FFF)
.endm

/* F5: G_SETTILE */
.set G_TX_LOADTILE,   0x7
.set G_TX_RENDERTILE, 0x0

/* axis clamp and mirror flags */
.set G_TX_NOMIRROR,   0x0
.set G_TX_WRAP,       0x0
.set G_TX_MIRROR,     0x1
.set G_TX_CLAMP,      0x2

/* mask flags */
.set G_TX_NOMASK,     0x0

/* shift flags */
.set G_TX_NOLOD,      0x0

.set G_SETTILE, 0xF5
.macro gsDPSetTile fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts
   .word (G_SETTILE << 24) | ((\fmt & 0x7) << 21) | ((\siz & 0x3) << 19) | ((\line & 0x1FF) << 9) | (\tmem & 0x1FF)
   .word ((\tile & 0x7) << 24) | ((\palette & 0xF) << 20) | ((\cmt & 0x3) << 18) | ((\maskt & 0xF) << 14) | ((\shiftt & 0xF) << 10) | ((\cms & 0x3) << 8) | ((\masks & 0xF) << 4) | (\shifts & 0xF)
.endm

/* F6: G_FILLRECT */
.set G_FILLRECT, 0xF6
.macro gsDPFillRectangle ulx, uly, lrx, lry
   .word (G_FILLRECT << 24) | ((\lrx & 0x3FF) << 14) | ((\lry & 0x3FF) << 2)
   .word                      ((\ulx & 0x3FF) << 14) | ((\uly & 0x3FF) << 2)
.endm

/* F7: G_SETFILLCOLOR */
.set G_SETFILLCOLOR, 0xF7
.macro gsDPSetFillColor fillValue
   .word G_SETFILLCOLOR << 24
   .word \fillValue
.endm

/* helper for RGBA colors */
.macro sDPRGBColor cmd r, g, b, a
   .word \cmd << 24
   .byte \r, \g, \b, \a
.endm

/* F8: G_SETFOGCOLOR */
.set G_SETFOGCOLOR, 0xF8
.macro gsDPSetFogColor r, g, b, a
   sDPRGBColor G_SETFOGCOLOR, \r, \g, \b, \a
.endm

/* F9: G_SETBLENDCOLOR */
.set G_SETBLENDCOLOR, 0xF9
.macro gsDPSetBlendColor r, g, b, a
   sDPRGBColor G_SETBLENDCOLOR, \r, \g, \b, \a
.endm

/* FA: G_SETPRIMCOLOR */
.set G_SETPRIMCOLOR, 0xFA
.macro gsDPSetPrimColor m, l, r, g, b, a
   .word (G_SETPRIMCOLOR << 24) | ((\m & 0xFF) << 8) | (\l & 0xFF)
   .byte \r, \g, \b, \a
.endm

/* FB: G_SETENVCOLOR */
.set G_SETENVCOLOR, 0xFB
.macro gsDPSetEnvColor r, g, b, a
   sDPRGBColor G_SETENVCOLOR, \r, \g, \b, \a
.endm

/* FC: G_SETCOMBINE */
/* color combiner */
.set G_CCMUX_COMBINED,         0
.set G_CCMUX_TEXEL0,           1
.set G_CCMUX_TEXEL1,           2
.set G_CCMUX_PRIMITIVE,        3
.set G_CCMUX_SHADE,            4
.set G_CCMUX_ENVIRONMENT,      5
.set G_CCMUX_CENTER,           6
.set G_CCMUX_SCALE,            6
.set G_CCMUX_COMBINED_ALPHA,   7
.set G_CCMUX_TEXEL0_ALPHA,     8
.set G_CCMUX_TEXEL1_ALPHA,     9
.set G_CCMUX_PRIMITIVE_ALPHA, 10
.set G_CCMUX_SHADE_ALPHA,     11
.set G_CCMUX_ENV_ALPHA,       12
.set G_CCMUX_LOD_FRACTION,    13
.set G_CCMUX_PRIM_LOD_FRAC,   14
.set G_CCMUX_NOISE,            7
.set G_CCMUX_K4,               7
.set G_CCMUX_K5,              15
.set G_CCMUX_1,                6
.set G_CCMUX_0,               31

/* alpha combiner */
.set G_ACMUX_COMBINED,      0
.set G_ACMUX_TEXEL0,        1
.set G_ACMUX_TEXEL1,        2
.set G_ACMUX_PRIMITIVE,     3
.set G_ACMUX_SHADE,         4
.set G_ACMUX_ENVIRONMENT,   5
.set G_ACMUX_LOD_FRACTION,  0
.set G_ACMUX_PRIM_LOD_FRAC, 6
.set G_ACMUX_1,             6
.set G_ACMUX_0,             7

.set G_SETCOMBINE, 0xFC
.macro gsDPSetCombine muxs0, muxs1
   .word (G_SETCOMBINE << 24) | (\muxs0 & 0x00FFFFFF)
   .word \muxs1
.endm
.macro gsDPSetCombineMode a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1
   .word (G_SETCOMBINE << 24) | ((\a0 & 0xF) << 20) | ((\c0 & 0x1F) << 15) | ((\Aa0 & 0x7) << 12) | ((\Ac0 & 0x7) << 9) | ((\a1 & 0xF) << 5) | (\c1 & 0x1F)
   .word ((\b0 & 0xF) << 28) | ((\b1 & 0xF) << 24) | ((\Aa1 & 0x7) << 21) | ((\Ac1 & 0x7) << 18) | ((\d0 & 0x7) << 15) | ((\Ab0 & 0x7) << 12) | ((\Ad0 & 0x7) << 9) | ((\d1 & 0x7) << 6) | ((\Ab1 & 0x7) << 3) | (\Ad1 & 0x7)
.endm

/* FD: G_SETTIMG */
/* fmt */
.set G_IM_FMT_RGBA, 0x00
.set G_IM_FMT_YUV,  0x01
.set G_IM_FMT_CI,   0x02
.set G_IM_FMT_IA,   0x03
.set G_IM_FMT_I,    0x04

/* size */
.set G_IM_SIZ_4b,   0x00
.set G_IM_SIZ_8b,   0x01
.set G_IM_SIZ_16b,  0x02
.set G_IM_SIZ_32b,  0x03

.set G_SETTIMG, 0xFD
.macro gsDPSetTextureImage fmt, size, width, segAddr
   .word (G_SETTIMG << 24) | ((\fmt & 0x7) << 21) | ((\size & 0x3) << 19) | ((\width-1) & 0x0FFF)
   .word \segAddr
.endm

