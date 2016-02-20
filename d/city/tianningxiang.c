// Room: /yangzhou/tianningxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","天宁巷");
	set("long",@LONG
这里是一条僻静的小巷，行人寥寥无几，从此向南是彩衣街口，向
北是天宁寺，小巷的西边挂着一块乌木匾，上书“天宁书局”四个大字，
不过，由于地方过于偏僻，很少有人来这里买书。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"northwest"  : __DIR__"tianningshuju",
		"northeast"  : __DIR__"yuelaoci",
		"south"      : __DIR__"caiyijiekou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}