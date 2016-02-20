// xiangmo-chu.c 金刚降魔杵
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N高举手中$w，使出一招"HIY"「金刚再世」"NOR"，直劈$n的$l",
	"skill_name" : "金刚再世",
	"lvl" : 0
]),
([	"action" : "$N使出"HIY"「金刚伏魔」"NOR"，单手舞动$w，一伏身，$w横扫$n的下盘",
	"skill_name" : "金刚伏魔",
	"lvl" : 8
]),
([	"action" : "$N反身仰面，使出一式"HIY"「金刚宣法」"NOR"，双手握$w，一棍直刺$n的$l",
	"skill_name" : "金刚宣法",
	"lvl" : 16
]),
([	"action" : "$N使出一招"HIY"「引趣众生」"NOR"，双手举棍撩向$n的裆部",
	"skill_name" : "引趣众生",
	"lvl" : 24
]),
([	"action" : "$N舞动手中$w，使出"HIY"「歌舞阎罗」"NOR"，顿时罩住$n的全身",
	"skill_name" : "歌舞阎罗",
	"lvl" : 32
]),
([	"action" : "$N使出一招"HIY"「浮游血海」"NOR"，全身贴地而飞，一棍直捣$n的$l",
	"skill_name" : "浮游血海",
	"lvl" : 40
]),
([	"action" : "$N使出一式"HIY"「驱鬼御魔」"NOR"，以棍支地，双足飞揣$n的面门",
	"skill_name" : "驱鬼御魔",
	"lvl" : 48
]),
([	"action" : "$N运力于掌，使出"HIY"「荡魔除妖」"NOR"，飞身疾进，手中$w横扫$n的$l",
	"skill_name" : "荡魔除妖",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，练不了金刚降魔杵。\n");
	me->receive_damage("qi", 40);
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
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 190;
	int m_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xiangmo-chu", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "挫伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n金刚降魔杵："NOR"\n");
	write(@HELP

    金刚降魔杵为雪山寺器械武功。

	学习要求：
		龙象般若功或小无相功20级
		内力100
HELP
	);
	return 1;
}

