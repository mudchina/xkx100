// Room: /d/taishan/xiangshan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "象山");
	set("long", @LONG
天街南为象山，俗称象鼻峰，山南崖奇石下垂似象鼻而名。峰西为
白云洞，峰东有青云洞。
LONG );
	set("exits", ([
		"north"    : __DIR__"tianjie",
		"eastdown" : __DIR__"qingyun",
		"westdown" : __DIR__"baiyun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
