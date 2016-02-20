// Last Modified by winder on May. 29 2001
// xiangmo-whip 降魔鞭

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N跃起三丈，身在半空，招式陡变，$w如惊涛骇浪，向$n电擎而落",
	"lvl" : 0,
	"skill_name" : "惊涛拍岸",
]),
([	"action": "$N鞭式一变，手中的$w宛如一条怪蟒，上下翻腾的袭向$n的$l",
	"lvl" : 20,
	"skill_name" : "万里腾云",
]),
([	"action": "$N手中$w前后舞动，一招「灵鹫展翅」，鞭鞭皆打向$n的$l！",
	"lvl" : 60,
	"skill_name" : "灵鹫展翅",
]),
([	"action": "$N手中$w抡动，鞭风汹涌，去式似游龙，或横扫直击，或盘旋翻卷，倾刻间已将$n全身裹住",
	"lvl" : 90,
	"skill_name" : "漫天飞雪",
]),
([	"action": "$N手中$w圈圈点点，鞭式连绵，忽地使出一招「降魔式」，$w上风声大作，漫天鞭影从四面八方向$n周身要害击到",
	"lvl" : 120,
	"skill_name" : "降魔式",
]),
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }
int valid_learn(object me)
{
	object weapon;

	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("你的站桩功火候太浅。\n");
	if ((int)me->query_skill("jiujie-whip",1) < 20)
		return notify_fail("你的九节鞭修为不足，没有办法练降魔鞭。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的体力不够练九节鞭法。\n");
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
	int p_e1 = 0;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 250;
	int m_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xiangmo-whip", 1);
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
		"damage_type" : random(2) ? "淤伤" : "刺伤",
	]);
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point() { return 1.0; }
 
int help(object me)
{
	write(HIC"\n降魔鞭："NOR"\n");
	write(@HELP

    降魔鞭是南少林高级鞭法。

	学习要求：
		站桩功50级
		九节鞭20级
		内力修为500
HELP
	);
	return 1;
}

