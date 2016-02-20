// Room: /d/guiyun/chufang.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是归云庄的厨房，供应弟子们每日的饭食。屋中充斥着青菜和调
料的味道。几个厨师正在忙碌着。偶尔会有些吃不完的主食和做菜时剩
下的猪肉留在这里。
LONG );
	set("exits", ([
		"west" : __DIR__"fanting",
	]));
	set("objects",([
		__DIR__"obj/meat" : 2,
		__DIR__"obj/baozi" : 1,
		__DIR__"obj/rice" : 1,
	]));
	setup();
	replace_program(ROOM);
}
