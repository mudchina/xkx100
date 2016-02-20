// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「焚我」"
int perform(object me, object target)
{
	object weapon,piece;
	int i;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if (weapon->is_unique())
		return notify_fail("你手中之刀已是锋利之极，使用「焚我」绝技没有什么作用！\n");

	fskill = "yijinjing";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"还不够娴熟，使不出"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("force") != "yijinjing")
			return notify_fail("没有易筋经作为根基，是无法使出「焚我」绝技的！\n"); 
	}
	if( (int)me->query_str() < 34)
		return notify_fail("你的膂力不够强劲，使不出「焚我」绝技。\n");
	if( (int)me->query_int() < 34)
		return notify_fail("没有大智慧大般若，是使不出焚我绝技的。\n");
	if(me->query_temp("ranmu")) 
		return notify_fail("你现在正在使用「焚心」绝技。\n"); 
	if (me->query_temp("fumo"))
		return notify_fail("你现在正在使用「金刚伏魔」神功。\n"); 
	if (me->query("max_neili") < 2000)
		return notify_fail("你的内力修为不够。\n");
	if (me->query("neili") < 650)
		return notify_fail("你的内力不够。\n");
	me->add("neili", -600);
	message_combatd( HIR"\n$N双掌夹刀合十，手中的"+weapon->name()+HIR"顿时升起一团火焰将自己包围，$N"HIR"猛宣一声佛号，一刀直劈向$n"HIR"！\n"NOR,me,target);	

//fenwo's damage depends on how many times u pfmd	
	i = me->query("fenwo");
	if(i > me->query_skill("blade")) i = me->query_skill("blade");
	i -= me->query("age");
//and it will not be over ur enable blade skill

	me->add_temp("apply/damage", i);
	me->set_temp("fenwo_hit", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add("fenwo",1);
	weapon->add("fenwo", 1);
	if (weapon && weapon->query("fenwo") >= (3+weapon->query("rigidity")))
	{
		message_combatd(HIY "\n只听“咔咔”几声，$N手中的$n"HIY"在熊熊火焰中裂成了碎片！\n"NOR,me,weapon);
		weapon->unequip();
   	seteuid(getuid());
   	piece = new("/clone/misc/piece");
   	piece->set("long", "烧成碎片的一堆物事。\n");
   	piece->set_name( "碎裂的" + weapon->query("name"), ({weapon->query("id"),"piece"}) );
   	piece->move(environment(me));
 		destruct(weapon);
		me->reset_action();
	}
	me->add_temp("apply/damage", -i);
	me->delete_temp("fenwo_hit");
	me->start_busy(2+random(2));
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
		焚毁自己兵刃，猛力出手

        出手要求：
                燃木刀法150级
                基本刀法150级
                易筋经120级
                后天膂力34
                后天悟性34
                内力修为2000
                内力650
HELP
        );
        return 1;
}

