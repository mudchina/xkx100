// baiyunwan.c 白云熊胆丸

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("白云熊胆丸", ({"baiyunxiudan wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗武林人士梦寐以求的疗伤圣药。\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	this_player()->receive_curing("qi", 100);
	this_player()->receive_curing("jing", 100);
	message_vision("$N吃下一颗白云熊胆丸，只觉精气上升，气色大好。\n", this_player());
	destruct(this_object());
	return 1;
}

