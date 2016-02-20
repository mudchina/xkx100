// yuma.c 玉马

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(GRN"翡翠玉马"NOR, ({ "stone horse", "yu ma", "ma" }));
	set("weight", 5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("value", 50000);
		set("long", "一座翡翠雕成的玉马。\n");
		set("material", "stone");
	}
	setup();
}
