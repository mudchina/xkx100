// mie.c  回风拂柳剑法「灭剑」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「灭剑」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"开什么玩笑，没装备剑就想使"PNAME"？\n"NOR);

	fskill = "linji-zhuang";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，"+PNAME+"不成招式。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"剑法不够娴熟，还使不出"+PNAME+"。\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail(RED"你的内力修为不足，无法运足"PNAME"的内力。\n"NOR);

	if ((int)me->query("neili")<400)
		return notify_fail(HIC"你现在内力不够，没能将"PNAME"使完！\n"NOR);

	msg = HIC "$N手中"+weapon->query("name")+HIC+"剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐\n"NOR;
	msg += HIC"渐逼近$n"HIC"，$n"HIC"看到漫天剑光，抽身后跃，只这一刹，漫天剑\n"NOR;
	msg += HIC"影化为一剑直刺$n"HIC"前胸，快捷无伦，只有一剑！\n"NOR;
	if (random(me->query_skill("force"))>target->query_skill("force")/2 || 
		random(me->query("combat_exp"))>target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1);
		damage = damage + random((int)(damage*3/5));
//		if (me->query("sex/number")) damage/=10;
		target->receive_damage("qi", (int)(damage/2),me);
		target->receive_wound("qi", damage,me);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", (int)(damage/2),me);
		msg +=HIC"$n根本没法躲避，一式「回风拂柳剑」的绝招「灭剑」端端正\n正扎进在$n胸口！$n一低头，便看到长剑自胸口挟"HIR"血"HIC"拔出！\n"NOR;
		me->add("neili", -400);
	} else
	{
		me->start_busy(4);
		msg +=HIY"可是$p轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，长\n剑在$p身侧划过，毫发无伤。\n"NOR;
		me->add("neili", -200);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方精气和气血

	出手要求：
		临济十二庄60级
		回风拂柳剑60级
		内力400
HELP
	);
	return 1;
}

