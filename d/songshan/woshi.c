// Room: /d/songshan/woshi.c
// Last Modified by winder on Jul. 17 2001

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
你走进了一间卧室。一种非常清亮的感觉扑面而来。琴剑书画，挂
在墙上。窗明几净，一切都井井有条。
    右首一张床，床上一条黄缎被，看起来很是舒适。
LONG );
	set("exits", ([
		"west" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 930);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
