// liuhe-blade.c 四象六合刀

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一声长啸，手中$w一扬，一式天穹如盖将$n罩在刀光之下",
	"lvl"    : 0,
	"skill_name" : "天穹如盖",
]),
([	"action" : "$N一招"HIR"「乾坤倒转」"NOR"，手中$w在空中虚劈数下，突然下划割向$n的$l",
	"lvl"    : 20,
	"skill_name" : "乾坤倒转",
]),
([	"action" : "$N脚下急旋，踏遍四方八面，手中$w化做一道寒芒，上下飞舞。好一招两仪四象",
	"lvl"    : 40,
	"skill_name" : "两仪四象",
]),
([	"action" : "$N神色肃杀，一声虎吼，掌中刀光闪烁不定，一片刺骨的刀风将$n团团围住，"HIC"「气吞六合」"NOR"!",
	"lvl"    : 60,
	"skill_name" : "气吞六合",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 30)
		return notify_fail("你的混天气功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练四象六合刀法。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("liuhe-blade", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"liuhe-blade/" + action;
}

int help(object me)
{
	write(HIC"\n四象六合刀："NOR"\n");
	write(@HELP

    四象六合刀为丐帮的刀法。

	学习要求：
		混天气功30级
		内力50
HELP
	);
	return 1;
}

