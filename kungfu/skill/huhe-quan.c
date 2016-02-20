// huhe-quan.c 虎鹤双形拳
// Last Modified by Winder on Mar. 10 2000
// 主要用在没门派的npc身上

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N二手合十，一式「起首势」，双拳蓄势而发，击向$n的$l",
	"lvl" : 0,
	"skill_name" : "莲花座"
]),
([	"action" : "$N一式「虎形」，双掌轮流下击，拳势如焰，吡啪爆响",
	"lvl" : 10,
	"skill_name" : "虎形"
]),
([	"action" : "$N腾空飞起，一式「鹤形」，双手双腿齐出，令$n无可躲藏",
	"lvl" : 20,
	"skill_name" : "鹤形"
]),
([	"action" : "$N双掌虚含，掌缘下沉，一式「黑虎掏心」，缓缓向$n推出",
	"lvl" : 30,
	"skill_name" : "黑虎掏心"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「鹤度九天」，攻向$n的身前身后",
	"lvl" : 40,
	"skill_name" : "鹤度九天"
]),
([	"action" : "$N一式「白鹤点水」，两手十指虚点$n的全身三十六道要穴",
	"lvl" : 48,
	"skill_name" : "白鹤点水"
]),
([	"action" : "$N两目内视，双手内笼，一式「虎啸龙吟」，四面八方响起震人心魄的
龙吟",
	"lvl" : 54,
	"skill_name" : "虎啸龙吟"
]),
([	"action" : "$N似笑非笑，双拳无形无定，一式「猛虎下山」，骤然击向$n的前胸",
	"lvl" : 60,
	"skill_name" : "猛虎下山"
])
});

int valid_enable(string usage) { return	usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练虎鹤双形拳必须空手。\n");
	if ((int)me->query_skill("haoran-zhengqi", 1) < 10)
		return notify_fail("你的浩然正气火候不够，无法学虎鹤双形拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练虎鹤双形拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练虎鹤双形拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 60;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huhe-quan", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n虎鹤双形拳："NOR"\n");
	write(@HELP

    虎鹤双形拳是云中鹤的成名绝技。

	学习要求：
		无
HELP
	);
	return 1;
}

