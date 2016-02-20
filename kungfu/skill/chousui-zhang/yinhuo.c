// yinhuo.c 抽髓掌之银火
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "「银火」"
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用"PNAME"！\n");	

	if(me->query_temp("pfm_chousui"))
		return notify_fail("你正在驱动火堆进行攻击！\n");
	fskill = "huagong-dafa";
	bskill = "strike";
	pskill = "poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "douzhuan-xingyi";
	}
	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(pskill, 1) < 110 )
		return notify_fail("你发现自己体内聚毒不够，无法使用"+PNAME+"进行攻击。\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你发现自己所用的内功无法进行"PNAME"攻击。\n");
	if( (int)me->query("max_neili") < 1200)
		return notify_fail("你发现自己内力太弱，无法驱动"PNAME"进行攻击。\n");
	if((int)me->query("neili") < 900)
		tell_object(me,"你发现自己现在真气太弱，使不出"PNAME"进行攻击。\n");	   

	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("没有火堆怎么驱动「银火」进行攻击？\n");
	  message_combatd(HIR"\n$N咬破指尖，数滴鲜血落到地面，再用内力一鼓，轰地一声燃起一堆熊熊火焰！\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(YEL"\n$N"YEL"衣袖一拂，一股劲气直射入"HIR"火焰"YEL"之中。从中又分出一道细细的"WHT"银火"YEL"，\n便似一条"WHT"银色长蛇"YEL"横卧空际，轻轻摆动，颜色又是鲜艳，又是诡异，"RED"光芒"YEL"闪烁不定！\n"NOR,me);
	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;
	object wep,piece;
	if(!me) return 0;	
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");	

	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!living(target) || !target || !me->is_fighting(target) ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N衣袖再拂，将升起的"WHT"银火"HIY"压回火焰之中。\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N眼看火堆熄灭，长叹一声，散开内息，双手下垂而立。\n"NOR,me);
		return 1;
	}

	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_str();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -500);
	me->receive_damage("jing", 50);

	msg = YEL"\n突然火焰中升起"GRN"绿色鬼火"YEL"，此时"WHT"银火"YEL"倏地缩回，\n跟着又向$n$l射去，力道极猛，去势奇快！\n"NOR;	

       
	if(random(ap) > dp/3)
	{
		if(objectp(wep = target->query_temp("weapon")))
		{ 
			msg +=HIY"$n看那银火来得迅猛无常，避无可避，只得把手中武器举起来硬挡！\n" NOR;
			if(me->query("neili") < target->query("neili")*2)
			{
				me->start_busy(2);
				msg += HIY "结果只听一声大响，$w"HIY"在$W"HIY"上撞出无数飞花，四散溅开！\n" NOR;
			}
			else if(me->query("neili") > target->query("neili")*4)
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "结果只听“嘣”的一声，在$w"HIW"的猛烈撞击下，$n虎口震裂，$W"HIW"脱手飞出！\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIW "结果只听“啪”的一声巨响，$n手中"+wep->name()+HIW"被$w"HIW"打断，碎片四散溅落！\n" NOR;
						wep->unequip();
						target->reset_action();
						seteuid(getuid());
		        piece = new("/clone/misc/piece");
      			piece->set_name( "断掉的"+wep->query("name"), ({wep->query("id"),"piece"}) );
       			piece->set("long", wep->query("long")+"可惜已经被打得粉碎了。\n");
        		piece->move(environment(target));
       			destruct(wep);
					}
				}
				else
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIY "结果只听一声大响，$w在$W上撞出无数飞花，四散溅开！\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "结果只听“嘣”的一声，在$w"HIW"的猛烈撞击下，$n虎口震裂，$W"HIW"脱手飞出！\n" NOR;
					}
				}
			msg = replace_string(msg, "$W", wep->name());
		}
		else
		{
			damage = i*2+me->query("jiali")*2;
			if(neili > target->query("neili")*2) damage = damage*2;
			if (damage > 1000) damage = 1000;
			target->receive_damage("qi", damage,me);		
			target->receive_wound("qi",damage/2,me);
			target->apply_condition("xx_poison", random(3) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "刺伤");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			me->start_busy(2);
			target->start_busy(2);
		}
	}
	else
	{
		me->start_busy(3);
		msg += HIY"\n$p全力向右一滚，那$w"HIY"堪堪擦肩而过，端的是凶险无比！\n" NOR;
	}
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", WHT"银火"NOR);   
//	if(!target->is_killing(me->query("id"))) target->kill_ob(me);    
	message_combatd(msg, me, target);
	return 1;
}  

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		伤害对方气血
		使对手中星宿毒
		毁损或击落对手兵器

	出手要求：
		化功大法140级
		抽髓掌140级
		基本毒技110级
		内力修为1200
		内力900
		周围有火堆
HELP
	);
	return 1;
}

