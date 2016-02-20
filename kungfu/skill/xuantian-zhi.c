// xuantian-zhi.c 玄天无情指
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N左指挥出，一式"BLU"「黯然消魂」"NOR"，削向$n的掌缘",
	"lvl" : 0,
	"skill_name" : "黯然消魂"
]),
([	"action" : "$N全身之力聚于一指，一式"HIC"「天似无情」"NOR"，指向$n的胸前",
	"lvl" : 15,
	"skill_name" : "天似无情"
]),
([	"action" : "$N左掌贴于神道穴，右手一式"MAG"「情根深种」"NOR"，向$n的$l划过",
	"lvl" : 25,
	"skill_name" : "情根深种"
]),
([	"action" : "$N双目怒视，一式"CYN"「情在天涯」"NOR"，双指拂向$n的额、颈、肩、臂、胸
、背",
	"lvl" : 45,
	"skill_name" : "情在天涯"
]),
([	"action" : "$N一式"HIR"「独饮情伤」"NOR"，左掌掌心向外，右指蓄势点向$n的$l",
	"lvl" : 60,
	"skill_name" : "独饮情伤"
]),
([	"action" : "$N右手伸出，十指叉开，一式"HIW"「无诉别情」"NOR"，小指拂向$n的太渊穴",
	"lvl" : 70,
	"skill_name" : "无诉别情"
]),
([	"action" : "$N双迸出无数道劲气，一式"HIG"「情意绵绵」"NOR"射向$n的全身",
	"lvl" : 80,
	"skill_name" : "情意绵绵"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练玄天无情指必须空手。\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 80)
		return notify_fail("你的葵花心法火候不够，无法学玄天无情指。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练玄天无情指。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("jing") < 40)
		return notify_fail("你的精太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练玄天无情指。\n");
	me->receive_damage("jing", 35);
	me->add("neili", -15);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("xuantian-zhi")) > 60 &&
		(victim->query_condition("cold_poison") < 50))
		victim->apply_condition("cold_poison", random(me->query_skill("xuantian-zhi")/20) + 1 + victim->query_condition("cold_poison"));
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
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 240;
	int f_e2 = 340;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xuantian-zhi", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n玄天无情指："NOR"\n");
	write(@HELP

    日月神教黑木崖武功。梅庄二庄主黑白子的凌厉指法，招数中
带有阴寒内劲，可伤人于无形之中。

	学习要求：
		葵花心法80级
		内力150
HELP
	);
	return 1;
}


