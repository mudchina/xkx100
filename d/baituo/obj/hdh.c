#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"鹤顶红"NOR, ({"heding hong", "hong", "heding"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", RED"这是一个新鲜的鹤顶红，还散发着阵阵热气。\n"NOR);
		set("value", 50000);
	}
	setup();
}

int init()
{
	call_out("dest", 800);
	add_action("do_eat", "fu"); 
	add_action("do_eat", "eat"); 
}

int do_eat(string arg)
{
	object me = this_player();
	int damage;

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	message_vision("$N服下一个" + name() + "。\n", me);  
	tell_object(me, MAG "你感觉腹中一股巨疼传来，瞬间全身火热滚烫！\n" NOR);
	damage = (int)me->query("max_jing");
	damage = damage/15;
	damage = damage*14;
	me->receive_wound("jing", damage);
	me->receive_damage("qi", damage);

	if ((int)me->query_condition("ice_poison") > 1)
	{
		me->apply_condition("ice_poison", 1);
		return 0;
	}
	if ((int)me->query_condition("cold_poison") > 1)
	{
		me->apply_condition("cold_poison", 1);
		return 0;
	}
	me->apply_condition("hot_poison", 70); 
	destruct(this_object());
	return 1;
}

void dest()
{
	object me = this_player();
	if (present(this_object(), me))
	tell_object(me, HIR "鹤顶红的热气散尽，慢慢干枯了。\n" NOR);

	destruct(this_object());
}

