//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
这是荆州城西的一条南北走向的大街。似乎有不少武林中人来去匆
匆。北边是城门，西边是卖墓碑的店铺，东边是一家打铁店。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/guofan" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xijie2",
		"west"  : __DIR__"mubeipu",
		"north" : __DIR__"beimen",
		"east"  : __DIR__"datie",
	]));

	set("coor/x", -1500);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}