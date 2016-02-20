// Room: /d/suzhou/dongdajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听
到守城官兵的吆喝声，北边是一家老字号的药铺，南边是打铁铺，叮叮
当当的声音老远就能听到。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"dongmen",
		"north"     : __DIR__"yaopu",
		"south"     : __DIR__"datiepu",
		"west"      : __DIR__"dongdajie1",
		"northwest" : __DIR__"hutong3",
	]));
	set("coor/x", 890);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
