// Room: /d/wuxi/road10.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
一条不宽的林荫道，两排香樟树在路两边搭起了一个天然的凉蓬，
中间夹杂着一些杨柳树，在风中摇摇荡荡，令人心旷神怡。北面是通
向无锡城里去的。再向南就要到太湖了。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"road7",
		"south"   : __DIR__"road11",
	]));
	set("objects", ([
		__DIR__"npc/shusheng" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -870);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}