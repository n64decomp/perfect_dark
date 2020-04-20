# User configurable

ROMID ?= ntsc-final
PIRACYCHECKS ?= 1

QEMU_IRIX ?= tools/irix/qemu-irix
IRIX_ROOT ?= tools/irix/root

################################################################################

export ROMID

NTSC=0
PAL=0
JAP=0

ifeq ($(ROMID),ntsc-beta)
	NTSC=1
	VERSION=0
endif
ifeq ($(ROMID),ntsc-1.0)
	NTSC=1
	VERSION=1
endif
ifeq ($(ROMID),ntsc-final)
	NTSC=1
	VERSION=2
endif
ifeq ($(ROMID),pal-beta)
	PAL=1
	VERSION=3
endif
ifeq ($(ROMID),pal-final)
	PAL=1
	VERSION=4
endif
ifeq ($(ROMID),jap-final)
	JAP=1
	VERSION=5
endif

E_DIR := extracted/$(ROMID)
B_DIR := build/$(ROMID)

ifeq ($(shell type mips64-elf-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips64-elf
else ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips-linux-gnu
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips64-linux-gnu
else
    TOOLCHAIN := mips-elf
endif

CFLAGS := -DVERSION=$(VERSION) \
	-DNTSC=$(NTSC) \
	-DPAL=$(PAL) \
	-DJAP=$(JAP) \
	-DPIRACYCHECKS=$(PIRACYCHECKS) \
	-Wo,-loopunroll,0 \
	-Wab,-r4300_mul \
	-non_shared \
	-G 0 \
	-Xcpluscomm \
	-woff 581,649,819,820,821,838,852 \
	-w2 \
	-I src/include \
	-mips2

C_FILES := $(shell find src/boot src/lib src/game src/inflate src/gvars -name '*.c')
O_FILES := $(patsubst src/%.c, $(B_DIR)/%.o, $(C_FILES))

ASSET_AUDIO_FILES := Arecep01M Arecep02M Arecep03M Arecep04M Arecep05M Arecep06M Arlguard1M Arltech01M Arltech02M Arltech03M Arltech04M Arltech05M Arltech06M Ascie2aM Ascie2bM Ascie2cM Ascie2dM Ascie2eM Ascie2fM Ascie2gM Ascie3aM Ascie3bM Ascie3cM Ascie3dM Ascie3eM Ascie3gM Ascien10aM Ascien2_aM Ascien3_aM Ascien4_aM Ascien5_aM Ascien6_aM Ascien7_aM Ascien9_aM AvilgrimM Awepgd01M Awepgd02M Awepgd03M Awepsc01M Awepsc02M Awepsc03M Aa51elv01M Aa51elv02M Aa51elv03M Aa51grd01M Aa51grd02M Aa51grd03M Aa51grd04M Aa51grd05M Aa51grd06M Aa51grd07M Aa51grd08M Aa51grd09M Aa51grd10M Aa51jo1M Aa51jo2M Aa51jo3M Aa51jo4M Aa51jo5M Aa51jo6M Aa51jon01M Aa51jon02M Aa51jon03M Aa51jon04M Aa51jon05M Aa51jon06M Aa51jon07M Aa51jon08M Aa51jon09M Aa51jon10M Aa51jon11M Aa51jon12M Aa51jon14M Aa51jon15M Aa51sci1M Aaf1jo01M Aaf1jo02M Aaf1jo03M Aaf1pr01M Aaf1pr02M Aaf1pr03M Aaf1pr04M Aaf1pr05M Aaf1pr06M Aaf1pr07M Aaf1pr08M Aaf1pr09M Aaf1pr10M Aaf1tr01M Aaf1tr02M Aaf1tr03M Aairbgd01M Aairbgd02M Aairbgd03M Aairbgd04M Aairbgd05M Aairbgd06M Aairbgd07M Aairbgd08M Aairbgd09M Aairbgd10M Aairbgd11M Aairbgd12M Aairbgd13M Aairbgd14M Aairbgd15M Aairbgd16M Aairstw01M Aairstw02M Aairstw03M Aassael01M Aassael02M Aassael03M Aassael04M Aassael05M Aassael06M Absewrk01M Absewrk02M Absewrk03M Absewrk04M Absewrk05M Acetael01M Achdroid1M Achdroid2M Acsec01M Acsec02M Acsec03M Acstan1M Acstan2M Adevr01M Adevr02M Adevr03M Adevr04M Adevr05M Adevr06M Adevr07M Adevr08M Adevr09M Adevr10M Adevr11M Adevr12M Aexec01M Aexec02M Aexec04M Aexec05M Aexec06M Aexec07M Aexec08M Aexec09M Aexec10M Aexec11M Aexec12M Aexec13M Aexec14M Ahelic01M Ahelic02M Ahelic03M Ahologd01M AholohopkM Ainvcar01M Ainvcar02M Ainvcar03M Ainvcar04M Ainvcar05M Ainvcar06M Ainvcar07M Ainvcar08M Ainvcar09M Ainvcar10M Ainvcar11M Ainvcar12M AinvfarrM AinvfemaM AinvfostM AinvgrimM AinvhopkM AinvmaleM Ajoexec01M Ajoexec02M Ajosci01M Ajosci02M Ajosci03M Alabacc1M Alabacc2M Alabacc3M Alabacc4M Alabacc5M Alabacc6M Alabtech1M Alabtech2M Alabtech3M Alabtech5M Alabtech6M Alabtech7M Alabtech8M Alabtech9M Aoffwrk01M Aoffwrk02M Aoffwrk03M Aoffwrk04M Am1_l1_aM Am1_l1_bM Am1_l1_cM Am1_l1_dM Am1_l2_aM Am1_l2_bM Am1_l2_cM Am1_l2_dM Am1_l3_aM Am1_l3_bM Am1_l3_cM Am1_l3_dM Am2_l1_aM Am2_l1_bM Am2_l1_cM Am2_l1_dM Am3_l1_aM Am3_l1_bM Am3_l1_cM Am3_l1_dM Am3_l2_aM Am3_l2_bM Am3_l2_cM Am3_l2_dM Am4_l1_aM Am4_l1_bM Am4_l1_cM Am4_l1_dM Am4_l2_aM Am4_l2_bM Am4_l2_cM Am4_l2_dM Am4_l3_aM Am4_l3_bM Am4_l3_cM Am4_l3_dM Am5_l1_aM Am5_l1_bM Am5_l1_cM Am5_l1_dM Am5_l2_aM Am5_l2_bM Am5_l2_cM Am5_l2_dM Am5_l3_aM Am5_l3_bM Am5_l3_cM Am5_l3_dM Am6_l1_aM Am6_l1_bM Am6_l1_cM Am6_l1_dM Am6_l2_aM Am6_l2_bM Am6_l2_cM Am6_l2_dM Am7_l1_aM Am7_l1_bM Am7_l1_cM Am7_l1_dM Am8_l1_aM Am8_l1_bM Am8_l1_cM Am8_l1_dM Am9_l1_aM Am9_l1_bM Am9_l1_cM Am9_l1_dM Ap1_01_joM Ap1_02_caM Ap1_03_joM Ap1_04_caM Ap1_05_joM Ap1_06_caM Ap1_07_joM Ap1_08_caM Ap2_01_joM Ap2_02_joM Ap2_03_drM Ap2_04_joM Ap2_05_joM Ap2_06_drM Ap2_07_drM Ap3_01_gdM Ap3_02_joM Ap3_03_joM Ap4_01_dvM Ap4_02_joM Ap4_03_dvM Ap4_04_joM Ap4_05_dvM Ap4_06_joM Ap4_07_blM Ap4_08_dvM Ap4_09_dvM Ap5_01_joM Ap5_02_joM Ap5_03_joM Ap6_01_joM Ap6_02_caM Ap6_03_joM Ap6_04_caM Ap6_05_joM Ap6_06_caM Ap7_01_caM Ap7_02_joM Ap7_03_caM Ap7_04_joM Ap8_01_dvM Ap8_02_blM Ap8_03_dvM Ap8_04_blM Ap8_06_blM Ap8_07_trM Ap8_08_dvM Ap8_09_trM Ap8_10_blM Ap9_01_joM Ap9_02_caM Ap9_03_joM Ap10_01_caM Ap10_02_caM Ap10_03_caM Ap10_04_caM Ap10_05_joM Ap10_06_caM Ap10_07_joM Ap10_08_caM Ap10_09_joM Ap11_01_jnM Ap11_02_joM Ap11_03_jnM Ap11_04_joM Ap11_05_jnM Ap11_06_joM Ap11_07_jnM Ap11_08_joM Ap12_01_jnM Ap12_02_joM Ap12_03_jnM Ap12_04_joM Ap12_05_jnM Ap12_06_joM Ap12_07_jnM Ap12_08_joM Ap12_09_jnM Ap12_10_joM Ap13_01_joM Ap13_02_suM Ap13_03_joM Ap13_04_suM Ap13_06_suM Ap14_03_suM Ap14_04_joM Ap14_05_suM Ap14_07_joM Ap15_01_elM Ap15_02_elM Ap15_03_joM Ap15_04_jnM Ap15_05_elM Ap15_06_joM Ap15_07_elM Ap15_08_joM Ap15_09_elM Ap15_10_joM Ap15_11_elM Ap16_01_joM Ap16_02_caM Ap16_04_caM Ap16_05_joM Ap16_06_caM Ap17_01_trM Ap17_02_prM Ap17_03_trM Ap17_04_prM Ap17_05_trM Ap17_06_trM Ap18_01_joM Ap18_02_elM Ap18_03_elM Ap18_04_joM Ap18_05_elM Ap19_01_caM Ap19_02_caM Ap19_03_joM Ap19_04_caM Ap19_05_joM Ap19_06_joM Ap20_01_joM Ap20_02_prM Ap20_03_joM Ap20_04_prM Ap20_05_joM Ap20_06_blM Ap20_07_trM Ap20_08_trM Ap21_01_elM Ap21_02_joM Ap21_03_elM Ap21_04_joM Ap22_01_elM Ap22_02_joM Ap22_03_elM Ap22_04_joM Ap23_01_joM Ap23_02_drM Ap23_03_joM Ap23_04_drM Ap23_05_joM Ap23_06_drM Ap23_07_joM Ap23_08_drM Ap24_01_caM Ap24_02_joM Ap24_03_caM Ap24_04_joM Ap24_05_caM Ap24_06_caM Ap24_07_joM Ap24_08_joM Ap25_01_joM Ap25_02_joM Ap26_01_joM Ap26_02_dvM Ap26_03_joM Ap26_04_dvM Ap26_05_dvM Ap26_06_joM Ap26_07_dvM Ap26_08_dvM Ap27_01_joM Ap27_02_elM Ap27_03_elM Ap27_04_joM Ap27_05_joM Ap27_06_elM Ap28_01_elM Ap28_02_joM Ap28_03_elM Ap28_04_joM Ap28_05_elM Ap28_06_joM Ap29_01_elM Ap29_02_joM Ap29_03_elM Ap29_04_joM Ap29_05_joM Ap29_06_elM Ap29_07_joM Ap29_08_elM Ap29_09_joM Ap29_10_elM Apelelv01M Apelgrd01M Ap29_11_joM Am3l2carrM Aelvcet01M Aelvcet02M Ajorep01M Ajorep02M Ajorep03M Ajorep04M Ajorpld01M Ajorpld02M Ajorpld03M Ajorpld04M Atrjo01M Atrgrim01M Atrgrim02M Atrcarr06M Atrcarr07M Atrcarr08M Atrcarr01M Atrcarr02M Atrcarr03M Atrcarr04M Atrcarr05M Atrcarr12M Abnblde01M Abncass01M Apelelv02M Avault2M Ap29_12_elM Ap14_09_joM Ap19_07_joM Ap19_08_joM Acicarr06M Acicarr11M Acifarr08M Acifarr12M Acifema01M Acifema04M Acifema07M Acifema08M Acifema09M Acifema14M Acifost08M Acifost12M Acigrim05M Acigrim06M Acigrim07M Acigrim08M Acigrim09M Acigrim10M Acihopk09M Acihopk11M Acimale02M Acimale03M Acimale07M Acimale09M Acimale11M Acimale13M Aciroge08M Aciroge12M Atrfost01M Atrfost02M Atrfost03M Atrcarr09M Atrcarr10M Atrcarr11M Acifarr01M Acifarr02M Acifarr03M Acigrim01M Acigrim03M Acigrim04M Acihopk01M Acihopk04M Acihopk06M Aciroge01M Aciroge02M Atrroge01M Acicarr07M Acicarr08M Ajoinst01M Ajoinst02M Ajoinst03M Ajoinst04M Ap25_03_joM Ap29_13_joM Ap29_14_joM Acicarr09M Acicarr10M Ap29_15_joM Ap16_03_joM Acarrbye02M Asaucerexp1M
ASSET_CHR_FILES := Ca51guardZ Carea51guardZ CcarringtonZ CcassandraZ Cdark_combatZ Cdark_frockZ Cdark_trenchZ CddshockZ Cdd_secguardZ CdjbondZ CdrcarrollZ CelvisZ Celvis1Z CeyespyZ Cfem_guardZ ClabtechZ CmrblondeZ CofficeworkerZ Cofficeworker2Z CoverallZ CsecretaryZ CskedarZ CstripesZ CtestchrZ CthekingZ CtrentZ Cdd_labtechZ CconneryZ CmooreZ CdaltonZ Cheaddark_combatZ CheadelvisZ CheadrossZ CheadcarringtonZ CheadmrblondeZ CheadtrentZ CheadddshockZ CheadgrahamZ Cheaddark_frockZ CheadsecretaryZ CheadcassandraZ CheadthekingZ Cheadfem_guardZ CheadjonZ Cdark_rippedZ Cheadmark2Z CheadchristZ CheadrussZ CheadgreyZ CheaddarlingZ Cdd_guardZ CheadrobertZ Cdd_shockZ CheadbeauZ Cdd_shock_infZ Cheadfem_guard2Z CbiotechZ CfbiguyZ CciaguyZ Ca51trooperZ CheadbrianZ CheadjamieZ Cheadduncan2Z CheadbiotechZ Ca51airmanZ Cheadneil2Z CchicrobZ CstewardZ CheadedmcgZ CstewardessZ CheadankaZ CpresidentZ Cstewardess_coatZ Cheadleslie_sZ CminiskedarZ Cnsa_lackeyZ Cheadmatt_cZ Cpres_securityZ Cheadpeer_sZ CnegotiatorZ Cheadeileen_tZ Cg5_guardZ Cheadandy_rZ Cpelagic_guardZ Cg5_swat_guardZ Calaskan_guardZ Cmaian_soldierZ Cheadben_rZ Cheadsteve_kZ Cpresident_cloneZ CheadjonathanZ Cheadmaian_sZ Cdark_af1Z CheadshaunZ CdarkwetZ CdarkaqualungZ CdarksnowZ CdarklabZ CfemlabtechZ CddsniperZ Cpilotaf1Z CcilabtechZ CcifemtechZ Cheadeileen_hZ Cheadscott_hZ CcarreveningsuitZ CjonathonZ CcisoldierZ CheadsanchezZ CheaddarkaquaZ CheadddsniperZ CskedarkingZ CelviswaistcoatZ CheadgriffeyZ CheadmotoZ CheadkeithZ CheadwinnerZ Ca51faceplateZ Cheadelvis_gogsZ CheadstevemZ Cdark_leatherZ Cheaddark_snowZ CheadpresidentZ Chead_vdZ Cdark_negotiatorZ CheadtimZ CheadgrantZ CheadpennyZ CheadrobinZ CheadalexZ CheadjulianneZ CheadlauraZ CheaddavecZ CheadkenZ CheadjoelZ CheadcookZ CheadpryceZ CheadsilkeZ CheadsmithZ CheadgarethZ CheadmurchieZ CheadwongZ CheadcarterZ CheadtintinZ CheadmuntonZ CheadstamperZ CheadjonesZ CheadphelpsZ
ASSET_GUN_FILES := GcartblueZ GcartridgeZ GcartrifleZ GcartshellZ GjoypadZ Pdoor1a_G5Z Pdoor1atri_G5Z Pdoor1b_G5Z Pdoor2_G5Z Pdoor2a_G5Z Pdoor4a_G5Z Pdoor4b_G5Z GtestgunZ GhudpieceZ Gfalcon2Z Gleegun1Z GskpistolZ Gdy357Z Gdy357trentZ GmaianpistolZ Gcmp150Z Gar34Z GdydragonZ GdysuperdragonZ Gk7avengerZ GcycloneZ GmaiansmgZ Grcp120Z GpcgunZ GshotgunZ GskminigunZ GdyrocketZ GdydevastatorZ GskrocketZ Gz2020Z GsniperrifleZ GcrossbowZ GdruggunZ GknifeZ GgrenadeZ GtimedmineZ GproximitymineZ GremotemineZ GwppkZ Gtt33Z GskorpionZ Gak47Z GuziZ Gmp5kZ Gm16Z Gfnp90Z Gfalcon2lodZ GskminigunlodZ Gar34lodZ GavengerlodZ Gcmp150lodZ GcrossbowlodZ GcyclonelodZ GdruggunlodZ Gdy357lodZ Gdy357trentlodZ GdevastatorlodZ GdydragonlodZ GdysuperdragonlodZ GknifelodZ GlaserlodZ GmagseclodZ GmayanpistollodZ GmayansmglodZ GpcgunlodZ Grcp120lodZ GrocketlodZ GshotgunlodZ GskpistollodZ GskrocketlodZ GsniperlodZ Gz2020lodZ GlaserZ GcombathandslodZ GnbombZ GnbomblodZ GgrenadelodZ Ghand_jowetsuitZ Ghand_trentZ Ghand_jofrockZ Ghand_jotrenchZ Ghand_ddsniperZ Ghand_presidentZ Ghand_joaf1Z Ghand_jopilotZ Ghand_carringtonZ Ghand_mrblondeZ Ghand_ciaZ Ghand_cifemtechZ Ghand_fbiarmZ Ghand_josnowZ Ghand_vriesZ Ghand_ddsecurityZ Ghand_tragic_pelagicZ Ghand_stewardess_coatZ Ghand_ddlabtechZ GecmmineZ GcommsuplinkZ GirscannerZ Ghand_elvisZ Ghand_a51guardZ Ghand_ddshockZ Ghand_blackguardZ Ghand_ddfodderZ Ghand_ddbioZ Ghand_a51airmanZ Ghand_g5guardZ Ghand_cisoldierZ
ASSET_PROP_FILES := Pa51_crate1Z Pa51_crate2Z Pa51_crate3Z Pa51_exp1Z Pa51_exp2Z Pa51_horiz_door_botZ Pa51_horiz_door_glZ Pa51_horiz_door_secretZ Pa51_horiz_door_topZ Pa51_lift_controlZ Pa51_lift_hangarZ Pa51_lift_storeZ Pa51_lift_thinwallZ Pa51_unexp1Z Pa51_unexp2Z Pa51_unexp3Z Pa51_vert_door_leftZ Pa51_vert_door_rightZ Pa51_vert_door_stZ Pa51boardZ Pa51chairZ Pa51deskentZ Pa51divideZ Pa51screenZ Pa51tableZ Pa51trolleyZ Pa51wastebinZ Paivillabot1Z Paivillabot2Z Paivillabot3Z Paivilladoor1Z Paivilladoor2aZ Paivilladoor4Z PaivillawindmillZ Pal_airlockZ Pal_dockliftZ Paldoor_lZ Paldoor_rZ Pborg_crateZ PcaseZ Pch_shutter1Z PchrbriefcaseZ PchrbugZ PchrdatathiefZ Pcryptdoor1bZ Pdd_ac_expZ Pdd_ac_unexpZ Pdd_acbot_expZ Pdd_acbot_unexpZ Pdd_bannerZ Pdd_chairZ Pdd_decodoorZ Pdd_deskZ Pdd_fanroofZ Pdd_fanwallZ Pdd_hovcabZ Pdd_hovcarZ Pdd_hovcopZ Pdd_hovercopterZ Pdd_hovmotoZ Pdd_hovtruckZ Pdd_lab_cautionZ Pdd_lab_cautiontopZ Pdd_lab_door_bsZ Pdd_lab_door_secZ Pdd_lab_door_windZ Pdd_lab_hazardZ Pdd_lab_restrictedZ Pdd_lab_sector2botZ Pdd_lab_sector2topZ Pdd_lab_sector3Z Pdd_lab_sector3topZ Pdd_lab_sector3windZ Pdd_lab_sector4topZ Pdd_liftdoorZ Pdd_liftrZ Pdd_officedoorZ Pdd_plantrubberZ Pdd_plantspiderZ Pdd_plantspikeZ Pdd_redarmZ Pdd_redsofaZ Pdd_secretdoorZ Pdd_secretdoor2Z Pdd_servicedoorZ Pdd_stonedeskZ Pdd_vertblindZ Pdd_winddoorZ Pdd_windowZ PddjumpshipZ Pdoor1a_G5Z Pdoor1atri_G5Z Pdoor1b_G5Z Pdoor2_G5Z Pdoor2a_G5Z Pdoor4a_G5Z Pdoor4b_G5Z Pdoor_rollertrainZ PdoorconsoleZ Pdr_caroll_doorZ Pdr_caroll_door_baseZ Pdr_caroll_door_bleftZ Pdr_caroll_door_bmainZ Pdr_caroll_door_brightZ Pdr_caroll_door_leftZ Pdr_caroll_door_mainZ Pdr_caroll_door_rightZ PdropshipZ PdumpsterZ PexplosionbitZ PflagZ Pg5_escdoordownZ Pg5_escdoordownboomZ Pg5_escdoorupZ Pg5_escdoorupboomZ Pg5_mainframeZ Pg5safedoorZ Pg5carliftdoorZ PgoldeneyelogoZ PhooverbotZ PhovbikeZ PhoverbedZ Phovercrate1Z PlasdoorZ PmarkerZ Pmedlabwin1Z Pmedlabwin2Z PmodemboxZ PnintendologoZ Pnlogo2Z Pnlogo3Z PnlogoZ Ppc1Z PpdfourZ PpdoneZ PpdthreeZ PpdtwoZ PperfectdarkZ PpolicecarZ PravineliftZ PropeZ Psk_cryopod1_botZ Psk_cryopod1_topZ Psk_door1Z Psk_fighter1Z Psk_hangardoor_botZ Psk_hangardoor_topZ Psk_ship_door1Z Psk_ship_holo1Z Psk_ship_holo2Z Psk_ship_hulldoor1Z Psk_ship_hulldoor2Z Psk_ship_hulldoor3Z Psk_ship_hulldoor4Z Psk_under_generatorZ Psk_under_transZ Pskcrev_exp1Z Pskcrev_unexp1Z Psktnl_exp1Z Psktnl_unexp1Z PtaxicabZ PtesterbotZ PtestobjZ PtvscreenZ PwindowZ Pcctv_pdZ PcomhubZ PquadpodZ Ppd_consoleZ Plift_platformZ Pdd_grateZ PlightswitchZ PblastshieldZ Plightswitch2Z Pdd_accessdoorupZ Pdd_accessdoordnZ Plab_containerZ Plab_chairZ Plab_tableZ Plab_microscopeZ Plab_mainframeZ Pdd_labdoorZ Pdd_lab_doortopZ Pmulti_ammo_crateZ PchrchainZ ProofgunZ PtdoorZ PgroundgunZ Pci_sofaZ Pci_liftZ Pci_liftdoorZ PlasercutZ Psk_shuttleZ PnewvilladoorZ Psk_pillarleftZ Psk_pillarrightZ Psk_plinth_tZ Psk_plinth_mlZ Psk_plinth_mrZ Psk_plinth_blZ Psk_plinth_brZ Psk_fl_shad_tZ Psk_fl_shad_mlZ Psk_fl_shad_mrZ Psk_fl_shad_blZ Psk_fl_shad_brZ Psk_fl_noshad_tZ Psk_fl_noshad_mlZ Psk_fl_noshad_mrZ Psk_fl_noshad_blZ Psk_fl_noshad_brZ Psk_templecolumn1Z Psk_templecolumn2Z Psk_templecolumn3Z Psk_sunshad1Z Psk_sunshad2Z Psk_sunnoshad1Z Psk_sunnoshad2Z PbarrelZ Pglass_floorZ Pesca_stepZ Pmatrix_liftZ Prubble1Z Prubble2Z Prubble3Z Prubble4Z Pcable_carZ Pelvis_saucerZ Pstewardess_trolleyZ Pairbase_lift_enclosedZ Pairbase_lift_angleZ Pairbase_safedoorZ Paf1_pilotchairZ Paf1_passchairZ PchrnightsightZ PchrshieldZ Pchrfalcon2Z Pchrleegun1Z PchrmaulerZ Pchrdy357Z Pchrdy357trentZ PchrmaianpistolZ Pchrfalcon2silZ Pchrfalcon2scopeZ Pchrcmp150Z Pchrar34Z PchrdragonZ PchrsuperdragonZ PchravengerZ PchrcycloneZ PchrmaiansmgZ Pchrrcp120Z PchrpcgunZ PchrshotgunZ PchrskminigunZ PchrdyrocketZ PchrdevastatorZ PchrskrocketZ Pchrz2020Z PchrsniperrifleZ PchrcrossbowZ PchrdruggunZ PchrknifeZ PchrnbombZ PchrflashbangZ PchrgrenadeZ PchrtimedmineZ PchrproximitymineZ PchrremotemineZ PchrecmmineZ PchrwppkZ Pchrtt33Z PchrskorpionZ PchrkalashZ PchruziZ Pchrmp5kZ Pchrm16Z Pchrfnp90Z PchrdyrocketmisZ PchrskrocketmisZ PchrcrossboltZ PchrdevgrenadeZ PchrdraggrenadeZ Pa51_turretZ PpelagicdoorZ PautosurgeonZ PlimoZ PpdmenuZ Pa51interceptorZ Pa51dishZ Pa51radarconsoleZ Pa51lockerdoorZ Pg5generatorZ Pg5dumpsterZ PchrcloakerZ PchrspeedpillZ PbaggagecarrierZ PminesignZ PchamberZ PisotopeexperimentZ PisotopeZ PreactordoorZ PsaucerinsideZ PvillastoolZ Pcetanwindow1Z Pcetanwindow2Z Pcetanwindow3Z PbigpelagicdoorZ Psk_jonrubble3Z Psk_jonrubble4Z Psk_jonrubble5Z Psk_jonrubble6Z PbinocularsZ PsubmarineZ Pairforce1Z PenginepartZ PcetroofgunZ PcetansmalldoorZ PpowernodeZ PcetanbluegreenlZ PcetanbluegreenrZ PskedarconsoleZ PskedarconsolepanelZ PweaponcdoorZ PtargetZ PdevicesecretdoorZ PcarringtonsecretdoorZ PsinisterpcZ PsinisterstationZ PkeypadlockZ PthumbprintscannerZ PretinalockZ PcardlockZ PgoodstationZ PgoodpcZ PchrautogunZ Pg5bigchairZ Pg5smallchairZ PkingsceptreZ PlabcoatZ Pcidoor1Z Pg5_chairZ Pg5_chair2Z Pdd_window_foyerZ Pci_cabinetZ Pci_deskZ Pci_carr_deskZ Pci_f_chairZ Pci_loungerZ Pci_f_sofaZ Pci_tableZ Pcv_coffee_tableZ Pcv_chair1Z Pcv_chair2Z Pcv_sofaZ Pcv_chair4Z Pcv_lampZ Pcv_cabinetZ Pcv_f_bedZ Ppel_chair1Z Psk_console2Z Pdd_ear_tableZ Pdd_ear_chairZ Pairbase_table2Z Pairbase_chair2Z Pmisc_crateZ Pmisc_irspecsZ Pa51_roofgunZ Psk_drone_gunZ Pci_roofgunZ Pcv_tableZ Pcidoor1_refZ Palaskadoor_outZ Palaskadoor_inZ PwirefenceZ PrarelogoZ PkeycardZ PbodyarmourZ Pa51gate_rZ Pa51gate_lZ Paf1_lampZ Paf1_toiletZ Paf1_doorbig2Z Paf1_phoneZ Paf1_cargodoorZ Pg5_alarmZ Pg5_laser_switchZ Psk_templecolumn4Z PcorehatchZ LameP LarchP LarecP LarkP LashP LateP LaztP LcatP LcaveP LcradP LcrypP LdamP LdepoP LdestP LdishP LearP LeldP LgunP LimpP LjunP LlamP LleeP LlenP LlipP LlueP LmiscP Lmp10P Lmp11P Lmp12P Lmp13P Lmp14P Lmp15P Lmp16P Lmp17P Lmp18P Lmp19P Lmp1P Lmp20P Lmp2P Lmp3P Lmp4P Lmp5P Lmp6P Lmp7P Lmp8P Lmp9P LmpmenuP LmpweaponsP LoatP LoldP LoptionsP LpamP LpeteP LpropobjP LrefP LritP LrunP LsevP LsevbP LsevxP LsevxbP LshoP LsiloP LstatP LtitleP LtraP LuffP LwaxP Pa51grateZ Paf1escapedoorZ PprescapsuleZ PskedarbridgeZ Ppelagicdoor2Z Pttb_boxZ PinstfrontdoorZ PchrlaserZ PbaftaZ PchrsonicscrewerZ PchrlumphammerZ PskedarbombZ PexplosivebrickZ PresearchtapeZ PziggycardZ PsafeitemZ Paf1_tableZ PsensitiveinfoZ PrussdarZ PxrayspecsZ PchreyespyZ PchrdoordecoderZ PbriefcaseZ PsuitcaseZ PshuttledoorZ PruinbridgeZ PsecretindoorZ PskpuzzleobjectZ Pa51liftdoorZ PcihubZ Psk_ship_door2Z Psk_window1Z Psk_hangardoorb_topZ Psk_hangardoorb_botZ Paf1_innerdoorZ Plaser_postZ PtargetampZ Psk_liftZ PknockknockZ PcetandoorZ Paf1rubbleZ Pdd_dr_nonrefZ PcetandoorsideZ PbuddybridgeZ
ASSET_SPSETUP_FILES := UsetupameZ UsetuparchZ UsetuparecZ UsetuparkZ UsetupashZ UsetupaztZ UsetupcatZ UsetupcaveZ UsetupcradZ UsetupcrypZ UsetupdamZ UsetupdepoZ UsetupdestZ UsetupdishZ UsetupearZ UsetupeldZ UsetupimpZ UsetupjunZ UsetupleeZ UsetuplenZ UsetuplipZ UsetuplueZ UsetupoatZ UsetuppamZ UsetuppeteZ UsetuprefZ UsetupritZ UsetuprunZ UsetupsevZ UsetupsevbZ UsetupsevxZ UsetupsevxbZ UsetupshoZ UsetupsiloZ UsetupstatZ UsetuptraZ UsetupwaxZ UsetupuffZ UsetupoldZ UsetupateZ UsetuplamZ Usetupmp1Z Usetupmp2Z Usetupmp3Z Usetupmp4Z Usetupmp5Z Usetupmp6Z Usetupmp7Z Usetupmp8Z Usetupmp9Z Usetupmp10Z Usetupmp11Z Usetupmp12Z Usetupmp13Z Usetupmp14Z Usetupmp15Z Usetupmp16Z Usetupmp17Z Usetupmp18Z Usetupmp19Z Usetupmp20Z
ASSET_MPSETUP_FILES := Ump_setupameZ Ump_setuparchZ Ump_setuparecZ Ump_setuparkZ Ump_setupashZ Ump_setupaztZ Ump_setupcatZ Ump_setupcaveZ Ump_setupcradZ Ump_setupcrypZ Ump_setupdamZ Ump_setupdepoZ Ump_setupdestZ Ump_setupdishZ Ump_setupearZ Ump_setupeldZ Ump_setupimpZ Ump_setupjunZ Ump_setupleeZ Ump_setuplenZ Ump_setuplipZ Ump_setuplueZ Ump_setupoatZ Ump_setuppamZ Ump_setuppeteZ Ump_setuprefZ Ump_setupritZ Ump_setuprunZ Ump_setupsevZ Ump_setupsevbZ Ump_setupsevxZ Ump_setupshoZ Ump_setupsiloZ Ump_setupstatZ Ump_setuptraZ Ump_setupwaxZ Ump_setupuffZ Ump_setupoldZ Ump_setupateZ Ump_setuplamZ Ump_setupmp1Z Ump_setupmp2Z Ump_setupmp3Z Ump_setupmp4Z Ump_setupmp5Z Ump_setupmp6Z Ump_setupmp7Z Ump_setupmp8Z Ump_setupmp9Z Ump_setupmp10Z Ump_setupmp11Z Ump_setupmp12Z Ump_setupmp13Z Ump_setupmp14Z Ump_setupmp15Z Ump_setupmp16Z Ump_setupmp17Z Ump_setupmp18Z Ump_setupmp19Z Ump_setupmp20Z
ASSET_BG_SEG_FILES := bgdata/bg_sev.seg bgdata/bg_silo.seg bgdata/bg_stat.seg bgdata/bg_arec.seg bgdata/bg_arch.seg bgdata/bg_tra.seg bgdata/bg_dest.seg bgdata/bg_sevb.seg bgdata/bg_azt.seg bgdata/bg_pete.seg bgdata/bg_depo.seg bgdata/bg_ref.seg bgdata/bg_cryp.seg bgdata/bg_dam.seg bgdata/bg_ark.seg bgdata/bg_run.seg bgdata/bg_sevx.seg bgdata/bg_jun.seg bgdata/bg_dish.seg bgdata/bg_cave.seg bgdata/bg_cat.seg bgdata/bg_crad.seg bgdata/bg_sho.seg bgdata/bg_eld.seg bgdata/bg_imp.seg bgdata/bg_ash.seg bgdata/bg_lue.seg bgdata/bg_ame.seg bgdata/bg_rit.seg bgdata/bg_oat.seg bgdata/bg_ear.seg bgdata/bg_lee.seg bgdata/bg_lip.seg bgdata/bg_len.seg bgdata/bg_wax.seg bgdata/bg_pam.seg bgdata/bg_uff.seg bgdata/bg_old.seg bgdata/bg_ate.seg bgdata/bg_lam.seg bgdata/bg_mp1.seg bgdata/bg_mp2.seg bgdata/bg_mp3.seg bgdata/bg_mp4.seg bgdata/bg_mp5.seg bgdata/bg_mp6.seg bgdata/bg_mp7.seg bgdata/bg_mp8.seg bgdata/bg_mp9.seg bgdata/bg_mp10.seg bgdata/bg_mp11.seg bgdata/bg_mp12.seg bgdata/bg_mp13.seg bgdata/bg_mp14.seg bgdata/bg_mp15.seg bgdata/bg_mp16.seg bgdata/bg_mp17.seg bgdata/bg_mp18.seg bgdata/bg_mp19.seg bgdata/bg_mp20.seg
ASSET_BG_PADS_FILES := bgdata/bg_ame_padsZ bgdata/bg_arch_padsZ bgdata/bg_arec_padsZ bgdata/bg_ark_padsZ bgdata/bg_ash_padsZ bgdata/bg_azt_padsZ bgdata/bg_cat_padsZ bgdata/bg_cave_padsZ bgdata/bg_crad_padsZ bgdata/bg_cryp_padsZ bgdata/bg_dam_padsZ bgdata/bg_depo_padsZ bgdata/bg_dest_padsZ bgdata/bg_dish_padsZ bgdata/bg_ear_padsZ bgdata/bg_eld_padsZ bgdata/bg_imp_padsZ bgdata/bg_jun_padsZ bgdata/bg_lee_padsZ bgdata/bg_len_padsZ bgdata/bg_lip_padsZ bgdata/bg_lue_padsZ bgdata/bg_oat_padsZ bgdata/bg_pam_padsZ bgdata/bg_pete_padsZ bgdata/bg_ref_padsZ bgdata/bg_rit_padsZ bgdata/bg_run_padsZ bgdata/bg_sev_padsZ bgdata/bg_sevb_padsZ bgdata/bg_sevx_padsZ bgdata/bg_sho_padsZ bgdata/bg_silo_padsZ bgdata/bg_stat_padsZ bgdata/bg_tra_padsZ bgdata/bg_wax_padsZ bgdata/bg_uff_padsZ bgdata/bg_old_padsZ bgdata/bg_ate_padsZ bgdata/bg_lam_padsZ bgdata/bg_mp1_padsZ bgdata/bg_mp2_padsZ bgdata/bg_mp3_padsZ bgdata/bg_mp4_padsZ bgdata/bg_mp5_padsZ bgdata/bg_mp6_padsZ bgdata/bg_mp7_padsZ bgdata/bg_mp8_padsZ bgdata/bg_mp9_padsZ bgdata/bg_mp10_padsZ bgdata/bg_mp11_padsZ bgdata/bg_mp12_padsZ bgdata/bg_mp13_padsZ bgdata/bg_mp14_padsZ bgdata/bg_mp15_padsZ bgdata/bg_mp16_padsZ bgdata/bg_mp17_padsZ bgdata/bg_mp18_padsZ bgdata/bg_mp19_padsZ bgdata/bg_mp20_padsZ
ASSET_BG_TILES_FILES := bgdata/bg_ame_tilesZ bgdata/bg_arch_tilesZ bgdata/bg_arec_tilesZ bgdata/bg_ark_tilesZ bgdata/bg_ash_tilesZ bgdata/bg_azt_tilesZ bgdata/bg_cat_tilesZ bgdata/bg_cave_tilesZ bgdata/bg_crad_tilesZ bgdata/bg_cryp_tilesZ bgdata/bg_dam_tilesZ bgdata/bg_depo_tilesZ bgdata/bg_dest_tilesZ bgdata/bg_dish_tilesZ bgdata/bg_ear_tilesZ bgdata/bg_eld_tilesZ bgdata/bg_imp_tilesZ bgdata/bg_jun_tilesZ bgdata/bg_lee_tilesZ bgdata/bg_len_tilesZ bgdata/bg_lip_tilesZ bgdata/bg_lue_tilesZ bgdata/bg_oat_tilesZ bgdata/bg_pam_tilesZ bgdata/bg_pete_tilesZ bgdata/bg_ref_tilesZ bgdata/bg_rit_tilesZ bgdata/bg_run_tilesZ bgdata/bg_sev_tilesZ bgdata/bg_sevb_tilesZ bgdata/bg_sevx_tilesZ bgdata/bg_sho_tilesZ bgdata/bg_silo_tilesZ bgdata/bg_stat_tilesZ bgdata/bg_tra_tilesZ bgdata/bg_wax_tilesZ bgdata/bg_uff_tilesZ bgdata/bg_old_tilesZ bgdata/bg_ate_tilesZ bgdata/bg_lam_tilesZ bgdata/bg_mp1_tilesZ bgdata/bg_mp2_tilesZ bgdata/bg_mp3_tilesZ bgdata/bg_mp4_tilesZ bgdata/bg_mp5_tilesZ bgdata/bg_mp6_tilesZ bgdata/bg_mp7_tilesZ bgdata/bg_mp8_tilesZ bgdata/bg_mp9_tilesZ bgdata/bg_mp10_tilesZ bgdata/bg_mp11_tilesZ bgdata/bg_mp12_tilesZ bgdata/bg_mp13_tilesZ bgdata/bg_mp14_tilesZ bgdata/bg_mp15_tilesZ bgdata/bg_mp16_tilesZ bgdata/bg_mp17_tilesZ bgdata/bg_mp18_tilesZ bgdata/bg_mp19_tilesZ bgdata/bg_mp20_tilesZ
ASSET_OB_SEG_FILES := ob/ob_mid.seg
ASSET_LANG_E_FILES := LameE LarchE LarecE LarkE LashE LateE LaztE LcatE LcaveE LcradE LcrypE LdamE LdepoE LdestE LdishE LearE LeldE LgunE LimpE LjunE LlamE LleeE LlenE LlipE LlueE LmiscE Lmp10E Lmp11E Lmp12E Lmp13E Lmp14E Lmp15E Lmp16E Lmp17E Lmp18E Lmp19E Lmp1E Lmp20E Lmp2E Lmp3E Lmp4E Lmp5E Lmp6E Lmp7E Lmp8E Lmp9E LmpmenuE LmpweaponsE LoatE LoldE LoptionsE LpamE LpeteE LpropobjE LrefE LritE LrunE LsevE LsevbE LsevxE LsevxbE LshoE LsiloE LstatE LtitleE LtraE LuffE LwaxE
ASSET_LANG_J_FILES := LameJ LarchJ LarecJ LarkJ LashJ LateJ LaztJ LcatJ LcaveJ LcradJ LcrypJ LdamJ LdepoJ LdestJ LdishJ LearJ LeldJ LgunJ LimpJ LjunJ LlamJ LleeJ LlenJ LlipJ LlueJ LmiscJ Lmp10J Lmp11J Lmp12J Lmp13J Lmp14J Lmp15J Lmp16J Lmp17J Lmp18J Lmp19J Lmp1J Lmp20J Lmp2J Lmp3J Lmp4J Lmp5J Lmp6J Lmp7J Lmp8J Lmp9J LmpmenuJ LmpweaponsJ LoatJ LoldJ LoptionsJ LpamJ LpeteJ LpropobjJ LrefJ LritJ LrunJ LsevJ LsevbJ LsevxJ LsevxbJ LshoJ LsiloJ LstatJ LtitleJ LtraJ LuffJ LwaxJ
ASSET_LANG_P_FILES := LameP LarchP LarecP LarkP LashP LateP LaztP LcatP LcaveP LcradP LcrypP LdamP LdepoP LdestP LdishP LearP LeldP LgunP LimpP LjunP LlamP LleeP LlenP LlipP LlueP LmiscP Lmp10P Lmp11P Lmp12P Lmp13P Lmp14P Lmp15P Lmp16P Lmp17P Lmp18P Lmp19P Lmp1P Lmp20P Lmp2P Lmp3P Lmp4P Lmp5P Lmp6P Lmp7P Lmp8P Lmp9P LmpmenuP LmpweaponsP LoatP LoldP LoptionsP LpamP LpeteP LpropobjP LrefP LritP LrunP LsevP LsevbP LsevxP LsevxbP LshoP LsiloP LstatP LtitleP LtraP LuffP LwaxP
ASSET_LANG_F_FILES := Lame_str_fZ Larch_str_fZ Larec_str_fZ Lark_str_fZ Lash_str_fZ Late_str_fZ Lazt_str_fZ Lcat_str_fZ Lcave_str_fZ Lcrad_str_fZ Lcryp_str_fZ Ldam_str_fZ Ldepo_str_fZ Ldest_str_fZ Ldish_str_fZ Lear_str_fZ Leld_str_fZ Lgun_str_fZ Limp_str_fZ Ljun_str_fZ Llam_str_fZ Llee_str_fZ Llen_str_fZ Llip_str_fZ Llue_str_fZ Lmisc_str_fZ Lmp10_str_fZ Lmp11_str_fZ Lmp12_str_fZ Lmp13_str_fZ Lmp14_str_fZ Lmp15_str_fZ Lmp16_str_fZ Lmp17_str_fZ Lmp18_str_fZ Lmp19_str_fZ Lmp1_str_fZ Lmp20_str_fZ Lmp2_str_fZ Lmp3_str_fZ Lmp4_str_fZ Lmp5_str_fZ Lmp6_str_fZ Lmp7_str_fZ Lmp8_str_fZ Lmp9_str_fZ Lmpmenu_str_fZ Lmpweapons_str_fZ Loat_str_fZ Lold_str_fZ Loptions_str_fZ Lpam_str_fZ Lpete_str_fZ Lpropobj_str_fZ Lref_str_fZ Lrit_str_fZ Lrun_str_fZ Lsev_str_fZ Lsevb_str_fZ Lsevx_str_fZ Lsevxb_str_fZ Lsho_str_fZ Lsilo_str_fZ Lstat_str_fZ Ltitle_str_fZ Ltra_str_fZ Luff_str_fZ Lwax_str_fZ
ASSET_LANG_G_FILES := Lame_str_gZ Larch_str_gZ Larec_str_gZ Lark_str_gZ Lash_str_gZ Late_str_gZ Lazt_str_gZ Lcat_str_gZ Lcave_str_gZ Lcrad_str_gZ Lcryp_str_gZ Ldam_str_gZ Ldepo_str_gZ Ldest_str_gZ Ldish_str_gZ Lear_str_gZ Leld_str_gZ Lgun_str_gZ Limp_str_gZ Ljun_str_gZ Llam_str_gZ Llee_str_gZ Llen_str_gZ Llip_str_gZ Llue_str_gZ Lmisc_str_gZ Lmp10_str_gZ Lmp11_str_gZ Lmp12_str_gZ Lmp13_str_gZ Lmp14_str_gZ Lmp15_str_gZ Lmp16_str_gZ Lmp17_str_gZ Lmp18_str_gZ Lmp19_str_gZ Lmp1_str_gZ Lmp20_str_gZ Lmp2_str_gZ Lmp3_str_gZ Lmp4_str_gZ Lmp5_str_gZ Lmp6_str_gZ Lmp7_str_gZ Lmp8_str_gZ Lmp9_str_gZ Lmpmenu_str_gZ Lmpweapons_str_gZ Loat_str_gZ Lold_str_gZ Loptions_str_gZ Lpam_str_gZ Lpete_str_gZ Lpropobj_str_gZ Lref_str_gZ Lrit_str_gZ Lrun_str_gZ Lsev_str_gZ Lsevb_str_gZ Lsevx_str_gZ Lsevxb_str_gZ Lsho_str_gZ Lsilo_str_gZ Lstat_str_gZ Ltitle_str_gZ Ltra_str_gZ Luff_str_gZ Lwax_str_gZ
ASSET_LANG_I_FILES := Lame_str_iZ Larch_str_iZ Larec_str_iZ Lark_str_iZ Lash_str_iZ Late_str_iZ Lazt_str_iZ Lcat_str_iZ Lcave_str_iZ Lcrad_str_iZ Lcryp_str_iZ Ldam_str_iZ Ldepo_str_iZ Ldest_str_iZ Ldish_str_iZ Lear_str_iZ Leld_str_iZ Lgun_str_iZ Limp_str_iZ Ljun_str_iZ Llam_str_iZ Llee_str_iZ Llen_str_iZ Llip_str_iZ Llue_str_iZ Lmisc_str_iZ Lmp10_str_iZ Lmp11_str_iZ Lmp12_str_iZ Lmp13_str_iZ Lmp14_str_iZ Lmp15_str_iZ Lmp16_str_iZ Lmp17_str_iZ Lmp18_str_iZ Lmp19_str_iZ Lmp1_str_iZ Lmp20_str_iZ Lmp2_str_iZ Lmp3_str_iZ Lmp4_str_iZ Lmp5_str_iZ Lmp6_str_iZ Lmp7_str_iZ Lmp8_str_iZ Lmp9_str_iZ Lmpmenu_str_iZ Lmpweapons_str_iZ Loat_str_iZ Lold_str_iZ Loptions_str_iZ Lpam_str_iZ Lpete_str_iZ Lpropobj_str_iZ Lref_str_iZ Lrit_str_iZ Lrun_str_iZ Lsev_str_iZ Lsevb_str_iZ Lsevx_str_iZ Lsevxb_str_iZ Lsho_str_iZ Lsilo_str_iZ Lstat_str_iZ Ltitle_str_iZ Ltra_str_iZ Luff_str_iZ Lwax_str_iZ
ASSET_LANG_S_FILES := Lame_str_sZ Larch_str_sZ Larec_str_sZ Lark_str_sZ Lash_str_sZ Late_str_sZ Lazt_str_sZ Lcat_str_sZ Lcave_str_sZ Lcrad_str_sZ Lcryp_str_sZ Ldam_str_sZ Ldepo_str_sZ Ldest_str_sZ Ldish_str_sZ Lear_str_sZ Leld_str_sZ Lgun_str_sZ Limp_str_sZ Ljun_str_sZ Llam_str_sZ Llee_str_sZ Llen_str_sZ Llip_str_sZ Llue_str_sZ Lmisc_str_sZ Lmp10_str_sZ Lmp11_str_sZ Lmp12_str_sZ Lmp13_str_sZ Lmp14_str_sZ Lmp15_str_sZ Lmp16_str_sZ Lmp17_str_sZ Lmp18_str_sZ Lmp19_str_sZ Lmp1_str_sZ Lmp20_str_sZ Lmp2_str_sZ Lmp3_str_sZ Lmp4_str_sZ Lmp5_str_sZ Lmp6_str_sZ Lmp7_str_sZ Lmp8_str_sZ Lmp9_str_sZ Lmpmenu_str_sZ Lmpweapons_str_sZ Loat_str_sZ Lold_str_sZ Loptions_str_sZ Lpam_str_sZ Lpete_str_sZ Lpropobj_str_sZ Lref_str_sZ Lrit_str_sZ Lrun_str_sZ Lsev_str_sZ Lsevb_str_sZ Lsevx_str_sZ Lsevxb_str_sZ Lsho_str_sZ Lsilo_str_sZ Lstat_str_sZ Ltitle_str_sZ Ltra_str_sZ Luff_str_sZ Lwax_str_sZ

# Prefix the above files with the path
ASSET_AUDIO_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_AUDIO_FILES))
ASSET_CHR_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_CHR_FILES))
ASSET_GUN_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_GUN_FILES))
ASSET_PROP_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_PROP_FILES))
ASSET_SPSETUP_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_SPSETUP_FILES))
ASSET_MPSETUP_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_MPSETUP_FILES))
ASSET_BG_SEG_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_BG_SEG_FILES))
ASSET_BG_PADS_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_BG_PADS_FILES))
ASSET_BG_TILES_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_BG_TILES_FILES))
ASSET_OB_SEG_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_OB_SEG_FILES))
ASSET_LANG_E_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_E_FILES))
ASSET_LANG_J_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_J_FILES))
ASSET_LANG_P_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_P_FILES))
ASSET_LANG_F_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_F_FILES))
ASSET_LANG_G_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_G_FILES))
ASSET_LANG_I_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_I_FILES))
ASSET_LANG_S_FILES := $(patsubst %, $(B_DIR)/files/%, $(ASSET_LANG_S_FILES))

ASSET_LANG_FILES := $(ASSET_LANG_E_FILES) $(ASSET_LANG_J_FILES) $(ASSET_LANG_P_FILES) $(ASSET_LANG_F_FILES) $(ASSET_LANG_G_FILES) $(ASSET_LANG_I_FILES) $(ASSET_LANG_S_FILES)

ASSET_FILES := $(ASSET_AUDIO_FILES) $(ASSET_CHR_FILES) $(ASSET_GUN_FILES) $(ASSET_PROP_FILES) $(ASSET_SPSETUP_FILES) $(ASSET_MPSETUP_FILES) $(ASSET_BG_SEG_FILES) $(ASSET_BG_PADS_FILES) $(ASSET_BG_TILES_FILES) $(ASSET_OB_SEG_FILES) $(ASSET_LANG_FILES)

ASSET_O_FILES := $(patsubst %, %.o, $(ASSET_FILES))

UCODE_BIN_FILES := \
	$(B_DIR)/ucode/boot.bin \
	$(B_DIR)/ucode/filenames.bin \
	$(B_DIR)/ucode/game.bin \
	$(B_DIR)/ucode/gamedata.bin \
	$(B_DIR)/ucode/gvars.bin \
	$(B_DIR)/ucode/lib.bin \
	$(B_DIR)/ucode/inflate.bin

default: all

################################################################################
# Audio files

$(B_DIR)/files/A%M: $(E_DIR)/files/A%M
	@mkdir -p $(B_DIR)/files
	cp $< $@

audio: $(ASSET_AUDIO_FILES)

################################################################################
# BG seg files

$(B_DIR)/files/bgdata/bg_%.seg: $(E_DIR)/files/bgdata/bg_%.seg
	@mkdir -p $(B_DIR)/files/bgdata
	cp $< $@

bgsegs: $(ASSET_BG_SEG_FILES)

################################################################################
# BG pad files

$(B_DIR)/files/bgdata/bg_%_padsZ: $(E_DIR)/files/bgdata/bg_%_padsZ
	@mkdir -p $(B_DIR)/files/bgdata
	cp $< $@

pads: $(ASSET_BG_PADS_FILES)

################################################################################
# BG tile files

src/files/bgdata/bg_%_tiles.o: src/files/bgdata/bg_%_tiles.s
	$(TOOLCHAIN)-as --defsym VERSION=$(VERSION) -march=vr4300 -mabi=32 -I src/include -EB -o $@ $<

$(B_DIR)/files/bgdata/bg_%_tiles.elf: src/files/bgdata/bg_%_tiles.o
	@mkdir -p $(B_DIR)/files/bgdata
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

tiles: $(ASSET_BG_TILES_FILES)

################################################################################
# Chr files

$(B_DIR)/files/C%Z: $(E_DIR)/files/C%Z
	@mkdir -p $(B_DIR)/files
	cp $< $@

chrs: $(ASSET_CHR_FILES)

################################################################################
# Gun files

$(B_DIR)/files/G%Z: $(E_DIR)/files/G%Z
	@mkdir -p $(B_DIR)/files
	cp $< $@

guns: $(ASSET_GUN_FILES)

################################################################################
# Lang files

$(B_DIR)/files/lang/L%.o: src/files/lang/$(ROMID)/%.c
	@mkdir -p $(B_DIR)/files/lang
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) $< -o $@ -O2

$(B_DIR)/files/L%.elf: $(B_DIR)/files/lang/L%.o
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

$(B_DIR)/files/L%E: $(B_DIR)/files/L%E.bin
	tools/rarezip $< > $@

$(B_DIR)/files/L%J: $(B_DIR)/files/L%J.bin
	tools/rarezip $< > $@

$(B_DIR)/files/L%P: $(B_DIR)/files/L%P.bin
	tools/rarezip $< > $@

lang: $(ASSET_LANG_FILES)

################################################################################
# OB seg files

$(B_DIR)/files/ob/ob_mid.seg:
	@mkdir -p $(B_DIR)/files/ob
	> $@

obseg: $(ASSET_OB_SEG_FILES)

################################################################################
# Prop files

$(B_DIR)/files/P%Z: $(E_DIR)/files/P%Z
	@mkdir -p $(B_DIR)/files
	cp $< $@

props: $(ASSET_PROP_FILES)

################################################################################
# Stage setup files

$(B_DIR)/files/U%.elf: $(B_DIR)/files/setup/%.o
	@mkdir -p $(B_DIR)/files
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

stagesetup: $(ASSET_SPSETUP_FILES) $(ASSET_MPSETUP_FILES)

################################################################################
# Boot

$(B_DIR)/ucode/boot.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment boot

boot: $(B_DIR)/ucode/boot.bin

################################################################################
# Lib

$(B_DIR)/ucode/lib.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment lib

lib: $(B_DIR)/ucode/lib.bin

################################################################################
# Game data file

$(B_DIR)/ucode/gamedata.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment gamedata

setup: $(B_DIR)/ucode/gamedata.bin

################################################################################
# Inflate

$(B_DIR)/ucode/inflate.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment inflate

inflate: $(B_DIR)/ucode/inflate.bin

################################################################################
# Main game

$(B_DIR)/ucode/game.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment game

game: $(B_DIR)/ucode/game.bin

################################################################################
# gVars

$(B_DIR)/ucode/gvars.bin: $(B_DIR)/pd.bin
	@mkdir -p $(B_DIR)/ucode
	B_DIR=$(B_DIR) tools/extract-segment gvars

gvars: $(B_DIR)/ucode/gvars.bin

################################################################################
# Miscellaneous

extract:
	tools/extract

$(B_DIR)/ucode/gamezips.bin: $(B_DIR)/ucode/game.bin
	tools/mkgamezips

test: all
	@md5sum --quiet -c checksums.$(ROMID).md5

$(B_DIR)/files/%.o: $(B_DIR)/files/%
	/bin/echo -e ".data\n.incbin \"$<\"" > $(B_DIR)/file.s
	$(TOOLCHAIN)-as -mabi=32 -mips2 -I src/include -EB -o $@ $(B_DIR)/file.s
	rm -f file.s

$(B_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/files/%.bin: $(B_DIR)/files/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/%Z: $(B_DIR)/files/%.bin
	tools/rarezip $< > $@

$(B_DIR)/ucode/filenames.elf: src/filenames.o
	@mkdir -p $(B_DIR)/ucode
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

$(B_DIR)/ucode/filenames.bin: $(B_DIR)/ucode/filenames.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/pd.elf: $(O_FILES) $(ASSET_O_FILES) ld/pd.ld
	cpp -DROMID=$(ROMID) -DVERSION=$(VERSION) -P ld/pd.ld -o $(B_DIR)/pd.ld
	$(TOOLCHAIN)-ld --no-check-sections -T $(B_DIR)/pd.ld --print-map -o $@ > $(B_DIR)/pd.map

$(B_DIR)/pd.bin: $(B_DIR)/pd.elf
	@mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary

all: $(UCODE_BIN_FILES) $(ASSET_O_FILES)

rom: $(UCODE_BIN_FILES) $(B_DIR)/ucode/gamezips.bin $(ASSET_O_FILES)
	TOOLCHAIN=$(TOOLCHAIN) tools/buildrom
	tools/checksum $(B_DIR)/pd.z64 --write

clean:
	rm -rf build/$(ROMID)

allclean:
	rm -rf build/*

codeclean:
	rm -f $(B_DIR)/ucode/*.bin
	find $(B_DIR)/{boot,game,gvars,inflate,lib} -name '*.o' -delete
