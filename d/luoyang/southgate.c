//  Room:  /d/luoyang/southgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "南门");
	set("long",  @LONG
由此洛阳城南门出去，就可以通往洛阳著名的名胜古迹：关林和龙
门石窟，再往南一些就可以到达郭靖率领各路英雄捍卫的襄阳城。北面
是通往洛阳城中心的主要干道，南面是出城的小路。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"luopu",
		"north" :  __DIR__"southroad",
		"south" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
