// Room: /d/changcheng/nansilou.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南四楼");
	set("long", WHT@LONG
一旦爬上十分陡峭的南四楼，你终于知道了“不到长城非好汉”的
况味了。疲惫之余，临风怡然远眺，东边是三十里长的关沟，似乎近在
咫尺。南面群山万壑之外，就是京城了。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"eastdown"  :__DIR__"changcheng22",
		"northdown" :__DIR__"beisilou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2000);
	set("coor/y", 5000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}