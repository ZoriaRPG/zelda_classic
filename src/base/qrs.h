#ifndef _QRS_H_
#define _QRS_H_

#include "base/ints.h"

#define QUESTRULES_SIZE 20
#define QUESTRULES_NEW_SIZE 100
#define QR_SZ QUESTRULES_NEW_SIZE
#define EXTRARULES_SIZE 1

extern byte quest_rules[QUESTRULES_NEW_SIZE];
extern byte extra_rules[EXTRARULES_SIZE];

enum
{
    // 1st byte out of 20
    qr_SOLIDBLK, qr_NOTMPNORET, qr_ALWAYSRET, qr_MEANTRAPS,
    qr_BSZELDA, qr_FADE, qr_FADECS5, qr_FASTDNGN,
    // 2
    qr_NOLEVEL3FIX, qr_COOLSCROLL, qr_NOSCROLL, qr_4TRI,
    qr_EXPLICIT_RAFTING, qr_FASTFILL, qr_CAVEEXITNOSTOPMUSIC, qr_3TRI,
    // 3
    qr_TIME, qr_FREEFORM, qr_KILLALL, qr_NOFLICKER,
    qr_CONTFULL_DEP/*DEPRECATED*/, qr_RLFIX, qr_LENSHINTS, /*DEPRECATED*/ 
    qr_HERODUNGEONPOSFIX,
    // 4
    qr_HOLDITEMANIMATION, qr_HESITANTPUSHBLOCKS, qr_HIDECARRIEDITEMS, qr_FFCSCROLL,
    qr_RAFTLENS, /*DEPRECATED*/  
	qr_SMOOTHVERTICALSCROLLING, qr_WHIRLWINDMIRROR, qr_NOFLASHDEATH,
    // 5
    qr_HOLDNOSTOPMUSIC, qr_FIREPROOFHERO, qr_OUCHBOMBS, qr_NOCLOCKS_DEP/*DEPRECATED*/,
    qr_TEMPCLOCKS_DEP/*DEPRECATED*/, qr_BRKBLSHLDS_DEP/*DEPRECATED*/, qr_BRKNSHLDTILES, qr_MEANPLACEDTRAPS,
    // 6
    qr_PHANTOMPLACEDTRAPS, qr_ALLOWFASTMSG, qr_LINKEDCOMBOS/*DEPRECATED*/, qr_NOGUYFIRES,
    qr_HEARTRINGFIX, qr_NOHEARTRING, qr_OVERWORLDTUNIC, qr_SWORDWANDFLIPFIX,
    // 7
    qr_ENABLEMAGIC, qr_MAGICWAND_DEP/*DEPRECATED*/, qr_MAGICCANDLE_DEP/*DEPRECATED*/, qr_MAGICBOOTS_DEP/*DEPRECATED*/,
    qr_NONBUBBLEMEDICINE, qr_NONBUBBLEFAIRIES, qr_NONBUBBLETRIFORCE, qr_NEWENEMYTILES,
    // 8
    qr_NOROPE2FLASH_DEP/*DEPRECATED*/, qr_NOBUBBLEFLASH_DEP/*DEPRECATED*/, qr_GHINI2BLINK_DEP, qr_BITMAPOFFSETFIX, /* UNIMPLEMENTED */
    qr_PHANTOMGHINI2_DEP/*DEPRECATED*/, qr_Z3BRANG_HSHOT, qr_NOITEMMELEE/*DEPRECATED*/, qr_SHADOWS,
    // 9
    qr_TRANSSHADOWS, qr_QUICKSWORD, qr_BOMBHOLDFIX, qr_EXPANDEDLTM,
    qr_NOPOTIONCOMBINE_DEP/*DEPRECATED*/, qr_HEROFLICKER, qr_SHADOWSFLICKER, qr_WALLFLIERS,
    // 10
    qr_NOBOMBPALFLASH, qr_HEARTSREQUIREDFIX, qr_PUSHBLOCKCSETFIX, qr_TRANSLUCENTDIVINEPROTECTIONROCKET_DEP/*DEPRECATED*/,
    qr_FLICKERINGDIVINEPROTECTIONROCKET_DEP/*DEPRECATED*/, qr_CMBCYCLELAYERS, qr_DMGCOMBOPRI, qr_WARPSIGNOREARRIVALPOINT,
    // 11
    qr_LTTPCOLLISION, qr_LTTPWALK, qr_SLOWENEMYANIM_DEP/*DEPRECATED*/, qr_TRUEARROWS,
    qr_NOSAVE, qr_NOCONTINUE, qr_QUARTERHEART, qr_NOARRIVALPOINT,
    // 12
    qr_NOGUYPOOF, qr_ALLOWMSGBYPASS, qr_NODIVING, qr_LAYER12UNDERCAVE,
    qr_NOSCROLLCONTINUE, qr_SMARTSCREENSCROLL, qr_RINGAFFECTDAMAGE/*DEPRECATED*/, qr_ALLOW10RUPEEDROPS_DEP/*DEPRECATED*/,
    // 13
    qr_TRAPPOSFIX, qr_TEMPCANDLELIGHT, qr_REDPOTIONONCE_DEP/*DEPRECATED*/, qr_OLDSTYLEWARP,
    qr_NOBORDER, qr_OLDTRIBBLES_DEP/*DEPRECATED*/, qr_REFLECTROCKS /*DEPRECATED*/, qr_OLDPICKUP,
    // 14
    qr_ENEMIESZAXIS, qr_SAFEENEMYFADE, qr_MORESOUNDS, qr_BRANGPICKUP,
    qr_HEARTPIECEINCR_DEP/*DEPRECATED*/, qr_ITEMSONEDGES, qr_EATSMALLSHIELD_DEP/*DEPRECATED*/, qr_MSGFREEZE,
    // 15
    qr_SLASHFLIPFIX/*DEPRECATED*/, qr_FIREMAGICSPRITE_DEP/*DEPRECATED*/, qr_SLOWCHARGINGWALK/*DEPRECATED*/, qr_NOWANDMELEE/*DEPRECATED*/,
    qr_SLOWBOMBFUSES_DEP/*DEPRECATED*/, qr_SWORDMIRROR, qr_SELECTAWPN, qr_LENSSEESENEMIES, /*DEPRECATED*/ 
    // 16
    qr_INSTABURNFLAGS, qr_DROWN, qr_MSGDISAPPEAR, qr_SUBSCREENOVERSPRITES,
    qr_BOMBDARKNUTFIX, qr_LONGBOMBBOOM_DEP/*DEPRECATED*/, qr_OFFSETEWPNCOLLISIONFIX, qr_DMGCOMBOLAYERFIX,
    // 17
    qr_ITEMSINPASSAGEWAYS, qr_LOG, qr_FIREPROOFHERO2, qr_NOITEMOFFSET,
    qr_ITEMBUBBLE, qr_GOTOLESSNOTEQUAL /* Compatibility */, qr_LADDERANYWHERE, qr_HOOKSHOTLAYERFIX,
    // 18
    qr_REPLACEOPENDOORS /* Compatibility */, qr_OLDLENSORDER /* Compatibility */, qr_NOFAIRYGUYFIRES /* Compatibility */, qr_SCRIPTERRLOG,
    qr_TRIGGERSREPEAT /* Compatibility */, qr_ENEMIESFLICKER, qr_OVALWIPE, qr_TRIANGLEWIPE,
    // 19
    qr_SMASWIPE, qr_NOSOLIDDAMAGECOMBOS, qr_SHOPCHEAT, qr_HOOKSHOTDOWNBUG /* Compatibility */,
    qr_OLDHOOKSHOTGRAB /* Compatibility */, qr_PEAHATCLOCKVULN /* Compatibility */, qr_VERYFASTSCROLLING, qr_OFFSCREENWEAPONS /* Compatibility */,
    // 20
    qr_BROKENSTATUES /* Compatibility */, qr_BOMBCHUSUPERBOMB,
    qr_ITEMPICKUPSETSBELOW /* Compatibility */,
    
    qr_GANONINTRO, //bugfix//
    qr_MELEEMAGICCOST/*DEPRECATED*/,
    qr_OLDMIRRORCOMBOS,
    qr_BROKENBOOKCOST,
    qr_OLDSIDEVIEWSPIKES,
    //21
	qr_OLDINFMAGIC/* Compatibility */, //Infinite magic prevents items from draining rupees
	qr_NEVERDISABLEAMMOONSUBSCREEN, qr_ITEMSCRIPTSKEEPRUNNING,
	qr_SCRIPTSRUNINHEROSTEPFORWARD, /*qr_SCRIPTDRAWSINCANCELWARP,*/ qr_FIXSCRIPTSDURINGSCROLLING, qr_SCRIPTDRAWSINWARPS,
	qr_DYINGENEMYESDONTHURTHERO, //t.b.a
	qr_SIDEVIEWTRIFORCECELLAR,
	//22
	qr_OUTOFBOUNDSENEMIES,
	qr_EPILEPSY,
	qr_SCRIPT_FRIENDLY_ENEMY_TYPES,
	qr_SMARTDROPS,
	qr_NO_L_R_BUTTON_INVENTORY_SWAP,
	qr_USE_EX1_EX2_INVENTORYSWAP,
	qr_NOFASTMODE,
	qr_OLD_F6 /* Compatibility */,
	//23
	qr_BROKEN_ASKIP_Y_FRAMES /* Compatibility */, qr_ENEMY_BROKEN_TOP_HALF_SOLIDITY /* Compatibility */, qr_SIDEVIEWLADDER_FACEUP, qr_ITEMS_IGNORE_SIDEVIEW_PLATFORMS,
	qr_DOWN_FALL_THROUGH_SIDEVIEW_PLATFORMS, qr_SIDEVIEW_FALLTHROUGH_USES_DRUNK, qr_DOWN_DOESNT_GRAB_LADDERS, qr_DOWNJUMP_FALL_THROUGH_SIDEVIEW_PLATFORMS,
	//24
	qr_OLD_SIDEVIEW_CEILING_COLLISON /* Compatibility */, qr_0AFRAME_ITEMS_IGNORE_AFRAME_CHANGES /* Compatibility */, qr_OLD_ENEMY_KNOCKBACK_COLLISION /* Compatibility */, qr_FADEBLACKWIPE,
	qr_PASSIVE_SUBSCRIPT_RUNS_DURING_ACTIVE_SUBSCRIPT, qr_DMAP_ACTIVE_RUNS_DURING_ACTIVE_SUBSCRIPT, qr_ANIMATECUSTOMWEAPONS, qr_WEAPONSMOVEOFFSCREEN,
	//25
	qr_CHECKSCRIPTWEAPONOFFSCREENCLIP, qr_SHORTDGNWALK, qr_SCRIPT_WEAPONS_UNIQUE_SPRITES, qr_ANGULAR_REFLECTED_WEAPONS,
	qr_MIRRORS_USE_WEAPON_CENTER, qr_CUSTOMCOMBOSLAYERS1AND2, qr_BUSHESONLAYERS1AND2, qr_NEW_HERO_MOVEMENT,
	//26
	qr_DISABLE_4WAY_GRIDLOCK, qr_NEW_COMBO_ANIMATION, qr_OLD_STRING_EDITOR_MARGINS, qr_NO_OVERWRITING_HOPPING,
	qr_DUNGEON_DMAPS_PERM_SECRETS, qr_STRING_FRAME_OLD_WIDTH_HEIGHT, qr_NO_SCROLL_WHILE_IN_AIR, qr_INSTANT_RESPAWN,
	//27
	qr_BROKEN_OVERWORLD_MINIMAP, qr_NO_STUNLOCK, qr_GREATER_MAX_TIME, qr_BROKEN_RING_POWER,
	qr_NO_OVERWORLD_MAP_CHARTING, qr_DUNGEONS_USE_CLASSIC_CHARTING, qr_ARROWS_ALWAYS_PENETRATE, qr_SWORDBEAMS_ALWAYS_PENETRATE, 
	//28
	qr_SET_XBUTTON_ITEMS, qr_SMARTER_WATER, qr_NO_HOPPING, qr_NO_SOLID_SWIM, 
	qr_WATER_ON_LAYER_1, qr_WATER_ON_LAYER_2, qr_SHALLOW_SENSITIVE, qr_SMARTER_SMART_SCROLL,
	//29
	qr_INSTANT_CONTINUE, qr_NONHEAVY_BLOCKTRIGGER_PERM, qr_SET_YBUTTON_ITEMS, qr_CORRECTED_EW_BRANG_ANIM,
	qr_SCRIPT_WRITING_HEROSTEP_DOESNT_CARRY_OVER, qr_OVERHEAD_COMBOS_L1_L2, qr_ALLOW_EDITING_COMBO_0, qr_OLD_CHEST_COLLISION,
	//30
	qr_AUTOCOMBO_LAYER_1, qr_AUTOCOMBO_LAYER_2, qr_TRUEFIXEDBOMBSHIELD, qr_BOMBSPIERCESHIELD,
	qr_BROKEN_HORIZONTAL_WEAPON_ANIM, qr_NEW_DARKROOM, qr_NEWDARK_L6, qr_ENEMIES_SECRET_ONLY_16_31,
	//31
	qr_SCREEN80_OWN_MUSIC, qr_OLDCS2, qr_HARDCODED_ENEMY_ANIMS, qr_OLD_ITEMDATA_SCRIPT_TIMING,
	qr_SIDESWIM, qr_SIDESWIMDIR, qr_PUSHBLOCK_LAYER_1_2, qr_NEWDARK_SCROLLEDGE,
	//32
	qr_STEPTEMP_SECRET_ONLY_16_31, qr_ALLTRIG_PERMSEC_NO_TEMP, qr_HARDCODED_LITEM_LTMS, qr_NO_BOTTLE_IF_ANY_COUNTER_FULL,
	qr_LIGHTBEAM_TRANSPARENT, qr_CANDLES_SHARED_LIMIT, qr_OLD_RESPAWN_POINTS, qr_HOOKSHOTALLLAYER,
	//33
	qr_ANONE_NOANIM, qr_BLOCKHOLE_SAME_ONLY, qr_SWITCHOBJ_RUN_SCRIPT, qr_ITEMCOMBINE_NEW_PSTR,
	qr_ITEMCOMBINE_CONTINUOUS, qr_SCC_ITEM_COMBINES_ITEMS, qr_SCROLLING_KILLS_CHARGE, qr_CUSTOMWEAPON_IGNORE_COST,
	//34
	qr_BLOCKS_DONT_LOCK_OTHER_LAYERS, qr_SCC_GOTO_RESPECTS_CONTFLAG, qr_BROKEN_KEEPOLD_FLAG, qr_KEEPOLD_APPLIES_RETROACTIVELY,
	qr_PASSIVE_ITEM_SCRIPT_ONLY_HIGHEST, qr_OLD_HALF_MAGIC, qr_LEVEL_RESTART_CONT_POINT, qr_SUBSCR_OLD_SELECTOR,
	//35
	qr_OLD_FAIRY_LIMIT, qr_FAIRYDIR, qr_ARROWCLIP, qr_CONT_SWORD_TRIGGERS, 
	qr_OLD_210_WATER, qr_8WAY_SHOT_SFX, qr_COPIED_SWIM_SPRITES, qr_WRONG_BRANG_TRAIL_DIR,
	//36
	qr_192b163_WARP, qr_210_WARPRETURN, qr_LESS_AWFUL_SIDESPIKES, qr_OLD_LADDER_ITEM_SIDEVIEW,
	qr_OLD_SECRETMONEY, qr_OLD_DOORREPAIR, qr_OLD_POTION_OR_HC, qr_NO_LANMOLA_RINGLEADER,
	//37
	qr_HARDCODED_BS_PATRA, qr_PATRAS_USE_HARDCODED_OFFSETS, qr_BROKEN_BIG_ENEMY_ANIMATION, qr_BROKEN_ATTRIBUTE_31_32,
	qr_CAN_PLACE_GANON, qr_CAN_PLACE_TRAPS, qr_FIND_CLOSEST_BAIT, qr_OLD_FLAMETRAIL_DURATION,
	//38
	qr_PERMANENT_WHISTLE_SECRETS, qr_SMARTER_DROPS, qr_WAVY_NO_EPILEPSY, qr_WAVY_NO_EPILEPSY_2,
	qr_DYING_ENEMIES_IGNORE_STUN, qr_SHOP_ITEMS_VANISH, qr_ANGULAR_REFLECT_BROKEN, qr_CSET1_LEVEL,
	//39
	qr_CSET5_LEVEL, qr_CSET7_LEVEL, qr_CSET8_LEVEL, qr_FADECS1,
	qr_FADECS7, qr_FADECS8, qr_FADECS9, qr_UNBEATABLES_DONT_KEEP_DEAD,
	//40
	qr_NO_LEAVE_ONE_ENEMY_ALIVE_TRICK, qr_OLD_BRIDGE_COMBOS, qr_BROKEN_Z3_ANIMATION, qr_OLD_TILE_INITIALIZATION,
	qr_FLUCTUATING_ENEMY_JUMP, qr_SPRITE_JUMP_IS_TRUNCATED, qr_BUGGY_BUGGY_SLASH_TRIGGERS, qr_OLD_DRAWOFFSET,
	//41
	qr_BROKEN_DRAWSCREEN_FUNCTIONS, qr_ENEMY_DROPS_USE_HITOFFSETS, qr_BROKEN_ITEM_CARRYING, qr_LEEVERS_DONT_OBEY_STUN,
	qr_QUAKE_STUNS_LEEVERS, qr_GANON_CANT_SPAWN_ON_CONTINUE, qr_WIZZROBES_DONT_OBEY_STUN, qr_OLD_BUG_NET,
	//42
	qr_MANHANDLA_BLOCK_SFX, qr_GRASS_SENSITIVE, qr_BETTER_RAFT, qr_BETTER_RAFT_2,
	qr_RAFT_SOUND, qr_WARPS_RESTART_DMAPSCRIPT, qr_DMAP_0_CONTINUE_BUG, qr_SCRIPT_WARPS_DMAP_SCRIPT_TOGGLE,
	//43
	qr_OLD_SCRIPTED_KNOCKBACK, qr_OLD_KEESE_Z_AXIS, qr_POLVIRE_NO_SHADOW, qr_CONVEYORS_L1_L2,
	qr_CUSTOMCOMBOS_EVERY_LAYER, qr_SUBSCR_BACKWARDS_ID_ORDER, qr_FASTCOUNTERDRAIN, qr_OLD_LOCKBLOCK_COLLISION,
	//44
	qr_DECO_2_YOFFSET, qr_SCREENSTATE_80s_BUG, qr_AUTOCOMBO_ANY_LAYER, qr_GOHMA_UNDAMAGED_BUG,
	qr_FFCPRELOAD_BUGGED_LOAD, qr_SWITCHES_AFFECT_MOVINGBLOCKS, qr_BROKEN_GETPIXEL_VALUE, qr_NO_LIFT_SPRITE,
	//45
	qr_OLD_SIDEVIEW_LANDING_CODE, qr_OLD_FFC_SPEED_CAP, qr_OLD_WIZZROBE_SUBMERGING, qr_SPARKLES_INHERIT_PROPERTIES,
	qr_BROKENHITBY, qr_ENEMIES_DONT_SCRIPT_FIRST_FRAME, qr_OLD_CONVEYOR_COLLISION, qr_SENSITIVE_SOLID_DAMAGE,
	//46
	qr_LENIENT_SOLID_DAMAGE, qr_NO_SIDEVIEW_SOLID_DAMAGE,
	//DEEDEE SPOT
	//50
	qr_OLD_FFC_FUNCTIONALITY = 50*8, qr_OLD_SHALLOW_SFX, qr_BUGGED_LAYERED_FLAGS, qr_HARDCODED_FFC_BUSH_DROPS,
	qr_POUNDLAYERS1AND2, qr_MOVINGBLOCK_FAKE_SOLID, qr_NEW_HERO_MOVEMENT2, qr_CARRYABLE_NO_ACROSS_SCREEN,
	//51
	qr_NO_SCROLL_WHILE_CARRYING, qr_HELD_BOMBS_EXPLODE, qr_BROKEN_MOVING_BOMBS, qr_OLD_BOMB_HITBOXES,
	qr_SCROLLWARP_NO_RESET_FRAME, qr_BROKEN_RAFT_SCROLL, qr_BROKEN_INPUT_DOWN_STATE, qr_OLD_GUY_HANDLING,
	//52
	qr_FREEFORM_SUBSCREEN_CURSOR, qr_SUBSCR_PRESS_TO_EQUIP, qr_FAIRY_FLAG_COMPAT, qr_MIRROR_PRISM_LAYERS,
	qr_OLD_LENS_LAYEREFFECT, qr_PUSHBLOCK_SPRITE_LAYER,
	//EMILY SPOT
	//60
	//CONNOR SPOT qr_ = 60*8,
	//70
	//MOOSH SPOT qr_ = 70*8,
	qr_OLD_SCRIPT_VOLUME = 70 * 8,
	
	//80 //PARSER SPOT
	qr_PARSER_250DIVISION = 80*8, qr_PARSER_NO_LOGGING, qr_PARSER_SHORT_CIRCUIT, qr_PARSER_BOOL_TRUE_DECIMAL,
	qr_SPRITEXY_IS_FLOAT, qr_PARSER_TRUE_INT_SIZE,
	qr_WPNANIMFIX, /* Not Implemented : This was in 2.50.2, but never used. */ 
	qr_NOSCRIPTSDURINGSCROLL, /* Not Implemented : This was in 2.50.2, but never used. */
	//81
	qr_OLDSPRITEDRAWS, qr_WEAPONSHADOWS, qr_ITEMSHADOWS, qr_OLDEWPNPARENT,
	qr_OLDCREATEBITMAP_ARGS, qr_OLDQUESTMISC, qr_PARSER_FORCE_INLINE, qr_CLEARINITDONSCRIPTCHANGE,
	//82
	qr_NOFFCWAITDRAW, qr_NOITEMWAITDRAW, qr_TRACESCRIPTIDS, qr_FIXDRUNKINPUTS,
	qr_PARSER_BINARY_32BIT, qr_ALWAYS_DEALLOCATE_ARRAYS, qr_ONDEATH_RUNS_AFTER_DEATH_ANIM, qr_DISALLOW_SETTING_RAFTING,
	//83
	qr_WEAPONS_EXTRA_FRAME, qr_250WRITEEDEFSCRIPT, qr_SETENEMYWEAPONSPRITESONWPNCHANGE, qr_BROKENCHARINTDRAWING,
	qr_WRITING_NPC_WEAPON_UNIQUE_SPRITES, qr_COMBOSCRIPTS_LAYER_0, qr_COMBOSCRIPTS_LAYER_1, qr_COMBOSCRIPTS_LAYER_2,
	//84
	qr_COMBOSCRIPTS_LAYER_3, qr_COMBOSCRIPTS_LAYER_4, qr_COMBOSCRIPTS_LAYER_5, qr_COMBOSCRIPTS_LAYER_6,
	qr_OLD_INIT_SCRIPT_TIMING, qr_DO_NOT_DEALLOCATE_INIT_AND_SAVELOAD_ARRAYS, qr_BITMAP_AND_FILESYSTEM_PATHS_ALWAYS_RELATIVE, qr_PARSER_STRINGSWITCH_INSENSITIVE,
	//85
	qr_OLD_SLASHNEXT_SECRETS, qr_STEP_IS_FLOAT, qr_OLDMAPDATAFLAGS, qr_OLD_PRINTF_ARGS,
	qr_PASSIVE_SUBSCRIPT_RUNS_WHEN_GAME_IS_FROZEN, qr_WRITE_ENTRYPOINTS_AFFECTS_HEROCLASS, qr_LOG_INVALID_UID_LOAD, qr_COMBODATA_INITD_MULT_TENK,
	//86
	qr_ZS_NO_NEG_ARRAY,
	
    qr_MAX
};

// Unsaved compatibility rules
enum extraRules
{
    er_BITMAPOFFSET, //to be deprecated by qr_BITMAPOFFSETFIX
	er_SHORTDGNWALK,
	er_MAGICCOSTSWORD, //BEAMS Only
	er_BROKENCHARINTDRAWING, //pre-2.53 fix to DrawInteger() and DrarCharacter() -Z
	er_SETENEMYWEAPONSPRITESONWPNCHANGE, //er_OLDSIDEVIEWSPIKES,
	er_MAX
};

bool get_qr(int index);
void set_qr(int index,bool state);
bool get_er(int index);
void set_er(int index,bool state);

#endif

