// Room: /d/guiyun/shushang.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
#define DOWN_TREE __DIR__"shulin5"
inherit ROOM;

int do_kill(string arg);
int do_climb(string arg);
string look_down();

void create()
{
	set("short", "树上");
	set("long",@LONG
这里是大树的树顶。往周围看，四面都是树，往下看，枝叶繁盛，
透过树叶的空隙，你能约略看到树下(down)的情景。
LONG
);
/*	set("exits",([
		"down" : __DIR__"shulin5",
	]) );*/
	set("item_desc", ([
		"down" : (: look_down :),
	]) );

	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

void init()
{
	object room, *ob;
	object here = this_object();
	object me = this_player();
	int i;

	if (userp(me) && !wizardp(me))
	{
		if (!room = find_object(DOWN_TREE)) 
			room = load_object(DOWN_TREE);
		ob = all_inventory(here);
		for (i = 0; i < sizeof(ob); i++)
		{
			if (userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me)
			{
				write("没想到" + ob[i]->name() + "也藏在树上！\n");
				message_vision("因为树枝无法承受两个人的重量，“啪”地一声折断了！\n", me);
				me->move(DOWN_TREE, 1);
				ob[i]->move(DOWN_TREE, 1);
				message_vision("只听“唏哩哗啦”一阵乱响，$N和$n从树上掉了下来。\n", me, ob[i]);
				message_vision("$N大怒，冲$n嚷道：“" + RANK_D->query_self_rude(ob[i]) + "在上面呆的好好的，你个" + RANK_D->query_rude(me) + "干嘛来捣乱？”\n", ob[i], me);
				message_vision("$N也不服气地反驳道：“你躲在上面，一看就知道不是好人！”\n", me);
				message_vision("两人越说越僵，终于拳脚相加！\n", me);
				me->fight_ob(ob[i]);
				ob[i]->fight_ob(me);
				return;
			}
		}
	}
	"/cmds/std/look"->look_room(me, here);
	add_action("do_kill", "kill");
	add_action("do_kill", "sha");
	add_action("do_kill", "touxi");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

string look_down()
{
	object down;

	if (!down = find_object(DOWN_TREE))
		down = load_object(DOWN_TREE);
	"/cmds/std/look"->look_room(this_player(), down);
	return "";
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg != "down")
		return notify_fail("你要爬到哪里？\n");
	message_vision("$N顺着树干爬了下去。\n", me);
	me->move(DOWN_TREE);
	message("vision", me->name() + "从树上爬了下来。\n", DOWN_TREE, ({me}));
	return 1;
}

int do_kill(string arg)
{
	object room, ob;
	object me = this_player();
//	int temp;
	string callname;

	if (me->is_busy())
		return notify_fail("你正忙着哪！\n");

	if (!arg || !(room = find_object(DOWN_TREE)))
		return notify_fail("你要偷袭谁？\n");

	if (!(ob = present(arg, room)))
		return notify_fail("你要偷袭谁？\n");

	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");

	if (!userp(ob)) {
		write("偷袭NPC？你想作弊啊！\n");
		return 1;
	}

	if (wiz_level(me) < wiz_level(ob))
		return notify_fail("你不能攻击巫师等级比你高的对手。\n");

	message("vision", me->name() + "一跃而下，向树下的" + ob->name() + "发起了偷袭！\n", this_object(), ({me}));
	me->move(room, 1);
//	temp = me->query("dex") / 10 + 1;
	if (random(4))
	{
		message_vision("$N从树上急跃而下，和身扑向$n，$n错愕间竟然惊呆了！\n", me, ob);
		ob->start_busy(3);
	}
	else {
		message_vision("$N从树上急跃而下，看来是想偷袭$n，却在落地时不小心跌了一跤，$n趁机立刻发动攻击！\n", me, ob);
		me->start_busy(5);
	}
        if ( userp(me) && userp(ob) && ob->query("combat_exp") < 1000 )
                return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n");
	callname = RANK_D->query_rude(ob);

	message_vision("\n$N对着$n喝道：「" + callname + "！今日不是你死就是我活！」\n\n", me, ob);

	me->delete_temp("guarding");
	ob->set_temp("guarding", 1);
	me->kill_ob(ob);
	if( !userp(ob) )
		ob->kill_ob(me);
	else {
		ob->fight_ob(me);
		if (userp(me))
			tell_object(ob, HIR "如果你要和" + me->name()
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	}
	return 1;
}
