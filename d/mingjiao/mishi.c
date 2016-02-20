// Room: /d/mingjiao/mishi.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "石室");
	set("long", @LONG
这间石室极大，顶上垂下钟乳，显是天然的石洞。走了几步，突见
地下倒着两具骷髅。骷髅身上衣服尚未烂尽，着得出是一男一女。走近
两具骷髅，只见那女子右手抓着一柄晶光闪亮的匕首，插在她自己胸口。
LONG );
	set("exits", ([
		"south" : __DIR__"midao0",
		"up"    : __DIR__"neishi",
	]));
	set("objects", ([
		__DIR__"obj/yangdt" : 1,
		__DIR__"obj/yangfr" : 1,
	]));
	set("no_clean_up", 0);
	set("xin_count", 1);
	set("coor/x", -52030);
	set("coor/y", 1080);
	set("coor/z", 90);
	setup();
	create_door("south", "石门", "north", !DOOR_CLOSED);
}
void init()
{
	this_player()->set_temp("ketou_times", 50);
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	object me, ob;

	me = this_player();
		
	if ( me->query_temp("ketou_times") == 0 )
	{
		message_vision("$N磕头磕得晕了过去。\n", me);
		me->set_temp("ketou_times", random(50));
		me->unconcious();
		return 1;
	}
	me->add_temp("ketou_times", -1);	

	message_vision("$N虔诚地跪下来，在阳教主遗骨前恭恭敬敬地磕头。\n", me);

	if ( random(20) == 3 && query("xin_count") > 0 )
	{
		add("xin_count", -1);
		ob=new("/d/mingjiao/obj/yixin");
		ob->move(this_object());
		tell_object(me, "突然你抬眼看到遗骨下面，有几张纸片！\n");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");
	return ::valid_leave();
}

