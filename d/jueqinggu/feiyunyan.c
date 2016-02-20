// Room: /d/jueqinggu/feiyunyan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "飞云岩");
	set("long", @LONG
这里似洞非洞，顶上崖檐覆出，石乳倒垂。浮者若飞霞，亘者若虹
霓，豁然楼殿门阙，悬若铜鼓编磬，并有狮象蛟龙、莲荷阡陌、蜂房水
涡之属。其下澄潭邃谷，幽深无底，四面茂盛古树参天，流水潆洄。
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"xiangqinxie",
		"west"   : __DIR__"wuxi",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

