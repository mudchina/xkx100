// meiren-sanzhao.c 美人三招
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

//inherit SKILL;

mapping *action = ({
([      "action" : "$N身子微曲，纤腰轻扭，左足反踢，向$n的小腹踢去，$n后缩相避，\n$N顺势反过身来，左手搂住$n头颈，右手握$w对准$n后心，一剑刺去",
	"lvl" : 0,
	"skill_name" : "贵妃回眸",
]),
([      "action" : "$N翻身卧倒，$n伸出右足踏住$N的后腰，$N的脑袋向着她自己的胸口钻落，\n顺势在地下一个筋斗，在$n的胯下钻过，右手握$w刺入$n的后心",
	"lvl" : 10,
	"skill_name" : "小怜横陈",
]),
([      "action" : "$N右足向前轻踢，顺势一勾，腿上的$w疾向$n的咽喉刺去",
	"lvl" : 20,
	"skill_name" : "飞燕回翔",
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_int() < 35)
		return notify_fail("你的悟性不够，无法学美人三招。\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学美人三招。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 60)
		return notify_fail("你的毒龙大法火候不够，无法学美人三招。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int practice_skill(object me)
{
        int level;
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("qi") < 30 || (int)me->query("jing") < 30 )
                return notify_fail("你的精气或气血太低了。\n");
        level = (int)me->query_skill("meiren-sanzhao", 1);
        if( level < 30 )
                return notify_fail("你对美人三招的掌握还不够。\n");
        if( level > 15 * (int)me->query("int") )
                return notify_fail("你的美人三招再也练不上去了。\n");

        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
        return 1;
}

mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = 25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("meiren-sanzhao",1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"meiren-sanzhao/" + action;
}

int help(object me)
{
	write(HIC"\n美人三招"NOR"\n");
	write(@HELP

    美人三招是神龙岛剑法，取自三个美人名。

	学习要求：
		毒龙大法60级
		内力修为100
		后天悟性35
HELP
	);
	return 1;
}

