// hamaquan.c
// Last Modified by winder on May. 15 2001
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「蛙鸣三起」"NOR"，以掌化爪，分袭$n的上中下三路要害",
	"lvl" : 0,
	"skill_name" : "蛙鸣三起"
]),
([	"action" : "$N左手虚晃，右手由前至后，反扣$n的肩井大穴",
	"lvl" : 8,
	"skill_name" : "反手点穴"
]),
([	"action" : "$N使一式"HIY"「前瞻后跳」"NOR"，人似蛤蟆状，半蹲而立，忽得扑向$n",
	"lvl" : 30,
	"skill_name" : "前瞻后跳"
]),
([	"action" : "$N使一式"HIW"「分身无影」"NOR"，四面八方出现无数掌影，一拳击向$n的胸口",
	"lvl" : 70,
	"skill_name" : "分身无影"
]),
([	"action" : "$N两手成爪像，全身咕噜作响，一式"HIR"「无敌蛤蟆」"NOR"，击向$n的$l",
	"lvl" : 98,
	"skill_name" : "无敌蛤蟆"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练蛤蟆拳必须空手。\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不够，无法学蛤蟆拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练蛤蟆拳手。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练蛤蟆拳。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 150;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamaquan", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hamaquan/" + action;
}

int help(object me)
{
	write(HIC"\n蛤蟆拳："NOR"\n");
	write(@HELP

    欧阳锋创立的白驼山派本门拳法。

	学习要求：
		蛤蟆功20级
		内力修为100
HELP
	);
	return 1;
}

