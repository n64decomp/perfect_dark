#ifndef _ULTRA64_GBI_H_
#define _ULTRA64_GBI_H_

/* Types */

/* Vertex (set up for use with colors) */
typedef struct
{
    short          ob[3];  /* x, y, z */
    unsigned short flag;
    short          tc[2];  /* texture coord */
    unsigned char  cn[4];  /* color & alpha */
} Vtx_t;

/* Vertex (set up for use with normals) */
typedef struct
{
    short          ob[3];  /* x, y, z */
    unsigned short flag;
    short          tc[2];  /* texture coord */
    signed char    n[3];   /* normal */
    unsigned char  a;      /* alpha  */
} Vtx_tn;

typedef union
{
    Vtx_t         v;  /* Use this one for colors  */
    Vtx_tn        n;  /* Use this one for normals */
    long long int force_structure_alignment;
} Vtx;


typedef struct
{
    short vscale[4];  /* scale, 2 bits fraction */
    short vtrans[4];  /* translate, 2 bits fraction */
} Vp_t;

typedef union
{
    Vp_t          vp;
    long long int force_structure_alignment;
} Vp;


typedef struct
{
    unsigned int w0;
    unsigned int w1;
} Gwords;

/* TODO: fill in the rest of the members */
typedef union
{
    Gwords words;
    long long int force_structure_alignment;
} Gfx;


#define _SHIFTL(value, shift, size) \
    ((unsigned int) (((unsigned int) (value) & ((1 << size) - 1)) << shift))

#define G_ON  1
#define G_OFF 0

#define GPACK_RGBA5551(r, g, b, a) \
    ((((r) << 8) & 0xF800) | \
    (((g) << 3) & 0x07C0) | \
    (((b) >> 2) & 0x003E) | \
    ((a) & 0x0001))
#define GPACK_ZDZ(z, dz) ((z) << 2 | (dz))


#define G_ZBUFFER            0x00000001
#define G_TEXTURE_ENABLE     0x00000002
#define G_SHADE              0x00000004
#define G_SHADING_SMOOTH     0x00000200
#define G_CULL_FRONT         0x00001000
#define G_CULL_BACK          0x00002000
#define G_CULL_BOTH          0x00003000
#define G_FOG                0x00010000
#define G_LIGHTING           0x00020000
#define G_TEXTURE_GEN        0x00040000
#define G_TEXTURE_GEN_LINEAR 0x00080000
#define G_LOD                0x00100000
#define G_CLIPPING           0x00800000

#define G_IM_FMT_RGBA   0
#define G_IM_FMT_YUV    1
#define G_IM_FMT_CI     2
#define G_IM_FMT_IA     3
#define G_IM_FMT_I      4

#define G_IM_SIZ_4b  0
#define G_IM_SIZ_8b  1
#define G_IM_SIZ_16b 2
#define G_IM_SIZ_32b 3
#define G_IM_SIZ_DD  5

#define G_AC_NONE      (0 << 0)
#define G_AC_THRESHOLD (1 << 0)
#define G_AC_DITHER    (3 << 0)

#define G_ZS_PIXEL (0 << 2)
#define G_ZS_PRIM  (1 << 2)

#define G_CD_MAGICSQ (0 << 6)
#define G_CD_BAYER   (1 << 6)
#define G_CD_NOISE   (2 << 6)

#define G_CK_NONE (0 << 8)
#define G_CK_KEY  (1 << 8)

#define G_TC_CONV     (0 << 9)
#define G_TC_FILTCONV (5 << 9)
#define G_TC_FILT     (6 << 9)

#define G_TF_POINT   (0 << 12)
#define G_TF_BILERP  (2 << 12)
#define G_TF_AVERAGE (3 << 12)

#define G_TT_NONE   (0 << 14)
#define G_TT_RGBA16 (2 << 14)
#define G_TT_IA16   (3 << 14)

#define G_TL_TILE (0 << 16)
#define G_TL_LOD  (1 << 16)

#define G_TD_CLAMP   (0 << 17)
#define G_TD_SHARPEN (1 << 17)
#define G_TD_DETAIL  (2 << 17)

#define G_TP_NONE   (0 << 19)
#define G_TP_PERSP  (1 << 19)

#define G_CYC_1CYCLE (0 << 20)
#define G_CYC_2CYCLE (1 << 20)
#define G_CYC_COPY   (2 << 20)
#define G_CYC_FILL   (3 << 20)

#define G_PM_NPRIMITIVE (0 << 23)
#define G_PM_1PRIMITIVE (1 << 23)

#define G_SC_NON_INTERLACE  0
#define G_SC_ODD_INTERLACE  3
#define G_SC_EVEN_INTERLACE 2

#define G_TX_LOADTILE   7
#define G_TX_RENDERTILE 0

#define G_TX_NOMIRROR 0
#define G_TX_WRAP 0
#define G_TX_MIRROR 1
#define G_TX_CLAMP 2
#define G_TX_NOMASK 0
#define G_TX_NOLOD 0

#define G_TX_LDBLK_MAX_TXL 2047

#define G_MV_VIEWPORT 0x80
#define G_MV_LOOKATY  0x82
#define G_MV_LOOKATX  0x84
#define G_MV_L0       0x86
#define G_MV_L1       0x88
#define G_MV_L2       0x8A
#define G_MV_L3       0x8C
#define G_MV_L4       0x8E
#define G_MV_L5       0x90
#define G_MV_L6       0x92
#define G_MV_L7       0x94
#define G_MV_TXTATT   0x96
#define G_MV_MATRIX_1 0x9E
#define G_MV_MATRIX_2 0x98
#define G_MV_MATRIX_3 0x9A
#define G_MV_MATRIX_4 0x9C

#define G_SETOTHERMODE_L 0xB9
#define G_SETOTHERMODE_H 0xBA

#ifndef MAX
#define MAX(a, b)               ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#endif

#define gSPMatrix(pkt, m, p)                     \
{                                                \
    Gfx *_g = (Gfx *)(pkt);                      \
    _g->words.w0 = _SHIFTL(0x01,        24,  8)  \
                 | _SHIFTL((p),         16,  8)  \
                 | _SHIFTL(sizeof(Mtx),  0, 16); \
    _g->words.w1 = (u32)(m);                     \
}

#define gSPVertex(pkt, v, n, v0)                         \
{                                                        \
    Gfx *_g = (Gfx *)(pkt);                              \
    _g->words.w0 = _SHIFTL(0x04,                24,  8)  \
                 | _SHIFTL(((n)-1) << 4 | (v0), 16,  8)  \
                 | _SHIFTL(sizeof(Vtx)*(n),      0, 16); \
    _g->words.w1 = (u32)(v);                             \
}

#define gDPLoadSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE6000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPPipeSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE7000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPTileSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE8000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPFullSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE9000000; \
    _g->words.w1 = 0x00000000; \
}

#define gSPDisplayList(pkt, dl) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0x06000000; \
    _g->words.w1 = (u32)(dl); \
}

#define gSPBranchList(pkt, dl) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = 0x06010000; \
    _g->words.w1 = (u32)(dl); \
}

#define gSPEndDisplayList(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB8000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPSetCycleType(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001402; \
    _g->words.w1 = type; \
}

#define gDPPipelineMode(pkt, mode) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001701; \
    _g->words.w1 = mode; \
}

#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry)          \
{                                                             \
    Gfx *_g = (Gfx *)(pkt);                                   \
    _g->words.w0 = _SHIFTL(0xED,                     24,  8)  \
                 | _SHIFTL((int)((float)(ulx)*4.0f), 12, 12)  \
                 | _SHIFTL((int)((float)(uly)*4.0f),  0, 12); \
    _g->words.w1 = _SHIFTL((mode),                   24,  8)  \
                 | _SHIFTL((int)((float)(lrx)*4.0f), 12, 12)  \
                 | _SHIFTL((int)((float)(lry)*4.0f),  0, 12); \
}

#define gDPSetCombine(pkt, muxs0, muxs1)    \
{                                           \
    Gfx *_g = (Gfx *)(pkt);                 \
    _g->words.w0 = _SHIFTL(0xFC,   24,  8)  \
                 | _SHIFTL((muxs0), 0, 24); \
    _g->words.w1 = (muxs1);                 \
}

#define gDPSetTextureLOD(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001001; \
    _g->words.w1 = type; \
}

#define gDPSetTextureLUT(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000E02; \
    _g->words.w1 = type; \
}

#define gDPSetTextureDetail(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001102; \
    _g->words.w1 = type; \
}

#define gDPSetTexturePersp(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001301; \
    _g->words.w1 = type; \
}

#define gDPSetTextureFilter(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000C02; \
    _g->words.w1 = type; \
}

#define gDPSetTextureConvert(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000903; \
    _g->words.w1 = type; \
}

#define gDPSetCombineKey(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000801; \
    _g->words.w1 = type; \
}

#define gDPSetColorDither(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000602; \
    _g->words.w1 = type; \
}

#define gDPSetFillColor(pkt, color) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xF7000000; \
    _g->words.w1 = color; \
}

#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) \
{                                                 \
    Gfx *_g = (Gfx *)(pkt);                       \
    _g->words.w0 = _SHIFTL(0xF6,  24,  8)         \
                 | _SHIFTL((lrx), 14, 10)         \
                 | _SHIFTL((lry),  2, 10);        \
    _g->words.w1 = _SHIFTL(0,     24,  8)         \
                 | _SHIFTL((ulx), 14, 10)         \
                 | _SHIFTL((uly),  2, 10);        \
}

#define gDPSetAlphaCompare(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB9000002; \
    _g->words.w1 = type; \
}

#define gDPSetDepthSource(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB9000201; \
    _g->words.w1 = type; \
}

#define gSPSetOtherMode(pkt, cmd, shift, length, data) \
{                                                      \
    Gfx *_g = (Gfx *) (pkt);                           \
    _g->words.w0 = _SHIFTL((cmd),        24, 8)        \
                 | _SHIFTL((shift),       8, 8)        \
                 | _SHIFTL(((length)-1),  0, 8);       \
    _g->words.w1 = (data);                             \
}

#define gDPSetRenderMode(pkt, mode1, mode2) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB900031D; \
    _g->words.w1 = (mode1) | (mode2); \
}

#define gSPClearGeometryMode(pkt, mode) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB6000000; \
    _g->words.w1 = mode; \
}

#define gSPSetGeometryMode(pkt, word) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB7000000; \
    _g->words.w1 = word; \
}

#define gSPNumLights(pkt, n) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBC000002; \
    _g->words.w1 = (0x80000000 + ((n) + 1) * 0x20); \
}

#define gSPTexture(pkt, sc, tc, level, tile, on) \
{                                                \
    Gfx *_g = (Gfx *)(pkt);                      \
    _g->words.w0 = _SHIFTL(0xBB,    24, 8)       \
                 | _SHIFTL(0,       16, 8)       \
                 | _SHIFTL((level), 11, 3)       \
                 | _SHIFTL((tile),   8, 3)       \
                 | _SHIFTL((on),     0, 8);      \
    _g->words.w1 = _SHIFTL((sc), 16, 16)         \
                 | _SHIFTL((tc),  0, 16);        \
}

#define gDPSetColorImage(pkt, fmt, size, width, image) \
{                                                      \
    Gfx *_g = (Gfx *)(pkt);                            \
    _g->words.w0 = _SHIFTL(0xFF,   24, 8)              \
                 | _SHIFTL((fmt),  21, 3)              \
                 | _SHIFTL((size), 19, 2)              \
                 | _SHIFTL((width)-1, 0, 12);          \
    _g->words.w1 = (image);                            \
}

#define gDPSetTileSize(pkt, tile, uls, ult, lrs, lrt) \
{                                                     \
    Gfx *_g = (Gfx *)(pkt);                           \
    _g->words.w0 = _SHIFTL(0xF2, 24, 8)               \
                 | _SHIFTL(uls, 12, 12)               \
                 | _SHIFTL(ult, 0, 12);               \
    _g->words.w1 = _SHIFTL(tile, 24, 3)               \
                 | _SHIFTL(lrs, 12, 12)               \
                 | _SHIFTL(lrt, 0, 12);               \
}

#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt)                  \
{                                                                    \
    Gfx *_g = (Gfx *)(pkt);                                          \
    _g->words.w0 = _SHIFTL(0xF3,   24,  8)                           \
                 | _SHIFTL((uls),  12, 12)                           \
                 | _SHIFTL((ult),   0, 12);                          \
    _g->words.w1 = _SHIFTL((tile),                          24,  3)  \
                 | _SHIFTL((MIN((lrs),G_TX_LDBLK_MAX_TXL)), 12, 12)  \
                 | _SHIFTL((dxt),                            0, 12); \
}

#define gDPSetTile(pkt, fmt, siz, line, tmem, tile,  \
    palette, cmt, maskt, shiftt, cms, masks, shifts) \
{                                                    \
    Gfx *_g = (Gfx *)(pkt);                          \
    _g->words.w0 = _SHIFTL(0xF5,  24, 8)             \
                 | _SHIFTL((fmt), 21, 3)             \
                 | _SHIFTL((siz), 19, 2)             \
                 | _SHIFTL((line), 9, 9)             \
                 | _SHIFTL((tmem), 0, 9);            \
    _g->words.w1 = _SHIFTL((tile),    24, 3)         \
                 | _SHIFTL((palette), 20, 4)         \
                 | _SHIFTL((cmt),     18, 2)         \
                 | _SHIFTL((maskt),   14, 4)         \
                 | _SHIFTL((shiftt),  10, 4)         \
                 | _SHIFTL((cms),      8, 2)         \
                 | _SHIFTL((masks),    4, 4)         \
                 | _SHIFTL((shifts),   0, 4);        \
}

#define gDPSetDepthImage(pkt, image)     \
{                                        \
    Gfx *_g = (Gfx *)(pkt);              \
    _g->words.w0 = _SHIFTL(0xFE, 24, 8); \
    _g->words.w1 = (image);              \
}

#define G_SETPRIMCOLOR 0xFA

#define	gDPSetPrimColor(pkt, m, l, r, g, b, a)     \
{                                                  \
    Gfx *_g = (Gfx *)(pkt);                        \
    _g->words.w0 = _SHIFTL(G_SETPRIMCOLOR, 24, 8)  \
                 | _SHIFTL(m,  8, 8)               \
                 | _SHIFTL(l,  0, 8);              \
    _g->words.w1 = _SHIFTL(r, 24, 8)               \
                 | _SHIFTL(g, 16, 8)               \
                 | _SHIFTL(b,  8, 8)               \
                 | _SHIFTL(a,  0, 8);              \
}

#define gDPSetEnvColor(pkt, r, g, b, a)  \
{                                        \
    Gfx *_g = (Gfx *)(pkt);              \
    _g->words.w0 = _SHIFTL(0xFB, 24, 8); \
    _g->words.w1 = _SHIFTL((r), 24, 8)   \
                 | _SHIFTL((g), 16, 8)   \
                 | _SHIFTL((b),  8, 8)   \
                 | _SHIFTL((a),  0, 8);  \
}

#define gDPSetTextureImage(pkt, fmt, size, width, img) \
{                                                      \
    Gfx *_g = (Gfx *)(pkt);                            \
    _g->words.w0 = _SHIFTL(0xFD,      24,  8)          \
                 | _SHIFTL((fmt),     21,  3)          \
                 | _SHIFTL((size),    19,  2)          \
                 | _SHIFTL((width)-1,  0, 12);         \
    _g->words.w1 = (u32)(img);                         \
}

#define gMoveWd(pkt, index, offset, data)     \
{                                             \
    Gfx *_g = (Gfx *)(pkt);                   \
    _g->words.w0 = _SHIFTL(0xBC,     24,  8)  \
                 | _SHIFTL((offset),  8, 16)  \
                 | _SHIFTL((index),   0,  8); \
    _g->words.w1 = (u32)(data);               \
}

/* Matrix Operations */

#define G_MTX_MODELVIEW  0x00
#define G_MTX_PROJECTION 0x01
#define G_MTX_MUL        0x00
#define G_MTX_LOAD       0x02
#define G_MTX_NOPUSH     0x00
#define G_MTX_PUSH       0x04

#define gSPPopMatrix(pkt, n) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBD000000; \
    _g->words.w1 = (n); \
}

#define gSPViewport(pkt, v)                        \
{                                                  \
    Gfx *_g = (Gfx *)(pkt);                        \
    _g->words.w0 = _SHIFTL(0x03,          24,  8)  \
                 | _SHIFTL(G_MV_VIEWPORT, 16,  8)  \
                 | _SHIFTL(sizeof(Vp),     0, 16); \
    _g->words.w1 = (u32)(v);                       \
}

#define gSP1Triangle(pkt, v0, v1, v2, flag) \
{                                           \
    Gfx *_g = (Gfx *)(pkt);                 \
    _g->words.w0 = _SHIFTL(0xBF, 24, 8);    \
    _g->words.w1 = _SHIFTL((flag),  24, 8)  \
                 | _SHIFTL((v0)*10, 16, 8)  \
                 | _SHIFTL((v1)*10,  8, 8)  \
                 | _SHIFTL((v2)*10,  0, 8); \
}

#if	(defined(F3DLP_GBI)||defined(F3DEX_GBI))
/***
 ***  2 Triangles
 ***/
#define gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1)	\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 = (_SHIFTL(G_TRI2, 24, 8)|				\
			__gsSP1Triangle_w1f(v00, v01, v02, flag0));	\
		_g->words.w1 =  __gsSP1Triangle_w1f(v10, v11, v12, flag1); 	\
}

#define gsSP2Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1)	\
{									\
	(_SHIFTL(G_TRI2, 24, 8)|					\
	 __gsSP1Triangle_w1f(v00, v01, v02, flag0)),			\
	 __gsSP1Triangle_w1f(v10, v11, v12, flag1)			\
}

#endif	/* F3DEX_GBI/F3DLP_GBI */

#if	(defined(TRI4_Ext))
 /***
  ***  4 Triangles - 2Tri Extension
  ***  Draws up to four triangles at a time.
  ***  Expects values from 0-F, corresponding with # points declared by vertex command.
  ***  Triangles with all points set to 0 are not drawn.
  ***  Vertex Buffer reduced to 16 due to only being able to address 0-F
  ***/
#define gSP4Triangles(pkt, v00, v01, v02, v10, v11, v12, \
							v20, v21, v22, v30, v31, v32 )	\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 = (_SHIFTL(G_TRI2, 24, 8)|				\
			_SHIFTL((v32),12,4)|_SHIFTL((v22),8,4)|_SHIFTL((v12),4,4)|_SHIFTL((v02),0,4);	\
		_g->words.w1 =  _SHIFTL((v31),28,4)|_SHIFTL((v30),24,4)|_SHIFTL((v21),20,4)|_SHIFTL((v20),16,4) \
						_SHIFTL((v11),12,4)|_SHIFTL((v10),8,4)|_SHIFTL((v02),4,4)|_SHIFTL((v00),0,4); 	\
}

#define gsSP4Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1)	\
{									\
	(_SHIFTL(G_TRI2, 24, 8)|					\
			_SHIFTL((v32),12,4)|_SHIFTL((v22),8,4)|_SHIFTL((v12),4,4)|_SHIFTL((v02),0,4)),	\
	(_SHIFTL((v31),28,4)|_SHIFTL((v30),24,4)|_SHIFTL((v21),20,4)|_SHIFTL((v20),16,4) \
			_SHIFTL((v11),12,4)|_SHIFTL((v10),8,4)|_SHIFTL((v02),4,4)|_SHIFTL((v00),0,4));			\
}

#endif	/* TRI4_Ext*/

#define gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
{                                                                        \
    Gfx *_g = (Gfx *)(pkt);                                              \
    _g->words.w0 = _SHIFTL(0xE4,   24,  8)                               \
                 | _SHIFTL((xh),   12, 12)                               \
                 | _SHIFTL((yh),    0, 12);                              \
    _g->words.w1 = _SHIFTL((tile), 24,  3)                               \
                 | _SHIFTL((xl),   12, 12)                               \
                 | _SHIFTL((yl),    0, 12);                              \
}                                                                        \
{                                                                        \
    Gfx *_g = (Gfx *)(pkt);                                              \
    _g->words.w0 = _SHIFTL(0xB3, 24,  8);                                \
    _g->words.w1 = _SHIFTL((s),  16, 16)                                 \
                 | _SHIFTL((t),   0, 16);                                \
}                                                                        \
{                                                                        \
    Gfx *_g = (Gfx *)(pkt);                                              \
    _g->words.w0 = _SHIFTL(0xB2,   24,  8);                              \
    _g->words.w1 = _SHIFTL((dsdx), 16, 16)                               \
                 | _SHIFTL((dtdy),  0, 16);                              \
}

/* Lights and Light Operations */

typedef struct {
    unsigned char col[3];
    char          pad1;
    unsigned char colc[3];
    char          pad2;
    signed char   dir[3];
    char          pad3;
} Light_t;

typedef struct {
    unsigned char col[3];
    char          pad1;
    unsigned char colc[3];
    char          pad2;
} Ambient_t;

typedef union {
    Ambient_t l;
    long long int force_structure_alignment[1];
} Ambient;

typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;

typedef struct {
    Ambient a;
    Light   l[4];
} Lights4;

typedef struct {
    Light l[2];
} LookAt;

typedef struct {
    int x1, y1, x2, y2;
} Hilite_t;

typedef union {
    Hilite_t h;
    long int force_alignmnet[4];
} Hilite;

#define G_MOVEMEM 0x03
/* for gSPNumLights */
// is NUMLIGHTS_0 accurate?
#define NUMLIGHTS_0 1
#define NUMLIGHTS_1 1
#define NUMLIGHTS_2 2
#define NUMLIGHTS_3 3
#define NUMLIGHTS_4 4
#define NUMLIGHTS_5 5
#define NUMLIGHTS_6 6
#define NUMLIGHTS_7 7

/* for gSPLight */
#define LIGHT_1 1
#define LIGHT_2 2
#define LIGHT_3 3
#define LIGHT_4 4
#define LIGHT_5 5	
#define LIGHT_6 6
#define LIGHT_7 7
#define LIGHT_8 8

#define gSPLight(pkt, l, n)                           \
{                                                     \
    Gfx *_g = (Gfx *)(pkt);                           \
    _g->words.w0 = _SHIFTL(G_MOVEMEM,         24, 8)  \
                 | _SHIFTL(((n)-1)*2+G_MV_L0, 16, 8)  \
                 | _SHIFTL(sizeof(Light),     0, 16); \
    _g->words.w1 = (u32)(l);                          \
}

#define gSPLookAtX(pkt, la)                       \
{                                                 \
    Gfx *_g = (Gfx *)(pkt);                       \
    _g->words.w0 = _SHIFTL(G_MOVEMEM,    24,  8)  \
                 | _SHIFTL(G_MV_LOOKATX, 16,  8)  \
                 | _SHIFTL(sizeof(Light), 0, 16); \
    _g->words.w1 = (u32)(la);                     \
}

#define gSPLookAtY(pkt, la)                       \
{                                                 \
    Gfx *_g = (Gfx *)(pkt);                       \
    _g->words.w0 = _SHIFTL(G_MOVEMEM,    24,  8)  \
                 | _SHIFTL(G_MV_LOOKATY, 16,  8)  \
                 | _SHIFTL(sizeof(Light), 0, 16); \
    _g->words.w1 = (u32)(la);                     \
}

#define gSPLookAt(pkt, la)             \
{                                      \
    gSPLookAtX((pkt), (la))            \
    gSPLookAtY((pkt), (char *)(la)+16) \
}

#endif
