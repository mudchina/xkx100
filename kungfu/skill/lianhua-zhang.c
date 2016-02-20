// lianhua-zhang.c 莲花掌
// Last Modified by qingyun 2005.1.9

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使出莲花掌起手势「小莲初绽」，左掌护胸，右掌缓缓拍向$n的$l",
	"lvl" : 0,
	"skill_name" : "小莲初绽"
]),
([	"action" : "$N后退一步，右手护胸，左手一记「千叶莲花」劈出一道掌风，直奔$n的$l",
	"lvl" : 20,
	"skill_name" : "千叶莲花"
]),
([	"action" : "$N一式「雨打莲花」飞身跃起直扑$n，双掌幻化出数十个掌影，快如雨点击向$n",
	"lvl" : 40,
	"skill_name" : "雨打莲花"
]),
([	"action" : "$N面露微笑，一招「叶底清荷」左掌一摆，右掌划出一道美妙的弧线，直切$n的$l",
	"lvl" : 80,
	"skill_name" : "叶底清荷"
]),
([	"action" : "$N使出「双莲争艳」，双掌飞快舞动，将$n圈在掌风之内，在眼花缭乱间骤然拍出",
	"lvl" : 100,
	"skill_name" : "双莲争艳"
]),
([	"action" : "$N双手微张缓缓前探，双臂伸直后突然变化为掌，一式「莲池泛舟」摆向$n的$l",
	"lvl" : 120,
	"skill_name" : "莲池泛舟"
]),
([	"action" : "$N绕着$n快速游走，使出「遍野荷香」手掌如穿花蝴蝶般上下飞舞，罩向$n的$l",
	"lvl" : 140,
	"skill_name" : "遍野荷香"
]),
([	"action" : "刹那间$N反身错步，突然使出一招「雨后清莲」，猛一掌便向$n的$l劈去",
	"lvl" : 160,
	"skill_name" : "雨后清莲"
]),
([	"action" : "$N右掌护胸，左掌在面前一晃，突地从腋下穿出，一式「旧藕新莲」直拍$n$l",
	"lvl" : 180,
	"skill_name" : "旧藕新莲"
]),
([	"action" : "只见$N使一招「藕断丝连」，左掌晃动着平举，右掌摇摆不定中画个圆圈拍向$n",
	"lvl" : 200,
	"skill_name" : "藕断丝连"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="suohou-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练莲花掌必须空手。\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("你的混天气功火候不够，无法学莲花掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练莲花掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练莲花掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
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
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 210;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lianhua-zhang", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point() { return 1.0; }

int help(object me)
{
	write(HIC"\n莲花掌："NOR"\n");
	write(@HELP

    莲花掌为洪七公绝技之一。
    可与锁喉擒拿手互备。

	学习要求：
		混天气功20级
		内力100
HELP
	);
	return 1;
}

