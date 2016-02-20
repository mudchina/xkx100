//  Room:  /d/lanzhou/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "官道");
	set("long",  @LONG
一条青石铺就的官道，向南通往兰州，往北三十里就是金城。道路
两旁是一片茂密的树林。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"northgate",
		"north" : __DIR__"jincheng",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}