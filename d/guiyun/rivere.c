// Room: /d/guiyun/rivere.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", "小河东岸");
	set("long", @LONG
这里是一条小河之滨，四下都是乱坟。往周围看去，并无桥梁可以
过河(he)。
LONG );
	set("exits", ([
		"east" : __DIR__"road1",
	]));
	set("item_desc", ([
		"river" : "小河很宽，河水下面隐隐约约有什么东西。你看不清。\n",
		"he"    : "小河很宽，河水下面隐隐约约有什么东西。你看不清。\n",
	]) );
  	set("outdoors", "guiyun");
	setup();
}

void init()
{
	if (!present("old man", this_object()))
		new(__DIR__"npc/qianzhang")->move(this_object());
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "he")
	{
		if (me->query_temp("guiyun_river") )
		{
			message("vision", me->name() + "飞身跃在水面，身形稳凝，河水只及小腿，一步步走过了河。\n", environment(me), ({me}) );
			write("你踩着水底的暗桩，慢慢的走过了小河。\n");
			me->move(__DIR__"riverw");
			message("vision", "只见河面上人影闪动，" + me->name() +  "如飘在水面一般，直走过来。\n", environment(me), ({me}) );
			write("你踩着暗桩慢慢地走过了小河。\n");
			me->delete_temp("guiyun_river");
			return 1;
		}
		else {
			write("你试了试，发觉河面很宽，你绝对跳不过去。\n");
			return 1;
		}
	}
	return 0;
}
