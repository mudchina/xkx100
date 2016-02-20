// item: whiteobj.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"白布小囊"NOR, ({"baibu xiaonan", "xiaonan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一只白布小囊，好象可以打开的。\n");
		set("unit", "只");
		set("value", 1);
	}
}
void init()
{
	add_action("do_dakai", "dakai");
}
int do_dakai(string arg)
{
	object bu, me = this_player();
	string message;
	int col;

	if(!id(arg)) return notify_fail("你要拆什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要拆什么？\n");
	message_vision("$N拆开白布小囊，摊开发现是张白布！\n", me);
	bu = new(__DIR__"whitecloth");
	bu->move(me);
	destruct(this_object());
	return 1;
}

