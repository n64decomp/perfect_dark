#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <PR/ultratypes.h>
#include "fs.h"

#ifdef PATH_MAX
#define FS_MAXPATH PATH_MAX
#else
#define FS_MAXPATH 1024
#endif

#define FS_BASEDIR "data"
#define FS_MAX_FILES 2048

static char baseDir[FS_MAXPATH + 1];

static struct {
	char *name[FS_MAXPATH + 1];
	s32 size;
	void *data;
} fileSlots[FS_MAX_FILES];

static const char *fsFullPath(const char *relPath)
{
	static char pathBuf[FS_MAXPATH];
	snprintf(pathBuf, sizeof(pathBuf), "%s/%s", baseDir, relPath);
	return pathBuf;
}

s32 fsInit(void)
{
	// TODO: support appdata/home/whatever
	strcpy(baseDir, FS_BASEDIR);
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
		buf = calloc(1, size + 1); // sick hack for a free null terminator
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
