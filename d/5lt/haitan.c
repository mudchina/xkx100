// Room: /d/5lt/haitan.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "海滩");
	set("long", @LONG
洁白的沙滩、清澈的海水、凉爽的海风、明媚的阳光、高耸婆娑的
椰林，每天都有很多村民到这里欣赏美妙的大自然风光。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"   : __DIR__"yuchang",
		"south"  : __DIR__"xiaolu",
	]));
	set("coor/x", -195);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");

	if (arg != "chao" && arg != "tide")
		return notify_fail("你要往哪里跳？\n");

	if (me->query_dex() < 59)
		return notify_fail("你试图跳进海潮里，却总觉得力不从心。\n");

	if (me->query_skill("dodge") < 80)
		return notify_fail("你试图跳进海潮里，却发现自己的轻功修为还没有达到这么高的境界。\n");
	message_vision("$N耸身一跃，跳进了海潮中！\n", me);
	me->move(__DIR__"tide");
	return 1;
}