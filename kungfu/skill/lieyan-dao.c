// lieyan-dao.c 烈焰刀
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一招「黑龙现身」，$w有如一条黑龙在$n的周身旋游，勿快勿慢，变化若神",
	"lvl" : 0,
	"skill_name" : "黑龙现身",
]),
([	"action" : "$N一招「万水千山」，左右腿一前一后，$w乱披风势向$n的$l斩去",
	"lvl" : 8,
	"skill_name" : "万水千山",
]),
([	"action" : "$N纵身跃落，一招「横扫千里」，$w带着疾风呼的一声便向$n横扫过去",
	"lvl" : 16,
	"skill_name" : "横扫千里",
]),
([	"action" : "$N一招「左右开弓」，$w大开大阖，左右并进，左一刀，右一刀向$n的两肩砍落",
	"lvl" : 24,
	"skill_name" : "左右开弓",
]),
([	"action" : "$N手中$w自上而下，一招「百丈飞瀑」，刀光流泻，如一片雪白瀑布砍向$n的头部",
	"lvl" : 33,
	"skill_name" : "百丈飞瀑",
]),
([	"action" : "$N挥舞$w，使出一招「直摧万马」，上劈下撩，左挡右开，如千军万马般罩向$n",
	"lvl" : 42,
	"skill_name" : "直摧万马",
]),
([	"action" : "$N带得刀风劲疾，一招「灵猫翻身」，一个猛转身，连刀带人往$n的$l的劈去",
	"lvl" : 51,
	"skill_name" : "灵猫翻身",
]),
([	"action" : "$N向前一个弓步，一招「上步劈山」，$w直直的劈出，一片流光般的刀影向$n的全身罩去",
	"lvl" : 60,
	"skill_name" : "上步劈山",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("你的九阳神功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练烈焰刀法。\n");
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
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 70;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("lieyan-dao", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);	 /* 选择出手招数序号 */
	return ([
		"action"	: action[seq]["action"],
		"dodge"	 : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"	 : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"	 : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"	: m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }
string perform_action_file(string action)
{
//	return __DIR__"lieyan-dao/" + action;
}
int help(object me)
{
	write(HIC"\n烈焰刀法："NOR"\n");
	write(@HELP

    烈焰刀法是明教的刀法。

	学习要求：
		九阳神功20级
		内力修为10
HELP
	);
	return 1;
}

