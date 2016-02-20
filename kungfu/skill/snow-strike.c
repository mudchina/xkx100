// Last Modified by winder on Jul. 9 2001
// snow-strike.c
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":  "$N一招"+(order[random(13)])+"「梅林小酌」"NOR"，双手挥洒自如，轻飘飘地点向$n$l", 
	"lvl"    : 0,
	"skill_name" : "梅林小酌"
]),
([	"action":  "$N左拳平削，右拳自下划了个半弧，一招" +(order[random(13)])+"「梅妻鹤子」"NOR",疾取$n的$l",
	"lvl"    : 10,
	"skill_name" : "梅妻鹤子"
]),
([	"action":  "$N一招" +(order[random(13)])+"「急雪落梅」"NOR"，双掌如风中劲草，疾如流星般拍向$n$l",
	"lvl"    : 20,
	"skill_name" : "急雪落梅"
]),
([	"action":  "$N信手一招"+(order[random(13)])+"「霜雪漫天」"NOR"，散出森森寒气，罩向$n的$l",
	"lvl"    : 30,
	"skill_name" : "霜雪漫天"
]),
([	"action":  "$N使一招"+(order[random(13)])+"「余雪残梅」"NOR"，身随意转，随手拍向$n$l",
	"lvl"    : 40,
	"skill_name" : "余雪残梅"
]),
([	"action":  "$N长身一笑，纵身而起，一式" +(order[random(13)])+"「寒江飘梅」"NOR"，围绕$n的$l轻飘飘接连出掌",
	"lvl"    : 50,
	"skill_name" : "寒江飘梅"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练飞雪映梅掌必须空手。\n");
	if ((int)me->query_skill("bingxue-xinfa", 1) < 10)
		return notify_fail("你的冰雪心法修为太弱，无法练习。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力修为太弱，无法练习。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够了！休息一下再练吧。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 130;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("snow-strike", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"snow-strike/" + action;
}

int help(object me)
{
        write(HIC"\n飞雪映梅掌："NOR"\n");
        write(@HELP

    飞雪映梅掌是雪山派掌法。

        学习要求：
                冰雪心法10级
                内力10
HELP
        );
        return 1;
}

