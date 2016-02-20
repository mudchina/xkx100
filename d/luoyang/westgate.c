//  Room:  /d/luoyang/westgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "西门");
	set("long",  @LONG
出了此门，就不在洛阳城的管辖范围，进入长安的辖地，登上城楼
已可以隐隐看见函谷关的城楼了。西面是通往长安城的大官道，而东面
则是通向洛阳城中心的主要通道。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  "/d/changan/road1",
		"east"  :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -700);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
