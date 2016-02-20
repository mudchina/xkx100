// jiu.c
inherit ITEM;
#include <ansi.h>

void init()
{
}
void create()
{
	set_name(HIB "玄冰"HIG"碧火"HIR"酒" NOR,({"xuanbingbihuo jiu", "jiu"}));
	set("taskobj", 1);
	set("unit", "壶");
	set("long", "这是一壶珍贵之极的玄冰碧火酒, 据说能解百毒。\n");
	setup();
}
