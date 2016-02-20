// qishang-quan.c 七伤拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l",
	"lvl" : 0,
	"skill_name" : "金戈铁马"
]),
([	"action" : "$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出",
	"lvl" : 10,
	"skill_name" : "木已成舟"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
	"lvl" : 20,
	"skill_name" : "水中捞月"
]),
([	"action" : "$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡",
	"lvl" : 30,
	"skill_name" : "火海刀山"
]),
([	"action" : "$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n",
	"lvl" : 40,
	"skill_name" : "土载万物"
]),
([	"action" : "$N身形一转，一式「阴风惨惨」，攻向$n的身前身后",
	"lvl" : 48,
	"skill_name" : "阴风惨惨"
]),
([	"action" : "$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影",
	"lvl" : 54,
	"skill_name" : "阳光普照"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸",
	"lvl" : 60,
	"skill_name" : "七者皆伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 10)
		return notify_fail("你的九阳神功火候不够，无法学七伤拳。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练七伤拳。\n");
	if ((int)me->query_skill("qishang-quan", 1) > 199)
		return 1;
	if(!myfam || myfam["family_name"] != "明教" ||
		myfam["master_id"] != "xie xun")
		return notify_fail("七伤拳只能向金毛狮王学习。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练七伤拳。\n");
/*
	if ((int)me->query_skill("qishang-quan",1) % 20 == 0 &&
		(int)me->query_skill("qishang-quan",1) < 200)
		return notify_fail("你的七伤拳到了关键火候，怎么练都无法领悟。\n");
*/
	me->receive_damage("qi", 30);
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
	int d_e2 = 30;
	int p_e1 = -50;
	int p_e2 = -5;
	int f_e1 = 250;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qishang-quan", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n七伤拳："NOR"\n");
	write(@HELP

    七伤拳，拳出必伤。是崆峒派的不传之秘，但后来谢逊为报家
仇，从崆峒派手中盗出《七伤拳谱》，从而练成。名为七伤，实则
为每出一拳可以有七种不同内劲，使人不知如何与之相抗。

                    ┌──────────┐
                    │    七伤拳总诀      │
                    │  五行之气调阴阳，  │
                    │  损心伤肺摧肝肠，  │
                    │  藏离精失意恍惚，  │
                    │三焦齐逆兮魂魄飞    │
                    └──────────┘

	学习要求：
		只能向谢逊学习
		九阳神功20级
		内力200
HELP
	);
	return 1;
}

