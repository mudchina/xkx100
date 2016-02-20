// Room: /d/fuzhou/gushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "鼓山");
	set("long", @LONG
鼓山以山上有石形如鼓，扣之如擂鼓而得名，非只山势如鼓覆地。
山上苍松滴翠，岩秀谷幽，风景秀丽，四季如春。有晋以来，即为“八
闽二绝”之一。
LONG );
	set("exits", ([
		"north"    : __DIR__"yongquan",
		"westdown" : __DIR__"shulin",
		"southdown": __DIR__"luoxingta",
	]));
	set("objects", ([
		"/d/wudang/npc/monkey": 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1890);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
