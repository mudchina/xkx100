// xiaowu2.c 蜂屋
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "蜂屋");
	set("long", @LONG
这里是小龙女喂养训练玉蜂的蜂屋，屋角上挂着很多个六角形的蜂
巢，还未进门，就闻得到一阵蜂蜜的甜香。
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao12",
		"south" : __DIR__"mudao13",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));
	set("coor/x", -3180);
	set("coor/y", -20);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
