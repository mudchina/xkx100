// Room: /d/huangshan/taoyuan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "桃源亭");
	set("long", @LONG
这里位于桃花峰上，周围溪流环绕，宛若仙居，故称桃源亭，此处
最佳之处在于可以静心欣赏黄山三名瀑之一的“人字瀑”，远看过去，
瀑布倾泄，恰好是个人字，煞是有趣。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"ciguang",
	]));
	set("objects", ([
		__DIR__"obj/ting" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
