// wg_wuchang2.c

#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
	set("short", "南练武场");
	set("long", @LONG
这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫，场子的东角有一个沙
坑(shakeng)。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wuchang4",
		"north" : __DIR__"wg_lang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_mjbz" : 1,
	]));
	set("item_desc", ([
		"shakeng" : "这是一个大沙坑，几个小伙子在沙坑中上下跳(tiao)跃着。\n",
	]));
	set("outdoors", "wuguan");
	setup();
}

void init()
{
	add_action("do_tiao", "tiao");
	
}
int do_tiao(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill;

	me = this_player();
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心练功！\n");
	if ( !living(me)) return notify_fail("你发疯了？\n");

	if ( !arg || arg != "shakeng" )
		return notify_fail("你在场子里蹦蹦跳跳了半天，别人还以为你发神经！\n");
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N奋力一跳，结果脚一滑，在沙坑里摔了个狗吃屎！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);
	message_vision("$N气从丹田提升，在大沙坑中奋力跳上跳下。\n", me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	if ( (int)me->query("combat_exp") < 50000)
	{
		if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
			(int)me->query_skill("dodge", 1) < 30 && random(10)>6 )
		{
			write(HIM"你不断的在沙坑中跳着，自己的基本轻功有了提高！\n"NOR);
			me->improve_skill("dodge", (int)(me->query("int") / 4));
		}
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("dex") / 10)));
	}
	return 1;
}
