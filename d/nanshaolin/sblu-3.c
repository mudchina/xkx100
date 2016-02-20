// Room: /d/nanshaolin/sblu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条青石铺成的小路向西，北，东三个方向蜿蜒而去。石路上绝无
半点尘土，看来经常有人来打扫。路的两旁中满的翠绿的青竹，在微风
中左右摇曳，沙沙做响。北面是受戒的戒坛。
LONG );
	set("exits", ([
		"south"     : __DIR__"sblu-2",
		"northwest" : __DIR__"jietan1",
		"northeast" : __DIR__"jietan2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6140);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

