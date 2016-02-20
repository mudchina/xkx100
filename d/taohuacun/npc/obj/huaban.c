// huaban.c 花瓣

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIM"花瓣"NOR, ({"huaban"}));
	set_weight(500);
	set("vegetable", 16);
	set("value", 100);
	set("unit", "片");
	set("long", "这是一片粉红的花瓣，看来刚摘下不久。\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	write("人家只有蜜蜂和蝴蝶对花瓣有兴趣，原来你也......\n");
	return 1;
}
