#include <ultra64.h>
#include "gvars/gvars.h"

// 8008ae20
u8 padding8008ae20[0x3018];

u32 var8008de38;

u8 padding8008de3c[0xc17c];

// 80099fc0
struct g_vars g_Vars; // ends at 8009a6c8

u8 padding8009a6c8[0x23f8];

u32 var8009cac0;
u32 var8009cac4;

u8 padding8009cac8[0x5fc];

// 8009d0c4
s32 g_NumTags;

// 8009d0c8
struct tag **g_TagPtrs;

// 8009d0d0
u8 padding8009d0d0[0xd54];

// 8009de24
u32 g_8009de24;

// 8009de28
u8 padding8009de28[0x43ec];

// 800a2214
u32 g_EepromFlags;
