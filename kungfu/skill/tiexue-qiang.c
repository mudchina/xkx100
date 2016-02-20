// tiexue-qiang.c 铁血枪法
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N暴喝一声，眶龇欲裂，手中$w狂野挥出，正是一式"RED"「血战千里」"NOR"",
	"lvl"   : 0,
	"skill_name" : "血战千里"
]),
([	"action":"$N脚下玄奥地连踏几步，使出"CYN"「怒挥北斗」"NOR"，手中$w横扫$n的$l",
	"lvl"   : 10,
	"skill_name" : "怒挥北斗"
]),
([	"action":"$N双腿微蹲，使出一式"YEL"「干戈刺天」"NOR"，手中$w遥摇指向$n的头部",
	"lvl"   : 20,
	"skill_name" : "干戈刺天"
]),
([	"action":"$N纵身跃起，一式"HIR"「尸横遍野」"NOR"，手中$w带起一团啸声挥向$n",
	"lvl"   : 30,
	"skill_name" : "尸横遍野"
]),
([	"action":"$N手中$w中宫直进，一式"HIY"「直捣黄龙」"NOR"，对准$n的胸口刺出",
	"lvl"   : 50,
	"skill_name" : "直捣黄龙"
]),
([	"action":"$N手中$w一式"HIB"「拔山举鼎」"NOR"，对准$n的$l自下而上猛挑。",
	"lvl"   : 80,
	"skill_name" : "拔山举鼎"
]),
([	"action":"$N手中$w幻起一团白芒，一式"HIC"「破釜沉舟」"NOR"，脱手飞刺$n胸口",
	"lvl"   : 100,
	"skill_name" : "破釜沉舟"
]),
([	"action":"$N一式"GRN"「玉石俱焚」"NOR"，飞跃至$n身后，手中$w如疾电刺向自己胸口",
	"lvl"   : 120,
	"skill_name" : "玉石俱焚"
]),
});

int valid_enable(string usage) { return usage=="spear" || usage=="parry"; }
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("练铁血枪法必须执枪。\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 20)
		return notify_fail("你归元吐纳法火候不够，无法学铁血枪法。\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("你的内力太弱，无法练铁血枪法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的内力或气不够练铁血枪法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 300;
	int m_e2 = 500;  //铁掌真牛逼 -_-b --qingyun
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiexue-qiang", 1);
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
		"damage_type" : "刺伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 0; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiexue-qiang/" + action;
}

int help(object me)
{
	write(HIC"\n铁血枪法："NOR"\n");
	write(@HELP

    铁血枪法是铁掌帮主上官剑南所创。此枪法出自岳家枪法，当年
上官帮主一心抗金，图复中原，枪法招式多与此相关。

	学习要求：
		归元吐纳法20级
		内力修为40
HELP
	);
	return 1;
}

