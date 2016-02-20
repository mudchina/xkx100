#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("mingjiao")+"/zhangwuji");
	set("start_room","/d/mingjiao/square");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}