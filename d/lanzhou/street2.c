//  Room:  /d/lanzhou/street2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "滨河大街");
	set("long",  @LONG
这是兰州城内最大的一条街，从东门一直延伸到西门。往西可以出
西门继续向西域进发，向北出北门，经金城古城，便是黄河渡口了。南
边是城内的城隍庙。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road3",
		"south" : __DIR__"square",
		"east"  : __DIR__"street1",
		"west"  : __DIR__"street3",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}