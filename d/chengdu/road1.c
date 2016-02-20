//Room: road1.c
//Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条通往成都的大青石道，两旁绿树荫蔽，空气十分清新。成
都平原向称天府之国，这里四周田野稻浪滚滚，平平展展的大地上，偶
尔会出现一大丛翠竹浓荫，细细认去，都是人家居处。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
		"east"      : "/d/emei/qsjie1",
		"southwest" : __DIR__"road2",
		"northwest" : __DIR__"liangting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6050);
	set("coor/y", -1010);
	set("coor/z", 0);
	set("coor/x", -6050);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

