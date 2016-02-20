// iron-sword.c 玄铁剑法
// Last Modified by winder on Feb. 28 2001
 
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
BLU "$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n"BLU"只觉\n一股大力由$w"BLU"直逼周身",
BLU "$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n"BLU"周身笼于剑气之下",
BLU "$N轻叹一声，随手横劈一剑，缓缓指向$n"BLU"，看似无丝毫变化，却尽得剑\n法精髓，当真平淡中蕴涵所有变化，无招胜有招",
BLU "$N迅疾挑出一剑，但见剑势如虹，快似闪电，无可当锋！此剑之快，匪夷所\n思，$n"BLU"无法分辨出剑路去来",
BLU "$N仰首长啸，令风云变幻，狂风遽起，旋及一剑平指，剑气弥漫于$n"BLU"周\n身各处，$n"BLU"只觉身处惊涛骇浪之中，惊怖中更觉$N剑力有如海潮一般，一波\n一浪阵阵涌来，绵延不绝，愈发愈强",
BLU "$N祭起$w"BLU"，左手捏成剑诀置于胸前，咄喝一声，正是剑法至尊的“御剑\n式”，空中满是剑影，宛若千道银链，只在$n"BLU"身边游动",
BLU "$N$w"BLU"连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，\n平淡至极又匪思至极，顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴\n归真，却已不再存任何破绽",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力太弱，无法练玄铁剑法。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 150)
		return notify_fail("你的玉女心法不熟练，无法练玄铁剑法。\n");
	if (!(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "iron sword")
		return notify_fail("没有玄铁剑在手，你无法体会玄铁剑法以拙驭巧的剑意。\n");
	return 1;
}
int practice_skill(object me)
{
	int cost;
	cost = 40;
	if ((int)me->query("qi") < 140)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练玄铁剑法。\n");
	if ((int)me->query_skill("anran-zhang", 1)>150)
	        cost=80;
	if ((int)me->query_skill("anran-zhang", 1)>250)
	        cost=160;   
	me->receive_damage("qi", cost);
	me->add("neili", -50);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))]+NOR,
		"damage":240+random(100),
		"damage_type":random(2)?"刺伤":"割伤",
		"dodge":-25+random(20),
		"parry":-55+random(20),
		"force":150+random(80)
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	object weapon;
  if (!objectp(weapon = me->query_temp("weapon")) ||
                (string)weapon->query("id") != "iron sword")  
		return 0.8;
  else return 1.2;
}

string perform_action_file(string action)
{
	return __DIR__"iron-sword/" + action;
}
int help(object me)
{
	write(HIC"\n玄铁剑法："NOR"\n");
	write(@HELP

    杨过自和小龙女在绝情谷断肠崖前分手，不久便由神雕带着在
海潮之中练功，数年之后，借助海潮之力，练成此剑法。

	学习要求：
		玉女心法150级
		内力1500
		必须手执玄铁剑
HELP
	);
	return 1;
}

