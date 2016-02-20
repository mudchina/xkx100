// Room: /binghuo/wangpangu1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "谷口");
	set("long", @LONG
走近山谷，前面向南就是群雄聚会之处。王盘山岛正当海潮生息
之所，海风劲烈，风势在这谷口里聚焦，更是吹得满山树枝乱舞，沙
尘漫天。往南望去，只见山谷里一片青草地上摆着七八张方桌，除了
东首第一席外，每张桌旁都已坐了人。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"north" : __DIR__"wangpanshan",
		"south" : __DIR__"wangpangu2",
	]));
	set("objects", ([
		"/d/mingjiao/npc/changjinpeng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

