// Room: /d/huanggong/gong1.c

inherit ROOM;

void create()
{
	set("short", "长春宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”. 宫中挂着一
个红木牌匾: "茂修内治".
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"tinglang1",
		"south" : __DIR__"gong3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}