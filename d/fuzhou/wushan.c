// Room: /d/fuzhou/wushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "福州乌山");
	set("long", @LONG
福州古城三山，以城内乌山、于山和屏山三山恃立之故也。乌山上
有乌塔。
LONG );
	set("exits", ([
                "northdown" : __DIR__"xidajie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
