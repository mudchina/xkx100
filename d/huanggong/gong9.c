// Room: /d/huanggong/gong9.c

inherit ROOM;

void create()
{
	set("short", "承乾宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”. 宫里陈设奢
华, 引人注目的是堂上的"勤襄内政"匾额.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"kunninggong",
		"east"  : __DIR__"tinglang5",
		"north" : __DIR__"gong7",
		"south" : __DIR__"gong11",
	]));

	set("coor/x", -190);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}