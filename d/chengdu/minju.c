// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这里是民居，门口挂着一串串风干的红辣椒和花椒，窗户糊着几层
花花纸。有几个居民在烧火做饭。
LONG	);
	set("exits", ([
		"west" : __DIR__"nanjie1",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

