// mantian-huayu.c 漫天花雨

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string	*msg = ({
"$N身子左侧，一式「月下踏径」，右手$w从身体下方突然甩出，直射向$n的$l",
"$w破空飞出，一式「长虹经天」，缓缓一个弧线，由左自右，绕向$n的$l，",
"$N双手连扬，一式「破云见日」，两把$w向$n撒出，笼罩$n的全身上下",
"$N向空中一撒，却是$n一招「秋日落叶」，十多枚$w由空中缓缓落下",
"$N身形急速向前滑动，一式「雪地追踪」，三枚$w向$n的胁下射去",
"$N一式「回首沧桑」，身体一转，反手掷出数枚$w，飞向$n的背部",
"$N凌空一纵，一招「雨打浮萍」，居高临下，手中$w疾射，直向$n的$l",
"$N一招「流星电闪」，手指弹出五枚$w，一点黑光射向$n的头部",
});

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("mantian-huayu",1))/4,
		"damage_type":"刺伤",
		"dodge":random(20)+20,
		"force":random(50)+me->query_skill("mantian-huayu",1),
		"post_action": (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练漫天花雨。\n");
	me->receive_damage("qi", 30);
	return 1;
}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("你的玄天无极功火候太浅。\n");
	return 1;
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"mantian-huayu/" + action;
}

int help(object me)
{
	write(HIC"\n漫天花雨："NOR"\n");
	write(@HELP

    漫天花雨是昆仑派的暗器绝技。

	学习要求：
		玄天无极功30级
		内力100
HELP
	);
	return 1;
}

