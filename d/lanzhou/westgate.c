//  Room:  /d/lanzhou/westgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "西门");
	set("long",  @LONG
这里是兰州西门。由于早年遭受进攻，因此城墙破损较为严重。再
往西北过黄河便是官府势力以外的地方了，不少在中原犯了大案的盗匪
在这里闯关西逃。守城的几个官兵正在盘查过往行人。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"street3",
		"west" : "/d/xingxiu/xxroad1",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 4,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9400);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}