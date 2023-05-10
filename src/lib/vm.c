#include <ultra64.h>
#include "lib/tlb.h"
#include "constants.h"
#include "bss.h"
#include "lib/boot.h"
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

u8 *g_VmMarker;
u32 g_VmRamEnd;
u32 g_VmStateTableEnd;

s32 g_VmNumPages = 0;


extern u8 _gameSegmentStart;
extern u8 _gameSegmentEnd;
extern u8 _gamezipSegmentRomStart;

extern u32 *g_VmStateTable;
extern u32 g_VmZipBuffer;
extern u32 *g_VmZipTable;

#define PAGE_SIZE (1024 * 4)

#define MAX_LOADED_PAGES 268

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
// Mismatch: Need maxsize to go in s1
void vmInit(void)
{
	s32 i;
	u32 *s5;
	u32 t8;
	u8 *s2;
	u8 *s1;
	u8 *chunkbuffer;
	u32 maxsize;
	u32 sp1474;
	u8 sp68[1024 * 5]; // 68 to 1467
	u8 *gameseg; // 54
	u8 *zip; // 48
	u8 *s7;
	s32 statetablelen;

	rzipInit();

	t8 = (u32)((&_gameSegmentEnd - &_gameSegmentStart) + (PAGE_SIZE - 1)) / PAGE_SIZE;
	s7 = (u8 *)(STACK_START - 8);

	// 0x803c0000 - (_gameSegmentLen aligned to 0x20000)
	gameseg = (u8 *) &_gameSegmentStart;

	s5 = (u32 *) 0x80600000;
	g_VmMarker = (u8 *) s7;
	sp1474 = t8 + 1;

	// Load gamezips pointer list
	dmaExec(s5, (u32) &_gamezipSegmentRomStart, ALIGN16((sp1474 + 1) << 2));

	// Make pointers absolute instead of relative to their segment
	for (i = 0; i < sp1474; i++) { \
		s5[i] += (u32) &_gamezipSegmentRomStart;
	}

	// Load each zip from the ROM and inflate them to the game segment
	s2 = gameseg;
	chunkbuffer = (u8 *) ((u32)s5 - PAGE_SIZE * 2);
	zip = chunkbuffer + 2;

	for (i = 0; i < sp1474 - 1; i++) { \
		dmaExec(chunkbuffer, s5[i], ALIGN16(s5[i + 1] - s5[i])); \
		s2 += rzipInflate(zip, s2, sp68);
	}

	osInvalICache(0, ICACHE_SIZE);
}
