#ifndef _IN_LANG_H
#define _IN_LANG_H

/**
 * Text is referenced throughout the code using 16-bit integers.
 * The first 7 bits are the bank/file number, and the remaining
 * 9 bits are the string index within that file.
 *
 * There is one bank/file per stage, as well as common banks for
 * menus, weapons and so on.
 */

#define LANGBANK_AME       0x01
#define LANGBANK_ARCH      0x02
#define LANGBANK_ARK       0x03
#define LANGBANK_ASH       0x04
#define LANGBANK_AZT       0x05
#define LANGBANK_CAT       0x06
#define LANGBANK_CAVE      0x07
#define LANGBANK_AREC      0x08
#define LANGBANK_CRAD      0x09
#define LANGBANK_CRYP      0x0a
#define LANGBANK_DAM       0x0b
#define LANGBANK_DEPO      0x0c
#define LANGBANK_DEST      0x0d
#define LANGBANK_DISH      0x0e
#define LANGBANK_EAR       0x0f
#define LANGBANK_ELD       0x10
#define LANGBANK_IMP       0x11
#define LANGBANK_JUN       0x12
#define LANGBANK_LEE       0x13
#define LANGBANK_LEN       0x14
#define LANGBANK_LIP       0x15
#define LANGBANK_LUE       0x16
#define LANGBANK_OAT       0x17
#define LANGBANK_PAM       0x18
#define LANGBANK_PETE      0x19
#define LANGBANK_REF       0x1a
#define LANGBANK_RIT       0x1b
#define LANGBANK_RUN       0x1c
#define LANGBANK_SEVB      0x1d
#define LANGBANK_SEV       0x1e
#define LANGBANK_SEVX      0x1f
#define LANGBANK_SEVXB     0x20
#define LANGBANK_SHO       0x21
#define LANGBANK_SILO      0x22
#define LANGBANK_STAT      0x23
#define LANGBANK_TRA       0x24
#define LANGBANK_WAX       0x25
#define LANGBANK_GUN       0x26
#define LANGBANK_TITLE     0x27
#define LANGBANK_MPMENU    0x28
#define LANGBANK_PROPOBJ   0x29
#define LANGBANK_MPWEAPONS 0x2a
#define LANGBANK_OPTIONS   0x2b
#define LANGBANK_MISC      0x2c
#define LANGBANK_UFF       0x2d
#define LANGBANK_OLD       0x2e
#define LANGBANK_ATE       0x2f
#define LANGBANK_LAM       0x30
#define LANGBANK_MP1       0x31
#define LANGBANK_MP2       0x32
#define LANGBANK_MP3       0x33
#define LANGBANK_MP4       0x34
#define LANGBANK_MP5       0x35
#define LANGBANK_MP6       0x36
#define LANGBANK_MP7       0x37
#define LANGBANK_MP8       0x38
#define LANGBANK_MP9       0x39
#define LANGBANK_MP10      0x3a
#define LANGBANK_MP11      0x3b
#define LANGBANK_MP12      0x3c
#define LANGBANK_MP13      0x3d
#define LANGBANK_MP14      0x3e
#define LANGBANK_MP15      0x3f
#define LANGBANK_MP16      0x40
#define LANGBANK_MP17      0x41
#define LANGBANK_MP18      0x42
#define LANGBANK_MP19      0x43
#define LANGBANK_MP20      0x44

/**
 * Include each lang header, which defines their enums.
 */
#include "lang/ame.h"
#include "lang/arch.h"
#include "lang/ark.h"
#include "lang/ash.h"
#include "lang/azt.h"
#include "lang/cat.h"
#include "lang/cave.h"
#include "lang/arec.h"
#include "lang/crad.h"
#include "lang/cryp.h"
#include "lang/dam.h"
#include "lang/depo.h"
#include "lang/dest.h"
#include "lang/dish.h"
#include "lang/ear.h"
#include "lang/eld.h"
#include "lang/imp.h"
#include "lang/jun.h"
#include "lang/lee.h"
#include "lang/len.h"
#include "lang/lip.h"
#include "lang/lue.h"
#include "lang/oat.h"
#include "lang/pam.h"
#include "lang/pete.h"
#include "lang/ref.h"
#include "lang/rit.h"
#include "lang/run.h"
#include "lang/sevb.h"
#include "lang/sev.h"
#include "lang/sevx.h"
#include "lang/sevxb.h"
#include "lang/sho.h"
#include "lang/silo.h"
#include "lang/stat.h"
#include "lang/tra.h"
#include "lang/wax.h"
#include "lang/gun.h"
#include "lang/title.h"
#include "lang/mpmenu.h"
#include "lang/propobj.h"
#include "lang/mpweapons.h"
#include "lang/options.h"
#include "lang/misc.h"
#include "lang/uff.h"
#include "lang/old.h"
#include "lang/ate.h"
#include "lang/lam.h"
#include "lang/mp1.h"
#include "lang/mp2.h"
#include "lang/mp3.h"
#include "lang/mp4.h"
#include "lang/mp5.h"
#include "lang/mp6.h"
#include "lang/mp7.h"
#include "lang/mp8.h"
#include "lang/mp9.h"
#include "lang/mp10.h"
#include "lang/mp11.h"
#include "lang/mp12.h"
#include "lang/mp13.h"
#include "lang/mp14.h"
#include "lang/mp15.h"
#include "lang/mp16.h"
#include "lang/mp17.h"
#include "lang/mp18.h"
#include "lang/mp19.h"
#include "lang/mp20.h"

#endif
