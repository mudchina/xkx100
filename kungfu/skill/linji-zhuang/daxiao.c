// daxiao.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/daxiao") &&
  !me->query("can_perform/linji-zhuang/daxiao") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (me->query_condition("linji_daxiao") || me->query("linji/jing")>0)
		return notify_fail("你已经在运大小庄了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number") )
		return notify_fail("你不是处女纯阴之体，不能运大小庄！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运大小庄！\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("jing") < skill + 100)
		return notify_fail("你的精不够运大小庄。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "你已经受伤过重，无法运功！\n");

	if( (int)me->query("qi") < skill ||
		(int)me->query("max_qi") < skill ||
		(int)me->query("eff_qi") < skill)
		return notify_fail("你的身体状况现在不适宜运转此功法。\n");

	message_vision("$N坐了下来运起大小庄，呼吸吐纳，真气直透九重。脸上神色一会变"HIR"红"NOR"，一\n会变"HIC"青"NOR"，一会又变成"HIY"黄"NOR"色，最后终于回复原来的脸色。\n"NOR,me);
	me->apply_condition("linji_daxiao", (int)skill/20);
	me->add("neili",  -500);
	me->add("max_jing", 0 - skill);
	me->add("eff_jing", 0 - skill);
	me->add("jing", 0 - skill);
	me->add("max_qi", 2 * skill);
	me->add("eff_qi", 2 * skill);
	me->add("qi", 2 * skill);
	me->set("linji/jing", skill);
	me->save();
	return 1;
}

int help(object me)
{
	write(WHT"\n临济十二庄之大小庄："NOR"\n");
	write(@HELP

	使用功效：
		以气化精

	出手要求：
		临济十二庄150级
		内力500
		处女纯阴之体
HELP
	);
	return 1;
}

