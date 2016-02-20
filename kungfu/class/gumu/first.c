
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("gumu")+"/longnv");
	set("start_room","/d/gumu/qianting");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "女性")
	{
		return "本派只有女子才能接任掌门弟子一职！";
	}
	return ::zm_apply();
}
