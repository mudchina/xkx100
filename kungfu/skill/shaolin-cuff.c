// Last Modified by winder on May. 29 2001
// shaolin-cuff.c - 少林南拳 南少林的入门空手功夫 与少林弹腿互备

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
 "$N一式『马步双插掌』，左脚向左横跨一步，双腿半蹲马步，双拳化掌用力前插",
 "$N一式『马步沉桥』，马步不动，双手变掌，屈膝沉腕，使劲下压",
 "$N右脚向左前一步，左脚绕过右脚，身体转动不停，一式『骑龙步右踢腿』，向$n踢去",
 "$N身体左转，右脚向左脚右跨一步，一式『马步劈掌』，右拳化掌，右臂由曲变伸，向下斜劈",
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shaolin-leg"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练少林南拳必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 1)
		return notify_fail("你的站桩功火候不够，无法学少林南拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习少林南拳。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练少林南拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"dodge"  : 35+random(25),
		"parry"  : -20+random(15),
		"force"  : 70+random(150),
		"damage_type" : random(2)?"内伤":"瘀伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n少林南拳："NOR"\n");
	write(@HELP

    南拳是南少林入门拳法，多短打近攻，动作迅疾刚猛。强调站
桩，讲究“四法一劲（身法、步法、手法、腿法和劲力）”，所谓
“步到身到手到，方为上手道”。

	学习要求：
		站桩功
HELP
	);
	return 1;
}

