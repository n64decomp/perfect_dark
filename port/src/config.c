#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <PR/ultratypes.h>
#include "fs.h"
#include "config.h"
#include "system.h"

#define CONFIG_MAX_STR 512
#define CONFIG_MAX_SECNAME 128
#define CONFIG_FNAME "./pd.ini"

enum configtype {
	CONFIG_END,
	CONFIG_S32,
	CONFIG_F32,
	CONFIG_STR,
};

struct configentry {
	const char *key;
	enum configtype type;
	union {
		s32 s32val;
		f32 f32val;
		char strval[CONFIG_MAX_STR + 1];
	};
} settings[] = {
	/* Video */
	{ "Video.DefaultFullscreen", CONFIG_S32, { .s32val = 0        } },
	{ "Video.DefaultWidth",      CONFIG_S32, { .s32val = 640      } },
	{ "Video.DefaultHeight",     CONFIG_S32, { .s32val = 480      } },
	{ "Video.VSync",             CONFIG_S32, { .s32val = 1        } },
	{ "Video.FramerateLimit",    CONFIG_S32, { .s32val = 0        } },
	/* Audio */
	{ "Audio.BufferSize",        CONFIG_S32, { .s32val = 512      } },
	{ "Audio.QueueLimit",        CONFIG_S32, { .s32val = 8192     } },
	/* Input */
	{ "Input.MouseEnabled",      CONFIG_S32, { .s32val = 1        } },
	{ "Input.MouseSpeedX",       CONFIG_F32, { .f32val = 1.5f     } },
	{ "Input.MouseSpeedY",       CONFIG_F32, { .f32val = 1.5f     } },
	{ "Input.LStickDeadzone",    CONFIG_S32, { .s32val = 4096     } },
	{ "Input.RStickDeadzone",    CONFIG_S32, { .s32val = 4096     } },
	{ "Input.SwapSticks",        CONFIG_S32, { .s32val = 1        } },
	/* Game */
	{ "Game.BaseDir",            CONFIG_STR, { .strval = "./data" } },
	{ "Game.MemorySize",         CONFIG_S32, { .s32val = 16       } },
	{ NULL,                      CONFIG_END, {                    } },
};

static inline struct configentry *configFindEntry(const char *key)
{
	for (struct configentry *cfg = settings; cfg->type; ++cfg) {
		if (!strcmp(key, cfg->key)) {
			return cfg;
		}
	}
	return NULL;
}

static inline const char *configGetSection(const char *key)
{
	static char sec[CONFIG_MAX_SECNAME + 1];

	// get the last dot in case we have a section with a '.'
	const char *dot = strrchr(key, '.');

	if (dot) {
		const u32 len = dot - key;
		if (len <= CONFIG_MAX_SECNAME) {
			memcpy(sec, key, len);
			sec[len] = '\0';
			return sec;
		}
	}

	return key;
}

void configSetInt(const char *key, s32 val)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		cfg->s32val = val;
	}
}

void configSetFloat(const char *key, f32 val)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		cfg->f32val = val;
	}
}

void configSetString(const char *key, const char *val)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		strncpy(cfg->strval, val, CONFIG_MAX_STR);
		cfg->strval[CONFIG_MAX_STR] = '\0';
	}
}

void configSetFromString(const char *key, const char *val)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		switch (cfg->type) {
			case CONFIG_S32: cfg->s32val = atoi(val); break;
			case CONFIG_F32: cfg->f32val = atof(val); break;
			case CONFIG_STR: strncpy(cfg->strval, val, CONFIG_MAX_STR); break;
			default: break;
		}
	}
}

s32 configGetInt(const char *key, s32 defval)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		return cfg->s32val;
	}
	return defval;
}

f32 configGetFloat(const char *key, f32 defval)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		return cfg->f32val;
	}
	return defval;
}

const char *configGetString(const char *key, const char *defval)
{
	struct configentry *cfg = configFindEntry(key);
	if (cfg) {
		return cfg->strval;
	}
	return defval;
}

s32 configSave(const char *fname)
{
	FILE *f = fsFileOpenWrite(fname);
	if (!f) {
		return 0;
	}

	char curSec[CONFIG_MAX_SECNAME + 1] = { 0 };
	strncpy(curSec, configGetSection(settings[0].key), CONFIG_MAX_SECNAME);
	fprintf(f, "[%s]\n", curSec);

	for (struct configentry *cfg = settings; cfg->type; ++cfg) {
		const char *cfgSec = configGetSection(cfg->key);
		if (strncmp(curSec, cfgSec, CONFIG_MAX_SECNAME) != 0) {
			fprintf(f, "\n[%s]\n", cfgSec);
			strncpy(curSec, cfgSec, CONFIG_MAX_SECNAME);
		}

		fprintf(f, "%s=", strrchr(cfg->key, '.') + 1);
		switch (cfg->type) {
			case CONFIG_S32: fprintf(f, "%d\n", cfg->s32val); break;
			case CONFIG_F32: fprintf(f, "%f\n", cfg->f32val); break;
			case CONFIG_STR: fprintf(f, "%s\n", cfg->strval); break;
			default: break;
		}
	}

	fsFileClose(f);
	return 1;
}

s32 configLoad(const char *fname)
{
	FILE *f = fsFileOpenRead(fname);
	if (!f) {
		return 0;
	}

	char curSec[CONFIG_MAX_SECNAME + 1] = { 0 };
	char keyBuf[CONFIG_MAX_SECNAME * 2 + 2] = { 0 }; // SECTION + . + KEY + \0
	char lineBuf[2048] = { 0 };
	char *line = lineBuf;
	s32 lineLen = 0;

	while (fgets(lineBuf, sizeof(lineBuf), f)) {
		line = lineBuf;

		// left-trim whitespace
		while (*line && isspace(*line)) {
			++line;
		}

		lineLen = strlen(line);
		if (!lineLen) {
			continue;
		}

		// right-trim whitespace and \n
		for (s32 i = lineLen - 1; i >= 0 && isspace(line[i]); --i, --lineLen);
		line[lineLen] = '\0';

		if (line[0] == ';' || line[0] == '#') {
			// comment; skip the rest of the line
			continue;
		} else if (line[0] == '[') {
			// section; skip [ and find matching ]
			++line;
			char *end = line;
			while (*end && *end != ']') {
				++end;
			}
			// found anything?
			if (*end != ']') {
				// didn't find shit
				continue;
			}
			// eat ] and whitespace on the right
			while (end > line && isspace(end[-1])) {
				--end;
			}
			*end = '\0';
			// empty []?
			if (end == line) {
				continue;
			}
			// eat whitespace on the left
			while (line < end && isspace(*line)) {
				++line;
			}
			// copy out the section name
			const s32 len = end - line;
			if (len > CONFIG_MAX_SECNAME) {
				continue; // too long
			}
			memcpy(curSec, line, len);
			curSec[len] = '\0';
		} else {
			// probably a key=value pair
			char *eq = strchr(line, '=');
			if (!eq) {
				continue; // garbage
			}
			char *value = eq + 1;
			if (!*value) {
				continue; // just a =
			}
			// trim right whitespace on the key
			--eq;
			while (eq > line && isspace(*eq)) {
				--eq;
			}
			if (eq == line) {
				continue; // = with nothing on the left
			}
			eq[1] = '\0';
			// assemble full key name and read the value
			snprintf(keyBuf, sizeof(keyBuf) - 1, "%s.%s", curSec, line);
			configSetFromString(keyBuf, value);
		}
	}

	fsFileClose(f);

	return 1;
}

void configInit(void)
{
	if (fsFileSize(CONFIG_FNAME) > 0) {
		configLoad(CONFIG_FNAME);
	} else {
		// config not found, save defaults
		configSave(CONFIG_FNAME);
	}
}
