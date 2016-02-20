// liehuo-jian.c 烈火剑
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
	"lvl" : 0,
	"skill_name" : "四海云飘",
]),
([	"action" : "$N一招「四通八达」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"lvl" : 19,
	"skill_name" : "四通八达",
]),
([	"action" : "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
	"lvl" : 29,
	"skill_name" : "在天一方",
]),
([	"action" : "$N身子向上弹起，左手下指，一招「怪蟒翻身」，右手$w带着一团剑花，逼向$n的$l",
	"lvl" : 39,
	"skill_name" : "怪蟒翻身",
]),
([	"action" : "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
	"lvl" : 59,
	"skill_name" : "飞瀑倒悬",
]),
([	"action" : "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
	"lvl" : 79,
	"skill_name" : "无声无色",
]),
([  "action" : "$N一招「万川归海」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
	"lvl" : 99,
	"skill_name" : "万川归海",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("就这么点内力还想学烈火剑法？\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 10)
		return notify_fail("你的九阳神功火候不够，学不了烈火剑法！\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 35 )
		return notify_fail("你的气不够练烈火剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 25;
	int p_e2 = 5;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("liehuo-jian", 1);
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
		"damage_type" : random(2) ? "劈伤" : "刺伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
//	return __DIR__"liehuo-jian/" + action;
}

int help(object me)
{
	write(HIR"\n烈火剑法："NOR"\n");
	write(@HELP

    烈火剑法是明教的剑法。

	学习要求：
		九阳神功10级
		内力修为10
HELP
	);
	return 1;
}

