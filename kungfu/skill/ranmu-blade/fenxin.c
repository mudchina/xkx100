// renmu-daofa 燃木刀法

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「焚心」"
int perform(object me, string arg)
{
	object weapon, target;
	int i, j, z;       
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

	if (weapon->query("id") != "mu dao" || weapon->query("ownmake"))
		return notify_fail("你没有木刀，无法使出「焚心」绝技！\n");

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

	if( (int)me->query_skill(fskill, 1) < 170 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 160 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(bskill)+"还不够娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("你的内功等级不够，使不出「焚心」绝技。\n");

	if( (int)me->query_str() < 32)
		return notify_fail("你的膂力还不够强劲，使不出「焚心」。\n");
	if( (int)me->query_dex() < 30)
		return notify_fail("你的身法还不够迅猛，使不出「焚心」。\n");

	if(me->query_temp("ranmu")) 
		return notify_fail("你现在正在使用「焚心」绝技。\n"); 

	if (me->query_temp("fumo"))
		return notify_fail("你现在正在使用「金刚伏魔」神功。\n"); 

	if (me->query("neili") < 1000)
		return notify_fail("你的内力不够。\n");

	j = me->query_skill("blade", 1)/10;
	z = me->query_skill("force", 1)/10;
	i = me->query_skill("force", 1)/10;
	me->add("neili", -j*8);
	me->add_temp("apply/strength", z);
	me->add_temp("apply/attack", j); 
	me->add_temp("apply/damage", 80);
	me->set_temp("ranmu", 1);
	call_out("check_fight", 1, me, z, j, i);
	message_combatd(HIR "$N"HIR"单掌合揖，突然爆吼一声，运起佛门至上金刚伏魔功，\n手中的木刀顿时化作一团火焰，激荡的炙流将$n团团围住！\n"NOR,me,target);
	return 1;
}

void remove_effect(object me, int j, int z, object weapon)
{
	object piece;
	me->add_temp("apply/strength", -z);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -80);
	me->delete_temp("ranmu");
	tell_object(me, HIR"你「焚心」绝技运行完毕，气回丹田");
	if (weapon && weapon->query("id") == "mu dao")
	{
		weapon->unequip();
		seteuid(getuid());
		piece = new("/clone/misc/piece");
		piece->set_name("木头", ({ "mu tou" }));
		piece->set("unit", "块");
		piece->set("long","一块木头。\n");
		tell_object(me, "，手中的木刀变成了一块木头。\n" NOR);
	  piece->move(me);
	  destruct(weapon);
	}
	else tell_object(me, "。\n" NOR);
}

void check_fight(object me, int z, int j, int i)
{
	object weapon;      

	if (!me) return;
	if(!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id") != "mu dao" ||
		weapon->query("skill_type") != "blade")
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	if (i < 1 || !me->is_fighting())
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	call_out("check_fight", 1, me, z, j, i-1);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
                焚烧手中木刀，大增自身攻击力

        出手要求：
                燃木刀法160级
                基本刀法140级
                基本内功200级
                易筋经170级
                后天膂力32
                后天身法30
                内力1000
HELP
        );
        return 1;
}

