// Feb. 6, 1999 by Winder
inherit ITEM;
void dest();
void setup()
{}
void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "down");
	call_out("dest", 20);
}
void create()
{
	set_name("暗道", ({"hole",}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个很小的洞。\n");
		set("unit", "个");
		set("no_get", "穷疯啦，洞也拿？\n");
	}
	setup();
}
int do_enter(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg!="hole" ) return 0;
	message("vision", me->name() + "一弯腰往洞里走下去。\n", environment(me), ({me}) );
	me->move("/d/shiliang/andao1");
	message("vision", me->name() + "从上面走了下来。\n", environment(me), ({me}) );
	return 1;
}	
void dest()
{
	destruct(this_object());
}
