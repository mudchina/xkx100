// chanchu_bufa.c 蟾蜍步法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n一招"HIY"「蟾飞九天」"NOR"，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"但是$n一个使出"HIY"「蛙鸣震天」"NOR"，身形飘忽，轻轻一纵，早已避开。\n",
	 "$n一招"HIY"「蛙入稻田」"NOR"，身行随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
	"可是$n一个"HIY"「蟾蜍扑虫」"NOR"，侧身一让，$N这一招扑了个空。\n",
	"却见$n"HIY"「蟾翻白肚」"NOR"，足不点地，往旁窜开数尺，躲了开去。\n",
	"$n身形一招"HIY"「金蟾归月」"NOR"，身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("hamagong", 1) < 10 )
		return notify_fail("你的蛤蟆功不够精熟，无法领会蟾蜍步法。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 10 || (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能练蟾蜍步法。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point() { return 1.1; }

int help(object me)
{
	write(HIC"\n蟾蜍步法："NOR"\n");
	write(@HELP

    白驼山本门轻功。

	学习要求：
	   蛤蟆功10级
HELP
	);
	return 1;
}

