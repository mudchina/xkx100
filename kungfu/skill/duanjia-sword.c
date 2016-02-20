// duanjia-sword.c 段家剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N向前跨上一步，一招"HIB"「云横秦岭」"NOR"，手中$w自左向右向$n的$l缓缓划去",
	"lvl" : 0,
	"skill_name" : "云横秦岭"
]),
([	"action" : "$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式" GRN"「飞流直下」"NOR"直刺$n的$l",
	"lvl" : 9,
	"skill_name" : "飞流直下"
]),
([	"action" : "$N一招"BLU"「雪拥蓝关」"NOR"，$w闪起数道寒光，自下而上反挑$n的$l",
	"lvl" : 19,
	"skill_name" : "雪拥蓝关"
]),
([	"action" : "$N一招"RED"「奇兵突起」"NOR"，手中$w看似横扫实则斜劈，刺向$n的$l",
	"lvl" : 29,
	"skill_name" : "奇兵突起"
]),
([	"action" : "$N使出"HIB"「夜叉探海」"NOR"，$w挽出三个剑花，绵绵不断划向$n的$l",
	"lvl" : 39,
	"skill_name" : "夜叉探海"
]),
([	"action" : "$N一招"HIG"「泰山压顶」"NOR"，左手一捏剑诀，右手$w自上而下雷霆万钧般直向$n的$l劈了下去",
	"lvl" : 49,
	"skill_name" : "泰山压顶"
]),
([	"action" : "$N一招"MAG"「雨打梨花」"NOR"，身在半空，$w回抽，反手勾向$n的$l",
	"lvl" : 69,
	"skill_name" : "雨打梨花"
]),
([	"action" : "$N身影一晃, 绕到$n背后，一招"HIW"「逐鹿中原」"NOR"，剑尖向$n的$l疾挑",
	"lvl" : 89,
	"skill_name" : "逐鹿中原"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "staff") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		 return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20)
		 return notify_fail("你的枯荣禅功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		 || (string)weapon->query("skill_type") != "sword")
		 return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		 return notify_fail("你先歇口气再练吧。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -15;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 200;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duanjia-sword", 1);
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
		"damage_type" : random(2) ? "挫伤" : "刺伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"duanjia-sword/" + action;
}
int help(object me)
{
	write(HIC"\n段家剑："NOR"\n");
	write(@HELP

    段家剑是天南大理段家剑法。

	学习要求：
		枯荣禅功20级
		内力100
HELP
	);
	return 1;
}

