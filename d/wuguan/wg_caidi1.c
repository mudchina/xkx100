// wg_caidi1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
这里是块菜地，由于长期得不到良好的照顾，菜地里杂草丛生，种
的菜都长势不好，蔫蔫的，地都荒了。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan3",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia5" : 1,
		__DIR__"npc/wg_nsldizi":1,
	]));
	set("outdoors", "wuguan");
 	setup();
}

void init()
{
	add_action("do_chu", "chu");
	add_action("do_chu", "锄");	
}
int do_chu(string arg)
{
	object me,weapon;
	int costj, costq,c_exp,c_skill;
	me = this_player();

	if(me->query_temp("job_name")!="锄草") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干活！\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "chutou")
		return notify_fail("你想用什么来锄草，用手吗？\n");
	if ( !arg || arg != "草" ) return notify_fail("你要锄什么？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N手一松，不小心锄在了自己的脚上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/锄") > 10+(random(10)) &&
		present("caiyuan guanshi", environment(me)))
	{
		me->set_temp("mark/锄完了",1);
		message_vision(RED"菜园管事对$N说：干的不错，好了，你可以回去覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N挥起锄头，对着地上的杂草锄了起来。\n", me);
	me->start_busy(3);
	me->add_temp("mark/锄",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("staff",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("staff", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在锄草中对于杖的用法有些体会！\n"NOR);
		me->improve_skill("staff", (int)(me->query("int") / 10));
	}
	return 1;
}

