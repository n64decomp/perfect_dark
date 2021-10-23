#include <stdio.h>
#include <stdlib.h>
#include "mkrom.h"

struct state state;

/**
 * mkrom - do ROM finalisation steps
 *
 * mkrom <romfile> <mapfile> <piracychecks> <zipmagic> <outfile>
 *
 * <romfile>
 * This is the path to the stage1 binary. This file is similar to the final ROM,
 * but the allocations for compressed segments are vacant, and the compressed
 * segments themselves are found uncompressed past the 32MB mark of the ROM.
 * This program will compress those segments, put them in their allocated spaces
 * and truncate the ROM to 32MB.
 *
 * <mapfile>
 * This is the path to the linker map, which is used to determine where the
 * uncompressed segments are and where they should be placed.
 *
 * <piracychecks>
 * This should be 0 or 1 to indicate whether this version of the ROM contains
 * piracy checks or not. Some piracy checks work by checksumming functions in
 * memory at runtime and comparing it with a known value. If set to 1, mkrom
 * will calculate the checksums for these functions and patch them into the
 * piracy checks.
 *
 * <zipmagic>
 * This is a two byte value which is used when zipping the game segments.
 * The original code was influenced by uninitialised data. These two bytes are
 * just setting that uninitialised data.
 *
 * <outfile>
 * The file to write the final ROM file to.
 *
 * eg. mkrom stage1.bin pd.map 1 0x1234 pd.z64
 */
int main(int argc, char **argv)
{
	if (argc < 6) {
		fprintf(stderr, "Usage: mkrom <romfile> <mapfile> <piracychecks> <zipmagic> <outfile>\n");
		exit(1);
	}

	rom_load(argv[1]);
	map_open(argv[2]);

	state.piracychecks = atoi(argv[3]);
	state.zipmagic = strtol(argv[4], NULL, 16);

	// Compute piracy checksums if requested
	if (state.piracychecks) {
		piracy_patch();
	}

	// Slice the game segment into chunks and zip each of them to create the
	// gamezips segment
	game_zip();

	// Pack each segment into their final locations
	pack_lib();
	pack_data();
	pack_game();
	pack_fill();

	rom_update_crc();

	rom_write(argv[5]);

	return 0;
}
