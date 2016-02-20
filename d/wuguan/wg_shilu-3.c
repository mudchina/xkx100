// wg_shilu-3.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，一直通向后院，路两旁是些普通的花草，树
上的小鸟，不停的叫着。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_houyuan",
		"west" : __DIR__"wg_shilu-4",
	]));
	set("objects", ([
		__DIR__"npc/wg_puren1" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 51);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

