//  Room:  /d/lanzhou/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "官道");
	set("long",  @LONG
一条青石铺就的官道，向北通往兰州，往东则到达长安。道路两旁
是一片茂密的树林。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"southgate",
		"east"  : __DIR__"caoyuan5",
		"west"  : __DIR__"yizhan",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2660);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}