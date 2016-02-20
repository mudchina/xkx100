// huashan-zhangfa.c 华山掌法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIW"「白云出岫」"NOR"，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
	"lvl" : 0,
	"skill_name" : "白云出岫"
]),
([	"action" : "$N并指如剑，一式"HIW"「白虹贯日」"NOR"，疾向$n的$l戳去",
	"lvl" : 10,
	"skill_name" : "白虹贯日"
]),
([	"action" : "$N使一式"HIB"「云断秦岭」"NOR"，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
	"lvl" : 20,
	"skill_name" : "云断秦岭"
]),
([	"action" : "$N双掌隐隐泛出青气，一式"GRN"「青松翠翠」"NOR"，幻成漫天碧绿的松针，雨点般向$n击去",
	"lvl" : 30,
	"skill_name" : "青松翠翠"
]),
([	"action" : "$N身形往上一纵，使出一式"HIC"「天绅倒悬」"NOR"，双掌并拢，笔直地向$n的$l插去",
	"lvl" : 40,
	"skill_name" : "天绅倒悬"
]),
([	"action" : "$N身形一变，使一式"MAG"「无边落木」"NOR"，双掌带着萧刹的劲气，猛地击往$n的$l",
	"lvl" : 50,
	"skill_name" : "无边落木"
]),
([	"action" : "$N使一式"HIG"「高山流水」"NOR"，左掌凝重，右掌轻盈，同时向$n的$l击去",
	"lvl" : 60,
	"skill_name" : "高山流水"
]),
([	"action" : "$N突地一招"RED"「金玉满堂」"NOR"，双掌挟着一阵风雷之势，猛地劈往$n的$l",
	"lvl" : 70,
	"skill_name" : "金玉满堂"
]),
([	"action" : "$N一式"HIM"「风伴流云」"NOR"，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
	"lvl" : 80,
	"skill_name" : "风伴流云"
]),
([	"action" : "$N一式"BLU"「烟雨飘渺」"NOR"，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪",
	"lvl" : 90,
	"skill_name" : "烟雨飘渺"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="poyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练混元掌必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("你的紫霞神功火候不够，无法学混元掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练混元掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练混元掌。\n");
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
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hunyuan-zhang", 1);
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
	return __DIR__"hunyuan-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n混元掌："NOR"\n");
	write(@HELP

    混元掌为华山武功。混元掌缘自剑法，固招数名称多与剑招相
符。
    可与劈石破玉拳互备。

	学习要求：
		紫霞神功20级
		内力100
HELP
	);
	return 1;
}
