#ifndef IN_GAME_DATA_02e820_H
#define IN_GAME_DATA_02e820_H
#include <ultra64.h>
#include "game/data/data_020df0.h"

extern u32 var80088800;
extern u8 var80088804;
extern u8 var80088808;
extern u8 var8008880c;
extern void *var80088810;
extern u16 g_FrPads[];
extern u32 var80088854;
extern u8 var800888a0;
extern struct chrbio g_ChrBios[10];
extern u32 misc_bios[];
extern u32 var80088964;
extern u32 place_bios[];
extern u8 var80088ad8;
extern u8 var80088adc;
extern u8 g_CiDeviceSaveFileFlags[10];
extern u32 g_CiDeviceWeapons[10];
extern u32 g_CiDeviceStageFlags[10];
extern u32 device_descriptions[10];
extern u32 device_tips1[10];
extern u32 device_tips2[10];
extern u8 var80088bb4;
extern u8 var80088bb8;
extern s16 g_HoloRooms[5];
extern u32 var80088bc8;
extern u32 var80088be4;
extern u32 var80088c04;
extern u32 var80088c20;
extern u32 var80088c3c;
extern u32 var80088c58;
extern u32 var80088c70;
extern u16 g_FiringRangeFailReasons[5];
extern u16 g_FiringRangeDifficultyNames[3];
extern u32 var80088c8c;
extern u32 var80088c90;
extern u32 var80088c94;
extern u32 var80088c98;
extern u32 var80088c9c;
extern u32 var80088ca0;
extern u32 var80088ca4;
extern u32 var80088ca8;
extern struct menu_dialog menudialog_frdifficulty;
extern struct menu_dialog g_FrWeaponListMenuDialog;
extern struct menu_dialog g_FrTrainingInfoMenuDialog;
extern struct menu_dialog menudialog_frtraininginfo2;
extern struct menu_dialog menudialog_frtrainingstats;
extern struct menu_dialog menudialog_frtrainingstats2;
extern u32 var800891b0;
extern struct menu_dialog menudialog_information;
extern u32 var80089268;
extern u32 var80089280;
extern struct menu_dialog menudialog_characterprofile;
extern struct menu_dialog menudialog_2f3c0;
extern struct menu_dialog g_DeviceTrainingListMenuDialog;
extern u32 var800893f8;
extern struct menu_dialog g_DeviceTrainingDetailsMenuDialog;
extern struct menu_dialog g_DeviceTrainingStatsFailedMenuDialog;
extern struct menu_dialog g_DeviceTrainingStatsCompletedMenuDialog;
extern struct menu_dialog g_HoloTrainingListMenuDialog;
extern struct menu_dialog g_HoloTrainingDetailsMenuDialog;
extern struct menu_dialog g_HoloTrainingStatsFailedMenuDialog;
extern struct menu_dialog g_HoloTrainingStatsCompletedMenuDialog;
extern u32 var800897a4;
extern u32 var800897b4;
extern u32 var800897c4;
extern struct hoverprop hoverprops[];
extern struct menu_dialog menudialog_2f938;
extern struct menu_dialog menudialog_2f950;
extern struct menu_dialog menudialog_hangarinformation;
extern u32 var80089ad0;
extern u32 var8008a2d0;

#endif
