//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
这是荆州城西的一条南北走向的大街。似乎有不少武林中人来去匆
匆。西边是一座轩朗巍峨的道观，东边是万家大院，南边是高大的城门。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/xiangnong" : random(3),
		__DIR__"npc/xiaofan" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"damen",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"kaiyuanguan",
		"north" : __DIR__"xijie3",
	]));
	set("coor/x", -1500);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
