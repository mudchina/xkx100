// /beijing/hai_dating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府大厅");
	set("long", @LONG
这是海澄公府的大厅，大厅不大，装饰也不华丽，很难想象这里竟
然是一等公爵的居所。此时大厅内外一片嘈杂，挤满了上门来寻事的御
前侍卫。
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dayuan",
		"south" : __DIR__"hai_houyuan",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/feng" : 1,
		__DIR__"npc/duolong" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
