#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("wudang")+"/zhang");
	set("start_room","/d/wudang/guangchang");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") != "taoist")
	{
		return "本门修真之士，方能执掌门户！";
	}	
	return ::zm_apply();
}