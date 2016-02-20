// wg_lang4.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，东面是武馆内的物品房，要在武馆做杂事的人都得去
物品房领工具，西边是南练武场。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wupinfang",
		"west" : __DIR__"wg_wuchang4",
	]));
	set("objects", ([
		__DIR__"npc/wg_thddizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

