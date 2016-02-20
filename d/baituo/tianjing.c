#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"天井"NOR);
	set("long", @LONG
转过一道石壁，你的眼前忽然一亮。原来这里是个天然形成的天井，
大约几十来丈见方，头顶一个圆洞，光亮都是从那里照射进来的。一条
暗流从山腹流过这里，旁边长慢了各种花草，还有几颗果树。随着一声
鹤鸣，你发现有一只罕见的丹顶鹤正站在溪边看着你。
LONG);
	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/he" : 1,
		"/clone/book/bt_book4" : 1
	]));	
	set("exits", ([
		"out" : __DIR__"midao4",
	]));
	set("outdoors", "baituo");
	set("grass_count",8);
	set("guo_count",10);
	set("coor/x", -49950);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	this_player()->set_temp("find_times", 20);
	add_action("do_find", "find");
	add_action("do_zhai", "zhai");
}

int do_find()
{
	object me, ob;
	int luck;
	me = this_player();
	ob = new(__DIR__"obj/grass");
	luck = (int)me->query_int() * (int)me->query_con() / 5;
	luck = luck + (int)me->query("kar") / 3 - 30;
	message_vision("$N蹲下身子，在草丛中仔细地寻找着什么。\n", me);
	if ( me->query_temp("find_times") == 0 )
	{
		message_vision("$N一不小心被杂草割了一个伤口，鲜血直流！\n",me);
		me->set_temp("find_times", random(20));
		me->receive_wound("qi", 65);
		return 1;
	}
	me->add_temp("find_times", -1);
	if (random(luck) > 115 && query("grass_count") >= 1)
	{
		add("grass_count", -1);
		ob->move(me);
		message_vision("$N“咦”了一声，原来发现了一株断肠草。\n", me);
	}
	return 1;
}

int do_zhai(string arg)
{
	object me = this_player();
	if (arg == "guo" && me->query_dex() > 25 && query("grass_count") >= 1)
	{
		message_vision("$N顺手从果树上摘下一个果子。\n", me);
		new(__DIR__"obj/guo")->move(me);
		add("grass_count", -1);
		return 1;
	}
	return notify_fail("你要摘什么？\n");
}
