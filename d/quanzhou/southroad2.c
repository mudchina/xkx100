// Room: /d/quanzhou/southroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐南路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。由此东行
便到承天寺，西边是民宅，西南则是一处阿拉伯宅区。泉州出名的源和
堂便在西边。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([ 
		"east"      : __DIR__"chengtiansi",
		"west"      : __DIR__"zhaiqu3",
		"north"     : __DIR__"southroad1",
		"southeast" : __DIR__"alabo",
	]));
	set("coor/x", 1850);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
