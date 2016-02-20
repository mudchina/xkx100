// anqi_poison.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( duration < 1 ) return 0;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"忽然一阵剧痛袭来，你中暗器的伤口恶化了！\n"NOR );
		message("vision", me->name() + "的脸上突然露出痛苦神情，牙关咬得格格直响。\n", environment(me), me);
	}
	me->receive_wound("qi",15 + random(10),"暗器毒发而死");
	me->receive_wound("jing", 10,"暗器毒发而死");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("anqi_poison", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
