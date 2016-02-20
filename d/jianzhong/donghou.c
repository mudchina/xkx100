#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","深谷");
	set("long",@LONG
洞后深谷中风景更是幽雅，树木苍翠，山气清佳，你信步过
去观赏景色，不知不觉中走进了树林深处。
LONG
	);
	set("exits",([
		"north":__DIR__"donghou1",
		"south":__DIR__"dongkou",
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -430);
	set("coor/z", 0);
	setup();
}