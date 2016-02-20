// Room: /d/huanggong/gong10.c

inherit ROOM;

void create()
{
	set("short", "永和宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
		__DIR__"npc/hui" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"tinglang5",
		"south" : __DIR__"gong12",
		"north" : __DIR__"gong8",
	]));

	set("coor/x", -170);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}