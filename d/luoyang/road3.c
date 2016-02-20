//  Room:  /d/luoyang/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "城郊小路");
	set("long",  @LONG
这是洛阳城郊的一条小路，向南望去已可以看见襄阳城的轮廓，北
面就是通往洛阳城的龙门关口。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  "/d/xiangyang/caodi3",
		"north" :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
