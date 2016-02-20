// /d/xingxiu/silk3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;
int do_climb(string arg);

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。南面连绵的祁连山脉在阳光的照
射下好像是一条玉带。东边是中原，西面则通往西域。西南有一座黄沙
堆积形成的山(mount)。
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"eastup"    : __DIR__"songmoya",
		"west"      : __DIR__"shimen",
		"northwest" : __DIR__"yanzhishan",
	]));
	set("objects", ([
		"/d/hangzhou/honghua/huo" :1,
		__DIR__"npc/trader" : 1,
	]));
	set("item_desc", ([
		"mount" : 
		"这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。你\n" 
		"不禁对自然的造物发出由衷的赞叹。\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -21500);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="mount")
	{
		message("vision", me->name() + "吭吃吭吃向沙山上爬去。\n", environment(me), ({me}) );
		me->move("/d/xingxiu/shashan");
		message("vision", me->name() + "从沙山下爬了上来，粘了一身沙子。\n", environment(me), me );
		return 1;
	}
}

#include "/d/xingxiu/job2.h";

