// jinyu-quan.c 金玉拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一招"HIY"「金光灿烂」"NOR"，双拳一上一下, 向$n挥去",
	"lvl"    : 0,
	"skill_name" : "金光灿烂"
]),
([	"action" : "$N一招"MAG"「其利断金」"NOR"，幻出一片拳影，气势如虹，击向$n的头部",
	"lvl"    : 20,
	"skill_name" : "其利断金"
]),
([	"action" : "$N身影向上飘起，脸浮微笑，一招"BLU"「蓝田美玉」"NOR"，轻轻拍向$n的$l",
	"lvl"    : 40,
	"skill_name" : "蓝田美玉"
]),
([	"action" : "$N一招"HIC"「金玉其外」"NOR"，双拳一合，$n只觉到处是$N的拳影",
	"lvl"    : 60,
	"skill_name" : "金玉其外"
]),
([	"action" : "$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招
"GRN"「金玉满堂」"NOR"",
	"lvl"    : 80,
	"skill_name" : "金玉满堂"
]),
([	"action" : "只见$N一个侧身退步，左手虚晃，突然猛跨两步，已到$n面前，
右拳陡出，事先绝无征兆，迅如崩雷，一招"HIM"「点石成金」"NOR"击向$n的前胸",
	"lvl"    : 100,
	"skill_name" : "点石成金"
]),
([	"action" : "$N一招"CYN"「众口铄金」"NOR"，扑向$n，似乎$n的全身都被拳影笼罩",
	"lvl"    : 120,
	"skill_name" : "众口铄金"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="wuluo-zhang"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法练金玉拳。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金玉拳必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练金玉拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金玉拳。\n");
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 90;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinyu-quan", 1);
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
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n金玉拳："NOR"\n");
	write(@HELP

    金玉拳为天南大理段家的武功。
    可与五罗轻烟掌互备。

	学习要求：
		枯荣禅功20级
		内力100
HELP
	);
	return 1;
}

