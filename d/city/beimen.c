// Room: /city/beimen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "镇淮门");
	set("long", @LONG
这是扬州的北门「镇淮门」，城门两边站着几个士兵，盘查着过往
行人车辆。门前有一道深深的护城河，左右各开一水门，连接护城河和
官河及小秦淮河。城门建有高高的门楼，上有几个士兵持枪在警戒。门
楼上悬着金字匾额「镇淮门」。因为曾经失火，到现在城墙还是黑乎乎
的，因此白纸黑字的官府告示(gaoshi)就显得特别显眼。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beimendajie",
		"north" : "/d/nanyang/yidao",
		"west"  : "/d/huanghe/caodi1",
		"up"    : __DIR__"chenglou",
		"northeast" : __DIR__"hangou2",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}
