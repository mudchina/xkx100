// Room: /d/nanshaolin/sblu-2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条青石铺成的小路向西，北，东三个方向蜿蜒而去。石路上绝无
半点尘土，看来经常有人来打扫。路的两旁中满的翠绿的青竹，在微风
中左右摇曳，沙沙做响。东面似乎有轻微的水流声传到你的耳中。
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaolu5",
		"east"  : __DIR__"xiaolu1",
		"south" : __DIR__"lxting",
		"north" : __DIR__"sblu-3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



