/*====================================================================
 * uportals.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/**************************************************************************
 *
 *  uportals.h - header file for the ultraportals library
 *
 *  $Revision: 1.12 $
 *  $Date: 1997/02/11 08:40:49 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/uportals.h,v $
 *
 **************************************************************************/



#ifndef __ULTRAPORTALS_H__
#define __ULTRAPORTALS_H__

#include <ultra64.h>
#include "matrix.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ENABLEPORTALS
#define ENABLEPORTALS
#endif

#define UP_MAXPVERTS 	16		/* max number of portal verts	*/
#define UP_MAXCELLS	50		/* max number of cells		*/
#define UP_CELLNL	32		/* max length of cell names 	*/
#define UP_OBNL		32		/* max length of obejct names 	*/
    
typedef struct
{
    vec3	min, max;		/* min and max pts of the box	*/
} upBox;

typedef struct _upPortalData * _portalptr;
typedef struct _upCellData * _cellptr;
typedef struct _upObjectData * _objectptr;

typedef struct _upPortalData
{
    int 	numverts;		/* number of verts in the portal*/
    _cellptr	attached_cell;		/* cell on the 'other side'	*/
    vec3	verts[UP_MAXPVERTS];	/* the actual vertices		*/
#ifdef MVTVIEW
    int         mvt_id;                 /* if has mvt, this is the id   */
#endif
} upPortalData;

typedef struct _upCellData
{
    int 	numportals;		/* number of portals		*/
    int 	numobjects;		/* number of objects		*/
    int 	rendered;		/* last frame number rendered	*/
    _portalptr	*portals;		/* array for the actual portals	*/
    _objectptr  *objects;		/* array for 'detail' objects	*/
    upBox	bbox;			/* bounding box of the cell	*/
    Gfx		*dlist;			/* associated display list	*/
    char	name[UP_CELLNL];	/* name of the cell		*/
    float 	eyeheight;		/* height to constrain eyept to */
    int		zone;			/* current zone number		*/
} upCellData;

typedef struct _upObjectData
{
    int 	rendered;		/* last frame number rendered   */
    upBox	bbox;			/* bounding box for the object 	*/
    Gfx		*dlist;			/* associated display list	*/
    char	name[UP_OBNL];		/* name of the object		*/
} upObjectData;

typedef struct
{
    int 	numcells;		/* how many cells are there?	*/
    upCellData	cells[UP_MAXCELLS];   	/* the actual cells		*/
    Gfx		*rootdlist;		/* display list for all cells	*/
    vec2	portalmin, portalmax;	/* XY bbox used by upCheckCells */
    float	near, far;		/* near, far clipping planes	*/
    FMatrix	viewmat;		/* viewing matrix (world->eye)	*/
    FMatrix	projmat;		/* proj matrix (eye->screen)	*/
    FMatrix 	compmat;		/* view * proj (world->screen)	*/
    int		portaldepth;		/* depth of the portal stack	*/
    int		framecount;		/* current frame number		*/
} upLocateData;

/*
 * Functions:
 */
extern void upInit();		/* generated automatically by flt2walk	*/
extern Gfx *upAddVisibleCells(Gfx * glistp, vec3 eyept);
extern void upTogglePortalBounds();
extern void upToggleScissorBox();

/*
 * Globals:
 */
extern upLocateData 	upLocator;	/* also extern by test_portals.h */

/*
 * Macros:
 */
#define UP_HUGEVAL  3.40282347e+37
#define PT_IN_BOX(p,box) ((p)[0] > (box).min[0] && (p)[0] < (box).max[0] &&\
			  (p)[1] > (box).min[1] && (p)[1] < (box).max[1] &&\
			  (p)[2] > (box).min[2] && (p)[2] < (box).max[2])


#ifdef __Cplusplus
}
#endif

#endif
