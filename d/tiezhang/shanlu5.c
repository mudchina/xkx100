// Room: /d/tiezhang/shanlu5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板铺成的小路上，两旁是高大的垂柳，虽在骄阳似火
的夏日，依旧凉爽怡人。因为小指峰风光秀美，游人较多，因此这里的
路也修砌的很好。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westup"   : __DIR__"sblu1",
		"eastdown" : __DIR__"pingtai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2050);
	set("coor/y", -1910);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

