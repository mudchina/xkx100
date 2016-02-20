// /d/shenlong/caodi.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里是一片青青的草地，有几个少年在玩耍。四周开满了各色的鲜
花，一阵凉风吹过，清新的空气中传来几缕淡淡的花香。
LONG );
	set("exits", ([
		"west"  : __DIR__"kongdi",
		"north" : __DIR__"xiaowu",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);
	set("coor/x", 4000);
	set("coor/y", 3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
