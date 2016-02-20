// xiang.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("大铁箱", ({"xiang"}));
	set_max_encumbrance(5000);
	set("weight", 100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一只大铁箱，好象有些什么东西在里头。\n");
		set("unit", "只");
		set("open_count", 1);
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
}

void init()
{
	add_action("do_open","open");
	add_action("do_open","unlock");
}

int do_open(string arg)
{
	object ob, me = this_player(), obj = this_object();
	if(!arg || arg != "xiang")
		return notify_fail("你要打开什么？\n");
	if( !present("tie key", me))
		return notify_fail("你撬不开大铁箱的锁。\n");
  if (me->is_busy())
  	return notify_fail("你现在正忙着呢。\n");
	if (query("open_count") > 0)
	{
		message_vision("$N用一把钥匙打开了大铁箱。\n", me);
		add("open_count", -1);

		ob = new("/clone/book/qing9da");
		ob -> move(obj);
		ob = new("/clone/money/gold");
		ob -> move(obj);
		ob = new("clone/jewelry/yubei");
		ob -> move(obj);
		ob = new("clone/jewelry/yudai");
		ob -> move(obj);
		ob = new("clone/jewelry/yufa");
		ob -> move(obj);
		ob = new("clone/jewelry/yujie");
		ob -> move(obj);
//		ob = new("clone/jewelry/yuruyi");
//		ob -> move(obj);
//		ob = new("clone/jewelry/yushou");
//		ob -> move(obj);
		ob = new("clone/jewelry/yuzhan");
		ob -> move(obj);
		me->start_busy(random(9) + 5);
		return 1;
	}
	else return notify_fail("大铁箱已经打开了。\n");
}
