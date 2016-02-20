#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "木房");
	set("long", @LONG
一进屋，你就被巨大的轰鸣声吵住了，这里堆了好多长的木头，准
备要做柴火用的，但是在送去柴房前先得把长木头锯短成一截截的，才
好用斧头劈开。你看见几个人在费力的锯着。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia2" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_pi", "ju");
	add_action("do_pi", "锯");	
}

int do_pi(string arg)
{ 
	object me,weapon;
	int costj, costq,i,c_exp,c_skill;
	i=0;
	me = this_player();

	if(me->query_temp("job_name")!="锯木头") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "juzi")
		return notify_fail("你想用什么来锯木头，用手掰吗？\n");

	if ( !arg || arg != "木头" ) return notify_fail("你要锯什么？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("木头突然断了，$N一没留神，让弹起来的木头砸在了头上！\n",me);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/锯") > 10 + random(10) &&
		present("mufang guanshi", environment(me)))
	{
		me->set_temp("mark/锯完了",1);
		message_vision(RED"木房管事对$N说：干的不错，好了，你可以去张总管那覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N摆正一根木头，慢慢锯了起来。\n", me);
	me->start_busy(3);
	me->add_temp("mark/锯",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("hand",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("hand", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在锯木头的推拉中对基本手法有些体会！\n"NOR);
		me->improve_skill("hand", (int)(me->query("int") / 10));
	}
	return 1;
}
