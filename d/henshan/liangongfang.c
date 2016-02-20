// Room: /d/henshan/liangongfang.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是刘府中用来练功的地方。有几个人正在专心致致地练武，有
几个手持兵器，在互相拆招。身法灵动，犹如穿花蝴蝶一般，你不禁看
花了眼，别的人则坐在地上的蒲团上苦练内力。
LONG );
//      set("outdoors", "henshan");

	set("exits", ([
		"west" : __DIR__"liufudayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -390);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

