// pomopima-jian.c 泼墨披麻剑法
// Last Modified by sir 11.1.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":       "$N使一招"HIW"「白虹贯日」"NOR"，手中$w轻飘飘地向$n的$l斩去！",
	"lvl" : 0,
	"skill_name" : "白虹贯日"
]),
([	"action":       "$N金刃劈风，$w随著一招"HIY"「腾蛟起风」"NOR"由下而上撩往$n的$l",
	"lvl" : 10,
	"skill_name" : "腾蛟起风"
]),
([	"action":       "$N身形一转，一招"GRN"「春风杨柳」"NOR"$w剑光不定，斩向$n的$l",
	"lvl" : 20,
	"skill_name" : "春风杨柳"
]),
([	"action":       "$N舞动$w，一招"CYN"「心驰神遥」"NOR"迅捷无伦地劈向$n的$l",
	"lvl" : 30,
	"skill_name" : "心驰神遥"
]),
([	"action":       "$N手中$w一晃，一招"HIG"「青山依旧」"NOR"往$n的$l斜斜砍出一剑",
	"lvl" : 40,
	"skill_name" : "青山依旧"
]),
([	"action":       "$N提剑过肩，蓄劲发力，一招"HIC"「玉龙倒悬」"NOR"直劈$n$l",
	"lvl" : 50,
	"skill_name" : "玉龙倒悬"
]),
([	"action":       "$N移步侧身，使一招"HIM"「漫山遍野」"NOR"剑光霍霍斩向$n的$l",
	"lvl" : 60,
	"skill_name" : "漫山遍野"
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry";}
int valid_learn(object me)
{
	if ((int)me->query_skill("kuihua-xinfa", 1) < 10)
		return notify_fail("你的葵花心法火候不够。\n");
	if(me->query("max_neili")<100)
		return notify_fail("你的内力修为不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑，才能练剑法。\n");

	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练这门剑法，还是先休息休息吧。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -10);
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
	int d_e1 = 30;
	int d_e2 = 55;
	int p_e1 = 5;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 125;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("pomopima-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n泼墨披麻剑法："NOR"\n");
	write(@HELP

    日月神教黑木崖武功，梅庄四庄主丹青生看家本领。

	学习要求：
		葵花心法10级
		内力100
HELP
	);
	return 1;
}
