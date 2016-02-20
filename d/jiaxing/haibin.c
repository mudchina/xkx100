// Room: /d/jiaxing/haibin.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_jump(string arg);
int do_look(string arg);
int do_use(string arg);

void create()
{
	set("short", "海滨");
	set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地
扑面而来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"west": __DIR__"jiangpan3.c",
	]) );

	set("item_desc", ([
		"tide" : "海潮滚滚而来，似乎欲将天地吞没。\n",
	]) );

	set("coor/x", 1610);
	set("coor/y", -1090);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_use", "use");
	add_action("do_look", "look");
}
/*
void relay_revive(object me)
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_use", "use");
	add_action("do_look", "look");
}
*/
int do_use(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat"))
	{
		me->delete_temp("thd_boat");
		write("你跳上小船，将船划向桃花岛。\n");
		write("海上正是顺风，船借风势，数日内便到达了。\n");
		me->move("/d/taohua/shore");
		return 1;
	}
	return 0;
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (arg == "boat" || arg == "chuan")
		return do_use(arg);

	if (arg != "chao" && arg != "tide")
		return notify_fail("你要往哪里跳？\n");

	if (me->query_dex() < 59)
		return notify_fail("你试图跳进海潮里，却总觉得力不从心。\n");

	if (me->query_skill("dodge") < 80)
		return notify_fail("你试图跳进海潮里，却发现自己的轻功修为还没有达到这么高的境界。\n");
	message_vision("$N耸身一跃，跳进了海潮中！\n", me);
	me->move("/d/taohua/tide");
	return 1;
}

int do_look(string arg)
{
	object me = this_player();

	if (me->query("family/master_name") != "黄药师" || me->query_skill("count", 1) < 50)
	{
		set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地
扑面而来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。
LONG
);
		me->look(arg);
	}
	else
	{
		if (!arg)
		{
			set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地
扑面而来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。远
处有一块巨岩(rock)，后面似乎隐藏着什么。
LONG
);
			me->look(arg);
		}
		else if (arg == "rock" || arg == "yanshi" || arg == "juyan")
		{
			write("一块巨岩，后面隐约露出一条船(boat)的船首来。\n");
			me->set_temp("thd_boat", 1);
			return 1;
		}
		else if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat"))
		{
			write("一条藏着的小船，不精通阴阳八卦是很难发现的。\n");
			return 1;
		}
	}
}