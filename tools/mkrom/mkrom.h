#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct state {
	/**
	 * A pointer to the full working ROM area in memory.
	 */
	unsigned char *rom;

	/**
	 * The size of the above rom allocation in bytes.
	 * The value is the same filesize as the stage1 binary,
	 * which is 32MB plus some uncompressed segments on the end.
	 */
	size_t romlen;

	/**
	 * Whether piracy checks are enabled for this build or not.
	 * If enabled, mkrom will recalculate piracy-related checksums.
	 */
	bool piracychecks;

	/**
	 * Two bytes that are used to seed some uninitialised data in the input
	 * buffer when zipping game chunks.
	 */
	unsigned short zipmagic;

	/**
	 * Number of bytes to copy after building gamezips.
	 */
	unsigned char copylen;

	/**
	 * File descriptor for the linker map.
	 */
	FILE *mapfd;

	/**
	 * A pointer to the gamezips segment, once created.
	 * The gamezips segment is the full segment but with the offest table
	 * zeroed.
	 */
	unsigned char *gamezips;

	/**
	 * Size of the above gamezips allocation in bytes.
	 */
	size_t gamezipslen;

	/**
	 * Pointer to a separate allocation for the gamezips offset table.
	 */
	unsigned char *gametable;

	/**
	 * Size of the above gametable allocation in bytes.
	 */
	size_t gametablelen;

	/**
	 * NTSC beta doesn't duplicate zip data unneccessarily so it must be
	 * identified and handled differently.
	 */
	bool is_ntscbeta;
};

void game_zip(void);

void map_open(char *filename);
bool map_get_function_rompos(char *funcname, uint32_t *start, uint32_t *end);
bool map_get_segment_rompos(char *funcname, uint32_t *start, uint32_t *end);

void pack_lib(void);
void pack_data(void);
void pack_game(void);

void piracy_patch(void);

void rarezip(uint8_t *outbuffer, size_t *outlen, uint8_t *inbuffer, size_t inlen, uint32_t magic);

void rom_load(char *filename);
void rom_update_crc(void);
void rom_write(char *filename);
