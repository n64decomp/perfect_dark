#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/camdraw.h"
#include "game/timing.h"
#include "game/game_173a00.h"
#include "game/utils.h"
#include "game/game_177e00.h"
#include "game/game_179060.h"
#include "game/game_17f930.h"
#include "game/game_1a3340.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

extern void *_file_bg_sev_seg;
extern void *_file_bg_silo_seg;
extern void *_file_bg_stat_seg;
extern void *_file_bg_arec_seg;
extern void *_file_bg_arch_seg;
extern void *_file_bg_tra_seg;
extern void *_file_bg_dest_seg;
extern void *_file_bg_sevb_seg;
extern void *_file_bg_azt_seg;
extern void *_file_bg_pete_seg;
extern void *_file_bg_depo_seg;
extern void *_file_bg_ref_seg;
extern void *_file_bg_cryp_seg;
extern void *_file_bg_dam_seg;
extern void *_file_bg_ark_seg;
extern void *_file_bg_run_seg;
extern void *_file_bg_sevx_seg;
extern void *_file_bg_jun_seg;
extern void *_file_bg_dish_seg;
extern void *_file_bg_cave_seg;
extern void *_file_bg_cat_seg;
extern void *_file_bg_crad_seg;
extern void *_file_bg_sho_seg;
extern void *_file_bg_eld_seg;
extern void *_file_bg_imp_seg;
extern void *_file_bg_ash_seg;
extern void *_file_bg_lue_seg;
extern void *_file_bg_ame_seg;
extern void *_file_bg_rit_seg;
extern void *_file_bg_oat_seg;
extern void *_file_bg_ear_seg;
extern void *_file_bg_lee_seg;
extern void *_file_bg_lip_seg;
extern void *_file_bg_len_seg;
extern void *_file_bg_wax_seg;
extern void *_file_bg_pam_seg;
extern void *_file_bg_uff_seg;
extern void *_file_bg_old_seg;
extern void *_file_bg_ate_seg;
extern void *_file_bg_lam_seg;
extern void *_file_bg_mp1_seg;
extern void *_file_bg_mp2_seg;
extern void *_file_bg_mp3_seg;
extern void *_file_bg_mp4_seg;
extern void *_file_bg_mp5_seg;
extern void *_file_bg_mp6_seg;
extern void *_file_bg_mp7_seg;
extern void *_file_bg_mp8_seg;
extern void *_file_bg_mp9_seg;
extern void *_file_bg_mp10_seg;
extern void *_file_bg_mp11_seg;
extern void *_file_bg_mp12_seg;
extern void *_file_bg_mp13_seg;
extern void *_file_bg_mp14_seg;
extern void *_file_bg_mp15_seg;
extern void *_file_bg_mp16_seg;
extern void *_file_bg_mp17_seg;
extern void *_file_bg_mp18_seg;
extern void *_file_bg_mp19_seg;
extern void *_file_bg_mp20_seg;
extern void *_file_ob_mid_seg;
extern void *_file_Ca51guardZ;
extern void *_file_Carea51guardZ;
extern void *_file_CcarringtonZ;
extern void *_file_CcassandraZ;
extern void *_file_Cdark_combatZ;
extern void *_file_Cdark_frockZ;
extern void *_file_Cdark_trenchZ;
extern void *_file_CddshockZ;
extern void *_file_Cdd_secguardZ;
extern void *_file_CdjbondZ;
extern void *_file_CdrcarrollZ;
extern void *_file_CelvisZ;
extern void *_file_Celvis1Z;
extern void *_file_CeyespyZ;
extern void *_file_Cfem_guardZ;
extern void *_file_ClabtechZ;
extern void *_file_CmrblondeZ;
extern void *_file_CofficeworkerZ;
extern void *_file_Cofficeworker2Z;
extern void *_file_CoverallZ;
extern void *_file_CsecretaryZ;
extern void *_file_CskedarZ;
extern void *_file_CstripesZ;
extern void *_file_CtestchrZ;
extern void *_file_CthekingZ;
extern void *_file_CtrentZ;
extern void *_file_GcartblueZ;
extern void *_file_GcartridgeZ;
extern void *_file_GcartrifleZ;
extern void *_file_GcartshellZ;
extern void *_file_GjoypadZ;
extern void *_file_Pa51_crate1Z;
extern void *_file_Pa51_crate2Z;
extern void *_file_Pa51_crate3Z;
extern void *_file_Pa51_exp1Z;
extern void *_file_Pa51_exp2Z;
extern void *_file_Pa51_horiz_door_botZ;
extern void *_file_Pa51_horiz_door_glZ;
extern void *_file_Pa51_horiz_door_secretZ;
extern void *_file_Pa51_horiz_door_topZ;
extern void *_file_Pa51_lift_controlZ;
extern void *_file_Pa51_lift_hangarZ;
extern void *_file_Pa51_lift_storeZ;
extern void *_file_Pa51_lift_thinwallZ;
extern void *_file_Pa51_unexp1Z;
extern void *_file_Pa51_unexp2Z;
extern void *_file_Pa51_unexp3Z;
extern void *_file_Pa51_vert_door_leftZ;
extern void *_file_Pa51_vert_door_rightZ;
extern void *_file_Pa51_vert_door_stZ;
extern void *_file_Pa51boardZ;
extern void *_file_Pa51chairZ;
extern void *_file_Pa51deskentZ;
extern void *_file_Pa51divideZ;
extern void *_file_Pa51screenZ;
extern void *_file_Pa51tableZ;
extern void *_file_Pa51trolleyZ;
extern void *_file_Pa51wastebinZ;
extern void *_file_Paivillabot1Z;
extern void *_file_Paivillabot2Z;
extern void *_file_Paivillabot3Z;
extern void *_file_Paivilladoor1Z;
extern void *_file_Paivilladoor2aZ;
extern void *_file_Paivilladoor4Z;
extern void *_file_PaivillawindmillZ;
extern void *_file_Pal_airlockZ;
extern void *_file_Pal_dockliftZ;
extern void *_file_Paldoor_lZ;
extern void *_file_Paldoor_rZ;
extern void *_file_Pborg_crateZ;
extern void *_file_PcaseZ;
extern void *_file_Pch_shutter1Z;
extern void *_file_PchrbriefcaseZ;
extern void *_file_PchrbugZ;
extern void *_file_PchrdatathiefZ;
extern void *_file_Pcryptdoor1bZ;
extern void *_file_Pdd_ac_expZ;
extern void *_file_Pdd_ac_unexpZ;
extern void *_file_Pdd_acbot_expZ;
extern void *_file_Pdd_acbot_unexpZ;
extern void *_file_Pdd_bannerZ;
extern void *_file_Pdd_chairZ;
extern void *_file_Pdd_decodoorZ;
extern void *_file_Pdd_deskZ;
extern void *_file_Pdd_fanroofZ;
extern void *_file_Pdd_fanwallZ;
extern void *_file_Pdd_hovcabZ;
extern void *_file_Pdd_hovcarZ;
extern void *_file_Pdd_hovcopZ;
extern void *_file_Pdd_hovercopterZ;
extern void *_file_Pdd_hovmotoZ;
extern void *_file_Pdd_hovtruckZ;
extern void *_file_Pdd_lab_cautionZ;
extern void *_file_Pdd_lab_cautiontopZ;
extern void *_file_Pdd_lab_door_bsZ;
extern void *_file_Pdd_lab_door_secZ;
extern void *_file_Pdd_lab_door_windZ;
extern void *_file_Pdd_lab_hazardZ;
extern void *_file_Pdd_lab_restrictedZ;
extern void *_file_Pdd_lab_sector2botZ;
extern void *_file_Pdd_lab_sector2topZ;
extern void *_file_Pdd_lab_sector3Z;
extern void *_file_Pdd_lab_sector3topZ;
extern void *_file_Pdd_lab_sector3windZ;
extern void *_file_Pdd_lab_sector4topZ;
extern void *_file_Pdd_liftdoorZ;
extern void *_file_Pdd_liftrZ;
extern void *_file_Pdd_officedoorZ;
extern void *_file_Pdd_plantrubberZ;
extern void *_file_Pdd_plantspiderZ;
extern void *_file_Pdd_plantspikeZ;
extern void *_file_Pdd_redarmZ;
extern void *_file_Pdd_redsofaZ;
extern void *_file_Pdd_secretdoorZ;
extern void *_file_Pdd_secretdoor2Z;
extern void *_file_Pdd_servicedoorZ;
extern void *_file_Pdd_stonedeskZ;
extern void *_file_Pdd_vertblindZ;
extern void *_file_Pdd_winddoorZ;
extern void *_file_Pdd_windowZ;
extern void *_file_PddjumpshipZ;
extern void *_file_Pdoor1a_G5Z;
extern void *_file_Pdoor1atri_G5Z;
extern void *_file_Pdoor1b_G5Z;
extern void *_file_Pdoor2_G5Z;
extern void *_file_Pdoor2a_G5Z;
extern void *_file_Pdoor4a_G5Z;
extern void *_file_Pdoor4b_G5Z;
extern void *_file_Pdoor_rollertrainZ;
extern void *_file_PdoorconsoleZ;
extern void *_file_Pdr_caroll_doorZ;
extern void *_file_Pdr_caroll_door_baseZ;
extern void *_file_Pdr_caroll_door_bleftZ;
extern void *_file_Pdr_caroll_door_bmainZ;
extern void *_file_Pdr_caroll_door_brightZ;
extern void *_file_Pdr_caroll_door_leftZ;
extern void *_file_Pdr_caroll_door_mainZ;
extern void *_file_Pdr_caroll_door_rightZ;
extern void *_file_PdropshipZ;
extern void *_file_PdumpsterZ;
extern void *_file_PexplosionbitZ;
extern void *_file_PflagZ;
extern void *_file_Pg5_escdoordownZ;
extern void *_file_Pg5_escdoordownboomZ;
extern void *_file_Pg5_escdoorupZ;
extern void *_file_Pg5_escdoorupboomZ;
extern void *_file_Pg5_mainframeZ;
extern void *_file_Pg5safedoorZ;
extern void *_file_Pg5carliftdoorZ;
extern void *_file_PgoldeneyelogoZ;
extern void *_file_PhooverbotZ;
extern void *_file_PhovbikeZ;
extern void *_file_PhoverbedZ;
extern void *_file_Phovercrate1Z;
extern void *_file_PlasdoorZ;
extern void *_file_PmarkerZ;
extern void *_file_Pmedlabwin1Z;
extern void *_file_Pmedlabwin2Z;
extern void *_file_PmodemboxZ;
extern void *_file_PnintendologoZ;
extern void *_file_Pnlogo2Z;
extern void *_file_Pnlogo3Z;
extern void *_file_PnlogoZ;
extern void *_file_Ppc1Z;
extern void *_file_PpdfourZ;
extern void *_file_PpdoneZ;
extern void *_file_PpdthreeZ;
extern void *_file_PpdtwoZ;
extern void *_file_PperfectdarkZ;
extern void *_file_PpolicecarZ;
extern void *_file_PravineliftZ;
extern void *_file_PropeZ;
extern void *_file_Psk_cryopod1_botZ;
extern void *_file_Psk_cryopod1_topZ;
extern void *_file_Psk_door1Z;
extern void *_file_Psk_fighter1Z;
extern void *_file_Psk_hangardoor_botZ;
extern void *_file_Psk_hangardoor_topZ;
extern void *_file_Psk_ship_door1Z;
extern void *_file_Psk_ship_holo1Z;
extern void *_file_Psk_ship_holo2Z;
extern void *_file_Psk_ship_hulldoor1Z;
extern void *_file_Psk_ship_hulldoor2Z;
extern void *_file_Psk_ship_hulldoor3Z;
extern void *_file_Psk_ship_hulldoor4Z;
extern void *_file_Psk_under_generatorZ;
extern void *_file_Psk_under_transZ;
extern void *_file_Pskcrev_exp1Z;
extern void *_file_Pskcrev_unexp1Z;
extern void *_file_Psktnl_exp1Z;
extern void *_file_Psktnl_unexp1Z;
extern void *_file_PtaxicabZ;
extern void *_file_PtesterbotZ;
extern void *_file_PtestobjZ;
extern void *_file_PtvscreenZ;
extern void *_file_PwindowZ;
extern void *_file_Ump_setupameZ;
extern void *_file_Ump_setuparchZ;
extern void *_file_Ump_setuparecZ;
extern void *_file_Ump_setuparkZ;
extern void *_file_Ump_setupashZ;
extern void *_file_Ump_setupaztZ;
extern void *_file_Ump_setupcatZ;
extern void *_file_Ump_setupcaveZ;
extern void *_file_Ump_setupcradZ;
extern void *_file_Ump_setupcrypZ;
extern void *_file_Ump_setupdamZ;
extern void *_file_Ump_setupdepoZ;
extern void *_file_Ump_setupdestZ;
extern void *_file_Ump_setupdishZ;
extern void *_file_Ump_setupearZ;
extern void *_file_Ump_setupeldZ;
extern void *_file_Ump_setupimpZ;
extern void *_file_Ump_setupjunZ;
extern void *_file_Ump_setupleeZ;
extern void *_file_Ump_setuplenZ;
extern void *_file_Ump_setuplipZ;
extern void *_file_Ump_setuplueZ;
extern void *_file_Ump_setupoatZ;
extern void *_file_Ump_setuppamZ;
extern void *_file_Ump_setuppeteZ;
extern void *_file_Ump_setuprefZ;
extern void *_file_Ump_setupritZ;
extern void *_file_Ump_setuprunZ;
extern void *_file_Ump_setupsevZ;
extern void *_file_Ump_setupsevbZ;
extern void *_file_Ump_setupsevxZ;
extern void *_file_Ump_setupshoZ;
extern void *_file_Ump_setupsiloZ;
extern void *_file_Ump_setupstatZ;
extern void *_file_Ump_setuptraZ;
extern void *_file_Ump_setupwaxZ;
extern void *_file_UsetupameZ;
extern void *_file_UsetuparchZ;
extern void *_file_UsetuparecZ;
extern void *_file_UsetuparkZ;
extern void *_file_UsetupashZ;
extern void *_file_UsetupaztZ;
extern void *_file_UsetupcatZ;
extern void *_file_UsetupcaveZ;
extern void *_file_UsetupcradZ;
extern void *_file_UsetupcrypZ;
extern void *_file_UsetupdamZ;
extern void *_file_UsetupdepoZ;
extern void *_file_UsetupdestZ;
extern void *_file_UsetupdishZ;
extern void *_file_UsetupearZ;
extern void *_file_UsetupeldZ;
extern void *_file_UsetupimpZ;
extern void *_file_UsetupjunZ;
extern void *_file_UsetupleeZ;
extern void *_file_UsetuplenZ;
extern void *_file_UsetuplipZ;
extern void *_file_UsetuplueZ;
extern void *_file_UsetupoatZ;
extern void *_file_UsetuppamZ;
extern void *_file_UsetuppeteZ;
extern void *_file_UsetuprefZ;
extern void *_file_UsetupritZ;
extern void *_file_UsetuprunZ;
extern void *_file_UsetupsevZ;
extern void *_file_UsetupsevbZ;
extern void *_file_UsetupsevxZ;
extern void *_file_UsetupsevxbZ;
extern void *_file_UsetupshoZ;
extern void *_file_UsetupsiloZ;
extern void *_file_UsetupstatZ;
extern void *_file_UsetuptraZ;
extern void *_file_UsetupwaxZ;
extern void *_file_bg_ame_padsZ;
extern void *_file_bg_ame_tilesZ;
extern void *_file_bg_arch_padsZ;
extern void *_file_bg_arch_tilesZ;
extern void *_file_bg_arec_padsZ;
extern void *_file_bg_arec_tilesZ;
extern void *_file_bg_ark_padsZ;
extern void *_file_bg_ark_tilesZ;
extern void *_file_bg_ash_padsZ;
extern void *_file_bg_ash_tilesZ;
extern void *_file_bg_azt_padsZ;
extern void *_file_bg_azt_tilesZ;
extern void *_file_bg_cat_padsZ;
extern void *_file_bg_cat_tilesZ;
extern void *_file_bg_cave_padsZ;
extern void *_file_bg_cave_tilesZ;
extern void *_file_bg_crad_padsZ;
extern void *_file_bg_crad_tilesZ;
extern void *_file_bg_cryp_padsZ;
extern void *_file_bg_cryp_tilesZ;
extern void *_file_bg_dam_padsZ;
extern void *_file_bg_dam_tilesZ;
extern void *_file_bg_depo_padsZ;
extern void *_file_bg_depo_tilesZ;
extern void *_file_bg_dest_padsZ;
extern void *_file_bg_dest_tilesZ;
extern void *_file_bg_dish_padsZ;
extern void *_file_bg_dish_tilesZ;
extern void *_file_bg_ear_padsZ;
extern void *_file_bg_ear_tilesZ;
extern void *_file_bg_eld_padsZ;
extern void *_file_bg_eld_tilesZ;
extern void *_file_bg_imp_padsZ;
extern void *_file_bg_imp_tilesZ;
extern void *_file_bg_jun_padsZ;
extern void *_file_bg_jun_tilesZ;
extern void *_file_bg_lee_padsZ;
extern void *_file_bg_lee_tilesZ;
extern void *_file_bg_len_padsZ;
extern void *_file_bg_len_tilesZ;
extern void *_file_bg_lip_padsZ;
extern void *_file_bg_lip_tilesZ;
extern void *_file_bg_lue_padsZ;
extern void *_file_bg_lue_tilesZ;
extern void *_file_bg_oat_padsZ;
extern void *_file_bg_oat_tilesZ;
extern void *_file_bg_pam_padsZ;
extern void *_file_bg_pam_tilesZ;
extern void *_file_bg_pete_padsZ;
extern void *_file_bg_pete_tilesZ;
extern void *_file_bg_ref_padsZ;
extern void *_file_bg_ref_tilesZ;
extern void *_file_bg_rit_padsZ;
extern void *_file_bg_rit_tilesZ;
extern void *_file_bg_run_padsZ;
extern void *_file_bg_run_tilesZ;
extern void *_file_bg_sev_padsZ;
extern void *_file_bg_sev_tilesZ;
extern void *_file_bg_sevb_padsZ;
extern void *_file_bg_sevb_tilesZ;
extern void *_file_bg_sevx_padsZ;
extern void *_file_bg_sevx_tilesZ;
extern void *_file_bg_sho_padsZ;
extern void *_file_bg_sho_tilesZ;
extern void *_file_bg_silo_padsZ;
extern void *_file_bg_silo_tilesZ;
extern void *_file_bg_stat_padsZ;
extern void *_file_bg_stat_tilesZ;
extern void *_file_bg_tra_padsZ;
extern void *_file_bg_tra_tilesZ;
extern void *_file_bg_wax_padsZ;
extern void *_file_bg_wax_tilesZ;
extern void *_file_GtestgunZ;
extern void *_file_Cdd_labtechZ;
extern void *_file_Pcctv_pdZ;
extern void *_file_PcomhubZ;
extern void *_file_PquadpodZ;
extern void *_file_Ppd_consoleZ;
extern void *_file_CconneryZ;
extern void *_file_CmooreZ;
extern void *_file_CdaltonZ;
extern void *_file_Cheaddark_combatZ;
extern void *_file_CheadelvisZ;
extern void *_file_CheadrossZ;
extern void *_file_CheadcarringtonZ;
extern void *_file_CheadmrblondeZ;
extern void *_file_CheadtrentZ;
extern void *_file_CheadddshockZ;
extern void *_file_CheadgrahamZ;
extern void *_file_Cheaddark_frockZ;
extern void *_file_CheadsecretaryZ;
extern void *_file_CheadcassandraZ;
extern void *_file_CheadthekingZ;
extern void *_file_Cheadfem_guardZ;
extern void *_file_CheadjonZ;
extern void *_file_Plift_platformZ;
extern void *_file_Pdd_grateZ;
extern void *_file_PlightswitchZ;
extern void *_file_PblastshieldZ;
extern void *_file_Plightswitch2Z;
extern void *_file_Pdd_accessdoorupZ;
extern void *_file_Pdd_accessdoordnZ;
extern void *_file_Cdark_rippedZ;
extern void *_file_Cheadmark2Z;
extern void *_file_CheadchristZ;
extern void *_file_Plab_containerZ;
extern void *_file_Plab_chairZ;
extern void *_file_Plab_tableZ;
extern void *_file_Plab_microscopeZ;
extern void *_file_Plab_mainframeZ;
extern void *_file_Pdd_labdoorZ;
extern void *_file_Pdd_lab_doortopZ;
extern void *_file_Pmulti_ammo_crateZ;
extern void *_file_CheadrussZ;
extern void *_file_CheadgreyZ;
extern void *_file_CheaddarlingZ;
extern void *_file_Cdd_guardZ;
extern void *_file_CheadrobertZ;
extern void *_file_Cdd_shockZ;
extern void *_file_CheadbeauZ;
extern void *_file_PchrchainZ;
extern void *_file_Cdd_shock_infZ;
extern void *_file_Cheadfem_guard2Z;
extern void *_file_ProofgunZ;
extern void *_file_PtdoorZ;
extern void *_file_CbiotechZ;
extern void *_file_CfbiguyZ;
extern void *_file_PgroundgunZ;
extern void *_file_CciaguyZ;
extern void *_file_Ca51trooperZ;
extern void *_file_CheadbrianZ;
extern void *_file_CheadjamieZ;
extern void *_file_Cheadduncan2Z;
extern void *_file_CheadbiotechZ;
extern void *_file_UsetupuffZ;
extern void *_file_Ump_setupuffZ;
extern void *_file_bg_uff_padsZ;
extern void *_file_bg_uff_tilesZ;
extern void *_file_UsetupoldZ;
extern void *_file_Ump_setupoldZ;
extern void *_file_bg_old_padsZ;
extern void *_file_bg_old_tilesZ;
extern void *_file_UsetupateZ;
extern void *_file_Ump_setupateZ;
extern void *_file_bg_ate_padsZ;
extern void *_file_bg_ate_tilesZ;
extern void *_file_UsetuplamZ;
extern void *_file_Ump_setuplamZ;
extern void *_file_bg_lam_padsZ;
extern void *_file_bg_lam_tilesZ;
extern void *_file_Usetupmp1Z;
extern void *_file_Ump_setupmp1Z;
extern void *_file_bg_mp1_padsZ;
extern void *_file_bg_mp1_tilesZ;
extern void *_file_Usetupmp2Z;
extern void *_file_Ump_setupmp2Z;
extern void *_file_bg_mp2_padsZ;
extern void *_file_bg_mp2_tilesZ;
extern void *_file_Usetupmp3Z;
extern void *_file_Ump_setupmp3Z;
extern void *_file_bg_mp3_padsZ;
extern void *_file_bg_mp3_tilesZ;
extern void *_file_Usetupmp4Z;
extern void *_file_Ump_setupmp4Z;
extern void *_file_bg_mp4_padsZ;
extern void *_file_bg_mp4_tilesZ;
extern void *_file_Usetupmp5Z;
extern void *_file_Ump_setupmp5Z;
extern void *_file_bg_mp5_padsZ;
extern void *_file_bg_mp5_tilesZ;
extern void *_file_Usetupmp6Z;
extern void *_file_Ump_setupmp6Z;
extern void *_file_bg_mp6_padsZ;
extern void *_file_bg_mp6_tilesZ;
extern void *_file_Usetupmp7Z;
extern void *_file_Ump_setupmp7Z;
extern void *_file_bg_mp7_padsZ;
extern void *_file_bg_mp7_tilesZ;
extern void *_file_Usetupmp8Z;
extern void *_file_Ump_setupmp8Z;
extern void *_file_bg_mp8_padsZ;
extern void *_file_bg_mp8_tilesZ;
extern void *_file_Usetupmp9Z;
extern void *_file_Ump_setupmp9Z;
extern void *_file_bg_mp9_padsZ;
extern void *_file_bg_mp9_tilesZ;
extern void *_file_Usetupmp10Z;
extern void *_file_Ump_setupmp10Z;
extern void *_file_bg_mp10_padsZ;
extern void *_file_bg_mp10_tilesZ;
extern void *_file_Usetupmp11Z;
extern void *_file_Ump_setupmp11Z;
extern void *_file_bg_mp11_padsZ;
extern void *_file_bg_mp11_tilesZ;
extern void *_file_Usetupmp12Z;
extern void *_file_Ump_setupmp12Z;
extern void *_file_bg_mp12_padsZ;
extern void *_file_bg_mp12_tilesZ;
extern void *_file_Usetupmp13Z;
extern void *_file_Ump_setupmp13Z;
extern void *_file_bg_mp13_padsZ;
extern void *_file_bg_mp13_tilesZ;
extern void *_file_Usetupmp14Z;
extern void *_file_Ump_setupmp14Z;
extern void *_file_bg_mp14_padsZ;
extern void *_file_bg_mp14_tilesZ;
extern void *_file_Usetupmp15Z;
extern void *_file_Ump_setupmp15Z;
extern void *_file_bg_mp15_padsZ;
extern void *_file_bg_mp15_tilesZ;
extern void *_file_Usetupmp16Z;
extern void *_file_Ump_setupmp16Z;
extern void *_file_bg_mp16_padsZ;
extern void *_file_bg_mp16_tilesZ;
extern void *_file_Usetupmp17Z;
extern void *_file_Ump_setupmp17Z;
extern void *_file_bg_mp17_padsZ;
extern void *_file_bg_mp17_tilesZ;
extern void *_file_Usetupmp18Z;
extern void *_file_Ump_setupmp18Z;
extern void *_file_bg_mp18_padsZ;
extern void *_file_bg_mp18_tilesZ;
extern void *_file_Usetupmp19Z;
extern void *_file_Ump_setupmp19Z;
extern void *_file_bg_mp19_padsZ;
extern void *_file_bg_mp19_tilesZ;
extern void *_file_Usetupmp20Z;
extern void *_file_Ump_setupmp20Z;
extern void *_file_bg_mp20_padsZ;
extern void *_file_bg_mp20_tilesZ;
extern void *_file_Ca51airmanZ;
extern void *_file_Cheadneil2Z;
extern void *_file_Pci_sofaZ;
extern void *_file_Pci_liftZ;
extern void *_file_Pci_liftdoorZ;
extern void *_file_CchicrobZ;
extern void *_file_CstewardZ;
extern void *_file_CheadedmcgZ;
extern void *_file_CstewardessZ;
extern void *_file_CheadankaZ;
extern void *_file_CpresidentZ;
extern void *_file_Cstewardess_coatZ;
extern void *_file_Cheadleslie_sZ;
extern void *_file_PlasercutZ;
extern void *_file_Psk_shuttleZ;
extern void *_file_CminiskedarZ;
extern void *_file_PnewvilladoorZ;
extern void *_file_Cnsa_lackeyZ;
extern void *_file_Cheadmatt_cZ;
extern void *_file_Cpres_securityZ;
extern void *_file_Cheadpeer_sZ;
extern void *_file_CnegotiatorZ;
extern void *_file_Cheadeileen_tZ;
extern void *_file_Psk_pillarleftZ;
extern void *_file_Psk_pillarrightZ;
extern void *_file_Psk_plinth_tZ;
extern void *_file_Psk_plinth_mlZ;
extern void *_file_Psk_plinth_mrZ;
extern void *_file_Psk_plinth_blZ;
extern void *_file_Psk_plinth_brZ;
extern void *_file_Psk_fl_shad_tZ;
extern void *_file_Psk_fl_shad_mlZ;
extern void *_file_Psk_fl_shad_mrZ;
extern void *_file_Psk_fl_shad_blZ;
extern void *_file_Psk_fl_shad_brZ;
extern void *_file_Psk_fl_noshad_tZ;
extern void *_file_Psk_fl_noshad_mlZ;
extern void *_file_Psk_fl_noshad_mrZ;
extern void *_file_Psk_fl_noshad_blZ;
extern void *_file_Psk_fl_noshad_brZ;
extern void *_file_GhudpieceZ;
extern void *_file_Psk_templecolumn1Z;
extern void *_file_Psk_templecolumn2Z;
extern void *_file_Psk_templecolumn3Z;
extern void *_file_Psk_sunshad1Z;
extern void *_file_Psk_sunshad2Z;
extern void *_file_Psk_sunnoshad1Z;
extern void *_file_Psk_sunnoshad2Z;
extern void *_file_Cg5_guardZ;
extern void *_file_Cheadandy_rZ;
extern void *_file_Cpelagic_guardZ;
extern void *_file_Cg5_swat_guardZ;
extern void *_file_Calaskan_guardZ;
extern void *_file_Cmaian_soldierZ;
extern void *_file_Cheadben_rZ;
extern void *_file_Cheadsteve_kZ;
extern void *_file_PbarrelZ;
extern void *_file_Pglass_floorZ;
extern void *_file_Pesca_stepZ;
extern void *_file_Pmatrix_liftZ;
extern void *_file_Prubble1Z;
extern void *_file_Prubble2Z;
extern void *_file_Prubble3Z;
extern void *_file_Prubble4Z;
extern void *_file_Arecep01M;
extern void *_file_Arecep02M;
extern void *_file_Arecep03M;
extern void *_file_Arecep04M;
extern void *_file_Arecep05M;
extern void *_file_Arecep06M;
extern void *_file_Arlguard1M;
extern void *_file_Arltech01M;
extern void *_file_Arltech02M;
extern void *_file_Arltech03M;
extern void *_file_Arltech04M;
extern void *_file_Arltech05M;
extern void *_file_Arltech06M;
extern void *_file_Ascie2aM;
extern void *_file_Ascie2bM;
extern void *_file_Ascie2cM;
extern void *_file_Ascie2dM;
extern void *_file_Ascie2eM;
extern void *_file_Ascie2fM;
extern void *_file_Ascie2gM;
extern void *_file_Ascie3aM;
extern void *_file_Ascie3bM;
extern void *_file_Ascie3cM;
extern void *_file_Ascie3dM;
extern void *_file_Ascie3eM;
extern void *_file_Ascie3gM;
extern void *_file_Ascien10aM;
extern void *_file_Ascien2_aM;
extern void *_file_Ascien3_aM;
extern void *_file_Ascien4_aM;
extern void *_file_Ascien5_aM;
extern void *_file_Ascien6_aM;
extern void *_file_Ascien7_aM;
extern void *_file_Ascien9_aM;
extern void *_file_AvilgrimM;
extern void *_file_Awepgd01M;
extern void *_file_Awepgd02M;
extern void *_file_Awepgd03M;
extern void *_file_Awepsc01M;
extern void *_file_Awepsc02M;
extern void *_file_Awepsc03M;
extern void *_file_Aa51elv01M;
extern void *_file_Aa51elv02M;
extern void *_file_Aa51elv03M;
extern void *_file_Aa51grd01M;
extern void *_file_Aa51grd02M;
extern void *_file_Aa51grd03M;
extern void *_file_Aa51grd04M;
extern void *_file_Aa51grd05M;
extern void *_file_Aa51grd06M;
extern void *_file_Aa51grd07M;
extern void *_file_Aa51grd08M;
extern void *_file_Aa51grd09M;
extern void *_file_Aa51grd10M;
extern void *_file_Aa51jo1M;
extern void *_file_Aa51jo2M;
extern void *_file_Aa51jo3M;
extern void *_file_Aa51jo4M;
extern void *_file_Aa51jo5M;
extern void *_file_Aa51jo6M;
extern void *_file_Aa51jon01M;
extern void *_file_Aa51jon02M;
extern void *_file_Aa51jon03M;
extern void *_file_Aa51jon04M;
extern void *_file_Aa51jon05M;
extern void *_file_Aa51jon06M;
extern void *_file_Aa51jon07M;
extern void *_file_Aa51jon08M;
extern void *_file_Aa51jon09M;
extern void *_file_Aa51jon10M;
extern void *_file_Aa51jon11M;
extern void *_file_Aa51jon12M;
extern void *_file_Aa51jon14M;
extern void *_file_Aa51jon15M;
extern void *_file_Aa51sci1M;
extern void *_file_Aaf1jo01M;
extern void *_file_Aaf1jo02M;
extern void *_file_Aaf1jo03M;
extern void *_file_Aaf1pr01M;
extern void *_file_Aaf1pr02M;
extern void *_file_Aaf1pr03M;
extern void *_file_Aaf1pr04M;
extern void *_file_Aaf1pr05M;
extern void *_file_Aaf1pr06M;
extern void *_file_Aaf1pr07M;
extern void *_file_Aaf1pr08M;
extern void *_file_Aaf1pr09M;
extern void *_file_Aaf1pr10M;
extern void *_file_Aaf1tr01M;
extern void *_file_Aaf1tr02M;
extern void *_file_Aaf1tr03M;
extern void *_file_Aairbgd01M;
extern void *_file_Aairbgd02M;
extern void *_file_Aairbgd03M;
extern void *_file_Aairbgd04M;
extern void *_file_Aairbgd05M;
extern void *_file_Aairbgd06M;
extern void *_file_Aairbgd07M;
extern void *_file_Aairbgd08M;
extern void *_file_Aairbgd09M;
extern void *_file_Aairbgd10M;
extern void *_file_Aairbgd11M;
extern void *_file_Aairbgd12M;
extern void *_file_Aairbgd13M;
extern void *_file_Aairbgd14M;
extern void *_file_Aairbgd15M;
extern void *_file_Aairbgd16M;
extern void *_file_Aairstw01M;
extern void *_file_Aairstw02M;
extern void *_file_Aairstw03M;
extern void *_file_Aassael01M;
extern void *_file_Aassael02M;
extern void *_file_Aassael03M;
extern void *_file_Aassael04M;
extern void *_file_Aassael05M;
extern void *_file_Aassael06M;
extern void *_file_Absewrk01M;
extern void *_file_Absewrk02M;
extern void *_file_Absewrk03M;
extern void *_file_Absewrk04M;
extern void *_file_Absewrk05M;
extern void *_file_Acetael01M;
extern void *_file_Achdroid1M;
extern void *_file_Achdroid2M;
extern void *_file_Acsec01M;
extern void *_file_Acsec02M;
extern void *_file_Acsec03M;
extern void *_file_Acstan1M;
extern void *_file_Acstan2M;
extern void *_file_Adevr01M;
extern void *_file_Adevr02M;
extern void *_file_Adevr03M;
extern void *_file_Adevr04M;
extern void *_file_Adevr05M;
extern void *_file_Adevr06M;
extern void *_file_Adevr07M;
extern void *_file_Adevr08M;
extern void *_file_Adevr09M;
extern void *_file_Adevr10M;
extern void *_file_Adevr11M;
extern void *_file_Adevr12M;
extern void *_file_Aexec01M;
extern void *_file_Aexec02M;
extern void *_file_Aexec04M;
extern void *_file_Aexec05M;
extern void *_file_Aexec06M;
extern void *_file_Aexec07M;
extern void *_file_Aexec08M;
extern void *_file_Aexec09M;
extern void *_file_Aexec10M;
extern void *_file_Aexec11M;
extern void *_file_Aexec12M;
extern void *_file_Aexec13M;
extern void *_file_Aexec14M;
extern void *_file_Ahelic01M;
extern void *_file_Ahelic02M;
extern void *_file_Ahelic03M;
extern void *_file_Ahologd01M;
extern void *_file_AholohopkM;
extern void *_file_Ainvcar01M;
extern void *_file_Ainvcar02M;
extern void *_file_Ainvcar03M;
extern void *_file_Ainvcar04M;
extern void *_file_Ainvcar05M;
extern void *_file_Ainvcar06M;
extern void *_file_Ainvcar07M;
extern void *_file_Ainvcar08M;
extern void *_file_Ainvcar09M;
extern void *_file_Ainvcar10M;
extern void *_file_Ainvcar11M;
extern void *_file_Ainvcar12M;
extern void *_file_AinvfarrM;
extern void *_file_AinvfemaM;
extern void *_file_AinvfostM;
extern void *_file_AinvgrimM;
extern void *_file_AinvhopkM;
extern void *_file_AinvmaleM;
extern void *_file_Ajoexec01M;
extern void *_file_Ajoexec02M;
extern void *_file_Ajosci01M;
extern void *_file_Ajosci02M;
extern void *_file_Ajosci03M;
extern void *_file_Alabacc1M;
extern void *_file_Alabacc2M;
extern void *_file_Alabacc3M;
extern void *_file_Alabacc4M;
extern void *_file_Alabacc5M;
extern void *_file_Alabacc6M;
extern void *_file_Alabtech1M;
extern void *_file_Alabtech2M;
extern void *_file_Alabtech3M;
extern void *_file_Alabtech5M;
extern void *_file_Alabtech6M;
extern void *_file_Alabtech7M;
extern void *_file_Alabtech8M;
extern void *_file_Alabtech9M;
extern void *_file_Aoffwrk01M;
extern void *_file_Aoffwrk02M;
extern void *_file_Aoffwrk03M;
extern void *_file_Aoffwrk04M;
extern void *_file_Cpresident_cloneZ;
extern void *_file_CheadjonathanZ;
extern void *_file_Cheadmaian_sZ;
extern void *_file_Cdark_af1Z;
extern void *_file_Pcable_carZ;
extern void *_file_Pelvis_saucerZ;
extern void *_file_Pstewardess_trolleyZ;
extern void *_file_Pairbase_lift_enclosedZ;
extern void *_file_Pairbase_lift_angleZ;
extern void *_file_Pairbase_safedoorZ;
extern void *_file_Paf1_pilotchairZ;
extern void *_file_Paf1_passchairZ;
extern void *_file_CheadshaunZ;
extern void *_file_PchrnightsightZ;
extern void *_file_PchrshieldZ;
extern void *_file_Pchrfalcon2Z;
extern void *_file_Pchrleegun1Z;
extern void *_file_PchrmaulerZ;
extern void *_file_Pchrdy357Z;
extern void *_file_Pchrdy357trentZ;
extern void *_file_PchrmaianpistolZ;
extern void *_file_Pchrfalcon2silZ;
extern void *_file_Pchrfalcon2scopeZ;
extern void *_file_Pchrcmp150Z;
extern void *_file_Pchrar34Z;
extern void *_file_PchrdragonZ;
extern void *_file_PchrsuperdragonZ;
extern void *_file_PchravengerZ;
extern void *_file_PchrcycloneZ;
extern void *_file_PchrmaiansmgZ;
extern void *_file_Pchrrcp120Z;
extern void *_file_PchrpcgunZ;
extern void *_file_PchrshotgunZ;
extern void *_file_PchrskminigunZ;
extern void *_file_PchrdyrocketZ;
extern void *_file_PchrdevastatorZ;
extern void *_file_PchrskrocketZ;
extern void *_file_Pchrz2020Z;
extern void *_file_PchrsniperrifleZ;
extern void *_file_PchrcrossbowZ;
extern void *_file_PchrdruggunZ;
extern void *_file_PchrknifeZ;
extern void *_file_PchrnbombZ;
extern void *_file_PchrflashbangZ;
extern void *_file_PchrgrenadeZ;
extern void *_file_PchrtimedmineZ;
extern void *_file_PchrproximitymineZ;
extern void *_file_PchrremotemineZ;
extern void *_file_PchrecmmineZ;
extern void *_file_PchrwppkZ;
extern void *_file_Pchrtt33Z;
extern void *_file_PchrskorpionZ;
extern void *_file_PchrkalashZ;
extern void *_file_PchruziZ;
extern void *_file_Pchrmp5kZ;
extern void *_file_Pchrm16Z;
extern void *_file_Pchrfnp90Z;
extern void *_file_PchrdyrocketmisZ;
extern void *_file_PchrskrocketmisZ;
extern void *_file_PchrcrossboltZ;
extern void *_file_PchrdevgrenadeZ;
extern void *_file_PchrdraggrenadeZ;
extern void *_file_Gfalcon2Z;
extern void *_file_Gleegun1Z;
extern void *_file_GskpistolZ;
extern void *_file_Gdy357Z;
extern void *_file_Gdy357trentZ;
extern void *_file_GmaianpistolZ;
extern void *_file_Gcmp150Z;
extern void *_file_Gar34Z;
extern void *_file_GdydragonZ;
extern void *_file_GdysuperdragonZ;
extern void *_file_Gk7avengerZ;
extern void *_file_GcycloneZ;
extern void *_file_GmaiansmgZ;
extern void *_file_Grcp120Z;
extern void *_file_GpcgunZ;
extern void *_file_GshotgunZ;
extern void *_file_GskminigunZ;
extern void *_file_GdyrocketZ;
extern void *_file_GdydevastatorZ;
extern void *_file_GskrocketZ;
extern void *_file_Gz2020Z;
extern void *_file_GsniperrifleZ;
extern void *_file_GcrossbowZ;
extern void *_file_GdruggunZ;
extern void *_file_GknifeZ;
extern void *_file_GgrenadeZ;
extern void *_file_GtimedmineZ;
extern void *_file_GproximitymineZ;
extern void *_file_GremotemineZ;
extern void *_file_GwppkZ;
extern void *_file_Gtt33Z;
extern void *_file_GskorpionZ;
extern void *_file_Gak47Z;
extern void *_file_GuziZ;
extern void *_file_Gmp5kZ;
extern void *_file_Gm16Z;
extern void *_file_Gfnp90Z;
extern void *_file_Gfalcon2lodZ;
extern void *_file_GskminigunlodZ;
extern void *_file_Pa51_turretZ;
extern void *_file_PpelagicdoorZ;
extern void *_file_Am1_l1_aM;
extern void *_file_Am1_l1_bM;
extern void *_file_Am1_l1_cM;
extern void *_file_Am1_l1_dM;
extern void *_file_Am1_l2_aM;
extern void *_file_Am1_l2_bM;
extern void *_file_Am1_l2_cM;
extern void *_file_Am1_l2_dM;
extern void *_file_Am1_l3_aM;
extern void *_file_Am1_l3_bM;
extern void *_file_Am1_l3_cM;
extern void *_file_Am1_l3_dM;
extern void *_file_Am2_l1_aM;
extern void *_file_Am2_l1_bM;
extern void *_file_Am2_l1_cM;
extern void *_file_Am2_l1_dM;
extern void *_file_Am3_l1_aM;
extern void *_file_Am3_l1_bM;
extern void *_file_Am3_l1_cM;
extern void *_file_Am3_l1_dM;
extern void *_file_Am3_l2_aM;
extern void *_file_Am3_l2_bM;
extern void *_file_Am3_l2_cM;
extern void *_file_Am3_l2_dM;
extern void *_file_Am4_l1_aM;
extern void *_file_Am4_l1_bM;
extern void *_file_Am4_l1_cM;
extern void *_file_Am4_l1_dM;
extern void *_file_Am4_l2_aM;
extern void *_file_Am4_l2_bM;
extern void *_file_Am4_l2_cM;
extern void *_file_Am4_l2_dM;
extern void *_file_Am4_l3_aM;
extern void *_file_Am4_l3_bM;
extern void *_file_Am4_l3_cM;
extern void *_file_Am4_l3_dM;
extern void *_file_Am5_l1_aM;
extern void *_file_Am5_l1_bM;
extern void *_file_Am5_l1_cM;
extern void *_file_Am5_l1_dM;
extern void *_file_Am5_l2_aM;
extern void *_file_Am5_l2_bM;
extern void *_file_Am5_l2_cM;
extern void *_file_Am5_l2_dM;
extern void *_file_Am5_l3_aM;
extern void *_file_Am5_l3_bM;
extern void *_file_Am5_l3_cM;
extern void *_file_Am5_l3_dM;
extern void *_file_Am6_l1_aM;
extern void *_file_Am6_l1_bM;
extern void *_file_Am6_l1_cM;
extern void *_file_Am6_l1_dM;
extern void *_file_Am6_l2_aM;
extern void *_file_Am6_l2_bM;
extern void *_file_Am6_l2_cM;
extern void *_file_Am6_l2_dM;
extern void *_file_Am7_l1_aM;
extern void *_file_Am7_l1_bM;
extern void *_file_Am7_l1_cM;
extern void *_file_Am7_l1_dM;
extern void *_file_Am8_l1_aM;
extern void *_file_Am8_l1_bM;
extern void *_file_Am8_l1_cM;
extern void *_file_Am8_l1_dM;
extern void *_file_Am9_l1_aM;
extern void *_file_Am9_l1_bM;
extern void *_file_Am9_l1_cM;
extern void *_file_Am9_l1_dM;
extern void *_file_Ap1_01_joM;
extern void *_file_Ap1_02_caM;
extern void *_file_Ap1_03_joM;
extern void *_file_Ap1_04_caM;
extern void *_file_Ap1_05_joM;
extern void *_file_Ap1_06_caM;
extern void *_file_Ap1_07_joM;
extern void *_file_Ap1_08_caM;
extern void *_file_Ap2_01_joM;
extern void *_file_Ap2_02_joM;
extern void *_file_Ap2_03_drM;
extern void *_file_Ap2_04_joM;
extern void *_file_Ap2_05_joM;
extern void *_file_Ap2_06_drM;
extern void *_file_Ap2_07_drM;
extern void *_file_Ap3_01_gdM;
extern void *_file_Ap3_02_joM;
extern void *_file_Ap3_03_joM;
extern void *_file_Ap4_01_dvM;
extern void *_file_Ap4_02_joM;
extern void *_file_Ap4_03_dvM;
extern void *_file_Ap4_04_joM;
extern void *_file_Ap4_05_dvM;
extern void *_file_Ap4_06_joM;
extern void *_file_Ap4_07_blM;
extern void *_file_Ap4_08_dvM;
extern void *_file_Ap4_09_dvM;
extern void *_file_Ap5_01_joM;
extern void *_file_Ap5_02_joM;
extern void *_file_Ap5_03_joM;
extern void *_file_Ap6_01_joM;
extern void *_file_Ap6_02_caM;
extern void *_file_Ap6_03_joM;
extern void *_file_Ap6_04_caM;
extern void *_file_Ap6_05_joM;
extern void *_file_Ap6_06_caM;
extern void *_file_Ap7_01_caM;
extern void *_file_Ap7_02_joM;
extern void *_file_Ap7_03_caM;
extern void *_file_Ap7_04_joM;
extern void *_file_Ap8_01_dvM;
extern void *_file_Ap8_02_blM;
extern void *_file_Ap8_03_dvM;
extern void *_file_Ap8_04_blM;
extern void *_file_Ap8_06_blM;
extern void *_file_Ap8_07_trM;
extern void *_file_Ap8_08_dvM;
extern void *_file_Ap8_09_trM;
extern void *_file_Ap8_10_blM;
extern void *_file_Ap9_01_joM;
extern void *_file_Ap9_02_caM;
extern void *_file_Ap9_03_joM;
extern void *_file_Ap10_01_caM;
extern void *_file_Ap10_02_caM;
extern void *_file_Ap10_03_caM;
extern void *_file_Ap10_04_caM;
extern void *_file_Ap10_05_joM;
extern void *_file_Ap10_06_caM;
extern void *_file_Ap10_07_joM;
extern void *_file_Ap10_08_caM;
extern void *_file_Ap10_09_joM;
extern void *_file_Ap11_01_jnM;
extern void *_file_Ap11_02_joM;
extern void *_file_Ap11_03_jnM;
extern void *_file_Ap11_04_joM;
extern void *_file_Ap11_05_jnM;
extern void *_file_Ap11_06_joM;
extern void *_file_Ap11_07_jnM;
extern void *_file_Ap11_08_joM;
extern void *_file_Ap12_01_jnM;
extern void *_file_Ap12_02_joM;
extern void *_file_Ap12_03_jnM;
extern void *_file_Ap12_04_joM;
extern void *_file_Ap12_05_jnM;
extern void *_file_Ap12_06_joM;
extern void *_file_Ap12_07_jnM;
extern void *_file_Ap12_08_joM;
extern void *_file_Ap12_09_jnM;
extern void *_file_Ap12_10_joM;
extern void *_file_Ap13_01_joM;
extern void *_file_Ap13_02_suM;
extern void *_file_Ap13_03_joM;
extern void *_file_Ap13_04_suM;
extern void *_file_Ap13_06_suM;
extern void *_file_Ap14_03_suM;
extern void *_file_Ap14_04_joM;
extern void *_file_Ap14_05_suM;
extern void *_file_Ap14_07_joM;
extern void *_file_Ap15_01_elM;
extern void *_file_Ap15_02_elM;
extern void *_file_Ap15_03_joM;
extern void *_file_Ap15_04_jnM;
extern void *_file_Ap15_05_elM;
extern void *_file_Ap15_06_joM;
extern void *_file_Ap15_07_elM;
extern void *_file_Ap15_08_joM;
extern void *_file_Ap15_09_elM;
extern void *_file_Ap15_10_joM;
extern void *_file_Ap15_11_elM;
extern void *_file_Ap16_01_joM;
extern void *_file_Ap16_02_caM;
extern void *_file_Ap16_04_caM;
extern void *_file_Ap16_05_joM;
extern void *_file_Ap16_06_caM;
extern void *_file_Ap17_01_trM;
extern void *_file_Ap17_02_prM;
extern void *_file_Ap17_03_trM;
extern void *_file_Ap17_04_prM;
extern void *_file_Ap17_05_trM;
extern void *_file_Ap17_06_trM;
extern void *_file_Ap18_01_joM;
extern void *_file_Ap18_02_elM;
extern void *_file_Ap18_03_elM;
extern void *_file_Ap18_04_joM;
extern void *_file_Ap18_05_elM;
extern void *_file_Ap19_01_caM;
extern void *_file_Ap19_02_caM;
extern void *_file_Ap19_03_joM;
extern void *_file_Ap19_04_caM;
extern void *_file_Ap19_05_joM;
extern void *_file_Ap19_06_joM;
extern void *_file_Ap20_01_joM;
extern void *_file_Ap20_02_prM;
extern void *_file_Ap20_03_joM;
extern void *_file_Ap20_04_prM;
extern void *_file_Ap20_05_joM;
extern void *_file_Ap20_06_blM;
extern void *_file_Ap20_07_trM;
extern void *_file_Ap20_08_trM;
extern void *_file_Ap21_01_elM;
extern void *_file_Ap21_02_joM;
extern void *_file_Ap21_03_elM;
extern void *_file_Ap21_04_joM;
extern void *_file_Ap22_01_elM;
extern void *_file_Ap22_02_joM;
extern void *_file_Ap22_03_elM;
extern void *_file_Ap22_04_joM;
extern void *_file_Ap23_01_joM;
extern void *_file_Ap23_02_drM;
extern void *_file_Ap23_03_joM;
extern void *_file_Ap23_04_drM;
extern void *_file_Ap23_05_joM;
extern void *_file_Ap23_06_drM;
extern void *_file_Ap23_07_joM;
extern void *_file_Ap23_08_drM;
extern void *_file_Ap24_01_caM;
extern void *_file_Ap24_02_joM;
extern void *_file_Ap24_03_caM;
extern void *_file_Ap24_04_joM;
extern void *_file_Ap24_05_caM;
extern void *_file_Ap24_06_caM;
extern void *_file_Ap24_07_joM;
extern void *_file_Ap24_08_joM;
extern void *_file_Ap25_01_joM;
extern void *_file_Ap25_02_joM;
extern void *_file_Ap26_01_joM;
extern void *_file_Ap26_02_dvM;
extern void *_file_Ap26_03_joM;
extern void *_file_Ap26_04_dvM;
extern void *_file_Ap26_05_dvM;
extern void *_file_Ap26_06_joM;
extern void *_file_Ap26_07_dvM;
extern void *_file_Ap26_08_dvM;
extern void *_file_Ap27_01_joM;
extern void *_file_Ap27_02_elM;
extern void *_file_Ap27_03_elM;
extern void *_file_Ap27_04_joM;
extern void *_file_Ap27_05_joM;
extern void *_file_Ap27_06_elM;
extern void *_file_Ap28_01_elM;
extern void *_file_Ap28_02_joM;
extern void *_file_Ap28_03_elM;
extern void *_file_Ap28_04_joM;
extern void *_file_Ap28_05_elM;
extern void *_file_Ap28_06_joM;
extern void *_file_Ap29_01_elM;
extern void *_file_Ap29_02_joM;
extern void *_file_Ap29_03_elM;
extern void *_file_Ap29_04_joM;
extern void *_file_Ap29_05_joM;
extern void *_file_Ap29_06_elM;
extern void *_file_Ap29_07_joM;
extern void *_file_Ap29_08_elM;
extern void *_file_Ap29_09_joM;
extern void *_file_Ap29_10_elM;
extern void *_file_PautosurgeonZ;
extern void *_file_CdarkwetZ;
extern void *_file_CdarkaqualungZ;
extern void *_file_CdarksnowZ;
extern void *_file_CdarklabZ;
extern void *_file_CfemlabtechZ;
extern void *_file_CddsniperZ;
extern void *_file_Cpilotaf1Z;
extern void *_file_CcilabtechZ;
extern void *_file_CcifemtechZ;
extern void *_file_Cheadeileen_hZ;
extern void *_file_Cheadscott_hZ;
extern void *_file_CcarreveningsuitZ;
extern void *_file_CjonathonZ;
extern void *_file_CcisoldierZ;
extern void *_file_CheadsanchezZ;
extern void *_file_CheaddarkaquaZ;
extern void *_file_CheadddsniperZ;
extern void *_file_PlimoZ;
extern void *_file_PpdmenuZ;
extern void *_file_Pa51interceptorZ;
extern void *_file_Pa51dishZ;
extern void *_file_Pa51radarconsoleZ;
extern void *_file_Pa51lockerdoorZ;
extern void *_file_Pg5generatorZ;
extern void *_file_Pg5dumpsterZ;
extern void *_file_Gar34lodZ;
extern void *_file_GavengerlodZ;
extern void *_file_Gcmp150lodZ;
extern void *_file_GcrossbowlodZ;
extern void *_file_GcyclonelodZ;
extern void *_file_GdruggunlodZ;
extern void *_file_Gdy357lodZ;
extern void *_file_Gdy357trentlodZ;
extern void *_file_GdevastatorlodZ;
extern void *_file_GdydragonlodZ;
extern void *_file_GdysuperdragonlodZ;
extern void *_file_GknifelodZ;
extern void *_file_GlaserlodZ;
extern void *_file_GmagseclodZ;
extern void *_file_GmayanpistollodZ;
extern void *_file_GmayansmglodZ;
extern void *_file_GpcgunlodZ;
extern void *_file_Grcp120lodZ;
extern void *_file_GrocketlodZ;
extern void *_file_GshotgunlodZ;
extern void *_file_GskpistollodZ;
extern void *_file_GskrocketlodZ;
extern void *_file_GsniperlodZ;
extern void *_file_Gz2020lodZ;
extern void *_file_PchrcloakerZ;
extern void *_file_PchrspeedpillZ;
extern void *_file_PbaggagecarrierZ;
extern void *_file_PminesignZ;
extern void *_file_PchamberZ;
extern void *_file_PisotopeexperimentZ;
extern void *_file_PisotopeZ;
extern void *_file_PreactordoorZ;
extern void *_file_PsaucerinsideZ;
extern void *_file_PvillastoolZ;
extern void *_file_Pcetanwindow1Z;
extern void *_file_Pcetanwindow2Z;
extern void *_file_Pcetanwindow3Z;
extern void *_file_Apelelv01M;
extern void *_file_Apelgrd01M;
extern void *_file_Ap29_11_joM;
extern void *_file_GlaserZ;
extern void *_file_PbigpelagicdoorZ;
extern void *_file_Psk_jonrubble3Z;
extern void *_file_Psk_jonrubble4Z;
extern void *_file_Psk_jonrubble5Z;
extern void *_file_Psk_jonrubble6Z;
extern void *_file_GcombathandslodZ;
extern void *_file_PbinocularsZ;
extern void *_file_PsubmarineZ;
extern void *_file_Pairforce1Z;
extern void *_file_PenginepartZ;
extern void *_file_Am3l2carrM;
extern void *_file_Aelvcet01M;
extern void *_file_Aelvcet02M;
extern void *_file_Ajorep01M;
extern void *_file_Ajorep02M;
extern void *_file_Ajorep03M;
extern void *_file_Ajorep04M;
extern void *_file_PcetroofgunZ;
extern void *_file_PcetansmalldoorZ;
extern void *_file_PpowernodeZ;
extern void *_file_PcetanbluegreenlZ;
extern void *_file_PcetanbluegreenrZ;
extern void *_file_PskedarconsoleZ;
extern void *_file_PskedarconsolepanelZ;
extern void *_file_Ajorpld01M;
extern void *_file_Ajorpld02M;
extern void *_file_Ajorpld03M;
extern void *_file_Ajorpld04M;
extern void *_file_GnbombZ;
extern void *_file_GnbomblodZ;
extern void *_file_GgrenadelodZ;
extern void *_file_PweaponcdoorZ;
extern void *_file_PtargetZ;
extern void *_file_PdevicesecretdoorZ;
extern void *_file_PcarringtonsecretdoorZ;
extern void *_file_PsinisterpcZ;
extern void *_file_PsinisterstationZ;
extern void *_file_PkeypadlockZ;
extern void *_file_PthumbprintscannerZ;
extern void *_file_PretinalockZ;
extern void *_file_PcardlockZ;
extern void *_file_PgoodstationZ;
extern void *_file_PgoodpcZ;
extern void *_file_CskedarkingZ;
extern void *_file_CelviswaistcoatZ;
extern void *_file_CheadgriffeyZ;
extern void *_file_CheadmotoZ;
extern void *_file_CheadkeithZ;
extern void *_file_CheadwinnerZ;
extern void *_file_Ca51faceplateZ;
extern void *_file_PchrautogunZ;
extern void *_file_Pg5bigchairZ;
extern void *_file_Pg5smallchairZ;
extern void *_file_PkingsceptreZ;
extern void *_file_PlabcoatZ;
extern void *_file_Atrjo01M;
extern void *_file_Atrgrim01M;
extern void *_file_Atrgrim02M;
extern void *_file_Atrcarr06M;
extern void *_file_Atrcarr07M;
extern void *_file_Atrcarr08M;
extern void *_file_Atrcarr01M;
extern void *_file_Atrcarr02M;
extern void *_file_Atrcarr03M;
extern void *_file_Atrcarr04M;
extern void *_file_Atrcarr05M;
extern void *_file_Atrcarr12M;
extern void *_file_Abnblde01M;
extern void *_file_Abncass01M;
extern void *_file_Pcidoor1Z;
extern void *_file_Pg5_chairZ;
extern void *_file_Pg5_chair2Z;
extern void *_file_Pdd_window_foyerZ;
extern void *_file_Ghand_jowetsuitZ;
extern void *_file_Ghand_trentZ;
extern void *_file_Ghand_jofrockZ;
extern void *_file_Ghand_jotrenchZ;
extern void *_file_Ghand_ddsniperZ;
extern void *_file_Ghand_presidentZ;
extern void *_file_Ghand_joaf1Z;
extern void *_file_Ghand_jopilotZ;
extern void *_file_Ghand_carringtonZ;
extern void *_file_Ghand_mrblondeZ;
extern void *_file_Ghand_ciaZ;
extern void *_file_Ghand_cifemtechZ;
extern void *_file_Ghand_fbiarmZ;
extern void *_file_Ghand_josnowZ;
extern void *_file_Ghand_vriesZ;
extern void *_file_Ghand_ddsecurityZ;
extern void *_file_Ghand_tragic_pelagicZ;
extern void *_file_Ghand_stewardess_coatZ;
extern void *_file_Ghand_ddlabtechZ;
extern void *_file_Pci_cabinetZ;
extern void *_file_Pci_deskZ;
extern void *_file_Pci_carr_deskZ;
extern void *_file_Pci_f_chairZ;
extern void *_file_Pci_loungerZ;
extern void *_file_Pci_f_sofaZ;
extern void *_file_Pci_tableZ;
extern void *_file_Pcv_coffee_tableZ;
extern void *_file_Pcv_chair1Z;
extern void *_file_Pcv_chair2Z;
extern void *_file_Pcv_sofaZ;
extern void *_file_Pcv_chair4Z;
extern void *_file_Pcv_lampZ;
extern void *_file_Pcv_cabinetZ;
extern void *_file_Pcv_f_bedZ;
extern void *_file_Ppel_chair1Z;
extern void *_file_Psk_console2Z;
extern void *_file_Pdd_ear_tableZ;
extern void *_file_Pdd_ear_chairZ;
extern void *_file_Pairbase_table2Z;
extern void *_file_Pairbase_chair2Z;
extern void *_file_Pmisc_crateZ;
extern void *_file_Pmisc_irspecsZ;
extern void *_file_Cheadelvis_gogsZ;
extern void *_file_CheadstevemZ;
extern void *_file_Pa51_roofgunZ;
extern void *_file_Psk_drone_gunZ;
extern void *_file_Pci_roofgunZ;
extern void *_file_Pcv_tableZ;
extern void *_file_Cdark_leatherZ;
extern void *_file_Cheaddark_snowZ;
extern void *_file_CheadpresidentZ;
extern void *_file_Pcidoor1_refZ;
extern void *_file_Palaskadoor_outZ;
extern void *_file_Palaskadoor_inZ;
extern void *_file_PwirefenceZ;
extern void *_file_PrarelogoZ;
extern void *_file_Chead_vdZ;
extern void *_file_Apelelv02M;
extern void *_file_PkeycardZ;
extern void *_file_PbodyarmourZ;
extern void *_file_Pa51gate_rZ;
extern void *_file_Pa51gate_lZ;
extern void *_file_Paf1_lampZ;
extern void *_file_Paf1_toiletZ;
extern void *_file_Paf1_doorbig2Z;
extern void *_file_Paf1_phoneZ;
extern void *_file_Paf1_cargodoorZ;
extern void *_file_Pg5_alarmZ;
extern void *_file_Pg5_laser_switchZ;
extern void *_file_Psk_templecolumn4Z;
extern void *_file_PcorehatchZ;
extern void *_file_LameE;
extern void *_file_LameJ;
extern void *_file_LameP;
extern void *_file_Lame_str_gZ;
extern void *_file_Lame_str_fZ;
extern void *_file_Lame_str_sZ;
extern void *_file_Lame_str_iZ;
extern void *_file_LarchE;
extern void *_file_LarchJ;
extern void *_file_LarchP;
extern void *_file_Larch_str_gZ;
extern void *_file_Larch_str_fZ;
extern void *_file_Larch_str_sZ;
extern void *_file_Larch_str_iZ;
extern void *_file_LarecE;
extern void *_file_LarecJ;
extern void *_file_LarecP;
extern void *_file_Larec_str_gZ;
extern void *_file_Larec_str_fZ;
extern void *_file_Larec_str_sZ;
extern void *_file_Larec_str_iZ;
extern void *_file_LarkE;
extern void *_file_LarkJ;
extern void *_file_LarkP;
extern void *_file_Lark_str_gZ;
extern void *_file_Lark_str_fZ;
extern void *_file_Lark_str_sZ;
extern void *_file_Lark_str_iZ;
extern void *_file_LashE;
extern void *_file_LashJ;
extern void *_file_LashP;
extern void *_file_Lash_str_gZ;
extern void *_file_Lash_str_fZ;
extern void *_file_Lash_str_sZ;
extern void *_file_Lash_str_iZ;
extern void *_file_LateE;
extern void *_file_LateJ;
extern void *_file_LateP;
extern void *_file_Late_str_gZ;
extern void *_file_Late_str_fZ;
extern void *_file_Late_str_sZ;
extern void *_file_Late_str_iZ;
extern void *_file_LaztE;
extern void *_file_LaztJ;
extern void *_file_LaztP;
extern void *_file_Lazt_str_gZ;
extern void *_file_Lazt_str_fZ;
extern void *_file_Lazt_str_sZ;
extern void *_file_Lazt_str_iZ;
extern void *_file_LcatE;
extern void *_file_LcatJ;
extern void *_file_LcatP;
extern void *_file_Lcat_str_gZ;
extern void *_file_Lcat_str_fZ;
extern void *_file_Lcat_str_sZ;
extern void *_file_Lcat_str_iZ;
extern void *_file_LcaveE;
extern void *_file_LcaveJ;
extern void *_file_LcaveP;
extern void *_file_Lcave_str_gZ;
extern void *_file_Lcave_str_fZ;
extern void *_file_Lcave_str_sZ;
extern void *_file_Lcave_str_iZ;
extern void *_file_LcradE;
extern void *_file_LcradJ;
extern void *_file_LcradP;
extern void *_file_Lcrad_str_gZ;
extern void *_file_Lcrad_str_fZ;
extern void *_file_Lcrad_str_sZ;
extern void *_file_Lcrad_str_iZ;
extern void *_file_LcrypE;
extern void *_file_LcrypJ;
extern void *_file_LcrypP;
extern void *_file_Lcryp_str_gZ;
extern void *_file_Lcryp_str_fZ;
extern void *_file_Lcryp_str_sZ;
extern void *_file_Lcryp_str_iZ;
extern void *_file_LdamE;
extern void *_file_LdamJ;
extern void *_file_LdamP;
extern void *_file_Ldam_str_gZ;
extern void *_file_Ldam_str_fZ;
extern void *_file_Ldam_str_sZ;
extern void *_file_Ldam_str_iZ;
extern void *_file_LdepoE;
extern void *_file_LdepoJ;
extern void *_file_LdepoP;
extern void *_file_Ldepo_str_gZ;
extern void *_file_Ldepo_str_fZ;
extern void *_file_Ldepo_str_sZ;
extern void *_file_Ldepo_str_iZ;
extern void *_file_LdestE;
extern void *_file_LdestJ;
extern void *_file_LdestP;
extern void *_file_Ldest_str_gZ;
extern void *_file_Ldest_str_fZ;
extern void *_file_Ldest_str_sZ;
extern void *_file_Ldest_str_iZ;
extern void *_file_LdishE;
extern void *_file_LdishJ;
extern void *_file_LdishP;
extern void *_file_Ldish_str_gZ;
extern void *_file_Ldish_str_fZ;
extern void *_file_Ldish_str_sZ;
extern void *_file_Ldish_str_iZ;
extern void *_file_LearE;
extern void *_file_LearJ;
extern void *_file_LearP;
extern void *_file_Lear_str_gZ;
extern void *_file_Lear_str_fZ;
extern void *_file_Lear_str_sZ;
extern void *_file_Lear_str_iZ;
extern void *_file_LeldE;
extern void *_file_LeldJ;
extern void *_file_LeldP;
extern void *_file_Leld_str_gZ;
extern void *_file_Leld_str_fZ;
extern void *_file_Leld_str_sZ;
extern void *_file_Leld_str_iZ;
extern void *_file_LgunE;
extern void *_file_LgunJ;
extern void *_file_LgunP;
extern void *_file_Lgun_str_gZ;
extern void *_file_Lgun_str_fZ;
extern void *_file_Lgun_str_sZ;
extern void *_file_Lgun_str_iZ;
extern void *_file_LimpE;
extern void *_file_LimpJ;
extern void *_file_LimpP;
extern void *_file_Limp_str_gZ;
extern void *_file_Limp_str_fZ;
extern void *_file_Limp_str_sZ;
extern void *_file_Limp_str_iZ;
extern void *_file_LjunE;
extern void *_file_LjunJ;
extern void *_file_LjunP;
extern void *_file_Ljun_str_gZ;
extern void *_file_Ljun_str_fZ;
extern void *_file_Ljun_str_sZ;
extern void *_file_Ljun_str_iZ;
extern void *_file_LlamE;
extern void *_file_LlamJ;
extern void *_file_LlamP;
extern void *_file_Llam_str_gZ;
extern void *_file_Llam_str_fZ;
extern void *_file_Llam_str_sZ;
extern void *_file_Llam_str_iZ;
extern void *_file_LleeE;
extern void *_file_LleeJ;
extern void *_file_LleeP;
extern void *_file_Llee_str_gZ;
extern void *_file_Llee_str_fZ;
extern void *_file_Llee_str_sZ;
extern void *_file_Llee_str_iZ;
extern void *_file_LlenE;
extern void *_file_LlenJ;
extern void *_file_LlenP;
extern void *_file_Llen_str_gZ;
extern void *_file_Llen_str_fZ;
extern void *_file_Llen_str_sZ;
extern void *_file_Llen_str_iZ;
extern void *_file_LlipE;
extern void *_file_LlipJ;
extern void *_file_LlipP;
extern void *_file_Llip_str_gZ;
extern void *_file_Llip_str_fZ;
extern void *_file_Llip_str_sZ;
extern void *_file_Llip_str_iZ;
extern void *_file_LlueE;
extern void *_file_LlueJ;
extern void *_file_LlueP;
extern void *_file_Llue_str_gZ;
extern void *_file_Llue_str_fZ;
extern void *_file_Llue_str_sZ;
extern void *_file_Llue_str_iZ;
extern void *_file_LmiscE;
extern void *_file_LmiscJ;
extern void *_file_LmiscP;
extern void *_file_Lmisc_str_gZ;
extern void *_file_Lmisc_str_fZ;
extern void *_file_Lmisc_str_sZ;
extern void *_file_Lmisc_str_iZ;
extern void *_file_Lmp10E;
extern void *_file_Lmp10J;
extern void *_file_Lmp10P;
extern void *_file_Lmp10_str_gZ;
extern void *_file_Lmp10_str_fZ;
extern void *_file_Lmp10_str_sZ;
extern void *_file_Lmp10_str_iZ;
extern void *_file_Lmp11E;
extern void *_file_Lmp11J;
extern void *_file_Lmp11P;
extern void *_file_Lmp11_str_gZ;
extern void *_file_Lmp11_str_fZ;
extern void *_file_Lmp11_str_sZ;
extern void *_file_Lmp11_str_iZ;
extern void *_file_Lmp12E;
extern void *_file_Lmp12J;
extern void *_file_Lmp12P;
extern void *_file_Lmp12_str_gZ;
extern void *_file_Lmp12_str_fZ;
extern void *_file_Lmp12_str_sZ;
extern void *_file_Lmp12_str_iZ;
extern void *_file_Lmp13E;
extern void *_file_Lmp13J;
extern void *_file_Lmp13P;
extern void *_file_Lmp13_str_gZ;
extern void *_file_Lmp13_str_fZ;
extern void *_file_Lmp13_str_sZ;
extern void *_file_Lmp13_str_iZ;
extern void *_file_Lmp14E;
extern void *_file_Lmp14J;
extern void *_file_Lmp14P;
extern void *_file_Lmp14_str_gZ;
extern void *_file_Lmp14_str_fZ;
extern void *_file_Lmp14_str_sZ;
extern void *_file_Lmp14_str_iZ;
extern void *_file_Lmp15E;
extern void *_file_Lmp15J;
extern void *_file_Lmp15P;
extern void *_file_Lmp15_str_gZ;
extern void *_file_Lmp15_str_fZ;
extern void *_file_Lmp15_str_sZ;
extern void *_file_Lmp15_str_iZ;
extern void *_file_Lmp16E;
extern void *_file_Lmp16J;
extern void *_file_Lmp16P;
extern void *_file_Lmp16_str_gZ;
extern void *_file_Lmp16_str_fZ;
extern void *_file_Lmp16_str_sZ;
extern void *_file_Lmp16_str_iZ;
extern void *_file_Lmp17E;
extern void *_file_Lmp17J;
extern void *_file_Lmp17P;
extern void *_file_Lmp17_str_gZ;
extern void *_file_Lmp17_str_fZ;
extern void *_file_Lmp17_str_sZ;
extern void *_file_Lmp17_str_iZ;
extern void *_file_Lmp18E;
extern void *_file_Lmp18J;
extern void *_file_Lmp18P;
extern void *_file_Lmp18_str_gZ;
extern void *_file_Lmp18_str_fZ;
extern void *_file_Lmp18_str_sZ;
extern void *_file_Lmp18_str_iZ;
extern void *_file_Lmp19E;
extern void *_file_Lmp19J;
extern void *_file_Lmp19P;
extern void *_file_Lmp19_str_gZ;
extern void *_file_Lmp19_str_fZ;
extern void *_file_Lmp19_str_sZ;
extern void *_file_Lmp19_str_iZ;
extern void *_file_Lmp1E;
extern void *_file_Lmp1J;
extern void *_file_Lmp1P;
extern void *_file_Lmp1_str_gZ;
extern void *_file_Lmp1_str_fZ;
extern void *_file_Lmp1_str_sZ;
extern void *_file_Lmp1_str_iZ;
extern void *_file_Lmp20E;
extern void *_file_Lmp20J;
extern void *_file_Lmp20P;
extern void *_file_Lmp20_str_gZ;
extern void *_file_Lmp20_str_fZ;
extern void *_file_Lmp20_str_sZ;
extern void *_file_Lmp20_str_iZ;
extern void *_file_Lmp2E;
extern void *_file_Lmp2J;
extern void *_file_Lmp2P;
extern void *_file_Lmp2_str_gZ;
extern void *_file_Lmp2_str_fZ;
extern void *_file_Lmp2_str_sZ;
extern void *_file_Lmp2_str_iZ;
extern void *_file_Lmp3E;
extern void *_file_Lmp3J;
extern void *_file_Lmp3P;
extern void *_file_Lmp3_str_gZ;
extern void *_file_Lmp3_str_fZ;
extern void *_file_Lmp3_str_sZ;
extern void *_file_Lmp3_str_iZ;
extern void *_file_Lmp4E;
extern void *_file_Lmp4J;
extern void *_file_Lmp4P;
extern void *_file_Lmp4_str_gZ;
extern void *_file_Lmp4_str_fZ;
extern void *_file_Lmp4_str_sZ;
extern void *_file_Lmp4_str_iZ;
extern void *_file_Lmp5E;
extern void *_file_Lmp5J;
extern void *_file_Lmp5P;
extern void *_file_Lmp5_str_gZ;
extern void *_file_Lmp5_str_fZ;
extern void *_file_Lmp5_str_sZ;
extern void *_file_Lmp5_str_iZ;
extern void *_file_Lmp6E;
extern void *_file_Lmp6J;
extern void *_file_Lmp6P;
extern void *_file_Lmp6_str_gZ;
extern void *_file_Lmp6_str_fZ;
extern void *_file_Lmp6_str_sZ;
extern void *_file_Lmp6_str_iZ;
extern void *_file_Lmp7E;
extern void *_file_Lmp7J;
extern void *_file_Lmp7P;
extern void *_file_Lmp7_str_gZ;
extern void *_file_Lmp7_str_fZ;
extern void *_file_Lmp7_str_sZ;
extern void *_file_Lmp7_str_iZ;
extern void *_file_Lmp8E;
extern void *_file_Lmp8J;
extern void *_file_Lmp8P;
extern void *_file_Lmp8_str_gZ;
extern void *_file_Lmp8_str_fZ;
extern void *_file_Lmp8_str_sZ;
extern void *_file_Lmp8_str_iZ;
extern void *_file_Lmp9E;
extern void *_file_Lmp9J;
extern void *_file_Lmp9P;
extern void *_file_Lmp9_str_gZ;
extern void *_file_Lmp9_str_fZ;
extern void *_file_Lmp9_str_sZ;
extern void *_file_Lmp9_str_iZ;
extern void *_file_LmpmenuE;
extern void *_file_LmpmenuJ;
extern void *_file_LmpmenuP;
extern void *_file_Lmpmenu_str_gZ;
extern void *_file_Lmpmenu_str_fZ;
extern void *_file_Lmpmenu_str_sZ;
extern void *_file_Lmpmenu_str_iZ;
extern void *_file_LmpweaponsE;
extern void *_file_LmpweaponsJ;
extern void *_file_LmpweaponsP;
extern void *_file_Lmpweapons_str_gZ;
extern void *_file_Lmpweapons_str_fZ;
extern void *_file_Lmpweapons_str_sZ;
extern void *_file_Lmpweapons_str_iZ;
extern void *_file_LoatE;
extern void *_file_LoatJ;
extern void *_file_LoatP;
extern void *_file_Loat_str_gZ;
extern void *_file_Loat_str_fZ;
extern void *_file_Loat_str_sZ;
extern void *_file_Loat_str_iZ;
extern void *_file_LoldE;
extern void *_file_LoldJ;
extern void *_file_LoldP;
extern void *_file_Lold_str_gZ;
extern void *_file_Lold_str_fZ;
extern void *_file_Lold_str_sZ;
extern void *_file_Lold_str_iZ;
extern void *_file_LoptionsE;
extern void *_file_LoptionsJ;
extern void *_file_LoptionsP;
extern void *_file_Loptions_str_gZ;
extern void *_file_Loptions_str_fZ;
extern void *_file_Loptions_str_sZ;
extern void *_file_Loptions_str_iZ;
extern void *_file_LpamE;
extern void *_file_LpamJ;
extern void *_file_LpamP;
extern void *_file_Lpam_str_gZ;
extern void *_file_Lpam_str_fZ;
extern void *_file_Lpam_str_sZ;
extern void *_file_Lpam_str_iZ;
extern void *_file_LpeteE;
extern void *_file_LpeteJ;
extern void *_file_LpeteP;
extern void *_file_Lpete_str_gZ;
extern void *_file_Lpete_str_fZ;
extern void *_file_Lpete_str_sZ;
extern void *_file_Lpete_str_iZ;
extern void *_file_LpropobjE;
extern void *_file_LpropobjJ;
extern void *_file_LpropobjP;
extern void *_file_Lpropobj_str_gZ;
extern void *_file_Lpropobj_str_fZ;
extern void *_file_Lpropobj_str_sZ;
extern void *_file_Lpropobj_str_iZ;
extern void *_file_LrefE;
extern void *_file_LrefJ;
extern void *_file_LrefP;
extern void *_file_Lref_str_gZ;
extern void *_file_Lref_str_fZ;
extern void *_file_Lref_str_sZ;
extern void *_file_Lref_str_iZ;
extern void *_file_LritE;
extern void *_file_LritJ;
extern void *_file_LritP;
extern void *_file_Lrit_str_gZ;
extern void *_file_Lrit_str_fZ;
extern void *_file_Lrit_str_sZ;
extern void *_file_Lrit_str_iZ;
extern void *_file_LrunE;
extern void *_file_LrunJ;
extern void *_file_LrunP;
extern void *_file_Lrun_str_gZ;
extern void *_file_Lrun_str_fZ;
extern void *_file_Lrun_str_sZ;
extern void *_file_Lrun_str_iZ;
extern void *_file_LsevE;
extern void *_file_LsevJ;
extern void *_file_LsevP;
extern void *_file_Lsev_str_gZ;
extern void *_file_Lsev_str_fZ;
extern void *_file_Lsev_str_sZ;
extern void *_file_Lsev_str_iZ;
extern void *_file_LsevbE;
extern void *_file_LsevbJ;
extern void *_file_LsevbP;
extern void *_file_Lsevb_str_gZ;
extern void *_file_Lsevb_str_fZ;
extern void *_file_Lsevb_str_sZ;
extern void *_file_Lsevb_str_iZ;
extern void *_file_LsevxE;
extern void *_file_LsevxJ;
extern void *_file_LsevxP;
extern void *_file_Lsevx_str_gZ;
extern void *_file_Lsevx_str_fZ;
extern void *_file_Lsevx_str_sZ;
extern void *_file_Lsevx_str_iZ;
extern void *_file_LsevxbE;
extern void *_file_LsevxbJ;
extern void *_file_LsevxbP;
extern void *_file_Lsevxb_str_gZ;
extern void *_file_Lsevxb_str_fZ;
extern void *_file_Lsevxb_str_sZ;
extern void *_file_Lsevxb_str_iZ;
extern void *_file_LshoE;
extern void *_file_LshoJ;
extern void *_file_LshoP;
extern void *_file_Lsho_str_gZ;
extern void *_file_Lsho_str_fZ;
extern void *_file_Lsho_str_sZ;
extern void *_file_Lsho_str_iZ;
extern void *_file_LsiloE;
extern void *_file_LsiloJ;
extern void *_file_LsiloP;
extern void *_file_Lsilo_str_gZ;
extern void *_file_Lsilo_str_fZ;
extern void *_file_Lsilo_str_sZ;
extern void *_file_Lsilo_str_iZ;
extern void *_file_LstatE;
extern void *_file_LstatJ;
extern void *_file_LstatP;
extern void *_file_Lstat_str_gZ;
extern void *_file_Lstat_str_fZ;
extern void *_file_Lstat_str_sZ;
extern void *_file_Lstat_str_iZ;
extern void *_file_LtitleE;
extern void *_file_LtitleJ;
extern void *_file_LtitleP;
extern void *_file_Ltitle_str_gZ;
extern void *_file_Ltitle_str_fZ;
extern void *_file_Ltitle_str_sZ;
extern void *_file_Ltitle_str_iZ;
extern void *_file_LtraE;
extern void *_file_LtraJ;
extern void *_file_LtraP;
extern void *_file_Ltra_str_gZ;
extern void *_file_Ltra_str_fZ;
extern void *_file_Ltra_str_sZ;
extern void *_file_Ltra_str_iZ;
extern void *_file_LuffE;
extern void *_file_LuffJ;
extern void *_file_LuffP;
extern void *_file_Luff_str_gZ;
extern void *_file_Luff_str_fZ;
extern void *_file_Luff_str_sZ;
extern void *_file_Luff_str_iZ;
extern void *_file_LwaxE;
extern void *_file_LwaxJ;
extern void *_file_LwaxP;
extern void *_file_Lwax_str_gZ;
extern void *_file_Lwax_str_fZ;
extern void *_file_Lwax_str_sZ;
extern void *_file_Lwax_str_iZ;
extern void *_file_Pa51grateZ;
extern void *_file_GecmmineZ;
extern void *_file_GcommsuplinkZ;
extern void *_file_GirscannerZ;
extern void *_file_Paf1escapedoorZ;
extern void *_file_PprescapsuleZ;
extern void *_file_PskedarbridgeZ;
extern void *_file_Ppelagicdoor2Z;
extern void *_file_Avault2M;
extern void *_file_Ap29_12_elM;
extern void *_file_Pttb_boxZ;
extern void *_file_PinstfrontdoorZ;
extern void *_file_Ap14_09_joM;
extern void *_file_Ap19_07_joM;
extern void *_file_Ap19_08_joM;
extern void *_file_PchrlaserZ;
extern void *_file_PbaftaZ;
extern void *_file_PchrsonicscrewerZ;
extern void *_file_PchrlumphammerZ;
extern void *_file_PskedarbombZ;
extern void *_file_PexplosivebrickZ;
extern void *_file_PresearchtapeZ;
extern void *_file_PziggycardZ;
extern void *_file_PsafeitemZ;
extern void *_file_Ghand_elvisZ;
extern void *_file_Paf1_tableZ;
extern void *_file_Ghand_a51guardZ;
extern void *_file_Ghand_ddshockZ;
extern void *_file_Ghand_blackguardZ;
extern void *_file_Ghand_ddfodderZ;
extern void *_file_Ghand_ddbioZ;
extern void *_file_Ghand_a51airmanZ;
extern void *_file_Ghand_g5guardZ;
extern void *_file_Ghand_cisoldierZ;
extern void *_file_PsensitiveinfoZ;
extern void *_file_PrussdarZ;
extern void *_file_PxrayspecsZ;
extern void *_file_PchreyespyZ;
extern void *_file_PchrdoordecoderZ;
extern void *_file_PbriefcaseZ;
extern void *_file_PsuitcaseZ;
extern void *_file_PshuttledoorZ;
extern void *_file_PruinbridgeZ;
extern void *_file_PsecretindoorZ;
extern void *_file_PskpuzzleobjectZ;
extern void *_file_Pa51liftdoorZ;
extern void *_file_Acicarr06M;
extern void *_file_Acicarr11M;
extern void *_file_Acifarr08M;
extern void *_file_Acifarr12M;
extern void *_file_Acifema01M;
extern void *_file_Acifema04M;
extern void *_file_Acifema07M;
extern void *_file_Acifema08M;
extern void *_file_Acifema09M;
extern void *_file_Acifema14M;
extern void *_file_Acifost08M;
extern void *_file_Acifost12M;
extern void *_file_Acigrim05M;
extern void *_file_Acigrim06M;
extern void *_file_Acigrim07M;
extern void *_file_Acigrim08M;
extern void *_file_Acigrim09M;
extern void *_file_Acigrim10M;
extern void *_file_Acihopk09M;
extern void *_file_Acihopk11M;
extern void *_file_Acimale02M;
extern void *_file_Acimale03M;
extern void *_file_Acimale07M;
extern void *_file_Acimale09M;
extern void *_file_Acimale11M;
extern void *_file_Acimale13M;
extern void *_file_Aciroge08M;
extern void *_file_Aciroge12M;
extern void *_file_Cdark_negotiatorZ;
extern void *_file_PcihubZ;
extern void *_file_Psk_ship_door2Z;
extern void *_file_Psk_window1Z;
extern void *_file_Psk_hangardoorb_topZ;
extern void *_file_Psk_hangardoorb_botZ;
extern void *_file_Paf1_innerdoorZ;
extern void *_file_Plaser_postZ;
extern void *_file_Atrfost01M;
extern void *_file_Atrfost02M;
extern void *_file_Atrfost03M;
extern void *_file_Atrcarr09M;
extern void *_file_Atrcarr10M;
extern void *_file_Atrcarr11M;
extern void *_file_Acifarr01M;
extern void *_file_Acifarr02M;
extern void *_file_Acifarr03M;
extern void *_file_Acigrim01M;
extern void *_file_Acigrim03M;
extern void *_file_Acigrim04M;
extern void *_file_Acihopk01M;
extern void *_file_Acihopk04M;
extern void *_file_Acihopk06M;
extern void *_file_Aciroge01M;
extern void *_file_Aciroge02M;
extern void *_file_Atrroge01M;
extern void *_file_Acicarr07M;
extern void *_file_Acicarr08M;
extern void *_file_PtargetampZ;
extern void *_file_Psk_liftZ;
extern void *_file_PknockknockZ;
extern void *_file_PcetandoorZ;
extern void *_file_Ajoinst01M;
extern void *_file_Ajoinst02M;
extern void *_file_Ajoinst03M;
extern void *_file_Ajoinst04M;
extern void *_file_Ap25_03_joM;
extern void *_file_Paf1rubbleZ;
extern void *_file_Pdd_dr_nonrefZ;
extern void *_file_CheadtimZ;
extern void *_file_CheadgrantZ;
extern void *_file_CheadpennyZ;
extern void *_file_CheadrobinZ;
extern void *_file_CheadalexZ;
extern void *_file_CheadjulianneZ;
extern void *_file_CheadlauraZ;
extern void *_file_CheaddavecZ;
extern void *_file_CheadkenZ;
extern void *_file_CheadjoelZ;
extern void *_file_PcetandoorsideZ;
extern void *_file_Ap29_13_joM;
extern void *_file_Ap29_14_joM;
extern void *_file_Acicarr09M;
extern void *_file_Acicarr10M;
extern void *_file_PbuddybridgeZ;
extern void *_file_CheadcookZ;
extern void *_file_CheadpryceZ;
extern void *_file_CheadsilkeZ;
extern void *_file_CheadsmithZ;
extern void *_file_CheadgarethZ;
extern void *_file_CheadmurchieZ;
extern void *_file_CheadwongZ;
extern void *_file_CheadcarterZ;
extern void *_file_CheadtintinZ;
extern void *_file_CheadmuntonZ;
extern void *_file_CheadstamperZ;
extern void *_file_CheadjonesZ;
extern void *_file_CheadphelpsZ;
extern void *_file_Ap29_15_joM;
extern void *_file_Ap16_03_joM;
extern void *_file_Acarrbye02M;
extern void *_file_Asaucerexp1M;
extern void *_filesSegmentRomEnd;

// 20df0
u16 var8007add0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
};

// 20e10
struct stagethinglist stagethinglist_20e10 = {
	STAGE_DUEL, 16, var8007add0,
};

// 20e18
u16 var8007adf8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
};

// 20e3c
struct stagethinglist stagethinglist_20e3c = {
	STAGE_MP_VILLA, 18, var8007adf8,
};

// 20e44
u16 var8007ae24[] = {
	0x0000,
};

// 20e48
struct stagethinglist stagethinglist_20e48 = {
	STAGE_RETAKING, 1, var8007ae24,
};

// 20e50
u16 var8007ae30[] = {
	0x0000,
	0x0101,
};

// 20e54
struct stagethinglist stagethinglist_20e54 = {
	0x0f, 2, var8007ae30,
};

// 20e5c
u16 var8007ae3c[] = {
	0x0000,
};

// 20e60
struct stagethinglist stagethinglist_20e60 = {
	STAGE_TEST_SILO, 1, var8007ae3c,
};

// 20e68
u16 var8007ae48[] = {
	0x0000,
};

// 20e6c
struct stagethinglist stagethinglist_20e6c = {
	0x15, 1, var8007ae48,
};

// 20e74
u16 var8007ae54[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20e80
struct stagethinglist stagethinglist_20e80 = {
	STAGE_ESCAPE, 5, var8007ae54,
};

// 20e88
u16 var8007ae68[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
};

// 20e94
struct stagethinglist stagethinglist_20e94 = {
	STAGE_WAR, 6, var8007ae68,
};

// 20e9c
u16 var8007ae7c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20ea4
struct stagethinglist stagethinglist_20ea4 = {
	0x11, 3, var8007ae7c,
};

// 20eac
u16 var8007ae8c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
};

// 20ec8
struct stagethinglist stagethinglist_20ec8 = {
	0x13, 13, var8007ae8c,
};

// 20ed0
u16 var8007aeb0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20edc
struct stagethinglist stagethinglist_20edc = {
	STAGE_TEST_ARCH, 5, var8007aeb0,
};

// 20ee4
u16 var8007aec4[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
};

// 20eec
struct stagethinglist stagethinglist_20eec = {
	0x12, 4, var8007aec4,
};

// 20ef4
u16 var8007aed4[] = {
	0x0000,
};

// 20ef8
struct stagethinglist stagethinglist_20ef8 = {
	0x10, 1, var8007aed4,
};

// 20f00
u16 var8007aee0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20f0c
struct stagethinglist stagethinglist_20f0c = {
	STAGE_MP_RAVINE, 5, var8007aee0,
};

// 20f14
u16 var8007aef4[] = {
	0x0000,
};

// 20f18
struct stagethinglist stagethinglist_20f18 = {
	0x0c, 1, var8007aef4,
};

// 20f20
u16 var8007af00[] = {
	0x0000,
};

// 20f24
struct stagethinglist stagethinglist_20f24 = {
	STAGE_CHICAGO, 1, var8007af00,
};

// 20f2c
u16 var8007af0c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
};

// 20f50
struct stagethinglist stagethinglist_20f50 = {
	STAGE_G5BUILDING, 17, var8007af0c,
};

// 20f58
u16 var8007af38[] = {
	0x0000,
};

// 20f5c
struct stagethinglist stagethinglist_20f5c = {
	STAGE_MP_COMPLEX, 1, var8007af38,
};

// 20f64
u16 var8007af44[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
};

// 20f74
struct stagethinglist stagethinglist_20f74 = {
	STAGE_MP_SKEDAR, 8, var8007af44,
};

// 20f7c
u16 var8007af5c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20f84
struct stagethinglist stagethinglist_20f84 = {
	STAGE_AIRBASE, 3, var8007af5c,
};

// 20f8c
u16 var8007af6c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
};

// 20fb8
struct stagethinglist stagethinglist_20fb8 = {
	STAGE_MP_PIPES, 21, var8007af6c,
};

// 20fc0
u16 var8007afa0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
};

// 20fd8
struct stagethinglist stagethinglist_20fd8 = {
	STAGE_INVESTIGATION, 11, var8007afa0,
};

// 20fe0
u16 var8007afc0[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20fe8
struct stagethinglist stagethinglist_20fe8 = {
	STAGE_MP_FORTRESS, 3, var8007afc0,
};

// 20ff0
u16 var8007afd0[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20ff8
struct stagethinglist stagethinglist_20ff8 = {
	STAGE_MP_WAREHOUSE, 3, var8007afd0,
};

// 21000
u16 var8007afe0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 2100c
struct stagethinglist stagethinglist_2100c = {
	STAGE_MP_FELICITY, 5, var8007afe0,
};

// 21014
u16 var8007aff4[] = {
	0x0000,
};

// 21018
struct stagethinglist stagethinglist_21018 = {
	0x8c, 1, var8007aff4,
};

// 21020
u16 var8007b000[] = {
	0x0000,
};

// 21024
struct stagethinglist stagethinglist_21024 = {
	STAGE_VILLA, 1, var8007b000,
};

// 2102c
u16 var8007b00c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 21034
struct stagethinglist stagethinglist_21034 = {
	0xc8, 3, var8007b00c,
};

// 2103c
u16 var8007b01c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 21084
struct stagethinglist stagethinglist_21084 = {
	0xbb, 35, var8007b01c,
};

// 2108c
struct propdefinition g_Props[] = {
	//                 file                         scale
	/*0x0000*/ { NULL, FILE_PROOFGUN,               0x0199 },
	/*0x0001*/ { NULL, FILE_PGROUNDGUN,             0x0199 },
	/*0x0002*/ { NULL, FILE_PTVSCREEN,              0x0199 },
	/*0x0003*/ { NULL, FILE_PBORG_CRATE,            0x0199 },
	/*0x0004*/ { NULL, FILE_PWINDOW,                0x0199 },
	/*0x0005*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0006*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0007*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0008*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0009*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000a*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000b*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000c*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000d*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000e*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000f*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0010*/ { NULL, FILE_PCRYPTDOOR1B,           0x1000 },
	/*0x0011*/ { NULL, FILE_PCHRBRIEFCASE,          0x0199 },
	/*0x0012*/ { NULL, FILE_PCHRBUG,                0x0199 },
	/*0x0013*/ { NULL, FILE_PCHRDATATHIEF,          0x0199 },
	/*0x0014*/ { NULL, FILE_PNINTENDOLOGO,          0x0199 },
	/*0x0015*/ { NULL, FILE_PDOOR_ROLLERTRAIN,      0x1000 },
	/*0x0016*/ { NULL, FILE_PFLAG,                  0x0199 },
	/*0x0017*/ { NULL, FILE_PMODEMBOX,              0x0199 },
	/*0x0018*/ { NULL, FILE_PDOORCONSOLE,           0x0199 },
	/*0x0019*/ { NULL, FILE_PA51_HORIZ_DOOR_TOP,    0x1000 },
	/*0x001a*/ { NULL, FILE_PA51_HORIZ_DOOR_BOT,    0x1000 },
	/*0x001b*/ { NULL, FILE_PA51_VERT_DOOR_LEFT,    0x1000 },
	/*0x001c*/ { NULL, FILE_PA51_VERT_DOOR_RIGHT,   0x1000 },
	/*0x001d*/ { NULL, FILE_PA51_VERT_DOOR_ST,      0x1000 },
	/*0x001e*/ { NULL, FILE_PA51_HORIZ_DOOR_GL,     0x1000 },
	/*0x001f*/ { NULL, FILE_PA51_HORIZ_DOOR_SECRET, 0x1000 },
	/*0x0020*/ { NULL, FILE_PA51_CRATE1,            0x1000 },
	/*0x0021*/ { NULL, FILE_PA51_CRATE2,            0x1000 },
	/*0x0022*/ { NULL, FILE_PA51_CRATE3,            0x1000 },
	/*0x0023*/ { NULL, FILE_PA51_EXP1,              0x0199 },
	/*0x0024*/ { NULL, FILE_PA51_UNEXP1,            0x1000 },
	/*0x0025*/ { NULL, FILE_PA51_EXP2,              0x0199 },
	/*0x0026*/ { NULL, FILE_PA51_UNEXP2,            0x1000 },
	/*0x0027*/ { NULL, FILE_PA51_UNEXP3,            0x0199 },
	/*0x0028*/ { NULL, FILE_PAIVILLADOOR1,          0x1000 },
	/*0x0029*/ { NULL, FILE_PAIVILLADOOR2A,         0x1000 },
	/*0x002a*/ { NULL, FILE_PAIVILLADOOR4,          0x1000 },
	/*0x002b*/ { NULL, FILE_PA51_LIFT_HANGAR,       0x1000 },
	/*0x002c*/ { NULL, FILE_PA51_LIFT_CONTROL,      0x1000 },
	/*0x002d*/ { NULL, FILE_PA51_LIFT_STORE,        0x1000 },
	/*0x002e*/ { NULL, FILE_PA51_LIFT_THINWALL,     0x1000 },
	/*0x002f*/ { NULL, FILE_PAIVILLABOT1,           0x1000 },
	/*0x0030*/ { NULL, FILE_PAIVILLABOT2,           0x1000 },
	/*0x0031*/ { NULL, FILE_PAIVILLABOT3,           0x1000 },
	/*0x0032*/ { NULL, FILE_PAIVILLAWINDMILL,       0x1000 },
	/*0x0033*/ { NULL, FILE_PHOVERBED,              0x0199 },
	/*0x0034*/ { NULL, FILE_PMARKER,                0x1000 },
	/*0x0035*/ { NULL, FILE_PALDOOR_R,              0x1000 },
	/*0x0036*/ { NULL, FILE_PALDOOR_L,              0x1000 },
	/*0x0037*/ { NULL, FILE_PDD_LIFTR,              0x1000 },
	/*0x0038*/ { NULL, FILE_PDD_FANROOF,            0x1000 },
	/*0x0039*/ { NULL, FILE_PDD_FANWALL,            0x1000 },
	/*0x003a*/ { NULL, FILE_PHOVBIKE,               0x0199 },
	/*0x003b*/ { NULL, FILE_PDD_OFFICEDOOR,         0x1000 },
	/*0x003c*/ { NULL, FILE_PDD_PLANTRUBBER,        0x1000 },
	/*0x003d*/ { NULL, FILE_PDD_PLANTSPIKE,         0x1000 },
	/*0x003e*/ { NULL, FILE_PDD_PLANTSPIDER,        0x1000 },
	/*0x003f*/ { NULL, FILE_PDD_WINDOW,             0x1000 },
	/*0x0040*/ { NULL, FILE_PDD_REDSOFA,            0x1000 },
	/*0x0041*/ { NULL, FILE_PDD_REDARM,             0x1000 },
	/*0x0042*/ { NULL, FILE_PDD_SERVICEDOOR,        0x1000 },
	/*0x0043*/ { NULL, FILE_PDD_WINDDOOR,           0x1000 },
	/*0x0044*/ { NULL, FILE_PDD_LIFTDOOR,           0x1000 },
	/*0x0045*/ { NULL, FILE_PDD_VERTBLIND,          0x1000 },
	/*0x0046*/ { NULL, FILE_PDD_DESK,               0x1000 },
	/*0x0047*/ { NULL, FILE_PDD_CHAIR,              0x1000 },
	/*0x0048*/ { NULL, FILE_PNLOGO,                 0x0199 },
	/*0x0049*/ { NULL, FILE_PNLOGO2,                0x0199 },
	/*0x004a*/ { NULL, FILE_PNLOGO3,                0x0199 },
	/*0x004b*/ { NULL, FILE_PPERFECTDARK,           0x0199 },
	/*0x004c*/ { NULL, FILE_PPDONE,                 0x0199 },
	/*0x004d*/ { NULL, FILE_PPDTWO,                 0x0199 },
	/*0x004e*/ { NULL, FILE_PPDTHREE,               0x0199 },
	/*0x004f*/ { NULL, FILE_PPDFOUR,                0x0199 },
	/*0x0050*/ { NULL, FILE_PDD_HOVCOP,             0x1000 },
	/*0x0051*/ { NULL, FILE_PDD_HOVMOTO,            0x1000 },
	/*0x0052*/ { NULL, FILE_PDD_HOVTRUCK,           0x1000 },
	/*0x0053*/ { NULL, FILE_PDD_HOVCAR,             0x1000 },
	/*0x0054*/ { NULL, FILE_PDD_HOVCAB,             0x1000 },
	/*0x0055*/ { NULL, FILE_PDD_AC_UNEXP,           0x1000 },
	/*0x0056*/ { NULL, FILE_PDD_AC_EXP,             0x1000 },
	/*0x0057*/ { NULL, FILE_PDD_ACBOT_UNEXP,        0x1000 },
	/*0x0058*/ { NULL, FILE_PDD_ACBOT_EXP,          0x1000 },
	/*0x0059*/ { NULL, FILE_PPC1,                   0x1000 },
	/*0x005a*/ { NULL, FILE_PHOVERCRATE1,           0x1000 },
	/*0x005b*/ { NULL, FILE_PDROPSHIP,              0x0199 },
	/*0x005c*/ { NULL, FILE_PAL_AIRLOCK,            0x1000 },
	/*0x005d*/ { NULL, FILE_PAL_DOCKLIFT,           0x1000 },
	/*0x005e*/ { NULL, FILE_PCASE,                  0x1000 },
	/*0x005f*/ { NULL, FILE_PDD_STONEDESK,          0x1000 },
	/*0x0060*/ { NULL, FILE_PMEDLABWIN1,            0x0199 },
	/*0x0061*/ { NULL, FILE_PMEDLABWIN2,            0x0199 },
	/*0x0062*/ { NULL, FILE_PA51TABLE,              0x1000 },
	/*0x0063*/ { NULL, FILE_PA51CHAIR,              0x1000 },
	/*0x0064*/ { NULL, FILE_PA51SCREEN,             0x1000 },
	/*0x0065*/ { NULL, FILE_PA51WASTEBIN,           0x1000 },
	/*0x0066*/ { NULL, FILE_PA51DESKENT,            0x0199 },
	/*0x0067*/ { NULL, FILE_PA51TROLLEY,            0x1000 },
	/*0x0068*/ { NULL, FILE_PA51DIVIDE,             0x1000 },
	/*0x0069*/ { NULL, FILE_PA51BOARD,              0x1000 },
	/*0x006a*/ { NULL, FILE_PSKCREV_EXP1,           0x1000 },
	/*0x006b*/ { NULL, FILE_PSKCREV_UNEXP1,         0x1000 },
	/*0x006c*/ { NULL, FILE_PSKTNL_EXP1,            0x1000 },
	/*0x006d*/ { NULL, FILE_PSKTNL_UNEXP1,          0x1000 },
	/*0x006e*/ { NULL, FILE_PSK_DOOR1,              0x1000 },
	/*0x006f*/ { NULL, FILE_PSK_SHIP_DOOR1,         0x1000 },
	/*0x0070*/ { NULL, FILE_PSK_SHIP_HOLO1,         0x1000 },
	/*0x0071*/ { NULL, FILE_PSK_SHIP_HOLO2,         0x1000 },
	/*0x0072*/ { NULL, FILE_PSK_SHIP_HULLDOOR1,     0x1000 },
	/*0x0073*/ { NULL, FILE_PSK_SHIP_HULLDOOR2,     0x1000 },
	/*0x0074*/ { NULL, FILE_PSK_SHIP_HULLDOOR3,     0x1000 },
	/*0x0075*/ { NULL, FILE_PSK_SHIP_HULLDOOR4,     0x1000 },
	/*0x0076*/ { NULL, FILE_PSK_FIGHTER1,           0x1000 },
	/*0x0077*/ { NULL, FILE_PSK_CRYOPOD1_TOP,       0x1000 },
	/*0x0078*/ { NULL, FILE_PSK_CRYOPOD1_BOT,       0x1000 },
	/*0x0079*/ { NULL, FILE_PSK_UNDER_GENERATOR,    0x1000 },
	/*0x007a*/ { NULL, FILE_PSK_UNDER_TRANS,        0x1000 },
	/*0x007b*/ { NULL, FILE_PSK_HANGARDOOR_TOP,     0x1000 },
	/*0x007c*/ { NULL, FILE_PSK_HANGARDOOR_BOT,     0x1000 },
	/*0x007d*/ { NULL, FILE_PDOOR2_G5,              0x1000 },
	/*0x007e*/ { NULL, FILE_PDOOR1A_G5,             0x1000 },
	/*0x007f*/ { NULL, FILE_PDOOR1B_G5,             0x1000 },
	/*0x0080*/ { NULL, FILE_PDOOR1ATRI_G5,          0x1000 },
	/*0x0081*/ { NULL, FILE_PDOOR2A_G5,             0x1000 },
	/*0x0082*/ { NULL, FILE_PDD_DECODOOR,           0x1000 },
	/*0x0083*/ { NULL, FILE_PDD_SECRETDOOR,         0x1000 },
	/*0x0084*/ { NULL, FILE_PDD_SECRETDOOR2,        0x1000 },
	/*0x0085*/ { NULL, FILE_PDDJUMPSHIP,            0x0199 },
	/*0x0086*/ { NULL, FILE_PTAXICAB,               0x0199 },
	/*0x0087*/ { NULL, FILE_PPOLICECAR,             0x0199 },
	/*0x0088*/ { NULL, FILE_PRAVINELIFT,            0x1000 },
	/*0x0089*/ { NULL, FILE_PDD_LAB_DOOR_BS,        0x1000 },
	/*0x008a*/ { NULL, FILE_PDD_LAB_DOOR_SEC,       0x1000 },
	/*0x008b*/ { NULL, FILE_PDD_LAB_DOOR_WIND,      0x1000 },
	/*0x008c*/ { NULL, FILE_PHOOVERBOT,             0x0800 },
	/*0x008d*/ { NULL, FILE_PTESTERBOT,             0x0800 },
	/*0x008e*/ { NULL, FILE_PDD_LAB_SECTOR2BOT,     0x1000 },
	/*0x008f*/ { NULL, FILE_PDD_LAB_SECTOR2TOP,     0x1000 },
	/*0x0090*/ { NULL, FILE_PDD_LAB_CAUTIONTOP,     0x1000 },
	/*0x0091*/ { NULL, FILE_PDD_LAB_HAZARD,         0x1000 },
	/*0x0092*/ { NULL, FILE_PDD_LAB_CAUTION,        0x1000 },
	/*0x0093*/ { NULL, FILE_PDR_CAROLL_DOOR,        0x1000 },
	/*0x0094*/ { NULL, FILE_PDD_LAB_SECTOR3TOP,     0x1000 },
	/*0x0095*/ { NULL, FILE_PDD_LAB_SECTOR3,        0x1000 },
	/*0x0096*/ { NULL, FILE_PDD_LAB_SECTOR3WIND,    0x1000 },
	/*0x0097*/ { NULL, FILE_PDD_HOVERCOPTER,        0x1000 },
	/*0x0098*/ { NULL, FILE_PDD_LAB_SECTOR4TOP,     0x1000 },
	/*0x0099*/ { NULL, FILE_PDD_LAB_RESTRICTED,     0x1000 },
	/*0x009a*/ { NULL, FILE_PDOOR4A_G5,             0x1000 },
	/*0x009b*/ { NULL, FILE_PDOOR4B_G5,             0x1000 },
	/*0x009c*/ { NULL, FILE_PLASDOOR,               0x1000 },
	/*0x009d*/ { NULL, FILE_PG5SAFEDOOR,            0x1000 },
	/*0x009e*/ { NULL, FILE_PROPE,                  0x0199 },
	/*0x009f*/ { NULL, FILE_PG5_MAINFRAME,          0x1000 },
	/*0x00a0*/ { NULL, FILE_PDR_CAROLL_DOOR_BASE,   0x1000 },
	/*0x00a1*/ { NULL, FILE_PDR_CAROLL_DOOR_MAIN,   0x1000 },
	/*0x00a2*/ { NULL, FILE_PDR_CAROLL_DOOR_LEFT,   0x1000 },
	/*0x00a3*/ { NULL, FILE_PDR_CAROLL_DOOR_RIGHT,  0x1000 },
	/*0x00a4*/ { NULL, FILE_PDR_CAROLL_DOOR_BMAIN,  0x1000 },
	/*0x00a5*/ { NULL, FILE_PDR_CAROLL_DOOR_BLEFT,  0x1000 },
	/*0x00a6*/ { NULL, FILE_PDR_CAROLL_DOOR_BRIGHT, 0x1000 },
	/*0x00a7*/ { NULL, FILE_PDD_BANNER,             0x0199 },
	/*0x00a8*/ { NULL, FILE_PG5_ESCDOORUP,          0x1000 },
	/*0x00a9*/ { NULL, FILE_PG5_ESCDOORUPBOOM,      0x1000 },
	/*0x00aa*/ { NULL, FILE_PG5_ESCDOORDOWN,        0x1000 },
	/*0x00ab*/ { NULL, FILE_PG5_ESCDOORDOWNBOOM,    0x1000 },
	/*0x00ac*/ { NULL, FILE_PDUMPSTER,              0x1000 },
	/*0x00ad*/ { NULL, FILE_PG5CARLIFTDOOR,         0x1000 },
	/*0x00ae*/ { NULL, FILE_PCH_SHUTTER1,           0x1000 },
	/*0x00af*/ { NULL, FILE_PCCTV_PD,               0x1000 },
	/*0x00b0*/ { NULL, FILE_PCOMHUB,                0x1000 },
	/*0x00b1*/ { NULL, FILE_PQUADPOD,               0x1000 },
	/*0x00b2*/ { NULL, FILE_PPD_CONSOLE,            0x1000 },
	/*0x00b3*/ { NULL, FILE_PDD_GRATE,              0x1000 },
	/*0x00b4*/ { NULL, FILE_PLIFT_PLATFORM,         0x1000 },
	/*0x00b5*/ { NULL, FILE_PLIGHTSWITCH,           0x1000 },
	/*0x00b6*/ { NULL, FILE_PBLASTSHIELD,           0x1000 },
	/*0x00b7*/ { NULL, FILE_PLIGHTSWITCH2,          0x0199 },
	/*0x00b8*/ { NULL, FILE_PDD_ACCESSDOORUP,       0x1000 },
	/*0x00b9*/ { NULL, FILE_PDD_ACCESSDOORDN,       0x1000 },
	/*0x00ba*/ { NULL, FILE_PLAB_CONTAINER,         0x1000 },
	/*0x00bb*/ { NULL, FILE_PLAB_CHAIR,             0x1000 },
	/*0x00bc*/ { NULL, FILE_PLAB_TABLE,             0x1000 },
	/*0x00bd*/ { NULL, FILE_PLAB_MICROSCOPE,        0x1000 },
	/*0x00be*/ { NULL, FILE_PLAB_MAINFRAME,         0x1000 },
	/*0x00bf*/ { NULL, FILE_PDD_LABDOOR,            0x1000 },
	/*0x00c0*/ { NULL, FILE_PDD_LAB_DOORTOP,        0x1000 },
	/*0x00c1*/ { NULL, FILE_PMULTI_AMMO_CRATE,      0x1000 },
	/*0x00c2*/ { NULL, FILE_PCHRCHAIN,              0x1000 },
	/*0x00c3*/ { NULL, FILE_PTDOOR,                 0x1000 },
	/*0x00c4*/ { NULL, FILE_PCI_SOFA,               0x1000 },
	/*0x00c5*/ { NULL, FILE_PCI_LIFT,               0x1000 },
	/*0x00c6*/ { NULL, FILE_PCI_LIFTDOOR,           0x1000 },
	/*0x00c7*/ { NULL, FILE_PLASERCUT,              0x0199 },
	/*0x00c8*/ { NULL, FILE_PSK_SHUTTLE,            0x0199 },
	/*0x00c9*/ { NULL, FILE_PNEWVILLADOOR,          0x1000 },
	/*0x00ca*/ { NULL, FILE_PSK_PILLARLEFT,         0x1000 },
	/*0x00cb*/ { NULL, FILE_PSK_PILLARRIGHT,        0x1000 },
	/*0x00cc*/ { NULL, FILE_PSK_PLINTH_T,           0x1000 },
	/*0x00cd*/ { NULL, FILE_PSK_PLINTH_ML,          0x1000 },
	/*0x00ce*/ { NULL, FILE_PSK_PLINTH_MR,          0x1000 },
	/*0x00cf*/ { NULL, FILE_PSK_PLINTH_BL,          0x1000 },
	/*0x00d0*/ { NULL, FILE_PSK_PLINTH_BR,          0x1000 },
	/*0x00d1*/ { NULL, FILE_PSK_FL_SHAD_T,          0x1000 },
	/*0x00d2*/ { NULL, FILE_PSK_FL_SHAD_ML,         0x1000 },
	/*0x00d3*/ { NULL, FILE_PSK_FL_SHAD_MR,         0x1000 },
	/*0x00d4*/ { NULL, FILE_PSK_FL_SHAD_BL,         0x1000 },
	/*0x00d5*/ { NULL, FILE_PSK_FL_SHAD_BR,         0x1000 },
	/*0x00d6*/ { NULL, FILE_PSK_FL_NOSHAD_T,        0x1000 },
	/*0x00d7*/ { NULL, FILE_PSK_FL_NOSHAD_ML,       0x1000 },
	/*0x00d8*/ { NULL, FILE_PSK_FL_NOSHAD_MR,       0x1000 },
	/*0x00d9*/ { NULL, FILE_PSK_FL_NOSHAD_BL,       0x1000 },
	/*0x00da*/ { NULL, FILE_PSK_FL_NOSHAD_BR,       0x1000 },
	/*0x00db*/ { NULL, FILE_PSK_TEMPLECOLUMN1,      0x1000 },
	/*0x00dc*/ { NULL, FILE_PSK_TEMPLECOLUMN2,      0x1000 },
	/*0x00dd*/ { NULL, FILE_PSK_TEMPLECOLUMN3,      0x1000 },
	/*0x00de*/ { NULL, FILE_PSK_SUNSHAD1,           0x1000 },
	/*0x00df*/ { NULL, FILE_PSK_SUNSHAD2,           0x1000 },
	/*0x00e0*/ { NULL, FILE_PSK_SUNNOSHAD1,         0x1000 },
	/*0x00e1*/ { NULL, FILE_PSK_SUNNOSHAD2,         0x1000 },
	/*0x00e2*/ { NULL, FILE_PBARREL,                0x1000 },
	/*0x00e3*/ { NULL, FILE_PGLASS_FLOOR,           0x0199 },
	/*0x00e4*/ { NULL, FILE_PESCA_STEP,             0x0199 },
	/*0x00e5*/ { NULL, FILE_PMATRIX_LIFT,           0x0199 },
	/*0x00e6*/ { NULL, FILE_PRUBBLE1,               0x1000 },
	/*0x00e7*/ { NULL, FILE_PRUBBLE2,               0x1000 },
	/*0x00e8*/ { NULL, FILE_PRUBBLE3,               0x1000 },
	/*0x00e9*/ { NULL, FILE_PRUBBLE4,               0x1000 },
	/*0x00ea*/ { NULL, FILE_PCABLE_CAR,             0x0199 },
	/*0x00eb*/ { NULL, FILE_PELVIS_SAUCER,          0x0199 },
	/*0x00ec*/ { NULL, FILE_PSTEWARDESS_TROLLEY,    0x0199 },
	/*0x00ed*/ { NULL, FILE_PAIRBASE_LIFT_ENCLOSED, 0x0199 },
	/*0x00ee*/ { NULL, FILE_PAIRBASE_LIFT_ANGLE,    0x0199 },
	/*0x00ef*/ { NULL, FILE_PAIRBASE_SAFEDOOR,      0x1000 },
	/*0x00f0*/ { NULL, FILE_PAF1_PILOTCHAIR,        0x0199 },
	/*0x00f1*/ { NULL, FILE_PAF1_PASSCHAIR,         0x0199 },
	/*0x00f2*/ { NULL, FILE_PTESTOBJ,               0x0199 },
	/*0x00f3*/ { NULL, FILE_PCHRNIGHTSIGHT,         0x0c00 },
	/*0x00f4*/ { NULL, FILE_PCHRSHIELD,             0x0199 },
	/*0x00f5*/ { NULL, FILE_PCHRFALCON2,            0x0199 },
	/*0x00f6*/ { NULL, FILE_PCHRLEEGUN1,            0x0199 },
	/*0x00f7*/ { NULL, FILE_PCHRMAULER,             0x0199 },
	/*0x00f8*/ { NULL, FILE_PCHRDY357,              0x0199 },
	/*0x00f9*/ { NULL, FILE_PCHRDY357TRENT,         0x0199 },
	/*0x00fa*/ { NULL, FILE_PCHRMAIANPISTOL,        0x0199 },
	/*0x00fb*/ { NULL, FILE_PCHRFALCON2SIL,         0x0199 },
	/*0x00fc*/ { NULL, FILE_PCHRFALCON2SCOPE,       0x0199 },
	/*0x00fd*/ { NULL, FILE_PCHRCMP150,             0x0199 },
	/*0x00fe*/ { NULL, FILE_PCHRAR34,               0x0199 },
	/*0x00ff*/ { NULL, FILE_PCHRDRAGON,             0x0199 },
	/*0x0100*/ { NULL, FILE_PCHRSUPERDRAGON,        0x0199 },
	/*0x0101*/ { NULL, FILE_PCHRAVENGER,            0x0199 },
	/*0x0102*/ { NULL, FILE_PCHRCYCLONE,            0x0199 },
	/*0x0103*/ { NULL, FILE_PCHRMAIANSMG,           0x0199 },
	/*0x0104*/ { NULL, FILE_PCHRRCP120,             0x0199 },
	/*0x0105*/ { NULL, FILE_PCHRPCGUN,              0x0199 },
	/*0x0106*/ { NULL, FILE_PCHRSHOTGUN,            0x0199 },
	/*0x0107*/ { NULL, FILE_PCHRSKMINIGUN,          0x0199 },
	/*0x0108*/ { NULL, FILE_PCHRDYROCKET,           0x0199 },
	/*0x0109*/ { NULL, FILE_PCHRDEVASTATOR,         0x0199 },
	/*0x010a*/ { NULL, FILE_PCHRSKROCKET,           0x0199 },
	/*0x010b*/ { NULL, FILE_PCHRZ2020,              0x0199 },
	/*0x010c*/ { NULL, FILE_PCHRSNIPERRIFLE,        0x0199 },
	/*0x010d*/ { NULL, FILE_PCHRCROSSBOW,           0x0199 },
	/*0x010e*/ { NULL, FILE_PCHRDRUGGUN,            0x0199 },
	/*0x010f*/ { NULL, FILE_PCHRKNIFE,              0x0199 },
	/*0x0110*/ { NULL, FILE_PCHRNBOMB,              0x0199 },
	/*0x0111*/ { NULL, FILE_PCHRFLASHBANG,          0x0199 },
	/*0x0112*/ { NULL, FILE_PCHRGRENADE,            0x0199 },
	/*0x0113*/ { NULL, FILE_PCHRTIMEDMINE,          0x0199 },
	/*0x0114*/ { NULL, FILE_PCHRPROXIMITYMINE,      0x0199 },
	/*0x0115*/ { NULL, FILE_PCHRREMOTEMINE,         0x0199 },
	/*0x0116*/ { NULL, FILE_PCHRECMMINE,            0x0199 },
	/*0x0117*/ { NULL, FILE_PCHRWPPK,               0x0199 },
	/*0x0118*/ { NULL, FILE_PCHRTT33,               0x0199 },
	/*0x0119*/ { NULL, FILE_PCHRSKORPION,           0x0199 },
	/*0x011a*/ { NULL, FILE_PCHRKALASH,             0x0199 },
	/*0x011b*/ { NULL, FILE_PCHRUZI,                0x0199 },
	/*0x011c*/ { NULL, FILE_PCHRMP5K,               0x0199 },
	/*0x011d*/ { NULL, FILE_PCHRM16,                0x0199 },
	/*0x011e*/ { NULL, FILE_PCHRFNP90,              0x0199 },
	/*0x011f*/ { NULL, FILE_PCHRDYROCKETMIS,        0x0199 },
	/*0x0120*/ { NULL, FILE_PCHRSKROCKETMIS,        0x0199 },
	/*0x0121*/ { NULL, FILE_PCHRCROSSBOLT,          0x0199 },
	/*0x0122*/ { NULL, FILE_PCHRDEVGRENADE,         0x0199 },
	/*0x0123*/ { NULL, FILE_PCHRDRAGGRENADE,        0x0199 },
	/*0x0124*/ { NULL, FILE_PA51_TURRET,            0x0199 },
	/*0x0125*/ { NULL, FILE_PPELAGICDOOR,           0x1000 },
	/*0x0126*/ { NULL, FILE_PAUTOSURGEON,           0x0199 },
	/*0x0127*/ { NULL, FILE_PLIMO,                  0x0199 },
	/*0x0128*/ { NULL, FILE_PA51INTERCEPTOR,        0x0199 },
	/*0x0129*/ { NULL, FILE_PA51DISH,               0x0199 },
	/*0x012a*/ { NULL, FILE_PA51RADARCONSOLE,       0x0199 },
	/*0x012b*/ { NULL, FILE_PA51LOCKERDOOR,         0x0199 },
	/*0x012c*/ { NULL, FILE_PG5GENERATOR,           0x0199 },
	/*0x012d*/ { NULL, FILE_PG5DUMPSTER,            0x0199 },
	/*0x012e*/ { NULL, FILE_PCHRCLOAKER,            0x0199 },
	/*0x012f*/ { NULL, FILE_PCHRSPEEDPILL,          0x2800 },
	/*0x0130*/ { NULL, FILE_PBIGPELAGICDOOR,        0x1000 },
	/*0x0131*/ { NULL, FILE_PSK_JONRUBBLE3,         0x1000 },
	/*0x0132*/ { NULL, FILE_PSK_JONRUBBLE4,         0x1000 },
	/*0x0133*/ { NULL, FILE_PSK_JONRUBBLE5,         0x1000 },
	/*0x0134*/ { NULL, FILE_PSK_JONRUBBLE6,         0x1000 },
	/*0x0135*/ { NULL, FILE_PBAGGAGECARRIER,        0x0199 },
	/*0x0136*/ { NULL, FILE_PMINESIGN,              0x0199 },
	/*0x0137*/ { NULL, FILE_PCHAMBER,               0x0199 },
	/*0x0138*/ { NULL, FILE_PISOTOPEEXPERIMENT,     0x0199 },
	/*0x0139*/ { NULL, FILE_PISOTOPE,               0x0199 },
	/*0x013a*/ { NULL, FILE_PREACTORDOOR,           0x0199 },
	/*0x013b*/ { NULL, FILE_PSAUCERINSIDE,          0x1000 },
	/*0x013c*/ { NULL, FILE_PVILLASTOOL,            0x0199 },
	/*0x013d*/ { NULL, FILE_PCETANWINDOW1,          0x0199 },
	/*0x013e*/ { NULL, FILE_PCETANWINDOW2,          0x0199 },
	/*0x013f*/ { NULL, FILE_PCETANWINDOW3,          0x0199 },
	/*0x0140*/ { NULL, FILE_PBINOCULARS,            0x0199 },
	/*0x0141*/ { NULL, FILE_PSUBMARINE,             0x0199 },
	/*0x0142*/ { NULL, FILE_PAIRFORCE1,             0x1000 },
	/*0x0143*/ { NULL, FILE_PENGINEPART,            0x0199 },
	/*0x0144*/ { NULL, FILE_PCETROOFGUN,            0x0199 },
	/*0x0145*/ { NULL, FILE_PCETANSMALLDOOR,        0x1000 },
	/*0x0146*/ { NULL, FILE_PPOWERNODE,             0x0199 },
	/*0x0147*/ { NULL, FILE_PCETANBLUEGREENL,       0x1000 },
	/*0x0148*/ { NULL, FILE_PCETANBLUEGREENR,       0x1000 },
	/*0x0149*/ { NULL, FILE_PSKEDARCONSOLE,         0x1000 },
	/*0x014a*/ { NULL, FILE_PSKEDARCONSOLEPANEL,    0x1000 },
	/*0x014b*/ { NULL, FILE_PWEAPONCDOOR,           0x1000 },
	/*0x014c*/ { NULL, FILE_PTARGET,                0x1000 },
	/*0x014d*/ { NULL, FILE_PDEVICESECRETDOOR,      0x1000 },
	/*0x014e*/ { NULL, FILE_PCARRINGTONSECRETDOOR,  0x1000 },
	/*0x014f*/ { NULL, FILE_PSINISTERPC,            0x1000 },
	/*0x0150*/ { NULL, FILE_PSINISTERSTATION,       0x1000 },
	/*0x0151*/ { NULL, FILE_PKEYPADLOCK,            0x1000 },
	/*0x0152*/ { NULL, FILE_PTHUMBPRINTSCANNER,     0x1000 },
	/*0x0153*/ { NULL, FILE_PRETINALOCK,            0x1000 },
	/*0x0154*/ { NULL, FILE_PCARDLOCK,              0x1000 },
	/*0x0155*/ { NULL, FILE_PGOODSTATION,           0x1000 },
	/*0x0156*/ { NULL, FILE_PGOODPC,                0x1000 },
	/*0x0157*/ { NULL, FILE_PCHRAUTOGUN,            0x0199 },
	/*0x0158*/ { NULL, FILE_PG5BIGCHAIR,            0x0199 },
	/*0x0159*/ { NULL, FILE_PG5SMALLCHAIR,          0x0199 },
	/*0x015a*/ { NULL, FILE_PKINGSCEPTRE,           0x0199 },
	/*0x015b*/ { NULL, FILE_PLABCOAT,               0x0199 },
	/*0x015c*/ { NULL, FILE_PCIDOOR1,               0x1000 },
	/*0x015d*/ { NULL, FILE_PG5_CHAIR,              0x1000 },
	/*0x015e*/ { NULL, FILE_PG5_CHAIR2,             0x1000 },
	/*0x015f*/ { NULL, FILE_PDD_WINDOW_FOYER,       0x0199 },
	/*0x0160*/ { NULL, FILE_PCI_CABINET,            0x1000 },
	/*0x0161*/ { NULL, FILE_PCI_DESK,               0x1000 },
	/*0x0162*/ { NULL, FILE_PCI_CARR_DESK,          0x1000 },
	/*0x0163*/ { NULL, FILE_PCI_F_CHAIR,            0x1000 },
	/*0x0164*/ { NULL, FILE_PCI_LOUNGER,            0x1000 },
	/*0x0165*/ { NULL, FILE_PCI_F_SOFA,             0x1000 },
	/*0x0166*/ { NULL, FILE_PCI_TABLE,              0x1000 },
	/*0x0167*/ { NULL, FILE_PCV_COFFEE_TABLE,       0x1000 },
	/*0x0168*/ { NULL, FILE_PCV_CHAIR1,             0x1000 },
	/*0x0169*/ { NULL, FILE_PCV_CHAIR2,             0x1000 },
	/*0x016a*/ { NULL, FILE_PCV_SOFA,               0x1000 },
	/*0x016b*/ { NULL, FILE_PCV_CHAIR4,             0x1000 },
	/*0x016c*/ { NULL, FILE_PCV_LAMP,               0x1000 },
	/*0x016d*/ { NULL, FILE_PCV_CABINET,            0x1000 },
	/*0x016e*/ { NULL, FILE_PCV_F_BED,              0x1000 },
	/*0x016f*/ { NULL, FILE_PPEL_CHAIR1,            0x1000 },
	/*0x0170*/ { NULL, FILE_PSK_CONSOLE2,           0x1000 },
	/*0x0171*/ { NULL, FILE_PDD_EAR_TABLE,          0x1000 },
	/*0x0172*/ { NULL, FILE_PDD_EAR_CHAIR,          0x1000 },
	/*0x0173*/ { NULL, FILE_PAIRBASE_TABLE2,        0x1000 },
	/*0x0174*/ { NULL, FILE_PAIRBASE_CHAIR2,        0x1000 },
	/*0x0175*/ { NULL, FILE_PMISC_CRATE,            0x1000 },
	/*0x0176*/ { NULL, FILE_PA51_CRATE1,            0x1000 },
	/*0x0177*/ { NULL, FILE_PMISC_IRSPECS,          0x0c00 },
	/*0x0178*/ { NULL, FILE_PA51_ROOFGUN,           0x0199 },
	/*0x0179*/ { NULL, FILE_PSK_DRONE_GUN,          0x0199 },
	/*0x017a*/ { NULL, FILE_PCI_ROOFGUN,            0x0199 },
	/*0x017b*/ { NULL, FILE_PCV_TABLE,              0x1000 },
	/*0x017c*/ { NULL, FILE_PCIDOOR1_REF,           0x1000 },
	/*0x017d*/ { NULL, FILE_PALASKADOOR_OUT,        0x1000 },
	/*0x017e*/ { NULL, FILE_PALASKADOOR_IN,         0x1000 },
	/*0x017f*/ { NULL, FILE_PWIREFENCE,             0x0199 },
	/*0x0180*/ { NULL, FILE_PRARELOGO,              0x1000 },
	/*0x0181*/ { NULL, FILE_PKEYCARD,               0x0199 },
	/*0x0182*/ { NULL, FILE_PBODYARMOUR,            0x0133 },
	/*0x0183*/ { NULL, FILE_PA51GATE_R,             0x1000 },
	/*0x0184*/ { NULL, FILE_PA51GATE_L,             0x1000 },
	/*0x0185*/ { NULL, FILE_PAF1_LAMP,              0x1000 },
	/*0x0186*/ { NULL, FILE_PAF1_TOILET,            0x1000 },
	/*0x0187*/ { NULL, FILE_PAF1_DOORBIG2,          0x1000 },
	/*0x0188*/ { NULL, FILE_PAF1_PHONE,             0x1000 },
	/*0x0189*/ { NULL, FILE_PAF1_CARGODOOR,         0x1000 },
	/*0x018a*/ { NULL, FILE_PG5_ALARM,              0x1000 },
	/*0x018b*/ { NULL, FILE_PG5_LASER_SWITCH,       0x1000 },
	/*0x018c*/ { NULL, FILE_PSK_TEMPLECOLUMN4,      0x1000 },
	/*0x018d*/ { NULL, FILE_PCOREHATCH,             0x1000 },
	/*0x018e*/ { NULL, FILE_PA51GRATE,              0x1000 },
	/*0x018f*/ { NULL, FILE_PAF1ESCAPEDOOR,         0x1000 },
	/*0x0190*/ { NULL, FILE_PPRESCAPSULE,           0x1000 },
	/*0x0191*/ { NULL, FILE_PSKEDARBRIDGE,          0x1000 },
	/*0x0192*/ { NULL, FILE_PPELAGICDOOR2,          0x1000 },
	/*0x0193*/ { NULL, FILE_PTTB_BOX,               0x0066 },
	/*0x0194*/ { NULL, FILE_PINSTFRONTDOOR,         0x1000 },
	/*0x0195*/ { NULL, FILE_PCHRLASER,              0x0199 },
	/*0x0196*/ { NULL, FILE_PBAFTA,                 0x1000 },
	/*0x0197*/ { NULL, FILE_PCHRSONICSCREWER,       0x0199 },
	/*0x0198*/ { NULL, FILE_PCHRLUMPHAMMER,         0x0199 },
	/*0x0199*/ { NULL, FILE_PEXPLOSIVEBRICK,        0x1000 },
	/*0x019a*/ { NULL, FILE_PSKEDARBOMB,            0x1000 },
	/*0x019b*/ { NULL, FILE_PZIGGYCARD,             0x1000 },
	/*0x019c*/ { NULL, FILE_PSAFEITEM,              0x1000 },
	/*0x019d*/ { NULL, FILE_PRUSSDAR,               0x0333 },
	/*0x019e*/ { NULL, FILE_PXRAYSPECS,             0x0c00 },
	/*0x019f*/ { NULL, FILE_PCHRLUMPHAMMER,         0x1000 },
	/*0x01a0*/ { NULL, FILE_PCHREYESPY,             0x1800 },
	/*0x01a1*/ { NULL, FILE_PCHRDOORDECODER,        0x0199 },
	/*0x01a2*/ { NULL, FILE_PAF1_TABLE,             0x0199 },
	/*0x01a3*/ { NULL, FILE_PSHUTTLEDOOR,           0x1000 },
	/*0x01a4*/ { NULL, FILE_PRUINBRIDGE,            0x0199 },
	/*0x01a5*/ { NULL, FILE_PSECRETINDOOR,          0x1000 },
	/*0x01a6*/ { NULL, FILE_PSENSITIVEINFO,         0x0199 },
	/*0x01a7*/ { NULL, FILE_PSUITCASE,              0x1000 },
	/*0x01a8*/ { NULL, FILE_PSKPUZZLEOBJECT,        0x1000 },
	/*0x01a9*/ { NULL, FILE_PA51LIFTDOOR,           0x1000 },
	/*0x01aa*/ { NULL, FILE_PCIHUB,                 0x1000 },
	/*0x01ab*/ { NULL, FILE_PSK_SHIP_DOOR2,         0x1000 },
	/*0x01ac*/ { NULL, FILE_PSK_WINDOW1,            0x1000 },
	/*0x01ad*/ { NULL, FILE_PSK_HANGARDOORB_TOP,    0x1000 },
	/*0x01ae*/ { NULL, FILE_PSK_HANGARDOORB_BOT,    0x1000 },
	/*0x01af*/ { NULL, FILE_PAF1_INNERDOOR,         0x1000 },
	/*0x01b0*/ { NULL, FILE_PLASER_POST,            0x1000 },
	/*0x01b1*/ { NULL, FILE_PTARGETAMP,             0x0199 },
	/*0x01b2*/ { NULL, FILE_PSK_LIFT,               0x1000 },
	/*0x01b3*/ { NULL, FILE_PKNOCKKNOCK,            0x1000 },
	/*0x01b4*/ { NULL, FILE_PCETANDOOR,             0x1000 },
	/*0x01b5*/ { NULL, FILE_PAF1RUBBLE,             0x1000 },
	/*0x01b6*/ { NULL, FILE_PDD_DR_NONREF,          0x1000 },
	/*0x01b7*/ { NULL, FILE_PCETANDOORSIDE,         0x1000 },
	/*0x01b8*/ { NULL, FILE_PBUDDYBRIDGE,           0x0199 },
};

// 21e54
u8 propexplosiontypes[] = {
	/*0x0000*/ 0x00,
	/*0x0001*/ 0x00,
	/*0x0002*/ 0x00,
	/*0x0003*/ 0x00,
	/*0x0004*/ 0x00,
	/*0x0005*/ 0x00,
	/*0x0006*/ 0x10,
	/*0x0007*/ 0x00,
	/*0x0008*/ 0x08,
	/*0x0009*/ 0x0b,
	/*0x000a*/ 0x06,
	/*0x000b*/ 0x04,
	/*0x000c*/ 0x00,
	/*0x000d*/ 0x00,
	/*0x000e*/ 0x00,
	/*0x000f*/ 0x00,
	/*0x0010*/ 0x00,
	/*0x0011*/ 0x00,
	/*0x0012*/ 0x00,
	/*0x0013*/ 0x00,
	/*0x0014*/ 0x00,
	/*0x0015*/ 0x00,
	/*0x0016*/ 0x00,
	/*0x0017*/ 0x00,
	/*0x0018*/ 0x00,
	/*0x0019*/ 0x03,
	/*0x001a*/ 0x00,
	/*0x001b*/ 0x06,
	/*0x001c*/ 0x00,
	/*0x001d*/ 0x00,
	/*0x001e*/ 0x00,
	/*0x001f*/ 0x06,
	/*0x0020*/ 0x09,
	/*0x0021*/ 0x00,
	/*0x0022*/ 0x00,
	/*0x0023*/ 0x00,
	/*0x0024*/ 0x00,
	/*0x0025*/ 0x00,
	/*0x0026*/ 0x00,
	/*0x0027*/ 0x00,
	/*0x0028*/ 0x03,
	/*0x0029*/ 0x03,
	/*0x002a*/ 0x03,
	/*0x002b*/ 0x00,
	/*0x002c*/ 0x00,
	/*0x002d*/ 0x00,
	/*0x002e*/ 0x00,
	/*0x002f*/ 0x00,
	/*0x0030*/ 0x00,
	/*0x0031*/ 0x00,
	/*0x0032*/ 0x00,
	/*0x0033*/ 0x00,
	/*0x0034*/ 0x00,
	/*0x0035*/ 0x00,
	/*0x0036*/ 0x00,
	/*0x0037*/ 0x00,
	/*0x0038*/ 0x00,
	/*0x0039*/ 0x00,
	/*0x003a*/ 0x00,
	/*0x003b*/ 0x0c,
	/*0x003c*/ 0x00,
	/*0x003d*/ 0x00,
	/*0x003e*/ 0x00,
	/*0x003f*/ 0x00,
	/*0x0040*/ 0x00,
	/*0x0041*/ 0x00,
	/*0x0042*/ 0x0b,
	/*0x0043*/ 0x00,
	/*0x0044*/ 0x00,
	/*0x0045*/ 0x00,
	/*0x0046*/ 0x00,
	/*0x0047*/ 0x00,
	/*0x0048*/ 0x00,
	/*0x0049*/ 0x00,
	/*0x004a*/ 0x00,
	/*0x004b*/ 0x00,
	/*0x004c*/ 0x00,
	/*0x004d*/ 0x00,
	/*0x004e*/ 0x00,
	/*0x004f*/ 0x00,
	/*0x0050*/ 0x00,
	/*0x0051*/ 0x00,
	/*0x0052*/ 0x00,
	/*0x0053*/ 0x00,
	/*0x0054*/ 0x00,
	/*0x0055*/ 0x00,
	/*0x0056*/ 0x00,
	/*0x0057*/ 0x00,
	/*0x0058*/ 0x0d,
	/*0x0059*/ 0x0d,
	/*0x005a*/ 0x0d,
	/*0x005b*/ 0x0d,
	/*0x005c*/ 0x0d,
	/*0x005d*/ 0x00,
	/*0x005e*/ 0x00,
	/*0x005f*/ 0x00,
	/*0x0060*/ 0x00,
	/*0x0061*/ 0x07,
	/*0x0062*/ 0x04,
	/*0x0063*/ 0x0c,
	/*0x0064*/ 0x00,
	/*0x0065*/ 0x00,
	/*0x0066*/ 0x03,
	/*0x0067*/ 0x00,
	/*0x0068*/ 0x00,
	/*0x0069*/ 0x00,
	/*0x006a*/ 0x00,
	/*0x006b*/ 0x00,
	/*0x006c*/ 0x00,
	/*0x006d*/ 0x00,
	/*0x006e*/ 0x0c,
	/*0x006f*/ 0x0c,
	/*0x0070*/ 0x00,
	/*0x0071*/ 0x00,
	/*0x0072*/ 0x00,
	/*0x0073*/ 0x00,
	/*0x0074*/ 0x00,
	/*0x0075*/ 0x00,
	/*0x0076*/ 0x00,
	/*0x0077*/ 0x00,
	/*0x0078*/ 0x00,
	/*0x0079*/ 0x00,
	/*0x007a*/ 0x00,
	/*0x007b*/ 0x00,
	/*0x007c*/ 0x00,
	/*0x007d*/ 0x00,
	/*0x007e*/ 0x0d,
	/*0x007f*/ 0x00,
	/*0x0080*/ 0x00,
	/*0x0081*/ 0x00,
	/*0x0082*/ 0x00,
	/*0x0083*/ 0x00,
	/*0x0084*/ 0x00,
	/*0x0085*/ 0x00,
	/*0x0086*/ 0x00,
	/*0x0087*/ 0x00,
	/*0x0088*/ 0x00,
	/*0x0089*/ 0x00,
	/*0x008a*/ 0x00,
	/*0x008b*/ 0x00,
	/*0x008c*/ 0x00,
	/*0x008d*/ 0x0d,
	/*0x008e*/ 0x0c,
	/*0x008f*/ 0x0c,
	/*0x0090*/ 0x00,
	/*0x0091*/ 0x00,
	/*0x0092*/ 0x00,
	/*0x0093*/ 0x00,
	/*0x0094*/ 0x00,
	/*0x0095*/ 0x00,
	/*0x0096*/ 0x00,
	/*0x0097*/ 0x00,
	/*0x0098*/ 0x00,
	/*0x0099*/ 0x00,
	/*0x009a*/ 0x00,
	/*0x009b*/ 0x00,
	/*0x009c*/ 0x00,
	/*0x009d*/ 0x00,
	/*0x009e*/ 0x00,
	/*0x009f*/ 0x0d,
	/*0x00a0*/ 0x00,
	/*0x00a1*/ 0x00,
	/*0x00a2*/ 0x00,
	/*0x00a3*/ 0x00,
	/*0x00a4*/ 0x00,
	/*0x00a5*/ 0x00,
	/*0x00a6*/ 0x00,
	/*0x00a7*/ 0x09,
	/*0x00a8*/ 0x00,
	/*0x00a9*/ 0x00,
	/*0x00aa*/ 0x00,
	/*0x00ab*/ 0x00,
	/*0x00ac*/ 0x00,
	/*0x00ad*/ 0x00,
	/*0x00ae*/ 0x00,
	/*0x00af*/ 0x00,
	/*0x00b0*/ 0x00,
	/*0x00b1*/ 0x00,
	/*0x00b2*/ 0x00,
	/*0x00b3*/ 0x00,
	/*0x00b4*/ 0x00,
	/*0x00b5*/ 0x00,
	/*0x00b6*/ 0x00,
	/*0x00b7*/ 0x07,
	/*0x00b8*/ 0x06,
	/*0x00b9*/ 0x00,
	/*0x00ba*/ 0x09,
	/*0x00bb*/ 0x00,
	/*0x00bc*/ 0x00,
	/*0x00bd*/ 0x06,
	/*0x00be*/ 0x06,
	/*0x00bf*/ 0x06,
	/*0x00c0*/ 0x00,
	/*0x00c1*/ 0x00,
	/*0x00c2*/ 0x0b,
	/*0x00c3*/ 0x00,
	/*0x00c4*/ 0x00,
	/*0x00c5*/ 0x06,
	/*0x00c6*/ 0x09,
	/*0x00c7*/ 0x00,
	/*0x00c8*/ 0x00,
	/*0x00c9*/ 0x0b,
	/*0x00ca*/ 0x06,
	/*0x00cb*/ 0x00,
	/*0x00cc*/ 0x00,
	/*0x00cd*/ 0x00,
	/*0x00ce*/ 0x00,
	/*0x00cf*/ 0x00,
	/*0x00d0*/ 0x19,
	/*0x00d1*/ 0x00,
	/*0x00d2*/ 0x00,
	/*0x00d3*/ 0x00,
	/*0x00d4*/ 0x00,
	/*0x00d5*/ 0x00,
	/*0x00d6*/ 0x00,
	/*0x00d7*/ 0x00,
	/*0x00d8*/ 0x00,
	/*0x00d9*/ 0x00,
	/*0x00da*/ 0x00,
	/*0x00db*/ 0x00,
	/*0x00dc*/ 0x00,
	/*0x00dd*/ 0x00,
	/*0x00de*/ 0x00,
	/*0x00df*/ 0x00,
	/*0x00e0*/ 0x00,
	/*0x00e1*/ 0x00,
	/*0x00e2*/ 0x00,
	/*0x00e3*/ 0x00,
	/*0x00e4*/ 0x00,
	/*0x00e5*/ 0x00,
	/*0x00e6*/ 0x00,
	/*0x00e7*/ 0x00,
	/*0x00e8*/ 0x00,
	/*0x00e9*/ 0x00,
	/*0x00ea*/ 0x0b,
	/*0x00eb*/ 0x00,
	/*0x00ec*/ 0x00,
	/*0x00ed*/ 0x00,
	/*0x00ee*/ 0x00,
	/*0x00ef*/ 0x00,
	/*0x00f0*/ 0x00,
	/*0x00f1*/ 0x00,
	/*0x00f2*/ 0x00,
	/*0x00f3*/ 0x11,
	/*0x00f4*/ 0x00,
	/*0x00f5*/ 0x00,
	/*0x00f6*/ 0x00,
	/*0x00f7*/ 0x00,
	/*0x00f8*/ 0x00,
	/*0x00f9*/ 0x00,
	/*0x00fa*/ 0x00,
	/*0x00fb*/ 0x00,
	/*0x00fc*/ 0x00,
	/*0x00fd*/ 0x00,
	/*0x00fe*/ 0x00,
	/*0x00ff*/ 0x00,
	/*0x0100*/ 0x00,
	/*0x0101*/ 0x00,
	/*0x0102*/ 0x00,
	/*0x0103*/ 0x00,
	/*0x0104*/ 0x00,
	/*0x0105*/ 0x00,
	/*0x0106*/ 0x00,
	/*0x0107*/ 0x00,
	/*0x0108*/ 0x00,
	/*0x0109*/ 0x00,
	/*0x010a*/ 0x00,
	/*0x010b*/ 0x00,
	/*0x010c*/ 0x00,
	/*0x010d*/ 0x00,
	/*0x010e*/ 0x00,
	/*0x010f*/ 0x00,
	/*0x0110*/ 0x00,
	/*0x0111*/ 0x00,
	/*0x0112*/ 0x00,
	/*0x0113*/ 0x00,
	/*0x0114*/ 0x00,
	/*0x0115*/ 0x00,
	/*0x0116*/ 0x00,
	/*0x0117*/ 0x00,
	/*0x0118*/ 0x00,
	/*0x0119*/ 0x00,
	/*0x011a*/ 0x0d,
	/*0x011b*/ 0x0d,
	/*0x011c*/ 0x0d,
	/*0x011d*/ 0x0d,
	/*0x011e*/ 0x00,
	/*0x011f*/ 0x00,
	/*0x0120*/ 0x00,
	/*0x0121*/ 0x00,
	/*0x0122*/ 0x00,
	/*0x0123*/ 0x00,
	/*0x0124*/ 0x00,
	/*0x0125*/ 0x00,
	/*0x0126*/ 0x00,
	/*0x0127*/ 0x0d,
	/*0x0128*/ 0x0d,
	/*0x0129*/ 0x00,
	/*0x012a*/ 0x0d,
	/*0x012b*/ 0x0d,
	/*0x012c*/ 0x08,
	/*0x012d*/ 0x00,
	/*0x012e*/ 0x00,
	/*0x012f*/ 0x0c,
	/*0x0130*/ 0x0d,
	/*0x0131*/ 0x07,
	/*0x0132*/ 0x0b,
	/*0x0133*/ 0x00,
	/*0x0134*/ 0x07,
	/*0x0135*/ 0x07,
	/*0x0136*/ 0x00,
	/*0x0137*/ 0x00,
	/*0x0138*/ 0x00,
	/*0x0139*/ 0x00,
	/*0x013a*/ 0x00,
	/*0x013b*/ 0x00,
	/*0x013c*/ 0x00,
	/*0x013d*/ 0x00,
	/*0x013e*/ 0x00,
	/*0x013f*/ 0x00,
	/*0x0140*/ 0x00,
	/*0x0141*/ 0x00,
	/*0x0142*/ 0x00,
	/*0x0143*/ 0x00,
	/*0x0144*/ 0x00,
	/*0x0145*/ 0x00,
	/*0x0146*/ 0x00,
	/*0x0147*/ 0x00,
	/*0x0148*/ 0x00,
	/*0x0149*/ 0x00,
	/*0x014a*/ 0x00,
	/*0x014b*/ 0x0d,
	/*0x014c*/ 0x07,
	/*0x014d*/ 0x00,
	/*0x014e*/ 0x00,
	/*0x014f*/ 0x00,
	/*0x0150*/ 0x00,
	/*0x0151*/ 0x07,
	/*0x0152*/ 0x00,
	/*0x0153*/ 0x00,
	/*0x0154*/ 0x00,
	/*0x0155*/ 0x00,
	/*0x0156*/ 0x00,
	/*0x0157*/ 0x07,
	/*0x0158*/ 0x08,
	/*0x0159*/ 0x06,
	/*0x015a*/ 0x06,
	/*0x015b*/ 0x06,
	/*0x015c*/ 0x06,
	/*0x015d*/ 0x08,
	/*0x015e*/ 0x07,
	/*0x015f*/ 0x07,
	/*0x0160*/ 0x00,
	/*0x0161*/ 0x00,
	/*0x0162*/ 0x00,
	/*0x0163*/ 0x00,
	/*0x0164*/ 0x00,
	/*0x0165*/ 0x00,
	/*0x0166*/ 0x00,
	/*0x0167*/ 0x00,
	/*0x0168*/ 0x00,
	/*0x0169*/ 0x00,
	/*0x016a*/ 0x00,
	/*0x016b*/ 0x00,
	/*0x016c*/ 0x00,
	/*0x016d*/ 0x00,
	/*0x016e*/ 0x00,
	/*0x016f*/ 0x00,
	/*0x0170*/ 0x00,
	/*0x0171*/ 0x00,
	/*0x0172*/ 0x00,
	/*0x0173*/ 0x00,
	/*0x0174*/ 0x06,
	/*0x0175*/ 0x00,
	/*0x0176*/ 0x00,
	/*0x0177*/ 0x00,
	/*0x0178*/ 0x07,
	/*0x0179*/ 0x00,
	/*0x017a*/ 0x00,
	/*0x017b*/ 0x00,
	/*0x017c*/ 0x00,
	/*0x017d*/ 0x00,
	/*0x017e*/ 0x00,
	/*0x017f*/ 0x06,
	/*0x0180*/ 0x08,
	/*0x0181*/ 0x08,
	/*0x0182*/ 0x08,
	/*0x0183*/ 0x00,
	/*0x0184*/ 0x00,
	/*0x0185*/ 0x00,
	/*0x0186*/ 0x00,
	/*0x0187*/ 0x00,
	/*0x0188*/ 0x00,
	/*0x0189*/ 0x00,
	/*0x018a*/ 0x00,
	/*0x018b*/ 0x00,
	/*0x018c*/ 0x00,
	/*0x018d*/ 0x06,
	/*0x018e*/ 0x00,
	/*0x018f*/ 0x00,
	/*0x0190*/ 0x06,
	/*0x0191*/ 0x00,
	/*0x0192*/ 0x07,
	/*0x0193*/ 0x07,
	/*0x0194*/ 0x00,
	/*0x0195*/ 0x00,
	/*0x0196*/ 0x00,
	/*0x0197*/ 0x00,
	/*0x0198*/ 0x0d,
	/*0x0199*/ 0x00,
	/*0x019a*/ 0x00,
	/*0x019b*/ 0x00,
	/*0x019c*/ 0x00,
	/*0x019d*/ 0x00,
	/*0x019e*/ 0x06,
	/*0x019f*/ 0x00,
	/*0x01a0*/ 0x00,
	/*0x01a1*/ 0x00,
	/*0x01a2*/ 0x11,
	/*0x01a3*/ 0x00,
	/*0x01a4*/ 0x00,
	/*0x01a5*/ 0x00,
	/*0x01a6*/ 0x00,
	/*0x01a7*/ 0x00,
	/*0x01a8*/ 0x00,
	/*0x01a9*/ 0x00,
	/*0x01aa*/ 0x00,
	/*0x01ab*/ 0x00,
	/*0x01ac*/ 0x00,
	/*0x01ad*/ 0x00,
	/*0x01ae*/ 0x00,
	/*0x01af*/ 0x0b,
	/*0x01b0*/ 0x00,
	/*0x01b1*/ 0x00,
	/*0x01b2*/ 0x00,
	/*0x01b3*/ 0x06,
	/*0x01b4*/ 0x00,
	/*0x01b5*/ 0x00,
	/*0x01b6*/ 0x00,
	/*0x01b7*/ 0x00,
	/*0x01b8*/ 0x00,
	/*0x01b9*/ 0x00,
	/*0x01ba*/ 0x00,
	/*0x01bb*/ 0x00,
	/*0x01bc*/ 0x00,
	/*0x01bd*/ 0x00,
	/*0x01be*/ 0x00,
	/*0x01bf*/ 0x00,
};

u32 var8007bff4 = 0x0000ff00;
u32 var8007bff8 = 0x00000000;
u32 var8007bffc = 0x00000000;
u32 var8007c000 = 0x00000000;
u32 var8007c004 = 0x00000000;
u32 var8007c008 = 0x00000000;
u32 var8007c00c = 0x00000000;
u32 var8007c010 = 0xf8f4f1e0;
u32 var8007c014 = 0x473f41dd;
u32 var8007c018 = 0xa510c9c6;
u32 var8007c01c = 0xbcae0bd1;
u32 var8007c020 = 0x0ff73a30;
u32 var8007c024 = 0x724083b7;
u32 var8007c028 = 0xffffffff;
u32 var8007c02c = 0xffffffff;
u32 var8007c030 = 0xffffffff;
u32 var8007c034 = 0x00000000;
u32 var8007c038 = 0x00000000;
u32 var8007c03c = 0x00000000;

// 22060
u16 var8007c040[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
};

// 2208c
struct stagethinglist stagethinglist_2208c = {
	0x02, 21, var8007c040,
};

u32 var8007c074 = 0x00000000;
u32 var8007c078 = 0x00000000;
u32 var8007c07c = 0x00000000;

// 220a0
u16 var8007c080[] = {
	0x0000,
	0x0101,
};

// 220a4
struct stagethinglist stagethinglist_220a4 = {
	0x03, 2, var8007c080,
};

u32 var8007c08c = 0x00000000;

// 220b0
u16 var8007c090[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
};

// 220d0
struct stagethinglist stagethinglist_220d0 = {
	0x0b, 15, var8007c090,
};

u32 var8007c0dc;
u32 var8007c0f4;
u32 var8007c10c;
u32 var8007c124;
u32 var8007c130;
u32 var8007c148;

u32 var8007c0b8 = 0x00000000;
u32 var8007c0bc = 0x00000000;
u32 var8007c0c0 = (u32) &var8007c0dc;
u32 var8007c0c4 = (u32) &stagethinglist_220d0;
u32 var8007c0c8 = 0x00000000;
u32 var8007c0cc = 0x00000003;
u32 var8007c0d0 = 0x4224a519;
u32 var8007c0d4 = 0x00000000;
u32 var8007c0d8 = 0x00000000;

u32 var8007c0dc = 0x00010000;
u32 var8007c0e0 = (u32) &var8007c124;
u32 var8007c0e4 = 0x00000000;
u32 var8007c0e8 = 0x00000000;
u32 var8007c0ec = 0x00000000;
u32 var8007c0f0 = (u32) &var8007c0f4;

u32 var8007c0f4 = 0x00020000;
u32 var8007c0f8 = (u32) &var8007c130;
u32 var8007c0fc = (u32) &var8007c0dc;
u32 var8007c100 = 0x00000000;
u32 var8007c104 = 0x00000000;
u32 var8007c108 = (u32) &var8007c10c;

u32 var8007c10c = 0x00020000;
u32 var8007c110 = (u32) &var8007c148;
u32 var8007c114 = (u32) &var8007c0f4;
u32 var8007c118 = 0x00000000;
u32 var8007c11c = 0x00000000;
u32 var8007c120 = 0x00000000;

u32 var8007c124 = 0x00000001;
u32 var8007c128 = 0x00000000;
u32 var8007c12c = 0x00000000;

u32 var8007c130 = 0x3f96c81d;
u32 var8007c134 = 0x422493d6;
u32 var8007c138 = 0x00000000;
u32 var8007c13c = 0x00010002;
u32 var8007c140 = 0xffffffff;
u32 var8007c144 = 0x00000000;

u32 var8007c148 = 0xc024dda0;
u32 var8007c14c = 0x43f036ea;
u32 var8007c150 = 0x00000000;
u32 var8007c154 = 0x00020000;
u32 var8007c158 = 0xffffffff;
u32 var8007c15c = 0x00000000;

// 22180
u16 var8007c160[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
	0x0f0f,
	0x1010,
	0x1111,
};

// 221a4
struct stagethinglist stagethinglist_221a4 = {
	0x0a, 18, var8007c160,
};

u32 var8007c18c = 0x00000000;
// 221b0
u16 var8007c190[] = {
	0x0000,
};

// 221b4
struct stagethinglist stagethinglist_221b4 = {
	STAGE_MP_G5BUILDING, 1, var8007c190,
};

u32 var8007c19c = 0x00000000;
// 221c0
u16 var8007c1a0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0505,
	0x0303,
	0x0404,
};

// 221cc
struct stagethinglist stagethinglist_221cc = {
	0x07, 6, var8007c1a0,
};

u32 var8007c1b4 = 0x00000000;
u32 var8007c1b8 = 0x00000000;
u32 var8007c1bc = 0x00000000;
// 221e0
u16 var8007c1c0[] = {
	0x0000,
};

// 221e4
struct stagethinglist stagethinglist_221e4 = {
	0x08, 1, var8007c1c0,
};

u32 var8007c1cc = 0x00000000;
// 221f0
u16 var8007c1d0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
};

// 22200
struct stagethinglist stagethinglist_22200 = {
	0x06, 7, var8007c1d0,
};

u32 var8007c1e8 = 0x00000000;
u32 var8007c1ec = 0x00000000;
// 22210
u16 var8007c1f0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0606,
	0x0404,
	0x0505,
};

// 22220
struct stagethinglist stagethinglist_22220 = {
	0x05, 7, var8007c1f0,
};

u32 var8007c208 = 0x00000000;
u32 var8007c20c = 0x00000000;
// 22230
u16 var8007c210[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
};

// 2224c
struct stagethinglist stagethinglist_2224c = {
	0x04, 13, var8007c210,
};

// 22254
u16 var8007c234[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
};

// 222b4
struct stagethinglist stagethinglist_222b4 = {
	STAGE_PELAGIC, 47, var8007c234,
};

// 222bc
u16 var8007c29c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
};

// 22318
struct stagethinglist stagethinglist_22318 = {
	STAGE_TEST_RUN, 46, var8007c29c,
};

// 22320
u16 var8007c300[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 22374
struct stagethinglist stagethinglist_22374 = {
	0x24, 41, var8007c300,
};

// 2237c
u16 var8007c35c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 223d4
struct stagethinglist stagethinglist_223d4 = {
	STAGE_MP_TEMPLE, 43, var8007c35c,
};

// 223dc
u16 var8007c3bc[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22424
struct stagethinglist stagethinglist_22424 = {
	STAGE_CITRAINING, 35, var8007c3bc,
};

// 2242c
u16 var8007c40c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 2247c
struct stagethinglist stagethinglist_2247c = {
	STAGE_TEST_MP14, 40, var8007c40c,
};

// 22484
u16 var8007c464[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 224d8
struct stagethinglist stagethinglist_224d8 = {
	STAGE_MP_GRID, 41, var8007c464,
};

// 224e0
u16 var8007c4c0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 22538
struct stagethinglist stagethinglist_22538 = {
	STAGE_TEST_MP16, 43, var8007c4c0,
};

// 22540
u16 var8007c520[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
};

// 2258c
struct stagethinglist stagethinglist_2258c = {
	STAGE_TEST_MP17, 38, var8007c520,
};

// 22594
u16 var8007c574[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
};

// 225d8
struct stagethinglist stagethinglist_225d8 = {
	STAGE_TEST_MP18, 33, var8007c574,
};

// 225e0
u16 var8007c5c0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 22630
struct stagethinglist stagethinglist_22630 = {
	STAGE_TEST_MP19, 39, var8007c5c0,
};

// 22638
u16 var8007c618[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
	0x2f2f,
};

// 22698
struct stagethinglist stagethinglist_22698 = {
	STAGE_TEST_MP20, 48, var8007c618,
};

// 226a0
u16 var8007c680[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 226e8
struct stagethinglist stagethinglist_226e8 = {
	STAGE_TEST_UFF, 35, var8007c680,
};

// 226f0
u16 var8007c6d0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
	0x2f2f,
	0x3030,
	0x3131,
};

// 22754
struct stagethinglist stagethinglist_22754 = {
	STAGE_TEST_OLD, 50, var8007c6d0,
};

// 2275c
u16 var8007c73c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 227ac
struct stagethinglist stagethinglist_227ac = {
	0x64, 39, var8007c73c,
};

// 227b4
u16 var8007c794[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 22804
struct stagethinglist stagethinglist_22804 = {
	0x65, 40, var8007c794,
};

// 2280c
u16 var8007c7ec[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 2285c
struct stagethinglist stagethinglist_2285c = {
	0x66, 40, var8007c7ec,
};

// 22864
u16 var8007c844[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 228b4
struct stagethinglist stagethinglist_228b4 = {
	0x67, 40, var8007c844,
};

// 228bc
u16 var8007c89c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
};

// 2291c
struct stagethinglist stagethinglist_2291c = {
	0x68, 47, var8007c89c,
};

// 22924
u16 var8007c904[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
};

// 22970
struct stagethinglist stagethinglist_22970 = {
	0x69, 37, var8007c904,
};

// 22978
u16 var8007c958[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
};

// 229c4
struct stagethinglist stagethinglist_229c4 = {
	0x6a, 38, var8007c958,
};

// 229cc
u16 var8007c9ac[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
};

// 22a20
struct stagethinglist stagethinglist_22a20 = {
	0x6b, 42, var8007c9ac,
};

// 22a28
u16 var8007ca08[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 22a78
struct stagethinglist stagethinglist_22a78 = {
	0x6c, 39, var8007ca08,
};

// 22a80
u16 var8007ca60[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
};

// 22adc
struct stagethinglist stagethinglist_22adc = {
	0x6d, 46, var8007ca60,
};

// 22ae4
u16 var8007cac4[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
};

// 22b28
struct stagethinglist stagethinglist_22b28 = {
	0x6e, 34, var8007cac4,
};

// 22b30
u16 var8007cb10[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 22b80
struct stagethinglist stagethinglist_22b80 = {
	0x6f, 40, var8007cb10,
};

// 22b88
u16 var8007cb68[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 22be0
struct stagethinglist stagethinglist_22be0 = {
	0x70, 43, var8007cb68,
};

// 22be8
u16 var8007cbc8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 22c3c
struct stagethinglist stagethinglist_22c3c = {
	0x71, 41, var8007cbc8,
};

// 22c44
u16 var8007cc24[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
};

// 22c54
struct stagethinglist stagethinglist_22c54 = {
	STAGE_SKEDARRUINS, 7, var8007cc24,
};

// 22c5c
u16 var8007cc3c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
};

// 22ca0
struct stagethinglist stagethinglist_22ca0 = {
	0xfa, 33, var8007cc3c,
};

// 22ca8
u16 var8007cc88[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22cf0
struct stagethinglist stagethinglist_22cf0 = {
	0x72, 35, var8007cc88,
};

// 22cf8
u16 var8007ccd8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22d40
struct stagethinglist stagethinglist_22d40 = {
	0x73, 35, var8007ccd8,
};

// 22d48
u16 var8007cd28[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22d90
struct stagethinglist stagethinglist_22d90 = {
	0x74, 35, var8007cd28,
};

// 22d98
u16 var8007cd78[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22de0
struct stagethinglist stagethinglist_22de0 = {
	0x75, 35, var8007cd78,
};

// 22de8
u16 var8007cdc8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
};

// 22e34
struct stagethinglist stagethinglist_22e34 = {
	0x76, 37, var8007cdc8,
};

u32 var8007ce1c = 0x00000000;
// 22e40
u16 var8007ce20[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
};

// 22e60
struct stagethinglist stagethinglist_22e60 = {
	STAGE_MAIANSOS, 15, var8007ce20,
};

u32 var8007ce48 = 0x00000000;
u32 var8007ce4c = 0x00000000;
// 22e70
u16 var8007ce50[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x080f,
	0x0910,
	0x0a11,
	0x0b12,
	0x0c13,
	0x0d14,
	0x0e15,
	0x0f08,
	0x1009,
	0x110a,
	0x120b,
	0x130c,
	0x140d,
	0x150e,
	0x161d,
	0x171e,
	0x181f,
	0x1920,
	0x1a21,
	0x1b22,
	0x1c23,
	0x1d16,
	0x1e17,
	0x1f18,
	0x2019,
	0x211a,
	0x221b,
	0x231c,
};

// 22eb8
struct stagethinglist stagethinglist_22eb8 = {
	STAGE_CRASHSITE, 36, var8007ce50,
};

// 22ec0
u16 var8007cea0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
};

// 22ec8
struct stagethinglist stagethinglist_22ec8 = {
	0x28, 4, var8007cea0,
};

// 22ed0
u16 var8007ceb0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1213,
	0x1312,
	0x1415,
	0x1514,
	0x1617,
	0x1716,
	0x1819,
	0x1918,
	0x1a1b,
	0x1b1a,
	0x1c1d,
	0x1d1c,
};

// 22f0c
struct stagethinglist stagethinglist_22f0c = {
	STAGE_EXTRACTION, 30, var8007ceb0,
};

// 22f14
u16 var8007cef4[] = {
	0x0000,
	0x0102,
	0x0201,
};

// 22f1c
struct stagethinglist stagethinglist_22f1c = {
	STAGE_ATTACKSHIP, 3, var8007cef4,
};

// 22f24
struct body g_Bodies[] = {
	{ /*0x0000*/ 1, 0x029c, FILE_CDJBOND,          1,    1.0446009635925,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0001*/ 1, 0x029c, FILE_CCONNERY,         1,    1.0300469398499,  0, FILE_GHAND_MRBLONDE        },
	{ /*0x0002*/ 1, 0x0294, FILE_CDALTON,          1,    1.0572769641876,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0003*/ 1, 0x029c, FILE_CMOORE,           1,    1.0399061441422,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0004*/ 0, 0x4434, FILE_CHEADDARK_COMBAT, 1,    1,                0, 0                          },
	{ /*0x0005*/ 1, 0x4c6c, FILE_CHEADELVIS,       1,    1,                0, 0                          },
	{ /*0x0006*/ 1, 0x4034, FILE_CHEADROSS,        1,    1,                0, 0                          },
	{ /*0x0007*/ 1, 0x4034, FILE_CHEADCARRINGTON,  1,    1,                0, 0                          },
	{ /*0x0008*/ 1, 0x5434, FILE_CHEADMRBLONDE,    1,    1,                0, 0                          },
	{ /*0x0009*/ 1, 0x4034, FILE_CHEADTRENT,       1,    1,                0, 0                          },
	{ /*0x000a*/ 1, 0x4034, FILE_CHEADDDSHOCK,     1,    1,                0, 0                          },
	{ /*0x000b*/ 1, 0x4034, FILE_CHEADGRAHAM,      1,    1,                0, 0                          },
	{ /*0x000c*/ 0, 0x4434, FILE_CHEADDARK_FROCK,  1,    1,                0, 0                          },
	{ /*0x000d*/ 0, 0x4434, FILE_CHEADSECRETARY,   1,    1,                0, 0                          },
	{ /*0x000e*/ 0, 0x5034, FILE_CHEADCASSANDRA,   1,    1,                0, 0                          },
	{ /*0x000f*/ 1, 0x4c6c, FILE_CHEADTHEKING,     1,    1,                0, 0                          },
	{ /*0x0010*/ 0, 0x4034, FILE_CHEADFEM_GUARD,   1,    1,                0, 0                          },
	{ /*0x0011*/ 1, 0x4034, FILE_CHEADJON,         1,    1,                0, 0                          },
	{ /*0x0012*/ 1, 0x4034, FILE_CHEADMARK2,       1,    1,                0, 0                          },
	{ /*0x0013*/ 1, 0x4034, FILE_CHEADCHRIST,      1,    1,                0, 0                          },
	{ /*0x0014*/ 1, 0x4034, FILE_CHEADRUSS,        1,    1,                0, 0                          },
	{ /*0x0015*/ 1, 0x4c34, FILE_CHEADGREY,        1,    1,                0, 0                          },
	{ /*0x0016*/ 1, 0x4034, FILE_CHEADDARLING,     1,    1,                0, 0                          },
	{ /*0x0017*/ 1, 0x4034, FILE_CHEADROBERT,      1,    1,                0, 0                          },
	{ /*0x0018*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0019*/ 0, 0x4034, FILE_CHEADFEM_GUARD2,  1,    1,                0, 0                          },
	{ /*0x001a*/ 1, 0x4034, FILE_CHEADBRIAN,       1,    1,                0, 0                          },
	{ /*0x001b*/ 1, 0x4034, FILE_CHEADJAMIE,       1,    1,                0, 0                          },
	{ /*0x001c*/ 1, 0x4034, FILE_CHEADDUNCAN2,     1,    1,                0, 0                          },
	{ /*0x001d*/ 1, 0x4034, FILE_CHEADBIOTECH,     1,    1,                0, 0                          },
	{ /*0x001e*/ 1, 0x4034, FILE_CHEADNEIL2,       1,    1,                0, 0                          },
	{ /*0x001f*/ 1, 0x4034, FILE_CHEADEDMCG,       1,    1,                0, 0                          },
	{ /*0x0020*/ 0, 0x4434, FILE_CHEADANKA,        1,    1,                0, 0                          },
	{ /*0x0021*/ 0, 0x4434, FILE_CHEADLESLIE_S,    1,    1,                0, 0                          },
	{ /*0x0022*/ 1, 0x4034, FILE_CHEADMATT_C,      1,    1,                0, 0                          },
	{ /*0x0023*/ 1, 0x4034, FILE_CHEADPEER_S,      1,    1,                0, 0                          },
	{ /*0x0024*/ 0, 0x4434, FILE_CHEADEILEEN_T,    1,    1,                0, 0                          },
	{ /*0x0025*/ 1, 0x4034, FILE_CHEADANDY_R,      1,    1,                0, 0                          },
	{ /*0x0026*/ 1, 0x4034, FILE_CHEADBEN_R,       1,    1,                0, 0                          },
	{ /*0x0027*/ 1, 0x4034, FILE_CHEADSTEVE_K,     1,    1,                0, 0                          },
	{ /*0x0028*/ 1, 0x4034, FILE_CHEADJONATHAN,    1,    1,                0, 0                          },
	{ /*0x0029*/ 1, 0x4c6c, FILE_CHEADMAIAN_S,     1,    1,                0, 0                          },
	{ /*0x002a*/ 1, 0x4034, FILE_CHEADSHAUN,       1,    1,                0, 0                          },
	{ /*0x002b*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x002c*/ 0, 0x4434, FILE_CHEADEILEEN_H,    1,    1,                0, 0                          },
	{ /*0x002d*/ 1, 0x4034, FILE_CHEADSCOTT_H,     1,    1,                0, 0                          },
	{ /*0x002e*/ 1, 0x4034, FILE_CHEADSANCHEZ,     1,    1,                0, 0                          },
	{ /*0x002f*/ 0, 0x4434, FILE_CHEADDARKAQUA,    1,    1,                0, 0                          },
	{ /*0x0030*/ 1, 0x4034, FILE_CHEADDDSNIPER,    1,    1,                0, 0                          },
	{ /*0x0031*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0032*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0033*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0034*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0035*/ 1, 0x4034, FILE_CHEADGRIFFEY,     1,    1,                0, 0                          },
	{ /*0x0036*/ 1, 0x4034, FILE_CHEADMOTO,        1,    1,                0, 0                          },
	{ /*0x0037*/ 1, 0x4034, FILE_CHEADKEITH,       1,    1,                0, 0                          },
	{ /*0x0038*/ 0, 0x4434, FILE_CHEADWINNER,      1,    1,                0, 0                          },
	{ /*0x0039*/ 1, 0x4034, FILE_CA51FACEPLATE,    1,    1,                0, 0                          },
	{ /*0x003a*/ 1, 0x4c6c, FILE_CHEADELVIS_GOGS,  1,    1,                0, 0                          },
	{ /*0x003b*/ 1, 0x4034, FILE_CHEADSTEVEM,      1,    1,                0, 0                          },
	{ /*0x003c*/ 0, 0x4434, FILE_CHEADDARK_SNOW,   1,    1,                0, 0                          },
	{ /*0x003d*/ 1, 0x4034, FILE_CHEADPRESIDENT,   1,    1,                0, 0                          },
	{ /*0x003e*/ 0, 0x4434, FILE_CHEAD_VD,         1,    1,                0, 0                          },
	{ /*0x003f*/ 1, 0x4034, FILE_CHEADKEN,         1,    1,                0, 0                          },
	{ /*0x0040*/ 1, 0x4034, FILE_CHEADJOEL,        1,    1,                0, 0                          },
	{ /*0x0041*/ 1, 0x4034, FILE_CHEADTIM,         1,    1,                0, 0                          },
	{ /*0x0042*/ 1, 0x4034, FILE_CHEADGRANT,       1,    1,                0, 0                          },
	{ /*0x0043*/ 1, 0x4034, FILE_CHEADPENNY,       1,    1,                0, 0                          },
	{ /*0x0044*/ 1, 0x4034, FILE_CHEADROBIN,       1,    1,                0, 0                          },
	{ /*0x0045*/ 0, 0x4834, FILE_CHEADALEX,        1,    1,                0, 0                          },
	{ /*0x0046*/ 0, 0x4834, FILE_CHEADJULIANNE,    1,    1,                0, 0                          },
	{ /*0x0047*/ 0, 0x4834, FILE_CHEADLAURA,       1,    1,                0, 0                          },
	{ /*0x0048*/ 1, 0x4034, FILE_CHEADDAVEC,       1,    1,                0, 0                          },
	{ /*0x0049*/ 1, 0x4034, FILE_CHEADCOOK,        1,    1,                0, 0                          },
	{ /*0x004a*/ 1, 0x4034, FILE_CHEADPRYCE,       1,    1,                0, 0                          },
	{ /*0x004b*/ 1, 0x4034, FILE_CHEADSILKE,       1,    1,                0, 0                          },
	{ /*0x004c*/ 1, 0x4034, FILE_CHEADSMITH,       1,    1,                0, 0                          },
	{ /*0x004d*/ 1, 0x4034, FILE_CHEADGARETH,      1,    1,                0, 0                          },
	{ /*0x004e*/ 1, 0x4034, FILE_CHEADMURCHIE,     1,    1,                0, 0                          },
	{ /*0x004f*/ 1, 0x4034, FILE_CHEADWONG,        1,    1,                0, 0                          },
	{ /*0x0050*/ 1, 0x4034, FILE_CHEADCARTER,      1,    1,                0, 0                          },
	{ /*0x0051*/ 1, 0x4034, FILE_CHEADTINTIN,      1,    1,                0, 0                          },
	{ /*0x0052*/ 1, 0x4034, FILE_CHEADMUNTON,      1,    1,                0, 0                          },
	{ /*0x0053*/ 1, 0x4034, FILE_CHEADSTAMPER,     1,    1,                0, 0                          },
	{ /*0x0054*/ 1, 0x4034, FILE_CHEADJONES,       1,    1,                0, 0                          },
	{ /*0x0055*/ 1, 0x4034, FILE_CHEADPHELPS,      1,    1,                0, 0                          },
	{ /*0x0056*/ 0, 0x067c, FILE_CDARK_COMBAT,     1,    0.95305162668228, 0, FILE_GCOMBATHANDSLOD       },
	{ /*0x0057*/ 1, 0x0da8, FILE_CELVIS1,          1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0058*/ 1, 0xa274, FILE_CAREA51GUARD,     1,    0.92769956588745, 0, FILE_GHAND_A51GUARD        },
	{ /*0x0059*/ 1, 0x027c, FILE_COVERALL,         1,    0.92769956588745, 0, FILE_GHAND_A51GUARD        },
	{ /*0x005a*/ 1, 0x0268, FILE_CCARRINGTON,      1,    0.85915493965149, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x005b*/ 1, 0x16a4, FILE_CMRBLONDE,        1,    1.1032863855362,  0, FILE_GHAND_MRBLONDE        },
	{ /*0x005c*/ 1, 0x227c, FILE_CSKEDAR,          1,    1,                0, 0                          },
	{ /*0x005d*/ 1, 0x0284, FILE_CTRENT,           1,    0.93896716833115, 0, FILE_GHAND_TRENT           },
	{ /*0x005e*/ 1, 0x2274, FILE_CDDSHOCK,         1,    0.93896716833115, 0, FILE_GHAND_DDFODDER        },
	{ /*0x005f*/ 1, 0x2274, FILE_CLABTECH,         1,    0.93896716833115, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x0060*/ 1, 0x2278, FILE_CSTRIPES,         1,    0.92769956588745, 0, FILE_GHAND_BLACKGUARD      },
	{ /*0x0061*/ 0, 0x067c, FILE_CDARK_FROCK,      1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0062*/ 0, 0x067c, FILE_CDARK_TRENCH,     1,    0.95305162668228, 0, FILE_GHAND_JOTRENCH        },
	{ /*0x0063*/ 1, 0x0274, FILE_COFFICEWORKER,    1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0064*/ 1, 0x0274, FILE_COFFICEWORKER2,   1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0065*/ 0, 0x0630, FILE_CSECRETARY,       1,    0.87323945760727, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0066*/ 0, 0x129c, FILE_CCASSANDRA,       1,    0.98591554164886, 0, FILE_GHAND_VRIES           },
	{ /*0x0067*/ 1, 0x0da8, FILE_CTHEKING,         1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0068*/ 0, 0x2a80, FILE_CFEM_GUARD,       1,    0.96713620424271, 0, FILE_GHAND_JOTRENCH        },
	{ /*0x0069*/ 1, 0x2274, FILE_CDD_LABTECH,      1,    0.93896716833115, 0, FILE_GHAND_DDLABTECH       },
	{ /*0x006a*/ 1, 0x2280, FILE_CDD_SECGUARD,     1,    0.93427228927612, 0, FILE_GHAND_DDSECURITY      },
	{ /*0x006b*/ 1, 0x427c, FILE_CDRCARROLL,       1,    1,                0, 0                          },
	{ /*0x006c*/ 1, 0x027c, FILE_CEYESPY,          1,    1,                0, 0                          },
	{ /*0x006d*/ 0, 0x067c, FILE_CDARK_RIPPED,     1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x006e*/ 1, 0x2280, FILE_CDD_GUARD,        1,    0.93896716833115, 0, FILE_GHAND_DDSECURITY      },
	{ /*0x006f*/ 1, 0x2274, FILE_CDD_SHOCK_INF,    1,    0.93896716833115, 0, FILE_GHAND_DDSHOCK         },
	{ /*0x0070*/ 1, 0x427c, FILE_CTESTCHR,         1,    1,                0, 0                          },
	{ /*0x0071*/ 1, 0x226c, FILE_CBIOTECH,         1,    0.93896716833115, 0, FILE_GHAND_DDBIO           },
	{ /*0x0072*/ 1, 0x227c, FILE_CFBIGUY,          1,    0.93896716833115, 0, FILE_GHAND_FBIARM          },
	{ /*0x0073*/ 1, 0x227c, FILE_CCIAGUY,          1,    0.93896716833115, 0, FILE_GHAND_CIA             },
	{ /*0x0074*/ 1, 0x227c, FILE_CA51TROOPER,      1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0075*/ 1, 0x0274, FILE_CA51AIRMAN,       1,    0.93896716833115, 0, FILE_GHAND_A51AIRMAN       },
	{ /*0x0076*/ 1, 0x027c, FILE_CCHICROB,         1,    1,                0, 0                          },
	{ /*0x0077*/ 1, 0x0264, FILE_CSTEWARD,         1,    0.89201879501343, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0078*/ 0, 0x063c, FILE_CSTEWARDESS,      1,    0.85446006059647, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0079*/ 1, 0x027c, FILE_CPRESIDENT,       1,    0.93896716833115, 0, FILE_GHAND_PRESIDENT       },
	{ /*0x007a*/ 0, 0x063c, FILE_CSTEWARDESS_COAT, 1,    0.85446006059647, 0, FILE_GHAND_STEWARDESS_COAT },
	{ /*0x007b*/ 1, 0x027c, FILE_CMINISKEDAR,      0.75, 0.5,              0, 0                          },
	{ /*0x007c*/ 1, 0x027c, FILE_CNSA_LACKEY,      1,    0.93896716833115, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x007d*/ 1, 0x027c, FILE_CPRES_SECURITY,   1,    0.93896716833115, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x007e*/ 0, 0x0638, FILE_CNEGOTIATOR,      1,    0.85446006059647, 0, FILE_GHAND_JOFROCK         },
	{ /*0x007f*/ 1, 0x027c, FILE_CG5_GUARD,        1,    0.93896716833115, 0, FILE_GHAND_G5GUARD         },
	{ /*0x0080*/ 1, 0x227c, FILE_CPELAGIC_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_TRAGIC_PELAGIC  },
	{ /*0x0081*/ 1, 0x2278, FILE_CG5_SWAT_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_G5GUARD         },
	{ /*0x0082*/ 1, 0x2278, FILE_CALASKAN_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_JOSNOW          },
	{ /*0x0083*/ 1, 0x2da8, FILE_CMAIAN_SOLDIER,   1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0084*/ 1, 0x027c, FILE_CPRESIDENT_CLONE, 1,    0.93896716833115, 0, FILE_GCOMBATHANDSLOD       },
	{ /*0x0085*/ 1, 0x027c, FILE_CPRESIDENT_CLONE, 1,    0.93896716833115, 0, FILE_GHAND_PRESIDENT       },
	{ /*0x0086*/ 0, 0x067c, FILE_CDARK_AF1,        1,    0.95305162668228, 0, FILE_GHAND_JOPILOT         },
	{ /*0x0087*/ 0, 0x067c, FILE_CDARKWET,         1,    0.95305162668228, 0, FILE_GHAND_JOWETSUIT       },
	{ /*0x0088*/ 0, 0x067c, FILE_CDARKAQUALUNG,    1,    0.95305162668228, 0, FILE_GHAND_JOWETSUIT       },
	{ /*0x0089*/ 0, 0x067c, FILE_CDARKSNOW,        1,    0.95305162668228, 0, FILE_GHAND_JOSNOW          },
	{ /*0x008a*/ 0, 0x067c, FILE_CDARKLAB,         1,    0.95305162668228, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x008b*/ 0, 0x267c, FILE_CFEMLABTECH,      1,    0.87323945760727, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x008c*/ 1, 0x227c, FILE_CDDSNIPER,        1,    0.93896716833115, 0, FILE_GHAND_DDSNIPER        },
	{ /*0x008d*/ 1, 0x027c, FILE_CPILOTAF1,        1,    0.88262909650803, 0, FILE_GHAND_JOPILOT         },
	{ /*0x008e*/ 1, 0x227c, FILE_CCILABTECH,       1,    0.93896716833115, 0, FILE_GHAND_CIFEMTECH       },
	{ /*0x008f*/ 0, 0x267c, FILE_CCIFEMTECH,       1,    0.86854463815689, 0, FILE_GHAND_CIFEMTECH       },
	{ /*0x0090*/ 1, 0x027c, FILE_CCARREVENINGSUIT, 1,    0.85915493965149, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x0091*/ 1, 0x027c, FILE_CJONATHON,        1,    0.93896716833115, 0, FILE_GHAND_A51GUARD        },
	{ /*0x0092*/ 1, 0x227c, FILE_CCISOLDIER,       1,    0.93896716833115, 0, FILE_GHAND_CISOLDIER       },
	{ /*0x0093*/ 1, 0x027c, FILE_CSKEDARKING,      1,    1.25,             0, 0                          },
	{ /*0x0094*/ 1, 0x0da8, FILE_CELVISWAISTCOAT,  1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0095*/ 0, 0x067c, FILE_CDARK_LEATHER,    1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0096*/ 0, 0x067c, FILE_CDARK_NEGOTIATOR, 1,    0.95305162668228, 0, FILE_GHAND_JOAF1           },
};

u32 var8007dad0 = 0x00000000;
u32 var8007dad4 = 0x3f800000;
u32 var8007dad8 = 0x00000000;
u32 var8007dadc = 0x00000000;
u32 var8007dae0 = 0x04e50000;
u32 var8007dae4 = 0xbd8ff972;
u32 var8007dae8 = 0x3efbda51;
u32 var8007daec = 0xbf5566cf;
u32 var8007daf0 = 0x3f8951e7;
u32 var8007daf4 = 0x3f8b4e44;
u32 var8007daf8 = 0x3f6d1644;
u32 var8007dafc = 0xbdcccccd;
u32 var8007db00 = 0x3edae148;
u32 var8007db04 = 0xbef70a3d;
u32 var8007db08 = 0x3f844567;
u32 var8007db0c = 0x3f772c62;
u32 var8007db10 = 0x3f6e0e41;
u32 var8007db14 = 0x3e3851ec;
u32 var8007db18 = 0x00000000;
u32 var8007db1c = 0x00000000;
u32 var8007db20 = 0x3f893e4f;
u32 var8007db24 = 0x3f800000;
u32 var8007db28 = 0x3f800000;
u32 var8007db2c = 0x3e72b021;
u32 var8007db30 = 0x3f7a1cac;
u32 var8007db34 = 0xbee147ae;
u32 var8007db38 = 0x3f96d7e0;
u32 var8007db3c = 0x3f91ff82;
u32 var8007db40 = 0x3f925d10;
u32 var8007db44 = 0xbdb8ef35;
u32 var8007db48 = 0x3e6d7732;
u32 var8007db4c = 0x3e016f00;
u32 var8007db50 = 0x3f7da512;
u32 var8007db54 = 0x3f828f5c;
u32 var8007db58 = 0x3f58bac7;
u32 var8007db5c = 0x00000000;
u32 var8007db60 = 0x3e181062;
u32 var8007db64 = 0x3ec2339c;
u32 var8007db68 = 0x3f93d07d;
u32 var8007db6c = 0x3f7ded29;
u32 var8007db70 = 0x3f738ef3;
u32 var8007db74 = 0x00000000;
u32 var8007db78 = 0x00000000;
u32 var8007db7c = 0x00000000;
f32 var8007db80 = 0;
f32 var8007db84 = 1;
u32 var8007db88 = 0x00000000;
u32 var8007db8c = 0x00000000;
u32 var8007db90 = 0x00000000;
u32 var8007db94 = 0x00000000;
u32 var8007db98 = 0x00000000;
u32 var8007db9c = 0x00000000;
u32 var8007dba0 = 0x00000010;
u32 var8007dba4 = 0x00000020;
u32 var8007dba8 = 0x0000000c;
u32 var8007dbac = 0x00000020;
u32 var8007dbb0 = 0x00000018;
u32 var8007dbb4 = 0x00000040;
u32 var8007dbb8 = 0x0000003c;
u32 var8007dbbc = 0x00000050;
u32 var8007dbc0 = 0x000000e1;
u32 var8007dbc4 = 0x00000113;
u32 var8007dbc8 = 0x000001d6;
u32 var8007dbcc = 0x0000023a;
u32 var8007dbd0 = 0xff99ffff;
u32 var8007dbd4 = 0x9999ffff;
u32 var8007dbd8 = 0x99ffffff;
u32 var8007dbdc = 0x99ff99ff;
u32 var8007dbe0 = 0xffff99ff;
u32 var8007dbe4 = 0xff9999ff;
u32 var8007dbe8 = 0x00000000;
u32 var8007dbec = 0x00000000;
u32 var8007dbf0 = 0x00000000;
u32 var8007dbf4 = 0x00000000;
u32 var8007dbf8 = 0x00000000;
u32 var8007dbfc = 0x3f800000;
u32 var8007dc00 = 0x00000000;
u32 var8007dc04 = 0x3f800000;
u32 var8007dc08 = 0x00000000;
u32 var8007dc0c = 0x00000000;
u32 var8007dc10 = 0x00000000;
u32 var8007dc14 = 0x00000100;
u32 var8007dc18 = 0x00000000;
u32 var8007dc1c = 0x00000000;
u32 var8007dc20 = 0x00000000;
u32 var8007dc24 = 0x00000000;
u32 var8007dc28 = 0x00000000;
u32 var8007dc2c = 0x00000000;
u32 var8007dc30 = 0x00000000;
u32 var8007dc34 = 0x00000000;
u32 var8007dc38 = 0x00000000;
u32 var8007dc3c = 0x00000000;
u32 var8007dc40 = 0x00000000;
u32 var8007dc44 = 0x00000000;
u32 var8007dc48 = 0x00000000;
u32 var8007dc4c = 0x00000000;
u32 var8007dc50 = 0x00000000;
u32 var8007dc54 = 0x00000000;
u32 var8007dc58 = 0x00000000;
u32 var8007dc5c = 0x00000000;
u32 var8007dc60 = 0x00000000;
u32 var8007dc64 = 0x00000000;
u32 var8007dc68 = 0x00000000;
u32 var8007dc6c = 0x00000000;
u32 var8007dc70 = 0x00000000;
u32 var8007dc74 = 0x00000000;
u32 var8007dc78 = 0x00000000;
u32 var8007dc7c = 0x00000000;
u32 var8007dc80 = 0x00000000;
u32 var8007dc84 = 0x3f800000;
u32 var8007dc88 = 0x00000000;
u32 var8007dc8c = 0x00000000;
u32 var8007dc90 = 0x00000000;
u32 var8007dc94 = 0x00000000;
u32 var8007dc98 = 0x3f800000;
u32 var8007dc9c = 0x00000000;
u32 var8007dca0 = 0x00000000;
u32 var8007dca4 = 0x00000000;
u32 var8007dca8 = 0x00000000;
u32 var8007dcac = 0x3f800000;
u32 var8007dcb0 = 0x00000000;
u32 var8007dcb4 = 0x00000000;
u32 var8007dcb8 = 0x00000000;
u32 var8007dcbc = 0x00000000;
u32 var8007dcc0 = 0x3f800000;
u32 var8007dcc4 = 0x00000000;
u32 var8007dcc8 = 0x00000000;
u32 var8007dccc = 0x00000000;
u32 var8007dcd0 = 0x00000000;
u32 var8007dcd4 = 0x00000000;
u32 var8007dcd8 = 0x00000000;
u32 var8007dcdc = 0xbf800000;
u32 var8007dce0 = 0x00000000;
u32 var8007dce4 = 0x3f800000;
u32 var8007dce8 = 0x00000000;
u32 var8007dcec = 0x00000000;
u32 var8007dcf0 = 0x00000000;
u32 var8007dcf4 = 0x00000000;
u32 var8007dcf8 = 0x00000000;
u32 var8007dcfc = 0x00000000;
u32 var8007dd00 = 0xc19ffffe;
u32 var8007dd04 = 0x00000000;
u32 var8007dd08 = 0x419ffffe;
u32 var8007dd0c = 0x00000000;
u32 var8007dd10 = 0x00000000;
u32 var8007dd14 = 0x00000000;
u32 var8007dd18 = 0x00000000;
u32 var8007dd1c = 0x00000000;
u32 var8007dd20 = 0x00000000;
u32 var8007dd24 = 0x00000000;
u32 var8007dd28 = 0x00000000;
u32 var8007dd2c = 0x00000000;
u32 var8007dd30 = 0x00000000;
u32 var8007dd34 = 0x00000000;
u32 var8007dd38 = 0x00000000;
u32 var8007dd3c = 0x00000000;
u32 var8007dd40 = 0x00000000;
u32 var8007dd44 = 0x00000000;
u32 var8007dd48 = 0xbf800000;
u32 var8007dd4c = 0x00000000;
u32 var8007dd50 = 0x00000000;
u32 var8007dd54 = 0xbf800000;
u32 var8007dd58 = 0x00000000;
u32 var8007dd5c = 0x00000000;
u32 var8007dd60 = 0xbf800000;
u32 var8007dd64 = 0x00000000;
u32 var8007dd68 = 0x00000000;
u32 var8007dd6c = 0xbf800000;
u32 var8007dd70 = 0x00000000;
u32 var8007dd74 = 0x3f800000;
u32 var8007dd78 = 0x00000000;
u32 var8007dd7c = 0x00000000;
u32 var8007dd80 = 0x3f800000;
u32 var8007dd84 = 0x00000000;
u32 var8007dd88 = 0x00000000;
u32 var8007dd8c = 0x3f800000;
u32 var8007dd90 = 0x00000000;
u32 var8007dd94 = 0x00000000;
u32 var8007dd98 = 0x3f800000;
u32 var8007dd9c = 0x00000000;
u32 var8007dda0 = 0x00000000;
u32 var8007dda4 = 0x00000000;
u32 var8007dda8 = 0x3f800000;
u32 var8007ddac = 0x3f800000;
u32 var8007ddb0 = 0x00000000;
u32 var8007ddb4 = 0x00000000;
u32 var8007ddb8 = 0x00000000;
u32 var8007ddbc = 0x00000000;
u32 var8007ddc0 = 0x00000000;
u32 var8007ddc4 = 0x00000000;
u32 var8007ddc8 = 0x00000000;
u32 var8007ddcc = 0x00000000;
u32 var8007ddd0 = 0x00000000;
u32 var8007ddd4 = 0x00000000;
u32 var8007ddd8 = 0x447a0000;
u32 var8007dddc = 0x00000000;
u32 var8007dde0 = 0x00000000;
u32 var8007dde4 = 0x00000000;
u32 var8007dde8 = 0x00000000;
u32 var8007ddec = 0xff000000;
u32 var8007ddf0 = 0x00000000;
u32 var8007ddf4 = 0x00000000;
u32 var8007ddf8 = 0x00000000;
u32 var8007ddfc = 0x00000000;
u32 var8007de00 = 0x00000000;
u32 var8007de04 = 0x00000000;
u32 var8007de08 = 0x00000000;
u32 var8007de0c = 0x00000000;
u32 var8007de10 = 0x00000000;
u32 var8007de14 = 0x00000000;
u32 var8007de18 = 0x00000000;
u32 var8007de1c = 0x00000000;
u32 var8007de20 = 0x00000000;
u32 var8007de24 = 0x00000000;
u32 var8007de28 = 0x00000000;
u32 var8007de2c = 0x00000000;
u32 var8007de30 = 0x00000000;
u32 var8007de34 = 0x00000000;
u32 var8007de38 = 0x00000000;
u32 var8007de3c = 0x00000000;
u32 var8007de40 = 0x00000000;
u32 var8007de44 = 0x00000000;
u32 var8007de48 = 0x00000000;
u32 var8007de4c = 0x00000000;
u32 var8007de50 = 0x00000000;
u32 var8007de54 = 0x00000000;
u32 var8007de58 = 0x00000000;
u32 var8007de5c = 0x00000000;
u32 var8007de60 = 0x00000000;
u32 var8007de64 = 0x00000000;
u32 var8007de68 = 0x00000000;
u32 var8007de6c = 0x00000000;
u32 var8007de70 = 0x00000000;
u32 var8007de74 = 0x00000000;
u32 var8007de78 = 0x00000000;
u32 var8007de7c = 0x00000000;
u32 var8007de80 = 0x00000000;
u32 var8007de84 = 0x00000000;
u32 var8007de88 = 0x00000000;
u32 var8007de8c = 0x00000000;
u32 var8007de90 = 0x00000000;
u32 var8007de94 = 0x00000000;
u32 var8007de98 = 0x00000000;
u32 var8007de9c = 0x00000000;
u32 var8007dea0 = 0x00000000;
u32 var8007dea4 = 0x00000000;
u32 var8007dea8 = 0x00000000;
u32 var8007deac = 0x00000000;
u32 var8007deb0 = 0x00000000;
u32 var8007deb4 = 0x00000000;
u32 var8007deb8 = 0x00000000;
u32 var8007debc = 0x00000000;
u32 var8007dec0 = 0x00000000;
u32 var8007dec4 = 0x00000000;
u32 var8007dec8 = 0x00000000;
u32 var8007decc = 0x00000000;
u32 var8007ded0 = 0x00000000;
u32 var8007ded4 = 0x00000000;
u32 var8007ded8 = 0x00000000;
u32 var8007dedc = 0x00000000;
u32 var8007dee0 = 0x00000000;
u32 var8007dee4 = 0x00000000;
u32 var8007dee8 = 0x00000000;
u32 var8007deec = 0x00000000;
u32 var8007def0 = 0x00000000;
u32 var8007def4 = 0x00000000;
u32 var8007def8 = 0x00000000;
u32 var8007defc = 0x00000000;
u32 var8007df00 = 0x00000000;
u32 var8007df04 = 0x00000000;
u32 var8007df08 = 0x00000000;
u32 var8007df0c = 0x00000000;
u32 var8007df10 = 0x00000000;
u32 var8007df14 = 0x00000000;
u32 var8007df18 = 0x00000000;
u32 var8007df1c = 0x00000000;
u32 var8007df20 = 0x00000000;
u32 var8007df24 = 0x00000000;
u32 var8007df28 = 0x00000000;
u32 var8007df2c = 0x00000000;
u32 var8007df30 = 0x00000000;
u32 var8007df34 = 0x00000000;
u32 var8007df38 = 0x00000000;
u32 var8007df3c = 0x00000000;
u32 var8007df40 = 0x00000000;
u32 var8007df44 = 0x00000000;
u32 var8007df48 = 0x00000000;
u32 var8007df4c = 0x00000000;
u32 var8007df50 = 0x00000000;
u32 var8007df54 = 0x00000000;
u32 var8007df58 = 0x00000000;
u32 var8007df5c = 0x00000000;
u32 var8007df60 = 0x00000000;
u32 var8007df64 = 0x00000000;
u32 var8007df68 = 0x00000000;
u32 var8007df6c = 0x00000000;
u32 var8007df70 = 0x00000000;
u32 var8007df74 = 0x00000000;
u32 var8007df78 = 0x00000000;
u32 var8007df7c = 0x00000000;
u32 var8007df80 = 0x00000000;
u32 var8007df84 = 0x00000000;
u32 var8007df88 = 0x00000000;
u32 var8007df8c = 0x00000000;
u32 var8007df90 = 0x00000000;
u32 var8007df94 = 0x00000000;
u32 var8007df98 = 0x00000000;
u32 var8007df9c = 0x00000000;
u32 var8007dfa0 = 0x00000000;
u32 var8007dfa4 = 0x00000000;
u32 var8007dfa8 = 0x00000000;
u32 var8007dfac = 0x00000000;
u32 var8007dfb0 = 0x00000000;
u32 var8007dfb4 = 0x00000000;
u32 var8007dfb8 = 0x00000000;
u32 var8007dfbc = 0x00000000;
u32 var8007dfc0 = 0x00000000;
u32 var8007dfc4 = 0x00000000;
u32 var8007dfc8 = 0x00000000;
u32 var8007dfcc = 0x00000000;
u32 var8007dfd0 = 0x00000000;
u32 var8007dfd4 = 0x00000000;
u32 var8007dfd8 = 0x00000000;
u32 var8007dfdc = 0x00000000;
u32 var8007dfe0 = 0x00000000;
u32 var8007dfe4 = 0x00000000;
u32 var8007dfe8 = 0x00000000;
u32 var8007dfec = 0x00000000;
u32 var8007dff0 = 0x00000000;
u32 var8007dff4 = 0x00000000;
u32 var8007dff8 = 0x00000000;
u32 var8007dffc = 0x00000000;
u32 var8007e000 = 0x00000000;
u32 var8007e004 = 0x00000000;
u32 var8007e008 = 0x00000000;
u32 var8007e00c = 0x00000000;
u32 var8007e010 = 0x00000000;
u32 var8007e014 = 0x00000000;
u32 var8007e018 = 0x00000000;
u32 var8007e01c = 0x00000000;
u32 var8007e020 = 0x00000000;
u32 var8007e024 = 0x00000000;
u32 var8007e028 = 0x00000000;
u32 var8007e02c = 0x00000000;
u32 var8007e030 = 0x00000000;
u32 var8007e034 = 0x00000000;
u32 var8007e038 = 0x00000000;
u32 var8007e03c = 0x00000000;
u32 var8007e040 = 0x00000000;
u32 var8007e044 = 0x00000000;
u32 var8007e048 = 0x00000000;
u32 var8007e04c = 0x00000000;
u32 var8007e050 = 0x00000000;
u32 var8007e054 = 0x00000000;
u32 var8007e058 = 0x00000000;
u32 var8007e05c = 0x00000000;
u32 var8007e060 = 0x00000000;
u32 var8007e064 = 0x00000000;
u32 var8007e068 = 0x00000000;
u32 var8007e06c = 0x00000000;
u32 var8007e070 = 0x00000000;
u32 var8007e074 = 0x00000000;
u32 var8007e078 = 0x00000000;
u32 var8007e07c = 0x00000000;
u32 var8007e080 = 0x00000000;
u32 var8007e084 = 0x00000000;
u32 var8007e088 = 0x00000000;
u32 var8007e08c = 0x00000000;
u32 var8007e090 = 0x00000000;
u32 var8007e094 = 0x00000000;
u32 var8007e098 = 0x00000000;
u32 var8007e09c = 0x00000000;
u32 var8007e0a0 = 0x00000000;
u32 var8007e0a4 = 0x00000000;
u32 var8007e0a8 = 0x00000000;
u32 var8007e0ac = 0x00000000;
u32 var8007e0b0 = 0x00000000;
u32 var8007e0b4 = 0x00000000;
u32 var8007e0b8 = 0x00000000;
u32 var8007e0bc = 0x00000000;
u32 var8007e0c0 = 0x00000000;
u32 var8007e0c4 = 0x00000000;
u32 var8007e0c8 = 0x00000000;
u32 var8007e0cc = 0x00000000;
u32 var8007e0d0 = 0x00000000;
u32 var8007e0d4 = 0x00000000;
u32 var8007e0d8 = 0x00000000;
u32 var8007e0dc = 0x00000000;
u32 var8007e0e0 = 0x00000000;
u32 var8007e0e4 = 0x00000000;
u32 var8007e0e8 = 0x00000000;
u32 var8007e0ec = 0x00000000;
u32 var8007e0f0 = 0x00000000;
u32 var8007e0f4 = 0x00000000;
u32 var8007e0f8 = 0x00000000;
u32 var8007e0fc = 0x00000000;
u32 var8007e100 = 0x00000000;
u32 var8007e104 = 0x00000000;
u32 var8007e108 = 0x00000000;
u32 var8007e10c = 0x00000000;
u32 var8007e110 = 0x00000000;
u32 var8007e114 = 0x00000000;
u32 var8007e118 = 0x00000000;
u32 var8007e11c = 0x00000000;
u32 var8007e120 = 0x00000000;
u32 var8007e124 = 0x00000000;
u32 var8007e128 = 0x00000000;
u32 var8007e12c = 0x00000000;
u32 var8007e130 = 0x00000000;
u32 var8007e134 = 0x00000000;
u32 var8007e138 = 0x00000000;
u32 var8007e13c = 0x00000000;
u32 var8007e140 = 0x00000000;
u32 var8007e144 = 0x00000000;
u32 var8007e148 = 0x00000000;
u32 var8007e14c = 0x00000000;
u32 var8007e150 = 0x00000000;
u32 var8007e154 = 0x00000000;
u32 var8007e158 = 0x00000000;
u32 var8007e15c = 0x00000000;
u32 var8007e160 = 0x00000000;
u32 var8007e164 = 0x00000000;
u32 var8007e168 = 0x00000000;
u32 var8007e16c = 0x00000000;
u32 var8007e170 = 0x00000000;
u32 var8007e174 = 0x00000000;
u32 var8007e178 = 0x00000000;
u32 var8007e17c = 0x00000000;
u32 var8007e180 = 0x00000000;
u32 var8007e184 = 0x00000000;
u32 var8007e188 = 0x00000000;
u32 var8007e18c = 0x00000000;
u32 var8007e190 = 0x00000000;
u32 var8007e194 = 0x00000000;
u32 var8007e198 = 0x00000000;
u32 var8007e19c = 0x00000000;
u32 var8007e1a0 = 0x00000000;
u32 var8007e1a4 = 0x00000000;
u32 var8007e1a8 = 0x00000000;
u32 var8007e1ac = 0x00000000;
u32 var8007e1b0 = 0x00000000;
u32 var8007e1b4 = 0x00000000;
u32 var8007e1b8 = 0x00000000;
u32 var8007e1bc = 0x00000000;
u32 var8007e1c0 = 0x00000000;
u32 var8007e1c4 = 0x00000000;
u32 var8007e1c8 = 0x00000000;
u32 var8007e1cc = 0x00000000;
u32 var8007e1d0 = 0x00000000;
u32 var8007e1d4 = 0x00000000;
u32 var8007e1d8 = 0x00000000;
u32 var8007e1dc = 0x00000000;
u32 var8007e1e0 = 0x00000000;
u32 var8007e1e4 = 0x00000000;
u32 var8007e1e8 = 0x00000000;
u32 var8007e1ec = 0x00000000;
u32 var8007e1f0 = 0x00000000;
u32 var8007e1f4 = 0x00000000;
u32 var8007e1f8 = 0x00000000;
u32 var8007e1fc = 0x00000000;
u32 var8007e200 = 0x00000000;
u32 var8007e204 = 0x00000000;
u32 var8007e208 = 0x00000000;
u32 var8007e20c = 0x00000000;
u32 var8007e210 = 0x00000000;
u32 var8007e214 = 0x00000000;
u32 var8007e218 = 0x00000000;
u32 var8007e21c = 0x00000000;
u32 var8007e220 = 0x00000000;
u32 var8007e224 = 0x00000000;
u32 var8007e228 = 0x00000000;
u32 var8007e22c = 0x00000000;
u32 var8007e230 = 0x00000000;
u32 var8007e234 = 0x00000000;
u32 var8007e238 = 0x00000000;
u32 var8007e23c = 0x00000000;
u32 var8007e240 = 0x00000000;
u32 var8007e244 = 0x00000000;
u32 var8007e248 = 0x00000000;
u32 var8007e24c = 0x00000000;
u32 var8007e250 = 0x00000000;
u32 var8007e254 = 0x00000000;
u32 var8007e258 = 0x00000000;
u32 var8007e25c = 0x00000000;
u32 var8007e260 = 0x00000000;
u32 var8007e264 = 0x00000000;
u32 var8007e268 = 0x00000000;
u32 var8007e26c = 0x00000000;
u32 var8007e270 = 0x00000000;
u32 var8007e274 = 0x00000000;
u32 var8007e278 = 0x00000000;
u32 var8007e27c = 0x00000000;
u32 var8007e280 = 0x00000000;
u32 var8007e284 = 0x00000000;
u32 var8007e288 = 0x00000000;
u32 var8007e28c = 0x00000000;
u32 var8007e290 = 0x00000000;
u32 var8007e294 = 0x00000000;
u32 var8007e298 = 0x00000000;
u32 var8007e29c = 0x00000000;
u32 var8007e2a0 = 0x00000000;
u32 var8007e2a4 = 0x00000000;
u32 var8007e2a8 = 0x00000000;
u32 var8007e2ac = 0x00000000;
u32 var8007e2b0 = 0x00000000;
u32 var8007e2b4 = 0x00000000;
u32 var8007e2b8 = 0x00000000;
u32 var8007e2bc = 0x00000000;
u32 var8007e2c0 = 0x00000000;
u32 var8007e2c4 = 0x00000000;
u32 var8007e2c8 = 0x00000000;
u32 var8007e2cc = 0x00000000;
u32 var8007e2d0 = 0x00000000;
u32 var8007e2d4 = 0x00000000;
u32 var8007e2d8 = 0x00000000;
u32 var8007e2dc = 0x00000000;
u32 var8007e2e0 = 0x00000000;
u32 var8007e2e4 = 0x00000000;
u32 var8007e2e8 = 0x00000000;
u32 var8007e2ec = 0x00000000;
u32 var8007e2f0 = 0x00000000;
u32 var8007e2f4 = 0x00000000;
u32 var8007e2f8 = 0x00000000;
u32 var8007e2fc = 0x00000000;
u32 var8007e300 = 0x00000000;
u32 var8007e304 = 0x00000000;
u32 var8007e308 = 0x00000000;
u32 var8007e30c = 0x00000000;
u32 var8007e310 = 0x00000000;
u32 var8007e314 = 0x00000000;
u32 var8007e318 = 0x00000000;
u32 var8007e31c = 0x00000000;
u32 var8007e320 = 0x00000000;
u32 var8007e324 = 0x00000000;
u32 var8007e328 = 0x00000000;
u32 var8007e32c = 0x00000000;
u32 var8007e330 = 0x00000000;
u32 var8007e334 = 0x00000000;
u32 var8007e338 = 0x00000000;
u32 var8007e33c = 0x00000000;
u32 var8007e340 = 0x00000000;
u32 var8007e344 = 0x00000000;
u32 var8007e348 = 0x00000000;
u32 var8007e34c = 0x00000000;
u32 var8007e350 = 0x00000000;
u32 var8007e354 = 0x00000000;
u32 var8007e358 = 0x00000000;
u32 var8007e35c = 0x00000000;
u32 var8007e360 = 0x00000000;
u32 var8007e364 = 0x00000000;
u32 var8007e368 = 0x00000000;
u32 var8007e36c = 0x00000000;
u32 var8007e370 = 0x00000000;
u32 var8007e374 = 0x00000000;
u32 var8007e378 = 0x00000000;
u32 var8007e37c = 0x00000000;
u32 var8007e380 = 0x00000000;
u32 var8007e384 = 0x00000000;
u32 var8007e388 = 0x00000000;
u32 var8007e38c = 0x00000000;
u32 var8007e390 = 0x00000000;
u32 var8007e394 = 0x00000000;
u32 var8007e398 = 0x00000000;
u32 var8007e39c = 0x00000000;
u32 var8007e3a0 = 0x00000000;
u32 var8007e3a4 = 0x00000000;
u32 var8007e3a8 = 0x00000000;
u32 var8007e3ac = 0x00000000;
u32 var8007e3b0 = 0x00000000;
u32 var8007e3b4 = 0x00000000;
u32 var8007e3b8 = 0x00000000;
u32 var8007e3bc = 0x00000000;
u32 var8007e3c0 = 0xab8d9f77;
u32 var8007e3c4 = 0x81280783;
u32 var8007e3c8 = 0x00000000;
u32 var8007e3cc = 0x00000000;
u32 var8007e3d0 = 0x00000bb8;
u32 var8007e3d4 = 0x00000078;
u32 var8007e3d8 = 0x00000bb8;
u32 var8007e3dc = 0x00000050;
u32 var8007e3e0 = 0x00000000;
u32 var8007e3e4 = 0x00000000;
u32 var8007e3e8 = 0x000001f4;
u32 var8007e3ec = 0x00000014;
u32 var8007e3f0 = 0x0000000c;
u32 var8007e3f4 = 0x00000000;
u32 var8007e3f8 = 0x00000000;
u32 var8007e3fc = 0x00000000;
u32 var8007e400 = 0x00000000;
u32 var8007e404 = 0x000005dc;
u32 var8007e408 = 0x00000028;
u32 var8007e40c = 0x000001f4;
u32 var8007e410 = 0x00000014;
u32 var8007e414 = 0x00000000;
u32 var8007e418 = 0x00000000;
u32 var8007e41c = 0x000001f4;
u32 var8007e420 = 0x00000014;
u32 var8007e424 = 0x0000000c;
u32 var8007e428 = 0x00000000;
u32 var8007e42c = 0x00000000;
u32 var8007e430 = 0x00000000;
u32 var8007e434 = 0x00000000;
u32 var8007e438 = 0x00001770;
u32 var8007e43c = 0x00000078;
u32 var8007e440 = 0x00001770;
u32 var8007e444 = 0x00000050;
u32 var8007e448 = 0x00000000;
u32 var8007e44c = 0x00000000;
u32 var8007e450 = 0x000003e8;
u32 var8007e454 = 0x00000014;
u32 var8007e458 = 0x00000004;
u32 var8007e45c = 0x00000000;
u32 var8007e460 = 0x00000000;
u32 var8007e464 = 0x00000000;
u32 var8007e468 = 0x00000000;
u32 var8007e46c = 0x000005dc;
u32 var8007e470 = 0x00000028;
u32 var8007e474 = 0x000001f4;
u32 var8007e478 = 0x00000014;
u32 var8007e47c = 0x00000000;
u32 var8007e480 = 0x00000000;
u32 var8007e484 = 0x000001f4;
u32 var8007e488 = 0x00000014;
u32 var8007e48c = 0x00000004;
u32 var8007e490 = 0x00000000;
u32 var8007e494 = 0x00000000;
u32 var8007e498 = 0x00000000;
u32 var8007e49c = 0x00000000;
u32 var8007e4a0 = 0x00000000;
u32 var8007e4a4 = 0x00000000;
u32 var8007e4a8 = 0x3f800000;
u32 var8007e4ac = 0x0000004b;
u32 var8007e4b0 = 0x000001e0;
u32 var8007e4b4 = 0x000000a8;

struct explosiontype g_ExplosionTypes[NUM_EXPLOSIONTYPES] = {
	/*00*/ { 0.1, 0.1, 0,   0,    0.1,  0,    0,    1,   1, 1, SMOKETYPE_0, 0x0000, 0     },
	/*01*/ { 1,   1,   0,   0,    1,    0,    0,    30,  1, 1, SMOKETYPE_7, 0x0000, 0     },
	/*02*/ { 20,  20,  0,   0,    30,   50,   50,   40,  1, 3, SMOKETYPE_2, 0x8099, 0.125 },
	/*03*/ { 50,  50,  0,   0,    50,   100,  100,  45,  1, 4, SMOKETYPE_2, 0x809a, 0.5   },
	/*04*/ { 60,  80,  2,   0.6,  100,  130,  240,  60,  2, 5, SMOKETYPE_1, 0x809e, 1     },
	/*05*/ { 60,  120, 2,   0.6,  150,  160,  280,  60,  2, 5, SMOKETYPE_1, 0x809e, 2     },
	/*06*/ { 20,  20,  0,   0,    22,   40,   40,   60,  1, 3, SMOKETYPE_2, 0x8099, 0.5   },
	/*07*/ { 35,  40,  0,   0,    35,   70,   70,   60,  1, 4, SMOKETYPE_2, 0x809a, 1     },
	/*08*/ { 50,  80,  2,   0.6,  50,   100,  160,  60,  2, 5, SMOKETYPE_1, 0x809e, 2     },
	/*09*/ { 60,  120, 2,   0.6,  50,   130,  180,  60,  2, 5, SMOKETYPE_1, 0x809e, 2     },
	/*10*/ { 40,  40,  0.8, 0.5,  70,   80,   160,  80,  4, 5, SMOKETYPE_4, 0x80a0, 1     },
	/*11*/ { 50,  50,  1.2, 0.8,  100,  100,  200,  90,  1, 4, SMOKETYPE_4, 0x809e, 2     },
	/*12*/ { 70,  60,  2,   1.2,  150,  140,  280,  90,  2, 5, SMOKETYPE_5, 0x809e, 4     },
	/*13*/ { 80,  60,  4,   1.4,  200,  200,  400,  90,  2, 5, SMOKETYPE_6, 0x809f, 4     },
	/*14*/ { 50,  50,  0,   0,    120,  150,  300,  150, 4, 4, SMOKETYPE_4, 0x809f, 4     },
	/*15*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_7, 0x809c, 0     },
	/*16*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_7, 0x809c, 0     },
	/*17*/ { 80,  60,  10,  5,    1500, 2200, 3600, 500, 1, 2, SMOKETYPE_0, 0x80a5, 4     },
	/*18*/ { 80,  60,  3,   1,    300,  450,  640,  60,  1, 2, SMOKETYPE_0, 0x809f, 4     },
	/*19*/ { 90,  75,  2.5, 0.87, 250,  375,  600,  180, 2, 5, SMOKETYPE_6, 0x809f, 4     },
	/*20*/ { 160, 120, 6,   2,    600,  450,  640,  60,  1, 2, SMOKETYPE_0, 0x809f, 4     },
	/*21*/ { 40,  30,  2,   0.7,  100,  140,  270,  45,  2, 5, SMOKETYPE_4, 0x809f, 3.5   },
	/*22*/ { 20,  20,  0,   0,    30,   100,  200,  40,  1, 3, SMOKETYPE_2, 0x8099, 0.25  },
	/*23*/ { 100, 80,  4,   1.4,  210,  220,  500,  90,  2, 5, SMOKETYPE_6, 0x809f, 4     },
	/*24*/ { 80,  60,  4,   1.4,  500,  200,  400,  90,  2, 5, SMOKETYPE_6, 0x809f, 4     },
	/*25*/ { 640, 480, 32,  11.2, 1600, 1000, 1000, 180, 2, 5, SMOKETYPE_0, 0x80a4, 4     },
};

u32 var8007e930 = 0x00000000;
u32 var8007e934 = 0x00000000;
u32 var8007e938 = 0x00000000;
u32 var8007e93c = 0xffffffff;

struct smoketype g_SmokeTypes[NUM_SMOKETYPES] = {
	/*00*/ { 1,   60, 99,  0,   0,     0x80808000, 0.3, 120, 0.15, 0.3,  1 },
	/*01*/ { 220, 60, 45,  60,  0.02,  0x50506000, 0.3, 120, 0.15, 0.3,  1 },
	/*02*/ { 220, 60, 50,  20,  0.01,  0x80808000, 0.3, 120, 0.15, 0.3,  1 },
	/*03*/ { 280, 60, 120, 100, 0.01,  0xc0c0c000, 0.3, 120, 0.15, 0.3,  1 },
	/*04*/ { 280, 60, 60,  80,  0.02,  0x40404000, 0.3, 120, 0.15, 0.3,  1 },
	/*05*/ { 340, 60, 50,  190, 0.015, 0x40404000, 0.3, 120, 0.15, 0.3,  1 },
	/*06*/ { 380, 60, 70,  300, 0.01,  0x40404000, 0.3, 120, 0.15, 0.3,  1 },
	/*07*/ { 60,  60, 8,   15,  0.03,  0xffffff00, 0.3, 120, 0.15, 0.3,  1 },
	/*08*/ { 20,  1,  6,   30,  0.03,  0xffffff00, 2,   30,  0.15, 0.3,  1 },
	/*09*/ { 25,  1,  7,   16,  0.03,  0xe0e0e000, 3,   30,  0.15, 0.3,  1 },
	/*10*/ { 900, 60, 70,  900, 0.01,  0x40404000, 0.3, 180, 0.15, 0.3,  1 },
	/*11*/ { 20,  1,  6,   30,  0.03,  0x18204000, 2,   30,  0.15, 0.3,  1 },
	/*12*/ { 50,  25, 7,   2,   0.03,  0xffffbf00, 0.3, 150, 0.15, 0.3,  1 },
	/*13*/ { 12,  15, 7,   5,   0.03,  0x66404000, 1,   18,  0.15, 0.3,  1 },
	/*14*/ { 12,  15, 7,   5,   0.03,  0x66660000, 1,   18,  0.15, 0.3,  1 },
	/*15*/ { 50,  5,  5,   3,   0.03,  0xffffff00, 0.3, 150, 0,    0.45, 0 },
	/*16*/ { 50,  5,  6,   3,   0.03,  0xafffaf00, 0.3, 150, 0.09, 0.3,  0 },
	/*17*/ { 50,  5,  3,   3,   0.03,  0xffffff00, 0.3, 150, 0,    0.35, 0 },
	/*18*/ { 50,  5,  3,   3,   0.03,  0xaf8f6f00, 0.3, 150, 0.1,  0.3,  0 },
	/*19*/ { 50,  1,  2,   16,  0.03,  0xffff8000, 3,   30,  0.15, 0.3,  1 },
	/*20*/ { 180, 10, 8,   18,  0.06,  0xffffff00, 0.3, 0,   0.19, 0.07, 1 },
	/*21*/ { 220, 40, 45,  60,  0.02,  0x20202000, 0.3, 30,  1.5,  1.8,  6 },
	/*22*/ { 220, 5,  8,   60,  0.03,  0xaf8f6f00, 0.3, 30,  1.5,  0.3,  1 },
};

u32 var8007ec7c = 0x00000000;

// 24ca0
u32 sparktable[] = {
	/*0x00*/ 0x0064001c, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x01*/ 0x0064001c, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0x80ffffff, 0xffffffff, 0x3ca3d70a,
	/*0x02*/ 0x0028ffff, 0x001e001e, 0x00000000, 0x40000000, 0x00230023, 0x00050000, 0x00000001, 0x301010ff, 0x401010ff, 0x3ca3d70a,
	/*0x03*/ 0x0028ffff, 0x012c00c8, 0x00000000, 0x3e19999a, 0x00050005, 0x00040000, 0x00000001, 0xffffff40, 0x560011a0, 0x3ca3d70a,
	/*0x04*/ 0x000a0001, 0x04b00190, 0x00000000, 0x3e19999a, 0x00050005, 0x00050000, 0x00000001, 0xa0a0e000, 0xffffffff, 0x3ca3d70a,
	/*0x05*/ 0x0028000a, 0x000a000a, 0x00000000, 0x40400000, 0x00b4005a, 0x00050000, 0x00000001, 0x00ff6aff, 0xffffffff, 0x3ca3d70a,
	/*0x06*/ 0x000f000a, 0x00140014, 0x00000000, 0x3f266666, 0x00b4005a, 0x00050000, 0x00000001, 0xa0a0e0ff, 0xffffffff, 0x3ca3d70a,
	/*0x07*/ 0x00010001, 0x00780002, 0x00000000, 0x00000000, 0x003c003c, 0x00050000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x08*/ 0x00010001, 0x012c0032, 0x00000000, 0x00000000, 0x00050005, 0x00050000, 0x00000001, 0xffff8000, 0xffffffff, 0x3ca3d70a,
	/*0x09*/ 0x00010001, 0x01900064, 0x00000000, 0x00000000, 0x000a000a, 0x00050000, 0x00000001, 0xffff8000, 0xffffffff, 0x3ca3d70a,
	/*0x0a*/ 0x004b0064, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x0b*/ 0x004b0064, 0x00140005, 0x00000000, 0x3fc00000, 0x003c003c, 0x00140000, 0x00000001, 0xa0a0e0ff, 0xffffffff, 0x3ca3d70a,
	/*0x0c*/ 0x0014000a, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x0d*/ 0x0014000a, 0x00140005, 0x00000000, 0x3fc00000, 0x003c003c, 0x00140000, 0x00000001, 0xa0a0e0ff, 0xffffffff, 0x3ca3d70a,
	/*0x0e*/ 0x00010000, 0x00500001, 0x001e0005, 0x00000000, 0x0078005a, 0x000f0000, 0x00000000, 0x0808f000, 0xffffffff, 0x3ca3d70a,
	/*0x0f*/ 0x00460000, 0x0096000f, 0x00000000, 0x40c00000, 0x0028000a, 0x00030000, 0x00000000, 0x11112880, 0xaaaaaa40, 0x3ca3d70a,
	/*0x10*/ 0x0032001c, 0x00640001, 0x00000000, 0x3f800000, 0x003c001e, 0x000a0000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x11*/ 0x012c0064, 0x00640002, 0x00000000, 0x3e99999a, 0x001e0001, 0x00280000, 0x00000002, 0xffff80ff, 0xffffffff, 0x3dcccccd,
	/*0x12*/ 0x00aa0050, 0x003c0005, 0x00000000, 0x3ecccccd, 0x001e0005, 0x000a0000, 0x00000003, 0xa0a0e0ff, 0xffffffff, 0x3dcccccd,
	/*0x13*/ 0x00780028, 0x001e0007, 0x00000000, 0x3e4ccccd, 0x003c0005, 0x000f0000, 0x00000003, 0xffff80ff, 0xffffffff, 0x3dcccccd,
	/*0x14*/ 0x0050000a, 0x000a0009, 0x00000000, 0x3dcccccd, 0x001e0005, 0x00140000, 0x00000003, 0xa0a0e0ff, 0xffffffff, 0x3dcccccd,
	/*0x15*/ 0x00640001, 0x00640032, 0x00000000, 0x40000000, 0x001e0014, 0x000f0000, 0x00000001, 0xffff80ff, 0xffffffff, 0x3ca3d70a,
	/*0x16*/ 0x0064001c, 0x00640001, 0x00000000, 0x40000000, 0x00780078, 0x001e0000, 0x00000001, 0xff8080ff, 0xffff80ff, 0x3ca3d70a,
	/*0x17*/ 0x0064001c, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0x4fff4fff, 0xffffffff, 0x3ca3d70a,
	/*0x18*/ 0x0064001c, 0x00640001, 0x00000000, 0x40000000, 0x003c003c, 0x000f0000, 0x00000001, 0xffff7f7f, 0xffffffff, 0x3ca3d70a,
	/*0x19*/ 0x0028ffff, 0x001e000a, 0x00000000, 0x40000000, 0x00320023, 0x000a0000, 0x00000001, 0x301010ff, 0x401010ff, 0x3ca3d70a,
	/*0x1a*/ 0x00460000, 0x0096000f, 0x00000000, 0x40c00000, 0x0028000a, 0x00030000, 0x00000000, 0x1111a880, 0xaaaaff40, 0x3ca3d70a,
};

u32 var8007f0b8 = 0x00000000;
u32 var8007f0bc = 0x00000000;
struct weatherdata *g_WeatherData = NULL;

s32 var8007f0c4[4] = {
	0x000080b7,
	0x000080b6,
	0x000080b8,
	-1,
};

u32 g_RainSpeedExtra = 20;
u32 g_SnowSpeed = 15;
u32 g_SnowSpeedExtra = 10;
u32 var8007f0e0 = 0x00000001;
u32 var8007f0e4 = 0xaaaaaa1f;
u32 var8007f0e8 = 0x11111844;
u32 var8007f0ec = 0x00000032;
u32 var8007f0f0 = 0x000009c4;
u32 var8007f0f4 = 0x00000001;
u32 var8007f0f8 = 0x00000001;
u32 var8007f0fc = 0x000055f0;
u32 var8007f100 = 0x00000032;
u32 var8007f104 = 0x00000005;
u32 var8007f108 = 0x0000000a;
u32 var8007f10c = 0x8888aaff;
u32 var8007f110 = 0xffffff7f;
u32 var8007f114 = 0x00000000;
u32 var8007f118 = 0x00000000;
u32 var8007f11c = 0x00000000;
u32 var8007f120 = 0x00000000;
u32 var8007f124 = 0x00000000;
u32 var8007f128 = 0x00000000;
u32 var8007f12c = 0x00000000;
u32 var8007f130 = 0x00000000;
u32 var8007f134 = 0x00000000;
u32 var8007f138 = 0x00000000;
u32 var8007f13c = 0x3e4ccccd;
u32 var8007f140 = 0x00010001;
u32 var8007f144 = 0x02010001;
u32 var8007f148 = 0x00000000;
u32 var8007f14c = 0x00000064;
u32 var8007f150 = 0x00000064;
u32 var8007f154 = 0x00000000;
u32 var8007f158 = 0x00003d84;
u32 var8007f15c = 0x00003d84;
u32 var8007f160 = 0x00000000;
u32 var8007f164 = 0x0036003d;
u32 var8007f168 = 0x0036003d;
u32 var8007f16c = 0x00000000;
u32 var8007f170 = 0x3f800000;
u32 var8007f174 = 0x00010001;
u32 var8007f178 = 0x02010001;
u32 var8007f17c = 0x00000000;
u32 var8007f180 = 0x00000037;
u32 var8007f184 = 0x000079a2;
u32 var8007f188 = 0x0036003d;
u32 var8007f18c = 0x000079a2;
u32 var8007f190 = 0x0036003d;
u32 var8007f194 = 0x00000037;
u32 var8007f198 = 0x0036003d;
u32 var8007f19c = 0x00000037;
u32 var8007f1a0 = 0x000079a2;
u32 var8007f1a4 = 0x3e4ccccd;
u32 var8007f1a8 = 0x00010001;
u32 var8007f1ac = 0x02010001;
u32 var8007f1b0 = 0x00000000;
u32 var8007f1b4 = 0x0036003d;
u32 var8007f1b8 = 0x0051003f;
u32 var8007f1bc = 0x00000037;
u32 var8007f1c0 = 0x0051003f;
u32 var8007f1c4 = 0x00000037;
u32 var8007f1c8 = 0x0036003d;
u32 var8007f1cc = 0x000000a6;
u32 var8007f1d0 = 0x0036003d;
u32 var8007f1d4 = 0x0051003f;
u32 var8007f1d8 = 0x3e4ccccd;
u32 var8007f1dc = 0x00010001;
u32 var8007f1e0 = 0x02010001;
u32 var8007f1e4 = 0x00000000;
u32 var8007f1e8 = 0x00003d84;
u32 var8007f1ec = 0x00003d84;
u32 var8007f1f0 = 0x00000064;
u32 var8007f1f4 = 0x00000064;
u32 var8007f1f8 = 0x00003d84;
u32 var8007f1fc = 0x00003d84;
u32 var8007f200 = 0x0036003d;
u32 var8007f204 = 0x00003d84;
u32 var8007f208 = 0x0036003d;
u32 var8007f20c = 0x3e4ccccd;
u32 var8007f210 = 0x00010001;
u32 var8007f214 = 0x02010001;
u32 var8007f218 = 0x00000000;
u32 var8007f21c = 0x00004345;
u32 var8007f220 = 0x00004345;
u32 var8007f224 = 0x0051003f;
u32 var8007f228 = 0x00000037;
u32 var8007f22c = 0x00000037;
u32 var8007f230 = 0x00004345;
u32 var8007f234 = 0x000079a2;
u32 var8007f238 = 0x00004345;
u32 var8007f23c = 0x000079a2;
u32 var8007f240 = 0x3e4ccccd;
u32 var8007f244 = 0x00010001;
u32 var8007f248 = 0x02010001;
u32 var8007f24c = 0x00000000;
u32 var8007f250 = 0x000000a6;
u32 var8007f254 = 0x000000a6;
u32 var8007f258 = 0x00000000;
u32 var8007f25c = 0x000000a6;
u32 var8007f260 = 0x000000a6;
u32 var8007f264 = 0x00000000;
u32 var8007f268 = 0x000000a6;
u32 var8007f26c = 0x000000a6;
u32 var8007f270 = 0x00000000;
u32 var8007f274 = 0x3c23d70a;
u32 var8007f278 = 0x00010001;
u32 var8007f27c = 0x02010001;
u32 var8007f280 = 0x00000000;
u32 var8007f284 = 0x0000ffff;
u32 var8007f288 = 0x000000ff;
u32 var8007f28c = 0x00000000;
u32 var8007f290 = 0x0000ffff;
u32 var8007f294 = 0x000000ff;
u32 var8007f298 = 0x00000000;
u32 var8007f29c = 0x0000ffff;
u32 var8007f2a0 = 0x000000ff;
u32 var8007f2a4 = 0x00000000;
u32 var8007f2a8 = 0x3c23d70a;
u32 var8007f2ac = 0x02010201;
u32 var8007f2b0 = 0x00010201;
u32 var8007f2b4 = 0x02000000;
u32 var8007f2b8 = 0x0000ffff;
u32 var8007f2bc = 0x000000ff;
u32 var8007f2c0 = 0x00000000;
u32 var8007f2c4 = 0x00ffffff;
u32 var8007f2c8 = 0x00ffffff;
u32 var8007f2cc = 0x00ffffff;
u32 var8007f2d0 = 0x00ffffff;
u32 var8007f2d4 = 0x00ffffff;
u32 var8007f2d8 = 0x00ffffff;
u32 var8007f2dc = 0x27102710;
u32 var8007f2e0 = 0xff380000;
u32 var8007f2e4 = 0x00000004;
u32 var8007f2e8 = 0x42f00000;
u32 var8007f2ec = 0x00000000;
u32 var8007f2f0 = 0x03e803e8;
u32 var8007f2f4 = 0xff380000;
u32 var8007f2f8 = 0x00000005;
u32 var8007f2fc = 0x435c0000;
u32 var8007f300 = 0x00000000;
u32 var8007f304 = 0x03e82710;
u32 var8007f308 = 0xffce0000;
u32 var8007f30c = 0x00000006;
u32 var8007f310 = 0x435c0000;
u32 var8007f314 = 0x00000000;
u32 var8007f318 = 0x03e82710;
u32 var8007f31c = 0xff380000;
u32 var8007f320 = 0x00000026;
u32 var8007f324 = 0x435c0000;
u32 var8007f328 = 0x00000000;
u32 var8007f32c = 0x01f42710;
u32 var8007f330 = 0xff380000;
u32 var8007f334 = 0x00000026;
u32 var8007f338 = 0x44020000;
u32 var8007f33c = 0x00000000;
u32 var8007f340 = 0x03e84e20;
u32 var8007f344 = 0xffce0000;
u32 var8007f348 = 0x00000026;
u32 var8007f34c = 0x42f00000;
u32 var8007f350 = 0x00000000;
u32 var8007f354 = 0x27102710;
u32 var8007f358 = 0xff380000;
u32 var8007f35c = 0x0000002a;
u32 var8007f360 = 0x42f00000;
u32 var8007f364 = 0x00000000;
u32 var8007f368 = 0x27102710;
u32 var8007f36c = 0xff380000;
u32 var8007f370 = 0x0000002b;
u32 var8007f374 = 0x42a00000;
u32 var8007f378 = 0x00000000;
u32 var8007f37c = 0x27100bb8;
u32 var8007f380 = 0xff380000;
u32 var8007f384 = 0x0000002b;
u32 var8007f388 = 0x42a00000;
u32 var8007f38c = 0x00000000;
u32 var8007f390 = 0x0bb80bb8;
u32 var8007f394 = 0xff380000;
u32 var8007f398 = 0x0000002d;
u32 var8007f39c = 0x42f00000;
u32 var8007f3a0 = 0x00000000;
u32 var8007f3a4 = 0x27102710;
u32 var8007f3a8 = 0xff380000;
u32 var8007f3ac = 0x00000007;
u32 var8007f3b0 = 0x42a00000;
u32 var8007f3b4 = 0x00000000;
u32 var8007f3b8 = 0x271003e8;
u32 var8007f3bc = 0xff380000;
u32 var8007f3c0 = 0x0000002d;
u32 var8007f3c4 = 0x435c0000;
u32 var8007f3c8 = 0x00000000;
u32 var8007f3cc = 0xffffffff;
u32 var8007f3d0 = 0xffffffff;
u32 var8007f3d4 = 0xffffffff;
u32 var8007f3d8 = 0xffffffff;
u32 var8007f3dc = 0x00000000;
u32 var8007f3e0 = 0x00000000;
u32 var8007f3e4 = 0x00000000;
u32 var8007f3e8 = 0x00000001;
u32 var8007f3ec = 0x00000000;
u32 var8007f3f0 = 0x00000000;
u32 var8007f3f4 = 0x010301f4;
u32 var8007f3f8 = 0x008888ff;
u32 var8007f3fc = 0x00ff88ff;
u32 var8007f400 = 0x00ff8888;
u32 var8007f404 = 0x006666ff;
u32 var8007f408 = 0x41f00000;
u32 var8007f40c = 0x41f00000;
u32 var8007f410 = 0x0000ffff;
u32 var8007f414 = 0x0044ffff;
u32 var8007f418 = 0x0088ffff;
u32 var8007f41c = 0x00ffffff;
u32 var8007f420 = 0x8888ff7f;
u32 var8007f424 = 0xff88ff7f;
u32 var8007f428 = 0xff88887f;
u32 var8007f42c = 0x6666ff7f;
u32 var8007f430 = 0xff00007f;
u32 var8007f434 = 0xffffff7f;
u32 var8007f438 = 0xff00004f;
u32 var8007f43c = 0xffffff4f;
u32 var8007f440 = 0xffffff7f;
u32 var8007f444 = 0xffffff5f;
u32 var8007f448 = 0xffffff3f;
u32 var8007f44c = 0xffffff1f;
u32 var8007f450 = 0x0000002a;
u32 var8007f454 = 0x00000000;
u32 var8007f458 = 0x00200020;
u32 var8007f45c = 0x0000002b;
u32 var8007f460 = 0x00000000;
u32 var8007f464 = 0x00200020;
u32 var8007f468 = 0x00000025;
u32 var8007f46c = 0x00000000;

// 25490
struct credit credits[] = {
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(2), L_TITLE(0) }, // "perfect dark", ""
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(3), L_TITLE(4) }, // "beau ner chesluk", "guns and visual orgasms"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(5), L_TITLE(6) }, // "jonathan nasty mummery", "mover and shaker"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(7), L_TITLE(8) }, // "darkmark", "reality engineer"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(9), L_TITLE(10) }, // "chris tilston", "designs on the future"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(11), L_TITLE(12) }, // "chris darling", "weapons specialist"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(13), L_TITLE(14) }, // "duncan botwood", "grey area"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(15), L_TITLE(16) }, // "b jones", "bodybuilder"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(17), L_TITLE(18) }, // "steve malpass", "perfect locations and vox"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(19), L_TITLE(20) }, // "brian marshall", "-aqham-"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(21), L_TITLE(22) }, // "russel irwin", "well packed man"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(23), L_TITLE(24) }, // "jamie 'evo' williams", "manic welsh designer"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(25), L_TITLE(26) }, // "ross bury", "bionic backgrounds"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(27), L_TITLE(28) }, // "martin penny", "sound geezer"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(29), L_TITLE(30) }, // "grant kirkhope", "play that music maestro"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(31), L_TITLE(32) }, // "david clynick", "bangin hardcore choonz"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(33), L_TITLE(34) }, // "keith 'bunny' rabbette", "dinomic backgrounds"
	{ 0xa0, CREDITSTYLE_C_BIG,       L_TITLE(35), L_TITLE(0) }, // "dd snipers", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(36), L_TITLE(37) }, // "kevin bayliss", "dean smith"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(38), L_TITLE(1) }, // "graham smith", "\n"
	{ 0xe0, CREDITSTYLE_C_BIG,       L_TITLE(35), L_TITLE(0) }, // "dd snipers", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(39), L_TITLE(40) }, // "mike 'curry' currington", "tony wong"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(41), L_TITLE(1) }, // "simon farmer", "\n"
	{ 0xc0, CREDITSTYLE_C_BIG,       L_TITLE(35), L_TITLE(0) }, // "dd snipers", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(42), L_TITLE(43) }, // "leigh loverday", "rob harrison"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(44), L_TITLE(1) }, // "steven hurst", "\n"
	{ 0x80, CREDITSTYLE_C_BIG,       L_TITLE(45), L_TITLE(0) }, // "fearsome foursome", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(46), L_TITLE(47) }, // "phil dunne", "ricky berwick"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(48), L_TITLE(49) }, // "gareth glover", "jonathan ambrose"
	{ 0xa0, CREDITSTYLE_C_BIG,       L_TITLE(50), L_TITLE(0) }, // "trent's henchmen", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(51), L_TITLE(52) }, // "lee musgrave", "johnni christensen"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(53), L_TITLE(1) }, // "mark betteridge", "\n"
	{ 0xc0, CREDITSTYLE_C_BIG,       L_TITLE(50), L_TITLE(0) }, // "trent's henchmen", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(54), L_TITLE(55) }, // "chris marlow", "robin beanland"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(56), L_TITLE(57) }, // "neil gallagher", "feargal plant"
	{ 0xa0, CREDITSTYLE_C_BIG,       L_TITLE(58), L_TITLE(0) }, // "voices in the dark", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(59), L_TITLE(60) }, // "eveline fischer", "chris sutherland"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(61), L_TITLE(62) }, // "chris seavor", "john silke"
	{ 0xe0, CREDITSTYLE_C_BIG,       L_TITLE(58), L_TITLE(0) }, // "voices in the dark", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(63), L_TITLE(64) }, // "ben cullum", "louise tilston"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(65), L_TITLE(66) }, // "alistair", "lindsay"
	{ 0xc0, CREDITSTYLE_C_BIG,       L_TITLE(58), L_TITLE(0) }, // "voices in the dark", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(68), L_TITLE(67) }, // "beau chesluk", "b jones"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(69), L_TITLE(1) }, // "steve malpass", "\n"
	{ 0xa0, CREDITSTYLE_L_BIG,       L_TITLE(93), L_TITLE(0) }, // "rare exterminators", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(94), L_TITLE(95) }, // "huw ward", "adam munton"
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(96), L_TITLE(97) }, // "david wong", "luke munton"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(98), L_TITLE(109) }, // "gary phelps", "andrew wilson"
	{ 0xe0, CREDITSTYLE_L_BIG,       L_TITLE(93), L_TITLE(0) }, // "rare exterminators", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(99), L_TITLE(100) }, // "john silke", "matthew carter"
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(101), L_TITLE(102) }, // "gavin price", "gareth stevenson"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(103), L_TITLE(1) }, // "bushbaby", "\n"
	{ 0xc0, CREDITSTYLE_L_BIG,       L_TITLE(93), L_TITLE(0) }, // "rare exterminators", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(104), L_TITLE(105) }, // "stephen stamper", "ross bullimore"
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(106), L_TITLE(107) }, // "justin cook", "dale murchie"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(108), L_TITLE(1) }, // "roger smith", "\n"
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(70), L_TITLE(0) }, // "ci techs", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(71), L_TITLE(72) }, // "richard 'force 9' gale", "mark green"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(73), L_TITLE(74) }, // "alex zoro", "mark wilson"
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(75), L_TITLE(0) }, // "hard and wary support", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(76), L_TITLE(77) }, // "pete 'hardrom' cox", "maul 'max' mikell"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(78), L_TITLE(0) }, // "doug crouch", ""
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(83), L_TITLE(0) }, // "motion capture", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(84), L_TITLE(85) }, // "alan tippertronic", "des easen"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(86), L_TITLE(0) }, // "jim 'love' ballard", ""
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(87), L_TITLE(0) }, // "going through the motions", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(88), L_TITLE(89) }, // "duncan 'bot' botwood", "michelle tipper"
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(90), L_TITLE(91) }, // "sue 'falling' fell", "doug 'crouch' crouch"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(92), L_TITLE(0) }, // "ross bury", ""
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(118), L_TITLE(0) }, // "testing (rare miami)", ""
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(119), L_TITLE(0) }, // "keith coll", ""
	{ 0x80, CREDITSTYLE_C_BIG,       L_TITLE(113), L_TITLE(0) }, // "rare in the sun", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(114), L_TITLE(115) }, // "joel hochberg", ""
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(116), L_TITLE(117) }, // "scott hochberg", ""
	{ 0x80, CREDITSTYLE_C_BIG,       L_TITLE(110), L_TITLE(0) }, // "dark commanders", ""
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(111), L_TITLE(112) }, // "bis", "wombat"
	{ 0xa0, CREDITSTYLE_L_BIG,       L_TITLE(120), L_TITLE(0) }, // "testing (noa)", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(121), L_TITLE(122) }, // "michael kelbaugh", "tim bechtel"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(123), L_TITLE(124) }, // "tom hertzog", "melvin 'sherwood' forrest"
	{ 0xc0, CREDITSTYLE_L_BIG,       L_TITLE(120), L_TITLE(0) }, // "testing (noa)", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(125), L_TITLE(126) }, // "dougall campbell", "roger harrison"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(127), L_TITLE(1) }, // "jeff kalles", "\n"
	{ 0x00, CREDITSTYLE_R_BIG_R_MED, L_TITLE(128), L_TITLE(129) }, // "the perfect core", "-darker than you"
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(130), L_TITLE(0) }, // "treehouse", ""
	{ 0x80, CREDITSTYLE_R_MED,       L_TITLE(131), L_TITLE(132) }, // "armond williams junior", "henry sterchi"
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(133), L_TITLE(0) }, // "ed ridgeway", ""
	{ 0x80, CREDITSTYLE_L_BIG,       L_TITLE(134), L_TITLE(0) }, // "perfect spelling", ""
	{ 0x00, CREDITSTYLE_R_MED,       L_TITLE(135), L_TITLE(0) }, // "teresa lillygren", ""
	{ 0xa0, CREDITSTYLE_C_BIG,       L_TITLE(136), L_TITLE(0) }, // "nintendo", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(137), L_TITLE(138) }, // "mr arakawa", ""
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(139), L_TITLE(140) }, // "don james", ""
	{ 0xc0, CREDITSTYLE_C_BIG,       L_TITLE(136), L_TITLE(0) }, // "nintendo", ""
	{ 0x80, CREDITSTYLE_C_MED,       L_TITLE(141), L_TITLE(142) }, // "howard lincoln", "ken lobb"
	{ 0x00, CREDITSTYLE_C_MED,       L_TITLE(143), L_TITLE(144) }, // "jacqualee story", "gail"
	{ 0x88, CREDITSTYLE_C_BIG_C_BIG, L_TITLE(148), L_TITLE(149) }, // "rare", "designs on the future"
	{ 0x80, CREDITSTYLE_C_SML,       L_TITLE(1), L_TITLE(145) }, // "\n", "copyright rare 2000"
	{ 0x00, CREDITSTYLE_C_SML,       L_TITLE(146), L_TITLE(147) }, // "perfect dark and the pd device", "are trademarks"
	{ 0x00, CREDITSTYLE_C_SML,       L_TITLE(150), L_TITLE(0) }, // "perfect dark is forever", ""
	{ 0x00, CREDITSTYLE_TERMINATOR,  L_TITLE(0), L_TITLE(0) }, // "", ""
};

u32 var8007f6c4 = 0x40800000;
u32 var8007f6c8 = 0x41000000;
u32 var8007f6cc = 0x41400000;
u32 var8007f6d0 = 0x41800000;
u32 var8007f6d4 = 0x00000000;
u32 var8007f6d8 = 0x0000ffff;
u32 var8007f6dc = 0x00000000;
u32 var8007f6e0 = 0xffffffff;
u32 var8007f6e4 = 0xffffffff;
u32 var8007f6e8 = 0x00000000;
u32 var8007f6ec = 0x00000000;
u32 var8007f6f0 = 0x00000000;
u32 var8007f6f4 = 0x00000000;
u32 var8007f6f8 = 0x00000000;
u32 var8007f6fc = 0x00000041;
u32 var8007f700 = 0x00000016;
u32 var8007f704 = 0x0000001d;
u32 var8007f708 = 0x0000004a;
u32 var8007f70c = 0x00000006;
u32 var8007f710 = 0x00000006;
u32 var8007f714 = 0x00000038;
u32 var8007f718 = 0x000003d5;
u32 var8007f71c = 0x00000018;
u32 var8007f720 = 0x00000018;
u32 var8007f724 = 0x00000034;
u32 var8007f728 = 0x000002f7;
u32 var8007f72c = 0x00000012;
u32 var8007f730 = 0x00000012;
u32 var8007f734 = 0x00000000;
u32 var8007f738 = 0x00000000;
u32 var8007f73c = 0x00000000;
u32 var8007f740 = 0x00000000;
u32 var8007f744 = 0x400a0a00;
u32 var8007f748 = 0x3f800000;
u32 var8007f74c = 0x3f800000;
u32 var8007f750 = 0x00000000;
u32 var8007f754 = 0x00000000;
u32 var8007f758 = 0x00000000;
u32 var8007f75c = 0x41200000;
u32 var8007f760 = 0x41200000;
u32 var8007f764 = 0x01000000;
u32 var8007f768 = 0x40c00000;
u32 var8007f76c = 0x40c00000;
u32 var8007f770 = 0x01000000;
u32 var8007f774 = 0x41000000;
u32 var8007f778 = 0x41000000;
u32 var8007f77c = 0x00000000;
u32 var8007f780 = 0x40c00000;
u32 var8007f784 = 0x40c00000;
u32 var8007f788 = 0x01000000;
u32 var8007f78c = 0x41000000;
u32 var8007f790 = 0x41000000;
u32 var8007f794 = 0x01000000;
u32 var8007f798 = 0x41400000;
u32 var8007f79c = 0x41400000;
u32 var8007f7a0 = 0x01000000;
u32 var8007f7a4 = 0x40c00000;
u32 var8007f7a8 = 0x40c00000;
u32 var8007f7ac = 0x01000000;
u32 var8007f7b0 = 0x42c80000;
u32 var8007f7b4 = 0x42c80000;
u32 var8007f7b8 = 0x02000000;
u32 var8007f7bc = 0x41c00000;
u32 var8007f7c0 = 0x41c00000;
u32 var8007f7c4 = 0x04000000;
u32 var8007f7c8 = 0x41a00000;
u32 var8007f7cc = 0x41a00000;
u32 var8007f7d0 = 0x03000000;
u32 var8007f7d4 = 0x41a00000;
u32 var8007f7d8 = 0x41a00000;
u32 var8007f7dc = 0x03000000;
u32 var8007f7e0 = 0x41a00000;
u32 var8007f7e4 = 0x41a00000;
u32 var8007f7e8 = 0x03000000;
u32 var8007f7ec = 0x41a00000;
u32 var8007f7f0 = 0x41a00000;
u32 var8007f7f4 = 0x03000000;
u32 var8007f7f8 = 0x40c00000;
u32 var8007f7fc = 0x40c00000;
u32 var8007f800 = 0x01000000;
u32 var8007f804 = 0x41000000;
u32 var8007f808 = 0x41000000;
u32 var8007f80c = 0x01000000;
u32 var8007f810 = 0x41400000;
u32 var8007f814 = 0x41400000;
u32 var8007f818 = 0x01000000;
u32 var8007f81c = 0x40800000;
u32 var8007f820 = 0x40800000;
u32 var8007f824 = 0x01000000;
u32 var8007f828 = 0x40c00000;
u32 var8007f82c = 0x40c00000;
u32 var8007f830 = 0x01000000;
u32 var8007f834 = 0x00000000;
u32 var8007f838 = 0x00000000;
u32 var8007f83c = 0x00000000;
u32 var8007f840 = 0x00000000;
u32 var8007f844 = 0x00000000;
u32 var8007f848 = 0x00000000;
u32 var8007f84c = 0x0000005a;
u32 var8007f850 = 0x00000003;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;
u32 var8007f860 = 0xffffffff;
u32 var8007f864 = 0x7f7f7fff;
u32 var8007f868 = 0xffffffff;
u32 var8007f86c = 0x7f7f7fff;
u32 var8007f870 = 0x000003e8;
u32 var8007f874 = 0x000003e8;
u32 var8007f878 = 0x00000000;
u32 var8007f87c = 0x6e00006e;
u32 var8007f880 = 0x65006500;
u32 var8007f884 = 0x00736500;
u32 var8007f888 = 0x73000073;
u32 var8007f88c = 0x77007700;
u32 var8007f890 = 0x006e7700;
u32 var8007f894 = 0x6e000000;
u32 var8007f898 = 0x00000000;
u32 var8007f89c = 0x00000000;
u32 var8007f8a0 = 0x3e19999a;
u32 var8007f8a4 = 0x40400000;
u32 var8007f8a8 = 0x41400000;
u32 var8007f8ac = 0x00000008;
u32 var8007f8b0 = 0x43340000;
u32 var8007f8b4 = 0x40a00000;
u32 var8007f8b8 = 0x42480000;
u32 var8007f8bc = 0x00000000;
u32 var8007f8c0 = (u32)&var7f1b6050;
u32 var8007f8c4 = (u32)&var7f1b6058;
u32 var8007f8c8 = (u32)&var7f1b606c;
u32 var8007f8cc = (u32)&var7f1b6080;
u32 var8007f8d0 = (u32)&var7f1b6088;
u32 var8007f8d4 = (u32)&var7f1b6090;
u32 var8007f8d8 = (u32)&var7f1b6098;
u32 var8007f8dc = 0x00000000;
u32 var8007f8e0 = 0x00000000;
u32 var8007f8e4 = 0x00000000;
u32 var8007f8e8 = 0x00000008;
u32 var8007f8ec = 0x0000005a;
u32 var8007f8f0 = 0x00000005;
u32 var8007f8f4 = 0x000000c8;
u32 var8007f8f8 = 0x00000000;
u32 var8007f8fc = 0x00000001;
u32 var8007f900 = 0x00000078;
u32 var8007f904 = 0x02000233;
u32 var8007f908 = 0x024e026b;
u32 var8007f90c = 0x028902a9;
u32 var8007f910 = 0x02ca02ed;
u32 var8007f914 = 0x03120338;
u32 var8007f918 = 0x0360038b;
u32 var8007f91c = 0x03b703e5;
u32 var8007f920 = 0x04160449;
u32 var8007f924 = 0x047f04b7;
u32 var8007f928 = 0x04f20530;
u32 var8007f92c = 0x057005b4;
u32 var8007f930 = 0x05fc0646;
u32 var8007f934 = 0x069506e7;
u32 var8007f938 = 0x073d0798;
u32 var8007f93c = 0x07f7085a;
u32 var8007f940 = 0x08c30930;
u32 var8007f944 = 0x09a30a1b;
u32 var8007f948 = 0x0a9a0b1e;
u32 var8007f94c = 0x0ba90c3b;
u32 var8007f950 = 0x0cd40d74;
u32 var8007f954 = 0x0e1c0ecc;
u32 var8007f958 = 0x0f851047;
u32 var8007f95c = 0x111311e8;
u32 var8007f960 = 0x12c813b3;
u32 var8007f964 = 0x14a915ab;
u32 var8007f968 = 0x16ba17d6;
u32 var8007f96c = 0x18ff1a38;
u32 var8007f970 = 0x1b7f1cd7;
u32 var8007f974 = 0x1e3f1fb9;
u32 var8007f978 = 0x214622e6;
u32 var8007f97c = 0x249a2663;
u32 var8007f980 = 0x28432a3a;
u32 var8007f984 = 0x2c492e73;
u32 var8007f988 = 0x30b73318;
u32 var8007f98c = 0x35963834;
u32 var8007f990 = 0x3af23dd3;
u32 var8007f994 = 0x40d74402;
u32 var8007f998 = 0x47534acf;
u32 var8007f99c = 0x4e75524a;
u32 var8007f9a0 = 0x564e5a84;
u32 var8007f9a4 = 0x5eef6392;
u32 var8007f9a8 = 0x686e6d87;
u32 var8007f9ac = 0x72df787a;
u32 var8007f9b0 = 0x7e5c8487;
u32 var8007f9b4 = 0x8aff91c7;
u32 var8007f9b8 = 0x98e5a05b;
u32 var8007f9bc = 0xa82fb065;
u32 var8007f9c0 = 0xb901c208;
u32 var8007f9c4 = 0xcb81d570;
u32 var8007f9c8 = 0xdfdbeac8;
u32 var8007f9cc = 0xf63dffff;
u32 var8007f9d0 = 0x00000000;
u32 var8007f9d4 = 0x00000000;
u32 var8007f9d8 = 0x3f800000;
u32 var8007f9dc = 0x3f800000;
u32 var8007f9e0 = 0x3f800000;
u32 var8007f9e4 = 0x3f800000;
u32 var8007f9e8 = 0x3f800000;
u32 var8007f9ec = 0x3f800000;
u32 var8007f9f0 = 0x3f800000;
u32 var8007f9f4 = 0x3f800000;
u32 var8007f9f8 = 0x3f800000;
u32 var8007f9fc = 0x3b42938e;
u32 var8007fa00 = 0x3c5a0169;
u32 var8007fa04 = 0x3cb3b752;
u32 var8007fa08 = 0x3c5a0169;
u32 var8007fa0c = 0x3b42938e;
u32 var8007fa10 = 0x3c5a0169;
u32 var8007fa14 = 0x3d7442c8;
u32 var8007fa18 = 0x3dc95bff;
u32 var8007fa1c = 0x3d7442c8;
u32 var8007fa20 = 0x3c5a0169;
u32 var8007fa24 = 0x3cb3b752;
u32 var8007fa28 = 0x3dc95bff;
u32 var8007fa2c = 0x3e25fe54;
u32 var8007fa30 = 0x3dc95bff;
u32 var8007fa34 = 0x3cb3b752;
u32 var8007fa38 = 0x3c5a0169;
u32 var8007fa3c = 0x3d7442c8;
u32 var8007fa40 = 0x3dc95bff;
u32 var8007fa44 = 0x3d7442c8;
u32 var8007fa48 = 0x3c5a0169;
u32 var8007fa4c = 0x3b42938e;
u32 var8007fa50 = 0x3c5a0169;
u32 var8007fa54 = 0x3cb3b752;
u32 var8007fa58 = 0x3c5a0169;
u32 var8007fa5c = 0x3b42938e;
u32 var8007fa60 = 0x3f800000;
u32 var8007fa64 = 0x3f800000;
u32 var8007fa68 = 0x3f800000;
u32 var8007fa6c = 0x3f800000;
u32 var8007fa70 = 0x3f800000;
u32 var8007fa74 = 0x3f800000;
u32 var8007fa78 = 0x3f800000;
u32 var8007fa7c = 0x00000000;
u32 var8007fa80 = 0x00000000;
u32 var8007fa84 = 0x00000000;
u32 var8007fa88 = 0x00000000;
u32 var8007fa8c = 0x00000000;
u8 g_InGameSubtitles = 1;
u8 g_CutsceneSubtitles = 0;
u32 var8007fa98 = 0x00000000;
u32 var8007fa9c = 0x00000001;
u32 var8007faa0 = 0x00000000;
u32 var8007faa4 = 0x00000001;
u32 var8007faa8 = 0x00000001;
u32 var8007faac = 0x00000001;
s32 g_ScreenSize = SCREENSIZE_FULL;
s32 g_ScreenRatio = SCREENRATIO_NORMAL;
u8 g_ScreenSplit = SCREENSPLIT_HORIZONTAL;
u32 var8007fabc = 0x00000000;
s32 var8007fac0 = 0x00000001;
u32 var8007fac4 = 0x00000000;
u32 var8007fac8 = 0x00000000;
u32 var8007facc = 0x00000000;
u32 var8007fad0 = 0x00000001;
u32 var8007fad4 = 0xffffffff;
u32 var8007fad8 = 0x00000000;
u32 var8007fadc = 0x00000000;
u32 var8007fae0 = 0x00000000;
u32 var8007fae4 = 0x00000000;
u32 var8007fae8 = 0x00000000;
u32 var8007faec = 0x00000000;
u32 var8007faf0 = 0x00000000;
u32 var8007faf4 = 0x00000000;
u32 var8007faf8 = 0x00000000;
u32 var8007fafc = 0x00000000;
u32 var8007fb00 = 0x00000000;
u32 var8007fb04 = 0x00000000;
u32 var8007fb08 = 0x00000000;
u32 var8007fb0c = 0x00000000;
u32 var8007fb10 = 0x00000000;
u32 var8007fb14 = 0x00000000;
u32 var8007fb18 = 0x00000000;
u32 var8007fb1c = 0x00000000;
u32 var8007fb20 = 0x00000000;
u32 var8007fb24 = 0x00000000;
u32 var8007fb28 = 0x00000000;
u32 var8007fb2c = 0x00000000;
u32 var8007fb30 = 0x00000000;
u32 var8007fb34 = 0x00000000;
u32 var8007fb38 = 0x00000000;
u32 var8007fb3c = 0xff00ff00;
u32 var8007fb40 = 0xff00ff00;
u32 var8007fb44 = 0xff00ff00;
u32 var8007fb48 = 0xff00ff00;
u32 var8007fb4c = 0xff00ff24;
u32 var8007fb50 = 0xff48ff6c;
u32 var8007fb54 = 0xff90ffb4;
u32 var8007fb58 = 0xffd8ffff;
u32 var8007fb5c = 0xff00ff58;
u32 var8007fb60 = 0xff74ff90;
u32 var8007fb64 = 0xffacffc8;
u32 var8007fb68 = 0xffe4ffff;
u32 var8007fb6c = 0xffffffff;
u32 var8007fb70 = 0xffffffff;
u32 var8007fb74 = 0xffffffff;
u32 var8007fb78 = 0xffffffff;
u32 var8007fb7c = 0xff00ff00;
u32 var8007fb80 = 0xff00ff00;
u32 var8007fb84 = 0xff00ff00;
u32 var8007fb88 = 0xff00ff00;
u32 var8007fb8c = 0xff00ff18;
u32 var8007fb90 = 0xff30ff5c;
u32 var8007fb94 = 0xff88ffb4;
u32 var8007fb98 = 0xffd8ffff;
u32 var8007fb9c = 0x00000000;
u32 var8007fba0 = 0x00000000;
u32 var8007fba4 = 0xffffffff;
u32 var8007fba8 = 0x00000000;
u32 var8007fbac = 0x00000001;
u32 var8007fbb0 = 0x00000064;
u32 var8007fbb4 = 0x0000002c;
u32 var8007fbb8 = 0x00000080;
u32 var8007fbbc = 0x0000003c;
u32 var8007fbc0 = 0x44444400;
u32 var8007fbc4 = 0xffffff00;
u32 var8007fbc8 = 0xffffff00;
u32 var8007fbcc = 0x00000c0b;
u32 var8007fbd0 = 0x00000000;
u32 var8007fbd4 = 0x00000000;
u32 var8007fbd8 = 0x00000000;
u32 var8007fbdc = 0x00000c0b;
u32 var8007fbe0 = 0x00000000;
u32 var8007fbe4 = 0x00000000;
u32 var8007fbe8 = 0x00000000;
u32 var8007fbec = 0x00000c0b;
u32 var8007fbf0 = 0x00000000;
u32 var8007fbf4 = 0x00000000;
u32 var8007fbf8 = 0x00000000;
u32 var8007fbfc = 0x00000000;
u32 g_StageIndex = 0x00000001;
u32 var8007fc04 = 0x00000000;
u32 var8007fc08 = 0x00000000;
u32 var8007fc0c = 0x00000000;
u32 var8007fc10 = 0x00000000;
u32 var8007fc14 = 0x00000000;
u32 var8007fc18 = 0x01000100;
u32 var8007fc1c = 0x00000000;
s32 var8007fc20 = 0x00000001;
u32 var8007fc24 = 0x800a4910;
u32 var8007fc28 = 0x00000000;
u32 var8007fc2c = 0x00000000;
s32 var8007fc30 = 0x00000000;
s32 var8007fc34 = 0x00000000;
u32 var8007fc38 = 0x00000000;
u16 var8007fc3c = 0xfffe;
s32 g_NumPortalThings = 0;
u32 var8007fc44 = 0xffffffff;
u32 var8007fc48 = 0xffff0000;
u32 var8007fc4c = 0x00000000;
u32 var8007fc50 = 0x00000000;
u32 var8007fc54 = 0x00000000;
bool g_PortalStack[20] = {0};
s32 g_PortalStackIndex = 0x00000000;
u32 g_PortalMode = 0x00000000;
u32 var8007fcb0 = 0x00000190;
u32 var8007fcb4 = 0x00000000;
u32 var8007fcb8 = 0x00000000;
u32 var8007fcbc = 0x00000000;

// 25ce0
// When adding or removing items from this table you must also update the
// STAGEINDEX constants in constants.h.
struct stagetableentry g_Stages[] = {
	//       id,                  ?, lia, liw, lih, ?, bg,               tiles,              pads,              setup,           mpsetp,             ?                0x18,            0x1c, ?, ?,  ?, 0x24,      0x28,   ?,   ?,   ?  ?
	/*0x00*/ STAGE_MAIANSOS,      2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_SEV_PADS,  FILE_USETUPSEV,  FILE_UMP_SETUPSEV,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x01*/ STAGE_TEST_SILO,     2, 255, 100, 100, 0, FILE_BG_OAT_SEG,  FILE_BG_OAT_TILES,  FILE_BG_OAT_PADS,  FILE_USETUPSILO, FILE_UMP_SETUPSILO, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x02*/ STAGE_WAR,           2, 255, 100, 100, 0, FILE_BG_SHO_SEG,  FILE_BG_SHO_TILES,  FILE_BG_STAT_PADS, FILE_USETUPSTAT, FILE_UMP_SETUPSTAT, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x03*/ STAGE_MP_RAVINE,     2, 255, 100, 100, 0, FILE_BG_AREC_SEG, FILE_BG_AREC_TILES, FILE_BG_AREC_PADS, FILE_USETUPAREC, FILE_UMP_SETUPAREC, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x04*/ STAGE_TEST_ARCH,     2, 255, 100, 100, 0, FILE_BG_ARCH_SEG, FILE_BG_ARCH_TILES, FILE_BG_ARCH_PADS, FILE_USETUPARCH, FILE_UMP_SETUPARCH, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x05*/ STAGE_ESCAPE,        2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_TRA_PADS,  FILE_USETUPTRA,  FILE_UMP_SETUPTRA,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x06*/ STAGE_TEST_DEST,     2, 255, 100, 100, 0, FILE_BG_DEST_SEG, FILE_BG_DEST_TILES, FILE_BG_DEST_PADS, FILE_USETUPDEST, FILE_UMP_SETUPDEST, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x07*/ STAGE_RETAKING,      2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_SEVB_PADS, FILE_USETUPSEVB, FILE_UMP_SETUPSEVB, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x08*/ STAGE_CRASHSITE,     2, 255, 100, 100, 0, FILE_BG_AZT_SEG,  FILE_BG_AZT_TILES,  FILE_BG_AZT_PADS,  FILE_USETUPAZT,  FILE_UMP_SETUPAZT,  1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x09*/ STAGE_CHICAGO,       2, 255, 100, 100, 0, FILE_BG_PETE_SEG, FILE_BG_PETE_TILES, FILE_BG_PETE_PADS, FILE_USETUPPETE, FILE_UMP_SETUPPETE, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0a*/ STAGE_G5BUILDING,    2, 255, 100, 100, 0, FILE_BG_DEPO_SEG, FILE_BG_DEPO_TILES, FILE_BG_DEPO_PADS, FILE_USETUPDEPO, FILE_UMP_SETUPDEPO, 1,                1,   100,             0, 0, 20, 220, 0x3e19999a, -1,  400, 0,   1,
	/*0x0b*/ STAGE_MP_COMPLEX,    2, 255, 100, 100, 0, FILE_BG_REF_SEG,  FILE_BG_REF_TILES,  FILE_BG_REF_PADS,  FILE_USETUPREF,  FILE_UMP_SETUPREF,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0c*/ STAGE_MP_G5BUILDING, 2, 255, 100, 100, 0, FILE_BG_CRYP_SEG, FILE_BG_CRYP_TILES, FILE_BG_CRYP_PADS, FILE_USETUPCRYP, FILE_UMP_SETUPCRYP, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x0d*/ STAGE_PELAGIC,       2, 255, 100, 100, 0, FILE_BG_DAM_SEG,  FILE_BG_DAM_TILES,  FILE_BG_DAM_PADS,  FILE_USETUPDAM,  FILE_UMP_SETUPDAM,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0e*/ STAGE_EXTRACTION,    2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_ARK_PADS,  FILE_USETUPARK,  FILE_UMP_SETUPARK,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x0f*/ STAGE_TEST_RUN,      2, 255, 100, 100, 0, FILE_BG_RUN_SEG,  FILE_BG_RUN_TILES,  FILE_BG_RUN_PADS,  FILE_USETUPRUN,  FILE_UMP_SETUPRUN,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x10*/ STAGE_24,            2, 255, 100, 100, 0, FILE_BG_SEVX_SEG, FILE_BG_SEVX_TILES, FILE_BG_SEVX_PADS, FILE_USETUPSEVX, FILE_UMP_SETUPSEVX, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x11*/ STAGE_MP_TEMPLE,     2, 255, 100, 100, 0, FILE_BG_JUN_SEG,  FILE_BG_JUN_TILES,  FILE_BG_JUN_PADS,  FILE_USETUPJUN,  FILE_UMP_SETUPJUN,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x12*/ STAGE_CITRAINING,    2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_DISH_PADS, FILE_USETUPDISH, FILE_UMP_SETUPDISH, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x13*/ STAGE_AIRBASE,       2, 255, 100, 100, 0, FILE_BG_CAVE_SEG, FILE_BG_CAVE_TILES, FILE_BG_CAVE_PADS, FILE_USETUPCAVE, FILE_UMP_SETUPCAVE, 1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x14*/ STAGE_28,            2, 255, 100, 100, 0, FILE_BG_CAT_SEG,  FILE_BG_CAT_TILES,  FILE_BG_CAT_PADS,  FILE_USETUPCAT,  FILE_UMP_SETUPCAT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 200, 800, 400, 1,
	/*0x15*/ STAGE_MP_PIPES,      2, 255, 100, 100, 0, FILE_BG_CRAD_SEG, FILE_BG_CRAD_TILES, FILE_BG_CRAD_PADS, FILE_USETUPCRAD, FILE_UMP_SETUPCRAD, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x16*/ STAGE_SKEDARRUINS,   2, 255, 100, 100, 0, FILE_BG_SHO_SEG,  FILE_BG_SHO_TILES,  FILE_BG_SHO_PADS,  FILE_USETUPSHO,  FILE_UMP_SETUPSHO,  1,                1,   100,             0, 0, 20, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x17*/ STAGE_2B,            2, 255, 100, 100, 0, FILE_BG_SEVX_SEG, FILE_BG_SEVX_TILES, FILE_BG_SEVX_PADS, FILE_USETUPSEVX, FILE_UMP_SETUPSEVX, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x18*/ STAGE_VILLA,         2, 255, 100, 100, 0, FILE_BG_ELD_SEG,  FILE_BG_ELD_TILES,  FILE_BG_ELD_PADS,  FILE_USETUPELD,  FILE_UMP_SETUPELD,  1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x19*/ STAGE_DEFENSE,       2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_IMP_PADS,  FILE_USETUPIMP,  FILE_UMP_SETUPIMP,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1a*/ STAGE_TEST_ASH,      2, 255, 100, 100, 0, FILE_BG_ASH_SEG,  FILE_BG_ASH_TILES,  FILE_BG_ASH_PADS,  FILE_USETUPASH,  FILE_UMP_SETUPASH,  1,                1,   100,             0, 0, -1, 500, 0x3e19999a, -1,  400, 0,   1,
	/*0x1b*/ STAGE_INFILTRATION,  2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_LUE_PADS,  FILE_USETUPLUE,  FILE_UMP_SETUPLUE,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1c*/ STAGE_DEFECTION,     2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_AME_PADS,  FILE_USETUPAME,  FILE_UMP_SETUPAME,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1d*/ STAGE_AIRFORCEONE,   2, 255, 100, 100, 0, FILE_BG_RIT_SEG,  FILE_BG_RIT_TILES,  FILE_BG_RIT_PADS,  FILE_USETUPRIT,  FILE_UMP_SETUPRIT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x1e*/ STAGE_MP_SKEDAR,     2, 255, 100, 100, 0, FILE_BG_OAT_SEG,  FILE_BG_OAT_TILES,  FILE_BG_OAT_PADS,  FILE_USETUPOAT,  FILE_UMP_SETUPOAT,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, 700, 800, 400, 1,
	/*0x1f*/ STAGE_INVESTIGATION, 2, 255, 100, 100, 0, FILE_BG_EAR_SEG,  FILE_BG_EAR_TILES,  FILE_BG_EAR_PADS,  FILE_USETUPEAR,  FILE_UMP_SETUPEAR,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x20*/ STAGE_ATTACKSHIP,    2, 255, 100, 100, 0, FILE_BG_LEE_SEG,  FILE_BG_LEE_TILES,  FILE_BG_LEE_PADS,  FILE_USETUPLEE,  FILE_UMP_SETUPLEE,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x21*/ STAGE_RESCUE,        2, 255, 100, 100, 0, FILE_BG_LUE_SEG,  FILE_BG_LUE_TILES,  FILE_BG_LIP_PADS,  FILE_USETUPLIP,  FILE_UMP_SETUPLIP,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x22*/ STAGE_TEST_LEN,      2, 255, 100, 100, 0, FILE_BG_LEN_SEG,  FILE_BG_LEN_TILES,  FILE_BG_LEN_PADS,  FILE_USETUPLEN,  FILE_UMP_SETUPLEN,  0.10040000081062, 1,   6.6844921112061, 0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x23*/ STAGE_MBR,           2, 255, 100, 100, 0, FILE_BG_AME_SEG,  FILE_BG_AME_TILES,  FILE_BG_AME_PADS,  FILE_USETUPWAX,  FILE_UMP_SETUPWAX,  1,                1,   100,             0, 0, 40, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x24*/ STAGE_DEEPSEA,       8, 96,  80,  200, 0, FILE_BG_PAM_SEG,  FILE_BG_PAM_TILES,  FILE_BG_PAM_PADS,  FILE_USETUPPAM,  FILE_UMP_SETUPPAM,  1,                1,   100,             0, 0, 30, 255, 0x3e4ccccd, 300, 600, 0,   1,
	/*0x25*/ STAGE_TEST_UFF,      2, 255, 100, 100, 0, FILE_BG_UFF_SEG,  FILE_BG_UFF_TILES,  FILE_BG_UFF_PADS,  FILE_USETUPUFF,  FILE_UMP_SETUPUFF,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x26*/ STAGE_TEST_OLD,      2, 255, 100, 100, 0, FILE_BG_OLD_SEG,  FILE_BG_OLD_TILES,  FILE_BG_OLD_PADS,  FILE_USETUPOLD,  FILE_UMP_SETUPOLD,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x27*/ STAGE_DUEL,          2, 255, 100, 100, 0, FILE_BG_DISH_SEG, FILE_BG_DISH_TILES, FILE_BG_ATE_PADS,  FILE_USETUPATE,  FILE_UMP_SETUPATE,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x28*/ STAGE_TEST_LAM,      2, 255, 100, 100, 0, FILE_BG_LAM_SEG,  FILE_BG_LAM_TILES,  FILE_BG_LAM_PADS,  FILE_USETUPLAM,  FILE_UMP_SETUPLAM,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x29*/ STAGE_MP_BASE,       2, 255, 100, 100, 0, FILE_BG_MP1_SEG,  FILE_BG_MP1_TILES,  FILE_BG_MP1_PADS,  FILE_USETUPMP1,  FILE_UMP_SETUPMP1,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2a*/ STAGE_TEST_MP2,      2, 255, 100, 100, 0, FILE_BG_MP2_SEG,  FILE_BG_MP2_TILES,  FILE_BG_MP2_PADS,  FILE_USETUPMP2,  FILE_UMP_SETUPMP2,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2b*/ STAGE_MP_AREA52,     2, 255, 100, 100, 0, FILE_BG_MP3_SEG,  FILE_BG_MP3_TILES,  FILE_BG_MP3_PADS,  FILE_USETUPMP3,  FILE_UMP_SETUPMP3,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2c*/ STAGE_MP_WAREHOUSE,  2, 255, 100, 100, 0, FILE_BG_MP4_SEG,  FILE_BG_MP4_TILES,  FILE_BG_MP4_PADS,  FILE_USETUPMP4,  FILE_UMP_SETUPMP4,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2d*/ STAGE_MP_CARPARK,    2, 255, 100, 100, 0, FILE_BG_MP5_SEG,  FILE_BG_MP5_TILES,  FILE_BG_MP5_PADS,  FILE_USETUPMP5,  FILE_UMP_SETUPMP5,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2e*/ STAGE_TEST_MP6,      2, 255, 100, 100, 0, FILE_BG_MP6_SEG,  FILE_BG_MP6_TILES,  FILE_BG_MP6_PADS,  FILE_USETUPMP6,  FILE_UMP_SETUPMP6,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x2f*/ STAGE_TEST_MP7,      2, 255, 100, 100, 0, FILE_BG_MP7_SEG,  FILE_BG_MP7_TILES,  FILE_BG_MP7_PADS,  FILE_USETUPMP7,  FILE_UMP_SETUPMP7,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x30*/ STAGE_TEST_MP8,      2, 255, 100, 100, 0, FILE_BG_MP8_SEG,  FILE_BG_MP8_TILES,  FILE_BG_MP8_PADS,  FILE_USETUPMP8,  FILE_UMP_SETUPMP8,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x31*/ STAGE_MP_RUINS,      2, 255, 100, 100, 0, FILE_BG_MP9_SEG,  FILE_BG_MP9_TILES,  FILE_BG_MP9_PADS,  FILE_USETUPMP9,  FILE_UMP_SETUPMP9,  1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x32*/ STAGE_MP_SEWERS,     2, 255, 100, 100, 0, FILE_BG_MP10_SEG, FILE_BG_MP10_TILES, FILE_BG_MP10_PADS, FILE_USETUPMP10, FILE_UMP_SETUPMP10, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x33*/ STAGE_MP_FELICITY,   2, 255, 100, 100, 0, FILE_BG_MP11_SEG, FILE_BG_MP11_TILES, FILE_BG_MP11_PADS, FILE_USETUPMP11, FILE_UMP_SETUPMP11, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x34*/ STAGE_MP_FORTRESS,   2, 255, 100, 100, 0, FILE_BG_MP12_SEG, FILE_BG_MP12_TILES, FILE_BG_MP12_PADS, FILE_USETUPMP12, FILE_UMP_SETUPMP12, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x35*/ STAGE_MP_VILLA,      2, 255, 100, 100, 0, FILE_BG_MP13_SEG, FILE_BG_MP13_TILES, FILE_BG_MP13_PADS, FILE_USETUPMP13, FILE_UMP_SETUPMP13, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x36*/ STAGE_TEST_MP14,     2, 255, 100, 100, 0, FILE_BG_MP14_SEG, FILE_BG_MP14_TILES, FILE_BG_MP14_PADS, FILE_USETUPMP14, FILE_UMP_SETUPMP14, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x37*/ STAGE_MP_GRID,       2, 255, 100, 100, 0, FILE_BG_MP15_SEG, FILE_BG_MP15_TILES, FILE_BG_MP15_PADS, FILE_USETUPMP15, FILE_UMP_SETUPMP15, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x38*/ STAGE_TEST_MP16,     2, 255, 100, 100, 0, FILE_BG_MP16_SEG, FILE_BG_MP16_TILES, FILE_BG_MP16_PADS, FILE_USETUPMP16, FILE_UMP_SETUPMP16, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x39*/ STAGE_TEST_MP17,     2, 255, 100, 100, 0, FILE_BG_MP17_SEG, FILE_BG_MP17_TILES, FILE_BG_MP17_PADS, FILE_USETUPMP17, FILE_UMP_SETUPMP17, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3a*/ STAGE_TEST_MP18,     2, 255, 100, 100, 0, FILE_BG_MP18_SEG, FILE_BG_MP18_TILES, FILE_BG_MP18_PADS, FILE_USETUPMP18, FILE_UMP_SETUPMP18, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3b*/ STAGE_TEST_MP19,     2, 255, 100, 100, 0, FILE_BG_MP19_SEG, FILE_BG_MP19_TILES, FILE_BG_MP19_PADS, FILE_USETUPMP19, FILE_UMP_SETUPMP19, 1,                1,   100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
	/*0x3c*/ STAGE_TEST_MP20,     2, 255, 100, 100, 0, FILE_BG_MP20_SEG, FILE_BG_MP20_TILES, FILE_BG_MP20_PADS, FILE_USETUPMP20, FILE_UMP_SETUPMP20, 1,                0.5, 100,             0, 0, -1, 255, 0x3e19999a, -1,  400, 0,   1,
};

u32 var80080a18 = 0x00000000;
u32 var80080a1c = 0x00000000;

// 26a40
struct twowords twowords_26a40[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc232dff, 0xfffffe38 },
	{ 0x00000000, 0x00000000 },
};

// 26a58
struct twowords twowords_26a58[] = {
	{ 0xb900031d, 0x0c192078 },
	{ 0xb900031d, 0xc8112078 },
	{ 0xb900031d, 0x0c182078 },
	{ 0xb900031d, 0xc8102078 },
	{ 0xb900031d, 0x0c192d58 },
	{ 0xb900031d, 0xc8112d58 },
	{ 0xb900031d, 0x0c184dd8 },
	{ 0xb900031d, 0xc8104dd8 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0xc81049d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0xb900031d, 0xc8113078 },
	{ 0xb900031d, 0x0c192048 },
	{ 0xb900031d, 0xc8112048 },
	{ 0xb900031d, 0x0c182048 },
	{ 0xb900031d, 0xc8102048 },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e404, 0x1f14ffff },
	{ 0x00000000, 0x00000000 },
};

// 26b90
struct twowords twowords_26b90[] = {
	{ 0xb900031d, 0x0c184dd8 },
	{ 0xb900031d, 0xc8104dd8 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0xc81049d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0xb900031d, 0xc8113078 },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e404, 0x1f14ffff },
	{ 0x00000000, 0x00000000 },
};

// 26c78
struct twowords twowords_26c78[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0x00000000, 0x00000000 },
};

// 26d20
struct twowords twowords_26d20[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0x00000000, 0x00000000 },
};

// 26dc8
struct twowords twowords_26dc8[] = {
	{ 0xb900031d, 0x005049d8 },
	{ 0xb900031d, 0x00553078 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0x00000000, 0x00000000 },
};

// 26df0
struct twowords twowords_26df0[] = {
	{ 0xb900031d, 0x00552078 },
	{ 0xb900031d, 0x00502078 },
	{ 0xb900031d, 0x0c192078 },
	{ 0xb900031d, 0x0c182078 },
	{ 0x00000000, 0x00000000 },
};

// 26e18
struct twowords twowords_26e18[] = {
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0x0c184b50 },
	{ 0x00000000, 0x00000000 },
};

// 26e30
struct twowords twowords_26e30[] = {
	{ 0xba001402, 0x00000000 },
	{ 0xba001402, 0x00100000 },
	{ 0xb900031d, 0x00502048 },
	{ 0xb900031d, 0x08d02048 },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127fff, 0xfffff838 },
	{ 0x00000000, 0x00000000 },
};

// 26e68
struct twowords twowords_26e68[] = {
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfc637ec6, 0xfffff9fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfc637fff, 0xfffff838 },
	{ 0x00000000, 0x00000000 },
};

// 26f50
struct twowords twowords_26f50[] = {
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc637ec6, 0xfffff9fc },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc637fff, 0xfffff838 },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0x00000000, 0x00000000 },
};

u32 var80081018 = (u32) &twowords_26a40;
u32 var8008101c = (u32) &twowords_26a58;
u32 var80081020 = (u32) &twowords_26dc8;
u32 var80081024 = (u32) &twowords_26df0;
u32 var80081028 = (u32) &twowords_26e18;
u32 var8008102c = (u32) &twowords_26b90;
u32 var80081030 = (u32) &twowords_26c78;
u32 var80081034 = (u32) &twowords_26d20;
u32 var80081038 = (u32) &twowords_26e30;
u32 var8008103c = (u32) &twowords_26e68;
u32 var80081040 = (u32) &twowords_26f50;
u32 var80081044 = 0x00000000;
u32 var80081048 = 0x00000000;
u32 var8008104c = 0x00000000;
u32 var80081050 = 0x7f7fffff;
u32 var80081054 = 0x00000000;
u32 var80081058 = 0x00000384;
u32 var8008105c = 0x000003e8;
u32 var80081060 = 0x00000000;
u32 var80081064 = 0x00000000;
u32 var80081068 = 0x00000000;
u32 var8008106c = 0x00000000;
u32 var80081070 = 0x00000000;
u32 var80081074 = 0x00000000;
u32 var80081078 = 0x00000000;
u32 var8008107c = 0x00000000;
u32 var80081080 = 0x00000000;
u32 var80081084 = 0x00000000;
u32 var80081088 = 0x00000000;
u32 var8008108c = 0x00000000;
u32 var80081090 = 0x00000000;
u32 var80081094 = 0x00000000;
u32 var80081098 = 0x00000000;
u32 var8008109c = 0x00000000;
u32 var800810a0 = 0x00000000;
u32 var800810a4 = 0x00000000;
u32 var800810a8 = 0x00000000;
u32 var800810ac = 0x00000000;

// 270d0
//                   lensflare,    r,    g,    b,        x,       y,        z, texture size, orb size
struct sun sun_00        = { 1, 0xff, 0xff, 0xff, -1000000,  200000,    50000, 20, 48 };
struct sun sun_area51    = { 0, 0xff, 0xe0, 0x80,  -200000,  310000,  1000000, 20, 48 };
struct sun sun_villa     = { 1, 0xff, 0xff, 0xff, -1000000,  200000,    50000, 20, 48 };
struct sun sun_ci        = { 1, 0xff, 0xff, 0xff,   400000,  600000, -1000000, 20, 48 };
struct sun sun_skedar    = { 1, 0xff, 0xff, 0xff,  -400000,  600000,  1000000, 20, 48 };
struct sun sun_05        = { 1, 0xff, 0xff, 0xff,        0, 1000000,  1000000, 25, 60 };
struct sun sun_06        = { 1, 0xff, 0xff, 0xff,   400000,  600000,  1000000, 15, 36 };
struct sun sun_crashsite = { 1, 0xff, 0xd7, 0xf2,  1900000,  300000, -1400000, 22, 48 };
struct sun sun_airbase   = { 1, 0xff, 0xd7, 0xf2, -1200000,  200000,   150000, 30, 60 };

// 27184
struct smallsky smallskies[] = {
	//                                                             |------ sky ------|                  |-------------- clouds --------------|                      |-------- water --------|
	// stage            blend  far  06    08   0a      0c      0e     r     g     b  e  sun             e    19     1a    1c     r     g     b    20      22    23  e     r     g     b    28
	{ STAGE_CRASHSITE, 15, 10000,    0,    0,   0, 0x03e2, 0x03e8, 0x9b, 0x2d, 0x1e, 1, &sun_crashsite, 1, 0x00,  1500, 0x00, 0xfa, 0xfa, 0x00, 0x0000, 0xec, 0x78, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_PELAGIC,   15, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x2d, 0x3e, 0x60, 0, NULL,           1, 0x00,  5000, 0x00, 0xf0, 0xf0, 0xf0, 0x0000, 0xf8, 0x30, 0, 0x14, 0x21, 0x2b, 0x00 },
	{ STAGE_VILLA,     15, 20000,    0,    0,   0, 0x03d5, 0x0417, 0x46, 0xa0, 0xff, 1, &sun_villa,     1, 0x00,  5000, 0x00, 0xff, 0xff, 0xff, 0x0000, 0xf8, 0xc6, 1, 0x00, 0xff, 0xff, 0x00 },
	{ 0x03a5,          30, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x10, 0x30, 0x60, 0, NULL,           1, 0x00,  5000, 0x00, 0xff, 0xff, 0xff, 0x0000, 0xfc, 0x18, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0024,           2, 25000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           1, 0x00, 10000, 0x00, 0xff, 0xff, 0xff, 0x0000, 0x00, 0x00, 1, 0x00, 0xff, 0xff, 0x07 },
	{ 0x002b,           2,  2000, 2500, 3055, 750, 0x03bd, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1, 0x00,  5000, 0x00, 0x3a, 0x11, 0x00, 0x0000, 0xfc, 0x18, 1, 0x00, 0xff, 0xff, 0x14 },
	{ 0x03af,           2,  8000, 6000, 8000, 800, 0x03df, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1, 0x00,  5000, 0x00, 0x3a, 0x11, 0x00, 0x0000, 0xfc, 0x18, 1, 0x00, 0xff, 0xff, 0x00 },
	{ 0x00ee,          10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0x0000, 0xfe, 0x0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0152,          10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0x0000, 0xfe, 0x0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x01b6,          10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0x0000, 0xfe, 0x0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00c8,          10,  7500,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x012c,          10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0190,          10,  5000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0000,           0,     0,    0,    0,   0, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00 },
};

// 273ec
struct sky skies[] = {
	//                                                                         |-------- clouds --------|     |------------ water ------------|
	// stage               04  06    08 0c     r     g     b     sun           e     r     g     b  scale 20  e     r     g     b   scale  type 30 34
	{ -1,                  15, 10000, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_RESCUE,        15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MAIANSOS,      15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ATTACKSHIP,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_INFILTRATION,  15, 12000, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ESCAPE,        15, 10000, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_ARCH,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_DEEPSEA,       15, 10000, 0, 0, 0x05, 0x00, 0x00, 0, NULL,         0, 0x9b, 0x9b, 0x9b,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_DEST,     15, 10000, 0, 0, 0x10, 0x30, 0x60, 0, NULL,         1, 0xe6, 0xe6, 0xe6,  3000, 0, 1, 0xff, 0xff, 0x96,   -150,    2, 0, 0 },
	{ STAGE_TEST_LEN,      15, 10000, 0, 0, 0x30, 0x40, 0x10, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_ASH,      15, 25000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFENSE,       15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_CITRAINING,    15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DUEL,          10, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_RETAKING,      15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFECTION,     10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MBR,           10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_EXTRACTION,    10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_SKEDARRUINS,   15, 10000, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_WAR,           15, 10000, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_RUN,      15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MP_SKEDAR,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_TEST_SILO,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_CHICAGO,       10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_G5BUILDING,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_AIRFORCEONE,   15, 20000, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 1, 0xff, 0xff, 0xff,  -5000,    2, 0, 1 },
	{ STAGE_MP_RAVINE,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00, -31000,    0, 0, 1 },
	{ STAGE_AIRBASE,       15, 20000, 0, 0, 0x00, 0x10, 0x40, 1, &sun_airbase, 1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_INVESTIGATION, 15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_MP_PIPES,      15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_G5BUILDING, 15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  4500, 0, 0, 0x00, 0x00, 0x00, -20000,    0, 0, 0 },
	{ STAGE_MP_TEMPLE,     15, 10000, 0, 0, 0x00, 0x10, 0x80, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0xff, 0xff,  -1850,    1, 0, 1 },
	{ STAGE_MP_COMPLEX,    15, 10000, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_UFF,      10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_OLD,      15, 30000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_LAM,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_BASE,       15, 20000, 0, 0, 0x04, 0x00, 0x00, 0, NULL,         1, 0x82, 0xb4, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP2,      15, 20000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_AREA52,     15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_WAREHOUSE,  15, 10000, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_CARPARK,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP6,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP7,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP8,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_RUINS,      15, 10000, 0, 0, 0x03, 0x00, 0x00, 0, NULL,         1, 0x82, 0xe6, 0xaa,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_SEWERS,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0x64, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FELICITY,   10, 10000, 0, 0, 0x04, 0x05, 0x00, 0, NULL,         1, 0x64, 0xd2, 0x82,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FORTRESS,   15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_VILLA,      15, 10000, 0, 0, 0x88, 0x88, 0xdc, 0, NULL,         1, 0xff, 0xaa, 0x2a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP14,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_GRID,       15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP16,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP17,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86, 10000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP18,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP19,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP20,     15, 20000, 0, 0, 0x00, 0x10, 0x3c, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
};

u32 var8008200c = 0x00000000;
u32 var80082010 = 0x00000000;
u32 var80082014 = 0x00000000;
u32 var80082018 = 0x00000000;
u32 var8008201c = 0x00000000;
u32 var80082020 = 0x00000000;
u32 var80082024 = 0x00000000;
u32 var80082028 = 0x00000000;
u32 var8008202c = 0x00000000;
u32 var80082030 = 0x00000000;
u32 var80082034 = 0x00000000;
u32 var80082038 = 0x00000000;
u32 var8008203c = 0x00000000;
u32 var80082040 = 0x00000000;
u32 var80082044 = 0x00000000;
u32 var80082048 = 0x00000000;
u32 var8008204c = 0x00000000;
u32 var80082050 = 0x00000000;
u32 var80082054 = 0x00000000;
u32 var80082058 = 0x00000000;
u32 var8008205c = 0x00000000;

void *filetable[] = {
	/*0x0000*/ NULL,
	/*0x0001*/ &_file_bg_sev_seg,
	/*0x0002*/ &_file_bg_silo_seg,
	/*0x0003*/ &_file_bg_stat_seg,
	/*0x0004*/ &_file_bg_arec_seg,
	/*0x0005*/ &_file_bg_arch_seg,
	/*0x0006*/ &_file_bg_tra_seg,
	/*0x0007*/ &_file_bg_dest_seg,
	/*0x0008*/ &_file_bg_sevb_seg,
	/*0x0009*/ &_file_bg_azt_seg,
	/*0x000a*/ &_file_bg_pete_seg,
	/*0x000b*/ &_file_bg_depo_seg,
	/*0x000c*/ &_file_bg_ref_seg,
	/*0x000d*/ &_file_bg_cryp_seg,
	/*0x000e*/ &_file_bg_dam_seg,
	/*0x000f*/ &_file_bg_ark_seg,
	/*0x0010*/ &_file_bg_run_seg,
	/*0x0011*/ &_file_bg_sevx_seg,
	/*0x0012*/ &_file_bg_jun_seg,
	/*0x0013*/ &_file_bg_dish_seg,
	/*0x0014*/ &_file_bg_cave_seg,
	/*0x0015*/ &_file_bg_cat_seg,
	/*0x0016*/ &_file_bg_crad_seg,
	/*0x0017*/ &_file_bg_sho_seg,
	/*0x0018*/ &_file_bg_eld_seg,
	/*0x0019*/ &_file_bg_imp_seg,
	/*0x001a*/ &_file_bg_ash_seg,
	/*0x001b*/ &_file_bg_lue_seg,
	/*0x001c*/ &_file_bg_ame_seg,
	/*0x001d*/ &_file_bg_rit_seg,
	/*0x001e*/ &_file_bg_oat_seg,
	/*0x001f*/ &_file_bg_ear_seg,
	/*0x0020*/ &_file_bg_lee_seg,
	/*0x0021*/ &_file_bg_lip_seg,
	/*0x0022*/ &_file_bg_len_seg,
	/*0x0023*/ &_file_bg_wax_seg,
	/*0x0024*/ &_file_bg_pam_seg,
	/*0x0025*/ &_file_bg_uff_seg,
	/*0x0026*/ &_file_bg_old_seg,
	/*0x0027*/ &_file_bg_ate_seg,
	/*0x0028*/ &_file_bg_lam_seg,
	/*0x0029*/ &_file_bg_mp1_seg,
	/*0x002a*/ &_file_bg_mp2_seg,
	/*0x002b*/ &_file_bg_mp3_seg,
	/*0x002c*/ &_file_bg_mp4_seg,
	/*0x002d*/ &_file_bg_mp5_seg,
	/*0x002e*/ &_file_bg_mp6_seg,
	/*0x002f*/ &_file_bg_mp7_seg,
	/*0x0030*/ &_file_bg_mp8_seg,
	/*0x0031*/ &_file_bg_mp9_seg,
	/*0x0032*/ &_file_bg_mp10_seg,
	/*0x0033*/ &_file_bg_mp11_seg,
	/*0x0034*/ &_file_bg_mp12_seg,
	/*0x0035*/ &_file_bg_mp13_seg,
	/*0x0036*/ &_file_bg_mp14_seg,
	/*0x0037*/ &_file_bg_mp15_seg,
	/*0x0038*/ &_file_bg_mp16_seg,
	/*0x0039*/ &_file_bg_mp17_seg,
	/*0x003a*/ &_file_bg_mp18_seg,
	/*0x003b*/ &_file_bg_mp19_seg,
	/*0x003c*/ &_file_bg_mp20_seg,
	/*0x003d*/ &_file_ob_mid_seg,
	/*0x003e*/ &_file_Ca51guardZ,
	/*0x003f*/ &_file_Carea51guardZ,
	/*0x0040*/ &_file_CcarringtonZ,
	/*0x0041*/ &_file_CcassandraZ,
	/*0x0042*/ &_file_Cdark_combatZ,
	/*0x0043*/ &_file_Cdark_frockZ,
	/*0x0044*/ &_file_Cdark_trenchZ,
	/*0x0045*/ &_file_CddshockZ,
	/*0x0046*/ &_file_Cdd_secguardZ,
	/*0x0047*/ &_file_CdjbondZ,
	/*0x0048*/ &_file_CdrcarrollZ,
	/*0x0049*/ &_file_CelvisZ,
	/*0x004a*/ &_file_Celvis1Z,
	/*0x004b*/ &_file_CeyespyZ,
	/*0x004c*/ &_file_Cfem_guardZ,
	/*0x004d*/ &_file_ClabtechZ,
	/*0x004e*/ &_file_CmrblondeZ,
	/*0x004f*/ &_file_CofficeworkerZ,
	/*0x0050*/ &_file_Cofficeworker2Z,
	/*0x0051*/ &_file_CoverallZ,
	/*0x0052*/ &_file_CsecretaryZ,
	/*0x0053*/ &_file_CskedarZ,
	/*0x0054*/ &_file_CstripesZ,
	/*0x0055*/ &_file_CtestchrZ,
	/*0x0056*/ &_file_CthekingZ,
	/*0x0057*/ &_file_CtrentZ,
	/*0x0058*/ &_file_GcartblueZ,
	/*0x0059*/ &_file_GcartridgeZ,
	/*0x005a*/ &_file_GcartrifleZ,
	/*0x005b*/ &_file_GcartshellZ,
	/*0x005c*/ &_file_GjoypadZ,
	/*0x005d*/ &_file_Pa51_crate1Z,
	/*0x005e*/ &_file_Pa51_crate2Z,
	/*0x005f*/ &_file_Pa51_crate3Z,
	/*0x0060*/ &_file_Pa51_exp1Z,
	/*0x0061*/ &_file_Pa51_exp2Z,
	/*0x0062*/ &_file_Pa51_horiz_door_botZ,
	/*0x0063*/ &_file_Pa51_horiz_door_glZ,
	/*0x0064*/ &_file_Pa51_horiz_door_secretZ,
	/*0x0065*/ &_file_Pa51_horiz_door_topZ,
	/*0x0066*/ &_file_Pa51_lift_controlZ,
	/*0x0067*/ &_file_Pa51_lift_hangarZ,
	/*0x0068*/ &_file_Pa51_lift_storeZ,
	/*0x0069*/ &_file_Pa51_lift_thinwallZ,
	/*0x006a*/ &_file_Pa51_unexp1Z,
	/*0x006b*/ &_file_Pa51_unexp2Z,
	/*0x006c*/ &_file_Pa51_unexp3Z,
	/*0x006d*/ &_file_Pa51_vert_door_leftZ,
	/*0x006e*/ &_file_Pa51_vert_door_rightZ,
	/*0x006f*/ &_file_Pa51_vert_door_stZ,
	/*0x0070*/ &_file_Pa51boardZ,
	/*0x0071*/ &_file_Pa51chairZ,
	/*0x0072*/ &_file_Pa51deskentZ,
	/*0x0073*/ &_file_Pa51divideZ,
	/*0x0074*/ &_file_Pa51screenZ,
	/*0x0075*/ &_file_Pa51tableZ,
	/*0x0076*/ &_file_Pa51trolleyZ,
	/*0x0077*/ &_file_Pa51wastebinZ,
	/*0x0078*/ &_file_Paivillabot1Z,
	/*0x0079*/ &_file_Paivillabot2Z,
	/*0x007a*/ &_file_Paivillabot3Z,
	/*0x007b*/ &_file_Paivilladoor1Z,
	/*0x007c*/ &_file_Paivilladoor2aZ,
	/*0x007d*/ &_file_Paivilladoor4Z,
	/*0x007e*/ &_file_PaivillawindmillZ,
	/*0x007f*/ &_file_Pal_airlockZ,
	/*0x0080*/ &_file_Pal_dockliftZ,
	/*0x0081*/ &_file_Paldoor_lZ,
	/*0x0082*/ &_file_Paldoor_rZ,
	/*0x0083*/ &_file_Pborg_crateZ,
	/*0x0084*/ &_file_PcaseZ,
	/*0x0085*/ &_file_Pch_shutter1Z,
	/*0x0086*/ &_file_PchrbriefcaseZ,
	/*0x0087*/ &_file_PchrbugZ,
	/*0x0088*/ &_file_PchrdatathiefZ,
	/*0x0089*/ &_file_Pcryptdoor1bZ,
	/*0x008a*/ &_file_Pdd_ac_expZ,
	/*0x008b*/ &_file_Pdd_ac_unexpZ,
	/*0x008c*/ &_file_Pdd_acbot_expZ,
	/*0x008d*/ &_file_Pdd_acbot_unexpZ,
	/*0x008e*/ &_file_Pdd_bannerZ,
	/*0x008f*/ &_file_Pdd_chairZ,
	/*0x0090*/ &_file_Pdd_decodoorZ,
	/*0x0091*/ &_file_Pdd_deskZ,
	/*0x0092*/ &_file_Pdd_fanroofZ,
	/*0x0093*/ &_file_Pdd_fanwallZ,
	/*0x0094*/ &_file_Pdd_hovcabZ,
	/*0x0095*/ &_file_Pdd_hovcarZ,
	/*0x0096*/ &_file_Pdd_hovcopZ,
	/*0x0097*/ &_file_Pdd_hovercopterZ,
	/*0x0098*/ &_file_Pdd_hovmotoZ,
	/*0x0099*/ &_file_Pdd_hovtruckZ,
	/*0x009a*/ &_file_Pdd_lab_cautionZ,
	/*0x009b*/ &_file_Pdd_lab_cautiontopZ,
	/*0x009c*/ &_file_Pdd_lab_door_bsZ,
	/*0x009d*/ &_file_Pdd_lab_door_secZ,
	/*0x009e*/ &_file_Pdd_lab_door_windZ,
	/*0x009f*/ &_file_Pdd_lab_hazardZ,
	/*0x00a0*/ &_file_Pdd_lab_restrictedZ,
	/*0x00a1*/ &_file_Pdd_lab_sector2botZ,
	/*0x00a2*/ &_file_Pdd_lab_sector2topZ,
	/*0x00a3*/ &_file_Pdd_lab_sector3Z,
	/*0x00a4*/ &_file_Pdd_lab_sector3topZ,
	/*0x00a5*/ &_file_Pdd_lab_sector3windZ,
	/*0x00a6*/ &_file_Pdd_lab_sector4topZ,
	/*0x00a7*/ &_file_Pdd_liftdoorZ,
	/*0x00a8*/ &_file_Pdd_liftrZ,
	/*0x00a9*/ &_file_Pdd_officedoorZ,
	/*0x00aa*/ &_file_Pdd_plantrubberZ,
	/*0x00ab*/ &_file_Pdd_plantspiderZ,
	/*0x00ac*/ &_file_Pdd_plantspikeZ,
	/*0x00ad*/ &_file_Pdd_redarmZ,
	/*0x00ae*/ &_file_Pdd_redsofaZ,
	/*0x00af*/ &_file_Pdd_secretdoorZ,
	/*0x00b0*/ &_file_Pdd_secretdoor2Z,
	/*0x00b1*/ &_file_Pdd_servicedoorZ,
	/*0x00b2*/ &_file_Pdd_stonedeskZ,
	/*0x00b3*/ &_file_Pdd_vertblindZ,
	/*0x00b4*/ &_file_Pdd_winddoorZ,
	/*0x00b5*/ &_file_Pdd_windowZ,
	/*0x00b6*/ &_file_PddjumpshipZ,
	/*0x00b7*/ &_file_Pdoor1a_G5Z,
	/*0x00b8*/ &_file_Pdoor1atri_G5Z,
	/*0x00b9*/ &_file_Pdoor1b_G5Z,
	/*0x00ba*/ &_file_Pdoor2_G5Z,
	/*0x00bb*/ &_file_Pdoor2a_G5Z,
	/*0x00bc*/ &_file_Pdoor4a_G5Z,
	/*0x00bd*/ &_file_Pdoor4b_G5Z,
	/*0x00be*/ &_file_Pdoor_rollertrainZ,
	/*0x00bf*/ &_file_PdoorconsoleZ,
	/*0x00c0*/ &_file_Pdr_caroll_doorZ,
	/*0x00c1*/ &_file_Pdr_caroll_door_baseZ,
	/*0x00c2*/ &_file_Pdr_caroll_door_bleftZ,
	/*0x00c3*/ &_file_Pdr_caroll_door_bmainZ,
	/*0x00c4*/ &_file_Pdr_caroll_door_brightZ,
	/*0x00c5*/ &_file_Pdr_caroll_door_leftZ,
	/*0x00c6*/ &_file_Pdr_caroll_door_mainZ,
	/*0x00c7*/ &_file_Pdr_caroll_door_rightZ,
	/*0x00c8*/ &_file_PdropshipZ,
	/*0x00c9*/ &_file_PdumpsterZ,
	/*0x00ca*/ &_file_PexplosionbitZ,
	/*0x00cb*/ &_file_PflagZ,
	/*0x00cc*/ &_file_Pg5_escdoordownZ,
	/*0x00cd*/ &_file_Pg5_escdoordownboomZ,
	/*0x00ce*/ &_file_Pg5_escdoorupZ,
	/*0x00cf*/ &_file_Pg5_escdoorupboomZ,
	/*0x00d0*/ &_file_Pg5_mainframeZ,
	/*0x00d1*/ &_file_Pg5safedoorZ,
	/*0x00d2*/ &_file_Pg5carliftdoorZ,
	/*0x00d3*/ &_file_PgoldeneyelogoZ,
	/*0x00d4*/ &_file_PhooverbotZ,
	/*0x00d5*/ &_file_PhovbikeZ,
	/*0x00d6*/ &_file_PhoverbedZ,
	/*0x00d7*/ &_file_Phovercrate1Z,
	/*0x00d8*/ &_file_PlasdoorZ,
	/*0x00d9*/ &_file_PmarkerZ,
	/*0x00da*/ &_file_Pmedlabwin1Z,
	/*0x00db*/ &_file_Pmedlabwin2Z,
	/*0x00dc*/ &_file_PmodemboxZ,
	/*0x00dd*/ &_file_PnintendologoZ,
	/*0x00de*/ &_file_Pnlogo2Z,
	/*0x00df*/ &_file_Pnlogo3Z,
	/*0x00e0*/ &_file_PnlogoZ,
	/*0x00e1*/ &_file_Ppc1Z,
	/*0x00e2*/ &_file_PpdfourZ,
	/*0x00e3*/ &_file_PpdoneZ,
	/*0x00e4*/ &_file_PpdthreeZ,
	/*0x00e5*/ &_file_PpdtwoZ,
	/*0x00e6*/ &_file_PperfectdarkZ,
	/*0x00e7*/ &_file_PpolicecarZ,
	/*0x00e8*/ &_file_PravineliftZ,
	/*0x00e9*/ &_file_PropeZ,
	/*0x00ea*/ &_file_Psk_cryopod1_botZ,
	/*0x00eb*/ &_file_Psk_cryopod1_topZ,
	/*0x00ec*/ &_file_Psk_door1Z,
	/*0x00ed*/ &_file_Psk_fighter1Z,
	/*0x00ee*/ &_file_Psk_hangardoor_botZ,
	/*0x00ef*/ &_file_Psk_hangardoor_topZ,
	/*0x00f0*/ &_file_Psk_ship_door1Z,
	/*0x00f1*/ &_file_Psk_ship_holo1Z,
	/*0x00f2*/ &_file_Psk_ship_holo2Z,
	/*0x00f3*/ &_file_Psk_ship_hulldoor1Z,
	/*0x00f4*/ &_file_Psk_ship_hulldoor2Z,
	/*0x00f5*/ &_file_Psk_ship_hulldoor3Z,
	/*0x00f6*/ &_file_Psk_ship_hulldoor4Z,
	/*0x00f7*/ &_file_Psk_under_generatorZ,
	/*0x00f8*/ &_file_Psk_under_transZ,
	/*0x00f9*/ &_file_Pskcrev_exp1Z,
	/*0x00fa*/ &_file_Pskcrev_unexp1Z,
	/*0x00fb*/ &_file_Psktnl_exp1Z,
	/*0x00fc*/ &_file_Psktnl_unexp1Z,
	/*0x00fd*/ &_file_PtaxicabZ,
	/*0x00fe*/ &_file_PtesterbotZ,
	/*0x00ff*/ &_file_PtestobjZ,
	/*0x0100*/ &_file_PtvscreenZ,
	/*0x0101*/ &_file_PwindowZ,
	/*0x0102*/ &_file_Ump_setupameZ,
	/*0x0103*/ &_file_Ump_setuparchZ,
	/*0x0104*/ &_file_Ump_setuparecZ,
	/*0x0105*/ &_file_Ump_setuparkZ,
	/*0x0106*/ &_file_Ump_setupashZ,
	/*0x0107*/ &_file_Ump_setupaztZ,
	/*0x0108*/ &_file_Ump_setupcatZ,
	/*0x0109*/ &_file_Ump_setupcaveZ,
	/*0x010a*/ &_file_Ump_setupcradZ,
	/*0x010b*/ &_file_Ump_setupcrypZ,
	/*0x010c*/ &_file_Ump_setupdamZ,
	/*0x010d*/ &_file_Ump_setupdepoZ,
	/*0x010e*/ &_file_Ump_setupdestZ,
	/*0x010f*/ &_file_Ump_setupdishZ,
	/*0x0110*/ &_file_Ump_setupearZ,
	/*0x0111*/ &_file_Ump_setupeldZ,
	/*0x0112*/ &_file_Ump_setupimpZ,
	/*0x0113*/ &_file_Ump_setupjunZ,
	/*0x0114*/ &_file_Ump_setupleeZ,
	/*0x0115*/ &_file_Ump_setuplenZ,
	/*0x0116*/ &_file_Ump_setuplipZ,
	/*0x0117*/ &_file_Ump_setuplueZ,
	/*0x0118*/ &_file_Ump_setupoatZ,
	/*0x0119*/ &_file_Ump_setuppamZ,
	/*0x011a*/ &_file_Ump_setuppeteZ,
	/*0x011b*/ &_file_Ump_setuprefZ,
	/*0x011c*/ &_file_Ump_setupritZ,
	/*0x011d*/ &_file_Ump_setuprunZ,
	/*0x011e*/ &_file_Ump_setupsevZ,
	/*0x011f*/ &_file_Ump_setupsevbZ,
	/*0x0120*/ &_file_Ump_setupsevxZ,
	/*0x0121*/ &_file_Ump_setupshoZ,
	/*0x0122*/ &_file_Ump_setupsiloZ,
	/*0x0123*/ &_file_Ump_setupstatZ,
	/*0x0124*/ &_file_Ump_setuptraZ,
	/*0x0125*/ &_file_Ump_setupwaxZ,
	/*0x0126*/ &_file_UsetupameZ,
	/*0x0127*/ &_file_UsetuparchZ,
	/*0x0128*/ &_file_UsetuparecZ,
	/*0x0129*/ &_file_UsetuparkZ,
	/*0x012a*/ &_file_UsetupashZ,
	/*0x012b*/ &_file_UsetupaztZ,
	/*0x012c*/ &_file_UsetupcatZ,
	/*0x012d*/ &_file_UsetupcaveZ,
	/*0x012e*/ &_file_UsetupcradZ,
	/*0x012f*/ &_file_UsetupcrypZ,
	/*0x0130*/ &_file_UsetupdamZ,
	/*0x0131*/ &_file_UsetupdepoZ,
	/*0x0132*/ &_file_UsetupdestZ,
	/*0x0133*/ &_file_UsetupdishZ,
	/*0x0134*/ &_file_UsetupearZ,
	/*0x0135*/ &_file_UsetupeldZ,
	/*0x0136*/ &_file_UsetupimpZ,
	/*0x0137*/ &_file_UsetupjunZ,
	/*0x0138*/ &_file_UsetupleeZ,
	/*0x0139*/ &_file_UsetuplenZ,
	/*0x013a*/ &_file_UsetuplipZ,
	/*0x013b*/ &_file_UsetuplueZ,
	/*0x013c*/ &_file_UsetupoatZ,
	/*0x013d*/ &_file_UsetuppamZ,
	/*0x013e*/ &_file_UsetuppeteZ,
	/*0x013f*/ &_file_UsetuprefZ,
	/*0x0140*/ &_file_UsetupritZ,
	/*0x0141*/ &_file_UsetuprunZ,
	/*0x0142*/ &_file_UsetupsevZ,
	/*0x0143*/ &_file_UsetupsevbZ,
	/*0x0144*/ &_file_UsetupsevxZ,
	/*0x0145*/ &_file_UsetupsevxbZ,
	/*0x0146*/ &_file_UsetupshoZ,
	/*0x0147*/ &_file_UsetupsiloZ,
	/*0x0148*/ &_file_UsetupstatZ,
	/*0x0149*/ &_file_UsetuptraZ,
	/*0x014a*/ &_file_UsetupwaxZ,
	/*0x014b*/ &_file_bg_ame_padsZ,
	/*0x014c*/ &_file_bg_ame_tilesZ,
	/*0x014d*/ &_file_bg_arch_padsZ,
	/*0x014e*/ &_file_bg_arch_tilesZ,
	/*0x014f*/ &_file_bg_arec_padsZ,
	/*0x0150*/ &_file_bg_arec_tilesZ,
	/*0x0151*/ &_file_bg_ark_padsZ,
	/*0x0152*/ &_file_bg_ark_tilesZ,
	/*0x0153*/ &_file_bg_ash_padsZ,
	/*0x0154*/ &_file_bg_ash_tilesZ,
	/*0x0155*/ &_file_bg_azt_padsZ,
	/*0x0156*/ &_file_bg_azt_tilesZ,
	/*0x0157*/ &_file_bg_cat_padsZ,
	/*0x0158*/ &_file_bg_cat_tilesZ,
	/*0x0159*/ &_file_bg_cave_padsZ,
	/*0x015a*/ &_file_bg_cave_tilesZ,
	/*0x015b*/ &_file_bg_crad_padsZ,
	/*0x015c*/ &_file_bg_crad_tilesZ,
	/*0x015d*/ &_file_bg_cryp_padsZ,
	/*0x015e*/ &_file_bg_cryp_tilesZ,
	/*0x015f*/ &_file_bg_dam_padsZ,
	/*0x0160*/ &_file_bg_dam_tilesZ,
	/*0x0161*/ &_file_bg_depo_padsZ,
	/*0x0162*/ &_file_bg_depo_tilesZ,
	/*0x0163*/ &_file_bg_dest_padsZ,
	/*0x0164*/ &_file_bg_dest_tilesZ,
	/*0x0165*/ &_file_bg_dish_padsZ,
	/*0x0166*/ &_file_bg_dish_tilesZ,
	/*0x0167*/ &_file_bg_ear_padsZ,
	/*0x0168*/ &_file_bg_ear_tilesZ,
	/*0x0169*/ &_file_bg_eld_padsZ,
	/*0x016a*/ &_file_bg_eld_tilesZ,
	/*0x016b*/ &_file_bg_imp_padsZ,
	/*0x016c*/ &_file_bg_imp_tilesZ,
	/*0x016d*/ &_file_bg_jun_padsZ,
	/*0x016e*/ &_file_bg_jun_tilesZ,
	/*0x016f*/ &_file_bg_lee_padsZ,
	/*0x0170*/ &_file_bg_lee_tilesZ,
	/*0x0171*/ &_file_bg_len_padsZ,
	/*0x0172*/ &_file_bg_len_tilesZ,
	/*0x0173*/ &_file_bg_lip_padsZ,
	/*0x0174*/ &_file_bg_lip_tilesZ,
	/*0x0175*/ &_file_bg_lue_padsZ,
	/*0x0176*/ &_file_bg_lue_tilesZ,
	/*0x0177*/ &_file_bg_oat_padsZ,
	/*0x0178*/ &_file_bg_oat_tilesZ,
	/*0x0179*/ &_file_bg_pam_padsZ,
	/*0x017a*/ &_file_bg_pam_tilesZ,
	/*0x017b*/ &_file_bg_pete_padsZ,
	/*0x017c*/ &_file_bg_pete_tilesZ,
	/*0x017d*/ &_file_bg_ref_padsZ,
	/*0x017e*/ &_file_bg_ref_tilesZ,
	/*0x017f*/ &_file_bg_rit_padsZ,
	/*0x0180*/ &_file_bg_rit_tilesZ,
	/*0x0181*/ &_file_bg_run_padsZ,
	/*0x0182*/ &_file_bg_run_tilesZ,
	/*0x0183*/ &_file_bg_sev_padsZ,
	/*0x0184*/ &_file_bg_sev_tilesZ,
	/*0x0185*/ &_file_bg_sevb_padsZ,
	/*0x0186*/ &_file_bg_sevb_tilesZ,
	/*0x0187*/ &_file_bg_sevx_padsZ,
	/*0x0188*/ &_file_bg_sevx_tilesZ,
	/*0x0189*/ &_file_bg_sho_padsZ,
	/*0x018a*/ &_file_bg_sho_tilesZ,
	/*0x018b*/ &_file_bg_silo_padsZ,
	/*0x018c*/ &_file_bg_silo_tilesZ,
	/*0x018d*/ &_file_bg_stat_padsZ,
	/*0x018e*/ &_file_bg_stat_tilesZ,
	/*0x018f*/ &_file_bg_tra_padsZ,
	/*0x0190*/ &_file_bg_tra_tilesZ,
	/*0x0191*/ &_file_bg_wax_padsZ,
	/*0x0192*/ &_file_bg_wax_tilesZ,
	/*0x0193*/ &_file_GtestgunZ,
	/*0x0194*/ &_file_Cdd_labtechZ,
	/*0x0195*/ &_file_Pcctv_pdZ,
	/*0x0196*/ &_file_PcomhubZ,
	/*0x0197*/ &_file_PquadpodZ,
	/*0x0198*/ &_file_Ppd_consoleZ,
	/*0x0199*/ &_file_CconneryZ,
	/*0x019a*/ &_file_CmooreZ,
	/*0x019b*/ &_file_CdaltonZ,
	/*0x019c*/ &_file_Cheaddark_combatZ,
	/*0x019d*/ &_file_CheadelvisZ,
	/*0x019e*/ &_file_CheadrossZ,
	/*0x019f*/ &_file_CheadcarringtonZ,
	/*0x01a0*/ &_file_CheadmrblondeZ,
	/*0x01a1*/ &_file_CheadtrentZ,
	/*0x01a2*/ &_file_CheadddshockZ,
	/*0x01a3*/ &_file_CheadgrahamZ,
	/*0x01a4*/ &_file_Cheaddark_frockZ,
	/*0x01a5*/ &_file_CheadsecretaryZ,
	/*0x01a6*/ &_file_CheadcassandraZ,
	/*0x01a7*/ &_file_CheadthekingZ,
	/*0x01a8*/ &_file_Cheadfem_guardZ,
	/*0x01a9*/ &_file_CheadjonZ,
	/*0x01aa*/ &_file_Plift_platformZ,
	/*0x01ab*/ &_file_Pdd_grateZ,
	/*0x01ac*/ &_file_PlightswitchZ,
	/*0x01ad*/ &_file_PblastshieldZ,
	/*0x01ae*/ &_file_Plightswitch2Z,
	/*0x01af*/ &_file_Pdd_accessdoorupZ,
	/*0x01b0*/ &_file_Pdd_accessdoordnZ,
	/*0x01b1*/ &_file_Cdark_rippedZ,
	/*0x01b2*/ &_file_Cheadmark2Z,
	/*0x01b3*/ &_file_CheadchristZ,
	/*0x01b4*/ &_file_Plab_containerZ,
	/*0x01b5*/ &_file_Plab_chairZ,
	/*0x01b6*/ &_file_Plab_tableZ,
	/*0x01b7*/ &_file_Plab_microscopeZ,
	/*0x01b8*/ &_file_Plab_mainframeZ,
	/*0x01b9*/ &_file_Pdd_labdoorZ,
	/*0x01ba*/ &_file_Pdd_lab_doortopZ,
	/*0x01bb*/ &_file_Pmulti_ammo_crateZ,
	/*0x01bc*/ &_file_CheadrussZ,
	/*0x01bd*/ &_file_CheadgreyZ,
	/*0x01be*/ &_file_CheaddarlingZ,
	/*0x01bf*/ &_file_Cdd_guardZ,
	/*0x01c0*/ &_file_CheadrobertZ,
	/*0x01c1*/ &_file_Cdd_shockZ,
	/*0x01c2*/ &_file_CheadbeauZ,
	/*0x01c3*/ &_file_PchrchainZ,
	/*0x01c4*/ &_file_Cdd_shock_infZ,
	/*0x01c5*/ &_file_Cheadfem_guard2Z,
	/*0x01c6*/ &_file_ProofgunZ,
	/*0x01c7*/ &_file_PtdoorZ,
	/*0x01c8*/ &_file_CbiotechZ,
	/*0x01c9*/ &_file_CfbiguyZ,
	/*0x01ca*/ &_file_PgroundgunZ,
	/*0x01cb*/ &_file_CciaguyZ,
	/*0x01cc*/ &_file_Ca51trooperZ,
	/*0x01cd*/ &_file_CheadbrianZ,
	/*0x01ce*/ &_file_CheadjamieZ,
	/*0x01cf*/ &_file_Cheadduncan2Z,
	/*0x01d0*/ &_file_CheadbiotechZ,
	/*0x01d1*/ &_file_UsetupuffZ,
	/*0x01d2*/ &_file_Ump_setupuffZ,
	/*0x01d3*/ &_file_bg_uff_padsZ,
	/*0x01d4*/ &_file_bg_uff_tilesZ,
	/*0x01d5*/ &_file_UsetupoldZ,
	/*0x01d6*/ &_file_Ump_setupoldZ,
	/*0x01d7*/ &_file_bg_old_padsZ,
	/*0x01d8*/ &_file_bg_old_tilesZ,
	/*0x01d9*/ &_file_UsetupateZ,
	/*0x01da*/ &_file_Ump_setupateZ,
	/*0x01db*/ &_file_bg_ate_padsZ,
	/*0x01dc*/ &_file_bg_ate_tilesZ,
	/*0x01dd*/ &_file_UsetuplamZ,
	/*0x01de*/ &_file_Ump_setuplamZ,
	/*0x01df*/ &_file_bg_lam_padsZ,
	/*0x01e0*/ &_file_bg_lam_tilesZ,
	/*0x01e1*/ &_file_Usetupmp1Z,
	/*0x01e2*/ &_file_Ump_setupmp1Z,
	/*0x01e3*/ &_file_bg_mp1_padsZ,
	/*0x01e4*/ &_file_bg_mp1_tilesZ,
	/*0x01e5*/ &_file_Usetupmp2Z,
	/*0x01e6*/ &_file_Ump_setupmp2Z,
	/*0x01e7*/ &_file_bg_mp2_padsZ,
	/*0x01e8*/ &_file_bg_mp2_tilesZ,
	/*0x01e9*/ &_file_Usetupmp3Z,
	/*0x01ea*/ &_file_Ump_setupmp3Z,
	/*0x01eb*/ &_file_bg_mp3_padsZ,
	/*0x01ec*/ &_file_bg_mp3_tilesZ,
	/*0x01ed*/ &_file_Usetupmp4Z,
	/*0x01ee*/ &_file_Ump_setupmp4Z,
	/*0x01ef*/ &_file_bg_mp4_padsZ,
	/*0x01f0*/ &_file_bg_mp4_tilesZ,
	/*0x01f1*/ &_file_Usetupmp5Z,
	/*0x01f2*/ &_file_Ump_setupmp5Z,
	/*0x01f3*/ &_file_bg_mp5_padsZ,
	/*0x01f4*/ &_file_bg_mp5_tilesZ,
	/*0x01f5*/ &_file_Usetupmp6Z,
	/*0x01f6*/ &_file_Ump_setupmp6Z,
	/*0x01f7*/ &_file_bg_mp6_padsZ,
	/*0x01f8*/ &_file_bg_mp6_tilesZ,
	/*0x01f9*/ &_file_Usetupmp7Z,
	/*0x01fa*/ &_file_Ump_setupmp7Z,
	/*0x01fb*/ &_file_bg_mp7_padsZ,
	/*0x01fc*/ &_file_bg_mp7_tilesZ,
	/*0x01fd*/ &_file_Usetupmp8Z,
	/*0x01fe*/ &_file_Ump_setupmp8Z,
	/*0x01ff*/ &_file_bg_mp8_padsZ,
	/*0x0200*/ &_file_bg_mp8_tilesZ,
	/*0x0201*/ &_file_Usetupmp9Z,
	/*0x0202*/ &_file_Ump_setupmp9Z,
	/*0x0203*/ &_file_bg_mp9_padsZ,
	/*0x0204*/ &_file_bg_mp9_tilesZ,
	/*0x0205*/ &_file_Usetupmp10Z,
	/*0x0206*/ &_file_Ump_setupmp10Z,
	/*0x0207*/ &_file_bg_mp10_padsZ,
	/*0x0208*/ &_file_bg_mp10_tilesZ,
	/*0x0209*/ &_file_Usetupmp11Z,
	/*0x020a*/ &_file_Ump_setupmp11Z,
	/*0x020b*/ &_file_bg_mp11_padsZ,
	/*0x020c*/ &_file_bg_mp11_tilesZ,
	/*0x020d*/ &_file_Usetupmp12Z,
	/*0x020e*/ &_file_Ump_setupmp12Z,
	/*0x020f*/ &_file_bg_mp12_padsZ,
	/*0x0210*/ &_file_bg_mp12_tilesZ,
	/*0x0211*/ &_file_Usetupmp13Z,
	/*0x0212*/ &_file_Ump_setupmp13Z,
	/*0x0213*/ &_file_bg_mp13_padsZ,
	/*0x0214*/ &_file_bg_mp13_tilesZ,
	/*0x0215*/ &_file_Usetupmp14Z,
	/*0x0216*/ &_file_Ump_setupmp14Z,
	/*0x0217*/ &_file_bg_mp14_padsZ,
	/*0x0218*/ &_file_bg_mp14_tilesZ,
	/*0x0219*/ &_file_Usetupmp15Z,
	/*0x021a*/ &_file_Ump_setupmp15Z,
	/*0x021b*/ &_file_bg_mp15_padsZ,
	/*0x021c*/ &_file_bg_mp15_tilesZ,
	/*0x021d*/ &_file_Usetupmp16Z,
	/*0x021e*/ &_file_Ump_setupmp16Z,
	/*0x021f*/ &_file_bg_mp16_padsZ,
	/*0x0220*/ &_file_bg_mp16_tilesZ,
	/*0x0221*/ &_file_Usetupmp17Z,
	/*0x0222*/ &_file_Ump_setupmp17Z,
	/*0x0223*/ &_file_bg_mp17_padsZ,
	/*0x0224*/ &_file_bg_mp17_tilesZ,
	/*0x0225*/ &_file_Usetupmp18Z,
	/*0x0226*/ &_file_Ump_setupmp18Z,
	/*0x0227*/ &_file_bg_mp18_padsZ,
	/*0x0228*/ &_file_bg_mp18_tilesZ,
	/*0x0229*/ &_file_Usetupmp19Z,
	/*0x022a*/ &_file_Ump_setupmp19Z,
	/*0x022b*/ &_file_bg_mp19_padsZ,
	/*0x022c*/ &_file_bg_mp19_tilesZ,
	/*0x022d*/ &_file_Usetupmp20Z,
	/*0x022e*/ &_file_Ump_setupmp20Z,
	/*0x022f*/ &_file_bg_mp20_padsZ,
	/*0x0230*/ &_file_bg_mp20_tilesZ,
	/*0x0231*/ &_file_Ca51airmanZ,
	/*0x0232*/ &_file_Cheadneil2Z,
	/*0x0233*/ &_file_Pci_sofaZ,
	/*0x0234*/ &_file_Pci_liftZ,
	/*0x0235*/ &_file_Pci_liftdoorZ,
	/*0x0236*/ &_file_CchicrobZ,
	/*0x0237*/ &_file_CstewardZ,
	/*0x0238*/ &_file_CheadedmcgZ,
	/*0x0239*/ &_file_CstewardessZ,
	/*0x023a*/ &_file_CheadankaZ,
	/*0x023b*/ &_file_CpresidentZ,
	/*0x023c*/ &_file_Cstewardess_coatZ,
	/*0x023d*/ &_file_Cheadleslie_sZ,
	/*0x023e*/ &_file_PlasercutZ,
	/*0x023f*/ &_file_Psk_shuttleZ,
	/*0x0240*/ &_file_CminiskedarZ,
	/*0x0241*/ &_file_PnewvilladoorZ,
	/*0x0242*/ &_file_Cnsa_lackeyZ,
	/*0x0243*/ &_file_Cheadmatt_cZ,
	/*0x0244*/ &_file_Cpres_securityZ,
	/*0x0245*/ &_file_Cheadpeer_sZ,
	/*0x0246*/ &_file_CnegotiatorZ,
	/*0x0247*/ &_file_Cheadeileen_tZ,
	/*0x0248*/ &_file_Psk_pillarleftZ,
	/*0x0249*/ &_file_Psk_pillarrightZ,
	/*0x024a*/ &_file_Psk_plinth_tZ,
	/*0x024b*/ &_file_Psk_plinth_mlZ,
	/*0x024c*/ &_file_Psk_plinth_mrZ,
	/*0x024d*/ &_file_Psk_plinth_blZ,
	/*0x024e*/ &_file_Psk_plinth_brZ,
	/*0x024f*/ &_file_Psk_fl_shad_tZ,
	/*0x0250*/ &_file_Psk_fl_shad_mlZ,
	/*0x0251*/ &_file_Psk_fl_shad_mrZ,
	/*0x0252*/ &_file_Psk_fl_shad_blZ,
	/*0x0253*/ &_file_Psk_fl_shad_brZ,
	/*0x0254*/ &_file_Psk_fl_noshad_tZ,
	/*0x0255*/ &_file_Psk_fl_noshad_mlZ,
	/*0x0256*/ &_file_Psk_fl_noshad_mrZ,
	/*0x0257*/ &_file_Psk_fl_noshad_blZ,
	/*0x0258*/ &_file_Psk_fl_noshad_brZ,
	/*0x0259*/ &_file_GhudpieceZ,
	/*0x025a*/ &_file_Psk_templecolumn1Z,
	/*0x025b*/ &_file_Psk_templecolumn2Z,
	/*0x025c*/ &_file_Psk_templecolumn3Z,
	/*0x025d*/ &_file_Psk_sunshad1Z,
	/*0x025e*/ &_file_Psk_sunshad2Z,
	/*0x025f*/ &_file_Psk_sunnoshad1Z,
	/*0x0260*/ &_file_Psk_sunnoshad2Z,
	/*0x0261*/ &_file_Cg5_guardZ,
	/*0x0262*/ &_file_Cheadandy_rZ,
	/*0x0263*/ &_file_Cpelagic_guardZ,
	/*0x0264*/ &_file_Cg5_swat_guardZ,
	/*0x0265*/ &_file_Calaskan_guardZ,
	/*0x0266*/ &_file_Cmaian_soldierZ,
	/*0x0267*/ &_file_Cheadben_rZ,
	/*0x0268*/ &_file_Cheadsteve_kZ,
	/*0x0269*/ &_file_PbarrelZ,
	/*0x026a*/ &_file_Pglass_floorZ,
	/*0x026b*/ &_file_Pesca_stepZ,
	/*0x026c*/ &_file_Pmatrix_liftZ,
	/*0x026d*/ &_file_Prubble1Z,
	/*0x026e*/ &_file_Prubble2Z,
	/*0x026f*/ &_file_Prubble3Z,
	/*0x0270*/ &_file_Prubble4Z,
	/*0x0271*/ &_file_Arecep01M,
	/*0x0272*/ &_file_Arecep02M,
	/*0x0273*/ &_file_Arecep03M,
	/*0x0274*/ &_file_Arecep04M,
	/*0x0275*/ &_file_Arecep05M,
	/*0x0276*/ &_file_Arecep06M,
	/*0x0277*/ &_file_Arlguard1M,
	/*0x0278*/ &_file_Arltech01M,
	/*0x0279*/ &_file_Arltech02M,
	/*0x027a*/ &_file_Arltech03M,
	/*0x027b*/ &_file_Arltech04M,
	/*0x027c*/ &_file_Arltech05M,
	/*0x027d*/ &_file_Arltech06M,
	/*0x027e*/ &_file_Ascie2aM,
	/*0x027f*/ &_file_Ascie2bM,
	/*0x0280*/ &_file_Ascie2cM,
	/*0x0281*/ &_file_Ascie2dM,
	/*0x0282*/ &_file_Ascie2eM,
	/*0x0283*/ &_file_Ascie2fM,
	/*0x0284*/ &_file_Ascie2gM,
	/*0x0285*/ &_file_Ascie3aM,
	/*0x0286*/ &_file_Ascie3bM,
	/*0x0287*/ &_file_Ascie3cM,
	/*0x0288*/ &_file_Ascie3dM,
	/*0x0289*/ &_file_Ascie3eM,
	/*0x028a*/ &_file_Ascie3gM,
	/*0x028b*/ &_file_Ascien10aM,
	/*0x028c*/ &_file_Ascien2_aM,
	/*0x028d*/ &_file_Ascien3_aM,
	/*0x028e*/ &_file_Ascien4_aM,
	/*0x028f*/ &_file_Ascien5_aM,
	/*0x0290*/ &_file_Ascien6_aM,
	/*0x0291*/ &_file_Ascien7_aM,
	/*0x0292*/ &_file_Ascien9_aM,
	/*0x0293*/ &_file_AvilgrimM,
	/*0x0294*/ &_file_Awepgd01M,
	/*0x0295*/ &_file_Awepgd02M,
	/*0x0296*/ &_file_Awepgd03M,
	/*0x0297*/ &_file_Awepsc01M,
	/*0x0298*/ &_file_Awepsc02M,
	/*0x0299*/ &_file_Awepsc03M,
	/*0x029a*/ &_file_Aa51elv01M,
	/*0x029b*/ &_file_Aa51elv02M,
	/*0x029c*/ &_file_Aa51elv03M,
	/*0x029d*/ &_file_Aa51grd01M,
	/*0x029e*/ &_file_Aa51grd02M,
	/*0x029f*/ &_file_Aa51grd03M,
	/*0x02a0*/ &_file_Aa51grd04M,
	/*0x02a1*/ &_file_Aa51grd05M,
	/*0x02a2*/ &_file_Aa51grd06M,
	/*0x02a3*/ &_file_Aa51grd07M,
	/*0x02a4*/ &_file_Aa51grd08M,
	/*0x02a5*/ &_file_Aa51grd09M,
	/*0x02a6*/ &_file_Aa51grd10M,
	/*0x02a7*/ &_file_Aa51jo1M,
	/*0x02a8*/ &_file_Aa51jo2M,
	/*0x02a9*/ &_file_Aa51jo3M,
	/*0x02aa*/ &_file_Aa51jo4M,
	/*0x02ab*/ &_file_Aa51jo5M,
	/*0x02ac*/ &_file_Aa51jo6M,
	/*0x02ad*/ &_file_Aa51jon01M,
	/*0x02ae*/ &_file_Aa51jon02M,
	/*0x02af*/ &_file_Aa51jon03M,
	/*0x02b0*/ &_file_Aa51jon04M,
	/*0x02b1*/ &_file_Aa51jon05M,
	/*0x02b2*/ &_file_Aa51jon06M,
	/*0x02b3*/ &_file_Aa51jon07M,
	/*0x02b4*/ &_file_Aa51jon08M,
	/*0x02b5*/ &_file_Aa51jon09M,
	/*0x02b6*/ &_file_Aa51jon10M,
	/*0x02b7*/ &_file_Aa51jon11M,
	/*0x02b8*/ &_file_Aa51jon12M,
	/*0x02b9*/ &_file_Aa51jon14M,
	/*0x02ba*/ &_file_Aa51jon15M,
	/*0x02bb*/ &_file_Aa51sci1M,
	/*0x02bc*/ &_file_Aaf1jo01M,
	/*0x02bd*/ &_file_Aaf1jo02M,
	/*0x02be*/ &_file_Aaf1jo03M,
	/*0x02bf*/ &_file_Aaf1pr01M,
	/*0x02c0*/ &_file_Aaf1pr02M,
	/*0x02c1*/ &_file_Aaf1pr03M,
	/*0x02c2*/ &_file_Aaf1pr04M,
	/*0x02c3*/ &_file_Aaf1pr05M,
	/*0x02c4*/ &_file_Aaf1pr06M,
	/*0x02c5*/ &_file_Aaf1pr07M,
	/*0x02c6*/ &_file_Aaf1pr08M,
	/*0x02c7*/ &_file_Aaf1pr09M,
	/*0x02c8*/ &_file_Aaf1pr10M,
	/*0x02c9*/ &_file_Aaf1tr01M,
	/*0x02ca*/ &_file_Aaf1tr02M,
	/*0x02cb*/ &_file_Aaf1tr03M,
	/*0x02cc*/ &_file_Aairbgd01M,
	/*0x02cd*/ &_file_Aairbgd02M,
	/*0x02ce*/ &_file_Aairbgd03M,
	/*0x02cf*/ &_file_Aairbgd04M,
	/*0x02d0*/ &_file_Aairbgd05M,
	/*0x02d1*/ &_file_Aairbgd06M,
	/*0x02d2*/ &_file_Aairbgd07M,
	/*0x02d3*/ &_file_Aairbgd08M,
	/*0x02d4*/ &_file_Aairbgd09M,
	/*0x02d5*/ &_file_Aairbgd10M,
	/*0x02d6*/ &_file_Aairbgd11M,
	/*0x02d7*/ &_file_Aairbgd12M,
	/*0x02d8*/ &_file_Aairbgd13M,
	/*0x02d9*/ &_file_Aairbgd14M,
	/*0x02da*/ &_file_Aairbgd15M,
	/*0x02db*/ &_file_Aairbgd16M,
	/*0x02dc*/ &_file_Aairstw01M,
	/*0x02dd*/ &_file_Aairstw02M,
	/*0x02de*/ &_file_Aairstw03M,
	/*0x02df*/ &_file_Aassael01M,
	/*0x02e0*/ &_file_Aassael02M,
	/*0x02e1*/ &_file_Aassael03M,
	/*0x02e2*/ &_file_Aassael04M,
	/*0x02e3*/ &_file_Aassael05M,
	/*0x02e4*/ &_file_Aassael06M,
	/*0x02e5*/ &_file_Absewrk01M,
	/*0x02e6*/ &_file_Absewrk02M,
	/*0x02e7*/ &_file_Absewrk03M,
	/*0x02e8*/ &_file_Absewrk04M,
	/*0x02e9*/ &_file_Absewrk05M,
	/*0x02ea*/ &_file_Acetael01M,
	/*0x02eb*/ &_file_Achdroid1M,
	/*0x02ec*/ &_file_Achdroid2M,
	/*0x02ed*/ &_file_Acsec01M,
	/*0x02ee*/ &_file_Acsec02M,
	/*0x02ef*/ &_file_Acsec03M,
	/*0x02f0*/ &_file_Acstan1M,
	/*0x02f1*/ &_file_Acstan2M,
	/*0x02f2*/ &_file_Adevr01M,
	/*0x02f3*/ &_file_Adevr02M,
	/*0x02f4*/ &_file_Adevr03M,
	/*0x02f5*/ &_file_Adevr04M,
	/*0x02f6*/ &_file_Adevr05M,
	/*0x02f7*/ &_file_Adevr06M,
	/*0x02f8*/ &_file_Adevr07M,
	/*0x02f9*/ &_file_Adevr08M,
	/*0x02fa*/ &_file_Adevr09M,
	/*0x02fb*/ &_file_Adevr10M,
	/*0x02fc*/ &_file_Adevr11M,
	/*0x02fd*/ &_file_Adevr12M,
	/*0x02fe*/ &_file_Aexec01M,
	/*0x02ff*/ &_file_Aexec02M,
	/*0x0300*/ &_file_Aexec04M,
	/*0x0301*/ &_file_Aexec05M,
	/*0x0302*/ &_file_Aexec06M,
	/*0x0303*/ &_file_Aexec07M,
	/*0x0304*/ &_file_Aexec08M,
	/*0x0305*/ &_file_Aexec09M,
	/*0x0306*/ &_file_Aexec10M,
	/*0x0307*/ &_file_Aexec11M,
	/*0x0308*/ &_file_Aexec12M,
	/*0x0309*/ &_file_Aexec13M,
	/*0x030a*/ &_file_Aexec14M,
	/*0x030b*/ &_file_Ahelic01M,
	/*0x030c*/ &_file_Ahelic02M,
	/*0x030d*/ &_file_Ahelic03M,
	/*0x030e*/ &_file_Ahologd01M,
	/*0x030f*/ &_file_AholohopkM,
	/*0x0310*/ &_file_Ainvcar01M,
	/*0x0311*/ &_file_Ainvcar02M,
	/*0x0312*/ &_file_Ainvcar03M,
	/*0x0313*/ &_file_Ainvcar04M,
	/*0x0314*/ &_file_Ainvcar05M,
	/*0x0315*/ &_file_Ainvcar06M,
	/*0x0316*/ &_file_Ainvcar07M,
	/*0x0317*/ &_file_Ainvcar08M,
	/*0x0318*/ &_file_Ainvcar09M,
	/*0x0319*/ &_file_Ainvcar10M,
	/*0x031a*/ &_file_Ainvcar11M,
	/*0x031b*/ &_file_Ainvcar12M,
	/*0x031c*/ &_file_AinvfarrM,
	/*0x031d*/ &_file_AinvfemaM,
	/*0x031e*/ &_file_AinvfostM,
	/*0x031f*/ &_file_AinvgrimM,
	/*0x0320*/ &_file_AinvhopkM,
	/*0x0321*/ &_file_AinvmaleM,
	/*0x0322*/ &_file_Ajoexec01M,
	/*0x0323*/ &_file_Ajoexec02M,
	/*0x0324*/ &_file_Ajosci01M,
	/*0x0325*/ &_file_Ajosci02M,
	/*0x0326*/ &_file_Ajosci03M,
	/*0x0327*/ &_file_Alabacc1M,
	/*0x0328*/ &_file_Alabacc2M,
	/*0x0329*/ &_file_Alabacc3M,
	/*0x032a*/ &_file_Alabacc4M,
	/*0x032b*/ &_file_Alabacc5M,
	/*0x032c*/ &_file_Alabacc6M,
	/*0x032d*/ &_file_Alabtech1M,
	/*0x032e*/ &_file_Alabtech2M,
	/*0x032f*/ &_file_Alabtech3M,
	/*0x0330*/ &_file_Alabtech5M,
	/*0x0331*/ &_file_Alabtech6M,
	/*0x0332*/ &_file_Alabtech7M,
	/*0x0333*/ &_file_Alabtech8M,
	/*0x0334*/ &_file_Alabtech9M,
	/*0x0335*/ &_file_Aoffwrk01M,
	/*0x0336*/ &_file_Aoffwrk02M,
	/*0x0337*/ &_file_Aoffwrk03M,
	/*0x0338*/ &_file_Aoffwrk04M,
	/*0x0339*/ &_file_Cpresident_cloneZ,
	/*0x033a*/ &_file_CheadjonathanZ,
	/*0x033b*/ &_file_Cheadmaian_sZ,
	/*0x033c*/ &_file_Cdark_af1Z,
	/*0x033d*/ &_file_Pcable_carZ,
	/*0x033e*/ &_file_Pelvis_saucerZ,
	/*0x033f*/ &_file_Pstewardess_trolleyZ,
	/*0x0340*/ &_file_Pairbase_lift_enclosedZ,
	/*0x0341*/ &_file_Pairbase_lift_angleZ,
	/*0x0342*/ &_file_Pairbase_safedoorZ,
	/*0x0343*/ &_file_Paf1_pilotchairZ,
	/*0x0344*/ &_file_Paf1_passchairZ,
	/*0x0345*/ &_file_CheadshaunZ,
	/*0x0346*/ &_file_PchrnightsightZ,
	/*0x0347*/ &_file_PchrshieldZ,
	/*0x0348*/ &_file_Pchrfalcon2Z,
	/*0x0349*/ &_file_Pchrleegun1Z,
	/*0x034a*/ &_file_PchrmaulerZ,
	/*0x034b*/ &_file_Pchrdy357Z,
	/*0x034c*/ &_file_Pchrdy357trentZ,
	/*0x034d*/ &_file_PchrmaianpistolZ,
	/*0x034e*/ &_file_Pchrfalcon2silZ,
	/*0x034f*/ &_file_Pchrfalcon2scopeZ,
	/*0x0350*/ &_file_Pchrcmp150Z,
	/*0x0351*/ &_file_Pchrar34Z,
	/*0x0352*/ &_file_PchrdragonZ,
	/*0x0353*/ &_file_PchrsuperdragonZ,
	/*0x0354*/ &_file_PchravengerZ,
	/*0x0355*/ &_file_PchrcycloneZ,
	/*0x0356*/ &_file_PchrmaiansmgZ,
	/*0x0357*/ &_file_Pchrrcp120Z,
	/*0x0358*/ &_file_PchrpcgunZ,
	/*0x0359*/ &_file_PchrshotgunZ,
	/*0x035a*/ &_file_PchrskminigunZ,
	/*0x035b*/ &_file_PchrdyrocketZ,
	/*0x035c*/ &_file_PchrdevastatorZ,
	/*0x035d*/ &_file_PchrskrocketZ,
	/*0x035e*/ &_file_Pchrz2020Z,
	/*0x035f*/ &_file_PchrsniperrifleZ,
	/*0x0360*/ &_file_PchrcrossbowZ,
	/*0x0361*/ &_file_PchrdruggunZ,
	/*0x0362*/ &_file_PchrknifeZ,
	/*0x0363*/ &_file_PchrnbombZ,
	/*0x0364*/ &_file_PchrflashbangZ,
	/*0x0365*/ &_file_PchrgrenadeZ,
	/*0x0366*/ &_file_PchrtimedmineZ,
	/*0x0367*/ &_file_PchrproximitymineZ,
	/*0x0368*/ &_file_PchrremotemineZ,
	/*0x0369*/ &_file_PchrecmmineZ,
	/*0x036a*/ &_file_PchrwppkZ,
	/*0x036b*/ &_file_Pchrtt33Z,
	/*0x036c*/ &_file_PchrskorpionZ,
	/*0x036d*/ &_file_PchrkalashZ,
	/*0x036e*/ &_file_PchruziZ,
	/*0x036f*/ &_file_Pchrmp5kZ,
	/*0x0370*/ &_file_Pchrm16Z,
	/*0x0371*/ &_file_Pchrfnp90Z,
	/*0x0372*/ &_file_PchrdyrocketmisZ,
	/*0x0373*/ &_file_PchrskrocketmisZ,
	/*0x0374*/ &_file_PchrcrossboltZ,
	/*0x0375*/ &_file_PchrdevgrenadeZ,
	/*0x0376*/ &_file_PchrdraggrenadeZ,
	/*0x0377*/ &_file_Gfalcon2Z,
	/*0x0378*/ &_file_Gleegun1Z,
	/*0x0379*/ &_file_GskpistolZ,
	/*0x037a*/ &_file_Gdy357Z,
	/*0x037b*/ &_file_Gdy357trentZ,
	/*0x037c*/ &_file_GmaianpistolZ,
	/*0x037d*/ &_file_Gcmp150Z,
	/*0x037e*/ &_file_Gar34Z,
	/*0x037f*/ &_file_GdydragonZ,
	/*0x0380*/ &_file_GdysuperdragonZ,
	/*0x0381*/ &_file_Gk7avengerZ,
	/*0x0382*/ &_file_GcycloneZ,
	/*0x0383*/ &_file_GmaiansmgZ,
	/*0x0384*/ &_file_Grcp120Z,
	/*0x0385*/ &_file_GpcgunZ,
	/*0x0386*/ &_file_GshotgunZ,
	/*0x0387*/ &_file_GskminigunZ,
	/*0x0388*/ &_file_GdyrocketZ,
	/*0x0389*/ &_file_GdydevastatorZ,
	/*0x038a*/ &_file_GskrocketZ,
	/*0x038b*/ &_file_Gz2020Z,
	/*0x038c*/ &_file_GsniperrifleZ,
	/*0x038d*/ &_file_GcrossbowZ,
	/*0x038e*/ &_file_GdruggunZ,
	/*0x038f*/ &_file_GknifeZ,
	/*0x0390*/ &_file_GgrenadeZ,
	/*0x0391*/ &_file_GtimedmineZ,
	/*0x0392*/ &_file_GproximitymineZ,
	/*0x0393*/ &_file_GremotemineZ,
	/*0x0394*/ &_file_GwppkZ,
	/*0x0395*/ &_file_Gtt33Z,
	/*0x0396*/ &_file_GskorpionZ,
	/*0x0397*/ &_file_Gak47Z,
	/*0x0398*/ &_file_GuziZ,
	/*0x0399*/ &_file_Gmp5kZ,
	/*0x039a*/ &_file_Gm16Z,
	/*0x039b*/ &_file_Gfnp90Z,
	/*0x039c*/ &_file_Gfalcon2lodZ,
	/*0x039d*/ &_file_GskminigunlodZ,
	/*0x039e*/ &_file_Pa51_turretZ,
	/*0x039f*/ &_file_PpelagicdoorZ,
	/*0x03a0*/ &_file_Am1_l1_aM,
	/*0x03a1*/ &_file_Am1_l1_bM,
	/*0x03a2*/ &_file_Am1_l1_cM,
	/*0x03a3*/ &_file_Am1_l1_dM,
	/*0x03a4*/ &_file_Am1_l2_aM,
	/*0x03a5*/ &_file_Am1_l2_bM,
	/*0x03a6*/ &_file_Am1_l2_cM,
	/*0x03a7*/ &_file_Am1_l2_dM,
	/*0x03a8*/ &_file_Am1_l3_aM,
	/*0x03a9*/ &_file_Am1_l3_bM,
	/*0x03aa*/ &_file_Am1_l3_cM,
	/*0x03ab*/ &_file_Am1_l3_dM,
	/*0x03ac*/ &_file_Am2_l1_aM,
	/*0x03ad*/ &_file_Am2_l1_bM,
	/*0x03ae*/ &_file_Am2_l1_cM,
	/*0x03af*/ &_file_Am2_l1_dM,
	/*0x03b0*/ &_file_Am3_l1_aM,
	/*0x03b1*/ &_file_Am3_l1_bM,
	/*0x03b2*/ &_file_Am3_l1_cM,
	/*0x03b3*/ &_file_Am3_l1_dM,
	/*0x03b4*/ &_file_Am3_l2_aM,
	/*0x03b5*/ &_file_Am3_l2_bM,
	/*0x03b6*/ &_file_Am3_l2_cM,
	/*0x03b7*/ &_file_Am3_l2_dM,
	/*0x03b8*/ &_file_Am4_l1_aM,
	/*0x03b9*/ &_file_Am4_l1_bM,
	/*0x03ba*/ &_file_Am4_l1_cM,
	/*0x03bb*/ &_file_Am4_l1_dM,
	/*0x03bc*/ &_file_Am4_l2_aM,
	/*0x03bd*/ &_file_Am4_l2_bM,
	/*0x03be*/ &_file_Am4_l2_cM,
	/*0x03bf*/ &_file_Am4_l2_dM,
	/*0x03c0*/ &_file_Am4_l3_aM,
	/*0x03c1*/ &_file_Am4_l3_bM,
	/*0x03c2*/ &_file_Am4_l3_cM,
	/*0x03c3*/ &_file_Am4_l3_dM,
	/*0x03c4*/ &_file_Am5_l1_aM,
	/*0x03c5*/ &_file_Am5_l1_bM,
	/*0x03c6*/ &_file_Am5_l1_cM,
	/*0x03c7*/ &_file_Am5_l1_dM,
	/*0x03c8*/ &_file_Am5_l2_aM,
	/*0x03c9*/ &_file_Am5_l2_bM,
	/*0x03ca*/ &_file_Am5_l2_cM,
	/*0x03cb*/ &_file_Am5_l2_dM,
	/*0x03cc*/ &_file_Am5_l3_aM,
	/*0x03cd*/ &_file_Am5_l3_bM,
	/*0x03ce*/ &_file_Am5_l3_cM,
	/*0x03cf*/ &_file_Am5_l3_dM,
	/*0x03d0*/ &_file_Am6_l1_aM,
	/*0x03d1*/ &_file_Am6_l1_bM,
	/*0x03d2*/ &_file_Am6_l1_cM,
	/*0x03d3*/ &_file_Am6_l1_dM,
	/*0x03d4*/ &_file_Am6_l2_aM,
	/*0x03d5*/ &_file_Am6_l2_bM,
	/*0x03d6*/ &_file_Am6_l2_cM,
	/*0x03d7*/ &_file_Am6_l2_dM,
	/*0x03d8*/ &_file_Am7_l1_aM,
	/*0x03d9*/ &_file_Am7_l1_bM,
	/*0x03da*/ &_file_Am7_l1_cM,
	/*0x03db*/ &_file_Am7_l1_dM,
	/*0x03dc*/ &_file_Am8_l1_aM,
	/*0x03dd*/ &_file_Am8_l1_bM,
	/*0x03de*/ &_file_Am8_l1_cM,
	/*0x03df*/ &_file_Am8_l1_dM,
	/*0x03e0*/ &_file_Am9_l1_aM,
	/*0x03e1*/ &_file_Am9_l1_bM,
	/*0x03e2*/ &_file_Am9_l1_cM,
	/*0x03e3*/ &_file_Am9_l1_dM,
	/*0x03e4*/ &_file_Ap1_01_joM,
	/*0x03e5*/ &_file_Ap1_02_caM,
	/*0x03e6*/ &_file_Ap1_03_joM,
	/*0x03e7*/ &_file_Ap1_04_caM,
	/*0x03e8*/ &_file_Ap1_05_joM,
	/*0x03e9*/ &_file_Ap1_06_caM,
	/*0x03ea*/ &_file_Ap1_07_joM,
	/*0x03eb*/ &_file_Ap1_08_caM,
	/*0x03ec*/ &_file_Ap2_01_joM,
	/*0x03ed*/ &_file_Ap2_02_joM,
	/*0x03ee*/ &_file_Ap2_03_drM,
	/*0x03ef*/ &_file_Ap2_04_joM,
	/*0x03f0*/ &_file_Ap2_05_joM,
	/*0x03f1*/ &_file_Ap2_06_drM,
	/*0x03f2*/ &_file_Ap2_07_drM,
	/*0x03f3*/ &_file_Ap3_01_gdM,
	/*0x03f4*/ &_file_Ap3_02_joM,
	/*0x03f5*/ &_file_Ap3_03_joM,
	/*0x03f6*/ &_file_Ap4_01_dvM,
	/*0x03f7*/ &_file_Ap4_02_joM,
	/*0x03f8*/ &_file_Ap4_03_dvM,
	/*0x03f9*/ &_file_Ap4_04_joM,
	/*0x03fa*/ &_file_Ap4_05_dvM,
	/*0x03fb*/ &_file_Ap4_06_joM,
	/*0x03fc*/ &_file_Ap4_07_blM,
	/*0x03fd*/ &_file_Ap4_08_dvM,
	/*0x03fe*/ &_file_Ap4_09_dvM,
	/*0x03ff*/ &_file_Ap5_01_joM,
	/*0x0400*/ &_file_Ap5_02_joM,
	/*0x0401*/ &_file_Ap5_03_joM,
	/*0x0402*/ &_file_Ap6_01_joM,
	/*0x0403*/ &_file_Ap6_02_caM,
	/*0x0404*/ &_file_Ap6_03_joM,
	/*0x0405*/ &_file_Ap6_04_caM,
	/*0x0406*/ &_file_Ap6_05_joM,
	/*0x0407*/ &_file_Ap6_06_caM,
	/*0x0408*/ &_file_Ap7_01_caM,
	/*0x0409*/ &_file_Ap7_02_joM,
	/*0x040a*/ &_file_Ap7_03_caM,
	/*0x040b*/ &_file_Ap7_04_joM,
	/*0x040c*/ &_file_Ap8_01_dvM,
	/*0x040d*/ &_file_Ap8_02_blM,
	/*0x040e*/ &_file_Ap8_03_dvM,
	/*0x040f*/ &_file_Ap8_04_blM,
	/*0x0410*/ &_file_Ap8_06_blM,
	/*0x0411*/ &_file_Ap8_07_trM,
	/*0x0412*/ &_file_Ap8_08_dvM,
	/*0x0413*/ &_file_Ap8_09_trM,
	/*0x0414*/ &_file_Ap8_10_blM,
	/*0x0415*/ &_file_Ap9_01_joM,
	/*0x0416*/ &_file_Ap9_02_caM,
	/*0x0417*/ &_file_Ap9_03_joM,
	/*0x0418*/ &_file_Ap10_01_caM,
	/*0x0419*/ &_file_Ap10_02_caM,
	/*0x041a*/ &_file_Ap10_03_caM,
	/*0x041b*/ &_file_Ap10_04_caM,
	/*0x041c*/ &_file_Ap10_05_joM,
	/*0x041d*/ &_file_Ap10_06_caM,
	/*0x041e*/ &_file_Ap10_07_joM,
	/*0x041f*/ &_file_Ap10_08_caM,
	/*0x0420*/ &_file_Ap10_09_joM,
	/*0x0421*/ &_file_Ap11_01_jnM,
	/*0x0422*/ &_file_Ap11_02_joM,
	/*0x0423*/ &_file_Ap11_03_jnM,
	/*0x0424*/ &_file_Ap11_04_joM,
	/*0x0425*/ &_file_Ap11_05_jnM,
	/*0x0426*/ &_file_Ap11_06_joM,
	/*0x0427*/ &_file_Ap11_07_jnM,
	/*0x0428*/ &_file_Ap11_08_joM,
	/*0x0429*/ &_file_Ap12_01_jnM,
	/*0x042a*/ &_file_Ap12_02_joM,
	/*0x042b*/ &_file_Ap12_03_jnM,
	/*0x042c*/ &_file_Ap12_04_joM,
	/*0x042d*/ &_file_Ap12_05_jnM,
	/*0x042e*/ &_file_Ap12_06_joM,
	/*0x042f*/ &_file_Ap12_07_jnM,
	/*0x0430*/ &_file_Ap12_08_joM,
	/*0x0431*/ &_file_Ap12_09_jnM,
	/*0x0432*/ &_file_Ap12_10_joM,
	/*0x0433*/ &_file_Ap13_01_joM,
	/*0x0434*/ &_file_Ap13_02_suM,
	/*0x0435*/ &_file_Ap13_03_joM,
	/*0x0436*/ &_file_Ap13_04_suM,
	/*0x0437*/ &_file_Ap13_06_suM,
	/*0x0438*/ &_file_Ap14_03_suM,
	/*0x0439*/ &_file_Ap14_04_joM,
	/*0x043a*/ &_file_Ap14_05_suM,
	/*0x043b*/ &_file_Ap14_07_joM,
	/*0x043c*/ &_file_Ap15_01_elM,
	/*0x043d*/ &_file_Ap15_02_elM,
	/*0x043e*/ &_file_Ap15_03_joM,
	/*0x043f*/ &_file_Ap15_04_jnM,
	/*0x0440*/ &_file_Ap15_05_elM,
	/*0x0441*/ &_file_Ap15_06_joM,
	/*0x0442*/ &_file_Ap15_07_elM,
	/*0x0443*/ &_file_Ap15_08_joM,
	/*0x0444*/ &_file_Ap15_09_elM,
	/*0x0445*/ &_file_Ap15_10_joM,
	/*0x0446*/ &_file_Ap15_11_elM,
	/*0x0447*/ &_file_Ap16_01_joM,
	/*0x0448*/ &_file_Ap16_02_caM,
	/*0x0449*/ &_file_Ap16_04_caM,
	/*0x044a*/ &_file_Ap16_05_joM,
	/*0x044b*/ &_file_Ap16_06_caM,
	/*0x044c*/ &_file_Ap17_01_trM,
	/*0x044d*/ &_file_Ap17_02_prM,
	/*0x044e*/ &_file_Ap17_03_trM,
	/*0x044f*/ &_file_Ap17_04_prM,
	/*0x0450*/ &_file_Ap17_05_trM,
	/*0x0451*/ &_file_Ap17_06_trM,
	/*0x0452*/ &_file_Ap18_01_joM,
	/*0x0453*/ &_file_Ap18_02_elM,
	/*0x0454*/ &_file_Ap18_03_elM,
	/*0x0455*/ &_file_Ap18_04_joM,
	/*0x0456*/ &_file_Ap18_05_elM,
	/*0x0457*/ &_file_Ap19_01_caM,
	/*0x0458*/ &_file_Ap19_02_caM,
	/*0x0459*/ &_file_Ap19_03_joM,
	/*0x045a*/ &_file_Ap19_04_caM,
	/*0x045b*/ &_file_Ap19_05_joM,
	/*0x045c*/ &_file_Ap19_06_joM,
	/*0x045d*/ &_file_Ap20_01_joM,
	/*0x045e*/ &_file_Ap20_02_prM,
	/*0x045f*/ &_file_Ap20_03_joM,
	/*0x0460*/ &_file_Ap20_04_prM,
	/*0x0461*/ &_file_Ap20_05_joM,
	/*0x0462*/ &_file_Ap20_06_blM,
	/*0x0463*/ &_file_Ap20_07_trM,
	/*0x0464*/ &_file_Ap20_08_trM,
	/*0x0465*/ &_file_Ap21_01_elM,
	/*0x0466*/ &_file_Ap21_02_joM,
	/*0x0467*/ &_file_Ap21_03_elM,
	/*0x0468*/ &_file_Ap21_04_joM,
	/*0x0469*/ &_file_Ap22_01_elM,
	/*0x046a*/ &_file_Ap22_02_joM,
	/*0x046b*/ &_file_Ap22_03_elM,
	/*0x046c*/ &_file_Ap22_04_joM,
	/*0x046d*/ &_file_Ap23_01_joM,
	/*0x046e*/ &_file_Ap23_02_drM,
	/*0x046f*/ &_file_Ap23_03_joM,
	/*0x0470*/ &_file_Ap23_04_drM,
	/*0x0471*/ &_file_Ap23_05_joM,
	/*0x0472*/ &_file_Ap23_06_drM,
	/*0x0473*/ &_file_Ap23_07_joM,
	/*0x0474*/ &_file_Ap23_08_drM,
	/*0x0475*/ &_file_Ap24_01_caM,
	/*0x0476*/ &_file_Ap24_02_joM,
	/*0x0477*/ &_file_Ap24_03_caM,
	/*0x0478*/ &_file_Ap24_04_joM,
	/*0x0479*/ &_file_Ap24_05_caM,
	/*0x047a*/ &_file_Ap24_06_caM,
	/*0x047b*/ &_file_Ap24_07_joM,
	/*0x047c*/ &_file_Ap24_08_joM,
	/*0x047d*/ &_file_Ap25_01_joM,
	/*0x047e*/ &_file_Ap25_02_joM,
	/*0x047f*/ &_file_Ap26_01_joM,
	/*0x0480*/ &_file_Ap26_02_dvM,
	/*0x0481*/ &_file_Ap26_03_joM,
	/*0x0482*/ &_file_Ap26_04_dvM,
	/*0x0483*/ &_file_Ap26_05_dvM,
	/*0x0484*/ &_file_Ap26_06_joM,
	/*0x0485*/ &_file_Ap26_07_dvM,
	/*0x0486*/ &_file_Ap26_08_dvM,
	/*0x0487*/ &_file_Ap27_01_joM,
	/*0x0488*/ &_file_Ap27_02_elM,
	/*0x0489*/ &_file_Ap27_03_elM,
	/*0x048a*/ &_file_Ap27_04_joM,
	/*0x048b*/ &_file_Ap27_05_joM,
	/*0x048c*/ &_file_Ap27_06_elM,
	/*0x048d*/ &_file_Ap28_01_elM,
	/*0x048e*/ &_file_Ap28_02_joM,
	/*0x048f*/ &_file_Ap28_03_elM,
	/*0x0490*/ &_file_Ap28_04_joM,
	/*0x0491*/ &_file_Ap28_05_elM,
	/*0x0492*/ &_file_Ap28_06_joM,
	/*0x0493*/ &_file_Ap29_01_elM,
	/*0x0494*/ &_file_Ap29_02_joM,
	/*0x0495*/ &_file_Ap29_03_elM,
	/*0x0496*/ &_file_Ap29_04_joM,
	/*0x0497*/ &_file_Ap29_05_joM,
	/*0x0498*/ &_file_Ap29_06_elM,
	/*0x0499*/ &_file_Ap29_07_joM,
	/*0x049a*/ &_file_Ap29_08_elM,
	/*0x049b*/ &_file_Ap29_09_joM,
	/*0x049c*/ &_file_Ap29_10_elM,
	/*0x049d*/ &_file_PautosurgeonZ,
	/*0x049e*/ &_file_CdarkwetZ,
	/*0x049f*/ &_file_CdarkaqualungZ,
	/*0x04a0*/ &_file_CdarksnowZ,
	/*0x04a1*/ &_file_CdarklabZ,
	/*0x04a2*/ &_file_CfemlabtechZ,
	/*0x04a3*/ &_file_CddsniperZ,
	/*0x04a4*/ &_file_Cpilotaf1Z,
	/*0x04a5*/ &_file_CcilabtechZ,
	/*0x04a6*/ &_file_CcifemtechZ,
	/*0x04a7*/ &_file_Cheadeileen_hZ,
	/*0x04a8*/ &_file_Cheadscott_hZ,
	/*0x04a9*/ &_file_CcarreveningsuitZ,
	/*0x04aa*/ &_file_CjonathonZ,
	/*0x04ab*/ &_file_CcisoldierZ,
	/*0x04ac*/ &_file_CheadsanchezZ,
	/*0x04ad*/ &_file_CheaddarkaquaZ,
	/*0x04ae*/ &_file_CheadddsniperZ,
	/*0x04af*/ &_file_PlimoZ,
	/*0x04b0*/ &_file_PpdmenuZ,
	/*0x04b1*/ &_file_Pa51interceptorZ,
	/*0x04b2*/ &_file_Pa51dishZ,
	/*0x04b3*/ &_file_Pa51radarconsoleZ,
	/*0x04b4*/ &_file_Pa51lockerdoorZ,
	/*0x04b5*/ &_file_Pg5generatorZ,
	/*0x04b6*/ &_file_Pg5dumpsterZ,
	/*0x04b7*/ &_file_Gar34lodZ,
	/*0x04b8*/ &_file_GavengerlodZ,
	/*0x04b9*/ &_file_Gcmp150lodZ,
	/*0x04ba*/ &_file_GcrossbowlodZ,
	/*0x04bb*/ &_file_GcyclonelodZ,
	/*0x04bc*/ &_file_GdruggunlodZ,
	/*0x04bd*/ &_file_Gdy357lodZ,
	/*0x04be*/ &_file_Gdy357trentlodZ,
	/*0x04bf*/ &_file_GdevastatorlodZ,
	/*0x04c0*/ &_file_GdydragonlodZ,
	/*0x04c1*/ &_file_GdysuperdragonlodZ,
	/*0x04c2*/ &_file_GknifelodZ,
	/*0x04c3*/ &_file_GlaserlodZ,
	/*0x04c4*/ &_file_GmagseclodZ,
	/*0x04c5*/ &_file_GmayanpistollodZ,
	/*0x04c6*/ &_file_GmayansmglodZ,
	/*0x04c7*/ &_file_GpcgunlodZ,
	/*0x04c8*/ &_file_Grcp120lodZ,
	/*0x04c9*/ &_file_GrocketlodZ,
	/*0x04ca*/ &_file_GshotgunlodZ,
	/*0x04cb*/ &_file_GskpistollodZ,
	/*0x04cc*/ &_file_GskrocketlodZ,
	/*0x04cd*/ &_file_GsniperlodZ,
	/*0x04ce*/ &_file_Gz2020lodZ,
	/*0x04cf*/ &_file_PchrcloakerZ,
	/*0x04d0*/ &_file_PchrspeedpillZ,
	/*0x04d1*/ &_file_PbaggagecarrierZ,
	/*0x04d2*/ &_file_PminesignZ,
	/*0x04d3*/ &_file_PchamberZ,
	/*0x04d4*/ &_file_PisotopeexperimentZ,
	/*0x04d5*/ &_file_PisotopeZ,
	/*0x04d6*/ &_file_PreactordoorZ,
	/*0x04d7*/ &_file_PsaucerinsideZ,
	/*0x04d8*/ &_file_PvillastoolZ,
	/*0x04d9*/ &_file_Pcetanwindow1Z,
	/*0x04da*/ &_file_Pcetanwindow2Z,
	/*0x04db*/ &_file_Pcetanwindow3Z,
	/*0x04dc*/ &_file_Apelelv01M,
	/*0x04dd*/ &_file_Apelgrd01M,
	/*0x04de*/ &_file_Ap29_11_joM,
	/*0x04df*/ &_file_GlaserZ,
	/*0x04e0*/ &_file_PbigpelagicdoorZ,
	/*0x04e1*/ &_file_Psk_jonrubble3Z,
	/*0x04e2*/ &_file_Psk_jonrubble4Z,
	/*0x04e3*/ &_file_Psk_jonrubble5Z,
	/*0x04e4*/ &_file_Psk_jonrubble6Z,
	/*0x04e5*/ &_file_GcombathandslodZ,
	/*0x04e6*/ &_file_PbinocularsZ,
	/*0x04e7*/ &_file_PsubmarineZ,
	/*0x04e8*/ &_file_Pairforce1Z,
	/*0x04e9*/ &_file_PenginepartZ,
	/*0x04ea*/ &_file_Am3l2carrM,
	/*0x04eb*/ &_file_Aelvcet01M,
	/*0x04ec*/ &_file_Aelvcet02M,
	/*0x04ed*/ &_file_Ajorep01M,
	/*0x04ee*/ &_file_Ajorep02M,
	/*0x04ef*/ &_file_Ajorep03M,
	/*0x04f0*/ &_file_Ajorep04M,
	/*0x04f1*/ &_file_PcetroofgunZ,
	/*0x04f2*/ &_file_PcetansmalldoorZ,
	/*0x04f3*/ &_file_PpowernodeZ,
	/*0x04f4*/ &_file_PcetanbluegreenlZ,
	/*0x04f5*/ &_file_PcetanbluegreenrZ,
	/*0x04f6*/ &_file_PskedarconsoleZ,
	/*0x04f7*/ &_file_PskedarconsolepanelZ,
	/*0x04f8*/ &_file_Ajorpld01M,
	/*0x04f9*/ &_file_Ajorpld02M,
	/*0x04fa*/ &_file_Ajorpld03M,
	/*0x04fb*/ &_file_Ajorpld04M,
	/*0x04fc*/ &_file_GnbombZ,
	/*0x04fd*/ &_file_GnbomblodZ,
	/*0x04fe*/ &_file_GgrenadelodZ,
	/*0x04ff*/ &_file_PweaponcdoorZ,
	/*0x0500*/ &_file_PtargetZ,
	/*0x0501*/ &_file_PdevicesecretdoorZ,
	/*0x0502*/ &_file_PcarringtonsecretdoorZ,
	/*0x0503*/ &_file_PsinisterpcZ,
	/*0x0504*/ &_file_PsinisterstationZ,
	/*0x0505*/ &_file_PkeypadlockZ,
	/*0x0506*/ &_file_PthumbprintscannerZ,
	/*0x0507*/ &_file_PretinalockZ,
	/*0x0508*/ &_file_PcardlockZ,
	/*0x0509*/ &_file_PgoodstationZ,
	/*0x050a*/ &_file_PgoodpcZ,
	/*0x050b*/ &_file_CskedarkingZ,
	/*0x050c*/ &_file_CelviswaistcoatZ,
	/*0x050d*/ &_file_CheadgriffeyZ,
	/*0x050e*/ &_file_CheadmotoZ,
	/*0x050f*/ &_file_CheadkeithZ,
	/*0x0510*/ &_file_CheadwinnerZ,
	/*0x0511*/ &_file_Ca51faceplateZ,
	/*0x0512*/ &_file_PchrautogunZ,
	/*0x0513*/ &_file_Pg5bigchairZ,
	/*0x0514*/ &_file_Pg5smallchairZ,
	/*0x0515*/ &_file_PkingsceptreZ,
	/*0x0516*/ &_file_PlabcoatZ,
	/*0x0517*/ &_file_Atrjo01M,
	/*0x0518*/ &_file_Atrgrim01M,
	/*0x0519*/ &_file_Atrgrim02M,
	/*0x051a*/ &_file_Atrcarr06M,
	/*0x051b*/ &_file_Atrcarr07M,
	/*0x051c*/ &_file_Atrcarr08M,
	/*0x051d*/ &_file_Atrcarr01M,
	/*0x051e*/ &_file_Atrcarr02M,
	/*0x051f*/ &_file_Atrcarr03M,
	/*0x0520*/ &_file_Atrcarr04M,
	/*0x0521*/ &_file_Atrcarr05M,
	/*0x0522*/ &_file_Atrcarr12M,
	/*0x0523*/ &_file_Abnblde01M,
	/*0x0524*/ &_file_Abncass01M,
	/*0x0525*/ &_file_Pcidoor1Z,
	/*0x0526*/ &_file_Pg5_chairZ,
	/*0x0527*/ &_file_Pg5_chair2Z,
	/*0x0528*/ &_file_Pdd_window_foyerZ,
	/*0x0529*/ &_file_Ghand_jowetsuitZ,
	/*0x052a*/ &_file_Ghand_trentZ,
	/*0x052b*/ &_file_Ghand_jofrockZ,
	/*0x052c*/ &_file_Ghand_jotrenchZ,
	/*0x052d*/ &_file_Ghand_ddsniperZ,
	/*0x052e*/ &_file_Ghand_presidentZ,
	/*0x052f*/ &_file_Ghand_joaf1Z,
	/*0x0530*/ &_file_Ghand_jopilotZ,
	/*0x0531*/ &_file_Ghand_carringtonZ,
	/*0x0532*/ &_file_Ghand_mrblondeZ,
	/*0x0533*/ &_file_Ghand_ciaZ,
	/*0x0534*/ &_file_Ghand_cifemtechZ,
	/*0x0535*/ &_file_Ghand_fbiarmZ,
	/*0x0536*/ &_file_Ghand_josnowZ,
	/*0x0537*/ &_file_Ghand_vriesZ,
	/*0x0538*/ &_file_Ghand_ddsecurityZ,
	/*0x0539*/ &_file_Ghand_tragic_pelagicZ,
	/*0x053a*/ &_file_Ghand_stewardess_coatZ,
	/*0x053b*/ &_file_Ghand_ddlabtechZ,
	/*0x053c*/ &_file_Pci_cabinetZ,
	/*0x053d*/ &_file_Pci_deskZ,
	/*0x053e*/ &_file_Pci_carr_deskZ,
	/*0x053f*/ &_file_Pci_f_chairZ,
	/*0x0540*/ &_file_Pci_loungerZ,
	/*0x0541*/ &_file_Pci_f_sofaZ,
	/*0x0542*/ &_file_Pci_tableZ,
	/*0x0543*/ &_file_Pcv_coffee_tableZ,
	/*0x0544*/ &_file_Pcv_chair1Z,
	/*0x0545*/ &_file_Pcv_chair2Z,
	/*0x0546*/ &_file_Pcv_sofaZ,
	/*0x0547*/ &_file_Pcv_chair4Z,
	/*0x0548*/ &_file_Pcv_lampZ,
	/*0x0549*/ &_file_Pcv_cabinetZ,
	/*0x054a*/ &_file_Pcv_f_bedZ,
	/*0x054b*/ &_file_Ppel_chair1Z,
	/*0x054c*/ &_file_Psk_console2Z,
	/*0x054d*/ &_file_Pdd_ear_tableZ,
	/*0x054e*/ &_file_Pdd_ear_chairZ,
	/*0x054f*/ &_file_Pairbase_table2Z,
	/*0x0550*/ &_file_Pairbase_chair2Z,
	/*0x0551*/ &_file_Pmisc_crateZ,
	/*0x0552*/ &_file_Pmisc_irspecsZ,
	/*0x0553*/ &_file_Cheadelvis_gogsZ,
	/*0x0554*/ &_file_CheadstevemZ,
	/*0x0555*/ &_file_Pa51_roofgunZ,
	/*0x0556*/ &_file_Psk_drone_gunZ,
	/*0x0557*/ &_file_Pci_roofgunZ,
	/*0x0558*/ &_file_Pcv_tableZ,
	/*0x0559*/ &_file_Cdark_leatherZ,
	/*0x055a*/ &_file_Cheaddark_snowZ,
	/*0x055b*/ &_file_CheadpresidentZ,
	/*0x055c*/ &_file_Pcidoor1_refZ,
	/*0x055d*/ &_file_Palaskadoor_outZ,
	/*0x055e*/ &_file_Palaskadoor_inZ,
	/*0x055f*/ &_file_PwirefenceZ,
	/*0x0560*/ &_file_PrarelogoZ,
	/*0x0561*/ &_file_Chead_vdZ,
	/*0x0562*/ &_file_Apelelv02M,
	/*0x0563*/ &_file_PkeycardZ,
	/*0x0564*/ &_file_PbodyarmourZ,
	/*0x0565*/ &_file_Pa51gate_rZ,
	/*0x0566*/ &_file_Pa51gate_lZ,
	/*0x0567*/ &_file_Paf1_lampZ,
	/*0x0568*/ &_file_Paf1_toiletZ,
	/*0x0569*/ &_file_Paf1_doorbig2Z,
	/*0x056a*/ &_file_Paf1_phoneZ,
	/*0x056b*/ &_file_Paf1_cargodoorZ,
	/*0x056c*/ &_file_Pg5_alarmZ,
	/*0x056d*/ &_file_Pg5_laser_switchZ,
	/*0x056e*/ &_file_Psk_templecolumn4Z,
	/*0x056f*/ &_file_PcorehatchZ,
	/*0x0570*/ &_file_LameE,
	/*0x0571*/ &_file_LameJ,
	/*0x0572*/ &_file_LameP,
	/*0x0573*/ &_file_Lame_str_gZ,
	/*0x0574*/ &_file_Lame_str_fZ,
	/*0x0575*/ &_file_Lame_str_sZ,
	/*0x0576*/ &_file_Lame_str_iZ,
	/*0x0577*/ &_file_LarchE,
	/*0x0578*/ &_file_LarchJ,
	/*0x0579*/ &_file_LarchP,
	/*0x057a*/ &_file_Larch_str_gZ,
	/*0x057b*/ &_file_Larch_str_fZ,
	/*0x057c*/ &_file_Larch_str_sZ,
	/*0x057d*/ &_file_Larch_str_iZ,
	/*0x057e*/ &_file_LarecE,
	/*0x057f*/ &_file_LarecJ,
	/*0x0580*/ &_file_LarecP,
	/*0x0581*/ &_file_Larec_str_gZ,
	/*0x0582*/ &_file_Larec_str_fZ,
	/*0x0583*/ &_file_Larec_str_sZ,
	/*0x0584*/ &_file_Larec_str_iZ,
	/*0x0585*/ &_file_LarkE,
	/*0x0586*/ &_file_LarkJ,
	/*0x0587*/ &_file_LarkP,
	/*0x0588*/ &_file_Lark_str_gZ,
	/*0x0589*/ &_file_Lark_str_fZ,
	/*0x058a*/ &_file_Lark_str_sZ,
	/*0x058b*/ &_file_Lark_str_iZ,
	/*0x058c*/ &_file_LashE,
	/*0x058d*/ &_file_LashJ,
	/*0x058e*/ &_file_LashP,
	/*0x058f*/ &_file_Lash_str_gZ,
	/*0x0590*/ &_file_Lash_str_fZ,
	/*0x0591*/ &_file_Lash_str_sZ,
	/*0x0592*/ &_file_Lash_str_iZ,
	/*0x0593*/ &_file_LateE,
	/*0x0594*/ &_file_LateJ,
	/*0x0595*/ &_file_LateP,
	/*0x0596*/ &_file_Late_str_gZ,
	/*0x0597*/ &_file_Late_str_fZ,
	/*0x0598*/ &_file_Late_str_sZ,
	/*0x0599*/ &_file_Late_str_iZ,
	/*0x059a*/ &_file_LaztE,
	/*0x059b*/ &_file_LaztJ,
	/*0x059c*/ &_file_LaztP,
	/*0x059d*/ &_file_Lazt_str_gZ,
	/*0x059e*/ &_file_Lazt_str_fZ,
	/*0x059f*/ &_file_Lazt_str_sZ,
	/*0x05a0*/ &_file_Lazt_str_iZ,
	/*0x05a1*/ &_file_LcatE,
	/*0x05a2*/ &_file_LcatJ,
	/*0x05a3*/ &_file_LcatP,
	/*0x05a4*/ &_file_Lcat_str_gZ,
	/*0x05a5*/ &_file_Lcat_str_fZ,
	/*0x05a6*/ &_file_Lcat_str_sZ,
	/*0x05a7*/ &_file_Lcat_str_iZ,
	/*0x05a8*/ &_file_LcaveE,
	/*0x05a9*/ &_file_LcaveJ,
	/*0x05aa*/ &_file_LcaveP,
	/*0x05ab*/ &_file_Lcave_str_gZ,
	/*0x05ac*/ &_file_Lcave_str_fZ,
	/*0x05ad*/ &_file_Lcave_str_sZ,
	/*0x05ae*/ &_file_Lcave_str_iZ,
	/*0x05af*/ &_file_LcradE,
	/*0x05b0*/ &_file_LcradJ,
	/*0x05b1*/ &_file_LcradP,
	/*0x05b2*/ &_file_Lcrad_str_gZ,
	/*0x05b3*/ &_file_Lcrad_str_fZ,
	/*0x05b4*/ &_file_Lcrad_str_sZ,
	/*0x05b5*/ &_file_Lcrad_str_iZ,
	/*0x05b6*/ &_file_LcrypE,
	/*0x05b7*/ &_file_LcrypJ,
	/*0x05b8*/ &_file_LcrypP,
	/*0x05b9*/ &_file_Lcryp_str_gZ,
	/*0x05ba*/ &_file_Lcryp_str_fZ,
	/*0x05bb*/ &_file_Lcryp_str_sZ,
	/*0x05bc*/ &_file_Lcryp_str_iZ,
	/*0x05bd*/ &_file_LdamE,
	/*0x05be*/ &_file_LdamJ,
	/*0x05bf*/ &_file_LdamP,
	/*0x05c0*/ &_file_Ldam_str_gZ,
	/*0x05c1*/ &_file_Ldam_str_fZ,
	/*0x05c2*/ &_file_Ldam_str_sZ,
	/*0x05c3*/ &_file_Ldam_str_iZ,
	/*0x05c4*/ &_file_LdepoE,
	/*0x05c5*/ &_file_LdepoJ,
	/*0x05c6*/ &_file_LdepoP,
	/*0x05c7*/ &_file_Ldepo_str_gZ,
	/*0x05c8*/ &_file_Ldepo_str_fZ,
	/*0x05c9*/ &_file_Ldepo_str_sZ,
	/*0x05ca*/ &_file_Ldepo_str_iZ,
	/*0x05cb*/ &_file_LdestE,
	/*0x05cc*/ &_file_LdestJ,
	/*0x05cd*/ &_file_LdestP,
	/*0x05ce*/ &_file_Ldest_str_gZ,
	/*0x05cf*/ &_file_Ldest_str_fZ,
	/*0x05d0*/ &_file_Ldest_str_sZ,
	/*0x05d1*/ &_file_Ldest_str_iZ,
	/*0x05d2*/ &_file_LdishE,
	/*0x05d3*/ &_file_LdishJ,
	/*0x05d4*/ &_file_LdishP,
	/*0x05d5*/ &_file_Ldish_str_gZ,
	/*0x05d6*/ &_file_Ldish_str_fZ,
	/*0x05d7*/ &_file_Ldish_str_sZ,
	/*0x05d8*/ &_file_Ldish_str_iZ,
	/*0x05d9*/ &_file_LearE,
	/*0x05da*/ &_file_LearJ,
	/*0x05db*/ &_file_LearP,
	/*0x05dc*/ &_file_Lear_str_gZ,
	/*0x05dd*/ &_file_Lear_str_fZ,
	/*0x05de*/ &_file_Lear_str_sZ,
	/*0x05df*/ &_file_Lear_str_iZ,
	/*0x05e0*/ &_file_LeldE,
	/*0x05e1*/ &_file_LeldJ,
	/*0x05e2*/ &_file_LeldP,
	/*0x05e3*/ &_file_Leld_str_gZ,
	/*0x05e4*/ &_file_Leld_str_fZ,
	/*0x05e5*/ &_file_Leld_str_sZ,
	/*0x05e6*/ &_file_Leld_str_iZ,
	/*0x05e7*/ &_file_LgunE,
	/*0x05e8*/ &_file_LgunJ,
	/*0x05e9*/ &_file_LgunP,
	/*0x05ea*/ &_file_Lgun_str_gZ,
	/*0x05eb*/ &_file_Lgun_str_fZ,
	/*0x05ec*/ &_file_Lgun_str_sZ,
	/*0x05ed*/ &_file_Lgun_str_iZ,
	/*0x05ee*/ &_file_LimpE,
	/*0x05ef*/ &_file_LimpJ,
	/*0x05f0*/ &_file_LimpP,
	/*0x05f1*/ &_file_Limp_str_gZ,
	/*0x05f2*/ &_file_Limp_str_fZ,
	/*0x05f3*/ &_file_Limp_str_sZ,
	/*0x05f4*/ &_file_Limp_str_iZ,
	/*0x05f5*/ &_file_LjunE,
	/*0x05f6*/ &_file_LjunJ,
	/*0x05f7*/ &_file_LjunP,
	/*0x05f8*/ &_file_Ljun_str_gZ,
	/*0x05f9*/ &_file_Ljun_str_fZ,
	/*0x05fa*/ &_file_Ljun_str_sZ,
	/*0x05fb*/ &_file_Ljun_str_iZ,
	/*0x05fc*/ &_file_LlamE,
	/*0x05fd*/ &_file_LlamJ,
	/*0x05fe*/ &_file_LlamP,
	/*0x05ff*/ &_file_Llam_str_gZ,
	/*0x0600*/ &_file_Llam_str_fZ,
	/*0x0601*/ &_file_Llam_str_sZ,
	/*0x0602*/ &_file_Llam_str_iZ,
	/*0x0603*/ &_file_LleeE,
	/*0x0604*/ &_file_LleeJ,
	/*0x0605*/ &_file_LleeP,
	/*0x0606*/ &_file_Llee_str_gZ,
	/*0x0607*/ &_file_Llee_str_fZ,
	/*0x0608*/ &_file_Llee_str_sZ,
	/*0x0609*/ &_file_Llee_str_iZ,
	/*0x060a*/ &_file_LlenE,
	/*0x060b*/ &_file_LlenJ,
	/*0x060c*/ &_file_LlenP,
	/*0x060d*/ &_file_Llen_str_gZ,
	/*0x060e*/ &_file_Llen_str_fZ,
	/*0x060f*/ &_file_Llen_str_sZ,
	/*0x0610*/ &_file_Llen_str_iZ,
	/*0x0611*/ &_file_LlipE,
	/*0x0612*/ &_file_LlipJ,
	/*0x0613*/ &_file_LlipP,
	/*0x0614*/ &_file_Llip_str_gZ,
	/*0x0615*/ &_file_Llip_str_fZ,
	/*0x0616*/ &_file_Llip_str_sZ,
	/*0x0617*/ &_file_Llip_str_iZ,
	/*0x0618*/ &_file_LlueE,
	/*0x0619*/ &_file_LlueJ,
	/*0x061a*/ &_file_LlueP,
	/*0x061b*/ &_file_Llue_str_gZ,
	/*0x061c*/ &_file_Llue_str_fZ,
	/*0x061d*/ &_file_Llue_str_sZ,
	/*0x061e*/ &_file_Llue_str_iZ,
	/*0x061f*/ &_file_LmiscE,
	/*0x0620*/ &_file_LmiscJ,
	/*0x0621*/ &_file_LmiscP,
	/*0x0622*/ &_file_Lmisc_str_gZ,
	/*0x0623*/ &_file_Lmisc_str_fZ,
	/*0x0624*/ &_file_Lmisc_str_sZ,
	/*0x0625*/ &_file_Lmisc_str_iZ,
	/*0x0626*/ &_file_Lmp10E,
	/*0x0627*/ &_file_Lmp10J,
	/*0x0628*/ &_file_Lmp10P,
	/*0x0629*/ &_file_Lmp10_str_gZ,
	/*0x062a*/ &_file_Lmp10_str_fZ,
	/*0x062b*/ &_file_Lmp10_str_sZ,
	/*0x062c*/ &_file_Lmp10_str_iZ,
	/*0x062d*/ &_file_Lmp11E,
	/*0x062e*/ &_file_Lmp11J,
	/*0x062f*/ &_file_Lmp11P,
	/*0x0630*/ &_file_Lmp11_str_gZ,
	/*0x0631*/ &_file_Lmp11_str_fZ,
	/*0x0632*/ &_file_Lmp11_str_sZ,
	/*0x0633*/ &_file_Lmp11_str_iZ,
	/*0x0634*/ &_file_Lmp12E,
	/*0x0635*/ &_file_Lmp12J,
	/*0x0636*/ &_file_Lmp12P,
	/*0x0637*/ &_file_Lmp12_str_gZ,
	/*0x0638*/ &_file_Lmp12_str_fZ,
	/*0x0639*/ &_file_Lmp12_str_sZ,
	/*0x063a*/ &_file_Lmp12_str_iZ,
	/*0x063b*/ &_file_Lmp13E,
	/*0x063c*/ &_file_Lmp13J,
	/*0x063d*/ &_file_Lmp13P,
	/*0x063e*/ &_file_Lmp13_str_gZ,
	/*0x063f*/ &_file_Lmp13_str_fZ,
	/*0x0640*/ &_file_Lmp13_str_sZ,
	/*0x0641*/ &_file_Lmp13_str_iZ,
	/*0x0642*/ &_file_Lmp14E,
	/*0x0643*/ &_file_Lmp14J,
	/*0x0644*/ &_file_Lmp14P,
	/*0x0645*/ &_file_Lmp14_str_gZ,
	/*0x0646*/ &_file_Lmp14_str_fZ,
	/*0x0647*/ &_file_Lmp14_str_sZ,
	/*0x0648*/ &_file_Lmp14_str_iZ,
	/*0x0649*/ &_file_Lmp15E,
	/*0x064a*/ &_file_Lmp15J,
	/*0x064b*/ &_file_Lmp15P,
	/*0x064c*/ &_file_Lmp15_str_gZ,
	/*0x064d*/ &_file_Lmp15_str_fZ,
	/*0x064e*/ &_file_Lmp15_str_sZ,
	/*0x064f*/ &_file_Lmp15_str_iZ,
	/*0x0650*/ &_file_Lmp16E,
	/*0x0651*/ &_file_Lmp16J,
	/*0x0652*/ &_file_Lmp16P,
	/*0x0653*/ &_file_Lmp16_str_gZ,
	/*0x0654*/ &_file_Lmp16_str_fZ,
	/*0x0655*/ &_file_Lmp16_str_sZ,
	/*0x0656*/ &_file_Lmp16_str_iZ,
	/*0x0657*/ &_file_Lmp17E,
	/*0x0658*/ &_file_Lmp17J,
	/*0x0659*/ &_file_Lmp17P,
	/*0x065a*/ &_file_Lmp17_str_gZ,
	/*0x065b*/ &_file_Lmp17_str_fZ,
	/*0x065c*/ &_file_Lmp17_str_sZ,
	/*0x065d*/ &_file_Lmp17_str_iZ,
	/*0x065e*/ &_file_Lmp18E,
	/*0x065f*/ &_file_Lmp18J,
	/*0x0660*/ &_file_Lmp18P,
	/*0x0661*/ &_file_Lmp18_str_gZ,
	/*0x0662*/ &_file_Lmp18_str_fZ,
	/*0x0663*/ &_file_Lmp18_str_sZ,
	/*0x0664*/ &_file_Lmp18_str_iZ,
	/*0x0665*/ &_file_Lmp19E,
	/*0x0666*/ &_file_Lmp19J,
	/*0x0667*/ &_file_Lmp19P,
	/*0x0668*/ &_file_Lmp19_str_gZ,
	/*0x0669*/ &_file_Lmp19_str_fZ,
	/*0x066a*/ &_file_Lmp19_str_sZ,
	/*0x066b*/ &_file_Lmp19_str_iZ,
	/*0x066c*/ &_file_Lmp1E,
	/*0x066d*/ &_file_Lmp1J,
	/*0x066e*/ &_file_Lmp1P,
	/*0x066f*/ &_file_Lmp1_str_gZ,
	/*0x0670*/ &_file_Lmp1_str_fZ,
	/*0x0671*/ &_file_Lmp1_str_sZ,
	/*0x0672*/ &_file_Lmp1_str_iZ,
	/*0x0673*/ &_file_Lmp20E,
	/*0x0674*/ &_file_Lmp20J,
	/*0x0675*/ &_file_Lmp20P,
	/*0x0676*/ &_file_Lmp20_str_gZ,
	/*0x0677*/ &_file_Lmp20_str_fZ,
	/*0x0678*/ &_file_Lmp20_str_sZ,
	/*0x0679*/ &_file_Lmp20_str_iZ,
	/*0x067a*/ &_file_Lmp2E,
	/*0x067b*/ &_file_Lmp2J,
	/*0x067c*/ &_file_Lmp2P,
	/*0x067d*/ &_file_Lmp2_str_gZ,
	/*0x067e*/ &_file_Lmp2_str_fZ,
	/*0x067f*/ &_file_Lmp2_str_sZ,
	/*0x0680*/ &_file_Lmp2_str_iZ,
	/*0x0681*/ &_file_Lmp3E,
	/*0x0682*/ &_file_Lmp3J,
	/*0x0683*/ &_file_Lmp3P,
	/*0x0684*/ &_file_Lmp3_str_gZ,
	/*0x0685*/ &_file_Lmp3_str_fZ,
	/*0x0686*/ &_file_Lmp3_str_sZ,
	/*0x0687*/ &_file_Lmp3_str_iZ,
	/*0x0688*/ &_file_Lmp4E,
	/*0x0689*/ &_file_Lmp4J,
	/*0x068a*/ &_file_Lmp4P,
	/*0x068b*/ &_file_Lmp4_str_gZ,
	/*0x068c*/ &_file_Lmp4_str_fZ,
	/*0x068d*/ &_file_Lmp4_str_sZ,
	/*0x068e*/ &_file_Lmp4_str_iZ,
	/*0x068f*/ &_file_Lmp5E,
	/*0x0690*/ &_file_Lmp5J,
	/*0x0691*/ &_file_Lmp5P,
	/*0x0692*/ &_file_Lmp5_str_gZ,
	/*0x0693*/ &_file_Lmp5_str_fZ,
	/*0x0694*/ &_file_Lmp5_str_sZ,
	/*0x0695*/ &_file_Lmp5_str_iZ,
	/*0x0696*/ &_file_Lmp6E,
	/*0x0697*/ &_file_Lmp6J,
	/*0x0698*/ &_file_Lmp6P,
	/*0x0699*/ &_file_Lmp6_str_gZ,
	/*0x069a*/ &_file_Lmp6_str_fZ,
	/*0x069b*/ &_file_Lmp6_str_sZ,
	/*0x069c*/ &_file_Lmp6_str_iZ,
	/*0x069d*/ &_file_Lmp7E,
	/*0x069e*/ &_file_Lmp7J,
	/*0x069f*/ &_file_Lmp7P,
	/*0x06a0*/ &_file_Lmp7_str_gZ,
	/*0x06a1*/ &_file_Lmp7_str_fZ,
	/*0x06a2*/ &_file_Lmp7_str_sZ,
	/*0x06a3*/ &_file_Lmp7_str_iZ,
	/*0x06a4*/ &_file_Lmp8E,
	/*0x06a5*/ &_file_Lmp8J,
	/*0x06a6*/ &_file_Lmp8P,
	/*0x06a7*/ &_file_Lmp8_str_gZ,
	/*0x06a8*/ &_file_Lmp8_str_fZ,
	/*0x06a9*/ &_file_Lmp8_str_sZ,
	/*0x06aa*/ &_file_Lmp8_str_iZ,
	/*0x06ab*/ &_file_Lmp9E,
	/*0x06ac*/ &_file_Lmp9J,
	/*0x06ad*/ &_file_Lmp9P,
	/*0x06ae*/ &_file_Lmp9_str_gZ,
	/*0x06af*/ &_file_Lmp9_str_fZ,
	/*0x06b0*/ &_file_Lmp9_str_sZ,
	/*0x06b1*/ &_file_Lmp9_str_iZ,
	/*0x06b2*/ &_file_LmpmenuE,
	/*0x06b3*/ &_file_LmpmenuJ,
	/*0x06b4*/ &_file_LmpmenuP,
	/*0x06b5*/ &_file_Lmpmenu_str_gZ,
	/*0x06b6*/ &_file_Lmpmenu_str_fZ,
	/*0x06b7*/ &_file_Lmpmenu_str_sZ,
	/*0x06b8*/ &_file_Lmpmenu_str_iZ,
	/*0x06b9*/ &_file_LmpweaponsE,
	/*0x06ba*/ &_file_LmpweaponsJ,
	/*0x06bb*/ &_file_LmpweaponsP,
	/*0x06bc*/ &_file_Lmpweapons_str_gZ,
	/*0x06bd*/ &_file_Lmpweapons_str_fZ,
	/*0x06be*/ &_file_Lmpweapons_str_sZ,
	/*0x06bf*/ &_file_Lmpweapons_str_iZ,
	/*0x06c0*/ &_file_LoatE,
	/*0x06c1*/ &_file_LoatJ,
	/*0x06c2*/ &_file_LoatP,
	/*0x06c3*/ &_file_Loat_str_gZ,
	/*0x06c4*/ &_file_Loat_str_fZ,
	/*0x06c5*/ &_file_Loat_str_sZ,
	/*0x06c6*/ &_file_Loat_str_iZ,
	/*0x06c7*/ &_file_LoldE,
	/*0x06c8*/ &_file_LoldJ,
	/*0x06c9*/ &_file_LoldP,
	/*0x06ca*/ &_file_Lold_str_gZ,
	/*0x06cb*/ &_file_Lold_str_fZ,
	/*0x06cc*/ &_file_Lold_str_sZ,
	/*0x06cd*/ &_file_Lold_str_iZ,
	/*0x06ce*/ &_file_LoptionsE,
	/*0x06cf*/ &_file_LoptionsJ,
	/*0x06d0*/ &_file_LoptionsP,
	/*0x06d1*/ &_file_Loptions_str_gZ,
	/*0x06d2*/ &_file_Loptions_str_fZ,
	/*0x06d3*/ &_file_Loptions_str_sZ,
	/*0x06d4*/ &_file_Loptions_str_iZ,
	/*0x06d5*/ &_file_LpamE,
	/*0x06d6*/ &_file_LpamJ,
	/*0x06d7*/ &_file_LpamP,
	/*0x06d8*/ &_file_Lpam_str_gZ,
	/*0x06d9*/ &_file_Lpam_str_fZ,
	/*0x06da*/ &_file_Lpam_str_sZ,
	/*0x06db*/ &_file_Lpam_str_iZ,
	/*0x06dc*/ &_file_LpeteE,
	/*0x06dd*/ &_file_LpeteJ,
	/*0x06de*/ &_file_LpeteP,
	/*0x06df*/ &_file_Lpete_str_gZ,
	/*0x06e0*/ &_file_Lpete_str_fZ,
	/*0x06e1*/ &_file_Lpete_str_sZ,
	/*0x06e2*/ &_file_Lpete_str_iZ,
	/*0x06e3*/ &_file_LpropobjE,
	/*0x06e4*/ &_file_LpropobjJ,
	/*0x06e5*/ &_file_LpropobjP,
	/*0x06e6*/ &_file_Lpropobj_str_gZ,
	/*0x06e7*/ &_file_Lpropobj_str_fZ,
	/*0x06e8*/ &_file_Lpropobj_str_sZ,
	/*0x06e9*/ &_file_Lpropobj_str_iZ,
	/*0x06ea*/ &_file_LrefE,
	/*0x06eb*/ &_file_LrefJ,
	/*0x06ec*/ &_file_LrefP,
	/*0x06ed*/ &_file_Lref_str_gZ,
	/*0x06ee*/ &_file_Lref_str_fZ,
	/*0x06ef*/ &_file_Lref_str_sZ,
	/*0x06f0*/ &_file_Lref_str_iZ,
	/*0x06f1*/ &_file_LritE,
	/*0x06f2*/ &_file_LritJ,
	/*0x06f3*/ &_file_LritP,
	/*0x06f4*/ &_file_Lrit_str_gZ,
	/*0x06f5*/ &_file_Lrit_str_fZ,
	/*0x06f6*/ &_file_Lrit_str_sZ,
	/*0x06f7*/ &_file_Lrit_str_iZ,
	/*0x06f8*/ &_file_LrunE,
	/*0x06f9*/ &_file_LrunJ,
	/*0x06fa*/ &_file_LrunP,
	/*0x06fb*/ &_file_Lrun_str_gZ,
	/*0x06fc*/ &_file_Lrun_str_fZ,
	/*0x06fd*/ &_file_Lrun_str_sZ,
	/*0x06fe*/ &_file_Lrun_str_iZ,
	/*0x06ff*/ &_file_LsevE,
	/*0x0700*/ &_file_LsevJ,
	/*0x0701*/ &_file_LsevP,
	/*0x0702*/ &_file_Lsev_str_gZ,
	/*0x0703*/ &_file_Lsev_str_fZ,
	/*0x0704*/ &_file_Lsev_str_sZ,
	/*0x0705*/ &_file_Lsev_str_iZ,
	/*0x0706*/ &_file_LsevbE,
	/*0x0707*/ &_file_LsevbJ,
	/*0x0708*/ &_file_LsevbP,
	/*0x0709*/ &_file_Lsevb_str_gZ,
	/*0x070a*/ &_file_Lsevb_str_fZ,
	/*0x070b*/ &_file_Lsevb_str_sZ,
	/*0x070c*/ &_file_Lsevb_str_iZ,
	/*0x070d*/ &_file_LsevxE,
	/*0x070e*/ &_file_LsevxJ,
	/*0x070f*/ &_file_LsevxP,
	/*0x0710*/ &_file_Lsevx_str_gZ,
	/*0x0711*/ &_file_Lsevx_str_fZ,
	/*0x0712*/ &_file_Lsevx_str_sZ,
	/*0x0713*/ &_file_Lsevx_str_iZ,
	/*0x0714*/ &_file_LsevxbE,
	/*0x0715*/ &_file_LsevxbJ,
	/*0x0716*/ &_file_LsevxbP,
	/*0x0717*/ &_file_Lsevxb_str_gZ,
	/*0x0718*/ &_file_Lsevxb_str_fZ,
	/*0x0719*/ &_file_Lsevxb_str_sZ,
	/*0x071a*/ &_file_Lsevxb_str_iZ,
	/*0x071b*/ &_file_LshoE,
	/*0x071c*/ &_file_LshoJ,
	/*0x071d*/ &_file_LshoP,
	/*0x071e*/ &_file_Lsho_str_gZ,
	/*0x071f*/ &_file_Lsho_str_fZ,
	/*0x0720*/ &_file_Lsho_str_sZ,
	/*0x0721*/ &_file_Lsho_str_iZ,
	/*0x0722*/ &_file_LsiloE,
	/*0x0723*/ &_file_LsiloJ,
	/*0x0724*/ &_file_LsiloP,
	/*0x0725*/ &_file_Lsilo_str_gZ,
	/*0x0726*/ &_file_Lsilo_str_fZ,
	/*0x0727*/ &_file_Lsilo_str_sZ,
	/*0x0728*/ &_file_Lsilo_str_iZ,
	/*0x0729*/ &_file_LstatE,
	/*0x072a*/ &_file_LstatJ,
	/*0x072b*/ &_file_LstatP,
	/*0x072c*/ &_file_Lstat_str_gZ,
	/*0x072d*/ &_file_Lstat_str_fZ,
	/*0x072e*/ &_file_Lstat_str_sZ,
	/*0x072f*/ &_file_Lstat_str_iZ,
	/*0x0730*/ &_file_LtitleE,
	/*0x0731*/ &_file_LtitleJ,
	/*0x0732*/ &_file_LtitleP,
	/*0x0733*/ &_file_Ltitle_str_gZ,
	/*0x0734*/ &_file_Ltitle_str_fZ,
	/*0x0735*/ &_file_Ltitle_str_sZ,
	/*0x0736*/ &_file_Ltitle_str_iZ,
	/*0x0737*/ &_file_LtraE,
	/*0x0738*/ &_file_LtraJ,
	/*0x0739*/ &_file_LtraP,
	/*0x073a*/ &_file_Ltra_str_gZ,
	/*0x073b*/ &_file_Ltra_str_fZ,
	/*0x073c*/ &_file_Ltra_str_sZ,
	/*0x073d*/ &_file_Ltra_str_iZ,
	/*0x073e*/ &_file_LuffE,
	/*0x073f*/ &_file_LuffJ,
	/*0x0740*/ &_file_LuffP,
	/*0x0741*/ &_file_Luff_str_gZ,
	/*0x0742*/ &_file_Luff_str_fZ,
	/*0x0743*/ &_file_Luff_str_sZ,
	/*0x0744*/ &_file_Luff_str_iZ,
	/*0x0745*/ &_file_LwaxE,
	/*0x0746*/ &_file_LwaxJ,
	/*0x0747*/ &_file_LwaxP,
	/*0x0748*/ &_file_Lwax_str_gZ,
	/*0x0749*/ &_file_Lwax_str_fZ,
	/*0x074a*/ &_file_Lwax_str_sZ,
	/*0x074b*/ &_file_Lwax_str_iZ,
	/*0x074c*/ &_file_Pa51grateZ,
	/*0x074d*/ &_file_GecmmineZ,
	/*0x074e*/ &_file_GcommsuplinkZ,
	/*0x074f*/ &_file_GirscannerZ,
	/*0x0750*/ &_file_Paf1escapedoorZ,
	/*0x0751*/ &_file_PprescapsuleZ,
	/*0x0752*/ &_file_PskedarbridgeZ,
	/*0x0753*/ &_file_Ppelagicdoor2Z,
	/*0x0754*/ &_file_Avault2M,
	/*0x0755*/ &_file_Ap29_12_elM,
	/*0x0756*/ &_file_Pttb_boxZ,
	/*0x0757*/ &_file_PinstfrontdoorZ,
	/*0x0758*/ &_file_Ap14_09_joM,
	/*0x0759*/ &_file_Ap19_07_joM,
	/*0x075a*/ &_file_Ap19_08_joM,
	/*0x075b*/ &_file_PchrlaserZ,
	/*0x075c*/ &_file_PbaftaZ,
	/*0x075d*/ &_file_PchrsonicscrewerZ,
	/*0x075e*/ &_file_PchrlumphammerZ,
	/*0x075f*/ &_file_PskedarbombZ,
	/*0x0760*/ &_file_PexplosivebrickZ,
	/*0x0761*/ &_file_PresearchtapeZ,
	/*0x0762*/ &_file_PziggycardZ,
	/*0x0763*/ &_file_PsafeitemZ,
	/*0x0764*/ &_file_Ghand_elvisZ,
	/*0x0765*/ &_file_Paf1_tableZ,
	/*0x0766*/ &_file_Ghand_a51guardZ,
	/*0x0767*/ &_file_Ghand_ddshockZ,
	/*0x0768*/ &_file_Ghand_blackguardZ,
	/*0x0769*/ &_file_Ghand_ddfodderZ,
	/*0x076a*/ &_file_Ghand_ddbioZ,
	/*0x076b*/ &_file_Ghand_a51airmanZ,
	/*0x076c*/ &_file_Ghand_g5guardZ,
	/*0x076d*/ &_file_Ghand_cisoldierZ,
	/*0x076e*/ &_file_PsensitiveinfoZ,
	/*0x076f*/ &_file_PrussdarZ,
	/*0x0770*/ &_file_PxrayspecsZ,
	/*0x0771*/ &_file_PchreyespyZ,
	/*0x0772*/ &_file_PchrdoordecoderZ,
	/*0x0773*/ &_file_PbriefcaseZ,
	/*0x0774*/ &_file_PsuitcaseZ,
	/*0x0775*/ &_file_PshuttledoorZ,
	/*0x0776*/ &_file_PruinbridgeZ,
	/*0x0777*/ &_file_PsecretindoorZ,
	/*0x0778*/ &_file_PskpuzzleobjectZ,
	/*0x0779*/ &_file_Pa51liftdoorZ,
	/*0x077a*/ &_file_Acicarr06M,
	/*0x077b*/ &_file_Acicarr11M,
	/*0x077c*/ &_file_Acifarr08M,
	/*0x077d*/ &_file_Acifarr12M,
	/*0x077e*/ &_file_Acifema01M,
	/*0x077f*/ &_file_Acifema04M,
	/*0x0780*/ &_file_Acifema07M,
	/*0x0781*/ &_file_Acifema08M,
	/*0x0782*/ &_file_Acifema09M,
	/*0x0783*/ &_file_Acifema14M,
	/*0x0784*/ &_file_Acifost08M,
	/*0x0785*/ &_file_Acifost12M,
	/*0x0786*/ &_file_Acigrim05M,
	/*0x0787*/ &_file_Acigrim06M,
	/*0x0788*/ &_file_Acigrim07M,
	/*0x0789*/ &_file_Acigrim08M,
	/*0x078a*/ &_file_Acigrim09M,
	/*0x078b*/ &_file_Acigrim10M,
	/*0x078c*/ &_file_Acihopk09M,
	/*0x078d*/ &_file_Acihopk11M,
	/*0x078e*/ &_file_Acimale02M,
	/*0x078f*/ &_file_Acimale03M,
	/*0x0790*/ &_file_Acimale07M,
	/*0x0791*/ &_file_Acimale09M,
	/*0x0792*/ &_file_Acimale11M,
	/*0x0793*/ &_file_Acimale13M,
	/*0x0794*/ &_file_Aciroge08M,
	/*0x0795*/ &_file_Aciroge12M,
	/*0x0796*/ &_file_Cdark_negotiatorZ,
	/*0x0797*/ &_file_PcihubZ,
	/*0x0798*/ &_file_Psk_ship_door2Z,
	/*0x0799*/ &_file_Psk_window1Z,
	/*0x079a*/ &_file_Psk_hangardoorb_topZ,
	/*0x079b*/ &_file_Psk_hangardoorb_botZ,
	/*0x079c*/ &_file_Paf1_innerdoorZ,
	/*0x079d*/ &_file_Plaser_postZ,
	/*0x079e*/ &_file_Atrfost01M,
	/*0x079f*/ &_file_Atrfost02M,
	/*0x07a0*/ &_file_Atrfost03M,
	/*0x07a1*/ &_file_Atrcarr09M,
	/*0x07a2*/ &_file_Atrcarr10M,
	/*0x07a3*/ &_file_Atrcarr11M,
	/*0x07a4*/ &_file_Acifarr01M,
	/*0x07a5*/ &_file_Acifarr02M,
	/*0x07a6*/ &_file_Acifarr03M,
	/*0x07a7*/ &_file_Acigrim01M,
	/*0x07a8*/ &_file_Acigrim03M,
	/*0x07a9*/ &_file_Acigrim04M,
	/*0x07aa*/ &_file_Acihopk01M,
	/*0x07ab*/ &_file_Acihopk04M,
	/*0x07ac*/ &_file_Acihopk06M,
	/*0x07ad*/ &_file_Aciroge01M,
	/*0x07ae*/ &_file_Aciroge02M,
	/*0x07af*/ &_file_Atrroge01M,
	/*0x07b0*/ &_file_Acicarr07M,
	/*0x07b1*/ &_file_Acicarr08M,
	/*0x07b2*/ &_file_PtargetampZ,
	/*0x07b3*/ &_file_Psk_liftZ,
	/*0x07b4*/ &_file_PknockknockZ,
	/*0x07b5*/ &_file_PcetandoorZ,
	/*0x07b6*/ &_file_Ajoinst01M,
	/*0x07b7*/ &_file_Ajoinst02M,
	/*0x07b8*/ &_file_Ajoinst03M,
	/*0x07b9*/ &_file_Ajoinst04M,
	/*0x07ba*/ &_file_Ap25_03_joM,
	/*0x07bb*/ &_file_Paf1rubbleZ,
	/*0x07bc*/ &_file_Pdd_dr_nonrefZ,
	/*0x07bd*/ &_file_CheadtimZ,
	/*0x07be*/ &_file_CheadgrantZ,
	/*0x07bf*/ &_file_CheadpennyZ,
	/*0x07c0*/ &_file_CheadrobinZ,
	/*0x07c1*/ &_file_CheadalexZ,
	/*0x07c2*/ &_file_CheadjulianneZ,
	/*0x07c3*/ &_file_CheadlauraZ,
	/*0x07c4*/ &_file_CheaddavecZ,
	/*0x07c5*/ &_file_CheadkenZ,
	/*0x07c6*/ &_file_CheadjoelZ,
	/*0x07c7*/ &_file_PcetandoorsideZ,
	/*0x07c8*/ &_file_Ap29_13_joM,
	/*0x07c9*/ &_file_Ap29_14_joM,
	/*0x07ca*/ &_file_Acicarr09M,
	/*0x07cb*/ &_file_Acicarr10M,
	/*0x07cc*/ &_file_PbuddybridgeZ,
	/*0x07cd*/ &_file_CheadcookZ,
	/*0x07ce*/ &_file_CheadpryceZ,
	/*0x07cf*/ &_file_CheadsilkeZ,
	/*0x07d0*/ &_file_CheadsmithZ,
	/*0x07d1*/ &_file_CheadgarethZ,
	/*0x07d2*/ &_file_CheadmurchieZ,
	/*0x07d3*/ &_file_CheadwongZ,
	/*0x07d4*/ &_file_CheadcarterZ,
	/*0x07d5*/ &_file_CheadtintinZ,
	/*0x07d6*/ &_file_CheadmuntonZ,
	/*0x07d7*/ &_file_CheadstamperZ,
	/*0x07d8*/ &_file_CheadjonesZ,
	/*0x07d9*/ &_file_CheadphelpsZ,
	/*0x07da*/ &_file_Ap29_15_joM,
	/*0x07db*/ &_file_Ap16_03_joM,
	/*0x07dc*/ &_file_Acarrbye02M,
	/*0x07dd*/ &_file_Asaucerexp1M,
	/*0x07de*/ &_filesSegmentRomEnd,
	/*0x07df*/ NULL,
};

u32 var80083fe0 = 0x00010000;
u32 var80083fe4 = 0x00018000;
u32 var80083fe8 = 0x00020000;
u32 var80083fec = 0x00028000;
u32 var80083ff0 = 0x00010000;
u32 var80083ff4 = 0x00018000;
u32 var80083ff8 = 0x00020000;
u32 var80083ffc = 0x00028000;
u32 var80084000 = 0x00000000;
u32 var80084004 = 0x00000001;
u32 var80084008 = 0x00000002;
u32 var8008400c = 0x00000000;
u32 var80084010 = 0;
bool var80084014 = false;
f32 var80084018 = 1;
u32 var8008401c = 0x00000001;

s32 g_Difficulty = 0;

s32 g_MpTimeElapsed = 0;
s32 g_MpTimeLimit = 36000;
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
void *g_MiscAudioHandle = NULL;
s32 var80084038 = 0;
f32 g_Uptime = 0;
bool var80084040 = true;
u32 var80084044 = 0x000005c8;
u32 var80084048 = 0x00008068;
u32 var8008404c = 0x000001c8;
u32 var80084050 = 0;

s16 g_FadeNumFrames = 0;

// 80084058
f32 fade80084058 = -1;
u32 g_FadePrevColor = 0;
u32 g_FadeColor = 0;

// 80084064
u16 fade80084064 = 0;

u32 var80084068 = 0x00000000;
u32 var8008406c = 0x00000000;
u32 var80084070 = 0x00000000;
u32 var80084074 = 0x00000000;
u32 var80084078 = 0x00000000;
u32 var8008407c = 0x00000000;
u32 var80084080 = 0x00000000;
u32 var80084084 = 0x00000000;
u32 var80084088 = 0x00000000;
u32 var8008408c = 0x00000000;
u32 var80084090 = 0x00000000;
u32 var80084094 = 0x1e000000;
u32 var80084098 = 0x00000000;
u32 var8008409c = 0x00000064;
u32 var800840a0 = 0x00000000;
u32 g_CutsceneTime240_60 = 0x00000000;
u32 var800840a8 = 0x00000000;
u32 var800840ac = 0x00000000;
u32 var800840b0 = 0x00000000;
u32 var800840b4 = 0x00000000;
u32 var800840b8 = 0x00000000;
u32 var800840bc = 0x00000000;
u32 var800840c0 = 0xffffffff;
u32 var800840c4 = 0x00000000;
u32 var800840c8 = 0xffffffff;
u32 var800840cc = 0xffffffff;
u32 var800840d0 = 0xffffffff;
u32 var800840d4 = 0x00000000;
u32 var800840d8 = 0x00000000;
u32 var800840dc = 0x00000000;
u32 var800840e0 = 0x0000000f;
u32 var800840e4 = 0x00000000;
u32 var800840e8 = 0x00000000;
u32 var800840ec = 0x50000000;
u32 var800840f0 = 0x00000000;
u32 var800840f4 = 0x00000000;
u32 var800840f8 = 0x00000078;
u32 var800840fc = 0x00000000;
u32 var80084100 = (u32)&var7f1b78c0;
u32 var80084104 = (u32)&var7f1b78c8;
u32 var80084108 = (u32)&var7f1b78d4;
u32 var8008410c = (u32)&var7f1b78f4;
u32 var80084110 = (u32)&var7f1b7900;
u32 var80084114 = (u32)&var7f1b7908;
u32 var80084118 = (u32)&var7f1b7910;
u32 var8008411c = 0x00000000;
u32 g_LanguageId = 0;

// 2a144
u16 g_LangFiles[] = {
	/* 0*/ 0,
	/* 1*/ FILE_LAMEE,
	/* 2*/ FILE_LARCHE,
	/* 3*/ FILE_LARKE,
	/* 4*/ FILE_LASHE,
	/* 5*/ FILE_LAZTE,
	/* 6*/ FILE_LCATE,
	/* 7*/ FILE_LCAVEE,
	/* 8*/ FILE_LARECE,
	/* 9*/ FILE_LCRADE,
	/*10*/ FILE_LCRYPE,
	/*11*/ FILE_LDAME,
	/*12*/ FILE_LDEPOE,
	/*13*/ FILE_LDESTE,
	/*14*/ FILE_LDISHE,
	/*15*/ FILE_LEARE,
	/*16*/ FILE_LELDE,
	/*17*/ FILE_LIMPE,
	/*18*/ FILE_LJUNE,
	/*19*/ FILE_LLEEE,
	/*20*/ FILE_LLENE,
	/*21*/ FILE_LLIPE,
	/*22*/ FILE_LLUEE,
	/*23*/ FILE_LOATE,
	/*24*/ FILE_LPAME,
	/*25*/ FILE_LPETEE,
	/*26*/ FILE_LREFE,
	/*27*/ FILE_LRITE,
	/*28*/ FILE_LRUNE,
	/*29*/ FILE_LSEVBE,
	/*30*/ FILE_LSEVE,
	/*31*/ FILE_LSEVXE,
	/*32*/ FILE_LSEVXBE,
	/*33*/ FILE_LSHOE,
	/*34*/ FILE_LSILOE,
	/*35*/ FILE_LSTATE,
	/*36*/ FILE_LTRAE,
	/*37*/ FILE_LWAXE,
	/*38*/ FILE_LGUNE,
	/*39*/ FILE_LTITLEE,
	/*40*/ FILE_LMPMENUE,
	/*41*/ FILE_LPROPOBJE,
	/*42*/ FILE_LMPWEAPONSE,
	/*43*/ FILE_LOPTIONSE,
	/*44*/ FILE_LMISCE,
	/*45*/ FILE_LUFFE,
	/*46*/ FILE_LOLDE,
	/*47*/ FILE_LATEE,
	/*48*/ FILE_LLAME,
	/*49*/ FILE_LMP1E,
	/*50*/ FILE_LMP2E,
	/*51*/ FILE_LMP3E,
	/*52*/ FILE_LMP4E,
	/*53*/ FILE_LMP5E,
	/*54*/ FILE_LMP6E,
	/*55*/ FILE_LMP7E,
	/*56*/ FILE_LMP8E,
	/*57*/ FILE_LMP9E,
	/*58*/ FILE_LMP10E,
	/*59*/ FILE_LMP11E,
	/*60*/ FILE_LMP12E,
	/*61*/ FILE_LMP13E,
	/*62*/ FILE_LMP14E,
	/*63*/ FILE_LMP15E,
	/*64*/ FILE_LMP16E,
	/*65*/ FILE_LMP17E,
	/*66*/ FILE_LMP18E,
	/*67*/ FILE_LMP19E,
	/*68*/ FILE_LMP20E,
};

u32 var800841b0 = 0x0006ddd0;
u32 var800841b4 = 0x00000000;
u32 var800841b8 = 0x00000004;
u32 var800841bc = 0x00000003;
u32 var800841c0 = 0x00000003;
u32 var800841c4 = 0x00000003;
u32 var800841c8 = 0x00000002;
u32 var800841cc = 0x00000002;
u32 var800841d0 = 0x00000001;
u32 var800841d4 = 0x00000001;
u32 var800841d8 = 0x00000001;
u32 var800841dc = 0x00000001;
u32 var800841e0 = 0x00000001;
u32 var800841e4 = 0x00000001;
u32 var800841e8 = 0x00000001;
u32 var800841ec = 0x00000000;
u32 var800841f0 = 0x00000001;
u32 var800841f4 = 0x00000000;
u32 var800841f8 = 0x00000000;
u32 var800841fc = 0x00000000;
u32 var80084200 = 0x00000000;
u32 var80084204 = 0x00000001;
u32 var80084208 = 0x00000000;
u32 var8008420c = 0x00000000;
u32 var80084210 = 0x00000000;
u32 var80084214 = 0x00000000;
u32 var80084218 = 0x00000000;
u32 var8008421c = 0x00000000;
u32 var80084220 = 0x00000100;
u32 var80084224 = 0x00000020;
u32 var80084228 = 0x00000100;
u32 var8008422c = 0x00000020;
u32 var80084230 = 0x00000100;
u32 var80084234 = 0x00000010;
u32 var80084238 = 0x00000008;
u32 var8008423c = 0x00000100;
u32 var80084240 = 0x00000010;
u32 var80084244 = 0x00000100;
u32 var80084248 = 0x00000010;
u32 var8008424c = 0x00000100;
u32 var80084250 = 0x00000010;
u32 var80084254 = 0x00000020;
u32 var80084258 = 0x00000010;
u32 var8008425c = 0x00000018;
u32 var80084260 = 0x0000000f;
u32 var80084264 = 0x00000010;
u32 var80084268 = 0x00000008;
u32 var8008426c = 0x00000004;
u32 var80084270 = 0x00000008;
u32 var80084274 = 0x00000004;
u32 var80084278 = 0x00000010;
u32 var8008427c = 0x00000010;
u32 var80084280 = 0x00000010;
u32 var80084284 = 0x00000010;
u32 var80084288 = 0x00000000;
u32 var8008428c = 0x00000000;
u32 var80084290 = 0x00000000;
u32 var80084294 = 0x00000000;
u32 var80084298 = 0x00000003;
u32 var8008429c = 0x00000003;
u32 var800842a0 = 0x00000003;
u32 var800842a4 = 0x00000004;
u32 var800842a8 = 0x00000004;
u32 var800842ac = 0x00000002;
u32 var800842b0 = 0x00000002;
u32 var800842b4 = 0x00000002;
u32 var800842b8 = 0x00000002;
u32 var800842bc = 0x00000003;
u32 var800842c0 = 0x00000002;
u32 var800842c4 = 0x00000003;
u32 var800842c8 = 0x00000002;
u32 var800842cc = 0x00000002;
u32 var800842d0 = 0x00000001;
u32 var800842d4 = 0x00000000;
u32 var800842d8 = 0x00000001;
u32 var800842dc = 0x00000000;
u32 var800842e0 = 0x00000001;
u32 var800842e4 = 0x00000000;
u32 var800842e8 = 0x00000001;
u32 var800842ec = 0x00000000;
u32 var800842f0 = 0x00000000;
u32 var800842f4 = 0x00000000;
u32 var800842f8 = 0x00000000;
u32 var800842fc = 0x00000000;
u32 var80084300 = 0x00000000;
u32 var80084304 = 0x00000000;
u32 var80084308 = 0x00000000;
u32 var8008430c = 0x00000000;
u32 var80084310 = 0x00000000;
u32 var80084314 = 0x00008000;
u32 var80084318 = 0x00008000;
u32 var8008431c = 0x0000c000;
u32 var80084320 = 0x0000c000;
u32 var80084324 = 0x00000000;
u32 var80084328 = 0x00000000;
u32 var8008432c = 0x00000000;

u32 var80084330 = 0x80878088;
u32 var80084334 = 0x06000000;

// 2a358
struct something something_2a358 = {
	&var80084330, &var80084334, 0x00020001,
};

u32 var80084344 = 0x80878088;
u32 var80084348 = 0x01000000;

// 2a36c
struct something something_2a36c = {
	&var80084344, &var80084348, 0x00020001,
};

u32 var80084358 = 0x807e807f;
u32 var8008435c = 0x10000000;

// 2a380
struct something something_2a380 = {
	&var80084358, &var8008435c, 0x00020001,
};

u32 var8008436c = 0x8079807b;
u32 var80084370 = 0x11000000;

// 2a394
struct something something_2a394 = {
	&var8008436c, &var80084370, 0x00020001,
};

u32 var80084380 = 0x80770000;
u32 var80084384 = 0x03040500;

// 2a3a8
struct something something_2a3a8 = {
	&var80084380, &var80084384, 0x00010003,
};

u32 var80084394 = 0x807d0000;
u32 var80084398 = 0x01000000;

// 2a3bc
struct something something_2a3bc = {
	&var80084394, &var80084398, 0x00010001,
};

u32 var800843a8 = 0x80848085;
u32 var800843ac = 0x02000000;

// 2a3d0
struct something something_2a3d0 = {
	&var800843a8, &var800843ac, 0x00020001,
};

u32 var800843bc = 0x80818082;
u32 var800843c0 = 0x80830000;
u32 var800843c4 = 0x02000000;

// 2a3e8
struct something something_2a3e8 = {
	&var800843bc, &var800843c4, 0x00030001,
};

u32 var800843d4 = 0x80860000;
u32 var800843d8 = 0x01000000;

// 2a3fc
struct something something_2a3fc = {
	&var800843d4, &var800843d8, 0x00010001,
};

u32 var800843e8 = 0x8089808a;
u32 var800843ec = 0x01060000;

// 2a410
struct something something_2a410 = {
	&var800843e8, &var800843ec, 0x00020002,
};

u32 var800843fc = 0x80760000;
u32 var80084400 = 0x02000000;

// 2a424
struct something something_2a424 = {
	&var800843fc, &var80084400, 0x00010001,
};

u32 var80084410 = 0x80770000;
u32 var80084414 = 0x03040500;

// 2a438
struct something something_2a438 = {
	&var80084410, &var80084414, 0x00010003,
};

// 2a444
struct something something_2a444 = {
	NULL, NULL, 0x00000000,
};

u32 var80084430 = 0x80800000;
u32 var80084434 = 0x00000000;

// 2a458
struct something something_2a458 = {
	&var80084430, &var80084434, 0x00010001,
};

u32 var80084444 = 0x80800000;
u32 var80084448 = 0x00000000;

// 2a46c
struct something something_2a46c = {
	&var80084444, &var80084448, 0x00010001,
};

// 2a478
struct something *somethings[] = {
	/* 0*/ &something_2a358,
	/* 1*/ &something_2a36c,
	/* 2*/ &something_2a380,
	/* 3*/ &something_2a394,
	/* 4*/ &something_2a3a8,
	/* 5*/ &something_2a458,
	/* 6*/ &something_2a3bc,
	/* 7*/ &something_2a3d0,
	/* 8*/ &something_2a3e8,
	/* 9*/ &something_2a3fc,
	/*10*/ &something_2a410,
	/*11*/ &something_2a424,
	/*12*/ &something_2a438,
	/*13*/ &something_2a444,
	/*14*/ &something_2a46c,
};

// 2a4b4
u32 somethingpointers[] = {
	/* 0*/ (u32)&var7f1b7ba0,
	/* 1*/ (u32)&var7f1b7ba8,
	/* 2*/ (u32)&var7f1b7bb0,
	/* 3*/ (u32)&var7f1b7bb8,
	/* 4*/ (u32)&var7f1b7bc0,
	/* 5*/ (u32)&var7f1b7bc8,
	/* 6*/ (u32)&var7f1b7bd8,
	/* 7*/ (u32)&var7f1b7be0,
	/* 8*/ (u32)&var7f1b7be8,
	/* 9*/ (u32)&var7f1b7bec,
	/*10*/ (u32)&var7f1b7bf4,
	/*11*/ (u32)&var7f1b7c00,
	/*12*/ (u32)&var7f1b7c04,
	/*13*/ (u32)&var7f1b7c10,
	/*14*/ (u32)&var7f1b7c18,
};

u32 var800844d0 = 0x00000000;
u32 var800844d4 = 0x00000000;
u32 var800844d8 = 0x00000000;
u32 var800844dc = 0x00000000;
u32 var800844e0 = 0x00000103;
u32 var800844e4 = 0x00000000;
u32 var800844e8 = 0x00000000;
u32 var800844ec = 0x00000000;
u32 var800844f0 = 0x00000000;
u32 var800844f4 = 0x00000000;
u32 var800844f8 = 0x00000000;
u32 var800844fc = 0x00000000;

// 2a520
struct stagemusic stagemusictable[] = {
	// stage,              main theme,           background sfx,          X theme
	{ STAGE_CITRAINING,    MUSIC_CI,             -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_DEFECTION,     MUSIC_DEFECTION,      MUSIC_DDTOWER_SFX,       MUSIC_DEFECTION_X     },
	{ STAGE_INVESTIGATION, MUSIC_INVESTIGATION,  MUSIC_INVESTIGATION_SFX, MUSIC_INVESTIGATION_X },
	{ STAGE_EXTRACTION,    MUSIC_EXTRACTION,     MUSIC_DDTOWER_SFX,       MUSIC_EXTRACTION_X    },
	{ STAGE_VILLA,         MUSIC_VILLA,          MUSIC_OCEAN,             MUSIC_VILLA_X         },
	{ STAGE_CHICAGO,       MUSIC_CHICAGO,        MUSIC_TRAFFIC,           MUSIC_CHICAGO_X       },
	{ STAGE_G5BUILDING,    MUSIC_G5,             MUSIC_TRAFFIC,           MUSIC_G5_X            },
	{ STAGE_INFILTRATION,  MUSIC_INFILTRATION,   MUSIC_INFILTRATION_SFX,  MUSIC_INFILTRATION_X  },
	{ STAGE_RESCUE,        MUSIC_RESCUE,         MUSIC_A51_LOUDSPEAKER1,  MUSIC_RESCUE_X        },
	{ STAGE_ESCAPE,        MUSIC_ESCAPE,         MUSIC_A51_LOUDSPEAKER2,  MUSIC_ESCAPE_X        },
	{ STAGE_AIRBASE,       MUSIC_AIRBASE,        MUSIC_WIND,              MUSIC_AIRBASE_X       },
	{ STAGE_AIRFORCEONE,   MUSIC_AIRFORCEONE,    MUSIC_AIRFORCEONE_SFX,   MUSIC_AIRFORCEONE_X   },
	{ STAGE_CRASHSITE,     MUSIC_CRASHSITE,      MUSIC_CRASHSITE_WIND,    MUSIC_CRASHSITE_X     },
	{ STAGE_PELAGIC,       MUSIC_PELAGIC,        MUSIC_OCEAN,             MUSIC_PELAGIC_X       },
	{ STAGE_DEEPSEA,       MUSIC_DEEPSEA,        MUSIC_DEEPSEA_SFX,       MUSIC_DEEPSEA_X       },
	{ STAGE_DEFENSE,       MUSIC_DEFENSE,        -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_ATTACKSHIP,    MUSIC_ATTACKSHIP,     MUSIC_ATTACKSHIP_SFX,    MUSIC_ATTACKSHIP_X    },
	{ STAGE_SKEDARRUINS,   MUSIC_SKEDARRUINS,    MUSIC_SKEDAR_WIND,       MUSIC_SKEDARRUINS_X   },
	{ STAGE_MBR,           MUSIC_DARK_COMBAT,    MUSIC_DDTOWER_SFX,       MUSIC_DARK_COMBAT     },
	{ STAGE_MAIANSOS,      MUSIC_MAIAN_TEARS,    MUSIC_A51_LOUDSPEAKER2,  MUSIC_MAIAN_TEARS     },
	{ STAGE_RETAKING,      MUSIC_CI_OPERATIVE,   -1,                      MUSIC_CI_OPERATIVE    },
	{ STAGE_WAR,           MUSIC_ALIEN_CONFLICT, MUSIC_SKEDAR_WIND,       MUSIC_ALIEN_CONFLICT  },
	{ STAGE_DUEL,          MUSIC_CREDITS,        -1,                      MUSIC_CREDITS         },
	{ STAGE_CREDITS,       MUSIC_ALIEN_CONFLICT, -1,                      MUSIC_ALIEN_CONFLICT  },
};

u32 var800845c0 = 0x00000000;
u32 var800845c4 = 0x00000000;
u32 var800845c8 = 0x00000000;
u32 var800845cc = 0x00000000;
u32 var800845d0 = 0x497423f0;
u32 var800845d4 = 0x3727c5ac;
s32 var800845d8 = 1;
u32 var800845dc = 0x00000000;
u32 var800845e0 = 0x00000000;
u32 var800845e4 = 0x00000000;
u32 var800845e8 = 0x00000000;
u32 var800845ec = 0x3f800000;
u32 var800845f0 = 0x00000000;
u32 var800845f4 = 0x00000000;
u32 var800845f8 = 0x00000000;
u32 var800845fc = 0x3f800000;
u32 var80084600 = 0x3f800000;
u32 var80084604 = 0x00000000;
u32 var80084608 = 0x00000000;
u32 var8008460c = 0xffffffff;
u32 var80084610 = 0x00000000;
u32 var80084614 = 0x00000000;
u32 var80084618 = 0x00000000;
u32 var8008461c = 0x00000004;
u32 var80084620 = 0x00000000;
u32 var80084624 = 0x00000000;
u32 var80084628 = 0x00000000;
u32 var8008462c = 0x00000000;

// 2a650
struct menu_item g_MpEndGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x02000020, L_MPMENU(291), 0x00000000, NULL }, // "Are you sure?"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(292), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU(293), 0x00000000, menuhandlerMpEndGame }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a6b4
struct menu_dialog g_MpEndGameMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(290), // "End Game"
	g_MpEndGameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a6cc
struct menu_item g_MpPauseControlMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextChallengeName, 0x00000000, menuhandler00178018 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextScenarioName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(162), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Time Limit:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000200, L_MPWEAPONS(163), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Score Limit:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000200, L_MPWEAPONS(164), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Team Score Limit:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(286), (u32)&menutextMatchTime, NULL }, // "Game Time:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, (u32)&menutextPauseOrUnpause, 0x00000000, menuhandlerMpPause },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000024, L_MPMENU(287), 0x00000000, &g_MpEndGameMenuDialog }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a794
struct menu_dialog g_MpPauseControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(285), // "Control"
	g_MpPauseControlMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a7ac
struct menu_item g_MpInventoryMenuItems[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000000, 0x00000078, 0x00000042, menuhandler00106178 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextWeaponDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a7e8
struct menu_dialog g_MpPauseInventoryMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseControlMenuDialog,
};

// 2a800
struct menu_dialog menudialog_2a800 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&menudialog_18d78,
};

// 2a818
struct menu_dialog menudialog_2a818 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&menudialog_18d90,
};

// 2a830
struct menu_item g_MpPlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_PLAYERSTATS, 0, 0x00000000, 0x00000000, 0x00000000, menuhandler00177e00 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a858
struct menu_dialog g_MpPausePlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1783a0,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseInventoryMenuDialog,
};

// 2a870
struct menu_dialog g_MpEndscreenPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1783a0,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a888
struct menu_item g_MpPlayerRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a8b0
struct menu_dialog g_MpPausePlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(276), // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerStatsMenuDialog,
};

// 2a8c8
struct menu_dialog g_MpEndscreenPlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(276), // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerStatsMenuDialog,
};

// 2a8e0
struct menu_item g_MpTeamRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000001, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a908
struct menu_dialog g_MpPauseTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(279), // "Team Ranking"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerRankingMenuDialog,
};

// 2a920
struct menu_dialog g_MpEndscreenTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(279), // "Team Ranking"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

// 2a938
u16 g_OrdinalSuffixes[] = {
	L_MPMENU(264), // "1st"
	L_MPMENU(265), // "2nd"
	L_MPMENU(266), // "3rd"
	L_MPMENU(267), // "4th"
	L_MPMENU(268), // "5th"
	L_MPMENU(269), // "6th"
	L_MPMENU(270), // "7th"
	L_MPMENU(271), // "8th"
	L_MPMENU(272), // "9th"
	L_MPMENU(273), // "10th"
	L_MPMENU(274), // "11th"
	L_MPMENU(275), // "12th"
};

// 2a950
struct menu_item g_MpGameOverMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x01000010, (u32)&mpGetCurrentPlayerName, (u32)&mpMenuTextPlacementWithSuffix, menuhandler001785c4 },
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_MPMENU(261), (u32)&mpMenuTextPlayerTitle, menuhandler00178a94 }, // "Title:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU(262), 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00200210, L_MPMENU(263), 0x00000000, menuhandler001786d8 }, // "Awards:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward1, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward2, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aa18
struct menu_dialog g_MpEndscreenIndividualGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(260), // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

// 2aa30
struct menu_dialog g_MpEndscreenTeamGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(260), // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenTeamRankingMenuDialog,
};

// 2aa48
struct menu_dialog g_MpEndscreenChallengeCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS(165), // "Challenge Completed!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa60
struct menu_dialog g_MpEndscreenChallengeCheatedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(167), // "Challenge Cheated!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa78
struct menu_dialog g_MpEndscreenChallengeFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(166), // "Challenge Failed!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa90
struct menu_item g_MpEndscreenConfirmPlayerNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(250), 0x00000000, NULL }, // "Confirm player name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler00178bf4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aacc
struct menu_dialog g_MpEndscreenConfirmPlayerNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(142), // "Player Name"
	g_MpEndscreenConfirmPlayerNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2aae4
struct menu_item g_MpEndscreenSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(247), 0x00000000, NULL }, // "Save new player and statistics?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x0000002c, L_MPWEAPONS(248), 0x00000000, &g_MpEndscreenConfirmPlayerNameMenuDialog }, // "Save Now"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(249), 0x00000000, NULL }, // "No Thanks!"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ab34
struct menu_dialog g_MpEndscreenSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(246), // "Save Player"
	g_MpEndscreenSavePlayerMenuItems,
	NULL,
	0x00000004,
	NULL,
};

u32 var80084b2c = 0x00000000;

// 2ab50
struct menu_item menuitems_2ab50[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandlerMpDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aba0
struct menu_dialog menudialog_2aba0 = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	menuitems_2ab50,
	NULL,
	0x00000000,
	NULL,
};

// 2abb8
struct mparena g_MpArenas[] = {
	// Stage, unlock, name
	{ STAGE_MP_SKEDAR,     0x00, L_MPMENU(119) },
	{ STAGE_MP_PIPES,      0x00, L_MPMENU(120) },
	{ STAGE_MP_RAVINE,     0x26, L_MPMENU(121) },
	{ STAGE_MP_G5BUILDING, 0x28, L_MPMENU(122) },
	{ STAGE_MP_SEWERS,     0x2c, L_MPMENU(123) },
	{ STAGE_MP_WAREHOUSE,  0x25, L_MPMENU(124) },
	{ STAGE_MP_GRID,       0x29, L_MPMENU(125) },
	{ STAGE_MP_RUINS,      0x2d, L_MPMENU(126) },
	{ STAGE_MP_AREA52,     0x00, L_MPMENU(127) },
	{ STAGE_MP_BASE,       0x2e, L_MPMENU(128) },
	{ STAGE_MP_FORTRESS,   0x30, L_MPMENU(130) },
	{ STAGE_MP_VILLA,      0x2b, L_MPMENU(131) },
	{ STAGE_MP_CARPARK,    0x23, L_MPMENU(132) },
	{ STAGE_MP_TEMPLE,     0x27, L_MPMENU(133) },
	{ STAGE_MP_COMPLEX,    0x24, L_MPMENU(134) },
	{ STAGE_MP_FELICITY,   0x2a, L_MPMENU(135) },
	{ 1,                   0x00, L_MPMENU(136) }, // "Random"
};

// 2ac20
u32 var80084c00[] = {
	0x00000000, 0x50740000, // "Dark"
	0x0000000d, 0x50750000, // "Classic"
	0x00000010, 0x50760000, // "Custom"
};

// 2ac38
u16 g_MpControlStyleLabels[] = {
	L_OPTIONS(239), // "1.1"
	L_OPTIONS(240), // "1.2"
	L_OPTIONS(241), // "1.3"
	L_OPTIONS(242), // "1.4"
};

// 2ac40
u16 g_MpAimModeLabels[] = {
	L_MPMENU(213), // "Hold"
	L_MPMENU(214), // "Toggle"
};

// 2ac44
struct menu_item menuitems_mpsavechr[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(191), 0x00000000, NULL }, // "Your player file is always saved automatically."
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(192), 0x00000000, NULL }, // "Save a copy now?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(193), 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(194), 0x00000000, menuhandlerMpConfirmSaveChr }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aca8
struct menu_dialog g_MpSaveChrMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(190), // "Confirm"
	menuitems_mpsavechr,
	NULL,
	0x00000000,
	NULL,
};

// 2acc0
struct menu_item menuitems_mpsavesetupname[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(189), 0x00000000, NULL }, // "Enter a name for your game setup file:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandlerMpPlayerName },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2acfc
struct menu_dialog menudialog_mpsavesetupname = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(188), // "Game File Name"
	menuitems_mpsavesetupname,
	NULL,
	0x00000000,
	NULL,
};

// 2ad14
struct menu_item menuitems_mpsavesetup[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS(230), (u32)&mpMenuTextSetupName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&pakMenuTextLocationName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(184), 0x00000000, NULL }, // "Do you want to save over your original game file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(185), 0x00000000, menuhandlerMpSaveSetupOverwrite }, // "Save Over Original"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(186), 0x00000000, menuhandlerMpSaveSetupCopy }, // "Save Copy"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(187), 0x00000000, NULL }, // "Do Not Save"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ada0
struct menu_dialog menudialog_mpsavesetup = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(183), // "Save Game Setup"
	menuitems_mpsavesetup,
	NULL,
	0x00000000,
	NULL,
};

// 2adb8
struct menu_item menuitems_mpweapons[] = {
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00020090, L_MPMENU(174), 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000212, L_MPMENU(175), 0x00000000, NULL }, // "Current Weapon Setup:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(176), 0x00000000, menuhandlerMpWeaponSlot }, // "1:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(177), 0x00000001, menuhandlerMpWeaponSlot }, // "2:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(178), 0x00000002, menuhandlerMpWeaponSlot }, // "3:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(179), 0x00000003, menuhandlerMpWeaponSlot }, // "4:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(180), 0x00000004, menuhandlerMpWeaponSlot }, // "5:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(181), 0x00000005, menuhandlerMpWeaponSlot }, // "6:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(182), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aea8
struct menu_dialog menudialog_mpweapons = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(173), // "Weapons"
	menuitems_mpweapons,
	NULL,
	0x00000010,
	NULL,
};

// 2aec0
struct menu_item menuitems_mpweapons2[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020090, L_MPMENU(174), 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(176), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "1:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000002, L_MPMENU(177), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "2:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000002, L_MPMENU(178), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "3:"
	{ MENUITEMTYPE_LABEL,       3, 0x00000002, L_MPMENU(179), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "4:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000002, L_MPMENU(180), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "5:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(182), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2af88
struct menu_dialog menudialog_mpweapons2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(173), // "Weapons"
	menuitems_mpweapons2,
	NULL,
	0x00000010,
	NULL,
};

// 2afa0
struct menu_item menuitems_mpoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(168), 0x00000002, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Pickups"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(169), 0x00000001, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Players"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(170), 0x00000008, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Teams"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(171), 0x00000004, menuhandlerMpDisplayOptionCheckbox }, // "Radar"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(172), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b02c
struct menu_dialog menudialog_mpoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(167), // "Options"
	menuitems_mpoptions,
	NULL,
	0x00000000,
	NULL,
};

// 2b044
struct menu_item menuitems_mpcontrol[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU(200), 0x00000000, menuhandlerMpControlStyle }, // "Control Style"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(201), 0x00000001, menuhandlerMpControlCheckbox }, // "Reverse Pitch"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(202), 0x00000002, menuhandlerMpControlCheckbox }, // "Look Ahead"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(203), 0x00000080, menuhandlerMpControlCheckbox }, // "Head Roll"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(204), 0x00000008, menuhandlerMpControlCheckbox }, // "Auto-Aim"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU(205), 0x00000000, menuhandlerMpAimControl }, // "Aim Control"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(206), 0x00000004, menuhandlerMpControlCheckbox }, // "Sight on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(207), L_AME(0), menuhandlerMpControlCheckbox }, // "Show Target"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(208), L_ARCH(0), menuhandlerMpControlCheckbox }, // "Show Zoom Range"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(209), 0x00000020, menuhandlerMpControlCheckbox }, // "Ammo on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(210), 0x00000040, menuhandlerMpControlCheckbox }, // "Gun Function"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(211), L_ASH(0), menuhandlerMpControlCheckbox }, // "Paintball"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(212), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b184
struct menu_dialog menudialog_mpcontrol = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(199), // "Control"
	menuitems_mpcontrol,
	NULL,
	0x00000000,
	NULL,
};

// 2b19c
struct menu_item menuitems_mpcompletedchallenges[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017a20c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b1c4
struct menu_dialog menudialog_mpcompletedchallenges = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(165), // "Completed Challenges"
	menuitems_mpcompletedchallenges,
	NULL,
	0x00000048,
	NULL,
};

u32 var800851bc = 0x4e806f76;
u32 var800851c0 = 0x7ca688ab;
u32 var800851c4 = 0x95bfa6ad;
u32 var800851c8 = 0xee888700;
u32 var800851cc = 0x5e6d5e7f;
u32 var800851d0 = 0x416c7d95;
u32 var800851d4 = 0x2e280000;

// 2b1f8
struct menu_item menuitems_mpplayerstats[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(146), (u32)&mpMenuTextKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(147), (u32)&mpMenuTextDeaths, NULL }, // "Deaths:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(148), (u32)&mpMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(149), (u32)&mpMenuTextHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(150), (u32)&mpMenuTextAmmoUsed, NULL }, // "Ammo Used:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(151), (u32)&mpMenuTextDamageDealt, NULL }, // "Damage Dealt:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(152), (u32)&mpMenuTextPainReceived, NULL }, // "Pain Received:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(153), (u32)&mpMenuTextGamesPlayed, NULL }, // "Games Played:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(154), (u32)&mpMenuTextGamesWon, NULL }, // "Games Won:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(155), (u32)&mpMenuTextGamesLost, NULL }, // "Games Lost:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(156), (u32)&mpMenuTextTime, NULL }, // "Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(157), (u32)&mpMenuTextDistance, NULL }, // "Distance:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU(158), 0x00000000, NULL }, // "Medals Won:"
	{ MENUITEMTYPE_LABEL,       2, 0x00200000, L_MPMENU(159), (u32)&mpMenuTextMedalAccuracy, menuhandlerMpMedal }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       1, 0x00200000, L_MPMENU(160), (u32)&mpMenuTextMedalHeadShot, menuhandlerMpMedal }, // "Head Shot:"
	{ MENUITEMTYPE_LABEL,       0, 0x00200000, L_MPMENU(161), (u32)&mpMenuTextMedalKillMaster, menuhandlerMpMedal }, // "KillMaster:"
	{ MENUITEMTYPE_LABEL,       3, 0x00200000, L_MPMENU(162), (u32)&mpMenuTextMedalSurvivor, menuhandlerMpMedal }, // "Survivor:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(163), 0x00000000, NULL }, // "Your Title:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextPlayerTitle, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(219), 0x00000000, menuhandlerMpUsernamePassword }, // "USERNAME:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(220), 0x00000000, menuhandlerMpUsernamePassword }, // "PASSWORD:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(164), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b450
struct menu_dialog menudialog_mpplayerstats = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17b360,
	menuitems_mpplayerstats,
	NULL,
	0x00000048,
	&menudialog_mpcompletedchallenges,
};

u32 var80085448 = 0x00000300;
u32 var8008544c = 0x0400ff00;

// 2b470
struct menu_item menuitems_mpcharacter[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004230, (u32)&mpMenuTextBodyName, 0x00000000, NULL },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x00000022, menuhandlerMpCharacterHead },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x0000001b, menuhandlerMpCharacterBody },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b4c0
struct menu_dialog menudialog_mpcharacter = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(143), // "Character"
	menuitems_mpcharacter,
	menudialog0017a174,
	0x00000002,
	NULL,
};

// 2b4d8
struct menu_item menuitems_mpplayername[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017b91c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b500
struct menu_dialog menudialog_mpplayername = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(142), // "Player Name"
	menuitems_mpplayername,
	NULL,
	0x00000000,
	NULL,
};

// 2b518
struct menu_item menuitems_mploadgamesettingstype0[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&func0f17be2c, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b554
struct menu_dialog menudialog_mploadgamesettingstype0 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(139), // "Load Game Settings"
	menuitems_mploadgamesettingstype0,
	NULL,
	0x00000001,
	NULL,
};

// 2b56c
struct menu_item menuitems_mploadgamesettingstype1[] = {
	{ MENUITEMTYPE_CUSTOM,      1, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&func0f17be2c, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b5a8
struct menu_dialog menudialog_mploadgamesettingstype1 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(139), // "Load Game Settings"
	menuitems_mploadgamesettingstype1,
	NULL,
	0x00000000,
	NULL,
};

// 2b5c0
struct menu_item menuitems_mploadplayer[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000000, 0x0000007e, 0x00000042, menuhandler0017bfc0 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPMENU(138), 0x00000000, NULL }, // "B Button to cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b5fc
struct menu_dialog menudialog_mploadplayer = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(137), // "Load Player"
	menuitems_mploadplayer,
	NULL,
	0x00000000,
	NULL,
};

// 2b614
struct menu_item menuitems_mparena[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00020000, 0x00000078, 0x0000004d, menuhandler001791c8 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b63c
struct menu_dialog menudialog_mparena = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(115), // "Arena"
	menuitems_mparena,
	NULL,
	0x00000011,
	NULL,
};

// 2b654
struct menu_item menuitems_mplimits[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU(108), 0x0000003c, menuhandlerMpTimeLimitSlider }, // "Time"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU(109), 0x00000064, menuhandlerMpScoreLimitSlider }, // "Score"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MISC(447), 0x00000190, menuhandlerMpTeamScoreLimitSlider }, // "Team Score"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(110), 0x00000000, menuhandlerMpRestoreScoreDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(111), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b6e0
struct menu_dialog menudialog_mplimits = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(107), // "Limits"
	menuitems_mplimits,
	NULL,
	0x00000010,
	NULL,
};

// 2b6f8
struct menu_item menuitems_mpplayerhandicaps[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, (u32)&func0f17c524, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      1, 0x00020010, (u32)&func0f17c524, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      2, 0x00020010, (u32)&func0f17c524, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      3, 0x00020010, (u32)&func0f17c524, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(110), 0x00000000, menuhandlerMpRestoreHandicapDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(111), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b798
struct menu_dialog menudialog_mpplayerhandicaps = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(184), // "Player Handicaps"
	menuitems_mpplayerhandicaps,
	NULL,
	0x00000010,
	NULL,
};

// 2b7b0
struct menu_item menuitems_mpready[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(106), 0x00000000, NULL }, // "...and waiting"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b7d8
struct menu_dialog g_MpReadyMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(105), // "Ready!"
	menuitems_mpready,
	menudialogMpReady,
	0x00000001,
	NULL,
};

u32 var800857d0 = 0x00000000;
u32 var800857d4 = 0x50670000; // "Normal Simulants"
u32 var800857d8 = 0x00000006;
u32 var800857dc = 0x50680000; // "Special Simulants"

// 2b800
struct menu_item menuitems_mpaddchangesimulant[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00020000, 0x00000078, 0x00000042, menuhandler0017c6a4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextSimulantDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b83c
struct menu_dialog g_MpAddSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(101), // "Add Simulant"
	menuitems_mpaddchangesimulant,
	NULL,
	0x00000011,
	NULL,
};

// 2b854
struct menu_dialog g_MpChangeSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(102), // "Change Simulant"
	menuitems_mpaddchangesimulant,
	menudialogMpSimulant,
	0x00000011,
	NULL,
};

// 2b86c
struct menu_item menuitems_mpsimulantcharacter[] = {
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x00000025, menuhandlerMpSimulantHead },
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x0000001b, menuhandlerMpSimulantBody },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b8a8
struct menu_dialog menudialog_mpsimulantcharacter = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(100), // "Simulant Character"
	menuitems_mpsimulantcharacter,
	menudialog0017ccfc,
	0x00000012,
	NULL,
};

// 2b8c0
struct menu_item menuitems_mpeditsimulant[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(95), 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(96), 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(97), 0x00000000, &menudialog_mpsimulantcharacter }, // "Character..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(98), 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(99), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b94c
struct menu_dialog g_MpEditSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17cfc0,
	menuitems_mpeditsimulant,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

// 2b964
struct menu_item menuitems_mpsimulants[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(84), 0x00000000, menuhandlerMpAddSimulant }, // "Add Simulant..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(85), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "1:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_MPMENU(86), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "2:"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_MPMENU(87), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "3:"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_MPMENU(88), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "4:"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00000000, L_MPMENU(89), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "5:"
	{ MENUITEMTYPE_SELECTABLE,  5, 0x00000000, L_MPMENU(90), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "6:"
	{ MENUITEMTYPE_SELECTABLE,  6, 0x00000000, L_MPMENU(91), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "7:"
	{ MENUITEMTYPE_SELECTABLE,  7, 0x00000000, L_MPMENU(92), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "8:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(93), 0x00000000, menuhandlerMpClearAllSimulants }, // "Clear All"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(94), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ba7c
struct menu_dialog menudialog_mpsimulants = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(83), // "Simulants"
	menuitems_mpsimulants,
	menudialogMpSimulants,
	0x00000010,
	NULL,
};

u32 var80085a74 = 0x00000000;
u32 var80085a78 = 0x00000000;
u32 var80085a7c = 0x00000000;
u32 var80085a80 = 0x00000000;
u8 g_TeamIdsForPairing[] = {0, 1, 2, 3};

// 2baa8
struct menu_item menuitems_mpautoteam[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(76), 0x00000000, menuhandlerMpTwoTeams }, // "Two Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(77), 0x00000000, menuhandlerMpThreeTeams }, // "Three Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(78), 0x00000000, menuhandlerMpFourTeams }, // "Four Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(79), 0x00000000, menuhandlerMpMaximumTeams }, // "Maximum Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(80), 0x00000000, menuhandlerMpHumansVsSimulants }, // "Humans vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(81), 0x00000000, menuhandlerMpHumanSimulantPairs }, // "Human-Simulant Pairs"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(82), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bb5c
struct menu_dialog menudialog_mpautoteam = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(75), // "Auto Team"
	menuitems_mpautoteam,
	NULL,
	0x00000010,
	NULL,
};

// 2bb74
struct menu_item menuitems_mpteamcontrol[] = {
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00020000, L_MPMENU(71), 0x00000002, menuhandlerMpTeamsEnabled }, // "Teams Enabled"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000010, L_MPMENU(72), 0x00000000, menuhandlerMpTeamsLabel }, // "Teams:"
	{ MENUITEMTYPE_DROPDOWN,     0, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     1, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     2, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     3, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     4, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     5, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     6, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     7, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     8, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     9, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    10, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    11, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000004, L_MPMENU(73), 0x00000000, &menudialog_mpautoteam }, // "Auto Team..."
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000008, L_MPMENU(74), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bcf0
struct menu_dialog menudialog_mpteamcontrol = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(70), // "Team Control"
	menuitems_mpteamcontrol,
	NULL,
	0x00000010,
	NULL,
};

u32 var80085ce8 = L_MISC(166); // "Random"
u32 var80085cec = L_MISC(167); // "Select All"
u32 var80085cf0 = L_MISC(168); // "Select None"
u32 var80085cf4 = L_MISC(169); // "Randomize"

// 2bd18
struct menu_item menuitems_2bd18[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00020000, 0x00000078, 0x0000004d, menuhandler0017dc84 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bd40
struct menu_dialog menudialog_2bd40 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextSelectTuneOrTunes,
	menuitems_2bd18,
	menudialogMpSelectTune,
	0x00000010,
	NULL,
};

// 2bd58
struct menu_item menuitems_mpsoundtrack[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(63), 0x00000000, NULL }, // "Current:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(3), (u32)&mpMenuTextCurrentTrack, NULL }, // ""
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, (u32)&mpMenuTextSelectTuneOrTunes, 0x00000000, &menudialog_2bd40 },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00020000, L_MPMENU(64), 0x00000000, menuhandlerMpMultipleTunes }, // "Multiple Tunes"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(65), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bdf8
struct menu_dialog menudialog_mpsoundtrack = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(62), // "Soundtrack"
	menuitems_mpsoundtrack,
	NULL,
	0x00000010,
	NULL,
};

// 2be10
struct menu_item menuitems_mpchangeteamname[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017e06c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2be38
struct menu_dialog g_MpChangeTeamNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(61), // "Change Team Name"
	menuitems_mpchangeteamname,
	NULL,
	0x00000000,
	NULL,
};

// 2be50
struct menu_item menuitems_mpteamnames[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(8), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Red"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(9), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Yellow"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(10), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Blue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(11), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Magenta"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(12), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Cyan"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(13), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Orange"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(14), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Pink"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(15), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Brown"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(60), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bf2c
struct menu_dialog menudialog_mpteamnames = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(59), // "Team Names"
	menuitems_mpteamnames,
	NULL,
	0x00000010,
	NULL,
};

// 2bf44
struct menu_item menuitems_2bf44[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00060000, L_MPMENU(57), 0x00000000, menuhandler0017e38c }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 2bfa8
struct menu_dialog menudialog_2bfa8 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_2bf44,
	menudialog0017e3fc,
	0x00000014,
	NULL,
};

// 2bfc0
struct menu_item menuitems_mpchallengedetails[] = {
	{ MENUITEMTYPE_CUSTOM,     0,                       0x00200000, 0x00000078,       0x0000004d, menuhandler0017e4d4         },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCHALLENGE, 0x00000000, 0x0000007c,       0x00000037, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SEPARATOR,  0,                       0x00000000, 0x00000000,       0x00000000, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPWEAPONS(171), 0x00000000, menuhandlerMpStartChallenge }, // "Start Challenge"
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPMENU(51),     0x00000000, menuhandlerMpAbortChallenge }, // "Abort Challenge"
	{ MENUITEMTYPE_END,        0,                       0x00000000, 0x00000000,       0x00000000, NULL                        },
};

// 2c038
struct menu_dialog menudialog_mpchallengedetails = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	menuitems_mpchallengedetails,
	menudialog0017eb34,
	0x00000808,
	NULL,
};

struct menu_dialog menudialog_mpgamesetup2;

// 2c050
struct menu_dialog menudialog_mpchallengedetails2 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	menuitems_mpchallengedetails,
	menudialog0017eb34,
	0x00000808,
	&menudialog_mpgamesetup2,
};

// 2c068
struct menu_item menuitems_2c068[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU(57), 0x00000000, menuhandler0017ec64 }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 2c0cc
struct menu_dialog menudialog_2c0cc = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_2c068,
	menudialog0017e3fc,
	0x00000004,
	NULL,
};

// 2c0e4
struct menu_item menuitems_mpcombatchallenges2[] = {
	{ MENUITEMTYPE_CUSTOM,      1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c10c
struct menu_dialog menudialog_mpcombatchallenges2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	menuitems_mpcombatchallenges2,
	menudialog0017eb34,
	0x00000000,
	NULL,
};

// 2c124
u16 mplockoptions[4] = {
	L_MPMENU(45), // "None"
	L_MPMENU(46), // "Last Winner"
	L_MPMENU(47), // "Last Loser"
	L_MPMENU(48), // "Random"
};

struct menu_dialog menudialog_mpabort2;

// 2c12c
struct menu_item menuitems_mpstuff[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(41), 0x00000000, &menudialog_mpsoundtrack }, // "Soundtrack"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(42), 0x00000000, &menudialog_mpteamnames }, // "Team Names"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(216), 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPWEAPONS(154), 0x00000000, menuhandlerScreenSplit }, // "Split"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(37), 0x00000000, &menudialog_2aba0 }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(27), 0x00000000, &menudialog_mpabort2 }, // "Abort Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c208
struct menu_dialog menudialog_mpstuff = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(40), // "Stuff"
	menuitems_mpstuff,
	NULL,
	0x00000810,
	&menudialog_mpchallengedetails,
};

// 2c220
struct menu_dialog menudialog_mpstuff2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(40), // "Stuff"
	menuitems_mpstuff,
	NULL,
	0x00000810,
	NULL,
};

// 2c238
struct menu_item menuitems_mpplayersetup4[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, &menudialog_mpplayername }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(31), 0x00000000, &menudialog_mpcharacter }, // "Character"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, &menudialog_mpcontrol }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, &menudialog_mpoptions }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, &menudialog_mpplayerstats }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c2ec
struct menu_dialog menudialog_mpplayersetup4 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000800,
	&menudialog_mpstuff,
};

// 2c304
struct menu_dialog menudialog_mpplayersetup2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000800,
	&menudialog_mpstuff2,
};

// 2c31c
struct menu_dialog menudialog_mpplayersetup3 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000000,
	NULL,
};

// 2c334
struct menu_item menuitems_mpabort2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0017ef30 }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c384
struct menu_dialog menudialog_mpabort2 = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	menuitems_mpabort2,
	NULL,
	0x00000000,
	NULL,
};

struct menu_dialog menudialog_mpscenario;

// 2c39c
struct menu_item menuitems_mpgamesetup3[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, &menudialog_mpscenario }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, &menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, &menudialog_mpweapons }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, &menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, &menudialog_mpplayerhandicaps }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, &menudialog_mpsimulants }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, &menudialog_mpteamcontrol }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, &menudialog_mploadgamesettingstype0 }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c48c
struct menu_dialog menudialog_mpgamesetup3 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpgamesetup3,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup4,
};

// 2c4a4
struct menu_dialog menudialog_mpgamesetup2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpgamesetup3,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup2,
};

// 2c4bc
struct menu_item menuitems_mpquickgo[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, &menudialog_mpplayersetup3 }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, &menudialog_2aba0 }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c520
struct menu_dialog g_MpQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	menuitems_mpquickgo,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

struct menu_dialog menudialog_mpscenario2;

// 2c538
struct menu_item menuitems_mpquickteamgamesetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, &menudialog_mpscenario2 }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, &menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), (u32)&mpMenuTextWeaponSetName, &menudialog_mpweapons2 }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, &menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, menuhandlerQuickTeamSeparator },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(449), 0x00000000, menuhandlerPlayerTeam }, // "Player 1 Team"
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00000000, L_MISC(450), 0x00000000, menuhandlerPlayerTeam }, // "Player 2 Team"
	{ MENUITEMTYPE_DROPDOWN,    2, 0x00000000, L_MISC(451), 0x00000000, menuhandlerPlayerTeam }, // "Player 3 Team"
	{ MENUITEMTYPE_DROPDOWN,    3, 0x00000000, L_MISC(452), 0x00000000, menuhandlerPlayerTeam }, // "Player 4 Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(453), 0x00000000, menuhandlerMpNumberOfSimulants }, // "Number Of Simulants"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(454), 0x00000000, menuhandlerMpSimulantsPerTeam }, // "Simulants Per Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(455), 0x00000000, menuhandler0017f74c }, // "Simulant Difficulty"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC(448), 0x00000000, menuhandlerMpFinishedSetup }, // "Finished Setup"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c6a0
struct menu_dialog g_MpQuickTeamGameSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpquickteamgamesetup,
	NULL,
	0x00000000,
	NULL,
};

// 2c6b8
struct menu_item menuitems_mpquickteam[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(463), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players Only"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00400000, L_MISC(464), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players and Simulants"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00400000, L_MISC(465), 0x00000000, menuhandlerMpQuickTeamOption }, // "Player Teams"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00400000, L_MISC(466), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00400000, L_MISC(467), 0x00000000, menuhandlerMpQuickTeamOption }, // "Player-Simulant Teams"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c744
struct menu_dialog menudialog_mpquickteam = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(462), // "Quick Team"
	menuitems_mpquickteam,
	NULL,
	0x00000004,
	NULL,
};

// 2c75c
struct menu_item menuitems_mpcombatsimulator[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, &menudialog_mpcombatchallenges2 }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, &menudialog_mploadgamesettingstype1 }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, &menudialog_mpquickteam }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandlerMpAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c7c0
struct menu_dialog g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(445), // "Combat Simulator"
	menuitems_mpcombatsimulator,
	menudialogCombatSimulator,
	0x00000004,
	NULL,
};

u32 var800867b8 = 0x00000000;
u32 var800867bc = 0x00000000;

// 2c7e0
u16 mpslowmotionoptions[] = {
	L_MPMENU(240), // "Off"
	L_MPMENU(241), // "On"
	L_MPMENU(242), // "Smart"
	0x0000,
};

// 2c7e8
struct menu_item menuitems_mpcombatoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222), MPOPTION_ONEHITKILLS,       menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223), 0x00000000,                 menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224), MPOPTION_FASTMOVEMENT,      menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225), MPOPTION_DISPLAYTEAM,       menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226), MPOPTION_NORADAR,           menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227), MPOPTION_NOAUTOAIM,         menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(228), MPOPTION_NOPLAYERHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Player Highlight"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(229), MPOPTION_NOPICKUPHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Pickup Highlight"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239), 0x00000000,                 NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
};

// 2c8d8
struct menu_dialog menudialog_mpcombatoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(215), // "Combat Options"
	menuitems_mpcombatoptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

// 2c8f0
struct menu_item menuitems_mpbriefcaseoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,            menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                      menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,           menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,            menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,                menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,              menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,             menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(237),  MPOPTION_HTB_HIGHLIGHTBRIEFCASE, menuhandlerMpCheckboxOption }, // "Highlight Briefcase"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_HTB_SHOWONRADAR,        menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                      NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
};

// 2c9f4
struct menu_dialog menudialog_mpbriefcaseoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(216), // "Briefcase Options"
	menuitems_mpbriefcaseoptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

struct defaultobj *var800869ec = NULL;
u32 var800869f0 = 0x01000008;
u32 var800869f4 = 0x00110000;
u32 var800869f8 = 0x00420001;
u32 var800869fc = 0x00204000;
u32 var80086a00 = 0x00000000;
u32 var80086a04 = 0x00000000;
u32 var80086a08 = 0x00000000;
u32 var80086a0c = 0x3f800000;
u32 var80086a10 = 0x00000000;
u32 var80086a14 = 0x00000000;
u32 var80086a18 = 0x00000000;
u32 var80086a1c = 0x3f800000;
u32 var80086a20 = 0x00000000;
u32 var80086a24 = 0x00000000;
u32 var80086a28 = 0x00000000;
u32 var80086a2c = 0x3f800000;
u32 var80086a30 = 0x00000000;
u32 var80086a34 = 0x00000000;
u32 var80086a38 = 0x00000000;
u32 var80086a3c = 0x000003e8;
u32 var80086a40 = 0xffffff00;
u32 var80086a44 = 0xffffff00;
u32 var80086a48 = 0x0fff0000;
u32 var80086a4c = 0x57000000;
u32 var80086a50 = 0x00ffffff;
u32 var80086a54 = 0x00000000;

// 2ca78
struct menu_item menuitems_mpcaptureoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(236),  MPOPTION_CTC_SHOWONRADAR, menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

// 2cb68
struct menu_dialog menudialog_mpcaptureoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(220), // "Capture Options"
	menuitems_mpcaptureoptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

u32 var80086b60 = 0x01000008;
u32 var80086b64 = 0x00110000;
u32 var80086b68 = 0x00420001;
u32 var80086b6c = 0x00204000;
u32 var80086b70 = 0x00000000;
u32 var80086b74 = 0x00000000;
u32 var80086b78 = 0x00000000;
u32 var80086b7c = 0x3f800000;
u32 var80086b80 = 0x00000000;
u32 var80086b84 = 0x00000000;
u32 var80086b88 = 0x00000000;
u32 var80086b8c = 0x3f800000;
u32 var80086b90 = 0x00000000;
u32 var80086b94 = 0x00000000;
u32 var80086b98 = 0x00000000;
u32 var80086b9c = 0x3f800000;
u32 var80086ba0 = 0x00000000;
u32 var80086ba4 = 0x00000000;
u32 var80086ba8 = 0x00000000;
u32 var80086bac = 0x000003e8;
u32 var80086bb0 = 0xffffff00;
u32 var80086bb4 = 0xffffff00;
u32 var80086bb8 = 0x0fff0000;
u32 var80086bbc = 0x57000000;
u32 var80086bc0 = 0x00ffffff;
u32 var80086bc4 = 0x00000000;

// 2cbe8
struct menu_item menuitems_mphilloptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(233),  MPOPTION_KOH_HILLONRADAR, menuhandlerMpCheckboxOption }, // "Hill on Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(234),  MPOPTION_KOH_MOBILEHILL,  menuhandlerMpCheckboxOption }, // "Mobile Hill"
	{ MENUITEMTYPE_SLIDER,     0, 0x00020000, L_MPMENU(235),  0x0000006e,               menuhandlerMpHillTime       }, // "Time"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

// 2cd00
struct menu_dialog menudialog_mphilloptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(219), // "Hill Options"
	menuitems_mphilloptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

// 2cd18
struct menu_item menuitems_mphackeroptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,           menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                     menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,          menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,           menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,               menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,             menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,            menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(231),  MPOPTION_HTM_HIGHLIGHTTERMINAL, menuhandlerMpCheckboxOption }, // "Highlight Terminal"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_HTM_SHOWONRADAR,       menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                     NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
};

// 2ce1c
struct menu_dialog menudialog_mphackeroptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(217), // "Hacker Options"
	menuitems_mphackeroptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

u32 var80086e14 = 0x02000008;
u32 var80086e18 = 0x00130000;
u32 var80086e1c = 0x00420001;
u32 var80086e20 = 0x00204000;
u32 var80086e24 = 0x00000000;
u32 var80086e28 = 0x00000000;
u32 var80086e2c = 0x00000000;
u32 var80086e30 = 0x3f800000;
u32 var80086e34 = 0x00000000;
u32 var80086e38 = 0x00000000;
u32 var80086e3c = 0x00000000;
u32 var80086e40 = 0x3f800000;
u32 var80086e44 = 0x00000000;
u32 var80086e48 = 0x00000000;
u32 var80086e4c = 0x00000000;
u32 var80086e50 = 0x3f800000;
u32 var80086e54 = 0x00000000;
u32 var80086e58 = 0x00000000;
u32 var80086e5c = 0x00000000;
u32 var80086e60 = 0x000003e8;
u32 var80086e64 = 0xffffff00;
u32 var80086e68 = 0xffffff00;
u32 var80086e6c = 0x0fff0000;
u32 var80086e70 = 0x36000000;
u32 var80086e74 = 0x00ffffff;
u32 var80086e78 = 0x00000000;

// 2ce9c
struct menu_item menuitems_mppopacapoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,         menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                   menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,        menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,         menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,             menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,           menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,          menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(230),  MPOPTION_PAC_HIGHLIGHTTARGET, menuhandlerMpCheckboxOption }, // "Highlight Target"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_PAC_SHOWONRADAR,     menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                   NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
};

// 2cfa0
struct menu_dialog menudialog_mppopacapoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(218), // "Pop a Cap Options"
	menuitems_mppopacapoptions,
	menudialog00184ec0,
	0x00000010,
	NULL,
};

// 2cfb8
struct mpscenario g_MpScenarios[] = {
	{ &menudialog_mpcombatoptions,    NULL,            NULL,                  NULL,             NULL,                  NULL,                  NULL,                  NULL,            NULL,             NULL,              NULL,                 NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mpbriefcaseoptions, scenarioHtbInit, scenarioHtbCallback08, scenarioHtbReset, scenarioHtbCallback10, scenarioHtbCallback14, scenarioHtbCallback18, scenarioHtbKill, scenarioHtbRadar, scenarioHtbRadar2, scenarioHtbHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mphackeroptions,    scenarioHtmInit, scenarioHtmCallback08, scenarioHtmReset, scenarioHtmCallback10, scenarioHtmCallback14, scenarioHtmCallback18, scenarioHtmKill, scenarioHtmRadar, scenarioHtmRadar2, scenarioHtmHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mppopacapoptions,   scenarioPacInit, NULL,                  scenarioPacReset, scenarioPacCallback10, NULL,                  scenarioPacCallback18, scenarioPacKill, scenarioPacRadar, scenarioPacRadar2, scenarioPacHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mphilloptions,      scenarioKohInit, NULL,                  scenarioKohReset, scenarioKohCallback10, NULL,                  scenarioKohCallback18, scenarioKohKill, scenarioKohRadar, NULL,              NULL,                 NULL,                  NULL,                   scenarioKohIsRoomHighlighted, scenarioKohCallback38, NULL, scenarioKohCallback40, scenarioKohCallback44 },
	{ &menudialog_mpcaptureoptions,   scenarioCtcInit, scenarioCtcCallback08, scenarioCtcReset, scenarioCtcCallback10, scenarioCtcCallback14, NULL,                  scenarioCtcKill, scenarioCtcRadar, scenarioCtcRadar2, scenarioCtcHighlight, scenarioCtcCallback2c, scenarioCtcGetMaxTeams, scenarioCtcIsRoomHighlighted, scenarioCtcCallback38, NULL, NULL,                  NULL                  },
};

// 2d168
struct mpscenariooverview g_MpScenarioOverviews[] = {
	// Full name, short name, unlock flags?
	{ L_MPMENU(246), L_MPMENU(253), 0x00, false }, // "Combat", "Combat"
	{ L_MPMENU(247), L_MPMENU(254), 0x20, false }, // "Hold the Briefcase", "Briefcase"
	{ L_MPMENU(248), L_MPMENU(255), 0x4e, false }, // "Hacker Central", "Hacker"
	{ L_MPMENU(249), L_MPMENU(256), 0x4d, false }, // "Pop a Cap", "Pop"
	{ L_MPMENU(250), L_MPMENU(257), 0x1f, true  }, // "King of the Hill", "Hill"
	{ L_MPMENU(251), L_MPMENU(258), 0x21, true  }, // "Capture the Case", "Capture"
};

u32 var8008716c = 0x00000000;
u32 var80087170 = 0x50f40000; // "Free for All!"
u32 var80087174 = 0x00000004;
u32 var80087178 = 0x50f50000; // "-Teamwork-"

// 2d19c
struct menu_item menuitems_mpscenario[] = {
	 { MENUITEMTYPE_CUSTOM,      0, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2d1c4
struct menu_dialog menudialog_mpscenario = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(243), // "Scenario"
	menuitems_mpscenario,
	NULL,
	0x00000011,
	NULL,
};

// 2d1dc
struct menu_item menuitems_mpscenario2[] = {
	 { MENUITEMTYPE_CUSTOM,      1, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2d204
struct menu_dialog menudialog_mpscenario2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(243), // "Scenario"
	menuitems_mpscenario2,
	NULL,
	0x00000011,
	NULL,
};

u32 var800871fc = 0x01000003;
u32 var80087200 = 0x0020ffff;
u32 var80087204 = 0x00000000;
u32 var80087208 = 0x00000000;
u32 var8008720c = 0x00000000;
u32 var80087210 = 0x00000000;
u32 var80087214 = 0x00000000;
u32 var80087218 = 0x3f800000;
u32 var8008721c = 0x00000000;
u32 var80087220 = 0x00000000;
u32 var80087224 = 0x00000000;
u32 var80087228 = 0x3f800000;
u32 var8008722c = 0x00000000;
u32 var80087230 = 0x00000000;
u32 var80087234 = 0x00000000;
u32 var80087238 = 0x3f800000;
u32 var8008723c = 0x00000000;
u32 var80087240 = 0x00000000;
u32 var80087244 = 0x00000000;
u32 var80087248 = 0x000003e8;
u32 var8008724c = 0xffffff00;
u32 var80087250 = 0xffffff00;
u32 var80087254 = 0x0fff0000;
u32 var80087258 = 0x00000000;
u32 var8008725c = 0x00000000;
s32 var80087260 = 0x00000000;
u32 var80087264 = 0x00000000;

// 2d288
struct mpweapon mpweaponstable[] = {
	/*0x00*/ { WEAPON_NONE,             0x00, 0x00, 0x00, 0x0080, MODEL_CHRTT33,          0x01, 0x00 },
	/*0x01*/ { WEAPON_FALCON2,          0x01, 0x50, 0x00, 0x0080, MODEL_CHRFALCON2,       0x01, 0x00 },
	/*0x02*/ { WEAPON_FALCON2_SILENCER, 0x01, 0x50, 0x00, 0x0085, MODEL_CHRFALCON2SIL,    0x01, 0x00 },
	/*0x03*/ { WEAPON_FALCON2_SCOPE,    0x01, 0x50, 0x00, 0x0086, MODEL_CHRFALCON2SCOPE,  0x01, 0x00 },
	/*0x04*/ { WEAPON_MAGSEC4,          0x01, 0x50, 0x00, 0x0080, MODEL_CHRLEEGUN1,       0x01, 0x00 },
	/*0x05*/ { WEAPON_MAULER,           0x01, 0x5c, 0x00, 0x0087, MODEL_CHRMAULER,        0x01, 0x00 },
	/*0x06*/ { WEAPON_PHOENIX,          0x01, 0x40, 0x00, 0x0088, MODEL_CHRMAIANPISTOL,   0x01, 0x00 },
	/*0x07*/ { WEAPON_DY357MAGNUM,      0x0a, 0x32, 0x00, 0x0080, MODEL_CHRDY357,         0x01, 0x00 },
	/*0x08*/ { WEAPON_DY357LX,          0x0a, 0x32, 0x00, 0x0089, MODEL_CHRDY357TRENT,    0x01, 0x00 },
	/*0x09*/ { WEAPON_CMP150,           0x02, 0x64, 0x00, 0x0080, MODEL_CHRCMP150,        0x01, 0x00 },
	/*0x0a*/ { WEAPON_CYCLONE,          0x02, 0x96, 0x00, 0x0080, MODEL_CHRCYCLONE,       0x01, 0x00 },
	/*0x0b*/ { WEAPON_CALLISTONTG,      0x02, 0x96, 0x00, 0x008a, MODEL_CHRMAIANSMG,      0x01, 0x00 },
	/*0x0c*/ { WEAPON_RCP120,           0x02, 0x96, 0x00, 0x008d, MODEL_CHRRCP120,        0x01, 0x00 },
	/*0x0d*/ { WEAPON_LAPTOPGUN,        0x02, 0x96, 0x00, 0x008b, MODEL_CHRPCGUN,         0x01, 0x00 },
	/*0x0e*/ { WEAPON_DRAGON,           0x04, 0x96, 0x00, 0x0080, MODEL_CHRDRAGON,        0x01, 0x00 },
	/*0x0f*/ { WEAPON_K7AVENGER,        0x04, 0x96, 0x00, 0x008c, MODEL_CHRAVENGER,       0x01, 0x00 },
	/*0x10*/ { WEAPON_AR34,             0x04, 0x64, 0x00, 0x0080, MODEL_CHRAR34,          0x01, 0x00 },
	/*0x11*/ { WEAPON_SUPERDRAGON,      0x04, 0x96, 0x0b, 0x1083, MODEL_CHRSUPERDRAGON,   0x01, 0x00 },
	/*0x12*/ { WEAPON_SHOTGUN,          0x05, 0x10, 0x00, 0x008e, MODEL_CHRSHOTGUN,       0x01, 0x00 },
	/*0x13*/ { WEAPON_REAPER,           0x0f, 0xc8, 0x00, 0x008f, MODEL_CHRSKMINIGUN,     0x01, 0x00 },
	/*0x14*/ { WEAPON_SNIPERRIFLE,      0x04, 0x32, 0x00, 0x0080, MODEL_CHRSNIPERRIFLE,   0x01, 0x00 },
	/*0x15*/ { WEAPON_FARSIGHTXR20,     0x06, 0x0a, 0x00, 0x0081, MODEL_CHRZ2020,         0x01, 0x00 },
	/*0x16*/ { WEAPON_DEVASTATOR,       0x0b, 0x10, 0x00, 0x0090, MODEL_CHRDEVASTATOR,    0x01, 0x00 },
	/*0x17*/ { WEAPON_ROCKETLAUNCHER,   0x08, 0x03, 0x00, 0x0080, MODEL_CHRDYROCKET,      0x01, 0x00 },
	/*0x18*/ { WEAPON_SLAYER,           0x08, 0x03, 0x00, 0x0084, MODEL_CHRSKROCKET,      0x01, 0x00 },
	/*0x19*/ { WEAPON_COMBATKNIFE,      0x09, 0x05, 0x00, 0x0080, MODEL_CHRKNIFE,         0x01, 0x00 },
	/*0x1a*/ { WEAPON_CROSSBOW,         0x03, 0x0a, 0x00, 0x0091, MODEL_CHRCROSSBOW,      0x01, 0x00 },
	/*0x1b*/ { WEAPON_TRANQUILIZER,     0x13, 0x32, 0x00, 0x0082, MODEL_CHRDRUGGUN,       0x01, 0x00 },
	/*0x1c*/ { WEAPON_GRENADE,          0x07, 0x05, 0x00, 0x0000, MODEL_CHRGRENADE,       0x01, 0x00 },
	/*0x1d*/ { WEAPON_NBOMB,            0x12, 0x03, 0x00, 0x0012, MODEL_CHRNBOMB,         0x01, 0x00 },
	/*0x1e*/ { WEAPON_TIMEDMINE,        0x0e, 0x05, 0x00, 0x0000, MODEL_CHRTIMEDMINE,     0x01, 0x80 },
	/*0x1f*/ { WEAPON_PROXIMITYMINE,    0x0d, 0x05, 0x00, 0x0013, MODEL_CHRPROXIMITYMINE, 0x01, 0x80 },
	/*0x20*/ { WEAPON_REMOTEMINE,       0x0c, 0x05, 0x00, 0x0014, MODEL_CHRREMOTEMINE,    0x01, 0x80 },
	/*0x21*/ { WEAPON_LASER,            0x00, 0x00, 0x00, 0x00cf, MODEL_CHRLASER,         0x02, 0x00 },
	/*0x22*/ { WEAPON_XRAYSCANNER,      0x00, 0x00, 0x00, 0x0095, MODEL_CHRNIGHTSIGHT,    0x01, 0x00 },
	/*0x23*/ { WEAPON_CLOAKINGDEVICE,   0x00, 0x00, 0x00, 0x0097, MODEL_CHRCLOAKER,       0x01, 0x00 },
	/*0x24*/ { WEAPON_COMBATBOOST,      0x00, 0x00, 0x00, 0x0098, MODEL_CHRSPEEDPILL,     0x01, 0x00 },
	/*0x25*/ { WEAPON_MPSHIELD,         0x00, 0x00, 0x00, 0x0096, MODEL_CHRSHIELD,        0x01, 0x00 },
	/*0x26*/ { WEAPON_DISABLED,         0x00, 0x00, 0x00, 0x0000, 0,                      0x00, 0x00 },
};
