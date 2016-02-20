//  Room:  /d/luoyang/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "南郊小路");
	set("long",  @LONG
这是洛阳城郊的一条小路，向南望去便是雄伟的龙门，北面是洛阳
城，东面是洛阳一风景点：关林和龙门石窟。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"guanlin",
		"south" :  __DIR__"longmen1",
		"north" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/wudang/npc/tufei1" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
