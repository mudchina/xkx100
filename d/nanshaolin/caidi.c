// Room: /d/nanshaolin/caidi.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

int do_pi(string arg);

void create()
{
	set("short", "菜地");
	set("long", @LONG
一块绿油油的菜地，种了不少蔬菜，正在茁壮成长，寺内不令肉食，
青菜就是僧人们就餐最好的食物了。菜地边上是一个粪池，放着两只粪桶。
LONG );
	set("exits", ([
		"east" : __DIR__"cyzi-1",
	]) );
	set("no_fight",1);
	set("outdoors","nanshaolin");
	set("objects", ([
		CLASS_D("nanshaolin")+"/fanghui" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "浇");
}

int do_jiao(string arg)
{   
	object me = this_player();
	int costj, costq,times;

	if(me->query_temp("job_name")!="菜地种菜") 
		return notify_fail("谁让你来的，滚！\n");
	if (me->is_busy())
	{
		write("你现在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在战斗中，无法专心干活！\n");
		return 1;
	}
	if ( !arg || arg != "粪" )
	{
		message_vision("$N要浇什么？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N脚下一滑，掉进粪坑里\n",me);
		me->unconcious();
		return 1;
	}
	me->start_busy(1);
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	if (((int)me->query_temp("mark/浇") > times) &&
		(present("fang hui", environment(me))))
	{
		me->set_temp("mark/浇完",1);
		message_vision(RED "方回对$N骂道：他妈的，这次就饶了你下次再教训你，滚回去寺监那里复命吧(zhongcai ok)！！\n"NOR, me);
		return 1;
	}  
	message_vision("$N挑起粪桶运劲将桶中的臭粪均匀的洒于每株菜蔬的根部，真臭呀。\n", me);
	me->add_temp("mark/浇",1);
	if ( (int)me->query_skill("staff", 1) < 20 && random(10)>6 )
	{
		write(HIM"你在浇粪中对于杖的用法有些体会。\n"NOR);
		me->improve_skill("staff", (int)(me->query_skill("buddhism",1) / 5));
	}
	return 1;
}
