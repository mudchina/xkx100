// steal.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	string what, who;
	object ob, victim, thisroom;

	mapping myfam, vtfam;
	int sp, dp;
        thisroom = environment(me);

//	if(1==1)
//	return notify_fail("现在不许行窃。\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("这里禁止行窃。\n");

	if( environment(me)->query("no_steal"))
		return notify_fail("这里禁止行窃。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
		return notify_fail("指令格式：steal <物品> from <人物>\n");

 //       if(arg=="corpse"||arg=="skeleton")
 //               return notify_fail("偷什么偷，直接从尸体里拿就是了！\n");
	victim = present(who, environment(me));
	if( !victim || victim==me)
		return notify_fail("你想行窃的对象不在这里。\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能偷巫师身上的东西。\n");
		
	if (userp(me) && victim->query("owner") && me->query("id") != victim->query("owner"))
			return notify_fail("不许对此人行窃。\n");					

	if( victim->query("no_steal"))
		return notify_fail("不许对此人行窃。\n");

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail("这种情况你还用得着偷吗？\n"); 
	if(me->query("id") != victim->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("你身为捕快，执行公务，岂能知法犯法！\n");
	notify_fail("此人来头不小，还是少惹为妙。\n");
	if (!userp(victim) && !victim->accept_hit(me)) return 0;

	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什么值钱的东西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail(victim->name() + "好象不是活物，你直接取(get)就是了。\n"); 

	sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
		- (int)me->query("thief") * 20;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
		sp = (int)me->query_skill("stealing")*10+(int)me->query("kar")*5
			- (int)me->query("thief") * 20;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() )
	{
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("你不动声色地慢慢靠近"+victim->name()+"，等待机会下手 ...\n\n");

        thisroom->set_temp("no_sleep",1);
        me->start_busy(2);
	me->set_temp("stealing", 1);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp,int dp)
{
	mapping myfam, vtfam;
	int steal_level;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}

	if( !living(victim) || victim->query_temp("noliving") ||
		(random(sp+dp) > dp) )
	{
		if( !present(ob, victim) )
		{
			tell_object(me,"你摸了半天没发现自己要偷的东西，看来对方已经把东西转移了！\n");
			return;
		}
		if( ob->query("no_steal") )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是你突然作贼心虚，居然不敢下手，真是可惜了。\n");
			return;
		}
		if( ob->query_temp("is_rided_by") )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是你发现那是人家的坐骑，真是可惜了。\n");
			return;
		}
		if( !ob->move(me) )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是对你而言太重了，不得不放弃。\n");
			return;
		}

		tell_object(me, HIW "得手了！\n\n" NOR);
		tell_object(me, "你成功地偷到一"+ob->query("unit")+ob->name() + "！\n");
		steal_level = (int)me->query_skill("stealing",1);

		if( living(victim) && !victim->query_temp("noliving") )
		{
			if ((int)me->query("combat_exp") >
				(steal_level*steal_level*steal_level/10) )
			{
				me->improve_skill("stealing", random(me->query("int")));
			}
			else
			{
				tell_object(me," 就这点经验也要去偷？ \n");
			}
			if ( (myfam = me->query("family")) &&
				myfam["family_name"] == "丐帮" )
			{
//add by Java. Nov 16.1997
				me->start_busy(2);
				me->add("thief", 1);
				me->receive_damage("jing", 10);
				me->receive_wound("jing", 4);
				me->add("combat_exp",1);
				if( random(5) == 1) me->add("potential",1);
				
			}
		}

		if( random(sp) < dp/2 )
			message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"
			+ victim->name() + "身上偷走了一" + ob->query("unit")
			+ ob->name()+"！\n", environment(me),({ me, victim }));
	}
	else
	{
		if( random(sp) > dp/2 )
		{
			tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n还好，没有被发现。\n");
			return;
		}
		tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
		message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n" + "$N喝道：「干什么！」\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);

		me->delete("env/combatd");
		victim->delete("env/combatd");

		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(3);
		me->add("thief", 1);
		me->receive_damage("jing", 10);
		me->receive_wound("jing", 4);
	}
environment(me)->delete_temp("no_sleep");
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

    这个指令让你有机会偷到他人身上的东西。成功了，当然你就能获
得该样物品。可是，马有失蹄，人总有失风的时候，当你失败时当然就
得付出代价，至于是什么代价......靠你自己去发掘罗。
HELP
	);
	return 1;
}

