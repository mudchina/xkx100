// zongjue.c 「总诀式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost, exp, myint;
	int skill_basic;
	mapping my_fam = me->query("family");

	skill = me->query_skill("lonely-sword",1);
	skill_basic = me->query_skill("sword",1);
	jing_cost = (int)me->query("int") - 45;

	if(!my_fam || my_fam["master_id"] != "feng qingyang")
		return notify_fail("你不是风清扬嫡传弟子，不能使用总诀式。\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zongjue") &&
  !me->query("can_perform/lonely-sword/zongjue") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");
   	if(environment(me)->is_chat_room()) return notify_fail("这里不准打斗。\n");
	if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。\n");
	myint = me->query("int");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

	if( !skill || (skill < 20))
		return notify_fail("你的独孤九剑等级不够, 不能演练总诀式！\n");
	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练总诀式！\n");

	exp= (int)me->query("combat_exp");
	if( skill*skill*skill/10>exp )
		return notify_fail("你的实战经验不够，无法体会「总诀式」！\n");

	msg= HIG"$N使出独孤九剑之「总诀式」，将手中"+weapon->name()+HIG"随意挥舞击刺。\n"NOR;
	message_combatd(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60) me->improve_skill("lonely-sword",10,skill_basic > skill? 0: 1);
	else if (skill < 90)
		me->improve_skill("lonely-sword",10+random(myint-9),skill_basic > skill? 0: 1);
	else if (skill < 140)
		me->improve_skill("lonely-sword",10+random(myint*2-9),skill_basic > skill? 0: 1);
	else if (skill < 200)
		me->improve_skill("lonely-sword",10+random(myint*4-9),skill_basic > skill? 0: 1);
	else me->improve_skill("lonely-sword",10+random(myint*8-9),skill_basic > skill? 0: 1);

	msg = MAG"$P的「独孤九剑」进步了！\n"NOR;
	me->start_busy(random(2));
	message_combatd(msg, me);
	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之总诀式："NOR"\n");
	write(@HELP

	使用功效：
		演示总诀，提高独孤九剑的修为

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑20级
		内力50
HELP
	);
	return 1;
}

