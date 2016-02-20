// Room: /d/chengdu/chufang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
一张长长的灶台上放了五六口铁锅，每口锅面前都有一位大师傅，
他们正在汗流浃背地炒着菜。
LONG	);
	set("exits", ([
		"west" : __DIR__"chenmapo",		
	]));
	set("objects", ([
		__DIR__"npc/dashifu" : 3,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

