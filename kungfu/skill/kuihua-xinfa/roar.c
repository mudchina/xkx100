// roar.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;


  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/kuihua-xinfa/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( ((int)me->query("neili") < 500 ) || ((int)me->query("max_neili") < 500 ) || ( (int)me->query_skill("kuihua-xinfa",1) < 100) )
		return notify_fail("你鼓足真气＂喵＂的吼了一声, 结果吓走了几只老鼠。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	skill = me->query_skill("force");

	me->add("neili", -200);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_combatd(
		HIY"$N深深地吸一囗气，真力迸发，运起葵花心法，发出一声尖利的长啸：“"HIR"日出东方，唯我不败！"HIY"”\n" NOR, me);

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
			tell_object(ob[i], "你觉得一阵天昏地暗，耳朵如针扎一般疼痛欲裂！\n");
		}

		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n葵花心法之东方不败："NOR"\n");
	write(@HELP

	使用功效：
		伤害自己周围的所有生物的精气

	出手要求：
		葵花心法100级
	        内力500
HELP
	);
	return 1;
}

