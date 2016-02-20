// pond2.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"青池"NOR, ({ "qing chi", "chi", "qing" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", HIC"一个水色为青的池潭。\n"NOR);
		set("value", 1);
	}
}

int is_container() { return 1; }

