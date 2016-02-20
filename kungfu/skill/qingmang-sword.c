// qingmang-sword.c 青蟒剑法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
	"$N刷刷刷连出三招，使出「青蟒吐信」，但见$w闪动，犹如蟒蛇吐信一般，不知要劈向何处",
	"$N得理不让人，又是一招，$w直挥$n面门，逼得$n急忙侧头避让",
	"$N左脚又在$n小腿上一扫，想将$n拌倒，跟着$w一抖，已指住$n咽喉",
	"$N一声冷笑，手中$w迎面砍下，直劈$n$l",
	"$N一下冲到$n身前，突然之间拔出$w，便往$n头上砍了下去",
	"$N突然一下拔$w挥击，既是突如其来，行动又是快极，$n全无闪避的馀裕",
	"$N$w挺出，一招「毒蛇出洞」，向$n当胸劈去，势道甚是劲急",
	"$N叫声：「好！」$w圈转，削向$n$l",
	"$N一招「灵舌吐信」，$w尖快绝无比点向$n的$l"
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("你的五毒神功火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("你的内力或气不够练青蟒剑法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"damage" : 30+random(100),
		"dodge"  : 30+random(25),
		"parry"  : 5+random(15),
		"force"  : 50+random(50),
		"damage_type" : random(2)?"刺伤":"割伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n青蟒剑法："NOR"\n");
	write(@HELP

    青蟒剑法是五毒剑法的一种。

	学习要求：
		基本内功20级
		五毒神功20级
		内力100
HELP
	);
	return 1;
}

