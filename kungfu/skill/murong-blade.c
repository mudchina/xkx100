// murong-blade.c 慕容刀法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N凌空跃起，双手握起$w，高举过头，一招"HIM"「劈天盖地满壮志」"NOR"，势
如奔雷坠地，卷起漫天风尘，一刀向$n的$l劈了下来",
	"lvl"    : 0,
	"skill_name" : "劈天盖地满壮志",
]),
([	"action" : "$N左腿斜跨一步，右手握着$w，横架前胸，猛地侧身旋转，以腰带
臂，以臂扛刀，一招"HIR"「弯刀逆转倒乾坤」"NOR"，平刃挥向$n的$l",
	"lvl"    : 20,
	"skill_name" : "弯刀逆转倒乾坤",
]),
([	"action" : "$N手握$w，展开身形，使动"HIW"「遥看万疆千里雪」"NOR"，突然之间，四周中
白光闪动，丈余圈子之内，全是刀影",
	"lvl"    : 40,
	"skill_name" : "遥看万疆千里雪",
]),
([	"action" : "$N一招"HIG"「壮志豪气满江湖」"NOR"，$w声势大变，东砍一刀少林寺的降魔刀
法，西劈一刀广西黎山洞黎老汉的柴刀十八路，回转又是一刀江南史家的
回风拂柳刀，刀刀不离$n左右",
	"lvl"    : 60,
	"skill_name" : "壮志豪气满江湖",
]),
});

int valid_enable(string usage) { return (usage=="blade") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("你的神元功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练慕容刀法。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 50;
	int d_e2 = 25;
	int p_e1 = -5;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("murong-blade", 1);
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
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"murong-blade/" + action;
}

int help(object me)
{
	write(HIC"\n慕容刀法："NOR"\n");
	write(@HELP

    慕容刀法为江南姑苏慕容祖传刀法。以雄浑沉厚、气势凝重著
称。

	学习要求：
		神元功10级
		内力50
HELP
	);
	return 1;
}

