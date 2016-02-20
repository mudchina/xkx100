#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("shenlong")+"/hong");
	set("start_room","/d/shenlong/tingkou");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
