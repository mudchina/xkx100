//kuangfeng-jian 狂风快剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N纵身跃起手中$w轻挥，斩向$n后颈",
	"lvl"    : 0,
	"skill_name" : "风平浪静"
]),
([	"action" : "$N手中$w连话三个弧形，向$n的右臂齐肩斩落",
	"lvl"    : 20,
	"skill_name" : "风起云涌"
]),
([	"action" : "$N轻吁一声，刷刷刷刷四剑，向$n胸，腹，腰，肩四处连刺",
	"lvl"    : 40,
	"skill_name" : "风卷残云"
]),
([	"action" : "$N仰天一声清啸，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
	"lvl"    : 60,
	"skill_name" : "风流云散"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("huashan-neigong", 1) < 60)
		return notify_fail("你的内功心法火候太浅。\n");
	if ((int)me->query_skill("dodge", 1) < 60)
		return notify_fail("你的轻功火候太浅。\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("你的身法还不够灵活。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练狂风快剑。\n");
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
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 80;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kuangfeng-jian", 1);
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
	return __DIR__"kuangfeng-jian/" + action;
}
int help(object me)
{
	write(HIC"\n狂风快剑："NOR"\n");
	write(@HELP

    狂风快剑为华山剑宗的剑法。
    这套“狂风快剑”，是封不平在中条山隐居十五年而创制出来
的得意剑法，剑招一剑快似一剑。他胸怀大志，不但要执掌华山一
派，还想成了华山派掌门人之后，更进而为五岳剑派盟主，所凭持
的便是这套一百零八式“狂风快剑”。

	学习要求：
		华山内功60级
		基本轻功60级
		后天身法25以上
		内力300
HELP
	);
	return 1;
}

