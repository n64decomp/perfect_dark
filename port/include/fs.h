#ifndef _IN_FS_H
#define _IN_FS_H

#include <limits.h>
#include <PR/ultratypes.h>

#ifdef PATH_MAX
#define FS_MAXPATH PATH_MAX
#else
#define FS_MAXPATH 1024
#endif

s32 fsInit(void);

void *fsFileLoad(const char *name, u32 *outSize);
s32 fsFileSize(const char *name);

#endif
