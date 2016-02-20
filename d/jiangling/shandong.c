//Edited by fandog, 02/18/2000
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "山洞");
	set("long", @LONG
洞中有戚芳用黏土捏的泥人，狄云用来弹鸟的弹弓，捉山兔的扳机，
戚芳放牛时吹的短笛，放在洞里的石上。那边是戚芳的针线篮。篮中的
剪刀已生满了黄锈。针线篮中还有一本旧书，那是戚芳用来夹鞋样、绣
花样的。
LONG );
	set("exits", ([
		"out"  : __DIR__"dashandong",
	]));
	set("book_count", 1);
	set("no_clean_up", 0);
	set("coor/x", -1640);
	set("coor/y", -2210);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object obj, me = this_player();
	if( !arg || arg!="book" ) return notify_fail("你要拿什么?\n");
	if( query("book_count") )
	{
		obj = new (__DIR__"obj/tangshi");
		obj->move(me);
		add("book_count", -1);
		message_vision("$N随手从针线篮中拿起一本旧书，书的封面上写着“唐诗选辑”四个字。\n",me );
message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到唐诗选辑啦。\n"NOR, users());
	}
	else
		return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
	return 1;
}