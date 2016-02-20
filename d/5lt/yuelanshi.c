// Room: /d/5lt/yuelanshi.c

inherit ROOM;

void create()
{
	set("short", "阅览室");
	set("long", @LONG
这里是村支部的阅览室。自从配置了先进的多媒体设备，这儿就常
常座无虚席。
LONG );
	set("exits", ([
		"south" : __DIR__"chuandashi",
	]));
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}