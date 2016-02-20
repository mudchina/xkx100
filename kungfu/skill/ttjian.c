// yunlong-jian.c 云龙剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"\n$N使一式"GRN"「第一招」"NOR"，手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
	"lvl" : 0,
		"dodge"       : -100000,
		"parry"       : -100000,
		"force"       : 1,
		"damage"      : 1,
	"skill_name" : "悠悠顺自然"
]),
([	"action" : "$N募的使一招"HIR"「第二招」"NOR"，顿时剑光中几朵血花洒向$n全身",
		"dodge"       : 100000,
		"parry"       : 100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "红叶舞秋山"
]),
([	"action" : "$N募的使一招"HIR"「第三招」"NOR"，顿时剑光中几朵血花洒向$n全身",
		"dodge"       : -100000,
		"parry"       : 100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "红叶舞秋山"
]),
([	"action" : "$N募的使一招"HIR"「第四招」"NOR"，顿时剑光中几朵血花洒向$n全身",
		"dodge"       : 100000,
		"parry"       : -100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "红叶舞秋山"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("你的云龙神功火候太浅。\n");
	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
		return notify_fail("你的云龙心法火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("你的云龙神功火候太浅。\n");
	if( (int)me->query("qi") < 55 || (int)me->query("neili") < 40 )
		return notify_fail("你的内力或气不够练云龙剑法。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	return action[random(sizeof(action))];
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yunlong-jian/" + action;
}
int help(object me)
{
	write(HIC"\n云龙剑法："NOR"\n");
	write(@HELP

    天地会看家本领，其特殊攻击法威力奇大，堪称武林一绝。

	学习要求：
		基本内功40级
		云龙神功20级
		云龙心法20级
		内力200
HELP
	);
	return 1;
}

