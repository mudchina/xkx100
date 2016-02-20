// Last Modified by winder on Jul. 9 2001
// jinwu.c 金乌堕地

/*
由于劈断对方武器的功能是这个perform最大的威力，但为了保持独孤九剑在
这一方面的第一地位，特地对发挥这一威力的条件，在程序中做了如下限制
希望以后的巫师不要更改这些设定，毕竟在weapon武功中，不能超越lonely-sword的地位。
*/

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「"+HIR"金乌堕地"NOR+"」"

int perform(object me,object target)
{
	string msg;
	object weapon, weapon2,*inv;
	int skill, ap, dp, neili_wound, qi_wound,equip,skill1,skill2,skill3,skill4;
	int temp;
	object piece;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
		
	fskill = "bingxue-xinfa";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够，无法运用「"+HIR"金乌堕地"NOR+"」！\n");

	if( me->query("neili") < 400 )
		return notify_fail("你的内力不够，无法运用「"+HIR"金乌堕地"NOR+"」！\n");

	skill  = me->query_skill(sskill,1);
	skill1 = me->query_skill("xueshan-sword",1);
	skill2 = me->query_skill(fskill,1);
	skill3 = me->query_skill(bskill,1);
	skill4 = me->query_skill("strike",1);
	msg = HIY"$N纵身跃起,使出"+HIR"「金乌堕地」"HIY"，挥舞"NOR+weapon->name()+HIY"从半空中挥刀直劈下来，\n刀锋离地尚有数尺，地下已是尘沙飞扬，败草落叶被刀风激得团团而舞，\n将$n逃遁退避的空隙封的严严实实。\n"NOR;
	message_combatd(msg, me, target);
	msg = "";

	ap = random(me->query_skill(bskill) + skill);
	dp = target->query_skill("dodge")/3;
	if (target->query_skill_mapped("parry") == "xueshan-sword")
	{
                msg += HIR "$n" HIR "慌忙中忙以"HIW"雪山剑法"HIR"作出抵挡，哪知$N"
                       HIR "刀法竟似雪山剑法克星般，\n" + weapon->name() +
                       HIR "刀芒霎时又暴涨数倍，完全封锁$n" HIR "的所"
                       "有剑招！\n" NOR;
		ap = ap * 2;
		temp = 1;
	}	
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-250);
		msg += HIC"$n避无可避，只觉一股刚猛之极的劲风扑面而来，使人直欲窒息。\n$n极力后退隔挡，却只见"NOR""+weapon->name()+""HIC"刀光一闪，毫不停息，一刀正中面门。\n"NOR;
		qi_wound = me->query_skill("blade",1)*2+me->query_str()*10;
		qi_wound *= 2;
		if (temp != 1) //对付非雪山门派
		{
			qi_wound = random(qi_wound);
			if(qi_wound > target->query("qi")) qi_wound = 100;
		}
		target->receive_damage("qi", qi_wound);
		target->receive_wound("qi", target->query("max_qi")/3);
		target->start_busy(2+random(1));
		me->start_busy(1+random(1)); 

		if(me->query("str")>=20	&& 		//先天臂力必须不小于20
			objectp(weapon2 = target->query_temp("weapon")) &&
			me->query_str() >= 45 &&	//后天臂力必须不小于45
			me->query("max_neili") > 2500 &&//最大内力必须大于2800
			!me->query("betrayer") &&	//必须没叛过师
			(me->query("neili") - me->query("max_neili")) > 300  &&
//现有内力必须比最大内力多300，由于在上面会减掉250，实际必须大于550
			skill > 200 &&			//金乌刀法必须大于200级
			skill1 > 200 &&			//雪山剑法必须大于200级
			skill2 > 200 &&			//冰雪心法必须大于200级
			skill3 > 200 &&			//基本刀法必须大于200级
			skill4 > 200 &&			//基本掌法必须大于200级
			me->query("family/master_id") == "bai zizai")
	//师父必须是白自在 
		{
			inv = all_inventory(target);
			for(equip=0; equip<sizeof(inv); equip++)
			{
				if(inv[equip]->query("weapon_prop") &&
					((string)inv[equip]->query("equipped")=="wielded"))
				{
					msg += HIW "$N力道未尽，手中刀势不绝，连带$n手上"NOR+inv[equip]->query("name")+HIW"一起劈断。\n只听当的一声，$n手上的"NOR+inv[equip]->query("name")+HIW"已被劈成两半，掉在了地上！\n"NOR;
					message_combatd(msg, me,target);
					inv[equip]->unequip();
					seteuid(getuid());
    			piece = new("/clone/misc/piece");
		    	piece->set_name("断掉的" + inv[equip]->query("name"),({inv[equip]->query("id"),"piece"}));
			    piece->move(environment(target));
					piece->set("long","一把破烂武器，从中断开，破口整齐，看来是被高手一刀劈开的。\n");
				  destruct(inv[equip]);
				}
			}
			return 1;
		}
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg += HIW"可是$n轻轻往旁边一闪，避过了$N这必杀的一刀。\n"NOR;
		me->start_busy(2+random(2));
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
		击落手持兵器的敌手之兵器

	出手要求：
		身为白自在嫡传弟子
		金乌刀法100级
		冰雪心法100级
		内力修为1000
		内力400
HELP
        );
        return 1;
}

