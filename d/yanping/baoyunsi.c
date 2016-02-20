// Room: /d/yanping/baoyunsi.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "宝云寺");
	set("long", @LONG
宝云寺位于九峰山上，始建于唐朝龙纪元年，原名南峰普济院，元
代改称“三寺”，遂有“三寺云深”景名。寺庙宏伟富丽，金碧辉煌，
寺旁古木参天，夕云起处，若隐若现。
LONG );
	set("exits", ([
		"northdown" : __DIR__"9fengshan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6230);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
