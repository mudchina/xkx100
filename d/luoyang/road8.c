// Room: /d/luoyang/road8.c
// Last modified by winder 2002.11.11

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。由于常年车马奔
驰，路面陷下深深的车辙。雨雪天气，泥泞不堪。晴天日头，又粉尘飞
扬。大道往东通向脂粉之都的扬州，而西面则是通往洛阳城。
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"east"      : __DIR__"road1",
		"northwest" : __DIR__"road9",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
