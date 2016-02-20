// huoqiu.c 抽髓掌之火球
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "「火球」"
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
	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你发现自己的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你发现自己的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(pskill, 1) < 150 )
		return notify_fail("你发现自己体内聚毒不够，无法使用"+PNAME+"进行攻击。\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你发现自己所用的内功无法进行"PNAME"攻击。\n");
	if( (int)me->query("max_neili") < 2500)
		return notify_fail("你发现自己内力太弱，无法驱动"PNAME"进行攻击。\n");
	if((int)me->query("neili") < 1500)
		return notify_fail("你发现自己现在真气太弱，使不出"PNAME"进行攻击。\n");	   
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("没有火堆怎么驱动"PNAME"进行攻击？\n");
	  message_combatd(HIR"\n$N"HIR"咬破指尖，数滴鲜血落到地面，再用内力一鼓，轰地一声燃起一堆熊熊火焰！\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(HIR "\n$N"HIR"厉声大喝，掌力加盛，火焰中突然生出一个斗大的"RED"火球"HIR"，在空中骨碌碌的迅速转动！\n\n"NOR,me);

	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}
int check_armor(object target)
{
	object *inv;
	int i, j;
	inv = all_inventory(target);
	j=0;

	for(i=0; i<sizeof(inv); i++)
		if( (string)inv[i]->query("equipped")=="worn" ) j++;
	return j;
}
int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;
	object *inv;
	object piece;
	if(!me) return 0;
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");
	damage = (i+me->query("jiali"))*2;

	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!target || !me->is_fighting(target) ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N衣袖再拂，将升起的"RED"火球"HIY"压回火焰之中。\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N眼看火堆熄灭，散开内息，放下举起的双手。\n"NOR,me);
		return 1;
	}

	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -500);
	me->receive_damage("jing", 100);

	msg = WHT"\n此时$N脸上已无半点血色，一口口鲜血不住向"RED"火球"WHT"中吐去，" HIR"\n火势一盛，嗤嗤两声轻响，爆出几朵火花，"RED"火球"HIR"陡然变大向$n疾冲过来！\n"NOR;

	if(random(ap) > dp/3)
	{
		inv = all_inventory(target);
		if(check_armor(target) >= 1)
		{
			if(me->query("neili")>target->query("neili")*2)
			{
				if(me->query_str()>random(target->query_str()))
				{
					me->start_busy(3);
					target->start_busy(2);
					msg += HIY "猛烈间火球温度飙升，火花迸射，炸开了$p的护具！\n" NOR;
					for(i=0; i<sizeof(inv); i++)
						if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique"))
						{
							inv[i]->unequip();
							seteuid(getuid());
							piece = new("/clone/misc/piece");
							piece->move(environment(target));
							piece->set("name", "粉碎的" + inv[i]->query("name"));
              destruct(inv[i]);
						}
					target->reset_action();
					damage = damage * 3;
					//if (damage > 2000) damage = 2000;
					damage = damage-target->query_temp("apply/armor");
					target->receive_damage("qi", damage,me);
					target->receive_wound("qi",damage/2,me);
					target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "砸伤");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					me->start_busy(2);
					target->start_busy(1);	       
				}
				else
				{
					me->start_busy(3);
					target->start_busy(3);
					msg += HIY "只见火球猛然升温，火花四溅，热力直透$p的护具！\n" NOR;
					for(i=0; i<sizeof(inv); i++)
						if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique"))
						{
							inv[i]->set("name", "碎裂的" + inv[i]->query("name"));
							inv[i]->set("value",0);
							if(inv[i]->query("armor_prop/armor"))
							{
								inv[i]->unequip();
								inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
							  inv[i]->wear();
							}
						}
					target->reset_action();
					damage = damage * 3;
					//if (damage > 1800) damage = 1800;
					damage = damage - target->query_temp("apply/armor");
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage/2,me);
					target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "砸伤");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					me->start_busy(2);
					target->start_busy(1);
				}
			}
			else
			{
				me->start_busy(3);
				target->start_busy(3);
				msg += HIY "火球急速滚动，火光四溅，掀起阵阵火焰撞向$p怀里！\n" NOR;		  
				damage = damage * 2;
				//if (damage > 1800) damage = 1800;
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);
				target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
				msg += damage_msg(damage, "砸伤");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				me->start_busy(2);
				target->start_busy(1);
			}
		}
		else
		{
		//target has no armor, so, hehe...
			damage = damage*2 + random(damage);
			if(neili > target->query("neili")*2) damage = damage*2;
			//if (damage > 2800) damage = 2800;
			target->receive_damage("qi", damage,me);   
			target->receive_wound("qi", damage/2,me);	     
			target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "砸伤");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			me->start_busy(2);
			target->start_busy(1);
		}
	}
	else
	{
		me->start_busy(2);
		msg += HIY "\n$p眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过$w"HIY"！\n" NOR;
	}
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", RED"火球"NOR);       
	message_combatd(msg, me, target);
	if(!target->is_killing(me->query("id"))) target->kill_ob(me);
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
		毁损对方护具

	出手要求：
		化功大法180级
		抽髓掌180级
		基本毒技150级
		内力修为2500
		内力1500
		周围有火堆
HELP
	);
	return 1;
}

