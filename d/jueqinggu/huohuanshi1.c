// Room: /d/jueqinggu/huohuanshi1.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这里是间丈许见方的石室，四面光秃秃的都是石壁。只有一个小孔
射出微弱的光亮。热气蒸腾，让人无法忍受。
LONG
	);

	set("exits", ([
		"out" : __DIR__"huohuanshi",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

