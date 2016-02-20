// /d/meizhuang/didao5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
你一到这里，迎面就闻到一股腐烂的泥土的味道，不过从前面的亮
光中，你又看到了希望，你不禁开始加快脚步，想看看那里到底有些什
么东西。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"lingmu",
		"south" : __DIR__"didao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
