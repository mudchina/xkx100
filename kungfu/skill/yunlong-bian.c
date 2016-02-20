// yunlong-bian.c 云龙鞭法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N单手一扬，一招"MAG"「开天辟地」"NOR"，手中$w抖得笔直，对准$n当头罩下",
	"lvl" : 0,
	"skill_name" : "开天辟地",
]),
([	"action": "$N身形一转，一招"BLU"「龙腾四海」"NOR"，手中$w如矫龙般腾空一卷，猛地击向$n太阳穴",
	"lvl" : 10,
	"skill_name" : "龙腾四海",
]),
([	"action": "$N唰的一抖长鞭，一招"HIM"「矫龙出水」"NOR"，手中$w抖得笔直，刺向$n双眼",
	"lvl" : 20,
	"skill_name" : "矫龙出水",
]),
([	"action": "$N力贯鞭梢，一招"HIC"「破云见日」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"lvl" : 30,
	"skill_name" : "破云见日",
]),
([	"action": "$N运气于腕，一招"HIY"「开山裂石」"NOR"，手中$w象一根铜棍般直击向$n",
	"lvl" : 40,
	"skill_name" : "开山裂石",
]),
([	"action": "$N单臂一挥，一招"HIW"「玉带围腰」"NOR"，手中$w直击向$n腰肋",
	"lvl" : 50,
	"skill_name" : "玉带围腰",
]),
([	"action": "$N高高跃起，一招"HIB"「大漠孤烟」"NOR"，手中$w笔直向$n当头罩下",
	"lvl" : 60,
	"skill_name" : "大漠孤烟",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力不足，没有办法练云龙鞭法, 多练些内力再来吧。\n");

	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("你的云龙神功火候太浅。\n");

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
	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("你的云龙神功火候太浅。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的体力不够练云龙鞭法。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -40;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 300;
	int m_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-bian", 1);
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
		"damage_type" : random(2) ? "劈伤" : "瘀伤",
	]);
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yunlong-bian/" + action;
}
int help(object me)
{
	write(HIC"\n云龙鞭法："NOR"\n");
	write(@HELP

    云龙鞭法为天地会云龙门武功。

	学习要求：
		云龙神功40级
		内力200
HELP
	);
	return 1;
}

