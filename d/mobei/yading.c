// Room: /d/mobei/yading.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "山崖顶");
	set ("long", @LONG
崖顶是个巨大的平台，积满了皑皑白雪。几块巨大的石头半卧在一
边，形状千奇百怪，上面有许多洞穿的小孔，风过处，如泣如诉。四边
的山崖平平如削，几棵矮树就斜长于崖边。
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("coor/x", -250);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","tiao");
}
int do_jump(string arg)
{
	object me = this_player();

	if (arg !="down") return notify_fail("你要跳到那去？\n");
	if( arg=="down")
	{
		write("你纵身跳下了山崖。\n");
		message("vision", me->name() + "一纵身跳下了山崖。\n", environment(me), ({me}) );
		me->move(__DIR__"downxuanya");
		message("vision", me->name() + "从山崖上面跳了下来。\n", environment(me), ({me}) );
	}
	return 1;
}
