// Room: /wuliang/shanlu4.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "栈道");
	set("long", @LONG
这是一段建在山坡脊上的栈道。云贵一带常有这样的栈道，这段
栈道不过因坡而建，虽然山风吹拂，枝木摇响，可是一点履险意味都
没有。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"shanlu3",
		"northup"  : __DIR__"shanlu5",
	]));
	set("coor/x", -70990);
	set("coor/y", -79990);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}