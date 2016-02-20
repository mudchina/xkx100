// nianhua-zhi.c -拈花指

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N侧身抬臂，右指划了个半圈，一式"HIG"「瓶花落砚」"NOR"击向$n的$l",
	"lvl" : 0,
	"skill_name" : "瓶花落砚"
]),
([	"action" : "$N左掌虚托，一式"MAG"「寒梅吐蕊」"NOR"，右指穿腋疾出，指向$n的胸前",
	"lvl" : 10,
	"skill_name" : "寒梅吐蕊"
]),
([	"action" : "$N俯身斜倚，左手半推，右手一式"BLU"「初杏问酒」"NOR"，向$n的$l划过",
	"lvl" : 20,
	"skill_name" : "初杏问酒"
]),
([	"action" : "$N双目微睁，一式"RED"「露草斜阳」"NOR"，双手幻化出千百个指影，拂向$n的$l",
	"lvl" : 30,
	"skill_name" : "露草斜阳"
]),
([	"action" : "$N一式"HIB"「仰月承霖」"NOR"，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
	"lvl" : 40,
	"skill_name" : "仰月承霖"
]),
([	"action" : "$N双掌平托胸前，十指叉开，一式"CYN"「叶底留莲」"NOR"，指向$n的周身大穴",
	"lvl" : 50,
	"skill_name" : "叶底留莲"
]),
([	"action" : "$N双掌翻飞，一式"HIW"「清风拂桂」"NOR"，指端迸出无数道劲气，射向$n的全身",
	"lvl" : 60,
	"skill_name" : "清风拂桂"
]),
([	"action" : "$N一式"YEL"「菊圃秋霜」"NOR"，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
	"lvl" : 70,
	"skill_name" : "菊圃秋霜"
]),
([	"action" : "$N一式"HIG"「伽叶微笑」"NOR"，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
	"lvl" : 80,
	"skill_name" : "伽叶微笑"
]),
([	"action" : "$N左掌竖立胸前，一式"HIY"「佛祖拈花」"NOR"，右手食指扣住拇指，轻轻对着$n一弹",
	"lvl" : 90,
	"skill_name" : "佛祖拈花"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanhua-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练拈花指必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学拈花指。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练拈花指。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练拈花指。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 220;
	int f_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("nianhua-zhi", 1);
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
	return __DIR__"nianhua-zhi/" + action;
}
int help(object me)
{
	write(HIC"\n拈花指："NOR"\n");
	write(@HELP

    拈花指为少林七十二绝技之一。
    当年迦叶尊者在灵山妙悟佛法，拈花微笑。此拈花指即取尊者
遗意而创。
    可与散花掌互备。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

