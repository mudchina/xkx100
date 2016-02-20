// wg_chaifang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这间屋里叮叮哐哐的，你仔细一看，几个人在劈柴火，屋子特别大，
屋子一边堆满了已经锯短的木头，但是另一边劈好的柴火却没有多少。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia1" : 1,
		__DIR__"npc/wg_qingchengdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_pi", "pi");
	add_action("do_pi", "劈");	
}
int do_pi(string arg)
{	 
	object me,weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="劈柴") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "chaidao")
		return notify_fail("你想用什么来劈柴，用手吗？\n");

	if ( !arg || arg != "柴" )
		return notify_fail("你要劈什么？劈人吗？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N手一歪，不小心劈在自己的腿上\n",me);
		me->receive_wound("qi", 20);
		me->set_temp("last_damage_from", "不小心被自己劈");
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);	   

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/劈") > 10 + random(10) &&
		present("chaifang guanshi", environment(me)))
	{
		me->set_temp("mark/劈完了",1);
		message_vision(RED"柴房管事对$N说：干的不错，好了，你可以回去覆命(job ok)了。"NOR, me);
		return 1;
	}  
	message_vision("$N摆正一块木头，一刀劈了下去，“哐”的一声，木头被劈为两片。\n", me);
	me->start_busy(3);
	me->add_temp("mark/劈",1);

	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("blade",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("blade", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在劈柴中对于刀的用法有些体会！\n"NOR);
		me->improve_skill("blade", (int)(me->query("str") / 10));
	}
	return 1;
}

