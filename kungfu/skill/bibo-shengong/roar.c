// roar.c 碧海生潮曲
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/bibo-shengong/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( ((int)me->query("neili") < 300 ) || ((int)me->query("max_neili") < 300 ) || ( (int)me->query_skill("bibo-shengong",1) < 100) )
		return notify_fail("你鼓足真气＂喵＂的吼了一声, 结果吓走了几只老鼠。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	skill = me->query_skill("force");


	me->add("neili", -100);
	me->receive_damage("qi", 10);
	me->start_busy(5);
	message_combatd(
	HIY "$N气凝丹田，运集全身内力吟出一曲「碧海生潮」！\n" NOR, me);

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
			tell_object(ob[i], "你只觉得眼前一片模糊，朦胧中似乎无数排山巨浪向你打来......\n");
		}
		if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
	}
	return 1;
}
int help(object me)
{
	write(WHT"\n碧波神功之碧海生潮曲："NOR"\n");
	write(@HELP

	使用功效：
                碧海生潮曲 ，灌注内力吟出曲子，使敌人心烦意
                乱，不战自溃。伤害自己周围的所有生物的精气

	出手要求：
		碧波神功100级
		内力300
HELP
	);
	return 1;
}

