//  Room:  /d/luoyang/road5.c

inherit  ROOM;

void  create  ()
{
	set("short",  "北郊小路");
	set("long",  @LONG
这是洛阳城郊的一条茅草小路，东北面仿佛是通往渡口的小路，而
南面则是洛阳城门。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast" :  __DIR__"dukou",
		"northup"   :  __DIR__"mangshan",
		"south"     :  __DIR__"northgate",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
