#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("xingxiu")+"/ding");
	set("start_room","/d/xingxiu/riyuedong1");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}