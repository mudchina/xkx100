// item: redobj.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"红布小囊"NOR, ({"hongbu xiaonang", "xiaonang"}));
	set_weight(80);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一只红布小囊，不知道有什么用处。\n");
		set("unit", "只");
		set("value", 1);
	}
}

void init()
{
}
