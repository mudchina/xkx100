// vote command..
// Modified by Marz, 04/18/96
inherit F_CLEAN_UP;

#include <net/dns.h>
#include <ansi.h>



// int valid_voters(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;

	if (((int)me->query("age")<16) && !wizardp(me))
	{
		return notify_fail("民主不是儿戏！小孩子一边玩去！\n");
	}
	if ((int)me->query("xkx_jail"))
	{
		return notify_fail("你还是老老实实做完牢再说吧！\n");
	}
	if ((int)me->query("vote/deprived"))
	{
		return notify_fail("你想起当初玩弄民主、被剥夺投票权的事，追悔莫及。\n");
	}
	if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2)
	{
		return notify_fail("这神圣的一票，要想清楚了才能投。\n");
	}
	victim = find_player(victim_name);
	if (!victim) victim = LOGIN_D->find_body(victim_name);
	if (!victim || !me->visible(victim) || victim->query("no_look_wiz"))
		return notify_fail("你要投谁的票？\n");
	if (wizardp(victim) && !victim->query("no_look_wiz")) return notify_fail("你要投巫师的票？\n");
		
	if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
		|| file_size(file + ".c") <= 0 )
			return notify_fail("你要投票干什么？\n");
	
	if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
	if ((int)file_ob->vote(me, victim) <= 0)
	{
		if ((int)me->query("vote/abuse")> 50)
		{
			write( HIG "你因为胡乱投票，投票权被剥夺了！\n" NOR);

//			me->set("xkx_jail", 1);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
// 			me->move("/d/city/jail");
		}	
		return 0;
	};
	
	return 1;
}


string *valid_voters(object me,object victim)
{
	object *list;
	int d = 0;
	int j;
	string *adds=({});
	string ip;

	list = users();
	j = sizeof(list);
	while( j-- )
	{
		// Skip those users in login limbo.
		if( !environment(list[j]) ) continue;
		if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		ip = query_ip_name(list[j]);
		if (member_array(ip,adds)==-1)
		 adds += ({ip});
	}
	return adds;
}


int help(object me)
{
	write(@HELP
指令格式 : vote <动议> <某人> 

    此命令提议对某人采取行动，由大家投票决定。可是如果五分钟内没有
人附议，投票会自动取消。当前可以有如下<动议>：

chblk:   关闭某人交谈频道，需三票以上的简单多数同意。
unchblk: 打开某人交谈频道，需三票以上的三分之一票数同意。
jail:    将某人送进监狱，需三票以上的简单多数同意。
unjail:  将某人放出监狱，需三票以上的简单多数同意。

HELP
	);
	return 1;
}

/**
future motion (not implemented yet):
eject: 驱逐某人，需三票以上的简单多数同意。
robot: 怀疑某人是机器人，如果有五人附议，则由系统审训被怀疑者。
jail: 将某人送进监狱，需三票以上的简单多数同意。
**/
