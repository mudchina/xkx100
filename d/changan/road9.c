//  Room:  /d/changan/road9.c

inherit  ROOM;

void  create  ()
{
	set("short",  "官道");
	set("long",  @LONG
一条青石铺就的官道，向北通往兰州，往东南则到达长安。道路两
旁是一片茂密的树林。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"     :  "/d/lanzhou/caoyuan1",
		"southeast" :  __DIR__"road8",
	]));
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("coor/x", -5100);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
