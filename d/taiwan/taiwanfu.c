// Room: /d/taiwan/taiwanfu.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "台湾府");
	set("long", @LONG
明朝天启四年，“开台王”颜思齐率众立寨入垦台湾，即择苯港登
陆。思齐见岛上地肥水美、大片荒野未辟，决意在此开疆拓土，干一番
事业。乃率聚伐木辟土，构筑寮寨。是时，土番以为外敌侵犯，聚族攻
击。思齐遣人加以安抚，商定疆界，互不侵扰。笨港分南北，中隔一溪，
曰南街，曰北街，舟车辐辏，百货骈阗，俗称小台湾。民谚说「一府二
笨」，不是虚言。
LONG );
	set("exits", ([
		"west"      : __DIR__"bengang",
		"northeast" : __DIR__"banxianshe",
		"southeast" : __DIR__"pingye",
	]));
	set("objects", ([
		__DIR__"npc/shangren": 2,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

