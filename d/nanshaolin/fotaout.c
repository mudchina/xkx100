// Room: /d/nanshaolin/fotaout.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "古佛舍利塔");
	set("long", @LONG
这座佛塔通体饰成淡黄色，高三层，八角密檐，以沟纹大砖建造。
塔基以花岗石须弥座和三层砖雕仰覆莲花组成，塔身正面设有一个半人
高的拱型小门。
LONG );
	set("exits", ([
		"south" : __DIR__"talin11", 
		"enter" : __DIR__"fota1",       
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

