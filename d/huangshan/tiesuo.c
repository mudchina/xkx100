// Room: /d/huangshan/tiesuo.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "铁索");
	set("long", @LONG

∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞

LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xuanyuan",
		"east" : __DIR__"huangshan",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
}
void init()
{
	object ob, me = this_player();

	if(me->query_kar() < random(30))
	{
		me->move(this_object());
		message_vision("$N脚下一个不稳，从铁索上直摔下去！\n", me);
		ob = load_object(__DIR__"kuzhu");
		me->move(ob);
		message_vision("只听到一声惨叫，$N不知从什么地方重重的摔了下来！\n", me);
		me->unconcious();
	}
	return;
}
