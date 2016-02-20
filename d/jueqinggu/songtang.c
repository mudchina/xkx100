// Room: /d/jueqinggu/songtang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "松堂");
	set("long", @LONG
面前一座三间朝东的白石敞轩，后有古朴的假山叠石。四周遍植白
皮松，两侧是绝壁，只见两名绿衫僮儿手执拂尘，站在门前。
LONG
	);

	set("exits", ([
		"east"    : __DIR__"huacong11",
		"northup" : __DIR__"shanlu1",
		"westup"  : __DIR__"sanqingxuan",
		"south"   : __DIR__"qingzhiyuan",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	]));

	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

