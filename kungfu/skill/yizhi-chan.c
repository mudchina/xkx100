// yizhi-chan.c 一指禅
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双指并拢，一式"HIY"「佛恩济世」"NOR"，和身而上，左右手一前一后戳向$n的胸腹间",
	"lvl" : 0,
	"skill_name" : "佛恩济世"
]),
([	"action" : "$N左掌护胸，一式"HIY"「佛光普照」"NOR"，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
	"lvl" : 20,
	"skill_name" : "佛光普照"
]),
([	"action" : "$N身形闪动，一式"HIY"「佛门广渡」"NOR"，双手食指端部各射出一道青气，射向$n的全身要穴",
	"lvl" : 40,
	"skill_name" : "佛门广渡"
]),
([	"action" : "$N盘膝跌坐，一式"HIY"「佛法无边」"NOR"，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
	"lvl" : 60,
	"skill_name" : "佛法无边"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一指禅必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学一指禅。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练一指禅。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练一指禅。\n");
	me->receive_damage("qi", 40);
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
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -15;
	int f_e1 = 360;
	int f_e2 = 460;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yizhi-chan", 1);
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
	return __DIR__"yizhi-chan/" + action;
}

int help(object me)
{
	write(HIC"\n一指禅："NOR"\n");
	write(@HELP

    一指禅为少林七十二绝技之一。
    可与般若掌互备。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

