// Room: /d/huanggong/gong2.c

inherit ROOM;

void create()
{
	set("short", "储秀宫");
	set("long", @LONG
这里已是深宫内院. 陈列着一些工艺美术, 这就是后妃嫔女居住的
地方. 进了这儿可以深深感受到何谓“一入宫门深似海”. 宫门上挂着
一个镶边匾额:  "懿恭婉顺".
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"tinglang1",
		"south" : __DIR__"gong4",
	]));
	set("objects", ([ /* sizeof() == 4 */
		 __DIR__"npc/taohongying": 1,
	]));

	set("coor/x", -210);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}