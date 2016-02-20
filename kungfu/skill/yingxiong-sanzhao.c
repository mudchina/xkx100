// yingxiong-sanzhao.c 英雄三招
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$n抓住$N的后颈，一把提起。$N左手慢慢反转，在$n左腋底搔了一把，\n$n身子软了下来，$N左手拿住$n腋下，右手慢慢回转，抓住$n领口，缓缓\n举起$n的身子，过了自己头顶，向外摔出",
	"lvl" : 0,
	"skill_name" : "子胥举鼎",
]),
([	"action" : "$N俯伏地上，$n伸右足踏住$N的后腰，$N双腿一缩，似欲跪拜，\n右臂却慢慢横掠而出，突然间一个筋斗，向$n的胯下钻去，只一作势\n左手已抓住$n右脚足踝，右手向$n小腹击去",
	"lvl" : 10,
	"skill_name" : "鲁达拔柳",
]),
([	"action" : "$N双臂反在背后，突然双手十指弯起，各成半球之形，身子向后一撞\n十指便抓向$n的胸部，$n向后一缩，$N突然一个倒翻筋斗，身子跃起\n双腿一分，已跨在$n肩头，同时双手按指压住$n太阳穴，食指按眉，中指按眼",
	"lvl" : 20,
	"skill_name" : "狄青降龙",
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shenlong-bashi"; }
int valid_learn(object me)
{
	if (me->query_int() < 35)
		return notify_fail("你的悟性不够，无法学英雄三招。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学英雄三招。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 60)
		return notify_fail("你的毒龙大法火候不够，无法学英雄三招。\n");
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
	if ((int)me->query("qi") < 55)
		return notify_fail("你的力气太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练英雄三招。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 490;
	int f_e2 = 590;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yingxiong-sanzhao",1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yingxiong-sanzhao/" + action;
}

int help(object me)
{
	write(HIC"\n英雄三招"NOR"\n");
	write(@HELP

    英雄三招是神龙岛指法，取自三个英雄名。可与神龙八式互备。

	学习要求：
		毒龙大法60级
		内力修为100
		后天悟性35
HELP
	);
	return 1;
}

