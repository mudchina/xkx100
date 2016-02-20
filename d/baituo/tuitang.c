// Room: /d/baituo/tuitang.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>


void create()
{
	set("short", "退堂");
	set("long", @LONG
这间退堂不大，只放有两个茶几，挂了两副字画。西边的屋子挂着
重帘，看不清里面有什么。东边隔着重帘似乎是个小院子。往北就是一
给大花园了。
LONG);
	set("exits", ([
		"south" : __DIR__"tangwu",
		"north" : __DIR__"huayuan",
		"west"  : __DIR__"danfang",
		"east"  : __DIR__"yuanzi",
	]));
	set("objects", ([
		__DIR__"npc/jiren1" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
