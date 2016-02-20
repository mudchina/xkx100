// hua4.c
//
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIC "翡翠兰" NOR, ({"hua4", "feicui"}));
	set("unit", "朵");
	set("long", "这是一朵千年难得一见的翡翠兰，据说能解百毒。\n");
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
	this_player()->set("eff_jing",this_player()->query("max_jing"));
	this_player()->set("jing",this_player()->query("max_jing"));
	this_player()->set("eff_qi",this_player()->query("max_qi"));
	this_player()->set("qi",this_player()->query("max_qi"));
	tell_object(this_player(), HIG "你只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR );
	destruct(this_object());
	return 1;
}
