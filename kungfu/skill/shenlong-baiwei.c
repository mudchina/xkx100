// xianglong-zhang.c 降龙十八掌之神龙摆尾
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int d_e1 = -60;
int d_e2 = -40;
int p_e1 = -20;
int p_e2 = 10;
int f_e1 = 350;
int f_e2 = 550;
int ttl = 17;
int seq = 17;
mapping *action = ({
	([
		"action"      : "$N左掌护胸，右掌使一招"+(order[random(13)])+"「神龙摆尾」"NOR"上下晃动着击向$n的$l",
		"skill_name"  : "神龙摆尾",
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]),
});


string main_skill() { return "xianglong-zhang"; }
int valid_enable(string usage) { return usage=="strike" ; }

int valid_learn(object me)
{
		if (me->query_skill("xianglong-zhang", 1) > 0)
				return notify_fail("你已经学全十八掌了，不必再单独学习。\n");

    if (!me->query("can_learn/hong/sub-xianglong-zhang"))
    		return notify_fail("你未得洪七公亲点，领悟不到降龙十八掌的精髓。\n");

		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
				return notify_fail("练降龙十八掌必须空手。\n");

		if ((int)me->query("max_neili") < 1000)
				return notify_fail("你的内力太弱，无法练降龙十八掌。\n");

		if ((int)me->query("str") < 25)
				return notify_fail("你的先天膂力孱弱，难以修炼降龙十八掌。\n");

		if ((int)me->query("con") < 20)
				return notify_fail("你的先天根骨孱弱，难以修炼降龙十八掌。\n");

		if ((int)me->query_skill("strike", 1) < 180)
				return notify_fail("你的基本掌法火候不够，难以修炼降龙十八掌。\n");

		if ((int)me->query_skill("strike", 1) < (int)me->query_skill("shenlong-baiwei", 1))
				return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n");

	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练降龙十八掌。\n");
	me->receive_damage("qi", 100);
	me->add("neili", -40);
	return 1;
}
string query_skill_name(int level)
{
			return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	return action[0];
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) {
	if (userp(me)) return 0.5; //因为是半成品 不允许高
  return 1;
} 

int help(object me)
{
	write(HIC"\n降龙十八掌之神龙摆尾："NOR"\n");
	write(@HELP

    降龙十八掌是丐帮镇帮之宝，是天下最刚猛的武功。

	学习要求：
		得到洪七公亲自指点
		内力1000
		先天臂力25
		先天根骨20
		基本掌法180
HELP
	);
	return 1;
}