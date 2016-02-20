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
	object me, book ,bag;
	object where;

	if ( !id(arg) )
	{
		return notify_fail("什么？\n");
	}
	if ( query("book_count") < 1)
	{
		return notify_fail("油布包里面什么也没有了。\n");
	}

	me = this_player();
		where = environment(me);
message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"找到九阳真经啦。\n"NOR, users());
		message_vision(
"$N轻轻地把油布包来看时，里面原来是四本薄薄的经书，只因油布包得紧密，虽
长期藏在猿腹之中，书页仍然完好无损。\n", me);
		book = new("/clone/book/jiuyang1");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang2");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang3");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang4");
		book->move(file_name(where));
		add("book_count",-1);
		bag = new(__DIR__"bag1");
		bag->move(this_player());
		destruct(this_object());
	return 1;
}
