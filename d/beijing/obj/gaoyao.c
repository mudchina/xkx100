// gaoyao.c 膏药

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(RED"膏"BLK"药"NOR, ({ "gaoyao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "看上去很奇怪的一副膏药，半边红半边黑。\n");
		set("unit", "副");
		set("value", 500);
        }
    setup();
}

void init()
{
	add_action("do_use","use");
	add_action("do_use","yong");
}


int do_use(string arg)
{
	if (!id(arg))
		return notify_fail("\n你要用什么药？\n");
	return notify_fail("\n你撕开药封来，只见一张纸上有个明目，曰:\n"
        +"“去清复明膏药”。此外什么也没有。\n");
}
