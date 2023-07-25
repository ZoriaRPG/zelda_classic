#include "new_subscr.h"

int shadow_x(int shadow)
{
	switch(shadow)
	{
		case sstsSHADOWU:
		case sstsOUTLINE8:
		case sstsOUTLINEPLUS:
		case sstsOUTLINEX:
		case sstsSHADOWEDU:
		case sstsOUTLINED8:
		case sstsOUTLINEDPLUS:
		case sstsOUTLINEDX:
			return -1;
	}
	return 0;
}
int shadow_y(int shadow)
{
	switch(shadow)
	{
		case sstsOUTLINE8:
		case sstsOUTLINEPLUS:
		case sstsOUTLINEX:
		case sstsOUTLINED8:
		case sstsOUTLINEDPLUS:
		case sstsOUTLINEDX:
			return -1;
	}
	return 0;
}
int shadow_w(int shadow)
{
	switch(shadow)
	{
		case sstsSHADOW:
		case sstsSHADOWU:
		case sstsOUTLINE8:
		case sstsOUTLINEPLUS:
		case sstsOUTLINEX:
		case sstsSHADOWED:
		case sstsSHADOWEDU:
		case sstsOUTLINED8:
		case sstsOUTLINEDPLUS:
		case sstsOUTLINEDX:
			return 1;
	}
	return 0;
}
int shadow_h(int shadow)
{
	switch(shadow)
	{
        case sstsSHADOW:
        case sstsSHADOWU:
        case sstsOUTLINE8:
        case sstsOUTLINEPLUS:
        case sstsOUTLINEX:
        case sstsSHADOWED:
        case sstsSHADOWEDU:
        case sstsOUTLINED8:
        case sstsOUTLINEDPLUS:
        case sstsOUTLINEDX:
			return 1;
	}
	return 0;
}

void SubscrPage::draw(BITMAP* dest, int32_t xofs, int32_t yofs, byte pos, bool showtime)
{
	for(SubscrWidget& widg : contents)
	{
		if(widg.visible(pos,showtime))
			widg.draw(dest,xofs,yofs);
	}
}

int32_t SubscrColorInfo::get_color()
{
	int32_t ret;
	
	switch(type)
	{
		case ssctSYSTEM:
			ret=(color==-1)?color:vc(color);
			break;
			
		case ssctMISC:
			switch(color)
			{
				case ssctTEXT:
					ret=QMisc.colors.text;
					break;
					
				case ssctCAPTION:
					ret=QMisc.colors.caption;
					break;
					
				case ssctOVERWBG:
					ret=QMisc.colors.overw_bg;
					break;
					
				case ssctDNGNBG:
					ret=QMisc.colors.dngn_bg;
					break;
					
				case ssctDNGNFG:
					ret=QMisc.colors.dngn_fg;
					break;
					
				case ssctCAVEFG:
					ret=QMisc.colors.cave_fg;
					break;
					
				case ssctBSDK:
					ret=QMisc.colors.bs_dk;
					break;
					
				case ssctBSGOAL:
					ret=QMisc.colors.bs_goal;
					break;
					
				case ssctCOMPASSLT:
					ret=QMisc.colors.compass_lt;
					break;
					
				case ssctCOMPASSDK:
					ret=QMisc.colors.compass_dk;
					break;
					
				case ssctSUBSCRBG:
					ret=QMisc.colors.subscr_bg;
					break;
					
				case ssctSUBSCRSHADOW:
					ret=QMisc.colors.subscr_shadow;
					break;
					
				case ssctTRIFRAMECOLOR:
					ret=QMisc.colors.triframe_color;
					break;
					
				case ssctBMAPBG:
					ret=QMisc.colors.bmap_bg;
					break;
					
				case ssctBMAPFG:
					ret=QMisc.colors.bmap_fg;
					break;
					
				case ssctHERODOT:
					ret=QMisc.colors.hero_dot;
					break;
					
				default:
					ret=(zc_oldrand()*1000)%256;
					break;
			}
			
			break;
			
		default:
			ret=(type<<4)+color;
	}
	
	return ret;
}

int32_t SubscrColorInfo::get_cset()
{
	int32_t ret=type;
	
	switch(type)
	{
		case ssctMISC:
			switch(color)
			{
				case sscsTRIFORCECSET:
					ret=QMisc.colors.triforce_cset;
					break;
					
				case sscsTRIFRAMECSET:
					ret=QMisc.colors.triframe_cset;
					break;
					
				case sscsOVERWORLDMAPCSET:
					ret=QMisc.colors.overworld_map_cset;
					break;
					
				case sscsDUNGEONMAPCSET:
					ret=QMisc.colors.dungeon_map_cset;
					break;
					
				case sscsBLUEFRAMECSET:
					ret=QMisc.colors.blueframe_cset;
					break;
					
				case sscsHCPIECESCSET:
					ret=QMisc.colors.HCpieces_cset;
					break;
					
				case sscsSSVINECSET:
					ret=wpnsbuf[iwSubscreenVine].csets&15;
					break;
					
				default:
					ret=(zc_oldrand()*1000)%256;
					break;
			}
			break;
	}
	
	return ret;
}

void SubscrColorInfo::load_old(subscreen_object const& old, int indx)
{
	if(indx < 1 || indx > 3) return;
	switch(indx)
	{
		case 1:
			type = old.colortype1;
			color = old.color1;
			break;
		case 2:
			type = old.colortype2;
			color = old.color2;
			break;
		case 3:
			type = old.colortype3;
			color = old.color3;
			break;
	}
}

SubscrWidget::SubscrWidget(subscreen_object const& old) : SubscrWidget()
{
	if(old.type > ssoNONE && old.type < ssoMAX)
		zprint2("Failed convert sso type '%d'\n", old.type); //!TODO remove trace
	load_old(old);
}
void SubscrWidget::load_old(subscreen_object const& old)
{
	type = old.type;
	posflags = old.pos;
	x = old.x;
	y = old.y;
	w = old.w;
	h = old.h;
}
int16_t SubscrWidget::getX() const
{
	return x;
}
int16_t SubscrWidget::getY() const
{
	return y;
}
word SubscrWidget::getW() const
{
	return w;
}
word SubscrWidget::getH() const
{
	return h;
}
int16_t SubscrWidget::getXOffs() const
{
	return 0;
}
int16_t SubscrWidget::getYOffs() const
{
	return 0;
}
byte SubscrWidget::getType() const
{
	return ssoNULL;
}
void SubscrWidget::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	
}
void SubscrWidget::visible(byte pos, bool showtime) const
{
	return posflags&pos;
}

SW_2x2Frame::SW_2x2Frame(subscreen_object const& old) : SW_2x2Frame()
{
	load_old(old);
}
void SW_2x2Frame::load_old(subscreen_object const& old)
{
	SubscrWidget::load_old(old);
	tile = old.d1;
	cs.load_old(old,1);
}
word SW_2x2Frame::getW() const
{
	return w*8;
}
word SW_2x2Frame::getH() const
{
	return h*8;
}
byte SW_2x2Frame::getType() const
{
	return sso2X2FRAME;
}
void SW_2x2Frame::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	frame2x2(dest, x+xofs, y+yofs, tile, cs.get_cset(), w, h, 0,
		flags&SUBSCR_2X2FR_OVERLAY, flags&SUBSCR_2X2FR_TRANSP);
}

SW_Text::SW_Text(subscreen_object const& old) : SW_Text()
{
	load_old(old);
}
void SW_Text::load_old(subscreen_object const& old)
{
	SubscrWidget::load_old(old);
	if(old.dp1) text = (char*)old.dp1;
	else text.clear();
	fontid = to_real_font(old.d1);
	align = old.d2;
	shadtype = old.d3;
	c_text.load_old(old,1);
	c_shadow.load_old(old,2);
	c_bg.load_old(old,3);
}
int16_t SW_Text::getX() const
{
	return x+shadow_x(shadtype);
}
int16_t SW_Text::getY() const
{
	return y+shadow_y(shadtype);
}
word SW_Text::getW() const
{
	return text_length(get_zc_font(fontid), text.c_str());
}
word SW_Text::getH() const
{
	return text_height(get_zc_font(fontid));
}
int16_t SW_Text::getXOffs() const
{
	switch(align)
	{
		case sstaCENTER:
			return -getW()/2;
		case sstaRIGHT:
			return -getW();
	}
	return 0;
}
byte SW_Text::getType() const
{
	return ssoTEXT;
}
void SW_Text::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	FONT* tempfont = get_zc_font(fontid);
	textout_styled_aligned_ex(dest,tempfont,text.c_str(),getX()+xofs,getY()+yofs,
		shadtype,align,c_text.get_color(),c_shadow.get_color(),c_bg.get_color());
}

SW_Line::SW_Line(subscreen_object const& old) : SW_Line()
{
	load_old(old);
}
void SW_Line::load_old(subscreen_object const& old)
{
	SubscrWidget::load_old(old);
	SETFLAG(flags,SUBSCR_LINE_TRANSP,old.d4);
	c_line.load_old(old,1);
}
byte SW_Line::getType() const
{
	return ssoLINE;
}
void SW_Line::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	if(flags&SUBSCR_LINE_TRANSP)
		drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
	
	line(dest, x+xofs, y+yofs, x+xofs+w-1, y+yofs+h-1, c_line.get_color());
	
	if(flags&SUBSCR_LINE_TRANSP)
		drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
}

SW_Rect::SW_Rect(subscreen_object const& old) : SW_Rect()
{
	load_old(old);
}
void SW_Rect::load_old(subscreen_object const& old)
{
	SubscrWidget::load_old(old);
	SETFLAG(flags,SUBSCR_RECT_TRANSP,old.d2);
	SETFLAG(flags,SUBSCR_RECT_FILLED,old.d1);
	c_fill.load_old(old,2);
	c_outline.load_old(old,1);
}
byte SW_Rect::getType() const
{
	return ssoRECT;
}
void SW_Rect::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	if(flags&SUBSCR_RECT_TRANSP)
		drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
	
	auto x2 = x+xofs, y2 = y+yofs;
	if(flags&SUBSCR_RECT_FILLED)
		rectfill(dest, x2, y2, x2+w-1, y2+h-1, c_fill.get_color());
	
	rect(dest, x2, y2, x2+w-1, y2+h-1, c_outline.get_color());
	
	if(flags&SUBSCR_RECT_TRANSP)
		drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
}

SW_Time::SW_Time(subscreen_object const& old) : SW_Time()
{
	load_old(old);
}
void SW_Time::load_old(subscreen_object const& old)
{
	SubscrWidget::load_old(old);
	timeType = old.type;
	fontid = to_real_font(old.d1);
	align = old.d2;
	shadtype = old.d3;
	c_text.load_old(old,1);
	c_shadow.load_old(old,2);
	c_bg.load_old(old,3);
}
int16_t SW_Time::getX() const
{
	return x+shadow_x(shadtype);
}
int16_t SW_Time::getY() const
{
	return y+shadow_y(shadtype);
}
word SW_Time::getW() const
{
	return text_length(get_zc_font(fontid), time_str_short2(game->get_time())) + shadow_w(shadtype);
}
word SW_Time::getH() const
{
	return text_height(get_zc_font(fontid)) + shadow_h(shadtype);
}
int16_t SW_Time::getXOffs() const
{
	switch(align)
	{
		case sstaCENTER:
			return -getW()/2;
		case sstaRIGHT:
			return -getW();
	}
	return 0;
}
byte SW_Time::getType() const
{
	return timeType; //ssoBSTIME,ssoTIME,ssoSSTIME
}
void SW_Time::draw(BITMAP* dest, int32_t xofs, int32_t yofs) const
{
	char *ts;
	auto tm = game ? game->get_time() : 0;
	switch(timeType)
	{
		case ssoBSTIME:
			ts = time_str_short2(tm);
			break;
		case ssoTIME:
		case ssoSSTIME:
			ts = time_str_med(tm);
			break;
	}
	FONT* tempfont = get_zc_font(fontid);
	textout_styled_aligned_ex(dest,tempfont,ts,getX()+xofs,getY()+yofs,
		shadtype,align,c_text.get_color(),c_shadow.get_color(),c_bg.get_color());
}
void SW_Time::visible(byte pos, bool showtime) const
{
	return showtime && SubscrWidget::visible(pos,showtime);
}



SubscrWidget SubscrWidget::fromOld(subscreen_object const& old)
{
	switch(old.type)
	{
		case sso2X2FRAME:
			return SW_2x2Frame(old);
		case ssoTEXT:
			return SW_Text(old);
		case ssoLINE:
			return SW_Line(old);
		case ssoRECT:
			return SW_Rect(old);
		case ssoBSTIME:
		case ssoTIME:
		case ssoSSTIME:
			return SW_Time(old);
		case ssoMAGICMETER:
		case ssoLIFEMETER:
		case ssoBUTTONITEM:
		case ssoICON:
		case ssoCOUNTER:
		case ssoCOUNTERS:
		case ssoMINIMAPTITLE:
		case ssoMINIMAP:
		case ssoLARGEMAP:
		case ssoCLEAR:
		case ssoCURRENTITEM:
		case ssoITEM:
		case ssoTRIFRAME:
		case ssoTRIFORCE:
		case ssoTILEBLOCK:
		case ssoMINITILE:
		case ssoSELECTOR1:
		case ssoSELECTOR2:
		case ssoMAGICGAUGE:
		case ssoLIFEGAUGE:
		case ssoTEXTBOX:
		case ssoCURRENTITEMTILE:
		case ssoSELECTEDITEMTILE:
		case ssoCURRENTITEMTEXT:
		case ssoCURRENTITEMNAME:
		case ssoSELECTEDITEMNAME:
		case ssoCURRENTITEMCLASSTEXT:
		case ssoCURRENTITEMCLASSNAME:
		case ssoSELECTEDITEMCLASSNAME:
			break; //!TODO
	}
	return SubscrWidget(old); //ssoNULL type result
}

