// biluo-zhang.c 碧罗掌
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式「起手式」，左手带风，右手拍向$n的$l",
	"lvl" : 0,
	"skill_name" : "起手式"
]),
([  "action" : "$N右手微台，直出向前，一式「截手式」，疾向$n的$l击去",
	"lvl" : 10,
	"skill_name" : "截手式"
]),
([	"action" : "$N使一式「逆风式」，左掌微拂，右掌顺势而进，猛地插往$n的$l",
        "lvl" : 30,
	"skill_name" : "逆风式"
]),
([	"action" : "$N双掌隐隐泛出青气，一式「御气式」，掌风激劲，雨点般向$n击去",
        "lvl" : 40,
	"skill_name" : "御气式"
]),
([	"action" : "$N双掌不断反转，使出一式「潜手式」，双掌并拢，笔直地向$n的$l袭去",
        "lvl" : 50,
	"skill_name" : "潜手式"
]),

([	"action" : "$N身形一变，使一式「齐掌式」，双掌带着萧刹的劲气，猛地击往$n的$l",
        "lvl" : 60,
	"skill_name" : "齐掌式"
]),
([	"action" : "$N使一式「青烟式」，双掌如梦似幻，同时向$n的$l击去",
        "lvl" : 70,
	"skill_name" : "青烟式"
]),

([	"action" : "$N一式「流云式」，身法忽变，似流云飘忽，不觉已击到$n的$l上",
        "lvl" : 80,
	"skill_name" : "流云式"
]),
([	"action" : "$N突地一招「风雷式」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
        "lvl" : 100,
	"skill_name" : "风雷式"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="strike"; }
int valid_combine(string combo) { return combo=="luoyan-hand"; }

int valid_learn(object me)
{
	if(((int)me->query_skill("huiyan-xinfa", 1) < 15 ) )
		return notify_fail("你的本门内功还不够娴熟。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练碧罗掌必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练碧罗掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练碧罗掌。\n");
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
	int d_e1 = 15;
	int d_e2 = 50;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 30;
	int f_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("biluo-zhang", 1);
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

string perform_action_file(string action)
{
	return __DIR__"biluo-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n碧罗掌："NOR"\n");
	write(@HELP

    碧罗掌是衡山派的掌法。
    可与大落雁手互备。

	学习要求：
		回雁心法15级
		内力50
HELP
	);
	return 1;
}

