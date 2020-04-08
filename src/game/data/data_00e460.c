#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/game_0601b0.h"
#include "game/game_015470.h"
#include "game/game_0dcdb0.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "stagesetup.h"
#include "types.h"

u32 var80068460 = 0x10204080;
u8 g_ChrTeamIds[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
u32 var8006846c = 0x00000064;
u32 var80068470 = 0x00000065;
u32 var80068474 = 0x00000066;
u32 var80068478 = 0x00000067;
u32 var8006847c = 0x00000030;
u32 var80068480 = 0x0000003a;
u32 var80068484 = 0x00000023;
u32 var80068488 = 0x00000023;
u32 var8006848c = 0x00000000;

// e4b0
bool (*g_CommandPointers[])(void) = {
	/*0x0000*/ aiGoToNext,
	/*0x0001*/ aiGoToFirst,
	/*0x0002*/ aiLabel,
	/*0x0003*/ aiYield,
	/*0x0004*/ aiEndList,
	/*0x0005*/ aiSetList,
	/*0x0006*/ aiSetReturnList,
	/*0x0007*/ aiSetShotList,
	/*0x0008*/ aiReturn,
	/*0x0009*/ aiStop,
	/*0x000a*/ aiKneel,
	/*0x000b*/ aiChrDoAnimation,
	/*0x000c*/ aiIfIdle,
	/*0x000d*/ aiBeSurprised000d,
	/*0x000e*/ aiBeSurprised000e,
	/*0x000f*/ aiStepSideways,
	/*0x0010*/ aiHopSideways,
	/*0x0011*/ aiRunSideways,
	/*0x0012*/ aiWalkAndFire,
	/*0x0013*/ aiRunAndFire,
	/*0x0014*/ aiRollAndFire,
	/*0x0015*/ aiAimAndFire1,
	/*0x0016*/ aiKneelAndFire,
	/*0x0017*/ aiAimAndFire2,
	/*0x0018*/ aiFaceEntity,
	/*0x0019*/ ai0019,
	/*0x001a*/ ai001a,
	/*0x001b*/ aiConsiderGrenadeThrow,
	/*0x001c*/ ai001c,
	/*0x001d*/ aiJogToPad,
	/*0x001e*/ aiGoToPadPreset,
	/*0x001f*/ aiWalkToPad,
	/*0x0020*/ aiRunToPad,
	/*0x0021*/ aiSetPath,
	/*0x0022*/ aiStartPath,
	/*0x0023*/ aiIfPathStarted,
	/*0x0024*/ aiSurrender,
	/*0x0025*/ aiFadeOut,
	/*0x0026*/ aiRemoveChr,
	/*0x0027*/ ai0027,
	/*0x0028*/ aiActivateAlarm,
	/*0x0029*/ aiDeactivateAlarm,
	/*0x002a*/ ai002a,
	/*0x002b*/ aiTryJogToTargetProp,
	/*0x002c*/ aiTryWalkToTargetProp,
	/*0x002d*/ aiTryRunToTargetProp,
	/*0x002e*/ ai002e,
	/*0x002f*/ aiTryJogToChr,
	/*0x0030*/ aiTryWalkToChr,
	/*0x0031*/ aiTryRunToChr,
	/*0x0032*/ aiIfStopped,
	/*0x0033*/ aiIfChrDying,
	/*0x0034*/ aiIfChrDeathAnimationFinished,
	/*0x0035*/ aiIfTargetPropInSight,
	/*0x0036*/ aiRandom,
	/*0x0037*/ aiIfRandomLessThan,
	/*0x0038*/ aiIfRandomGreaterThan,
	/*0x0039*/ aiIfChrAlarmActivate,
	/*0x003a*/ aiIfAlarmActive,
	/*0x003b*/ aiIfAlarmInactive,
	/*0x003c*/ ai003c,
	/*0x003d*/ aiIfSawInjury,
	/*0x003e*/ aiIfSawDeath,
	/*0x003f*/ aiIfSeesPlayer,
	/*0x0040*/ ai0040,
	/*0x0041*/ ai0041,
	/*0x0042*/ aiIfInLoadedRoom,
	/*0x0043*/ aiIfSawTargetRecently,
	/*0x0044*/ aiIfHeardTargetRecently,
	/*0x0045*/ ai0045,
	/*0x0046*/ aiIfNeverBeenOnScreen,
	/*0x0047*/ ai0047,
	/*0x0048*/ aiIfChrInActiveRoom,
	/*0x0049*/ aiIfRoomActive,
	/*0x004a*/ ai004a,
	/*0x004b*/ aiIfNearMiss,
	/*0x004c*/ aiIfSeesSuspiciousItem,
	/*0x004d*/ ai004d,
	/*0x004e*/ ai004e,
	/*0x004f*/ ai004f,
	/*0x0050*/ ai0050,
	/*0x0051*/ ai0051,
	/*0x0052*/ aiIfDistanceToTargetLessThan,
	/*0x0053*/ aiIfDistanceToTargetGreaterThan,
	/*0x0054*/ aiIfChrDistanceToPadLessThan,
	/*0x0055*/ aiIfChrDistanceToPadGreaterThan,
	/*0x0056*/ aiIfDistanceToChrLessThan,
	/*0x0057*/ aiIfDistanceToChrGreaterThan,
	/*0x0058*/ ai0058,
	/*0x0059*/ aiIfDistanceFromTargetToPadLessThan,
	/*0x005a*/ aiIfDistanceFromTargetToPadGreaterThan,
	/*0x005b*/ aiIfChrInRoom,
	/*0x005c*/ aiIfTargetInRoom,
	/*0x005d*/ aiIfChrHasObject,
	/*0x005e*/ aiIfWeaponThrown,
	/*0x005f*/ aiIfWeaponThrownOnObject,
	/*0x0060*/ aiIfChrHasWeaponEquipped,
	/*0x0061*/ aiIfGunUnclaimed,
	/*0x0062*/ aiIfObjectHealthy,
	/*0x0063*/ aiIfChrActivatedObject,
	/*0x0064*/ NULL,
	/*0x0065*/ ai0065,
	/*0x0066*/ aiDestroyObject,
	/*0x0067*/ ai0067,
	/*0x0068*/ aiChrDropItems,
	/*0x0069*/ aiChrDropWeapon,
	/*0x006a*/ aiGiveObjectToChr,
	/*0x006b*/ aiObjectMoveToPad,
	/*0x006c*/ aiOpenDoor,
	/*0x006d*/ aiCloseDoor,
	/*0x006e*/ aiIfDoorState,
	/*0x006f*/ aiIfObjectIsDoor,
	/*0x0070*/ aiLockDoor,
	/*0x0071*/ aiUnlockDoor,
	/*0x0072*/ aiIfDoorLocked,
	/*0x0073*/ aiIfObjectiveComplete,
	/*0x0074*/ aiIfObjectiveFailed,
	/*0x0075*/ ai0075,
	/*0x0076*/ ai0076,
	/*0x0077*/ aiIfDifficultyLessThan,
	/*0x0078*/ aiIfDifficultyGreaterThan,
	/*0x0079*/ aiIfUptimeLessThan,
	/*0x007a*/ aiIfUptimeGreaterThan,
	/*0x007b*/ aiIfStageIdLessThan,
	/*0x007c*/ aiIfStageIdGreaterThan,
	/*0x007d*/ aiIfNumArghsLessThan,
	/*0x007e*/ aiIfNumArghsGreaterThan,
	/*0x007f*/ aiIfNumCloseArghsLessThan,
	/*0x0080*/ aiIfNumCloseArghsGreaterThan,
	/*0x0081*/ aiIfChrHealthGreaterThan,
	/*0x0082*/ aiIfChrHealthLessThan,
	/*0x0083*/ aiIfInjured,
	/*0x0084*/ aiSetMorale,
	/*0x0085*/ aiAddMorale,
	/*0x0086*/ aiChrAddMorale,
	/*0x0087*/ aiSubtractMorale,
	/*0x0088*/ aiIfMoraleLessThan,
	/*0x0089*/ aiIfMoraleLessThanRandom,
	/*0x008a*/ aiSetAlertness,
	/*0x008b*/ aiAddAlertness,
	/*0x008c*/ aiChrAddAlertness,
	/*0x008d*/ aiSubtractAlertness,
	/*0x008e*/ aiIfAlertness,
	/*0x008f*/ aiIfChrAlertnessLessThan,
	/*0x0090*/ aiIfAlertnessLessThanRandom,
	/*0x0091*/ aiNoOp0091,
	/*0x0092*/ aiSetHearDistance,
	/*0x0093*/ aiSetViewDistance,
	/*0x0094*/ aiSetGrenadeProbability,
	/*0x0095*/ aiSetChrNum,
	/*0x0096*/ aiSetMaxDamage,
	/*0x0097*/ aiAddHealth,
	/*0x0098*/ aiSetReactionSpeed,
	/*0x0099*/ aiSetRecoverySpeed,
	/*0x009a*/ aiSetAccuracy,
	/*0x009b*/ aiSetFlag,
	/*0x009c*/ aiUnsetFlag,
	/*0x009d*/ aiIfHasFlag,
	/*0x009e*/ aiChrSetFlag,
	/*0x009f*/ aiChrUnsetFlag,
	/*0x00a0*/ aiIfChrHasFlag,
	/*0x00a1*/ aiSetStageFlag,
	/*0x00a2*/ aiUnsetStageFlag,
	/*0x00a3*/ aiIfStageFlagEq,
	/*0x00a4*/ aiSetChrflag,
	/*0x00a5*/ aiUnsetChrflag,
	/*0x00a6*/ aiIfHasChrflag,
	/*0x00a7*/ aiChrSetChrflag,
	/*0x00a8*/ aiChrUnsetChrflag,
	/*0x00a9*/ aiIfChrHasChrflag,
	/*0x00aa*/ aiSetObjFlag,
	/*0x00ab*/ aiUnsetObjFlag,
	/*0x00ac*/ aiIfObjHasFlag,
	/*0x00ad*/ aiSetObjFlag2,
	/*0x00ae*/ aiUnsetObjFlag2,
	/*0x00af*/ aiIfObjHasFlag2,
	/*0x00b0*/ aiSetChrPreset,
	/*0x00b1*/ aiSetChrTarget,
	/*0x00b2*/ aiSetPadPreset,
	/*0x00b3*/ aiChrSetPadPreset,
	/*0x00b4*/ aiChrCopyPadPreset,
	/*0x00b5*/ aiPrint,
	/*0x00b6*/ aiRestartTimer,
	/*0x00b7*/ aiResetTimer,
	/*0x00b8*/ aiPauseTimer,
	/*0x00b9*/ aiResumeTimer,
	/*0x00ba*/ aiIfTimerStopped,
	/*0x00bb*/ aiIfTimerGreaterThanRandom,
	/*0x00bc*/ aiIfTimerLessThan,
	/*0x00bd*/ aiIfTimerGreaterThan,
	/*0x00be*/ aiShowCountdownTimer,
	/*0x00bf*/ aiHideCountdownTimer,
	/*0x00c0*/ aiSetCountdownTimerValue,
	/*0x00c1*/ aiStopCountdownTimer,
	/*0x00c2*/ aiStartCountdownTimer,
	/*0x00c3*/ aiIfCountdownTimerStopped,
	/*0x00c4*/ aiIfCountdownTimerLessThan,
	/*0x00c5*/ aiIfCountdownTimerGreaterThan,
	/*0x00c6*/ aiSpawnChrAtPad,
	/*0x00c7*/ aiSpawnChrAtChr,
	/*0x00c8*/ aiTryEquipWeapon,
	/*0x00c9*/ aiTryEquipHat,
	/*0x00ca*/ aiDuplicateChr,
	/*0x00cb*/ aiShowHudmsg,
	/*0x00cc*/ aiShowHudmsgTopMiddle,
	/*0x00cd*/ aiSpeak,
	/*0x00ce*/ aiPlaySound,
	/*0x00cf*/ ai00cf,
	/*0x00d0*/ ai00d0,
	/*0x00d1*/ ai00d1,
	/*0x00d2*/ ai00d2,
	/*0x00d3*/ aiAudioMuteChannel,
	/*0x00d4*/ ai00d4,
	/*0x00d5*/ aiHovercarBeginPath,
	/*0x00d6*/ aiSetVehicleSpeed,
	/*0x00d7*/ aiSetRotarySpeed,
	/*0x00d8*/ aiNoOp00d8,
	/*0x00d9*/ aiNoOp00d9,
	/*0x00da*/ aiSetObjImage,
	/*0x00db*/ aiNoOp00db,
	/*0x00dc*/ aiEndLevel,
	/*0x00dd*/ ai00dd,
	/*0x00de*/ aiWarpJoToPad,
	/*0x00df*/ ai00df,
	/*0x00e0*/ aiRevokeControl,
	/*0x00e1*/ aiGrantControl,
	/*0x00e2*/ aiChrMoveToPad,
	/*0x00e3*/ ai00e3,
	/*0x00e4*/ ai00e4,
	/*0x00e5*/ aiIfColourFadeComplete,
	/*0x00e6*/ NULL,
	/*0x00e7*/ NULL,
	/*0x00e8*/ aiSetDoorOpen,
	/*0x00e9*/ ai00e9,
	/*0x00ea*/ aiIfNumPlayersLessThan,
	/*0x00eb*/ aiIfChrAmmoQuantityLessThan,
	/*0x00ec*/ aiChrDrawWeapon,
	/*0x00ed*/ aiChrDrawWeaponInCutscene,
	/*0x00ee*/ ai00ee,
	/*0x00ef*/ aiIfObjInRoom,
	/*0x00f0*/ ai00f0,
	/*0x00f1*/ aiIfAttacking,
	/*0x00f2*/ ai00f2,
	/*0x00f3*/ aiChrSetInvincible,
	/*0x00f4*/ ai00f4,
	/*0x00f5*/ ai00f5,
	/*0x00f6*/ ai00f6,
	/*0x00f7*/ aiIfAllObjectivesComplete,
	/*0x00f8*/ aiIfPlayerIsInvincible,
	/*0x00f9*/ aiAudioPlayXMusic,
	/*0x00fa*/ aiAudioStopChannel,
	/*0x00fb*/ aiChrExplosions,
	/*0x00fc*/ aiIfKillCountGreaterThan,
	/*0x00fd*/ ai00fd,
	/*0x00fe*/ aiKillBond,
	/*0x00ff*/ aiBeSurprised00ff,
	/*0x0100*/ aiNoOp0100,
	/*0x0101*/ aiNoOp0101,
	/*0x0102*/ aiSetLights,
	/*0x0103*/ ai0103,
	/*0x0104*/ aiRemoveObjectAtPropPreset,
	/*0x0105*/ aiIfPropPresetHeightLessThan,
	/*0x0106*/ aiSetTarget,
	/*0x0107*/ aiIfPresetsTargetIsNotMyTarget,
	/*0x0108*/ aiIfChrTarget,
	/*0x0109*/ ai0109,
	/*0x010a*/ ai010a,
	/*0x010b*/ aiChrSetTeam,
	/*0x010c*/ aiIfCompareChrPresetsTeam,
	/*0x010d*/ aiNoOp010d,
	/*0x010e*/ aiSetShield,
	/*0x010f*/ aiIfChrShieldLessThan,
	/*0x0110*/ aiIfChrShieldGreaterThan,
	/*0x0111*/ aiSetCameraAnimation,
	/*0x0112*/ aiObjectDoAnimation,
	/*0x0113*/ aiIfInCutscene,
	/*0x0114*/ aiShowChr,
	/*0x0115*/ aiHideChr,
	/*0x0116*/ aiShowObj,
	/*0x0117*/ aiHideObj,
	/*0x0118*/ aiSetObjFlag3,
	/*0x0119*/ aiUnsetObjFlag3,
	/*0x011a*/ aiIfObjHasFlag3,
	/*0x011b*/ aiChrSetHiddenFlag,
	/*0x011c*/ aiChrUnsetHiddenFlag,
	/*0x011d*/ aiIfChrHasHiddenFlag,
	/*0x011e*/ aiIfHuman,
	/*0x011f*/ aiIfSkedar,
	/*0x0120*/ ai0120,
	/*0x0121*/ ai0121,
	/*0x0122*/ ai0122,
	/*0x0123*/ ai0123,
	/*0x0124*/ aiGoToCover,
	/*0x0125*/ ai0125,
	/*0x0126*/ aiIfPlayerUsingCmpOrAr34,
	/*0x0127*/ aiDetectEnemyOnSameFloor,
	/*0x0128*/ aiDetectEnemy,
	/*0x0129*/ aiIfSafetyLessThan,
	/*0x012a*/ aiIfTargetMovingSlowly,
	/*0x012b*/ aiIfTargetMovingCloser,
	/*0x012c*/ aiIfTargetMovingAway,
	/*0x012d*/ NULL,
	/*0x012e*/ NULL,
	/*0x012f*/ ai012f,
	/*0x0130*/ aiSayQuip,
	/*0x0131*/ aiIncreaseSquadronAlertness,
	/*0x0132*/ aiSetAction,
	/*0x0133*/ aiSetTeamOrders,
	/*0x0134*/ aiIfOrders,
	/*0x0135*/ aiIfHasOrders,
	/*0x0136*/ aiRetreat,
	/*0x0137*/ aiIfChrInSquadronDoingAction,
	/*0x0138*/ aiIfChannelIdle,
	/*0x0139*/ ai0139,
	/*0x013a*/ aiSetChrPresetToUnalertedTeammate,
	/*0x013b*/ aiSetSquadron,
	/*0x013c*/ ai013c,
	/*0x013d*/ aiIfDangerousObjectNearby,
	/*0x013e*/ ai013e,
	/*0x013f*/ aiIfHeliWeaponsArmed,
	/*0x0140*/ aiIfHoverbotNextStep,
	/*0x0141*/ aiShuffleInvestigationTerminals,
	/*0x0142*/ aiSetPadPresetToInvestigationTerminal,
	/*0x0143*/ aiHeliArmWeapons,
	/*0x0144*/ aiHeliUnarmWeapons,
	/*0x0145*/ aiRebuildTeams,
	/*0x0146*/ aiRebuildSquadrons,
	/*0x0147*/ aiIfSquadronIsDead,
	/*0x0148*/ aiChrSetListening,
	/*0x0149*/ aiIfChrListening,
	/*0x014a*/ aiIfTrue,
	/*0x014b*/ aiIfNotListening,
	/*0x014c*/ NULL,
	/*0x014d*/ NULL,
	/*0x014e*/ NULL,
	/*0x014f*/ NULL,
	/*0x0150*/ NULL,
	/*0x0151*/ NULL,
	/*0x0152*/ aiIfNumChrsInSquadronGreaterThan,
	/*0x0153*/ NULL,
	/*0x0154*/ NULL,
	/*0x0155*/ NULL,
	/*0x0156*/ NULL,
	/*0x0157*/ aiSetTintedGlassEnabled,
	/*0x0158*/ NULL,
	/*0x0159*/ NULL,
	/*0x015a*/ NULL,
	/*0x015b*/ aiAudioPlayMusic,
	/*0x015c*/ aiAudioRestartMusic,
	/*0x015d*/ NULL,
	/*0x015e*/ NULL,
	/*0x015f*/ NULL,
	/*0x0160*/ NULL,
	/*0x0161*/ NULL,
	/*0x0162*/ NULL,
	/*0x0163*/ NULL,
	/*0x0164*/ NULL,
	/*0x0165*/ aiIfChrInjured,
	/*0x0166*/ aiIfAction,
	/*0x0167*/ aiHovercopterFireRocket,
	/*0x0168*/ ai0168,
	/*0x0169*/ aiIfNaturalAnim,
	/*0x016a*/ aiIfY,
	/*0x016b*/ ai016b,
	/*0x016c*/ aiNoOp016c,
	/*0x016d*/ aiChrAdjustMotionBlur,
	/*0x016e*/ ai016e,
	/*0x016f*/ aiIfChrHasGun,
	/*0x0170*/ aiDoGunCommand,
	/*0x0171*/ aiIfDistanceToGunLessThan,
	/*0x0172*/ ai0172,
	/*0x0173*/ aiChrCopyProperties,
	/*0x0174*/ aiIfCutsceneButtonPressed,
	/*0x0175*/ ai0175,
	/*0x0176*/ ai0176,
	/*0x0177*/ aiPlayerAutoWalk,
	/*0x0178*/ aiIfPlayerAutoWalkFinished,
	/*0x0179*/ ai0179,
	/*0x017a*/ ai017a,
	/*0x017b*/ aiIfChrUnloaded,
	/*0x017c*/ aiAssignSound,
	/*0x017d*/ aiAudioSetMusicTrack,
	/*0x017e*/ aiAudioRestartDefaultMusic,
	/*0x017f*/ aiAudioSetSfxTrack,
	/*0x0180*/ aiAudioRestartSfx,
	/*0x0181*/ aiIfPlayerLookingAtObject,
	/*0x0182*/ aiPunchOrKick,
	/*0x0183*/ aiIfTargetIsPlayer,
	/*0x0184*/ ai0184,
	/*0x0185*/ aiMpInitSimulants,
	/*0x0186*/ aiIfSoundTimer,
	/*0x0187*/ aiSetTargetToEyespyIfInSight,
	/*0x0188*/ aiIfLiftStationary,
	/*0x0189*/ aiLiftGoToStop,
	/*0x018a*/ aiIfLiftAtStop,
	/*0x018b*/ aiConfigureRain,
	/*0x018c*/ aiChrToggleProp,
	/*0x018d*/ aiActivateLift,
	/*0x018e*/ aiMiniSkedarTryPounce,
	/*0x018f*/ aiIfObjectDistanceToPadLessThan,
	/*0x0190*/ aiSetSavefileFlag,
	/*0x0191*/ aiUnsetSavefileFlag,
	/*0x0192*/ aiIfSavefileFlagIsSet,
	/*0x0193*/ aiIfSavefileFlagIsUnset,
	/*0x0194*/ NULL,
	/*0x0195*/ NULL,
	/*0x0196*/ NULL,
	/*0x0197*/ NULL,
	/*0x0198*/ NULL,
	/*0x0199*/ NULL,
	/*0x019a*/ NULL,
	/*0x019b*/ NULL,
	/*0x019c*/ NULL,
	/*0x019d*/ NULL,
	/*0x019e*/ aiIfObjHealthLessThan,
	/*0x019f*/ aiSetObjHealth,
	/*0x01a0*/ aiSetChrSpecialDeathAnimation,
	/*0x01a1*/ aiSetRoomToSearch,
	/*0x01a2*/ aiSayCiStaffQuip,
	/*0x01a3*/ aiDoPresetAnimation,
	/*0x01a4*/ aiShowHudmsgMiddle,
	/*0x01a5*/ ai01a5,
	/*0x01a6*/ aiIfTargetYDifferenceLessThan,
	/*0x01a7*/ aiIfChrPropsoundcountZero,
	/*0x01a8*/ NULL,
	/*0x01a9*/ NULL,
	/*0x01aa*/ ai01aa,
	/*0x01ab*/ aiIfNumKnockedOutChrs,
	/*0x01ac*/ NULL,
	/*0x01ad*/ aiReleaseObject,
	/*0x01ae*/ aiClearInventory,
	/*0x01af*/ aiChrGrabObject,
	/*0x01b0*/ NULL,
	/*0x01b1*/ aiShuffleRuinsPillars,
	/*0x01b2*/ ai01b2,
	/*0x01b3*/ aiToggleP1P2,
	/*0x01b4*/ ai01b4,
	/*0x01b5*/ aiChrSetP1P2,
	/*0x01b6*/ aiConfigureSnow,
	/*0x01b7*/ aiChrSetCloaked,
	/*0x01b8*/ aiSetAutogunType,
	/*0x01b9*/ aiShufflePelagicSwitches,
	/*0x01ba*/ ai01ba,
	/*0x01bb*/ aiNoOp01bb,
	/*0x01bc*/ ai01bc,
	/*0x01bd*/ aiIfTrainingPcHolographed,
	/*0x01be*/ aiIfChrWeaponEquipped,
	/*0x01bf*/ aiChrBeginOrEndTeleport,
	/*0x01c0*/ aiIfChrTeleportFullWhite,
	/*0x01c1*/ aiSetPunchDodgeList,
	/*0x01c2*/ aiSetShootingAtMeList,
	/*0x01c3*/ aiSetDarkRoomList,
	/*0x01c4*/ aiSetPlayerDeadList,
	/*0x01c5*/ ai01c5,
	/*0x01c6*/ aiSetDodgeRating,
	/*0x01c7*/ aiSetUnarmedDodgeRating,
	/*0x01c8*/ ai01c8,
	/*0x01c9*/ ai01c9,
	/*0x01ca*/ aiChrSetCutsceneWeapon,
	/*0x01cb*/ aiFadeScreen,
	/*0x01cc*/ aiIfFadeComplete,
	/*0x01cd*/ aiSetChrHudpieceVisible,
	/*0x01ce*/ aiSetPassiveMode,
	/*0x01cf*/ aiChrSetFiringInCutscene,
	/*0x01d0*/ aiSetPortalFlag,
	/*0x01d1*/ aiSetObjPartVisible,
	/*0x01d2*/ aiChrEmitSparks,
	/*0x01d3*/ aiSetDrCarollImages,
	/*0x01d4*/ ai01d4,
	/*0x01d5*/ aiShowCutsceneChrs,
	/*0x01d6*/ aiMiscellaneous,
	/*0x01d7*/ aiIfDistanceToTarget2LessThan,
	/*0x01d8*/ aiIfDistanceToTarget2GreaterThan,
	/*0x01d9*/ aiPlaySoundFromProp,
	/*0x01da*/ aiPlayMusicContinuously,
	/*0x01db*/ aiChrKill,
	/*0x01dc*/ aiRemoveWeaponFromInventory,
	/*0x01dd*/ ai01dd,
	/*0x01de*/ aiIfCoopMode,
	/*0x01df*/ aiIfChrSameFloorDistanceToPadLessThan,
	/*0x01e0*/ aiRemoveReferencesToChr,
};

// ec34
u16 g_CommandLengths[] = {
	/*0x0000*/ 0x0003, /*0x0001*/ 0x0003, /*0x0002*/ 0x0003, /*0x0003*/ 0x0002,
	/*0x0004*/ 0x0002, /*0x0005*/ 0x0005, /*0x0006*/ 0x0005, /*0x0007*/ 0x0004,
	/*0x0008*/ 0x0002, /*0x0009*/ 0x0002, /*0x000a*/ 0x0002, /*0x000b*/ 0x000c,
	/*0x000c*/ 0x0003, /*0x000d*/ 0x0002, /*0x000e*/ 0x0002, /*0x000f*/ 0x0003,
	/*0x0010*/ 0x0003, /*0x0011*/ 0x0003, /*0x0012*/ 0x0003, /*0x0013*/ 0x0003,
	/*0x0014*/ 0x0003, /*0x0015*/ 0x0007, /*0x0016*/ 0x0007, /*0x0017*/ 0x0007,
	/*0x0018*/ 0x0007, /*0x0019*/ 0x0008, /*0x001a*/ 0x0005, /*0x001b*/ 0x0007,
	/*0x001c*/ 0x0006, /*0x001d*/ 0x0004, /*0x001e*/ 0x0003, /*0x001f*/ 0x0004,
	/*0x0020*/ 0x0004, /*0x0021*/ 0x0003, /*0x0022*/ 0x0002, /*0x0023*/ 0x0003,
	/*0x0024*/ 0x0002, /*0x0025*/ 0x0002, /*0x0026*/ 0x0003, /*0x0027*/ 0x0005,
	/*0x0028*/ 0x0002, /*0x0029*/ 0x0002, /*0x002a*/ 0x0003, /*0x002b*/ 0x0003,
	/*0x002c*/ 0x0003, /*0x002d*/ 0x0003, /*0x002e*/ 0x0003, /*0x002f*/ 0x0004,
	/*0x0030*/ 0x0004, /*0x0031*/ 0x0004, /*0x0032*/ 0x0003, /*0x0033*/ 0x0004,
	/*0x0034*/ 0x0004, /*0x0035*/ 0x0003, /*0x0036*/ 0x0002, /*0x0037*/ 0x0004,
	/*0x0038*/ 0x0004, /*0x0039*/ 0x0003, /*0x003a*/ 0x0003, /*0x003b*/ 0x0003,
	/*0x003c*/ 0x0003, /*0x003d*/ 0x0004, /*0x003e*/ 0x0004, /*0x003f*/ 0x0003,
	/*0x0040*/ 0x0007, /*0x0041*/ 0x0007, /*0x0042*/ 0x0003, /*0x0043*/ 0x0003,
	/*0x0044*/ 0x0003, /*0x0045*/ 0x0004, /*0x0046*/ 0x0003, /*0x0047*/ 0x0003,
	/*0x0048*/ 0x0004, /*0x0049*/ 0x0005, /*0x004a*/ 0x0003, /*0x004b*/ 0x0003,
	/*0x004c*/ 0x0003, /*0x004d*/ 0x0004, /*0x004e*/ 0x0006, /*0x004f*/ 0x0004,
	/*0x0050*/ 0x0004, /*0x0051*/ 0x0004, /*0x0052*/ 0x0005, /*0x0053*/ 0x0005,
	/*0x0054*/ 0x0008, /*0x0055*/ 0x0008, /*0x0056*/ 0x0006, /*0x0057*/ 0x0006,
	/*0x0058*/ 0x0005, /*0x0059*/ 0x0007, /*0x005a*/ 0x0007, /*0x005b*/ 0x0007,
	/*0x005c*/ 0x0005, /*0x005d*/ 0x0005, /*0x005e*/ 0x0004, /*0x005f*/ 0x0005,
	/*0x0060*/ 0x0005, /*0x0061*/ 0x0005, /*0x0062*/ 0x0004, /*0x0063*/ 0x0005,
	/*0x0064*/ 0x0001, /*0x0065*/ 0x0003, /*0x0066*/ 0x0003, /*0x0067*/ 0x0003,
	/*0x0068*/ 0x0003, /*0x0069*/ 0x0003, /*0x006a*/ 0x0004, /*0x006b*/ 0x0005,
	/*0x006c*/ 0x0003, /*0x006d*/ 0x0003, /*0x006e*/ 0x0005, /*0x006f*/ 0x0004,
	/*0x0070*/ 0x0004, /*0x0071*/ 0x0004, /*0x0072*/ 0x0005, /*0x0073*/ 0x0004,
	/*0x0074*/ 0x0004, /*0x0075*/ 0x0004, /*0x0076*/ 0x0004, /*0x0077*/ 0x0004,
	/*0x0078*/ 0x0004, /*0x0079*/ 0x0005, /*0x007a*/ 0x0005, /*0x007b*/ 0x0004,
	/*0x007c*/ 0x0004, /*0x007d*/ 0x0004, /*0x007e*/ 0x0004, /*0x007f*/ 0x0004,
	/*0x0080*/ 0x0004, /*0x0081*/ 0x0005, /*0x0082*/ 0x0005, /*0x0083*/ 0x0004,
	/*0x0084*/ 0x0003, /*0x0085*/ 0x0003, /*0x0086*/ 0x0004, /*0x0087*/ 0x0003,
	/*0x0088*/ 0x0004, /*0x0089*/ 0x0003, /*0x008a*/ 0x0003, /*0x008b*/ 0x0003,
	/*0x008c*/ 0x0004, /*0x008d*/ 0x0003, /*0x008e*/ 0x0005, /*0x008f*/ 0x0005,
	/*0x0090*/ 0x0003, /*0x0091*/ 0x0002, /*0x0092*/ 0x0004, /*0x0093*/ 0x0003,
	/*0x0094*/ 0x0003, /*0x0095*/ 0x0003, /*0x0096*/ 0x0005, /*0x0097*/ 0x0004,
	/*0x0098*/ 0x0003, /*0x0099*/ 0x0003, /*0x009a*/ 0x0003, /*0x009b*/ 0x0007,
	/*0x009c*/ 0x0007, /*0x009d*/ 0x0009, /*0x009e*/ 0x0008, /*0x009f*/ 0x0008,
	/*0x00a0*/ 0x0009, /*0x00a1*/ 0x0006, /*0x00a2*/ 0x0006, /*0x00a3*/ 0x0008,
	/*0x00a4*/ 0x0006, /*0x00a5*/ 0x0006, /*0x00a6*/ 0x0007, /*0x00a7*/ 0x0007,
	/*0x00a8*/ 0x0007, /*0x00a9*/ 0x0008, /*0x00aa*/ 0x0007, /*0x00ab*/ 0x0007,
	/*0x00ac*/ 0x0008, /*0x00ad*/ 0x0007, /*0x00ae*/ 0x0007, /*0x00af*/ 0x0008,
	/*0x00b0*/ 0x0003, /*0x00b1*/ 0x0004, /*0x00b2*/ 0x0004, /*0x00b3*/ 0x0005,
	/*0x00b4*/ 0x0004, /*0x00b5*/ 0x0000, /*0x00b6*/ 0x0002, /*0x00b7*/ 0x0002,
	/*0x00b8*/ 0x0002, /*0x00b9*/ 0x0002, /*0x00ba*/ 0x0003, /*0x00bb*/ 0x0003,
	/*0x00bc*/ 0x0006, /*0x00bd*/ 0x0006, /*0x00be*/ 0x0002, /*0x00bf*/ 0x0002,
	/*0x00c0*/ 0x0004, /*0x00c1*/ 0x0002, /*0x00c2*/ 0x0002, /*0x00c3*/ 0x0003,
	/*0x00c4*/ 0x0005, /*0x00c5*/ 0x0005, /*0x00c6*/ 0x000d, /*0x00c7*/ 0x000c,
	/*0x00c8*/ 0x000a, /*0x00c9*/ 0x0009, /*0x00ca*/ 0x000a, /*0x00cb*/ 0x0005,
	/*0x00cc*/ 0x0006, /*0x00cd*/ 0x0009, /*0x00ce*/ 0x0005, /*0x00cf*/ 0x0006,
	/*0x00d0*/ 0x0007, /*0x00d1*/ 0x0007, /*0x00d2*/ 0x0007, /*0x00d3*/ 0x0003,
	/*0x00d4*/ 0x0006, /*0x00d5*/ 0x0003, /*0x00d6*/ 0x0006, /*0x00d7*/ 0x0006,
	/*0x00d8*/ 0x0003, /*0x00d9*/ 0x0003, /*0x00da*/ 0x0005, /*0x00db*/ 0x0003,
	/*0x00dc*/ 0x0002, /*0x00dd*/ 0x0002, /*0x00de*/ 0x0004, /*0x00df*/ 0x0007,
	/*0x00e0*/ 0x0004, /*0x00e1*/ 0x0003, /*0x00e2*/ 0x0007, /*0x00e3*/ 0x0003,
	/*0x00e4*/ 0x0003, /*0x00e5*/ 0x0004, /*0x00e6*/ 0x0001, /*0x00e7*/ 0x0001,
	/*0x00e8*/ 0x0003, /*0x00e9*/ 0x0004, /*0x00ea*/ 0x0004, /*0x00eb*/ 0x0006,
	/*0x00ec*/ 0x0004, /*0x00ed*/ 0x0004, /*0x00ee*/ 0x0005, /*0x00ef*/ 0x0006,
	/*0x00f0*/ 0x0003, /*0x00f1*/ 0x0003, /*0x00f2*/ 0x0002, /*0x00f3*/ 0x0003,
	/*0x00f4*/ 0x000e, /*0x00f5*/ 0x0002, /*0x00f6*/ 0x0003, /*0x00f7*/ 0x0003,
	/*0x00f8*/ 0x0004, /*0x00f9*/ 0x0005, /*0x00fa*/ 0x0003, /*0x00fb*/ 0x0003,
	/*0x00fc*/ 0x0004, /*0x00fd*/ 0x0004, /*0x00fe*/ 0x0002, /*0x00ff*/ 0x0002,
	/*0x0100*/ 0x0003, /*0x0101*/ 0x0003, /*0x0102*/ 0x000b, /*0x0103*/ 0x0003,
	/*0x0104*/ 0x0002, /*0x0105*/ 0x0005, /*0x0106*/ 0x0005, /*0x0107*/ 0x0003,
	/*0x0108*/ 0x0006, /*0x0109*/ 0x0006, /*0x010a*/ 0x0008, /*0x010b*/ 0x0004,
	/*0x010c*/ 0x0004, /*0x010d*/ 0x0002, /*0x010e*/ 0x0004, /*0x010f*/ 0x0006,
	/*0x0110*/ 0x0006, /*0x0111*/ 0x0004, /*0x0112*/ 0x0008, /*0x0113*/ 0x0003,
	/*0x0114*/ 0x0003, /*0x0115*/ 0x0003, /*0x0116*/ 0x0003, /*0x0117*/ 0x0003,
	/*0x0118*/ 0x0007, /*0x0119*/ 0x0007, /*0x011a*/ 0x0008, /*0x011b*/ 0x0007,
	/*0x011c*/ 0x0007, /*0x011d*/ 0x0008, /*0x011e*/ 0x0004, /*0x011f*/ 0x0004,
	/*0x0120*/ 0x0004, /*0x0121*/ 0x0005, /*0x0122*/ 0x0009, /*0x0123*/ 0x0009,
	/*0x0124*/ 0x0003, /*0x0125*/ 0x0003, /*0x0126*/ 0x0003, /*0x0127*/ 0x0003,
	/*0x0128*/ 0x0004, /*0x0129*/ 0x0004, /*0x012a*/ 0x0004, /*0x012b*/ 0x0003,
	/*0x012c*/ 0x0003, /*0x012d*/ 0x0001, /*0x012e*/ 0x0001, /*0x012f*/ 0x0002,
	/*0x0130*/ 0x000a, /*0x0131*/ 0x0003, /*0x0132*/ 0x0004, /*0x0133*/ 0x0004,
	/*0x0134*/ 0x0005, /*0x0135*/ 0x0003, /*0x0136*/ 0x0004, /*0x0137*/ 0x0004,
	/*0x0138*/ 0x0004, /*0x0139*/ 0x0008, /*0x013a*/ 0x0005, /*0x013b*/ 0x0003,
	/*0x013c*/ 0x0003, /*0x013d*/ 0x0004, /*0x013e*/ 0x0002, /*0x013f*/ 0x0003,
	/*0x0140*/ 0x0005, /*0x0141*/ 0x0009, /*0x0142*/ 0x0004, /*0x0143*/ 0x0002,
	/*0x0144*/ 0x0002, /*0x0145*/ 0x0002, /*0x0146*/ 0x0002, /*0x0147*/ 0x0004,
	/*0x0148*/ 0x0004, /*0x0149*/ 0x0006, /*0x014a*/ 0x0006, /*0x014b*/ 0x0003,
	/*0x014c*/ 0x0001, /*0x014d*/ 0x0001, /*0x014e*/ 0x0001, /*0x014f*/ 0x0001,
	/*0x0150*/ 0x0001, /*0x0151*/ 0x0001, /*0x0152*/ 0x0005, /*0x0153*/ 0x0001,
	/*0x0154*/ 0x0001, /*0x0155*/ 0x0001, /*0x0156*/ 0x0001, /*0x0157*/ 0x0003,
	/*0x0158*/ 0x0001, /*0x0159*/ 0x0001, /*0x015a*/ 0x0001, /*0x015b*/ 0x0003,
	/*0x015c*/ 0x0002, /*0x015d*/ 0x0001, /*0x015e*/ 0x0001, /*0x015f*/ 0x0001,
	/*0x0160*/ 0x0001, /*0x0161*/ 0x0001, /*0x0162*/ 0x0001, /*0x0163*/ 0x0001,
	/*0x0164*/ 0x0001, /*0x0165*/ 0x0004, /*0x0166*/ 0x0004, /*0x0167*/ 0x0003,
	/*0x0168*/ 0x0004, /*0x0169*/ 0x0004, /*0x016a*/ 0x0007, /*0x016b*/ 0x000a,
	/*0x016c*/ 0x0002, /*0x016d*/ 0x0005, /*0x016e*/ 0x0005, /*0x016f*/ 0x0005,
	/*0x0170*/ 0x0004, /*0x0171*/ 0x0005, /*0x0172*/ 0x0004, /*0x0173*/ 0x0004,
	/*0x0174*/ 0x0003, /*0x0175*/ 0x0003, /*0x0176*/ 0x0003, /*0x0177*/ 0x0009,
	/*0x0178*/ 0x0004, /*0x0179*/ 0x000b, /*0x017a*/ 0x0003, /*0x017b*/ 0x0004,
	/*0x017c*/ 0x0005, /*0x017d*/ 0x0003, /*0x017e*/ 0x0002, /*0x017f*/ 0x0003,
	/*0x0180*/ 0x0002, /*0x0181*/ 0x0005, /*0x0182*/ 0x0004, /*0x0183*/ 0x0003,
	/*0x0184*/ 0x0004, /*0x0185*/ 0x0002, /*0x0186*/ 0x0006, /*0x0187*/ 0x0003,
	/*0x0188*/ 0x0004, /*0x0189*/ 0x0004, /*0x018a*/ 0x0005, /*0x018b*/ 0x0003,
	/*0x018c*/ 0x0004, /*0x018d*/ 0x0004, /*0x018e*/ 0x0007, /*0x018f*/ 0x0008,
	/*0x0190*/ 0x0003, /*0x0191*/ 0x0003, /*0x0192*/ 0x0004, /*0x0193*/ 0x0004,
	/*0x0194*/ 0x0001, /*0x0195*/ 0x0001, /*0x0196*/ 0x0001, /*0x0197*/ 0x0001,
	/*0x0198*/ 0x0001, /*0x0199*/ 0x0001, /*0x019a*/ 0x0001, /*0x019b*/ 0x0001,
	/*0x019c*/ 0x0001, /*0x019d*/ 0x0001, /*0x019e*/ 0x0006, /*0x019f*/ 0x0005,
	/*0x01a0*/ 0x0004, /*0x01a1*/ 0x0002, /*0x01a2*/ 0x0004, /*0x01a3*/ 0x0003,
	/*0x01a4*/ 0x0006, /*0x01a5*/ 0x0003, /*0x01a6*/ 0x0004, /*0x01a7*/ 0x0004,
	/*0x01a8*/ 0x0001, /*0x01a9*/ 0x0001, /*0x01aa*/ 0x0003, /*0x01ab*/ 0x0005,
	/*0x01ac*/ 0x0001, /*0x01ad*/ 0x0003, /*0x01ae*/ 0x0003, /*0x01af*/ 0x0004,
	/*0x01b0*/ 0x0001, /*0x01b1*/ 0x0012, /*0x01b2*/ 0x0003, /*0x01b3*/ 0x0003,
	/*0x01b4*/ 0x0003, /*0x01b5*/ 0x0004, /*0x01b6*/ 0x0003, /*0x01b7*/ 0x0005,
	/*0x01b8*/ 0x0004, /*0x01b9*/ 0x0002, /*0x01ba*/ 0x0007, /*0x01bb*/ 0x0004,
	/*0x01bc*/ 0x0004, /*0x01bd*/ 0x0003, /*0x01be*/ 0x0005, /*0x01bf*/ 0x0005,
	/*0x01c0*/ 0x0004, /*0x01c1*/ 0x0004, /*0x01c2*/ 0x0004, /*0x01c3*/ 0x0004,
	/*0x01c4*/ 0x0004, /*0x01c5*/ 0x0002, /*0x01c6*/ 0x0004, /*0x01c7*/ 0x0003,
	/*0x01c8*/ 0x0003, /*0x01c9*/ 0x0003, /*0x01ca*/ 0x0005, /*0x01cb*/ 0x0008,
	/*0x01cc*/ 0x0003, /*0x01cd*/ 0x0004, /*0x01ce*/ 0x0003, /*0x01cf*/ 0x0004,
	/*0x01d0*/ 0x0005, /*0x01d1*/ 0x0005, /*0x01d2*/ 0x0003, /*0x01d3*/ 0x0005,
	/*0x01d4*/ 0x0006, /*0x01d5*/ 0x0003, /*0x01d6*/ 0x0006, /*0x01d7*/ 0x0005,
	/*0x01d8*/ 0x0005, /*0x01d9*/ 0x000b, /*0x01da*/ 0x0003, /*0x01db*/ 0x0003,
	/*0x01dc*/ 0x0003, /*0x01dd*/ 0x0004, /*0x01de*/ 0x0003, /*0x01df*/ 0x0008,
	/*0x01e0*/ 0x0002,
};

u32 var80068fd8 = 0x00000000;
u32 var80068fdc = 0x00000000;
struct coord var80068fe0 = {0, 0, 0};
struct coord var80068fec = {0, 0, 0};

s16 g_GuardQuipBank[][4] = {
	// Voicebox 0
	{  0, 0x027b, 0x027b, 0x027c },
	{  1, 0x027d, 0x027e, 0x027f },
	{  2, 0x028a, 0x028b, 0x028c },
	{  3, 0x035b, 0x035c, 0x035d },
	{  4, 0x0290, 0x80fb, 0x0292 },
	{  5, 0x0293, 0x0294, 0x029d },
	{  6, 0x0297, 0x0298, 0x0299 },
	{  7, 0x029a, 0x029b, 0x029c },
	{  8, 0x02a7, 0x02a8, 0x02a9 },
	{  9, 0x026b, 0x026c, 0x026d },
	{ 10, 0x0037, 0x0037, 0x0037 },
	{ 11, 0x0264, 0x0265, 0x0266 },
	{ 12, 0x80f7, 0x80f7, 0x80f8 },
	{ 13, 0x025e, 0x025f, 0x0260 },
	{ 14, 0x0261, 0x0262, 0x0263 },
	{ 15, 0x02a3, 0x02a4, 0x02a5 },
	{ 16, 0x0272, 0x0273, 0x0274 },
	{ 34, 0x0037, 0x0037, 0x0037 },
	{ 18, 0x025b, 0x025c, 0x025c },
	{ 19, 0x026e, 0x026f, 0x0270 },
	{ 20, 0x0037, 0x0037, 0x0037 },
	{ 21, 0x0280, 0x0281, 0x0282 },
	{ 22, 0x80f9, 0x80f9, 0x0287 },
	{ 23, 0x80fa, 0x80fa, 0x0289 },
	{ 24, 0x028d, 0x028e, 0x028f },
	{ 25, 0x80fc, 0x80fd, 0x02a2 },
	{ 26, 0x0037, 0x0037, 0x0037 },
	{ 27, 0x0275, 0x0277, 0x0278 },
	{ 28, 0x8167, 0x04c9, 0x04ca },
	{ 29, 0x815d, 0x815e, 0x815f },
	{ 30, 0x1aa0, 0x1aa1, 0x1aa2 },
	{ 31, 0x0037, 0x1aa3, 0x1aa4 },
	{ 32, 0x1aa5, 0x1aa5, 0x1aa6 },
	{ 33, 0x04c6, 0x04c6, 0x04c6 },
	{ 34, 0x04c7, 0x04c7, 0x04c7 },
	{ 35, 0x04cb, 0x04cb, 0x04cc },
	{ 36, 0x027b, 0x027b, 0x027d },
	{ 37, 0x027b, 0x027d, 0x027d },
	{ 38, 0x02a3, 0x02a4, 0x02a5 },
	{ 39, 0x04c6, 0x04c6, 0x04c6 },
	{ 40, 0x1aa6, 0x1aa6, 0x1aa6 },
	// Voicebox 1
	{  0, 0x0322, 0x0323, 0x0324 },
	{  1, 0x0325, 0x0326, 0x0327 },
	{  2, 0x812e, 0x0335, 0x0336 },
	{  3, 0x035b, 0x035c, 0x035d },
	{  4, 0x033a, 0x033b, 0x033c },
	{  5, 0x033d, 0x033f, 0x0342 },
	{  6, 0x0343, 0x0344, 0x0345 },
	{  7, 0x0346, 0x0347, 0x0348 },
	{  8, 0x0349, 0x034a, 0x034b },
	{  9, 0x030e, 0x030f, 0x0310 },
	{ 10, 0x0037, 0x0037, 0x0037 },
	{ 11, 0x0306, 0x0307, 0x0308 },
	{ 12, 0x0309, 0x8128, 0x030b },
	{ 13, 0x8126, 0x0301, 0x0302 },
	{ 14, 0x8127, 0x0304, 0x0305 },
	{ 15, 0x0037, 0x0037, 0x0037 },
	{ 16, 0x031c, 0x031d, 0x031e },
	{ 34, 0x0037, 0x0037, 0x0037 },
	{ 18, 0x8124, 0x8125, 0x02ff },
	{ 19, 0x8129, 0x812a, 0x0316 },
	{ 20, 0x031c, 0x031d, 0x031e },
	{ 21, 0x0356, 0x0329, 0x0329 },
	{ 22, 0x812b, 0x032f, 0x812c },
	{ 23, 0x0331, 0x0332, 0x812d },
	{ 24, 0x0337, 0x0338, 0x0339 },
	{ 25, 0x812f, 0x034d, 0x034e },
	{ 26, 0x0355, 0x0356, 0x0357 },
	{ 27, 0x031f, 0x0320, 0x0321 },
	{ 28, 0x04cf, 0x04d0, 0x04d1 },
	{ 29, 0x8163, 0x8163, 0x8164 },
	{ 30, 0x1ace, 0x1ace, 0x1acf },
	{ 31, 0x1ad0, 0x1ad0, 0x1ad1 },
	{ 32, 0x1ad2, 0x1ad2, 0x1ad3 },
	{ 33, 0x8168, 0x8168, 0x8168 },
	{ 34, 0x04ce, 0x04ce, 0x04ce },
	{ 35, 0x04d2, 0x04d3, 0x04d3 },
	{ 36, 0x0322, 0x0323, 0x0324 },
	{ 37, 0x0324, 0x0327, 0x0327 },
	{ 38, 0x0356, 0x0357, 0x035a },
	{ 39, 0x812b, 0x032f, 0x812c },
	{ 40, 0x1ad2, 0x1ad2, 0x1ad2 },
	// Voicebox 2
	{  0, 0x03e7, 0x03e8, 0x03e9 },
	{  1, 0x03ea, 0x03eb, 0x03ec },
	{  2, 0x03f9, 0x03fa, 0x03fb },
	{  3, 0x0420, 0x0421, 0x813d },
	{  4, 0x03ff, 0x8139, 0x0401 },
	{  5, 0x0403, 0x0405, 0x0407 },
	{  6, 0x0408, 0x0409, 0x040a },
	{  7, 0x040b, 0x040c, 0x040d },
	{  8, 0x040e, 0x040f, 0x0410 },
	{  9, 0x03d6, 0x03d6, 0x03d7 },
	{ 10, 0x0037, 0x0037, 0x0037 },
	{ 11, 0x03d0, 0x03d1, 0x8134 },
	{ 12, 0x03d3, 0x8135, 0x03d5 },
	{ 13, 0x8132, 0x03c8, 0x03c8 },
	{ 14, 0x03cd, 0x03ce, 0x8133 },
	{ 15, 0x0037, 0x0037, 0x0037 },
	{ 16, 0x03e1, 0x03e2, 0x03e3 },
	{ 34, 0x0037, 0x0037, 0x0037 },
	{ 18, 0x03c4, 0x03c5, 0x03c6 },
	{ 19, 0x03d9, 0x03da, 0x03db },
	{ 20, 0x031c, 0x031d, 0x031e },
	{ 21, 0x03ed, 0x03ee, 0x03ef },
	{ 22, 0x8136, 0x03f4, 0x8137 },
	{ 23, 0x8138, 0x03f7, 0x03f8 },
	{ 24, 0x03fc, 0x03fd, 0x03fe },
	{ 25, 0x813a, 0x813c, 0x0415 },
	{ 26, 0x041b, 0x041c, 0x041d },
	{ 27, 0x03e4, 0x03e5, 0x03e6 },
	{ 28, 0x04d5, 0x04d6, 0x04d7 },
	{ 29, 0x8165, 0x8165, 0x8166 },
	{ 30, 0x1ad6, 0x1ad6, 0x1ad7 },
	{ 31, 0x1ad8, 0x1ad8, 0x1ad9 },
	{ 32, 0x1ada, 0x1ada, 0x1adb },
	{ 33, 0x8168, 0x8168, 0x8168 },
	{ 34, 0x04d4, 0x04d4, 0x04d4 },
	{ 35, 0x04d8, 0x04d8, 0x04d9 },
	{ 36, 0x03e7, 0x03e8, 0x03e9 },
	{ 37, 0x03e8, 0x03eb, 0x03eb },
	{ 38, 0x041b, 0x0417, 0x041d },
	{ 39, 0x8134, 0x03f4, 0x8134 },
	{ 40, 0x1adb, 0x1adb, 0x1adb },
	// Voicebox 3
	{  0, 0x0396, 0x0396, 0x0396 },
	{  1, 0x0037, 0x0398, 0x0399 },
	{  2, 0x03a4, 0x0037, 0x03a6 },
	{  3, 0x03c1, 0x03c2, 0x03c2 },
	{  4, 0x03aa, 0x03ab, 0x03ac },
	{  5, 0x03ad, 0x03ae, 0x0037 },
	{  6, 0x03b0, 0x03b0, 0x03b1 },
	{  7, 0x0037, 0x03b3, 0x03b4 },
	{  8, 0x03b5, 0x03b5, 0x03b6 },
	{  9, 0x0037, 0x0389, 0x038a },
	{ 10, 0x0000, 0x0000, 0x0000 },
	{ 11, 0x0381, 0x0382, 0x0037 },
	{ 12, 0x0385, 0x0037, 0x0387 },
	{ 13, 0x0037, 0x037e, 0x037f },
	{ 14, 0x037e, 0x037f, 0x0380 },
	{ 15, 0x0000, 0x0000, 0x0000 },
	{ 16, 0x0384, 0x0385, 0x0037 },
	{ 34, 0x03aa, 0x03ab, 0x03ac },
	{ 18, 0x0037, 0x037b, 0x037c },
	{ 19, 0x038d, 0x038d, 0x038d },
	{ 20, 0x0384, 0x0385, 0x0387 },
	{ 21, 0x039a, 0x039b, 0x0037 },
	{ 22, 0x039f, 0x0037, 0x03a1 },
	{ 23, 0x03a1, 0x03a2, 0x8130 },
	{ 24, 0x03a7, 0x0037, 0x03a9 },
	{ 25, 0x03b7, 0x03b8, 0x8131 },
	{ 26, 0x03be, 0x0037, 0x03c0 },
	{ 27, 0x0381, 0x0382, 0x0037 },
	{ 28, 0x0000, 0x0000, 0x0000 },
	{ 29, 0x0037, 0x0396, 0x0037 },
	{ 30, 0x0037, 0x0396, 0x0037 },
	{ 31, 0x0037, 0x0396, 0x0037 },
	{ 32, 0x0037, 0x0396, 0x0037 },
	{ 33, 0x037b, 0x037c, 0x037b },
	{ 34, 0x03aa, 0x03b1, 0x03ab },
	{ 35, 0x0000, 0x0000, 0x0000 },
	{ 36, 0x0396, 0x0396, 0x0399 },
	{ 37, 0x0399, 0x0399, 0x0396 },
	{ 38, 0x03bc, 0x03be, 0x03c0 },
	{ 39, 0x039f, 0x039f, 0x039f },
	{ 40, 0x0000, 0x0000, 0x0000 },
};

s16 g_SpecialQuipBank[][4] = {
	{  0, 0x0af2, 0x0af3, 0x0af8 },
	{  1, 0x1aee, 0x1aef, 0x1aee },
	{  2, 0x023d, 0x023e, 0x0247 },
	{  3, 0x0248, 0x0249, 0x024b },
	{  4, 0x0246, 0x023f, 0x0240 },
	{  5, 0x024c, 0x0252, 0x0251 },
	{  6, 0x024f, 0x0258, 0x024d },
	{  7, 0x0243, 0x0244, 0x0245 },
	{  8, 0x1294, 0x1295, 0x1296 },
	{  9, 0x1297, 0x1298, 0x1297 },
	{ 10, 0x1290, 0x127e, 0x8103 },
	{ 11, 0x7324, 0x7325, 0x7326 },
	{ 12, 0x128e, 0x1280, 0x1287 },
	{ 13, 0x128d, 0x1283, 0x1286 },
	{ 14, 0x1291, 0x1284, 0x128a },
	{ 15, 0x1292, 0x1281, 0x1288 },
	{ 16, 0x128b, 0x1282, 0x1289 },
	{ 17, 0x000d, 0x000d, 0x000d },
	{ 18, 0x815d, 0x815e, 0x815f },
	{ 19, 0x1aa0, 0x1aa1, 0x1aa2 },
	{ 20, 0x0037, 0x1aa3, 0x1aa4 },
	{ 21, 0x1aa5, 0x1aa5, 0x1aa6 },
	{ 22, 0x0446, 0x0461, 0x0465 },
	{ 23, 0x0447, 0x045d, 0x0466 },
	{ 24, 0x814a, 0x045e, 0x0463 },
	{ 25, 0x0444, 0x045f, 0x0468 },
	{ 26, 0x0448, 0x0449, 0x0449 },
	{ 27, 0x044b, 0x0459, 0x045a },
	{ 28, 0x05be, 0x0515, 0x05bf },
	{ 29, 0x044b, 0x0459, 0x045a },
	{ 30, 0x044b, 0x0459, 0x045a },
	{ 31, 0x1aeb, 0x1aeb, 0x1aeb },
	{ 32, 0x1b35, 0x1b36, 0x1b37 },
	{ 33, 0x1ac0, 0x1ac1, 0x1ac3 },
	{ 34, 0x0446, 0x0461, 0x0000 },
	{ 35, 0x0447, 0x045d, 0x0000 },
	{ 36, 0x814a, 0x045e, 0x1aee },
	{ 37, 0x0444, 0x045f, 0x0000 },
	{ 38, 0x051b, 0x051c, 0x051d },
	{ 39, 0x051e, 0x051f, 0x0520 },
	{ 40, 0x0521, 0x0522, 0x0525 },
	{ 41, 0x0523, 0x0523, 0x0524 },
	{ 42, 0x1adb, 0x1aa6, 0x1ad2 },
	{ 43, 0x0af2, 0x0af8, 0x0af8 },
	{ 44, 0x0525, 0x0525, 0x0525 },
	{ 45, 0x1aec, 0x1aec, 0x1aec },
};

s16 g_QuipTexts[][4] = {
	{  1, L_AME(83), L_AME(84), L_AME(85) }, // "How dare you disturb me!", "You will regret this intrusion, girl!", "If I were you, I'd leave...NOW!"
	{  2, L_AME(86), L_AME(87), L_AME(86) }, // "Please don't kill me!", "Don't shoot!"
	{  3, L_EAR(64), L_EAR(65), L_EAR(66) }, // "What are you doing in my lab?", "I haven't seen you before...", "Who the hell are you?"
	{  4, L_EAR(67), L_EAR(68), L_EAR(69) }, // "Shut down the experiment.", "Pull the plug on that, NOW.", "Switch this thing off."
	{  5, L_EAR(70), L_EAR(71), L_EAR(72) }, // "I'll shut it down.", "Please don't hurt me.", "Allow me to assist you."
	{  6, L_EAR(73), L_EAR(74), L_EAR(75) }, // "My experiments!", "There the experiment is down.", "Leave this area NOW!"
	{  7, L_EAR(76), L_EAR(77), L_EAR(78) }, // "Security!", "I'm calling security.", "Accidents will happen."
	{  8, L_EAR(79), L_EAR(80), L_EAR(81) }, // "How did that happen?", "Looks like it's off already.", "Have you been tampering with this?"
	{  9, L_EAR(82), L_EAR(83), L_EAR(84) }, // "Someone's broken my equipment.", "What's happened to the terminal?", "You vandal - you've broken it."
	{ 10, L_WAX(10), L_WAX(12), L_WAX(12) }, // "How dare you disturb me!", "If I were you, I'd leave... NOW!"
};

s16 g_SkedarQuipBank[][4] = {
	{ 1, 0x0529, 0x052a, 0x052b },
	{ 2, 0x052d, 0x052e, 0x052f },
	{ 3, 0x0530, 0x0530, 0x0531 },
	{ 1, 0x0532, 0x0533, 0x0534 },
	{ 2, 0x0536, 0x0537, 0x0538 },
	{ 3, 0x0539, 0x0539, 0x053a },
	{ 0, 0x0000, 0x0000, 0x0000 },
};

s16 g_MaianQuipBank[][4] = {
	{ 1, 0x05e2, 0x05e3, 0x05e4 },
	{ 2, 0x05e5, 0x05e6, 0x05e7 },
	{ 3, 0x05df, 0x05e0, 0x05e1 },
	{ 0, 0x0000, 0x0000, 0x0000 },
};

/**
 * Used by AI command 0142, which makes Investigation scientists run to the
 * computer terminals. The number of the left is the pad that the terminal sits
 * on, and the number on the right is the pad that the scientist will run to
 * when running to the terminal.
 */
u16 g_InvestigationPadMap[40] = {
	0x0246, 0x007b,
	0x0247, 0x007d,
	0x0248, 0x007e,
	0x0249, 0x007c,
	0x024a, 0x0093,
	0x024b, 0x0091,
	0x024c, 0x0092,
	0x024d, 0x0093,
	0x024e, 0x00ae,
	0x024f, 0x00ac,
	0x0250, 0x00ab,
	0x0251, 0x00ad,
	0x0252, 0x00a1,
	0x0253, 0x009f,
	0x0254, 0x00a0,
	0x0255, 0x009e,
	0x0256, 0x00bb,
	0x0257, 0x00b8,
	0x0258, 0x00b9,
	0x0259, 0x00ba,
};

u32 var80069780 = 0x00000000;
u32 var80069784 = 0x00000000;
u32 var80069788 = 0x00000000;
u32 var8006978c = 0x1a000003;

// f7b0
s16 ciquiptable_bank1[][3] = {
	{ 0x17a1, 0x17a2, 0x17a3 },
	{ 0x17a4, 0x17a5, 0x17a6 },
	{ 0x17a7, 0x17a8, 0x17a9 },
	{ 0x17aa, 0x17ab, 0x17ac },
	{ 0x17ad, 0x17ae, 0x17af },
	{ 0x179e, 0x179f, 0x17a0 },
};

// f7d4
s16 ciquiptable_bank0[][3] = {
	{ 0x8028, 0x8028, 0x8028 },
	{ 0x802b, 0x802b, 0x802b },
	{ 0x802c, 0x802d, 0x802e },
	{ 0x802f, 0x802f, 0x802f },
	{ 0x8030, 0x8030, 0x8030 },
	{ 0x8031, 0x8031, 0x8031 },
	{ 0x8032, 0x8032, 0x8033 },
	{ 0x8033, 0x8034, 0x8034 },
	{ 0x8035, 0x8035, 0x8036 },
	{ 0x8036, 0x8037, 0x8037 },
};

// f810
s16 ciquiptable_bank2[][3] = {
	{ 0x177b, 0x177b, 0x177b },
	{ 0x177d, 0x177d, 0x177d },
	{ 0x1789, 0x178a, 0x178b },
	{ 0x178d, 0x178d, 0x178d },
	{ 0x1795, 0x1795, 0x1795 },
	{ 0x1785, 0x1785, 0x1785 },
	{ 0x1791, 0x1791, 0x1791 },
	{ 0x1791, 0x1791, 0x1791 },
	{ 0x1782, 0x1782, 0x1782 },
	{ 0x1783, 0x1783, 0x1783 },
};

// f84c
s16 ciquiptable_bank3[] = {
	0x0000, 0x1b1c, 0x1b1f, 0x1b20, 0x0000, 0x1b1e, 0x1b21, 0x1b21,
	0x1b1d, 0x1b1d,
};

// Table for cmd 01a3 (do_preset_animation)
// These all appear to be talking animations
u16 g_PresetAnimations[15] = {
	/* 0*/ 0x0296,
	/* 1*/ 0x0297,
	/* 2*/ 0x0298,
	/* 3*/ 0x028a, // when value is 3 (1/2 chance)
	/* 4*/ 0x028c, // when value is 3 (1/2 chance)
	/* 5*/ 0x0290,
	/* 6*/ 0x0291,
	/* 7*/ 0x00a3, // when value is 255 (1/8 chance)
	/* 8*/ 0x028e, // when value is 255 (1/8 chance)
	/* 9*/ 0x028f, // when value is 255 (1/8 chance)
	/*10*/ 0x0231, // when value is 255 (1/8 chance)
	/*11*/ 0x0232, // when value is 255 (1/8 chance)
	/*12*/ 0x0233, // when value is 255 (1/8 chance)
	/*13*/ 0x0234, // when value is 255 (1/8 chance)
	/*14*/ 0x028d, // when value is 255 (1/8 chance)
};

u8 var80069860[8] = {0};
struct coord var80069868 = {0, 0, 0};
struct coord var80069874 = {0, 0, 0};
u32 var80069880 = 0x3f800000;
u32 var80069884 = 0x00000001;
u32 var80069888 = 0x01010101;
u32 var8006988c = 0x01000101;
u32 var80069890 = 0x01010100;
u32 var80069894 = 0x00010101;
u32 var80069898 = 0x01010000;
u32 var8006989c = 0x00000000;
u32 var800698a0 = 0x00000100;
u32 var800698a4 = 0x00000000;
u32 var800698a8 = 0x01010000;
u32 var800698ac = 0x00000101;
u32 var800698b0 = 0x01000101;
u32 var800698b4 = 0x00000000;
u32 var800698b8 = 0x00000100;
u32 var800698bc = 0x00000001;
u32 var800698c0 = 0x00000000;
u32 var800698c4 = 0x00000000;
u32 var800698c8 = 0x00000000;
u32 var800698cc = 0x00000000;

// f8f0
u32 g_TintedGlassEnabled = 0;

// f8f4
s32 g_AlarmActive = 0;

u32 var800698d8 = 0x00000000;
u32 var800698dc = 0x42800000;
u32 var800698e0 = 0x3f800000;
u32 var800698e4 = 0x00000000;
u32 var800698e8 = 0x00000000;
u32 var800698ec = 0x00000000;
u32 var800698f0 = 0x00000000;
u32 var800698f4 = 0x00000000;
u32 var800698f8 = 0x00000000;
u32 var800698fc = 0x00000000;
u32 var80069900 = 0x00000000;

u32 g_CountdownTimerVisible = 1; // 80069904
bool g_CountdownTimerRunning = false; // 80069908
f32 g_CountdownTimerValue = 0; // 8006990c

u32 var80069910 = 0x00000000;
u32 var80069914 = 0x00000000;
u32 var80069918 = 0x00000000;
u32 var8006991c = 0x00000000;
u32 var80069920 = 0x00000000;
u32 var80069924 = 0x00000000;
u32 var80069928 = 0x00000000;
u32 var8006992c = 0x00000000;
u32 var80069930 = 0x00000000;
u32 var80069934 = 0x00000000;
u32 var80069938 = 0x00000000;
u32 var8006993c = 0x00000000;
u32 var80069940 = 0x00000000;
u32 var80069944 = 0x00000000;
u32 var80069948 = 0x3f800000;
u32 var8006994c = 0x3f800000;
u32 var80069950 = 0x3f800000;
u32 var80069954 = 0x3f800000;
u32 var80069958 = 0x3f800000;
f32 g_AmmoMultiplier = 1;
u32 var80069960 = 0x00000000;
u32 var80069964 = 0xffffffff;
struct autogunobj *g_ThrownLaptops = NULL;
u32 var8006996c = 0x00000000;
u32 var80069970 = 0x00000000;
u32 var80069974 = 0x00000000;
u32 var80069978 = 0x00000000;
u32 var8006997c = 0x00000000;
u32 var80069980 = 0x0100000f;
u32 var80069984 = 0x0000ffff;
u32 var80069988 = 0x00000001;
u32 var8006998c = 0x00000000;
u32 var80069990 = 0x00000000;
u32 var80069994 = 0x00000000;
u32 var80069998 = 0x00000000;
u32 var8006999c = 0x3f800000;
u32 var800699a0 = 0x00000000;
u32 var800699a4 = 0x00000000;
u32 var800699a8 = 0x00000000;
u32 var800699ac = 0x3f800000;
u32 var800699b0 = 0x00000000;
u32 var800699b4 = 0x00000000;
u32 var800699b8 = 0x00000000;
u32 var800699bc = 0x3f800000;
u32 var800699c0 = 0x00000000;
u32 var800699c4 = 0x00000000;
u32 var800699c8 = 0x00000000;
u32 var800699cc = 0x000003e8;
u32 var800699d0 = 0xffffff00;
u32 var800699d4 = 0xffffff00;
u32 var800699d8 = 0x0fff0000;
u32 var800699dc = 0x00000000;
u32 var800699e0 = 0x00000000;
u32 var800699e4 = 0x00000000;
u32 var800699e8 = 0x00000000;
u32 var800699ec = 0x00000000;
u32 var800699f0 = 0x00000000;
u32 var800699f4 = 0x80748074;
u32 var800699f8 = 0x80740000;
u32 var800699fc = 0x00000000;
u32 var80069a00 = 0xc1200000;
u32 var80069a04 = 0x00000000;
u32 var80069a08 = 0x00000000;
u32 var80069a0c = 0x00000001;
u32 var80069a10 = 0x00000003;
u32 var80069a14 = 0x00000000;
u32 var80069a18 = 0x00000000;
u32 var80069a1c = 0x00000000;
u32 var80069a20 = 0x00000000;
u32 var80069a24 = 0x00000000;
u32 var80069a28 = 0x00000000;
u32 var80069a2c = 0x00000000;
u32 var80069a30 = 0x00000000;
u32 var80069a34 = 0x00000000;
u32 var80069a38 = 0x00000000;
u32 var80069a3c = 0x00000000;
u32 var80069a40 = 0x00000000;
u32 var80069a44 = 0x00000000;
struct prop *g_Lifts[MAX_LIFTS] = {NULL};
u32 var80069a70 = 0x42b40000;
u32 var80069a74 = 0x3f800000;
u32 var80069a78 = 0x40000000;
u32 var80069a7c = 0x3a83126f;
u32 var80069a80 = 0x3f800000;
u32 var80069a84 = 0x3bcddaca;
u32 var80069a88 = 0x3bcddaca;
u32 var80069a8c = 0x372fa9a2;
u32 var80069a90 = 0x39a4af08;
u32 var80069a94 = 0x3bcddaca;
u32 var80069a98 = 0x3bcddaca;
u32 var80069a9c = 0x372fa9a2;
u32 var80069aa0 = 0x39a4af08;
u32 var80069aa4 = 0x42a00000;
u32 var80069aa8 = 0x3f800000;
u32 var80069aac = 0x40400000;
u32 var80069ab0 = 0x3b23d70a;
u32 var80069ab4 = 0x3dcccccd;
u32 var80069ab8 = 0x3c4ddaca;
u32 var80069abc = 0x3c9a6417;
u32 var80069ac0 = 0x37afa9a2;
u32 var80069ac4 = 0x3a24af08;
u32 var80069ac8 = 0x3c4ddaca;
u32 var80069acc = 0x3c9a6417;
u32 var80069ad0 = 0x37afa9a2;
u32 var80069ad4 = 0x3a24af08;
u32 var80069ad8 = 0x428c0000;
u32 var80069adc = 0x40000000;
u32 var80069ae0 = 0x40800000;
u32 var80069ae4 = 0x3a83126f;
u32 var80069ae8 = 0x3f800000;
u32 var80069aec = 0x3bcddaca;
u32 var80069af0 = 0x3c4ddaca;
u32 var80069af4 = 0x372fa9a2;
u32 var80069af8 = 0x39a4af08;
u32 var80069afc = 0x3bcddaca;
u32 var80069b00 = 0x3c4ddaca;
u32 var80069b04 = 0x372fa9a2;
u32 var80069b08 = 0x39a4af08;
u32 var80069b0c = 0x432a0000;
u32 var80069b10 = 0x40000000;
u32 var80069b14 = 0x40000000;
u32 var80069b18 = 0x3a83126f;
u32 var80069b1c = 0x3f800000;
u32 var80069b20 = 0x3b4ddaca;
u32 var80069b24 = 0x3b4ddaca;
u32 var80069b28 = 0x36afa9a2;
u32 var80069b2c = 0x39459ed6;
u32 var80069b30 = 0x3b4ddaca;
u32 var80069b34 = 0x3b4ddaca;
u32 var80069b38 = 0x36afa9a2;
u32 var80069b3c = 0x39459ed6;
u32 var80069b40 = 0x432a0000;
u32 var80069b44 = 0x40000000;
u32 var80069b48 = 0x40000000;
u32 var80069b4c = 0x3a83126f;
u32 var80069b50 = 0x3f800000;
u32 var80069b54 = 0x3b4ddaca;
u32 var80069b58 = 0x3b4ddaca;
u32 var80069b5c = 0x36afa9a2;
u32 var80069b60 = 0x39459ed6;
u32 var80069b64 = 0x3b4ddaca;
u32 var80069b68 = 0x3b4ddaca;
u32 var80069b6c = 0x36afa9a2;
u32 var80069b70 = 0x39459ed6;
u32 var80069b74 = 0x00000000;
u32 var80069b78 = 0x00000000;
u32 var80069b7c = 0x00000000;
u32 var80069b80 = 0x00000000;
u32 var80069b84 = 0x00000000;
u32 var80069b88 = 0x00000000;
u32 var80069b8c = 0x00000000;
u32 var80069b90 = 0x00000000;
u32 var80069b94 = 0x00000000;
u32 var80069b98 = 0x00000000;
u32 var80069b9c = 0x00000000;
u32 var80069ba0 = 0x00000000;
u32 var80069ba4 = 0x00000000;
u32 var80069ba8 = 0x00000000;
u32 var80069bac = 0x3f800000;
u32 var80069bb0 = 0x00000000;
u32 var80069bb4 = 0x3f800000;
u32 var80069bb8 = 0x00000000;
u32 var80069bbc = 0x00270028;
u32 var80069bc0 = 0x0029002a;
u32 var80069bc4 = 0x00000000;
u32 var80069bc8 = 0x00000003;
u32 var80069bcc = 0x00000014;
u32 var80069bd0 = 0x00000078;
u32 var80069bd4 = 0x00000000;
u32 var80069bd8 = 0x00000000;
u32 var80069bdc = 0xc4bfff5c;
u32 var80069be0 = 0xc3ff8000;
u32 var80069be4 = 0xc5a45171;
u32 var80069be8 = 0x00000029;
u32 var80069bec = 0xc4bfff5c;
u32 var80069bf0 = 0xc3fce148;
u32 var80069bf4 = 0xc5a22371;
u32 var80069bf8 = 0x00000095;
u32 var80069bfc = 0xc4bfff5c;
u32 var80069c00 = 0xc3fc651f;
u32 var80069c04 = 0xc59c8600;
u32 var80069c08 = 0x000002ba;
u32 var80069c0c = 0xc4bfff5c;
u32 var80069c10 = 0xc2c9d1ec;
u32 var80069c14 = 0xc58396e1;
u32 var80069c18 = 0x000002f7;
u32 var80069c1c = 0xc4bfff5c;
u32 var80069c20 = 0xc2c5c7ae;
u32 var80069c24 = 0xc5806cf6;
u32 var80069c28 = 0x00000320;
u32 var80069c2c = 0xc4bfff5c;
u32 var80069c30 = 0xc2cc0000;
u32 var80069c34 = 0xc57c70f6;
u32 var80069c38 = 0xffffffff;
u32 var80069c3c = 0x00000000;
u32 var80069c40 = 0x00000000;
u32 var80069c44 = 0x00000000;
u32 var80069c48 = 0x00000000;
u32 var80069c4c = 0xc4f188a4;
u32 var80069c50 = 0xc2cc0000;
u32 var80069c54 = 0xc56f0948;
u32 var80069c58 = 0x00000029;
u32 var80069c5c = 0xc4fa5a8f;
u32 var80069c60 = 0xc2c5c7ae;
u32 var80069c64 = 0xc56f0948;
u32 var80069c68 = 0x00000066;
u32 var80069c6c = 0xc503811f;
u32 var80069c70 = 0xc2c9d1ec;
u32 var80069c74 = 0xc56f0948;
u32 var80069c78 = 0x0000028b;
u32 var80069c7c = 0xc5355f5c;
u32 var80069c80 = 0xc3fc651f;
u32 var80069c84 = 0xc56f0948;
u32 var80069c88 = 0x000002f7;
u32 var80069c8c = 0xc5409a3d;
u32 var80069c90 = 0xc3fce148;
u32 var80069c94 = 0xc56f0948;
u32 var80069c98 = 0x00000320;
u32 var80069c9c = 0xc544f63d;
u32 var80069ca0 = 0xc3ff8000;
u32 var80069ca4 = 0xc56f0948;
u32 var80069ca8 = 0xffffffff;
u32 var80069cac = 0x00000000;
u32 var80069cb0 = 0x00000000;
u32 var80069cb4 = 0x00000000;
u32 var80069cb8 = 0x2b000000;
u32 var80069cbc = 0x0e000001;
u32 var80069cc0 = 0x00000000;
u32 var80069cc4 = 0x00000000;
u32 var80069cc8 = 0x00000001;
u32 var80069ccc = 0x00000003;
u32 var80069cd0 = 0x00000000;
u32 var80069cd4 = 0x00000000;
u32 var80069cd8 = 0x00000000;
u32 var80069cdc = 0x00000000;
u32 var80069ce0 = 0x00000000;
u32 var80069ce4 = 0x00000000;
u32 var80069ce8 = 0x00000000;
u32 var80069cec = 0x00000000;
u32 var80069cf0 = 0x00000000;
u32 var80069cf4 = 0x00000000;
u32 var80069cf8 = 0x00000000;
u32 var80069cfc = 0x00000000;
u32 var80069d00 = 0x00000000;
u32 var80069d04 = 0x00000000;
u32 var80069d08 = 0x00000001;
u32 var80069d0c = 0x00000003;
u32 var80069d10 = 0x00000000;
u32 var80069d14 = 0x00000000;
u32 var80069d18 = 0x00000000;
u32 var80069d1c = 0x00000000;
u32 var80069d20 = 0x00000000;
u32 var80069d24 = 0x00000000;
u32 var80069d28 = 0x00000000;
u32 var80069d2c = 0x00000000;
u32 var80069d30 = 0x00000000;
u32 var80069d34 = 0x00000000;
u32 var80069d38 = 0x00000000;
u32 var80069d3c = 0x00000000;
u32 var80069d40 = 0x00000000;
u32 var80069d44 = 0x00000000;
u32 var80069d48 = 0x00000001;
u32 var80069d4c = 0x00000003;
u32 var80069d50 = 0x00000000;
u32 var80069d54 = 0x00000000;
u32 var80069d58 = 0x00000000;
u32 var80069d5c = 0x00000000;
u32 var80069d60 = 0x00000000;
u32 var80069d64 = 0x00000000;
u32 var80069d68 = 0x00000000;
u32 var80069d6c = 0x00000000;
u32 var80069d70 = 0x00000000;
u32 var80069d74 = 0x00000000;
u32 var80069d78 = 0x00000000;
u32 var80069d7c = 0x00000000;
u32 var80069d80 = 0x00000000;
u32 var80069d84 = 0x00000000;
u32 var80069d88 = 0x00000000;
u32 var80069d8c = 0x00000000;
u32 var80069d90 = 0x00000007;
u32 var80069d94 = 0x0000001d;
u32 var80069d98 = 0x0000000d;
u32 var80069d9c = 0x008000ff;
u32 var80069da0 = 0x00000001;
u32 var80069da4 = 0x00000002;
u32 var80069da8 = 0xfffffe00;
u32 var80069dac = 0x00000050;
u32 var80069db0 = 0x00000008;
u32 var80069db4 = 0x00000078;
u32 var80069db8 = 0x00000002;
u32 var80069dbc = 0xffffff00;
u32 var80069dc0 = 0x00000014;
u32 var80069dc4 = 0x00000008;
u32 var80069dc8 = 0x00000078;
u32 var80069dcc = 0x00000002;
u32 var80069dd0 = 0xffffff80;
u32 var80069dd4 = 0x0000000a;
u32 var80069dd8 = 0x00000008;
u32 var80069ddc = 0x00000028;
u32 var80069de0 = 0x00000002;
u32 var80069de4 = 0xfffffe00;
u32 var80069de8 = 0x00000028;
u32 var80069dec = 0x00000008;
u32 var80069df0 = 0x0000003c;
u32 var80069df4 = 0x00000002;
u32 var80069df8 = 0xffffffc0;
u32 var80069dfc = 0x0000001e;
u32 var80069e00 = 0x00000008;
u32 var80069e04 = 0x00000078;
u32 var80069e08 = 0x0000000b;
u32 var80069e0c = 0x0000000d;
u32 var80069e10 = 0x202020ff;
u32 var80069e14 = 0x00000001;
u32 var80069e18 = 0x00000007;
u32 var80069e1c = 0x0000001c;
u32 var80069e20 = 0x00000001;
u32 var80069e24 = 0x00000800;
u32 var80069e28 = 0x00000078;
u32 var80069e2c = 0x00000008;
u32 var80069e30 = 0x00000078;
u32 var80069e34 = 0x00000005;
u32 var80069e38 = 0x00000100;
u32 var80069e3c = 0x00000001;
u32 var80069e40 = 0x00000006;
u32 var80069e44 = 0x00000200;
u32 var80069e48 = 0x0000003c;
u32 var80069e4c = 0x00000001;
u32 var80069e50 = 0xffffe000;
u32 var80069e54 = 0x00000078;
u32 var80069e58 = 0x00000008;
u32 var80069e5c = 0x00000078;
u32 var80069e60 = 0x00000005;
u32 var80069e64 = 0x00000400;
u32 var80069e68 = 0x00000001;
u32 var80069e6c = 0x00000006;
u32 var80069e70 = 0x00000400;
u32 var80069e74 = 0x0000003c;
u32 var80069e78 = 0x00000006;
u32 var80069e7c = 0x00000400;
u32 var80069e80 = 0x0000003c;
u32 var80069e84 = 0x00000001;
u32 var80069e88 = 0x00000800;
u32 var80069e8c = 0x00000078;
u32 var80069e90 = 0x00000008;
u32 var80069e94 = 0x00000078;
u32 var80069e98 = 0x00000005;
u32 var80069e9c = 0x00000080;
u32 var80069ea0 = 0x00000001;
u32 var80069ea4 = 0x00000006;
u32 var80069ea8 = 0x00000800;
u32 var80069eac = 0x0000003c;
u32 var80069eb0 = 0x00000006;
u32 var80069eb4 = 0x00000400;
u32 var80069eb8 = 0x00000078;
u32 var80069ebc = 0x00000002;
u32 var80069ec0 = 0x00000400;
u32 var80069ec4 = 0x0000003c;
u32 var80069ec8 = 0x00000001;
u32 var80069ecc = 0x00000200;
u32 var80069ed0 = 0x00000078;
u32 var80069ed4 = 0x00000008;
u32 var80069ed8 = 0x00000078;
u32 var80069edc = 0x0000000b;
u32 var80069ee0 = 0x0000000d;
u32 var80069ee4 = 0x202020ff;
u32 var80069ee8 = 0x00000001;
u32 var80069eec = 0x00000007;
u32 var80069ef0 = 0x0000001c;
u32 var80069ef4 = 0x00000005;
u32 var80069ef8 = 0x00000080;
u32 var80069efc = 0x00000001;
u32 var80069f00 = 0x00000006;
u32 var80069f04 = 0x00000800;
u32 var80069f08 = 0x0000003c;
u32 var80069f0c = 0x00000006;
u32 var80069f10 = 0x00000400;
u32 var80069f14 = 0x00000078;
u32 var80069f18 = 0x00000002;
u32 var80069f1c = 0x00000400;
u32 var80069f20 = 0x0000000a;
u32 var80069f24 = 0x00000001;
u32 var80069f28 = 0x00000200;
u32 var80069f2c = 0x00000028;
u32 var80069f30 = 0x00000008;
u32 var80069f34 = 0x00000078;
u32 var80069f38 = 0x0000000b;
u32 var80069f3c = 0x00000007;
u32 var80069f40 = 0x0000001d;
u32 var80069f44 = 0x0000000d;
u32 var80069f48 = 0x008000ff;
u32 var80069f4c = 0x00000001;
u32 var80069f50 = 0x00000002;
u32 var80069f54 = 0xfffffe00;
u32 var80069f58 = 0x00000050;
u32 var80069f5c = 0x00000008;
u32 var80069f60 = 0x00000078;
u32 var80069f64 = 0x00000002;
u32 var80069f68 = 0xffffff00;
u32 var80069f6c = 0x00000014;
u32 var80069f70 = 0x00000008;
u32 var80069f74 = 0x00000078;
u32 var80069f78 = 0x00000002;
u32 var80069f7c = 0xffffff80;
u32 var80069f80 = 0x0000000a;
u32 var80069f84 = 0x00000008;
u32 var80069f88 = 0x00000028;
u32 var80069f8c = 0x00000002;
u32 var80069f90 = 0xfffffe00;
u32 var80069f94 = 0x00000028;
u32 var80069f98 = 0x00000008;
u32 var80069f9c = 0x0000003c;
u32 var80069fa0 = 0x00000002;
u32 var80069fa4 = 0xffffffc0;
u32 var80069fa8 = 0x0000001e;
u32 var80069fac = 0x00000008;
u32 var80069fb0 = 0x00000078;
u32 var80069fb4 = 0x0000000b;
u32 var80069fb8 = 0x00000007;
u32 var80069fbc = 0x00000032;
u32 var80069fc0 = 0x0000000d;
u32 var80069fc4 = 0x008000fe;
u32 var80069fc8 = 0x00000001;
u32 var80069fcc = 0x00000002;
u32 var80069fd0 = 0xfffffe00;
u32 var80069fd4 = 0x00000050;
u32 var80069fd8 = 0x00000008;
u32 var80069fdc = 0x00000078;
u32 var80069fe0 = 0x00000002;
u32 var80069fe4 = 0xffffff00;
u32 var80069fe8 = 0x00000014;
u32 var80069fec = 0x00000008;
u32 var80069ff0 = 0x00000078;
u32 var80069ff4 = 0x00000002;
u32 var80069ff8 = 0xffffff80;
u32 var80069ffc = 0x0000000a;
u32 var8006a000 = 0x00000008;
u32 var8006a004 = 0x00000028;
u32 var8006a008 = 0x00000002;
u32 var8006a00c = 0xfffffe00;
u32 var8006a010 = 0x00000028;
u32 var8006a014 = 0x00000008;
u32 var8006a018 = 0x0000003c;
u32 var8006a01c = 0x00000002;
u32 var8006a020 = 0xffffffc0;
u32 var8006a024 = 0x0000001e;
u32 var8006a028 = 0x00000008;
u32 var8006a02c = 0x00000078;
u32 var8006a030 = 0x0000000b;
u32 var8006a034 = 0x00000007;
u32 var8006a038 = 0x0000001d;
u32 var8006a03c = 0x0000000d;
u32 var8006a040 = 0x280000ff;
u32 var8006a044 = 0x00000001;
u32 var8006a048 = 0x00000002;
u32 var8006a04c = 0x00000200;
u32 var8006a050 = 0x00000050;
u32 var8006a054 = 0x00000008;
u32 var8006a058 = 0x00000078;
u32 var8006a05c = 0x00000002;
u32 var8006a060 = 0x00000100;
u32 var8006a064 = 0x00000014;
u32 var8006a068 = 0x00000008;
u32 var8006a06c = 0x00000078;
u32 var8006a070 = 0x00000002;
u32 var8006a074 = 0x00000080;
u32 var8006a078 = 0x0000000a;
u32 var8006a07c = 0x00000008;
u32 var8006a080 = 0x00000028;
u32 var8006a084 = 0x00000002;
u32 var8006a088 = 0x00000200;
u32 var8006a08c = 0x00000028;
u32 var8006a090 = 0x00000008;
u32 var8006a094 = 0x0000003c;
u32 var8006a098 = 0x00000002;
u32 var8006a09c = 0x00000040;
u32 var8006a0a0 = 0x0000001e;
u32 var8006a0a4 = 0x00000008;
u32 var8006a0a8 = 0x00000078;
u32 var8006a0ac = 0x00000002;
u32 var8006a0b0 = 0x00000100;
u32 var8006a0b4 = 0x00000014;
u32 var8006a0b8 = 0x00000008;
u32 var8006a0bc = 0x00000078;
u32 var8006a0c0 = 0x00000002;
u32 var8006a0c4 = 0x00000080;
u32 var8006a0c8 = 0x0000000a;
u32 var8006a0cc = 0x0000000b;
u32 var8006a0d0 = 0x00000007;
u32 var8006a0d4 = 0x0000001d;
u32 var8006a0d8 = 0x0000000d;
u32 var8006a0dc = 0x003c00ff;
u32 var8006a0e0 = 0x00000001;
u32 var8006a0e4 = 0x00000002;
u32 var8006a0e8 = 0x00000200;
u32 var8006a0ec = 0x00000050;
u32 var8006a0f0 = 0x00000008;
u32 var8006a0f4 = 0x00000078;
u32 var8006a0f8 = 0x00000002;
u32 var8006a0fc = 0x00000080;
u32 var8006a100 = 0x0000000a;
u32 var8006a104 = 0x00000008;
u32 var8006a108 = 0x00000028;
u32 var8006a10c = 0x00000002;
u32 var8006a110 = 0x00000100;
u32 var8006a114 = 0x00000014;
u32 var8006a118 = 0x00000008;
u32 var8006a11c = 0x00000078;
u32 var8006a120 = 0x00000002;
u32 var8006a124 = 0x00000080;
u32 var8006a128 = 0x0000000a;
u32 var8006a12c = 0x00000008;
u32 var8006a130 = 0x00000028;
u32 var8006a134 = 0x00000002;
u32 var8006a138 = 0x00000200;
u32 var8006a13c = 0x00000028;
u32 var8006a140 = 0x00000008;
u32 var8006a144 = 0x0000003c;
u32 var8006a148 = 0x00000002;
u32 var8006a14c = 0x00000040;
u32 var8006a150 = 0x0000001e;
u32 var8006a154 = 0x00000008;
u32 var8006a158 = 0x00000078;
u32 var8006a15c = 0x0000000b;
u32 var8006a160 = 0x00000007;
u32 var8006a164 = 0x0000001e;
u32 var8006a168 = 0x0000000d;
u32 var8006a16c = 0x404000ff;
u32 var8006a170 = 0x00000001;
u32 var8006a174 = 0x00000001;
u32 var8006a178 = 0x00000280;
u32 var8006a17c = 0x00000001;
u32 var8006a180 = 0x00000008;
u32 var8006a184 = 0x0000000a;
u32 var8006a188 = 0x0000000b;
u32 var8006a18c = 0x00000007;
u32 var8006a190 = 0x0000001e;
u32 var8006a194 = 0x0000000d;
u32 var8006a198 = 0x004040ff;
u32 var8006a19c = 0x00000001;
u32 var8006a1a0 = 0x00000001;
u32 var8006a1a4 = 0x00000280;
u32 var8006a1a8 = 0x00000001;
u32 var8006a1ac = 0x00000008;
u32 var8006a1b0 = 0x0000000a;
u32 var8006a1b4 = 0x0000000b;
u32 var8006a1b8 = 0x00000007;
u32 var8006a1bc = 0x0000001e;
u32 var8006a1c0 = 0x0000000d;
u32 var8006a1c4 = 0x008000ff;
u32 var8006a1c8 = 0x00000001;
u32 var8006a1cc = 0x00000001;
u32 var8006a1d0 = 0xfffffd80;
u32 var8006a1d4 = 0x00000001;
u32 var8006a1d8 = 0x00000008;
u32 var8006a1dc = 0x0000000a;
u32 var8006a1e0 = 0x0000000b;
u32 var8006a1e4 = 0x00000007;
u32 var8006a1e8 = 0x00000031;
u32 var8006a1ec = 0x00000005;
u32 var8006a1f0 = 0x00000200;
u32 var8006a1f4 = 0x00000000;
u32 var8006a1f8 = 0x00000006;
u32 var8006a1fc = 0x00000200;
u32 var8006a200 = 0x00000000;
u32 var8006a204 = 0x0000000d;
u32 var8006a208 = 0xdc2828ff;
u32 var8006a20c = 0x0000003c;
u32 var8006a210 = 0x00000008;
u32 var8006a214 = 0x0000003c;
u32 var8006a218 = 0x0000000d;
u32 var8006a21c = 0x323232ff;
u32 var8006a220 = 0x0000000a;
u32 var8006a224 = 0x00000008;
u32 var8006a228 = 0x0000000a;
u32 var8006a22c = 0x0000000b;
u32 var8006a230 = 0x00000007;
u32 var8006a234 = 0x00000031;
u32 var8006a238 = 0x00000005;
u32 var8006a23c = 0x00000200;
u32 var8006a240 = 0x00000000;
u32 var8006a244 = 0x00000006;
u32 var8006a248 = 0x00000200;
u32 var8006a24c = 0x00000000;
u32 var8006a250 = 0x0000000d;
u32 var8006a254 = 0x32c832ff;
u32 var8006a258 = 0x0000003c;
u32 var8006a25c = 0x00000008;
u32 var8006a260 = 0x0000003c;
u32 var8006a264 = 0x0000000d;
u32 var8006a268 = 0x323232ff;
u32 var8006a26c = 0x0000000a;
u32 var8006a270 = 0x00000008;
u32 var8006a274 = 0x0000000a;
u32 var8006a278 = 0x0000000b;
u32 var8006a27c = 0x00000007;
u32 var8006a280 = 0x00000031;
u32 var8006a284 = 0x00000005;
u32 var8006a288 = 0x00000200;
u32 var8006a28c = 0x00000000;
u32 var8006a290 = 0x00000006;
u32 var8006a294 = 0x00000200;
u32 var8006a298 = 0x00000000;
u32 var8006a29c = 0x0000000d;
u32 var8006a2a0 = 0x323232ff;
u32 var8006a2a4 = 0x0000000a;
u32 var8006a2a8 = 0x00000008;
u32 var8006a2ac = 0x0000000a;
u32 var8006a2b0 = 0x0000000b;
u32 var8006a2b4 = 0x00000007;
u32 var8006a2b8 = 0x00000031;
u32 var8006a2bc = 0x00000005;
u32 var8006a2c0 = 0x00000200;
u32 var8006a2c4 = 0x00000000;
u32 var8006a2c8 = 0x00000006;
u32 var8006a2cc = 0x00000200;
u32 var8006a2d0 = 0x00000000;
u32 var8006a2d4 = 0x0000000d;
u32 var8006a2d8 = 0xdc2828ff;
u32 var8006a2dc = 0x0000000a;
u32 var8006a2e0 = 0x00000008;
u32 var8006a2e4 = 0x0000000a;
u32 var8006a2e8 = 0x0000000b;
u32 var8006a2ec = 0x00000007;
u32 var8006a2f0 = 0x00000031;
u32 var8006a2f4 = 0x00000005;
u32 var8006a2f8 = 0x00000200;
u32 var8006a2fc = 0x00000000;
u32 var8006a300 = 0x00000006;
u32 var8006a304 = 0x00000200;
u32 var8006a308 = 0x00000000;
u32 var8006a30c = 0x0000000d;
u32 var8006a310 = 0x32c832ff;
u32 var8006a314 = 0x0000000a;
u32 var8006a318 = 0x00000008;
u32 var8006a31c = 0x0000000a;
u32 var8006a320 = 0x0000000b;
u32 var8006a324 = 0x00000007;
u32 var8006a328 = 0x00000033;
u32 var8006a32c = 0x0000000d;
u32 var8006a330 = 0xffffffff;
u32 var8006a334 = 0x00000001;
u32 var8006a338 = 0x00000008;
u32 var8006a33c = 0x0000000a;
u32 var8006a340 = 0x0000000b;
u32 var8006a344 = 0x00000007;
u32 var8006a348 = 0x00000048;
u32 var8006a34c = 0x0000000d;
u32 var8006a350 = 0xffffffff;
u32 var8006a354 = 0x00000001;
u32 var8006a358 = 0x00000008;
u32 var8006a35c = 0x0000000a;
u32 var8006a360 = 0x0000000b;
u32 var8006a364 = 0x00000007;
u32 var8006a368 = 0x00000049;
u32 var8006a36c = 0x0000000d;
u32 var8006a370 = 0xffffffff;
u32 var8006a374 = 0x00000001;
u32 var8006a378 = 0x00000008;
u32 var8006a37c = 0x0000000a;
u32 var8006a380 = 0x0000000b;
u32 var8006a384 = 0x00000007;
u32 var8006a388 = 0x0000004a;
u32 var8006a38c = 0x0000000d;
u32 var8006a390 = 0xffffffff;
u32 var8006a394 = 0x00000001;
u32 var8006a398 = 0x00000008;
u32 var8006a39c = 0x0000000a;
u32 var8006a3a0 = 0x0000000b;
u32 var8006a3a4 = 0x00000007;
u32 var8006a3a8 = 0x0000004b;
u32 var8006a3ac = 0x0000000d;
u32 var8006a3b0 = 0xffffffff;
u32 var8006a3b4 = 0x00000001;
u32 var8006a3b8 = 0x00000008;
u32 var8006a3bc = 0x0000000a;
u32 var8006a3c0 = 0x0000000b;
u32 var8006a3c4 = 0x00000007;
u32 var8006a3c8 = 0x0000004c;
u32 var8006a3cc = 0x0000000d;
u32 var8006a3d0 = 0xffffffff;
u32 var8006a3d4 = 0x00000001;
u32 var8006a3d8 = 0x00000008;
u32 var8006a3dc = 0x0000000a;
u32 var8006a3e0 = 0x0000000b;
u32 var8006a3e4 = 0x00000007;
u32 var8006a3e8 = 0x0000004d;
u32 var8006a3ec = 0x0000000d;
u32 var8006a3f0 = 0xffffffff;
u32 var8006a3f4 = 0x00000001;
u32 var8006a3f8 = 0x00000008;
u32 var8006a3fc = 0x0000000a;
u32 var8006a400 = 0x0000000b;
u32 var8006a404 = 0x0000000d;
u32 var8006a408 = 0x000000ff;
u32 var8006a40c = 0x00000001;
u32 var8006a410 = 0x00000007;
u32 var8006a414 = 0x0000004b;
u32 var8006a418 = 0x00000008;
u32 var8006a41c = 0x00000001;
u32 var8006a420 = 0x0000000d;
u32 var8006a424 = 0xffffffff;
u32 var8006a428 = 0x000000b4;
u32 var8006a42c = 0x00000008;
u32 var8006a430 = 0x00000168;
u32 var8006a434 = 0x0000000d;
u32 var8006a438 = 0x000000ff;
u32 var8006a43c = 0x0000001e;
u32 var8006a440 = 0x00000008;
u32 var8006a444 = 0x0000001e;
u32 var8006a448 = 0x00000007;
u32 var8006a44c = 0x0000004c;
u32 var8006a450 = 0x00000008;
u32 var8006a454 = 0x00000001;
u32 var8006a458 = 0x0000000d;
u32 var8006a45c = 0xffffffff;
u32 var8006a460 = 0x000000b4;
u32 var8006a464 = 0x00000008;
u32 var8006a468 = 0x00000168;
u32 var8006a46c = 0x0000000d;
u32 var8006a470 = 0x000000ff;
u32 var8006a474 = 0x0000001e;
u32 var8006a478 = 0x00000008;
u32 var8006a47c = 0x0000001e;
u32 var8006a480 = 0x00000007;
u32 var8006a484 = 0x0000004d;
u32 var8006a488 = 0x00000008;
u32 var8006a48c = 0x00000001;
u32 var8006a490 = 0x0000000d;
u32 var8006a494 = 0xffffffff;
u32 var8006a498 = 0x000000b4;
u32 var8006a49c = 0x00000008;
u32 var8006a4a0 = 0x00000168;
u32 var8006a4a4 = 0x0000000d;
u32 var8006a4a8 = 0x000000ff;
u32 var8006a4ac = 0x0000001d;
u32 var8006a4b0 = 0x00000008;
u32 var8006a4b4 = 0x0000001d;
u32 var8006a4b8 = 0x0000000b;
u32 var8006a4bc = 0x00000007;
u32 var8006a4c0 = 0x0000004e;
u32 var8006a4c4 = 0x0000000d;
u32 var8006a4c8 = 0xffffffff;
u32 var8006a4cc = 0x00000001;
u32 var8006a4d0 = 0x00000008;
u32 var8006a4d4 = 0x0000000a;
u32 var8006a4d8 = 0x0000000b;
u32 var8006a4dc = 0x00000007;
u32 var8006a4e0 = 0x00000034;
u32 var8006a4e4 = 0x0000000d;
u32 var8006a4e8 = 0xffffffff;
u32 var8006a4ec = 0x00000001;
u32 var8006a4f0 = 0x00000008;
u32 var8006a4f4 = 0x00000005;
u32 var8006a4f8 = 0x00000007;
u32 var8006a4fc = 0x00000035;
u32 var8006a500 = 0x00000008;
u32 var8006a504 = 0x00000005;
u32 var8006a508 = 0x00000007;
u32 var8006a50c = 0x00000036;
u32 var8006a510 = 0x00000008;
u32 var8006a514 = 0x00000005;
u32 var8006a518 = 0x00000007;
u32 var8006a51c = 0x00000037;
u32 var8006a520 = 0x00000008;
u32 var8006a524 = 0x00000005;
u32 var8006a528 = 0x0000000b;
u32 var8006a52c = 0x00000007;
u32 var8006a530 = 0x0000004f;
u32 var8006a534 = 0x0000000d;
u32 var8006a538 = 0xffffffff;
u32 var8006a53c = 0x00000001;
u32 var8006a540 = 0x00000008;
u32 var8006a544 = 0x00000005;
u32 var8006a548 = 0x00000007;
u32 var8006a54c = 0x00000050;
u32 var8006a550 = 0x00000008;
u32 var8006a554 = 0x00000005;
u32 var8006a558 = 0x00000007;
u32 var8006a55c = 0x00000051;
u32 var8006a560 = 0x00000008;
u32 var8006a564 = 0x00000005;
u32 var8006a568 = 0x00000007;
u32 var8006a56c = 0x00000052;
u32 var8006a570 = 0x00000008;
u32 var8006a574 = 0x00000005;
u32 var8006a578 = 0x0000000b;
u32 var8006a57c = 0x00000007;
u32 var8006a580 = 0x00000038;
u32 var8006a584 = 0x0000000d;
u32 var8006a588 = 0xffffffff;
u32 var8006a58c = 0x00000001;
u32 var8006a590 = 0x00000008;
u32 var8006a594 = 0x0000000a;
u32 var8006a598 = 0x00000007;
u32 var8006a59c = 0x00000039;
u32 var8006a5a0 = 0x00000008;
u32 var8006a5a4 = 0x0000000a;
u32 var8006a5a8 = 0x00000007;
u32 var8006a5ac = 0x0000003a;
u32 var8006a5b0 = 0x00000008;
u32 var8006a5b4 = 0x0000000a;
u32 var8006a5b8 = 0x00000007;
u32 var8006a5bc = 0x0000003b;
u32 var8006a5c0 = 0x00000008;
u32 var8006a5c4 = 0x0000000a;
u32 var8006a5c8 = 0x0000000b;
u32 var8006a5cc = 0x00000007;
u32 var8006a5d0 = 0x0000003c;
u32 var8006a5d4 = 0x0000000d;
u32 var8006a5d8 = 0xffffffff;
u32 var8006a5dc = 0x00000001;
u32 var8006a5e0 = 0x00000008;
u32 var8006a5e4 = 0x0000000f;
u32 var8006a5e8 = 0x00000007;
u32 var8006a5ec = 0x0000003d;
u32 var8006a5f0 = 0x00000008;
u32 var8006a5f4 = 0x0000000f;
u32 var8006a5f8 = 0x0000000b;
u32 var8006a5fc = 0x00000007;
u32 var8006a600 = 0x0000003e;
u32 var8006a604 = 0x0000000d;
u32 var8006a608 = 0xffffffff;
u32 var8006a60c = 0x00000001;
u32 var8006a610 = 0x00000008;
u32 var8006a614 = 0x0000000a;
u32 var8006a618 = 0x00000007;
u32 var8006a61c = 0x0000003f;
u32 var8006a620 = 0x00000008;
u32 var8006a624 = 0x0000000a;
u32 var8006a628 = 0x00000007;
u32 var8006a62c = 0x00000040;
u32 var8006a630 = 0x00000008;
u32 var8006a634 = 0x0000000a;
u32 var8006a638 = 0x00000007;
u32 var8006a63c = 0x00000041;
u32 var8006a640 = 0x00000008;
u32 var8006a644 = 0x0000000a;
u32 var8006a648 = 0x00000007;
u32 var8006a64c = 0x00000042;
u32 var8006a650 = 0x00000008;
u32 var8006a654 = 0x0000000a;
u32 var8006a658 = 0x0000000b;
u32 var8006a65c = 0x00000007;
u32 var8006a660 = 0x00000043;
u32 var8006a664 = 0x0000000d;
u32 var8006a668 = 0xffffffff;
u32 var8006a66c = 0x00000001;
u32 var8006a670 = 0x00000008;
u32 var8006a674 = 0x0000000a;
u32 var8006a678 = 0x00000007;
u32 var8006a67c = 0x00000044;
u32 var8006a680 = 0x00000008;
u32 var8006a684 = 0x0000000a;
u32 var8006a688 = 0x00000007;
u32 var8006a68c = 0x00000045;
u32 var8006a690 = 0x00000008;
u32 var8006a694 = 0x0000000a;
u32 var8006a698 = 0x00000007;
u32 var8006a69c = 0x00000046;
u32 var8006a6a0 = 0x00000008;
u32 var8006a6a4 = 0x0000000a;
u32 var8006a6a8 = 0x00000007;
u32 var8006a6ac = 0x00000047;
u32 var8006a6b0 = 0x00000008;
u32 var8006a6b4 = 0x0000000a;
u32 var8006a6b8 = 0x0000000b;
u32 var8006a6bc = 0x00000007;
u32 var8006a6c0 = 0x00000053;
u32 var8006a6c4 = 0x0000000d;
u32 var8006a6c8 = 0xffffffff;
u32 var8006a6cc = 0x00000001;
u32 var8006a6d0 = 0x00000008;
u32 var8006a6d4 = 0x0000000a;
u32 var8006a6d8 = 0x0000000b;
u32 var8006a6dc = 0x00000007;
u32 var8006a6e0 = 0x00000054;
u32 var8006a6e4 = 0x0000000d;
u32 var8006a6e8 = 0xffffffff;
u32 var8006a6ec = 0x00000001;
u32 var8006a6f0 = 0x00000008;
u32 var8006a6f4 = 0x0000000a;
u32 var8006a6f8 = 0x0000000b;
u32 var8006a6fc = 0x00000007;
u32 var8006a700 = 0x00000055;
u32 var8006a704 = 0x0000000d;
u32 var8006a708 = 0x008000ff;
u32 var8006a70c = 0x00000001;
u32 var8006a710 = 0x00000002;
u32 var8006a714 = 0xfffffe00;
u32 var8006a718 = 0x00000050;
u32 var8006a71c = 0x00000008;
u32 var8006a720 = 0x00000050;
u32 var8006a724 = 0x0000000b;
u32 var8006a728 = 0x00000007;
u32 var8006a72c = 0x00000055;
u32 var8006a730 = 0x0000000d;
u32 var8006a734 = 0x0032c8ff;
u32 var8006a738 = 0x00000001;
u32 var8006a73c = 0x00000002;
u32 var8006a740 = 0x00000200;
u32 var8006a744 = 0x00000050;
u32 var8006a748 = 0x00000008;
u32 var8006a74c = 0x00000050;
u32 var8006a750 = 0x0000000b;
u32 var8006a754 = 0x00000007;
u32 var8006a758 = 0x00000056;
u32 var8006a75c = 0x0000000d;
u32 var8006a760 = 0xffffffff;
u32 var8006a764 = 0x00000001;
u32 var8006a768 = 0x00000008;
u32 var8006a76c = 0x0000000a;
u32 var8006a770 = 0x0000000b;
u32 var8006a774 = 0x00000007;
u32 var8006a778 = 0x00000056;
u32 var8006a77c = 0x0000000d;
u32 var8006a780 = 0xffffffff;
u32 var8006a784 = 0x00000001;
u32 var8006a788 = 0x00000002;
u32 var8006a78c = 0xfffffe00;
u32 var8006a790 = 0x00000050;
u32 var8006a794 = 0x00000008;
u32 var8006a798 = 0x00000050;
u32 var8006a79c = 0x0000000b;
u32 var8006a7a0 = 0x00000007;
u32 var8006a7a4 = 0x00000057;
u32 var8006a7a8 = 0x0000000d;
u32 var8006a7ac = 0x008000ff;
u32 var8006a7b0 = 0x00000001;
u32 var8006a7b4 = 0x00000002;
u32 var8006a7b8 = 0xfffffe00;
u32 var8006a7bc = 0x00000050;
u32 var8006a7c0 = 0x00000008;
u32 var8006a7c4 = 0x00000050;
u32 var8006a7c8 = 0x0000000b;
u32 var8006a7cc = 0x00000007;
u32 var8006a7d0 = 0x00000057;
u32 var8006a7d4 = 0x0000000d;
u32 var8006a7d8 = 0x0032c8ff;
u32 var8006a7dc = 0x00000001;
u32 var8006a7e0 = 0x00000002;
u32 var8006a7e4 = 0x00000200;
u32 var8006a7e8 = 0x00000050;
u32 var8006a7ec = 0x00000008;
u32 var8006a7f0 = 0x00000050;
u32 var8006a7f4 = 0x0000000b;
u32 var8006a7f8 = 0x00000007;
u32 var8006a7fc = 0x00000058;
u32 var8006a800 = 0x0000000d;
u32 var8006a804 = 0xffffffff;
u32 var8006a808 = 0x00000001;
u32 var8006a80c = 0x00000008;
u32 var8006a810 = 0x0000000a;
u32 var8006a814 = 0x0000000b;
u32 var8006a818 = 0x00000007;
u32 var8006a81c = 0x00000059;
u32 var8006a820 = 0x0000000d;
u32 var8006a824 = 0x007f00ff;
u32 var8006a828 = 0x00000001;
u32 var8006a82c = 0x00000002;
u32 var8006a830 = 0xfffffe00;
u32 var8006a834 = 0x00000050;
u32 var8006a838 = 0x00000008;
u32 var8006a83c = 0x00000078;
u32 var8006a840 = 0x00000002;
u32 var8006a844 = 0xffffff00;
u32 var8006a848 = 0x00000014;
u32 var8006a84c = 0x00000008;
u32 var8006a850 = 0x00000078;
u32 var8006a854 = 0x00000002;
u32 var8006a858 = 0xffffff80;
u32 var8006a85c = 0x0000000a;
u32 var8006a860 = 0x00000008;
u32 var8006a864 = 0x00000028;
u32 var8006a868 = 0x00000002;
u32 var8006a86c = 0xfffffe00;
u32 var8006a870 = 0x00000028;
u32 var8006a874 = 0x00000008;
u32 var8006a878 = 0x0000003c;
u32 var8006a87c = 0x00000002;
u32 var8006a880 = 0xffffffc0;
u32 var8006a884 = 0x0000001e;
u32 var8006a888 = 0x00000008;
u32 var8006a88c = 0x00000078;
u32 var8006a890 = 0x0000000b;
u32 var8006a894 = 0x00000007;
u32 var8006a898 = 0x00000059;
u32 var8006a89c = 0x0000000d;
u32 var8006a8a0 = 0xff7f00ff;
u32 var8006a8a4 = 0x00000001;
u32 var8006a8a8 = 0x00000002;
u32 var8006a8ac = 0x00000200;
u32 var8006a8b0 = 0x00000050;
u32 var8006a8b4 = 0x00000008;
u32 var8006a8b8 = 0x00000078;
u32 var8006a8bc = 0x00000002;
u32 var8006a8c0 = 0x00000100;
u32 var8006a8c4 = 0x00000014;
u32 var8006a8c8 = 0x00000008;
u32 var8006a8cc = 0x00000078;
u32 var8006a8d0 = 0x00000002;
u32 var8006a8d4 = 0x00000080;
u32 var8006a8d8 = 0x0000000a;
u32 var8006a8dc = 0x00000008;
u32 var8006a8e0 = 0x00000028;
u32 var8006a8e4 = 0x00000002;
u32 var8006a8e8 = 0x00000200;
u32 var8006a8ec = 0x00000028;
u32 var8006a8f0 = 0x00000008;
u32 var8006a8f4 = 0x0000003c;
u32 var8006a8f8 = 0x00000002;
u32 var8006a8fc = 0x00000040;
u32 var8006a900 = 0x0000001e;
u32 var8006a904 = 0x00000008;
u32 var8006a908 = 0x00000078;
u32 var8006a90c = 0x0000000b;
u32 var8006a910 = 0x00000007;
u32 var8006a914 = 0x0000005a;
u32 var8006a918 = 0x0000000d;
u32 var8006a91c = 0xffffffff;
u32 var8006a920 = 0x00000001;
u32 var8006a924 = 0x00000008;
u32 var8006a928 = 0x0000000a;
u32 var8006a92c = 0x0000000b;
u32 var8006a930 = 0x00000007;
u32 var8006a934 = 0x0000005b;
u32 var8006a938 = 0x0000000d;
u32 var8006a93c = 0xffffffff;
u32 var8006a940 = 0x00000001;
u32 var8006a944 = 0x00000008;
u32 var8006a948 = 0x0000000a;
u32 var8006a94c = 0x0000000b;
u32 var8006a950 = 0x00000007;
u32 var8006a954 = 0x0000005c;
u32 var8006a958 = 0x0000000d;
u32 var8006a95c = 0xffffffff;
u32 var8006a960 = 0x00000001;
u32 var8006a964 = 0x00000008;
u32 var8006a968 = 0x0000000a;
u32 var8006a96c = 0x0000000b;
u32 var8006a970 = 0x0000000d;
u32 var8006a974 = 0x000000ff;
u32 var8006a978 = 0x00000001;
u32 var8006a97c = 0x00000007;
u32 var8006a980 = 0x0000005a;
u32 var8006a984 = 0x00000008;
u32 var8006a988 = 0x00000001;
u32 var8006a98c = 0x0000000d;
u32 var8006a990 = 0xffffffff;
u32 var8006a994 = 0x000000b4;
u32 var8006a998 = 0x00000008;
u32 var8006a99c = 0x00000168;
u32 var8006a9a0 = 0x0000000d;
u32 var8006a9a4 = 0x000000ff;
u32 var8006a9a8 = 0x0000001e;
u32 var8006a9ac = 0x00000008;
u32 var8006a9b0 = 0x0000001e;
u32 var8006a9b4 = 0x00000007;
u32 var8006a9b8 = 0x0000005b;
u32 var8006a9bc = 0x00000008;
u32 var8006a9c0 = 0x00000001;
u32 var8006a9c4 = 0x0000000d;
u32 var8006a9c8 = 0xffffffff;
u32 var8006a9cc = 0x000000b4;
u32 var8006a9d0 = 0x00000008;
u32 var8006a9d4 = 0x00000168;
u32 var8006a9d8 = 0x0000000d;
u32 var8006a9dc = 0x000000ff;
u32 var8006a9e0 = 0x0000001e;
u32 var8006a9e4 = 0x00000008;
u32 var8006a9e8 = 0x0000001e;
u32 var8006a9ec = 0x00000007;
u32 var8006a9f0 = 0x0000005c;
u32 var8006a9f4 = 0x00000008;
u32 var8006a9f8 = 0x00000001;
u32 var8006a9fc = 0x0000000d;
u32 var8006aa00 = 0xffffffff;
u32 var8006aa04 = 0x000000b4;
u32 var8006aa08 = 0x00000008;
u32 var8006aa0c = 0x00000168;
u32 var8006aa10 = 0x0000000d;
u32 var8006aa14 = 0x000000ff;
u32 var8006aa18 = 0x0000001d;
u32 var8006aa1c = 0x00000008;
u32 var8006aa20 = 0x0000001d;
u32 var8006aa24 = 0x0000000b;
u32 var8006aa28 = 0x00000007;
u32 var8006aa2c = 0x0000005d;
u32 var8006aa30 = 0x0000000d;
u32 var8006aa34 = 0xffffffff;
u32 var8006aa38 = 0x00000001;
u32 var8006aa3c = 0x00000008;
u32 var8006aa40 = 0x0000000a;
u32 var8006aa44 = 0x0000000b;
u32 var8006aa48 = 0x00000007;
u32 var8006aa4c = 0x0000005e;
u32 var8006aa50 = 0x0000000d;
u32 var8006aa54 = 0xffffffff;
u32 var8006aa58 = 0x00000001;
u32 var8006aa5c = 0x00000008;
u32 var8006aa60 = 0x0000000a;
u32 var8006aa64 = 0x0000000b;
u32 var8006aa68 = 0x00000007;
u32 var8006aa6c = 0x0000005f;
u32 var8006aa70 = 0x0000000d;
u32 var8006aa74 = 0xffffffff;
u32 var8006aa78 = 0x00000001;
u32 var8006aa7c = 0x00000008;
u32 var8006aa80 = 0x0000000a;
u32 var8006aa84 = 0x0000000b;
u32 var8006aa88 = 0x00000007;
u32 var8006aa8c = 0x00000000;
u32 var8006aa90 = 0x0000000d;
u32 var8006aa94 = 0x000000ff;
u32 var8006aa98 = 0x00000000;
u32 var8006aa9c = 0x0000000c;
u32 var8006aaa0 = 0x00000005;
u32 var8006aaa4 = 0x00000400;
u32 var8006aaa8 = 0x00000000;
u32 var8006aaac = 0x00000006;
u32 var8006aab0 = 0x00000400;
u32 var8006aab4 = 0x00000000;
u32 var8006aab8 = 0x00000008;
u32 var8006aabc = 0x00000001;
u32 var8006aac0 = 0x00000005;
u32 var8006aac4 = 0x00001000;
u32 var8006aac8 = 0x00000014;
u32 var8006aacc = 0x00000006;
u32 var8006aad0 = 0x00001000;
u32 var8006aad4 = 0x00000014;
u32 var8006aad8 = 0x00000008;
u32 var8006aadc = 0x00000014;
u32 var8006aae0 = 0x0000000b;
u32 var8006aae4 = 0x00000007;
u32 var8006aae8 = 0x00000000;
u32 var8006aaec = 0x00000001;
u32 var8006aaf0 = 0x00000400;
u32 var8006aaf4 = 0x00000014;
u32 var8006aaf8 = 0x00000008;
u32 var8006aafc = 0x00000014;
u32 var8006ab00 = 0x00000002;
u32 var8006ab04 = 0x00000400;
u32 var8006ab08 = 0x00000014;
u32 var8006ab0c = 0x0000000d;
u32 var8006ab10 = 0x000000ff;
u32 var8006ab14 = 0x00000014;
u32 var8006ab18 = 0x00000008;
u32 var8006ab1c = 0x00000014;
u32 var8006ab20 = 0x00000005;
u32 var8006ab24 = 0x00000200;
u32 var8006ab28 = 0x00000014;
u32 var8006ab2c = 0x00000006;
u32 var8006ab30 = 0x00000200;
u32 var8006ab34 = 0x00000014;
u32 var8006ab38 = 0x0000000d;
u32 var8006ab3c = 0xffffffff;
u32 var8006ab40 = 0x00000014;
u32 var8006ab44 = 0x00000008;
u32 var8006ab48 = 0x00000014;
u32 var8006ab4c = 0x00000005;
u32 var8006ab50 = 0x00000400;
u32 var8006ab54 = 0x00000014;
u32 var8006ab58 = 0x00000006;
u32 var8006ab5c = 0x00000400;
u32 var8006ab60 = 0x00000014;
u32 var8006ab64 = 0x00000008;
u32 var8006ab68 = 0x00000014;
u32 var8006ab6c = 0x0000000b;
u32 var8006ab70 = 0x00000000;
u32 var8006ab74 = 0x00000001;
u32 var8006ab78 = 0x00000003;
u32 var8006ab7c = 0x00000000;
u32 var8006ab80 = 0x00000000;
u32 var8006ab84 = 0x00000000;
u32 var8006ab88 = 0x00000000;
u32 var8006ab8c = 0x00000000;
u32 var8006ab90 = 0x00000000;
u32 var8006ab94 = 0x00000000;
u32 var8006ab98 = 0x00000000;
u32 var8006ab9c = 0x00000000;
u32 var8006aba0 = 0x00000000;
u32 var8006aba4 = 0x00000000;
u32 var8006aba8 = 0x00000000;
u32 var8006abac = 0x00000000;
u32 var8006abb0 = 0x00000000;
u32 var8006abb4 = 0x00000000;
u32 var8006abb8 = 0x00000000;
u32 var8006abbc = 0x00000000;
u32 var8006abc0 = 0x00000000;
u32 var8006abc4 = 0x00000000;
u32 var8006abc8 = 0x00000000;
u32 var8006abcc = 0x00000000;
u32 var8006abd0 = 0x00000000;
u32 var8006abd4 = 0x00000000;
u32 var8006abd8 = 0x00000000;
u32 var8006abdc = 0x00000000;
u32 var8006abe0 = 0x00000000;
u32 var8006abe4 = 0x00000000;
u32 var8006abe8 = 0x00000000;
u32 var8006abec = 0x00000000;
u32 var8006abf0 = 0x00000000;
u32 var8006abf4 = 0x00000000;
u32 var8006abf8 = 0x00000000;
u32 var8006abfc = 0x00000000;
u32 var8006ac00 = 0x00000000;
u32 var8006ac04 = 0x00000000;
u32 var8006ac08 = 0x01000007;
u32 var8006ac0c = 0x0000ffff;
u32 var8006ac10 = 0x00000001;
u32 var8006ac14 = 0x00000000;
u32 var8006ac18 = 0x00000000;
u32 var8006ac1c = 0x00000000;
u32 var8006ac20 = 0x00000000;
u32 var8006ac24 = 0x3f800000;
u32 var8006ac28 = 0x00000000;
u32 var8006ac2c = 0x00000000;
u32 var8006ac30 = 0x00000000;
u32 var8006ac34 = 0x3f800000;
u32 var8006ac38 = 0x00000000;
u32 var8006ac3c = 0x00000000;
u32 var8006ac40 = 0x00000000;
u32 var8006ac44 = 0x3f800000;
u32 var8006ac48 = 0x00000000;
u32 var8006ac4c = 0x00000000;
u32 var8006ac50 = 0x00000000;
u32 var8006ac54 = 0x000003e8;
u32 var8006ac58 = 0xffffff00;
u32 var8006ac5c = 0xffffff00;
u32 var8006ac60 = 0x0fff0000;
u8 g_CiTaggedTerminals[] = { 0x0e, 0x0f, 0x10, 0x47, 0x46, 0x45, 0x1b, 0x7f };
u32 var8006ac6c = 0x01000011;
u32 var8006ac70 = 0x00000000;
u32 var8006ac74 = 0x00004000;
u32 var8006ac78 = 0x00000000;
u32 var8006ac7c = 0x00000000;
u32 var8006ac80 = 0x00000000;
u32 var8006ac84 = 0x00000000;
u32 var8006ac88 = 0x3f800000;
u32 var8006ac8c = 0x00000000;
u32 var8006ac90 = 0x00000000;
u32 var8006ac94 = 0x00000000;
u32 var8006ac98 = 0x3f800000;
u32 var8006ac9c = 0x00000000;
u32 var8006aca0 = 0x00000000;
u32 var8006aca4 = 0x00000000;
u32 var8006aca8 = 0x3f800000;
u32 var8006acac = 0x00000000;
u32 var8006acb0 = 0x00000000;
u32 var8006acb4 = 0x00000000;
u32 var8006acb8 = 0x000003e8;
u32 var8006acbc = 0xffffff00;
u32 var8006acc0 = 0xffffff00;
u32 var8006acc4 = 0x0fff0000;
u32 var8006acc8 = 0x0100000d;
u32 var8006accc = 0x00000001;
u32 var8006acd0 = 0x00000000;
u32 var8006acd4 = 0x00000000;
u32 var8006acd8 = 0x00000000;
u32 var8006acdc = 0x00000000;
u32 var8006ace0 = 0x00000000;
u32 var8006ace4 = 0x3f800000;
u32 var8006ace8 = 0x00000000;
u32 var8006acec = 0x00000000;
u32 var8006acf0 = 0x00000000;
u32 var8006acf4 = 0x3f800000;
u32 var8006acf8 = 0x00000000;
u32 var8006acfc = 0x00000000;
u32 var8006ad00 = 0x00000000;
u32 var8006ad04 = 0x3f800000;
u32 var8006ad08 = 0x00000000;
u32 var8006ad0c = 0x00000000;
u32 var8006ad10 = 0x00000000;
u32 var8006ad14 = 0x000003e8;
u32 var8006ad18 = 0xffffff00;
u32 var8006ad1c = 0xffffff00;
u32 var8006ad20 = 0x0fff0000;
u32 var8006ad24 = 0x01000008;
u32 var8006ad28 = 0x0000ffff;
u32 var8006ad2c = 0x00000001;
u32 var8006ad30 = 0x00000000;
u32 var8006ad34 = 0x00000000;
u32 var8006ad38 = 0x00000000;
u32 var8006ad3c = 0x00000000;
u32 var8006ad40 = 0x3f800000;
u32 var8006ad44 = 0x00000000;
u32 var8006ad48 = 0x00000000;
u32 var8006ad4c = 0x00000000;
u32 var8006ad50 = 0x3f800000;
u32 var8006ad54 = 0x00000000;
u32 var8006ad58 = 0x00000000;
u32 var8006ad5c = 0x00000000;
u32 var8006ad60 = 0x3f800000;
u32 var8006ad64 = 0x00000000;
u32 var8006ad68 = 0x00000000;
u32 var8006ad6c = 0x00000000;
u32 var8006ad70 = 0x000003e8;
u32 var8006ad74 = 0xffffff00;
u32 var8006ad78 = 0xffffff00;
u32 var8006ad7c = 0x0fff0000;
u32 var8006ad80 = 0x00000000;
u32 var8006ad84 = 0x00ffffff;
u32 var8006ad88 = 0x00000000;
u32 var8006ad8c = 0x00000000;
u32 var8006ad90 = 0x01000008;
u32 var8006ad94 = 0x00000000;
u32 var8006ad98 = 0x00004001;
u32 var8006ad9c = 0x00000000;
u32 var8006ada0 = 0x00000000;
u32 var8006ada4 = 0x00000000;
u32 var8006ada8 = 0x00000000;
u32 var8006adac = 0x3f800000;
u32 var8006adb0 = 0x00000000;
u32 var8006adb4 = 0x00000000;
u32 var8006adb8 = 0x00000000;
u32 var8006adbc = 0x3f800000;
u32 var8006adc0 = 0x00000000;
u32 var8006adc4 = 0x00000000;
u32 var8006adc8 = 0x00000000;
u32 var8006adcc = 0x3f800000;
u32 var8006add0 = 0x00000000;
u32 var8006add4 = 0x00000000;
u32 var8006add8 = 0x00000000;
u32 var8006addc = 0x000003e8;
u32 var8006ade0 = 0xffffff00;
u32 var8006ade4 = 0xffffff00;
u32 var8006ade8 = 0x0fff0000;
u32 var8006adec = 0x00000000;
u32 var8006adf0 = 0x00ffffff;
u32 var8006adf4 = 0x00000000;
u32 var8006adf8 = 0x00000000;
u32 var8006adfc = 0x00000000;
u32 var8006ae00 = 0x00000000;
u32 var8006ae04 = 0x00000000;
u32 var8006ae08 = 0x00000000;
u32 var8006ae0c = 0x00000000;
u32 var8006ae10 = 0x00000000;
u32 var8006ae14 = 0x00000000;
s8 var8006ae18 = 0;
s8 var8006ae1c = 0;
s8 var8006ae20 = 0;
s8 var8006ae24 = 0;
s8 var8006ae28 = 0;
u32 var8006ae2c = 0x00000000;
u32 var8006ae30 = 0x00000000;
u32 var8006ae34 = 0x00000000;
u32 var8006ae38 = 0x00000000;
u32 var8006ae3c = 0x00000000;
u32 var8006ae40 = 0x00000000;
u32 var8006ae44 = 0x00000000;
u32 var8006ae48 = 0x00000001;
u32 var8006ae4c = 0x00000000;
u32 var8006ae50 = 0xffff0000;
u32 var8006ae54 = 0x000003e7;
u32 var8006ae58 = 0x00000000;
u32 var8006ae5c = 0x80b080b1;
u32 var8006ae60 = 0x80b280b3;
u32 var8006ae64 = 0x80b480b5;
u32 var8006ae68 = 0x00000000;
u32 var8006ae6c = 0x00000000;
s32 var8006ae70 = -1;
u32 var8006ae74 = 0x00000000;
u32 var8006ae78 = 0x00000000;
u32 var8006ae7c = 0x00000000;
u32 var8006ae80 = 0x00000000;
u32 var8006ae84 = 0x00000000;
u32 var8006ae88 = 0x00000000;
u32 var8006ae8c = 0x00000000;
u32 var8006ae90 = 0x80007eba;
u32 var8006ae94 = 0x7d747c2d;
u32 var8006ae98 = 0x7ae779a0;
u32 var8006ae9c = 0x78597711;
u32 var8006aea0 = 0x75c97480;
u32 var8006aea4 = 0x733771ec;
u32 var8006aea8 = 0x70a16f55;
u32 var8006aeac = 0x6e076cb8;
u32 var8006aeb0 = 0x6b686a17;
u32 var8006aeb4 = 0x68c46770;
u32 var8006aeb8 = 0x661a64c1;
u32 var8006aebc = 0x6367620b;
u32 var8006aec0 = 0x60ad5f4c;
u32 var8006aec4 = 0x5de95c83;
u32 var8006aec8 = 0x5b1a59ae;
u32 var8006aecc = 0x583e56cb;
u32 var8006aed0 = 0x555553db;
u32 var8006aed4 = 0x525c50d9;
u32 var8006aed8 = 0x4f514dc5;
u32 var8006aedc = 0x4c324a9a;
u32 var8006aee0 = 0x48fc4757;
u32 var8006aee4 = 0x45ab43f7;
u32 var8006aee8 = 0x423a4075;
u32 var8006aeec = 0x3ea53ccb;
u32 var8006aef0 = 0x3ae538f1;
u32 var8006aef4 = 0x36ef34dc;
u32 var8006aef8 = 0x32b7307d;
u32 var8006aefc = 0x2e2b2bbd;
u32 var8006af00 = 0x292e2678;
u32 var8006af04 = 0x2391206c;
u32 var8006af08 = 0x1cf60000;
u32 var8006af0c = 0x1cf61cbb;
u32 var8006af10 = 0x1c801c45;
u32 var8006af14 = 0x1c081bcc;
u32 var8006af18 = 0x1b8f1b51;
u32 var8006af1c = 0x1b131ad4;
u32 var8006af20 = 0x1a951a55;
u32 var8006af24 = 0x1a1419d3;
u32 var8006af28 = 0x1992194f;
u32 var8006af2c = 0x190c18c9;
u32 var8006af30 = 0x1884183f;
u32 var8006af34 = 0x17f917b3;
u32 var8006af38 = 0x176b1723;
u32 var8006af3c = 0x16da1690;
u32 var8006af40 = 0x164515f9;
u32 var8006af44 = 0x15ac155e;
u32 var8006af48 = 0x150f14be;
u32 var8006af4c = 0x146d141a;
u32 var8006af50 = 0x13c61370;
u32 var8006af54 = 0x131912c1;
u32 var8006af58 = 0x1267120b;
u32 var8006af5c = 0x11ad114e;
u32 var8006af60 = 0x10ec1088;
u32 var8006af64 = 0x10220fb9;
u32 var8006af68 = 0x0f4d0ede;
u32 var8006af6c = 0x0e6c0df7;
u32 var8006af70 = 0x0d7d0d00;
u32 var8006af74 = 0x0c7d0bf4;
u32 var8006af78 = 0x0b660ad0;
u32 var8006af7c = 0x0a310989;
u32 var8006af80 = 0x08d3080e;
u32 var8006af84 = 0x0734063d;
u32 var8006af88 = 0x0518039a;
u32 var8006af8c = 0x039a031e;
u32 var8006af90 = 0x028c01cd;
u32 var8006af94 = 0x00000000;
u32 var8006af98 = 0x00000000;
u32 var8006af9c = 0x00000000;
u32 var8006afa0 = 0x00000001;
u32 var8006afa4 = 0x00000002;
u32 var8006afa8 = 0x00000000;
u32 var8006afac = 0x00000000;
