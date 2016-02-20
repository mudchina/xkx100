// songyang-strike.c 大嵩阳掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N身躯微欠，中宫一掌缓缓拍出，光明正大，是此套掌法的起首式"HIR"「大嵩阳」"NOR"",
	"lvl" : 0,
	"skill_name" : "大嵩阳"
]),
([	"action" : "$N忽拳忽掌，忽指忽抓，一式取自嵩山飞瀑的"HIC"「天河水」"NOR"，拍向$n的片刻间已变了十来种招数",
	"lvl" : 10,
	"skill_name" : "天河水"
]),
([	"action" : "$N大喝一声，使出一路大嵩阳掌法中的"BLU"「铁梁道」"NOR"，双掌上下翻飞、大开大阖，连续击向$n",
	"lvl" : 30,
	"skill_name" : "铁梁道"
]),
([	"action" : "$N运劲于臂，大吼一声"HIB"「万仞壑」"NOR"，左掌拍出，右手成抓，同时袭到，两股巨力排山倒海般向$n压了过来",
	"lvl" : 50,
	"skill_name" : "万仞壑",
]),
([	"action" : "$N运起丹田之气猛喝一声，一式"GRN"「观胜峰」"NOR"，右掌挟带着狂风，向前斜推，掌势如劈山排云搬压向$n",
	"lvl" : 70,
	"skill_name" : "观胜峰"
]),
([	"action" : "$N双手忽而抓，忽而戳，忽而拳，忽而掌，连变数种，使一套"MAG"「小铁梁」"NOR"手法，左手一晃，右掌向$n的$l按去",
	"lvl" : 90,
	"skill_name" : "小铁梁"
]),
([	"action" : "$N气沉丹田，猛然怒喝一声，向前一个弓步，双掌合成"HIM"「朝天闸」"NOR"，带着风雷之声奋力击向$n",
	"lvl" : 110,
	"skill_name" : "朝天闸"
]),
([	"action" : "$N右腿向前弓步，一招"CYN"「千丈渊」"NOR"，左手化拳为掌，劲气十足，闪电般地由上向下劈$n",
	"lvl" : 130,
	"skill_name" : "千丈渊"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="poyun-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大嵩阳掌必须空手。\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 10)
		return notify_fail("你的寒冰真气火候不够，无法学大嵩阳掌。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力太弱，无法练大嵩阳掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大嵩阳掌。\n");
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
	int d_e1 = -35;
	int d_e2 = -10;
	int p_e1 = 10;
	int p_e2 = 35;
	int f_e1 = 170;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songyang-strike", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"songyang-strike/" + action;
}

int help(object me)
{
	write(HIC"\n大嵩阳掌："NOR"\n");
	write(@HELP

    大嵩阳掌为嵩山派守山掌法。可与破云手互备。

	学习要求：
		寒冰真气10级
		内力10
HELP
	);
	return 1;
}

