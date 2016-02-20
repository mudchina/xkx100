// Room: road2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条通往成都的大青石道，两旁绿树荫蔽，空气十分清新。
成都平原向称天府之国，四野鸡鸣犬吠，交替起落，一派安乐气息。
西面隐隐可以看到成都城门了。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"road1",
		"west"      : __DIR__"fuheqiaoe",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -3000);
	set("coor/z", 0);
	set("coor/x", -6100);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

