// Room: /yangzhou/caohexiaojie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河小街");
	set("long",@LONG
沿小街西边是扬州官衙的高墙，多开漏窗，倚墙种着槐树，透过槐
树、漏窗，依稀可看到墙内是个园子。东边是官河，杨柳、碧桃临河而
植。小街向北边穿过小广场通向扬州的府学「资政书院」；东面是通泗
桥，连接着官河对岸的十里长街；南边多为民宅；西面是通泗街。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"tongsijie",
		"east"      : __DIR__"tongsiqiao",
		"south"     : __DIR__"caohenanjie",
		"north"     : __DIR__"xiaosquare",
		"southwest" : __DIR__"wudao4",
	]));
	set("objects", ([
		__DIR__"npc/youke1" : 1,
		"/d/mingjiao/npc/fenggongying" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if (dir == "southwest") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
