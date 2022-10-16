#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mkrom.h"

extern struct state state;

static void copy(char *segname, uint8_t *payload, uint32_t len, char *constname)
{
	uint32_t start;
	uint32_t end;
	char zipsegname[32];
	uint32_t allocation;

	snprintf(zipsegname, sizeof(zipsegname), "%szip", segname);

	map_get_segment_rompos(zipsegname, &start, &end);

	allocation = end - start;

	if (len > allocation) {
		fprintf(stderr, "The %s segment is too big after compression to fit the allocation of 0x%x.\n", segname, allocation);
		fprintf(stderr, "In the Makefile, increase the value of %s to 0x%x or higher.\n", constname, len);
		exit(1);
	}

	memcpy(&state.rom[start], payload, len);
}

/**
 * To pack the data segment, zip it in full and copy it to the datazip segment.
 */
void pack_data(void)
{
	uint32_t start;
	uint32_t end;
	size_t ziplen;

	map_get_segment_rompos("data", &start, &end);

	uint8_t *buffer = malloc(end - start);

	rarezip(buffer, &ziplen, &state.rom[start], end - start, 0);

	copy("data", buffer, ziplen, "ROMALLOCATION_DATA");

	free(buffer);
}

/**
 * On the ROM, the gamezips segment exists with its offset table and zip data.
 * Then after that comes a copy of the gamezips segment but with the offset
 * table cleared. The second segment is garbage data.
 *
 * mkrom has already built the gamezips segment but with a zeroed table.
 * The real table is pointed to by state.gametable.
 *
 * So we have to copy the gamezips segment twice, then paste the gametable
 * segment over the start of the first one.
 */
void pack_game(void)
{
	uint32_t gamezipstart;
	uint32_t gamezipend;
	size_t truncatedlen;

	// Copy the gamezips segment
	copy("game", state.gamezips, state.gamezipslen, "ROMALLOCATION_GAME");

	// Paste over the offset table
	map_get_segment_rompos("gamezip", &gamezipstart, &gamezipend);

	memcpy(&state.rom[gamezipstart], state.gametable, state.gametablelen);

	if (!state.is_ntscbeta) {
		// Paste the second segment, truncating it to fit the allocation
		truncatedlen = gamezipend - gamezipstart - state.gamezipslen;

		if (truncatedlen > state.gamezipslen) {
			truncatedlen = state.gamezipslen;
		}

		memcpy(&state.rom[gamezipstart + state.gamezipslen], state.gamezips, truncatedlen);

		// The final two bytes from the real segment are duplicated into
		// the first two bytes of the second segment's offset table...
		// though for some versions the copy length can vary for unknown reasons
		// so we take the copy length as an argument to mkrom.
		memcpy(&state.rom[gamezipstart + state.gamezipslen], &state.rom[gamezipstart + state.gamezipslen - state.copylen], state.copylen);
	}
}

/**
 * The lib segment is zipped from 0x2000 onwards.
 *
 * It's placed twice in a row in the ROM within its allocation, where the second
 * one is truncated and unused.
 */
void pack_lib(void)
{
	uint32_t libzipstart;
	uint32_t libzipend;
	uint32_t libstart;
	uint32_t libend;
	size_t ziplen;
	size_t seglen;
	size_t truncatedlen;

	map_get_segment_rompos("lib", &libstart, &libend);

	uint8_t *buffer = malloc(libend - libstart);

	// Read the first 0x2000 into a buffer
	memcpy(buffer, &state.rom[libstart], 0x2000);

	// Compress the remainder from ROM, appending to the buffer
	rarezip(&buffer[0x2000], &ziplen, &state.rom[libstart + 0x2000], libend - libstart - 0x2000, 0);
	seglen = ziplen + 0x2000;

	// Copy the buffer to its real spot in the ROM
	copy("lib", buffer, seglen, "ROMALLOCATION_LIB");

	if (!state.is_ntscbeta) {
		// Copy it truncated to its fake spot
		map_get_segment_rompos("libzip", &libzipstart, &libzipend);

		truncatedlen = libzipend - libzipstart - seglen;

		if (truncatedlen > seglen) {
			truncatedlen = seglen;
		}

		memcpy(state.rom + libzipstart + seglen, buffer, truncatedlen);
	}

	free(buffer);
}
