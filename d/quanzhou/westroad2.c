// Room: /d/quanzhou/westroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐西路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。北边是开
元寺，南边是济世堂老店，西边则是西门吊桥。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"westbridge",
		"east"  : __DIR__"westroad1",
		"north" : __DIR__"kaiyuansi",
		"south" : __DIR__"jishitang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
