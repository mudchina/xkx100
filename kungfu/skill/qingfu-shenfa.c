// qingfu-shenfa.c 青蝠身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n一招"HIC"「福满乾坤」"NOR"，身形陡然纵起，躲过了$N这一招。\n",
	"$n一式"HIC"「五蝠献寿」"NOR"，身形晃动，向一旁飘出，避开了$N这一招。。\n",
	"$n使出"HIC"「洞天福地」"NOR"，一个空心筋斗向后翻出，避开了$N的凌厉攻势。\n",
	"$n一招"HIC"「云龙百蝠」"NOR"，身随意转，$N只觉眼前一花，$n已绕至$N的身后。\n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("jiuyang-shengong", 1) < 10 )
	return notify_fail("你的九阳神功不够精熟，无法领会青蝠身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("你的体力太差了，不能练青蝠身法。\n");
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
	write(HIC"\n青蝠身法："NOR"\n");
	write(@HELP

    明教的本门轻功身法。主要是从韦一笑的轻功身法而来。

	学习要求：
		无
HELP
	);
	return 1;
}

