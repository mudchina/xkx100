// /d/taohua/liangongfang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这是桃花岛上的练功房。房中摆着几个机关人，是给桃花岛弟子练
功用的。这里经常有弟子们在此练功，打得四处尘土飞扬。房后是桃花
岛的试剑峰。
LONG );
	set("exits", ([
	    "south" :__DIR__"lianwuchang",
	    "north" :__DIR__"siguoshi" ,
	]));
	set("objects", ([
	      __DIR__"npc/jiguan" : 5,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}