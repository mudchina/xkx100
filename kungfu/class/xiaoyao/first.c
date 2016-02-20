
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("xiaoyao")+"/xiaoyaozi");
	set("start_room","/d/xiaoyao/shidong");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
