// zhaixinggong.c 摘星功
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一个"HIW"「天外摘星」"NOR"，跃起数尺，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招"HIC"「飘然出尘」"NOR"，避过了$N的攻击。\n",
	"$n使出"HIG"「天狼涉水」"NOR"，恰好躲过了$N的攻势。\n",
	"$n一招"HIW"「织女穿梭」"NOR"，姿态美妙地躲了开去。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("huagong-dafa", 1) < 10 )
	return notify_fail("你的化功大法不够精熟，无法领会摘星功。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能摘星功。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n摘星功："NOR"\n");
	write(@HELP

    摘星功是星宿派本门轻功身法。

	学习要求：
	  化功大法10级
HELP
	);
	return 1;
}

