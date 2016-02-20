// Room: /d/wuyi/tianchejia.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天车架");
	set("long", @LONG
天车架也称古崖居，位居丹霞嶂上。是清代咸丰年间三家士绅为逃
避太平军而在形如城壁的丹霞嶂的十余丈高处建的避难所。避难所建在
一串隙岩洞里，洞口有小楼半悬空中，洞沿设有围栏和吊架，可容百余
人。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"path15",
		"south" : __DIR__"path13",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4900);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

