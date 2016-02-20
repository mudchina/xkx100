// Room: /d/gaochang/mishi2.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit ROOM;
int do_study(string arg);

void create()
{
	set("short", "地下室");
	set("long", @LONG
这里是宫殿底下的地下密室。密室虽小，却也是五脏俱全，石桌石
椅，石几石床，连室内放的几件器皿，也都是石制的。看来似乎很久以
前有人在这里住过。正中的石桌(table) 上平放着一块薄薄的石板，上
面好象刻着些什么。
LONG
	);
	set("had_sword", 1);
	set("exits", ([
		"south" : __DIR__"mishi",
	]) );
	set("item_desc", ([
		"table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。
桌上放着一口黑黝黝毫不起眼的重剑(zhongjian)。\n",
		"zhongjian": "这是一口玄铁煅制的玄铁宝剑，正连鞘隔在石桌上。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36510);
	set("coor/y", 10110);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_take", "take");
	add_action("do_take", "qu");
	add_action("do_take", "jian");
	add_action("do_take", "pick");
	add_action("do_zuan","zuan");
	add_action("do_zuan","enter");
}

int do_study(string arg)
{
	object me = this_player();

	if ( !arg || ( arg != "table" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if((int)me->query("jing") < 30)
		return notify_fail("你现在精神无法集中！\n");

	me->receive_damage("jing", 10);

	message_vision("$N正专心研读石桌上的古怪图形。\n", me);
	if ( (int)me->query_skill("literate", 1) < 150)
	{
		me->improve_skill("literate", (int)(me->query("int")/3));
		write("你对着石桌琢磨了一回儿，似乎对读书识字有点心得。\n");
		me->set_temp("stone_learned",1);
	}
	if ( !me->query_temp("stone_learned") )
	{
		write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}

int do_take(string arg)
{
	object sword, me=this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="zhongjian" )
	{
		if (!query("had_sword") || uptime() < 300)
			message_vision("$N伸手去取剑，才发现只剩剑鞘了，玄铁剑早就被别人取走了...。\n", me);
		else
		{
			if (me->query_str() < 30)
				return notify_fail("那玩意儿太重，你费了半天劲还是拿不起来。\n");
			set("had_sword", 0);
			message_vision("$N轻轻的从石桌上捡起一口剑来。\n", me);
			sword = new(WEAPON_DIR"treasure/xuantie-sword");
			if (sword->violate_unique())
			{
				destruct( sword );
				return notify_fail("你伸手去取剑，才发现只剩剑鞘了，玄铁剑早就被别人取走了...。\n");
			} 
			sword->move(me);
message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"得了一口玄铁剑啦。\n"NOR, users());
			return 1;
		}
		return 1;
	}
	return 0;
}
int do_zuan(string arg)
{
	object me=this_player();
	
	if (!arg || arg!="table")
		return notify_fail("你要钻到那里去?\n");
	if (me->query_str()>30)
		return notify_fail("你的身形太大，钻不到桌子底下。\n");
	message_vision("$N哧溜一下钻到了桌子下面去。\n",me);
	me->move("d/gaochang/mishi3");
	message("vision",me->query("name")+"从外面钻了进来。\n",environment(me),({me}));
	return 1;
}