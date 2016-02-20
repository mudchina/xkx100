// Room: /beijing/dongcha2.c

inherit ROOM;
void create()
{
	set("short", "东长安街");
	set("long", @LONG
你走在东长安街上，踩着坚实的青石板地面。东边是东城门，可以
听到守城官兵的吆喝声。南边是打铁铺，叮叮当当的声音老远就能听到。
由于王府井大街就在北边，许多人都往北去，那里人声鼎沸，似乎十分
热闹。西边比这里更热闹，从那儿往北可以去王府井。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east"  : __DIR__"dongmen",
		"west"  : __DIR__"dongcha1",
		"south" : __DIR__"datiepu",
		"north" : __DIR__"wangfu1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
