// wg_caidi2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
这里是块菜地，菜地旁有几口大缸，里面盛满了水，可是菜地看起
来都干裂了，几棵菜蔫蔫的长着，看样子是缺水太多了。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan3",
	]));
	set("objects", ([
		__DIR__"npc/wg_guanjia6" : 1,
		__DIR__"npc/wg_kunlundizi" : 1,
	]));
	set("outdoors", "wuguan");
 	set("coor/x", 81);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "浇");	 
}
int do_jiao(string arg)
{
	object me, weapon;
	int costj, costq;
	me = this_player();

	if(me->query_temp("job_name")!="浇菜地") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干活！\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "piao")
		return notify_fail("你想用什么来舀水浇，用手吗？\n");
	if ( !arg || arg != "水" ) return notify_fail("你要浇什么？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N弯腰到大缸里舀水，结果一失足栽进了缸里！\n",me);
		me->set("water", 350);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/浇") > 10+(random(5)) &&
		present("caiyuan guanshi", environment(me)))
	{
		me->set_temp("mark/浇完了",1);
		message_vision(RED"菜园管事对$N说：干的不错，好了，你可以回去覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N用瓢从缸里舀起水，在菜地里浇起水来。 \n", me);
	me->start_busy(3);
	me->add_temp("mark/浇",1);
	return 1;
}

