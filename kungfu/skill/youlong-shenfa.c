// youlong-shenfa.c 游龙身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n一招"HIC"「龙翔九天」"NOR"，右脚轻轻点地，身体「嗖」的向上笔直地纵起
丈余，躲过了$N这一招。\n",
	"$n一个"HIY"「龙游四海」"NOR"，双臂一张，行云流水般向后纵出，避开了$N的凌厉
攻势。\n",
	"$n使出"MAG"「翩若惊鸿」"NOR"，身形不住闪动，终于躲过$N的攻击。\n",
	"$n使出"BLU"「神龙无影」"NOR"，$N眼前一花，已不见$n踪影。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("honghua-shengong", 1) < 10 )
	return notify_fail("你的红花神功不够精熟，无法领会游龙身法。\n");
	return 1;
} 
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习游龙身法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 15; } 
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIM"\n游龙身法："NOR"\n");
	write(@HELP

    红花会轻功身法。

	学习要求：
		红花神功10级
HELP
	);
	return 1;
}
