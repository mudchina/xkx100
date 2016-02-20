// Room: /d/kunlun/tieqinju.c 铁琴居
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","铁琴居");
        set("long",@long
这儿便是“铁琴先生”何太冲的居处。房间陈设颇为精巧，物品与
中土所见别是不同。几个昆仑派弟子守在这里，个个深有忧色。东边通
往卧室。
long );
	set("objects",([
		CLASS_D("kunlun")+"/hetaichong" : 1,
		__DIR__"npc/kl-dizi2.c" :   1,
		__DIR__"npc/kl-dizi4.c" :   1,
	]));
	set("exits", ([
		"south" : __DIR__"huapu",
		"east"  : __DIR__"sleeproom",
	]));
	create_door("east", "小门", "west", DOOR_CLOSED);
	set("coor/x", -119980);
	set("coor/y", 40140);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if (dir == "east" &&
		objectp(present("he taichong", environment(me))) &&
		(!fam || fam["family_name"] != "昆仑派") &&
		!me->query_temp("kl_pass"))
		return notify_fail("何太冲拦住你，说道：里侧为内眷居住，还是请勿打扰为是。\n");

	return ::valid_leave(me, dir);
}