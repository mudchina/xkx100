// chuanyun-leg.c 穿云腿法
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N身子疾转，右脚贴地伸出，一式"BLU"「划地为牢」"NOR"，横扫$n的下盘",
	"lvl" : 0,
	"skill_name" : "划地为牢"
]),
([	"action" : "$N左腿踢出，不待左腿落下，右脚紧跟着凌空踢出，一式"GRN"「追风逐电」"NOR"，双脚先后踢向$n的$l",
	"lvl" : 15,
	"skill_name" : "追风逐电"
]),
([	"action" : "$N一式"MAG"「左右穿花」"NOR"，左脚横踹，随即向右前方落步，右脚迅速发力踢向$n的$l",
	"lvl" : 30,
	"skill_name" : "左右穿花"
]),
([	"action" : "$N突然一个后翻，一式"HIW"「倒踢北斗」"NOR"，双腿晃动，向$n的$l踢去",
	"lvl" : 45,
	"skill_name" : "倒踢北斗"
]),
([	"action" : "$N使一式"HIC"「登云步月」"NOR"，拔地而起，双腿连续踢出，击向$n的胸口",
	"lvl" : 60,
	"skill_name" : "登云步月"
]),
([	"action" : "$N身子盘旋飞起，一式"HIY"「横扫九州」"NOR"，右腿横扫$n的$l",
	"lvl" : 75,
	"skill_name" : "横扫九州"
]),
([	"action" : "$N左手一绕，向击向$n的头部，一式"HIB"「无影无踪」"NOR"，右腿突然踢向$n的$l",
	"lvl" : 90,
	"skill_name" : "无影无踪"
]),
([	"action" : "$N使一式"HIR"「雷霆天下」"NOR"，身体凌空而起，双腿连环，只见漫天腿影笼罩着$n",
	"lvl" : 100,
	"skill_name" : "雷霆天下"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhentian-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练穿云腿必须空手。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 20)
		return notify_fail("你的玄天无极功火候不够，无法学穿云腿。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练穿云腿。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 15)
		return notify_fail("你的内力不够练穿云腿。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = -5;
	int p_e2 = 25;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chuanyun-leg", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { 
	if (me->query("gender")=="女性")
	  return 1.2;
	else 
	  return 0.8;
}

string perform_action_file(string action)
{
	return __DIR__"chuanyun-leg/" + action;
}

int help(object me)
{
	write(HIC"\n穿云腿："NOR"\n");
	write(@HELP

    穿云腿是昆仑派侧重女弟子的武功。

	学习要求：
		玄天无极功20级
		内力50
HELP
	);
	return 1;
}

