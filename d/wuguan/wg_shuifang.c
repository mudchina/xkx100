// wg_shuifang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "水房");
	set("long", @LONG
一进屋，你看见屋内放着几口大缸，好象是装水用的，不过缸似乎
都是空的，这里没有一个人，估计仆人都跑了。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia4" : 1,
	]));		
	setup();
}
void init()
{
	add_action("do_tiao", "tiao");		
}
int do_tiao(string arg)
{	
	object me, weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="挑水") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");
	if(me->query_temp("mark/挑完了")) 
		return notify_fail("你已经干完活了，回去覆命(job ok)吧！\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "shuitong")
		return notify_fail("你想用什么来挑水，用手挑吗？\n");

	if ( !arg || arg != "水" ) return notify_fail("你要挑什么？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N弯腰向大缸里倒水，结果一失足栽进了缸里！\n",me);
		me->set("water", 350);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/挑") > 10 + random(10) &&
		present("shuifang guanshi", environment(me)))
	{
		me->set_temp("mark/挑完了",1);
		message_vision(RED"水房管事对$N说：干的不错，好了，你可以回去覆命(job ok)了。\n"NOR, me);
		return 1;
	}
	message_vision("$N用水桶从井里挑起水，再倒到水缸里。\n", me);
	me->start_busy(3);
	me->add_temp("mark/挑",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("hammer",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("hammer", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在挑水中对于基本锤法有些体会！\n"NOR);
		me->improve_skill("hammer", (int)(me->query("int") / 10));
	}
	return 1;
}




