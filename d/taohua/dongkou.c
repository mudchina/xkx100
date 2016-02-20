// Room: /d/taohua/dongkou.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
在桃花丛里居然安排了这么一个岩洞，可见岛主用心之巧。岩洞周
围全是桃花，而向洞里看，黑乎乎地什么也看不见。
LONG
	);
	set("exits", ([ 
		"west"  : __DIR__"road3",
		"enter" : __DIR__"cave",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 9200);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}