// Room: /d/xiangyang/westjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西边是一
个大十字街口。东面是襄阳的中央广场，北边是人称郭大侠郭
靖的府邸大门，不时地有人从那里进进出出。南面是一家当铺，
听说里面常能买到你所需的东西。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"guangchang",
		"west"  : __DIR__"westjie2",
		"south" : __DIR__"dangpu",
		"north" : __DIR__"guofugate",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}