#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <PR/ultratypes.h>
#include "config.h"
#include "system.h"
#include "fs.h"

#define FS_MAX_FILES 2048

static char baseDir[FS_MAXPATH + 1];
static char exeDir[FS_MAXPATH + 1];

static struct {
	char *name[FS_MAXPATH + 1];
	s32 size;
	void *data;
} fileSlots[FS_MAX_FILES];

const char *fsFullPath(const char *relPath)
{
	static char pathBuf[FS_MAXPATH + 1];

	if (relPath[0] == '!') {
		// path relative to the exe
		const u32 len = strlen(exeDir);
		if (len > 0) {
			memcpy(pathBuf, exeDir, len);
			strncpy(pathBuf + len, relPath + 1, FS_MAXPATH - len);
			return pathBuf;
		}
	} else if (relPath[0] == '.') {
		// user explicitly wants working directory
		return relPath;
	}

	// path relative to basedir
	snprintf(pathBuf, FS_MAXPATH, "%s/%s", baseDir, relPath);
	return pathBuf;
}

s32 fsInit(void)
{
	sysGetExecutablePath(exeDir, FS_MAXPATH);

	// get path to data dir and expand it if needed
	const char *path = configGetString("Game.BaseDir", "./data");
	if (path[0] == '!') {
		strncpy(baseDir, fsFullPath(path), FS_MAXPATH);
	} else {
		strncpy(baseDir, path, FS_MAXPATH);
	}

	return 0;
}

void *fsFileLoad(const char *name, u32 *outSize)
{
	const char *fullName = fsFullPath(name);

	FILE *f = fopen(fullName, "rb");
	if (!f) {
		fprintf(stderr, "fsFileLoad: could not find file: %s\n", fullName);
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	const s32 size = ftell(f);
	fseek(f, 0, SEEK_SET);

	if (size < 0) {
		fprintf(stderr, "fsFileLoad: empty file or invalid size (%d): %s\n", size, fullName);
		fclose(f);
		return NULL;
	}

	void *buf = NULL;
	if (size) {
		buf = sysMemZeroAlloc(size + 1); // sick hack for a free null terminator
		if (!buf) {
			fprintf(stderr, "fsFileLoad: could not alloc %d bytes for file: %s\n", size, fullName);
			fclose(f);
			return NULL;
		}
		fread(buf, 1, size, f);
	}

	fclose(f);

	if (outSize) {
		*outSize = size;
	}

	return buf;
}

s32 fsFileSize(const char *name)
{
	const char *fullName = fsFullPath(name);
	struct stat st;
	if (stat(fullName, &st) < 0) {
		return -1;
	} else {
		return st.st_size;
	}
}

FILE *fsFileOpenWrite(const char *name)
{
	return fopen(fsFullPath(name), "wb");
}

FILE *fsFileOpenRead(const char *name)
{
	return fopen(fsFullPath(name), "rb");
}

void fsFileClose(FILE *f)
{
	fclose(f);
}
