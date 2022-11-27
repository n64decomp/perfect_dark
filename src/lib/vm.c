#include <ultra64.h>
#include "lib/tlb.h"
#include "constants.h"
#include "bss.h"
#include "lib/boot.h"
#include "lib/crash.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/lib_48150.h"
#include "data.h"
#include "types.h"

/**
 * vm - virtual memory
 *
 * To get around memory limitations, Perfect Dark implements a memory paging
 * system similar to ones found in modern operating systems. Memory is divided
 * into pages and can be accessed by virtual addresses. If the page does not
 * exist in physical memory then the operating system can replace a page in
 * physical memory with the required one and try again. This allows the system
 * to address more memory than is actually loaded and have a smaller memory
 * footprint.
 *
 * All code in the game is divided into two segments: Unpagable and pagable.
 *
 * Unpagable:
 * - Is what decomp calls lib.
 * - Is virtual at 0x70000000 and statically mapped to 0x80000000.
 * - Contains frequently used code which would be a bad idea to swap in and out,
 *   as well as all of libultra.
 *
 * Pagable:
 * - Is what decomp calls game.
 * - Is virtual at 0x7f000000.
 * - Contains the majority of the game code.
 *
 * Paging cannot occur for any sections which are writeable in memory because
 * the N64 ROM is read only. Sections of this type are .data and .bss.
 * These sections reside in physical memory at 0x80000000 and are not pagable.
 *
 * Paging is implemented for the .text (ie. code) and .rodata segments. When
 * building the ROM image, these are grouped into one binary then sliced into
 * chunks of size 4KB (the page size). Each chunk is zipped and then each zip is
 * placed on the ROM along with a zip offset table.
 *
 * The N64 contains a translation lookaside buffer (TLB), a feature of the CPU
 * which can map virtual memory to physical memory. The TLB contains a table of
 * 32 entries. Each entry can map two pages, and PD's page size is 4KB. The
 * unpagable segment described above is mapped using one TLB entry, leaving 31
 * entries for dynamic paging.
 *
 * A page an be in one of three states:
 * - Mapped in the TLB and loaded in physical memory.
 * - Not mapped in the TLB but still loaded in physical memory.
 * - Not mapped in the TLB and not in physical memory
 *   (must be unzipped from the ROM to access).
 *
 * A TLB miss occurs when a request is made for a page that isn't mapped in the
 * TLB. When this happens, the system's exception handler checks if the page
 * exists in physical memory or not. If it does, a TLB entry is created for it.
 *
 * A page miss occurs when the page didn't exist in physical memory. In this
 * case the exception handler must load it from the ROM, unzip the page and
 * replace an existing one.
 *
 * Paging is only implemented for 4MB systems (ie. when the expansion pak is not
 * being used). When using the expansion pak all game code is loaded and the
 * mappings in the TLB are static.
 */

u8 g_Is4Mb;
u32 g_VmNumTlbMisses;
u32 g_VmNumPageMisses;
u32 g_VmNumPageReplaces;
u8 *g_VmMarker;
u32 g_VmRamEnd;
u32 g_VmStateTableEnd;

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
u8 g_VmShowStats = false;
#endif

#if VERSION == VERSION_NTSC_BETA
u32 fillnb[2] = {0};
#endif

#if VERSION == VERSION_PAL_BETA
s32 g_VmNumPages = 0;
u32 var8005cf80 = 0;
#else
u32 var8005cf80 = 0;
s32 g_VmNumPages = 0;
#endif

u32 var8005cf88 = 0;

extern u8 _gameSegmentStart;
extern u8 _gameSegmentEnd;
extern u8 _gamezipSegmentRomStart;

extern u32 var8008ae20;
extern u32 *g_VmStateTable;
extern u8 g_VmInitialised;
extern u32 g_VmZipBuffer;
extern u32 *g_VmZipTable;

#define PAGE_SIZE (1024 * 4)

#if VERSION >= VERSION_NTSC_1_0
#define MAX_LOADED_PAGES 268
#else
#define MAX_LOADED_PAGES 266
#endif

/**
 * Initialise the virtual memory.
 *
 * The logic here is different depending on whether the system has the 4MB
 * of onboard memory or is using the expansion pak for a total of 8MB.
 *
 * -- For 4MB systems --
 *
 * vmInit allocates space in memory for the TLB to be able to load zips in its
 * exception handler. It initialises the zip table then leaves it to the TLB to
 * load the game zips as needed.
 *
 * The memory is laid out like this:
 *
 *              (zip buffer) (zip table) (state table) (stack)    (end of onboard memory)
 *   Addresses:              0x???       0x???         0x803f50b8 0x80400000
 *     Lengths:              0x6ec       0xdd8         0xaf48     0
 *
 * zip buffer - is sized according to the biggest single game zip, and is
 *     reserved space where the TLB's exception handler can DMA the zip to RAM
 *     before unzipping it.
 * zip table - is the ROM offset table where each zip can be found, which is
 *     used by the TLB's exception handler.
 * state table - is cleared by vmInit then left to the TLB's exception handler
 *     for it to populate as zips are loaded and paged out.
 * stack - is reserved stack space for different threads, which vmInit must not
 *     write into.
 *
 * -- For 8MB systems --
 *
 * vmInit loads all game zips into memory and sets TLB entries to map it to
 * virtual address space. The page swapping feature is not used as the TLB
 * never encounters a page miss.
 *
 * The memory is laid out like this:
 *
 *              (zip buffer) (zip table) (game seg) (stack)    (end of onboard memory)
 *   Addresses:              0x???       0x80220000 0x803f50b8 0x80400000
 *     Lengths:              0x6ec       0x1b99e0   0xaf48     0
 *
 * zip buffer: is sized as PAGE_SIZE * 2, which guarantees it's big enough to
 *     hold any zip.
 * zip table: is the ROM offset table where each zip can be found.
 * game seg: is where the entire game segment is unzipped to.
 * stack: is reserved stack space for different threads, which vmInit must not
 *     write into.
 *
 * -- Both systems --
 *
 * Regardless of the amount of memory being used, it is critical that vmInit
 * sets the g_VmMarker global variable correctly. This marks the point in memory
 * where memory must be preserved. The main thread uses this variable as the end
 * address of memp's heap.
 *
 * In 4MB, g_VmMarker is set to the start of the zip buffer because the zip
 * buffer is used by the exception handler.
 *
 * In 8MB, the zip buffer and zip table are no longer needed, so g_VmMarker is
 * set to the start of the unzipped game segment.
 */
void vmInit(void)
{
	s32 s1;
	u32 *romaddrs;
	u32 numpages;
	u8 *s2;
	u8 *s1p;
	u8 *chunkbuffer;
	u8 *s7; // nb: 154c
	u8 *gameseg;
	u8 *zip; // 48
	s32 pagenum;
	s32 statetablelen;
#if VERSION < VERSION_NTSC_1_0
	u32 stack1;
#endif
	u32 size;
	u32 numentries2; // N/A, 1474
	u32 numentries;
	u32 *ptr;
#if VERSION >= VERSION_NTSC_1_0
	s32 i;
	u8 sp68[1024 * 5]; // 128, 68
#else
	u8 sp68[1024 * 5]; // 128, 68
	char message[128]; // nb: a8
	s32 len;
	s32 stack2;
#endif

	g_VmInitialised = true;

	rzipInit();

#if VERSION >= VERSION_NTSC_1_0
	if (bootGetMemSize() <= 0x400000)
#else
	if (osGetMemSize() <= 0x400000)
#endif
	{
		g_Is4Mb = true;

		g_VmNumPages = (s32)((&_gameSegmentEnd - &_gameSegmentStart) + (PAGE_SIZE - 1)) / PAGE_SIZE;

		g_VmRamEnd = 0x7f000000 + PAGE_SIZE * g_VmNumPages;
		g_VmStateTableEnd = STACK_START;
		gameseg = (u8 *) (STACK_START - g_VmNumPages * 8);
		g_VmStateTable = (u32 *) gameseg;

		numpages = (u32) (((u32) &_gameSegmentEnd - (u32) &_gameSegmentStart) + (PAGE_SIZE - 1)) / PAGE_SIZE;
		numentries = numpages + 1;

		g_VmZipTable = (u32 *) ((u32) ((u32 *) gameseg - (numentries + 4)) & ~0xf);

		// Load gamezips pointer list
		dmaExec(g_VmZipTable, (u32) &_gamezipSegmentRomStart, ALIGN16((numentries + 1) << 2));

		// Make pointers absolute instead of relative to their segment
		for (pagenum = 0; pagenum < numentries; pagenum++) {
			g_VmZipTable[pagenum] += (u32) &_gamezipSegmentRomStart;
		}

		// Find the size of the biggest compressed zip
		s1 = 0;

		for (pagenum = 0; pagenum < numentries - 1; pagenum++) {
			size = g_VmZipTable[pagenum + 1] - g_VmZipTable[pagenum];

			if (size > s1) {
				s1 = size;
			}
		}

		s1 += 0x40;
		s1 &= (u32) ~0xf;
		g_VmZipBuffer = (u32) g_VmZipTable - s1;
		g_VmZipBuffer &= ~0xf;
		gameseg = (u8 *) (g_VmZipBuffer - MAX_LOADED_PAGES * PAGE_SIZE);
		gameseg -= (u32) gameseg & 0x1fff;
		var8008ae20 = (u32) gameseg;
		g_VmMarker = gameseg;

		tlb000010a4();

		// Clear the state table
		ptr = g_VmStateTable;
		statetablelen = (g_VmNumPages * 8) >> 2;

		for (s1 = 0; s1 < statetablelen; s1++) {
			ptr[s1] = 0;
		}

		tlb0000113c();
	} else {
		// Expansion pak is being used
		g_Is4Mb = numentries * false;

		numpages = (u32)((&_gameSegmentEnd - &_gameSegmentStart) + (PAGE_SIZE - 1)) / PAGE_SIZE;
		s7 = (u8 *) STACK_START;

#if VERSION >= VERSION_NTSC_1_0
		numentries = numpages + 1;
		gameseg = (u8 *) ((u32) (s7 - (u8 *) ALIGN64((u32) &_gameSegmentEnd - (u32) &_gameSegmentStart)) & 0xfffe0000);
#else
		gameseg = (u8 *) ((u32) (s7 - (u8 *) ALIGN64((u32) &_gameSegmentEnd - (u32) &_gameSegmentStart)) & 0xfffe0000);
		numentries = numpages + 1;
#endif

		romaddrs = (u32 *) (((u32) gameseg - ((numentries + 4) << 2)) & ~0xf);
		g_VmMarker = gameseg;
		numentries2 = numentries;

		// Load gamezips pointer list
		dmaExec(romaddrs, (u32) &_gamezipSegmentRomStart, ALIGN16((numentries2 + 1) << 2));

		if (pagenum);

#if VERSION >= VERSION_NTSC_1_0
#define ITER i
#else
#define ITER s1
#endif

		// Make pointers absolute instead of relative to their segment
		for (ITER = 0; ITER < numentries2; ITER++) { \
			romaddrs[ITER] += (u32) &_gamezipSegmentRomStart;
		}

		// Load each zip from the ROM and inflate them to the game segment
		s2 = gameseg;
		chunkbuffer = (u8 *) ((u32) romaddrs - PAGE_SIZE * 2);
		zip = chunkbuffer + 2;

		for (ITER = 0; ITER < numentries2 - 1;) {
			dmaExec(chunkbuffer, romaddrs[ITER], ALIGN16(romaddrs[ITER + 1] - romaddrs[ITER]));

#if VERSION >= VERSION_NTSC_1_0
			s2 += rzipInflate(zip, s2, sp68);
#else
			len = rzipInflate(zip, s2, sp68);

			if (len == 0) {
				sprintf(message, "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
						"vm_m.c", 298,
						chunkbuffer[0], chunkbuffer[1], chunkbuffer[2], chunkbuffer[3],
						chunkbuffer[4], chunkbuffer[5], chunkbuffer[6], chunkbuffer[7],
						chunkbuffer[8], chunkbuffer[9], chunkbuffer[10], chunkbuffer[11],
						chunkbuffer[12], chunkbuffer[13], chunkbuffer[14], chunkbuffer[15]);
				crashSetMessage(message);
				CRASH();
			}

			s2 += len;
#endif

			ITER++;
		}

		// This loop sets the following TLB entries:
		// entry 2: 0x7f000000 to 0x7f010000 and 0x7f010000 to 0x7f020000
		// entry 3: 0x7f020000 to 0x7f030000 and 0x7f030000 to 0x7f040000
		// ...
		// entry 14: 0x7f1a0000 to 0x7f1b0000 and 0x7f1b0000 to 0x7f1c0000
		s1p = (u8 *) 0x7f000000;
		pagenum = 2; // reusing variable

		while (gameseg <= s7) {
			osMapTLB(pagenum, OS_PM_64K, s1p,
					osVirtualToPhysical((void *) gameseg),
					osVirtualToPhysical((void *) (gameseg + 0x10000)), -1);

			gameseg += 0x20000;
			s1p += 0x20000;
			pagenum++;
		}
	}

	g_VmNumTlbMisses = 0;
	g_VmNumPageMisses = 0;
	g_VmNumPageReplaces = 0;

	osInvalICache(0, ICACHE_SIZE);
}
