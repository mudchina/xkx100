//bing2.c 二举饼
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY "二举饼" NOR, ({"bing2", "erjubing"}));
	set("unit", "个");
	set("long", "这是一个甜香的二举饼。\n");
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
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (query("owner") != me->query("id"))
	{
		write(HIR"你只能吃自个赢来的饼。\n"NOR);
		return 1;
	}
	if(arg=="bing2"||arg=="erjubing")
	{
		me->add("combat_exp",168);
		me->add("potential",68);
		message_vision(HIY "$N三口两口吃下一块$n。\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
