// grass.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("断肠草", ({"duanchang cao", "cao", "duanchang"}));
	set_weight(25);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIM"\n这是一株深紫色的小草，散发出一股恶臭，中人欲呕。\n"NOR);
		set("unit", "株");
		set("value", 100);
	}
	setup();
}

int init()
{
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
	if(!id(arg)) return notify_fail("你要什么？\n");

	message_vision("$N服下一株" + name() + "。\n", me);	
	tell_room(environment(me),HIR+me->name()+"突然露出非常痛苦的样子，全身大汗淋漓。\n" NOR, ({ me }));
	tell_object(me, HIR "你腹中猛地一动，跟着便一阵阵巨痛传来！\n" NOR);
	message_vision(RED"$N忽地“哇”的一声，吐出一大口血来。\n"NOR,me);

	damage = me->query_con()*10;
	damage = me->query_skill("force") + damage;

	me->receive_wound("jing", damage);
	me->receive_wound("qi", damage*2);
	me->add("neili", - damage*4);
	me->add("jingli", - damage*2);
	if ((int)me->query_condition("qinghua_poison") > 3)
		me->apply_condition("qinghua_poison", me->query_condition("qinghua_poison") -1 );
	if ((int)me->query_condition("qinghua_poison") == 2) 
		me->apply_condition("qinghua_poison", 1);

	destruct(this_object());
	return 1;
}
