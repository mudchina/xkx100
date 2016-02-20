//  Room:  /d/luoyang/northgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "北门");
	set("long",  @LONG
出了此门，就不在洛阳城的管辖范围了，门口站着的是守城官兵。
站在城楼望出去，外面是一片茅草路，据说可以通往各地，官兵守备也
不甚严。不少商贩正是利用这条小路将洛阳的唐三彩贩卖到京城各地。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"road5",
		"south"  :  __DIR__"northroad",
	]));
	set("objects",  ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
