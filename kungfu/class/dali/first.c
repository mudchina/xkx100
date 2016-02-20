
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("dali")+"/duanzc");
	set("start_room","/d/dali/wangfugate");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}