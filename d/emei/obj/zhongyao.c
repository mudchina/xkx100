// zhongyao.c 中药
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_use", "use");
}
void create()
{
	set_name("中药", ({"zhongyao", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包普通的中药。\n");
		set("value", 500);
	}
	setup();
}
int do_use(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("你要用什么药？\n");
	if(!present(this_object(), me)) return notify_fail("你要用什么药？\n");

	if ((int)this_player()->query("eff_qi") ==
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用中药。\n");
	else {
		this_player()->receive_curing("qi", 25);
		message_vision("$N煎了一包中药外敷内用，感到伤势好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}
