// wuluo-zhang.c 五罗轻烟掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N屏息静气，手起一掌"HIB"「轻烟袅袅」"NOR"，轻轻柔柔地拍向$n",
	"lvl"    : 0,
	"skill_name" : "轻烟袅袅"
]),
([	"action" : "$N轻轻浅笑，绕到$n身后，左手做势温柔轻拥$n腰间。$n蹙眉急躲，$N右手一招"BLU"「烟雾缭绕」"NOR"，无声无息向$n的$l拍到",
	"lvl"    : 20,
	"skill_name" : "烟雾缭绕"
]),
([	"action" : "$N一招"MAG"「烟海云涛」"NOR"，双掌幻化出一片掌影，如一阵轻烟，将$n细细密密地笼罩于内",
	"lvl"    : 40,
	"skill_name" : "烟海云涛"
]),
([	"action" : "$N返身越出圈外，回首一招"HIC"「云烟渺渺」"NOR"，远远地向$n的$l轻轻拍出两掌，掌风刮到，陡然变盛直让$n呼不出气来",
	"lvl"    : 60,
	"skill_name" : "云烟渺渺"
]),
([	"action" : "$N左掌从右掌内围翻出，轻飘飘地向$n拍去，看到$n起手招架，右掌却自胸口疾速圈出，一招"HIW"「烟雾弥漫」"NOR"，赶超左掌，拍向$n的$l",
	"lvl"    : 80,
	"skill_name" : "烟雾弥漫"
]),
([	"action" : "$N双掌齐推，振起一阵劲风，一招"HIW"「烟消云散」"NOR"在一丈开外击向$n",
	"lvl"    : 100,
	"skill_name" : "烟消云散"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练五罗轻烟掌必须空手。\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功太弱，无法练五罗轻烟掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练五罗轻烟掌。\n");
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 130;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuluo-zhang", 1);
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
	write(HIC"\n五罗轻烟掌："NOR"\n");
	write(@HELP

    五罗轻烟掌是天南大理段家的武功。
    可与金玉拳互备。

	学习要求：
		枯荣禅功20级
		内力100
HELP
	);
	return 1;
}


