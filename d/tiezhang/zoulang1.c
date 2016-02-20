// Room: /d/tiezhang/zoulang1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条走廊上。北面的屋内传来阵阵金属的声音。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"bqshi",
		"west"  : __DIR__"wztang",
		"east"  : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2030);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}