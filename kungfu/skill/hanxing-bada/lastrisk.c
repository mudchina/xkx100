// hanxing-fada/lastrisk.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "孤注一掷"
int perform(object me, object target)
{
	int i,s;
	string msg;
	object *ob;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("你必须先有暗器。\n");

	fskill = "honghua-shengong";
	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修为太浅，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"修为太浅，无法使用"+PNAME+"。\n");

	if( me->query("max_neili") < 300)
		return notify_fail("你的内力修为太浅。\n");

	if( me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");

	s = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"孤注一掷，发出所有暗器攻向$n"CYN"！"NOR;
	me->start_busy(2);
	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
	{
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->receive_wound("qi", random(s)*2,me);
	}
	else
	{
		msg += "可是$p躲过了$P的最后一击。\n" NOR;
	}
	message_combatd(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( (string)ob[i]->query("equipped")!="wielded" ) continue;
		ob[i]->unequip();
		ob[i]->move(environment(me));
	}
	me->reset_action();
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		投掷身上所有暗器，损伤对方气血

	出手要求：
		红花神功60级
		寒星八打60级
		内力修为300
		内力200
HELP
	);
	return 1;
}

