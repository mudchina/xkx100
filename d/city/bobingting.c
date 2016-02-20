// Room: bobingting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "搏饼厅");
	set("long", @LONG
这里是搏饼厅，也是「侠客行一百」玩家们聚会的地方。每逢大日
子，新老玩家们都会赶来这里，大侠小虾一块儿热热闹闹地乐一乐。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("objects", ([
		__DIR__"player/fandog": 1,
	]));
	set("exits", ([
		"west"  : __DIR__"bobing1",
		"east"  : __DIR__"bobing2",
		"north" : __DIR__"duchang",
		"south" : __DIR__"bobing3",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
