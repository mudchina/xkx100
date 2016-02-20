// wg_lang2.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向东练武场，人来人往的，很是热闹。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_wuchang2",
		"north" : __DIR__"wg_dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaohs" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

