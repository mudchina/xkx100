// Room: /d/nanshaolin/fzjs2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写着大大
的一个『禅』字。一位慈眉善目的灰衣老僧正端坐于蒲团上打坐。
LONG );
	set("exits", ([
		 "south" : __DIR__"fzjs1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/tianhong" : 1,
	]));
	set("coor/x", 1780);
	set("coor/y", -6140);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_massage", "massage");
	add_action("do_massage", "按摩");
}
int do_massage(string arg)
{      
	object me = this_player();
	int costj, costq, times;

	if(me->query_temp("job_name")!="服侍方丈") 
		return notify_fail("捣什么乱，把这当按摩院啊？！\n");
	if(!present("tianhong", environment(me)))
		return notify_fail("方丈不在，你搞什么搞嘛！！\n");
	if(query("massage") > 10)
		return notify_fail("天虹方丈说道：去睡吧。明天再来服侍。\n");
	if(me->is_busy())
	{
		write("你现在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在战斗中，无法专心干活！\n");
		return 1;
	}
	if ( !arg || arg != "方丈" )
	{   
		message_vision("$N要给谁按摩？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if((int)me->query("jing")<costj || (int)me->query("qi")<costq)
	{
		message_vision("$N手忙脚乱，脚下一软，摔倒在地。\n",me);
		me->unconcious();
		return 1;
	}
	if(!wizardp(me))
	{
		me->receive_damage("jing", costj);
		me->receive_damage("qi", costq);	
		me->start_busy(1);
	}
	if (((int)me->query_temp("mark/按摩")>times) &&
		(present("tianhong", environment(me))))
	{
		me->set_temp("mark/按摩完", 1);
		add("massage", 1);
		return notify_fail(RED "天虹方丈说道：谢谢你来服侍我，快回去休息吧(massage ok)！\n"NOR);
	}  
	message_vision("$N盘膝坐下，用力按摩方丈全身，把天虹方丈弄的爽爽的。\n", me);
	me->add_temp("mark/按摩",1);
	if ( (int)me->query_skill("buddhism", 1) < 50 && random(10)>6 )
	{
		write(HIM"你静坐倾听方丈诵经，对禅宗心法有些领悟。\n"NOR);
		me->improve_skill("buddhism", (me->query_skill("force",1) / 5));
	}
	return 1;
}
