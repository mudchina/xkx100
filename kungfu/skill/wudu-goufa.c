// wudu-goufa.c 五毒钩法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N手中$w一抖，一式"HIR"「灵蛇吐信」"NOR"，闪电般的疾刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "灵蛇吐信"
]),
([	"action":"$N一式"MAG"「柔丝轻系」"NOR"，剑意绵绵不绝，化做一张无形的大网将$n困在当中",
	"lvl" : 10,
	"skill_name" : "柔丝轻系"
]),
([	"action":"$N一声阴笑，飞身纵起，一式"BLU"「张牙舞爪」"NOR"，手中$w狂舞，幻出千万条手臂，合身扑向$n",
	"lvl" : 25,
	"skill_name" : "张牙舞爪"
]),
([	"action":"$N足尖点地，身形一旋看似欲走，手中$w却倏的从腋下穿过，疾
刺向$n的$l，好一式"HIM"「天蝎藏针」"NOR"",
	"lvl" : 35,
	"skill_name" : "天蝎藏针"
]),
([	"action":"$N脚步踉跄，身形忽的向前跌倒，一式"HIC"「井底望月」"NOR"，掌中$w自下而上直刺$n的小腹",
	"lvl" : 50,
	"skill_name" : "井底望月"
]),
([	"action":"$N身形一晃，一式"HIY"「金蛇缠腕」"NOR"，手中$w如附骨之蛆般无声无息地刺向$n的手腕",
	"lvl" : 60,
	"skill_name" : "金蛇缠腕"
]),
([	"action":"\n$N一声厉啸，身形冲天而起，一式"HIG"「神蟾九变」"NOR"，掌中$w如鬼魅般连刺$n全身九道大穴",
	"lvl" : 70,
	"skill_name" : "神蟾九变"
]),
([	"action":"$N深吸一口起，双手握钩，招演"GRN"「万毒至尊」"NOR"，$w尖端透出一条强劲的黑气，闪电般的袭向$n",
	"lvl" : 80,
	"skill_name" : "万毒至尊"
]),
});

int valid_enable(string usage) { return usage == "hook" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("你的五毒神功火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hook")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的内力或气不够练五毒钩法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(damage_bonus/2) > victim->query_con() )
	{
		victim->receive_wound("qi", damage_bonus/ 3 );
	}
	if ( victim->query("family/family_name")!= "五毒教" &&
		me->query_skill("wudu-shengong",1)>40)
	{
		switch( random(5) )
		{
			case 0:
				victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("snake_poison"));
				break;
			case 1:
				victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("zhizhu_poison"));
				break;
			case 2:
				victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("wugong_poison"));
				break;
			case 3:
				victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("xiezi_poison"));
				break;
			case 4:
				victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("chanchu_poison"));
				break;
		}
		return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
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
	int d_e1 = -50;
	int d_e2 = -20;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 100;
	int f_e2 = 200;
	int m_e1 = 200;
	int m_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudu-goufa", 1);
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
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}
int help(object me)
{
	write(HIC"\n五毒钩法："NOR"\n");
	write(@HELP

    五毒钩法是五毒教的钩法。

	学习要求：
		基本内功20级
		五毒神功20级
		内力100
HELP
	);
	return 1;
}

