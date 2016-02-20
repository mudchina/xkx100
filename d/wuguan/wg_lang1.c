// Last Modified by Sir on 9/17/2001
// wg_lang1.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向北练武场，人们急冲冲的走过，不时有人被抬出
来，看样子是练功脱力昏倒的。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_wuchang1",
		"south" : __DIR__"wg_dayuan",
	]));
	set("outdoors", "wuguan");
	set("objects", ([
		__DIR__"npc/wg_mrdizi" : 1,
	]));
	set("coor/x", 11);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

