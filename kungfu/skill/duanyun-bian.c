// duanyun-bian.c 断云鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N中规中距，一招"HIR"「聚火」"NOR"，手中$w轻轻颤动，一点鞭尖点向$n的$l",
	"lvl" :	0,
	"skill_name" : "聚火",	
]),
([	"action" : "$N向前跨上一步，左手回环，右手$w使出一式"HIW"「起光」"NOR"自斜下扫向$n的$l",	
	"lvl" :	15,
	"skill_name" : "起光",
]),
([	"action" : "$N身形一挫，鞭交左手，右手劈空一掌，$w随即向上挥出，使出"HIG"「招雨」"NOR"抽向$n的$l",	
	"lvl" :	30,
	"skill_name" : "招雨",
]),
([	"action" : "$N身形一展，右手$w使出一式"HIC"「动雷」"NOR"，由上而下疾劈$n的$l",	
	"lvl" :	45,
	"skill_name" : "动雷",
]),
([	"action" : "$N一招"HIM"「移电」"NOR"，$w自左上而右下划出一个大弧，平平地向$n的$l挥去",
	"lvl" :	60,
	"skill_name" : "移电",
]),
([	"action" : "$N上身往左侧一拧，一招"HIM"「剪虹」"NOR"，右手$w反手抖动，向$n的$l铰去",
	"lvl" :	75,
	"skill_name" : "剪虹",
]),
([	"action" : "$N左腿提膝，手中$w斜指，一招"HIC"「止风」"NOR"横向$n的$l",
	"lvl" :	90,
	"skill_name" : "止风",
]),
([	"action" : "$N猛的加速，$w时快时慢，当$n准备挡时，$w一招"HIW"「断云」"NOR"，横扫$n的$l",
	"lvl" :	105,
	"skill_name" : "断云",
]),
([	"action" : "$N轻轻跃起，一招"HIB"「遮月」"NOR"，$w在半空中化为一圈银芒，落向$n的$l",
	"lvl" :	110,
	"skill_name" : "遮月",
]),
([	"action" : "$N使出"HIY"「掩日」"NOR"，$w划出无数个圆圈，鞭缘直出，贯注内力，绵绵不断划向$n的$l",
	"lvl" :	120,
	"skill_name" : "掩日",
])
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力不足，没有办法练断云鞭法。\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 40)
		return notify_fail("你的先天气功火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon")) ||
		( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的体力不够练断云鞭法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
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
	int d_e1 = -55;
	int d_e2 = -45;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 350;
	int m_e2 = 500;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duanyun-bian", 1);
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
		"damage_type" : random(2) ? "瘀伤" : "刺伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"duanyun-bian/" + action;
}
int help(object me)
{
	write(HIC"\n断云鞭法："NOR"\n");
	write(@HELP

    断云鞭法为全真掌教马钰的独门武功。

	学习要求：
		先天气功40级
		内力200
HELP
	);
	return 1;
}
