#include <stdlib.h>
#include <stdio.h>
#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <PR/libaudio.h>
#include "platform.h"
#include "data.h"
#include "bss.h"
#include "preprocess.h"
#include "romdata.h"

#define PD_BEFIELD_I16(x) x = PD_BE16(x)
#define PD_BEFIELD_I32(x) x = PD_BE32(x)
#define PD_BEFIELD_F32(x) *(u32 *)&x = PD_BE32(*(u32 *)&x)
#define PD_BEFIELD_PTR(x) x = (void *)PD_BE32((u32)x)

#define PD_PTR_BASE(x, b) (void *)((u8 *)b + (u32)x)
#define PD_PTR_BASEOFS(x, b, d) (void *)((u8 *)b + (u32)x - d)

static inline void preprocessALWaveTable(ALWaveTable *tbl, u8 *bankBase)
{
	if ((uintptr_t)tbl->base < 0x02000000) {
		// already swapped (maybe come up with a better check)
		return;
	}

	PD_BEFIELD_I32(tbl->len);
	PD_BEFIELD_PTR(tbl->base);

	if (tbl->type == AL_ADPCM_WAVE) {
		if (tbl->waveInfo.adpcmWave.loop ) {
			PD_BEFIELD_PTR(tbl->waveInfo.adpcmWave.loop);
			ALADPCMloop *loop = PD_PTR_BASE(tbl->waveInfo.adpcmWave.loop, bankBase);
			PD_BEFIELD_I32(loop->count);
			PD_BEFIELD_I32(loop->start);
			PD_BEFIELD_I32(loop->end);
			/* TODO: this goes into the mixer -- swapping not required?
			for (s32 i = 0; i < 16; ++i) {
				PD_BEFIELD_I16(loop->state[i]);
			}
			*/
		}
		if (tbl->waveInfo.adpcmWave.book) {
			PD_BEFIELD_PTR(tbl->waveInfo.adpcmWave.book);
			ALADPCMBook *book = PD_PTR_BASE(tbl->waveInfo.adpcmWave.book, bankBase);
			PD_BEFIELD_I32(book->npredictors);
			PD_BEFIELD_I32(book->order);
			/* TODO: this goes into the mixer -- swapping not required?
			const s32 bookSize = book->order * book->npredictors * ADPCMVSIZE;
			for (s32 i = 0; i < bookSize && i < 128; ++i) {
				PD_BEFIELD_I16(book->book[i]);
			}
			*/
		}
	} else if (tbl->type == AL_RAW16_WAVE) {
		if (tbl->waveInfo.rawWave.loop) {
			PD_BEFIELD_PTR(tbl->waveInfo.rawWave.loop);
			ALRawLoop *loop = PD_PTR_BASE(tbl->waveInfo.rawWave.loop, bankBase);
			PD_BEFIELD_I32(loop->count);
			PD_BEFIELD_I32(loop->start);
			PD_BEFIELD_I32(loop->end);
		}
	}
}

static inline void preprocessALSound(ALSound *snd, u8 *bankBase)
{
	if ((uintptr_t)snd->wavetable < 0x02000000) {
		// already swapped (maybe come up with a better check)
		return;
	}

	if (snd->envelope) {
		PD_BEFIELD_PTR(snd->envelope);
		ALEnvelope *env = PD_PTR_BASE(snd->envelope, bankBase);
		PD_BEFIELD_I32(env->attackTime);
		PD_BEFIELD_I32(env->releaseTime);
		PD_BEFIELD_I32(env->decayTime);
	}

	if (snd->keyMap) {
		PD_BEFIELD_PTR(snd->keyMap);
	}

	if (snd->wavetable) {
		PD_BEFIELD_PTR(snd->wavetable);
		preprocessALWaveTable(PD_PTR_BASE(snd->wavetable, bankBase), bankBase);
	}
}

static inline void preprocessALInstrument(ALInstrument *inst, u8 *bankBase)
{
	if ((uintptr_t)inst->soundArray[0] < 0x02000000) {
		// already swapped (maybe come up with a better check)
		return;
	}

	PD_BEFIELD_I16(inst->bendRange);
	PD_BEFIELD_I16(inst->soundCount);

	for (s16 i = 0; i < inst->soundCount; ++i) {
		PD_BEFIELD_PTR(inst->soundArray[i]);
		preprocessALSound(PD_PTR_BASE(inst->soundArray[i], bankBase), bankBase);
	}
}

static inline void preprocessALBank(ALBank *bank, u8 *bankBase)
{
	if ((uintptr_t)bank->instArray[0] < 0x02000000) {
		// already swapped (maybe come up with a better check)
		return;
	}

	PD_BEFIELD_I32(bank->sampleRate);
	PD_BEFIELD_I16(bank->instCount);

	if (bank->percussion) {
		PD_BEFIELD_PTR(bank->percussion);
		preprocessALInstrument(PD_PTR_BASE(bank->percussion, bankBase), bankBase);
	}

	for (s16 i = 0; i < bank->instCount; ++i) {
		PD_BEFIELD_PTR(bank->instArray[i]);
		preprocessALInstrument(PD_PTR_BASE(bank->instArray[i], bankBase), bankBase);
	}
}

static inline void preprocessGfx(Gfx *gdl)
{
	while (gdl) {
		const u8 opcode = gdl->bytes[0];
		PD_BEFIELD_I32(gdl->words.w0);
		PD_BEFIELD_I32(gdl->words.w1);
		if (opcode == G_ENDDL) {
			break;
		}
		++gdl;
	}
}

static inline void preprocessVtx(Vtx *vtx)
{
	PD_BEFIELD_I16(vtx->x);
	PD_BEFIELD_I16(vtx->y);
	PD_BEFIELD_I16(vtx->z);
	PD_BEFIELD_I16(vtx->s);
	PD_BEFIELD_I16(vtx->t);
}

static void preprocessModelGunDL(struct modelrodata_gundl *gundl, u8 *base, u32 ofs)
{
	PD_BEFIELD_PTR(gundl->opagdl);
	PD_BEFIELD_PTR(gundl->xlugdl);
	PD_BEFIELD_PTR(gundl->baseaddr);
	PD_BEFIELD_PTR(gundl->vertices);
	PD_BEFIELD_I32(gundl->numvertices);
	PD_BEFIELD_I16(gundl->unk12);

	Vtx *vtx = PD_PTR_BASEOFS(gundl->vertices, base, ofs);
	for (s16 i = 0; i < gundl->numvertices; ++i, ++vtx) {
		preprocessVtx(vtx);
	}

	preprocessGfx(PD_PTR_BASEOFS(gundl->opagdl, base, ofs));
	preprocessGfx(PD_PTR_BASEOFS(gundl->xlugdl, base, ofs));
}

static void preprocessModelDL(struct modelrodata_dl *dl, u8 *base, u32 ofs)
{
	PD_BEFIELD_PTR(dl->opagdl);
	PD_BEFIELD_PTR(dl->xlugdl);
	PD_BEFIELD_PTR(dl->colours);
	PD_BEFIELD_PTR(dl->vertices);

	PD_BEFIELD_I16(dl->numvertices);
	PD_BEFIELD_I16(dl->numcolours);
	PD_BEFIELD_I16(dl->mcount);
	PD_BEFIELD_I16(dl->rwdataindex);

	Vtx *vtx = PD_PTR_BASEOFS(dl->vertices, base, ofs);
	for (s16 i = 0; i < dl->numvertices; ++i, ++vtx) {
		preprocessVtx(vtx);
	}

	preprocessGfx(PD_PTR_BASEOFS(dl->opagdl, base, ofs));
	preprocessGfx(PD_PTR_BASEOFS(dl->xlugdl, base, ofs));
}

static void preprocessModelNode(struct modelnode *node, u8 *base, u32 ofs)
{
	PD_BEFIELD_I16(node->type);
	PD_BEFIELD_PTR(node->child);
	PD_BEFIELD_PTR(node->next);
	PD_BEFIELD_PTR(node->parent);

	if (!node->rodata) {
		return;
	}

	PD_BEFIELD_PTR(node->rodata);
	union modelrodata* ro = PD_PTR_BASEOFS(node->rodata, base, ofs);

	switch (node->type & 0xff) {
		case MODELNODETYPE_CHRINFO:
			PD_BEFIELD_I16(ro->chrinfo.animpart);
			PD_BEFIELD_I16(ro->chrinfo.mtxindex);
			PD_BEFIELD_I16(ro->chrinfo.rwdataindex);
			PD_BEFIELD_F32(ro->chrinfo.unk04);
			break;
		case MODELNODETYPE_POSITION:
			PD_BEFIELD_F32(ro->position.drawdist);
			PD_BEFIELD_F32(ro->position.pos.x);
			PD_BEFIELD_F32(ro->position.pos.y);
			PD_BEFIELD_F32(ro->position.pos.z);
			PD_BEFIELD_I16(ro->position.part);
			PD_BEFIELD_I16(ro->position.mtxindex0);
			PD_BEFIELD_I16(ro->position.mtxindex1);
			PD_BEFIELD_I16(ro->position.mtxindex2);
			break;
		case MODELNODETYPE_GUNDL:
			preprocessModelGunDL(&ro->gundl, base, ofs);
			break;
		case MODELNODETYPE_05:
			break;
		case MODELNODETYPE_DISTANCE:
			PD_BEFIELD_F32(ro->distance.near);
			PD_BEFIELD_F32(ro->distance.far);
			PD_BEFIELD_I16(ro->distance.rwdataindex);
			PD_BEFIELD_PTR(ro->distance.target);
			// TODO: assuming target points to one of the nodes we'll swap by following node->next
			break;
		case MODELNODETYPE_REORDER:
			PD_BEFIELD_F32(ro->reorder.unk00);
			PD_BEFIELD_F32(ro->reorder.unk04);
			PD_BEFIELD_F32(ro->reorder.unk08);
			PD_BEFIELD_F32(ro->reorder.unk0c[0]);
			PD_BEFIELD_F32(ro->reorder.unk0c[1]);
			PD_BEFIELD_F32(ro->reorder.unk0c[2]);
			PD_BEFIELD_I16(ro->reorder.rwdataindex);
			PD_BEFIELD_I16(ro->reorder.side);
			break;
		case MODELNODETYPE_BBOX:
			PD_BEFIELD_F32(ro->bbox.xmin);
			PD_BEFIELD_F32(ro->bbox.xmax);
			PD_BEFIELD_F32(ro->bbox.ymin);
			PD_BEFIELD_F32(ro->bbox.ymax);
			PD_BEFIELD_F32(ro->bbox.zmin);
			PD_BEFIELD_F32(ro->bbox.zmax);
			PD_BEFIELD_I32(ro->bbox.hitpart);
			break;
		case MODELNODETYPE_0B:
			PD_BEFIELD_PTR(ro->type0b.baseaddr);
			PD_BEFIELD_I16(ro->type0b.rwdataindex);
			PD_BEFIELD_I32(ro->type0b.unk00);
			PD_BEFIELD_PTR(ro->type0b.unk3c);
			// TODO: do we need to swap the rest of the words?
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			PD_BEFIELD_PTR(ro->chrgunfire.baseaddr);
			PD_BEFIELD_PTR(ro->chrgunfire.texture);
			PD_BEFIELD_I16(ro->chrgunfire.rwdataindex);
			PD_BEFIELD_F32(ro->chrgunfire.pos.x);
			PD_BEFIELD_F32(ro->chrgunfire.pos.y);
			PD_BEFIELD_F32(ro->chrgunfire.pos.z);
			PD_BEFIELD_F32(ro->chrgunfire.dim.x);
			PD_BEFIELD_F32(ro->chrgunfire.dim.y);
			PD_BEFIELD_F32(ro->chrgunfire.dim.z);
			PD_BEFIELD_F32(ro->chrgunfire.unk1c);
			// TODO: do we swap contents of *texture or is it part of mdl->textureconfigs[]?
			break;
		case MODELNODETYPE_0D:
			PD_BEFIELD_PTR(ro->type0d.baseaddr);
			PD_BEFIELD_PTR(ro->type0d.unk10);
			PD_BEFIELD_PTR(ro->type0d.unk14);
			// TODO: do we need to swap the rest of the words?
			break;
		case MODELNODETYPE_0E:
		case MODELNODETYPE_0F:
			break;
		case MODELNODETYPE_11:
			PD_BEFIELD_PTR(ro->type11.unk14);
			// TODO: do we need to swap the rest of the words?
			break;
		case MODELNODETYPE_TOGGLE:
			PD_BEFIELD_I16(ro->toggle.rwdataindex);
			PD_BEFIELD_PTR(ro->toggle.target);
			// TODO: assuming target points to one of the nodes we'll swap by following node->next
			break;
		case MODELNODETYPE_DL:
			preprocessModelDL(&ro->dl, base, ofs);
			break;
		case 0x19:
			PD_BEFIELD_I32(ro->type19.numvertices);
			for (s32 i = 0; i < ARRAYCOUNT(ro->type19.vertices); ++i) {
				PD_BEFIELD_F32(ro->type19.vertices[i].x);
				PD_BEFIELD_F32(ro->type19.vertices[i].y);
				PD_BEFIELD_F32(ro->type19.vertices[i].z);
			}
			break;
		default:
			fprintf(stderr, "preprocessModelNode: node at %p: unknown node->type: 0x%02x\n", node, node->type & 0xff);
			break;
	}

	if (node->child) {
		node = PD_PTR_BASEOFS(node->child, base, ofs);
	} else {
		while (node) {
			if (node->next) {
				node = PD_PTR_BASEOFS(node->next, base, ofs);
				break;
			}
			node = PD_PTR_BASEOFS(node->parent, base, ofs);
		}
	}
}

static inline void preprocessPadData(u8 *ptr)
{
	// for some insane reason pads are packed
	// header is always 1 word, the rest of the fields depends on the flags
	u32 *header = (u32 *) ptr;
	PD_BEFIELD_I32(header[0]);

	ptr += 4;

	if ((*header >> 14) & PADFLAG_INTPOS) {
		// position is 3x s16
		s16 *sbuffer = (s16 *) ptr;
		PD_BEFIELD_I16(sbuffer[0]);
		PD_BEFIELD_I16(sbuffer[1]);
		PD_BEFIELD_I16(sbuffer[2]);
		ptr += 8;
	} else {
		// position is 3x f32
		f32 *fbuffer = (f32 *) ptr;
		PD_BEFIELD_F32(fbuffer[0]);
		PD_BEFIELD_F32(fbuffer[1]);
		PD_BEFIELD_F32(fbuffer[2]);
		ptr += 12;
	}

	if (!((*header >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ))) {
		// up vector, 3x f32
		f32 *fbuffer = (f32 *) ptr;
		PD_BEFIELD_F32(fbuffer[0]);
		PD_BEFIELD_F32(fbuffer[1]);
		PD_BEFIELD_F32(fbuffer[2]);
		ptr += 12;
	}

	if (!((*header >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ))) {
		// look vector, 3x f32
		f32 *fbuffer = (f32 *) ptr;
		PD_BEFIELD_F32(fbuffer[0]);
		PD_BEFIELD_F32(fbuffer[1]);
		PD_BEFIELD_F32(fbuffer[2]);
		ptr += 12;
	}

	if ((*header >> 14) & PADFLAG_HASBBOXDATA) {
		// bbox, 3x f32 mins + 3x f32 maxs
		f32 *fbuffer = (f32 *) ptr;
		PD_BEFIELD_F32(fbuffer[0]);
		PD_BEFIELD_F32(fbuffer[1]);
		PD_BEFIELD_F32(fbuffer[2]);
		PD_BEFIELD_F32(fbuffer[3]);
		PD_BEFIELD_F32(fbuffer[4]);
		PD_BEFIELD_F32(fbuffer[5]);
	}
}


void preprocessAnimations(u8 *data, u32 size)
{
	// set the anim table pointers as well
	extern u8 *_animationsTableRomStart;
	extern u8 *_animationsTableRomEnd;
	// the animation table is at the end of the segment
	u32 *animtbl = (void *)(data + size - 0x38a0);
	_animationsTableRomStart = (u8 *)animtbl;
	_animationsTableRomEnd = data + size;
	PD_BEFIELD_I32(*animtbl);
	const u32 count = *animtbl++;
	struct animtableentry *anim = (struct animtableentry *)animtbl;
	for (u32 i = 0; i < count; ++i, ++anim) {
		PD_BEFIELD_I16(anim->numframes);
		PD_BEFIELD_I16(anim->bytesperframe);
		PD_BEFIELD_I16(anim->headerlen);
		PD_BEFIELD_I32(anim->data);
	}
}

void preprocessMpConfigs(u8 *data, u32 size)
{
	const u32 count = size / sizeof(struct mpconfig);
	struct mpconfig *cfg = (struct mpconfig *)data;
	for (u32 i = 0; i < count; ++i, ++cfg) {
		PD_BEFIELD_I32(cfg->setup.options);
		PD_BEFIELD_I16(cfg->setup.teamscorelimit);
		PD_BEFIELD_I16(cfg->setup.chrslots);
		// TODO: are these required or are they always 0?
		PD_BEFIELD_I16(cfg->setup.fileguid.deviceserial);
		PD_BEFIELD_I32(cfg->setup.fileguid.fileid);
	}
}

void preprocessFont(u8 *data, u32 size)
{
	struct font *fnt = (struct font *)data;

	for (s32 i = 0; i < ARRAYCOUNT(fnt->kerning); ++i) {
		PD_BEFIELD_I32(fnt->kerning[i]);
	}

	for (s32 i = 0; i < ARRAYCOUNT(fnt->chars); ++i) {
		PD_BEFIELD_I32(fnt->chars[i].kerningindex);
		PD_BEFIELD_PTR(fnt->chars[i].pixeldata);
	}
}

void preprocessJpnFont(u8 *data, u32 size)
{
	// ???
}

void preprocessALBankFile(u8 *data, u32 size)
{
	ALBankFile *bankf = (ALBankFile *)data;
	PD_BEFIELD_I16(bankf->revision);
	PD_BEFIELD_I16(bankf->bankCount);

	for (s16 i = 0; i < bankf->bankCount; ++i) {
		PD_BEFIELD_PTR(bankf->bankArray[i]);
		preprocessALBank(PD_PTR_BASE(bankf->bankArray[i], data), data);
	}
}

void preprocessSequences(u8 *data, u32 size)
{
	struct seqtable *seq = (struct seqtable *)data;
	PD_BEFIELD_I16(seq->count);

	for (s16 i = 0; i < seq->count; ++i) {
		PD_BEFIELD_I16(seq->entries[i].binlen);
		PD_BEFIELD_I16(seq->entries[i].ziplen);
		PD_BEFIELD_I32(seq->entries[i].romaddr);
	}
}

void preprocessFiringRange(u8 *data, u32 size)
{
	// u16 texts[9] is the first and only thing we care about here
	// probably no sense supporting custom sizes either
	u16 *texts = (u16 *)data;
	for (s32 i = 0; i < 9; ++i) {
		PD_BEFIELD_I16(texts[i]);
	}
}

void preprocessTexturesList(u8 *data, u32 size)
{
	struct texture *tex = (struct texture *)data;
	const u32 count = size / sizeof(*tex);
	for (u32 i = 0; i < count; ++i, ++tex) {
		// TODO: it sure looks like none of the fields except soundsurfacetype, surfacetype and dataoffset are set
		// just swap the last 3 bytes of the first word
		const u32 dofs = (u32)tex->dataoffset << 8;
		tex->dataoffset = PD_BE32(dofs);
	}
}

void preprocessModel(u8 *base, u32 ofs)
{
	struct modeldef *mdl = (struct modeldef *)base;

	PD_BEFIELD_I16(mdl->nummatrices);
	PD_BEFIELD_I16(mdl->numparts);
	PD_BEFIELD_I16(mdl->numtexconfigs);
	PD_BEFIELD_I16(mdl->rwdatalen);
	PD_BEFIELD_F32(mdl->scale);

	if (mdl->skel) {
		PD_BEFIELD_PTR(mdl->skel);
		if ((u32)mdl->skel >= 0x10000) {
			// skeleton is a pointer instead of an index
			// preprocessSkeleton((struct skeleton *)(base + (u32)mdl->skel)); // TODO
		}
	}

	if (mdl->parts) {
		PD_BEFIELD_PTR(mdl->parts);
		struct modelnode **parts = PD_PTR_BASEOFS(mdl->parts, base, ofs);
		for (s16 i = 0; i < mdl->numparts; ++i) {
			PD_BEFIELD_PTR(parts[i]);
		}
		s16 *partnums = (s16 *)&parts[mdl->numparts];
		for (s16 i = 0; i < mdl->numparts; ++i) {
			PD_BEFIELD_I16(partnums[i]);
		}
	}

	if (mdl->texconfigs) {
		PD_BEFIELD_PTR(mdl->texconfigs);
		struct textureconfig *texconfigs = PD_PTR_BASEOFS(mdl->texconfigs, base, ofs);
		for (s16 i = 0; i < mdl->numtexconfigs; ++i) {
			PD_BEFIELD_I32(texconfigs[i].texturenum);
		}
	}

	if (mdl->rootnode) {
		PD_BEFIELD_PTR(mdl->rootnode);
		preprocessModelNode(PD_PTR_BASEOFS(mdl->rootnode, base, ofs), base, ofs);
	}
}

void preprocessLangFile(u8 *data, u32 size)
{
	// lang banks are just an offset table + text data right after
	// offsets are from the beginning of the bank
	// however we cannot preprocess them in advance because the length of the
	// offset table is unknown, so that's done in lang.c on demand instead
}

void preprocessPadsFile(u8 *data, u32 size)
{
	struct padsfileheader *hdr = (void *)data;

	PD_BEFIELD_I32(hdr->numpads);
	PD_BEFIELD_I32(hdr->numcovers);

	for (s32 i = 0; i < hdr->numpads; ++i) {
		if (hdr->padoffsets[i]) {
			PD_BEFIELD_I32(hdr->padoffsets[i]);
			preprocessPadData(PD_PTR_BASE(hdr->padoffsets[i], hdr));
		}
	}

	if (hdr->numcovers && hdr->coversoffset) {
		PD_BEFIELD_I32(hdr->coversoffset);
		struct coverdefinition *def = PD_PTR_BASE(hdr->coversoffset, hdr);
		for (s32 i = 0; i < hdr->numcovers; ++i, ++def) {
			PD_BEFIELD_I16(def->flags);
			PD_BEFIELD_F32(def->look.x);
			PD_BEFIELD_F32(def->look.y);
			PD_BEFIELD_F32(def->look.z);
			PD_BEFIELD_F32(def->pos.x);
			PD_BEFIELD_F32(def->pos.y);
			PD_BEFIELD_F32(def->pos.z);
		}
	}

	if (hdr->waypointsoffset) {
		PD_BEFIELD_I32(hdr->waypointsoffset);
		struct waypoint *wp = PD_PTR_BASE(hdr->waypointsoffset, hdr);
		while (wp->padnum) {
			PD_BEFIELD_I32(wp->padnum);
			PD_BEFIELD_I32(wp->groupnum);
			PD_BEFIELD_I32(wp->step);
			PD_BEFIELD_PTR(wp->neighbours);
			++wp;
		}
	}

	if (hdr->waygroupsoffset) {
		PD_BEFIELD_I32(hdr->waygroupsoffset);
		struct waygroup *wg = PD_PTR_BASE(hdr->waygroupsoffset, hdr);
		while (wg->neighbours) {
			PD_BEFIELD_PTR(wg->neighbours);
			PD_BEFIELD_PTR(wg->waypoints);
			PD_BEFIELD_I32(wg->step);
			++wg;
		}
	}
}

void preprocessTilesFile(u8 *data, u32 size)
{
	u32 *roomTable = (u32 *)data;
	PD_BEFIELD_I32(roomTable[0]);

	const u32 numRooms = roomTable[0];
	++roomTable;

	u32 *rooms = roomTable;
	for (u32 i = 0; i < numRooms; ++i) {
		PD_BEFIELD_I32(rooms[i]);
	}

	struct geo *geo = (struct geo *)(data + rooms[0]);
	struct geo *end = (struct geo *)(data + rooms[numRooms]);

	while (geo < end) {
		PD_BEFIELD_I16(geo->flags);
		switch (geo->type) {
			case GEOTYPE_TILE_I: {
				struct geotilei *tile = (struct geotilei *)geo;
				PD_BEFIELD_I16(tile->floorcol);
				PD_BEFIELD_I16(tile->floortype);
				for (u32 i = 0; i < geo->numvertices; ++i) {
					PD_BEFIELD_I16(tile->vertices[i][0]);
					PD_BEFIELD_I16(tile->vertices[i][1]);
					PD_BEFIELD_I16(tile->vertices[i][2]);
				}
				geo = (struct geo *)((u8 *)geo + (uintptr_t)(geo->numvertices - 0x40) * 6 + 0x18e);
				break;
			}
			case GEOTYPE_TILE_F: {
				struct geotilef *tile = (struct geotilef *)geo;
				PD_BEFIELD_I16(tile->floorcol);
				PD_BEFIELD_I16(tile->floortype);
				for (u32 i = 0; i < geo->numvertices; ++i) {
					PD_BEFIELD_F32(tile->vertices[i].x);
					PD_BEFIELD_F32(tile->vertices[i].y);
					PD_BEFIELD_F32(tile->vertices[i].z);
				}
				geo = (struct geo *)((u8 *)geo + (uintptr_t)(geo->numvertices - 0x40) * 12 + 0x310);
				break;
			}
			case GEOTYPE_BLOCK: {
				struct geoblock *blk = (struct geoblock *)geo;
				PD_BEFIELD_F32(blk->ymin);
				PD_BEFIELD_F32(blk->ymax);
				for (u32 i = 0; i < geo->numvertices; ++i) {
					PD_BEFIELD_F32(blk->vertices[i][0]);
					PD_BEFIELD_F32(blk->vertices[i][1]);
				}
				geo = (struct geo *)((u8 *)geo + sizeof(struct geoblock));
				break;
			}
			case GEOTYPE_CYL: {
				struct geocyl *cyl = (struct geocyl *)geo;
				PD_BEFIELD_F32(cyl->x);
				PD_BEFIELD_F32(cyl->z);
				PD_BEFIELD_F32(cyl->radius);
				PD_BEFIELD_F32(cyl->ymin);
				PD_BEFIELD_F32(cyl->ymax);
				geo = (struct geo *)((u8 *)geo + sizeof(struct geocyl));
				break;
			}
			default:
				break;
		}
	}
}

void preprocessSetupFile(u8 *data, u32 size)
{
	struct stagesetup *set = (void *)data;

	if (set->intro) {
		PD_BEFIELD_PTR(set->intro);
		for (s32 *p = PD_PTR_BASE(set->intro, set); (u8 *)p < data + size; ++p) {
			PD_BEFIELD_I32(*p);
			if (*p == 0x0c /*endintro*/) {
				break;
			}
		}
	}

	if (set->props) {
		PD_BEFIELD_PTR(set->props);
		for (s32 *p = PD_PTR_BASE(set->props, set); (u8 *)p < data + size; ++p) {
			PD_BEFIELD_I32(*p);
			if (*p == 0x34 /*endprops*/) {
				break;
			}
		}
	}

	if (set->paths) {
		PD_BEFIELD_PTR(set->paths);
		struct path *p = PD_PTR_BASE(set->paths, set);
		while ((u8 *)p < data + size && p->pads) {
			PD_BEFIELD_PTR(p->pads);
			PD_BEFIELD_I16(p->len);
			s32 *pp = PD_PTR_BASE(p->pads, set);
			while ((u8 *)pp < data + size) {
				PD_BEFIELD_I32(*pp);
				if (*pp < 0) {
					break;
				}
			}
		}
	}

	if (set->ailists) {
		PD_BEFIELD_PTR(set->ailists);
		struct ailist *p = PD_PTR_BASE(set->ailists, set);
		while ((u8 *)p < data + size && p->list) {
			PD_BEFIELD_I32(p->id);
			PD_BEFIELD_PTR(p->list);
			// the actual command lists are made up of variable length instructions,
			// but they don't do any wonky word casting, so they should probably work as is
		}
	}

	// the rest of the pointers are set after loading
}

void preprocessModelFile(u8 *data, u32 size)
{
	preprocessModel(data, size);
}

void preprocessGunFile(u8 *data, u32 size)
{
	preprocessModel(data, size);
}

void preprocessBgSection1Header(u8 *data, u32 size)
{
	u32 *header = (u32 *)data;
	PD_BEFIELD_I32(header[0]); // inflatedsize
	PD_BEFIELD_I32(header[1]); // section1size
	PD_BEFIELD_I32(header[2]); // primcompsize
}

void preprocessBgSection1(u8 *data, u32 ofs) {
	struct {
		u32 unk00;
		u32 roomsofs;
		u32 portalsofs;
		u32 commandsofs;
		u32 lightsofs;
		u32 stanofs;
	} __attribute__((packed)) *header = (void *)data;

	PD_BEFIELD_I32(header->unk00);
	PD_BEFIELD_I32(header->roomsofs);
	PD_BEFIELD_I32(header->portalsofs);

	struct bgroom *rm = PD_PTR_BASEOFS(header->roomsofs, data, ofs);
	for (; rm->unk00; ++rm) {
		PD_BEFIELD_I32(rm->unk00);
		PD_BEFIELD_F32(rm->pos.x);
		PD_BEFIELD_F32(rm->pos.y);
		PD_BEFIELD_F32(rm->pos.z);
	}

	struct bgportal *portals = PD_PTR_BASEOFS(header->portalsofs, data, ofs);
	s32 numportals = 0;
	u32 offset = 0;
	for (struct bgportal *prt = portals; prt->verticesoffset; ++prt) {
		PD_BEFIELD_I16(prt->verticesoffset);
		PD_BEFIELD_I16(prt->roomnum1);
		PD_BEFIELD_I16(prt->roomnum2);
		++numportals;
		offset += sizeof(struct bgportal);
	}
	offset += sizeof(struct bgportal);

	// see bgBuildTables for an explanation of what the fuck this is
	for (s32 i = 1; 1; i++) {
		for (s32 j = 0; j < numportals; j++) {
			if (portals[j].verticesoffset == i) {
				portals[j].verticesoffset = offset;
			}
		}
		struct portalvertices *pverts = PD_PTR_BASE(offset, portals);
		for (u32 i = 0; i < pverts->count; ++i) {
			PD_BEFIELD_F32(pverts->vertices[i].x);
			PD_BEFIELD_F32(pverts->vertices[i].y);
			PD_BEFIELD_F32(pverts->vertices[i].z);
		}
	}

	if (header->commandsofs) {
		PD_BEFIELD_I32(header->commandsofs);
		struct bgcmd *cmd = PD_PTR_BASEOFS(header->commandsofs, data, ofs);
		for (; cmd->type != 0x00; cmd++) {
			PD_BEFIELD_I32(cmd->param);
		}
	}

	if (header->lightsofs) {
		PD_BEFIELD_I32(header->lightsofs);
		// data swapping done later in preprocessBgLights
	}

	if (header->stanofs) {
		PD_BEFIELD_I32(header->stanofs);
		// unused, so won't swap the contents
	}
}

void preprocessBgSection2Header(u8 *data, u32 size)
{
	u16 *header = (u16 *)data;
	PD_BEFIELD_I16(header[0]); // inflatedsize
	PD_BEFIELD_I16(header[1]); // section2compsize
}

void preprocessBgSection2(u8 *data, u32 size)
{
	// section2 is a texture id list
	u16 *section2 = (u16 *)data;
	for (s32 i = 0; i < size; ++i) {
		PD_BEFIELD_I16(section2[i]);
	}
}

void preprocessBgSection3Header(u8 *data, u32 size)
{
	u16 *header = (u16 *)data;
	PD_BEFIELD_I16(header[0]);
	PD_BEFIELD_I16(header[1]);
}

void preprocessBgSection3(u8 *data, u32 size)
{
	// room bounding boxes, 6x s16 per room
	s16 *bbox = (s16 *)data;
	for (s32 i = 1; i < g_Vars.roomcount; ++i) {
		PD_BEFIELD_I16(*bbox); ++bbox;
		PD_BEFIELD_I16(*bbox); ++bbox;
		PD_BEFIELD_I16(*bbox); ++bbox;
		PD_BEFIELD_I16(*bbox); ++bbox;
		PD_BEFIELD_I16(*bbox); ++bbox;
		PD_BEFIELD_I16(*bbox); ++bbox;
	}

	// gfxdatalen list
	u16 *gfxdatalen = (u16 *)bbox;
	for (s32 i = 1; i < g_Vars.roomcount; ++i) {
		PD_BEFIELD_I16(*gfxdatalen); ++gfxdatalen;
	}
}

void preprocessBgRoom(u8 *data, u32 ofs) {
	struct roomgfxdata *rgfx = (void *)data;

	PD_BEFIELD_I16(rgfx->numvertices);
	PD_BEFIELD_I16(rgfx->numcolours);
	PD_BEFIELD_I16(rgfx->numlights);
	PD_BEFIELD_I16(rgfx->lightsindex);
	PD_BEFIELD_PTR(rgfx->vertices);
	PD_BEFIELD_PTR(rgfx->opablocks);
	PD_BEFIELD_PTR(rgfx->xlublocks);
	PD_BEFIELD_PTR(rgfx->colours);

	Vtx *vertices = PD_PTR_BASEOFS(rgfx->vertices, data, ofs);
	Vtx *vtx = vertices;
	for (s32 i = 0; i < rgfx->numvertices; ++i, ++vtx) {
		preprocessVtx(vtx);
	}

	// here's hoping that xlublocks and opablocks aren't completely separate trees

	struct roomblock *blk = rgfx->blocks;
	struct roomblock *end = (void *)vertices;
	struct coord *tmp;

	for (; blk + 1 <= end; blk++) {
		PD_BEFIELD_PTR(blk->next);
		switch (blk->type) {
			case ROOMBLOCKTYPE_LEAF:
				if (blk->gdl) {
					PD_BEFIELD_PTR(blk->gdl);
					preprocessGfx(PD_PTR_BASEOFS(blk->gdl, data, ofs));
				}
				break;
			case ROOMBLOCKTYPE_PARENT:
				PD_BEFIELD_PTR(blk->child);
				PD_BEFIELD_PTR(blk->unk0c);
				tmp = PD_PTR_BASEOFS(blk->unk0c, data, ofs);
				for (s32 i = 0; i < 2; ++i) {
					PD_BEFIELD_F32(tmp[i].x);
					PD_BEFIELD_F32(tmp[i].y);
					PD_BEFIELD_F32(tmp[i].z);
				}
				if ((u8 *)tmp < (u8 *)end) {
					end = (void *)tmp;
				}
				break;
			default:
				break;
		}
	}
}

void preprocessBgLights(u8 *data, u32 ofs)
{
	struct light *lbase = (void *)data;
	if (!lbase) {
		return;
	}

	for (s32 i = 0; i < g_Vars.roomcount; ++i) {
		if (g_Rooms[i].numlights) {
			struct light *lit = &lbase[g_Rooms[i].lightindex];
			for (s32 i = 0; i < g_Rooms[i].numlights; ++i, ++lit) {
				PD_BEFIELD_I16(lit->bbox->x);
				PD_BEFIELD_I16(lit->bbox->y);
				PD_BEFIELD_I16(lit->bbox->z);
				PD_BEFIELD_I16(lit->colour); // TODO: required?
				PD_BEFIELD_I16(lit->roomnum);
			}
		}
	}
}
