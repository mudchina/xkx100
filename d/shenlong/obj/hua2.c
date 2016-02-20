// hua2.c 无名花
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("无名花", ({"hua2", "wuming"}));
	set("unit", "朵");
	set("long", "这是一朵无名小花，花蕊虽小，却十分美丽。\n");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;
	object me = this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if ( neili_limit <= force_limit  )
		me->add("max_neili", 1);
	me->unconcious();
	destruct(this_object());
	return 1;
}

