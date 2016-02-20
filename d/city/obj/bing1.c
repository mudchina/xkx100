//bing1.c 一秀饼
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "一秀饼" NOR, ({"bing1", "yixiubing"}));
	set("unit", "块");
	set("long", "这是一块脆香的一秀饼。\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if (query("owner") != me->query("id"))
	{
		write(HIR"你只能吃自个赢来的饼。\n"NOR);
		return 1;
	}
	if(arg=="bing1"||arg=="yixiubing")
	{
		message_vision(HIY "$N三口两口吃下一块$n。\n" NOR, this_player(), this_object());
		me->add("combat_exp",68);
		me->add("potential",18);
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
