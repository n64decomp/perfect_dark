/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1995, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright  law.  They  may not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 *************************************************************************/

/**************************************************************************
 *
 *  $Revision: 1.8 $
 *  $Date: 1997/07/02 02:35:06 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/ultrahost.h,v $
 *
 **************************************************************************/

#ifndef _ULTRAHOST_H_
#define _ULTRAHOST_H_

#ifdef PTN64 /* { */

#define	execl		execl_pt

#define uhOpenGame	uhOpenGame_pt
#define uhCloseGame	uhCloseGame_pt

#define uhReadGame	uhReadGame_pt
#define uhWriteGame	uhWriteGame_pt
#define uhReadRamrom	uhReadRamrom_pt
#define uhWriteRamrom	uhWriteRamrom_pt
#define uhPartnerCmd	uhPartnerCmd_pt
#define uhGload		uhGload_pt

int uhPartnerCmd(int,char *);
int uhGload(int,char *);

#endif /* } */

#ifdef __cplusplus
extern "C" {
#endif
int	uhOpenGame(const char *);
int	uhCloseGame(int);

int	uhReadGame(int, void *, int);
int	uhWriteGame(int, void *, int);
int	uhWriteRamrom(int, void *, void*, int);
int	uhReadRamrom(int, void *, void*, int);

#ifdef __cplusplus
}
#endif

#endif /* ULTRAHOST */
