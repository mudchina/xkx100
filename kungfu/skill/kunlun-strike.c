// kunlun-strike.c 昆仑掌

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N掌风激荡，双掌错落，来势神妙无方，一招"HIY"「日入空山」"NOR"，劈向$n的$l",
	"lvl" : 0,
	"skill_name" : "日入空山"
]),
([	"action" : "$N双掌骤起，一招"HIC"「天清云淡」"NOR"，一掌击向$n面门，另一掌却按向$n小腹",
	"lvl" : 20,
	"skill_name" : "天清云淡"
]),
([	"action" : "$N双掌互错，变幻莫测，一招"HIC"「秋风不尽」"NOR"，前后左右，瞬息之间向$n攻出了四四一十六招",
	"lvl" : 38,
	"skill_name" : "秋风不尽"
]),
([	"action" : "$N一声清啸，呼的一掌，一招"HIB"「山回路转」"NOR"，自巧转拙，却是去势奇快，向$n的$l猛击过去，",
	"lvl" : 55,
	"skill_name" : "山回路转"
]),
([	"action" : "$N双掌交错，若有若无，一招"BLU"「天衣无缝」"NOR"，拍向$n的$l",
	"lvl" : 72,
	"skill_name" : "天衣无缝"
]),
([	"action" : "$N一招"GRN"「青山断河」"NOR"，右手一拳击出，左掌紧跟着在右拳上一搭，变成双掌下劈，击向$n的$l",
	"lvl" : 87,
	"skill_name" : "青山断河"
]),
([	"action" : "$N双手齐划，跟着双掌齐推，一招"MAG"「北风卷地」"NOR"，一股排山倒海的掌力，直扑$n面门",
	"lvl" : 101,
	"skill_name" : "北风卷地"
]),
([	"action" : "$N突然滴溜溜的转身，一招"HIW"「天山雪飘」"NOR"，掌影飞舞，霎时之间将$n四面八方都裹住了",
	"lvl" : 120,
	"skill_name" : "天山雪飘"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	mapping fam = me->query("family");
	if (fam["family_name"] != "昆仑派" || fam["generation"] != 2)
		return notify_fail("昆仑掌只能从何足道处学到。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练昆仑掌必须空手。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 120)
		return notify_fail("你的玄天无极功火候不够，无法练昆仑掌。\n");
	if(me->query("gender")!="女性")
	{
		if ((int)me->query_skill("zhentian-cuff", 1) < 80)
			return notify_fail("你的相关功夫火候不够，无法练昆仑掌。\n");
	} else
	{
		if ((int)me->query_skill("chuanyun-leg", 1) < 80)
			return notify_fail("你的相关功夫火候不够，无法练昆仑掌。\n");
	}
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力修为不够，无法练昆仑掌。\n");
	return 1;
}
int practice_skill(object me)
{
	int lvl = me->query_skill("kunlun-strike", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练昆仑掌。\n");
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
	int d_e1 = -30;
	int d_e2 = -10;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 160;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kunlun-strike", 1);
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
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kunlun-strike/" + action;
}

int help(object me)
{
	write(HIC"\n昆仑掌法："NOR"\n");
	write(@HELP

    昆仑掌法为昆仑派上乘绝技。

	学习要求：
		玄天无极功120级
		震天拳法或穿云腿80级
		内力800
		何足道的嫡传弟子
HELP
	);
	return 1;
}

