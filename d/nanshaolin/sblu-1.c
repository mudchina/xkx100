// Room: /d/nanshaolin/sblu-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条宽阔的石板路上。这是用一米见方的巨大石板铺设而成
的，可以并行十来个人也绝无问题。两侧是参天古柏，直耸入天，上端
树冠相叠，遮天蔽日。几个僧人与香客来往于其间。路的尽头，矗立着
金壁辉煌的大雄宝殿。
LONG );
	set("exits", ([
		"southeast" : __DIR__"celang-4",
		"southwest" : __DIR__"celang-2",
                "south"     : __DIR__"twdian",
                "north"     : __DIR__"xianglu",
	]));
	set("objects",([
		__DIR__"npc/zjseng1" : 1,
		__DIR__"npc/slseng1" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

