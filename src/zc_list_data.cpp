#include "zc_list_data.h"
#include "zq/zquest.h"
#include "qst.h"

extern zcmodule moduledata;
extern char *weapon_string[];
extern char *sfx_string[];
extern miscQdata QMisc;

static bool skipchar(char c)
{
	return c == 0 || c == '-';
}

GUI::ListData GUI::ZCListData::itemclass(bool numbered)
{
	map<std::string, int32_t> fams;
	std::set<std::string> famnames;
	
	for(int32_t i=0; i<itype_max; ++i)
	{
		if(!ZI.isUsableItemclass(i))
			continue; //Hidden
		char const* itname = ZI.getItemClassName(i);
        if(i < itype_last || itname[0])
		{
            char* name = new char[strlen(itname) + 7];
            if(numbered)
				sprintf(name, "%s (%03d)", itname, i);
            else strcpy(name, itname);
			std::string sname(name);
			
			fams[sname] = i;
			famnames.insert(sname);
			delete[] name;
		}
		else 
		{
			char *name = new char[12];
			if(numbered)
				sprintf(name, "zz%03d (%03d)", i, i);
			else sprintf(name, "zz%03d", i);
			std::string sname(name);
			
			fams[sname] = i;
			famnames.insert(sname);
			delete[] name;
		}
	}
	
	GUI::ListData ls;
	
	for(auto it = famnames.begin(); it != famnames.end(); ++it)
	{
		ls.add(*it, fams[*it]);
	}
	return ls;
}

GUI::ListData GUI::ZCListData::combotype(bool numbered, bool skipNone)
{
	GUI::ListData ls;
	map<std::string, int32_t> types;
	std::set<std::string> typenames;

	if(!skipNone) ls.add("(None)", 0);
	for(int32_t i=1; i<cMAX; ++i)
	{
		if(!ZI.isUsableComboType(i))
			continue; //Hidden
		char const* module_str = ZI.getComboTypeName(i);
		if(module_str[0])
		{
			char* name = new char[strlen(module_str) + 7];
			if(numbered)
				sprintf(name, "%s (%03d)", module_str, i);
			else strcpy(name, module_str);
			std::string sname(name);
			
			types[sname] = i;
			typenames.insert(sname);
			delete[] name;
		}
		else 
		{
			char *name = new char[12];
			if(numbered)
				sprintf(name, "zz%03d (%03d)", i, i);
			else sprintf(name, "zz%03d", i);
			std::string sname(name);
			
			types[sname] = i;
			typenames.insert(sname);
			delete[] name;
		}
	}

	for(auto it = typenames.begin(); it != typenames.end(); ++it)
	{
		ls.add(*it, types[*it]);
	}
	return ls;
}

GUI::ListData GUI::ZCListData::mapflag(int32_t numericalFlags, bool numbered, bool skipNone)
{
	GUI::ListData ls;
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	if(!skipNone) ls.add("(None)", 0);
	for(int32_t q = 1; q < mfMAX; ++q)
	{
		if(!ZI.isUsableMapFlag(q))
			continue; //Hidden
		char const* module_str = ZI.getMapFlagName(q);
		char* name = new char[strlen(module_str) + 7];
		if(numbered)
			sprintf(name, "%s (%03d)", module_str, q);
		else strcpy(name, module_str);
		
		std::string sname(name);
		if (numericalFlags)
		{
			ls.add(sname, q);
		}
		else
		{
			vals[sname] = q;
			names.insert(sname);
		}
		
		delete[] name;
	}
	if (!numericalFlags)
	{
		for(auto it = names.begin(); it != names.end(); ++it)
		{
			ls.add(*it, vals[*it]);
		}
	}
	
	return ls;
}

GUI::ListData GUI::ZCListData::dmaps(bool numbered)
{
	GUI::ListData ls;
	
	for(int32_t q = 0; q < MAXDMAPS; ++q)
	{
		char const* dm_str = DMaps[q].name;
		if(numbered)
		{
			char* name = new char[strlen(dm_str) + 7];
			sprintf(name, "%3d-%s", q, dm_str);
			ls.add(name, q);
			delete[] name;
		}
		else ls.add(dm_str, q);
	}
	
	return ls;
}

GUI::ListData GUI::ZCListData::counters(bool numbered, bool skipNone)
{
	GUI::ListData ls;
	// std::map<std::string, int32_t> vals;
	// std::set<std::string> names;
	
	if(!skipNone) ls.add("(None)", crNONE);
	for(int32_t q = 0; q < MAX_COUNTERS; ++q)
	{
		if(!ZI.isUsableCtr(q))
			continue; //Hidden
		char const* module_str = ZI.getCtrName(q);
		char* name = new char[strlen(module_str) + 6];
		if(numbered)
			sprintf(name, "%s (%02d)", module_str, q);
		else strcpy(name, module_str);
		
		std::string sname(name);
		
		// vals[sname] = q;
		// names.insert(sname);
		ls.add(sname, q);
		
		delete[] name;
	}
	
	// for(auto it = names.begin(); it != names.end(); ++it)
	// {
		// ls.add(*it, vals[*it]);
	// }
	
	return ls;
}

GUI::ListData GUI::ZCListData::miscsprites()
{
	std::map<std::string, int32_t> ids;
	std::set<std::string> sprnames;
	
	for(int32_t i=0; i<wMAX; ++i)
	{
		std::string sname(weapon_string[i]);
		
		ids[sname] = i;
		sprnames.insert(sname);
	}
	
	GUI::ListData ls;
	
	for(auto it = sprnames.begin(); it != sprnames.end(); ++it)
	{
		ls.add(*it, ids[*it]);
	}
	return ls;
}

GUI::ListData GUI::ZCListData::bottletype()
{
	GUI::ListData ls;
	
	ls.add("(None)", 0);
	for(int32_t q = 0; q < 64; ++q)
	{
		if(QMisc.bottle_types[q].name[0])
			ls.add(QMisc.bottle_types[q].name,q+1);
		else
		{
			char buf[8] = { 0 };
			sprintf(buf, "%2d", q+1);
			
			ls.add(buf, q+1);
		}
	}
	
	return ls;
}

GUI::ListData GUI::ZCListData::lweaptypes()
{
	std::map<std::string, int32_t> vals;
	
	std::string none(moduledata.player_weapon_names[0]);
	if(skipchar(moduledata.player_weapon_names[0][0]))
		none = "(None)";
	
	GUI::ListData ls;
	ls.add(none, 0);
	for(int32_t i=1; i<41; ++i)
	{
		if(skipchar(moduledata.player_weapon_names[i][0]))
			continue;
		
		std::string sname(moduledata.player_weapon_names[i]);
		ls.add(sname, i);
	}
	
	return ls;
}

GUI::ListData GUI::ZCListData::sfxnames(bool numbered)
{
	std::map<std::string, int32_t> vals;
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	for(int32_t i=1; i<WAV_COUNT; ++i)
	{
		char const* sfx_name = sfx_string[i];
		char* name = new char[strlen(sfx_name) + 7];
		if(numbered)
			sprintf(name, "%s (%03d)", sfx_name, i);
		else strcpy(name, sfx_name);
		ls.add(name, i);
		delete[] name;
	}
	
	return ls;
}

static void load_scriptnames(std::set<std::string> &names, std::map<std::string, int32_t> &vals,
	std::map<int32_t, script_slot_data> scrmap, int32_t count)
{
	for(int32_t i = 0; i < count; ++i)
	{
		if(!scrmap[i].scriptname[0])
			continue;
		std::string sname(scrmap[i].scriptname);
		sname += " (" + std::to_string(i+1) + ")";
		
		vals[sname] = i+1;
		names.insert(sname);
	}
}

GUI::ListData GUI::ZCListData::itemdata_script()
{
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	load_scriptnames(names,vals,itemmap,NUMSCRIPTITEM-1);
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	ls.add(names,vals);
	return ls;
}

GUI::ListData GUI::ZCListData::itemsprite_script()
{
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	load_scriptnames(names,vals,itemspritemap,NUMSCRIPTSITEMSPRITE-1);
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	ls.add(names,vals);
	return ls;
}

GUI::ListData GUI::ZCListData::ffc_script()
{
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	load_scriptnames(names,vals,ffcmap,NUMSCRIPTFFC-1);
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	ls.add(names,vals);
	return ls;
}

GUI::ListData GUI::ZCListData::lweapon_script()
{
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	load_scriptnames(names,vals,lwpnmap,NUMSCRIPTWEAPONS-1);
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	ls.add(names,vals);
	return ls;
}

GUI::ListData GUI::ZCListData::combodata_script()
{
	std::map<std::string, int32_t> vals;
	std::set<std::string> names;
	
	load_scriptnames(names,vals,comboscriptmap,NUMSCRIPTSCOMBODATA-1);
	
	GUI::ListData ls;
	ls.add("(None)", 0);
	ls.add(names,vals);
	return ls;
}

static const GUI::ListData defense_types
{
	{ "(None)", 0 },
	{ "1/2 Damage", 1 },
	{ "1/4 Damage", 2 },
	{ "Stun", 3 },
	{ "Stun Or Block", 4 },
	{ "Stun Or Ignore", 5 },
	{ "Block If < 1", 6 },
	{ "Block If < 2", 7 },
	{ "Block If < 4", 8 },
	{ "Block If < 6", 9 },
	{ "Block If < 8", 10 },
	{ "Block", 11 },
	{ "Ignore If < 1", 12 },
	{ "Ignore", 13 },
	{ "One-Hit-Kill", 14 },
	{ "Block if Power < 10", 15 },
	{ "Double Damage", 16 },
	{ "Triple Damage", 17 },
	{ "Quadruple Damage", 18 },
	{ "Enemy Gains HP = Damage", 19 },
	{ "Trigger Screen Secrets", 20 },
	// { "-freeze", 21 },
	// { "-msgnotenabled", 22 },
	// { "-msgline", 23 }, 
	// { "-lvldamage", 24 },
	// { "-lvlreduction", 25 },
	{ "Split", 26 },
	{ "Transform", 27 },
	// { "-lvlblock2", 28 },
	// { "-lvlblock3", 29 },
	// { "-lvlblock4", 30 }, 
	// { "-lvlblock5", 31 },
	// { "-shock", 32 },
	{ "Bomb Explosion", 33 },
	{ "Superbomb Explosion", 34 },
	// { "-deadrock", 35 },
	// { "-breakshoeld", 36 },
	// { "-restoreshield", 37 },
	// { "-specialdrop", 38 },
	// { "-incrcounter", 39 },
	// { "-reducecounter", 40 },
	{ "Harmless Explosion", 41 },
	// { "-killnosplit", 42 },
	// { "-tribble", 43 },
	// { "-fireball", 44 },
	// { "-fireballlarge", 45 },
	{ "Summon", 46 }// ,
	// { "-wingame", 47 },
	// { "-jump", 48 },
	// { "-eat", 49 },
	// { "-showmessage", 50 }
};

GUI::ListData const& GUI::ZCListData::deftypes()
{
	return defense_types;
}