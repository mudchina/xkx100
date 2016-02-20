// Room: /d/nanshaolin/xjchu.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
int do_pi(string arg);
void create()
{
	set("short", "香积厨");
	set("long", @LONG
一间不大的小屋，正中摆着一口大铁锅，正冒着腾腾的热气，一股
粥香弥漫在室内。几个火工正在忙着加柴，煽火，全寺弟子做完早课都
要喝粥。一位侍粥僧挥舞着沉重的大铁勺，正在吃力的搅动着粥汤。
LONG );
	set("exits", ([
		"south"  : __DIR__"zhaitang",
	]) );
	set("objects", ([
		__DIR__"npc/szseng" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_ao", "ao");
	add_action("do_ao", "熬");
}
int do_ao(string arg)
{
	object ob, me = this_player();
	int costj, costq,times,lvl1,lvl2,exp;

	exp = me->query("combat_exp");
	lvl1 = me->query_skill("hand",1);
	lvl2 = me->query_skill("finger",1);
	if(me->query_temp("job_name")!="熬粥") 
		return notify_fail("厨房可不是闹着玩的地方，你还是走开吧！\n");
	if (me->is_busy())
	{
		write("你现在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在战斗中,无法专心干活！\n");
		return 1;
	}
	if ( !arg || arg != "粥" )
	{   
		message_vision("$N要做什么？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(10);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N手一松，掉进锅里。\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);	
	if (((int)me->query_temp("mark/做")>times) &&
		(present("shizhou seng", environment(me))))
	{
		me->add("potential",(int)(me->query_skill("buddhism",1)/5)+30);
		me->add("combat_exp",(int)(me->query_skill("buddhism",1)/5)+60);
		me->delete_temp("job_name");
		me->delete_temp("mark");
		return notify_fail(RED "侍粥僧说道：多谢你来帮我的忙，还是快回去吧！！！\n"NOR);
	}
	me->start_busy(1);
	message_vision("$N身形一抖，双脚勾住房梁，倒悬在空中，接过铁勺用力搅拌粥锅。\n", me);
	me->add_temp("mark/做",1);
	if ( (int)me->query_skill("hand", 1) < 20 && random(10)>6 )
	{
		if(lvl1 * lvl1 * lvl1 / 10 < exp)
		{
			write(HIM"你在挥舞铁勺中，对手上功夫有些领悟！\n"NOR);
			me->improve_skill("hand", (int)(me->query_skill("buddhism",1) / 5));
		}
		if(lvl2 * lvl2 * lvl2 / 10 < exp)
		{
			write(HIM"你在挥舞铁勺中，对指上功夫有些领悟！\n"NOR);
			me->improve_skill("finger", (int)(me->query_skill("buddhism",1) / 5));
		}
	}
	return 1;
}
