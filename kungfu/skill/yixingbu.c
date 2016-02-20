// yixingbu.c 意形步法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	BLU"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n"NOR,
	MAG"可是$n不紧不慢往右走了一步，躲过了$N这一招。\n"NOR,
	MAG"但是$n身形飘忽，轻轻一纵，早已避开。\n"NOR,
	MAG"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n"NOR,
	BLU"可是$n侧身一让，$N这一招扑了个空。\n"NOR,
	BLU"却见$n足不点地，往旁窜开数尺，躲了开去。\n"NOR,
	BLU"$n身形微晃，有惊无险地避开了$N这一招。\n"NOR,
	MAG"$n看似无心地信手一拂，肩头微侧，堪堪避过了$N这一招。\n"NOR,
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("dulong-dafa", 1) < 10 )
	return notify_fail("你的毒龙大法不够精熟，无法领会意形步法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("你的体力太差了，不能练意形步法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n意形步法："NOR"\n");
	write(@HELP

    意形步法为神龙岛独门轻功身法。

	学习要求：
	  毒龙大法10级
HELP
	);
	return 1;
}


