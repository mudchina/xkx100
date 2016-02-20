//  Room:  /d/lanzhou/eastgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "东门");
	set("long",  @LONG
这里是兰州东门。城外是一片茂密的树林，不过最近那边治安不太
好，因此几个守门官兵将城门紧紧关闭了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"street1",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing": 4,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9270);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}