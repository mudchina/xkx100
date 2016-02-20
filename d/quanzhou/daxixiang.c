// Room: /d/quanzhou/daxixiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "打锡巷");
	set("long", @LONG
这是普普通通的一条石板小路。走在上面，也许你根本想不到这是
施琅将军攻克台湾后为显其战功，将其城池的砌石运回铺成此路。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"southroad1",
		"east" : __DIR__"jiangjunfu",
	]));
	set("coor/x", 1860);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
