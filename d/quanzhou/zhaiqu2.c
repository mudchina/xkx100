// Room: /d/quanzhou/zhaiqu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红
顶青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。北边和
南边都是宅区。西边则是泉州最大的「扬威武馆」。西南可通至源和堂。
间戏院，南边也是一大片宅区。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"xiyuan",
		"southwest" : __DIR__"yuanhetang",
		"west"      : __DIR__"wuguangate",
		"south"     : __DIR__"zhaiqu3",
		"north"     : __DIR__"zhaiqu1",
	]));
	set("objects", ([
		"/d/village/npc/kid" : random(3),
		"/d/village/npc/oldwoman" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
