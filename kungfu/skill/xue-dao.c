// xue-dao.c 血刀
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N高举手中$w,使出一招"RED"「磨牙吮血」"NOR"，一刀斜劈$n的$l",
	"skill_name" : "磨牙吮血",
	"lvl" : 0,
]),
([	"action" : "$N就地一滚，使一招"HIR"「刺血满地」"NOR"，手中$w卷向$n的大腿",
	"skill_name" : "刺血满地",
	"lvl" : 8,
]),
([	"action" : "$N足尖一点，使出"RED"「血海茫茫」"NOR"，刀锋自上而下直插$n的$l",
	"skill_name" : "血海茫茫",
	"lvl" : 16,
]),
([	"action" : "$N使出一招"HIR"「呕心沥血」"NOR"，将$w舞得如白雾一般压向$n",
	"skill_name" : "呕心沥血",
	"lvl" : 24,
]),
([	"action" : "$N低吼一声，使出"RED"「血口喷人」"NOR"，举$w直劈$n的$l",
	"skill_name" : "血口喷人",
	"lvl" : 32,
]),
([	"action" : "$N使出"HIR"「血迹斑斑」"NOR"，飞身斜刺，忽然反手一刀横斩$n的腰部",
	"skill_name" : "血迹斑斑",
	"lvl" : 40,
]),
([	"action" : "$N使一式"RED"「以血还血」"NOR"，挥刀直指$n的胸口",
	"skill_name" : "以血还血",
	"lvl" : 48,
]),
([	"action" : "$N刀锋虚点，使出一招"HIR"「血流满面」"NOR"，转身举$w横劈$n的面门",
	"skill_name" : "血流漫面",
	"lvl" : 56,
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else return notify_fail("你的本门内功火候太浅。\n");
}
int practice_skill(object me)
{
	object weapon;

	if(!me->query_skill("longxiang",1) && !me->query_skill("xiaowuxiang",1))
		return notify_fail("练血刀必须要有雪山派的内功作为根基。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n"); 
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了「血刀」。\n");

	me->receive_damage("qi", 30);
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
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -35;
	int f_e1 = 100;
	int f_e2 = 200;
	int m_e1 = 150;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("xue-dao", 1);
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
		"damage_type" : random(2) ? "割伤" : "擦伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"xue-dao/" + action;
}
int help(object me)
{
	write(HIR"\n血刀："NOR"\n");
	write(@HELP

    血刀是藏边血刀门血刀老祖所传功夫。为雪山寺旁门功夫。

	学习要求：
		龙象般若功或小无相功20级
		内力50
HELP
	);
	return 1;
}

