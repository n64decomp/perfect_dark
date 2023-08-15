#pragma once

#include <PR/ultratypes.h>

void configInit(void);
s32 configLoad(const char *fname);
s32 configSave(const char *fname);

s32 configGetInt(const char *key, s32 defval);
f32 configGetFloat(const char *key, f32 defval);
const char *configGetString(const char *key, const char *defval);

void configSetInt(const char *key, s32 val);
void configSetFloat(const char *key, f32 val);
void configSetString(const char *key, const char *val);
