// Room: /yangzhou/qiqifang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","江氏漆器工坊");
	set("long",@LONG
这里是名噪扬州的漆工艺人江千里的作坊。江千里制作的漆器器皿，
异常精致，形神俱美。扬州人莫不以有一套江千里的漆器器皿为傲，扬
州城里「杯盘处处江秋水」。作坊内几个客人正和江千里商量些什么，
边上的一个帐房模样的人执笔记着。对于你的进来，似乎没人在意。
LONG );
	set("exits", ([
		"south" : __DIR__"dashixijie",
	]));
	set("objects", ([
		__DIR__"npc/jiangqianli" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}