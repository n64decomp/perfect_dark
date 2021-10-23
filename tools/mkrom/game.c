#include <arpa/inet.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mkrom.h"

extern struct state state;

/**
 * This file handles creation of the gamezips segment.
 *
 * Before mkrom is called, the game segment (uncompressed) is placed past the
 * end of the ROM by ld. This segment must be split into 4KB chunks. Each chunk
 * is zipped and then placed in its final location within the ROM.
 *
 * The format of the gamezips segment is:
 * - Array of offsets to each chunk, where each offset is 4 bytes and relative
 *   to the start of the gamezips segment.
 * - A final offset that points to the end of the final chunk.
 * - Chunk data, where each chunk consists of:
 *     - A 2 byte checksum of the uncompressed chunk.
 *     - Zip data (starting with 0x1173001000).
 *     - Optional single byte to align it to the next 2 byte boundary.
 *       The added byte is data from the previous chunk.
 */

/**
 * Calculate the checksum of this chunk's raw data.
 *
 * The game never verifies this, but it exists in the ROM so it has to be
 * calculated by mkrom.
 *
 * It's a simple sum of each word, but then it gets stored as a short so the
 * upper half is lost.
 */
static uint32_t crc(uint8_t *buffer, size_t len)
{
	uint32_t sum = 0;
	uint32_t offset;

	for (offset = 0; offset < len; offset += 4) {
		sum += ntohl(*(uint32_t *) &buffer[offset]);
	}

	return sum;
}

/**
 * Create a game chunk. We just calculate and prepend the checksum, then call
 * rarezip() which does the zipping and adding of the 0x1173 header.
 */
static void create_chunk(uint8_t *outbuf, size_t *outlen, uint8_t *inbuf, size_t inlen)
{
	uint32_t sum = crc(inbuf, inlen);

	outbuf[0] = (sum >> 8) & 0xff;
	outbuf[1] = sum & 0xff;

	rarezip(&outbuf[2], outlen, inbuf, inlen, state.zipmagic);

	*outlen += 2;
}

/**
 * Generate the gamezips segment.
 *
 * This segment starts with an offset table followed by the chunk data.
 * However, we need to keep the offset table zeroed here and build the table
 * in a different allocation because the ROM is packed with a duplicate of
 * this segment which has an empty offset table.
 *
 * So this function creates:
 * - state.gamezips, which is big enough to hold the offset table plus zips,
 *   but has the offset table zeroed
 * - state.gametable, which is just the table and has the entries populated.
 *
 * Each chunk is aligned to an even byte. If alignment needs to occur, the extra
 * byte is taken from the same offset in the previous chunk. In other words, the
 * same output buffer is used for every chunk and it's not cleared between uses.
 */
void game_zip(void)
{
	uint32_t end;
	size_t len;
	size_t num_chunks;
	uint32_t tableoffset;
	uint32_t dataoffset;
	size_t len_remaining;
	uint8_t outscratch[0x1100];
	uint32_t offset;
	uint32_t tablelen;

	memset(outscratch, 0, 0x1000);

	// Find the game's position in the ROM and calculate the number of chunks
	map_get_segment_rompos("game", &offset, &end);

	len = end - offset;
	num_chunks = len / 0x1000;

	if (len % 0x1000) {
		num_chunks++;
	}

	// Allocate buffers
	tablelen = num_chunks * 4 + 4;

	state.gamezips = malloc(tablelen + len);
	state.gametable = malloc(tablelen);
	state.gametablelen = tablelen;

	memset(state.gamezips, 0, tablelen);

	tableoffset = 0;
	dataoffset = tablelen;

	len_remaining = len;

	// Generate the chunks
	while (offset < end) {
		size_t chunkoriglen = len_remaining >= 0x1000 ? 0x1000 : len_remaining;
		size_t chunklen;

		// Write the table entry
		state.gametable[tableoffset + 0] = (dataoffset >> 24) & 0xff;
		state.gametable[tableoffset + 1] = (dataoffset >> 16) & 0xff;
		state.gametable[tableoffset + 2] = (dataoffset >> 8) & 0xff;
		state.gametable[tableoffset + 3] = dataoffset & 0xff;
		tableoffset += 4;

		// Write the data
		create_chunk(outscratch, &chunklen, &state.rom[offset], chunkoriglen);

		chunklen += chunklen % 2;

		memcpy(&state.gamezips[dataoffset], outscratch, chunklen);

		dataoffset += chunklen;

		len_remaining -= 0x1000;
		offset += 0x1000;
	}

	// The table contains an additional pointer to the end of the final chunk
	state.gametable[tableoffset + 0] = (dataoffset >> 24) & 0xff;
	state.gametable[tableoffset + 1] = (dataoffset >> 16) & 0xff;
	state.gametable[tableoffset + 2] = (dataoffset >> 8) & 0xff;
	state.gametable[tableoffset + 3] = dataoffset & 0xff;

	state.gamezipslen = dataoffset;
}
