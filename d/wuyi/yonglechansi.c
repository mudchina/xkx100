// Room: /d/wuyi/yonglechansi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "永乐禅寺");
	set("long", @LONG
“自古田园风光好，天下名山僧占多”。位于天心岩腹地的天心永
乐禅寺，从创建的那天起，就把禅心裹进武夷的山水中去了。周围群峰
料峭，古木参天。数百年过去了，每天的晨钟暮鼓，敲打着同样的声调：
“天心原佛国碧水丹山开法界，永乐本禅居清风明月皈真如。”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"tianxinyan",
		"south"     : __DIR__"path5",
		"southwest" : __DIR__"path11",
		"northwest" : __DIR__"path14",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng": random(2),
		"/d/hangzhou/npc/shami": random(3),
	]));
	set("coor/x", 1400);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

