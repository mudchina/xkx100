// throw.c 抽髓掌施毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「腐尸毒」"

inherit F_SSERVER;
int perform(object me, object target)
{
	object obj;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	//兵器空手均可
	
	fskill = "huagong-dafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 600) 
		return notify_fail("你内力修为太弱，使不出"PNAME"。\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("你现在真气太弱，使不出"PNAME"。\n");

	if ( !(objectp(obj=present("corpse", environment(me))) ||
		objectp(obj=present("corpse", me)) ||
		objectp(obj=present("skeleton", environment(me))) ||
		objectp(obj=present("skeleton", me)) ) )
		return notify_fail("你周围没有尸体。\n");

	msg = BLU"\n$N"BLU"一声阴笑，右手突出，顺手挟起一具尸体掷向$n"BLU"，一股死鱼烂肉的臭气弥漫四周，闻者欲呕！\n"NOR;

	me->start_busy(1);
	me->add("neili", -200);
	if( random( (int)me->query_skill("strike")) >
		random(target->query_skill("dodge",1) )/2 )
	{
		msg += CYN "$n见此怪异的招数，手足无措，躲闪无及，只见散发着恶臭的尸体，正击在自己身上。\n"NOR;
		target->receive_damage("qi",(int)me->query_skill("strike",1),me);
		target->receive_wound("qi",15 + random(10),me);
		target->receive_wound("jing", 10,me);
		target->apply_condition("fushi_poison", random(me->query_skill("strike",1)/10) + 1 + target->query_condition("fushi_poison"));
		target->start_busy(1 + random(2));
	} else {
		msg += HIB"$n见势不好，连忙纵身直起，腐尸从身下掠过，没有打中。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
		destruct(obj);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方精气和气血
		使对方中毒

	出手要求：
		化功大法40级
		抽髓掌40级
		周围有尸体
		内力修为600
		内力400
HELP
	);
	return 1;
}

