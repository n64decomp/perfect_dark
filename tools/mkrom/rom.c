#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mkrom.h"

extern struct state state;

/**
 * Load the stage1 ROM into memory.
 */
void rom_load(char *filename)
{
	FILE *fp = fopen(filename, "rb");

	if (!fp) {
		fprintf(stderr, "Unable to open \"%s\" for reading\n", filename);
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	state.romlen = ftell(fp);

	state.rom = malloc(state.romlen);

	if (!state.rom) {
		fprintf(stderr, "Unable to allocate memory for ROM\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	fread(state.rom, state.romlen, 1, fp);
	fclose(fp);

	state.is_ntscbeta = strncmp(&state.rom[0x20], "Perfect Dark DBGNTSC", 20) == 0;
}

/**
 * Write the ROM to the given filename and truncate it to 32MB.
 */
void rom_write(char *filename)
{
	FILE *fp = fopen(filename, "wb");
	uint32_t fill_start;
	uint32_t rom_size;

	if (!fp) {
		fprintf(stderr, "Unable to open \"%s\" for writing\n", filename);
		exit(1);
	}

	map_get_segment_rompos("fill", &fill_start, &rom_size);

	fwrite(state.rom, rom_size, 1, fp);
	fclose(fp);
}

static uint32_t rol(uint32_t i, uint32_t b)
{
	return (i << b) | (i >> (32 - b));
}

static uint32_t r4(unsigned char *b)
{
	return b[0] * 0x1000000 + b[1] * 0x10000 + b[2] * 0x100 + b[3];
}

static void crc(unsigned char *rom, uint32_t *crc1, uint32_t *crc2)
{
	uint32_t seed = 0xdf26f436;
	uint32_t t1 = seed;
	uint32_t t2 = seed;
	uint32_t t3 = seed;
	uint32_t t4 = seed;
	uint32_t t5 = seed;
	uint32_t t6 = seed;
	uint32_t offset;
	uint32_t d;
	uint32_t r;
	uint32_t temp;

	unsigned char *lookup = &rom[0x40 + 0x0710];

	for (offset = 0x1000; offset < 0x101000; offset += 4) {
		d = r4(&rom[offset]);

		if ((t6 + d) < t6) {
			t4++;
		}

		t6 += d;
		t3 ^= d;

		r = rol(d, d & 0x1f);

		t5 += r;

		if (t2 > d) {
			t2 ^= r;
		} else {
			t2 ^= t6 ^ d;
		}

		temp = r4(&lookup[offset & 0xff]);
		t1 += temp ^ d;
	}

	*crc1 = t6 ^ t4 ^ t3;
	*crc2 = t5 ^ t2 ^ t1;
}

/**
 * Calculate the checksum of the ROM and write it to the ROM header.
 */
void rom_update_crc(void)
{
	uint32_t crc1;
	uint32_t crc2;

	crc(state.rom, &crc1, &crc2);

	state.rom[0x10] = (crc1 >> 24) & 0xff;
	state.rom[0x11] = (crc1 >> 16) & 0xff;
	state.rom[0x12] = (crc1 >> 8) & 0xff;
	state.rom[0x13] = crc1 & 0xff;

	state.rom[0x14] = (crc2 >> 24) & 0xff;
	state.rom[0x15] = (crc2 >> 16) & 0xff;
	state.rom[0x16] = (crc2 >> 8) & 0xff;
	state.rom[0x17] = crc2 & 0xff;
}
