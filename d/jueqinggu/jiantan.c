// Room: /d/jueqinggu/jiantan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "剑潭");
	set("long", @LONG
只见这里壁上、桌上、架上、柜中、几间，尽皆列满兵刃，式样繁
多，其中十之八九都是古剑，或长逾七尺，或短仅数寸，有的是铁锈斑
驳，有的却仍寒光逼人。
LONG
	);
	set("exits", ([
		"north" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
 	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

