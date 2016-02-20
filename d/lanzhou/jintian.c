//  Room:  /d/lanzhou/jintian.c

inherit  ROOM;

void  create  ()
{
	set("short",  "金天观");
	set("long",  @LONG
你走过树林，发现树林后一道山门，上书------金天观。相传本观
始建于建文二年，主祀“雷祖”，故又称雷坛。永乐年间，赐名金天观。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"street3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}