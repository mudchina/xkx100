// room: /d/xingxiu/tianroad2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片
草原。路尽头松林下一位壮汉正在长啸练功。北上就是人人害怕的灵鹫
宫了。
LONG );
	set("exits", ([
		"northup"   : "/d/lingjiu/shanjiao",
		"northdown" : __DIR__"xxh",
		"south"     : __DIR__"tianroad1",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/dulong" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou"  : 1,
		"/clone/misc/dache" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");
	set("coor/x", -50000);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
