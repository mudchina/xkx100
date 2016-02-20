// bag.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("油布包", ({ "bag", "bao" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个油布包裹。\n");
		set("value", 500);
		set("material", "cloth");
	}
	set("book_count", 1);
}

void init()
{
	if( this_player() == environment() )
	{
		add_action("do_open", "open");
		add_action("do_open", "unpack");
		add_action("do_open", "dakai");
	}
}

int do_open(string arg)
{
	object me, book;
	object where;

	if ( !arg ) return 0;
	return notify_fail("油布包里面什么也没有了。\n");
}
