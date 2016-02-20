// tanzhi.c 弹指神通
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右指划了个半圈，一式"CYN"「划天裂地」"NOR"自上而下划向$n的全身",
	"lvl" : 0,
	"skill_name" : "划天裂地"
]),
([	"action" : "$N左掌护胸，一招"BLU"「我心悠悠」"NOR"，右指欲举无力指向$n的额头",
	"lvl" : 10,
	"skill_name" : "我心悠悠"
]),
([	"action" : "$N双手齐出，一式"YEL"「千夫所指」"NOR"，疾指向$n的$l",
	"lvl" : 20,
	"skill_name" : "千夫所指"
]),
([	"action" : "$N仰天一叹，一招"RED"「弹指人生」"NOR"，双手幻出重重指影，点向$n的$l",
	"lvl" : 30,
	"skill_name" : "弹指人生"
]),
([	"action" : "$N一式"GRN"「笑指天南」"NOR"，左掌蓄式，右指弹出一缕指风点向$n的$l",
	"lvl" : 40,
	"skill_name" : "笑指天南"
]),
([	"action" : "$N用出"HIY"「擎天一指」"NOR"，蓄集全身力气，一指点向$n的$l",
	"lvl" : 50,
	"skill_name" : "擎天一指"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="lanhua-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练弹指神通必须空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不够，无法学弹指神通。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练弹指神通。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够，休息一下再练吧。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练弹指神通。\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 300;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tanzhi-shentong", 1);
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
		"damage_type" : random(2) ? "刺伤" : "瘀伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}
int help(object me)
{
	write(HIC"\n弹指神通："NOR"\n");
	write(@HELP

    东海桃花岛主黄药师的成名绝技。
    可与兰花拂穴手互备。

	学习要求：
		碧波神功20级
		内力100
HELP
	);
	return 1;
}

