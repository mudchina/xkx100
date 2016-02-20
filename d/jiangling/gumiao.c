//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "古庙");
	set("long", @LONG
这古庙地处荒僻，年久失修，庙内也无庙祝和尚。神案上满是灰尘
积垢，却有枝粗大的蜡烛(lazhu)放在案上。
LONG );
	set("item_desc", ([
		"lazhu": "一枝粗大的蜡烛，烛泪似乎颇为新鲜，好象刚有人点过。\n"
	]) );
	set("exits", ([
		"east" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/foxiang" : 1,
	]));
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_dian", "fire");
	add_action("do_open", "qiao");
	add_action("do_open", "open");
}

int do_dian(string arg)
{
	string dir;
	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="lazhu" )
	{
		if (! objectp(present("tangshi jianpu", me)))
			return notify_fail("你想点蜡烛干嘛！\n");
	message("vision", me->name()+"把蜡烛点了起来，突然发现佛像后面有个暗门耶！！\n", environment(me));
		me->set_temp("marks/lazhu", 1);
		return 1;
	}
	else 
		return notify_fail("你想要点什么？\n");
}
int do_open(string arg)
{
	object foxiang, obj, me = this_player();

	if (!objectp(foxiang = present("dafo xiang", this_object())))
		return notify_fail("奇怪，佛像不见了！\n");
	if (foxiang->query("opened"))
		return notify_fail("佛像暗门早给人家打开了！\n");
	if (me->query_temp("marks/lazhu") )
	{
		message("vision", me->name() + "奋力去撬暗门。撬得几下，那暗门渐渐松了。"+me->name()+"伸手指将暗门轻轻起了出来，举烛一照，只见佛像肚里珠光宝气，霭霭浮动，不知这个大肚子之中，藏了有多少珍珠宝贝。\n", environment(me) );
		me->delete_temp("marks/lazhu");
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		foxiang -> set("opened", 1); 
		return 1;
	}
        else {
		write("黑呼呼的你想干什么？！\n");
		return 1;
        }
}