// Room: /d/luoyang/road9.c
// Last modified by winder 2002.11.11

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上尘土飞扬，
将道边的绿树染上一层黄灰。大道往东通向脂粉之都的扬州，而西面则
是通往洛阳城。
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"west"      : __DIR__"road10",
		"southeast" : __DIR__"road8",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -140);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
