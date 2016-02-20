// Last Modified by winder on Sep. 12 2001
// zhuhun-jian.c 追魂夺命剑

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一式"HIB"「无常抖索」"NOR"，手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
	"lvl"    : 0,
	"skill_name" : "无常抖索"
]),
([	"action" : "$N错步上前，使出"BLU"「煞神当道」"NOR"，剑意如虹，$w凶猛无匹地向$n的$l挥去",
	"lvl"    : 20,
	"skill_name" : "煞神当道"
]),
([	"action" : "$N一个斜身，一式"MAG"「望乡回顾」"NOR"，更不回头，倒转剑尖，手中$w向后刺向$n的$l",
	"lvl"    : 40,
	"skill_name" : "望乡回顾"
]),
([	"action" : "$N手中$w一沉，一式"HIB"「孟婆灌汤」"NOR"，无声无息地扎向$n的喉头",
	"lvl"    : 60,
	"skill_name" : "孟婆灌汤"
]),
([	"action" :"$N随风轻轻飘落，一式"BLU"「怨魂缠足」"NOR"，和身下扑，手中$w下指，疾刺$n的下三路",
	"lvl"    : 80,
	"skill_name" : "怨魂缠足"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("sword", 1) < 50)
		return notify_fail("你的红花神功火候太浅。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 50)
		return notify_fail("你的红花神功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练追魂夺命剑法。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 15;
	int d_e2 = 35;
	int p_e1 = -15;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 190;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhuihun-jian", 1);
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
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zhuihun-jian/" + action;
}
int help(object me)
{
	write(HIM"\n追魂夺命剑："NOR"\n");
	write(@HELP

    七十二路追魂夺命剑天下无双，是红花会二当家无尘道长的得意武功。

	学习要求：
		红花神功50级
		基本剑法50级
		内力修为300
HELP
	);
	return 1;
}
