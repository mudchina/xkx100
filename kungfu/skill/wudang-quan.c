// wudang-quan.c 武当长拳
// Last Modified by Winder on Feb. 18 2001
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N力灌右臂，一招"RED"「七星手」"NOR"，一拳直出打向$n的$l",
	"lvl" : 0,
	"skill_name" : "七星手"
]),
([	"action" : "$N身行前探，闪身跨奔$n身侧，一招"HIB"「推手」"NOR"，向$n的$l推去",
	"lvl" : 10,
	"skill_name" : "推手"
]),
([	"action" : "$N双臂微曲，身行晃动，一招"HIM"「一条鞭」"NOR"守中带攻打向$n的$l",
	"lvl" : 20,
	"skill_name" : "一条鞭"
]),
([	"action" : "$N马步扎稳，左手虚晃，右手握拳一式"GRN"「直击」"NOR"迅猛打向$n的胸口",
	"lvl" : 40,
	"skill_name" : "直击"
]),
([	"action" : "$N施出"HIC"「雁回头」"NOR"，纵身跃向空中，双手同时击向$n的$l",
	"lvl" : 50,
	"skill_name" : "雁回头"
]),
([	"action" : "$N双臂回环，身行微微后仰，一招"HIW"「井栏」"NOR"，缠向$n的双手",
	"lvl" : 60,
	"skill_name" : "井栏"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练武当长拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 1)
		return notify_fail("你的太极神功火候不够，无法学武当长拳。\n");
	return 1;
}
int practice_skill(object me)
{
	int lvl = me->query_skill("wudang-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	me->receive_damage("qi", 20);
	return 1;
}
string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 120;
	int f_e2 = 220;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudang-quan", 1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n武当长拳："NOR"\n");
	write(@HELP

    武当长拳为武当派入门拳法。

	学习要求：
		太极神功1级
HELP
	);
	return 1;
}

