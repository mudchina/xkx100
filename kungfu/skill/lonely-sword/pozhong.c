// pozhong.c 破众

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{

	object *ob,weapon,target;
	int i, skill, damage,flag=0;
	string msg;

	if(me->query("family/master_id") != "feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("你不是风清扬嫡传弟子，不能使用绝招！\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/pozhong") &&
  !me->query("can_perform/lonely-sword/pozhong") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("独孤九剑攻招只能对战斗中的对手使用。\n");
	skill = me->query_skill("lonely-sword",1);
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( skill < 80)
		return notify_fail("你的独孤九剑等级不够，不能「破众」！\n");
	if( me->query("max_neili") < 800 )
		return notify_fail("你的内力修为不够，无法运用「破众」！\n");
	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够，无法运用「破众」！\n");
//	if( environment(me)->query("no_fight") )
//		return notify_fail("在这里不能攻击他人。\n");
	me->add("neili", -250);
	me->receive_damage("qi", 10);
	me->start_busy(1);
	message_combatd(HIC"$N清啸一声，手中长剑轻转，剑势变幻，化出光芒千道，剑尖向四面八方疾速点出！\n"NOR,me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) ||ob[i]->query_temp("noliving")
		     || ob[i]==me ) continue;
		if( !ob[i]->is_fighting(me))
		          continue;  
		damage=skill-((int)ob[i]->query_skill("dodge",1)/2);
//		if ( damage <= 0 ) continue;
		if( damage>0 )
		{
			ob[i]->receive_damage("jing", damage);
			ob[i]->receive_damage("qi", damage*2);
			ob[i]->receive_wound("qi", damage);
			switch (random(5))
			{
				case 1:
message_combatd(HIC"$N手中剑尖破空，正刺中$n的咽喉！\n"NOR,me,ob[i]);
					break;
				case 2:
message_combatd(HIC"只见$N右手剑尖一点，$n胸口鲜血喷涌而出！\n"NOR,me,ob[i]);
					break;
				case 3:
message_combatd(HIC"$N手中剑光闪处，在$n手腕就是一个透明窟窿！\n"NOR,me,ob[i]);
					break;
				case 4:
message_combatd(HIC"$N手中剑尖斜挑，轻轻插进$n的小腹！\n"NOR,me,ob[i]);
					break;
				default:
message_combatd(HIC"你看见$N手中剑光一闪，正扎在$n左臂肩井穴上！\n"NOR,me,ob[i]);
					break;
			}
			tell_object(ob[i],HIC"你觉得眼前一点寒星直奔而来，顿觉一阵刺痛难忍，眼前发黑。\n"NOR);
		}
		if(userp(ob[i])) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me)) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n独孤九剑之破众："NOR"\n");
	write(@HELP

	使用功效：
		对群殴之敌出手，伤敌精气气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑80级
		内力修为50
		内力250
HELP
	);
	return 1;
}

