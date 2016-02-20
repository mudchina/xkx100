// Room: youxiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "游嬉厅");
	set("long", @LONG
游嬉厅一贯热闹非凡，人来人往的嘈杂，帮闲的吆喝，鸡飞狗跳的
声音，赌徒满脸油汗的臭气，充斥了整个空间。如果你没兴趣，那是真
不想在这里呆的。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"doujiroom",
		"east"  : __DIR__"saiguiroom",
		"north" : __DIR__"zoulang2",
		"south" : __DIR__"yaqianroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
