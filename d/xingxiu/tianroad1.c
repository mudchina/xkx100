// room: /d/xingxiu/tianroad1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片
草原。草原上一位牧羊人赶着一群羊。这里向东可以下山。北边传来阵
阵猛兽的啸声。
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"eastdown" : __DIR__"shanjiao",
		"north"    : __DIR__"tianroad2",
	]));
	set("objects", ([
		__DIR__"npc/herdsman" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 10000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
