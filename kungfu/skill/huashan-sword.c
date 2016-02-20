// huashan-sword.c
// Modified by Venus Oct.1997
//气宗,重force .

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "有凤来仪",
	"action": "$N使一招"HIM"「有凤来仪」"NOR"，手中$w剑光暴长，向$n的$l刺去",
	"lvl" : 0
]),
([	"skill_name" :"无边落木",
	"action": "$N剑随身转，一招"GRN"「无边落木」"NOR"罩向$n的$l",
	"lvl" : 10
]),
([	"skill_name" :"鸿飞冥冥",
	"action": "$N舞动$w，一招"BLU"「鸿飞冥冥」"NOR"挟著无数剑光刺向$n的$l",
	"lvl" : 20
]),
([	"skill_name" :"平沙落雁",
	"action": "$N手中$w龙吟一声，祭出"HIY"「平沙落雁」"NOR"往$n的$l刺出数剑",
	"lvl" : 30
]),
([	"skill_name" :"金玉满堂",
	"action": "$N手中$w剑光暴长，一招"RED"「金玉满堂」"NOR"往$n$l刺去",
	"lvl" : 40
]),
([	"skill_name" :"白虹贯日",
	"action": "$N手中$w化成一道光弧，直指$n$l，一招"HIW"「白虹贯日」"NOR"发出虎哮龙吟刺去",
	"lvl" : 50
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练华山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("华山剑法必须配合紫霞神功才能练。\n");
	if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你内力或气不够，没有办法练习华山剑法。\n");
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
	int d_e1 = 0;
	int d_e2 = 25;
	int p_e1 = -25;
	int p_e2 = -10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 120;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huashan-sword", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"huashan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n华山剑法："NOR"\n");
	write(@HELP

    华山剑法为华山气宗剑法。

	学习要求：
		紫霞神功
		内力50
HELP
	);
	return 1;
}

