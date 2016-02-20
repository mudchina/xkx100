// Room: /d/quanzhou/nantaiyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "南台岩");
	set("long", @LONG
「苍崖千尺峭空虚」，这是清源山的最高处。一片高耸的巨石屹然
矗立，前面是悬崖峭壁，形势十分险峻。岩石上镌刻着「空中台阁」四
大字。临台建有「魁星阁」，因为山势高，这里常含云吐雾，漫为云海，
从山下仰视，如在空中。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"qingyuandong",
		"westdown" : __DIR__"laojunyan",
	]));
	set("coor/x", 1830);
	set("coor/y", -6380);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
