#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("lingxiao")+"/bai");
	set("start_room","/d/lingxiao/houyuan1");
	::create();
}

string zm_apply()
{
	return ::zm_apply();
}
