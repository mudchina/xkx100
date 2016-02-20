//  Room:  /d/luoyang/eastgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "东门");
	set("long",  @LONG
由此洛阳城东门出去，就可以通往洛阳另一个著名的名胜古迹：白
马寺。再往东一些就可以到达烟花三月的扬州了。西面是通往洛阳城中
心的主要干道，东面是出城的大道。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"road2",
		"west"  :  __DIR__"eastroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
