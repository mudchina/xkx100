// Room: /d/city/kuixingge.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","魁星阁");
	set("long",@LONG
一座三层的阁楼倚墙而建，二楼的檐上挂着一金字匾额「魁星阁」。
一楼塑着魁星，只见他手拿生花妙笔，悠然坐在阁台上，面前的供桌摆
着一些个干鲜果品，偶然有几个书生进来跪拜魁星大人。
LONG    );

	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"caohebeijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
