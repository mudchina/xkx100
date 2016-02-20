// Room: /d/huashan/jzroad2.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。中间一条小路，两边都是黑森森的几丈高的松树。
快出林了，可以看到东边好高的一道大山。
LONG );
	set("exits", ([
		"west" : __DIR__"jzroad1",
		"east" : __DIR__"jzroad3",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);
	set("coor/x", -940);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
