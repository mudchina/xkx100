#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("taohua")+"/huang");
	set("start_room","/d/taohua/dating");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") == "eunach" || ob->query("class") == "officer")
	{
		return "官场大内无耻之辈，岂能出任掌门弟子一职！";
	}	return ::zm_apply();
}