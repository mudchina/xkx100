// Room: /city/nanmen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "安定门");
	set("long", @LONG
一座高大的城门耸峙在渡江桥头，城门嵌有「安定门」三字石额。
城墙上建有一个城楼，几个巡逻的官兵们被近处的欢声笑语所吸引，似
乎不是很认真在执勤。左右各有一个水门，便于官河和小秦淮河流通，
及城内外的水运的便利。城墙被当成了广告牌，贴满了花花绿绿各行各
业的广告，城门口贴着几张榜文告示(gaoshi)因此不太显目。大量的行
人车辆进出安定门，熙熙攘攘的人群立即使人感受到扬州的繁华。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"dujiangqiao",
		"north" : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}