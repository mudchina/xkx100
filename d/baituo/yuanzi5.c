// Room: /d/baituo/yuanzi5.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "院子");
	set("long", @LONG
这里堆放着上百堆的石头。这些石头有大有小，大如一间房屋，小如
一个鸭蛋，形状各异。你发现几个巨石(stone)围成一圈，不知里面有些
什么古怪。
LONG);
	set("exits", ([
		"southwest" : __DIR__"yuanzi4",
		"southeast" : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"stone": "\n这块石头上有些凹洞，大概可以由此爬上去。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49910);
	set("coor/y", 20090);
	set("coor/z", 30);
	set("outdoors", "baituo");
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_yun", "yun");
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		message_vision("$N手脚并用，顺着凹洞爬了上去。\n", me);
		message("vision", me->name() + "翻身一纵，已经跳进了石堆。\n", environment(me), ({me}) );
		me->move(__DIR__"shidui");
		message("vision", me->name() + "从外面跳了进来。\n", environment(me), ({me}) );
		return 1;
	}
}

int do_yun(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "hamagong" )
	{
		if(!me->query_temp("baituo_book"))
			return notify_fail("这地方练什么功？\n");
		if(!me->query_skill("hamagong", 1))
			return notify_fail("什么？\n");
		message_vision(HIC "$N蹲低身子潜运功力，突然张嘴：呱呱！叫了两声。\n"NOR,me);
		tell_object(me,HIB "你忽然感觉到有两声细微的蛤蟆叫声从巨石堆里传来。\n" NOR );
		me->set_temp("baituo_yun", 1);
		return 1;
	}
}
