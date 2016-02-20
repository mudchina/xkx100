// Room:  /d/luoyang/dukang.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "杜康仙庄");
	set("long",  @LONG
杜康仙庄是酒祖造酒遗址，是酒文化发源地。“杜康仙庄”为周平
王封赐，位于洛阳东南一百里杜康村。山门是琉璃瓦的朱红门楼，进入
庄内有杜康祠，爬山碑廊，雕栏池，樱花圆和七贤台。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road7",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
