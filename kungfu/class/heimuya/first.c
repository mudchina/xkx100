
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("heimuya")+"/dongfang");
	set("start_room","/d/heimuya/chengdedian");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
