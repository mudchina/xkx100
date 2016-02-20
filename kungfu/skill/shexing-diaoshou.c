// shexing-diaoshou.c 蛇形刁手
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「灵蛇出洞」"NOR"，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"lvl" : 0,
	"skill_name" : "灵蛇出洞"
]),
([	"action" : "$N侧身一晃，一式"HIY"「虎头蛇尾」"NOR"，左手拿向$n的肩头，右拳打向$n的胸口",
	"lvl" : 10,
	"skill_name" : "虎头蛇尾"
]),
([	"action" : "$N一式"MAG"「画蛇添足」"NOR"，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"lvl" : 20,
	"skill_name" : "画蛇添足"
]),
([	"action" : "$N左手虚招，右掌直立，一式"GRN"「杯弓蛇影」"NOR"，错步飘出，疾拍$n的面门",
	"lvl" : 30,
	"skill_name" : "杯弓蛇影"
]),
([	"action" : "$N使一式"HIB"「蛇行鼠窜」"NOR"，左拳上格，右手探底突出，抓向$n的裆部",
	"lvl" : 38,
	"skill_name" : "蛇行鼠窜"
]),
([	"action" : "$N一式"CYN"「蛇磐青竹」"NOR"，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"lvl" : 51,
	"skill_name" : "蛇磐青竹"
]),
([	"action" : "$N双手抱拳，一式"GRN"「万蛇汹涌」"NOR"，掌影翻飞，同时向$n施出九九八十一招",
	"lvl" : 56,
	"skill_name" : "万蛇汹涌"
]),
([	"action" : "$N一式"RED"「白蛇吐信」"NOR"，拳招若隐若现，若有若无，急急地拍向$n的丹田",
	"lvl" : 60,
	"skill_name" : "白蛇吐信"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="hamagong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练蛇形刁手必须空手。\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不够，无法学蛇形刁手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 35)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("你的内力不够练蛇形刁手。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -45;
	int d_e2 = -10;
	int p_e1 = 20;
	int p_e2 = 45;
	int f_e1 = 130;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shexing-diaoshou", 1);
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
	return __DIR__"shexing-diaoshou/" + action;
}

int help(object me)
{
	write(HIC"\n蛇形刁手："NOR"\n");
	write(@HELP

    蛇形刁手是白驼山派武功，是老毒物欧阳锋从蛇的蠕动中体会
出来的武功。

	学习要求：
		蛤蟆功20级
		内力100
HELP
	);
	return 1;
}

