// Room: /d/wuxi/road7.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
一条不宽的林荫道，两排香樟树在路两边搭起了一个天然的凉蓬，
中间夹杂着一些杨柳树，在风中摇摇荡荡，令人心旷神怡。北面是清
名桥，向南一直通向太湖。西边有一条小道，通向梅村的泰伯庙。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"road8",
		"south"  : __DIR__"road10",
		"north"  : __DIR__"qingmingqiao",
	]));
	set("coor/x", 370);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}