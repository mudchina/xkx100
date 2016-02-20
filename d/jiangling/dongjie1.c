//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "东街");
	set("long", @LONG
这是荆州城东的一条小街。虽然这里没有西街繁华，近日却也颇有
些江湖人物来去匆匆。西边是一条僻静的小巷，东边却是一座壮观的楼
阁。
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"yuanmiaoguan",
		"south" : __DIR__"dongjie2",
		"west"  : __DIR__"xiang1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}