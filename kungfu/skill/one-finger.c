// Last Modified by winder on May. 29 2001
// one-finger.c 一指禅 不可互备 取自佛教《大般若经》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双指并拢，一式"MAG"「道行般若」"NOR"，和身缓缓而上，左右手一前一后弹向$n$l",
	"lvl"   : 0,
	"skill_name" : "道行般若"
]),
([	"action" : "$N左掌护胸，含笑一式"GRN"「小品般若」"NOR"，右手中指前后划了个半弧，轻轻一甩，点向$n$l",
	"lvl"   : 20,
	"skill_name" : "小品般若"
]),
([	"action" : "$N身形闪动，一式"HIW"「光赞般若」"NOR"，双手食指端部各射出一道青光，射向$n的全身要穴",
	"lvl"   : 40,
	"skill_name" : "光赞般若"
]),
([	"action" : "$N盘膝跌坐，一式"HIC"「放光般若」"NOR"，全身罡气密布，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
	"lvl"   : 60,
	"skill_name" : "放光般若"
]),
([	"action" : "$N面露宝相，结兰花手，轻轻一下点出"GRN"「摩诃般若」"NOR"，凭空凝气成线，缓缓刺向$n",
	"lvl"   : 100,
	"skill_name" : "摩诃般若"
]),
([	"action" : "$N口念佛经，内息激发，衣衫渐渐胀鼓，身若金刚，便立指一式"HIY"「金刚般若」"NOR"，对着$n点去",
	"lvl"   : 150,
	"skill_name" : "金刚般若"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一指禅必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 100)
		return notify_fail("你的站桩功火候不够，无法学一指禅。\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的内力太弱，无法练习一指禅。\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("boruo-strike", 1) < 50) )
		return notify_fail("你的拈花指和般若掌火候不够，无法学一指禅。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练一指禅。\n");
	me->receive_damage("qi", 55);
	me->add("neili", -25);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 330;
	int f_e2 = 430;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("one-finger", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"one-finger/" + action;
}

int help(object me)
{
	write(HIC"\n一指禅："NOR"\n");
	write(@HELP

    一指禅是南少林高级指法，出自佛教《大般若经》。

	学习要求：
		站桩功100级
		拈花指50级
		般若掌50级
		内力修为1200
HELP
	);
	return 1;
}

