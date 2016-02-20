// Room: /d/xingxiu/cave.c
// Last Modified by Winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "山洞");
	set("long", @LONG
黑黝黝的山洞里，有一股腥臭味。等眼睛适应了这里的弱光后，才
发现地上有一条色彩斑斓的巨蟒。巨蟒旁有许多白惨惨的骨骇，令人胆
寒。想必都是探险之人，误入山洞，为巨蟒所害。
LONG
	);
	set("exits", ([
		"out" : __DIR__"shanshi",
	]));
	set("objects", ([
		__DIR__"npc/jumang" : 1,
		__DIR__"npc/snake" : 1,
	]));
	set("coor/x", -50400);
	set("coor/y", 20400);
	set("coor/z", 200);
	setup();
}
void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if(arg=="fire")
	{
		write("你点燃了火折，发现西面石壁上有一道裂缝，似乎可以钻(zuan)出去。\n");
		me->set_temp("marks/钻", 1);
		me->start_busy(2);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if(me->query_temp("marks/钻") )
	{
		message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n", environment(me), ({me}) );
		me->move(__DIR__"cave2");
		message("vision", me->name() + "从石缝里钻了进来。\n", environment(me), ({me}) );
		me->set_temp("marks/钻", 0);
		return 1;
	}
	else {
		write("你想往哪儿钻?!\n");
		return 1;
	}
}

