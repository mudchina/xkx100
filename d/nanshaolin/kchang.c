// Room: /d/nanshaolin/kchang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "空场");
	set("long", @LONG
这是法堂后面的一片空场，亦是少林寺的最后部分。因为这里地处
偏僻，亦是寺中重地，所以平常很少有僧人来这里。北面是千佛殿，东
面是白衣殿，西面是地藏殿。
LONG );
	set("exits", ([
		"west"  : __DIR__"dzdian",
		"east"  : __DIR__"bydian",
		"north" : __DIR__"qfdian",
		"south" : __DIR__"fatang",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

