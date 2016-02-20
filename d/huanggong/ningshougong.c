// Room: /d/huanggong/ningshougong.c

inherit ROOM;

void create()
{
	set("short", "宁寿宫");
	set("long", @LONG
这里是太上皇起居休憩的地方。现下却是公主寝宫。只见墙壁上、
桌椅上，都是刀剑皮鞭之类的兵器，便如是个武人的居室，哪里像是金
枝玉叶的公主寝室。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		 "north" : __DIR__"changyinge",
		 "south" : __DIR__"huangjidian",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jianning" : 1,
	]));

	set("coor/x", -180);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}