// Room: /lingzhou/yipinzhang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "一品堂帐房");
	set("long", @LONG
这里是西夏一品堂的帐房，自愿加入一品堂的江湖高手，都可以领
到饷银。一个老先生两眼一抹黑在此管帐。
LONG );
	set("exits", ([
		"east"  : __DIR__"yipindayuan",
	]));
	set("objects", ([
		__DIR__"npc/zhangfang" :1,
	]));
	set("coor/x", -17980);
	set("coor/y", 32090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}