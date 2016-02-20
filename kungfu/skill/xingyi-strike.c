// xingyi-strike.c 星移掌
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N两掌一合，然后左掌拍出，身形跟进，一式"CYN"「幻形变影」"NOR"，左掌收回，右掌变幻吞吐，猛地推向$n的$l",
	"lvl" : 0,
	"skill_name" : "幻形变影"
]),
([	"action" : "$N伸出双手，十指箕张，一式"RED"「星星点点」"NOR"，手指左右飘忽，十只指尖疾点$n的$l",
	"lvl" : 20,
	"skill_name" : "星星点点"
]),
([	"action" : "$N使一式"HIC"「漫天星斗」"NOR"，一个飞身跃起，左掌虚立，右掌乍伸乍合，风驰电掣般向$n的$l拍了下来",
	"lvl" : 40,
	"skill_name" : "漫天星斗"
]),
([	"action" : "$N一声长啸，一式"HIW"「北斗七星」"NOR"，双掌幻成漫天星斗，铺天盖地般向$n击去",
	"lvl" : 60,
	"skill_name" : "北斗七星"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="canhe-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练星移掌必须空手。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("你的神元功火候不够，无法学星移掌。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练星移掌。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练星移掌。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xingyi-strike", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n星移掌："NOR"\n");
	write(@HELP

    姑苏慕容家最拿手的绝技，乃是一门借力打力之技，叫做“斗
转星移”。星移掌便是依此演化的慕容家传掌法。
    可与参合指互备。

	学习要求：
		神元功15级
		内力50
HELP
	);
	return 1;
}

