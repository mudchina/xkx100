//  Room:  /d/luoyang/westroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "问鼎街");
	set("long",  @LONG
相传春秋时代，楚王在此仰望周王城，问鼎重几何。周室暗弱，居
然隐忍不发。这便是街名的由来。湿润的青石路显然是刚刚下过雨，因
为来往行人过多，路面多少有些坑坑凹凹，一不留神很容易被绊到。这
里是洛阳繁华之处，北面就是号称中州第一的金刀王家了，南面是一家
专门卖唐三彩的店铺。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"westgate",
		"east"  :  __DIR__"center",
		"south" :  __DIR__"dianpu",
		"north" :  __DIR__"wanggate",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangbofen" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
