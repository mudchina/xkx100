// Last Modified by Winder on May. 29 2001
// sanhua-strike.c 散花掌 和摩诃指互备。四季诗句截至前人。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N合掌抱球而开，一式「"HIG"春深芳草尽"NOR"」，掌力变幻吞吐，宛若春风抚体，缓缓飘向$n",
	"lvl"   : 0,
	"skill_name" : "春深芳草尽"
]),
([	"action" : "$N五指绽开，一式「"GRN"夏闲独兰馨"NOR"」，左右双掌穿插翻飞，活力四溅，劲风向$n疾飞而去",
	"lvl"   : 30,
	"skill_name" : "夏闲独兰馨"
]),
([	"action" : "$N一式「"HIY"秋酣菊霜清"NOR"」，左掌虚托，右掌乍伸乍合，如在风中摇摆，轻轻抚向$n$l",
	"lvl"   : 60,
	"skill_name" : "秋酣菊霜清"
]),
([	"action" : "$N双掌雪白，一式「"HIW"冬卧听梅吟"NOR"」，翻飞中掌尖幻成漫天梅花朵朵，雨点般向$n飘去",
	"lvl"   : 100,
	"skill_name" : "冬卧听梅吟"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="mohe-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练散花掌必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 30)
		return notify_fail("你的站桩功火候不够，无法学散花掌。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练散花掌。\n");
	if (me->query_skill("weituo-strike", 1) < 30)
		return notify_fail("你的韦陀掌火候不够，无法学散花掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练散花掌。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -25;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 45;
	int f_e1 = 140;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sanhua-strike", 1);
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
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"sanhua-strike/" + action;
}

int help(object me)
{
	write(HIC"\n散花掌："NOR"\n");
	write(@HELP

    散花掌是南少林掌法。和摩诃指互备。

	学习要求：
		站桩功30级
		韦陀掌30级
		内力修为200
HELP
	);
	return 1;
}

