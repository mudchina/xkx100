// huangqi.c 黄芪

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"黄芪"NOR, ({"huang qi", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", YEL"这是一株毛茸茸的开着淡黄色小花的黄芪。\n"NOR);
		set("value", 2500);
	}
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if ( (int)me->query_condition("medicine" ) > 0 )
	{
		me->add("qi", -100);
		me->add("neili", 100);
		message_vision(HIR "$N吃下一株黄芪，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	} else {
		me->add("qi", 50);
		message_vision("$N吃下一株黄芪，只觉得浑身热气腾腾，顿时充满了活力！\n", me);

		me->apply_condition("medicine", 30);
	}

	destruct(this_object());
	return 1;
}
