// roar.c 黯然销魂吟
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/yunv-xinfa/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( ((int)me->query("neili") < 150 ) || ((int)me->query("max_neili") < 150 ) || ( (int)me->query_skill("yunv-xinfa",1) < 100) )
		return notify_fail("你长叹一声，大家吓了一跳。\n");

	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(3);
	message_combatd(MAG"$N右手抚胸，低声长吟出一曲「黯然销魂」。\n"NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||	ob[i]==me )	continue;

		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

		if (!userp(ob[i]) && !ob[i]->accept_hit(me)) continue;

		damage = skill - ((int)ob[i]->query("max_neili") / 10);

		if( damage > 0 )
		{
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "你忽然觉得一阵寒意扑面而来，心神朦胧中漂移不定。\n");
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n玉女心法之黯然销魂吟："NOR"\n");
	write(@HELP

	使用功效：
		伤害自己周围的所有生物的精气

	出手要求：
		玉女心法100级
	        内力150
HELP
	);
	return 1;
}

