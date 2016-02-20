// Room: /wuliang/road5.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这是条通往后山的羊肠小路，就是无量弟子也绝少来此。这里山
林茂密，人迹罕见，小鸟鸣响不绝于耳。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"road6",
		"east"   : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"obj/cao" : 2,
	]));
	set("coor/x", -71020);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}