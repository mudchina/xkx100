// Room: /d/huanggong/gong12.c

inherit ROOM;

void create()
{
	set("short", "延禧宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"tinglang6",
		"north" : __DIR__"gong10",
	]));
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}