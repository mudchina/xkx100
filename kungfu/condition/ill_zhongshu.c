// ill_zhongshu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "头重脚轻，脑门发热，看来是中暑了。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"你觉得头重脚轻，脑门发热，看来是中暑了。\n"NOR );
		message("vision", me->name() + "只觉得胸臆之间一阵翻腾，头重脚轻，抬不起头来，脑门发热，看来是中暑了。\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"积劳成疾累死了");
	me->receive_damage("qi", 1,"积劳成疾累死了");
	me->apply_condition("ill_zhongshu", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}
