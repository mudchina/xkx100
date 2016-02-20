//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "东街");
	set("long", @LONG
这是荆州城东的一条小街。虽然这里没有西街繁华，近日却也颇有
些江湖人物来去匆匆。西边是一堵高高的围墙，东边是一个茶馆。
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dongmen",
		"north" : __DIR__"dongjie1",
	]));
	set("objects", ([
		__DIR__"npc/langzhong": 1,
	]));

	set("coor/x", -1470);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}