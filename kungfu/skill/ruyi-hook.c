// ruyi-hook.c 如意钩法
// Last Modifyed by Winder on Aug. 21 2002

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "只见$N$w望空一点，一招「翻天覆地」同时攻向$n的头部，左腿横出，扫向$n腿部。",
	"lvl" : 0,
	"skill_name" : "翻天覆地"
]),
([	"action" : "只见$N左手剑指虚攻$n的上身，$w却以迅雷不及掩耳之势向$n的腰部钩去。好一招「若离若合」！",
	"lvl" : 3,
	"skill_name" : "若离若合"
]),
([	"action" : "只见$N一招「雪满银钩」将$w舞得如同雪花纷飞，将$n的全身笼罩在$w光芒之下。",
	"lvl" : 6,
	"skill_name" : "雪满银钩"
]),
([	"action" : "只见$N使出「天王索命」，一钩紧似一钩，一钩快似一勾，一气呵成，直逼$n的周身大穴。",
	"lvl" : 9,
	"skill_name" : "天王索命"
]),
([	"action" : "$N一招「天马行空」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"lvl" : 12,
	"skill_name" : "天马行空"
]),
([	"action" : "$N一招「神龙摆尾」，右脚虚上，右手回收，$w向下截劈$n的$l",
	"lvl" : 15,
	"skill_name" : "神龙摆尾"
]),
([	"action" : "$N一招「钩心斗角」，$w自左而右，一气呵成横扫$n的$l",
	"lvl" : 18,
	"skill_name" : "钩心斗角"
]),
([	"action" : "$N右脚向前一步，左膝提起，一招「不阴不阳」，$w向前上方刺向$n的$l",
	"lvl" : 21,
	"skill_name" : "不阴不阳"
]),
([	"action" : "$N使一招「尔虞我诈」，右脚向后回撤，$w随身体右后撤，突然向左前方刺向$n的$l",
	"lvl" : 24,
	"skill_name" : "尔虞我诈"
]),
([	"action" : "$N使出「峰峦重叠」，$w划出三个圆弧，绵绵不断划向$n的$l",
	"lvl" : 27,
	"skill_name" : "峰峦重叠"
]),
([	"action" : "$N一转身，$w向后斜带，一招「飞横拔户」，砍向$n的$l",
	"lvl" : 30,
	"skill_name" : "飞横拔户"
]),
([	"action" : "$N双手握着$w，微一低头，一招「闭门思过」，突然从脑后疾向$n刺去",
	"lvl" : 35,
	"skill_name" : "闭门思过"
]),
([	"action" : "$N双手执着$w，钩头向内，一招「欲擒故纵」，倒转身体，刺向$n",
	"lvl" : 40,
	"skill_name" : "欲擒故纵"
]),
([	"action" : "$N一招「对牛弹琴」，$w在$n一楞之间突然划向$n的$l",
	"lvl" : 50,
	"skill_name" : "对牛弹琴"
]),
([	"action" : "$N双脚并步，身体立起，一招「莲叶托桃」，$w向前平刺$n的裆部",
	"lvl" : 60,
	"skill_name" : "莲叶托桃"
]),
([	"action" : "$N一招「群魔乱舞」，$w舞动护住全身向$n撞去",
	"lvl" : 70,
	"skill_name" : "群魔乱舞"
]),
([	"action" : "$N一反身，使一招「鱼死网破」，$w不顾一切地劈向$n的$l",
	"lvl" : 80,
	"skill_name" : "鱼死网破"
]),
([	"action" : "$N右手$w向后撤，再向前平平托起，一招「描龙绣凤」刺向$n的$l",
	"lvl" : 90,
	"skill_name" : "描龙绣凤"
]),
([	"action" : "$N身子向上纵起，一招「天地同寿」，头下脚上，$w向$n的头顶刺去",
	"lvl" : 100,
	"skill_name" : "天地同寿"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("你的毒龙大法火候太浅。\n");
	if ((int)me->query_skill("hook", 1) < 20)
		return notify_fail("你的钩法基本功还不扎实。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "hook")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的气血不够练如意钩法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
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

	lvl = (int) me->query_skill("ruyi-hook",1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"ruyi-hook/" + action;
}

int help(object me)
{
	write(HIC"\n如意钩法"NOR"\n");
	write(@HELP

    如意钩法是神龙岛钩法。

	学习要求：
		毒龙大法20级
		基本钩法20级
		内力修为100
HELP
	);
	return 1;
}

