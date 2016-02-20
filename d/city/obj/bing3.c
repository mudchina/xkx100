//bing3.c 四进饼
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "四进饼" NOR, ({"bing3", "sijingbing"}));
	set("unit", "个");
	set("long", "这是一个浓香的四进饼。\n");
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
	if(arg=="bing3"||arg=="sijingbing")
	{
		me->add("combat_exp",468);
		me->add("potential",168);
		message_vision(HIY "$N三口两口吃下一块$n。\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
