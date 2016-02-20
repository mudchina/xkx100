// Room: /d/gumu/jianshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"剑室"NOR);
	set("long", @LONG
一间摆满兵器的石室，很多种剑都整齐地堆放在地上。周围的火把
照的整个石室灯火通明，几个古墓弟子正站在室中仔细挑选自己合手的
兵刃。墙角放着一个木制的护具架，上面挂着些古墓弟子平时防身用的
护具。
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao07",
	]));

	set("objects", ([
		WEAPON_DIR"changjian" : 2,
		WEAPON_DIR"sword/zhujian" : 2,
		__DIR__"obj/huju-jia" : 1,
	]));
	set("coor/x", -3180);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
}

int valid_leave(object ob, string dir)
{
	string* jian = keys(query("objects"));
	object* sword = deep_inventory(ob);

	int i = sizeof(sword), count = 0;
	while (i--)
		if (member_array(base_name(sword[i]), jian) != -1) count++;
	if (count > 1)
		return notify_fail("你一下子拿这么多剑，别人不要用了吗？\n");
	return ::valid_leave(ob, dir);
}

