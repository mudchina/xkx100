// mingwang-jian.c 不动明王剑
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N怒目圆睁，使出一招"HIB"「不动」"NOR"，手中$w一抖，直刺$n的$l",
	"skill_name" : "不动",
	"lvl" : 0
]),
([	"action" : "$N使出一式"HIW"「起手出剑」"NOR"，足下一滑，剑芒闪向$n的$l",
	"skill_name" : "起手出剑",
	"lvl" : 10
]),
([	"action" : "$N使出一招"HIY"「山崩」"NOR"，纵身跃入半空，$w如山崩般劈向$n的$l",
	"skill_name" : "山崩",
	"lvl" : 20
]),
([	"action" : "$N使出"HIC"「千旋转」"NOR"，将$w舞得如纺车一般，忽然一剑刺向$n的$l",
	"skill_name" : "千旋转",
	"lvl" : 30
]),
([	"action" : "$N使出一招"HIM"「降魔舞」"NOR"，全身劲气贯于$w中，剑气直指$n的$l",
	"skill_name" : "降魔舞",
	"lvl" : 40
]),
([	"action" : "$N单足独立，使出一式"MAG"「鹤舞」"NOR"，一道剑光如白影般向$n的$l扫去",
	"skill_name" : "鹤舞",
	"lvl" : 50
]),
([	"action" : "$N使出一招"GRN"「龙腾」"NOR"，手中$w如游龙般扑向$n的$l",
	"skill_name" : "龙腾",
	"lvl" : 60
]),
([	"action" : "$N飞身一跃，居高临下使出"BLU"「花雨满天」"NOR"，顿时剑尖如雨刺向$n的$l",
	"skill_name" : "花雨漫天",
	"lvl" : 80
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
//int valid_combine(string combo) { return combo=="xue-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("你的内力或气不够，练不了不动明王剑。\n");
	me->receive_damage("qi", 30);
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
	int d_e2 = 50;
	int p_e1 = 0;
	int p_e2 = 20;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 40;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("mingwang-jian", 1);
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
	write(HIC"\n不动明王剑："NOR"\n");
	write(@HELP

    雪域雪山寺剑法。

	学习要求：
		龙象功或小无相功20级
		内力100
HELP
	);
	return 1;
}

