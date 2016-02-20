// nian.c 太极拳「粘」字诀
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「粘」字诀"
int perform(object me, object target)
{
	object ob;
	string msg;
	int skill,busytime=0;
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

	if( objectp(ob = me->query_temp("nian")) )
	{
		if( ob->is_fighting(me) )
		return notify_fail("你已经在粘连粘随对手了。\n");
	}

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手。\n");
		
	if( (string)target->query("race") != "人类" )
 		return notify_fail("有这个必要么？\n");

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
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( !me->query_temp("taiji") && (int)me->query("jiali") )
			return notify_fail("太极拳纯以意行，最忌用力，你加了力使不出「粘」字诀。\n");
	}
	if(me->query("neili")<100)
		return notify_fail("你的内力不足。\n");
  skill = (int)me->query_skill(sskill, 1);
	msg = HIY"\n$N左手带着$n的右手，转了一个大圈，一股极强的螺旋力带动$p左手，正是太极云手。\n";

	me->recieve_damage("qi", 50);
	me->recieve_damage("jing", 50);
	me->add("neili",-60);

	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / 200 )
	{
//		msg += "结果$p被$P粘连得跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷。\n" NOR;
		msg += "这云手连绵不断，一圈过后，又是一圈，$n的双掌似乎全给$P粘住了。\n"NOR;
		me->set_temp("nian", target);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/6);      
	}
	else
	{
		switch( random(3) )
		{
			case 0: msg += "$p急忙使出“千斤坠”之力定住身形。\n" NOR; break;
			case 1: msg += "$p不敢便接，斜身闪开。\n" NOR; break;
			case 2: msg += "$n全身内力一震，$P双手按他不住，被$p跃出圈外！\n" NOR; break;
		}
		me->start_busy(1 + random(3));
	}
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me)
{
	if( objectp(me->query_temp("nian")) )
	{
		me->delete_temp("nian");
		if( me->is_fighting() )
			message_combatd("\n$N劲力一松，粘力卸去。\n", me);
	}
}
/*
想到他连最后一分力气也给自己逼了出来，不由得汗如雨下。劲力一松，粘力卸去，
拖得精疲力尽，虚脱而死。
*/

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		使对手无法离开

	出手要求：
		太极神功100级
		太极拳100级
		运太极心法或不加力
HELP
	);
	return 1;
}

