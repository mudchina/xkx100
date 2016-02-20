//Room: /d/huashan/shop.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "山顶小店");
	set("long", @LONG
这里是华山山顶的一间小店，卖些简单的饮食，专门赚那些游客的
钱。
LONG );
	set("exits", ([
		"east" : __DIR__"square",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
