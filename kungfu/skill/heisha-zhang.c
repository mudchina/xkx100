// heisha-zhang.c 黑砂掌
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「无常抖索」"NOR"，双手陡地一挥，已到$n的$l边上",
	"lvl"    : 0,
	"skill_name"  : "无常抖索"
]),
([	"action" : "$N身形一转，一式"BLU"「小鬼扶腰」"NOR"，左掌斜侧，右掌虚托，封向$n的腰部",
	"lvl"    : 20,
	"skill_name"  : "小鬼扶腰"
]),
([	"action" : "$N使一式"HIB"「夜叉破浪」"NOR"，身形前冲，双掌向前带着风声，尽力拍出，直取$n的$l",
	"lvl"    : 40,
	"skill_name"  : "夜叉破浪"
]),
([	"action" : "$N一式"BLU"「酆都冲沙」"NOR"，左右两掌往$n周身不绝连拍，虚实不定",
	"lvl"    : 60,
	"skill_name"  : "酆都冲沙"
]),
([	"action" : "$N左掌作势侧过，右掌顺势拍下，一式"BLU"「油锤灌顶」"NOR"，猛劈$n的头部",
	"lvl"    : 80,
	"skill_name"  : "油锤灌顶"
]),
([	"action" : "$N突然身形一顿，掌为腿先，掌腿相扣，正是"HIB"「沸鼎熬渣」"NOR"",
	"lvl"    : 100,
	"skill_name"  : "沸鼎熬渣"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黑砂掌必须空手。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 10)
		return notify_fail("你的红花神功火候不够，无法学黑砂掌。\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("你的内力太弱，无法练黑砂掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练黑砂掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("heisha-zhang")) > 60 &&
		(victim->query_condition("black_poison") < 50))
		victim->apply_condition("black_poison", random(me->query_skill("heisha-zhang")/20) + 1 + victim->query_condition("black_poison"));
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
	int d_e2 = 10;
	int p_e1 = 30;
	int p_e2 = 55;
	int f_e1 = 110;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("heisha-zhang", 1);
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
	write(HIC"\n黑砂掌："NOR"\n");
	write(@HELP

    黑砂掌是川西黑白无常常氏二杰的独门掌法。掌中蕴毒，无常夺命。

	学习要求：
		红花神功10级
		内力修为20
HELP
	);
	return 1;
}

