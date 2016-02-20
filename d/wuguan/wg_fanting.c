// wg_fanting.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这里是武馆内用餐的地方。屋里布置很简单, 只摆着几张桌椅几个
人在一声不响地吃着。一个厨子在不停的忙碌着，你可以向他要食物和
水。看着可口的饭菜，你忍不住也想叫(order)一份。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_shilu-4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 41);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_order","order");
}

int do_order(string arg)
{
	object me=this_player();
	object food;
	object water;

	if (arg) return notify_fail("这样东西这里没有啊。\n");
	if ((present("bowl",this_player()) || present("rice",this_player())))
		message_vision("厨子冲出来，瞪了$N一眼：“还没吃完又想要！”\n", me);
	else
	{
		message_vision("厨子连忙从厨房出来，把一碗米饭和一碗水拿了给$N。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/bowl");
		food->move(me);
		water->move(me);
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	me=this_player();

	if(( dir=="south" ) && (present("bowl",this_player()) ||
		present("rice",this_player())))
		return notify_fail("厨子说道：食物和饮水不能带出膳堂去。\n");
	return ::valid_leave(me,dir);
}
