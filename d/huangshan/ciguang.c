// Room: /d/huangshan/ciguang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "慈光阁");
	set("long", @LONG
已是桃花峰顶，看下面的温泉犹如颗颗明珠，嵌映群峰，前面就是
青鸾桥，游人到此一般都要稍做歇息，于是便有了这座慈光阁。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"wenquan",
		"northdown" : __DIR__"qingluan",
		"west"      : __DIR__"taoyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
