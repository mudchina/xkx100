// Room: /yangzhou/sixiepu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","李家丝鞋铺");
	set("long",@LONG
李家做的丝鞋，以「舒适合脚，轻便耐穿」而著称。铺内陈列着一
双特大个的白丝鞋，看来只有巨灵神才穿的下。柜台上放着几双丝鞋，
边上的鞋架上放着皮靴、皂靴等各式鞋样，可供客人试穿，以便挑选到
自己喜欢的合适的鞋。
LONG );
	set("exits", ([
		"south" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/libailv" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}