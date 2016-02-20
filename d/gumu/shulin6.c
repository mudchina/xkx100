// shulin6.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自
密林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。不论往哪ㄦ走尽
是茂密的树林。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"  : __DIR__"shulin0",
		"east"  : __FILE__,
		"north" : __DIR__"shulin4",
		"south" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
