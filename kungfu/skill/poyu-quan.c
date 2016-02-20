// poyu-quan.c 劈石破玉拳
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右脚立定、左脚虚点，一式「起手式」，左右手一高一低，击向$n的$l",
	"lvl" : 0,
	"skill_name" : "起手式"
]),
([	"action" : "$N左脚虚踏，全身右转，一招「石破天惊」，右拳猛地击向$n的$l",
	"lvl" : 10,
	"skill_name" : "石破天惊"
]),
([	"action" : "$N双手大开大阖，宽打高举，使一招「铁闩横门」，双拳向$n的$l打去",
	"lvl" : 20,
	"skill_name" : "铁闩横门"
]),
([	"action" : "$N左掌圈花扬起，屈肘当胸，右手虎口朝上，一招「千斤坠地」打向$n的$l",
	"lvl" : 30,
	"skill_name" : "千斤坠地"
]),
([	"action" : "$N使一招「傍花拂柳」，上身前探，双拳划了个半圈，击向$n的$l",
	"lvl" : 40,
	"skill_name" : "傍花拂柳"
]),
([	"action" : "$N双拳划弧，一记「金刚挚尾」，掌出如电，一下子切到$n的手上",
	"lvl" : 50,
	"skill_name" : "金刚挚尾"
]),
([	"action" : "$N施出「封闭手」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
	"lvl" : 60,
	"skill_name" : "封闭手"
]),
([	"action" : "$N左脚内扣，右腿曲坐，一式「粉石碎玉」，双拳齐齐捶向$n的胸口",
	"lvl" : 80,
	"skill_name" : "粉石碎玉"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「劈石破玉拳」必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候不够，无法学「劈石破玉拳」。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「劈石破玉拳」。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练「劈石破玉拳」。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = 20;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -20;
	int f_e1 = 160;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("poyu-quan", 1);
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
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"poyu-quan/" + action;
}
int help(object me)
{
	write(HIC"\n劈石破玉拳："NOR"\n");
	write(@HELP

    劈石破玉拳原为劈石及破玉两路拳法绝学，为华山武功。
    可与混元掌互备。

	学习要求：
		紫霞神功10级
		内力50
HELP
	);
	return 1;
}

