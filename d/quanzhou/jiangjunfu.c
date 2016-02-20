// Room: /d/quanzhou/jiangjunfu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "施琅将军府");
	set("long", @LONG
这是一座气势恢宏的大宅院，琉璃瓦顶，飞檐斗拱，风格迥异。大
红的正门上方挂着一块横匾，上书四个金光闪闪的「靖海侯府」，乃是
皇上所敕之宅，以彰施琅将军攻破台湾的功绩。
LONG );
	set("exits", ([
		"west"  : __DIR__"daxixiang",
		"north" : __DIR__"jiangjunfu1",
		"south" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1870);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && objectp(present("wu jiang", environment(me))))
		return notify_fail("武将大喝道：将军有令，闲杂人等回避！\n");
	return ::valid_leave(me, dir);
}

