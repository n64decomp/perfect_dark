#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u16 *g_FrameBuffers[NUM_FRAMEBUFFERS];

void lang_init(void)
{
	s32 i;

#if VERSION >= VERSION_JPN_FINAL
	g_JpnMaxCacheItems = IS4MB() ? 124 : 174;

	g_JpnCharCachePixels = memp_alloc(MAX_JPN_CACHE_ITEMS() * (sizeof(struct jpncharpixels) * 8), MEMPOOL_PERMANENT);
	g_JpnCacheCacheItems = memp_alloc(ALIGN16(MAX_JPN_CACHE_ITEMS() * sizeof(struct jpncacheitem)), MEMPOOL_PERMANENT);

	for (i = 0; i < MAX_JPN_CACHE_ITEMS(); i++) {
		g_JpnCacheCacheItems[i].ttl = 0;
		g_JpnCacheCacheItems[i].codepoint = -1;
	}
#else
	if (g_Jpn) {
		g_JpnCharCachePixels = memp_alloc(MAX_JPN_CACHE_ITEMS() * (sizeof(struct jpncharpixels) * 8), MEMPOOL_PERMANENT);
		g_JpnCacheCacheItems = memp_alloc(ALIGN16(MAX_JPN_CACHE_ITEMS() * sizeof(struct jpncacheitem)), MEMPOOL_PERMANENT);

		for (i = 0; i < MAX_JPN_CACHE_ITEMS(); i++) {
			g_JpnCacheCacheItems[i].ttl = 0;
			g_JpnCacheCacheItems[i].codepoint = -1;
		}
	}
#endif
}
