//shusha-zhang.c 朱砂掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「虚步推手」"NOR"，似掌非掌，双手一挥，直向$n的$l击去",
	"lvl"    : 0,
	"skill_name"  : "虚步推手"
]),
([	"action" : "$N身形一转，一式"BLU"「双封掌」"NOR"，左掌斜向外侧，掌心向下，封向$n的$l",
	"lvl"    : 20,
	"skill_name"  : "双封掌"
]),
([	"action" : "$N使一式"HIC"「破风穿云」"NOR"，身形前冲，双掌向前插出，直取$n的$l",
	"lvl"    : 40,
	"skill_name"  : "破风穿云"
]),
([	"action" : "$N两掌一分，一式"RED"「引针腰斩」"NOR"，左掌反擒$n的手部，右掌向$n的腰胁推劈",
	"lvl"    : 60,
	"skill_name"  : "引针腰斩"
]),
([	"action" : "$N右掌拍下，一式"GRN"「反摔掌」"NOR"，左掌以掌背反摔$n的头部",
	"lvl"    : 80,
	"skill_name"  : "反摔掌"
]),
([	"action" : "$N突然身形一缓，使出一式"MAG"「偷漏掌」"NOR"，右脚前扣，右掌向外圈手，又外向里拍向$n的$l",
	"lvl"    : 100,
	"skill_name"  : "偷漏掌"
]),
([	"action" : "$N使一式"HIG"「单臂挑山」"NOR"，右掌向下伸出，掌心翻转，猛地向上拍向$n的$l",
	"lvl"    : 120,
	"skill_name"  : "单臂挑山"
]),
([	"action" : "$N一声大喝，一招"HIG"「开门见山」"NOR"，招式沉稳，双掌暗红，迎面拍向$n的头部",
	"lvl"    : 150,
	"skill_name" : "开门见山"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练朱砂掌必须空手。\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 10)
		return notify_fail("你的归元吐纳法火候不够，无法学朱砂掌。\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("你的内力太弱，无法练朱砂掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练朱砂掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("zhusha-zhang")) > 60 &&
		(victim->query_condition("warm_poison") < 50))
		victim->apply_condition("warm_poison", random(me->query_skill("zhusha-zhang")/20) + 1 + victim->query_condition("warm_poison"));
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 120;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhusha-zhang", 1);
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
	write(HIC"\n朱砂掌："NOR"\n");
	write(@HELP

    朱砂掌是铁掌帮入门掌法。掌中蕴毒，帮中弟子在习得铁掌之前，
仗此游走江湖。

	学习要求：
		归元吐纳法10级
		内力修为20
HELP
	);
	return 1;
}

