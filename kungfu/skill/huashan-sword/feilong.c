// feilong.c  华山剑法「天外飞龙」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「天外飞龙」"
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

  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"装备剑才能使用"PNAME"！\n"NOR);
        
	fskill = "zixia-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");

  if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);

  if ((int)me->query("neili") < 400)
		return notify_fail(HIC"你现在内力不够，没能将"PNAME"使完！\n"NOR);
 
    msg = HIC "$N"HIC"心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n"HIC"掷了出去，\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi");
        target->receive_damage("qi", damage-10,me);
        target->receive_wound("qi", damage*2/3,me);
        msg += HIC"$n"HIC"疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！\n"NOR;
        me->set("neili", 100);
    } else
    {
        me->start_busy(2);
        msg += HIY"可是$n"HIY"轻轻一笑，侧身伸指，正弹在$N"HIY"的剑脊上，剑斜飞落地。\n"NOR;
        me->add("neili", -200);
    }
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
		脱手飞剑伤敌
		极度损伤对方气血，但威力稍弱于狂风快剑

	出手要求：
		华山剑法150级
		紫霞神功100级
		内力600
HELP
	);
	return 1;
}

