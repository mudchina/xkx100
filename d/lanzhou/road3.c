//  Room:  /d/lanzhou/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "林荫道");
	set("long",  @LONG
这是一条宽阔的青石板街道，从北门一直向南延伸。两旁路树成荫，
不时有过往行人走过，和刚才城外荒凉的景象形成鲜明对比。南边是城
内最大的大街------滨河大街。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"northgate",
		"south" : __DIR__"street2",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}