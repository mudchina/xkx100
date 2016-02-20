// Room: /d/wuxi/road6.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
走在这条行人稀少的官道，虽然不会遇见什么匪盗，但心里总是有
些忐忑不安。再向北走就快到了要塞了，向南是通向无锡城里去的路，
路面干净得很。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"road5",
		"north"  : __DIR__"paotai",
	]));
	set("coor/x", 370);
	set("coor/y", -730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}