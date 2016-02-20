// songshan-sword.c 嵩山剑法
// Last Modified by winder on Mar. 10 2000
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "万岳朝宗",
	"action" : "$N右手$w一立，举剑过顶，弯腰躬身，使一招"HIY"「万岳朝宗」"NOR"正是\n嫡系正宗的嵩山剑法",
	"lvl" : 0
]),
([	"skill_name" : "开门见山",
	"action" : "$N左手向外一分，右手$w向右掠出，使的是嵩山派剑法"HIG"「开门见\n山」"NOR"",
	"lvl" : 10
]),
([	"skill_name" : "独劈华山",
	"action" : "$N手中$w自上而下的向$n直劈下去，一招"HIB"「独劈华山」"NOR"，真有石\n破天惊的气势，将嵩山剑法之所长发挥得淋漓尽致",
	"lvl" : 20
]),
([	"skill_name" :"千古人龙",
	"action" : "$N手中$w突然间剑光一吐，化作一道白虹，端严雄伟，端丽飘逸，\n正是嵩山剑法的精要所在，一招"RED"「千古人龙」"NOR"向$n$l直刺过来",
	"lvl" : 30
]),
([	"skill_name" :"叠翠浮青",
	"action" : "$N手中$w突然间剑光一吐，一招"GRN"「叠翠浮青」"NOR"化成一道青光，气\n壮雄浑，向$n$l直刺过来",
	"lvl" : 40
]),
([	"skill_name" : "玉井天池",
	"action" : "$N手中$w剑光一吐，一招"HIW"「玉井天池」"NOR"威仪整肃，端严雄伟，向\n$n$l直刺过来",
	"lvl" : 50
]),
([	"skill_name" : "天外玉龙",
	"action" : "$N手中$w刷的一剑自左而右急削过去，正是一招嵩山派正宗剑法\n"HIC"「天外玉龙」"NOR"。奔腾矫夭，气势雄浑。但见$w自半空中横过，剑身似曲似\n直，长剑便如一件活物一般",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练嵩山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
		return notify_fail("嵩山剑法必须配合寒冰真气才能练。\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没法练习嵩山剑法。\n");
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
	int d_e1 = 5;
	int d_e2 = 25;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 120;
	int m_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songshan-sword", 1);
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

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"songshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n嵩山剑法："NOR"\n");
	write(@HELP

    嵩山剑法是五岳盟主、嵩山掌门左冷禅整理本派剑谱，集其大
成，重新厘定的剑法。

	学习要求：
		寒冰真气
		内力50
HELP
	);
	return 1;
}

