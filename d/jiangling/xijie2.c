//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
这是荆州城西的一条南北走向的大街。似乎有不少武林中人来去匆
匆。西边是卖棺材的店铺，东边是一条僻静的小巷。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/caifan" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"xiang2",
		"south" : __DIR__"xijie3",
		"west"  : __DIR__"guancaipu",
		"north" : __DIR__"xijie1",
	]));

	set("coor/x", -1500);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}