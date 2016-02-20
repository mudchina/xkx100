// Room: /d/baituo/changlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","长廊");
	set("long", @LONG
这里是非常气派的长廊。北边是间休息室。南边有间药房，里面传
来一阵器皿碰击的声音。西边是扇拱月形小敞门。东边是练功场。
LONG	);

	set("exits",([
		"west"  : __DIR__"ximen",
		"north" : __DIR__"restroom",
		"east"  : __DIR__"liangong",
		"south" : __DIR__"yaofang",
	]));
	set("outdoors","baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
