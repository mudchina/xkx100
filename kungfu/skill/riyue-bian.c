// riyue-bian.c 日月鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":      "$N端坐不动，一招"HIY"「裂石式」"NOR"，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
	"lvl" :        0,
	"skill_name" : "裂石式",
]),
([	"action":      "$N身形一转，一招"HIB"「断川式」"NOR"，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
	"lvl" :        60,
	"skill_name" : "断川式",
]),
([	"action":      "$N力贯鞭梢，一招"HIC"「破云式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        90,
	"skill_name" : "破云式",
]),
([	"action":"$N力贯鞭梢，一招"HIW"「分海式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        100,
	"skill_name" : "分海式",
]),
([	"action":"$N力贯鞭梢，一招"HIG"「裂空式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        110,
	"skill_name" : "裂空式",
]),
([	"action":"$N力贯鞭梢，一招"HIY"「佛光普照」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        120,
	"skill_name":  "佛光普照",
]),
([	"action":"$N力贯鞭梢，一招"HIY"「金刚伏魔」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        130,
	"skill_name" : "金刚伏魔",
]),
([	"action":"$N力贯鞭梢，一招"HIM"「佛法无边」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" :        200,
	"skill_name" : "佛法无边",
]),
});

int valid_enable(string usage) { return usage == "whip" || usage =="parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不足，没有办法练日月鞭法, 多练些内力再来吧。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("你的混元一气功火候太浅。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
		|| ( string)weapon->query("skill_type") != "whip" )
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
		return notify_fail("你的体力不够练日月鞭法。\n");
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
	int d_e1 = -60;
	int d_e2 = -50;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 300;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-bian", 1);
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

int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { 
	object weapon;
	if ( objectp(weapon = me->query_temp("weapon")) 
	           && weapon->query("id")=="heisuo")
	 return 1.3;
	else 
	return 1.0; 
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
		return __DIR__"riyue-bian/" + action;
}
int help(object me)
{
	write(HIC"\n日月鞭法："NOR"\n");
	write(@HELP

    日月鞭法为少林长老三渡的镇山绝技。

	学习要求：
		混元一气功50级
		内力500
HELP
	);
	return 1;
}

