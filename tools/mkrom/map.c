#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mkrom.h"

/**
 * This file handles reading and parsing the linker map.
 */

extern struct state state;

void map_open(char *filename)
{
	state.mapfd = fopen(filename, "r");

	if (!state.mapfd) {
		fprintf(stderr, "Unable to open map file \"%s\" for reading\n", filename);
		exit(1);
	}
}

/**
 * Find the start and end offsets of the given function in the ROM and write
 * their offsets to the start and end pointers.
 *
 * Return true if the function was found, false if not.
 */
bool map_get_function_rompos(char *funcname, uint32_t *start, uint32_t *end)
{
	char line[1024];
	char *ptr;
	uint32_t segramaddr = 0;
	uint32_t segromoffset = 0;
	uint32_t ramaddr;
	char find[1024];
	bool lookingforend = false;

	snprintf(find, sizeof(find), " %s\n", funcname);

	fseek(state.mapfd, 0, SEEK_SET);

	while (fgets(line, 1024, state.mapfd)) {
		if (lookingforend) {
			ptr = line;

			while (isspace(*ptr)) {
				ptr++;
			}

			if (ptr[0] == '0' && ptr[1] == 'x') {
				ramaddr = strtoul(ptr, NULL, 16);

				*end = ramaddr - segramaddr + segromoffset;
				return true;
			}
		} else if (line[0] == '.') {
			// Start of a segment
			// ".game           0x000000007f000000   0x1b99e0 load address 0x00000000020ac170"

			// Jump to RAM address
			ptr = strstr(line, "0x");

			if (ptr == NULL) {
				continue;
			}

			segramaddr = strtoul(ptr, NULL, 16);

			// Jump to length
			ptr++;
			ptr = strstr(ptr, "0x");

			// Jump to ROM offset
			ptr++;
			ptr = strstr(ptr, "0x");
			segromoffset = strtoul(ptr, NULL, 16);
		} else if (strstr(line, find)) {
			// Found the function
			// "0x000000007f15d9a8                bgInflate"
			ptr = strstr(line, "0x");
			ramaddr = strtoul(ptr, NULL, 16);

			*start = ramaddr - segramaddr + segromoffset;
			lookingforend = true;
		}
	}

	return false;
}

/**
 * Find the start and end offsets of the given segment in the ROM and write
 * their offsets to the start and end pointers.
 *
 * Either point may be NULL.
 *
 * Return true if the segment was found, false if not.
 */
bool map_get_segment_rompos(char *segname, uint32_t *start, uint32_t *end)
{
	char startstring[64];
	char endstring[64];
	char line[1024];
	bool found_start = false;
	bool found_end = false;

	snprintf(startstring, sizeof(startstring), "_%sSegmentRomStart = ", segname);
	snprintf(endstring, sizeof(endstring), "_%sSegmentRomEnd = ", segname);

	fseek(state.mapfd, 0, SEEK_SET);

	// Find lines like this:
	// "                0x0000000000001050                _libzipSegmentRomStart = __rompos"

	while (fgets(line, 1024, state.mapfd)) {
		if (!found_start && strstr(line, startstring)) {
			char *ptr = strstr(line, "0x");

			if (start != NULL) {
				*start = strtoul(ptr, NULL, 16);
			}

			if (found_end) {
				return true;
			}

			found_start = true;
		}

		if (!found_end && strstr(line, endstring)) {
			char *ptr = strstr(line, "0x");

			if (end != NULL) {
				*end = strtoul(ptr, NULL, 16);
			}

			if (found_start) {
				return true;
			}

			found_end = true;
		}
	}

	fprintf(stderr, "Unable to find segment \"%s\" in linker map\n", segname);

	return false;
}
