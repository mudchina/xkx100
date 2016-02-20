// shanjiao.c 终南山脚
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "终南山脚");
	set("long", @LONG
这里是终南山的山脚，终南山号称西北的第一山，以山势奇峻，
环境清幽著称。这里的山势还很平缓，一道石阶蜿蜒通往山上。面前
是一座高山，如同擎天一柱般插向天空，所以古人的诗句中有‘终南
一柱’的说法。
LONG
	);
	set("outdoors", "zhongnan");
	set("exits", ([
		"north"    : __DIR__"shanlu4",
		"westdown" : __DIR__"shanlu3",
	]));
	set("objects",([
		__DIR__"npc/youke" : 1,
		__DIR__"npc/xiangke" : 2,
		"/clone/misc/dache" : 1,
	]));

	set("coor/x", -3130);
	set("coor/y", -10);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
