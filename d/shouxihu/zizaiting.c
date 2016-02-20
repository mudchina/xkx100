// Room: /yangzhou/zizaiting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","观自在亭");
	set("long",@LONG
琴室东南湖岸边，旧有御碑亭一座，现故址重修为“观自在亭”，
内置石桌、石凳，以观水景。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northwest"  : __DIR__"qinshi1",
	]));
	set("objects", ([
		"/d/city/npc/lady2" : 1,
	]));
	set("coor/x", 30);
	set("coor/y", 90);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
