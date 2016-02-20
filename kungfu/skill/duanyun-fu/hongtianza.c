//hongtianza.c 夺命三斧之「轰天砸」
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define PNAME "轰天砸」"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg,*limbs;
	int i,size,damage;
	int p;
	object my_w,target_w,piece;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	my_w = me->query_temp("weapon");
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
	target_w = target->query_temp("weapon");
//	if( target->is_busy() )
//		return notify_fail(target->name() +"目前正茫然不知所措，加紧攻击吧。\n");

	if (!objectp(my_w = me->query_temp("weapon"))
		|| (string)my_w->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"还使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"功力还使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力不够。\n");
	me->add("neili", -300);
	msg = CYN"$N突然暴吼一声：“我砸！我砸！我砸砸砸！”，手中巨斧竟然砸向$p手中兵刃！\n"NOR;

	if(target->query_temp("weapon")||target->query_temp("secondary_weapon"))
	{	
		me->start_busy(2);
		if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
		{
			if( target_w->weight() > 2 * random(my_w->weight()) )
			{
				msg += "结果$p手中的" +target_w->query("name") + "被$P的轰天砸砸个正着，再也把握不住，立即脱手飞出！\n" NOR;
				target_w->unequip();
				target_w->move(environment(target));
				target->reset_action();
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1) / 30);
			}
			else
			{
				msg += HIC"只见$n手中的"+target_w->query("name")+"竟然被砸断作数段，并且受到$N的劲气的激荡而向$n迅速射去！\n"NOR;
				target_w->unequip();
				target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆兵器的碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1)/40);
				limbs=target->query("limbs");
				me->start_busy(1);
				size=(int)(me->query_skill(bskill, 1)/10);
				damage=random(size)+size;
				damage=damage+me->query_str()/3+random(me->query_temp("apply/damage"));
				for(i=0;i<=random(size);i++)
				{
					msg+=HIB"“嗤”，碎片射入$p"+limbs[random(sizeof(limbs))]+"！\n"NOR;
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage/3,me);
				}
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
//				COMBAT_D->report_status(target);
			}
		} else {
			msg+="可是$p将手中的"+target_w->query("name")+"一侧，并没有让$P的砸着什么。\n" NOR;
		}
		message_combatd(msg,me,target);
		return 1;
	}
	return notify_fail(target->name() + "目前是空手，你想砸什么？\n");
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		摧毁对方兵器并利用兵器碎片伤人

	出手要求：
		枯荣禅功100级
		断云斧100级
		内力500
HELP
	);
	return 1;
}

