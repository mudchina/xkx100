// Room: /d/nanshaolin/gchang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "广场西侧");
	set("long", @LONG
这里是天王殿前的一个广场。广场正中放着个二人高的青铜大香炉，
前面摆着个香台，几位香客正在虔诚谟拜。自此向左有一间偏殿，供比
丘们打坐诵经之用。北面有一个长廊，通向天王殿后。
LONG );

	set("exits", ([
		"east"  : __DIR__"gchang-1",
		"west"  : __DIR__"cdian-2",
		"north" : __DIR__"celang-1",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

