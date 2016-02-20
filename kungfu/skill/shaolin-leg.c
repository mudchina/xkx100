// Last Modified by winder on May. 29 2001
// shaolin-leg.c 少林弹腿 与少林南拳互备

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"BLU"「落燕式」"NOR"，右腿支地，左腿画弧，直踢$n的头部",
	"lvl"    : 0,
	"skill_name" : "落燕式"
]),
([	"action" : "$N身形一闪，已从$n身边掠过，右足反踢，正是一招"HIW"「抚平式」"NOR"，踹向$n的背心",
	"lvl"    : 20,
	"skill_name" : "抚平式"
]),
([	"action" : "$N身体半蹲，右足画出个半圆，使出"HIC"「追月式」"NOR"，扫向$n的膝部",
	"lvl"    : 40,
	"skill_name" : "追月式"
]),
([	"action" : "$N上身微侧，左足倏地弹出，踢向$n的头部，裆部，正是一式"GRN"「连环式」"NOR"",
	"lvl"    : 60,
	"skill_name" : "连环式"
]),
([	"action" : "$N右足独立，左足随身形反转横扫，又左足立定，右足横扫向前，一招"HIG"「扫叶式」"NOR"，踢向$n的$l",
	"lvl"    : 80,
	"skill_name" : "扫叶式"
]),
([	"action" : "$N跃起在半空，双足乱舞，带起无数劲风，"HIY"「盘龙式」"NOR"！迅捷无伦地卷向$n",
	"lvl"    : 100,
	"skill_name" : "盘龙式"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shaolin-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学少林弹腿时手里不能拿武器。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 1)
		return notify_fail("你的站桩功火候不够，无法学少林弹腿。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练少林弹腿。\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -30;
	int d_e2 = 0;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shaolin-leg", 1);
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

int help(object me)
{
	write(HIC"\n少林弹腿："NOR"\n");
	write(@HELP

    弹腿是南少林入门腿法，注重腿法练习。

	学习要求：
		站桩功
HELP
	);
	return 1;
}

