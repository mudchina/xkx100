// tianyu-qijian.c 天羽奇剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一式"HIC"「海天一线」"NOR"，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "海天一线"
]),
([	"action":"$N错步上前，使出"HIM"「闪电惊虹」"NOR"，手中$w划出一道剑光劈向$n的$l",
	"lvl" : 9,
	"skill_name" : "闪电惊虹"
]),
([	"action":"$N手中$w一抖，一招"HIY"「日在九天」"NOR"，斜斜一剑反腕撩出，攻向$n的$l",
	"lvl" : 18,
	"skill_name" : "日在九天"
]),
([	"action":"$N手中剑锵啷啷长吟一声，一式"HIB"「咫尺天涯」"NOR"，一道剑光飞向$n的$l",
	"lvl" : 27,
	"skill_name" : "咫尺天涯"
]),
([	"action":"$N一式"HIR"「怒剑狂花」"NOR"，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
	"lvl" : 36,
	"skill_name" : "怒剑狂花"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式"BLU"「九弧震日」"NOR"，对准$n的$l斜斜击出",
	"lvl" : 44,
	"skill_name" : "九弧震日"
]),
([	"action":"$N一式"HIW"「漫天风雪」"NOR"，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"lvl" : 52,
	"skill_name" : "漫天风雪"
]),
([	"action":"$N一式"GRN"「天河倒泻」"NOR"，$w飞斩盘旋，如疾电般射向$n的胸口",
	"lvl" : 60,
	"skill_name" : "天河倒泻"
]),
([	"action":"$N一式"HIG"「天外飞仙」"NOR"，$w突然从天而降，一片金光围掠$n全身",
	"lvl" : 70,
	"skill_name" : "天外飞仙"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 20 ))
		return notify_fail("你的本门内功还不够娴熟。\n");
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("你的内力或气不够练天羽奇剑。\n");
	me->receive_damage("qi", 45);
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianyu-qijian", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="lingjiu")
	  return 1.4; 
  return 1.0;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
int help(object me)
{
	write(HIC"\n天羽奇剑："NOR"\n");
	write(@HELP

    天羽奇剑为天山灵鹫宫剑法。

	学习要求：
		八荒六合惟我独尊功20级
		内力80
HELP
	);
	return 1;
}

