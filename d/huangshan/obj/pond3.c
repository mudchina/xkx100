// pond3

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLK"乌池"NOR, ({ "wu chi", "chi", "wu" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", BLK"一个水色为乌的池潭。\n"NOR);
		set("value", 1);
	}
}

int is_container() { return 1; }

