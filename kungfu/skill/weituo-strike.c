// Last Modified by winder on May. 29 2001
// weituo-strike.c 韦陀掌 与如来千叶手互备

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双眼微睁，袍袖微微鼓气，双掌齐推，一招"HIC"「开天辟地」"NOR"，一股排山之势压向$n",
	"lvl"   : 0,
	"skill_name" : "开天辟地"
]),
([	"action" : "$N口中阿弥陀佛，一招"HIW"「即世即空」"NOR"，左掌击向$n面门，另一掌却按向$n的小腹",
	"lvl"   : 15,
	"skill_name" : "即世即空"
]),
([	"action" : "$N双掌互错，变幻莫测，一招"MAG"「无相无色」"NOR"，瞬息之间向$n攻出了三四一十二招",
	"lvl"   : 30,
	"skill_name" : "无相无色"
]),
([	"action" : "$N呼的一掌，没有半点征兆，一招"HIY"「佛法无边」"NOR"，猛地向$n的$l击打过去",
	"lvl"   : 40,
	"skill_name" : "佛法无边"
]),
([	"action" : "$N双掌交错，若有若无，一招"HIB"「谁入地狱」"NOR"，带着劲风拍向$n的肩头和前胸",
	"lvl"   : 50,
	"skill_name" : "谁入地狱"
]),
([	"action" : "$N一招"HIM"「禅心永明」"NOR"，右手一掌击出，紧接着右掌上一搭，击向$n的$l",
	"lvl"   : 60,
	"skill_name" : "禅心永明"
]),
([	"action" : "$N双手在空中齐划，跟着双掌齐推，一招"HIR"「我佛慈悲」"NOR"，一股排山倒海的掌力，直扑$n面门",
	"lvl"   : 70,
	"skill_name" : "我佛慈悲"
]),
([	"action" : "$N突然身行急转，一招"GRN"「苦海回头」"NOR"，掌影飞舞，霎时之间将$n四面八方都裹住了",
	"lvl"   : 80,
	"skill_name" : "苦海回头"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qianye-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练韦陀掌必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("你的站桩功火候不够，无法练韦陀掌。\n");
	if ((int)me->query_skill("luohan-cuff", 1) < 20)
		return notify_fail("你的罗汉拳火候不够，无法练韦陀掌。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练韦陀掌。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练韦陀掌。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-strike", 1);
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
	write(HIC"\n韦陀掌："NOR"\n");
	write(@HELP

    韦陀掌是南少林入门掌法。与如来千叶手互备。

	学习要求：
		站桩功20级
		罗汉拳20级
		内力修为50
HELP
	);
	return 1;
}

