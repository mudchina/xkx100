// juemen-gun.c 绝门棍
// Last Modified by sega on Mar. 10 2000
//没碰文件,没用吧?
//归云庄南西仁和柯镇恶用着个？

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"$n右脚轻轻一点跃开躲过了$N的攻击。\n",
	"$n向旁边扑出，顺势一滚，闪到一边。\n",
	"$n斜里冲前一步，身法诡异，$N这一招落到空处。\n",
	"$n忽然直身飞入半空，很久也不见人影，半响后竟闪到了$N的背后。\n",
	"$n突然一个急转身，$N的这一招滑到了一边。\n",
});

mapping *action = ({
([	"action" : "$N斜里冲前一步，身法诡异，手中$w横扫$n的$l",
	"damage": 450,
	"dodge" : 50,
	"damage_type" : "挫伤"
]),
([	"action" : "$N忽然直身飞入半空，很久也不见人影，$n正搜寻间，$N已
飞身扑下，$w攻向$n的$l",
	"damage": 500,
	"dodge" : 45,
	"damage_type" : "挫伤"
]),
([	"action" : "$N原地一个后滚翻，却在落地的一刹那，身体向$n平飞过
去，手中$w指向$n的$l",
	"damage": 550,
	"dodge" : 60,
	"damage_type" : "挫伤"
]),
([	"action" : "$N突然一个急转身，$w横扫一圈后挟着猛烈的劲道打向$n的$l",
	"damage": 600,
	"dodge" : 75,
	"damage_type" : "挫伤"
]),
([	"action" : "$N向前扑出，顺势一滚，接着翻身跳起，手里$w斜向上击
向$n的$l",
	"damage": 750,
	"dodge" : 65,
	"damage_type" : "挫伤"
]),
([	"action" : "$N手中$w上下翻飞，舞成了一团杖花，这杖花绕$n游走三
圈后指向$n的$l",
	"damage": 800,
	"dodge" : 65,
	"damage_type" : "挫伤"
])
});

int valid_enable(string usage){return usage=="club" || usage=="parry"|| usage=="dodge"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("hunyuan-yiqi") < 20)
		return notify_fail("你的混元一气不到火候，无法练绝门棍。\n");
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力太弱，无法练绝门棍。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练绝门棍。\n");
	me->receive_damage("qi", 20);
	return 1;
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point() { return 1.0; }
int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"juemen-gun/" + action;
}

int help(object me)
{
	write(HIC"\n绝门棍："NOR"\n");
	write(@HELP

    绝门棍为少林七十二绝技之一。

	学习要求：
		混元一气功20级
		内力400
HELP
	);
	return 1;
}

