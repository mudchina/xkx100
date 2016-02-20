// Room: /d/wuyi/liuxiangjian.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "流香涧");
	set("long", @LONG
流水潺潺，岩壑纵深。花香鸟语，意境幽雅。这里就是天心岩北麓
的流香涧。是仙女沐浴时洒落的胭脂，还是涧边花草染出的清香？走进
流香涧这条悠深的狭谷，崖壁耸立，青藤垂蔓，野花丛生。一路行去，
流水声响与飞花相随不舍，淡淡幽香，不尽飘来。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"path10",
		"northeast" : __DIR__"path12",
		"southeast" : __DIR__"path11",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

