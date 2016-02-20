// Room: /huanghe/shulin6.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶尔从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身后传来野
兽的啸声使人不觉犹豫了前进的脚步。
LONG );
	set("exits", ([
		"east"  : __DIR__"shulin5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -410);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}