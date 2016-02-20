//  Room:  /d/luoyang/road5.c

inherit  ROOM;

void  create  ()
{
	set("short",  "北郊小路");
	set("long",  @LONG
这是洛阳城郊的一条茅草小路，草丛中时有小兽出没，小路向北延
伸直达黄河岸边。往东北通往牡丹园，南面可以遥遥看到洛阳城门。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"     : __DIR__"road6",
		"south"     : __DIR__"northgate",
		"northeast" : __DIR__"mudan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
