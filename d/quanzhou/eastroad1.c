// Room: /d/quanzhou/eastroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐东路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。北边的粮
仓里有士兵把守，以防贼盗洗劫。往东可至恩怨巷，再到擂台。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"eastroad2",
		"west"  : __DIR__"guangchang",
		"north" : __DIR__"liangcang",
	]));
	set("coor/x", 1860);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
