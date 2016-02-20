// Room: /d/quanzhou/zhaiqu3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红
顶青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。东边的
刺桐南路传来繁闹的喧哗声。西边有家出名的蜜饯制作铺「源和堂」。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"southroad2",
		"west"  : __DIR__"yuanhetang",
		"north" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		"/d/village/npc/girl" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
