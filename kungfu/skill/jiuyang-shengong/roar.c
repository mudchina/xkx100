// roar.c 佛门狮子吼
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/jiuyang-shengong/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( ((int)me->query("neili") < 600 ) || ((int)me->query("max_neili") < 600 ) || ( (int)me->query_skill("jiuyang-shengong",1) < 100) )
		return notify_fail("你鼓足真气\"喵\"的吼了一声, 结果吓走了几只老鼠。\n");


	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(1);
	message_combatd(
		HIY "$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼！\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||
			ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
			continue;
	if (!userp(target) && !target->accept_hit(me)) continue;
		damage = skill - ((int)ob[i]->query("max_neili") / 20);
		if( damage > 0 )
		{
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
		}
		if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
	}

	return 1;
}

int help(object me)
{
	write(WHT"\n九阳神功之狮子吼："NOR"\n");
	write(@HELP

	使用功效：
		伤害自己周围所有生物的精气

	出手要求：
		九阳神功100级
	        内力600
HELP
	);
	return 1;
}

