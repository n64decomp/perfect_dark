/*====================================================================
 * initfx.h
 *
 * Copyright 1993, Silicon Graphics, Inc.
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

#ifndef __initfx__
#define __initfx__

#define MAX_L0 AL_FX_BUFFER_SIZE/4
#define MAX_L1 AL_FX_BUFFER_SIZE/4
#define MAX_L2 AL_FX_BUFFER_SIZE/2

#define L0_INC MAX_L0/128
#define L1_INC MAX_L1/128
#define L2_INC MAX_L2/128

#define SMALLROOM_SECT_CNT 3
#define SMALLROOM_SIZE AL_FX_BUFFER_SIZE
#define SMALLROOM_L0 880	/* 22 ms */
#define SMALLROOM_C0 9830
#define SMALLROOM_L1 1400	/* 35 ms */
#define SMALLROOM_C1 3276
#define SMALLROOM_L2 2640	/* 66 ms */
#define SMALLROOM_C2 10000
#define SMALLROOM_FILT_CNT 1
#define SMALLROOM_FC0 0x4000	/* .25 */

#define BIGROOM_SECT_CNT 3
#define BIGROOM_SIZE AL_FX_BUFFER_SIZE
#define BIGROOM_L0 1408		/* 32 ms */
#define BIGROOM_C0 9830
#define BIGROOM_L1 1984		/* 45 ms */
#define BIGROOM_C1 9830
#define BIGROOM_L2 3792		/* 86 ms */
#define BIGROOM_C2 12000
#define BIGROOM_FILT_CNT 1
#define BIGROOM_FC0 0x4000	/* .25 */

#define ECHO_SIZE AL_FX_BUFFER_SIZE
#define ECHO_SECT_CNT 1
#define ECHO_L0 7936		/* 180 ms */
#define ECHO_C0 0x6000

#endif
