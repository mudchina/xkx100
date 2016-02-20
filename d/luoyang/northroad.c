//  Room:  /d/luoyang/northroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "中州街");
	set("long",  @LONG
不知道为什么，走在这条路上，总感觉差了点什么，也许由于连年
的战乱，使得本来很热闹的街市冷冷清清，道路两旁的店铺早已破旧不
堪，一眼望去便知道有很久没有人居住了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"northgate",
		"south"  :  __DIR__"center",
	]));
	set("objects",  ([
		"/d/huashan/npc/youke" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
