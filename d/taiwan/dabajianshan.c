// Room: /d/taiwan/dabajianshan.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大霸尖山");
	set("long", @LONG
竹东郡与大湖郡交界处，一峰突立，即为大霸尖山，山高千丈，和
东侧连互的次高山组成山脉，素有「世纪奇峰」之称的大霸尖山，巨岩
突兀，泰雅族尊奉为「祖山」。
LONG );
	set("exits", ([
		"westdown" : __DIR__"maolishe",
	]));
	set("objects", ([
//		__DIR__"npc/taiyaren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2530);
	set("coor/y", -6990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

