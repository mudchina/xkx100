
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("kunlun")+"/hetaichong");
	set("start_room","/d/kunlun/pingfeng");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}