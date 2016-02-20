// /d/meizhuang/mishi.c
// Last Modified by winder on Apr. 10 2000
#include <room.h>

inherit ROOM;
int do_press();
int valid_leave();

void create()
{
	set("short","密室");
	set("long", @LONG
这是一间不大的房间，房间里摆着一排排的书架(shu jia) 和很多
书(book)，在书架的两旁靠着几具死人的骸骨，有一具的胸骨之中还插
着一柄剑。
LONG);
	set("exits", ([
		"out" : __DIR__"neitang",
	]));
	set("item_desc", ([
		"shu jia" : "书架上摆着各种各样的书。\n",
		"book"    : "都是一些很平常的书，到处都可以见到。\n",
	]) );
	set("objects", ([
		__DIR__"obj/tizi" : 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="shu jia")
	{
		if (me->query_temp("marks/跳1") )
		{
			if (me->query_skill("dodge",1)<100)
				write("你试图跳到书架顶上去，可老是差了点。\n");
			else
			{
				write("你纵身跃上了书架顶端。\n");
				message("vision", me->name() + "一纵身跃上了书架顶端。\n", environment(me), ({me}) );
				me->move(__DIR__"dingduan");
				message("vision", me->name() + "从下面跃了上来。\n", environment(me), ({me}) );
			}
		}
		else message_vision("$N老在地上跳啊跳，不知道在玩什么玄虚。\n", me);
		return 1;
	}
	return notify_fail("你想往哪里跳？\n");
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/跳1");
	return ::valid_leave(me, dir);
}
