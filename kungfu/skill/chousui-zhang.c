// chousui-zhang.c 抽髓掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": ""HIB"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l"NOR"",
	"lvl"   : 0,
	"skill_name" : "抽髓掌"
]),
([	"action": ""BLU"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l"NOR"",
	"lvl"   : 10,
	"skill_name" : "抽髓掌"
]),
([	"action": ""HIB"$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l"NOR"",
	"lvl"   : 20,
	"skill_name" : "抽髓掌"
]),
([	"action": ""BLU"$N双掌挟着一股腥臭之气拍向$n的$l"NOR"",
	"lvl"   : 30,
	"skill_name" : "抽髓掌"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanyin-wugongzhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练抽髓掌必须空手。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("你的内力太弱，无法练抽髓掌。");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练抽髓掌。\n");
	if (me->query_skill("chousui-zhang", 1) < 50)
		me->receive_damage("qi", 45);
	else
		me->receive_damage("qi", 40);
	me->add("neili", -25);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("huagong-dafa",1)) > 5)
	{
		victim->apply_condition("xx_poison", random(2) + 1 + victim->query_condition("xx_poison"));
	}
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
	int d_e1 = -45;
	int d_e2 = -25;
	int p_e1 = -5;
	int p_e2 = 25;
	int f_e1 = 210;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chousui-zhang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chousui-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n抽髓掌："NOR"\n");
	write(@HELP

    星宿派掌法，以腐尸毒名慑天下。
    可与三阴蜈蚣爪互备。

	学习要求：
		化功大法10级
		内力60
HELP
	);
	return 1;
}

