// Room: /d/quanzhou/northroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。东边是都
督巷，可通往都督府。一队队的士兵穿来插去，把守森严。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"duduxiang",
		"south" : __DIR__"northroad2",
		"north" : __DIR__"weiyuanlou",
	]));
	set("coor/x", 1850);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
