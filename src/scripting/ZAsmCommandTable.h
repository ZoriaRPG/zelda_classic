// Defines ZASM_COMMAND_TABLE using the "X Macro" idiom. Arguments are the
// first and second argument types, and the symbol.

#ifndef ZASM_COMMAND_TABLE
#define ZASM_COMMAND_TABLE \
	X(ArgRegister, ArgValue,    SETV) \
	X(ArgRegister, ArgRegister, SETR) \
	X(ArgRegister, ArgRegister, ADDR) \
	X(ArgRegister, ArgValue,    ADDV) \
	X(ArgRegister, ArgRegister, SUBR) \
	X(ArgRegister, ArgValue,    SUBV) \
	X(ArgRegister, ArgRegister, MULTR) \
	X(ArgRegister, ArgValue,    MULTV) \
	X(ArgRegister, ArgRegister, DIVR) \
	X(ArgRegister, ArgValue,    DIVV) \
	X(ArgNone,     ArgNone,     WAITFRAME) \
	X(ArgLabel,    ArgNone,     GOTO) \
	X(ArgNone,     ArgNone,     CHECKTRIG) \
	X(ArgValue,    ArgValue,    WARP) \
	X(ArgRegister, ArgRegister, COMPARER) \
	X(ArgRegister, ArgValue,    COMPAREV) \
	X(ArgLabel,    ArgNone,     GOTOTRUE) \
	X(ArgLabel,    ArgNone,     GOTOFALSE) \
	X(ArgLabel,    ArgNone,     GOTOLESS) \
	X(ArgLabel,    ArgNone,     GOTOMORE) \
	X(ArgRegister, ArgRegister, LOAD1) \
	X(ArgRegister, ArgRegister, LOAD2) \
	X(ArgRegister, ArgRegister, SETA1) \
	X(ArgRegister, ArgRegister, SETA2) \
	X(ArgNone,     ArgNone,     QUIT) \
	X(ArgRegister, ArgRegister, SINR) \
	X(ArgRegister, ArgValue,    SINV) \
	X(ArgRegister, ArgRegister, COSR) \
	X(ArgRegister, ArgValue,    COSV) \
	X(ArgRegister, ArgRegister, TANR) \
	X(ArgRegister, ArgValue,    TANV) \
	X(ArgRegister, ArgRegister, MODR) \
	X(ArgRegister, ArgValue,    MODV) \
	X(ArgRegister, ArgNone,     ABS) \
	X(ArgRegister, ArgRegister, MINR) \
	X(ArgRegister, ArgValue,    MINV) \
	X(ArgRegister, ArgRegister, MAXR) \
	X(ArgRegister, ArgValue,    MAXV) \
	X(ArgRegister, ArgRegister, RNDR) \
	X(ArgRegister, ArgValue,    RNDV) \
	X(ArgRegister, ArgNone,     FACTORIAL) \
	X(ArgRegister, ArgRegister, POWERR) \
	X(ArgRegister, ArgValue,    POWERV) \
	X(ArgRegister, ArgRegister, IPOWERR) \
	X(ArgRegister, ArgValue,    IPOWERV) \
	X(ArgRegister, ArgRegister, ANDR) \
	X(ArgRegister, ArgValue,    ANDV) \
	X(ArgRegister, ArgRegister, ORR) \
	X(ArgRegister, ArgValue,    ORV) \
	X(ArgRegister, ArgRegister, XORR) \
	X(ArgRegister, ArgValue,    XORV) \
	X(ArgRegister, ArgRegister, NANDR) \
	X(ArgRegister, ArgValue,    NANDV) \
	X(ArgRegister, ArgRegister, NORR) \
	X(ArgRegister, ArgValue,    NORV) \
	X(ArgRegister, ArgRegister, XNORR) \
	X(ArgRegister, ArgValue,    XNORV) \
	X(ArgRegister, ArgNone,     NOT) \
	X(ArgRegister, ArgRegister, LSHIFTR) \
	X(ArgRegister, ArgValue,    LSHIFTV) \
	X(ArgRegister, ArgRegister, RSHIFTR) \
	X(ArgRegister, ArgValue,    RSHIFTV) \
	X(ArgRegister, ArgNone,     TRACER) \
	X(ArgValue,    ArgNone,     TRACEV) \
	X(ArgNone,     ArgNone,     TRACE3) \
	X(ArgLabel,    ArgRegister, LOOP) \
	X(ArgRegister, ArgNone,     PUSHR) \
	X(ArgValue,    ArgNone,     PUSHV) \
	X(ArgRegister, ArgNone,     POP) \
	X(ArgRegister, ArgRegister, ENQUEUER) \
	X(ArgRegister, ArgValue,    ENQUEUEV) \
	X(ArgRegister, ArgNone,     DEQUEUE) \
	X(ArgRegister, ArgNone,     PLAYSOUNDR) \
	X(ArgValue,    ArgNone,     PLAYSOUNDV) \
	X(ArgRegister, ArgNone,     LOADLWEAPONR) \
	X(ArgValue,    ArgNone,     LOADLWEAPONV) \
	X(ArgRegister, ArgNone,     LOADITEMR) \
	X(ArgValue,    ArgNone,     LOADITEMV) \
	X(ArgRegister, ArgNone,     LOADNPCR) \
	X(ArgValue,    ArgNone,     LOADNPCV) \
	X(ArgRegister, ArgNone,     CREATELWEAPONR) \
	X(ArgValue,    ArgNone,     CREATELWEAPONV) \
	X(ArgRegister, ArgNone,     CREATEITEMR) \
	X(ArgValue,    ArgNone,     CREATEITEMV) \
	X(ArgRegister, ArgNone,     CREATENPCR) \
	X(ArgValue,    ArgNone,     CREATENPCV) \
	X(ArgRegister, ArgRegister, LOADI) \
	X(ArgRegister, ArgRegister, STOREI) \
	X(ArgRegister, ArgNone,     GOTOR) \
	X(ArgRegister, ArgValue,    SQROOTV) \
	X(ArgRegister, ArgRegister, SQROOTR) \
	X(ArgRegister, ArgNone,     CREATEEWEAPONR) \
	X(ArgValue,    ArgNone,     CREATEEWEAPONV) \
	X(ArgValue,    ArgValue,    PITWARP) \
	X(ArgRegister, ArgRegister, WARPR) \
	X(ArgRegister, ArgRegister, PITWARPR) \
	X(ArgRegister, ArgNone,     CLEARSPRITESR) \
	X(ArgValue,    ArgNone,     CLEARSPRITESV) \
	X(ArgNone,     ArgNone,     RECTR) \
	X(ArgNone,     ArgNone,     CIRCLER) \
	X(ArgNone,     ArgNone,     ARCR) \
	X(ArgNone,     ArgNone,     ELLIPSER) \
	X(ArgNone,     ArgNone,     LINER) \
	X(ArgNone,     ArgNone,     PUTPIXELR) \
	X(ArgNone,     ArgNone,     DRAWTILER) \
	X(ArgNone,     ArgNone,     DRAWCOMBOR) \
	X(ArgNone,     ArgNone,     ELLIPSE2) \
	X(ArgNone,     ArgNone,     SPLINER) \
	X(ArgNone,     ArgNone,     FLOODFILL) \
	X(ArgRegister, ArgNone,     COMPOUNDR) \
	X(ArgValue,    ArgNone,     COMPOUNDV) \
	X(ArgRegister, ArgNone,     MSGSTRR) \
	X(ArgValue,    ArgNone,     MSGSTRV) \
	X(ArgRegister, ArgNone,     ISVALIDITEM) \
	X(ArgRegister, ArgNone,     ISVALIDNPC) \
	X(ArgRegister, ArgNone,     PLAYMIDIR) \
	X(ArgValue,    ArgNone,     PLAYMIDIV) \
	X(ArgValue,    ArgValue,    COPYTILEVV) \
	X(ArgValue,    ArgRegister, COPYTILEVR) \
	X(ArgRegister, ArgValue,    COPYTILERV) \
	X(ArgRegister, ArgRegister, COPYTILERR) \
	X(ArgValue,    ArgValue,    SWAPTILEVV) \
	X(ArgValue,    ArgRegister, SWAPTILEVR) \
	X(ArgRegister, ArgValue,    SWAPTILERV) \
	X(ArgRegister, ArgRegister, SWAPTILERR) \
	X(ArgValue,    ArgNone,     CLEARTILEV) \
	X(ArgRegister, ArgNone,     CLEARTILER) \
	X(ArgValue,    ArgValue,    OVERLAYTILEVV) \
	X(ArgValue,    ArgRegister, OVERLAYTILEVR) \
	X(ArgRegister, ArgValue,    OVERLAYTILERV) \
	X(ArgRegister, ArgRegister, OVERLAYTILERR) \
	X(ArgValue,    ArgValue,    FLIPROTTILEVV) \
	X(ArgValue,    ArgRegister, FLIPROTTILEVR) \
	X(ArgRegister, ArgValue,    FLIPROTTILERV) \
	X(ArgRegister, ArgRegister, FLIPROTTILERR) \
	X(ArgValue,    ArgNone,     GETTILEPIXELV) \
	X(ArgRegister, ArgNone,     GETTILEPIXELR) \
	X(ArgValue,    ArgNone,     SETTILEPIXELV) \
	X(ArgRegister, ArgNone,     SETTILEPIXELR) \
	X(ArgValue,    ArgValue,    SHIFTTILEVV) \
	X(ArgValue,    ArgRegister, SHIFTTILEVR) \
	X(ArgRegister, ArgValue,    SHIFTTILERV) \
	X(ArgRegister, ArgRegister, SHIFTTILERR) \
	X(ArgRegister, ArgNone,     ISVALIDLWPN) \
	X(ArgRegister, ArgNone,     ISVALIDEWPN) \
	X(ArgRegister, ArgNone,     LOADEWEAPONR) \
	X(ArgValue,    ArgNone,     LOADEWEAPONV) \
	X(ArgRegister, ArgRegister, ALLOCATEMEMR) \
	X(ArgRegister, ArgValue,    ALLOCATEMEMV) \
	X(ArgRegister, ArgValue,    ALLOCATEGMEMV) \
	X(ArgRegister, ArgNone,     DEALLOCATEMEMR) \
	X(ArgValue,    ArgNone,     DEALLOCATEMEMV) \
	X(ArgNone,     ArgNone,     WAITDRAW) \
	X(ArgRegister, ArgNone,     ARCTANR) \
	X(ArgRegister, ArgNone,     LWPNUSESPRITER) \
	X(ArgValue,    ArgNone,     LWPNUSESPRITEV) \
	X(ArgRegister, ArgNone,     EWPNUSESPRITER) \
	X(ArgValue,    ArgNone,     EWPNUSESPRITEV) \
	X(ArgRegister, ArgNone,     LOADITEMDATAR) \
	X(ArgValue,    ArgNone,     LOADITEMDATAV) \
	X(ArgRegister, ArgNone,     BITNOT) \
	X(ArgRegister, ArgNone,     LOG10) \
	X(ArgRegister, ArgNone,     LOGE) \
	X(ArgRegister, ArgNone,     ISSOLID) \
	X(ArgRegister, ArgRegister, LAYERSCREEN) \
	X(ArgRegister, ArgRegister, LAYERMAP) \
	X(ArgRegister, ArgNone,     TRACE2R) \
	X(ArgValue,    ArgNone,     TRACE2V) \
	X(ArgNone,     ArgNone,     TRACE4) \
	X(ArgNone,     ArgNone,     TRACE5) \
	X(ArgNone,     ArgNone,     SECRETS) \
	X(ArgNone,     ArgNone,     DRAWCHARR) \
	X(ArgRegister, ArgNone,     GETSCREENFLAGS) \
	X(ArgNone,     ArgNone,     QUADR) \
	X(ArgNone,     ArgNone,     TRIANGLER) \
	X(ArgRegister, ArgRegister, ARCSINR) \
	X(ArgValue,    ArgRegister, ARCSINV) \
	X(ArgRegister, ArgRegister, ARCCOSR) \
	X(ArgValue,    ArgRegister, ARCCOSV) \
	X(ArgNone,     ArgNone,     GAMEEND) \
	X(ArgNone,     ArgNone,     DRAWINTR) \
	X(ArgRegister, ArgNone,     SETTRUE) \
	X(ArgRegister, ArgNone,     SETFALSE) \
	X(ArgRegister, ArgNone,     SETMORE) \
	X(ArgRegister, ArgNone,     SETLESS) \
	X(ArgNone,     ArgNone,     FASTTILER) \
	X(ArgNone,     ArgNone,     FASTCOMBOR) \
	X(ArgNone,     ArgNone,     DRAWSTRINGR) \
	X(ArgNone,     ArgNone,     SETSIDEWARP) \
	X(ArgNone,     ArgNone,     SAVE) \
	X(ArgRegister, ArgNone,     TRACE6) \
	X(ArgRegister, ArgNone,     DEPRECATED) \
	X(ArgNone,     ArgNone,     QUAD3DR) \
	X(ArgNone,     ArgNone,     TRIANGLE3DR) \
	X(ArgNone,     ArgNone,     SETCOLORB) \
	X(ArgNone,     ArgNone,     SETDEPTHB) \
	X(ArgNone,     ArgNone,     GETCOLORB) \
	X(ArgNone,     ArgNone,     GETDEPTHB) \
	X(ArgRegister, ArgRegister, COMBOTILE) \
	X(ArgNone,     ArgNone,     SETTILEWARP) \
	X(ArgRegister, ArgNone,     GETSCREENEFLAGS) \
	X(ArgRegister, ArgNone,     GETSAVENAME) \
	X(ArgRegister, ArgNone,     ARRAYSIZE) \
	X(ArgRegister, ArgNone,     ITEMNAME) \
	X(ArgRegister, ArgNone,     SETSAVENAME) \
	X(ArgRegister, ArgNone,     NPCNAME) \
	X(ArgRegister, ArgRegister, GETMESSAGE) \
	X(ArgRegister, ArgRegister, GETDMAPNAME) \
	X(ArgRegister, ArgRegister, GETDMAPTITLE) \
	X(ArgRegister, ArgRegister, GETDMAPINTRO) \
	X(ArgRegister, ArgRegister, ALLOCATEGMEMR) \
	X(ArgNone,     ArgNone,     BITMAPR) \
	X(ArgNone,     ArgNone,     SETRENDERTARGET) \
	X(ArgRegister, ArgRegister, PLAYENHMUSIC) \
	X(ArgRegister, ArgRegister, GETMUSICFILE) \
	X(ArgRegister, ArgNone,     GETMUSICTRACK) \
	X(ArgNone,     ArgNone,     SETDMAPENHMUSIC) \
	X(ArgNone,     ArgNone,     DRAWLAYERR) \
	X(ArgNone,     ArgNone,     DRAWSCREENR) \
	X(ArgRegister, ArgNone,     BREAKSHIELD) \
	X(ArgRegister, ArgNone,     SAVESCREEN) \
	X(ArgNone,     ArgNone,     SAVEQUITSCREEN) \
	X(ArgRegister, ArgNone,     SELECTAWPNR) \
	X(ArgValue,    ArgNone,     SELECTAWPNV) \
	X(ArgRegister, ArgNone,     SELECTBWPNR) \
	X(ArgValue,    ArgNone,     SELECTBWPNV) \
	X(ArgRegister, ArgNone,     GETSIDEWARPDMAP) \
	X(ArgRegister, ArgNone,     GETSIDEWARPSCR) \
	X(ArgRegister, ArgNone,     GETSIDEWARPTYPE) \
	X(ArgRegister, ArgNone,     GETTILEWARPDMAP) \
	X(ArgRegister, ArgNone,     GETTILEWARPSCR) \
	X(ArgRegister, ArgNone,     GETTILEWARPTYPE) \
	X(ArgRegister, ArgNone,     GETFFCSCRIPT) \
	X(ArgNone,     ArgNone,     BITMAPEXR) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_QUAD2R) \
	X(ArgNone,     ArgNone,     WAVYIN) \
	X(ArgNone,     ArgNone,     WAVYOUT) \
	X(ArgNone,     ArgNone,     ZAPIN) \
	X(ArgNone,     ArgNone,     ZAPOUT) \
	X(ArgNone,     ArgNone,     OPENWIPE) \
	X(ArgNone,     ArgNone,     FREE0x00F1) \
	X(ArgNone,     ArgNone,     FREE0x00F2) \
	X(ArgNone,     ArgNone,     FREE0x00F3) \
	X(ArgRegister, ArgRegister, SETMESSAGE) \
	X(ArgRegister, ArgRegister, SETDMAPNAME) \
	X(ArgRegister, ArgRegister, SETDMAPTITLE) \
	X(ArgRegister, ArgRegister, SETDMAPINTRO) \
	X(ArgNone,     ArgNone,     GREYSCALEON) \
	X(ArgNone,     ArgNone,     GREYSCALEOFF) \
	X(ArgRegister, ArgNone,     ENDSOUNDR) \
	X(ArgValue,    ArgNone,     ENDSOUNDV) \
	X(ArgRegister, ArgNone,     PAUSESOUNDR) \
	X(ArgValue,    ArgNone,     PAUSESOUNDV) \
	X(ArgRegister, ArgNone,     RESUMESOUNDR) \
	X(ArgValue,    ArgNone,     RESUMESOUNDV) \
	X(ArgNone,     ArgNone,     PAUSEMUSIC) \
	X(ArgNone,     ArgNone,     RESUMEMUSIC) \
	X(ArgRegister, ArgNone,     LWPNARRPTR) \
	X(ArgRegister, ArgNone,     EWPNARRPTR) \
	X(ArgRegister, ArgNone,     ITEMARRPTR) \
	X(ArgRegister, ArgNone,     IDATAARRPTR) \
	X(ArgRegister, ArgNone,     FFCARRPTR) \
	X(ArgRegister, ArgNone,     BOOLARRPTR) \
	X(ArgRegister, ArgNone,     NPCARRPTR) \
	X(ArgRegister, ArgNone,     LWPNARRPTR2) \
	X(ArgRegister, ArgNone,     EWPNARRPTR2) \
	X(ArgRegister, ArgNone,     ITEMARRPTR2) \
	X(ArgRegister, ArgNone,     IDATAARRPTR2) \
	X(ArgRegister, ArgNone,     FFCARRPTR2) \
	X(ArgRegister, ArgNone,     BOOLARRPTR2) \
	X(ArgRegister, ArgNone,     NPCARRPTR2) \
	X(ArgRegister, ArgNone,     ARRAYSIZEB) \
	X(ArgRegister, ArgNone,     ARRAYSIZEF) \
	X(ArgRegister, ArgNone,     ARRAYSIZEN) \
	X(ArgRegister, ArgNone,     ARRAYSIZEL) \
	X(ArgRegister, ArgNone,     ARRAYSIZEE) \
	X(ArgRegister, ArgNone,     ARRAYSIZEI) \
	X(ArgRegister, ArgNone,     ARRAYSIZEID) \
	X(ArgNone,     ArgNone,     POLYGONR) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_POLYGON3DR) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_SETRENDERSOURCE) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_CREATEBITMAP) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_PIXELARRAYR) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_TILEARRAYR) \
	X(ArgNone,     ArgNone,     __RESERVED_FOR_COMBOARRAYR) \
	X(ArgNone,     ArgNone,     RES0000) \
	X(ArgNone,     ArgNone,     RES0001) \
	X(ArgNone,     ArgNone,     RES0002) \
	X(ArgNone,     ArgNone,     RES0003) \
	X(ArgNone,     ArgNone,     RES0004) \
	X(ArgNone,     ArgNone,     RES0005) \
	X(ArgNone,     ArgNone,     RES0006) \
	X(ArgNone,     ArgNone,     RES0007) \
	X(ArgNone,     ArgNone,     RES0008) \
	X(ArgNone,     ArgNone,     RES0009) \
	X(ArgNone,     ArgNone,     RES000A) \
	X(ArgNone,     ArgNone,     RES000B) \
	X(ArgNone,     ArgNone,     RES000C) \
	X(ArgNone,     ArgNone,     RES000D) \
	X(ArgNone,     ArgNone,     RES000E) \
	X(ArgNone,     ArgNone,     RES000F) \
	X(ArgValue,    ArgValue,    __RESERVED_FOR_CREATELWPN2VV) \
	X(ArgValue,    ArgRegister, __RESERVED_FOR_CREATELWPN2VR) \
	X(ArgRegister, ArgValue,    __RESERVED_FOR_CREATELWPN2RV) \
	X(ArgRegister, ArgRegister, __RESERVED_FOR_CREATELWPN2RR) \
	X(ArgRegister, ArgNone,     GETSCREENDOOR) \
	X(ArgRegister, ArgNone,     GETSCREENENEMY) \
	X(ArgRegister, ArgNone,     PAUSESFX) \
	X(ArgRegister, ArgNone,     RESUMESFX) \
	X(ArgRegister, ArgNone,     CONTINUESFX) \
	X(ArgRegister, ArgRegister, ADJUSTSFX) \
	X(ArgRegister, ArgNone,     GETITEMSCRIPT) \
	X(ArgRegister, ArgNone,     GETSCREENLAYOP) \
	X(ArgRegister, ArgNone,     GETSCREENSECCMB) \
	X(ArgRegister, ArgNone,     GETSCREENSECCST) \
	X(ArgRegister, ArgNone,     GETSCREENSECFLG) \
	X(ArgRegister, ArgNone,     GETSCREENLAYMAP) \
	X(ArgRegister, ArgNone,     GETSCREENLAYSCR) \
	X(ArgRegister, ArgNone,     GETSCREENPATH) \
	X(ArgRegister, ArgNone,     GETSCREENWARPRX) \
	X(ArgRegister, ArgNone,     GETSCREENWARPRY) \
	X(ArgRegister, ArgNone,     TRIGGERSECRETR) \
	X(ArgValue,    ArgNone,     TRIGGERSECRETV) \
	X(ArgRegister, ArgNone,     CHANGEFFSCRIPTR) \
	X(ArgValue,    ArgNone,     CHANGEFFSCRIPTV)
#endif