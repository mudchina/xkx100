// Room: /d/quanzhou/southroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐南路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。刺桐南路
的东边是打锡巷，西边有一大片民宅，四通八达，连着武馆和戏院。北
边便是热闹的中心广场。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([ 
		"east"  : __DIR__"daxixiang",
		"west"  : __DIR__"zhaiqu1",
		"north" : __DIR__"guangchang",
		"south" : __DIR__"southroad2",
	]));
	set("coor/x", 1850);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
