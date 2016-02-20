#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("xueshan")+"/jiumozhi");
	set("start_room","/d/xueshan/dadian");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") != "lama")
	{
		return "你非我雪山僧众，岂能出任掌门弟子一职！";
	}
	return ::zm_apply();
}