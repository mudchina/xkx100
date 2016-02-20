// Room: /d/taohua/taohua9.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <ansi.h>
int do_look(string arg);

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(12) + 1;
	thd2 = random(12) + 1;
	thd3 = random(12) + 1;
	thd4 = random(12) + 1;
	if (thd1 == 9 && thd2 == 9 && thd3 == 9 && thd4 == 9)
		while (thd4 == 9)
			thd4 = random(12) + 1;
	set("short", "桃花阵");
	set("long", @LONG
这里是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂
过，落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌
乱起来：还是早点出去的好。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"xiaoyuan",
	]));
	set("no_drop","1");
	set("coor/x", 9010);
	set("coor/y", -3090);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob=this_player();

	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("你在阵中累得精疲力尽，终因体力不支而昏了过去！\n");
		write("迷迷胡胡中似乎有人把你抬出了阵，仿佛有个威严的声音喝道：“扔到海里去”。\n");
		ob->unconcious();
		ob->move(__DIR__"shore", 1);
		message("vision", "忽然一个大潮涌了过来，将一个被水泡得半死的家伙冲到了岸边。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
	add_action("do_look", "look");
	add_action("do_look", "l");
}

int do_look(string arg)
{
	object me = this_player();
	if (arg == "east" || arg == "west" || arg == "south" || arg == "north")
	{
		write(HIC"桃花阵"NOR" -
    这里是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂
过，落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌
乱起来：还是早点出去的好。
    这里明显的出口是 east、north、south 和 west。\n");
		return 1;
	}
	return 0;
}

