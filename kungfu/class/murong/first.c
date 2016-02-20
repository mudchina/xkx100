#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("murong")+"/murong-fu");
	set("start_room","/d/yanziwu/canheju");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}