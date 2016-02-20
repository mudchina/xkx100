//ROOM: /d/huashan/changlang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long",@LONG
你走在长廊上只见红栏碧瓦，雕梁画栋，廊外风吹翠竹，细吟阵阵，
看来华山派气派果然不凡。西面是岳夫人的居室。
LONG );
	set("exits", ([
		"west"  : __DIR__"jushi",
		"north" : __DIR__"songlin1",
		"south" : __DIR__"garden",
	]));
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 230);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
