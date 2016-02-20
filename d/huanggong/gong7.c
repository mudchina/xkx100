// Room: /d/huanggong/gong7.c

inherit ROOM;

void create()
{
	set("short", "钟粹宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"tinglang4",
		"south" : __DIR__"gong9",
	]));

	set("coor/x", -190);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}