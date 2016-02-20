// Room: /d/huanggong/gong3.c

inherit ROOM;

void create()
{
	set("short", "体元殿");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"tinglang2",
		"north" : __DIR__"gong1",
		"south" : __DIR__"gong5",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}