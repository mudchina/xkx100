// Last Modified by Winder on May. 29 2001
// nianhua-finger.c 拈花指 和鹰爪功互备 取自如来十大弟子名。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N侧身抬臂，右指钩了个半圈，一式"HIB"「优婆离式」"NOR"轻轻一弹，击向$n的$l",
	"lvl"    : 0,
	"skill_name" : "优婆离式"
]),
([	"action" : "$N左掌虚托胸前，一招"HIY"「须菩提式」"NOR"，右指穿腋而出，不紧不缓，点向$n的$l",
	"lvl"    : 10,
	"skill_name" : "须菩提式"
]),
([	"action" : "$N面带微笑，俯身斜倚，左手驻起气墙，右手一式"HIM"「阿难式」"NOR"，向$n$l轻点",
	"lvl"    : 20,
	"skill_name" : "阿难式"
]),
([	"action" : "$N双目微睁，面露轻笑，一式"HIG"「迦叶式」"NOR"，幻化出千百个指影，拂向$n$l",
	"lvl"    : 30,
	"skill_name" : "迦叶式"
]),
([	"action" : "$N一式"MAG"「金蝉子式」"NOR"，左掌护住丹田，右手斜指苍天蓄势，接着才缓缓点向$n$l",
	"lvl"    : 40,
	"skill_name" : "金蝉子式"
]),
([	"action" : "$N微笑之中提双掌平托胸前，十指叉开，一式"CYN"「侨陈如式」"NOR"，指向$n的周身大穴",
	"lvl"    : 60,
	"skill_name" : "侨陈如式"
]),
([	"action" : "$N双掌翻飞，一式"RED"「阿金婆誓式」"NOR"，微笑中于指端迸出数道柔劲，点向$n",
	"lvl"    : 80,
	"skill_name" : "阿金婆誓式"
]),
([	"action" : "$N一招"HIC"「摩诃跋提式」"NOR"，并指如柳，化出一束束细柔的气劲，凌虚向$n的$l点去",
	"lvl"    : 110,
	"skill_name" : "摩诃跋提式"
]),
([	"action" : "$N一招"HIM"「十力伽叶式」"NOR"，轻笑一声，双手食指交叉，指端挑出一缕罡气，轻轻抚向$n$l",
	"lvl"    : 130,
	"skill_name" : "十力伽叶式"
]),
([	"action" : "$N左掌竖立胸前，一式"HIR"「摩男俱利式」"NOR"，微笑中右手食指扣住拇指，轻轻对着$n一弹",
	"lvl"    : 150,
	"skill_name" : "摩男俱利式"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo){ return combo=="eagleg-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练拈花指必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("你的站桩功火候不够，无法学拈花指。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太弱，无法练拈花指。\n");
	if ((me->query_skill("duoluoye-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金刚神掌和多罗叶指火候不够，无法学拈花指。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的力气太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练拈花指。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 35;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = -5;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("nianhua-finger", 1);
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
	return __DIR__"nianhua-finger/" + action;
}

int help(object me)
{
	write(HIC"\n拈花指："NOR"\n");
	write(@HELP

    拈花指是南少林指法，和鹰爪功互备，取自如来十大弟子名。

	学习要求：
		站桩功60级
		大金刚神掌50级
		多罗叶指50级
		内力修为600
HELP
	);
	return 1;
}

