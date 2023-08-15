#ifndef _IN_FS_H
#define _IN_FS_H

#include <stdio.h>
#include <PR/ultratypes.h>

#define FS_MAXPATH 1024

s32 fsInit(void);

const char *fsFullPath(const char *relPath);

void *fsFileLoad(const char *name, u32 *outSize);
s32 fsFileSize(const char *name);

FILE *fsFileOpenWrite(const char *name);
FILE *fsFileOpenRead(const char *name);
void fsFileClose(FILE *f);

#endif
