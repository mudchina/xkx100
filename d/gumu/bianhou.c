// Room: /d/gumu/bianhou.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIB"匾后"NOR);
	set("long", @LONG
这里就是古墓中堂匾额之后，黑漆漆的什么都看不清楚。匾下石室
里点着烛火，一片晕黄。里面似乎还有一条通道。
LONG	);
	set("exits",([
		"down"  : __DIR__"zhongting",
		"enter" : __DIR__"mishi1",
	]));
	set("objects",([
		__DIR__"obj/silverkey" : 1,
	]));
	set("coor/x", -3200);
	set("coor/y", 10);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

