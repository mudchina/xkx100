// liangong.c 练功室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "练功室");
	set("long", @LONG
这座石室形状甚是奇特，前窄後宽，成为梯形，东边半圆，西边却
作三角形状，原来这是以前重阳祖师的练功室，前窄练掌，后宽使拳，
东圆研剑，西角发镖。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mudao03",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -3240);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
