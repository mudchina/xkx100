// wuguang.c 断云鞭法「日月无光」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「日月无光」"
int perform(object me, object target)
{
	int damage, power;
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail(HIR"装备鞭才能使用「日月无光」？\n"NOR);

	fskill = "xiantian-qigong";
	bskill = "whip";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
	if ((int)me->query("neili") < 600)
		return notify_fail(HIC"你现在内力不够，没能将"PNAME"使完！\n"NOR);
	msg = HIC "$N"HIC"一声大喝，右手一振，手中"+weapon->query("name")+HIC"脱手飞出。只见满天鞭影，盘旋缭绕，遮闭天日，劈头盖脑向$n"HIC"砸了下去！\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		if ((int)me->query("shen") > 1000000) 
			power = 1000000;	
		else if ((int)me->query("shen")>0) 
			power = (int)me->query("shen");
		else power = 3000;
		if ((int)target->query("shen") <0) 
			power=power*2;
		damage = random((int)(power/1000))+(int)(power/3000);
		me->add("neili", -600);
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);		
		target->receive_wound("qi", damage/2,me);
		target->receive_damage("jing", damage/4,me);
msg += HIR"$n疾忙返身后跃，但鞭势疾如电闪，但见黑影如压城之势而来，全身如遭
雷击，一时不知挨了多少鞭，不禁惨声连连！\n"NOR;
	} else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20,me);
		msg += HIY"可是$n"HIY"一纵数丈，一下就跃出了$N的鞭影。\n"NOR;
		me->add("neili", -200);
	}
	msg += HIC+weapon->query("name")+HIC+"落下，倒插在地上，犹振然弄威作响。\n"NOR;
	weapon->move(environment(me));
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
		损伤对方精气
		迟滞对方出手

	出手要求：
		先天气功150级
		断云鞭法120级
		内力600
HELP
	);
	return 1;
}

