
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("honghua")+"/chen-jialuo");
	set("start_room","/d/huijiang/zoulang3");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
