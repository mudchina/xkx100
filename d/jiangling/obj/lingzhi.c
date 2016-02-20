//Edited by fandog, 02/15/2000
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
	set_name(HIG"灵芝"NOR, ({"lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵灵芝，是湖北出产的名贵中药。\n");
		set("value", 20000);
	}
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
	if(arg=="lingzhi") 
	{
		me->set("jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIG"$N吃下一棵灵芝，顿时觉得浑身充满了活力！\n"NOR,me);
		me->start_busy(1);
		destruct(this_object());
	}
	return 1;
}

