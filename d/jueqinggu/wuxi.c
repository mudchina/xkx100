// Room: /d/jueqinggu/wuxi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "浯溪");
	set("long", @LONG
突然一阵清香涌至，眼前无边无际的全是水仙花。原来地下是浅浅
的一片水塘，深不逾尺，种满了水仙。前面好象是一片遍野的花丛，很
难变清道路。一种迥异的香味在空气中弥漫着。
LONG
	);

	set("exits", ([
                "east"  : __DIR__"feiyunyan",
                "enter" : __DIR__"huacong1",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -500);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

