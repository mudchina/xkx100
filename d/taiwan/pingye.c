// Room: /d/taiwan/pingye.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "平野");
	set("long", @LONG
颜思齐于苯港登陆后，在笨港东南岸的平野，思齐规划建筑了井字
型营寨，中间为大高台，使之成为组织指挥垦荒的中枢。与此同时，派
杨天生率船队赴漳、泉故里招募移民，前后计三千余众。颜思齐将垦民
分成十寨，发给银两和耕牛、农具等，开始了台湾最早的大规模拓垦活
动。
LONG );
	set("exits", ([
		"northwest" : __DIR__"taiwanfu",
		"southeast" : __DIR__"zhuluo",
	]));
	set("objects", ([
		__DIR__"npc/nongfu": 3,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

