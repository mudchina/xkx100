#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("tiezhang")+"/qqren");
	set("start_room","/d/tiezhang/shanmen");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}