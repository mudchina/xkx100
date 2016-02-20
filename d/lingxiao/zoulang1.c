// Room: /d/lingxiao/zoulang1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","走廊");
	set("long",@LONG 
这是一条安静的走廊。上下都是凌霄弟子的居所，北边是耿万钟的
居室，听说他目前正在广收门徒。南边是汪万翼的房间。西边是一个安
静的小间，可以在那睡觉休息。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"sleep",
		"east"  : __DIR__"zhongting",
		"north" : __DIR__"roomgeng",
		"south" : __DIR__"roomwang", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

