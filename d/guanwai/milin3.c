// /guanwai/milin3.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
这是一片茂密的松林，杂乱的生长在倾斜的山坡上。每棵松树都有
三四抱粗细，高达十几丈。树冠枝多叶密，将天空完全遮住，因此林内
显得有些昏暗。树木之间长着很多灌木杂草，使行走很艰难，据说人参
就生长在这些杂草之中。
LONG );
	set("exits", ([
		"northdown"  : __DIR__"milin2",
		"eastup"     : __DIR__"heifengkou",
	]));
	set("count", 2);
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5200);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_dig","dig");
}
int do_dig()
{
	object ob,me;
	me = this_player();

	if (query("count") < 1)
	{
		message_vision("$N满怀希望挖了半天，别说千年人参了，连半年的都没有。\n",me);
		return 1;
	}
	add("count", -1);
	message_vision("$N感到挖到个什么东西，忙用红线别上，轻轻掏开旁边的细土，捡起来抹了土看看，这可是再正宗不过的长白人参了。\n", me);
	ob = new("/clone/medicine/vegetable/renshen");
	ob->move(me);
	return 1;
}