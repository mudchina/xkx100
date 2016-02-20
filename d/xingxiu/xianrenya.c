// Room: /d/xingxiu/xianrenya.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "仙人崖");
	set("long", @LONG
这里以传说有神仙出没而得名，每到盛夏夜，火光从崖面飞出，名
曰仙人送灯。面山带水，群峰环峙，野草蒙茸，奇花异树，清幽险峻，
令人绝俗。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"northwest" : __DIR__"shuiliandong",
		"northeast" : __DIR__"silk1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20000);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";
