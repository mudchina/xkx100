// /d/beihai/jiulongbi.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "九龙壁");
	set("long", @LONG
这里是小西天西之九龙壁，青白玉基台，上有绿琉璃须弥座，壁面
前后各有九条形态各异，奔腾在云雾波涛中的蛟龙浮雕。壁东面为江崖
海水，旭日东升流云纹饰，西面为江崖海水，明月当空流云纹饰。影壁
用四百二十四块七色琉璃砖砌筑而成。色彩绚丽，古朴大方。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"xitian",
		"south" : __DIR__"dukou1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
