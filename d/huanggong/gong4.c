// Room: /d/huanggong/gong4.c

inherit ROOM;

void create()
{
	set("short", "翊坤宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”. 宫内高悬一
幅 "令仪淑德" 的雕匾.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"gong2",
		"south" : __DIR__"gong6",
		"east"  : __DIR__"kunninggong",
		"west"  : __DIR__"tinglang2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}