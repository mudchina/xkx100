// qiufeng-chenfa.c 秋风拂尘
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N端坐不动，一招"HIC"「秋风拂叶」"NOR"，手中$w带着一股劲风，击向$n的脸颊",
	"lvl"    : 0,
	"skill_name" : "秋风拂叶",
]),
([	"action" : "$N单臂一挥，一招"HIW"「玉带围腰」"NOR"，手中$w直绕向$n的身后",
	"lvl"    : 20,
	"skill_name" : "玉带围腰",
]),
([	"action" : "$N身形一转，一招"HIB"「流云断川」"NOR"，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
	"lvl"    : 40,
	"skill_name" : "流云断川",
]),
([	"action" : "$N力贯尘梢，一招"HIG"「春风化雨」"NOR"，手中$w舞出满天幻影，排山倒海般扫向$n全身",
	"lvl"    : 50,
	"skill_name" : "春风化雨",
]),
([	"action" : "$N忽的向前一跃，一招"HIY"「野马分鬃」"NOR"，手中$w分击$n左右",
	"lvl"    : 60,
	"skill_name" : "野马分鬃",
]),
([	"action" : "$N慢步上前，一招"GRN"「竹影扫阶」"NOR"，手中$w缓缓罩向$n前胸",
	"lvl"    : 70,
	"skill_name" : "竹影扫阶",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不足，没有办法练秋风尘法, 多练些内力再来吧。\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候太浅。\n");
        if ((int)me->query_skill("yunv-xinfa",1)<10)
                return notify_fail("你的玉女心法火候太浅。\n");
        if ( !objectp(weapon = me->query_temp("weapon"))
		|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条拂尘才能练尘法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练秋风尘法。\n");
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
	int d_e1 = -45;
	int d_e2 = -35;
	int p_e1 = 5;
	int p_e2 = 15;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 150;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qiufeng-chenfa", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; } 
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	if ( this_player()->query_skill("qiufeng-chenfa", 1) >= 40 )
		return __DIR__"qiufeng-chenfa/" + action;
}

int help(object me)
{
	write(HIC"\n秋风拂尘："NOR"\n");
	write(@HELP

    秋风拂尘为古墓派李莫愁扬名天下的武功。

	学习要求：
		基本内功50级
		玉女心经10级
		内力300
HELP
	);
	return 1;
}

