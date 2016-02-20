// Room: /d/taiwan/banxianshe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "半线社");
	set("long", @LONG
半线社位于台湾西部平原中段，为平埔族游猎之地。明郑时代已有
汉人聚居，清初隶诸罗县，闽海居民相继东渡，移垦台湾西部中段，此
地才渐渐繁盛起来。
LONG );
	set("exits", ([
		"northeast" : __DIR__"maolishe",
		"west"      : __DIR__"lugang",
		"southwest" : __DIR__"taiwanfu",
		"southeast" : __DIR__"riyuetan",
	]));
	set("objects", ([
		__DIR__"npc/nongfu": 2,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

