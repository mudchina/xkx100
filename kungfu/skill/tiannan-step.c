// tiannan-step.c 天南步法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"只见$n一招"HIG"「旱地拔葱」"NOR"，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
"$n一个"MAG"「雨燕归巢」"NOR"，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
"$n使出"BLK"「破土而出」"NOR"，向一旁飘然纵出，轻轻着地。\n",
"但是$n身形飘忽，一招"BLU"「无中生有」"NOR"轻轻一纵，早已避开。\n",
"$n身随意转，一招"HIC"「乘风而去」"NOR"倏地往一旁挪开了三尺，避过了这一招。\n",
"可是$n侧身一让，一招"HIY"「鲧化大鹏」"NOR"$N这一招扑了个空。\n",
"却见$n足不点地，一招"HIW"「青云直上」"NOR"往旁窜开数尺，躲了开去。\n",
"$n身形微晃，一招"HIR"「凤翔九天」"NOR"有惊无险地避开了$N这一招。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("kurong-changong", 1) < 10 )
	return notify_fail("你的枯荣禅功不够精熟，无法领会天南步法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练天南步法。\n");
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
	write(HIC"\n天南步法："NOR"\n");
	write(@HELP

    天南步法是天南大理段家本门轻功身法。

	学习要求：
	  枯荣禅功10级
HELP
	);
	return 1;
}

