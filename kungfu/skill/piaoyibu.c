// piaoyibu.c 飘逸步法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype(object me) { return "dodge"; }

string *dodge_msg = ({
	"$n一个"HIC"「银鹭渡海」"NOR"，跃起数尺，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招"HIY"「玉兔落尘」"NOR"，避过了$N的攻击。\n",
	"$n使出"HIY"「锦鲤穿沙」"NOR"，恰好躲过了$N的攻势。\n",
	"$n一招"MAG"「灵狐幻遁」"NOR"，姿态美妙地躲了开去。\n"
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("kuihua-xinfa", 1) < 10 )
	return notify_fail("你的葵花心法不够精熟，无法领会飘逸步法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能练飘逸步法。\n");
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
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n飘逸步法："NOR"\n");
	write(@HELP

    日月神教黑木崖本门轻功。

	学习要求：
	  葵花心法10级
HELP
	);
	return 1;
}

