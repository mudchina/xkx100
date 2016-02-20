
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("henshan")+"/moda");
	set("start_room","/d/henshan/zhurongdian");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}