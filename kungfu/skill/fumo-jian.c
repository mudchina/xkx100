// fumo-jian.c 伏魔剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIC"「穿云势」"NOR"，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
	"lvl" : 0,
	"skill_name" : "穿云势"
]),
([	"action" : "$N向前跃上一步，左手剑诀，右手$w使出一式"HIW"「破雾势」"NOR"直刺$n的$l
",
	"lvl" : 10,
	"skill_name" : "破雾势"
]),
([	"action" : "$N拔步挺腰，一式"HIY"「推山势」"NOR"，手中$w沉滞无比，缓缓挥剑撞向$n的
$l",
	"lvl" : 20,
	"skill_name" : "推山势"
]),
([	"action" : "$N一式"HIG"「搅海势」"NOR"，$w自左而右划出一个大弧，平平地向$n的$l挥去
",
	"lvl" : 30,
	"skill_name" : "搅海势"
]),
([	"action" : "$N回身拧腰，右手虚抱成圆，一式"HIW"「开天势」"NOR"，$w中宫直进，刺向$n
的胸口",
	"lvl" : 40,
	"skill_name" : "开天势"
]),
([	"action" : "$N一式"BLU"「劈地势」"NOR"，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩
向$n的$l",
	"lvl" : 49,
	"skill_name" : "劈地势"
]),
([	"action" : "$N运气施出"MAG"「雷针势」"NOR"，$w剑尖逼出一道青芒，闪电般破空射向$n的
$l",
	"lvl" : 57,
	"skill_name" : "雷针势"
]),
([	"action" : "$N双腿半屈半蹲，一式"GRN"「龙吞势」"NOR"，剑尖划出无数圆圈，狂风骤起，
笼罩天地",
	"lvl" : 64,
	"skill_name" : "龙吞势"
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }
//int valid_combine(string combo) { return combo=="cibei-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练伏魔剑。\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 130;
	int m_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fumo-jian", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n伏魔剑："NOR"\n");
	write(@HELP

    伏魔剑为少林七十二绝技之一。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

