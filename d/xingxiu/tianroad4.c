// room: /d/xingxiu/tianroad4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void init();
int do_jump(string arg);

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片
针叶林。石壁上盛开着一朵洁白的天山雪莲，一个采药人正在采药。东
面一条深涧(valley)挡住了下山的路。
LONG );
	set("exits", ([
	    "westup" : __DIR__"tianroad5"
	]));
	set("objects", ([
		__DIR__"npc/caiyaoren"  : 1,
		"/clone/medicine/vegetable/xuelian" : 1
	]));

	set("item_desc", ([
	"valley" : "深涧有三丈多宽，不过因为这边地势高，应该不难跳(jump)过去。\n"
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	set("coor/x", -52000);
	set("coor/y", 20100);
	set("coor/z", 30);
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
	if( arg=="valley" )
	{
		message("vision", me->name() + "一提气，双足点地跳过了深涧。\n", environment(me), ({me}) );
		me->move("/d/xingxiu/tianroad3");
		message("vision", me->name() + "从深涧上面跳了下来。\n", environment(me), ({me}) );
		return 1;
	}
}
