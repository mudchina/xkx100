// Room: /d/heimuya/tian1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "天香堂");
	set("long",@LONG
这里是黑木崖的第四大堂“天香堂”。一中年妇人横眉立在当地。
LONG );
	set("exits", ([
		"northdown"   : __DIR__"dating4",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/sang" : 1,
	]));       
//	set("no_clean_up", 0);
	set("coor/x", -3010);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}