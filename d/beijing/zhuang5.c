#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "庄府大厅");
	set("long", @LONG
这是一间大厅。通往各个房间，东边的屋里有女子啼哭之声隐隐传
来。
LONG );
	set("exits", ([
		"east"  : __DIR__"zhuang6",
		"west"  : __DIR__"zhuang7",
		"north" : __DIR__"zhuang8",
		"south" : __DIR__"zhuang4",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 2,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
