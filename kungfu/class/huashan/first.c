
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("huashan")+"/yue-buqun");
	set("start_room","/d/huashan/buwei3");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
