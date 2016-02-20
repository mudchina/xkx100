//  Room:  /d/lanzhou/market.c

inherit  ROOM;

void  create  ()
{
	set("short",  "集市");
	set("long",  @LONG
热闹的集市里，人来人往，摩肩接踵，不时有人从你身边擦身而过。
偶尔也能看见几个江湖豪客在南边的顺风客栈休息、投宿。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"kedian",
		"north" : __DIR__"street1",
		"east"  : __DIR__"yangrouguan",
		"west"  : __DIR__"square",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/xiaofan" : 1,
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}