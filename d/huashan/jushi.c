// jushi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "居室");
	set("long", @LONG
这里是岳夫人的寝室，岳夫人在江湖上人称「淑女剑」，为人极有
骨气，她的居室却相当朴素，床椅之外，靠碧纱窗(window)处有个梳妆
台(tai)， 墙上挂着一口宝剑(sword)， 蛇皮吞口，看来很是锋利。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"changlang",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/yue-wife" :1,
	]));
	set("item_desc", ([
		"window" : "窗外就是天声峡了。往外望去，云深谷幽令人目眩。\n",
		"sword"  : "这是上次前往福建时带回的龙泉剑。\n",
		"tai"    : "这是一张红漆梳妆台，半开的抽屉斜插着几朵鲜花。\n"
	]));
	set("coor/x", -880);
	set("coor/y", 230);
	set("coor/z", 120);
	setup();
}
void init()
{
	add_action("do_move", "push");
	add_action("do_move", "move");
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_move(string arg)
{
	object paper, me=this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="tai" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail("岳夫人喝道：这位" + RANK_D->query_respect(me) + "，你不能随便翻人家东西。\n");
			return 1;
		}
		if (!query("had_yunu"))
		{
			message_vision("$N轻轻的拉开抽屉，发现里面有一本书...。\n", me);
			paper = new("/clone/book/yunu_book");
			paper->move(__FILE__);
			message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到玉女剑谱啦。\n"NOR, users());
			set("had_yunu", 1);
			return 1;
		}
		message_vision("$N轻轻的拉开抽屉，可是里面啥都没有...。\n", me);
		return 1;
	}
	return 0;
}

int do_pick(string arg)
{
	object sword, me=this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="sword" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail("岳夫人喝道：这位" + RANK_D->query_respect(me) + "，你不能随便翻人家东西。\n");
			return 1;
		}
		if (!query("had_sword"))
		{
			sword = new(WEAPON_DIR"treasure/longquan-jian");
			if ( sword->violate_unique() ) destruct( sword );
			else
			{
				message_vision("$N轻轻的摘下宝剑，哈哈，真开心...。\n", me);
				sword->move(me);
				message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"抢了一口龙泉剑啦。\n"NOR, users());
				set("had_sword", 1);
				return 1;
			}
		}
		message_vision("$N伸手去摘宝剑，才发现只剩剑鞘了，宝剑早就被别人取走了...。\n", me);
		return 1;
	}
	return 0;
}
