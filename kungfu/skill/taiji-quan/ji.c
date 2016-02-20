// ji.c 太极拳「挤」字诀
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「挤」字诀"
string *taiji_msg = ({"揽雀尾","单鞭","提手上势","白鹤亮翅","搂膝勾步","白蛇吐信","高探马","伏虎式","揽月势","金鸡独立","玉女穿梭","进步七星","弯弓射虎","抱虎归山",});

int perform(object me, object target)
{
	int damage, force;
	string msg, *limbs;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你先放下手中的武器再说吧？！\n");     
		
	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够高，不能用来挤伤敌。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("你现在真气不够，强行使用「挤」是发挥不了它的威力的！\n");

	if( (int)me->query("jing", 1) < 100 )
		return notify_fail("你现在精气不够，强行使用「挤」是发挥不了它的威力的！\n");		     
		
	limbs = target->query("limbs");
	msg = CYN"\n$N使一招太极拳「"+taiji_msg[random(sizeof(taiji_msg))]+"」，右脚实，左脚虚，运起"RED"「挤」"CYN"字诀，粘连粘随，右掌已搭住$p"+limbs[random(sizeof(limbs))]+"！\n"NOR;
	
	force = me->query_skill("force", 1) + target->query_skill("force", 1);

	if(random(me->query_skill("unarmed", 1)) > target->query_skill("parry",1)/3)
	{
		me->start_busy(2);
		if(!target->is_busy()) target->start_busy(random(2));
		damage = (int)me->query_skill("force", 1) * 2;
		damage = damage+ (int)me->query_skill(bskill, 1);
		if(me->query("max_neili") > target->query("neili")*2)
			damage *= 2;
		else if(me->query("max_neili") > target->query("neili")*3/2)
			damage += random(damage);
		else if(me->query("max_neili")*2 < target->query("neili")) damage /= 2;
		else if(me->query("max_neili") < target->query("neili")) damage -= random(damage);
		else damage = damage/2 + random(damage);
		if(damage> 1000) damage = 1000; 
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -(damage/4));
		me->add("jing", -50);
		msg += HIR "跟着$P横劲发出，$p给这么一挤，身子被自己的劲力带得不由主的向前一冲，跨出数步！\n"NOR;       
		} 
	else{
		me->start_busy(3);
		me->add("jing", -25);
		me->add("neili", -150);
		msg += HIY"$p见此情景，一声惊噫，连忙收回自己的劲力，闪身避让！\n"NOR;
	    }
	message_combatd(msg, me, target);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		自身内力修为越高伤害度越高

	出手要求：
		太极神功100级
		太极拳100级
		内力500
HELP
	);
	return 1;
}

