// wg_mafang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "马房");
	set("long", @LONG
这里是马房，里面臭烘烘的，养了几十匹马，你看过去，马身上都
很脏了，该洗洗了，旁边有个水池，里面有些清水。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia3" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_sao", "clean");
	add_action("do_sao", "sao");	
}
int do_sao(string arg)
{	 
	object me, weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="打扫马房") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");
	if(me->query_temp("mark/扫完了")) 
		 return notify_fail("你已经干完活了，回去覆命(job ok)吧！\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "saozhou")
		return notify_fail("你想用什么来打扫，用手扫吗？\n");

	if ( !arg || arg != "马房" ) return notify_fail("你要打扫什么？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N脚一滑，不小心滑倒在粪堆里，吃了一大口马粪！\n",me);
		me->add("food", 10);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/扫") > 10 + random(10) &&
		present("mafang guanshi", environment(me)))
	{
		me->set_temp("mark/扫完了",1);
		message_vision(RED"马房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR, me);
		return 1;
	}
	message_vision("$N找了个地方开始扫了起来，真够臭的，你不由闭紧了呼吸。\n", me);
	me->start_busy(3);
	me->add_temp("mark/扫",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("club",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("club", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在扫地中对于棍的用法有些体会！\n"NOR);
		me->improve_skill("club", (int)(me->query("int") / 10));
	}
	return 1;
}



