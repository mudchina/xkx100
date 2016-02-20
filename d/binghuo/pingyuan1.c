// Room: /binghuo/pingyuan1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "平原");
	set("long", @LONG
这里是十来里方圆的平原，此处竟有大片土地可供奔驰，实是说
不出的快活。沿途所见，除了低丘高树之外，尽是青草奇花。草丛之
中，偶尔惊起一些叫不出名目的大鸟小兽，看来也皆无害于人。向北
转过一大片树林，只见西北角上似乎是一座石山。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"haitan",
		"north"  : __DIR__"shulin3",
	]));
	setup();
	replace_program(ROOM);
}

