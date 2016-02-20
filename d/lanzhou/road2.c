//  Room:  /d/lanzhou/road2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "林荫道");
	set("long",  @LONG
这是一条宽阔的青石板街道，从南门一直向北延伸。两旁路树成荫，
不时有过往行人走过，和刚才城外荒凉的景象形成鲜明对比。北边是个
热闹的广场。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"southgate",
		"north" : __DIR__"square",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2680);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}