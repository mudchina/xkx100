// Room: /d/tiezhang/zoulang2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条走廊上，四周昏暗一片，寂静异常。北面的屋子似乎有
翻书的哗哗声一阵阵传出。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"zoulang3",
		"east"  : __DIR__"wztang",
		"north" : __DIR__"shufang",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2050);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
