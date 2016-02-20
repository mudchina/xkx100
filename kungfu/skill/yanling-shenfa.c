// yanling-shenfa.c 燕灵身法
// Last Modified by sir on 18.10.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n轻轻巧巧地往后一跃，身轻如燕，一式"BLU"「单燕南飞」"NOR"，$N的招数顿时用尽。\n",
	"$n不退反进，身形飒然欺进，一式"BLU"「一叶障目」"NOR"，张开手掌往$N眼前一舞而过，$N视线被挡，手上招数顿时缓了一缓。\n",
	"$n双袖轻拂，身形拔地而起，在空中一个空翻，"HIW"「双燕分飞」"NOR"，跃到$N身后。\n",
	"$n左足上挑，右足力蹬，一式"HIC"「燕子出巢」"NOR"纵跃于几丈开外。\n",
	"$n左一步，右一转，斜刺里一插，一式"GRN"「余音绕梁」"NOR"，围绕$N转了半圈，避开了$N的出招。\n",
	"$n一声轻啸，一式"HIM"「走马看花」"NOR"长身而起，侧身让过了$N这招。\n",
	"$n待$N攻近面门，后退几步，突然身形后挫，回手一式"HIM"「燕子回头」"NOR"，堪堪躲过$N这一招。\n",
	"$n一式"HIB"「燕南归巢」"NOR"，一个侧身飘然掠起，转眼已在$N身后。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("shenyuan-gong", 1) < 10 )
	return notify_fail("你的神元功不够精熟，无法领会燕灵身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习燕灵身法。\n");
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
	write(HIC"\n燕灵身法："NOR"\n");
	write(@HELP

    燕灵身法是慕容世家轻功身法，施展时有如飞燕掠空，轻灵迅
捷而得名。

	学习要求：
	  神元功10级
HELP
	);
	return 1;
}

