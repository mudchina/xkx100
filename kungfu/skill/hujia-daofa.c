// hujia-daofa.c 胡家刀法
// Last Modified by sega on Mar. 10 2000
//威力不小,但难练

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w横推，一招"HIM"「推波助澜」"NOR"，由上至下向$nl砍去",
	"lvl"    : 0,
	"skill_name" : "推波助澜",
]),
([	"action" : "$N一招"HIC"「沙鸥掠波」"NOR"，刀锋自下而上划了个半弧，$w一提一收，平刃
挥向$n的颈部",
	"lvl"    : 8,
	"skill_name" : "沙鸥掠波",
]),
([	"action" : "$N使出一招"HIB"「天设牢笼」"NOR"，将$w舞得如白雾一般压向$n ",
	"lvl"    : 16,
	"skill_name" : "天设牢笼",
]),
([	"action" : "$N一招"HIG"「闭门铁扇」"NOR"，$w缓缓的斜着向$n推去 ",
	"lvl"    : 24,
	"skill_name" : "闭门铁扇",
]),
([	"action" : "$N手拖$w，转身跃起，一招"RED"「翼德闯帐」"NOR"，一道白光射向$n的胸口",
	"lvl"    : 32,
	"skill_name" : "翼德闯帐",
]),
([	"action" : "$N挥舞$w，使出一招"HIW"「白鹤舒翅」"NOR"，上劈下撩，左挡右开，齐齐罩向$n",
	"lvl"    : 40,
	"skill_name" : "白鹤舒翅",
]),
([	"action" : "$N一招"GRN"「春风送暖」"NOR"，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"lvl"    : 48,
	"skill_name" : "春风送暖",
]),
([	"action" : "$N募的使一招"HIM"「八方藏刀」"NOR"，顿时剑光中无数朵刀花从四面八方涌向
$n全身",
	"lvl"    : 56,
	"skill_name" : "八方藏刀",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了胡家刀法。\n");
	me->receive_damage("qi", 50-(int)(me->query_str()/5));
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
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 70;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("hujia-daofa",1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n胡家刀法："NOR"\n");
	write(@HELP

    胡家刀法为胡家始祖飞天狐狸所创。胡斐据家传刀谱练成后与
金面佛苗人凤的苗家剑齐名天下。

	学习要求：
		基本内功20级
		内力50
HELP
	);
	return 1;
}

