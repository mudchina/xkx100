// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, hitter;
	string *killer, callname;

	if( environment(me)->query("no_fight") )
	{
		environment(me)->delete("no_fight");
//		return notify_fail("这里不准战斗。\n");
	}
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	if( !arg )
		return notify_fail("你想杀谁？\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
	if( obj->query("no_kill") )
		return notify_fail("你真黑，居然下得了这个毒手！\n");
//
	obj->delete("dietime");
	me->delete("killertime");
//
/*
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
*/
	if(obj==me) return notify_fail("用 suicide 指令会比较快:P。\n");
/*
	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");
*/

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
	if( !userp(obj) ) obj->kill_ob(me);
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
最大的不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 
只需单方面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，
通常如果对方是 NPC 的话，他们也会同样对你使用 kill。

    当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，
如果你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用
法术除外)。

其他相关指令: hit, fight

HELP
	);
	return 1;
}
 

