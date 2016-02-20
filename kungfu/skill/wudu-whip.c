// wudu-whip.c 五毒鞭法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":  "$N轻抖手腕，一招"HIG"「青蛇吐芯」"NOR"，手中$w抖得笔直，直向$n卷去",
	"lvl"   :  0,
	"skill_name" : "青蛇吐芯",
]),
([	"action":  "$N身形一转，一招"RED"「毒蝎反尾」"NOR"，$w在空中转了个圈，以怪异的角度劈向$n",
	"lvl"   :  10,
	"skill_name" : "毒蝎反尾",
]),
([	"action":  "$N一抖长鞭，一招"BLK"「黑蛛吐丝」"NOR"，手中$w化做无数幻影，罩向$n",
	"lvl"   :  20,
	"skill_name" : "黑蛛吐丝",
]),
([	"action":  "$N力贯鞭梢，一招"YEL"「蟾蜍出洞」"NOR"，手中$w忽左忽右，直劈向$n胸口",
	"lvl"   :  30,
	"skill_name" : "蟾蜍出洞",
]),
([	"action":  "$N运气于腕，一招"BLU"「蜈蚣翻身」"NOR"，手中$w转起无数个圈圈，带着一股阴风，直向$n扑去",
	"lvl"   :  40,
	"skill_name" : "蜈蚣翻身",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query_skill("wudu-shengong", 1) < 30 )
		return notify_fail("你的五毒神功太低，不能练五毒鞭。\n");
	if( (int)me->query("max_neili") < 30 )
		return notify_fail("你的内力修为太低，不能练五毒鞭。\n");
	if ( !objectp(weapon = me->query_temp("weapon")) ||
		( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的体力不够练五毒鞭法。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
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
	int d_e2 = -40;
	int p_e1 = 0;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 200;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudu-whip", 1);
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
	return __DIR__"wudu-whip/" + action;
}
int help(object me)
{
	write(HIC"\n五毒鞭法："NOR"\n");
	write(@HELP

    五毒鞭法为五毒教的独门鞭法。

	学习要求：
		五毒神功30级
		内力30
HELP
	);
	return 1;
}

