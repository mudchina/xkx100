// kill.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object obj, hitter;
	string *killer, callname;
	seteuid(getuid());
	if( environment(me)->query("no_ansuan") )
		return notify_fail("这里禁止战斗。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	if( !arg )
		return notify_fail("你想杀谁？\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
//	if (userp(me)&& obj->query("owner") && me->query("id") != obj->query("owner"))
//    return notify_fail("不是你要抓的人，凑什么热闹！\n");
//增加一个yinshi任务的限制条件		
	if( obj->query("no_kill") ||( obj->query("yinshi") && obj->query("ask_time")<=2) )
		return notify_fail("你真黑，居然下得了这个毒手！\n");
	
       if( objectp(hitter = obj->query_temp("last_damage_from")))
	{       
         	if( hitter->query("id") != me->query("id"))
		{
			if ((obj->query("name") ==
				me->query("family_quest/betrayer/name") ||
			obj->query("name") ==
				me->query("family_quest/thief/name") ||
			obj->query("name") ==
				me->query("quest/shan/quest") ||
			obj->query("name") ==
				me->query("quest/helian/quest")) &&
			(!living(obj) ||obj->query_temp("noliving") ||
				obj->query("qi") < obj->query("max_qi")/2) )
				return notify_fail("不是你打伤的，你不能杀了来完成任务。\n");
			else
				message_vision("\n$N对着$n得意地笑道：「"+obj->query("name")+"！今日活该你倒霉，欺侮你身上有伤，这个便宜我就不客气了！」\n\n", me, obj);
		}
	}

	if(me->query("id") != obj->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("你身为捕快，执行公务，可不能杀良冒功！\n");
	if(obj==me) return notify_fail("用 suicide 指令会比较快:P。\n");
	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");

//限制大米pk  
  if( userp(obj) && obj->query_temp("noliving") && 
      obj->query("id") != me->query("last_die_by_id") &&
     (!objectp(hitter) || hitter->query("id")!= me->query("id")) &&
     me->query("combat_exp",1)<1000000)
          return notify_fail("想占这样的便宜，多练练再来吧!\n");
	if (userp(me) && userp(obj) && me->query("combat_exp")<100000 &&
	       obj->query("id") != me->query("last_die_by_id") &&
      obj->query("combat_exp")>1000000)
			return notify_fail("就凭你这点实力，还是少惹点事吧。")  ;       

	notify_fail("此人来头不小，还是少惹为妙。\n");
	if (!userp(obj) && !obj->accept_kill(me)) return 0;		

	callname = RANK_D->query_rude(obj);
	if (random(3) > 1)
		message_vision("\n$N对着$n喝道：「" + callname + "！今日不是你死就是我活！」\n\n", me, obj);
	else
		message_vision("\n$N对着$n喝道：「" + callname + "！明年今日就是你的忌日！」\n\n", me, obj);

	me->delete("env/combatd");
	obj->delete("env/combatd");

	me->kill_ob(obj);
	if ( userp(obj))
		write_file("/log/static/ATTEMP_KILL", sprintf("%s   试图杀死   %s on %s\n", me->name(1),obj->name(1), ctime(time()) ));
// Look for PKS 
	if( !userp(obj) ) 
	{
		if (!obj->query("owner") &&
		stringp(me->query("family/family_name")) &&
		(string)obj->query("family/family_name") == (string)me->query("family/family_name"))
		{
			if (living(obj) && !obj->query_temp("noliving"))
			message_vision(HIC"$n厉声对$N道：你我本同门，却为何想相害于我！\n"NOR,me,obj);
			me->delete("family/fealty");
			"/cmds/skill/expell"->main(obj,me->query("id"));
		}
		obj->kill_ob(me);
	}
	else
	{
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	}

	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : kill <人物>
 
    这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 
最大的不同在于双方将会真刀实枪地打斗，也就是说，会真的受伤。由于 kill 
只需单方面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，
通常如果对方是 NPC 的话，他们也会同样对你使用 kill。

    当有人对你使用 kill 指令时会出现红色的字样警告你，对于一个玩家而言，
如果你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死（使用
毒术除外）。

其他相关指令: hit, fight

HELP
	);
	return 1;
}
 

