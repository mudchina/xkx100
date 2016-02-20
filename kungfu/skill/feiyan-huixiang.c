// feiyan-huixiang.c 飞燕回翔
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"但是$n身形飘忽，轻轻一纵，一招"GRN"「乳燕投林」"NOR"，举重若轻的避开这一击。\n",
	"$n身随意转，一式"HIW"「雪花飞舞」"NOR"，倏地往一旁飘开数尺，避过了这一招。\n",
	"可是$n侧身一让，使出"HIG"「柳絮轻飘」"NOR"，$N这一招扑了个空。\n",
	"却见$n足不点地，一招"WHT"「腾云驾雾」"NOR"，身形滴溜溜一转，往旁闪开数尺，躲了开去。\n",
	"$n左脚一点右脚背，身形往上一拔，一招"HIC"「一鹤冲天」"NOR"，轻轻巧巧地避开了这一招。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{
	if( (int)me->query_skill("zixia-shengong", 1) < 10 )
	return notify_fail("你的紫霞神功不够精熟，无法领会飞燕回翔。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20 || (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练飞燕回翔。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n飞燕回翔："NOR"\n");
	write(@HELP

    飞燕回翔为华山派本门轻功。

	学习要求：
	 紫霞神功10级
HELP
	);
	return 1;
}

