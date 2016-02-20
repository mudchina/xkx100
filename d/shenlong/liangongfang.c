// liangongfang.c 练功房
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是神龙教秘密的练功房，地下整整齐齐放着几个蒲团，几位神
龙教长老正盘膝坐在上面练功。四壁列着一些柜子，抽屉中放满了各类
药酒。柜子上放着几本神龙教从各处猎获的内功心法册子。
LONG
	);
	set("exits", ([
		"south" : __DIR__"zhulin2",
	]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
}

int do_practice(string arg)
{
	object me = this_player();
	string skill;
	int lvl;

	if( (int)me->query("sg/exp") < 5000 )
	{
		message("vision", 
			"只见一位神龙教长老把"+me->name() + "一脚踢了出去。\n",
			environment(me), ({me}));
		me->move(__DIR__"zhulin1");
		message_vision("$N被神龙教长老踢了出来。\n", me);
		return 1;
	}

	if( !arg ) return ("/cmds/skill/enable")->main(me, arg);

	if(arg == "strike" && me->query_skill_mapped(arg) == "huagu-mianzhang" )
		return 0;

	write("这里是修习化骨绵掌的场所。\n");
	return 1;
}

