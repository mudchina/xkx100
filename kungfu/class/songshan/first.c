#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("songshan")+"/zuo");
	set("start_room","/d/songshan/junjigate");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}