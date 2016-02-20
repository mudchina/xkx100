// xianglu.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("香炉", ({ "xiang lu", "lu" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个很雅致的香炉，炉中飘出阵阵淡淡檀香。\n");
		set("value", 100);
		set("material", "gold");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
}

