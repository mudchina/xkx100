// Room: /d/gumu/chucangshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"储藏室"NOR);
	set("long", @LONG
古墓生活甚是清苦，储藏室堆着些日常用品，都整整齐齐堆放在墙
角，看来经常有古墓弟子前来打扫，其余别无他物。
LONG	);

	set("exits", ([
		"east" : __DIR__"mudao22",
	]));
	set("fire_count", 2);
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", -20);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_search", ({"search", "zhao"}));
}

int do_search(string arg)
{
	object ob, me = this_player();

	if ( arg == "qiangjiao" || arg == "墙角")
	{
		if ( me->query_temp("fire") < 3 )
		{
			if(objectp(ob = present("fire", me)))
				return notify_fail("你已经拿了火折了，怎么这么贪心？\n");
			me->add_temp("fire", 1);
			message_vision(YEL "$N在墙脚的物品堆里翻来翻去什么也没找着。\n"NOR, me);
			return 1;
		}
		message_vision("$N在墙脚的物品堆里翻来翻去找出一把火折。\n",me);
		me->delete_temp("fire");
		new("/clone/misc/fire")->move(me);
		return 1;
	}
	return notify_fail("你要找什么？\n");	 
}
