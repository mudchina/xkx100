//sanyin-wugongzhao.c 三阴蜈蚣爪
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N爪现青白，骨结隆起，自上而下撕扯$n的$l",
	"lvl"    : 0,
	"skill_name" : "蜈蚣现爪" ,
]),
([	"action" : "$N双手忽隐忽现，爪爪鬼魅般抓向$n的$l",
	"lvl"    : 10,
	"skill_name" : "鬼影连爪" ,
]),
([	"action" : "$N身形围$n一转，爪影纵横毫不留情对着$n的$l抓下",
	"lvl"    : 20,
	"skill_name" : "旋风毒爪" ,
]),
([	"action" : "$N一声怪叫，一爪横出直击$n的天灵盖",
	"lvl"    : 40,
	"skill_name" : "唯我独尊" ,
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练三阴蜈蚣爪必须空手。\n");
	if (me->query_skill("huagong-dafa", 1) < 20)
		return notify_fail("你的化功大法修为太弱，无法练三阴蜈蚣爪。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob;
	int i,damage;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练三阴蜈蚣爪。\n");
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
	int d_e1 = 60;
	int d_e2 = 40;
	int p_e1 = 0;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("sanyin-wugongzhao",1);
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
		"damage_type" : random(2) ? "抓伤" : "内伤",
	]);
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("huagong-dafa",1)) > 5)
	{
		victim->apply_condition("xx_poison", random(2) + 1 + victim->query_condition("xx_poison"));
	}
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n三阴蜈蚣爪："NOR"\n");
	write(@HELP

    三阴蜈蚣爪为星宿派歹毒武功。
    可与抽髓掌互备。

	学习要求：
		化功大法20级
		内力200
HELP
	);
	return 1;
}

