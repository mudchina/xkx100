// Room: /d/baituo/yuanzi4.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "院子");
	set("long", @LONG
这里堆放着上百堆的石头。这些石头有大有小，大如一间房屋，小如
一个鸭蛋，形状大多都呈圆柱形。你发现从有些石头之间的缝隙(fengxi)
中飘出一股股的腥臭味，使你快要做呕了。
LONG);
	set("exits", ([
		"southeast" : __DIR__"yuanzi2",
		"northeast" : __DIR__"yuanzi5",
		"east"      : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"fengxi": "\n缝隙里面漆黑一片，隐隐约约有沙沙的声响。\n",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	if(me->query_temp("baituo_stone2"))
	{
		me->delete_temp("baituo_stone2");
		me->set_temp("baituo_wait", 1);
		remove_call_out("do_open");
		call_out("do_open", 30, me);
	}
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if (arg == "fengxi" )
	{
		message_vision("$N刨开缝隙口的乱石子。\n" NOR, me); 
		message("vision", me->name() + "一弯腰往缝隙里钻了进去。\n", environment(me), ({me}) );
		me->move(__DIR__"fengxi2");
		message("vision", me->name() + "从外面钻了进来。\n", environment(me), ({me}) );
		return 1;
	}
}

void do_wait()
{
	object me = this_player();
	if(environment(me) && me->query_temp("baituo_wait"))
	{
		remove_call_out("do_open");
		call_out("do_open", 1, me);
	}
}

int do_open()
{
	string dir;
	object room;	
	message("vision","石柱忽然发出轧轧的声音，向一侧缓缓移开，向下露出一个黑洞洞的入口。\n", this_object() );
	set("exits/down", __DIR__"midao0");
	if( room = load_object(__DIR__"midao0") )
	{
		 room->set("exits/up", __FILE__);
		 message("vision",
 "头顶上的石柱忽然发出轧轧的声音，露出一个光亮亮的洞口。\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 3);
	return 1;
}

void close_door()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision","石柱发出轧轧的声音，缓缓地移回原处，将向下的洞口盖住了。\n", this_object() );
	if( room = load_object(__DIR__"midao0") )
	{
		room->delete("exits/up");
		message("vision","头顶上发出轧轧的声音，石柱又缓缓地收了回去，阶梯消失了。\n", room );
	}
	delete("exits/down");
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_wait");
	return ::valid_leave(me, dir);
}
