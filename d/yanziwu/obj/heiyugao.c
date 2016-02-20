inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIC "黑玉断续膏" NOR, ({"heiyugao"}));
	set("unit", "粒");
	set("long", "这是一粒千年极其难配制的的黑玉断续膏，据说能起死回生。\n");
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
	this_player()->set_temp("nopoison", 1);
	this_player()->receive_curing("jing", 200);
	this_player()->recieve_curing("qi", 200);
	tell_object(this_player(), HIG "你只觉一股热流在七经八脉中循环了一个周天，立刻神采奕奕了！\n" NOR );
	destruct(this_object());
	return 1;
}
