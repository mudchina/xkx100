
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("lingjiu")+"/xuzhu");
	set("start_room","/d/lingjiu/xianchou");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if ( ob->query("gender")!= "女性" )
	  return "灵鹫宫只有女子才能接任掌门弟子一职。";
	return ::zm_apply();
}
