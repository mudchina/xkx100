// Room: /d/wuxi/road8.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "乡间小道");
	set("long", @LONG
路两边的树都低矮了许多，许多不知名的小野花在轻风中点来点
去，透过树枝看到两边都是一望无际的田野。你怎么也不会想到这里
就是孕育吴越文化的梅村了。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"road7",
		"west"   : __DIR__"road9",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}