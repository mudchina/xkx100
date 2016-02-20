// Room: /d/huijiang/gebi2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long", @LONG
焦热的阳光晒着茫茫的戈壁，软绵的黄沙开始被大大小小的砾石所
代替。砂石之间的地面上开始出现青草，前面传来潺潺的流水声。看来
不远就有水源了。
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiaoxi",
		"east" : __DIR__"shamo4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

