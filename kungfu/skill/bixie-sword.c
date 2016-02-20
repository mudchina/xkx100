// bixie-sword.c
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"HIM"「群邪辟易」"NOR"，手中$w圈起，倏地刺出，银星点点，剑尖直向$n的$l刺去",
	"lvl"    : 0,
	"skill_name" : "群邪辟易"
]),
([	"action" : "$N一招"HIB"「钟馗抉目」"NOR"，剑随身转，围着$n身围疾刺，剑光霍霍罩向$n的$l",
	"lvl"    : 10,
	"skill_name" : "钟馗抉目"
]),
([	"action" : "$N舞动$w，一招"MAG"「花开见佛」"NOR"挟著无数剑光刺向$n的$l",
	"lvl"    : 20,
	"skill_name": "花开见佛"
]),
([	"action" : "$N手中$w一声清啸，祭出"HIW"「流星赶月」"NOR"剑锋闪烁不定，银光飞舞，猛地里一剑挺出，直刺$n$l",
	"lvl"    : 30,
	"skill_name": "流星赶月"
]),
([	"action" : "$N手中$w剑光暴长，一招"GRN"「飞燕穿柳」"NOR"往$n$l刺去",
	"lvl"    : 40,
	"skill_name": "飞燕穿柳"
]),
([	"action" : "$N手中$w化成一道光弧，直指$n$l，一招"HIG"「江上弄笛」"NOR"发出虎哮龙吟刺去",
        "lvl"    : 50,
	"skill_name": "江上弄笛"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

int valid_learn(object me)
{
	object ob;

	if ( (string)me->query("gender")=="女性" )
		return notify_fail("女子不能学辟邪剑法。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练辟邪剑法。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习辟邪剑法！\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
//	write("你按著所学练了一遍辟邪剑法。\n");
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = 10;
	int p_e2 = 30;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 10;
	int m_e2 = 100;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("bixie-sword", 1);
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
int valid_effect(object me, object weapon, string name, int skill)
{
}

int help(object me)
{
	write(HIC"\n辟邪剑法："NOR"\n");
	write(@HELP

    辟邪剑法原自《葵花宝典》。请help bixie-jian。
    这套辟邪剑法是林震南传下的，由于祖训，且缺少练功的真正
法门，没有自宫，威力就大不如了。

	学习要求：
		女性不宜学
		内力100
HELP
	);
	return 1;
}

