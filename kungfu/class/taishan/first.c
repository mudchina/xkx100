#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("taishan")+"/tianmen");
	set("start_room","/d/taishan/kaishan");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}