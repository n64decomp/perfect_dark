#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/chr/chrai.h"
#include "game/chr/chraicommands.h"
#include "game/data/ailists.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "types.h"

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
	/*0x000d*/ aiBeSurprisedOneHand,
	/*0x000e*/ aiBeSurprisedLookAround,
	/*0x000f*/ aiTrySidestep,
	/*0x0010*/ aiTryJumpOut,
	/*0x0011*/ aiTryRunSideways,
	/*0x0012*/ aiTryAttackWalk,
	/*0x0013*/ aiTryAttackRun,
	/*0x0014*/ aiTryAttackRoll,
	/*0x0015*/ aiTryAttackStand,
	/*0x0016*/ aiTryAttackKneel,
	/*0x0017*/ aiTryModifyAttack,
	/*0x0018*/ aiFaceEntity,
	/*0x0019*/ ai0019,
	/*0x001a*/ ai001a,
	/*0x001b*/ aiConsiderGrenadeThrow,
	/*0x001c*/ aiDropItem,
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
	/*0x0027*/ aiTryStartAlarm,
	/*0x0028*/ aiActivateAlarm,
	/*0x0029*/ aiDeactivateAlarm,
	/*0x002a*/ aiTryRunFromTarget,
	/*0x002b*/ aiTryJogToTargetProp,
	/*0x002c*/ aiTryWalkToTargetProp,
	/*0x002d*/ aiTryRunToTargetProp,
	/*0x002e*/ ai002e,
	/*0x002f*/ aiTryJogToChr,
	/*0x0030*/ aiTryWalkToChr,
	/*0x0031*/ aiTryRunToChr,
	/*0x0032*/ aiIfStopped,
	/*0x0033*/ aiIfChrDead,
	/*0x0034*/ aiIfChrDeathAnimationFinished,
	/*0x0035*/ aiIfTargetInSight,
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
	/*0x00ff*/ aiBeSurprisedSurrender,
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
	/*0x016e*/ aiDamagePlayer,
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
	/*0x017b*/ aiIfChrKnockedOut,
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
	/*0x01ba*/ aiTryAttackLie,
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

s32 chraiGetListIdByList(u8 *ailist, bool *is_global)
{
	s32 i;

	if (g_StageSetup.ailists) {
		for (i = 0; g_StageSetup.ailists[i].list != NULL; i++) {
			if (g_StageSetup.ailists[i].list == ailist) {
				*is_global = false;
				return g_StageSetup.ailists[i].id;
			}
		}
	}

	for (i = 0; g_GlobalAilists[i].list != NULL; i++) {
		if (g_GlobalAilists[i].list == ailist) {
			*is_global = true;
			return g_GlobalAilists[i].id;
		}
	}

	return -1;
}

u32 chraiGoToLabel(u8 *ailist, u32 aioffset, u8 label)
{
	do {
		u8 *cmd = aioffset + ailist;
		u32 type = (cmd[0] << 8) + cmd[1];

		if (type == CMD_LABEL) {
			if (label == cmd[2]) {
				return aioffset;
			}
		} else if (type == CMD_END) {
			return 0;
		}

		aioffset += chraiGetCommandLength(ailist, aioffset);
	} while (true);
}

void chraiExecute(void *entity, s32 proptype)
{
	g_Vars.chrdata = NULL;
	g_Vars.truck = NULL;
	g_Vars.heli = NULL;
	g_Vars.hovercar = NULL;
	g_Vars.ailist = NULL;
	g_Vars.aioffset = 0;

	if (proptype == PROPTYPE_CHR) {
		g_Vars.chrdata = entity;
	} else if (proptype == PROPTYPE_OBJ) {
		struct defaultobj *obj = entity;

		if (obj->type == OBJTYPE_TRUCK) {
			g_Vars.truck = entity;
		} else if (obj->type == OBJTYPE_HELI) {
			g_Vars.heli = entity;
		} else if (obj->type == OBJTYPE_HOVERCAR || obj->type == OBJTYPE_CHOPPER) {
			g_Vars.hovercar = entity;
		}
	}

	if (g_Vars.chrdata) {
		g_Vars.ailist = g_Vars.chrdata->ailist;
		g_Vars.aioffset = g_Vars.chrdata->aioffset;
	} else if (g_Vars.truck) {
		g_Vars.ailist = g_Vars.truck->ailist;
		g_Vars.aioffset = g_Vars.truck->aioffset;
	} else if (g_Vars.heli) {
		g_Vars.ailist = g_Vars.heli->ailist;
		g_Vars.aioffset = g_Vars.heli->aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.ailist = g_Vars.hovercar->ailist;
		g_Vars.aioffset = g_Vars.hovercar->aioffset;
	}

	if (g_Vars.ailist) {
		if (g_Vars.chrdata) {
			chrAddTargetToBdlist(g_Vars.chrdata);
		}

		// Check if the ailist should be switched to a different one
		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_00200000)) {
			u32 animnum = animGetId(g_Vars.chrdata->animdata);
			if (g_Vars.chrdata->aishotlist >= 0
					&& g_Vars.chrdata->cshield <= 0
					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gunprop != NULL)
					&& animnum != ANIM_SNIPING_0269
					&& animnum != ANIM_SNIPING_026B
					&& animnum != ANIM_SNIPING_026A) {
				// Set shot list
				g_Vars.chrdata->chrflags &= ~CHRCFLAG_00200000;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishotlist);
				g_Vars.aioffset = 0;
			}
		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_CONSIDER_DODGE)) {
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_CONSIDER_DODGE;

			if (g_Vars.chrdata->aishootingatmelist >= 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->dodgerating > (u32)random() % 100
					&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1) == 0
					&& chrHasFlag(g_Vars.chrdata, CHRFLAG0_AIVSAI, BANK_0) == 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->actiontype != ACT_ATTACK
					&& g_Vars.chrdata->actiontype != ACT_ATTACKWALK
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH
					&& g_Vars.chrdata->actiontype != ACT_PREARGH
					&& g_Vars.chrdata->actiontype != ACT_ATTACKROLL) {
				// Set shooting at me list
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishootingatmelist);
				g_Vars.aioffset = 0;
				g_Vars.chrdata->dodgerating = 0;
			} else {
				// Increase dodge rating
				g_Vars.chrdata->dodgerating *= 2;

				if (g_Vars.chrdata->dodgerating > g_Vars.chrdata->maxdodgerating) {
					g_Vars.chrdata->dodgerating = g_Vars.chrdata->maxdodgerating;
				}
			}
		} else if (g_Vars.chrdata
				&& g_Vars.chrdata->darkroomthing
				&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1) == 0
				&& ailistFindById(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
				&& g_Vars.stagenum != STAGE_CRASHSITE) {
			g_Vars.chrdata->darkroomthing = 0;

			if (g_Vars.chrdata->aidarkroomlist >= 0
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH) {
				// Set darkroom list
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1);
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_10000000, BANK_1);
				g_Vars.chrdata->alertness = 0;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aidarkroomlist);
				g_Vars.aioffset = 0;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		while (g_Vars.ailist) {
			u8 *cmd = g_Vars.aioffset + g_Vars.ailist;
			s32 type = (cmd[0] << 8) + cmd[1];

			if (type >= 0 && type <= 0x1e0) {
				if (g_CommandPointers[type]()) {
					break;
				}
			} else {
				// This is attempting to handle situations where the command
				// type is invalid by passing over them and continuing
				// execution. This would very likely result in a crash though.
				g_Vars.aioffset += chraiGetCommandLength(g_Vars.ailist, g_Vars.aioffset);
			}
		}
	}
}

u32 chraiGetCommandLength(u8 *ailist, u32 aioffset)
{
	u8 *cmd = aioffset + ailist;
	s32 type = (cmd[0] << 8) + cmd[1];

	if (type == CMD_PRINT) {
		u32 prop = aioffset + 2;

		while (ailist[prop] != 0) {
			++prop;
		}

		return (prop - aioffset) + 1;
	}

	if (type >= 0 && type < NUM_AICOMMANDS) {
		return g_CommandLengths[type];
	}

	return 1;
}
