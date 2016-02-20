// fight.c

inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj, old_target;
	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");
	if(me->query("id") != obj->query_temp("bt_ownname") && me->query_temp("bt/working"))
		return notify_fail("你身为捕快，执行公务，可不能杀良冒功！\n");
//  if ( userp(me) && obj->query("owner") && me->query("id") != obj->query("owner"))
//    return notify_fail("不是你要抓的人，凑什么热闹！\n");
//  if( obj->query("jianxi") && !obj->query_temp("asked") )
//    return notify_fail("不是你要抓的人，凑什么热闹！\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是生物。\n");

//	if( obj->is_fighting(me) )
//		return notify_fail("加油！加油！加油！\n");

	if( me->is_fighting(obj) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "已经晕菜了你还打，过分了点吧？\n"); 

	if(obj==me) return notify_fail("打自己？别这么想不开。\n");

	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧。\n");

	notify_fail("此人来头不小，还是少惹为妙。\n");
	if (!userp(obj) && !obj->accept_hit(me)) return 0;

	if( userp(obj) ) {
		message_vision("\n$N对着$n大喝一声：看招！\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对着$n大喝一声：看招！\n\n", me, obj);

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
    这个指令让你直接向一个人物「进招」。这种形式的战斗是即时的，只要
玩家一敲这个命令，战斗就会开始，直到某一方受伤50% 以上为止。这个指令
对那些不喜欢fight的NPC很有用，因为很多时候你的比武要求会被拒绝。
 
    其他相关指令: fight, kill

HELP
    );
    return 1;
}
 
