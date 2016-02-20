#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("shaolin")+"/xuan-ci");
	set("start_room","/d/shaolin/dxbdian");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "男性" || ob->query("class") != "bonze")
	{
		return "本派掌门弟子均为出家和尚！";
	}	
	return ::zm_apply();
}