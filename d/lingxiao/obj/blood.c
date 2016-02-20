// Obj: /d/lingxiao/obj/blood.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ITEM;

int do_drink(string);
void init();

void init()
{
	add_action("do_drink", "drink");
}

void create()
{
	set_name( HIR "怪蛇血" NOR , ({"she xue", "blood"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "管");
		set("long", "一管怪蛇的血液，很是腥臭，看起来绿油油的。\n");
		set("value", 1000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_drink(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;
	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
 
	if(!id(arg)) return notify_fail("你要喝什么？\n");
	if(!present(this_object(), this_player()))
		return notify_fail("你要喝什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢喝，小心别呛着了。\n");

	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 5);
		message_vision( HIR"$N只觉一股热线从咽喉直通到腹中，然后丹田就象有一团火般烧了起来。\n" NOR, me);
	}
	destruct(this_object());
	return 1;
}

