// Room: /yangzhou/xichuntai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","熙春台二楼");
	set("long",@LONG
熙春台位于瘦西湖西岸，与莲花桥遥遥相对。乾隆宸苑卿汪廷璋建，
旧景“春台明月”，为乾隆盛世北郊二十四景之一。传说曾于此为乾隆
皇帝祝寿，故又名“春台祝寿”。
    楼层上悬“熙春台”大匾，两列竹简壁挂，融书法、篆刻于一体，
镌刻历代名家歌咏扬州的诗词和古二十四桥桥名。顶棚三百六十五只竹
编灯笼，入夜五彩缤纷，熠熠生辉。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"down"   : __DIR__"xichuntai",
	]));
	set("objects", ([
		"/d/city/npc/lady1" : 1,
	]));
	set("coor/x", -60);
	set("coor/y", 100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
