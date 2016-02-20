// raozhi.c 「绕指柔剑」
// Last Modifyed by Winder on Jan. 14 2002

/*
这路「绕指柔剑」全仗以浑厚内力逼弯剑刃，使剑招闪烁无常，敌人难以挡架。
殷天正从未见过这等剑法，急忙沉肩相避，不料铮的一声轻响，那剑反弹过来，
直刺入他左手上臂。
*/

#include <ansi.h>
void remove_effect(object me, object weapon, int sword, int force);
inherit F_SSERVER;
#define PNAME "「绕指柔剑」"
int perform(object me,object target)
{
	int force, sword;
	object weapon = me->query_temp("weapon");
	string shape = weapon->query("id");
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
		
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能使出「绕指柔剑」？！\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("你已经将内力贯注入剑中了！！\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(fskill)+"修为火候未足，无法以内力逼弯剑刃！\n");

	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(sskill)+"修为还不够，难以施展"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill )
			return notify_fail("你所用的内功与「绕指柔剑」心法相悖！\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if(userp(me) && !me->query("wudang/raozhi") )
			return notify_fail("你未得高人指点，不知该如何施展「绕指柔剑」。\n");
	}

  if( me->query_temp("taiji"))
    return notify_fail("你已经运了太级心法，没有太多精力施展「绕指柔剑」！\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("你的内力不够浑厚，劲力不足以逼弯剑刃！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不够，劲力不足以逼弯剑刃！\n");

	if( me->query("qi") <= 400 )
		return notify_fail("你的体力有限，难以施展「绕指柔剑」！\n");

	if( shape == "iron sword" )
		return notify_fail("你所持之剑质地过於坚硬，难以用内力将其逼弯！\n");

	if( weapon->query("ownmake"))
	  return notify_fail("自铸兵器不宜施展「绕指柔剑」！\n");

	if( shape == "tie di" || shape == "tie xiao" || shape == "zhu xiao" ||
		shape == "yu xiao")
		return notify_fail("箫笛形状不适合施展「绕指柔剑」！\n");

	if( shape == "xiuhua zhen" || shape == "qijue zhen" ||
		shape == "emei ci" || shape == "duanjian" || shape == "bishou" )
		return notify_fail("你的佩剑太短，不适合施展「绕指柔剑」！\n");

	me->add("neili", -100);
	me->receive_damage("qi", 150);

	if( (string)weapon->query("material") != "steel" || weapon->query("rao"))
	{
		message_combatd(HIW"\n猛地里$N一声清啸，剑法忽变。可是手中"+weapon->name()+HIW"却已经不住内力冲击，裂成碎片！！\n"NOR, me);
		destruct(weapon);
		me->reset_action();
		me->start_busy(1);

		return 1;
	}

	force = me->query_skill("force")/2;
	sword = me->query_skill(bskill)/3;

	weapon->add("rigidity", -force);
	weapon->set("rao",1);
	me->add_temp("apply/attack", sword);
	me->set_temp("wudang/raozhi", sword);

	message_combatd(HIG"\n猛地里$N一声清啸，剑法忽变，那柄"+ weapon->name() +HIG"竟似成了一条软带，轻柔曲折，飘忽不定。\n正是武当派绝技"+ HIW +"「绕指柔剑」"+ HIG +"！\n"NOR, me);

	call_out("checking", 1, me, weapon, sword, force);
	return 1;
}

void checking(object me, object weapon, int sword, int force)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() || !objectp(weapon))
	{
		remove_effect(me, weapon, sword, force);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIG "\n$N伸指在剑脊上轻轻一弹，只听得" + weapon->name() + HIG"振起嗡嗡之响，剑身不停抖动。\n"+CYN+"$N顺势挽起一个剑花，将剑势收回。\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( environment(weapon) != me || weapon !=me->query_temp("weapon"))
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIR "\n$N放弃手中" + weapon->name() +HIR"，将剑势收回！\n"NOR, me);
		return;
        }
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("qi") < (int)me->query("max_qi") / 4 )
	{
	        remove_effect(me, weapon, sword, force);
        	tell_object(me,HIR"\n你微觉内息不畅，不得不将内力收回！\n" NOR);
		message("vision", CYN+"\n"+ me->name() + weapon->name() + CYN"圈转，收回剑势。招数已不如之前闪烁无常，变幻不定！\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian" &&
		!me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(CYN "\n$N圈转" + weapon->name()+ CYN"，突然变招，使出与"+ HIW +"「太极剑」"+ NOR + CYN"不同的剑法！\n"NOR, me);
		return; 
	}
	else if( me->query_temp("wudang/raozhi") <= 50 )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIC "\n$N" + weapon->name()+ HIC"圈转，已堪堪将一路"+ HIW +"「绕指柔剑」"+ HIC +"尽数使出！\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, weapon, sword, force);
} 

void remove_effect(object me, object weapon, int sword, int force)
{
	me->delete_temp("wudang/raozhi");
	me->add_temp("apply/attack", -sword);
  if (objectp(weapon))
  {
  	weapon->add("rigidity", force);
  	weapon->delete("rao");
  }
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
                绕指柔剑全仗以浑厚内力逼弯剑刃，使剑招闪烁无常，敌人难以挡架。

	出手要求：
		太极神功180级
		太极剑法180级
		激发太极神功和太极剑法
		内力修为1500
		内力500
		气血400
		需机缘学得
HELP
	);
	return 1;
}

