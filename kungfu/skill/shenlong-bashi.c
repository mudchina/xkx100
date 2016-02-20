// shenlong-bashi 神龙八式
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"GRN"「疏影横斜」"NOR"，左手轻轻一抹，向$n的$l拍去",
	"lvl"    : 0,
	"skill_name" : "疏影横斜"
]),
([	"action" : "$N鼓气大喝，双掌使一招"HIY"「五丁开山」"NOR"，推向$n的$l",
	"lvl"    : 10,
	"skill_name" : "五丁开山"
]),
([	"action" : "$N顺势使一招"GRN"「风行草偃」"NOR"，移肩转身，左掌护面，右掌直击$n",
	"lvl"    : 20,
	"skill_name" : "风行草偃"
]),
([	"action" : "$N退后几步，突然反手一掌，一招"RED"「神龙摆尾」"NOR"，无比怪异地击向$n",
	"lvl"    : 30,
	"skill_name" : "神龙摆尾"
]),
([	"action" : "$N使一式"CYN"「风卷残云」"NOR"，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
	"lvl"    : 40,
	"skill_name" : "风卷残云"
]),
([	"action" : "$N忽的使出"HIW"「乾坤倒旋」"NOR"，以手支地，双腿翻飞踢向$n",
	"lvl"    : 50,
	"skill_name" : "乾坤倒旋"
]),
([	"action" : "$N大吼一声，使出"BLU"「同归于尽」"NOR"，不顾一切般扑向$n",
	"lvl"    : 60,
	"skill_name" : "同归于尽"
]),
([	"action" : "$N深吸一口气，使出"HIW"「流星赶月」"NOR"身体涨成球状，猛然流星赶月般直撞向$n",
	"lvl"    : 70,
	"skill_name" : "流星赶月"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingxiong-sanzhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练神龙八式必须空手。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 25)
		return notify_fail("你的毒龙大法火候不够，无法学神龙八式.\n");
	if ((int)me->query_skill("force", 1) < 25)
		return notify_fail("你的基本内功火候不够，无法学神龙八式。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练神龙八式。\n");
	if (2*(int)me->query_skill("dulong-dafa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("你的毒龙大法火候不够，无法继续学神龙八式。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练神龙八式。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -55;
	int d_e2 = -25;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenlong-bashi", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n神龙八式："NOR"\n");
	write(@HELP

    神龙八式为神龙教武功。可与英雄三招互备。

	学习要求：
		基本内功25级
		毒龙大法25级
		内力150
HELP
	);
	return 1;
}

