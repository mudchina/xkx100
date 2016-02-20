// po.c 破剑式
// Last Modified by winder on Mar. 10 2000
/*
独孤九剑，“总诀式”做在zongjue 中，有种种变化，用以体演
总诀，便于修习。
第二招“破剑式”，用以破解普天下各门各派的剑法。
第三招“破刀式”，用以破解单刀、双刀、柳叶刀、鬼头刀、大
砍刀、斩马刀种种刀法。
第四招“破枪式”，包括破解长枪、大戟、蛇矛、齐眉棍、狼牙
棒、白蜡杆、禅杖、方便铲种种长兵刃之法。
第五招“破鞭式”，用以破解钢鞭、铁锏、点穴橛、拐子、蛾眉
刺、匕首、板斧、铁牌、八角槌、铁椎等等短兵刃。
第六招“破索式”，破解的是长索、软鞭、三节棍、链子枪、铁
链、渔网、飞锤流星等等软兵刃。
第七招“破掌式”，破的是拳脚指掌上的功夫，将长拳短打、擒
拿点穴、魔爪虎爪、铁沙神掌，诸般拳脚功夫尽数包括内在。
第八招“破箭式”，则总罗诸般暗器，练这一剑时，须得先学听
风辨器之术，不但要能以一柄长剑击开敌人发射来的种种暗器，
还须借力反打，以敌人射来的暗器反射伤敌。
三述八招归于po中。
第九剑“破气式”，是为对付身具上乘内功的敌人而用，神而明
之，存乎一心。用poqi来实现。
pozhong 一招，是“破箭式”的变招。
*/

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "破剑式"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage, sk ;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	if(me->query("family/master_id")!="feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");
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
		return notify_fail("独孤九剑攻招只能对战斗中的对手使用。\n");
		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("没有剑在手怎么能用独孤九剑？\n");

	bskill = "sword";

	skill = me->query_skill(sskill,1);

	if( skill < 50)
		return notify_fail("你的独孤九剑等级不够，不能使用攻招！\n");
		
	if( me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够，无法运用攻招！\n");

	if( me->query("neili") < 250 )
		return notify_fail("你的内力不够，无法运用攻招！\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))) sk = 1;
	else
	{
		if((string)weapon2->query("skill_type")=="sword") sk=2; //掌
		if((string)weapon2->query("skill_type")=="blade") sk=3; //刀
		if((string)weapon2->query("skill_type")=="spear" ||     //枪
			(string)weapon2->query("skill_type")=="club" || //棍
			(string)weapon2->query("skill_type")=="fork" || //叉
			(string)weapon2->query("skill_type")=="rake" || //耙
			(string)weapon2->query("skill_type")=="stick" || //棒
			(string)weapon2->query("skill_type")=="staff") sk=4;//杖
		if((string)weapon2->query("skill_type")=="mace" || //鞭
			(string)weapon2->query("skill_type")=="axe" || //斧
			(string)weapon2->query("skill_type")=="dagger" || //匕
			(string)weapon2->query("skill_type")=="hammer" || //锤
			(string)weapon2->query("skill_type")=="hook") sk=5; //钩
		if((string)weapon2->query("skill_type")=="whip") sk=6; //软鞭
		if((string)weapon2->query("skill_type")=="throwing") sk=7;//暗器
	}
// 破掌
	switch (sk)
	{
		case 1:
			msg = HIC"$N"HIC"使出独孤九剑之「破掌式」，劲力聚在剑尖，以意使剑，向$n"HIC"的掌心刺去。\n";
			break;
		case 2:
			msg = HIC"$N"HIC"举"+weapon->name()+HIC"画弧，默潜独孤九剑之「破剑式」, 斜刺里刺出一剑，剑势飘忽，刺向$n"HIC"的手腕。\n";
			break;
		case 3:
			msg = HIC"$N"HIC"使出独孤九剑「破刀式」，手腕微翻，"+weapon->name()+HIC"挑上，刷的一声，刺向$n"HIC"肩头“肩贞穴”。\n";
			break;
		case 4:
			msg = HIC "$N"HIC"一式独孤九剑「破枪式」，剑势灵巧地顺着"+weapon2->name()+HIC"削落，划向$n"HIC"的五指。\n";
			break;
		case 5:
			msg = HIC"$N"HIC"使出独孤九剑「破鞭式」逼近$n"HIC"，提剑幻出重重剑影，向$n"HIC"如柔丝般向$n裹去。\n";
			break;
		case 6:
			msg = HIC"$N"HIC"使出独孤九剑之「破索式」，剑化流星，迅急无比地点向$n"HIC"的手腕。\n";
			break;
		case 7:
			msg = HIC"$N"HIC"举剑连点，运起独孤九剑之「破箭式」, 将$n掷过来的"+weapon2->name()+"打得向$n"HIC"反击回去。\n";
			break;
	}
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill(bskill) + skill;
	dp = target->query_skill(bskill) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-50);
		switch (sk)
		{
			case 1:
				msg = HIY"$n顿时觉得眼前一花，手心一凉，手掌中心一截剑尖冒了出来。\n"NOR;
				break;
			case 2:
				msg = HIY"$n顿时觉得眼前一花，手腕一麻，手中"+weapon2->name()+HIY"脱手而出！\n"NOR;
				break;
			case 3:
				msg = HIY"$n肩头剧痛，双手使不出力道，手中"+weapon2->name()+HIY"“当啷”一声掉在地上。\n"NOR;
				break;
			case 4:
				msg = HIY"$n顿时大惊，为保手指，忙把手中"+weapon2->name()+HIY"撒手抛出！\n"NOR;
				break;
			case 5:
				msg = HIY"$n顿觉手心猛地剧痛，手中"+weapon2->name()+HIY"被绞得脱手飞出！\n"NOR;
				break;
			case 6:
				msg = HIY"$n只觉得$N的"+weapon->name()+"乘空直入，手中"+weapon2->name()+HIY"被挡在外门，回救不及，不得不弃之腾出手来空手招架。\n"NOR;
				break;
			case 7:
				msg = HIY"$n顿时觉得铺天盖地的"+weapon2->name()+HIY"反而向自己袭来！全身上下立刻被打得跟马蜂窝似的\n" NOR;
				break;
		}
		me->start_busy(1+random(2));
		target->receive_damage("qi", damage,me);
		if (!target->is_busy())
		target->start_busy(2);
		if (sk ==1)
		{
			if (!target->query_temp("lonely-sword/pozhang"))
			{
				target->set_temp("lonely-sword/pozhang",1);
				target->start_call_out((:call_other, __FILE__, "remove_effect", target:), skill/30+2);
			}
		}
		else 
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		if(sk==1)
			msg = HIG"可是$n看破了$N的剑路，一个铁坂桥，避开$N的凶狠出手。\n"NOR;
		else
			msg = HIG"可是$n看破了$N的剑路，立刻将手中" + weapon2->name()+ "舞得风雨不透，使$N的出手落空。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}
void remove_effect(object me)
{
	if (me->query_temp("lonely-sword/pozhang"))
	{
//	 tell_object(find_player("qingyun"),me->name()+"remove eff from pozhang\n");
	 me->delete_temp("lonely-sword/pozhang");
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		击落手持兵器的敌手之兵器，并伤敌气血
		攻击未持兵器的敌手，伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑50级
		内力修为500
		内力250
HELP
	);
	return 1;
}

