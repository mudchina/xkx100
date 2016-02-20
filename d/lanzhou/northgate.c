//  Room:  /d/lanzhou/northgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "北门");
	set("long",  @LONG
这里便是兰州北门。由于最近正在加固城墙，因此显得有些凌乱。
城墙上下堆满了土石，上百民夫正在劳作。看来不等城墙修建好，城门
是不会开放的了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road4",
		"south" : __DIR__"road3",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 2,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9290);
	set("coor/y", 2720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}