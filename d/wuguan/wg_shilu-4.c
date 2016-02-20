// wg_shilu-4.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，东面过去就是后院了，西面是北练功场，
北面传来阵阵饭菜的香气，那里是武馆的饭厅。南面过去是武馆大厅。
LONG);
	set("exits", ([
		"west"  : __DIR__"wg_lang3",
		"east"  : __DIR__"wg_shilu-3",
		"south" : __DIR__"wg_shilu-2",
		"north" : __DIR__"wg_fanting",
	]));
	set("objects", ([
		__DIR__"npc/wg_emxiaost" : 1,
		__DIR__"npc/wg_tiezhangdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

