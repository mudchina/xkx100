// Room: /d/quanzhou/zhaiqu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红
顶青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。西边是
间戏院，南边也是一大片宅区。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"southroad1",
		"west"  : __DIR__"xiyuan",
		"south" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		"/d/village/npc/boy" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
