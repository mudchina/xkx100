// chuanyun-shou.c 穿云手
// Last Modified by Sir on 5/19/2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIC"「穿云式」"NOR"，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"lvl" : 0,
	"skill_name" : "穿云式"
]),
([	"action" : "$N侧身一晃，一式"HIW"「开天式」"NOR"，左手拿向$n的肩头，右拳打向$n的胸口",
	"lvl" : 10,
	"skill_name" : "开天式"
]),
([	"action" : "$N一式"BLU"「夺剑式」"NOR"，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"lvl" : 20,
	"skill_name" : "夺剑式"
]),
([	"action" : "$N左手虚招，右掌直立，一式"GRN"「抚琴式」"NOR"，错步飘出，疾拍$n的面门",
	"lvl" : 30,
	"skill_name" : "抚琴式"
]),
([	"action" : "$N使一式"CYN"「流水式」"NOR"，左拳上格，右手探底突出，抓向$n的裆部",
	"lvl" : 38,
	"skill_name" : "流水式"
]),
([	"action" : "$N一式"HIM"「抱月式」"NOR"，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"lvl" : 51,
	"skill_name" : "抱月式"
]),
([	"action" : "$N双手抱拳，一式"HIY"「摘星式」"NOR"，掌影翻飞，同时向$n施出九九八十一招",
	"lvl" : 56,
	"skill_name" : "摘星式"
]),
([	"action" : "$N一式"HIR"「追日式」"NOR"，拳招若隐若现，若有若无，急急地拍向$n的丹田",
	"lvl" : 60,
	"skill_name" : "追日式"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tianchang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练穿云手必须空手。\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 20)
		return notify_fail("你的白云心法火候不够，无法学穿云手。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练穿云手。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e2 = -5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 90;
	int f_e2 = 190;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chuanyun-shou", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"chuanyun-shou/" + action;
}

int help(object me)
{
	write(HIC"\n穿云手："NOR"\n");
	write(@HELP

    穿云手为恒山派武功。
    可与天长掌互备。

	学习要求：
		白云心法20级
HELP
	);
	return 1;
}

