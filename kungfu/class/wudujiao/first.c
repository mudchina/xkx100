#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("wudujiao")+"/hetieshou");
	set("start_room","/d/wudujiao/dating");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}